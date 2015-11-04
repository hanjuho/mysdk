#pragma once



#include "tcpproxy.h"
#include "../../interface/network/client.h"



namespace hsdk
{
	namespace network
	{

		// ���� : 
		DECL_CLASS(TCPClient)
			:public i::network::i_Client
		{
		public:

			// ������.
			CLASS_DECL_CONSTRUCTOR(TCPClient)(void);

			// �Ҹ���.
			CLASS_DECL_DESTRUCTOR(TCPClient)(void);

			// ������ Ư�� ��Ʈ�� ����
			INTERFACE_DECL_FUNC(connect)(
				_In_ const char * _url,
				_In_ unsigned int _port,
				_In_ unsigned int _wait = 0);

			// ������ ����
			INTERFACE_DECL_FUNC(disconnect)(
				_X_ void);

			// ���� : _context�� _offset�������� _size��ŭ ����.
			INTERFACE_DECL_FUNC(send)(
				_In_ char * _context,
				_In_ unsigned int _offset,
				_In_ unsigned int _size);

			// ���� : _size��ŭ�� _context�� ����.
			INTERFACE_DECL_FUNC(receive)(
				_Out_ char * (&_context),
				_Out_ unsigned int(&_size));

			// ���� : ���ú� ��ȣ�� ���.
			INTERFACE_DECL_FUNC(wait_Recv)(
				_In_ unsigned int _time);

			// ���� : client���� ������ ������ ��, client�� �ʱ�ȭ.
			INTERFACE_DECL_FUNC(reset)(
				_X_ void);

			// ���� : 
			CLASS_DECL_FUNC_T(SOCKET, get_Socket)(
				_X_ void);

		protected:

			// ���� : 
			TCPProxy m_Proxy;

			// ���� : 
			const char * m_Url;

			// ���� : 
			unsigned int m_Port;

		};

	}
}