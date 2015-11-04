#pragma once



#include "common.h"



namespace hsdk
{
	namespace game
	{
		namespace i
		{

			// 설명 : 
			DECL_INTERFACE(i_GameObject)
			{

				// 소멸자.
				CLASS_DECL_DESTRUCTOR(i_GameObject)(void)
				{

				}

				// 설명 : 
				INTERFACE_DECL_FUNC_T(i_DataTable *, datatalbe)(
					_X_ void)const = 0;

				// 설명 : 
				INTERFACE_DECL_FUNC_T(i_Controller *, controller)(
					_X_ void)const = 0;

				// 설명 : 
				INTERFACE_DECL_FUNC_T(i_ModelRenderer *, renderer)(
					_X_ void)const = 0;
				
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