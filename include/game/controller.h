#pragma once



#include "interface/controller.h"
#include "interface/actionlistener.h"



namespace hsdk
{
	namespace game
	{

		// ���� : 
		DLL_DECL_CLASS(Controller)
			: public i::i_Controller
		{
		public:

			// ������.
			CLASS_DECL_CONSTRUCTOR(Controller)(void);

			// �Ҹ���.
			CLASS_DECL_DESTRUCTOR(Controller)(void);

			// ���� :
			INTERFACE_DECL_FUNC_T(void, attack)(
				/* [r] */ long _flag);

			// ���� :
			INTERFACE_DECL_FUNC_T(void, suffer)(
				/* [r] */ unsigned int _frequency,
				/* [r] */ float _amount,
				/* [r] */ long _flag);

			// ���� :
			INTERFACE_DECL_FUNC_T(void, move)(
				/* [r] */ float _x,
				/* [r] */ float _y,
				/* [r] */ long _flag);

			// ���� :
			INTERFACE_DECL_FUNC_T(void, wait)(
				/* [r] */ long _flag);

			// ���� :
			INTERFACE_DECL_FUNC_T(void, effect)(
				/* [r] */ unsigned int _effect,
				/* [r] */ long _flag);

			// ���� :
			INTERFACE_DECL_FUNC_T(void, recovery)(
				/* [r] */ unsigned int _frequency,
				/* [r] */ float _amount,
				/* [r] */ long _flag);

			// ���� :
			INTERFACE_DECL_FUNC_T(void, resurrect)(
				/* [r] */ long _flag);

			// ���� :
			INTERFACE_DECL_FUNC_T(void, disappear)(
				/* [r] */ long _flag);

			// ���� : 
			CLASS_DECL_FUNC_T(void, link_ActionBase)(
				/* [ref] */ i::i_ActionBase * _actionbase);

			// ���� : 
			CLASS_DECL_FUNC_T(void, link_ActionListener)(
				/* [ref] */ i::i_ActionListener * _actionlistener);

		protected:

			// ���� : 
			i::i_ActionBase * m_ActionBase;

			// ���� : 
			i::i_ActionListener * m_ActionListener;

		};

	}
}