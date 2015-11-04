#pragma once



#include "common.h"



namespace hsdk
{
	namespace i
	{
		namespace frame
		{

			// ���� : keyboard event�� ���� �� �ִ� �������̽��� �߻�ȭ.
			DECL_INTERFACE(i_Keyboardable)
			{

				// ���� �Ҹ���
				CLASS_DECL_DESTRUCTOR(i_Keyboardable)(void)
				{

				}

				// ���� : keyboard�� ��ư�� ������ �� �߻��ϴ� event.
				INTERFACE_DECL_FUNC_T(void, onKey_Down)(
					_In_ unsigned char _vKey) = 0;

				// ���� : keyboard�� ��ư�� �����ٰ� ���� �߻��ϴ� event.
				INTERFACE_DECL_FUNC_T(void, onKey_Up)(
					_In_ unsigned char _vKey) = 0;

			};

		}
	}
}