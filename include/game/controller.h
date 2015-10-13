#pragma once



#include "interface/controller.h"
#include "interface/actionlistener.h"



namespace hsdk
{
	namespace game
	{

		// 설명 : 
		DLL_DECL_CLASS(Controller)
			: public i::i_Controller
		{
		public:

			// 생성자.
			CLASS_DECL_CONSTRUCTOR(Controller)(void);

			// 소멸자.
			CLASS_DECL_DESTRUCTOR(Controller)(void);

			// 설명 :
			INTERFACE_DECL_FUNC_T(void, attack)(
				/* [r] */ long _flag);

			// 설명 :
			INTERFACE_DECL_FUNC_T(void, suffer)(
				/* [r] */ unsigned int _frequency,
				/* [r] */ float _amount,
				/* [r] */ long _flag);

			// 설명 :
			INTERFACE_DECL_FUNC_T(void, move)(
				/* [r] */ float _x,
				/* [r] */ float _y,
				/* [r] */ long _flag);

			// 설명 :
			INTERFACE_DECL_FUNC_T(void, wait)(
				/* [r] */ long _flag);

			// 설명 :
			INTERFACE_DECL_FUNC_T(void, effect)(
				/* [r] */ unsigned int _effect,
				/* [r] */ long _flag);

			// 설명 :
			INTERFACE_DECL_FUNC_T(void, recovery)(
				/* [r] */ unsigned int _frequency,
				/* [r] */ float _amount,
				/* [r] */ long _flag);

			// 설명 :
			INTERFACE_DECL_FUNC_T(void, resurrect)(
				/* [r] */ long _flag);

			// 설명 :
			INTERFACE_DECL_FUNC_T(void, disappear)(
				/* [r] */ long _flag);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, link_ActionBase)(
				/* [ref] */ i::i_ActionBase * _actionbase);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, link_ActionListener)(
				/* [ref] */ i::i_ActionListener * _actionlistener);

		protected:

			// 설명 : 
			i::i_ActionBase * m_ActionBase;

			// 설명 : 
			i::i_ActionListener * m_ActionListener;

		};

	}
}