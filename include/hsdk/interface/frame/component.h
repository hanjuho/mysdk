#pragma once



#include "common.h"



namespace hsdk
{
	namespace i
	{
		namespace frame
		{

			// 설명 : 창의 구성 요소를 추상화.
			DLL_DECL_INTERFACE(i_Component)
			{

				// 가상 소멸자.
				CLASS_DECL_DESTRUCTOR(i_Component)(void)
				{

				}

				// 설명 : 이 component를 포함하고 있는 부모의 주소 반환.
				INTERFACE_DECL_FUNC_T(i_Component *, parent)(
					/* [x] */ void)const = 0;

				// 설명 : component의 시각적 요소에 접근.
				INTERFACE_DECL_FUNC_T(i_Graphics *, graphics)(
					/* [x] */ void)const = 0;

				// 설명 : 마우스 이벤트에 반응하는 객체를 component에 추가.
				INTERFACE_DECL_FUNC_T(void, set_Mouseable)(
					/* [set] */ i_Mouseable * _mouseable) = 0;

				// 설명 : 마우스 이벤트에 반응하는 객체를 component로부터 호출.
				INTERFACE_DECL_FUNC_T(i_Mouseable *, get_Mouseable)(
					/* [x] */ void)const = 0;

				// 설명 : 이 component에 새로운 컴포넌트를 추가.
				INTERFACE_DECL_FUNC(add_Component)(
					/* [set] */ i_Component * _component) = 0;

				// 설명 : 이 component로부터 _component를 제거.
				INTERFACE_DECL_FUNC(remove_Component)(
					/* [r/w] */ i_Component * _component) = 0;

				// 설명 : 이 component에 _component가 있는지 검사.
				INTERFACE_DECL_FUNC_T(bool, contain_Component)(
					/* [r] */ i_Component * _component)const = 0;

				// 설명 : 이 component로부터 _component를 제거.
				INTERFACE_DECL_FUNC(get_Component)(
					/* [w] */ i_Component * (&_component),
					/* [r] */ unsigned int _id)const = 0;

				// 설명 : 이 component의 고유 식별 번호.
				INTERFACE_DECL_FUNC_T(unsigned int, get_id)(
					/* [x] */ void)const = 0;

				// 설명 : 화면의 x 좌표를 _value로 설정.
				INTERFACE_DECL_FUNC_T(void, set_X)(
					/* [r] */ float _value) = 0;

				// 설명 : 화면의 x 좌표를 _value로 설정.
				INTERFACE_DECL_FUNC_T(void, set_Y)(
					/* [r] */ float _value) = 0;

				// 설명 : 화면의 x 좌표를 _value로 설정.
				INTERFACE_DECL_FUNC_T(void, set_W)(
					/* [r] */ float _value) = 0;

				// 설명 : 화면의 높이를 _value로 설정.
				INTERFACE_DECL_FUNC_T(void, set_H)(
					/* [r] */ float _value) = 0;

				// 설명 : 화면의 x 좌표를 얻어옴.
				INTERFACE_DECL_FUNC_T(float, get_X)(
					/* [x] */ void)const = 0;

				// 설명 : 화면의 y 좌표를 얻어옴.
				INTERFACE_DECL_FUNC_T(float, get_Y)(
					/* [x] */ void)const = 0;

				// 설명 : 화면의 너비를 얻어옴.
				INTERFACE_DECL_FUNC_T(float, get_W)(
					/* [x] */ void)const = 0;

				// 설명 : 화면의 높이를 얻어옴.
				INTERFACE_DECL_FUNC_T(float, get_H)(
					/* [x] */ void)const = 0;

				// 설명 : 파라미터 값이 true면 스크린을 보여주고, false면 감춤.
				INTERFACE_DECL_FUNC(set_Visible)(
					/* [r] */ bool _visible) = 0;

				// 설명 : 이 component가 보이는지 확인.
				INTERFACE_DECL_FUNC_T(bool, is_Visible)(
					/* [x] */ void)const = 0;

				// 설명 : 이벤트에 반응하는 component를 갱신.
				INTERFACE_DECL_FUNC_T(bool, event_chain)(
					/* [r/w] */ i_inputEventHelper * _eventhelper) = 0;

				// 설명 : component를 갱신.
				INTERFACE_DECL_FUNC_T(void, update)(
					/* [x] */ void) = 0;

				// 설명 : component를 화면에 뿌려줌.
				INTERFACE_DECL_FUNC_T(void, render)(
					/* [x] */ void) = 0;

				// 설명 : component에게 문제가 생겼을 때, component를 초기화.
				INTERFACE_DECL_FUNC_T(void, reset)(
					/* [x] */ void) = 0;

			};

		}
	}
}