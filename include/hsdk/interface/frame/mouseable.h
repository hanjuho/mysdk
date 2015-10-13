#pragma once



#include "common.h"



namespace hsdk
{
	namespace i
	{
		namespace frame
		{

			// 설명 : mouse event를 받을 수 있는 인터페이스를 추상화
			DLL_DECL_INTERFACE(i_Mouseable)
			{

				// 설명 : 눌린 마우스 버튼의 종류
				enum MOUSE_BUTTON
				{
					LBUTTON, RBUTTON, WBUTTON, NONE
				};

				// 가상 소멸자
				CLASS_DECL_DESTRUCTOR(i_Mouseable)(void)
				{

				}

				// 설명 : mouse의 버튼이 눌렸을 때 발생하는 event
				INTERFACE_DECL_FUNC_T(void, onClick_Down)(
					/* [r] */ MOUSE_BUTTON _button,
					/* [r] */ int _x,
					/* [r] */ int _y) = 0;

				// 설명 : mouse의 버튼이 눌렸다가 때면 발생하는 event
				INTERFACE_DECL_FUNC_T(void, onClick_Up)(
					/* [r] */ MOUSE_BUTTON _button,
					/* [r] */ int _x,
					/* [r] */ int _y) = 0;

				// 설명 : mouse의 버튼을 누른 채 커서를 이동하면 발생하는 event
				INTERFACE_DECL_FUNC_T(void, onDrag)(
					/* [r] */ MOUSE_BUTTON _button,
					/* [r] */ int _x,
					/* [r] */ int _y) = 0;

				// 설명 : mouse의 커서를 이동시키면 발생하는 event
				INTERFACE_DECL_FUNC_T(void, onMove)(
					/* [r] */ int _x,
					/* [r] */ int _y) = 0;

				// 설명 : mouse의 wheel을 조작하면 발생하는 event
				INTERFACE_DECL_FUNC_T(void, onWheel)(
					/* [r] */ int _x,
					/* [r] */ int _y,
					/* [r] */ int _w) = 0;

			};

		}
	}
}