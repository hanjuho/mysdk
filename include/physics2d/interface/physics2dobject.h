#pragma once



#include "common.h"



namespace hsdk
{
	namespace physics2d
	{
		namespace i
		{

			// 설명 :
			DLL_DECL_INTERFACE(i_Physics2DObject)
			{

				// 소멸자.
				CLASS_DECL_DESTRUCTOR(i_Physics2DObject)(void)
				{

				}

				// 설명 :
				INTERFACE_DECL_FUNC_T(i_RigidBody2D *, rigidBody)(
					/* [x] */ void)const = 0;

				// 설명 :
				INTERFACE_DECL_FUNC_T(i_Collider2D *, collider)(
					/* [x] */ void)const = 0;

				// 설명 : 
				INTERFACE_DECL_FUNC_T(void, integrate_Velocity)(
					/* [r] */ const Vector2D & _gravity,
					/* [r] */ float _dt);

				// 설명 : 
				INTERFACE_DECL_FUNC_T(void, integrate_Forces)(
					/* [r] */ const Vector2D & _gravity,
					/* [r] */ float _torque,
					/* [r] */ float _dt);

				// 설명 :
				INTERFACE_DECL_FUNC_T(void, move)(
					/* [x] */ const Vector2D & _vector) = 0;

				// 설명 :
				INTERFACE_DECL_FUNC_T(void, rotate)(
					/* [x] */ float _angle) = 0;

				// 설명 :
				INTERFACE_DECL_FUNC_T(Vector2D, position)(
					/* [x] */ void)const = 0;

				// 설명 :
				INTERFACE_DECL_FUNC_T(Matrix2D, matrix)(
					/* [x] */ void)const = 0;

				// 설명 : 객체가 기억하는 다른 객체의 아이디.
				INTERFACE_DECL_FUNC_T(unsigned int, pid)(
					/* [x] */ void)const = 0;

				// 설명 : 이 값이 같은 오브젝트끼리는 충돌이 발생하지 않음.
				INTERFACE_DECL_FUNC_T(unsigned int, group_id)(
					/* [x] */ void)const = 0;

				// 설명 : 이 값이 false라면 충돌이 발생하지 않음.
				INTERFACE_DECL_FUNC_T(bool, is_Collision)(
					/* [x] */ void)const = 0;

			};

		}
	}
}