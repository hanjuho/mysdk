#pragma once



#include "component.h"
#include <map>


namespace hsdk
{
	namespace frame
	{

		// 설명 : 창의 구성 요소를 win32로 구현.
		DLL_DECL_CLASS(Container)
			: public Component
		{
		public:

			// 생성자
			CLASS_DECL_CONSTRUCTOR(Container)(
				_In_ float _x = 0.0f,
				_In_ float _y = 0.0f,
				_In_ float _w = 0.0f,
				_In_ float _h = 0.0f);

			// 가상 소멸자.
			CLASS_DECL_DESTRUCTOR(Container)(void);

			// 설명 :
			INTERFACE_

			// 설명 : 이 container에 새로운 컴포넌트를 추가.
			INTERFACE_DECL_FUNC(add_Component)(
				/* [set] */ i_Component * _component,
				_In_ i::frame::LAYOUT_COMPOSITION _composition = i::frame::COMPOSITION_DEFALUT);

			// 설명 : 이 container로부터 _component를 제거.
			INTERFACE_DECL_FUNC(remove_Component)(
				_Inout_ i_Component * _component);

			// 설명 : 이 container에 _component가 있는지 검사.
			INTERFACE_DECL_FUNC_T(bool, contain_Component)(
				_In_ i_Component * _component)const;

			// 설명 : 이 container로부터 _component를 제거.
			INTERFACE_DECL_FUNC(get_Component)(
				_Out_ i_Component * (&_component),
				_In_ unsigned int _id)const;

			/*
			설명 : 이벤트에 반응하는 하위 혹은 이 container를 갱신(단, 부모를 거슬러 올라가진 않음).
			$ 참고 : 반환값이 true일 경우, i_inputEvent는 하위 혹은 이 component를 주시하게 됨.
			*/
			INTERFACE_DECL_FUNC_T(bool, event_chain)(
				_Inout_ i::frame::i_inputEventHelper * _eventhelper);

			// 설명 : component 갱신.
			INTERFACE_DECL_FUNC_T(void, update)(
				_X_ void);

			// 설명 : component의 좌표를 갱신.
			INTERFACE_DECL_FUNC_T(void, reform)(
				_X_ void);

			// 설명 : container를 화면에 뿌려줌.
			INTERFACE_DECL_FUNC_T(void, render)(
				_X_ void);

			// 설명 : 
			INTERFACE_DECL_FUNC_T(void, clear)(
				_X_ void);

		protected:

			// 설명 :
			std::map<unsigned int, Component *> m_Container;

		};

	}
}