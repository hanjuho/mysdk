#pragma once



#include "common.h"
#include "../../interface/network/proxy.h"



namespace hsdk
{
	namespace win
	{
		namespace network
		{

			// ���� : 
			DLL_DECL_CLASS(TCPProxy)
				:public i::network::i_Proxy
			{
			public:

				// ������.
				CLASS_DECL_CONSTRUCTOR(TCPProxy)(void);
				
				// �Ҹ���.
				CLASS_DECL_DESTRUCTOR(TCPProxy)(void);

				// ���� : _context�� _offset�������� _size��ŭ ����.
				INTERFACE_DECL_FUNC(send)(
					/* [r] */ char * _context,
					/* [r] */ unsigned int _offset,
					/* [r] */ unsigned int _size);

				// ���� : _size��ŭ�� _context�� ����.
				INTERFACE_DECL_FUNC(receive)(
					/* [w] */ char * (&_context),
					/* [w] */ unsigned int(&_size));

				// ���� : ���ú� ��ȣ�� ���.
				INTERFACE_DECL_FUNC(wait_Recv)(
					/* [r] */ unsigned int _time);

				// ���� �ʱ�ȭ.
				CLASS_DECL_FUNC(initailize)(
					/* [r] */ SOCKET _socket,
					/* [r] */ unsigned int _ip);

				// ���� : 
				CLASS_DECL_FUNC_T(SOCKET, get_Socket)(
					/* [x] */ void);

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
}