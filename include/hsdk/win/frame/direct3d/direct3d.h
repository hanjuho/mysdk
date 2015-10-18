#pragma once



#include "common.h"
#include "direct3d_device.h"
#include "../../usertimestream.h"



namespace hsdk
{
	namespace direct3d
	{

		// 설명 : 
		DECL_STRUCT(Direct3D_State)
		{
			
			// 설명 :
			bool modifyBackBuffer_inMsgProc = false;

			// 설명 : 
			BOOL autoChangeAdapter = true;

			// 설명 : 
			BOOL is_in_GammaCorrectMode = false;
			
			// 설명 :
			volatile long setupWindow = 0;

			// 설명 :
			volatile long setupDeviceFactory = 0;

			// 설명 :
			volatile long setupDevice = 0;

			// 설명 :
			volatile long runMainLoop = 0;

			// 설명 :
			BOOL minimizedSize = false;

			// 설명 :
			BOOL maximizedSize = false;

			// 설명 : 
			BOOL allowWhenFullscreen = false;

			// 설명 : 
			BOOL allowWhenWindowed = false;

			// 
			BOOL calledWasKeyPressed = false;

			// 설명 : 
			HHOOK keyboardHook = nullptr;

			// 설명 : StickyKey settings upon startup so they can be restored later
			STICKYKEYS stickyKeys;

			// 설명 : ToggleKey settings upon startup so they can be restored later
			TOGGLEKEYS toggleKeys;

			// 설명 : FilterKey settings upon startup so they can be restored later
			FILTERKEYS filterKeys;

			// 설명 :
			unsigned int adapter = 0;

			// 설명 : 
			BOOL windowed = TRUE;

			// 설명 :
			unsigned long width = 0;

			// 설명 :
			unsigned long height = 0;

			// 설명 : 
			unsigned long frameCount = 0;

		};

		// 설명 : 
		DECL_STRUCT(Direct3D_Window)
		{

			// 설명 : handle to the app instance
			HINSTANCE HINSTANCE = nullptr;

			// 설명 : window title     
			std::wstring windowTitle;

			// 설명 : the main app focus window
			HWND hwnd = nullptr;

			// 설명 : handle to menu
			HMENU menu = nullptr;

			// 설명 : the monitor of the adapter 
			HMONITOR adapterMonitor = nullptr;

		};

		// 설명 : 
		DLL_DECL_CLASS(Direct3D)
		{
		public:
			
			//--------------------------------------------------------------------------------------
			// initialize task
			//--------------------------------------------------------------------------------------

			/*
			설명 :
			$ 참고 : Choose either createWindow or setWindow.If using setWindow, consider using staticWndProc.
			*/
			CLASS_DECL_FUNC(setup0_Window)(
				/* [r] */ const wchar_t * _strWindowTitle = L"Direct3D Window",
				/* [r] */ int _x = CW_USEDEFAULT,
				/* [r] */ int _y = CW_USEDEFAULT,
				/* [r] */ HINSTANCE _hInstance = nullptr,
				/* [r] */ HICON _hIcon = nullptr,
				/* [r] */ HMENU _hMenu = nullptr);

			// 설명 : 
			CLASS_DECL_FUNC(setup1_DeviceFactory)(
				/* [set] */ Direct3D_DeviceFactory * _factory);
			
			// 설명 : 
			CLASS_DECL_FUNC(setup2_Device9)(
				/* [set] */ D3D9_DEVICE_DESC & _desc);

			// 설명 : 
			CLASS_DECL_FUNC(setup2_Device10)(
				/* [set] */ D3D10_DEVICE_DESC & _desc);

			// 설명 : 
			CLASS_DECL_FUNC(dynamic_WndProc)(
				/* [r] */ unsigned int _uMsg,
				/* [r] */ unsigned int _wParam,
				/* [r] */ long _lParam);

			// 설명 : 
			CLASS_DECL_FUNC(transform)(
				/* [r] */ BOOL _windowed = true,
				/* [r] */ unsigned long _suggestedWidth = 0,
				/* [r] */ unsigned long _suggestedHeight = 0,
				/* [r] */ unsigned int _adapter = -1);
			
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
			
			// 설명 : 
			CLASS_DECL_FUNC_T(void, render)(
				/* [x] */ void);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, shutdown)(
				/* [r] */ int _exitCode = 0);

			//--------------------------------------------------------------------------------------
			// userSet tasks 
			//--------------------------------------------------------------------------------------
			
			// 설명 : Controls the Windows key, and accessibility shortcut keys.
			CLASS_DECL_FUNC_T(void, userSet_ShortcutKeySettings)(
				/* [r] */ BOOL _allowWhenFullscreen = false,
				/* [r] */ BOOL _allowWhenWindowed = true);
			
			// 설명 : 
			CLASS_DECL_FUNC_T(void, userSet_AutoChangeMoniter)(
				/* [r] */ BOOL _autoChange = true);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, userSet_GammaCorrectMode)(
				/* [r] */ BOOL _gammaCorrect = true);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, userSet_Vsync)(
				/* [r] */ BOOL _vsync = true);

			//--------------------------------------------------------------------------------------
			// General
			//--------------------------------------------------------------------------------------

			// 설명 : Useful for returning to full screen mode with the same resolution as before toggle to windowed mode.
			CLASS_DECL_FUNC_T(void, clip_Screen)(
				/* [r] */ BOOL _windowed,
				/* [r] */ RECT & _rect)const;

			// 설명 : Pass a virtual-key code, ex. VK_F1, 'A', VK_RETURN, VK_LSHIFT, etc.
			CLASS_DECL_FUNC_T(BOOL, is_KeyDown)(
				/* [r] */ unsigned char vKey)const;

			// 설명 : Like Direct3D::IsKeyDown() but return true only if the key was just pressed.
			CLASS_DECL_FUNC_T(BOOL, was_KeyPressed)(
				/* [r] */ unsigned char vKey)const;

			// 설명 : Pass a virtual-key code: VK_LBUTTON, VK_RBUTTON, VK_MBUTTON, VK_XBUTTON1, VK_XBUTTON2.
			CLASS_DECL_FUNC_T(BOOL, is_MouseButtonDown)(
				/* [r] */ unsigned char vButton)const;

			//--------------------------------------------------------------------------------------
			// State retrieval  
			//--------------------------------------------------------------------------------------

			// 설명 : 
			CLASS_DECL_FUNC_T(Direct3D_Callbacks *, callbacks)(
				/* [x] */ void)const;

			// 설명 : 
			CLASS_DECL_FUNC_T(win::UserTimeStream *, timeStream)(
				/* [x] */ void)const;

			// 설명 : 
			CLASS_DECL_FUNC_T(const Direct3D_State *, get_State)(
				/* [x] */ void)const;
			
			// 설명 : 
			CLASS_DECL_FUNC_T(const Direct3D_Window *, get_Window)(
				/* [x] */ void)const;

			// 설명 : 
			CLASS_DECL_FUNC_T(const Direct3D_Device *, get_Device)(
				/* [x] */ void)const;

			// 설명 : 
			CLASS_DECL_FUNC_T(const D3D9_DEVICE_DESC *, get_Device9Desc)(
				/* [x] */ void)const;
			
			// 설명 : 
			CLASS_DECL_FUNC_T(const D3D10_DEVICE_DESC *, get_Device10Desc)(
				/* [x] */ void)const;

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