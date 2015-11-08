#pragma once



#include "interface/gameobject.h"
#include "interface/datatable.h"
#include "interface/actionlayer.h"
#include "controller.h"
#include "actionbase.h"
#include "modelrenderer.h"
#include "../hsdk/autodelete.h"
#include <list>



namespace hsdk
{
	namespace game
	{

		// 설명 : 
		DECL_CLASS(GameObject)
			: public i::i_GameObject, public i::i_ActionListener
		{
		public:

			// 생성자.
			CLASS_DECL_CONSTRUCTOR(GameObject)(
				/* [set] */ i::i_DataTable * _datatable,
				/* [set] */ Controller * _controller,
				/* [set] */ ActionBase *_actionbase,
				/* [set] */ ModelRenderer * _renderer);

			// 소멸자.
			CLASS_DECL_DESTRUCTOR(GameObject)(void);

			// 설명 : 
			INTERFACE_DECL_FUNC_T(i::i_DataTable *, datatalbe)(
				_X_ void)const;

			// 설명 : 
			INTERFACE_DECL_FUNC_T(i::i_Controller *, controller)(
				_X_ void)const;

			// 설명 : 
			INTERFACE_DECL_FUNC_T(i::i_ModelRenderer *, renderer)(
				_X_ void)const;

			// 설명 : 
			INTERFACE_DECL_FUNC_T(void, update)(
				_X_ void);

			// 설명 : 
			INTERFACE_DECL_FUNC_T(void, render)(
				_X_ void);

			// 설명 :
			INTERFACE_DECL_FUNC_T(void, listen_Action)(
				_Ref_ i::i_ActionLayer * _actionlayer)final;

		protected:

			// 설명 :
			CLASS_DECL_FUNC_T(void, act_ActionLayers)(
				_X_ void);

		protected:

			// 설명 : 
			AutoDelete<i::i_DataTable> m_DataTable;

			// 설명 : 
			AutoDelete<Controller> m_Controller;

			// 설명 : 
			AutoDelete<ActionBase> m_ActionBase;

			// 설명 : 
			AutoDelete<ModelRenderer> m_Renderer;

		private:

			// 설명 :
			std::list<i::i_ActionLayer *> my_Effects;

			// 설명 :
			i::i_ActionLayer * my_Action;

		};

	}
}