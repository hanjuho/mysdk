#pragma once



#include "common.h"
#include "../../interface/network/server.h"



namespace hsdk
{
	namespace network
	{

		// 설명 : 
		DECL_CLASS(TCPServer)
			:public i::network::i_Server
		{
		public:

			// 생성자.
			CLASS_DECL_CONSTRUCTOR(TCPServer)(void);

			// 소멸자.
			CLASS_DECL_DESTRUCTOR(TCPServer)(void);

			// 설명 : 특정 포트로 클라이언트와 통신할 게이트를 오픈.
			INTERFACE_DECL_FUNC(open)(
				_In_ unsigned int _port);

			// 설명 : 열린 포트를 닫음.
			INTERFACE_DECL_FUNC(close)(
				_In_ void);

			// 설명 : server에게 접근할 client를 _time만큼 대기.
			INTERFACE_DECL_FUNC(accept)(
				_Out_ i::network::i_Proxy * (&_proxy),
				_In_ unsigned int _time);

			// 설명 : server에 문제가 생겼을 때, server를 초기화.
			INTERFACE_DECL_FUNC(reset)(
				_X_ void);

			// 설명 : server에게 접근할 client를 _time만큼 대기.
			CLASS_DECL_FUNC(accept)(
				_Out_ SOCKET & _socket,
				_Out_ unsigned int & _ip,
				_In_ unsigned int _time);

			// 설명 : 
			CLASS_DECL_FUNC_T(SOCKET, get_Socket)(
				_X_ void);

		protected:

			// 설명 : 
			WSANETWORKEVENTS m_Events;

			// 설명 : 
			WSAEVENT m_Event;

			// 설명 : 
			SOCKET m_Socket;

			// 설명 :
			unsigned int m_Port;

		};

	}
}