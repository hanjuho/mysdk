#pragma once



#include "../../interface/criticalsection/event.h"
#include <Windows.h>



namespace hsdk
{
	namespace criticalsection
	{

		/*
		���� : ���� ������ ���� �Ӱ� ����, �� �ϳ��� �����尡 ������ �� �ִ� �Ӱ豸���� ����.
		���� : � ������� ��⿡�� ����� event�� �ڵ����� none - signal ���°� ��.
		*/
		DECL_CLASS(AutoResetEvent) final
			: public i::criticalsection::i_Event
		{
		public:

			// ������.
			CLASS_DECL_CONSTRUCTOR(AutoResetEvent)(void);

			// �Ҹ���.
			CLASS_DECL_DESTRUCTOR(AutoResetEvent)(void);

			// ���� : thread�� ��� ���·κ��� ���.
			INTERFACE_DECL_FUNC(signal)(
				_X_ void);

			// ���� : thread�� signal ���¸� _time��ŭ ���.
			INTERFACE_DECL_FUNC(wait)(
				_In_ unsigned long _time);

			// ���� : event�� ������ ���� ���, event�� �ʱ�ȭ.
			INTERFACE_DECL_FUNC(reset)(
				_X_ void);

		private:

			// ���� : 
			HANDLE my_Event;

		};

	}
}