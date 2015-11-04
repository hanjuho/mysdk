#pragma once



#include "common.h"
#include "../../interface/network/server.h"



namespace hsdk
{
	namespace network
	{

		// ���� : 
		DECL_CLASS(TCPServer)
			:public i::network::i_Server
		{
		public:

			// ������.
			CLASS_DECL_CONSTRUCTOR(TCPServer)(void);

			// �Ҹ���.
			CLASS_DECL_DESTRUCTOR(TCPServer)(void);

			// ���� : Ư�� ��Ʈ�� Ŭ���̾�Ʈ�� ����� ����Ʈ�� ����.
			INTERFACE_DECL_FUNC(open)(
				_In_ unsigned int _port);

			// ���� : ���� ��Ʈ�� ����.
			INTERFACE_DECL_FUNC(close)(
				_In_ void);

			// ���� : server���� ������ client�� _time��ŭ ���.
			INTERFACE_DECL_FUNC(accept)(
				_Out_ i::network::i_Proxy * (&_proxy),
				_In_ unsigned int _time);

			// ���� : server�� ������ ������ ��, server�� �ʱ�ȭ.
			INTERFACE_DECL_FUNC(reset)(
				_X_ void);

			// ���� : server���� ������ client�� _time��ŭ ���.
			CLASS_DECL_FUNC(accept)(
				_Out_ SOCKET & _socket,
				_Out_ unsigned int & _ip,
				_In_ unsigned int _time);

			// ���� : 
			CLASS_DECL_FUNC_T(SOCKET, get_Socket)(
				_X_ void);

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