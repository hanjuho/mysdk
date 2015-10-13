#pragma once



#include "../../../hsdk_common.h"



namespace hsdk
{
	namespace i
	{
		namespace criticalsection
		{

			// ���� : �Ӱ豸�� event�� �߻�ȭ.
			DLL_DECL_INTERFACE(i_Section)
			{

				// ���� �Ҹ���.
				CLASS_DECL_DESTRUCTOR(i_Section)(void)
				{

				};

				// ���� : section�� ��, ������ ��� _time��ŭ ���.
				INTERFACE_DECL_FUNC(enter)(
					/* [r] */ unsigned long _time) = 0;

				// ���� : section�κ��� ����.
				INTERFACE_DECL_FUNC(leave)(
					/* [x] */ void) = 0;

				// ���� : section�� ������ ���� ���, section�� �ʱ�ȭ.
				INTERFACE_DECL_FUNC(reset)(
					/* [x] */ void) = 0;

			};

		}
	}
}