#include "bullet_engine.h"
#include "BulletCollision/CollisionShapes/btHeightfieldTerrainShape.h"
#include <algorithm>



using namespace hsdk::bullet;


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
IMPL_FUNC_T(int, compute_Pow2)(
	_In_ int _value)
{
	int pow2 = 1;
	while (pow2 < _value)
	{
		pow2 <<= 1;
	}

	return pow2;
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
	// �̹� �ͷ����� �ִٸ� �ͷ��� ���� �Ұ�
	if (my_DynamicsWorld->getCollisionObjectArray().size())
	{
		return 1;
	}

	// 
	if (_cellX < 1 || _cellY < 1)
	{
		return HSDK_FAIL;
	}

	//
	int x = compute_Pow2(abs(_cellX));
	int z = compute_Pow2(abs(_cellY));

	int vx = x + 1;
	int vz = z + 1;

	// float �����͸� ����� �������� 4��
	my_HeightBuffer.resize(vx * vz * 4, 0);
	memcpy(&my_HeightBuffer[0], _heightBuffer, sizeof(float)* _size);

	float minH, maxH;

	minH = maxH = _heightBuffer[0];
	for (unsigned int index = 1; index < _size; ++index)
	{
		float value = _heightBuffer[index];
		minH = std::min(value, minH);
		maxH = std::max(value, maxH);
	}

	//
	btTransform form;
	form.setIdentity();
	form.setOrigin(btVector3(0.0f, maxH / 2.0f, 0.0f));

	//
	add(form, new btHeightfieldTerrainShape(vx, vz,
		&my_HeightBuffer[0], 1.0f, minH, maxH, 1, PHY_FLOAT, false), 0.0f)
		->setCompanionId(BULLET_COMPANION_TERRAINID);

	float xx = float((x + 10) / 2);
	float zz = float((z + 10) / 2);

	//
	form.setOrigin(btVector3(-xx, 0.0f, 0.0f));
	add(form, new btStaticPlaneShape(
	{ 1.0f, 0.0f, 0.0f }, 5.0f), 0.0f)->setCompanionId(BULLET_COMPANION_EASTWALLID);

	//
	form.setOrigin(btVector3(xx, 0.0f, 0.0f));
	add(form, new btStaticPlaneShape(
	{ -1.0f, 0.0f, 0.0f }, 5.0f), 0.0f)->setCompanionId(BULLET_COMPANION_WESTWALLID);

	//
	form.setOrigin(btVector3(0.0f, 0.0f, zz));
	add(form, new btStaticPlaneShape(
	{ 0.0f, 0.0f, -1.0f }, 5.0f), 0.0f)->setCompanionId(BULLET_COMPANION_SOUTHID);

	//
	form.setOrigin(btVector3(0.0f, 0.0f, -zz));
	add(form, new btStaticPlaneShape(
	{ 0.0f, 0.0f, 1.0f }, 5.0f), 0.0f)->setCompanionId(BULLET_COMPANION_NORTHID);


	//
	if (my_DynamicsWorld->getCollisionObjectArray().size() != 5)
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
	// ù��° ������ �ݵ�� �ͷ����̹Ƿ� reset()���� �ۿ� ���� �� ����.
	for (int index = my_DynamicsWorld->getNumCollisionObjects() - 1; index != -1; --index)
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
CLASS_IMPL_FUNC_T(Bullet_Engine, btRigidBody *, add)(
	_In_ const btTransform & _form,
	_In_ btCollisionShape * _shape,
	_In_ float _mass)
{
	btAssert((!_shape || _shape->getShapeType() != INVALID_SHAPE_PROXYTYPE));

	//rigidbody is dynamic if and only if mass is non zero, otherwise static
	btVector3 localInertia(0, 0, 0);
	if (_mass != 0.0f)
	{
		_shape->calculateLocalInertia(_mass, localInertia);
	}

	//using motionstate is recommended, it provides interpolation capabilities, and only synchronizes 'active' objects
	btDefaultMotionState * myMotionState =
		new btDefaultMotionState(_form);

	//
	btRigidBody::btRigidBodyConstructionInfo cInfo(
		_mass, myMotionState, _shape, localInertia);

	//
	btRigidBody * body = new btRigidBody(cInfo);

	// 
	my_DynamicsWorld->addRigidBody(body);

	//
	return body;
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
	// ù��° ������ �ݵ�� �ͷ����̹Ƿ� reset()���� �ۿ� ���� �� ����.
	for (int index = my_DynamicsWorld->getNumCollisionObjects() - 1; index != 1; --index)
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


//--------------------------------------------------------------------------------------
// 
//--------------------------------------------------------------------------------------

Bullet_Engine hsdk::bullet::g_BulletEngine(1.0f);