#pragma once



#include "common.h"



namespace hsdk
{
	namespace physics2d
	{
		namespace i
		{

			// 설명 : 
			DLL_DECL_INTERFACE(i_Terrain2D)
			{

				// 소멸자.
				CLASS_DECL_DESTRUCTOR(i_Terrain2D)(void)
				{

				}

				// 설명 : _x 좌표 지형의 높이, _dy는 기울기.
				INTERFACE_DECL_FUNC_T(float, height)(
					_In_ float _x,
					_Out_ float * _dy = nullptr)const = 0;

			};

		}
	}
}