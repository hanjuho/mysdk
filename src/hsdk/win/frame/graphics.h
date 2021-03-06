#pragma once



#include "../../interface/frame/graphics.h"
#include "../direct3d/d3d10_common.h"
#include <string>


namespace hsdk
{
	namespace frame
	{

		// 설명 : 좌표평면의 시각적 요소를 제어할 수 있는 객체를 D3D11로 구현.
		DECL_CLASS(Graphics)
			: public i::frame::i_Graphics
		{
		public:

			// 설명 :
			INTERFACE_DECL_FUNC_T(void, set_Background)(
				_In_ const float(&_color)[4]);

			// 설명 : 이미지를 설정.
			INTERFACE_DECL_FUNC_T(void, set_image)(
				_In_ const wchar_t * _filename);

			/*
			설명 : 이미지를 상세 설정.
			$ 참고 : _clip(x, y, w, h)
			*/
			INTERFACE_DECL_FUNC_T(void, set_imageDetail)(
				_In_ const float(&_clip)[4]);

			// 설명 : 폰트를 설정.
			INTERFACE_DECL_FUNC_T(void, set_Font)(
				_In_ const wchar_t * _fontname,
				_In_ unsigned int _fontsize);

			// 설명 :
			INTERFACE_DECL_FUNC_T(void, set_FontColor)(
				_In_ const float(&_color)[4]);

			// 설명 : 텍스트를 설정.
			INTERFACE_DECL_FUNC_T(void, set_Text)(
				_In_ const wchar_t * _text);

		public:
						
			// 설명 : 
			D3DXVECTOR4 bgColor = {
				0.0f, 0.0f, 0.0f, 1.0f };
			
			// 설명 :
			float imageW = 0.0f;

			// 설명 :
			float imageH = 0.0f;

			// 설명 :
			D3DXMATRIX mTexcoord = {
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f };

			// 설명 :
			ID3D10ShaderResourceView * refTexture = nullptr;

		};
	}
}