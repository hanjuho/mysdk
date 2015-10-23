#pragma once



#include "interface/actionlayer.h"



namespace hsdk
{
	namespace game
	{

		// 설명 : 
		DLL_DECL_CLASS(ActionLayer)
			: public i::i_ActionLayer
		{
		public:

			// 생성자.
			CLASS_DECL_CONSTRUCTOR(ActionLayer)(void);

			// 소멸자.
			CLASS_DECL_DESTRUCTOR(ActionLayer)(void);

			// 설명 : 
			INTERFACE_DECL_FUNC_T(void, initialize)(
				/* [x] */ void);

			// 설명 : 
			INTERFACE_DECL_FUNC_T(bool, act)(
				_In_ float _dt)const;

			// 설명 :
			INTERFACE_DECL_FUNC_T(unsigned int, priority)(
				/* [x] */ void)const;

			// 설명 :
			INTERFACE_DECL_FUNC_T(void, link_DataTable)(
				/* [ref] */ i::i_DataTable * _datatable);

		protected:

			// 설명 : 
			i::i_DataTable * m_DataTable;

		};

	}
}