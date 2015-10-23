#pragma once



#include "component.h"



namespace hsdk
{
	namespace i
	{
		namespace frame
		{

			// ���� : �Է� �̺�Ʈ ���� �����ڸ� �߻�ȭ
			DLL_DECL_INTERFACE(i_inputEventHelper)
			{

				// ���� �Ҹ���
				CLASS_DECL_DESTRUCTOR(i_inputEventHelper)(void)
				{

				}

				// ���� : component�� event �߻� ������ �����ϴ��� �˻�
				INTERFACE_DECL_FUNC_T(bool, chain)(
					_In_ const i_Component * _component) = 0;
				
				// ���� : input event focus ����� ����
				INTERFACE_DECL_FUNC_T(void, update)(
					/* [x] */ void) = 0;

			};

		}
	}
}