#pragma once



#include "../../interface/criticalsection/event.h"
#include <Windows.h>



namespace hsdk
{
	namespace criticalsection
	{

		// 설명 : 다중 쓰레드 제어 임계 구역, signal 상태 일 때, 모든 쓰레드가 출입할 수 있는 임계구역을 만듦.
		DECL_CLASS(ManualEvent) final
			: public i::criticalsection::i_Event
		{
		public:

			// 생성자.
			CLASS_DECL_CONSTRUCTOR(ManualEvent)(void);

			// 소멸자.
			CLASS_DECL_DESTRUCTOR(ManualEvent)(void);

			// 설명 : thread가 대기 상태로부터 벗어남.
			INTERFACE_DECL_FUNC(signal)(
				_X_ void);

			// 설명 : thread가 signal 상태를 _time만큼 대기.
			INTERFACE_DECL_FUNC(wait)(
				_In_ unsigned long _time);

			// 설명 : event에 문제가 생긴 경우, event를 초기화.
			INTERFACE_DECL_FUNC(reset)(
				_X_ void);

			// 설명 : event를 none - signal 상태로 만듦.
			CLASS_DECL_FUNC(lock)(
				_X_ void);

		private:

			// 설명 : 
			HANDLE my_Event;

		};

	}
}