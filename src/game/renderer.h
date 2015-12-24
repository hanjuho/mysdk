#pragma once



#include "interface/renderer.h"



namespace hsdk
{
	namespace game
	{

		// ���� : 
		DECL_CLASS(Renderer)
			: public i::i_Renderer
		{
		public:

			// ���� : 
			INTERFACE_DECL_FUNC_T(void, render)(
				_X_ void);

			// ���� : 
			CLASS_DECL_FUNC_T(void, link_DataTable)(
				_Ref_ i::i_DataTable * _datatable);

		protected:

			// ���� :
			i::i_DataTable * m_Datatable = nullptr;

		};

	}
}