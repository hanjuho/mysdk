#pragma once



#include "../../../hsdk_common.h"



namespace hsdk
{
	namespace i
	{
		namespace criticalsection
		{

			// 설명 : 임계구역 event를 추상화.
			DECL_INTERFACE(i_Section)
			{

				// 가상 소멸자.
				CLASS_DECL_DESTRUCTOR(i_Section)(void)
				{

				};

				// 설명 : section로 들어감, 만원인 경우 _time만큼 대기.
				INTERFACE_DECL_FUNC(enter)(
					_In_ unsigned long _time) = 0;

				// 설명 : section로부터 나옴.
				INTERFACE_DECL_FUNC(leave)(
					_X_ void) = 0;

				// 설명 : section에 문제가 생긴 경우, section을 초기화.
				INTERFACE_DECL_FUNC(reset)(
					_X_ void) = 0;

			};

		}
	}
}