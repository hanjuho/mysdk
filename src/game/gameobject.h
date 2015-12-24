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

		// ���� : 
		DECL_CLASS(GameObject)
			: public i::i_ActionListener
		{
		public:

			// ���� : 
			INTERFACE_DECL_FUNC_T(void, update)(
				_X_ void);

			// ���� : 
			INTERFACE_DECL_FUNC_T(void, render)(
				_X_ void);

			// ���� : 
			INTERFACE_DECL_FUNC_T(void, set_Datatalbe)(
				/* [set] */ DataTable * _datatable);

			// ���� : 
			INTERFACE_DECL_FUNC_T(void, set_Controller)(
				/* [set] */ Controller * _controller);

			// ���� : 
			INTERFACE_DECL_FUNC_T(void, set_ActionBase)(
				/* [set] */ ActionBase * _actionbase);

			// ���� : 
			INTERFACE_DECL_FUNC_T(void, set_Renderer)(
				/* [set] */ Renderer * _renderer);

			// ���� : 
			INTERFACE_DECL_FUNC_T(i::i_DataTable *, get_Datatalbe)(
				_X_ void)const;

			// ���� : 
			INTERFACE_DECL_FUNC_T(i::i_Controller *, get_Controller)(
				_X_ void)const;

			// ���� : 
			INTERFACE_DECL_FUNC_T(i::i_ActionBase *, get_ActionBase)(
				_X_ void)const;

			// ���� : 
			INTERFACE_DECL_FUNC_T(i::i_Renderer *, get_Renderer)(
				_X_ void)const;

			// ���� :
			INTERFACE_DECL_FUNC_T(void, listen_Action)(
				_Ref_ i::i_ActionLayer * _actionlayer)final;

		protected:

			// ���� :
			CLASS_DECL_FUNC_T(void, act_ActionLayers)(
				_X_ void);

		protected:

			// ���� : 
			AutoDelete<DataTable> m_DataTable;

			// ���� : 
			AutoDelete<Controller> m_Controller;

			// ���� : 
			AutoDelete<ActionBase> m_ActionBase;

			// ���� : 
			AutoDelete<Renderer> m_Renderer;

		private:

			// ���� :
			std::list<i::i_ActionLayer *> my_Effects;

			// ���� :
			i::i_ActionLayer * my_Action;

		};

	}
}