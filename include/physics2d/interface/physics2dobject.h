#pragma once



#include "common.h"



namespace hsdk
{
	namespace physics2d
	{
		namespace i
		{

			// ���� :
			DLL_DECL_INTERFACE(i_Physics2DObject)
			{

				// �Ҹ���.
				CLASS_DECL_DESTRUCTOR(i_Physics2DObject)(void)
				{

				}

				// ���� :
				INTERFACE_DECL_FUNC_T(i_RigidBody2D *, rigidBody)(
					_X_ void)const = 0;

				// ���� :
				INTERFACE_DECL_FUNC_T(i_Collider2D *, collider)(
					_X_ void)const = 0;

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
				INTERFACE_DECL_FUNC_T(void, move)(
					_X_ const Vector2D & _vector) = 0;

				// ���� :
				INTERFACE_DECL_FUNC_T(void, rotate)(
					_X_ float _angle) = 0;

				// ���� :
				INTERFACE_DECL_FUNC_T(Vector2D, position)(
					_X_ void)const = 0;

				// ���� :
				INTERFACE_DECL_FUNC_T(Matrix2D, matrix)(
					_X_ void)const = 0;

				// ���� : ��ü�� ����ϴ� �ٸ� ��ü�� ���̵�.
				INTERFACE_DECL_FUNC_T(unsigned int, pid)(
					_X_ void)const = 0;

				// ���� : �� ���� ���� ������Ʈ������ �浹�� �߻����� ����.
				INTERFACE_DECL_FUNC_T(unsigned int, group_id)(
					_X_ void)const = 0;

				// ���� : �� ���� false��� �浹�� �߻����� ����.
				INTERFACE_DECL_FUNC_T(bool, is_Collision)(
					_X_ void)const = 0;

			};

		}
	}
}