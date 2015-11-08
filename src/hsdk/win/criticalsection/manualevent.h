#pragma once



#include "../../interface/criticalsection/event.h"
#include <Windows.h>



namespace hsdk
{
	namespace criticalsection
	{

		// ���� : ���� ������ ���� �Ӱ� ����, signal ���� �� ��, ��� �����尡 ������ �� �ִ� �Ӱ豸���� ����.
		DECL_CLASS(ManualEvent) final
			: public i::criticalsection::i_Event
		{
		public:

			// ������.
			CLASS_DECL_CONSTRUCTOR(ManualEvent)(void);

			// �Ҹ���.
			CLASS_DECL_DESTRUCTOR(ManualEvent)(void);

			// ���� : thread�� ��� ���·κ��� ���.
			INTERFACE_DECL_FUNC(signal)(
				_X_ void);

			// ���� : thread�� signal ���¸� _time��ŭ ���.
			INTERFACE_DECL_FUNC(wait)(
				_In_ unsigned long _time);

			// ���� : event�� ������ ���� ���, event�� �ʱ�ȭ.
			INTERFACE_DECL_FUNC(reset)(
				_X_ void);

			// ���� : event�� none - signal ���·� ����.
			CLASS_DECL_FUNC(lock)(
				_X_ void);

		private:

			// ���� : 
			HANDLE my_Event;

		};

	}
}