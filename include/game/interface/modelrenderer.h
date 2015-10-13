#pragma once



#include "common.h"



namespace hsdk
{
	namespace game
	{
		namespace i
		{

			// 설명 : 
			DLL_DECL_INTERFACE(i_ModelRenderer)
			{

				// 소멸자.
				CLASS_DECL_DESTRUCTOR(i_ModelRenderer)(void)
				{

				}

				// 설명 : 
				INTERFACE_DECL_FUNC_T(void, initialize)(
					/* [x] */ void) = 0;
					
				// 설명 : 
				INTERFACE_DECL_FUNC_T(void, render)(
					/* [x] */ void) = 0;

			};

		}
	}
}