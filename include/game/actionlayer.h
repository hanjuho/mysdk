#pragma once



#include "interface/actionlayer.h"



namespace hsdk
{
	namespace game
	{

		// ���� : 
		DLL_DECL_CLASS(ActionLayer)
			: public i::i_ActionLayer
		{
		public:

			// ������.
			CLASS_DECL_CONSTRUCTOR(ActionLayer)(void);

			// �Ҹ���.
			CLASS_DECL_DESTRUCTOR(ActionLayer)(void);

			// ���� : 
			INTERFACE_DECL_FUNC_T(void, initialize)(
				/* [x] */ void);

			// ���� : 
			INTERFACE_DECL_FUNC_T(bool, act)(
				_In_ float _dt)const;

			// ���� :
			INTERFACE_DECL_FUNC_T(unsigned int, priority)(
				/* [x] */ void)const;

			// ���� :
			INTERFACE_DECL_FUNC_T(void, link_DataTable)(
				/* [ref] */ i::i_DataTable * _datatable);

		protected:

			// ���� : 
			i::i_DataTable * m_DataTable;

		};

	}
}