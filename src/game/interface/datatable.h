#pragma once



#include "common.h"



namespace hsdk
{
	namespace game
	{
		namespace i
		{

			// ���� : 
			DECL_INTERFACE(i_DataTable)
			{

				// �Ҹ���.
				CLASS_DECL_DESTRUCTOR(i_DataTable)(void)
				{

				}
								
				// ���� : 
				INTERFACE_DECL_FUNC(read_Table)(
					_In_ unsigned int _offset,
					_In_ unsigned int _size,
					_Out_ void * (&_data))const = 0;

				// ���� : 
				INTERFACE_DECL_FUNC(write_Table)(
					_In_ unsigned int _datavalue,
					_In_ ...) = 0;

				// ���� : 
				INTERFACE_DECL_FUNC_T(const wchar_t *, name)(
					_X_ void)const = 0;

				// ���� : 
				INTERFACE_DECL_FUNC_T(unsigned int, type)(
					_X_ void)const = 0;

				// ���� : 
				INTERFACE_DECL_FUNC_T(unsigned int, state)(
					_X_ void)const = 0;

			};

		}
	}
}