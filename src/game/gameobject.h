#pragma once



#include "interface/actionlayer.h"
#include "datatable.h"
#include "controller.h"
#include "actionbase.h"
#include "renderer.h"
#include "../hsdk/autodelete.h"
#include <list>



namespace hsdk
{
	namespace game
	{

		// 설명 : 
		DECL_CLASS(GameObject)
			: public i::i_ActionListener
		{
		public:

			// 설명 : 
			INTERFACE_DECL_FUNC_T(void, update)(
				_X_ void);

			// 설명 : 
			INTERFACE_DECL_FUNC_T(void, render)(
				_X_ void);

			// 설명 : 
			INTERFACE_DECL_FUNC_T(void, set_Datatalbe)(
				/* [set] */ DataTable * _datatable);

			// 설명 : 
			INTERFACE_DECL_FUNC_T(void, set_Controller)(
				/* [set] */ Controller * _controller);

			// 설명 : 
			INTERFACE_DECL_FUNC_T(void, set_ActionBase)(
				/* [set] */ ActionBase * _actionbase);

			// 설명 : 
			INTERFACE_DECL_FUNC_T(void, set_Renderer)(
				/* [set] */ Renderer * _renderer);

			// 설명 : 
			INTERFACE_DECL_FUNC_T(i::i_DataTable *, get_Datatalbe)(
				_X_ void)const;

			// 설명 : 
			INTERFACE_DECL_FUNC_T(i::i_Controller *, get_Controller)(
				_X_ void)const;

			// 설명 : 
			INTERFACE_DECL_FUNC_T(i::i_ActionBase *, get_ActionBase)(
				_X_ void)const;

			// 설명 : 
			INTERFACE_DECL_FUNC_T(i::i_Renderer *, get_Renderer)(
				_X_ void)const;

			// 설명 :
			INTERFACE_DECL_FUNC_T(void, listen_Action)(
				_Ref_ i::i_ActionLayer * _actionlayer)final;

		protected:

			// 설명 :
			CLASS_DECL_FUNC_T(void, act_ActionLayers)(
				_X_ void);

		protected:

			// 설명 : 
			AutoDelete<DataTable> m_DataTable;

			// 설명 : 
			AutoDelete<Controller> m_Controller;

			// 설명 : 
			AutoDelete<ActionBase> m_ActionBase;

			// 설명 : 
			AutoDelete<Renderer> m_Renderer;

		private:

			// 설명 :
			std::list<i::i_ActionLayer *> my_Effects;

			// 설명 :
			i::i_ActionLayer * my_Action;

		};

	}
}