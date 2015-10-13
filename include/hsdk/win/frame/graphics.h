#pragma once



#include "../../interface/frame/graphics.h"
#include "direct3d/d3d10_manager.h"
#include <string>


namespace hsdk
{
	namespace win
	{
		namespace frame
		{
			
			// ���� : 
			DECL_STRUCT(D3D10_SCREEN_VERTEX)
			{

				// ���� : 
				float x, y, z;

				// ���� : 
				D3DCOLORVALUE color;

				// ���� : 
				float tu, tv;

			};

			// ���� : ��ǥ����� �ð��� ��Ҹ� ������ �� �ִ� ��ü�� D3D11�� ����.
			DECL_CLASS(Graphics)
				: public i::frame::i_Graphics
			{

			public:

				// ���� :
				CLASS_DECL_OPEN_FUNC(initialize)(
					/* [r] */ direct3d::D3D10_Manager & _manager);

				// ���� :
				CLASS_DECL_OPEN_FUNC_T(void, destroy)(
					/* [x] */ void);

			public:

				// ������.
				CLASS_DECL_CONSTRUCTOR(Graphics)(void);

				// ���� �Ҹ���.
				CLASS_DECL_DESTRUCTOR(Graphics)(void);

				// ���� : �̹����� ����.
				INTERFACE_DECL_FUNC_T(void, set_image)(
					/* [r] */ const wchar_t * _filename);

				/*
				���� : �̹����� �� ����.
				$ ���� : _rectangle(x, y, w, h)
				*/
				INTERFACE_DECL_FUNC_T(void, set_imageDetail)(
					/* [r] */ float _imageW,
					/* [r] */ float _imageH,
					/* [r] */ const float(&_rectangle)[4]);

				// ���� : ��Ʈ�� ����.
				INTERFACE_DECL_FUNC_T(void, set_Font)(
					/* [r] */ const wchar_t * _fontname,
					/* [r] */ unsigned int _fontsize);

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
					/* [x] */ void);

			private:

				// ���� :
				AutoRelease<ID3D10Buffer> my_Panel;

				// ���� :
				ID3D10ShaderResourceView * my_refCustom;

				// ���� :
				ID3D10SamplerState * my_refSampler;

				// ���� :
				float m_imageW;

				// ���� :
				float m_imageH;

				/*
				���� :
				$ ���� : uvRectangle(x, y, w, h)
				*/
				float m_uvRectangle[4];

				// ���� :
				std::wstring m_Text;

			};
		}
	}
}