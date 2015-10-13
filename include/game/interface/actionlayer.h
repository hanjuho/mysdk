#pragma once



#include "common.h"



namespace hsdk
{
	namespace game
	{
		namespace i
		{

			// ���� : 
			DLL_DECL_INTERFACE(i_ActionLayer)
			{

				// �Ҹ���.
				CLASS_DECL_DESTRUCTOR(i_ActionLayer)(void)
				{

				}

				// ���� : 
				INTERFACE_DECL_FUNC_T(void, initialize)(
					/* [x] */ void) = 0;

				// ���� : 
				INTERFACE_DECL_FUNC_T(bool, act)(
					/* [x] */ void)const = 0;

				// ���� :
				INTERFACE_DECL_FUNC_T(unsigned int, priority)(
					/* [x] */ void)const = 0;

			};

		}
	}
}