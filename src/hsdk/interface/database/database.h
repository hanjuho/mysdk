#pragma once



#include "../../../hsdk_common.h"



namespace hsdk
{
	namespace i
	{
		namespace database
		{

			// 설명 : 정보를 관리하는 객체를 추상화.
			DECL_INTERFACE(i_Database)
			{

				// 가상 소멸자.
				CLASS_DECL_DESTRUCTOR(i_Database)(void)
				{

				}

				//
				INTERFACE_DECL_FUNC(load)() = 0;

				//
				INTERFACE_DECL_FUNC(save)() = 0;

			};

		}
	}
}