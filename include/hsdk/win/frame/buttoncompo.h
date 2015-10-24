#pragma once



#include "component.h"



namespace hsdk
{
	namespace win
	{
		namespace frame
		{

			// 설명 :
			DLL_DECL_CLASS(ButtonCompo)
				: public Component
			{

			public:

				// 생성자.
				CLASS_DECL_CONSTRUCTOR(ButtonCompo)(
					_In_ float _x = 0.0f,
					_In_ float _y = 0.0f,
					_In_ float _w = 0.0f,
					_In_ float _h = 0.0f);

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

				// 설명 : component를 화면에 뿌려줌.
				INTERFACE_DECL_FUNC_T(void, render)(
					_X_ void);

			protected:

				float m_GraphicsRenderState = 1.0f;

			};

		}
	}
}