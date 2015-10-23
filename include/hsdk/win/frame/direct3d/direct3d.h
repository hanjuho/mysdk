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
			volatile long setupWindow = 0;

			// ���� :
			volatile long setupDeviceFactory = 0;

			// ���� :
			volatile long setupDevice = 0;

			// ���� :
			volatile long runMainLoop = 0;

			// ���� :
			bool calledMsgProc = false;

			// ���� :
			bool calledModifiedBackBuffer = false;

			// ���� : 
			BOOL autoChangeAdapter = true;

			// ���� : 
			BOOL is_in_GammaCorrectMode = false;

			// ���� : 
			BOOL allowWhenFullscreen = false;

			// ���� : 
			BOOL allowWhenWindowed = false;

			// 
			BOOL storeLastKeyPressed = true;

			// ���� : 
			HHOOK keyboardHook = nullptr;

			// ���� : StickyKey settings upon startup so they can be restored later
			STICKYKEYS stickyKeys;

			// ���� : ToggleKey settings upon startup so they can be restored later
			TOGGLEKEYS toggleKeys;

			// ���� : FilterKey settings upon startup so they can be restored later
			FILTERKEYS filterKeys;

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

			// ���� :
			unsigned int adapter = 0;

			// ���� : 
			BOOL windowed = TRUE;

			// ���� :
			unsigned long width = 0;

			// ���� :
			unsigned long height = 0;

			// ���� : window size When it was windowed
			RECT windowedRect;

			// ���� : window style When it was windowed
			long windowedStyle;

			// ���� :
			BOOL minimizedSize = false;

			// ���� :
			BOOL maximizedSize = false;

		};

		/*
		���� : direct3d framework
		$ ���� : do not generate this class, use global variable g_Direct3D.
		even if you will generate this class it links with g_Direct3D.
		*/
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
				_In_ const wchar_t * _strWindowTitle = L"Direct3D Window",
				_In_ int _x = CW_USEDEFAULT,
				_In_ int _y = CW_USEDEFAULT,
				_In_ HINSTANCE _hInstance = nullptr,
				_In_ HICON _hIcon = nullptr,
				_In_ HMENU _hMenu = nullptr);

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
				_In_ unsigned int _uMsg,
				_In_ unsigned int _wParam,
				_In_ long _lParam);

			// ���� : 
			CLASS_DECL_FUNC(transform)(
				_In_ BOOL _windowed = true,
				_In_ unsigned long _suggestedWidth = 0,
				_In_ unsigned long _suggestedHeight = 0,
				_In_ bool _clipMonitor = false,
				_In_ unsigned int _adapter = -1);

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
				_In_ HACCEL _accel = nullptr);

			// ���� : 
			CLASS_DECL_FUNC_T(void, render)(
				/* [x] */ void);

			// ���� : 
			CLASS_DECL_FUNC_T(void, shutdown)(
				_In_ int _exitCode = 0);

			//--------------------------------------------------------------------------------------
			// userSet tasks 
			//--------------------------------------------------------------------------------------

			// ���� : Controls the Windows key, and accessibility shortcut keys.
			CLASS_DECL_FUNC_T(void, userSet_ShortcutKeySettings)(
				_In_ BOOL _allowWhenFullscreen = false,
				_In_ BOOL _allowWhenWindowed = true);

			// ���� : 
			CLASS_DECL_FUNC_T(void, userSet_AutoChangeMoniter)(
				_In_ BOOL _autoChange = true);

			// ���� : 
			CLASS_DECL_FUNC_T(void, userSet_GammaCorrectMode)(
				_In_ BOOL _gammaCorrect = true);

			// ���� : 
			CLASS_DECL_FUNC_T(void, userSet_Vsync)(
				_In_ BOOL _vsync = true);

			//--------------------------------------------------------------------------------------
			// General
			//--------------------------------------------------------------------------------------

			// ���� : _rect must have (x, y, w, h)
			CLASS_DECL_FUNC_T(BOOL, clip_Screen)(
				_In_ RECT & _rect,
				_In_ BOOL _windowed)const;

			// ���� : Pass a virtual-key code, ex. VK_F1, 'A', VK_RETURN, VK_LSHIFT, etc.
			CLASS_DECL_FUNC_T(BOOL, is_KeyDown)(
				_In_ unsigned char vKey)const;

			// ���� : Like Direct3D::IsKeyDown() but return true only if the key was just pressed.
			CLASS_DECL_FUNC_T(BOOL, was_KeyPressed)(
				_In_ unsigned char vKey)const;

			// ���� : Pass a virtual-key code: VK_LBUTTON, VK_RBUTTON, VK_MBUTTON, VK_XBUTTON1, VK_XBUTTON2.
			CLASS_DECL_FUNC_T(BOOL, is_MouseButtonDown)(
				_In_ unsigned char vButton)const;

			//--------------------------------------------------------------------------------------
			// State retrieval  
			//--------------------------------------------------------------------------------------

			// ���� : 
			CLASS_DECL_FUNC_T(win::UserTimeStream *, timeStream)(
				/* [x] */ void)const;

			// ���� : 
			CLASS_DECL_FUNC_T(Direct3D_Callbacks *, callbacks)(
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

		// ���� : direct3d grobal variable
		extern HSDK_DLL Direct3D g_Direct3D;

		// ���� : direct3d grobal variable. you can read and write. just do not call update.
		extern HSDK_DLL win::UserTimeStream & g_Direct3D_TimeStream;

		// ���� : direct3d grobal variable.
		extern HSDK_DLL Direct3D_Callbacks & g_Direct3D_Callbacks;

		// ���� : direct3d grobal variable. only read, so do not write forced.
		extern HSDK_DLL const Direct3D_State & g_Direct3D_State;

		// ���� : direct3d grobal variable. only read, so do not write forced.
		extern HSDK_DLL const Direct3D_Window & g_Direct3D_Window;

		// ���� : direct3d grobal variable. only read, so do not write forced.
		extern HSDK_DLL const Direct3D_Device & g_Direct3D_Device;

	}
}