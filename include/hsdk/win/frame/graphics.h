#pragma once



#include "../../interface/frame/graphics.h"
#include "../direct3d/d3d10_common.h"
#include <string>


namespace hsdk
{
	namespace frame
	{

		// ���� : ��ǥ����� �ð��� ��Ҹ� ������ �� �ִ� ��ü�� D3D11�� ����.
		DLL_DECL_CLASS(Graphics)
			: public i::frame::i_Graphics
		{
		public:

			// ���� :
			INTERFACE_DECL_FUNC_T(void, set_Background)(
				_In_ const float(&_color)[4]);

			// ���� : �̹����� ����.
			INTERFACE_DECL_FUNC_T(void, set_image)(
				_In_ const wchar_t * _filename);

			/*
			���� : �̹����� �� ����.
			$ ���� : _clip(x, y, w, h)
			*/
			INTERFACE_DECL_FUNC_T(void, set_imageDetail)(
				_In_ const float(&_clip)[4]);

			// ���� : ��Ʈ�� ����.
			INTERFACE_DECL_FUNC_T(void, set_Font)(
				_In_ const wchar_t * _fontname,
				_In_ unsigned int _fontsize);

			// ���� :
			INTERFACE_DECL_FUNC_T(void, set_FontColor)(
				_In_ const float(&_color)[4]);

			// ���� : �ؽ�Ʈ�� ����.
			INTERFACE_DECL_FUNC_T(void, set_Text)(
				_In_ const wchar_t * _text);

		public:
						
			// ���� : 
			D3DXVECTOR4 bgColor = {
				0.0f, 0.0f, 0.0f, 1.0f };

			// ���� :
			ID3D10ShaderResourceView * texture = nullptr;

			// ���� :
			float imageW = 0.0f;

			// ���� :
			float imageH = 0.0f;

			// ���� :
			D3DXMATRIX mTexcoord = {
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f };

		};
	}
}