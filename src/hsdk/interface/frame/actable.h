#pragma once



#include "common.h"



namespace hsdk
{
	namespace i
	{
		namespace frame
		{

			// ���� : action event�� ���� �� �ִ� �������̽��� �߻�ȭ
			DECL_INTERFACE(i_Actable)
			{

				// ���� �Ҹ���
				CLASS_DECL_DESTRUCTOR(i_Actable)(void)
				{

				}

				// ���� : 
				INTERFACE_DECL_FUNC_T(void, onAct)(
					_X_ void) = 0;

			};

		}
	}
}