#pragma once



#include "../interface/datatable.h"



namespace hsdk
{
	namespace game
	{
		namespace datatable
		{

			// ���� : 
			DLL_DECL_CLASS(CharacterDataTable)
				: public i::i_DataTable
			{
			public:

				// ������.
				CLASS_DECL_CONSTRUCTOR(CharacterDataTable)(void);

				// �Ҹ���.
				CLASS_DECL_DESTRUCTOR(CharacterDataTable)(void);

				// ���� : 
				INTERFACE_DECL_FUNC(read_Table)(
					_In_ unsigned int _state,
					_Out_ void * (&_data),
					_In_ unsigned int _size)const;

				// ���� : 
				INTERFACE_DECL_FUNC(write_Table)(
					_In_ unsigned int _state,
					_In_ ...);

			protected:

				// ���� : 
				unsigned int m_MaxLife;

				// ���� : 
				unsigned int m_Life;

				// ���� : 
				unsigned int m_MaxMana;

				// ���� : 
				unsigned int m_Mana;

				// ���� : 
				unsigned int m_Attack;

				// ���� : 
				unsigned int m_Defense;

			};

		}
	}
}