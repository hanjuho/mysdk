#pragma once



#include "container.h"
#include "inputeventhelper.h"



namespace hsdk
{
	namespace win
	{
		namespace frame
		{

			// ���� : â�� ���� ��Ҹ� win32�� ����.
			DLL_DECL_CLASS(Frame)
				: public Container
			{
			public:

				// ������.
				CLASS_DECL_CONSTRUCTOR(Frame)(void);

				// ���� �Ҹ���.
				CLASS_DECL_DESTRUCTOR(Frame)(void);

				/*
				���� : Frame�� ����.
				$ ���� : �ʱ⿡ ������Ʈ���� �߰��� ��, �� �Լ��� �� �� ȣ���ϴ� ���� ����(�ݺ������� ȣ���ϴ� ���� ��ȿ������).
				*/
				INTERFACE_DECL_FUNC_T(void, update)(
					/* [x] */ void);

				// ���� : Frame�� ȭ�鿡 �ѷ���.
				INTERFACE_DECL_FUNC_T(void, render)(
					/* [x] */ void);

				// ���� : message procedure.
				INTERFACE_DECL_FUNC_T(void, message_Proc)(
					/* [r] */unsigned int _uMsg,
					/* [r] */unsigned int _wParam,
					/* [r] */unsigned long _lParam);
				
				// ���� : �Ķ���� ���� true�� ��ũ���� �����ְ�, false�� ����.
				INTERFACE_DECL_FUNC(set_Visible)(
					/* [r] */ bool _visible);

				// ���� :
				CLASS_DECL_FUNC_T(void, set_FullScreen)(
					/* [r] */ bool _full);
				
				// ���� :
				CLASS_DECL_FUNC_T(BOOL, is_FullScreen)(
					/* [x] */ void)const;

			protected:

				// ���� : 
				inputEventHelper m_inputEventHelper;

			};

		}
	}
}