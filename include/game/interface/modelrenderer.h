#pragma once



#include "common.h"



namespace hsdk
{
	namespace game
	{
		namespace i
		{

			// ���� : 
			DLL_DECL_INTERFACE(i_ModelRenderer)
			{

				// �Ҹ���.
				CLASS_DECL_DESTRUCTOR(i_ModelRenderer)(void)
				{

				}

				// ���� : 
				INTERFACE_DECL_FUNC_T(void, initialize)(
					/* [x] */ void) = 0;
					
				// ���� : 
				INTERFACE_DECL_FUNC_T(void, render)(
					/* [x] */ void) = 0;

			};

		}
	}
}