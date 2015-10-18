#pragma once



#include "component.h"



namespace hsdk
{
	namespace i
	{
		namespace frame
		{

			// 설명 : 좌표평면의 시각적 요소를 제어할 수 있는 객체를 추상화
			DLL_DECL_INTERFACE(i_Graphics)
			{

				// 가상 소멸자
				CLASS_DECL_DESTRUCTOR(i_Graphics)(void)
				{

				}

				// 설명 :
				INTERFACE_DECL_FUNC_T(void, set_Background)(
					/* [r] */ const float(&_color)[4]) = 0;

				// 설명 : 이미지를 설정.
				INTERFACE_DECL_FUNC_T(void, set_image)(
					/* [r] */ const wchar_t * _filename) = 0;

				/*
				설명 : 이미지를 상세 설정.
				참고 : _clip(x, y, w, h)
				*/
				INTERFACE_DECL_FUNC_T(void, set_imageDetail)(
					/* [r] */ const float(&_clip)[4]) = 0;

				// 설명 : 폰트를 설정.
				INTERFACE_DECL_FUNC_T(void, set_Font)(
					/* [r] */ const wchar_t * _fontname,
					/* [r] */ unsigned int _fontsize) = 0;

				// 설명 :
				INTERFACE_DECL_FUNC_T(void, set_FontColor)(
					/* [r] */ const float(&_color)[4]) = 0;

				// 설명 : 텍스트를 설정.
				INTERFACE_DECL_FUNC_T(void, set_Text)(
					/* [r] */ const wchar_t * _text) = 0;

			};

		}
	}
}