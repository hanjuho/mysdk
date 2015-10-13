#pragma once



#include "../../interface/frame/component.h"
#include "../../interface/frame/mouseable.h"
#include "../../autodelete.h"
#include "graphics.h"



namespace hsdk
{
	namespace win
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
				CLASS_DECL_CONSTRUCTOR(Component)(void);

				// ���� �Ҹ���.
				CLASS_DECL_DESTRUCTOR(Component)(void);

				// ���� : �� component�� �����ϰ� �ִ� �θ��� �ּ� ��ȯ.
				INTERFACE_DECL_FUNC_T(i_Component *, parent)(
					/* [x] */ void)const;

				// ���� : component�� �ð��� ��ҿ� ����.
				INTERFACE_DECL_FUNC_T(i::frame::i_Graphics *, graphics)(
					/* [x] */ void)const;

				// ���� : ���콺 �̺�Ʈ�� �����ϴ� ��ü�� component�� �߰�.
				INTERFACE_DECL_FUNC_T(void, set_Mouseable)(
					/* [set] */ i::frame::i_Mouseable * _mouseable);

				// ���� : ���콺 �̺�Ʈ�� �����ϴ� ��ü�� component�κ��� ȣ��.
				INTERFACE_DECL_FUNC_T(i::frame::i_Mouseable *, get_Mouseable)(
					/* [x] */ void)const;

				// ���� : �� component�� ���ο� ������Ʈ�� �߰�.
				INTERFACE_DECL_FUNC(add_Component)(
					/* [set] */ i_Component * _component);

				// ���� : �� component�κ��� _component�� ����.
				INTERFACE_DECL_FUNC(remove_Component)(
					/* [r/w] */ i_Component * _component);

				// ���� : �� component�� _component�� �ִ��� �˻�.
				INTERFACE_DECL_FUNC_T(bool, contain_Component)(
					/* [r] */ i_Component * _component)const;

				// ���� : �� component�κ��� _component�� ����.
				INTERFACE_DECL_FUNC(get_Component)(
					/* [w] */ i_Component * (&_component),
					/* [r] */ unsigned int _id)const;

				// ���� : �� component�� ���� �ĺ� ��ȣ.
				INTERFACE_DECL_FUNC_T(unsigned int, get_id)(
					/* [x] */ void)const;

				// ���� : ����� x ��ǥ�� _value�� ����.
				INTERFACE_DECL_FUNC_T(void, set_X)(
					/* [r] */ float _value);

				// ���� : ����� x ��ǥ�� _value�� ����.
				INTERFACE_DECL_FUNC_T(void, set_Y)(
					/* [r] */ float _value);

				// ���� : ������ x ��ǥ�� _value�� ����.
				INTERFACE_DECL_FUNC_T(void, set_W)(
					/* [r] */ float _value);

				// ���� : ������ ���̸� _value�� ����.
				INTERFACE_DECL_FUNC_T(void, set_H)(
					/* [r] */ float _value);

				// ���� : ����� x ��ǥ�� ����.
				INTERFACE_DECL_FUNC_T(float, get_X)(
					/* [x] */ void)const;

				// ���� : ����� y ��ǥ�� ����.
				INTERFACE_DECL_FUNC_T(float, get_Y)(
					/* [x] */ void)const;

				// ���� : ������ �ʺ� ����.
				INTERFACE_DECL_FUNC_T(float, get_W)(
					/* [x] */ void)const;

				// ���� : ������ ���̸� ����.
				INTERFACE_DECL_FUNC_T(float, get_H)(
					/* [x] */ void)const;

				// ���� : �Ķ���� ���� true�� ��ũ���� �����ְ�, false�� ����.
				INTERFACE_DECL_FUNC(set_Visible)(
					/* [r] */ bool _visible);

				// ���� : �� component�� ���̴��� Ȯ��.
				INTERFACE_DECL_FUNC_T(bool, is_Visible)(
					/* [x] */ void)const;

				/*
				���� : �̺�Ʈ�� �����ϴ� component�� ����(��, �θ� �Ž��� �ö��� ����).
				$ ���� : ��ȯ���� true�� ���, i_inputEvent�� �� component�� �ֽ��ϰ� ��.
				*/
				INTERFACE_DECL_FUNC_T(bool, event_chain)(
					/* [r] */ i::frame::i_inputEventHelper * _eventhelper);

				// ���� : component�� ����.
				INTERFACE_DECL_FUNC_T(void, update)(
					/* [x] */ void);

				// ���� : component�� ȭ�鿡 �ѷ���.
				INTERFACE_DECL_FUNC_T(void, render)(
					/* [x] */ void);

				// ���� : component���� ������ ������ ��, component�� �ʱ�ȭ.
				INTERFACE_DECL_FUNC_T(void, reset)(
					/* [x] */ void){
					return;
				}

				// ���� : ���� x ��ǥ�� ����(��, set_X�Լ��� ȣ��Ǵ��� update �Լ��� ���� ������ �Ǿ� �����).
				CLASS_DECL_FUNC_T(float, get_AbsX)(
					/* [x] */ void)const;

				// ���� : ���� y ��ǥ�� ����(��, set_Y�Լ��� ȣ��Ǵ��� update �Լ��� ���� ������ �Ǿ� �����).
				CLASS_DECL_FUNC_T(float, get_AbsY)(
					/* [x] */ void)const;

			protected:

				// ���� : component�� �ð��� ��Ҹ� �����ϴ� ��ü.
				AutoDelete<Graphics> m_D3D10Graphics;

				// ���� :  �� component ������ �Ͼ ���콺 �̺�Ʈ�� �ܺο� �����ϴ� ��ü.
				AutoDelete<i::frame::i_Mouseable> m_Mouseable;

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
}