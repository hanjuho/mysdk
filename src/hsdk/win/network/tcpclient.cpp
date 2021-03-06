#include "tcpclient.h"



using namespace hsdk::network;


//--------------------------------------------------------------------------------------
CLASS_IMPL_CONSTRUCTOR(TCPClient, TCPClient)(void)
: m_Url(""), m_Port(0)
{

}

//--------------------------------------------------------------------------------------
CLASS_IMPL_DESTRUCTOR(TCPClient, TCPClient)(void)
{

}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(TCPClient, connect)(
	_In_ const char * _url,
	_In_ unsigned int _port,
	_In_ unsigned int _wait)
{
	SOCKET new_socket;

	// 서버와 통신 준비를 위해 소켓을 생성
	IF_FAILED(new_socket = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, nullptr, 0, 0))
	{
		return ADD_FLAG(HSDK_FAIL, WSAGetLastError());
	}

	// 서버의 주소와 포트
	sockaddr_in server;
	server.sin_family = AF_INET;
	IF_FAILED(inet_pton(AF_INET, _url, &server.sin_addr))
	{
		return ADD_FLAG(HSDK_FAIL, WSAGetLastError());
	}

	server.sin_port = htons(USHORT(_port));
	HRESULT hr;

	// 서버와 연결을 시도
	IF_FAILED(::connect(new_socket, (SOCKADDR *)&server, sizeof(server)))
	{
		// ::connect의 에러 원인 유지
		hr = ADD_FLAG(HSDK_FAIL, WSAGetLastError());
		closesocket(new_socket);

		return hr;
	}
	
	// 대리자 초기화
	IF_FAILED(hr = m_Proxy.initailize(htonl(INADDR_ANY), new_socket))
	{
		return hr;
	}
	
	m_Url = _url;
	m_Port = _port;

	return S_OK;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(TCPClient, disconnect)(
	_X_ void)
{
	try
	{
		// none 소켓 초기화
		m_Proxy.~TCPProxy();
	}
	catch (long hr)
	{
		return hr;
	}

	return S_OK;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(TCPClient, send)(
	_In_ char * _context,
	_In_ unsigned int _offset,
	_In_ unsigned int _size)
{
	return m_Proxy.send(_context, _offset, _size);
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(TCPClient, receive)(
	_Out_ char * (&_context),
	_Out_ unsigned int(&_size))
{
	return m_Proxy.receive(_context, _size);
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(TCPClient, wait_Recv)(
	_In_ unsigned int _time)
{
	return m_Proxy.wait_Recv(_time);
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(TCPClient, reset)(
	_X_ void)
{
	return disconnect() | connect(m_Url, m_Port, 1000);
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(TCPClient, SOCKET, get_Socket)(
	_X_ void)
{
	return m_Proxy.get_Socket();
}