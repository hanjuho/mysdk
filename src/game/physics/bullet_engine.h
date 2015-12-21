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

			/*
			���� : ������ �ʺ�, ����, ���̸� ����, ����.
			$ ���� 1 : _cellX, _cellY�� �ݵ�� 2�� ������� ��(�׷��� ���� ��� ���ο��� 2�� ����� ������).
			$ ���� 2 : �� 5���� ���������� �߰��Ǹ�, �� ������ reset()���θ� ���� �� ����.
			*/
			CLASS_DECL_FUNC(setup1_Terrain)(
				_In_ int _cellX,
				_In_ int _cellY,
				_In_ const float * _heightBuffer,
				_In_ unsigned int _size);

			// ���� : 
			CLASS_DECL_FUNC_T(void, update)(
				_X_ float _time);

			// ���� : �� �Լ��� ȣ���ϸ� setup0 ���� �ٽ� ȣ���Ͽ��� ��.
			CLASS_DECL_FUNC_T(void, reset)(
				_X_ void);

			/*
			���� : _body�� ���ο��� �����Ͽ� ��ȯ�� ��.
			$ ���� 1 : btRigidBody�� �ܼ��� _shape�� ������ ���̱� ������ ���� btRigidBody�� �ϳ��� btCollisionShape�� ������ �� ����.
			$ ���� 2 : btCollisionShape * _shape�� ������ å������ ����.
			*/
			CLASS_DECL_FUNC(create)(
				_Out_ btRigidBody ** _body,
				_In_ const btTransform & _form,
				_In_ btCollisionShape * _shape,
				_In_ float _mass)const;

			// ���� : �������� ���¸� ���忡 �߰�, �����Ϳ� ���� �����ǵ� �Բ� �ѱ�.
			CLASS_DECL_FUNC_T(void, add)(
				_In_ btRigidBody * _body);

			// ���� : �������� ���¸� ���忡 ����, �����Ϳ� ���� �����ǵ� �Բ� ������.
			CLASS_DECL_FUNC_T(void, remove)(
				_In_ btRigidBody * _body);

			// ���� : �ͷ����� ������ ������ ��� ������Ʈ�� ����.
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
			AutoDelete<btCollisionShape> my_Shapes[5];

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
		
		// ���� : 		
		inline IMPL_FUNC_T(int, compute_Find2)(
			_In_ int _value)
		{
			int pow2 = 1;
			while (pow2 < _value)
			{
				pow2 <<= 1;
			}

			return pow2;
		}

	}
}