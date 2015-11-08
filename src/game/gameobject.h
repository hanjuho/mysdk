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

		// ���� : 
		DECL_CLASS(GameObject)
			: public i::i_GameObject, public i::i_ActionListener
		{
		public:

			// ������.
			CLASS_DECL_CONSTRUCTOR(GameObject)(
				/* [set] */ i::i_DataTable * _datatable,
				/* [set] */ Controller * _controller,
				/* [set] */ ActionBase *_actionbase,
				/* [set] */ ModelRenderer * _renderer);

			// �Ҹ���.
			CLASS_DECL_DESTRUCTOR(GameObject)(void);

			// ���� : 
			INTERFACE_DECL_FUNC_T(i::i_DataTable *, datatalbe)(
				_X_ void)const;

			// ���� : 
			INTERFACE_DECL_FUNC_T(i::i_Controller *, controller)(
				_X_ void)const;

			// ���� : 
			INTERFACE_DECL_FUNC_T(i::i_ModelRenderer *, renderer)(
				_X_ void)const;

			// ���� : 
			INTERFACE_DECL_FUNC_T(void, update)(
				_X_ void);

			// ���� : 
			INTERFACE_DECL_FUNC_T(void, render)(
				_X_ void);

			// ���� :
			INTERFACE_DECL_FUNC_T(void, listen_Action)(
				_Ref_ i::i_ActionLayer * _actionlayer)final;

		protected:

			// ���� :
			CLASS_DECL_FUNC_T(void, act_ActionLayers)(
				_X_ void);

		protected:

			// ���� : 
			AutoDelete<i::i_DataTable> m_DataTable;

			// ���� : 
			AutoDelete<Controller> m_Controller;

			// ���� : 
			AutoDelete<ActionBase> m_ActionBase;

			// ���� : 
			AutoDelete<ModelRenderer> m_Renderer;

		private:

			// ���� :
			std::list<i::i_ActionLayer *> my_Effects;

			// ���� :
			i::i_ActionLayer * my_Action;

		};

	}
}