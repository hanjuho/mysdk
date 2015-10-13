#pragma once



#include "../interface/datatable.h"



namespace hsdk
{
	namespace game
	{
		namespace datatable
		{

			// ���� : 
			DLL_DECL_CLASS(ObjectDataTable)
				: public i::i_DataTable
			{
			public:

				CLASS_DECL_CONSTRUCTOR(ObjectDataTable)(void);

				// �Ҹ���.
				CLASS_DECL_DESTRUCTOR(ObjectDataTable)(void);

				// ���� : 
				INTERFACE_DECL_FUNC(read_Table)(
					/* [r] */ unsigned int _state,
					/* [w] */ void * (&_data),
					/* [r] */ unsigned int _size)const;

				// ���� : 
				INTERFACE_DECL_FUNC(write_Table)(
					/* [r] */ unsigned int _state,
					/* [r] */ ...);

			protected:



			};

		}
	}
}