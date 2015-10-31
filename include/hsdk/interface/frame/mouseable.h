#pragma once



#include "common.h"



namespace hsdk
{
	namespace i
	{
		namespace frame
		{

			// ���� : mouse event�� ���� �� �ִ� �������̽��� �߻�ȭ.
			DLL_DECL_INTERFACE(i_Mouseable)
			{

				// ���� �Ҹ���
				CLASS_DECL_DESTRUCTOR(i_Mouseable)(void)
				{

				}

				// ���� :
				INTERFACE_DECL_FUNC_T(void, onMouse_Enter)(
					_In_ int _x,
					_In_ int _y) = 0;

				// ���� : 
				INTERFACE_DECL_FUNC_T(void, onMouse_Exit)(
					_In_ int _x,
					_In_ int _y) = 0;

				// ���� : mouse�� ��ư�� ������ �� �߻��ϴ� event.
				INTERFACE_DECL_FUNC_T(void, onClick_Down)(
					_In_ MOUSE_BUTTON _button,
					_In_ int _x,
					_In_ int _y) = 0;

				// ���� : mouse�� ��ư�� �����ٰ� ���� �߻��ϴ� event.
				INTERFACE_DECL_FUNC_T(void, onClick_Up)(
					_In_ MOUSE_BUTTON _button,
					_In_ int _x,
					_In_ int _y) = 0;

				// ���� : mouse�� ��ư�� ���� ä Ŀ���� �̵��ϸ� �߻��ϴ� event.
				INTERFACE_DECL_FUNC_T(void, onDrag)(
					_In_ MOUSE_BUTTON _button,
					_In_ int _x,
					_In_ int _y) = 0;

				// ���� : mouse�� Ŀ���� �̵���Ű�� �߻��ϴ� event.
				INTERFACE_DECL_FUNC_T(void, onMove)(
					_In_ int _x,
					_In_ int _y) = 0;

				// ���� : mouse�� wheel�� �����ϸ� �߻��ϴ� event.
				INTERFACE_DECL_FUNC_T(void, onWheel)(
					_In_ int _x,
					_In_ int _y,
					_In_ int _w) = 0;

			};

		}
	}
}