#pragma once



#include "d3d10_common.h"



namespace hsdk
{
	namespace direct3d
	{

		// 설명 : 
		DLL_DECL_CLASS(D3D10_RenderTarget)
		{

		public:

			// 설명 : 
			CLASS_DECL_CONSTRUCTOR(D3D10_RenderTarget)(void);

			// 설명 : 
			CLASS_DECL_FUNC(initialize)(
				_In_ unsigned int _width,
				_In_ unsigned int _height);

			// 설명 : 
			CLASS_DECL_FUNC(begin)(
				_In_ const float * _color);
			
			// 설명 : 
			CLASS_DECL_FUNC_T(void, end)(
				_X_ void);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, viewport)(
				_X_ void);

			// 설명 : 
			CLASS_DECL_FUNC_T(ID3D10ShaderResourceView *, get_View)(
				_X_ void)const;

			// 설명 : 
			CLASS_DECL_FUNC_T(D3D10_TEXTURE2D_DESC, get_Desc)(
				_X_ void)const;

		private:

			// 설명 : 
			D3D10_VIEWPORT my_Vp;

			// 설명 : 
			D3D10_TEXTURE2D_DESC my_Desc;

			// 설명 : 
			AutoRelease<ID3D10Texture2D> my_texure2D;

			// 설명 : 
			AutoRelease<ID3D10DepthStencilView> my_DSV;

			// 설명 : 
			AutoRelease<ID3D10RenderTargetView> my_RTV;

			// 설명 : 
			AutoRelease<ID3D10ShaderResourceView> my_SRV;

		};

	}
}