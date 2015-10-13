#pragma once



#include "common.h"



namespace hsdk
{
	namespace direct3d
	{

		// 설명 : 
		DLL_DECL_CLASS(Direct3D)
		{
		public:
			
			//--------------------------------------------------------------------------------------
			// initialize task
			//--------------------------------------------------------------------------------------

			// 설명 : 
			CLASS_DECL_FUNC(initialize_Default)(
				/* [r] */ BOOL _parseCommandLine = true,
				/* [r] */ BOOL _showMsgBoxOnError = true,
				/* [r] */ __in_opt wchar_t * _strExtraCommandLineParams = nullptr,
				/* [r] */ BOOL _threadSafe = false);

			/*
			설명 :
			$ 참고 : Choose either createWindow or setWindow.If using setWindow, consider using staticWndProc.
			*/
			CLASS_DECL_FUNC(initialize_Window)(
				/* [r] */ const wchar_t * _strWindowTitle = L"Direct3D Window",
				/* [r] */ int _x = CW_USEDEFAULT,
				/* [r] */ int _y = CW_USEDEFAULT,
				/* [r] */ HINSTANCE _hInstance = nullptr,
				/* [r] */ HICON _hIcon = nullptr,
				/* [r] */ HMENU _hMenu = nullptr);

			// 설명 : 
			CLASS_DECL_FUNC(userSet_Window)(
				/* [in] */ HWND _focus,
				/* [in] */ HWND _fullScreen,
				/* [in] */ HWND _windowScreen,
				/* [r] */ BOOL _handleMessages = true);

			// 설명 : 
			CLASS_DECL_FUNC(dynamic_WndProc)(
				/* [r] */ HWND _hWnd,
				/* [r] */ unsigned int _uMsg,
				/* [r] */ unsigned int _wParam,
				/* [r] */ long _lParam);

			/*
			설명 :
			$ 참고 : Choose either Direct3D::CreateDevice or Direct3D::SetD3D*Device or Direct3D::CreateD3DDeviceFromSettings.
			*/
			CLASS_DECL_FUNC(initialize_Device)(
				/* [r] */ BOOL _windowed = true,
				/* [r] */ int _suggestedWidth = 640,
				/* [r] */ int _suggestedHeight = 480);

			// 설명 : 
			CLASS_DECL_FUNC(userSet_Device)(
				/* [r] */ const Direct3D_DeviceDescs & _d3dDescs,
				/* [r] */ BOOL _clipWindowToSingleAdapter = true,
				/* [r] */ BOOL _resetRecovery = false);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, destroy)(
				/* [x] */ void);

			//--------------------------------------------------------------------------------------
			// Active task
			//--------------------------------------------------------------------------------------

			/*
			설명:
			$ 참고 : Choose either Direct3D::MainLoop or implement your own main loop.
			*/
			CLASS_DECL_FUNC(mainLoop)(
				/* [r] */ HACCEL _accel = nullptr);

			//--------------------------------------------------------------------------------------
			// Common tasks 
			//--------------------------------------------------------------------------------------

			// 설명 : 
			CLASS_DECL_FUNC_T(void, shutdown)(
				/* [r] */ int _exitCode = 0);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, pause_Time)(
				/* [r] */ BOOL _pauseTime);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, pause_Rendering)(
				/* [r] */ BOOL _pauseRendering);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, set_ConstantFrameTime)(
				/* [r] */ BOOL _constantFrameTime,
				/* [r] */ float _fTimePerFrame = 0.0333f);

			// 설명 : 
			CLASS_DECL_FUNC(set_Timer)(
				/* [r] */ CALLBACK_TIMER _callbackTimer,
				/* [r] */ float _fTimeoutInSecs = 1.0f,
				/* [r] */ unsigned int * _nIDEvent = nullptr,
				/* [r] */ void * _userContext = nullptr);

			// 설명 : 
			CLASS_DECL_FUNC(kill_Timer)(
				/* [r] */ UINT nIDEvent);

			// 설명 : Controls the Windows key, and accessibility shortcut keys.
			CLASS_DECL_FUNC_T(void, set_ShortcutKeySettings)(
				/* [r] */ BOOL _allowWhenFullscreen = false,
				/* [r] */ BOOL _allowWhenWindowed = true);

			// 설명 : 
			CLASS_DECL_FUNC(toggle_FullScreen)(
				/* [x] */ void);

			// 설명 : 
			CLASS_DECL_FUNC(toggle_REF)(
				/* [x] */ void);

			// 설명 : 
			CLASS_DECL_FUNC(toggle_WARP)(
				/* [x] */ void);
			
			// 설명 : 
			CLASS_DECL_FUNC_T(void, change_Monitor)(
				/* [r] */ BOOL _windowed = true,
				/* [r] */ int _suggestedWidth = 0,
				/* [r] */ int _suggestedHeight = 0,
				/* [r] */ unsigned int _adapter = -1);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, set_AutoChangeMoniter)(
				/* [r] */ BOOL _autoChange = true);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, set_GammaCorrectMode)(
				/* [r] */ BOOL _gammaCorrect = true);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, set_Vsync)(
				/* [r] */ BOOL _vsync = true);

			//--------------------------------------------------------------------------------------
			// General
			//--------------------------------------------------------------------------------------

			// 설명 : 
			CLASS_DECL_FUNC_T(const wchar_t *, get_Window_Title)(
				/* [x] */ void)const;

			// 설명 : 
			CLASS_DECL_FUNC_T(HINSTANCE, get_HINSTANCE)(
				/* [x] */ void)const;

			// 설명 : 
			CLASS_DECL_FUNC_T(HWND, get_HWND_Focus)(
				/* [x] */ void)const;

			// 설명 : 
			CLASS_DECL_FUNC_T(HWND, get_HWND_FullScreen)(
				/* [x] */ void)const;

			// 설명 : 
			CLASS_DECL_FUNC_T(HWND, get_HWND_WindowScreen)(
				/* [x] */ void)const;

			// 설명 : Useful for returning to windowed mode with the same resolution as before toggle to full screen mode.
			CLASS_DECL_FUNC_T(RECT, get_Window_ClientRect_AtModeChange)(
				/* [x] */ void)const;

			// 설명 : Useful for returning to full screen mode with the same resolution as before toggle to windowed mode.
			CLASS_DECL_FUNC_T(RECT, get_FullsceenClientRect_AtModeChange)(
				/* [x] */ void)const;

			// 설명 : 
			CLASS_DECL_FUNC_T(double, get_Time)(
				/* [x] */ void)const;

			// 설명 : 
			CLASS_DECL_FUNC_T(float, get_ElapsedTime)(
				/* [x] */ void)const;

			// 설명 : 
			CLASS_DECL_FUNC_T(float, get_FPS)(
				/* [x] */ void)const;

			// 설명 : 
			CLASS_DECL_FUNC_T(BOOL, is_Time_Paused)(
				/* [x] */ void)const;

			// 설명 : 
			CLASS_DECL_FUNC_T(BOOL, is_Rendering_Paused)(
				/* [x] */ void)const;

			// 설명 : 
			CLASS_DECL_FUNC_T(BOOL, is_Active)(
				/* [x] */ void)const;

			// 설명 : Pass a virtual-key code, ex. VK_F1, 'A', VK_RETURN, VK_LSHIFT, etc.
			CLASS_DECL_FUNC_T(BOOL, is_KeyDown)(
				/* [r] */ unsigned char vKey)const;

			// 설명 : Like Direct3D::IsKeyDown() but return true only if the key was just pressed.
			CLASS_DECL_FUNC_T(BOOL, was_KeyPressed)(
				/* [r] */ unsigned char vKey)const;

			// 설명 : Pass a virtual-key code: VK_LBUTTON, VK_RBUTTON, VK_MBUTTON, VK_XBUTTON1, VK_XBUTTON2.
			CLASS_DECL_FUNC_T(BOOL, is_MouseButtonDown)(
				/* [r] */ unsigned char vButton)const;
			
			// 설명 : 
			CLASS_DECL_FUNC_T(BOOL, is_Windowed)(
				/* [x] */ void)const;
			
			// 설명 : 
			CLASS_DECL_FUNC_T(int, get_Width)(
				/* [x] */ void)const;

			// 설명 : 
			CLASS_DECL_FUNC_T(int, get_Height)(
				/* [x] */ void)const;

			// 설명 : 
			CLASS_DECL_FUNC_T(int, get_ExitCode)(
				/* [x] */ void)const;

			//--------------------------------------------------------------------------------------
			// State retrieval  
			//--------------------------------------------------------------------------------------

			// 설명 : 
			CLASS_DECL_FUNC_T(DEVICE_VERSION, get_D3DVersion)(
				/* [x] */ void)const;

			// Direct3D 9

			// 설명 : Does not addref unlike typical Get* APIs.
			CLASS_DECL_FUNC_T(IDirect3D9 *, get_D3D9)(
				/* [x] */ void)const;

			// 설명 : Does not addref unlike typical Get* APIs.
			CLASS_DECL_FUNC_T(IDirect3DDevice9 *, get_D3D9_Device) (
				/* [x] */ void)const;

			// 설명 : 
			CLASS_DECL_FUNC_T(D3D9_DEVICE_DESC, get_D3D9_Settings)(
				/* [x] */ void)const;

			// 설명 : 
			CLASS_DECL_FUNC_T(D3DPRESENT_PARAMETERS, get_D3D9_PresentParameters) (
				/* [x] */ void)const;

			// 설명 : 
			CLASS_DECL_FUNC_T(D3DSURFACE_DESC, get_D3D9_BackBufferSurfaceDesc) (
				/* [x] */ void)const;

			// Direct3D 10

			// 설명 : If D3D10 APIs are availible.
			CLASS_DECL_FUNC_T(BOOL, is_D3D10_Available)(
				/* [x] */ void)const;

			// 설명 : Does not addref unlike typical Get* APIs.
			CLASS_DECL_FUNC_T(IDXGIFactory *, get_DXGIFactory)(
				/* [x] */ void)const;

			// 설명 : Does not addref unlike typical Get* APIs.
			CLASS_DECL_FUNC_T(ID3D10Device *, get_D3D10_Device)(
				/* [x] */ void)const;

			// 설명 : Does not addref unlike typical Get* APIs.
			CLASS_DECL_FUNC_T(ID3D10Device1 *, get_D3D10_Device1)(
				/* [x] */ void)const;

			CLASS_DECL_FUNC_T(D3D10_DEVICE_DESC, get_D3D10_Settings)(
				/* [x] */ void)const;

			// 설명 : Does not addref unlike typical Get* APIs.
			CLASS_DECL_FUNC_T(IDXGISwapChain *, get_DXGISwapChain)(
				/* [x] */ void)const;

			// 설명 : Does not addref unlike typical Get* APIs.
			CLASS_DECL_FUNC_T(ID3D10RenderTargetView *, get_D3D10_RenderTargetView)(
				/* [x] */ void)const;

			// 설명 : Does not addref unlike typical Get* APIs.
			CLASS_DECL_FUNC_T(ID3D10DepthStencilView *, get_D3D10_DepthStencilView)(
				/* [x] */ void)const;
			// 설명 : 
			CLASS_DECL_FUNC_T(DXGI_SURFACE_DESC, get_DXGIBackBufferSurfaceDesc)(
				/* [x] */ void)const;

			//--------------------------------------------------------------------------------------
			// General callbacks
			//--------------------------------------------------------------------------------------

			// 설명 : 
			CLASS_DECL_FUNC_T(void, set_Callback_FrameMove)(
				/* [ref] */ CALLBACK_FRAMEMOVE _callback,
				/* [ref] */ void * _userContext = nullptr);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, set_Callback_Keyboard)(
				/* [ref] */ CALLBACK_KEYBOARD _callback,
				/* [ref] */ void * _userContext = nullptr);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, set_Callback_Mouse)(
				/* [ref] */ CALLBACK_MOUSE _callback,
				/* [r] */ BOOL _includeMouseMove = false,
				/* [ref] */ void * _userContext = nullptr);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, set_Callback_MsgProc)(
				/* [ref] */ CALLBACK_MSGPROC _callback,
				/* [ref] */ void * _userContext = nullptr);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, set_Callback_DeviceChanging)(
				/* [ref] */ CALLBACK_MODIFY_DEVICE_SETTINGS _callback,
				/* [ref] */ void * _userContext = nullptr);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, set_Callback_DeviceRemoved)(
				/* [ref] */ CALLBACK_DEVICE_REMOVED _callback,
				/* [ref] */ void * _userContext = nullptr);

			// Direct3D 9 callbacks

			// 설명 : 
			CLASS_DECL_FUNC_T(void, set_Callback_D3D9_DeviceAcceptable)(
				/* [ref] */ CALLBACK_IS_D3D9_DEVICE_ACCEPTABLE _callback,
				/* [ref] */ void * _userContext = nullptr);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, set_Callback_D3D9_DeviceCreated)(
				/* [ref] */ CALLBACK_D3D9_DEVICE_CREATED _callback,
				/* [ref] */ void * _userContext = nullptr);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, set_Callback_D3D9_DeviceReset)(
				/* [ref] */ CALLBACK_D3D9_DEVICE_RESET _callback,
				/* [ref] */ void * _userContext = nullptr);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, set_Callback_D3D9_DeviceLost)(
				/* [ref] */ CALLBACK_D3D9_DEVICE_LOST _callback,
				/* [ref] */ void * _userContext = nullptr);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, set_Callback_D3D9_DeviceDestroyed)(
				/* [ref] */ CALLBACK_D3D9_DEVICE_DESTROYED _callback,
				/* [ref] */ void * _userContext = nullptr);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, set_Callback_D3D9_FrameRender)(
				/* [ref] */ CALLBACK_D3D9_FRAME_RENDER _callback,
				/* [ref] */ void * _userContext = nullptr);

			// Direct3D 10 callbacks

			// 설명 : 
			CLASS_DECL_FUNC_T(void, set_Callback_D3D10_DeviceAcceptable)(
				/* [ref] */ CALLBACK_IS_D3D10_DEVICE_ACCEPTABLE _callback,
				/* [ref] */ void * _userContext = nullptr);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, set_Callback_D3D10_DeviceCreated)(
				/* [ref] */ CALLBACK_D3D10_DEVICE_CREATED _callback,
				/* [ref] */ void * _userContext = nullptr);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, set_Callback_D3D10_SwapChainResized)(
				/* [ref] */ CALLBACK_D3D10_SWAPCHAINRESIZED _callback,
				/* [ref] */ void * _userContext = nullptr);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, set_Callback_D3D10_SwapChainReleasing)(
				/* [ref] */ CALLBACK_D3D10_SWAPCHAINRELEASING _callback,
				/* [ref] */ void * _userContext = nullptr);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, set_Callback_D3D10_DeviceDestroyed)(
				/* [ref] */ CALLBACK_D3D10_DEVICE_DESTROYED _callback,
				/* [ref] */ void * _userContext = nullptr);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, set_Callback_D3D10_FrameRender)(
				/* [ref] */ CALLBACK_D3D10_FRAME_RENDER _callback,
				/* [ref] */ void * _userContext = nullptr);

		};


		typedef HRESULT (WINAPI * callback_CreateDXGIFactory)(
			REFIID riid,
			void **ppFactory);

		typedef HRESULT(WINAPI * callback_D3D10CreateDevice1)(
			IDXGIAdapter *pAdapter,
			D3D10_DRIVER_TYPE DriverType,
			HMODULE Software,
			UINT Flags,
			D3D10_FEATURE_LEVEL1 HardwareLevel,
			UINT SDKVersion,
			ID3D10Device1 **ppDevice);

		typedef HRESULT(WINAPI * callback_D3D10CreateDevice)(
			IDXGIAdapter *pAdapter,
			D3D10_DRIVER_TYPE DriverType,
			HMODULE Software,
			UINT Flags,
			UINT SDKVersion,
			ID3D10Device **ppDevice);
		
		typedef IDirect3D9 * (WINAPI * callback_Direct3DCreate9)(
			UINT SDKVersion);

	}
}