#pragma once



#include "proxy.h"



namespace hsdk
{
	namespace i
	{
		namespace network
		{
			
			// ���� : network���� client�� ����ȭ�ϴ� server�� �߻�ȭ.
			DLL_DECL_INTERFACE(i_Server)
			{

				// ���� �Ҹ���.
				CLASS_DECL_DESTRUCTOR(i_Server)(void)
				{

				}

				// ���� : Ư�� ��Ʈ�� Ŭ���̾�Ʈ�� ����� ����Ʈ�� ����.
				INTERFACE_DECL_FUNC(open)(
					/* [r] */ unsigned int _port) = 0;

				// ���� : ���� ��Ʈ�� ����.
				INTERFACE_DECL_FUNC(close)(
					/* [r] */ void) = 0;

				// ���� : server���� ������ client�� _time��ŭ ���.
				INTERFACE_DECL_FUNC(accept)(
					/* [w] */ i_Proxy * (&_proxy),
					/* [r] */ unsigned int _time) = 0;

				// ���� : server�� ������ ������ ��, server�� �ʱ�ȭ.
				INTERFACE_DECL_FUNC(reset)(
					/* [x] */ void) = 0;

			};

		}
	}
}