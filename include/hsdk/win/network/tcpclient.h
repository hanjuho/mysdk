#pragma once



#include "tcpproxy.h"
#include "../../interface/network/client.h"



namespace hsdk
{
	namespace win
	{
		namespace network
		{

			// 설명 : 
			DLL_DECL_CLASS(TCPClient)
				:public i::network::i_Client
			{
			public:

				// 생성자.
				CLASS_DECL_CONSTRUCTOR(TCPClient)(void);

				// 소멸자.
				CLASS_DECL_DESTRUCTOR(TCPClient)(void);

				// 서버의 특정 포트로 접속
				INTERFACE_DECL_FUNC(connect)(
					/* [r] */ const char * _url,
					/* [r] */ unsigned int _port,
					/* [r] */ unsigned int _wait = 0);

				// 서버와 단절
				INTERFACE_DECL_FUNC(disconnect)(
					/* [x] */ void);

				// 설명 : _context를 _offset에서부터 _size만큼 전송.
				INTERFACE_DECL_FUNC(send)(
					/* [r] */ char * _context,
					/* [r] */ unsigned int _offset,
					/* [r] */ unsigned int _size);

				// 설명 : _size만큼의 _context를 수신.
				INTERFACE_DECL_FUNC(receive)(
					/* [w] */ char * (&_context),
					/* [w] */ unsigned int(&_size));

				// 설명 : 리시브 신호를 대기.
				INTERFACE_DECL_FUNC(wait_Recv)(
					/* [r] */ unsigned int _time);

				// 설명 : client에게 문제가 생겼을 때, client를 초기화.
				INTERFACE_DECL_FUNC(reset)(
					/* [x] */ void);

				// 설명 : 
				CLASS_DECL_FUNC_T(SOCKET, get_Socket)(
					/* [x] */ void);

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
}