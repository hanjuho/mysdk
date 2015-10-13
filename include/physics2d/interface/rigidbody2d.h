#pragma once



#include "common.h"



namespace hsdk
{
	namespace physics2d
	{
		namespace i
		{

			// ���� : 
			DLL_DECL_INTERFACE(i_RigidBody2D)
			{

				// �Ҹ���.
				CLASS_DECL_DESTRUCTOR(i_RigidBody2D)(void)
				{

				}

				// ���� : 
				INTERFACE_DECL_FUNC_T(void, apply_Shape)(
					/* [r] */ const i_Collider2D * _collider) = 0;

				// ���� : 
				INTERFACE_DECL_FUNC_T(void, impulse)(
					/* [r] */ const Vector2D & _impulse,
					/* [r] */ const Vector2D & _contact) = 0;

				// ���� : 
				INTERFACE_DECL_FUNC_T(void, increase)(
					/* [r] */ const Vector2D & _vector) = 0;

				// ���� : �ӵ� ����.
				INTERFACE_DECL_FUNC_T(void, accelerate)(
					/* [r] */ const Vector2D & _vector) = 0;

				// ���� : �ӵ� ����.
				INTERFACE_DECL_FUNC_T(void, spin)(
					/* [r] */ float _value) = 0;
				// ���� : �ӵ� ��ȯ.
				INTERFACE_DECL_FUNC_T(Vector2D, velocity)(
					/* [x] */ void)const = 0;

				// ���� : �ӵ� ��ȯ.
				INTERFACE_DECL_FUNC_T(float, angularVelocity)(
					/* [x] */ void)const = 0;

				// ���� : �� ��ȯ.
				INTERFACE_DECL_FUNC_T(Vector2D, force)(
					/* [x] */ void)const = 0;

				// ���� : ����.
				INTERFACE_DECL_FUNC_T(float, mass)(
					/* [x] */ void)const = 0;

				// ���� : ź��.
				INTERFACE_DECL_FUNC_T(float, inertia)(
					/* [x] */ void)const = 0;

				// ���� : ���� ������.
				INTERFACE_DECL_FUNC_T(float, s_Friction)(
					/* [x] */ void)const = 0;

				// ���� : � ������.
				INTERFACE_DECL_FUNC_T(float, d_Friction)(
					/* [x] */ void)const = 0;

				// ���� : ������.
				INTERFACE_DECL_FUNC_T(float, restitution)(
					/* [x] */ void)const = 0;

				// ���� : �������� �ʴ� ��ü.
				INTERFACE_DECL_FUNC_T(void, fixed)(
					/* [r] */ void) = 0;
				
				// ���� : �� �ʱ�ȭ.
				INTERFACE_DECL_FUNC_T(void, expended)(
					/* [r] */ void) = 0;

			};

		}
	}
}