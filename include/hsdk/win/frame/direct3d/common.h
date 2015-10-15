#pragma once

#include "dxsdkver.h"
#if ( _DXSDK_PRODUCT_MAJOR < 9 || _DXSDK_BUILD_MAJOR < 1949 )
#error The installed DXSDK is out of date.
#endif

#pragma comment( lib, "dxerr.lib" )
#pragma comment( lib, "dxguid.lib" )
#pragma comment( lib, "d3d9.lib" )
#pragma comment( lib, "d3d10.lib" )
#pragma comment( lib, "d3d10_1.lib" )
#pragma comment( lib, "dxgi.lib" )
#pragma comment( lib, "comctl32.lib" )
#pragma comment(lib, "winmm.lib")



#pragma warning(push)
#pragma warning(disable:4005)
#pragma warning(disable:4838)

// Direct3D9 includes
#include <d3d9.h>
#include <d3dx9.h>

// Direct3D10 includes
#include <d3dcommon.h>
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



#include "../../../../hsdk_common.h"
#include "../../../autorelease.h"



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
	namespace direct3d
	{

		DECL_STRUCT(D3D9_DEVICE_DESC);
		DECL_STRUCT(D3D10_DEVICE_DESC);
		DECL_STRUCT(D3D10_COUNTERS);
		DECL_STRUCT(Direct3D_Callbacks);
		DECL_STRUCT(Direct3D_Callback_UserContexts);
		DECL_STRUCT(Direct3D_INIT_DESC);
		DECL_STRUCT(Direct3D_TIMER_DESC);
		DECL_STRUCT(Direct3D_Window);
		DECL_STRUCT(Direct3D_Device);
		DECL_STRUCT(Direct3D_DeviceDescs);
		DECL_STRUCT(Direct3D_DeviceMatchOptions);

		// 설명 : 
		enum DEVICE_VERSION
		{
			NONE_DEVICE = 0,
			D3D9_DEVICE,
			D3D10_DEVICE
		};

		// 설명 : Finding valid device settings.
		enum DEVICE_MATCH_TYPE
		{
			// 설명 : Use the closest valid value to a default.
			IGNORE_INPUT = 0,

			// 설명 : Use input without change, but may cause no valid device to be found.
			PRESERVE_INPUT,

			// 설명 : Use the closest valid value to the input.
			CLOSEST_TO_INPUT
		};

		//--------------------------------------------------------------------------------------
		// General callbacks
		//--------------------------------------------------------------------------------------

		// 설명 : 
		typedef void (CALLBACK *CALLBACK_FRAMEMOVE)(
			/* [r] */ double _fTime,
			/* [r] */ float _fElapsedTime,
			/* [r/w] */ void * _userContext);

		// 설명 : 
		typedef void (CALLBACK *CALLBACK_KEYBOARD)(
			/* [r] */ unsigned int _key,
			/* [r] */ BOOL _keyDown,
			/* [r] */ BOOL _altDown,
			/* [r/w] */ void * _userContext);

		// 설명 : 
		typedef void (CALLBACK *CALLBACK_MOUSE)(
			/* [r] */ const BOOL * _buttonsDown,
			/* [r] */ unsigned int _buttonCount,
			/* [r] */ int _mouseWheelDelta,
			/* [r] */ int _xPos,
			/* [r] */ int _yPos,
			/* [r/w] */ void * _userContext);

		// 설명 : 
		typedef long (CALLBACK *CALLBACK_MSGPROC)(
			/* [w] */ BOOL * _refNoFurtherProcessing,
			/* [r] */ HWND _hWnd,
			/* [r] */ unsigned int _uMsg,
			/* [r] */ unsigned int _wParam,
			/* [r] */ long _lParam,
			/* [r/w] */ void * _userContext);

		// 설명 : 
		typedef BOOL(CALLBACK *CALLBACK_TIMER)(
			/* [r] */ unsigned int _idEvent,
			/* [r/w] */ void * _userContext);

		// 설명 : 
		typedef BOOL(CALLBACK *CALLBACK_MODIFY_DEVICE_SETTINGS)(
			/* [w] */ Direct3D_DeviceDescs & _refDeviceDescs,
			/* [r/w] */ void * _userContext);

		// 설명 : 
		typedef BOOL(CALLBACK *CALLBACK_DEVICE_REMOVED)(
			/* [r/w] */ void * _userContext);

		// Direct3D 9 callbacks

		// 설명 : 
		typedef BOOL(CALLBACK *CALLBACK_IS_D3D9_DEVICE_ACCEPTABLE)(
			/* [r] */ const D3DCAPS9 & _caps,
			/* [r] */ D3DFORMAT _adapterFormat,
			/* [r] */ D3DFORMAT _backBufferFormat,
			/* [r] */ BOOL _windowed,
			/* [r/w] */ void * _userContext);

		// 설명 : 
		typedef long (CALLBACK *CALLBACK_D3D9_DEVICE_CREATED)(
			/* [r] */ const Direct3D_Device & _d3dDevice,
			/* [r] */ const D3DSURFACE_DESC & _backBufferSurfaceDesc,
			/* [r/w] */ void * _userContext);

		// 설명 : 
		typedef long (CALLBACK *CALLBACK_D3D9_DEVICE_RESET)(
			/* [r] */ const Direct3D_Device & _d3dDevice,
			/* [r] */ const D3DSURFACE_DESC & _backBufferSurfaceDesc,
			/* [r/w] */ void * _userContext);

		// 설명 : 
		typedef void (CALLBACK *CALLBACK_D3D9_FRAME_RENDER)(
			/* [r] */ const Direct3D_Device & _d3dDevice,
			/* [r] */ double _fTime,
			/* [r] */ float _fElapsedTime,
			/* [r/w] */ void * _userContext);

		// 설명 : 
		typedef void (CALLBACK *CALLBACK_D3D9_DEVICE_LOST)(
			/* [r/w] */ void * _userContext);

		// 설명 : 
		typedef void (CALLBACK *CALLBACK_D3D9_DEVICE_DESTROYED)(
			/* [r/w] */ void * _userContext);

		// Direct3D 10 callbacks

		// 설명 : 
		typedef BOOL(CALLBACK *CALLBACK_IS_D3D10_DEVICE_ACCEPTABLE)(
			/* [r] */ unsigned int _adapter,
			/* [r] */ unsigned int _output,
			/* [r] */ D3D10_DRIVER_TYPE _deviceType,
			/* [r] */ DXGI_FORMAT _backBufferFormat,
			/* [r] */ BOOL _windowed,
			/* [r/w] */ void * _userContext);

		// 설명 : 
		typedef long (CALLBACK *CALLBACK_D3D10_DEVICE_CREATED)(
			/* [r] */ const Direct3D_Device & _d3dDevice,
			/* [r] */ const DXGI_SURFACE_DESC & _backBufferSurfaceDesc,
			/* [r/w] */ void * _userContext);

		// 설명 : 
		typedef long (CALLBACK *CALLBACK_D3D10_SWAPCHAINRESIZED)(
			/* [r] */ const Direct3D_Device & _d3dDevice,
			/* [r] */ IDXGISwapChain * _swapChain,
			/* [r] */ const DXGI_SURFACE_DESC & _backBufferSurfaceDesc,
			/* [r/w] */ void * _userContext);

		// 설명 : 
		typedef void (CALLBACK *CALLBACK_D3D10_FRAME_RENDER)(
			/* [r] */ const Direct3D_Device & _d3dDevice,
			/* [r] */ double _fTime,
			/* [r] */ float _fElapsedTime,
			/* [r/w] */ void * _userContext);

		// 설명 : 
		typedef void (CALLBACK *CALLBACK_D3D10_SWAPCHAINRELEASING)(
			/* [r/w] */ void* _userContext);

		// 설명 : 
		typedef void (CALLBACK *CALLBACK_D3D10_DEVICE_DESTROYED)(
			/* [r/w] */ void * _userContext);

		//--------------------------------------------------------------------------------------
		// Structs
		//--------------------------------------------------------------------------------------

		// 설명 : 
		DECL_STRUCT(D3D9_DEVICE_DESC)
		{

			// 설명 : 
			unsigned int adapterOrdinal;

			// 설명 : 
			D3DDEVTYPE deviceType;

			// 설명 : 
			D3DFORMAT adapterFormat;

			// 설명 : 
			unsigned long behaviorFlags;

			// 설명 : 
			D3DPRESENT_PARAMETERS pp;

		};

		// 설명 : 
		DECL_STRUCT(D3D10_DEVICE_DESC)
		{

			// 설명 : 
			unsigned int adapterOrdinal;

			// 설명 : 
			D3D10_DRIVER_TYPE driverType;

			// 설명 : 
			unsigned int output;

			// 설명 : 
			DXGI_SWAP_CHAIN_DESC sd;

			// 설명 : 
			unsigned int createFlags;

			// 설명 : 
			unsigned int syncInterval;

			// 설명 : 
			unsigned long presentFlags;

			// 설명 : Direct3D will create the a depth stencil resource and view if true
			BOOL autoCreateDepthStencil;

			// 설명 : 
			DXGI_FORMAT autoDepthStencilFormat;

		};

		// 설명 : D3D10 Counters.
		DECL_STRUCT(D3D10_COUNTERS)
		{

			// 설명 : 
			float fGPUIdle;

			// 설명 : 
			float fVertexProcessing;

			// 설명 : 
			float fGeometryProcessing;

			// 설명 : 
			float fPixelProcessing;

			// 설명 : 
			float fOtherGPUProcessing;

			// 설명 : 
			float fHostAdapterBandwidthUtilization;

			// 설명 : 
			float fLocalVidmemBandwidthUtilization;

			// 설명 : 
			float fVertexThroughputUtilization;

			// 설명 : 
			float fTriangleSetupThroughputUtilization;

			// 설명 : 
			float fFillrateThroughputUtilization;

			// 설명 : 
			float fVSMemoryLimited;

			// 설명 : 
			float fVSComputationLimited;

			// 설명 : 
			float fGSMemoryLimited;

			// 설명 : 
			float fGSComputationLimited;

			// 설명 : 
			float fPSMemoryLimited;

			// 설명 : 
			float fPSComputationLimited;

			// 설명 : 
			float fPostTransformCacheHitRate;

			// 설명 : 
			float fTextureCacheHitRate;

		};

		// 설명 : 
		DECL_STRUCT(Direct3D_Callbacks)
		{

			// 설명 : frame move callback.
			CALLBACK_FRAMEMOVE frameMoveFunc = nullptr;

			// 설명 : keyboard callback.
			CALLBACK_KEYBOARD keyboardFunc = nullptr;

			// 설명 : mouse callback.
			CALLBACK_MOUSE mouseFunc = nullptr;

			// 설명 : window messages callback.
			CALLBACK_MSGPROC windowMsgFunc = nullptr;

			// 설명 : modify Direct3D device settings callback.
			CALLBACK_MODIFY_DEVICE_SETTINGS modifyDeviceSettingsFunc = nullptr;

			// 설명 : Direct3D device removed callback.
			CALLBACK_DEVICE_REMOVED deviceRemovedFunc = nullptr;

			// 설명 : D3D9 is device acceptable callback.
			CALLBACK_IS_D3D9_DEVICE_ACCEPTABLE isD3D9DeviceAcceptableFunc = nullptr;

			// 설명 : D3D9 device created callback.
			CALLBACK_D3D9_DEVICE_CREATED d3d9DeviceCreatedFunc = nullptr;

			// 설명 : D3D9 device reset callback.
			CALLBACK_D3D9_DEVICE_RESET d3d9DeviceResetFunc = nullptr;

			// 설명 : D3D9 device lost callback.
			CALLBACK_D3D9_DEVICE_LOST d3d9DeviceLostFunc = nullptr;

			// 설명 : D3D9 device destroyed callback.
			CALLBACK_D3D9_DEVICE_DESTROYED d3d9DeviceDestroyedFunc = nullptr;

			// 설명 : D3D9 frame render callback.
			CALLBACK_D3D9_FRAME_RENDER d3d9FrameRenderFunc = nullptr;

			// 설명 : D3D10 is device acceptable callback.
			CALLBACK_IS_D3D10_DEVICE_ACCEPTABLE isD3D10DeviceAcceptableFunc = nullptr;

			// 설명 : D3D10 device created callback.
			CALLBACK_D3D10_DEVICE_CREATED d3d10DeviceCreatedFunc = nullptr;

			// 설명 : D3D10 SwapChain reset callback.
			CALLBACK_D3D10_SWAPCHAINRESIZED d3d10SwapChainResizedFunc = nullptr;

			// 설명 : D3D10 SwapChain lost callback.
			CALLBACK_D3D10_SWAPCHAINRELEASING d3d10SwapChainReleasingFunc = nullptr;

			// 설명 : D3D10 device destroyed callback.
			CALLBACK_D3D10_DEVICE_DESTROYED d3d10DeviceDestroyedFunc = nullptr;

			// 설명 : D3D10 frame render callback.
			CALLBACK_D3D10_FRAME_RENDER d3d10FrameRenderFunc = nullptr;

		};

		// 설명 : 
		DECL_STRUCT(Direct3D_Callback_UserContexts)
		{

			// 설명 : user context for frame move callback
			void * frameMoveFuncUserContext = nullptr;

			// 설명 : user context for keyboard callback
			void * keyboardFuncUserContext = nullptr;

			// 설명 : if true, include WM_MOUSEMOVE in mousecallback
			BOOL notifyOnMouseMove = false;

			// 설명 : user context for mouse callback
			void * mouseFuncUserContext = nullptr;

			// 설명 : user context for window messages callback
			void * windowMsgFuncUserContext = nullptr;

			// 설명 : user context for modify Direct3D device settings callback
			void * modifyDeviceSettingsFuncUserContext = nullptr;

			// 설명 : user context for Direct3D device removed callback
			void * deviceRemovedFuncUserContext = nullptr;

			// 설명 : user context for is D3D9 device acceptable callback
			void * isD3D9DeviceAcceptableFuncUserContext = nullptr;

			// 설명 : user context for D3D9 device created callback
			void * d3d9DeviceCreatedFuncUserContext = nullptr;

			// 설명 : user context for D3D9 device reset callback
			void * d3d9DeviceResetFuncUserContext = nullptr;

			// 설명 : user context for D3D9 device lost callback
			void * d3d9DeviceLostFuncUserContext = nullptr;

			// 설명 : user context for D3D9 device destroyed callback
			void * d3d9DeviceDestroyedFuncUserContext = nullptr;

			// 설명 : user context for D3D9 frame render callback
			void * d3d9FrameRenderFuncUserContext = nullptr;

			// 설명 : user context for is D3D10 device acceptable callback
			void * isD3D10DeviceAcceptableFuncUserContext = nullptr;

			// 설명 : user context for D3D10 device created callback
			void * d3d10DeviceCreatedFuncUserContext = nullptr;

			// 설명 : user context for D3D10 SwapChain resized callback
			void * d3d10SwapChainResizedFuncUserContext = nullptr;

			// 설명 : user context for D3D10 SwapChain releasing callback
			void * d3d10SwapChainReleasingFuncUserContext = nullptr;

			// 설명 : user context for D3D10 device destroyed callback
			void * d3d10DeviceDestroyedFuncUserContext = nullptr;

			// 설명 : user context for D3D10 frame render callback
			void * d3d10FrameRenderFuncUserContext = nullptr;

		};

		// 설명 : 
		DECL_STRUCT(Direct3D_INIT_DESC)
		{

			// 설명 : if != -1, then override to use this Direct3D API version
			int	forceAPI = -1;

			// 설명 : if != -1, then override to use this adapter ordinal
			int	adapterOrdinal = -1;

			// 설명 : if true, then force to start windowed
			BOOL fullScreen = false;

			// 설명 : if != -1, then override to use the particular output on the adapter
			int	output = -1;

			// 설명 : if true, then force to HAL device (failing if one doesn't exist)
			BOOL forceHAL = false;

			// 설명 : if true, then force to REF device (failing if one doesn't exist)
			BOOL forceREF = false;

			// 설명 : if true, then force to WARP device (failing if one doesn't exist)
			BOOL forceWARP = false;

			// 설명 : if true, then force to use pure HWVP (failing if device doesn't support it)
			BOOL forcePureHWVP = false;

			// 설명 : if true, then force to use HWVP (failing if device doesn't support it)
			BOOL forceHWVP = false;

			// 설명 : if true, then force to use SWVP 
			BOOL forceSWVP = false;

			// 설명 : if == 0, then it will force the app to use D3DPRESENT_INTERVAL_IMMEDIATE, if == 1 force use of D3DPRESENT_INTERVAL_DEFAULT
			int	forceVsync = 1;

			// 설명 : if != 0, then override to this width
			int	width = 0;

			// 설명 : if != 0, then override to this height
			int	height = 0;

			// 설명 : if != -1, then override to this X position of the window
			int	startX = -1;

			// 설명 : if != -1, then override to this Y position of the window
			int	startY = -1;

			// 설명 : if true, then force to constant frame time
			BOOL constantFrameTime = false;

			// 설명 : the constant time per frame in seconds if m_OverrideConstantFrameTime==true
			float constantTimePerFrame = 0.0f;

			// 설명 : if != 0, then it will force the app to quit after that frame
			int quitAfterFrame = 0;

			// if true, then DXUTGetFrameStats() and DXUTGetDeviceStats() will return blank strings
			BOOL noStats = false;

			// 설명 : if true, then force relaunch of MCE at exit
			BOOL relaunchMCE = false;

			// if true, automation is enabled
			BOOL automation = false;

			// 설명 : StickyKey settings upon startup so they can be restored later
			STICKYKEYS stickyKeys;

			// 설명 : ToggleKey settings upon startup so they can be restored later
			TOGGLEKEYS toggleKeys;

			// 설명 : FilterKey settings upon startup so they can be restored later
			FILTERKEYS filterKeys;

		};

		// 설명 : Stores timer callback info.
		DECL_STRUCT(Direct3D_TIMER_DESC)
		{

			// 설명 : 
			CALLBACK_TIMER callbackTimer = nullptr;

			// 설명 : 
			void * callbackUserContext = nullptr;

			// 설명 : 
			float fTimeoutInSecs = 0.0f;

			// 설명 : 
			float fCountdown = 0.0f;

			// 설명 : 
			BOOL bEnabled = true;

			// 설명 : 
			unsigned int nID = 0;

		};

		// 설명 : 
		DECL_STRUCT(Direct3D_Window)
		{

			// 설명 : handle to the app instance
			HINSTANCE HINSTANCE = nullptr;

			// 설명 : the main app focus window
			HWND focus = nullptr;

			// 설명 : the main app device window in fullscreen mode
			HWND fullScreen = nullptr;

			// 설명 : the main app device window in windowed mode
			HWND windowScreen = nullptr;

			// 설명 : the monitor of the adapter 
			HMONITOR adapterMonitor = nullptr;

			// 설명 : handle to menu
			HMENU menu = nullptr;

			// 설명 : window title     
			wchar_t windowTitle[256];

		};

		// 설명 : 
		DECL_STRUCT(Direct3D_Device)
		{

			// 설명 : 
			AutoRelease<IDirect3D9> direct3D9;

			// 설명 : 
			AutoRelease<IDXGIFactory> dxgiFactory;

			// 설명 :
			AutoRelease<IDirect3DDevice9> d3d9Device;

			// 설명 : 
			D3DSURFACE_DESC backBuffer_Desc;

			// 설명 : 
			AutoRelease<IDXGISwapChain> dxgiSwapChain;

			// 설명 :
			DXGI_SURFACE_DESC dxgiBackBuffer_Desc;

			// 설명 :
			AutoRelease<ID3D10Device1> d3d10Device1;

			// 설명 :
			AutoRelease<ID3D10Device> d3d10Device;

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
		DECL_STRUCT(Direct3D_DeviceDescs)
		{

			// 설명 :
			DEVICE_VERSION version = NONE_DEVICE;

			union
			{
				// 설명 : current device settings
				D3D9_DEVICE_DESC d3d9DeviceDesc;

				// 설명 : current device settings
				D3D10_DEVICE_DESC d3d10DeviceDesc;
			};

		};

		// 설명 : 
		DECL_STRUCT(Direct3D_DeviceMatchOptions)
		{

			// 설명 : 
			DEVICE_MATCH_TYPE eAPIVersion;

			// 설명 : 
			DEVICE_MATCH_TYPE eAdapterOrdinal;

			// 설명 : 
			DEVICE_MATCH_TYPE eDeviceType;

			// 설명 : 
			DEVICE_MATCH_TYPE eOutput;

			// 설명 : 
			DEVICE_MATCH_TYPE eFullScreen;

			// 설명 : 
			DEVICE_MATCH_TYPE eAdapterFormat;

			// 설명 : 
			DEVICE_MATCH_TYPE eVertexProcessing;

			// 설명 : 
			DEVICE_MATCH_TYPE eResolution;

			// 설명 : 
			DEVICE_MATCH_TYPE eBackBufferFormat;

			// 설명 : 
			DEVICE_MATCH_TYPE eBackBufferCount;

			// 설명 : 
			DEVICE_MATCH_TYPE eMultiSample;

			// 설명 : 
			DEVICE_MATCH_TYPE eSwapEffect;

			// 설명 : 
			DEVICE_MATCH_TYPE eDepthFormat;

			// 설명 : 
			DEVICE_MATCH_TYPE eStencilFormat;

			// 설명 : 
			DEVICE_MATCH_TYPE ePresentFlags;

			// 설명 : 
			DEVICE_MATCH_TYPE eRefreshRate;

			// 설명 : 
			DEVICE_MATCH_TYPE ePresentInterval;

		};

		//--------------------------------------------------------------------------------------
		// common inline function
		//--------------------------------------------------------------------------------------

		// 설명 : Outputs to the debug stream a formatted Unicode string with a variable-argument list.
		inline DECL_FUNC_T(void, direct3D_OutputDebugString)(
			/* [r] */ const wchar_t * _strMsg, ...);

		// 설명 : Helper function for ParseCommandLine.
		inline DECL_FUNC_T(BOOL, is_NextArg)(
			/* [r/w] */ wchar_t * & _strCmdLine,
			/* [r] */ const wchar_t * _strArg);

		/*
		설명 : Helper function for DXUTParseCommandLine.  Updates strCmdLine and strFlag.
		$ ex1 : if strCmdLine=="-width:1024 -forceref"
		$ ex2 : strCmdLine==" -forceref" and strFlag=="1024"
		*/
		inline DECL_FUNC_T(BOOL, get_CmdParam)(
			/* [r/w] */ wchar_t * & _strCmdLine,
			/* [r/w] */ wchar_t * _strFlag);

		// 설명 : Parses the command line for parameters.  See initialize_Default() for list.
		inline DECL_FUNC_T(void, parse_CommandLine)(
			/* [w] */ Direct3D_INIT_DESC & _initDesc,
			/* [r] */ __inout const wchar_t * _strCommandLine,
			/* [r] */ BOOL _ignoreFirstCommand);

		// 설명 : get D3D9_DEVICE_DESC from Direct3D_INIT_DESC.
		inline DECL_FUNC_T(D3D9_DEVICE_DESC, initialize_DeviceDesc)(
			/* [r] */ HWND _hwnd,
			/* [r] */ BOOL _windowed = true,
			/* [r] */ int _width = 640,
			/* [r] */ int _height = 480);

		// 설명 : convert Format D3D9 to DXGI.
		inline DECL_FUNC_T(DXGI_FORMAT, convert_Format_D3D9ToDXGI)(
			/* [r] */ D3DFORMAT _format);

		// 설명 : convert DriverType D3D9 to DXGI.
		inline DECL_FUNC_T(D3D10_DRIVER_TYPE, convert_DriverType_D3D9ToDXGI)(
			/* [r] */ D3DDEVTYPE _type);

		// 설명 : convert DriverType DXGI to D3D9.
		inline DECL_FUNC_T(D3DDEVTYPE, convert_DriverType_DXGITOD3D9)(
			/* [r] */ D3D10_DRIVER_TYPE _type);

		// 설명 : convert D3D9_DEVICE_DESC to D3D10_DEVICE_DESC.
		inline DECL_FUNC_T(void, convert_DeviceDesc_9to10)(
			/* [w] */ D3D10_DEVICE_DESC & _out,
			/* [r] */ const D3D9_DEVICE_DESC & _in);

		/*
		설명 : Internal helper function to build a D3D9 device settings structure based upon the match options.
		If the match option is set to ignore, then a optimal default value is used.
		The default value may not exist on the system, but later this will be taken into account.
		*/
		inline DECL_FUNC_T(void, build_OptimalDeviceDesc)(
			/* [w] */ D3D9_DEVICE_DESC & _out,
			/* [r] */ const D3D9_DEVICE_DESC & _in,
			/* [r] */ const Direct3D_DeviceMatchOptions & _matOpt);

		/*
		설명 : Internal helper function to build a D3D10 device settings structure based upon the match options.
		If the match option is set to ignore, then a optimal default value is used.
		The default value may not exist on the system, but later this will be taken into account.
		*/
		inline DECL_FUNC_T(void, build_OptimalDeviceDesc)(
			/* [w] */ D3D10_DEVICE_DESC & _out,
			/* [r] */ const D3D10_DEVICE_DESC & _in,
			/* [r] */ const Direct3D_DeviceMatchOptions & _matOpt);

		// 설명 : Check if the new device is close enough to the old device to simply reset or resize the back buffer.
		inline DECL_FUNC_T(BOOL, is_ResetDevice)(
			/* [w] */ const Direct3D_DeviceDescs & _oldDesc,
			/* [w] */ const Direct3D_DeviceDescs & _newDesc);

		// 설명 :
		inline DECL_FUNC_T(BOOL, is_WindowedFromDesc)(
			/* [r] */ const Direct3D_DeviceDescs & _desc);

		// 설명 :
		inline DECL_FUNC_T(unsigned int, get_WidthFromDesc)(
			/* [r] */ const Direct3D_DeviceDescs & _desc);

		// 설명 :
		inline DECL_FUNC_T(unsigned int, get_HeightFromDesc)(
			/* [r] */ const Direct3D_DeviceDescs & _desc);

	}
}



#include "common.inl"