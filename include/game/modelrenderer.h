#pragma once



#include "interface/modelrenderer.h"



namespace hsdk
{
	namespace game
	{

		// ���� : 
		DLL_DECL_CLASS(ModelRenderer)
			: public i::i_ModelRenderer
		{
		public:

			// ������.
			CLASS_DECL_CONSTRUCTOR(ModelRenderer)(void);

			// �Ҹ���.
			CLASS_DECL_DESTRUCTOR(ModelRenderer)(void);

			// ���� : 
			INTERFACE_DECL_FUNC_T(void, initialize)(
				_X_ void);

			// ���� : 
			INTERFACE_DECL_FUNC_T(void, render)(
				_X_ void);

			// ���� : 
			CLASS_DECL_FUNC_T(void, link_DataTable)(
				/* [ref] */ i::i_DataTable * _datatable);

		protected:

			// ���� :
			i::i_DataTable * m_Datatable;

		};

	}
}