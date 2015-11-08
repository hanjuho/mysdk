#pragma once



#include "common.h"
#include "layout.h"



namespace hsdk
{
	namespace i
	{
		namespace frame
		{

			// 설명 : 창의 구성 요소를 추상화.
			DECL_INTERFACE(i_Component)
			{

				// 가상 소멸자.
				CLASS_DECL_DESTRUCTOR(i_Component)(void)
				{

				}

				// 설명 : 이 component를 포함하고 있는 부모의 주소 반환.
				INTERFACE_DECL_FUNC_T(i_Component *, parent)(
					_X_ void)const = 0;

				// 설명 : component의 시각적 요소에 접근.
				INTERFACE_DECL_FUNC_T(i_Graphics *, graphics)(
					_X_ void)const = 0;

				// 설명 : 이 component에 새로운 컴포넌트를 추가.
				INTERFACE_DECL_FUNC(add_Component)(
					/* [set] */ i_Component * _component,
					_In_ LAYOUT_COMPOSITION _composition = COMPOSITION_DEFALUT) = 0;

				// 설명 : 이 component로부터 _component를 제거.
				INTERFACE_DECL_FUNC(remove_Component)(
					_Inout_ i_Component * _component) = 0;

				// 설명 : 이 component에 _component가 있는지 검사.
				INTERFACE_DECL_FUNC(contain_Component)(
					_In_ i_Component * _component)const = 0;

				// 설명 : 
				INTERFACE_DECL_FUNC(get_Component)(
					_Out_ i_Component * (&_component),
					_In_ unsigned int _id)const = 0;

				// 설명 : 이 component의 고유 식별 번호.
				INTERFACE_DECL_FUNC_T(unsigned int, get_id)(
					_X_ void)const = 0;

				// 설명 : 화면의 x 좌표를 _value로 설정.
				INTERFACE_DECL_FUNC_T(void, set_X)(
					_In_ float _value) = 0;

				// 설명 : 화면의 x 좌표를 _value로 설정.
				INTERFACE_DECL_FUNC_T(void, set_Y)(
					_In_ float _value) = 0;

				// 설명 : 화면의 x 좌표를 _value로 설정.
				INTERFACE_DECL_FUNC_T(void, set_W)(
					_In_ float _value) = 0;

				// 설명 : 화면의 높이를 _value로 설정.
				INTERFACE_DECL_FUNC_T(void, set_H)(
					_In_ float _value) = 0;

				// 설명 : 화면의 x 좌표를 얻어옴.
				INTERFACE_DECL_FUNC_T(float, get_X)(
					_X_ void)const = 0;

				// 설명 : 화면의 y 좌표를 얻어옴.
				INTERFACE_DECL_FUNC_T(float, get_Y)(
					_X_ void)const = 0;

				// 설명 : 화면의 너비를 얻어옴.
				INTERFACE_DECL_FUNC_T(float, get_W)(
					_X_ void)const = 0;

				// 설명 : 화면의 높이를 얻어옴.
				INTERFACE_DECL_FUNC_T(float, get_H)(
					_X_ void)const = 0;

				// 설명 : 파라미터 값이 true면 스크린을 보여주고, false면 감춤.
				INTERFACE_DECL_FUNC(set_Visible)(
					_In_ bool _visible) = 0;

				// 설명 : 이 component가 보이는지 확인.
				INTERFACE_DECL_FUNC_T(bool, is_Visible)(
					_X_ void)const = 0;

				// 설명 : 이벤트에 반응하는 component를 갱신.
				INTERFACE_DECL_FUNC_T(bool, event_chain)(
					_Inout_ i_inputEventHelper * _eventhelper) = 0;

				// 설명 : component 갱신.
				INTERFACE_DECL_FUNC_T(void, update)(
					_X_ void) = 0;

				// 설명 : component의 좌표를 갱신.
				INTERFACE_DECL_FUNC_T(void, reform)(
					_X_ void) = 0;

				// 설명 : component를 화면에 뿌려줌.
				INTERFACE_DECL_FUNC_T(void, render)(
					_X_ void) = 0;

				// 설명 : component에게 문제가 생겼을 때, component를 초기화.
				INTERFACE_DECL_FUNC_T(void, reset)(
					_X_ void) = 0;

				// 설명 : 마우스 이벤트에 반응하는 객체를 component에 추가.
				INTERFACE_DECL_FUNC_T(void, set_Mouseable)(
					/* [set] */ i_Mouseable * _mouseable) = 0;

				// 설명 : 마우스 이벤트에 반응하는 객체를 component로부터 호출.
				INTERFACE_DECL_FUNC_T(i_Mouseable *, get_Mouseable)(
					_X_ void)const = 0;

				// 설명 : 키보드 이벤트에 반응하는 객체를 component에 추가.
				INTERFACE_DECL_FUNC_T(void, set_Keyboardable)(
					/* [set] */ i_Keyboardable * _Keyboardable) = 0;

				// 설명 : 키보드 이벤트에 반응하는 객체를 component로부터 호출.
				INTERFACE_DECL_FUNC_T(i_Keyboardable *, get_Keyboardable)(
					_X_ void)const = 0;

				// 설명 : 액션 이벤트에 반응하는 객체를 component에 추가.
				INTERFACE_DECL_FUNC_T(void, set_Actable)(
					/* [set] */ i_Actable * _actable) = 0;

				// 설명 : 액션 이벤트에 반응하는 객체를 component로부터 호출.
				INTERFACE_DECL_FUNC_T(i_Actable *, get_Actable)(
					_X_ void)const = 0;

				// 설명 : 
				INTERFACE_DECL_FUNC_T(void, onMouse_Enter)(
					_In_ int _x,
					_In_ int _y) = 0;

				// 설명 :
				INTERFACE_DECL_FUNC_T(void, onMouse_Exit)(
					_In_ int _x,
					_In_ int _y) = 0;

				// 설명 : mouse의 버튼이 눌렸을 때 발생하는 event.
				INTERFACE_DECL_FUNC_T(void, onClick_Down)(
					_In_ MOUSE_BUTTON _button,
					_In_ int _x,
					_In_ int _y) = 0;

				// 설명 : mouse의 버튼이 눌렸다가 때면 발생하는 event.
				INTERFACE_DECL_FUNC_T(void, onClick_Up)(
					_In_ MOUSE_BUTTON _button,
					_In_ int _x,
					_In_ int _y) = 0;

				// 설명 : mouse의 버튼을 누른 채 커서를 이동하면 발생하는 event.
				INTERFACE_DECL_FUNC_T(void, onDrag)(
					_In_ MOUSE_BUTTON _button,
					_In_ int _x,
					_In_ int _y) = 0;

				// 설명 : mouse의 커서를 이동시키면 발생하는 event.
				INTERFACE_DECL_FUNC_T(void, onMove)(
					_In_ int _x,
					_In_ int _y) = 0;

				// 설명 : mouse의 wheel을 조작하면 발생하는 event.
				INTERFACE_DECL_FUNC_T(void, onWheel)(
					_In_ int _x,
					_In_ int _y,
					_In_ int _w) = 0;

				// 설명 : keyboard의 버튼이 눌렸을 때 발생하는 event.
				INTERFACE_DECL_FUNC_T(void, onKey_Down)(
					_In_ unsigned char _vKey) = 0;

				// 설명 : keyboard의 버튼을 눌렀다가 띄우면 발생하는 event.
				INTERFACE_DECL_FUNC_T(void, onKey_Up)(
					_In_ unsigned char _vKey) = 0;

				// 설명 : 
				INTERFACE_DECL_FUNC_T(void, onAct)(
					_X_ void) = 0;

			};

		}
	}
}