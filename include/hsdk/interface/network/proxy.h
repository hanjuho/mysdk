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
					_In_ char * _context,
					_In_ unsigned int _offset,
					_In_ unsigned int _size) = 0;

				// ���� : _size��ŭ�� _context�� ����.
				INTERFACE_DECL_FUNC(receive)(
					_Out_ char * (&_context),
					_Out_ unsigned int (&_size)) = 0;
				
				// ���� : ���ú� ��ȣ�� ���.
				INTERFACE_DECL_FUNC(wait_Recv)(
					_In_ unsigned int _time) = 0;

			};

		}
	}
}