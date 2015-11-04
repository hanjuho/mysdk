#pragma once



#include "../../interface/frame/inputeventhelper.h"
#include "../../interface/frame/mouseable.h"
#include <Windows.h>



namespace hsdk
{
	namespace frame
	{

		// 설명 : 창의 구성 요소를 win32로 구현.
		DECL_CLASS(inputEventHelper)
			: public i::frame::i_inputEventHelper
		{
		public:

			// 생성자.
			CLASS_DECL_CONSTRUCTOR(inputEventHelper)(
				_In_ i::frame::i_Component * _component);

			// 가상 소멸자.
			CLASS_DECL_DESTRUCTOR(inputEventHelper)(void);

			/*
			설명 : component가 event 발생 조건을 충족하는지 검사.
			$ 참고 : 멤버변수 xy가 _component안에 있어야하며, i_Component::is_Visible의 반환 값이 참이어야 함.
			*/
			INTERFACE_DECL_FUNC_T(bool, chain)(
				_In_ const i::frame::i_Component * _component);

			/*
			설명 : input event focus 대상을 갱신.
			$ 참고 : 이 클래스 멤버함수 중 onClick_Down에서만 update가 호출됨.
			*/
			INTERFACE_DECL_FUNC_T(void, update)(
				_X_ void);

			// 설명 : mouse의 버튼이 눌렸을 때 발생하는 event.
			CLASS_DECL_FUNC_T(void, onClick_Down)(
				_In_ i::frame::MOUSE_BUTTON _button,
				_In_ int _x,
				_In_ int _y);

			// 설명 : mouse의 버튼이 눌렸다가 때면 발생하는 event.
			CLASS_DECL_FUNC_T(void, onClick_Up)(
				_In_ i::frame::MOUSE_BUTTON _button,
				_In_ int _x,
				_In_ int _y);

			// 설명 : mouse의 버튼을 누른 채 커서를 이동하면 발생하는 event.
			CLASS_DECL_FUNC_T(void, onDrag)(
				_In_ i::frame::MOUSE_BUTTON _button,
				_In_ int _x,
				_In_ int _y);

			// 설명 : mouse의 커서를 이동시키면 발생하는 event.
			CLASS_DECL_FUNC_T(void, onMove)(
				_In_ int _x,
				_In_ int _y);

			// 설명 : mouse의 wheel을 조작하면 발생하는 event.
			CLASS_DECL_FUNC_T(void, onWheel)(
				_In_ int _x,
				_In_ int _y,
				_In_ int _w);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, restore)(
				_In_ i::frame::i_Component * _component);

		public:

			/*
			설명 : 마우스 좌표. update를 호출하면 xy에 맞는 component를 갱신
			$ 참고 :
			*/
			POINT xy;

		private:

			// 설명 : event helper가 주시하고 있는 component
			i::frame::i_Component * my_FocusComponent;

		};

	}
}