#pragma once



#include "common.h"
#include "actiontable.h"



namespace hsdk
{
	namespace game
	{
		namespace i
		{

			// 설명 : 
			DECL_INTERFACE(i_Controller)
				: public i_ActionTable<void>
			{

				// 소멸자.
				CLASS_DECL_DESTRUCTOR(i_Controller)(void)
				{

				}
				
			};

		}
	}
}