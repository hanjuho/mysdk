#pragma once



#include "common.h"
#include "../../interface/network/proxy.h"



namespace hsdk
{
	namespace win
	{
		namespace network
		{

			// 설명 : 
			DLL_DECL_CLASS(TCPProxy)
				:public i::network::i_Proxy
			{
			public:

				// 생성자.
				CLASS_DECL_CONSTRUCTOR(TCPProxy)(void);
				
				// 소멸자.
				CLASS_DECL_DESTRUCTOR(TCPProxy)(void);

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

				// 소켓 초기화.
				CLASS_DECL_FUNC(initailize)(
					/* [r] */ SOCKET _socket,
					/* [r] */ unsigned int _ip);

				// 설명 : 
				CLASS_DECL_FUNC_T(SOCKET, get_Socket)(
					/* [x] */ void);

			protected:

				// 설명 : 
				unsigned int m_ip;

				// 설명 : 
				SOCKET m_Socket;

				// 설명 : 
				WSAEVENT m_Event;

				// 설명 : 
				WSANETWORKEVENTS m_Events;

			};

		}
	}
}