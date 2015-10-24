#pragma once



#include "proxy.h"



namespace hsdk
{
	namespace i
	{
		namespace network
		{

			// 설명 : network에서 서버와 송신하는 client를 추상화.
			DLL_DECL_INTERFACE(i_Client)
				: public i_Proxy
			{

				// 가상 소멸자.
				CLASS_DECL_DESTRUCTOR(i_Client)(void)
				{

				}

				// 서버의 특정 포트로 접속
				INTERFACE_DECL_FUNC(connect)(
					_In_ const char * _url,
					_In_ unsigned int _port,
					_In_ unsigned int _wait = 0) = 0;

				// 서버와 단절
				INTERFACE_DECL_FUNC(disconnect)(
					_X_ void) = 0;

				// 설명 : client에게 문제가 생겼을 때, client를 초기화.
				INTERFACE_DECL_FUNC(reset)(
					_X_ void) = 0;

			};

		}
	}
}