
#pragma once



#include "../interface/datatable.h"
#include <string>



namespace hsdk
{
	namespace game
	{
		namespace datatable
		{

			// 설명 : 
			DLL_DECL_CLASS(BuildingDataTable)
				: public i::i_DataTable
			{
			public:

				enum DEFAULT_DATA
				{

				};

				// 생성자.
				CLASS_DECL_CONSTRUCTOR(BuildingDataTable)(
					const wchar_t * name,
					unsigned int type,
					unsigned int state,
					unsigned int maxLife,
					int defense);

				// 소멸자.
				CLASS_DECL_DESTRUCTOR(BuildingDataTable)(void);

				// 설명 : 
				INTERFACE_DECL_FUNC(read_Table)(
					_In_ unsigned int _offset,
					_In_ unsigned int _size,
					_Out_ void * (&_data))const;

				// 설명 : 
				INTERFACE_DECL_FUNC(write_Table)(
					_In_ unsigned int _state,
					_In_ ...);

				// 설명 : 
				INTERFACE_DECL_FUNC_T(const wchar_t *, name)(
					/* [x] */ void)const;

				// 설명 : 
				INTERFACE_DECL_FUNC_T(unsigned int, type)(
					/* [x] */ void)const;

				// 설명 : 
				INTERFACE_DECL_FUNC_T(unsigned int, state)(
					/* [x] */ void)const;

			protected:

				// 설명 : 
				std::wstring m_Name;

				// 설명 : 
				unsigned int m_Type;
				
				// 설명 : 
				unsigned int m_State;

				// 설명 : 
				unsigned int m_MaxLife;

				// 설명 : 
				unsigned int m_Life;

				// 설명 : 
				int m_Defense;

			};

		}
	}
}