#pragma once



#include "proxy.h"



namespace hsdk
{
	namespace i
	{
		namespace network
		{
			
			// 설명 : network에서 client를 동기화하는 server를 추상화.
			DECL_INTERFACE(i_Server)
			{

				// 가상 소멸자.
				CLASS_DECL_DESTRUCTOR(i_Server)(void)
				{

				}

				// 설명 : 특정 포트로 클라이언트와 통신할 게이트를 오픈.
				INTERFACE_DECL_FUNC(open)(
					_In_ unsigned int _port) = 0;

				// 설명 : 열린 포트를 닫음.
				INTERFACE_DECL_FUNC(close)(
					_In_ void) = 0;

				// 설명 : server에게 접근할 client를 _time만큼 대기.
				INTERFACE_DECL_FUNC(accept)(
					_Out_ i_Proxy * (&_proxy),
					_In_ unsigned int _time) = 0;

				// 설명 : server에 문제가 생겼을 때, server를 초기화.
				INTERFACE_DECL_FUNC(reset)(
					_X_ void) = 0;

			};

		}
	}
}