#pragma once



#include "interface/actiontable.h"



namespace hsdk
{
	namespace game
	{

		// ���� :
		DLL_DECL_CLASS(ActionBase)
			: public i::i_ActionBase
		{
		public:

			// ������.
			CLASS_DECL_CONSTRUCTOR(ActionBase)(void);

			// �Ҹ���.
			CLASS_DECL_DESTRUCTOR(ActionBase)(void);

			// ���� :
			INTERFACE_DECL_FUNC_T(i::i_ActionLayer *, attack)(
				/* [r] */ long _flag);

			// ���� :
			INTERFACE_DECL_FUNC_T(i::i_ActionLayer *, suffer)(
				/* [r] */ unsigned int _frequency,
				/* [r] */ float _amount,
				/* [r] */ long _flag);

			// ���� :
			INTERFACE_DECL_FUNC_T(i::i_ActionLayer *, move)(
				/* [r] */ float _x,
				/* [r] */ float _y,
				/* [r] */ long _flag);

			// ���� :
			INTERFACE_DECL_FUNC_T(i::i_ActionLayer *, wait)(
				/* [r] */ long _flag);

			// ���� :
			INTERFACE_DECL_FUNC_T(i::i_ActionLayer *, effect)(
				/* [r] */ unsigned int _effect,
				/* [r] */ long _flag);

			// ���� :
			INTERFACE_DECL_FUNC_T(i::i_ActionLayer *, recovery)(
				/* [r] */ unsigned int _frequency,
				/* [r] */ float _amount,
				/* [r] */ long _flag);

			// ���� :
			INTERFACE_DECL_FUNC_T(i::i_ActionLayer *, resurrect)(
				/* [r] */ long _flag);

			// ���� :
			INTERFACE_DECL_FUNC_T(i::i_ActionLayer *, disappear)(
				/* [r] */ long _flag);

			// ���� : 
			CLASS_DECL_FUNC_T(void, link_DataTable)(
				/* [ref] */ i::i_DataTable * _datatable);

		protected:

			// ���� :
			i::i_DataTable * m_Datatable;

		};

	}
}