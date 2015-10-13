#pragma once



#include "../../../hsdk_common.h"
#include <string>



namespace hsdk
{
	namespace i
	{
		namespace network
		{

			// 설명 : network에서 송신을 수행하는 proxy를 추상화.
			DLL_DECL_INTERFACE(i_Proxy)
			{

				// 가상 소멸자.
				CLASS_DECL_DESTRUCTOR(i_Proxy)(void)
				{

				}

				// 설명 : _context를 _offset에서부터 _size만큼 전송.
				INTERFACE_DECL_FUNC(send)(
					/* [r] */ char * _context,
					/* [r] */ unsigned int _offset,
					/* [r] */ unsigned int _size) = 0;

				// 설명 : _size만큼의 _context를 수신.
				INTERFACE_DECL_FUNC(receive)(
					/* [w] */ char * (&_context),
					/* [w] */ unsigned int (&_size)) = 0;
				
				// 설명 : 리시브 신호를 대기.
				INTERFACE_DECL_FUNC(wait_Recv)(
					/* [r] */ unsigned int _time) = 0;

			};

		}
	}
}