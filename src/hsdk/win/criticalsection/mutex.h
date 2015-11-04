#pragma once



#include "../../interface/criticalsection/section.h"
#include <Windows.h>



namespace hsdk
{
	namespace criticalsection
	{

		// ���� : ���� ������ ���� �Ӱ� ����, �� �ϳ��� �����常�� ������ �� �ִ� �Ӱ豸���� ����.
		DECL_CLASS(Mutex) final
			: public i::criticalsection::i_Section
		{
		public:

			// ������.
			CLASS_DECL_CONSTRUCTOR(Mutex)(void);

			// �Ҹ���.
			CLASS_DECL_DESTRUCTOR(Mutex)(void);

			// ���� : section�� ��, ������ ��� _time��ŭ ���.
			INTERFACE_DECL_FUNC(enter)(
				_In_ unsigned long _time);

			// ���� : section�κ��� ����.
			INTERFACE_DECL_FUNC(leave)(
				_X_ void);

			// ���� : section�� ������ ���� ���, section�� �ʱ�ȭ.
			INTERFACE_DECL_FUNC(reset)(
				_X_ void);

		private:

			// ���� : 
			HANDLE my_Mutex;

		};

	}
}