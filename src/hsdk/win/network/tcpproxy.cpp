#include "tcpproxy.h"



using namespace hsdk::network;


//--------------------------------------------------------------------------------------
CLASS_IMPL_CONSTRUCTOR(TCPProxy, TCPProxy)(void)
{
	// �̺�Ʈ�� �����Ѵ�
	IF_TRUE((m_Event = WSACreateEvent()) == WSA_INVALID_EVENT)
	{
		throw ADD_FLAG(HSDK_FAIL, WSAGetLastError());
	}
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_DESTRUCTOR(TCPProxy, TCPProxy)(void)
{
	// �̺�Ʈ�� �����Ѵ�
	IF_FALSE(WSACloseEvent(m_Event))
	{
		throw ADD_FLAG(HSDK_FAIL, WSAGetLastError());
	}

	// ������ �ݴ´�.
	HRESULT hr;
	IF_FAILED(hr = shutdown(m_Socket, SD_BOTH))
	{
		IF_FALSE(hr == 0xffffffff)
		{
			throw ADD_FLAG(HSDK_FAIL, WSAGetLastError());
		}
	}
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(TCPProxy, send)(
	_In_ char * _context,
	_In_ unsigned int _offset,
	_In_ unsigned int _size)
{
	// ��Ŷ���� ��ȯ�� ������ ���� �۽��Ѵ�.
	IF_FAILED(::send(m_Socket, &_context[_offset], _size, 0))
	{
		return ADD_FLAG(HSDK_FAIL, WSAGetLastError());
	}

	return S_OK;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(TCPProxy, receive)(
	_Out_ char * (&_context),
	_Out_ unsigned int (&_size))
{
	unsigned int buffer_len;

	// ���Ͽ� ����ִ� ������ ���� �����Ѵ�.
	buffer_len = ::recv(m_Socket, _context, 65535, 0);

	// recv �� �����ϸ� 0xffffffff�� ��ȯ��
	IF_FAILED(buffer_len)
	{
		return ADD_FLAG(HSDK_FAIL, WSAGetLastError());
	}
	
	// ��Ŷ�� ���� ��ȯ
	_size = buffer_len;

	return S_OK;

}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(TCPProxy, wait_Recv)(
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

	// �̺�Ʈ ��� �˻�
	WSAEnumNetworkEvents(m_Socket, m_Event, LPWSANETWORKEVENTS(&m_Events));

	// ���� ����
	IF_TRUE(IS_FLAG(m_Events.lNetworkEvents, FD_READ))
	{
		// �̺�Ʈ ��ȿ�� �˻� 
		IF_TRUE(hr = m_Events.iErrorCode[FD_READ_BIT])
		{
			return ADD_FLAG(HSDK_FAIL, hr);
		}

		// ��� ����
		return FD_READ_BIT;
	}

	// ����
	IF_TRUE(IS_FLAG(m_Events.lNetworkEvents, FD_CLOSE))
	{
		// �̺�Ʈ ��ȿ�� �˻� 
		IF_TRUE(hr = m_Events.iErrorCode[FD_CLOSE_BIT])
		{
			return ADD_FLAG(HSDK_FAIL, hr);
		}

		// ���� ���� �̺�Ʈ�� ȣ�� �Ǿ������� ������ ������ �� �̻� �ش� ������ ����� �� ���� ����
		return ADD_FLAG(HSDK_FAIL, FD_CLOSE_BIT);
	}

	return S_OK;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(TCPProxy, initailize)(
	_In_ unsigned int _ip,
	_In_ SOCKET _socket)
{
	// ���ϰ� �̺�Ʈ�� �����Ѵ�.
	IF_FAILED(WSAEventSelect(_socket, m_Event, FD_READ | FD_CLOSE))
	{
		return ADD_FLAG(HSDK_FAIL, WSAGetLastError());
	}

	// ip
	m_ip = _ip;

	// ������ ��ü�Ѵ�.
	SOCKET temp_socket = m_Socket;
	m_Socket = _socket;

	// ������ �����ִ� ������ �ݴ´�.
	closesocket(temp_socket);

	// ũ�� �� ����
	return S_OK;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(TCPProxy, SOCKET, get_Socket)(
	_X_ void)
{
	return m_Socket;
}
