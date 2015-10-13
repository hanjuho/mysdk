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
					/* [x] */ void)const = 0;

				// ���� :
				INTERFACE_DECL_FUNC_T(i_Collider2D *, collider)(
					/* [x] */ void)const = 0;

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
				INTERFACE_DECL_FUNC_T(void, move)(
					/* [x] */ const Vector2D & _vector) = 0;

				// ���� :
				INTERFACE_DECL_FUNC_T(void, rotate)(
					/* [x] */ float _angle) = 0;

				// ���� :
				INTERFACE_DECL_FUNC_T(Vector2D, position)(
					/* [x] */ void)const = 0;

				// ���� :
				INTERFACE_DECL_FUNC_T(Matrix2D, matrix)(
					/* [x] */ void)const = 0;

				// ���� : ��ü�� ����ϴ� �ٸ� ��ü�� ���̵�.
				INTERFACE_DECL_FUNC_T(unsigned int, pid)(
					/* [x] */ void)const = 0;

				// ���� : �� ���� ���� ������Ʈ������ �浹�� �߻����� ����.
				INTERFACE_DECL_FUNC_T(unsigned int, group_id)(
					/* [x] */ void)const = 0;

				// ���� : �� ���� false��� �浹�� �߻����� ����.
				INTERFACE_DECL_FUNC_T(bool, is_Collision)(
					/* [x] */ void)const = 0;

			};

		}
	}
}