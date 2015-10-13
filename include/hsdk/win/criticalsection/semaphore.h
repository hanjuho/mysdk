#pragma once



#include "../../interface/criticalsection/section.h"
#include <Windows.h>



namespace hsdk
{
	namespace win
	{
		namespace criticalsection
		{

			// 설명 : 다중 쓰레드 제어 임계 구역, _maxCount 만큼의 쓰레드가 출입할 수 있는 임계구역을 만듦.
			DLL_DECL_CLASS(Semaphore) final
				: public i::criticalsection::i_Section
			{
			public:

				// 생성자.
				CLASS_DECL_CONSTRUCTOR(Semaphore)(
					/* [r] */ unsigned int _initCount,
					/* [r] */ unsigned int _maxCount);

				// 소멸자.
				CLASS_DECL_DESTRUCTOR(Semaphore)(void);

				// 설명 : section로 들어감, 만원인 경우 _time만큼 대기.
				INTERFACE_DECL_FUNC(enter)(
					/* [r] */ unsigned long _time);

				// 설명 : section로부터 나옴.
				INTERFACE_DECL_FUNC(leave)(
					/* [x] */ void);

				// 설명 : section에 문제가 생긴 경우, section을 초기화.
				INTERFACE_DECL_FUNC(reset)(
					/* [x] */ void);

			private:

				// 설명 : 
				const unsigned int my_initCount;

				// 설명 : 
				const unsigned int my_maxCount;

				// 설명 : 
				HANDLE my_Semaphore;

			};

		}
	}
}