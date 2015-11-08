#pragma once



#include "../../interface/criticalsection/section.h"
#include <Windows.h>



namespace hsdk
{
	namespace criticalsection
	{

		// ���� : ���� ������ ���� �Ӱ� ����, _maxCount ��ŭ�� �����尡 ������ �� �ִ� �Ӱ豸���� ����.
		DECL_CLASS(Semaphore) final
			: public i::criticalsection::i_Section
		{
		public:

			// ������.
			CLASS_DECL_CONSTRUCTOR(Semaphore)(
				_In_ unsigned int _initCount,
				_In_ unsigned int _maxCount);

			// �Ҹ���.
			CLASS_DECL_DESTRUCTOR(Semaphore)(void);

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
			const unsigned int my_initCount;

			// ���� : 
			const unsigned int my_maxCount;

			// ���� : 
			HANDLE my_Semaphore;

		};

	}
}