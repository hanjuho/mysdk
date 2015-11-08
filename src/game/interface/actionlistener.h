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
			DECL_INTERFACE(i_ActionListener)
			{

				// �Ҹ���.
				CLASS_DECL_DESTRUCTOR(i_ActionListener)(void)
				{

				}

				// ���� :
				INTERFACE_DECL_FUNC_T(void, listen_Action)(
					_Ref_ i_ActionLayer * _actionlayer) = 0;

			};

		}
	}
}