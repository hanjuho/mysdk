#include "tcpserver.h"
#include "tcpproxy.h"



using namespace hsdk::network;


//--------------------------------------------------------------------------------------
CLASS_IMPL_CONSTRUCTOR(TCPServer, TCPServer)(void)
: m_Port(0)
{
	// �̺�Ʈ�� �����Ѵ�
	IF_TRUE((m_Event = WSACreateEvent()) == WSA_INVALID_EVENT)
	{
		throw ADD_FLAG(HSDK_FAIL, WSAGetLastError());
	}
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_DESTRUCTOR(TCPServer, TCPServer)(void)
{
	// �̺�Ʈ�� �����Ѵ�
	IF_FALSE(WSACloseEvent(m_Event))
	{
		throw ADD_FLAG(HSDK_FAIL, WSAGetLastError());
	}

	// ������ �����Ѵ�
	HRESULT hr;
	IF_FAILED(hr = close())
	{
		throw hr;
	}
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(TCPServer, open)(
	_In_ unsigned int _port)
{
	// �� ���� 
	SOCKET new_socket;

	// ���ͳ� �������� ���� 4 (IPv4) �� ��Ʈ�� ��Ŷ TPC ������ �����Ѵ�
	IF_FAILED(new_socket = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, nullptr, 0, 0))
	{
		return ADD_FLAG(HSDK_FAIL, WSAGetLastError());
	}

	// �̺�Ʈ�� ������ �����Ѵ� 
	IF_FAILED(WSAEventSelect(new_socket, m_Event, FD_ACCEPT))
	{
		// ���� �ֱٿ� �߻��� ������ ����
		HRESULT hr = ADD_FLAG(HSDK_FAIL, WSAGetLastError());

		// ���� ������ ����
		closesocket(new_socket);

		// WSAEventSelect�� ��� ��ȯ
		return hr;
	}

	// SO_REUSEADDR : ����������� ���·� ���� Ŀ���� bind������ �����ϰ� �������� �߻��ϴ� ������ �ذ��ϱ� ����
	// ������ bind�� �Ҵ�� �����ڿ��� ���μ����� �� ����� �� �ֵ��� ����Ѵ�.
	INT optval = 1;
	IF_FAILED(setsockopt(new_socket, SOL_SOCKET, SO_REUSEADDR, LPCSTR(&optval), sizeof(optval)))
	{
		// ���� �ֱٿ� �߻��� ������ ����
		HRESULT hr = ADD_FLAG(HSDK_FAIL, WSAGetLastError());

		// ���� ������ ����
		closesocket(new_socket);

		return hr;
	}

	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(USHORT(_port));

	// ������ OS�� ���.
	IF_FAILED(bind(new_socket, (SOCKADDR *)&addr, sizeof(addr)))
	{
		// ���� �ֱٿ� �߻��� ������ ����
		HRESULT hr = ADD_FLAG(HSDK_FAIL, WSAGetLastError());

		// ���� ������ ����
		closesocket(new_socket);

		return hr;
	}

	// Ŭ���̾�Ʈ�� ����ϱ� ���� ������ �۽� ��� ���·� ����.
	IF_FAILED(listen(new_socket, SOMAXCONN))
	{
		// ���� �ֱٿ� �߻��� ������ ����
		HRESULT hr = ADD_FLAG(HSDK_FAIL, WSAGetLastError());

		// ���� ������ ����
		closesocket(new_socket);

		return hr;
	}

	SOCKET temp_socket;
	temp_socket = m_Socket;

	// ���� �ʱ�ȭ
	m_Socket = new_socket;
	m_Port = _port;

	// ���� ���� �Ұ�
	closesocket(temp_socket);

	return S_OK;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(TCPServer, close)(
	_In_ void)
{
	// ���� ������ ����
	closesocket(m_Socket);

	return S_OK;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(TCPServer, accept)(
	_Out_ hsdk::i::network::i_Proxy * (&_proxy),
	_In_ unsigned int _time)
{
	HRESULT hr;

	// ������ �����Ѵ�.
	SOCKET new_socket;
	unsigned int new_ip;
	IF_FAILED(hr = accept(new_socket, new_ip, _time))
	{
		return hr;
	}

	// ���Ͻø� �����Ѵ�.
	TCPProxy * new_proxy;
	try
	{
		new_proxy = new TCPProxy();
	}
	catch (long hr)
	{
		// ���� ���͵� ���� ������ ����
		closesocket(new_socket);
		return hr;
	}
	
	// ���Ͻø� �ʱ�ȭ�Ѵ�.
	IF_FAILED(hr = new_proxy->initailize(new_socket, new_ip))
	{
		// ���� ������ ����
		closesocket(new_socket);
		DEL_POINTER(new_proxy);

		return hr;
	}

	// ������ �Ķ���͸� ���� ��ȯ
	_proxy = new_proxy;

	return S_OK;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(TCPServer, reset)(
	_X_ void)
{
	return close() | open(m_Port);
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(TCPServer, accept)(
	_Out_ SOCKET & _socket,
	_Out_ unsigned int & _ip,
	_In_ unsigned int _time)
{
	HRESULT hr;

	// Ŭ���̾�Ʈ�� �����ϱ⸦ ��ٸ���.
	IF_FAILED(hr = WSAWaitForMultipleEvents(1, &m_Event, FALSE, _time, FALSE))
	{
		return ADD_FLAG(HSDK_FAIL, WSAGetLastError());
	}

	// �Լ� ȣ���� ���������� Ÿ�Ӿƿ��̴�.
	IF_TRUE(hr == WSA_WAIT_TIMEOUT)
	{
		return ADD_FLAG(HSDK_FAIL, WSA_WAIT_TIMEOUT);
	}

	// �̺�Ʈ�� �߻������� ���� �̺�Ʈ���� Ȯ���� �ʿ��ϴ�.
	WSAEnumNetworkEvents(m_Socket, m_Event, LPWSANETWORKEVENTS(&m_Events));

	// ������ ���� �õ�, �ٸ� �̺�Ʈ�� ������� ����.
	if (IS_FLAG(m_Events.lNetworkEvents, FD_ACCEPT))
	{
		IF_TRUE(hr = m_Events.iErrorCode[FD_ACCEPT_BIT])
		{
			return ADD_FLAG(HSDK_FAIL, hr);
		}
	}
	else
	{
		return ADD_FLAG(HSDK_FAIL, FD_ACCEPT);
	}

	sockaddr_in addr;
	INT	addr_len = sizeof(addr);

	// ������ �㰡�Ѵ�.
	_socket = ::accept(m_Socket, (sockaddr*)&addr, &addr_len);
	_ip = addr.sin_addr.S_un.S_addr;

	return S_OK;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(TCPServer, SOCKET, get_Socket)(
	_X_ void)
{
	return m_Socket;
}