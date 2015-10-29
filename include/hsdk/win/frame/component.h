#pragma once



#include "../../interface/frame/component.h"
#include "../../interface/frame/mouseable.h"
#include "../../interface/frame/keyboardable.h"
#include "../../interface/frame/actable.h"
#include "../../autodelete.h"
#include "graphics.h"



namespace hsdk
{
	namespace frame
	{

		// ���� : â�� ���� ��Ҹ� D3D11�� ����.
		DLL_DECL_CLASS(Component)
			: public i::frame::i_Component
		{

			friend class Container;

		public:

			// ������.
			CLASS_DECL_CONSTRUCTOR(Component)(
				_In_ float _x = 0.0f,
				_In_ float _y = 0.0f,
				_In_ float _w = 0.0f,
				_In_ float _h = 0.0f,
				_In_ i::frame::FRAME_FORM _form = i::frame::ABSOLUTE_FORM);

			// ���� �Ҹ���.
			CLASS_DECL_DESTRUCTOR(Component)(void);

			// ���� : �� component�� �����ϰ� �ִ� �θ��� �ּ� ��ȯ.
			INTERFACE_DECL_FUNC_T(i_Component *, parent)(
				_X_ void)const;

			// ���� : component�� �ð��� ��ҿ� ����.
			INTERFACE_DECL_FUNC_T(i::frame::i_Graphics *, graphics)(
				_X_ void)const;

			// ���� : �� component�� ���ο� ������Ʈ�� �߰�.
			INTERFACE_DECL_FUNC(add_Component)(
				/* [set] */ i_Component * _component);

			// ���� : �� component�κ��� _component�� ����.
			INTERFACE_DECL_FUNC(remove_Component)(
				_Inout_ i_Component * _component);

			// ���� : �� component�� _component�� �ִ��� �˻�.
			INTERFACE_DECL_FUNC_T(bool, contain_Component)(
				_In_ i_Component * _component)const;

			// ���� : �� component�κ��� _component�� ����.
			INTERFACE_DECL_FUNC(get_Component)(
				_Out_ i_Component * (&_component),
				_In_ unsigned int _id)const;

			// ���� : �� component�� ���� �ĺ� ��ȣ.
			INTERFACE_DECL_FUNC_T(unsigned int, get_id)(
				_X_ void)const;

			// ���� : ����� x ��ǥ�� _value�� ����.
			INTERFACE_DECL_FUNC_T(void, set_X)(
				_In_ float _value);

			// ���� : ����� x ��ǥ�� _value�� ����.
			INTERFACE_DECL_FUNC_T(void, set_Y)(
				_In_ float _value);

			// ���� : ������ x ��ǥ�� _value�� ����.
			INTERFACE_DECL_FUNC_T(void, set_W)(
				_In_ float _value);

			// ���� : ������ ���̸� _value�� ����.
			INTERFACE_DECL_FUNC_T(void, set_H)(
				_In_ float _value);

			// ���� : ����� x ��ǥ�� ����.
			INTERFACE_DECL_FUNC_T(float, get_X)(
				_X_ void)const;

			// ���� : ����� y ��ǥ�� ����.
			INTERFACE_DECL_FUNC_T(float, get_Y)(
				_X_ void)const;

			// ���� : ������ �ʺ� ����.
			INTERFACE_DECL_FUNC_T(float, get_W)(
				_X_ void)const;

			// ���� : ������ ���̸� ����.
			INTERFACE_DECL_FUNC_T(float, get_H)(
				_X_ void)const;

			// ���� :
			INTERFACE_DECL_FUNC_T(void, set_Form)(
				_In_ i::frame::FRAME_FORM _form);

			// ���� :
			INTERFACE_DECL_FUNC_T(i::frame::FRAME_FORM, get_Form)(
				_X_  void)const;
			
			// ���� : �Ķ���� ���� true�� ��ũ���� �����ְ�, false�� ����.
			INTERFACE_DECL_FUNC(set_Visible)(
				_In_ bool _visible);

			// ���� : �� component�� ���̴��� Ȯ��.
			INTERFACE_DECL_FUNC_T(bool, is_Visible)(
				_X_ void)const;

			/*
			���� : �̺�Ʈ�� �����ϴ� component�� ����(��, �θ� �Ž��� �ö��� ����).
			$ ���� : ��ȯ���� true�� ���, i_inputEvent�� �� component�� �ֽ��ϰ� ��.
			*/
			INTERFACE_DECL_FUNC_T(bool, event_chain)(
				_In_ i::frame::i_inputEventHelper * _eventhelper);

			// ���� : component ����.
			INTERFACE_DECL_FUNC_T(void, update)(
				_X_ void);

			// ���� : component�� ��ǥ�� ����.
			INTERFACE_DECL_FUNC_T(void, reform)(
				_X_ void);

			// ���� : component�� ȭ�鿡 �ѷ���.
			INTERFACE_DECL_FUNC_T(void, render)(
				_X_ void);

			// ���� : component���� ������ ������ ��, component�� �ʱ�ȭ.
			INTERFACE_DECL_FUNC_T(void, reset)(
				_X_ void);

			// ���� : ���콺 �̺�Ʈ�� �����ϴ� ��ü�� component�� �߰�.
			INTERFACE_DECL_FUNC_T(void, set_Mouseable)(
				/* [set] */ i::frame::i_Mouseable * _mouseable);

			// ���� : ���콺 �̺�Ʈ�� �����ϴ� ��ü�� component�κ��� ȣ��.
			INTERFACE_DECL_FUNC_T(i::frame::i_Mouseable *, get_Mouseable)(
				_X_ void)const;

			// ���� : Ű���� �̺�Ʈ�� �����ϴ� ��ü�� component�� �߰�.
			INTERFACE_DECL_FUNC_T(void, set_Keyboardable)(
				/* [set] */ i::frame::i_Keyboardable * _Keyboardable);

			// ���� : Ű���� �̺�Ʈ�� �����ϴ� ��ü�� component�κ��� ȣ��.
			INTERFACE_DECL_FUNC_T(i::frame::i_Keyboardable *, get_Keyboardable)(
				_X_ void)const;

			// ���� : �׼� �̺�Ʈ�� �����ϴ� ��ü�� component�� �߰�.
			INTERFACE_DECL_FUNC_T(void, set_Actable)(
				/* [set] */ i::frame::i_Actable * _actable);

			// ���� : �׼� �̺�Ʈ�� �����ϴ� ��ü�� component�κ��� ȣ��.
			INTERFACE_DECL_FUNC_T(i::frame::i_Actable *, get_Actable)(
				_X_ void)const;

			// ���� : mouse�� ��ư�� ������ �� �߻��ϴ� event.
			INTERFACE_DECL_FUNC_T(void, onClick_Down)(
				_In_ i::frame::MOUSE_BUTTON _button,
				_In_ int _x,
				_In_ int _y);

			// ���� : mouse�� ��ư�� ���ȴٰ� ���� �߻��ϴ� event.
			INTERFACE_DECL_FUNC_T(void, onClick_Up)(
				_In_ i::frame::MOUSE_BUTTON _button,
				_In_ int _x,
				_In_ int _y);

			// ���� : mouse�� ��ư�� ���� ä Ŀ���� �̵��ϸ� �߻��ϴ� event.
			INTERFACE_DECL_FUNC_T(void, onDrag)(
				_In_ i::frame::MOUSE_BUTTON _button,
				_In_ int _x,
				_In_ int _y);

			// ���� : mouse�� Ŀ���� �̵���Ű�� �߻��ϴ� event.
			INTERFACE_DECL_FUNC_T(void, onMove)(
				_In_ int _x,
				_In_ int _y);

			// ���� : mouse�� wheel�� �����ϸ� �߻��ϴ� event.
			INTERFACE_DECL_FUNC_T(void, onWheel)(
				_In_ int _x,
				_In_ int _y,
				_In_ int _w);

			// ���� : keyboard�� ��ư�� ������ �� �߻��ϴ� event.
			INTERFACE_DECL_FUNC_T(void, onKey_Down)(
				_In_ unsigned char _vKey);

			// ���� : keyboard�� ��ư�� �����ٰ� ���� �߻��ϴ� event.
			INTERFACE_DECL_FUNC_T(void, onKey_Up)(
				_In_ unsigned char _vKey);

			// ���� : 
			INTERFACE_DECL_FUNC_T(void, onAct)(
				_X_ void);

			// ���� : ���� x ��ǥ�� ����(��, set_X�Լ��� ȣ��Ǵ��� update �Լ��� ���� ������ �Ǿ� �����).
			CLASS_DECL_FUNC_T(float, get_AbsX)(
				_X_ void)const;

			// ���� : ���� y ��ǥ�� ����(��, set_Y�Լ��� ȣ��Ǵ��� update �Լ��� ���� ������ �Ǿ� �����).
			CLASS_DECL_FUNC_T(float, get_AbsY)(
				_X_ void)const;

		protected:

			// ���� : component�� �ð��� ��Ҹ� �����ϴ� ��ü.
			Graphics m_D3D10Graphics;

			// ���� :  �� component ������ �Ͼ ���콺 �̺�Ʈ�� �ܺο� �����ϴ� ��ü.
			AutoDelete<i::frame::i_Mouseable> m_Mouseable;

			// ���� :  �� component ������ �Ͼ Ű���� �̺�Ʈ�� �ܺο� �����ϴ� ��ü.
			AutoDelete<i::frame::i_Keyboardable> m_Keyboardable;

			// ���� :  �� component ������ �Ͼ �׼� �̺�Ʈ�� �ܺο� �����ϴ� ��ü.
			AutoDelete<i::frame::i_Actable> m_Actable;

		private:

			/*
			���� : �� component�� ���� component.
			$ ���� : ���� component�� �θ� �˾ƾ� �ڽ��� �θ�κ��� ������ų �� ����.
			*/
			Component * my_Parent;

			/*
			���� : component ���� �ĺ� ��ȣ.
			$ ���� : component�� id�� ���� �θ�κ��� ���� component�� ȣ�� �� �� ����.
			*/
			unsigned int my_id;

			// ���� : 
			i::frame::FRAME_FORM my_Form;

			// ���� : ȭ�� ���� ���� ��ǥ x
			float my_AbsX;

			// ���� : ȭ�� ���� ���� ��ǥ y
			float my_AbsY;

			/*
			���� : set_T, get_T �Լ��� ����Ǵ� ����, �� x, y�� �ش��ϴ� ������ ����κ��� ������� ���� ����.
			$ ���� : rectangle(x, y, w, h), update()�Լ����� m_d3d11Graphics::form ���� ���� ���ϴ� �� ���.
			*/
			float my_Rectangle[4];

			// ���� :
			bool my_Visible;

		};

	}
}