#pragma once



#include "common.h"



namespace hsdk
{
	namespace i
	{
		namespace frame
		{

			// ���� : â�� ���� ��Ҹ� �߻�ȭ.
			DLL_DECL_INTERFACE(i_Component)
			{

				// ���� �Ҹ���.
				CLASS_DECL_DESTRUCTOR(i_Component)(void)
				{

				}

				// ���� : �� component�� �����ϰ� �ִ� �θ��� �ּ� ��ȯ.
				INTERFACE_DECL_FUNC_T(i_Component *, parent)(
					/* [x] */ void)const = 0;

				// ���� : component�� �ð��� ��ҿ� ����.
				INTERFACE_DECL_FUNC_T(i_Graphics *, graphics)(
					/* [x] */ void)const = 0;

				// ���� : ���콺 �̺�Ʈ�� �����ϴ� ��ü�� component�� �߰�.
				INTERFACE_DECL_FUNC_T(void, set_Mouseable)(
					/* [set] */ i_Mouseable * _mouseable) = 0;

				// ���� : ���콺 �̺�Ʈ�� �����ϴ� ��ü�� component�κ��� ȣ��.
				INTERFACE_DECL_FUNC_T(i_Mouseable *, get_Mouseable)(
					/* [x] */ void)const = 0;

				// ���� : �� component�� ���ο� ������Ʈ�� �߰�.
				INTERFACE_DECL_FUNC(add_Component)(
					/* [set] */ i_Component * _component) = 0;

				// ���� : �� component�κ��� _component�� ����.
				INTERFACE_DECL_FUNC(remove_Component)(
					/* [r/w] */ i_Component * _component) = 0;

				// ���� : �� component�� _component�� �ִ��� �˻�.
				INTERFACE_DECL_FUNC_T(bool, contain_Component)(
					/* [r] */ i_Component * _component)const = 0;

				// ���� : �� component�κ��� _component�� ����.
				INTERFACE_DECL_FUNC(get_Component)(
					/* [w] */ i_Component * (&_component),
					/* [r] */ unsigned int _id)const = 0;

				// ���� : �� component�� ���� �ĺ� ��ȣ.
				INTERFACE_DECL_FUNC_T(unsigned int, get_id)(
					/* [x] */ void)const = 0;

				// ���� : ȭ���� x ��ǥ�� _value�� ����.
				INTERFACE_DECL_FUNC_T(void, set_X)(
					/* [r] */ float _value) = 0;

				// ���� : ȭ���� x ��ǥ�� _value�� ����.
				INTERFACE_DECL_FUNC_T(void, set_Y)(
					/* [r] */ float _value) = 0;

				// ���� : ȭ���� x ��ǥ�� _value�� ����.
				INTERFACE_DECL_FUNC_T(void, set_W)(
					/* [r] */ float _value) = 0;

				// ���� : ȭ���� ���̸� _value�� ����.
				INTERFACE_DECL_FUNC_T(void, set_H)(
					/* [r] */ float _value) = 0;

				// ���� : ȭ���� x ��ǥ�� ����.
				INTERFACE_DECL_FUNC_T(float, get_X)(
					/* [x] */ void)const = 0;

				// ���� : ȭ���� y ��ǥ�� ����.
				INTERFACE_DECL_FUNC_T(float, get_Y)(
					/* [x] */ void)const = 0;

				// ���� : ȭ���� �ʺ� ����.
				INTERFACE_DECL_FUNC_T(float, get_W)(
					/* [x] */ void)const = 0;

				// ���� : ȭ���� ���̸� ����.
				INTERFACE_DECL_FUNC_T(float, get_H)(
					/* [x] */ void)const = 0;

				// ���� : �Ķ���� ���� true�� ��ũ���� �����ְ�, false�� ����.
				INTERFACE_DECL_FUNC(set_Visible)(
					/* [r] */ bool _visible) = 0;

				// ���� : �� component�� ���̴��� Ȯ��.
				INTERFACE_DECL_FUNC_T(bool, is_Visible)(
					/* [x] */ void)const = 0;

				// ���� : �̺�Ʈ�� �����ϴ� component�� ����.
				INTERFACE_DECL_FUNC_T(bool, event_chain)(
					/* [r/w] */ i_inputEventHelper * _eventhelper) = 0;

				// ���� : component�� ����.
				INTERFACE_DECL_FUNC_T(void, update)(
					/* [x] */ void) = 0;

				// ���� : component�� ȭ�鿡 �ѷ���.
				INTERFACE_DECL_FUNC_T(void, render)(
					/* [x] */ void) = 0;

				// ���� : component���� ������ ������ ��, component�� �ʱ�ȭ.
				INTERFACE_DECL_FUNC_T(void, reset)(
					/* [x] */ void) = 0;

			};

		}
	}
}