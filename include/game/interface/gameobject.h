#pragma once



#include "common.h"



namespace hsdk
{
	namespace game
	{
		namespace i
		{

			// ���� : 
			DLL_DECL_INTERFACE(i_GameObject)
			{

				// �Ҹ���.
				CLASS_DECL_DESTRUCTOR(i_GameObject)(void)
				{

				}

				// ���� : 
				INTERFACE_DECL_FUNC_T(i_DataTable *, datatalbe)(
					/* [x] */ void)const = 0;

				// ���� : 
				INTERFACE_DECL_FUNC_T(i_Controller *, controller)(
					/* [x] */ void)const = 0;

				// ���� : 
				INTERFACE_DECL_FUNC_T(i_ModelRenderer *, renderer)(
					/* [x] */ void)const = 0;
				
				// ���� : 
				INTERFACE_DECL_FUNC_T(void, update)(
					/* [x] */ void) = 0;

				// ���� : 
				INTERFACE_DECL_FUNC_T(void, render)(
					/* [x] */ void) = 0;

			};

		}
	}
}