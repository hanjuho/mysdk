#pragma once



#include "common.h"



namespace hsdk
{
	namespace i
	{
		namespace frame
		{

			// 설명 : action event를 받을 수 있는 인터페이스를 추상화
			DECL_INTERFACE(i_Actable)
			{

				// 가상 소멸자
				CLASS_DECL_DESTRUCTOR(i_Actable)(void)
				{

				}

				// 설명 : 
				INTERFACE_DECL_FUNC_T(void, onAct)(
					_X_ void) = 0;

			};

		}
	}
}