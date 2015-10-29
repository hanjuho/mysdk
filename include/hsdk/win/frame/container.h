#pragma once



#include "component.h"
#include <hash_map>


namespace hsdk
{
	namespace frame
	{

		// ���� : â�� ���� ��Ҹ� win32�� ����.
		DLL_DECL_CLASS(Container)
			: public Component
		{
		public:

			// ������
			CLASS_DECL_CONSTRUCTOR(Container)(
				_In_ float _x = 0.0f,
				_In_ float _y = 0.0f,
				_In_ float _w = 0.0f,
				_In_ float _h = 0.0f,
				_In_ i::frame::FRAME_FORM _form = i::frame::ABSOLUTE_FORM);

			// ���� �Ҹ���.
			CLASS_DECL_DESTRUCTOR(Container)(void);

			// ���� : �� container�� ���ο� ������Ʈ�� �߰�.
			INTERFACE_DECL_FUNC(add_Component)(
				/* [set] */ i_Component * _component);

			// ���� : �� container�κ��� _component�� ����.
			INTERFACE_DECL_FUNC(remove_Component)(
				_Inout_ i_Component * _component);

			// ���� : �� container�� _component�� �ִ��� �˻�.
			INTERFACE_DECL_FUNC_T(bool, contain_Component)(
				_In_ i_Component * _component)const;

			// ���� : �� container�κ��� _component�� ����.
			INTERFACE_DECL_FUNC(get_Component)(
				_Out_ i_Component * (&_component),
				_In_ unsigned int _id)const;

			/*
			���� : �̺�Ʈ�� �����ϴ� ���� Ȥ�� �� container�� ����(��, �θ� �Ž��� �ö��� ����).
			$ ���� : ��ȯ���� true�� ���, i_inputEvent�� ���� Ȥ�� �� component�� �ֽ��ϰ� ��.
			*/
			INTERFACE_DECL_FUNC_T(bool, event_chain)(
				_Inout_ i::frame::i_inputEventHelper * _eventhelper);

			// ���� : component ����.
			INTERFACE_DECL_FUNC_T(void, update)(
				_X_ void);

			// ���� : component�� ��ǥ�� ����.
			INTERFACE_DECL_FUNC_T(void, reform)(
				_X_ void);

			// ���� : container�� ȭ�鿡 �ѷ���.
			INTERFACE_DECL_FUNC_T(void, render)(
				_X_ void);

			// ���� : 
			INTERFACE_DECL_FUNC_T(void, clear)(
				_X_ void);

		protected:

			// ���� :
			std::hash_map<unsigned int, Component *> m_Container;

		};

	}
}