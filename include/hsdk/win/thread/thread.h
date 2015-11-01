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
		설명 : 새로운 분기를 생성하는 객체
		참고1 : 생성자 파라미터 _task가 nullptr 값이라면, Thread::func를 구현해야 함.
		참고2 : 생성자 파라미터 _task가 nullptr 값이 아니라면, Thread::func는 사용되지 않음.
		*/
		DLL_DECL_CLASS(Thread) final
			: public i::thread::i_Thread, public i_Task
		{
		public:

			// 생성자.
			CLASS_DECL_CONSTRUCTOR(Thread)(
				/* [set] */ i_Task * _task = nullptr);

			// 소멸자.
			CLASS_DECL_DESTRUCTOR(Thread)(void);

			// 설명 : 비동기 프로세스를 시작.
			INTERFACE_DECL_FUNC(start)(
				_X_ void);

			// 설명 : 비동기 프로세스를 종료.
			INTERFACE_DECL_FUNC(kill)(
				_X_ void);

			// 설명 : thread가 종료되기를 _time만큼 기다림.
			INTERFACE_DECL_FUNC(wait)(
				_In_ unsigned int _time);

			// 설명 : thread에 문제가 생겼을 때, thread를 초기화.
			INTERFACE_DECL_FUNC(reset)(
				_X_ void);

			// 설명 : 
			INTERFACE_DECL_FUNC_T(void, func)(
				_X_ void) {}

		protected:

			// 설명 : 
			HANDLE m_Thread;

			// 설명 : 
			unsigned long m_ThreadID;

		private:

			// 설명 : 
			AutoDelete<i_Task> my_Task;

		};

	}
}