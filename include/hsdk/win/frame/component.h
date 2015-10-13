#pragma once



#include "../../interface/frame/component.h"
#include "../../interface/frame/mouseable.h"
#include "../../autodelete.h"
#include "graphics.h"



namespace hsdk
{
	namespace win
	{
		namespace frame
		{

			// 설명 : 창의 구성 요소를 D3D11로 구현.
			DLL_DECL_CLASS(Component)
				: public i::frame::i_Component
			{

				friend class Container;

			public:

				// 생성자.
				CLASS_DECL_CONSTRUCTOR(Component)(void);

				// 가상 소멸자.
				CLASS_DECL_DESTRUCTOR(Component)(void);

				// 설명 : 이 component를 포함하고 있는 부모의 주소 반환.
				INTERFACE_DECL_FUNC_T(i_Component *, parent)(
					/* [x] */ void)const;

				// 설명 : component의 시각적 요소에 접근.
				INTERFACE_DECL_FUNC_T(i::frame::i_Graphics *, graphics)(
					/* [x] */ void)const;

				// 설명 : 마우스 이벤트에 반응하는 객체를 component에 추가.
				INTERFACE_DECL_FUNC_T(void, set_Mouseable)(
					/* [set] */ i::frame::i_Mouseable * _mouseable);

				// 설명 : 마우스 이벤트에 반응하는 객체를 component로부터 호출.
				INTERFACE_DECL_FUNC_T(i::frame::i_Mouseable *, get_Mouseable)(
					/* [x] */ void)const;

				// 설명 : 이 component에 새로운 컴포넌트를 추가.
				INTERFACE_DECL_FUNC(add_Component)(
					/* [set] */ i_Component * _component);

				// 설명 : 이 component로부터 _component를 제거.
				INTERFACE_DECL_FUNC(remove_Component)(
					/* [r/w] */ i_Component * _component);

				// 설명 : 이 component에 _component가 있는지 검사.
				INTERFACE_DECL_FUNC_T(bool, contain_Component)(
					/* [r] */ i_Component * _component)const;

				// 설명 : 이 component로부터 _component를 제거.
				INTERFACE_DECL_FUNC(get_Component)(
					/* [w] */ i_Component * (&_component),
					/* [r] */ unsigned int _id)const;

				// 설명 : 이 component의 고유 식별 번호.
				INTERFACE_DECL_FUNC_T(unsigned int, get_id)(
					/* [x] */ void)const;

				// 설명 : 상대적 x 좌표를 _value로 설정.
				INTERFACE_DECL_FUNC_T(void, set_X)(
					/* [r] */ float _value);

				// 설명 : 상대적 x 좌표를 _value로 설정.
				INTERFACE_DECL_FUNC_T(void, set_Y)(
					/* [r] */ float _value);

				// 설명 : 절대적 x 좌표를 _value로 설정.
				INTERFACE_DECL_FUNC_T(void, set_W)(
					/* [r] */ float _value);

				// 설명 : 절대적 높이를 _value로 설정.
				INTERFACE_DECL_FUNC_T(void, set_H)(
					/* [r] */ float _value);

				// 설명 : 상대적 x 좌표를 얻어옴.
				INTERFACE_DECL_FUNC_T(float, get_X)(
					/* [x] */ void)const;

				// 설명 : 상대적 y 좌표를 얻어옴.
				INTERFACE_DECL_FUNC_T(float, get_Y)(
					/* [x] */ void)const;

				// 설명 : 절대적 너비를 얻어옴.
				INTERFACE_DECL_FUNC_T(float, get_W)(
					/* [x] */ void)const;

				// 설명 : 절대적 높이를 얻어옴.
				INTERFACE_DECL_FUNC_T(float, get_H)(
					/* [x] */ void)const;

				// 설명 : 파라미터 값이 true면 스크린을 보여주고, false면 감춤.
				INTERFACE_DECL_FUNC(set_Visible)(
					/* [r] */ bool _visible);

				// 설명 : 이 component가 보이는지 확인.
				INTERFACE_DECL_FUNC_T(bool, is_Visible)(
					/* [x] */ void)const;

				/*
				설명 : 이벤트에 반응하는 component를 갱신(단, 부모를 거슬러 올라가진 않음).
				$ 참고 : 반환값이 true일 경우, i_inputEvent는 이 component를 주시하게 됨.
				*/
				INTERFACE_DECL_FUNC_T(bool, event_chain)(
					/* [r] */ i::frame::i_inputEventHelper * _eventhelper);

				// 설명 : component를 갱신.
				INTERFACE_DECL_FUNC_T(void, update)(
					/* [x] */ void);

				// 설명 : component를 화면에 뿌려줌.
				INTERFACE_DECL_FUNC_T(void, render)(
					/* [x] */ void);

				// 설명 : component에게 문제가 생겼을 때, component를 초기화.
				INTERFACE_DECL_FUNC_T(void, reset)(
					/* [x] */ void){
					return;
				}

				// 설명 : 절대 x 좌표를 얻어옴(단, set_X함수가 호출되더라도 update 함수를 통해 갱신이 되야 적용됨).
				CLASS_DECL_FUNC_T(float, get_AbsX)(
					/* [x] */ void)const;

				// 설명 : 절대 y 좌표를 얻어옴(단, set_Y함수가 호출되더라도 update 함수를 통해 갱신이 되야 적용됨).
				CLASS_DECL_FUNC_T(float, get_AbsY)(
					/* [x] */ void)const;

			protected:

				// 설명 : component의 시각적 요소를 편집하는 객체.
				AutoDelete<Graphics> m_D3D10Graphics;

				// 설명 :  이 component 위에서 일어난 마우스 이벤트를 외부에 전달하는 객체.
				AutoDelete<i::frame::i_Mouseable> m_Mouseable;

			private:

				/*
				설명 : 이 component의 상위 component.
				$ 참고 : 하위 component가 부모를 알아야 자신을 부모로부터 독립시킬 수 있음.
				*/
				Component * my_Parent;

				/*
				설명 : component 고유 식별 번호.
				$ 참고 : component의 id를 통해 부모로부터 하위 component를 호출 할 수 있음.
				*/
				unsigned int my_id;

				// 설명 : 화면 상의 절대 좌표 x
				float my_AbsX;

				// 설명 : 화면 상의 절대 좌표 y
				float my_AbsY;

				/*
				설명 : set_T, get_T 함수와 직결되는 변수, 값 x, y에 해당하는 변수는 보모로부터 상대적인 값을 가짐.
				$ 참고 : rectangle(x, y, w, h), update()함수에서 m_d3d11Graphics::form 절대 값을 구하는 데 사용.
				*/
				float my_Rectangle[4];
				
				// 설명 :
				bool my_Visible;

			};

		}
	}
}