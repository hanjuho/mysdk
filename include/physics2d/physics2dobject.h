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
				_X_ void)const final;

			// ���� :
			INTERFACE_DECL_FUNC_T(i::i_Collider2D *, collider)(
				_X_ void)const final;

			// ���� : 
			INTERFACE_DECL_FUNC_T(void, integrate_Velocity)(
				_In_ const Vector2D & _gravity,
				_In_ float _dt);

			// ���� : 
			INTERFACE_DECL_FUNC_T(void, integrate_Forces)(
				_In_ const Vector2D & _gravity,
				_In_ float _torque,
				_In_ float _dt);

			// ���� : 
			CLASS_DECL_FUNC_T(void, initialize_Body)(
				_X_ void);

		protected:

			// ���� : ��ü
			AutoDelete<i::i_RigidBody2D> my_RigidBody;

			// ���� : �浹 ����
			AutoDelete <i::i_Collider2D> my_Collider;

		};

	}
}