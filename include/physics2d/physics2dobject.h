#pragma once



#include "interface/physics2dobject.h"
#include "matrix2d.h"
#include "../hsdk/autodelete.h"



namespace hsdk
{
	namespace physics2d
	{

		// ���� : 
		DLL_DECL_CLASS(Physics2DObject)
			: public i::i_Physics2DObject
		{
		public:

			// ������.
			CLASS_DECL_CONSTRUCTOR(Physics2DObject)(
				/* [set] */ i::i_RigidBody2D * _rigidbody,
				/* [set] */ i::i_Collider2D * _collider);

			// ���� :
			INTERFACE_DECL_FUNC_T(i::i_RigidBody2D *, rigidBody)(
				/* [x] */ void)const final;

			// ���� :
			INTERFACE_DECL_FUNC_T(i::i_Collider2D *, collider)(
				/* [x] */ void)const final;

			// ���� : 
			INTERFACE_DECL_FUNC_T(void, integrate_Velocity)(
				/* [r] */ const Vector2D & _gravity,
				/* [r] */ float _dt);

			// ���� : 
			INTERFACE_DECL_FUNC_T(void, integrate_Forces)(
				/* [r] */ const Vector2D & _gravity,
				/* [r] */ float _torque,
				/* [r] */ float _dt);

			// ���� : 
			CLASS_DECL_FUNC_T(void, initialize_Body)(
				/* [x] */ void);

		protected:

			// ���� : ��ü
			AutoDelete<i::i_RigidBody2D> my_RigidBody;

			// ���� : �浹 ����
			AutoDelete <i::i_Collider2D> my_Collider;

		};

	}
}