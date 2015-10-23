#pragma once



#include "component.h"
#include <hash_map>


namespace hsdk
{
	namespace win
	{
		namespace frame
		{

			// ���� : â�� ���� ��Ҹ� win32�� ����.
			DLL_DECL_CLASS(Container)
				: public Component
			{
			public:

				// ���� �Ҹ���.
				CLASS_DECL_DESTRUCTOR(Container)(void);

				// ���� : �� container�� ���ο� ������Ʈ�� �߰�.
				INTERFACE_DECL_FUNC(add_Component)(
					/* [set] */ i_Component * _component);

				// ���� : �� container�κ��� _component�� ����.
				INTERFACE_DECL_FUNC(remove_Component)(
					/* [r/w] */ i_Component * _component);

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
					/* [r/w] */ i::frame::i_inputEventHelper * _eventhelper);

				// ���� : component ����.
				INTERFACE_DECL_FUNC_T(void, update)(
					/* [x] */ void);
				
				// ���� : component�� ��ǥ�� ����.
				INTERFACE_DECL_FUNC_T(void, reform)(
					/* [x] */ void);

				// ���� : container�� ȭ�鿡 �ѷ���.
				INTERFACE_DECL_FUNC_T(void, render)(
					/* [x] */ void);

				// ���� : 
				INTERFACE_DECL_FUNC_T(void, clear)(
					/* [x] */ void);

			protected:

				// ���� :
				std::hash_map<unsigned int, Component *> m_Container;

			};

		}
	}
}