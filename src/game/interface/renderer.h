#pragma once



#include "common.h"



namespace hsdk
{
	namespace game
	{
		namespace i
		{

			// ���� : 
			DECL_INTERFACE(i_Renderer)
			{

				// �Ҹ���.
				CLASS_DECL_DESTRUCTOR(i_Renderer)(void)
				{

				}

				// ���� : 
				INTERFACE_DECL_FUNC_T(void, initialize)(
					_X_ void) = 0;

				// ���� : 
				INTERFACE_DECL_FUNC_T(void, update)(
					_X_ void) = 0;
					
				// ���� : 
				INTERFACE_DECL_FUNC_T(void, render)(
					_X_ void) = 0;

			};

		}
	}
}