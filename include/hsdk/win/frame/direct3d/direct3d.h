#pragma once



#include "common.h"
#include "direct3d_device.h"
#include "../../usertimestream.h"



namespace hsdk
{
	namespace direct3d
	{

		// ���� : 
		DECL_STRUCT(Direct3D_State)
		{
			
			// ���� :
			bool modifyBackBuffer_inMsgProc = false;

			// ���� : 
			BOOL autoChangeAdapter = true;

			// ���� : 
			BOOL is_in_GammaCorrectMode = false;
			
			// ���� :
			volatile long setupWindow = 0;

			// ���� :
			volatile long setupDeviceFactory = 0;

			// ���� :
			volatile long setupDevice = 0;

			// ���� :
			volatile long runMainLoop = 0;

			// ���� :
			BOOL minimizedSize = false;

			// ���� :
			BOOL maximizedSize = false;

			// ���� : 
			BOOL allowWhenFullscreen = false;

			// ���� : 
			BOOL allowWhenWindowed = false;

			// 
			BOOL calledWasKeyPressed = false;

			// ���� : 
			HHOOK keyboardHook = nullptr;

			// ���� : StickyKey settings upon startup so they can be restored later
			STICKYKEYS stickyKeys;

			// ���� : ToggleKey settings upon startup so they can be restored later
			TOGGLEKEYS toggleKeys;

			// ���� : FilterKey settings upon startup so they can be restored later
			FILTERKEYS filterKeys;

			// ���� :
			unsigned int adapter = 0;

			// ���� : 
			BOOL windowed = TRUE;

			// ���� :
			unsigned long width = 0;

			// ���� :
			unsigned long height = 0;

			// ���� : 
			unsigned long frameCount = 0;

		};

		// ���� : 
		DECL_STRUCT(Direct3D_Window)
		{

			// ���� : handle to the app instance
			HINSTANCE HINSTANCE = nullptr;

			// ���� : window title     
			std::wstring windowTitle;

			// ���� : the main app focus window
			HWND hwnd = nullptr;

			// ���� : handle to menu
			HMENU menu = nullptr;

			// ���� : the monitor of the adapter 
			HMONITOR adapterMonitor = nullptr;

		};

		// ���� : 
		DLL_DECL_CLASS(Direct3D)
		{
		public:
			
			//--------------------------------------------------------------------------------------
			// initialize task
			//--------------------------------------------------------------------------------------

			/*
			���� :
			$ ���� : Choose either createWindow or setWindow.If using setWindow, consider using staticWndProc.
			*/
			CLASS_DECL_FUNC(setup0_Window)(
				/* [r] */ const wchar_t * _strWindowTitle = L"Direct3D Window",
				/* [r] */ int _x = CW_USEDEFAULT,
				/* [r] */ int _y = CW_USEDEFAULT,
				/* [r] */ HINSTANCE _hInstance = nullptr,
				/* [r] */ HICON _hIcon = nullptr,
				/* [r] */ HMENU _hMenu = nullptr);

			// ���� : 
			CLASS_DECL_FUNC(setup1_DeviceFactory)(
				/* [set] */ Direct3D_DeviceFactory * _factory);
			
			// ���� : 
			CLASS_DECL_FUNC(setup2_Device9)(
				/* [set] */ D3D9_DEVICE_DESC & _desc);

			// ���� : 
			CLASS_DECL_FUNC(setup2_Device10)(
				/* [set] */ D3D10_DEVICE_DESC & _desc);

			// ���� : 
			CLASS_DECL_FUNC(dynamic_WndProc)(
				/* [r] */ unsigned int _uMsg,
				/* [r] */ unsigned int _wParam,
				/* [r] */ long _lParam);

			// ���� : 
			CLASS_DECL_FUNC(transform)(
				/* [r] */ BOOL _windowed = true,
				/* [r] */ unsigned long _suggestedWidth = 0,
				/* [r] */ unsigned long _suggestedHeight = 0,
				/* [r] */ unsigned int _adapter = -1);
			
			// ���� : 
			CLASS_DECL_FUNC_T(void, destroy)(
				/* [x] */ void);

			//--------------------------------------------------------------------------------------
			// Active task
			//--------------------------------------------------------------------------------------

			/*
			����:
			$ ���� : Choose either Direct3D::MainLoop or implement your own main loop.
			*/
			CLASS_DECL_FUNC(mainLoop)(
				/* [r] */ HACCEL _accel = nullptr);
			
			// ���� : 
			CLASS_DECL_FUNC_T(void, render)(
				/* [x] */ void);

			// ���� : 
			CLASS_DECL_FUNC_T(void, shutdown)(
				/* [r] */ int _exitCode = 0);

			//--------------------------------------------------------------------------------------
			// userSet tasks 
			//--------------------------------------------------------------------------------------
			
			// ���� : Controls the Windows key, and accessibility shortcut keys.
			CLASS_DECL_FUNC_T(void, userSet_ShortcutKeySettings)(
				/* [r] */ BOOL _allowWhenFullscreen = false,
				/* [r] */ BOOL _allowWhenWindowed = true);
			
			// ���� : 
			CLASS_DECL_FUNC_T(void, userSet_AutoChangeMoniter)(
				/* [r] */ BOOL _autoChange = true);

			// ���� : 
			CLASS_DECL_FUNC_T(void, userSet_GammaCorrectMode)(
				/* [r] */ BOOL _gammaCorrect = true);

			// ���� : 
			CLASS_DECL_FUNC_T(void, userSet_Vsync)(
				/* [r] */ BOOL _vsync = true);

			//--------------------------------------------------------------------------------------
			// General
			//--------------------------------------------------------------------------------------

			// ���� : Useful for returning to full screen mode with the same resolution as before toggle to windowed mode.
			CLASS_DECL_FUNC_T(void, clip_Screen)(
				/* [r] */ BOOL _windowed,
				/* [r] */ RECT & _rect)const;

			// ���� : Pass a virtual-key code, ex. VK_F1, 'A', VK_RETURN, VK_LSHIFT, etc.
			CLASS_DECL_FUNC_T(BOOL, is_KeyDown)(
				/* [r] */ unsigned char vKey)const;

			// ���� : Like Direct3D::IsKeyDown() but return true only if the key was just pressed.
			CLASS_DECL_FUNC_T(BOOL, was_KeyPressed)(
				/* [r] */ unsigned char vKey)const;

			// ���� : Pass a virtual-key code: VK_LBUTTON, VK_RBUTTON, VK_MBUTTON, VK_XBUTTON1, VK_XBUTTON2.
			CLASS_DECL_FUNC_T(BOOL, is_MouseButtonDown)(
				/* [r] */ unsigned char vButton)const;

			//--------------------------------------------------------------------------------------
			// State retrieval  
			//--------------------------------------------------------------------------------------

			// ���� : 
			CLASS_DECL_FUNC_T(Direct3D_Callbacks *, callbacks)(
				/* [x] */ void)const;

			// ���� : 
			CLASS_DECL_FUNC_T(win::UserTimeStream *, timeStream)(
				/* [x] */ void)const;

			// ���� : 
			CLASS_DECL_FUNC_T(const Direct3D_State *, get_State)(
				/* [x] */ void)const;
			
			// ���� : 
			CLASS_DECL_FUNC_T(const Direct3D_Window *, get_Window)(
				/* [x] */ void)const;

			// ���� : 
			CLASS_DECL_FUNC_T(const Direct3D_Device *, get_Device)(
				/* [x] */ void)const;

			// ���� : 
			CLASS_DECL_FUNC_T(const D3D9_DEVICE_DESC *, get_Device9Desc)(
				/* [x] */ void)const;
			
			// ���� : 
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