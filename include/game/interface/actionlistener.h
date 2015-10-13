#pragma once



#include "common.h"
#include "actionlayer.h"



namespace hsdk
{
	namespace game
	{
		namespace i
		{

			// 설명 : 
			DLL_DECL_INTERFACE(i_ActionListener)
			{

				// 소멸자.
				CLASS_DECL_DESTRUCTOR(i_ActionListener)(void)
				{

				}

				// 설명 :
				INTERFACE_DECL_FUNC_T(void, listen_Action)(
					/* [ref] */ i_ActionLayer * _actionlayer) = 0;

			};

		}
	}
}