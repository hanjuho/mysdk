#pragma once



#include "../../../hsdk_common.h"



namespace hsdk
{
	namespace win
	{
		namespace thread
		{

			// ���� : 
			DLL_DECL_INTERFACE(i_Task)
			{

				// ���� �Ҹ���.
				CLASS_DECL_DESTRUCTOR(i_Task)(void)
				{

				}

				// ���� : 
				INTERFACE_DECL_FUNC_T(void, func)(
					/* [x] */ void) = 0;

			};

		}
	}
}