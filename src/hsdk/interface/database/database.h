#pragma once



#include "../../../hsdk_common.h"



namespace hsdk
{
	namespace i
	{
		namespace database
		{

			// ���� : ������ �����ϴ� ��ü�� �߻�ȭ.
			DECL_INTERFACE(i_Database)
			{

				// ���� �Ҹ���.
				CLASS_DECL_DESTRUCTOR(i_Database)(void)
				{

				}

				//
				INTERFACE_DECL_FUNC(load)() = 0;

				//
				INTERFACE_DECL_FUNC(save)() = 0;

			};

		}
	}
}