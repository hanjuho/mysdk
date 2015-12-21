#pragma once



#include "component.h"
#include <list>


namespace hsdk
{
	namespace frame
	{

		// 설명 : 창의 구성 요소를 win32로 구현.
		DECL_CLASS(Container)
			: public Component
		{
		public:

			// 생성자
			CLASS_DECL_CONSTRUCTOR(Container)(
				_In_ PARENT_RELATION _relation = PARENT_RELATION_ABSOLUTE);

			// 가상 소멸자.
			CLASS_DECL_DESTRUCTOR(Container)(void);

			// 설명 :
			INTERFACE_DECL_FUNC_T(void, set_Layout)(
				/* [set] */ i::frame::i_Layout * _layout);

			// 설명 :
			INTERFACE_DECL_FUNC_T(i::frame::i_Layout *, get_Layout)(
				_X_ void);

			/*
			설명 : 이 container에 새로운 컴포넌트를 추가.
			$ 참고 : remove_Component()에 의해서 제거되지 않는 한, _component는 이 Container가 책임짐.
			*/
			INTERFACE_DECL_FUNC(add_Component)(
				/* [set] */ i_Component * _component,
				_In_ i::frame::LAYOUT_COMPOSITION _composition = i::frame::COMPOSITION_DEFALUT);

			/*
			설명 : 이 container로부터 _component를 제거.
			$ 주의 : 아직 메모리상에서 사라지지 않음.
			*/
			INTERFACE_DECL_FUNC(remove_Component)(
				_Inout_ i_Component * _component);

			// 설명 : 이 container에 _component가 있는지 검사.
			INTERFACE_DECL_FUNC(contain_Component)(
				_In_ i_Component * _component)const;

			// 설명 : 이 container로부터 _component를 제거.
			INTERFACE_DECL_FUNC(get_Component)(
				_Out_ i_Component * (&_component),
				_In_ unsigned int _id)const;

			// 설명 : component를 메모리 상에서 모두 제거, reset()에 의해서도 호출됨.
			INTERFACE_DECL_FUNC_T(void, clear_Component)(
				_X_ void);

			/*
			설명 : 이벤트에 반응하는 하위 혹은 이 container를 갱신(단, 부모를 거슬러 올라가진 않음).
			$ 참고 : 반환값이 true일 경우, i_inputEvent는 하위 혹은 이 component를 주시하게 됨.
			*/
			INTERFACE_DECL_FUNC_T(bool, event_chain)(
				_Inout_ i::frame::i_inputEventHelper * _eventhelper);

			// 설명 : component 갱신.
			INTERFACE_DECL_FUNC_T(void, update)(
				_X_ void);

			// 설명 : container를 화면에 뿌려줌, 자신을 render()를 호출하고 Component들의 render()를 호출.
			INTERFACE_DECL_FUNC_T(void, render)(
				_X_ void);

			// 설명 : component의 좌표를 갱신.
			INTERFACE_DECL_FUNC_T(void, reform)(
				_X_ void);

			// 설명 : component를 다시 그림.
			INTERFACE_DECL_FUNC_T(void, redraw)(
				_X_ void);

			// 설명 : container가 가진 전부를 초기화, Graphics, Layout, Component가 모두 사라짐.
			INTERFACE_DECL_FUNC_T(void, reset)(
				_X_ void);

		protected:

			// 설명 :
			std::list<Component *> m_Container;

			// 설명 :
			AutoDelete<i::frame::i_Layout> m_Layout;

		};

	}
}