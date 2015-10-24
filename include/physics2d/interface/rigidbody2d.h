#pragma once



#include "common.h"



namespace hsdk
{
	namespace physics2d
	{
		namespace i
		{

			// 설명 : 
			DLL_DECL_INTERFACE(i_RigidBody2D)
			{

				// 소멸자.
				CLASS_DECL_DESTRUCTOR(i_RigidBody2D)(void)
				{

				}

				// 설명 : 
				INTERFACE_DECL_FUNC_T(void, apply_Shape)(
					_In_ const i_Collider2D * _collider) = 0;

				// 설명 : 
				INTERFACE_DECL_FUNC_T(void, impulse)(
					_In_ const Vector2D & _impulse,
					_In_ const Vector2D & _contact) = 0;

				// 설명 : 
				INTERFACE_DECL_FUNC_T(void, increase)(
					_In_ const Vector2D & _vector) = 0;

				// 설명 : 속도 증가.
				INTERFACE_DECL_FUNC_T(void, accelerate)(
					_In_ const Vector2D & _vector) = 0;

				// 설명 : 속도 설정.
				INTERFACE_DECL_FUNC_T(void, spin)(
					_In_ float _value) = 0;
				// 설명 : 속도 반환.
				INTERFACE_DECL_FUNC_T(Vector2D, velocity)(
					_X_ void)const = 0;

				// 설명 : 속도 반환.
				INTERFACE_DECL_FUNC_T(float, angularVelocity)(
					_X_ void)const = 0;

				// 설명 : 힘 반환.
				INTERFACE_DECL_FUNC_T(Vector2D, force)(
					_X_ void)const = 0;

				// 설명 : 질량.
				INTERFACE_DECL_FUNC_T(float, mass)(
					_X_ void)const = 0;

				// 설명 : 탄성.
				INTERFACE_DECL_FUNC_T(float, inertia)(
					_X_ void)const = 0;

				// 설명 : 정지 마찰력.
				INTERFACE_DECL_FUNC_T(float, s_Friction)(
					_X_ void)const = 0;

				// 설명 : 운동 마찰력.
				INTERFACE_DECL_FUNC_T(float, d_Friction)(
					_X_ void)const = 0;

				// 설명 : 복원력.
				INTERFACE_DECL_FUNC_T(float, restitution)(
					_X_ void)const = 0;

				// 설명 : 움직이지 않는 몸체.
				INTERFACE_DECL_FUNC_T(void, fixed)(
					_In_ void) = 0;
				
				// 설명 : 힘 초기화.
				INTERFACE_DECL_FUNC_T(void, expended)(
					_In_ void) = 0;

			};

		}
	}
}