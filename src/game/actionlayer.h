#pragma once



#include "interface/actionlayer.h"



namespace hsdk
{
	namespace game
	{

		// 설명 : 
		DECL_CLASS(ActionLayer)
			: public i::i_ActionLayer
		{
		public:

			// 설명 : 
			INTERFACE_DECL_FUNC_T(void, initialize)(
				_X_ void);

			// 설명 : 
			INTERFACE_DECL_FUNC_T(bool, act)(
				_In_ float _dt)const;

			// 설명 :
			INTERFACE_DECL_FUNC_T(unsigned int, priority)(
				_X_ void)const;

			// 설명 :
			INTERFACE_DECL_FUNC_T(void, link_DataTable)(
				_Ref_ i::i_DataTable * _datatable);

		protected:

			// 설명 : 
			i::i_DataTable * m_DataTable = nullptr;

		};

	}
}