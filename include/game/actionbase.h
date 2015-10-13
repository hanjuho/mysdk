#pragma once



#include "interface/actiontable.h"



namespace hsdk
{
	namespace game
	{

		// 설명 :
		DLL_DECL_CLASS(ActionBase)
			: public i::i_ActionBase
		{
		public:

			// 생성자.
			CLASS_DECL_CONSTRUCTOR(ActionBase)(void);

			// 소멸자.
			CLASS_DECL_DESTRUCTOR(ActionBase)(void);

			// 설명 :
			INTERFACE_DECL_FUNC_T(i::i_ActionLayer *, attack)(
				/* [r] */ long _flag);

			// 설명 :
			INTERFACE_DECL_FUNC_T(i::i_ActionLayer *, suffer)(
				/* [r] */ unsigned int _frequency,
				/* [r] */ float _amount,
				/* [r] */ long _flag);

			// 설명 :
			INTERFACE_DECL_FUNC_T(i::i_ActionLayer *, move)(
				/* [r] */ float _x,
				/* [r] */ float _y,
				/* [r] */ long _flag);

			// 설명 :
			INTERFACE_DECL_FUNC_T(i::i_ActionLayer *, wait)(
				/* [r] */ long _flag);

			// 설명 :
			INTERFACE_DECL_FUNC_T(i::i_ActionLayer *, effect)(
				/* [r] */ unsigned int _effect,
				/* [r] */ long _flag);

			// 설명 :
			INTERFACE_DECL_FUNC_T(i::i_ActionLayer *, recovery)(
				/* [r] */ unsigned int _frequency,
				/* [r] */ float _amount,
				/* [r] */ long _flag);

			// 설명 :
			INTERFACE_DECL_FUNC_T(i::i_ActionLayer *, resurrect)(
				/* [r] */ long _flag);

			// 설명 :
			INTERFACE_DECL_FUNC_T(i::i_ActionLayer *, disappear)(
				/* [r] */ long _flag);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, link_DataTable)(
				/* [ref] */ i::i_DataTable * _datatable);

		protected:

			// 설명 :
			i::i_DataTable * m_Datatable;

		};

	}
}