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
				
				// ���� : message procedure.
				INTERFACE_DECL_FUNC_T(void, event_Proc)(
					/* [r] */unsigned int _uEvent,
					/* [r] */unsigned int _wParam,
					/* [r] */unsigned long _lParam);

			protected:
				
				// ���� : 
				inputEventHelper m_inputEventHelper;

			private:



			};

		}
	}
}