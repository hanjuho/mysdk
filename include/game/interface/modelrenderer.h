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
					_X_ void) = 0;
					
				// ���� : 
				INTERFACE_DECL_FUNC_T(void, render)(
					_X_ void) = 0;

			};

		}
	}
}