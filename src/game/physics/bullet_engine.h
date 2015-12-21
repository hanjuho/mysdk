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

		// 설명 : 
		typedef void(__stdcall *CALLBACK_COLLISIONRESULT)(
			_In_ const btPersistentManifold & _manifold,
			_In_ btScalar _timeStep);

		// 설명 : 
		DECL_CLASS(Bullet_Engine)
		{
		public:

			// 생성자.
			CLASS_DECL_CONSTRUCTOR(Bullet_Engine)(
				_In_ float _gravityscale = 1.0f);

			// 설명 : 
			CLASS_DECL_FUNC(setup0_World)(
				_In_ int _width,
				_In_ int _height,
				_In_ int _depth,
				_In_ CALLBACK_COLLISIONRESULT _callback = nullptr);

			/*
			설명 : 지형의 너비, 높이, 깊이를 설정, 생성.
			$ 참고 1 : _cellX, _cellY는 반드시 2의 배수여야 함(그렇지 않은 경우 내부에서 2의 배수로 수정함).
			$ 참고 2 : 총 5개의 물리도형이 추가되며, 이 도형은 reset()으로만 지울 수 있음.
			*/
			CLASS_DECL_FUNC(setup1_Terrain)(
				_In_ int _cellX,
				_In_ int _cellY,
				_In_ const float * _heightBuffer,
				_In_ unsigned int _size);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, update)(
				_X_ float _time);

			// 설명 : 이 함수를 호출하면 setup0 부터 다시 호출하여야 함.
			CLASS_DECL_FUNC_T(void, reset)(
				_X_ void);

			/*
			설명 : _body를 내부에서 생성하여 반환만 함.
			$ 참고 1 : btRigidBody는 단순히 _shape를 참조할 뿐이기 때문에 여러 btRigidBody가 하나의 btCollisionShape를 참조할 수 있음.
			$ 참고 2 : btCollisionShape * _shape의 삭제는 책임지지 않음.
			*/
			CLASS_DECL_FUNC(create)(
				_Out_ btRigidBody ** _body,
				_In_ const btTransform & _form,
				_In_ btCollisionShape * _shape,
				_In_ float _mass)const;

			// 설명 : 물리적인 형태를 월드에 추가, 포인터에 대한 소유권도 함께 넘김.
			CLASS_DECL_FUNC_T(void, add)(
				_In_ btRigidBody * _body);

			// 설명 : 물리적인 형태를 월드에 제거, 포인터에 대한 소유권도 함께 가져옴.
			CLASS_DECL_FUNC_T(void, remove)(
				_In_ btRigidBody * _body);

			// 설명 : 터레인을 제외한 월드의 모든 오브젝트를 제거.
			CLASS_DECL_FUNC_T(void, clear)(
				_X_ void);

			// 설명 : 
			CLASS_DECL_FUNC_T(btVector3, minWorldSize)(
				_X_ void);

			// 설명 : 
			CLASS_DECL_FUNC_T(btVector3, maxWorldSize)(
				_X_ void);

		private:

			// 설명 : 
			float my_GravityScale = 1.0f;

			// 설명 : 
			btVector3 my_WorldMinSize = { 0, 0, 0 };

			// 설명 : 
			btVector3 my_WorldMaxSize = { 0, 0, 0 };

			// 설명 : 
			std::vector<unsigned char> my_HeightBuffer;

			// 설명 : 
			AutoDelete<btCollisionShape> my_Shapes[5];

			// 설명 : 
			AutoDelete<btAxisSweep3> my_OverlappingPairCache;

			// 설명 : 
			AutoDelete<btDefaultCollisionConfiguration>	my_CollisionConfiguration;

			// 설명 : 
			AutoDelete<btCollisionDispatcher> my_CollisionDispatcher;

			// 설명 : 
			AutoDelete<btSequentialImpulseConstraintSolver> my_ConstraintSolver;

			// 설명 :
			AutoDelete<btDiscreteDynamicsWorld> my_DynamicsWorld;

		};
		
		// 설명 : 		
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