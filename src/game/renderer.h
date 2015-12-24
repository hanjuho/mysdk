#pragma once



#include "interface/renderer.h"



namespace hsdk
{
	namespace game
	{

		// 설명 : 
		DECL_CLASS(Renderer)
			: public i::i_Renderer
		{
		public:

			// 설명 : 
			INTERFACE_DECL_FUNC_T(void, render)(
				_X_ void);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, link_DataTable)(
				_Ref_ i::i_DataTable * _datatable);

		protected:

			// 설명 :
			i::i_DataTable * m_Datatable = nullptr;

		};

	}
}