#pragma once



#include "common.h"
#include "../autodelete.h"



namespace hsdk
{
	namespace framework
	{
		
		// ���� : 
		DECL_STRUCT(Framework_Device)
		{

			//--------------------------------------------------------------------------------------
			// 
			//--------------------------------------------------------------------------------------

			// ���� : 
			AutoRelease<IDirect3D9> d3d9;

			// ���� :
			AutoRelease<IDirect3DDevice9> d3d9Device;

			// ���� :
			AutoRelease<ID3DXSprite> d3d9Sprite;

			// ���� : 
			D3DSURFACE_DESC backBuffer_Desc;

			//--------------------------------------------------------------------------------------
			// 
			//--------------------------------------------------------------------------------------

			// ���� : 
			AutoRelease<IDXGIFactory> dxgiFactory;

			// ���� : 
			AutoRelease<IDXGISwapChain> dxgiSwapChain;

			// ���� :
			AutoRelease<ID3D10Texture2D> dxgiBackBuffer;

			// ���� :
			DXGI_SURFACE_DESC dxgiBackBuffer_Desc;

			// ���� :
			AutoRelease<ID3D10Device1> d3d10Device1;

			// ���� :
			AutoRelease<ID3D10Device> d3d10Device;

			// ���� : 
			AutoRelease<ID3DX10Sprite>  d3d10Sprite;

			// ���� :
			AutoRelease<ID3D10DepthStencilView> d3d10DSV;

			// ���� :
			AutoRelease<ID3D10RenderTargetView> d3d10RTV;

			// ���� :
			AutoRelease<ID3D10Texture2D> d3d10DepthStencil;

			// ���� :
			AutoRelease<ID3D10RasterizerState> d3d10DefaultRasterizerState;

		};

		// ���� : 
		DLL_DECL_CLASS(Framework_DeviceFactory)
		{

		public:

			//--------------------------------------------------------------------------------------
			// 
			//--------------------------------------------------------------------------------------

			// ���� : 
			INTERFACE_DECL_FUNC(create9)(
				_Out_ Framework_Device & _device,
				_In_ const D3D9_DEVICE_DESC & _desc,
				_In_ const Framework_Callbacks * _callback = nullptr);

			// ���� : 
			INTERFACE_DECL_FUNC(reset9)(
				_Out_ Framework_Device & _device,
				_In_ const D3D9_DEVICE_DESC & _desc,
				_In_ const Framework_Callbacks * _callback = nullptr);

			// ���� : 
			INTERFACE_DECL_FUNC(restore9)(
				_Out_ Framework_Device & _device,
				_In_ const D3D9_DEVICE_DESC & _pp,
				_In_ const Framework_Callbacks * _callback = nullptr);

			//--------------------------------------------------------------------------------------
			//
			//--------------------------------------------------------------------------------------

			// ���� : 
			INTERFACE_DECL_FUNC(create10)(
				_Out_ Framework_Device & _device,
				_In_ const D3D10_DEVICE_DESC & _desc,
				_In_ const Framework_Callbacks * _callback = nullptr,
				_In_ BOOL _createRenderTarget = TRUE);

			// ���� : 
			INTERFACE_DECL_FUNC(resize10)(
				_Out_ Framework_Device & _device,
				_In_ const D3D10_DEVICE_DESC & _desc,
				_In_ const Framework_Callbacks * _callback = nullptr);

			// ���� : 
			INTERFACE_DECL_FUNC(reset10)(
				_Out_ Framework_Device & _device,
				_In_ const D3D10_DEVICE_DESC & _desc,
				_In_ const Framework_Callbacks * _callback = nullptr,
				_In_ BOOL _resetAll = false);

			// ���� : 
			INTERFACE_DECL_FUNC(setup_RenderTarget)(
				_Out_ Framework_Device & _device,
				_In_ const D3D10_DEVICE_DESC & _desc);

		};

	}
}