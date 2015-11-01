#pragma once



#include "d3d10_common.h"



namespace hsdk
{
	namespace direct3d
	{

		// ���� : 
		DLL_DECL_CLASS(D3D10_RenderTarget)
		{

		public:

			// ���� : 
			CLASS_DECL_CONSTRUCTOR(D3D10_RenderTarget)(void);

			// ���� : 
			CLASS_DECL_FUNC(initialize)(
				_In_ unsigned int _width,
				_In_ unsigned int _height);

			// ���� : 
			CLASS_DECL_FUNC(begin)(
				_In_ const float * _color);
			
			// ���� : 
			CLASS_DECL_FUNC_T(void, end)(
				_X_ void);

			// ���� : 
			CLASS_DECL_FUNC_T(void, viewport)(
				_X_ void);

			// ���� : 
			CLASS_DECL_FUNC_T(ID3D10ShaderResourceView *, get_View)(
				_X_ void)const;

			// ���� : 
			CLASS_DECL_FUNC_T(D3D10_TEXTURE2D_DESC, get_Desc)(
				_X_ void)const;

		private:

			// ���� : 
			D3D10_VIEWPORT my_Vp;

			// ���� : 
			D3D10_TEXTURE2D_DESC my_Desc;

			// ���� : 
			AutoRelease<ID3D10Texture2D> my_texure2D;

			// ���� : 
			AutoRelease<ID3D10DepthStencilView> my_DSV;

			// ���� : 
			AutoRelease<ID3D10RenderTargetView> my_RTV;

			// ���� : 
			AutoRelease<ID3D10ShaderResourceView> my_SRV;

		};

	}
}