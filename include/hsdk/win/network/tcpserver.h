#pragma once



#include "common.h"
#include "../../interface/network/server.h"



namespace hsdk
{
	namespace win
	{
		namespace network
		{

			// ���� : 
			DLL_DECL_CLASS(TCPServer)
				:public i::network::i_Server
			{
			public:

				// ������.
				CLASS_DECL_CONSTRUCTOR(TCPServer)(void);

				// �Ҹ���.
				CLASS_DECL_DESTRUCTOR(TCPServer)(void);

				// ���� : Ư�� ��Ʈ�� Ŭ���̾�Ʈ�� ����� ����Ʈ�� ����.
				INTERFACE_DECL_FUNC(open)(
					/* [r] */ unsigned int _port);

				// ���� : ���� ��Ʈ�� ����.
				INTERFACE_DECL_FUNC(close)(
					/* [r] */ void);

				// ���� : server���� ������ client�� _time��ŭ ���.
				INTERFACE_DECL_FUNC(accept)(
					/* [w] */ i::network::i_Proxy * (&_proxy),
					/* [r] */ unsigned int _time);

				// ���� : server�� ������ ������ ��, server�� �ʱ�ȭ.
				INTERFACE_DECL_FUNC(reset)(
					/* [x] */ void);

				// ���� : server���� ������ client�� _time��ŭ ���.
				CLASS_DECL_FUNC(accept)(
					/* [w] */ SOCKET & _socket,
					/* [w] */ unsigned int & _ip,
					/* [r] */ unsigned int _time);

				// ���� : 
				CLASS_DECL_FUNC_T(SOCKET, get_Socket)(
					/* [x] */ void);

			protected:
				
				// ���� : 
				WSANETWORKEVENTS m_Events;

				// ���� : 
				WSAEVENT m_Event;

				// ���� : 
				SOCKET m_Socket;

				// ���� :
				unsigned int m_Port;

			};

		}
	}
}