#pragma once



#include "proxy.h"



namespace hsdk
{
	namespace i
	{
		namespace network
		{
			
			// ���� : network���� client�� ����ȭ�ϴ� server�� �߻�ȭ.
			DECL_INTERFACE(i_Server)
			{

				// ���� �Ҹ���.
				CLASS_DECL_DESTRUCTOR(i_Server)(void)
				{

				}

				// ���� : Ư�� ��Ʈ�� Ŭ���̾�Ʈ�� ����� ����Ʈ�� ����.
				INTERFACE_DECL_FUNC(open)(
					_In_ unsigned int _port) = 0;

				// ���� : ���� ��Ʈ�� ����.
				INTERFACE_DECL_FUNC(close)(
					_In_ void) = 0;

				// ���� : server���� ������ client�� _time��ŭ ���.
				INTERFACE_DECL_FUNC(accept)(
					_Out_ i_Proxy * (&_proxy),
					_In_ unsigned int _time) = 0;

				// ���� : server�� ������ ������ ��, server�� �ʱ�ȭ.
				INTERFACE_DECL_FUNC(reset)(
					_X_ void) = 0;

			};

		}
	}
}