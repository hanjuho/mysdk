#pragma once



#include "../../interface/criticalsection/event.h"
#include <Windows.h>



namespace hsdk
{
	namespace win
	{
		namespace criticalsection
		{

			/*
			���� : ���� ������ ���� �Ӱ� ����, �� �ϳ��� �����尡 ������ �� �ִ� �Ӱ豸���� ����.
			���� : � ������� ��⿡�� ����� event�� �ڵ����� none - signal ���°� ��.
			*/
			DLL_DECL_CLASS(AutoResetEvent) final
				: public i::criticalsection::i_Event
			{
			public:

				// ������.
				CLASS_DECL_CONSTRUCTOR(AutoResetEvent)(void);

				// �Ҹ���.
				CLASS_DECL_DESTRUCTOR(AutoResetEvent)(void);
				
				// ���� : thread�� ��� ���·κ��� ���.
				INTERFACE_DECL_FUNC(signal)(
					/* [x] */ void);

				// ���� : thread�� signal ���¸� _time��ŭ ���.
				INTERFACE_DECL_FUNC(wait)(
					/* [r] */ unsigned long _time);

				// ���� : event�� ������ ���� ���, event�� �ʱ�ȭ.
				INTERFACE_DECL_FUNC(reset)(
					/* [x] */ void);

			private:

				// ���� : 
				HANDLE my_Event;

			};

		}
	}
}