#pragma once



#include "common.h"
#include "../autodelete.h"



namespace hsdk
{
	namespace framework
	{
		
		// 설명 : 
		DECL_STRUCT(Framework_Device)
		{

			//--------------------------------------------------------------------------------------
			// 
			//--------------------------------------------------------------------------------------

			// 설명 : 
			AutoRelease<IDirect3D9> d3d9;

			// 설명 :
			AutoRelease<IDirect3DDevice9> d3d9Device;

			// 설명 :
			AutoRelease<ID3DXSprite> d3d9Sprite;

			// 설명 : 
			D3DSURFACE_DESC backBuffer_Desc;

			//--------------------------------------------------------------------------------------
			// 
			//--------------------------------------------------------------------------------------

			// 설명 : 
			AutoRelease<IDXGIFactory> dxgiFactory;

			// 설명 : 
			AutoRelease<IDXGISwapChain> dxgiSwapChain;

			// 설명 :
			AutoRelease<ID3D10Texture2D> dxgiBackBuffer;

			// 설명 :
			DXGI_SURFACE_DESC dxgiBackBuffer_Desc;

			// 설명 :
			AutoRelease<ID3D10Device1> d3d10Device1;

			// 설명 :
			AutoRelease<ID3D10Device> d3d10Device;

			// 설명 : 
			AutoRelease<ID3DX10Sprite>  d3d10Sprite;

			// 설명 :
			AutoRelease<ID3D10DepthStencilView> d3d10DSV;

			// 설명 :
			AutoRelease<ID3D10RenderTargetView> d3d10RTV;

			// 설명 :
			AutoRelease<ID3D10Texture2D> d3d10DepthStencil;

			// 설명 :
			AutoRelease<ID3D10RasterizerState> d3d10DefaultRasterizerState;

		};

		// 설명 : 
		DLL_DECL_CLASS(Framework_DeviceFactory)
		{

		public:

			//--------------------------------------------------------------------------------------
			// 
			//--------------------------------------------------------------------------------------

			// 설명 : 
			INTERFACE_DECL_FUNC(create9)(
				_Out_ Framework_Device & _device,
				_In_ const D3D9_DEVICE_DESC & _desc,
				_In_ const Framework_Callbacks * _callback = nullptr);

			// 설명 : 
			INTERFACE_DECL_FUNC(reset9)(
				_Out_ Framework_Device & _device,
				_In_ const D3D9_DEVICE_DESC & _desc,
				_In_ const Framework_Callbacks * _callback = nullptr);

			// 설명 : 
			INTERFACE_DECL_FUNC(restore9)(
				_Out_ Framework_Device & _device,
				_In_ const D3D9_DEVICE_DESC & _pp,
				_In_ const Framework_Callbacks * _callback = nullptr);

			//--------------------------------------------------------------------------------------
			//
			//--------------------------------------------------------------------------------------

			// 설명 : 
			INTERFACE_DECL_FUNC(create10)(
				_Out_ Framework_Device & _device,
				_In_ const D3D10_DEVICE_DESC & _desc,
				_In_ const Framework_Callbacks * _callback = nullptr,
				_In_ BOOL _createRenderTarget = TRUE);

			// 설명 : 
			INTERFACE_DECL_FUNC(resize10)(
				_Out_ Framework_Device & _device,
				_In_ const D3D10_DEVICE_DESC & _desc,
				_In_ const Framework_Callbacks * _callback = nullptr);

			// 설명 : 
			INTERFACE_DECL_FUNC(reset10)(
				_Out_ Framework_Device & _device,
				_In_ const D3D10_DEVICE_DESC & _desc,
				_In_ const Framework_Callbacks * _callback = nullptr,
				_In_ BOOL _resetAll = false);

			// 설명 : 
			INTERFACE_DECL_FUNC(setup_RenderTarget)(
				_Out_ Framework_Device & _device,
				_In_ const D3D10_DEVICE_DESC & _desc);

		};

	}
}