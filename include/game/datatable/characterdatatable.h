#pragma once



#include "../interface/datatable.h"



namespace hsdk
{
	namespace game
	{
		namespace datatable
		{

			// 설명 : 
			DLL_DECL_CLASS(CharacterDataTable)
				: public i::i_DataTable
			{
			public:

				// 생성자.
				CLASS_DECL_CONSTRUCTOR(CharacterDataTable)(void);

				// 소멸자.
				CLASS_DECL_DESTRUCTOR(CharacterDataTable)(void);

				// 설명 : 
				INTERFACE_DECL_FUNC(read_Table)(
					/* [r] */ unsigned int _state,
					/* [w] */ void * (&_data),
					/* [r] */ unsigned int _size)const;

				// 설명 : 
				INTERFACE_DECL_FUNC(write_Table)(
					/* [r] */ unsigned int _state,
					/* [r] */ ...);

			protected:

				// 설명 : 
				unsigned int m_MaxLife;

				// 설명 : 
				unsigned int m_Life;

				// 설명 : 
				unsigned int m_MaxMana;

				// 설명 : 
				unsigned int m_Mana;

				// 설명 : 
				unsigned int m_Attack;

				// 설명 : 
				unsigned int m_Defense;

			};

		}
	}
}