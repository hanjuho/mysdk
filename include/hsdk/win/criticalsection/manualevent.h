#pragma once



#include "../../interface/criticalsection/event.h"
#include <Windows.h>



namespace hsdk
{
	namespace win
	{
		namespace criticalsection
		{

			// ���� : ���� ������ ���� �Ӱ� ����, signal ���� �� ��, ��� �����尡 ������ �� �ִ� �Ӱ豸���� ����.
			DLL_DECL_CLASS(ManualEvent) final
				: public i::criticalsection::i_Event
			{
			public:

				// ������.
				CLASS_DECL_CONSTRUCTOR(ManualEvent)(void);

				// �Ҹ���.
				CLASS_DECL_DESTRUCTOR(ManualEvent)(void);

				// ���� : thread�� ��� ���·κ��� ���.
				INTERFACE_DECL_FUNC(signal)(
					/* [x] */ void);

				// ���� : thread�� signal ���¸� _time��ŭ ���.
				INTERFACE_DECL_FUNC(wait)(
					/* [r] */ unsigned long _time);

				// ���� : event�� ������ ���� ���, event�� �ʱ�ȭ.
				INTERFACE_DECL_FUNC(reset)(
					/* [x] */ void);

				// ���� : event�� none - signal ���·� ����.
				CLASS_DECL_FUNC(lock)(
					/* [x] */ void);

			private:

				// ���� : 
				HANDLE my_Event;

			};

		}
	}
}