#pragma once



#include "component.h"



namespace hsdk
{
	namespace frame
	{

		// 설명 :
		DECL_CLASS(ButtonCompo)
			: public Component
		{

		public:

			// 생성자.
			CLASS_DECL_CONSTRUCTOR(ButtonCompo)(
				_In_ PARENT_RELATION _relation = PARENT_RELATION_ABSOLUTE);

			// 설명 : 
			INTERFACE_DECL_FUNC_T(void, onMouse_Enter)(
				_In_ int _x,
				_In_ int _y);

			// 설명 : 
			INTERFACE_DECL_FUNC_T(void, onMouse_Exit)(
				_In_ int _x,
				_In_ int _y);

			// 설명 : mouse의 버튼이 눌렸을 때 발생하는 event.
			INTERFACE_DECL_FUNC_T(void, onClick_Down)(
				_In_ i::frame::MOUSE_BUTTON _button,
				_In_ int _x,
				_In_ int _y);

			// 설명 : mouse의 버튼이 눌렸다가 때면 발생하는 event.
			INTERFACE_DECL_FUNC_T(void, onClick_Up)(
				_In_ i::frame::MOUSE_BUTTON _button,
				_In_ int _x,
				_In_ int _y);

			// 설명 : component를 화면에 뿌려줌.
			INTERFACE_DECL_FUNC_T(void, render)(
				_X_ void);

		protected:

			// 설명 : 
			bool m_light = false;

			// 설명 : 
			bool m_alpha = false;

		};

	}
}