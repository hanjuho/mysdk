#pragma once



#include "common.h"
#include "../../interface/network/proxy.h"



namespace hsdk
{
	namespace network
	{

		// ���� : 
		DECL_CLASS(TCPProxy)
			:public i::network::i_Proxy
		{
		public:

			// ������.
			CLASS_DECL_CONSTRUCTOR(TCPProxy)(void);

			// �Ҹ���.
			CLASS_DECL_DESTRUCTOR(TCPProxy)(void);

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

			// ���� �ʱ�ȭ.
			CLASS_DECL_FUNC(initailize)(
				_In_ SOCKET _socket,
				_In_ unsigned int _ip);

			// ���� : 
			CLASS_DECL_FUNC_T(SOCKET, get_Socket)(
				_X_ void);

		protected:

			// ���� : 
			unsigned int m_ip;

			// ���� : 
			SOCKET m_Socket;

			// ���� : 
			WSAEVENT m_Event;

			// ���� : 
			WSANETWORKEVENTS m_Events;

		};

	}
}