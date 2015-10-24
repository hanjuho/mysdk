#pragma once

#include "dxsdkver.h"
#if ( _DXSDK_PRODUCT_MAJOR < 9 || _DXSDK_BUILD_MAJOR < 1949 )
#error The installed DXSDK is out of date.
#endif

#pragma comment( lib, "dxerr.lib" )
#pragma comment( lib, "dxguid.lib" )
#pragma comment( lib, "d3d9.lib" )
#pragma comment( lib, "d3dx9.lib" )
#pragma comment( lib, "d3d10.lib" )
#pragma comment( lib, "d3dx10.lib" )
#pragma comment( lib, "d3d10_1.lib" )
#pragma comment( lib, "dxgi.lib" )
#pragma comment( lib, "comctl32.lib" )
#pragma comment(lib, "winmm.lib")



#pragma warning(push)
#pragma warning(disable:4005)
#pragma warning(disable:4838)

#include <d3dcommon.h>

// Direct3D9 includes
#include <d3d9.h>
#include <d3dx9.h>

// Direct3D10 includes
#include <dxgi.h>
#include <d3d10_1.h>
#include <d3d10.h>
#include <d3dx10.h>



#include <d2d1.h>
#include <dwrite.h>
#include <xnamath.h>
#pragma warning(pop)



// Standard Windows includes
#include <commctrl.h>	// for InitCommonControls() 
#include <shellapi.h>	// for ExtractIcon()
#include <new.h>		// for placement new
#include <stdio.h>		// for vswprintf_s()



#include "../../hsdk_common.h"
#include "../autorelease.h"



//--------------------------------------------------------------------------------------
// Error codes
//--------------------------------------------------------------------------------------
#define Direct3DERR_NODIRECT3D              MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0901)
#define Direct3DERR_NOCOMPATIBLEDEVICES     MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0902)
#define Direct3DERR_MEDIANOTFOUND           MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0903)
#define Direct3DERR_NONZEROREFCOUNT         MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0904)
#define Direct3DERR_CREATINGDEVICE          MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0905)
#define Direct3DERR_RESETTINGDEVICE         MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0906)
#define Direct3DERR_CREATINGDEVICEOBJECTS   MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0907)
#define Direct3DERR_RESETTINGDEVICEOBJECTS  MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0908)
#define Direct3DERR_DEVICEREMOVED           MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x090A)

//--------------------------------------------------------------------------------------
// mouse button index
//--------------------------------------------------------------------------------------
enum
{
	Direct3D_LEFTBUTTON = 0,
	Direct3D_MIDDLEBUTTON = 1,
	Direct3D_RIGHTBUTTON = 2,
	Direct3D_SIDEBUTTON1 = 3,
	Direct3D_SIDEBUTTON2 = 4
};


namespace hsdk
{
	namespace framework
	{

		// ���� : 
		DECL_STRUCT(D3D9_DEVICE_DESC)
		{

			// ���� : 
			D3D9_DEVICE_DESC(
				_In_ BOOL _windowed,
				_In_ unsigned int _width,
				_In_ unsigned int _heigth)
			{
				pp.BackBufferWidth = _width;
				pp.BackBufferHeight = _heigth;
				pp.BackBufferFormat = D3DFMT_A8R8G8B8;
				pp.BackBufferCount = 2;
				pp.MultiSampleType = D3DMULTISAMPLE_NONE;
				pp.MultiSampleQuality = 0;
				pp.SwapEffect = D3DSWAPEFFECT_DISCARD;
				pp.hDeviceWindow = nullptr;
				pp.Windowed = _windowed;
				pp.EnableAutoDepthStencil = TRUE;
				pp.AutoDepthStencilFormat = D3DFMT_D24S8;
				pp.Flags = D3DPRESENTFLAG_DISCARD_DEPTHSTENCIL;
				pp.FullScreen_RefreshRateInHz = 0;
				pp.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;
			}

			// ���� : 
			unsigned int adapterOrdinal = D3DADAPTER_DEFAULT;

			// ���� : 
			D3DDEVTYPE deviceType = D3DDEVTYPE_HAL;

			// ���� : 
			D3DFORMAT adapterFormat = D3DFMT_UNKNOWN;

			// ���� : 
			unsigned long behaviorFlags = D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_PUREDEVICE;

			// ���� : 
			D3DPRESENT_PARAMETERS pp;

		};

		// ���� : 
		DECL_STRUCT(D3D10_DEVICE_DESC)
		{

			// ���� : 
			D3D10_DEVICE_DESC(
				_In_ BOOL _windowed,
				_In_ unsigned int _width,
				_In_ unsigned int _heigth)
			{
				sd.BufferDesc.Width = _width;
				sd.BufferDesc.Height = _heigth;
				sd.BufferDesc.RefreshRate.Numerator = 0;
				sd.BufferDesc.RefreshRate.Denominator = 0;
				sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM_SRGB;
				sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
				sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
				sd.SampleDesc.Count = 1;
				sd.SampleDesc.Quality = 0;
				sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
				sd.BufferCount = 2;
				sd.OutputWindow = nullptr;
				sd.Windowed = _windowed;
				sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
				sd.Flags = 0;
			}

			// ���� : 
			unsigned int adapterOrdinal = D3DADAPTER_DEFAULT;

			// ���� : 
			D3D10_DRIVER_TYPE driverType = D3D10_DRIVER_TYPE_HARDWARE;

			// ���� : 
			unsigned int output = 0;

#if defined(DEBUG) || defined(_DEBUG)

			// ���� : 
			unsigned int createFlags = D3D10_CREATE_DEVICE_DEBUG;

#else

			// ���� : 
			unsigned int createFlags = 0;

#endif

			// ���� : 
			unsigned int syncInterval = D3DPRESENT_INTERVAL_DEFAULT;

			// ���� : 
			unsigned long presentFlags = 0;

			// ���� : Direct3D will create the a depth stencil resource and view if true
			BOOL autoCreateDepthStencil = TRUE;

			// ���� : 
			DXGI_FORMAT autoDepthStencilFormat = DXGI_FORMAT_D24_UNORM_S8_UINT;

			// ���� : 
			DXGI_SWAP_CHAIN_DESC sd;

		};

		//--------------------------------------------------------------------------------------
		// General callbacks
		//--------------------------------------------------------------------------------------

		// ���� : 
		typedef void (CALLBACK *CALLBACK_FRAMEMOVE)(
			_In_ double _fTime,
			_In_ float _fElapsedTime,
			/* [r/w] */ void * _userContext);

		// ���� : 
		typedef void (CALLBACK *CALLBACK_KEYBOARD)(
			_In_ unsigned char _key,
			_In_ short _keyDown,
			_In_ short _altDown,
			/* [r/w] */ void * _userContext);

		// ���� : 
		typedef void (CALLBACK *CALLBACK_MOUSE)(
			_In_ const short * _buttonsDown,
			_In_ unsigned int _buttonCount,
			_In_ int _mouseWheelDelta,
			_In_ int _xPos,
			_In_ int _yPos,
			/* [r/w] */ void * _userContext);

		// ���� : 
		typedef long (CALLBACK *CALLBACK_MSGPROC)(
			_Out_ BOOL * _refNoFurtherProcessing,
			_In_ HWND _hWnd,
			_In_ unsigned int _uMsg,
			_In_ unsigned int _wParam,
			_In_ long _lParam,
			/* [r/w] */ void * _userContext);

		// ���� : 
		typedef BOOL(CALLBACK *CALLBACK_MODIFY_DEVICE9_SETTINGS)(
			_Out_ const D3D9_DEVICE_DESC & _refDeviceDescs,
			/* [r/w] */ void * _userContext);

		// ���� : 
		typedef BOOL(CALLBACK *CALLBACK_MODIFY_DEVICE10_SETTINGS)(
			_Out_ const D3D10_DEVICE_DESC & _refDeviceDescs,
			/* [r/w] */ void * _userContext);

		// ���� : 
		typedef BOOL(CALLBACK *CALLBACK_DEVICE_REMOVED)(
			/* [r/w] */ void * _userContext);

		// Direct3D 9 callbacks

		// ���� : 
		typedef BOOL(CALLBACK *CALLBACK_IS_D3D9_DEVICE_ACCEPTABLE)(
			_In_ const D3DCAPS9 & _caps,
			_In_ D3DFORMAT _adapterFormat,
			_In_ D3DFORMAT _backBufferFormat,
			_In_ BOOL _windowed,
			/* [r/w] */ void * _userContext);

		// ���� : 
		typedef long (CALLBACK *CALLBACK_D3D9_DEVICE_CREATED)(
			_In_ IDirect3DDevice9 * _d3dDevice,
			_In_ const D3DSURFACE_DESC & _backBufferSurfaceDesc,
			/* [r/w] */ void * _userContext);

		// ���� : 
		typedef long (CALLBACK *CALLBACK_D3D9_DEVICE_RESET)(
			_In_ IDirect3DDevice9 * _d3dDevice,
			_In_ const D3DSURFACE_DESC & _backBufferSurfaceDesc,
			/* [r/w] */ void * _userContext);

		// ���� : 
		typedef void (CALLBACK *CALLBACK_D3D9_FRAME_RENDER)(
			_In_ IDirect3DDevice9 * _d3dDevice,
			_In_ double _fTime,
			_In_ float _fElapsedTime,
			/* [r/w] */ void * _userContext);

		// ���� : 
		typedef void (CALLBACK *CALLBACK_D3D9_DEVICE_LOST)(
			/* [r/w] */ void * _userContext);

		// ���� : 
		typedef void (CALLBACK *CALLBACK_D3D9_DEVICE_DESTROYED)(
			/* [r/w] */ void * _userContext);

		// Direct3D 10 callbacks

		// ���� : 
		typedef BOOL(CALLBACK *CALLBACK_IS_D3D10_DEVICE_ACCEPTABLE)(
			_In_ unsigned int _adapter,
			_In_ unsigned int _output,
			_In_ D3D10_DRIVER_TYPE _deviceType,
			_In_ DXGI_FORMAT _backBufferFormat,
			_In_ BOOL _windowed,
			/* [r/w] */ void * _userContext);

		// ���� : 
		typedef long (CALLBACK *CALLBACK_D3D10_DEVICE_CREATED)(
			_In_ ID3D10Device * _d3dDevice,
			_In_ const DXGI_SURFACE_DESC & _backBufferSurfaceDesc,
			/* [r/w] */ void * _userContext);

		// ���� : 
		typedef long (CALLBACK *CALLBACK_D3D10_SWAPCHAINRESIZED)(
			_In_ ID3D10Device * _d3dDevice,
			_In_ IDXGISwapChain * _swapChain,
			_In_ const DXGI_SURFACE_DESC & _backBufferSurfaceDesc,
			/* [r/w] */ void * _userContext);

		// ���� : 
		typedef void (CALLBACK *CALLBACK_D3D10_FRAME_RENDER)(
			_In_ ID3D10Device * _d3dDevice,
			_In_ double _fTime,
			_In_ float _fElapsedTime,
			/* [r/w] */ void * _userContext);

		// ���� : 
		typedef void (CALLBACK *CALLBACK_D3D10_SWAPCHAINRELEASING)(
			/* [r/w] */ void* _userContext);

		// ���� : 
		typedef void (CALLBACK *CALLBACK_D3D10_DEVICE_DESTROYED)(
			/* [r/w] */ void * _userContext);

		//--------------------------------------------------------------------------------------
		// Structs
		//--------------------------------------------------------------------------------------

		// ���� : 
		DECL_STRUCT(Framework_Callbacks)
		{

			// ���� : frame move callback.
			CALLBACK_FRAMEMOVE frameMoveFunc = nullptr;

			// ���� : user context for frame move callback
			void * frameMoveFuncUserContext = nullptr;

			// ���� : keyboard callback.
			CALLBACK_KEYBOARD keyboardFunc = nullptr;

			// ���� : user context for keyboard callback
			void * keyboardFuncUserContext = nullptr;

			// ���� : mouse callback.
			CALLBACK_MOUSE mouseFunc = nullptr;

			// ���� : if true, include WM_MOUSEMOVE in mousecallback
			BOOL notifyOnMouseMove = false;

			// ���� : user context for mouse callback
			void * mouseFuncUserContext = nullptr;

			// ���� : window messages callback.
			CALLBACK_MSGPROC windowMsgFunc = nullptr;

			// ���� : user context for window messages callback
			void * windowMsgFuncUserContext = nullptr;

			// ���� : modify Direct3D device settings callback.
			CALLBACK_MODIFY_DEVICE9_SETTINGS modifyDevice9SettingsFunc = nullptr;

			// ���� : user context for modify Direct3D device settings callback
			void * modifyDevice9SettingsFuncUserContext = nullptr;

			// ���� : modify Direct3D device settings callback.
			CALLBACK_MODIFY_DEVICE10_SETTINGS modifyDevice10SettingsFunc = nullptr;

			// ���� : user context for modify Direct3D device settings callback
			void * modifyDevice10SettingsFuncUserContext = nullptr;

			// ���� : Direct3D device removed callback.
			CALLBACK_DEVICE_REMOVED deviceRemovedFunc = nullptr;

			// ���� : user context for Direct3D device removed callback
			void * deviceRemovedFuncUserContext = nullptr;

			// ���� : D3D9 is device acceptable callback.
			CALLBACK_IS_D3D9_DEVICE_ACCEPTABLE isD3D9DeviceAcceptableFunc = nullptr;

			// ���� : user context for is D3D9 device acceptable callback
			void * isD3D9DeviceAcceptableFuncUserContext = nullptr;

			// ���� : D3D9 device created callback.
			CALLBACK_D3D9_DEVICE_CREATED d3d9DeviceCreatedFunc = nullptr;

			// ���� : user context for D3D9 device created callback
			void * d3d9DeviceCreatedFuncUserContext = nullptr;

			// ���� : D3D9 device reset callback.
			CALLBACK_D3D9_DEVICE_RESET d3d9DeviceResetFunc = nullptr;

			// ���� : user context for D3D9 device reset callback
			void * d3d9DeviceResetFuncUserContext = nullptr;

			// ���� : D3D9 device lost callback.
			CALLBACK_D3D9_DEVICE_LOST d3d9DeviceLostFunc = nullptr;

			// ���� : user context for D3D9 device lost callback
			void * d3d9DeviceLostFuncUserContext = nullptr;

			// ���� : D3D9 device destroyed callback.
			CALLBACK_D3D9_DEVICE_DESTROYED d3d9DeviceDestroyedFunc = nullptr;

			// ���� : user context for D3D9 device destroyed callback
			void * d3d9DeviceDestroyedFuncUserContext = nullptr;

			// ���� : D3D9 frame render callback.
			CALLBACK_D3D9_FRAME_RENDER d3d9FrameRenderFunc = nullptr;

			// ���� : user context for D3D9 frame render callback
			void * d3d9FrameRenderFuncUserContext = nullptr;

			// ���� : D3D10 is device acceptable callback.
			CALLBACK_IS_D3D10_DEVICE_ACCEPTABLE isD3D10DeviceAcceptableFunc = nullptr;

			// ���� : user context for is D3D10 device acceptable callback
			void * isD3D10DeviceAcceptableFuncUserContext = nullptr;

			// ���� : D3D10 device created callback.
			CALLBACK_D3D10_DEVICE_CREATED d3d10DeviceCreatedFunc = nullptr;

			// ���� : user context for D3D10 device created callback
			void * d3d10DeviceCreatedFuncUserContext = nullptr;

			// ���� : D3D10 SwapChain reset callback.
			CALLBACK_D3D10_SWAPCHAINRESIZED d3d10SwapChainResizedFunc = nullptr;

			// ���� : user context for D3D10 SwapChain resized callback
			void * d3d10SwapChainResizedFuncUserContext = nullptr;

			// ���� : D3D10 SwapChain lost callback.
			CALLBACK_D3D10_SWAPCHAINRELEASING d3d10SwapChainReleasingFunc = nullptr;

			// ���� : user context for D3D10 SwapChain releasing callback
			void * d3d10SwapChainReleasingFuncUserContext = nullptr;

			// ���� : D3D10 device destroyed callback.
			CALLBACK_D3D10_DEVICE_DESTROYED d3d10DeviceDestroyedFunc = nullptr;

			// ���� : user context for D3D10 device destroyed callback
			void * d3d10DeviceDestroyedFuncUserContext = nullptr;

			// ���� : D3D10 frame render callback.
			CALLBACK_D3D10_FRAME_RENDER d3d10FrameRenderFunc = nullptr;

			// ���� : user context for D3D10 frame render callback
			void * d3d10FrameRenderFuncUserContext = nullptr;

		};


		//--------------------------------------------------------------------------------------
		// common inline function
		//--------------------------------------------------------------------------------------

		// ���� : convert Format D3D9 to DXGI.
		inline DECL_FUNC_T(DXGI_FORMAT, convert_Format_D3D9ToDXGI)(
			_In_ D3DFORMAT _format);

		// ���� : convert DriverType D3D9 to DXGI.
		inline DECL_FUNC_T(D3D10_DRIVER_TYPE, convert_DriverType_D3D9ToDXGI)(
			_In_ D3DDEVTYPE _type);

		// ���� : convert DriverType DXGI to D3D9.
		inline DECL_FUNC_T(D3DDEVTYPE, convert_DriverType_DXGIToD3D9)(
			_In_ D3D10_DRIVER_TYPE _type);

	}
}



#include "common.inl"