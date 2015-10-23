#pragma once



#include "interface/rigidbody2d.h"
#include "vector2d.h"



namespace hsdk
{
	namespace physics2d
	{

		// 설명 : 
		DLL_DECL_CLASS(RigidBody2D)
			: public i::i_RigidBody2D
		{
		public:
			
			// 생성자.
			CLASS_DECL_CONSTRUCTOR(RigidBody2D)(
				_In_ float sFriction,
				_In_ float dFriction,
				_In_ float restitution);
			
			// 설명 : 
			INTERFACE_DECL_FUNC_T(void, apply_Shape)(
				_In_ const i::i_Collider2D * _collider);

			// 설명 : 
			INTERFACE_DECL_FUNC_T(void, impulse)(
				_In_ const Vector2D & _impulse,
				_In_ const Vector2D & _contact);
			
			// 설명 : 질량.
			INTERFACE_DECL_FUNC_T(float, mass)(
				/* [x] */ void)const;

			// 설명 : 탄성.
			INTERFACE_DECL_FUNC_T(float, inertia)(
				/* [x] */ void)const;

			// 설명 : 정지 마찰력.
			INTERFACE_DECL_FUNC_T(float, s_Friction)(
				/* [x] */ void)const;

			// 설명 : 운동 마찰력.
			INTERFACE_DECL_FUNC_T(float, d_Friction)(
				/* [x] */ void)const;

			// 설명 : 복원력.
			INTERFACE_DECL_FUNC_T(float, restitution)(
				/* [x] */ void)const;

			// 설명 : 움직이지 않는 몸체.
			INTERFACE_DECL_FUNC_T(void, fixed)(
				_In_ void);

		protected:

			// 설명 : moment of inertia
			float m_inertia;

			// 설명 : mass
			float m_mass;

			// http://gamedev.tutsplus.com/tutorials/implementation/how-to-create-a-custom-2d-physics-engine-friction-scene-and-jump-table/
			
			// 설명 : 
			float m_SFriction;

			// 설명 : 
			float m_DFriction;

			// 설명 : 
			float m_Restitution;

		};

	}
}