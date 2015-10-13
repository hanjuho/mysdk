#pragma once



#include "container.h"
#include "inputeventhelper.h"



namespace hsdk
{
	namespace win
	{
		namespace frame
		{

			// 설명 : 창의 구성 요소를 win32로 구현.
			DLL_DECL_CLASS(Frame)
				: public Container
			{
			public:

				// 생성자.
				CLASS_DECL_CONSTRUCTOR(Frame)(void);

				// 가상 소멸자.
				CLASS_DECL_DESTRUCTOR(Frame)(void);

				/*
				설명 : Frame을 갱신.
				$ 참고 : 초기에 컴포넌트들을 추가한 후, 이 함수를 한 번 호출하는 것을 권장(반복적으로 호출하는 것은 비효율적임).
				*/
				INTERFACE_DECL_FUNC_T(void, update)(
					/* [x] */ void);

				// 설명 : Frame을 화면에 뿌려줌.
				INTERFACE_DECL_FUNC_T(void, render)(
					/* [x] */ void);

				// 설명 : message procedure.
				INTERFACE_DECL_FUNC_T(void, message_Proc)(
					/* [r] */unsigned int _uMsg,
					/* [r] */unsigned int _wParam,
					/* [r] */unsigned long _lParam);
				
				// 설명 : 파라미터 값이 true면 스크린을 보여주고, false면 감춤.
				INTERFACE_DECL_FUNC(set_Visible)(
					/* [r] */ bool _visible);

				// 설명 :
				CLASS_DECL_FUNC_T(void, set_FullScreen)(
					/* [r] */ bool _full);
				
				// 설명 :
				CLASS_DECL_FUNC_T(BOOL, is_FullScreen)(
					/* [x] */ void)const;

			protected:

				// 설명 : 
				inputEventHelper m_inputEventHelper;

			};

		}
	}
}