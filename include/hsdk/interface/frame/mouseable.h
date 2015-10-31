#pragma once



#include "common.h"



namespace hsdk
{
	namespace i
	{
		namespace frame
		{

			// 설명 : mouse event를 받을 수 있는 인터페이스를 추상화.
			DLL_DECL_INTERFACE(i_Mouseable)
			{

				// 가상 소멸자
				CLASS_DECL_DESTRUCTOR(i_Mouseable)(void)
				{

				}

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

				// 설명 : mouse의 버튼이 눌렀다가 띄우면 발생하는 event.
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

			};

		}
	}
}