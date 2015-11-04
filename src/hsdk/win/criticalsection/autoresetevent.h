#pragma once



#include "../../interface/criticalsection/event.h"
#include <Windows.h>



namespace hsdk
{
	namespace criticalsection
	{

		/*
		설명 : 단일 쓰레드 제어 임계 구역, 단 하나의 쓰레드가 출입할 수 있는 임계구역을 만듦.
		참고 : 어떤 쓰레드라도 대기에서 벗어나면 event는 자동으로 none - signal 상태가 됨.
		*/
		DECL_CLASS(AutoResetEvent) final
			: public i::criticalsection::i_Event
		{
		public:

			// 생성자.
			CLASS_DECL_CONSTRUCTOR(AutoResetEvent)(void);

			// 소멸자.
			CLASS_DECL_DESTRUCTOR(AutoResetEvent)(void);

			// 설명 : thread가 대기 상태로부터 벗어남.
			INTERFACE_DECL_FUNC(signal)(
				_X_ void);

			// 설명 : thread가 signal 상태를 _time만큼 대기.
			INTERFACE_DECL_FUNC(wait)(
				_In_ unsigned long _time);

			// 설명 : event에 문제가 생긴 경우, event를 초기화.
			INTERFACE_DECL_FUNC(reset)(
				_X_ void);

		private:

			// 설명 : 
			HANDLE my_Event;

		};

	}
}