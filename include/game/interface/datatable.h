#pragma once



#include "common.h"



namespace hsdk
{
	namespace game
	{
		namespace i
		{

			// ���� : 
			DLL_DECL_INTERFACE(i_DataTable)
			{

				// �Ҹ���.
				CLASS_DECL_DESTRUCTOR(i_DataTable)(void)
				{

				}
								
				// ���� : 
				INTERFACE_DECL_FUNC(read_Table)(
					/* [r] */ unsigned int _offset,
					/* [r] */ unsigned int _size,
					/* [w] */ void * (&_data))const = 0;

				// ���� : 
				INTERFACE_DECL_FUNC(write_Table)(
					/* [r] */ unsigned int _datavalue,
					/* [r] */ ...) = 0;

				// ���� : 
				INTERFACE_DECL_FUNC_T(const wchar_t *, name)(
					/* [x] */ void)const = 0;

				// ���� : 
				INTERFACE_DECL_FUNC_T(unsigned int, type)(
					/* [x] */ void)const = 0;

				// ���� : 
				INTERFACE_DECL_FUNC_T(unsigned int, state)(
					/* [x] */ void)const = 0;

			};

		}
	}
}