#pragma once



#include "../../../hsdk_common.h"
#include <string>



namespace hsdk
{
	namespace i
	{
		namespace network
		{

			// ���� : network���� �۽��� �����ϴ� proxy�� �߻�ȭ.
			DLL_DECL_INTERFACE(i_Proxy)
			{

				// ���� �Ҹ���.
				CLASS_DECL_DESTRUCTOR(i_Proxy)(void)
				{

				}

				// ���� : _context�� _offset�������� _size��ŭ ����.
				INTERFACE_DECL_FUNC(send)(
					/* [r] */ char * _context,
					/* [r] */ unsigned int _offset,
					/* [r] */ unsigned int _size) = 0;

				// ���� : _size��ŭ�� _context�� ����.
				INTERFACE_DECL_FUNC(receive)(
					/* [w] */ char * (&_context),
					/* [w] */ unsigned int (&_size)) = 0;
				
				// ���� : ���ú� ��ȣ�� ���.
				INTERFACE_DECL_FUNC(wait_Recv)(
					/* [r] */ unsigned int _time) = 0;

			};

		}
	}
}