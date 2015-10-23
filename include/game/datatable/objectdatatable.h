#pragma once



#include "../interface/datatable.h"



namespace hsdk
{
	namespace game
	{
		namespace datatable
		{

			// 설명 : 
			DLL_DECL_CLASS(ObjectDataTable)
				: public i::i_DataTable
			{
			public:

				CLASS_DECL_CONSTRUCTOR(ObjectDataTable)(void);

				// 소멸자.
				CLASS_DECL_DESTRUCTOR(ObjectDataTable)(void);

				// 설명 : 
				INTERFACE_DECL_FUNC(read_Table)(
					_In_ unsigned int _state,
					_Out_ void * (&_data),
					_In_ unsigned int _size)const;

				// 설명 : 
				INTERFACE_DECL_FUNC(write_Table)(
					_In_ unsigned int _state,
					_In_ ...);

			protected:



			};

		}
	}
}