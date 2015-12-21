#include "bullet_engine.h"
#include "BulletCollision/CollisionShapes/btHeightfieldTerrainShape.h"
#include <algorithm>



using namespace hsdk::bullet;


// 설명 : 
#define TERRAIN_COUNT 5


//--------------------------------------------------------------------------------------
void bullet_Callback(
	_In_ btDynamicsWorld * _world,
	_In_ btScalar _timeStep)
{
	CALLBACK_COLLISIONRESULT callback = (CALLBACK_COLLISIONRESULT)_world->getWorldUserInfo();
	IF_INVALID(callback)
	{
		return;
	}

	btDispatcher * dispatcher = _world->getDispatcher();
	unsigned int size = dispatcher->getNumManifolds();
	for (unsigned int index = 0; index < size; ++index)
	{
		btPersistentManifold & manifold = *dispatcher->getManifoldByIndexInternal(index);
		manifold.m_companionIdA = manifold.getBody0()->getCompanionId();
		manifold.m_companionIdB = manifold.getBody1()->getCompanionId();

		if (manifold.m_companionIdA < 0 && manifold.m_companionIdB < 0)
		{
			continue;
		}

		callback(manifold, _timeStep);
	}
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_CONSTRUCTOR(Bullet_Engine, Bullet_Engine)(
	_In_ float _gravityscale)
	: my_GravityScale(_gravityscale)
{
	my_CollisionConfiguration = new btDefaultCollisionConfiguration();
	my_CollisionDispatcher = new btCollisionDispatcher(my_CollisionConfiguration);
	my_ConstraintSolver = new btSequentialImpulseConstraintSolver();
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(Bullet_Engine, setup0_World)(
	_In_ int _width,
	_In_ int _height,
	_In_ int _depth,
	_In_ CALLBACK_COLLISIONRESULT _callback)
{
	if (my_DynamicsWorld)
	{
		return HSDK_FAIL;
	}

	//
	int x = abs(_width / 2);
	int z = abs(_depth / 2);

	//
	float fx = float(x), fz = float(z);
	my_WorldMinSize = btVector3(-fx, 0, -fz);
	my_WorldMaxSize = btVector3(fx, float(abs(_height)), fz);

	my_OverlappingPairCache = new btAxisSweep3(
		my_WorldMinSize,
		my_WorldMaxSize);

	//
	my_DynamicsWorld = new btDiscreteDynamicsWorld(
		my_CollisionDispatcher,
		my_OverlappingPairCache,
		my_ConstraintSolver,
		my_CollisionConfiguration);

	//
	my_DynamicsWorld->setInternalTickCallback(bullet_Callback, _callback);

	// reset gravity to point in appropriate direction
	my_DynamicsWorld->setGravity(btVector3(0, -BULLET_GRAVITY * my_GravityScale, 0));

	//
	return 0;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(Bullet_Engine, setup1_Terrain)(
	_In_ int _cellX,
	_In_ int _cellY,
	_In_ const float * _heightBuffer,
	_In_ unsigned int _size)
{
	// 이미 터레인이 있다면 터레인 생성 불가
	if (TERRAIN_COUNT <= my_DynamicsWorld->getCollisionObjectArray().size())
	{
		return 1;
	}

	if (_cellX < 1 || _cellY < 1)
	{
		return HSDK_FAIL;
	}

	// 지면은 항상 2의 배수의 크기만큼 생성되어야 함
	int x = compute_Find2(abs(_cellX));
	int z = compute_Find2(abs(_cellY));

	int vx = x + 1;
	int vz = z + 1;

	// float 데이터를 사용할 것임으로 4배 길이를 복사
	my_HeightBuffer.resize(vx * vz * 4, 0);
	memcpy(&my_HeightBuffer[0], _heightBuffer, sizeof(float)* _size);

	// 최대 높이와 최저 높이를 계산
	float minH, maxH;
	minH = maxH = _heightBuffer[0];
	for (unsigned int index = 1; index < _size; ++index)
	{
		float value = _heightBuffer[index];
		minH = std::min(value, minH);
		maxH = std::max(value, maxH);
	}
	
	// 경계 상자 생성
	my_Shapes[0] = new btHeightfieldTerrainShape(vx, vz, &my_HeightBuffer[0], 1.0f, minH, maxH, 1, PHY_FLOAT, false);

	float thickness = 5.0f;
	my_Shapes[1] = new btStaticPlaneShape({ 1.0f, 0.0f, 0.0f }, thickness);
	my_Shapes[2] = new btStaticPlaneShape({ -1.0f, 0.0f, 0.0f }, thickness);
	my_Shapes[3] = new btStaticPlaneShape({ 0.0f, 0.0f, -1.0f }, thickness);
	my_Shapes[4] = new btStaticPlaneShape({ 0.0f, 0.0f, 1.0f }, thickness);
		
	// 필드 물리 상자
	AutoDelete<btRigidBody> field[5];
		
	btTransform form;
	form.setIdentity();
	
	unsigned int index;

	//-------------------------------------------

	// 지면 매트릭스 오프셋
	form.setOrigin(btVector3(0.0f, maxH / 2.0f, 0.0f));
	index = 0;

	// 지면 물리 상자 생성
	IF_FAILED(create(&field[index], form, my_Shapes[index], 0.0f))
	{
		return HSDK_FAIL;
	}
	field[index]->setCompanionId(BULLET_COMPANION_TERRAINID);
	
	//-------------------------------------------

	float xx = float(x / 2) + thickness;
	float zz = float(z / 2) + thickness;
	
	//-------------------------------------------
	
	// 동쪽 경계면 매트릭스 오프셋
	form.setOrigin(btVector3(-xx, 0.0f, 0.0f));
	index = 1;

	// 동쪽 경계면 상자 생성
	IF_FAILED(create(&field[index], form, my_Shapes[index], 0.0f))
	{
		return HSDK_FAIL;
	}
	field[index]->setCompanionId(BULLET_COMPANION_EASTWALLID);

	//-------------------------------------------
	//-------------------------------------------

	// 서쪽 경계면 매트릭스 오프셋
	form.setOrigin(btVector3(xx, 0.0f, 0.0f));
	index = 2;

	// 서쪽 경계면 상자 생성
	IF_FAILED(create(&field[index], form, my_Shapes[index], 0.0f))
	{
		return HSDK_FAIL;
	}
	field[index]->setCompanionId(BULLET_COMPANION_WESTWALLID);
	
	//-------------------------------------------
	//-------------------------------------------

	// 남쪽 경계면 매트릭스 오프셋
	form.setOrigin(btVector3(0.0f, 0.0f, zz));
	index = 3;

	// 남쪽 경계면 상자 생성
	IF_FAILED(create(&field[index], form, my_Shapes[index], 0.0f))
	{
		return HSDK_FAIL;
	}
	field[index]->setCompanionId(BULLET_COMPANION_SOUTHID);

	//-------------------------------------------
	//-------------------------------------------

	// 북쪽 경계면 매트릭스 오프셋
	form.setOrigin(btVector3(0.0f, 0.0f, -zz));
	index = 4;

	// 북쪽 경계면 상자 생성
	IF_FAILED(create(&field[index], form, my_Shapes[index], 0.0f))
	{
		return HSDK_FAIL;
	}
	field[index]->setCompanionId(BULLET_COMPANION_SOUTHID);

	//-------------------------------------------
	//-------------------------------------------

	for (unsigned int i = index; i != -1; --i)
	{
		btRigidBody * body = nullptr;
		field[i].steal(&body);

		add(body);
	}
	
	// 지면이 모두 추가되지 않은 경우
	if (TERRAIN_COUNT != my_DynamicsWorld->getCollisionObjectArray().size())
	{
		reset();

		return HSDK_FAIL;
	}

	return 0;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Bullet_Engine, void, update)(
	_X_ float _time)
{
	static const float minTimeStep = 1.0f / 60.0f;
	my_DynamicsWorld->stepSimulation(_time, 2, minTimeStep);
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Bullet_Engine, void, reset)(
	_X_ void)
{
	IF_INVALID(my_DynamicsWorld)
	{
		return;
	}

	//remove the rigidbodies from the dynamics world and delete them
	// 첫번째 유닛은 반드시 터레인이므로 reset()으로 밖에 지울 수 없다.
	const unsigned int size = my_DynamicsWorld->getNumCollisionObjects();
	for (unsigned int index = 0; index < size; ++index)
	{
		btCollisionObject * obj = my_DynamicsWorld->getCollisionObjectArray()[index];
		btRigidBody * body = btRigidBody::upcast(obj);

		if (body && body->getMotionState())
		{
			delete body->getMotionState();
		}

		my_DynamicsWorld->removeCollisionObject(obj);
		delete obj;
	}

	my_DynamicsWorld.~AutoDelete();
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(Bullet_Engine, create)(
	_Out_ btRigidBody ** _body,
	_In_ const btTransform & _form,
	_In_ btCollisionShape * _shape,
	_In_ float _mass)const
{
	if(_shape == nullptr || _shape->getShapeType() == INVALID_SHAPE_PROXYTYPE)
	{
		return HSDK_FAIL;
	}

	// rigidbody is dynamic if and only if mass is non zero, otherwise static
	btVector3 localInertia(0, 0, 0);
	if (_mass != 0.0f)
	{
		_shape->calculateLocalInertia(_mass, localInertia);
	}

	// using motionstate is recommended, it provides interpolation capabilities, and only synchronizes 'active' objects
	btDefaultMotionState * myMotionState =
		new btDefaultMotionState(_form);

	//
	btRigidBody::btRigidBodyConstructionInfo cInfo(
		_mass, myMotionState, _shape, localInertia);

	//
	DEL_POINTER((*_body));
	if ((*_body) = new btRigidBody(cInfo))
	{
		return 0;
	}
	else
	{
		return HSDK_FAIL;
	}
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Bullet_Engine, void, add)(
	_In_ btRigidBody * _body)
{
	// 
	my_DynamicsWorld->addRigidBody(_body);
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Bullet_Engine, void, remove)(
	_In_ btRigidBody * _body)
{
	my_DynamicsWorld->removeRigidBody(_body);
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Bullet_Engine, void, clear)(
	_X_ void)
{
	//remove the rigidbodies from the dynamics world and delete them
	// 첫번째 유닛은 반드시 터레인이므로 reset()으로 밖에 지울 수 없다.
	const unsigned int size = my_DynamicsWorld->getNumCollisionObjects();
	for (unsigned int index = TERRAIN_COUNT; index < size; ++index)
	{
		btCollisionObject * obj = my_DynamicsWorld->getCollisionObjectArray()[index];
		btRigidBody * body = btRigidBody::upcast(obj);

		if (body && body->getMotionState())
		{
			delete body->getMotionState();
		}

		my_DynamicsWorld->removeCollisionObject(obj);
		delete obj;
	}
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Bullet_Engine, btVector3, minWorldSize)(
	_X_ void)
{
	return my_WorldMinSize;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Bullet_Engine, btVector3, maxWorldSize)(
	_X_ void)
{
	return my_WorldMaxSize;
}