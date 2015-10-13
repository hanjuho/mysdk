#pragma once



#include "../../../hsdk_common.h"



namespace hsdk
{
	namespace win
	{
		namespace thread
		{

			// 설명 : 
			DLL_DECL_INTERFACE(i_Task)
			{

				// 가상 소멸자.
				CLASS_DECL_DESTRUCTOR(i_Task)(void)
				{

				}

				// 설명 : 
				INTERFACE_DECL_FUNC_T(void, func)(
					/* [x] */ void) = 0;

			};

		}
	}
}