#pragma once



#include "common.h"
#include "framework_device.h"
#include "framework_usertimestream.h"



namespace hsdk
{
	namespace framework
	{

		// 설명 : 
		DECL_STRUCT(Framework_State)
		{

			// 설명 :
			volatile long setupWindow = 0;

			// 설명 :
			volatile long setupDeviceFactory = 0;

			// 설명 :
			volatile long setupDevice = 0;

			// 설명 :
			volatile long runMainLoop = 0;

			// 설명 :
			bool calledMsgProc = false;

			// 설명 :
			bool calledModifiedBackBuffer = false;

			// 설명 : 
			BOOL autoChangeAdapter = true;

			// 설명 : 
			BOOL is_in_GammaCorrectMode = false;

			// 설명 : 
			BOOL allowWhenFullscreen = false;

			// 설명 : 
			BOOL allowWhenWindowed = false;

			// 
			BOOL storeLastKeyPressed = true;

			// 설명 : 
			HHOOK keyboardHook = nullptr;

			// 설명 : StickyKey settings upon startup so they can be restored later
			STICKYKEYS stickyKeys;

			// 설명 : ToggleKey settings upon startup so they can be restored later
			TOGGLEKEYS toggleKeys;

			// 설명 : FilterKey settings upon startup so they can be restored later
			FILTERKEYS filterKeys;

			// 설명 : 
			unsigned long frameCount = 0;

		};

		// 설명 : 
		DECL_STRUCT(Framework_Window)
		{

			// 설명 : handle to the app instance
			HINSTANCE HINSTANCE = nullptr;

			// 설명 : window title     
			std::wstring windowTitle;

			// 설명 : the main app focus window
			HWND hwnd = nullptr;

			// 설명 : handle to menu
			HMENU menu = nullptr;

			// 설명 :
			unsigned int adapter = 0;

			// 설명 : 
			BOOL windowed = TRUE;

			// 설명 :
			unsigned long width = 0;

			// 설명 :
			unsigned long height = 0;

			// 설명 : window size When it was windowed
			RECT windowedRect;

			// 설명 : window style When it was windowed
			long windowedStyle;

			// 설명 :
			BOOL minimizedSize = false;

			// 설명 :
			BOOL maximizedSize = false;

		};

		/*
		설명 : direct3d framework
		$ 참고 : do not generate this class, use global variable g_Direct3D.
		even if you will generate this class it links with g_Direct3D.
		*/
		DLL_DECL_CLASS(Framework)
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
				_In_ const wchar_t * _strWindowTitle = L"Direct3DWindow",
				_In_ int _x = CW_USEDEFAULT,
				_In_ int _y = CW_USEDEFAULT,
				_In_ HINSTANCE _hInstance = nullptr,
				_In_ HICON _hIcon = nullptr,
				_In_ HMENU _hMenu = nullptr);

			// 설명 : 
			CLASS_DECL_FUNC(setup1_DeviceFactory)(
				/* [set] */ Framework_DeviceFactory * _factory);

			// 설명 : 
			CLASS_DECL_FUNC(setup2_Device9)(
				/* [set] */ D3D9_DEVICE_DESC & _desc);

			// 설명 : 
			CLASS_DECL_FUNC(setup2_Device10)(
				/* [set] */ D3D10_DEVICE_DESC & _desc);

			// 설명 : 
			CLASS_DECL_FUNC(dynamic_WndProc)(
				_In_ unsigned int _uMsg,
				_In_ unsigned int _wParam,
				_In_ long _lParam);

			// 설명 : 
			CLASS_DECL_FUNC(transform)(
				_In_ BOOL _windowed = true,
				_In_ unsigned long _suggestedWidth = 0,
				_In_ unsigned long _suggestedHeight = 0,
				_In_ bool _clipMonitor = false,
				_In_ unsigned int _adapter = -1);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, destroy)(
				_X_ void);

			//--------------------------------------------------------------------------------------
			// Active task
			//--------------------------------------------------------------------------------------

			/*
			설명:
			$ 참고 : Choose either Direct3D::MainLoop or implement your own main loop.
			*/
			CLASS_DECL_FUNC(mainLoop)(
				_In_ HACCEL _accel = nullptr);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, render)(
				_X_ void);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, shutdown)(
				_In_ int _exitCode = 0);

			//--------------------------------------------------------------------------------------
			// userSet tasks 
			//--------------------------------------------------------------------------------------

			// 설명 : Controls the Windows key, and accessibility shortcut keys.
			CLASS_DECL_FUNC_T(void, userSet_ShortcutKeySettings)(
				_In_ BOOL _allowWhenFullscreen = false,
				_In_ BOOL _allowWhenWindowed = true);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, userSet_AutoChangeMoniter)(
				_In_ BOOL _autoChange = true);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, userSet_GammaCorrectMode)(
				_In_ BOOL _gammaCorrect = true);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, userSet_Vsync)(
				_In_ BOOL _vsync = true);

			//--------------------------------------------------------------------------------------
			// General
			//--------------------------------------------------------------------------------------

			// 설명 : _rect must have (x, y, w, h)
			CLASS_DECL_FUNC_T(BOOL, clip_Screen)(
				_In_ RECT & _rect,
				_In_ BOOL _windowed)const;

			// 설명 : Pass a virtual-key code, ex. VK_F1, 'A', VK_RETURN, VK_LSHIFT, etc.
			CLASS_DECL_FUNC_T(BOOL, is_KeyDown)(
				_In_ unsigned char vKey)const;

			// 설명 : Like Direct3D::IsKeyDown() but return true only if the key was just pressed.
			CLASS_DECL_FUNC_T(BOOL, was_KeyPressed)(
				_In_ unsigned char vKey)const;

			// 설명 : Pass a virtual-key code: VK_LBUTTON, VK_RBUTTON, VK_MBUTTON, VK_XBUTTON1, VK_XBUTTON2.
			CLASS_DECL_FUNC_T(BOOL, is_MouseButtonDown)(
				_In_ unsigned char vButton)const;

			//--------------------------------------------------------------------------------------
			// State retrieval  
			//--------------------------------------------------------------------------------------

			// 설명 : 
			CLASS_DECL_FUNC_T(Framework_UserTimeStream *, timeStream)(
				_X_ void)const;

			// 설명 : 
			CLASS_DECL_FUNC_T(Framework_Callbacks *, callbacks)(
				_X_ void)const;

			// 설명 : 
			CLASS_DECL_FUNC_T(const Framework_State *, get_State)(
				_X_ void)const;

			// 설명 : 
			CLASS_DECL_FUNC_T(const Framework_Window *, get_Window)(
				_X_ void)const;

			// 설명 : 
			CLASS_DECL_FUNC_T(const Framework_Device *, get_Device)(
				_X_ void)const;

			// 설명 : 
			CLASS_DECL_FUNC_T(const D3D9_DEVICE_DESC *, get_Device9Desc)(
				_X_ void)const;

			// 설명 : 
			CLASS_DECL_FUNC_T(const D3D10_DEVICE_DESC *, get_Device10Desc)(
				_X_ void)const;

		};

		// 설명 : framework grobal variable
		extern HSDK_DLL Framework g_Direct3D;

		// 설명 : framework grobal variable. you can read and write. just do not call update.
		extern HSDK_DLL Framework_UserTimeStream & g_Direct3D_TimeStream;

		// 설명 : framework grobal variable.
		extern HSDK_DLL Framework_Callbacks & g_Direct3D_Callbacks;

		// 설명 : framework grobal variable. only read, so do not write forced.
		extern HSDK_DLL const Framework_State & g_Direct3D_State;

		// 설명 : framework grobal variable. only read, so do not write forced.
		extern HSDK_DLL const Framework_Window & g_Framework_Window;

		// 설명 : framework grobal variable. only read, so do not write forced.
		extern HSDK_DLL const Framework_Device & g_Framework_Device;

	}
}