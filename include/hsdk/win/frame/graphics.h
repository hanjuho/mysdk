#pragma once



#include "../../interface/frame/graphics.h"
#include "direct3d/d3d10_master.h"
#include <string>


namespace hsdk
{
	namespace win
	{
		namespace frame
		{

			// ���� : ��ǥ����� �ð��� ��Ҹ� ������ �� �ִ� ��ü�� D3D11�� ����.
			DLL_DECL_CLASS(Graphics)
				: public i::frame::i_Graphics
			{
			public:

				// ������.
				CLASS_DECL_CONSTRUCTOR(Graphics)(void);

				// ���� �Ҹ���.
				CLASS_DECL_DESTRUCTOR(Graphics)(void);

				// ���� :
				INTERFACE_DECL_FUNC_T(void, set_Background)(
					/* [r] */ const float(&_color)[4]);

				// ���� : �̹����� ����.
				INTERFACE_DECL_FUNC_T(void, set_image)(
					/* [r] */ const wchar_t * _filename);

				/*
				���� : �̹����� �� ����.
				$ ���� : _clip(x, y, w, h)
				*/
				INTERFACE_DECL_FUNC_T(void, set_imageDetail)(
					/* [r] */ const float(&_clip)[4]);

				// ���� : ��Ʈ�� ����.
				INTERFACE_DECL_FUNC_T(void, set_Font)(
					/* [r] */ const wchar_t * _fontname,
					/* [r] */ unsigned int _fontsize);

				// ���� :
				INTERFACE_DECL_FUNC_T(void, set_FontColor)(
					/* [r] */ const float(&_color)[4]);

				// ���� : �ؽ�Ʈ�� ����.
				INTERFACE_DECL_FUNC_T(void, set_Text)(
					/* [r] */ const wchar_t * _text);

				/*
				���� : graphics�� ����.
				$ ���� : _rectangle(x, y, w, h)
				*/
				CLASS_DECL_FUNC_T(void, update)(
					/* [r] */ const float(&_rectangle)[4]);

				// ���� : graphics�� ȭ�鿡 �ѷ���.
				CLASS_DECL_FUNC_T(void, render)(
					/* [x] */ float _persent);

			private:

				// ���� : 
				D3DXMATRIX my_Position;

				// ���� :
				const D3DX10_IMAGE_INFO * my_Texture_info = nullptr;

				// ���� :
				ID3D10ShaderResourceView * my_Texture = nullptr;

				// ���� : 
				D3DXVECTOR4 my_BGColor = { 0.0f, 0.0f, 0.0f, 1.0f };

				// ���� :
				D3DXVECTOR4 my_Sprite = { 0.0f, 0.0f, 1.0f, 1.0f };

			};
		}
	}
}