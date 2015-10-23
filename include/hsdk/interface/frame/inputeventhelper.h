#pragma once



#include "component.h"



namespace hsdk
{
	namespace i
	{
		namespace frame
		{

			// 설명 : 입력 이벤트 전달 보조자를 추상화
			DLL_DECL_INTERFACE(i_inputEventHelper)
			{

				// 가상 소멸자
				CLASS_DECL_DESTRUCTOR(i_inputEventHelper)(void)
				{

				}

				// 설명 : component가 event 발생 조건을 충족하는지 검사
				INTERFACE_DECL_FUNC_T(bool, chain)(
					_In_ const i_Component * _component) = 0;
				
				// 설명 : input event focus 대상을 갱신
				INTERFACE_DECL_FUNC_T(void, update)(
					/* [x] */ void) = 0;

			};

		}
	}
}