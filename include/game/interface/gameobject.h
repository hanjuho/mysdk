#pragma once



#include "common.h"



namespace hsdk
{
	namespace game
	{
		namespace i
		{

			// 설명 : 
			DLL_DECL_INTERFACE(i_GameObject)
			{

				// 소멸자.
				CLASS_DECL_DESTRUCTOR(i_GameObject)(void)
				{

				}

				// 설명 : 
				INTERFACE_DECL_FUNC_T(i_DataTable *, datatalbe)(
					/* [x] */ void)const = 0;

				// 설명 : 
				INTERFACE_DECL_FUNC_T(i_Controller *, controller)(
					/* [x] */ void)const = 0;

				// 설명 : 
				INTERFACE_DECL_FUNC_T(i_ModelRenderer *, renderer)(
					/* [x] */ void)const = 0;
				
				// 설명 : 
				INTERFACE_DECL_FUNC_T(void, update)(
					/* [x] */ void) = 0;

				// 설명 : 
				INTERFACE_DECL_FUNC_T(void, render)(
					/* [x] */ void) = 0;

			};

		}
	}
}