#pragma once



#include "common.h"



namespace hsdk
{
	namespace game
	{
		namespace i
		{

			// ���� : 
			DECL_INTERFACE(i_GameObject)
			{

				// �Ҹ���.
				CLASS_DECL_DESTRUCTOR(i_GameObject)(void)
				{

				}

				// ���� : 
				INTERFACE_DECL_FUNC_T(i_DataTable *, datatalbe)(
					_X_ void)const = 0;

				// ���� : 
				INTERFACE_DECL_FUNC_T(i_Controller *, controller)(
					_X_ void)const = 0;

				// ���� : 
				INTERFACE_DECL_FUNC_T(i_ModelRenderer *, renderer)(
					_X_ void)const = 0;
				
				// ���� : 
				INTERFACE_DECL_FUNC_T(void, update)(
					_X_ void) = 0;

				// ���� : 
				INTERFACE_DECL_FUNC_T(void, render)(
					_X_ void) = 0;

			};

		}
	}
}