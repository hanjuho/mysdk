#pragma once



#include "../../interface/frame/graphics.h"
#include "../direct3d/d3d10_factory.h"
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

			// ������.
			CLASS_DECL_CONSTRUCTOR(Graphics)(void);

			// ���� �Ҹ���.
			CLASS_DECL_DESTRUCTOR(Graphics)(void);

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

			/*
			���� : graphics�� ����.
			$ ���� : _rectangle(x, y, w, h)
			*/
			CLASS_DECL_FUNC_T(void, update)(
				_In_ const float(&_rectangle)[4]);

			// ���� : graphics�� ȭ�鿡 �ѷ���.
			CLASS_DECL_FUNC_T(void, render)(
				_X_ float _persent);

		private:

			// ���� :
			ID3D10ShaderResourceView * my_Texture = nullptr;

			// ���� :
			const D3DX10_IMAGE_INFO * my_Texture_info = nullptr;

			// ���� : 
			D3DXVECTOR4 my_BGColor = {
				0.0f, 0.0f, 0.0f, 1.0f };

			// ���� : 
			D3DXMATRIX my_Position = {
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f };

			// ���� :
			D3DXMATRIX my_Texcoord = {
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f };

		};
	}
}