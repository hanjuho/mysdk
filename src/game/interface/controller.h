#pragma once



#include "common.h"
#include "actiontable.h"



namespace hsdk
{
	namespace game
	{
		namespace i
		{

			// ���� : 
			DECL_INTERFACE(i_Controller)
				: public i_ActionTable<void>
			{

				// �Ҹ���.
				CLASS_DECL_DESTRUCTOR(i_Controller)(void)
				{

				}
				
			};

		}
	}
}