#pragma once



#include "proxy.h"



namespace hsdk
{
	namespace i
	{
		namespace network
		{

			// ���� : network���� ������ �۽��ϴ� client�� �߻�ȭ.
			DLL_DECL_INTERFACE(i_Client)
				: public i_Proxy
			{

				// ���� �Ҹ���.
				CLASS_DECL_DESTRUCTOR(i_Client)(void)
				{

				}

				// ������ Ư�� ��Ʈ�� ����
				INTERFACE_DECL_FUNC(connect)(
					/* [r] */ const char * _url,
					/* [r] */ unsigned int _port,
					/* [r] */ unsigned int _wait = 0) = 0;

				// ������ ����
				INTERFACE_DECL_FUNC(disconnect)(
					/* [x] */ void) = 0;

				// ���� : client���� ������ ������ ��, client�� �ʱ�ȭ.
				INTERFACE_DECL_FUNC(reset)(
					/* [x] */ void) = 0;

			};

		}
	}
}