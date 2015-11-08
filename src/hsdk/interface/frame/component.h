#pragma once



#include "common.h"
#include "layout.h"



namespace hsdk
{
	namespace i
	{
		namespace frame
		{

			// ���� : â�� ���� ��Ҹ� �߻�ȭ.
			DECL_INTERFACE(i_Component)
			{

				// ���� �Ҹ���.
				CLASS_DECL_DESTRUCTOR(i_Component)(void)
				{

				}

				// ���� : �� component�� �����ϰ� �ִ� �θ��� �ּ� ��ȯ.
				INTERFACE_DECL_FUNC_T(i_Component *, parent)(
					_X_ void)const = 0;

				// ���� : component�� �ð��� ��ҿ� ����.
				INTERFACE_DECL_FUNC_T(i_Graphics *, graphics)(
					_X_ void)const = 0;

				// ���� : �� component�� ���ο� ������Ʈ�� �߰�.
				INTERFACE_DECL_FUNC(add_Component)(
					/* [set] */ i_Component * _component,
					_In_ LAYOUT_COMPOSITION _composition = COMPOSITION_DEFALUT) = 0;

				// ���� : �� component�κ��� _component�� ����.
				INTERFACE_DECL_FUNC(remove_Component)(
					_Inout_ i_Component * _component) = 0;

				// ���� : �� component�� _component�� �ִ��� �˻�.
				INTERFACE_DECL_FUNC(contain_Component)(
					_In_ i_Component * _component)const = 0;

				// ���� : 
				INTERFACE_DECL_FUNC(get_Component)(
					_Out_ i_Component * (&_component),
					_In_ unsigned int _id)const = 0;

				// ���� : �� component�� ���� �ĺ� ��ȣ.
				INTERFACE_DECL_FUNC_T(unsigned int, get_id)(
					_X_ void)const = 0;

				// ���� : ȭ���� x ��ǥ�� _value�� ����.
				INTERFACE_DECL_FUNC_T(void, set_X)(
					_In_ float _value) = 0;

				// ���� : ȭ���� x ��ǥ�� _value�� ����.
				INTERFACE_DECL_FUNC_T(void, set_Y)(
					_In_ float _value) = 0;

				// ���� : ȭ���� x ��ǥ�� _value�� ����.
				INTERFACE_DECL_FUNC_T(void, set_W)(
					_In_ float _value) = 0;

				// ���� : ȭ���� ���̸� _value�� ����.
				INTERFACE_DECL_FUNC_T(void, set_H)(
					_In_ float _value) = 0;

				// ���� : ȭ���� x ��ǥ�� ����.
				INTERFACE_DECL_FUNC_T(float, get_X)(
					_X_ void)const = 0;

				// ���� : ȭ���� y ��ǥ�� ����.
				INTERFACE_DECL_FUNC_T(float, get_Y)(
					_X_ void)const = 0;

				// ���� : ȭ���� �ʺ� ����.
				INTERFACE_DECL_FUNC_T(float, get_W)(
					_X_ void)const = 0;

				// ���� : ȭ���� ���̸� ����.
				INTERFACE_DECL_FUNC_T(float, get_H)(
					_X_ void)const = 0;

				// ���� : �Ķ���� ���� true�� ��ũ���� �����ְ�, false�� ����.
				INTERFACE_DECL_FUNC(set_Visible)(
					_In_ bool _visible) = 0;

				// ���� : �� component�� ���̴��� Ȯ��.
				INTERFACE_DECL_FUNC_T(bool, is_Visible)(
					_X_ void)const = 0;

				// ���� : �̺�Ʈ�� �����ϴ� component�� ����.
				INTERFACE_DECL_FUNC_T(bool, event_chain)(
					_Inout_ i_inputEventHelper * _eventhelper) = 0;

				// ���� : component ����.
				INTERFACE_DECL_FUNC_T(void, update)(
					_X_ void) = 0;

				// ���� : component�� ��ǥ�� ����.
				INTERFACE_DECL_FUNC_T(void, reform)(
					_X_ void) = 0;

				// ���� : component�� ȭ�鿡 �ѷ���.
				INTERFACE_DECL_FUNC_T(void, render)(
					_X_ void) = 0;

				// ���� : component���� ������ ������ ��, component�� �ʱ�ȭ.
				INTERFACE_DECL_FUNC_T(void, reset)(
					_X_ void) = 0;

				// ���� : ���콺 �̺�Ʈ�� �����ϴ� ��ü�� component�� �߰�.
				INTERFACE_DECL_FUNC_T(void, set_Mouseable)(
					/* [set] */ i_Mouseable * _mouseable) = 0;

				// ���� : ���콺 �̺�Ʈ�� �����ϴ� ��ü�� component�κ��� ȣ��.
				INTERFACE_DECL_FUNC_T(i_Mouseable *, get_Mouseable)(
					_X_ void)const = 0;

				// ���� : Ű���� �̺�Ʈ�� �����ϴ� ��ü�� component�� �߰�.
				INTERFACE_DECL_FUNC_T(void, set_Keyboardable)(
					/* [set] */ i_Keyboardable * _Keyboardable) = 0;

				// ���� : Ű���� �̺�Ʈ�� �����ϴ� ��ü�� component�κ��� ȣ��.
				INTERFACE_DECL_FUNC_T(i_Keyboardable *, get_Keyboardable)(
					_X_ void)const = 0;

				// ���� : �׼� �̺�Ʈ�� �����ϴ� ��ü�� component�� �߰�.
				INTERFACE_DECL_FUNC_T(void, set_Actable)(
					/* [set] */ i_Actable * _actable) = 0;

				// ���� : �׼� �̺�Ʈ�� �����ϴ� ��ü�� component�κ��� ȣ��.
				INTERFACE_DECL_FUNC_T(i_Actable *, get_Actable)(
					_X_ void)const = 0;

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

				// ���� : mouse�� ��ư�� ���ȴٰ� ���� �߻��ϴ� event.
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

				// ���� : keyboard�� ��ư�� ������ �� �߻��ϴ� event.
				INTERFACE_DECL_FUNC_T(void, onKey_Down)(
					_In_ unsigned char _vKey) = 0;

				// ���� : keyboard�� ��ư�� �����ٰ� ���� �߻��ϴ� event.
				INTERFACE_DECL_FUNC_T(void, onKey_Up)(
					_In_ unsigned char _vKey) = 0;

				// ���� : 
				INTERFACE_DECL_FUNC_T(void, onAct)(
					_X_ void) = 0;

			};

		}
	}
}