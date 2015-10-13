#pragma once



#include "tcpproxy.h"
#include "../../interface/network/client.h"



namespace hsdk
{
	namespace win
	{
		namespace network
		{

			// ���� : 
			DLL_DECL_CLASS(TCPClient)
				:public i::network::i_Client
			{
			public:

				// ������.
				CLASS_DECL_CONSTRUCTOR(TCPClient)(void);

				// �Ҹ���.
				CLASS_DECL_DESTRUCTOR(TCPClient)(void);

				// ������ Ư�� ��Ʈ�� ����
				INTERFACE_DECL_FUNC(connect)(
					/* [r] */ const char * _url,
					/* [r] */ unsigned int _port,
					/* [r] */ unsigned int _wait = 0);

				// ������ ����
				INTERFACE_DECL_FUNC(disconnect)(
					/* [x] */ void);

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

				// ���� : client���� ������ ������ ��, client�� �ʱ�ȭ.
				INTERFACE_DECL_FUNC(reset)(
					/* [x] */ void);

				// ���� : 
				CLASS_DECL_FUNC_T(SOCKET, get_Socket)(
					/* [x] */ void);

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
}