#pragma once



#include "../../../hsdk_common.h"



namespace hsdk
{
	namespace i
	{
		namespace criticalsection
		{

			// 설명 : 임계구역 event를 추상화.
			DLL_DECL_INTERFACE(i_Event)
			{

				// 가상 소멸자.
				CLASS_DECL_DESTRUCTOR(i_Event)(void)
				{

				};

				// 설명 : thread가 대기 상태로부터 벗어남.
				INTERFACE_DECL_FUNC(signal)(
					_X_ void) = 0;

				// 설명 : thread가 signal 상태를 _time만큼 대기.
				INTERFACE_DECL_FUNC(wait)(
					_In_ unsigned long _time) = 0;

				// 설명 : event에 문제가 생긴 경우, event를 초기화.
				INTERFACE_DECL_FUNC(reset)(
					_X_ void) = 0;

			};

		}
	}
}