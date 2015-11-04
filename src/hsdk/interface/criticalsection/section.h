#pragma once



#include "../../../hsdk_common.h"



namespace hsdk
{
	namespace i
	{
		namespace criticalsection
		{

			// ���� : �Ӱ豸�� event�� �߻�ȭ.
			DECL_INTERFACE(i_Section)
			{

				// ���� �Ҹ���.
				CLASS_DECL_DESTRUCTOR(i_Section)(void)
				{

				};

				// ���� : section�� ��, ������ ��� _time��ŭ ���.
				INTERFACE_DECL_FUNC(enter)(
					_In_ unsigned long _time) = 0;

				// ���� : section�κ��� ����.
				INTERFACE_DECL_FUNC(leave)(
					_X_ void) = 0;

				// ���� : section�� ������ ���� ���, section�� �ʱ�ȭ.
				INTERFACE_DECL_FUNC(reset)(
					_X_ void) = 0;

			};

		}
	}
}