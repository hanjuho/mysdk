#pragma once



#include "../../interface/thread/thread.h"
#include "../../autodelete.h"
#include "task.h"
#include <Windows.h>



namespace hsdk
{
	namespace thread
	{

		/*
		���� : ���ο� �б⸦ �����ϴ� ��ü
		����1 : ������ �Ķ���� _task�� nullptr ���̶��, Thread::func�� �����ؾ� ��.
		����2 : ������ �Ķ���� _task�� nullptr ���� �ƴ϶��, Thread::func�� ������ ����.
		*/
		DLL_DECL_CLASS(Thread) final
			: public i::thread::i_Thread, public i_Task
		{
		public:

			// ������.
			CLASS_DECL_CONSTRUCTOR(Thread)(
				/* [set] */ i_Task * _task = nullptr);

			// �Ҹ���.
			CLASS_DECL_DESTRUCTOR(Thread)(void);

			// ���� : �񵿱� ���μ����� ����.
			INTERFACE_DECL_FUNC(start)(
				_X_ void);

			// ���� : �񵿱� ���μ����� ����.
			INTERFACE_DECL_FUNC(kill)(
				_X_ void);

			// ���� : thread�� ����Ǳ⸦ _time��ŭ ��ٸ�.
			INTERFACE_DECL_FUNC(wait)(
				_In_ unsigned int _time);

			// ���� : thread�� ������ ������ ��, thread�� �ʱ�ȭ.
			INTERFACE_DECL_FUNC(reset)(
				_X_ void);

			// ���� : 
			INTERFACE_DECL_FUNC_T(void, func)(
				_X_ void) {}

		protected:

			// ���� : 
			HANDLE m_Thread;

			// ���� : 
			unsigned long m_ThreadID;

		private:

			// ���� : 
			AutoDelete<i_Task> my_Task;

		};

	}
}