#pragma once



#if defined(DEBUG) || defined(_DEBUG)
#pragma comment(lib, "BulletCollision_vs2010_debug.lib")
#pragma comment(lib, "BulletDynamics_vs2010_debug.lib")
#pragma comment(lib, "LinearMath_vs2010_debug.lib")
#else
#pragma comment(lib, "BulletCollision_vs2010.lib")
#pragma comment(lib, "BulletDynamics_vs2010.lib")
#pragma comment(lib, "LinearMath_vs2010.lib")
#endif



#include "../../hsdk_common.h"
#include "../../hsdk/autodelete.h"
#include <vector>
#include "btBulletCollisionCommon.h"
#include "btBulletDynamicsCommon.h"



// 9.8 m/s^2
#define BULLET_GRAVITY 9.8f
#define BULLET_COMPANION_TERRAINID	-1
#define BULLET_COMPANION_EASTWALLID -2
#define BULLET_COMPANION_WESTWALLID -4
#define BULLET_COMPANION_SOUTHID	-8
#define BULLET_COMPANION_NORTHID	-16



namespace hsdk
{
	namespace bullet
	{

		// ���� : 
		typedef void(__stdcall *CALLBACK_COLLISIONRESULT)(
			_In_ const btPersistentManifold & _manifold,
			_In_ btScalar _timeStep);

		// ���� : 
		DECL_CLASS(Bullet_Engine)
		{
		public:

			// ������.
			CLASS_DECL_CONSTRUCTOR(Bullet_Engine)(
				_In_ float _gravityscale = 1.0f);

			// ���� : 
			CLASS_DECL_FUNC(setup0_World)(
				_In_ int _width,
				_In_ int _height,
				_In_ int _depth,
				_In_ CALLBACK_COLLISIONRESULT _callback = nullptr);

			// ���� : 
			CLASS_DECL_FUNC(setup1_Terrain)(
				_In_ int _cellX,
				_In_ int _cellY,
				_In_ const float * _heightBuffer,
				_In_ unsigned int _size);

			// ���� : 
			CLASS_DECL_FUNC_T(void, update)(
				_X_ float _time);

			// ���� : 
			CLASS_DECL_FUNC_T(void, reset)(
				_X_ void);

			/*
			���� : btRigidBody�� �ܼ��� _shape�� ������ ���̱� ������ ���� btRigidBody�� �ϳ��� btCollisionShape�� ������ �� ����.
			$ ���� 1 : btCollisionShape * _shape�� ������ å������ ����.
			$ ���� 2 : �� �Լ��� ȣ���� �����ϸ� ��ȯ ���� nullptr�̸�, ��ȯ ���� Bullet_Engine���ο� ����Ǳ� ������ �����Ͱ� ���������� �ȵ�.
			*/
			CLASS_DECL_FUNC_T(btRigidBody *, add)(
				_In_ const btTransform & _form,
				_In_ btCollisionShape * _shape,
				_In_ float _mass);

			// ���� : 
			CLASS_DECL_FUNC_T(void, remove)(
				_In_ btRigidBody * _body);

			// ���� : 
			CLASS_DECL_FUNC_T(void, clear)(
				_X_ void);

			// ���� : 
			CLASS_DECL_FUNC_T(btVector3, minWorldSize)(
				_X_ void);

			// ���� : 
			CLASS_DECL_FUNC_T(btVector3, maxWorldSize)(
				_X_ void);

		private:

			// ���� : 
			float my_GravityScale = 1.0f;

			// ���� : 
			btVector3 my_WorldMinSize = { 0, 0, 0 };

			// ���� : 
			btVector3 my_WorldMaxSize = { 0, 0, 0 };

			// ���� : 
			std::vector<unsigned char> my_HeightBuffer;

			// ���� : 
			AutoDelete<btAxisSweep3> my_OverlappingPairCache;

			// ���� : 
			AutoDelete<btDefaultCollisionConfiguration>	my_CollisionConfiguration;

			// ���� : 
			AutoDelete<btCollisionDispatcher> my_CollisionDispatcher;

			// ���� : 
			AutoDelete<btSequentialImpulseConstraintSolver> my_ConstraintSolver;

			// ���� :
			AutoDelete<btDiscreteDynamicsWorld> my_DynamicsWorld;

		};

	}
}