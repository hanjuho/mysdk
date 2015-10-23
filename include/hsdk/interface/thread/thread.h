#pragma once



#include "../../../hsdk_common.h"
#include <string>



namespace hsdk
{
	namespace i
	{
		namespace thread
		{

			// 설명 : 비동기 프로세스를 추상화.
			DLL_DECL_INTERFACE(i_Thread)
			{
				
				// 가상 소멸자.
				CLASS_DECL_DESTRUCTOR(i_Thread)(void)
				{

				}

				// 설명 : 비동기 프로세스를 시작.
				INTERFACE_DECL_FUNC(start)(
					/* [x] */ void) = 0;

				// 설명 : 비동기 프로세스를 종료.
				INTERFACE_DECL_FUNC(kill)(
					/* [x] */ void) = 0;

				// 설명 : thread가 종료되기를 _time만큼 기다림.
				INTERFACE_DECL_FUNC(wait)(
					_In_ unsigned int _time) = 0;

				// 설명 : thread에 문제가 생겼을 때, thread를 초기화.
				INTERFACE_DECL_FUNC(reset)(
					/* [x] */ void) = 0;

			};

		}
	}
}