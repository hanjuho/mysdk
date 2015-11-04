#pragma once



#include "tcpproxy.h"
#include "../../interface/network/client.h"



namespace hsdk
{
	namespace network
	{

		// 설명 : 
		DECL_CLASS(TCPClient)
			:public i::network::i_Client
		{
		public:

			// 생성자.
			CLASS_DECL_CONSTRUCTOR(TCPClient)(void);

			// 소멸자.
			CLASS_DECL_DESTRUCTOR(TCPClient)(void);

			// 서버의 특정 포트로 접속
			INTERFACE_DECL_FUNC(connect)(
				_In_ const char * _url,
				_In_ unsigned int _port,
				_In_ unsigned int _wait = 0);

			// 서버와 단절
			INTERFACE_DECL_FUNC(disconnect)(
				_X_ void);

			// 설명 : _context를 _offset에서부터 _size만큼 전송.
			INTERFACE_DECL_FUNC(send)(
				_In_ char * _context,
				_In_ unsigned int _offset,
				_In_ unsigned int _size);

			// 설명 : _size만큼의 _context를 수신.
			INTERFACE_DECL_FUNC(receive)(
				_Out_ char * (&_context),
				_Out_ unsigned int(&_size));

			// 설명 : 리시브 신호를 대기.
			INTERFACE_DECL_FUNC(wait_Recv)(
				_In_ unsigned int _time);

			// 설명 : client에게 문제가 생겼을 때, client를 초기화.
			INTERFACE_DECL_FUNC(reset)(
				_X_ void);

			// 설명 : 
			CLASS_DECL_FUNC_T(SOCKET, get_Socket)(
				_X_ void);

		protected:

			// 설명 : 
			TCPProxy m_Proxy;

			// 설명 : 
			const char * m_Url;

			// 설명 : 
			unsigned int m_Port;

		};

	}
}