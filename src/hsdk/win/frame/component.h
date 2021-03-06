#pragma once



#include "../../interface/frame/component.h"
#include "../../interface/frame/mouseable.h"
#include "../../interface/frame/keyboardable.h"
#include "../../interface/frame/actable.h"
#include "../../autodelete.h"
#include "graphics.h"



namespace hsdk
{
	namespace frame
	{

		// 설명 : 
		enum PARENT_RELATION
		{

			// 설명 : 
			PARENT_RELATION_ABSOLUTE,

			// 설명 : 
			PARENT_RELATION_RELATIVE

		};

		// 설명 : 창의 구성 요소를 D3D11로 구현.
		DECL_CLASS(Component)
			: public i::frame::i_Component
		{

			friend class Container;

		public:

			// 생성자.
			CLASS_DECL_CONSTRUCTOR(Component)(
				_In_ PARENT_RELATION _relation = PARENT_RELATION_ABSOLUTE);

			// 가상 소멸자.
			CLASS_DECL_DESTRUCTOR(Component)(void);

			// 설명 : 이 component를 포함하고 있는 부모의 주소 반환.
			INTERFACE_DECL_FUNC_T(i_Component *, parent)(
				_X_ void);

			// 설명 : component의 시각적 요소에 접근.
			INTERFACE_DECL_FUNC_T(i::frame::i_Graphics *, graphics)(
				_X_ void);

			// 설명 : 이 component에 새로운 컴포넌트를 추가.
			INTERFACE_DECL_FUNC(add_Component)(
				/* [set] */ i_Component * _component,
				_In_ i::frame::LAYOUT_COMPOSITION _composition = i::frame::COMPOSITION_DEFALUT);

			// 설명 : 이 component로부터 _component를 제거.
			INTERFACE_DECL_FUNC(remove_Component)(
				_Inout_ i_Component * _component);

			// 설명 : 이 component에 _component가 있는지 검사.
			INTERFACE_DECL_FUNC(contain_Component)(
				_In_ i_Component * _component)const;

			// 설명 :
			INTERFACE_DECL_FUNC(get_Component)(
				_Out_ i_Component * (&_component),
				_In_ unsigned int _id)const;

			// 설명 : 사용되지 않음.
			INTERFACE_DECL_FUNC_T(void, clear_Component)(
				_X_ void);

			// 설명 : 이 component의 고유 식별 번호.
			INTERFACE_DECL_FUNC_T(unsigned int, get_id)(
				_X_ void)const;

			// 설명 : 상대적 x 좌표를 _value로 설정.
			INTERFACE_DECL_FUNC_T(void, set_X)(
				_In_ float _value);

			// 설명 : 상대적 x 좌표를 _value로 설정.
			INTERFACE_DECL_FUNC_T(void, set_Y)(
				_In_ float _value);

			// 설명 : 절대적 x 좌표를 _value로 설정.
			INTERFACE_DECL_FUNC_T(void, set_W)(
				_In_ float _value);

			// 설명 : 절대적 높이를 _value로 설정.
			INTERFACE_DECL_FUNC_T(void, set_H)(
				_In_ float _value);

			// 설명 : 상대적 x 좌표를 얻어옴.
			INTERFACE_DECL_FUNC_T(float, get_X)(
				_X_ void)const;

			// 설명 : 상대적 y 좌표를 얻어옴.
			INTERFACE_DECL_FUNC_T(float, get_Y)(
				_X_ void)const;

			// 설명 : 절대적 너비를 얻어옴.
			INTERFACE_DECL_FUNC_T(float, get_W)(
				_X_ void)const;

			// 설명 : 절대적 높이를 얻어옴.
			INTERFACE_DECL_FUNC_T(float, get_H)(
				_X_ void)const;

			// 설명 : 파라미터 값이 true면 스크린을 보여주고, false면 감춤.
			INTERFACE_DECL_FUNC(set_Visible)(
				_In_ bool _visible);

			// 설명 : 이 component가 보이는지 확인.
			INTERFACE_DECL_FUNC_T(bool, is_Visible)(
				_X_ void)const;

			/*
			설명 : 이벤트에 반응하는 component를 갱신(단, 부모를 거슬러 올라가진 않음).
			$ 참고 : 반환값이 true일 경우, i_inputEvent는 이 component를 주시하게 됨.
			*/
			INTERFACE_DECL_FUNC_T(bool, event_chain)(
				_In_ i::frame::i_inputEventHelper * _eventhelper);

			// 설명 : component 갱신.
			INTERFACE_DECL_FUNC_T(void, update)(
				_X_ void);

			// 설명 : component를 화면에 뿌려줌.
			INTERFACE_DECL_FUNC_T(void, render)(
				_X_ void);

			// 설명 : component의 좌표를 갱신.
			INTERFACE_DECL_FUNC_T(void, reform)(
				_X_ void);

			// 설명 : component를 다시 그림.
			INTERFACE_DECL_FUNC_T(void, redraw)(
				_X_ void);

			// 설명 : component에게 문제가 생겼을 때, component를 초기화.
			INTERFACE_DECL_FUNC_T(void, reset)(
				_X_ void);

			// 설명 : 마우스 이벤트에 반응하는 객체를 component에 추가.
			INTERFACE_DECL_FUNC_T(void, set_Mouseable)(
				/* [set] */ i::frame::i_Mouseable * _mouseable);

			// 설명 : 마우스 이벤트에 반응하는 객체를 component로부터 호출.
			INTERFACE_DECL_FUNC_T(i::frame::i_Mouseable *, get_Mouseable)(
				_X_ void)const;

			// 설명 : 키보드 이벤트에 반응하는 객체를 component에 추가.
			INTERFACE_DECL_FUNC_T(void, set_Keyboardable)(
				/* [set] */ i::frame::i_Keyboardable * _Keyboardable);

			// 설명 : 키보드 이벤트에 반응하는 객체를 component로부터 호출.
			INTERFACE_DECL_FUNC_T(i::frame::i_Keyboardable *, get_Keyboardable)(
				_X_ void)const;

			// 설명 : 액션 이벤트에 반응하는 객체를 component에 추가.
			INTERFACE_DECL_FUNC_T(void, set_Actable)(
				/* [set] */ i::frame::i_Actable * _actable);

			// 설명 : 액션 이벤트에 반응하는 객체를 component로부터 호출.
			INTERFACE_DECL_FUNC_T(i::frame::i_Actable *, get_Actable)(
				_X_ void)const;

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

			// 설명 : mouse의 버튼을 누른 채 커서를 이동하면 발생하는 event.
			INTERFACE_DECL_FUNC_T(void, onDrag)(
				_In_ i::frame::MOUSE_BUTTON _button,
				_In_ int _x,
				_In_ int _y);

			// 설명 : mouse의 커서를 이동시키면 발생하는 event.
			INTERFACE_DECL_FUNC_T(void, onMove)(
				_In_ int _x,
				_In_ int _y);

			// 설명 : mouse의 wheel을 조작하면 발생하는 event.
			INTERFACE_DECL_FUNC_T(void, onWheel)(
				_In_ int _x,
				_In_ int _y,
				_In_ int _w);

			// 설명 : keyboard의 버튼이 눌렸을 때 발생하는 event.
			INTERFACE_DECL_FUNC_T(void, onKey_Down)(
				_In_ unsigned char _vKey);

			// 설명 : keyboard의 버튼을 눌렀다가 띄우면 발생하는 event.
			INTERFACE_DECL_FUNC_T(void, onKey_Up)(
				_In_ unsigned char _vKey);

			// 설명 : 
			INTERFACE_DECL_FUNC_T(void, onAct)(
				_X_ void);

			// 설명 : 절대 x 좌표를 얻어옴(단, set_X함수가 호출되더라도 update 함수를 통해 갱신이 되야 적용됨).
			CLASS_DECL_FUNC_T(float, get_AbsX)(
				_X_ void)const;

			// 설명 : 절대 y 좌표를 얻어옴(단, set_Y함수가 호출되더라도 update 함수를 통해 갱신이 되야 적용됨).
			CLASS_DECL_FUNC_T(float, get_AbsY)(
				_X_ void)const;

		protected:

			// 설명 : component의 시각적 요소를 편집하는 객체.
			Graphics m_Graphics;

			// 설명 :  이 component 위에서 일어난 마우스 이벤트를 외부에 전달하는 객체.
			i::frame::i_Mouseable * m_Mouseable = nullptr;

			// 설명 :  이 component 위에서 일어난 키보드 이벤트를 외부에 전달하는 객체.
			i::frame::i_Keyboardable * m_Keyboardable = nullptr;

			// 설명 :  이 component 위에서 일어난 액션 이벤트를 외부에 전달하는 객체.
			i::frame::i_Actable * m_Actable = nullptr;

			// 설명 : 화면 상의 절대 좌표 x
			float m_AbsX = 0.0f;

			// 설명 : 화면 상의 절대 좌표 y
			float m_AbsY = 0.0f;

			// 설명 : 
			D3DXMATRIX m_Position;

			// 설명 : 
			i::frame::LAYOUT_COMPOSITION m_Composition;

		private:

			/*
			설명 : 이 component의 상위 component.
			$ 참고 : 하위 component가 부모를 알아야 자신을 부모로부터 독립시킬 수 있음.
			*/
			Component * my_Parent = nullptr;

			// 설명 : 
			PARENT_RELATION my_Relation;

			/*
			설명 : component 고유 식별 번호.
			$ 참고 : component의 id를 통해 부모로부터 하위 component를 호출 할 수 있음.
			*/
			unsigned int my_id;

			/*
			설명 : set_T, get_T 함수와 직결되는 변수, 값 x, y에 해당하는 변수는 보모로부터 상대적인 값을 가짐.
			$ 참고 : rectangle(x, y, w, h), update()함수에서 m_d3d11Graphics::form 절대 값을 구하는 데 사용.
			*/
			float my_Rectangle[4];

			// 설명 :
			bool my_Visible = false;

		};

	}
}