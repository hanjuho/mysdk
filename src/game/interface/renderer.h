#pragma once



#include "common.h"



namespace hsdk
{
	namespace game
	{
		namespace i
		{

			// 설명 : 
			DECL_INTERFACE(i_Renderer)
			{

				// 소멸자.
				CLASS_DECL_DESTRUCTOR(i_Renderer)(void)
				{

				}

				// 설명 : 
				INTERFACE_DECL_FUNC_T(void, initialize)(
					_X_ void) = 0;

				// 설명 : 
				INTERFACE_DECL_FUNC_T(void, update)(
					_X_ void) = 0;
					
				// 설명 : 
				INTERFACE_DECL_FUNC_T(void, render)(
					_X_ void) = 0;

			};

		}
	}
}