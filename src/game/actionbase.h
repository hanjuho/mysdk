#pragma once



#include "interface/actiontable.h"



namespace hsdk
{
	namespace game
	{

		// 설명 :
		DECL_CLASS(ActionBase)
			: public i::i_ActionBase
		{
		public:

			// 생성자.
			CLASS_DECL_CONSTRUCTOR(ActionBase)(void);

			// 소멸자.
			CLASS_DECL_DESTRUCTOR(ActionBase)(void);

			// 설명 :
			INTERFACE_DECL_FUNC_T(i::i_ActionLayer *, attack)(
				_In_ long _flag);

			// 설명 :
			INTERFACE_DECL_FUNC_T(i::i_ActionLayer *, suffer)(
				_In_ unsigned int _frequency,
				_In_ float _amount,
				_In_ long _flag);

			// 설명 :
			INTERFACE_DECL_FUNC_T(i::i_ActionLayer *, move)(
				_In_ float _x,
				_In_ float _y,
				_In_ long _flag);

			// 설명 :
			INTERFACE_DECL_FUNC_T(i::i_ActionLayer *, wait)(
				_In_ long _flag);

			// 설명 :
			INTERFACE_DECL_FUNC_T(i::i_ActionLayer *, effect)(
				_In_ unsigned int _effect,
				_In_ long _flag);

			// 설명 :
			INTERFACE_DECL_FUNC_T(i::i_ActionLayer *, recovery)(
				_In_ unsigned int _frequency,
				_In_ float _amount,
				_In_ long _flag);

			// 설명 :
			INTERFACE_DECL_FUNC_T(i::i_ActionLayer *, resurrect)(
				_In_ long _flag);

			// 설명 :
			INTERFACE_DECL_FUNC_T(i::i_ActionLayer *, disappear)(
				_In_ long _flag);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, link_DataTable)(
				_Ref_ i::i_DataTable * _datatable);

		protected:

			// 설명 :
			i::i_DataTable * m_Datatable;

		};

	}
}