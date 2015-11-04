#pragma once



#include "component.h"



namespace hsdk
{
	namespace frame
	{

		// ���� :
		DECL_CLASS(ButtonCompo)
			: public Component
		{

		public:

			// ������.
			CLASS_DECL_CONSTRUCTOR(ButtonCompo)(
				_In_ PARENT_RELATION _relation = PARENT_RELATION_ABSOLUTE);

			// ���� : 
			INTERFACE_DECL_FUNC_T(void, onMouse_Enter)(
				_In_ int _x,
				_In_ int _y);

			// ���� : 
			INTERFACE_DECL_FUNC_T(void, onMouse_Exit)(
				_In_ int _x,
				_In_ int _y);

			// ���� : mouse�� ��ư�� ������ �� �߻��ϴ� event.
			INTERFACE_DECL_FUNC_T(void, onClick_Down)(
				_In_ i::frame::MOUSE_BUTTON _button,
				_In_ int _x,
				_In_ int _y);

			// ���� : mouse�� ��ư�� ���ȴٰ� ���� �߻��ϴ� event.
			INTERFACE_DECL_FUNC_T(void, onClick_Up)(
				_In_ i::frame::MOUSE_BUTTON _button,
				_In_ int _x,
				_In_ int _y);

			// ���� : component�� ȭ�鿡 �ѷ���.
			INTERFACE_DECL_FUNC_T(void, render)(
				_X_ void);

		protected:

			// ���� : 
			bool m_light = false;

			// ���� : 
			bool m_alpha = false;

		};

	}
}