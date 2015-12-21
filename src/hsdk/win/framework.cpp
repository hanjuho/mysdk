#include "framework.h"
#include "framework_outside.h"

#define NODEBUG
#include <assert.h>
#include <list>



using namespace hsdk::framework;


//--------------------------------------------------------------------------------------
// Grobal thread safety
//--------------------------------------------------------------------------------------

// ���� : 
CRITICAL_SECTION g_cs;

// ���� : 
BOOL g_bThreadSafe = true;


//--------------------------------------------------------------------------------------
// Grobal d3d variable
//--------------------------------------------------------------------------------------

// ���� :
Framework_Callbacks g_Callbacks;

// ���� : 
Framework_UserTimeStream g_TimeStream;

//--------------------------------------------------------------------------------------
// Grobal control variable
//--------------------------------------------------------------------------------------

// ���� : array of key state
short g_Keys[256] = { 0 };

// ���� : array of last key state
short g_LastKeys[256] = { 0 };

// ���� : array of mouse states
short g_MouseButtons[5] = { 0 };

//--------------------------------------------------------------------------------------
// Grobal device handle variable
//--------------------------------------------------------------------------------------

// ���� : 
Framework_State g_State;

// ���� : 
Framework_Window g_Window;

// ���� : 
hsdk::AutoDelete<Framework_DeviceFactory> g_DeviceFactory;

// ���� : 
Framework_Device g_Device;

// ���� : 
hsdk::AutoDelete<D3D9_DEVICE_DESC> g_D3D9Descs;

// ���� : 
hsdk::AutoDelete<D3D10_DEVICE_DESC> g_D3D10Descs;

//--------------------------------------------------------------------------------------
// Grobal function declare
//--------------------------------------------------------------------------------------

/*
���� : Enables/disables Windows keys, and disables or restores the StickyKeys/ToggleKeys/FilterKeys
shortcut to help prevent accidental task switching.
*/
DECL_FUNC_T(void, allow_ShortcutKeys)(
	_In_ BOOL _allowKeys);

// ���� : Handles window messages 
LRESULT CALLBACK direct3D_WndProc(
	_In_ HWND _hWnd,
	_In_ unsigned int _uMsg,
	_In_ unsigned int _wParam,
	_In_ long _lParam);

// ���� : Low level keyboard hook to disable Windows key to prevent accidental task switching. 
LRESULT CALLBACK direct3D_LowLevelKeyboardProc(
	_In_ int _code,
	_In_ WPARAM _wParam,
	_In_ LPARAM _lParam);

//--------------------------------------------------------------------------------------
// initialize task
//--------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(Framework, setup0_Window)(
	_In_ const wchar_t * _strWindowTitle,
	_In_ int _x,
	_In_ int _y,
	_In_ HINSTANCE _hInstance,
	_In_ HICON _hIcon,
	_In_ HMENU _hMenu)
{
	if (TRUE == InterlockedCompareExchange(&g_State.setupWindow, TRUE, FALSE))
	{
		return S_FALSE;
	}

	// Not always needed, but lets the app create GDI dialogs
	InitCommonControls();

	// Save the current sticky/toggle/filter key settings so DXUT can restore them later
	g_State.stickyKeys = { sizeof(STICKYKEYS), 0 };
	SystemParametersInfo(SPI_GETSTICKYKEYS, sizeof(STICKYKEYS), &g_State.stickyKeys, 0);

	g_State.toggleKeys = { sizeof(TOGGLEKEYS), 0 };
	SystemParametersInfo(SPI_GETTOGGLEKEYS, sizeof(TOGGLEKEYS), &g_State.toggleKeys, 0);

	g_State.filterKeys = { sizeof(FILTERKEYS), 0 };
	SystemParametersInfo(SPI_GETFILTERKEYS, sizeof(FILTERKEYS), &g_State.filterKeys, 0);

	IF_INVALID(_hInstance)
	{
		_hInstance = (HINSTANCE)GetModuleHandle(nullptr);
	}

	WCHAR szExePath[MAX_PATH];
	GetModuleFileName(nullptr, szExePath, MAX_PATH);

	// If the icon is nullptr, then use the first one found in the exe
	IF_INVALID(_hIcon)
	{
		_hIcon = ExtractIcon(_hInstance, szExePath, 0);
	}

	// Register the windows class
	WNDCLASS wndClass;
	wndClass.style = CS_DBLCLKS;
	wndClass.lpfnWndProc = direct3D_WndProc;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hInstance = _hInstance;
	wndClass.hIcon = _hIcon;
	wndClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndClass.lpszMenuName = nullptr;
	wndClass.lpszClassName = L"Direct3DWindowClass";

	IF_FALSE(RegisterClass(&wndClass))
	{
		unsigned long dwError = GetLastError();
		if (dwError != ERROR_CLASS_ALREADY_EXISTS)
		{
			return ADD_FLAG(HSDK_FAIL, dwError);
		}
	}

	// Find the window's initial size, but it might be changed later
	long nDefaultWidth = 640;
	long nDefaultHeight = 480;

	RECT rc = {
		0,
		0,
		nDefaultWidth,
		nDefaultHeight
	};

	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, (_hMenu != nullptr) ? true : false);

	// Create the render window
	HWND hWnd = CreateWindow(
		L"Direct3DWindowClass",
		_strWindowTitle,
		WS_OVERLAPPEDWINDOW,
		_x,
		_y,
		(rc.right - rc.left),
		(rc.bottom - rc.top),
		0,
		_hMenu,
		_hInstance,
		0);

	IF_INVALID(hWnd)
	{
		g_State.setupWindow = FALSE;

		return ADD_FLAG(HSDK_FAIL, GetLastError());
	}

	g_Window.HINSTANCE = _hInstance;
	g_Window.windowTitle = _strWindowTitle;
	g_Window.hwnd = hWnd;
	g_Window.menu = _hMenu;

	g_Window.adapter = -1;
	g_Window.windowed = -1;
	g_Window.width = nDefaultWidth;
	g_Window.height = nDefaultHeight;

	GetWindowRect(hWnd, &g_Window.windowedRect);
	g_Window.windowedStyle = GetWindowLong(hWnd, GWL_STYLE);

	return S_OK;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(Framework, setup1_DeviceFactory)(
	/* [set] */ Framework_DeviceFactory * _factory)
{
	IF_INVALID(_factory)
	{
		return E_INVALIDARG;
	}

	if (TRUE == InterlockedCompareExchange(&g_State.setupDeviceFactory, TRUE, FALSE))
	{
		return S_FALSE;
	}

	g_DeviceFactory = _factory;

	return S_OK;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(Framework, setup2_Device9)(
	/* [set] */ D3D9_DEVICE_DESC & _desc)
{
	IF_FALSE(g_State.setupDeviceFactory)
	{
		return E_ACCESSDENIED;
	}

	if (nullptr == _desc.pp.hDeviceWindow)
	{
		_desc.pp.hDeviceWindow = g_Window.hwnd;
	}
	else if (_desc.pp.hDeviceWindow != g_Window.hwnd)
	{
		return E_INVALIDARG;
	}

	if (TRUE == InterlockedCompareExchange(&g_State.setupDevice, TRUE, FALSE))
	{
		return S_FALSE;
	}

	g_State.calledModifiedBackBuffer = false;

	HRESULT hr;
	if (FAILED(hr = g_DeviceFactory->create9(
		&g_Device, 
		_desc, 
		&g_Callbacks)))
	{
		g_State.setupDevice = FALSE;
		return hr;
	}
	else
	{
		g_D3D9Descs = new D3D9_DEVICE_DESC(_desc);
	}

	g_State.calledModifiedBackBuffer = true;

	return transform(
		g_D3D9Descs->pp.Windowed,
		g_D3D9Descs->pp.BackBufferWidth,
		g_D3D9Descs->pp.BackBufferHeight,
		true,
		g_D3D9Descs->adapterOrdinal);
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(Framework, setup2_Device10)(
	/* [set] */ D3D10_DEVICE_DESC & _desc)
{
	IF_FALSE(g_State.setupDeviceFactory)
	{
		return E_ACCESSDENIED;
	}

	if (nullptr == _desc.sd.OutputWindow)
	{
		_desc.sd.OutputWindow = g_Window.hwnd;
	}
	else if (_desc.sd.OutputWindow != g_Window.hwnd)
	{
		return E_INVALIDARG;
	}

	if (TRUE == InterlockedCompareExchange(&g_State.setupDevice, TRUE, FALSE))
	{
		return S_FALSE;
	}

	g_State.calledModifiedBackBuffer = true;

	HRESULT hr;
	if (FAILED(hr = g_DeviceFactory->create10(
		&g_Device,
		_desc,
		&g_Callbacks,
		false)))
	{
		g_State.setupDevice = FALSE;
		return hr;
	}
	else
	{
		g_D3D10Descs = new D3D10_DEVICE_DESC(_desc);
		g_Direct3D_Outside.initialize(g_Device.dxgiFactory, TRUE, g_State.is_in_GammaCorrectMode);
	}

	g_State.calledModifiedBackBuffer = false;

	return transform(
		g_D3D10Descs->sd.Windowed,
		g_D3D10Descs->sd.BufferDesc.Width,
		g_D3D10Descs->sd.BufferDesc.Height,
		true,
		g_D3D10Descs->adapterOrdinal);
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(Framework, dynamic_WndProc)(
	_In_ unsigned int _uMsg,
	_In_ unsigned int _wParam,
	_In_ long _lParam)
{
	return direct3D_WndProc(g_Window.hwnd, _uMsg, _wParam, _lParam);
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(Framework, transform)(
	_In_ BOOL _windowed,
	_In_ unsigned long _suggestedWidth,
	_In_ unsigned long _suggestedHeight,
	_In_ bool _clipMonitor,
	_In_ unsigned int _adapter)
{
	IF_FALSE(g_State.setupDevice)
	{
		return E_ACCESSDENIED;
	}

	// ���� ���� ī�� ������ Ȯ�� �� �� �ȴٸ� ���� �ڵ忡 �߰�.
	unsigned int adapter = _adapter;
	if (g_D3D10Descs)
	{
		// version 10
		const VideoCard_info * info =
			g_Direct3D_Outside.get_info(adapter);

		IF_INVALID(info)
		{
			if (g_State.autoChangeAdapter)
			{
				adapter = g_D3D10Descs->adapterOrdinal;
			}
			else
			{
				return E_INVALIDARG;
			}
		}
	}
	else if (g_D3D9Descs)
	{
		D3DADAPTER_IDENTIFIER9 identifyer9;

		// version 9
		IF_FAILED(g_Device.d3d9->GetAdapterIdentifier(adapter, D3DENUM_WHQL_LEVEL, &identifyer9))
		{
			if (g_State.autoChangeAdapter)
			{
				adapter = g_D3D9Descs->adapterOrdinal;
			}
			else
			{
				return E_INVALIDARG;
			}
		}
	}

	g_State.calledModifiedBackBuffer = true;

	BOOL resultWindowed = _windowed;
	unsigned int resultWidth = _suggestedWidth;
	unsigned int resultHeight = _suggestedHeight;
	unsigned int resultAdapter = adapter;

	HRESULT hr = E_FAIL;

	// window form
	RECT resultRect = { 0 };
	if (g_Window.windowed && _windowed)
	{
		if (g_Window.width == _suggestedWidth &&
			g_Window.height == _suggestedHeight)
		{
			if (_clipMonitor)
			{
				RECT adjRect = { 0 };
				adjRect.right = g_Window.width;
				adjRect.bottom = g_Window.height;

				// compute window size that more than backbuffer 
				AdjustWindowRect(
					&adjRect,
					GetWindowLong(g_Window.hwnd, GWL_STYLE),
					g_Window.menu ? TRUE : FALSE);

				// i just only need position
				GetWindowRect(g_Window.hwnd, &resultRect);
				resultRect.right = adjRect.right - adjRect.left;
				resultRect.bottom = adjRect.bottom - adjRect.top;

				BOOL clip;
				if (clip = clip_Screen(resultRect, g_Window.windowed))
				{
					// clip_Screen�� ���ؼ� width �� heigth �� ��ȭ�� �Ͼ�ٸ�
					if (IS_FLAG(clip, 2) || IS_FLAG(clip, 8))
					{
						GetWindowRect(g_Window.hwnd, &resultRect);

						return transform(
							g_Window.windowed,
							resultRect.right - resultRect.left + adjRect.left - 8,
							resultRect.bottom - resultRect.top + adjRect.top - 8,
							false,
							g_Window.adapter);
					}
				}
			}
		}
		else
		{
			RECT adjRect = { 0 };
			adjRect.right = _suggestedWidth;
			adjRect.bottom = _suggestedHeight;

			// compute window size that need more than backbuffer 
			AdjustWindowRect(
				&adjRect,
				GetWindowLong(g_Window.hwnd, GWL_STYLE),
				g_Window.menu ? TRUE : FALSE);

			// i just only need position
			GetWindowRect(g_Window.hwnd, &resultRect);
			resultRect.right = adjRect.right - adjRect.left;
			resultRect.bottom = adjRect.bottom - adjRect.top;

			if (_clipMonitor)
			{
				clip_Screen(resultRect, g_Window.windowed);
				resultWidth = resultRect.right + adjRect.left - 8;
				resultHeight = resultRect.bottom + adjRect.top - 8;
			}

			hr = S_OK;
		}
	}
	else if (g_Window.windowed && FALSE == _windowed)
	{
		// get fullsize backbuffer
		clip_Screen(resultRect, _windowed);

		resultWidth = resultRect.right - resultRect.left;
		resultHeight = resultRect.bottom - resultRect.top;

		hr = S_OK;
	}
	else if (FALSE == g_Window.windowed && _windowed)
	{
		RECT adjRect = { 0 };

		// compute window size that need more than backbuffer
		AdjustWindowRect(
			&adjRect,
			g_Window.windowedStyle,
			g_Window.menu ? TRUE : FALSE);

		// restore window form
		if (_suggestedWidth == 0)
		{
			resultWidth =
				g_Window.windowedRect.right -
				g_Window.windowedRect.left + adjRect.left - 8;
		}

		// restore window form
		if (_suggestedHeight == 0)
		{
			resultHeight =
				g_Window.windowedRect.bottom -
				g_Window.windowedRect.top + adjRect.top - 8;
		}

		resultRect.left = g_Window.windowedRect.left;
		resultRect.top = g_Window.windowedRect.top;
		resultRect.right = resultWidth - adjRect.left;
		resultRect.bottom = resultHeight - adjRect.top;

		if (_clipMonitor)
		{
			clip_Screen(resultRect, _windowed);
		}

		hr = S_OK;
	}
	else
	{
		// do not initialized g_Window from DeviceDesc
		if (g_Window.adapter != -1 ||
			g_Window.adapter == resultAdapter)
		{
			hr = E_FAIL;
		}
	}

	if (FALSE == resultWindowed)
	{
		// do not initialized g_Window from DeviceDesc
		if (FALSE == g_Window.windowed || g_Window.windowed != -1)
		{
			// store window form
			GetWindowRect(g_Window.hwnd, &g_Window.windowedRect);
			g_Window.windowedStyle = GetWindowLong(g_Window.hwnd, GWL_STYLE);
		}
	}

	IF_SUCCEEDED(hr)
	{
		if (g_Window.adapter == -1 ||
			g_Window.adapter == resultAdapter)
		{
			if (g_D3D10Descs)
			{
				D3D10_DEVICE_DESC backUp = *g_D3D10Descs;

				g_D3D10Descs->sd.Windowed = resultWindowed;
				g_D3D10Descs->sd.BufferDesc.Width = resultWidth;
				g_D3D10Descs->sd.BufferDesc.Height = resultHeight;

				IF_FAILED(hr = g_DeviceFactory->resize10(
					&g_Device, *g_D3D10Descs, &g_Callbacks))
				{
					memcpy(g_D3D10Descs, &backUp, sizeof(D3D10_DEVICE_DESC));
					return hr;
				}
			}
			else if (g_D3D9Descs)
			{

				D3D9_DEVICE_DESC backUp = *g_D3D9Descs;

				g_D3D9Descs->pp.Windowed = resultWindowed;
				g_D3D9Descs->pp.BackBufferWidth = resultWidth;
				g_D3D9Descs->pp.BackBufferHeight = resultHeight;

				IF_FAILED(hr = g_DeviceFactory->restore9(
					&g_Device, *g_D3D9Descs, &g_Callbacks))
				{
					memcpy(g_D3D9Descs, &backUp, sizeof(D3D9_DEVICE_DESC));
					return hr;
				}

			}
		}
		else if (g_Window.adapter != resultAdapter)
		{
			if (g_D3D10Descs)
			{
				D3D10_DEVICE_DESC newDesc = *g_D3D10Descs;

				newDesc.adapterOrdinal = resultAdapter;
				newDesc.sd.Windowed = resultWindowed;
				newDesc.sd.BufferDesc.Width = resultWidth;
				newDesc.sd.BufferDesc.Height = resultHeight;

				CALLBACK_MODIFY_DEVICE10_SETTINGS callback_Modify =
					g_Callbacks.modifyDevice10SettingsFunc;

				if (callback_Modify)
				{
					IF_FALSE(callback_Modify(
						newDesc, g_Callbacks.modifyDevice10SettingsFuncUserContext))
					{
						return E_FAIL;
					}
				}

				IF_FAILED(g_DeviceFactory->reset10(
					&g_Device, newDesc, &g_Callbacks))
				{
					g_State.setupDevice = FALSE;
					return setup2_Device10(*g_D3D10Descs);
				}
			}
			else if (g_D3D9Descs)
			{

				D3D9_DEVICE_DESC newDesc = *g_D3D9Descs;
				memcpy(g_D3D9Descs, &newDesc, sizeof(D3D9_DEVICE_DESC));

				newDesc.adapterOrdinal = resultAdapter;
				newDesc.pp.Windowed = resultWindowed;
				newDesc.pp.BackBufferWidth = resultWidth;
				newDesc.pp.BackBufferHeight = resultHeight;

				CALLBACK_MODIFY_DEVICE9_SETTINGS callback_Modify =
					g_Callbacks.modifyDevice9SettingsFunc;

				if (callback_Modify)
				{
					IF_FALSE(callback_Modify(
						newDesc, g_Callbacks.modifyDevice9SettingsFuncUserContext))
					{
						return E_FAIL;
					}
				}

				IF_FAILED(g_DeviceFactory->reset9(
					&g_Device, newDesc, &g_Callbacks))
				{
					g_State.setupDevice = FALSE;
					return setup2_Device9(newDesc);
				}
			}
		}
	}
	
	g_Device.d3d10ViewPort.Width = resultWidth;
	g_Device.d3d10ViewPort.Height = resultHeight;

	g_Window.windowed = resultWindowed;
	g_Window.width = resultWidth;
	g_Window.height = resultHeight;
	g_Window.adapter = resultAdapter;

	if (resultWindowed)
	{
		IF_FALSE(g_State.calledMsgProc)
		{
			SetWindowPos(
				g_Window.hwnd,
				HWND_TOP,
				resultRect.left,
				resultRect.top,
				resultRect.right,
				resultRect.bottom,
				0);
		}
	}

	if (g_Window.minimizedSize)
	{
		// Need to resize, so if window is maximized or minimized then restore the window
		if (IsIconic(g_Window.hwnd))
		{
			ShowWindow(g_Window.hwnd, SW_RESTORE);
		}
	}

	if (g_Window.maximizedSize)
	{
		// doing the IsIconic() check first also handles the WPF_RESTORETOMAXIMIZED case
		if (IsZoomed(g_Window.hwnd))
		{
			ShowWindow(g_Window.hwnd, SW_RESTORE);
		}
	}

	// Make the window visible
	if (!IsWindowVisible(g_Window.hwnd))
	{
		ShowWindow(g_Window.hwnd, SW_SHOW);
	}

	// Ensure that the display doesn't power down when fullscreen but does when windowed
	if (g_Window.windowed)
	{
		SetThreadExecutionState(ES_DISPLAY_REQUIRED | ES_CONTINUOUS);
	}
	else
	{
		SetThreadExecutionState(ES_CONTINUOUS);
	}

	g_State.calledModifiedBackBuffer = false;

	return S_OK;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Framework, void, destroy)(
	_X_ void)
{
	g_Direct3D_Outside.destroy();
	this->shutdown();

	// all clear
	g_TimeStream = Framework_UserTimeStream();;
	g_Callbacks = Framework_Callbacks();

	g_D3D10Descs.~AutoDelete();
	g_D3D9Descs.~AutoDelete();
	g_DeviceFactory.~AutoDelete();
	g_Window = Framework_Window();
	g_State = Framework_State();
}

//--------------------------------------------------------------------------------------
// Active task
//--------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(Framework, mainLoop)(
	_In_ HACCEL _accel)
{
	if (TRUE == InterlockedCompareExchange(&g_State.runMainLoop, TRUE, FALSE))
	{
		return S_FALSE;
	}

	const HWND & hWnd = g_Window.hwnd;

	float oneSecond = 0.0f;
	unsigned int oneSecondCount = 0;

	// Now we're ready to receive and process Windows messages.
	MSG msg;

	msg.message = WM_NULL;
	PeekMessage(&msg, nullptr, 0U, 0U, PM_NOREMOVE);

	g_TimeStream.reset();
	while (WM_QUIT != msg.message)
	{
		while (PeekMessage(&msg, nullptr, 0U, 0U, PM_REMOVE))
		{
			// Translate and dispatch the message
			IF_FALSE(TranslateAccelerator(hWnd, _accel, &msg))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}

		IF_FALSE(g_TimeStream.is_Time_Paused())
		{
			// Store the time for the app
			g_TimeStream.update_Time();

			// Animate the scene by calling the app's frame move callback
			CALLBACK_FRAMEMOVE callback_FrameMove =
				g_Callbacks.frameMoveFunc;

			if (callback_FrameMove)
			{
				callback_FrameMove(
					g_TimeStream.get_Time(),
					g_TimeStream.get_ElapsedTime(),
					g_Callbacks.frameMoveFuncUserContext);
			}
		}

		IF_FALSE(g_TimeStream.is_Rendering_Paused())
		{
			render();

			// Update current frame #
			g_TimeStream.update_Frame();

			++g_State.frameCount;
		}

		// If the app called DXUTWasKeyPressed() then do the work 
		// to store the current state of the keys in bLastKeys
		if (g_State.storeLastKeyPressed)
		{
			memcpy(g_LastKeys, g_Keys, 256 * sizeof(short));
		}

		ZeroMemory(g_Keys, 256 * sizeof(short));
	}

	// Cleanup the accelerator table
	if (_accel)
	{
		DestroyAcceleratorTable(_accel);
	}

	return S_OK;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Framework, void, render)(
	_X_ void)
{
	// Render a frame during idle time (no messages are waiting)
	if (g_D3D10Descs)
	{
		CALLBACK_D3D10_FRAME_RENDER callback_FrameRender =
			g_Callbacks.d3d10FrameRenderFunc;

		if (callback_FrameRender)
		{
			callback_FrameRender(
				g_Device.d3d10Device,
				g_TimeStream.get_Time(),
				g_TimeStream.get_ElapsedTime(),
				g_Callbacks.d3d10FrameRenderFuncUserContext);
		}

		// Show the frame on the primary surface.
		HRESULT hr;
		IF_FAILED(hr = g_Device.dxgiSwapChain->Present(0, g_D3D10Descs->presentFlags))
		{
			if (D3DERR_DEVICELOST == hr)
			{
				g_DeviceFactory->resize10(
					&g_Device,
					*g_D3D10Descs,
					&g_Callbacks);
			}
		}
	}
	else if (g_D3D9Descs)
	{
		// If no device created yet because device was lost (ie. another fullscreen exclusive device exists), 
		// then wait and try to create every so often.
		IDirect3DDevice9 * const d3d9Device = g_Device.d3d9Device;

		// Render the scene by calling the app's render callback
		CALLBACK_D3D9_FRAME_RENDER callback_FrameRender =
			g_Callbacks.d3d9FrameRenderFunc;

		if (callback_FrameRender)
		{
			callback_FrameRender(
				d3d9Device,
				g_TimeStream.get_Time(),
				g_TimeStream.get_ElapsedTime(),
				g_Callbacks.d3d9FrameRenderFuncUserContext);
		}

		// Show the frame on the primary surface.
		HRESULT hr;
		IF_FAILED(hr = d3d9Device->Present(nullptr, nullptr, nullptr, nullptr))
		{
			if (D3DERR_DEVICELOST == hr)
			{
				g_DeviceFactory->restore9(
					&g_Device,
					*g_D3D9Descs,
					&g_Callbacks);
			}
		}
	}
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Framework, void, shutdown)(
	_In_ int _exitCode)
{
	const HWND & hWnd = g_Window.hwnd;
	IF_INVALID(hWnd)
	{
		SendMessage(hWnd, WM_CLOSE, 0, 0);
	}

	g_TimeStream.pause_Time(true);
	g_TimeStream.pause_Rendering(true);

	if (g_D3D9Descs)
	{
		if (g_State.setupDevice)
		{
			CALLBACK_D3D9_DEVICE_LOST callback_DeviceLost =
				g_Callbacks.d3d9DeviceLostFunc;

			if (callback_DeviceLost)
			{
				callback_DeviceLost(
					g_Callbacks.d3d9DeviceLostFuncUserContext);
			}

			if (g_Device.d3d9Device)
			{
				CALLBACK_D3D9_DEVICE_DESTROYED callback_DeviceDestroyed =
					g_Callbacks.d3d9DeviceDestroyedFunc;

				if (callback_DeviceDestroyed)
				{
					callback_DeviceDestroyed(
						g_Callbacks.d3d9DeviceDestroyedFuncUserContext);
				}
			}

			g_State.setupDevice = false;
		}

		g_D3D9Descs.~AutoDelete();
	}
	else if (g_D3D10Descs)
	{
		if (g_State.setupDevice)
		{
			CALLBACK_D3D10_SWAPCHAINRELEASING callback_SwapChainReleasing =
				g_Callbacks.d3d10SwapChainReleasingFunc;

			if (callback_SwapChainReleasing)
			{
				callback_SwapChainReleasing(
					g_Callbacks.d3d10SwapChainReleasingFuncUserContext);
			}

			g_Device.dxgiSwapChain->SetFullscreenState(FALSE, 0);

			if (g_Device.d3d10Device)
			{
				g_Device.d3d10Device->ClearState();

				CALLBACK_D3D10_DEVICE_DESTROYED callback_DeviceDestroyed =
					g_Callbacks.d3d10DeviceDestroyedFunc;

				if (callback_DeviceDestroyed)
				{
					callback_DeviceDestroyed(
						g_Callbacks.d3d10DeviceDestroyedFuncUserContext);
				}
			}

			g_State.setupDevice = false;
		}

		g_D3D10Descs.~AutoDelete();
	}

	// all clear
	g_Device = Framework_Device();

	// Restore shortcut keys (Windows key, accessibility shortcuts) to original state
	// This is important to call here if the shortcuts are disabled, 
	// because accessibility setting changes are permanent.
	// This means that if this is not done then the accessibility settings 
	// might not be the same as when the app was started. 
	// If the app crashes without restoring the settings, this is also true so it
	// would be wise to backup/restore the settings from a file so they can be 
	// restored when the crashed app is run again.
	allow_ShortcutKeys(true);
}

//--------------------------------------------------------------------------------------
// Common tasks 
//--------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Framework, void, userSet_ShortcutKeySettings)(
	_In_ BOOL _allowWhenFullscreen,
	_In_ BOOL _allowWhenWindowed)
{
	g_State.allowWhenFullscreen = _allowWhenFullscreen;
	g_State.allowWhenWindowed = _allowWhenWindowed;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Framework, void, userSet_AutoChangeMoniter)(
	_In_ BOOL _autoChange)
{
	g_State.autoChangeAdapter = _autoChange;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Framework, void, userSet_GammaCorrectMode)(
	_In_ BOOL _gammaCorrect)
{
	g_State.is_in_GammaCorrectMode = _gammaCorrect;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Framework, void, userSet_Vsync)(
	_In_ BOOL _vsync)
{
	assert(L"�̱���");
}


//--------------------------------------------------------------------------------------
// General
//--------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Framework, BOOL, clip_Screen)(
	_In_ RECT & _rect,
	_In_ BOOL _windowed)const
{
	// Get the rect of the monitor attached to the adapter
	MONITORINFO miAdapter;
	miAdapter.cbSize = sizeof(MONITORINFO);

	IF_FALSE(GetMonitorInfo(MonitorFromWindow(g_Window.hwnd, MONITOR_DEFAULTTOPRIMARY), &miAdapter))
	{
		return false;
	}

	if (_windowed)
	{
		// Do something reasonable if the BackBuffer size is greater than the monitor size
		int nAdapterMonitorWidth = miAdapter.rcWork.left + miAdapter.rcWork.right;
		int nAdapterMonitorHeight = miAdapter.rcWork.top + miAdapter.rcWork.bottom;

		int empty_x = _rect.left - miAdapter.rcWork.left;
		int empty_y = _rect.top - miAdapter.rcWork.top;

		if (_rect.left < miAdapter.rcWork.left)
		{
			_rect.left = miAdapter.rcWork.left;
			empty_x = 0;
		}

		if (_rect.top < miAdapter.rcWork.top)
		{
			_rect.top = miAdapter.rcWork.top;
			empty_y = 0;
		}

		BOOL clipX = FALSE;
		BOOL clipY = FALSE;

		int cx = _rect.left + _rect.right;
		if (nAdapterMonitorWidth < cx)
		{
			int dw = cx - nAdapterMonitorWidth;
			if (empty_x < dw)
			{
				_rect.left -= empty_x;
				dw -= empty_x;

				clipX = 1;
				if (dw)
				{
					_rect.right -= dw;
					clipX = 2;
				}
			}
			else
			{
				_rect.left -= dw;
				clipX = 1;
			}
		}

		int cy = _rect.top + _rect.bottom;
		if (nAdapterMonitorHeight < cy)
		{
			int dh = cy - nAdapterMonitorHeight;
			if (empty_y < dh)
			{
				_rect.top -= empty_y;
				dh -= empty_y;

				clipY = 4;
				if (dh)
				{
					_rect.bottom -= dh;
					clipY = 8;
				}
			}
			else
			{
				_rect.top -= dh;
				clipY = 4;
			}
		}

		return ADD_FLAG(clipX, clipY);
	}
	else
	{
		_rect = miAdapter.rcMonitor;
		return 16;
	}

	return FALSE;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Framework, BOOL, is_KeyDown)(
	_In_ unsigned char vKey)const
{
	if (0x9f < vKey && vKey < 0xA6)
	{
		// VK_LSHIFT, VK_RSHIFT, VK_LCONTROL, VK_RCONTROL, VK_LMENU, VK_RMENU
		// these keys only are tracked via GetAsyncKeyState()
		return GetAsyncKeyState(vKey) & 0x8000;
	}
	else if (0x00 < vKey && vKey < 0x07 && vKey != 0x03)
	{
		// mouse buttons (VK_BUTTON)
		return is_MouseButtonDown(vKey);
	}
	else
	{
		return g_Keys[vKey];
	}
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Framework, BOOL, was_KeyPressed)(
	_In_ unsigned char vKey)const
{
	return (!g_LastKeys[vKey] && g_Keys[vKey]);
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Framework, BOOL, is_MouseButtonDown)(
	_In_ unsigned char vButton)const
{
	switch (vButton)
	{
	case MK_LBUTTON:
		return g_MouseButtons[0];
	case VK_MBUTTON:
	case MK_MBUTTON:
		return g_MouseButtons[1];
	case MK_RBUTTON:
		return g_MouseButtons[2];
	case VK_XBUTTON1:
	case MK_XBUTTON1:
		return g_MouseButtons[3];
	case VK_XBUTTON2:
	case MK_XBUTTON2:
		return g_MouseButtons[4];
	}

	return false;
}

//--------------------------------------------------------------------------------------
// Grobal function impl
//--------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Framework, Framework_Callbacks *, callbacks)(
	_X_ void)const
{
	return &g_Callbacks;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Framework, Framework_UserTimeStream *, timeStream)(
	_X_ void)const
{
	return &g_TimeStream;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Framework, const Framework_State *, get_State)(
	_X_ void)const
{
	return &g_State;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Framework, const Framework_Window *, get_Window)(
	_X_ void)const
{
	return &g_Window;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Framework, const Framework_Device *, get_Device)(
	_X_ void)const
{
	return &g_Device;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Framework, const D3D9_DEVICE_DESC *, get_Device9Desc)(
	_X_ void)const
{
	return g_D3D9Descs;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Framework, const D3D10_DEVICE_DESC *, get_Device10Desc)(
	_X_ void)const
{
	return g_D3D10Descs;
}

//--------------------------------------------------------------------------------------
IMPL_FUNC_T(void, allow_ShortcutKeys)(
	_In_ BOOL _allowKeys)
{
	if (_allowKeys)
	{
		// Restore StickyKeys/etc to original state and enable Windows key      
		STICKYKEYS sk = g_State.stickyKeys;
		TOGGLEKEYS tk = g_State.toggleKeys;
		FILTERKEYS fk = g_State.filterKeys;

		SystemParametersInfo(SPI_SETSTICKYKEYS, sizeof(STICKYKEYS), &sk, 0);
		SystemParametersInfo(SPI_SETTOGGLEKEYS, sizeof(TOGGLEKEYS), &tk, 0);
		SystemParametersInfo(SPI_SETFILTERKEYS, sizeof(FILTERKEYS), &fk, 0);

		// Remove the keyboard hoook when it isn't needed to prevent any slow down of other apps
		if (g_State.keyboardHook)
		{
			UnhookWindowsHookEx(g_State.keyboardHook);
			g_State.keyboardHook = nullptr;
		}
	}
	else
	{
		// Set low level keyboard hook if haven't already
		IF_INVALID(g_State.keyboardHook)
		{
			HHOOK hKeyboardHook = SetWindowsHookEx(
				WH_KEYBOARD_LL,
				direct3D_LowLevelKeyboardProc,
				GetModuleHandle(nullptr),
				0);

			g_State.keyboardHook = hKeyboardHook;
		}

		// Disable StickyKeys/etc shortcuts but if the accessibility feature is on, 
		// then leave the settings alone as its probably being usefully used

		STICKYKEYS skOff = g_State.stickyKeys;
		if ((skOff.dwFlags & SKF_STICKYKEYSON) == 0)
		{
			// Disable the hotkey and the confirmation
			skOff.dwFlags &= ~SKF_HOTKEYACTIVE;
			skOff.dwFlags &= ~SKF_CONFIRMHOTKEY;

			SystemParametersInfo(SPI_SETSTICKYKEYS, sizeof(STICKYKEYS), &skOff, 0);
		}

		TOGGLEKEYS tkOff = g_State.toggleKeys;
		if ((tkOff.dwFlags & TKF_TOGGLEKEYSON) == 0)
		{
			// Disable the hotkey and the confirmation
			tkOff.dwFlags &= ~TKF_HOTKEYACTIVE;
			tkOff.dwFlags &= ~TKF_CONFIRMHOTKEY;

			SystemParametersInfo(SPI_SETTOGGLEKEYS, sizeof(TOGGLEKEYS), &tkOff, 0);
		}

		FILTERKEYS fkOff = g_State.filterKeys;
		if ((fkOff.dwFlags & FKF_FILTERKEYSON) == 0)
		{
			// Disable the hotkey and the confirmation
			fkOff.dwFlags &= ~FKF_HOTKEYACTIVE;
			fkOff.dwFlags &= ~FKF_CONFIRMHOTKEY;

			SystemParametersInfo(SPI_SETFILTERKEYS, sizeof(FILTERKEYS), &fkOff, 0);
		}
	}
}

//--------------------------------------------------------------------------------------
LRESULT CALLBACK direct3D_WndProc(
	_In_ HWND _hWnd,
	_In_ unsigned int _uMsg,
	_In_ unsigned int _wParam,
	_In_ long _lParam)
{
	g_State.calledMsgProc = true;

	// Consolidate the keyboard messages and pass them to the app's keyboard callback
	if (_uMsg == WM_KEYDOWN || _uMsg == WM_SYSKEYDOWN || _uMsg == WM_KEYUP || _uMsg == WM_SYSKEYUP)
	{
		short bKeyDown = (_uMsg & 0x1) + 1;
		unsigned long dwMask = (1 << 29);
		short bAltDown = ((_lParam & dwMask) != 0);

		g_Keys[(unsigned char)(_wParam & 0xFF)] = bKeyDown;

		CALLBACK_KEYBOARD callback_Keyboard =
			g_Callbacks.keyboardFunc;

		if (callback_Keyboard)
		{
			callback_Keyboard(
				(unsigned char)_wParam,
				bKeyDown,
				bAltDown,
				g_Callbacks.keyboardFuncUserContext);

			return DefWindowProc(_hWnd, _uMsg, _wParam, _lParam);
		}
	}

	// Consolidate the mouse button messages and pass them to the app's mouse callback
	if (_uMsg == WM_LBUTTONDOWN ||
		_uMsg == WM_LBUTTONDBLCLK ||
		_uMsg == WM_MBUTTONDOWN ||
		_uMsg == WM_MBUTTONDBLCLK ||
		_uMsg == WM_RBUTTONDOWN ||
		_uMsg == WM_RBUTTONDBLCLK ||
		_uMsg == WM_XBUTTONDOWN ||
		_uMsg == WM_XBUTTONDBLCLK ||
		_uMsg == WM_MOUSEWHEEL ||
		_uMsg == WM_MOUSEMOVE)
	{
		int xPos = (short)LOWORD(_lParam);
		int yPos = (short)HIWORD(_lParam);

		if (_uMsg == WM_MOUSEWHEEL)
		{
			// WM_MOUSEWHEEL passes screen mouse coords
			// so convert them to client coords
			POINT pt;
			pt.x = xPos; pt.y = yPos;
			ScreenToClient(_hWnd, &pt);
			xPos = pt.x; yPos = pt.y;
		}

		int nMouseWheelDelta = 0;
		if (_uMsg == WM_MOUSEWHEEL)
			nMouseWheelDelta = (short)HIWORD(_wParam);

		int nMouseButtonState = LOWORD(_wParam);
		short bLeftButton = (IS_FLAG(nMouseButtonState, MK_LBUTTON) != 0);
		short bMiddleButton = (IS_FLAG(nMouseButtonState, MK_MBUTTON) != 0);
		short bRightButton = (IS_FLAG(nMouseButtonState, MK_RBUTTON) != 0);
		short bSideButton1 = (IS_FLAG(nMouseButtonState, MK_XBUTTON1) != 0);
		short bSideButton2 = (IS_FLAG(nMouseButtonState, MK_XBUTTON2) != 0);

		g_MouseButtons[0] = bLeftButton;
		g_MouseButtons[1] = bMiddleButton;
		g_MouseButtons[2] = bRightButton;
		g_MouseButtons[3] = bSideButton1;
		g_MouseButtons[4] = bSideButton2;

		CALLBACK_MOUSE callback_Mouse =
			g_Callbacks.mouseFunc;

		if (callback_Mouse)
		{
			callback_Mouse(
				g_MouseButtons,
				5,
				nMouseWheelDelta,
				xPos,
				yPos,
				g_Callbacks.mouseFuncUserContext);

			return DefWindowProc(_hWnd, _uMsg, _wParam, _lParam);
		}
	}
	else if (_uMsg == WM_LBUTTONUP ||
		_uMsg == WM_MBUTTONUP ||
		_uMsg == WM_RBUTTONUP ||
		_uMsg == WM_XBUTTONUP)
	{
		short bLeftButton = IS_FLAG(_uMsg, 0x2);
		short bMiddleButton = IS_FLAG(_uMsg, 0x8) >> 2;
		short bRightButton = IS_FLAG(_uMsg, 0x1) << 1;
		short bSideButton1 = IS_FLAG(_uMsg, 0x4) >> 1;
		short bSideButton2 = bSideButton1;

		g_MouseButtons[0] = bLeftButton;
		g_MouseButtons[1] = bMiddleButton;
		g_MouseButtons[2] = bRightButton;
		g_MouseButtons[3] = bSideButton1;
		g_MouseButtons[4] = bSideButton2;

		CALLBACK_MOUSE callback_Mouse =
			g_Callbacks.mouseFunc;

		if (callback_Mouse)
		{
			callback_Mouse(
				g_MouseButtons,
				5,
				0,
				(short)LOWORD(_lParam),
				(short)HIWORD(_lParam),
				g_Callbacks.mouseFuncUserContext);

			return DefWindowProc(_hWnd, _uMsg, _wParam, _lParam);
		}
	}

	if (_uMsg == WM_SIZE)
	{
		if (SIZE_MINIMIZED == _wParam)
		{
			g_Window.minimizedSize = true;

			// Pause while we're minimized
			g_TimeStream.pause_Rendering(true);
		}
		else
		{
			IF_FALSE(g_State.calledModifiedBackBuffer)
			{
				unsigned int width = LOWORD(_lParam);
				unsigned int height = HIWORD(_lParam);

				if (width == 0 || height == 0)
				{

				}
				else if (SIZE_RESTORED == _wParam)
				{
					if (g_State.autoChangeAdapter)
					{
						g_Framework.transform(
							g_Window.windowed,
							width,
							height);
					}
				}
				else if (SIZE_MAXIMIZED == _wParam)
				{
					if (g_Window.windowed)
					{
						g_Framework.transform(
							g_Window.windowed,
							width,
							height);
					}

					g_Window.maximizedSize = true;
				}
			}

			if (g_Window.minimizedSize)
			{
				g_Window.minimizedSize = false;

				// pause_Rendering(true) in SIZE_MINIMIZED
				g_TimeStream.pause_Rendering(false);
			}
			else if (g_Window.maximizedSize)
			{
				g_Window.maximizedSize = false;
			}
		}
	}

	// Pass all messages to the app's MsgProc callback, and don't 
	// process further messages if the apps says not to.
	CALLBACK_MSGPROC callback_MsgProc =
		g_Callbacks.windowMsgFunc;

	if (callback_MsgProc)
	{
		BOOL bNoFurtherProcessing = false;
		LRESULT nResult = callback_MsgProc(
			&bNoFurtherProcessing,
			_hWnd,
			_uMsg,
			_wParam,
			_lParam,
			g_Callbacks.windowMsgFuncUserContext);

		if (bNoFurtherProcessing)
		{
			return nResult;
		}
	}

	switch (_uMsg)
	{
	case WM_PAINT:
		// Handle paint messages when the app is paused
		if (g_TimeStream.is_Rendering_Paused())
		{
			g_Framework.render();
		}
		break;

	case WM_GETMINMAXINFO:
		((MINMAXINFO*)_lParam)->ptMinTrackSize.x = 200;
		((MINMAXINFO*)_lParam)->ptMinTrackSize.y = 200;
		break;

	case WM_ACTIVATEAPP:
		if (_wParam == TRUE && g_State.runMainLoop) // Handle only if previously not active 
		{
			// Upon returning to this app, potentially disable shortcut keys 
			// (Windows key, accessibility shortcuts)
			allow_ShortcutKeys(g_Window.windowed);
		}
		else if (_wParam == FALSE && g_State.runMainLoop) // Handle only if previously active 
		{
			// Restore shortcut keys (Windows key, accessibility shortcuts) to original state
			//
			// This is important to call here if the shortcuts are disabled, 
			// because if this is not done then the Windows key will continue to 
			// be disabled while this app is running which is very bad.
			// If the app crashes, the Windows key will return to normal.
			allow_ShortcutKeys(true);
		}
		break;

	case WM_MENUCHAR:
		// A menu is active and the user presses a key that does not correspond to any mnemonic or accelerator key
		// So just ignore and don't beep
		return MAKELRESULT(0, MNC_CLOSE);
		break;

	case WM_NCHITTEST:
		// Prevent the user from selecting the menu in full screen mode
		IF_FALSE(g_Window.windowed)
			return HTCLIENT;
		break;

	case WM_POWERBROADCAST:
		switch (_wParam)
		{
#ifndef PBT_APMQUERYSUSPEND
#define PBT_APMQUERYSUSPEND 0x0000
#endif
		case PBT_APMQUERYSUSPEND:
			// At this point, the app should save any data for open
			// network connections, files, etc., and prepare to go into
			// a suspended mode.  The app can use the MsgProc callback
			// to handle this if desired.
			return true;

#ifndef PBT_APMRESUMESUSPEND
#define PBT_APMRESUMESUSPEND 0x0007
#endif
		case PBT_APMRESUMESUSPEND:
			// At this point, the app should recover any data, network
			// connections, files, etc., and resume running from when
			// the app was suspended. The app can use the MsgProc callback
			// to handle this if desired.

			// QPC may lose consistency when suspending, so reset the timer
			// upon resume.
			g_TimeStream.reset();
			return true;
		}
		break;

	case WM_SYSCOMMAND:
		// Prevent moving/sizing in full screen mode
		switch ((_wParam & 0xFFF0))
		{
		case SC_MOVE:
		case SC_SIZE:
		case SC_MAXIMIZE:
		case SC_KEYMENU:
			IF_FALSE(g_Window.windowed)
				return 0;
			break;
		}
		break;

	case WM_SYSKEYDOWN:
		g_Framework.destroy();
		break;

	case WM_KEYDOWN:

		if (_wParam == VK_ESCAPE)
		{
			if (g_Window.windowed)
			{
				if (MessageBox(_hWnd, L"������ �����Ͻðڽ��ϱ�? ", L"����!!", MB_YESNO) == IDYES)
				{
					SendMessage(_hWnd, WM_CLOSE, 0, 0);
				}
			}
			else
			{
				g_Framework.transform(true);
			}
		}
		else if (_wParam == VK_F5)
		{
			if (g_Window.windowed)
			{
				if (MessageBox(_hWnd, L"��üȭ������ �Ͻðڽ��ϱ�? ", L"����!!", MB_YESNO) == IDYES)
				{
					g_Framework.transform(false);
				}
			}
		}

		break;

	case WM_CLOSE:
	{
					 HMENU hMenu;
					 if (hMenu = GetMenu(_hWnd))
					 {
						 DestroyMenu(hMenu);
					 }

					 DestroyWindow(_hWnd);

					 UnregisterClass(L"Direct3DWindowClass", nullptr);

					 g_Window.hwnd = nullptr;
					 g_State.setupWindow = false;

					 return 0;
	}

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	g_State.calledMsgProc = false;

	// Don't allow the F10 key to act as a shortcut to the menu bar
	// by not passing these messages to the DefWindowProc only when
	// there's no menu present
	if (nullptr == g_Window.menu && (_uMsg == WM_SYSKEYDOWN || _uMsg == WM_SYSKEYUP) && _wParam == VK_F10)
	{
		return 0;
	}
	else
	{
		return DefWindowProc(_hWnd, _uMsg, _wParam, _lParam);
	}
}

//--------------------------------------------------------------------------------------
LRESULT CALLBACK direct3D_LowLevelKeyboardProc(
	_In_ int _code,
	_In_ WPARAM _wParam,
	_In_ LPARAM _lParam)
{
	// do not process message 
	if (_code < 0 || _code != HC_ACTION)
	{
		return CallNextHookEx(
			g_State.keyboardHook,
			_code,
			_wParam,
			_lParam);
	}

	BOOL bEatKeystroke = false;
	KBDLLHOOKSTRUCT* p = (KBDLLHOOKSTRUCT*)_lParam;
	switch (_wParam)
	{
	case WM_KEYDOWN:
	case WM_KEYUP:
	{
					 bEatKeystroke = p->vkCode == VK_LWIN || p->vkCode == VK_RWIN;
					 break;
	}
	}

	if (bEatKeystroke)
	{
		return 1;
	}
	else
	{
		return CallNextHookEx(
			g_State.keyboardHook,
			_code,
			_wParam,
			_lParam);
	}
}

//--------------------------------------------------------------------------------------
// open value 
//--------------------------------------------------------------------------------------

// ���� : 
Framework hsdk::framework::g_Framework;

// ���� : 
Framework_UserTimeStream & hsdk::framework::g_Framework_TimeStream = g_TimeStream;

// ���� : you can read / write
Framework_Callbacks & hsdk::framework::g_Framework_Callbacks = g_Callbacks;

// ���� : just only read / do not write force
const Framework_State & hsdk::framework::g_Direct3D_State = g_State;

// ���� : just only read / do not write force
const Framework_Window & hsdk::framework::g_Framework_Window = g_Window;

// ���� : just only read / do not write force
const Framework_Device & hsdk::framework::g_Framework_Device = g_Device;