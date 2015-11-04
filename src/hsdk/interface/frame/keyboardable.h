#pragma once



#include "common.h"



namespace hsdk
{
	namespace i
	{
		namespace frame
		{

			// 설명 : keyboard event를 받을 수 있는 인터페이스를 추상화.
			DECL_INTERFACE(i_Keyboardable)
			{

				// 가상 소멸자
				CLASS_DECL_DESTRUCTOR(i_Keyboardable)(void)
				{

				}

				// 설명 : keyboard의 버튼이 눌렸을 때 발생하는 event.
				INTERFACE_DECL_FUNC_T(void, onKey_Down)(
					_In_ unsigned char _vKey) = 0;

				// 설명 : keyboard의 버튼을 눌렀다가 띄우면 발생하는 event.
				INTERFACE_DECL_FUNC_T(void, onKey_Up)(
					_In_ unsigned char _vKey) = 0;

			};

		}
	}
}