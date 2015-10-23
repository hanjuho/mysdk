#pragma once



#include "component.h"
#include <hash_map>


namespace hsdk
{
	namespace win
	{
		namespace frame
		{

			// 설명 : 창의 구성 요소를 win32로 구현.
			DLL_DECL_CLASS(Container)
				: public Component
			{
			public:

				// 가상 소멸자.
				CLASS_DECL_DESTRUCTOR(Container)(void);

				// 설명 : 이 container에 새로운 컴포넌트를 추가.
				INTERFACE_DECL_FUNC(add_Component)(
					/* [set] */ i_Component * _component);

				// 설명 : 이 container로부터 _component를 제거.
				INTERFACE_DECL_FUNC(remove_Component)(
					/* [r/w] */ i_Component * _component);

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
					/* [r/w] */ i::frame::i_inputEventHelper * _eventhelper);

				// 설명 : component 갱신.
				INTERFACE_DECL_FUNC_T(void, update)(
					/* [x] */ void);
				
				// 설명 : component의 좌표를 갱신.
				INTERFACE_DECL_FUNC_T(void, reform)(
					/* [x] */ void);

				// 설명 : container를 화면에 뿌려줌.
				INTERFACE_DECL_FUNC_T(void, render)(
					/* [x] */ void);

				// 설명 : 
				INTERFACE_DECL_FUNC_T(void, clear)(
					/* [x] */ void);

			protected:

				// 설명 :
				std::hash_map<unsigned int, Component *> m_Container;

			};

		}
	}
}