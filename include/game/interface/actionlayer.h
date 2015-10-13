#pragma once



#include "common.h"



namespace hsdk
{
	namespace game
	{
		namespace i
		{

			// 설명 : 
			DLL_DECL_INTERFACE(i_ActionLayer)
			{

				// 소멸자.
				CLASS_DECL_DESTRUCTOR(i_ActionLayer)(void)
				{

				}

				// 설명 : 
				INTERFACE_DECL_FUNC_T(void, initialize)(
					/* [x] */ void) = 0;

				// 설명 : 
				INTERFACE_DECL_FUNC_T(bool, act)(
					/* [x] */ void)const = 0;

				// 설명 :
				INTERFACE_DECL_FUNC_T(unsigned int, priority)(
					/* [x] */ void)const = 0;

			};

		}
	}
}