#pragma once



#include "common.h"
#include "actionlayer.h"



namespace hsdk
{
	namespace game
	{
		namespace i
		{

			// ���� : 
			DLL_DECL_INTERFACE(i_ActionListener)
			{

				// �Ҹ���.
				CLASS_DECL_DESTRUCTOR(i_ActionListener)(void)
				{

				}

				// ���� :
				INTERFACE_DECL_FUNC_T(void, listen_Action)(
					/* [ref] */ i_ActionLayer * _actionlayer) = 0;

			};

		}
	}
}