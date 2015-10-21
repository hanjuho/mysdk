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
				
				// 설명 : message procedure.
				INTERFACE_DECL_FUNC_T(void, event_Proc)(
					/* [r] */unsigned int _uEvent,
					/* [r] */unsigned int _wParam,
					/* [r] */unsigned long _lParam);

			protected:
				
				// 설명 : 
				inputEventHelper m_inputEventHelper;

			private:



			};

		}
	}
}