#pragma once



#include "common.h"



namespace hsdk
{
	namespace i
	{
		namespace frame
		{

			// ���� : mouse event�� ���� �� �ִ� �������̽��� �߻�ȭ
			DLL_DECL_INTERFACE(i_Mouseable)
			{

				// ���� : ���� ���콺 ��ư�� ����
				enum MOUSE_BUTTON
				{
					LBUTTON, RBUTTON, WBUTTON, NONE
				};

				// ���� �Ҹ���
				CLASS_DECL_DESTRUCTOR(i_Mouseable)(void)
				{

				}

				// ���� : mouse�� ��ư�� ������ �� �߻��ϴ� event
				INTERFACE_DECL_FUNC_T(void, onClick_Down)(
					/* [r] */ MOUSE_BUTTON _button,
					/* [r] */ int _x,
					/* [r] */ int _y) = 0;

				// ���� : mouse�� ��ư�� ���ȴٰ� ���� �߻��ϴ� event
				INTERFACE_DECL_FUNC_T(void, onClick_Up)(
					/* [r] */ MOUSE_BUTTON _button,
					/* [r] */ int _x,
					/* [r] */ int _y) = 0;

				// ���� : mouse�� ��ư�� ���� ä Ŀ���� �̵��ϸ� �߻��ϴ� event
				INTERFACE_DECL_FUNC_T(void, onDrag)(
					/* [r] */ MOUSE_BUTTON _button,
					/* [r] */ int _x,
					/* [r] */ int _y) = 0;

				// ���� : mouse�� Ŀ���� �̵���Ű�� �߻��ϴ� event
				INTERFACE_DECL_FUNC_T(void, onMove)(
					/* [r] */ int _x,
					/* [r] */ int _y) = 0;

				// ���� : mouse�� wheel�� �����ϸ� �߻��ϴ� event
				INTERFACE_DECL_FUNC_T(void, onWheel)(
					/* [r] */ int _x,
					/* [r] */ int _y,
					/* [r] */ int _w) = 0;

			};

		}
	}
}