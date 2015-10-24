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
					_In_ const i_Collider2D * _collider) = 0;

				// ���� : 
				INTERFACE_DECL_FUNC_T(void, impulse)(
					_In_ const Vector2D & _impulse,
					_In_ const Vector2D & _contact) = 0;

				// ���� : 
				INTERFACE_DECL_FUNC_T(void, increase)(
					_In_ const Vector2D & _vector) = 0;

				// ���� : �ӵ� ����.
				INTERFACE_DECL_FUNC_T(void, accelerate)(
					_In_ const Vector2D & _vector) = 0;

				// ���� : �ӵ� ����.
				INTERFACE_DECL_FUNC_T(void, spin)(
					_In_ float _value) = 0;
				// ���� : �ӵ� ��ȯ.
				INTERFACE_DECL_FUNC_T(Vector2D, velocity)(
					_X_ void)const = 0;

				// ���� : �ӵ� ��ȯ.
				INTERFACE_DECL_FUNC_T(float, angularVelocity)(
					_X_ void)const = 0;

				// ���� : �� ��ȯ.
				INTERFACE_DECL_FUNC_T(Vector2D, force)(
					_X_ void)const = 0;

				// ���� : ����.
				INTERFACE_DECL_FUNC_T(float, mass)(
					_X_ void)const = 0;

				// ���� : ź��.
				INTERFACE_DECL_FUNC_T(float, inertia)(
					_X_ void)const = 0;

				// ���� : ���� ������.
				INTERFACE_DECL_FUNC_T(float, s_Friction)(
					_X_ void)const = 0;

				// ���� : � ������.
				INTERFACE_DECL_FUNC_T(float, d_Friction)(
					_X_ void)const = 0;

				// ���� : ������.
				INTERFACE_DECL_FUNC_T(float, restitution)(
					_X_ void)const = 0;

				// ���� : �������� �ʴ� ��ü.
				INTERFACE_DECL_FUNC_T(void, fixed)(
					_In_ void) = 0;
				
				// ���� : �� �ʱ�ȭ.
				INTERFACE_DECL_FUNC_T(void, expended)(
					_In_ void) = 0;

			};

		}
	}
}