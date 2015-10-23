
#pragma once



#include "../interface/datatable.h"
#include <string>



namespace hsdk
{
	namespace game
	{
		namespace datatable
		{

			// ���� : 
			DLL_DECL_CLASS(BuildingDataTable)
				: public i::i_DataTable
			{
			public:

				enum DEFAULT_DATA
				{

				};

				// ������.
				CLASS_DECL_CONSTRUCTOR(BuildingDataTable)(
					const wchar_t * name,
					unsigned int type,
					unsigned int state,
					unsigned int maxLife,
					int defense);

				// �Ҹ���.
				CLASS_DECL_DESTRUCTOR(BuildingDataTable)(void);

				// ���� : 
				INTERFACE_DECL_FUNC(read_Table)(
					_In_ unsigned int _offset,
					_In_ unsigned int _size,
					_Out_ void * (&_data))const;

				// ���� : 
				INTERFACE_DECL_FUNC(write_Table)(
					_In_ unsigned int _state,
					_In_ ...);

				// ���� : 
				INTERFACE_DECL_FUNC_T(const wchar_t *, name)(
					/* [x] */ void)const;

				// ���� : 
				INTERFACE_DECL_FUNC_T(unsigned int, type)(
					/* [x] */ void)const;

				// ���� : 
				INTERFACE_DECL_FUNC_T(unsigned int, state)(
					/* [x] */ void)const;

			protected:

				// ���� : 
				std::wstring m_Name;

				// ���� : 
				unsigned int m_Type;
				
				// ���� : 
				unsigned int m_State;

				// ���� : 
				unsigned int m_MaxLife;

				// ���� : 
				unsigned int m_Life;

				// ���� : 
				int m_Defense;

			};

		}
	}
}