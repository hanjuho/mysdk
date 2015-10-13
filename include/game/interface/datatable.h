#pragma once



#include "common.h"



namespace hsdk
{
	namespace game
	{
		namespace i
		{

			// 설명 : 
			DLL_DECL_INTERFACE(i_DataTable)
			{

				// 소멸자.
				CLASS_DECL_DESTRUCTOR(i_DataTable)(void)
				{

				}
								
				// 설명 : 
				INTERFACE_DECL_FUNC(read_Table)(
					/* [r] */ unsigned int _offset,
					/* [r] */ unsigned int _size,
					/* [w] */ void * (&_data))const = 0;

				// 설명 : 
				INTERFACE_DECL_FUNC(write_Table)(
					/* [r] */ unsigned int _datavalue,
					/* [r] */ ...) = 0;

				// 설명 : 
				INTERFACE_DECL_FUNC_T(const wchar_t *, name)(
					/* [x] */ void)const = 0;

				// 설명 : 
				INTERFACE_DECL_FUNC_T(unsigned int, type)(
					/* [x] */ void)const = 0;

				// 설명 : 
				INTERFACE_DECL_FUNC_T(unsigned int, state)(
					/* [x] */ void)const = 0;

			};

		}
	}
}