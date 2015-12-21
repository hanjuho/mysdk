#pragma once



#include "interface/controller.h"
#include "interface/actionlistener.h"



namespace hsdk
{
	namespace game
	{

		// ���� : 
		DECL_CLASS(Controller)
			: public i::i_Controller
		{
		public:

			// ���� :
			INTERFACE_DECL_FUNC_T(void, attack)(
				_In_ long _flag);

			// ���� :
			INTERFACE_DECL_FUNC_T(void, suffer)(
				_In_ unsigned int _frequency,
				_In_ float _amount,
				_In_ long _flag);

			// ���� :
			INTERFACE_DECL_FUNC_T(void, move)(
				_In_ float _x,
				_In_ float _y,
				_In_ long _flag);

			// ���� :
			INTERFACE_DECL_FUNC_T(void, wait)(
				_In_ long _flag);

			// ���� :
			INTERFACE_DECL_FUNC_T(void, effect)(
				_In_ unsigned int _effect,
				_In_ long _flag);

			// ���� :
			INTERFACE_DECL_FUNC_T(void, recovery)(
				_In_ unsigned int _frequency,
				_In_ float _amount,
				_In_ long _flag);

			// ���� :
			INTERFACE_DECL_FUNC_T(void, resurrect)(
				_In_ long _flag);

			// ���� :
			INTERFACE_DECL_FUNC_T(void, disappear)(
				_In_ long _flag);

			// ���� : 
			CLASS_DECL_FUNC_T(void, link_ActionBase)(
				_Ref_ i::i_ActionBase * _actionbase);

			// ���� : 
			CLASS_DECL_FUNC_T(void, link_ActionListener)(
				_Ref_ i::i_ActionListener * _actionlistener);

		protected:

			// ���� : 
			i::i_ActionBase * m_ActionBase = nullptr;

			// ���� : 
			i::i_ActionListener * m_ActionListener = nullptr;

		};

	}
}