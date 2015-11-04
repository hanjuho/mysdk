#pragma once



#include "common.h"



namespace hsdk
{
	namespace game
	{
		namespace i
		{

			// ���� : 
			DECL_INTERFACE(i_ActionLayer)
			{

				// �Ҹ���.
				CLASS_DECL_DESTRUCTOR(i_ActionLayer)(void)
				{

				}

				// ���� : 
				INTERFACE_DECL_FUNC_T(void, initialize)(
					_X_ void) = 0;

				// ���� : 
				INTERFACE_DECL_FUNC_T(bool, act)(
					_X_ void)const = 0;

				// ���� :
				INTERFACE_DECL_FUNC_T(unsigned int, priority)(
					_X_ void)const = 0;

			};

		}
	}
}