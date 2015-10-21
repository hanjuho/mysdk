#pragma once



#include "../../../hsdk_common.h"



namespace hsdk
{
	namespace i
	{
		namespace frame
		{
						
			DECL_STRUCT(i_Component);
			DECL_STRUCT(i_Container);
			DECL_STRUCT(i_Graphics);
			DECL_STRUCT(i_inputEventHelper);
			DECL_STRUCT(i_Mouseable);
			DECL_STRUCT(i_Keyboardable);
			DECL_STRUCT(i_Actable);

			// 설명 : 눌린 마우스 버튼의 종류
			enum MOUSE_BUTTON
			{
				LBUTTON, RBUTTON, WBUTTON, NONE
			};

		}
	}
}