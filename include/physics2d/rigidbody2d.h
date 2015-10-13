#pragma once



#include "interface/rigidbody2d.h"
#include "vector2d.h"



namespace hsdk
{
	namespace physics2d
	{

		// ���� : 
		DLL_DECL_CLASS(RigidBody2D)
			: public i::i_RigidBody2D
		{
		public:
			
			// ������.
			CLASS_DECL_CONSTRUCTOR(RigidBody2D)(
				/* [r] */float sFriction,
				/* [r] */float dFriction,
				/* [r] */float restitution);
			
			// ���� : 
			INTERFACE_DECL_FUNC_T(void, apply_Shape)(
				/* [r] */ const i::i_Collider2D * _collider);

			// ���� : 
			INTERFACE_DECL_FUNC_T(void, impulse)(
				/* [r] */ const Vector2D & _impulse,
				/* [r] */ const Vector2D & _contact);
			
			// ���� : ����.
			INTERFACE_DECL_FUNC_T(float, mass)(
				/* [x] */ void)const;

			// ���� : ź��.
			INTERFACE_DECL_FUNC_T(float, inertia)(
				/* [x] */ void)const;

			// ���� : ���� ������.
			INTERFACE_DECL_FUNC_T(float, s_Friction)(
				/* [x] */ void)const;

			// ���� : � ������.
			INTERFACE_DECL_FUNC_T(float, d_Friction)(
				/* [x] */ void)const;

			// ���� : ������.
			INTERFACE_DECL_FUNC_T(float, restitution)(
				/* [x] */ void)const;

			// ���� : �������� �ʴ� ��ü.
			INTERFACE_DECL_FUNC_T(void, fixed)(
				/* [r] */ void);

		protected:

			// ���� : moment of inertia
			float m_inertia;

			// ���� : mass
			float m_mass;

			// http://gamedev.tutsplus.com/tutorials/implementation/how-to-create-a-custom-2d-physics-engine-friction-scene-and-jump-table/
			
			// ���� : 
			float m_SFriction;

			// ���� : 
			float m_DFriction;

			// ���� : 
			float m_Restitution;

		};

	}
}