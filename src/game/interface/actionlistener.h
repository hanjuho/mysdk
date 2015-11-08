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
			DECL_INTERFACE(i_ActionListener)
			{

				// 소멸자.
				CLASS_DECL_DESTRUCTOR(i_ActionListener)(void)
				{

				}

				// 설명 :
				INTERFACE_DECL_FUNC_T(void, listen_Action)(
					_Ref_ i_ActionLayer * _actionlayer) = 0;

			};

		}
	}
}