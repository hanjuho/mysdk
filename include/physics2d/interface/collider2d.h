#pragma once



#include "common.h"



namespace hsdk
{
	namespace physics2d
	{
		namespace i
		{

			// 설명 : 콜라이더 추상화
			DLL_DECL_INTERFACE(i_Collider2D)
			{

				// 소멸자.
				CLASS_DECL_DESTRUCTOR(i_Collider2D)(void)
				{

				}

				// 설명 : collider의 속성
				INTERFACE_DECL_FUNC_T(unsigned int, type)(
					_X_ void)const = 0;

				// 설명 : 
				INTERFACE_DECL_FUNC_T(unsigned int, numOfVerties)(
					_X_ void)const = 0;

				// 설명 : 
				INTERFACE_DECL_FUNC_T(Vector2D, vertex)(
					_In_ unsigned int _index)const = 0;

				// 설명 : 
				INTERFACE_DECL_FUNC_T(const Vector2D *, vertices)(
					_X_ void)const = 0;

				// 설명 : 
				INTERFACE_DECL_FUNC_T(Vector2D, normal)(
					_In_ unsigned int _index)const = 0;

				// 설명 : 
				INTERFACE_DECL_FUNC_T(const Vector2D *, normals)(
					_X_ void)const = 0;

				// 설명 : 
				INTERFACE_DECL_FUNC_T(float, density)(
					_X_ void)const = 0;

				// 설명 : 
				INTERFACE_DECL_FUNC_T(float, area)(
					_X_ void)const = 0;

				// 설명 : 
				INTERFACE_DECL_FUNC_T(float, radius)(
					_X_ void)const = 0;

			};

		}
	}
}