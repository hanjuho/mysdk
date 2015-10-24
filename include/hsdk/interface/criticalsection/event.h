#pragma once



#include "../../../hsdk_common.h"



namespace hsdk
{
	namespace i
	{
		namespace criticalsection
		{

			// ���� : �Ӱ豸�� event�� �߻�ȭ.
			DLL_DECL_INTERFACE(i_Event)
			{

				// ���� �Ҹ���.
				CLASS_DECL_DESTRUCTOR(i_Event)(void)
				{

				};

				// ���� : thread�� ��� ���·κ��� ���.
				INTERFACE_DECL_FUNC(signal)(
					_X_ void) = 0;

				// ���� : thread�� signal ���¸� _time��ŭ ���.
				INTERFACE_DECL_FUNC(wait)(
					_In_ unsigned long _time) = 0;

				// ���� : event�� ������ ���� ���, event�� �ʱ�ȭ.
				INTERFACE_DECL_FUNC(reset)(
					_X_ void) = 0;

			};

		}
	}
}