#pragma once



#include "../../../hsdk_common.h"
#include <string>



namespace hsdk
{
	namespace i
	{
		namespace thread
		{

			// ���� : �񵿱� ���μ����� �߻�ȭ.
			DLL_DECL_INTERFACE(i_Thread)
			{
				
				// ���� �Ҹ���.
				CLASS_DECL_DESTRUCTOR(i_Thread)(void)
				{

				}

				// ���� : �񵿱� ���μ����� ����.
				INTERFACE_DECL_FUNC(start)(
					/* [x] */ void) = 0;

				// ���� : �񵿱� ���μ����� ����.
				INTERFACE_DECL_FUNC(kill)(
					/* [x] */ void) = 0;

				// ���� : thread�� ����Ǳ⸦ _time��ŭ ��ٸ�.
				INTERFACE_DECL_FUNC(wait)(
					_In_ unsigned int _time) = 0;

				// ���� : thread�� ������ ������ ��, thread�� �ʱ�ȭ.
				INTERFACE_DECL_FUNC(reset)(
					/* [x] */ void) = 0;

			};

		}
	}
}