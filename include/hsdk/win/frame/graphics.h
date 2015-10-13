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
			
			// 설명 : 
			DECL_STRUCT(D3D10_SCREEN_VERTEX)
			{

				// 설명 : 
				float x, y, z;

				// 설명 : 
				D3DCOLORVALUE color;

				// 설명 : 
				float tu, tv;

			};

			// 설명 : 좌표평면의 시각적 요소를 제어할 수 있는 객체를 D3D11로 구현.
			DECL_CLASS(Graphics)
				: public i::frame::i_Graphics
			{

			public:

				// 설명 :
				CLASS_DECL_OPEN_FUNC(initialize)(
					/* [r] */ direct3d::D3D10_Manager & _manager);

				// 설명 :
				CLASS_DECL_OPEN_FUNC_T(void, destroy)(
					/* [x] */ void);

			public:

				// 생성자.
				CLASS_DECL_CONSTRUCTOR(Graphics)(void);

				// 가상 소멸자.
				CLASS_DECL_DESTRUCTOR(Graphics)(void);

				// 설명 : 이미지를 설정.
				INTERFACE_DECL_FUNC_T(void, set_image)(
					/* [r] */ const wchar_t * _filename);

				/*
				설명 : 이미지를 상세 설정.
				$ 참고 : _rectangle(x, y, w, h)
				*/
				INTERFACE_DECL_FUNC_T(void, set_imageDetail)(
					/* [r] */ float _imageW,
					/* [r] */ float _imageH,
					/* [r] */ const float(&_rectangle)[4]);

				// 설명 : 폰트를 설정.
				INTERFACE_DECL_FUNC_T(void, set_Font)(
					/* [r] */ const wchar_t * _fontname,
					/* [r] */ unsigned int _fontsize);

				// 설명 : 텍스트를 설정.
				INTERFACE_DECL_FUNC_T(void, set_Text)(
					/* [r] */ const wchar_t * _text);

				/*
				설명 : graphics를 갱신.
				$ 참고 : _rectangle(x, y, w, h)
				*/
				CLASS_DECL_FUNC_T(void, update)(
					/* [r] */ const float(&_rectangle)[4]);

				// 설명 : graphics를 화면에 뿌려줌.
				CLASS_DECL_FUNC_T(void, render)(
					/* [x] */ void);

			private:

				// 설명 :
				AutoRelease<ID3D10Buffer> my_Panel;

				// 설명 :
				ID3D10ShaderResourceView * my_refCustom;

				// 설명 :
				ID3D10SamplerState * my_refSampler;

				// 설명 :
				float m_imageW;

				// 설명 :
				float m_imageH;

				/*
				설명 :
				$ 참고 : uvRectangle(x, y, w, h)
				*/
				float m_uvRectangle[4];

				// 설명 :
				std::wstring m_Text;

			};
		}
	}
}