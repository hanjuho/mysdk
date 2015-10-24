#pragma once



#include "interface/modelrenderer.h"



namespace hsdk
{
	namespace game
	{

		// 설명 : 
		DLL_DECL_CLASS(ModelRenderer)
			: public i::i_ModelRenderer
		{
		public:

			// 생성자.
			CLASS_DECL_CONSTRUCTOR(ModelRenderer)(void);

			// 소멸자.
			CLASS_DECL_DESTRUCTOR(ModelRenderer)(void);

			// 설명 : 
			INTERFACE_DECL_FUNC_T(void, initialize)(
				_X_ void);

			// 설명 : 
			INTERFACE_DECL_FUNC_T(void, render)(
				_X_ void);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, link_DataTable)(
				/* [ref] */ i::i_DataTable * _datatable);

		protected:

			// 설명 :
			i::i_DataTable * m_Datatable;

		};

	}
}