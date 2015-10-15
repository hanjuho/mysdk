#include "common.h"

//--------------------------------------------------------------------------------------
IMPL_FUNC_T(void, hsdk::direct3d::direct3D_OutputDebugString)(
	/* [r] */ const wchar_t * _strMsg, ...)
{
#if defined(DEBUG) || defined(_DEBUG)
	wchar_t strBuffer[512];

	va_list args;
	va_start(args, _strMsg);
	vswprintf_s(strBuffer, 512, _strMsg, args);
	strBuffer[511] = L'\0';
	va_end(args);

	OutputDebugString(strBuffer);
#else
	UNREFERENCED_PARAMETER(strMsg);
#endif
}

//--------------------------------------------------------------------------------------
IMPL_FUNC_T(BOOL, hsdk::direct3d::is_NextArg)(
	/* [r/w] */ wchar_t * & _strCmdLine,
	/* [r] */ const wchar_t * _strArg)
{
	int nArgLen = (int)wcslen(_strArg);
	int nCmdLen = (int)wcslen(_strCmdLine);

	if (nCmdLen >= nArgLen &&
		_wcsnicmp(_strCmdLine, _strArg, nArgLen) == 0 &&
		(_strCmdLine[nArgLen] == 0 || _strCmdLine[nArgLen] == L':'))
	{
		_strCmdLine += nArgLen;
		return true;
	}

	return false;
}

//--------------------------------------------------------------------------------------
IMPL_FUNC_T(BOOL, hsdk::direct3d::get_CmdParam)(
	/* [r/w] */ wchar_t * & _strCmdLine,
	/* [r/w] */ wchar_t * _strFlag)
{
	if (*_strCmdLine == L':')
	{
		_strCmdLine++; // Skip ':'

		// Place nullptr terminator in strFlag after current token
		wcscpy_s(_strFlag, MAX_PATH, _strCmdLine);
		wchar_t * strSpace = _strFlag;

		while (*strSpace && (*strSpace > L' '))
		{
			strSpace++;
		}

		*strSpace = 0;

		// Update strCmdLine
		_strCmdLine += wcslen(_strFlag);
		return true;
	}
	else
	{
		_strFlag[0] = 0;
		return false;
	}
}

//--------------------------------------------------------------------------------------
IMPL_FUNC_T(void, hsdk::direct3d::parse_CommandLine)(
	/* [w] */ Direct3D_INIT_DESC & _initDesc,
	/* [r] */ __inout const wchar_t * _strCommandLine,
	/* [r] */ BOOL _ignoreFirstCommand)
{
	wchar_t * strCmdLine;
	wchar_t strFlag[MAX_PATH];

	int nNumArgs;
	int iArgStart = 0;
	wchar_t ** pstrArgList = CommandLineToArgvW(_strCommandLine, &nNumArgs);

	if (_ignoreFirstCommand)
	{
		iArgStart = 1;
	}

	for (int iArg = iArgStart; iArg < nNumArgs; iArg++)
	{
		strCmdLine = pstrArgList[iArg];

		// Handle flag args
		if (*strCmdLine == L'/' || *strCmdLine == L'-')
		{
			strCmdLine++;

			if (is_NextArg(strCmdLine, L"forceapi"))
			{
				if (get_CmdParam(strCmdLine, strFlag))
				{
					int nAPIVersion = _wtoi(strFlag);
					_initDesc.forceAPI = nAPIVersion;
					continue;
				}
			}

			if (is_NextArg(strCmdLine, L"adapter"))
			{
				if (get_CmdParam(strCmdLine, strFlag))
				{
					int nAdapter = _wtoi(strFlag);
					_initDesc.adapterOrdinal = nAdapter;
					continue;
				}
			}

			if (is_NextArg(strCmdLine, L"output"))
			{
				if (get_CmdParam(strCmdLine, strFlag))
				{
					int Output = _wtoi(strFlag);
					_initDesc.output = Output;
					continue;
				}
			}

			if (is_NextArg(strCmdLine, L"fullscreen"))
			{
				_initDesc.fullScreen = true;
				continue;
			}

			if (is_NextArg(strCmdLine, L"forcehal"))
			{
				_initDesc.forceHAL = true;
				continue;
			}

			if (is_NextArg(strCmdLine, L"forceref"))
			{
				_initDesc.forceREF = true;
				continue;
			}

			if (is_NextArg(strCmdLine, L"forcewarp"))
			{
				_initDesc.forceWARP = true;
				continue;
			}

			if (is_NextArg(strCmdLine, L"forcepurehwvp"))
			{
				_initDesc.forcePureHWVP = true;
				continue;
			}

			if (is_NextArg(strCmdLine, L"forcehwvp"))
			{
				_initDesc.forceHWVP = true;
				continue;
			}

			if (is_NextArg(strCmdLine, L"forceswvp"))
			{
				_initDesc.forceSWVP = true;
				continue;
			}

			if (is_NextArg(strCmdLine, L"forcevsync"))
			{
				if (get_CmdParam(strCmdLine, strFlag))
				{
					int nOn = _wtoi(strFlag);
					_initDesc.forceVsync = nOn;
					continue;
				}
			}

			if (is_NextArg(strCmdLine, L"width"))
			{
				if (get_CmdParam(strCmdLine, strFlag))
				{
					int nWidth = _wtoi(strFlag);
					_initDesc.width = nWidth;
					continue;
				}
			}

			if (is_NextArg(strCmdLine, L"height"))
			{
				if (get_CmdParam(strCmdLine, strFlag))
				{
					int nHeight = _wtoi(strFlag);
					_initDesc.height = nHeight;
					continue;
				}
			}

			if (is_NextArg(strCmdLine, L"startx"))
			{
				if (get_CmdParam(strCmdLine, strFlag))
				{
					int nX = _wtoi(strFlag);
					_initDesc.startX = nX;
					continue;
				}
			}

			if (is_NextArg(strCmdLine, L"starty"))
			{
				if (get_CmdParam(strCmdLine, strFlag))
				{
					int nY = _wtoi(strFlag);
					_initDesc.startY = nY;
					continue;
				}
			}

			if (is_NextArg(strCmdLine, L"constantframetime"))
			{
				float fTimePerFrame;
				if (get_CmdParam(strCmdLine, strFlag))
				{
					fTimePerFrame = (float)wcstod(strFlag, nullptr);
				}
				else
				{
					fTimePerFrame = 0.0333f;
				}

				_initDesc.constantFrameTime = true;
				_initDesc.constantTimePerFrame = fTimePerFrame;
				continue;
			}

			if (is_NextArg(strCmdLine, L"quitafterframe"))
			{
				if (get_CmdParam(strCmdLine, strFlag))
				{
					int nFrame = _wtoi(strFlag);
					_initDesc.quitAfterFrame = nFrame;
					continue;
				}
			}

			if (is_NextArg(strCmdLine, L"nostats"))
			{
				_initDesc.noStats = true;
				continue;
			}

			if (is_NextArg(strCmdLine, L"relaunchmce") && GetSystemMetrics(SM_MEDIACENTER) != 0)
			{
				_initDesc.relaunchMCE = true;
				continue;
			}

			if (is_NextArg(strCmdLine, L"automation"))
			{
				_initDesc.automation = true;
				continue;
			}
		}

		// Unrecognized flag
		wcscpy_s(strFlag, MAX_PATH, strCmdLine);
		WCHAR* strSpace = strFlag;

		while (*strSpace && (*strSpace > L' '))
		{
			strSpace++;
		}

		*strSpace = 0;
		strCmdLine += wcslen(strFlag);

		direct3D_OutputDebugString(L"Unrecognized flag: %s", strFlag);
	}

	LocalFree(pstrArgList);
}

//--------------------------------------------------------------------------------------
IMPL_FUNC_T(hsdk::direct3d::D3D9_DEVICE_DESC, hsdk::direct3d::initialize_DeviceDesc)(
	/* [r] */ HWND _hwnd,
	/* [r] */ BOOL _windowed,
	/* [r] */ int _width,
	/* [r] */ int _height)
{
	// Override with settings from the command line
	return{
		// adapterOrdinal
		D3DADAPTER_DEFAULT,

		// deviceType
		D3DDEVTYPE_HAL,

		// adapterFormat
		D3DFMT_UNKNOWN,

		// behaviorFlags
		D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_PUREDEVICE,

		// pp
		{
			// BackBufferWidth
			_width,

			// BackBufferHeight
			_height,

			// BackBufferFormat
			D3DFMT_A8R8G8B8,

			// BackBufferCount			
			2,

			// MultiSampleType
			D3DMULTISAMPLE_NONE,

			// MultiSampleQuality
			0,

			// SwapEffect
			D3DSWAPEFFECT_DISCARD,

			// hDeviceWindow
			_hwnd,

			// Windowed	
			_windowed,

			// EnableAutoDepthStencil
			TRUE,

			// AutoDepthStencilFormat
			D3DFMT_D24S8,

			// Flags
			D3DPRESENTFLAG_DISCARD_DEPTHSTENCIL,

			// FullScreen_RefreshRateInHz
			0,

			// PresentationInterval
			D3DPRESENT_INTERVAL_DEFAULT
		}
	};
}

//--------------------------------------------------------------------------------------
IMPL_FUNC_T(DXGI_FORMAT, hsdk::direct3d::convert_Format_D3D9ToDXGI)(
	/* [r] */ D3DFORMAT _format)
{
	switch (_format)
	{
	case D3DFMT_UNKNOWN:

		return DXGI_FORMAT_UNKNOWN;

	case D3DFMT_R8G8B8:
	case D3DFMT_A8R8G8B8:
	case D3DFMT_X8R8G8B8:

		return DXGI_FORMAT_R8G8B8A8_UNORM_SRGB;

	case D3DFMT_R5G6B5:

		return DXGI_FORMAT_B5G6R5_UNORM;

	case D3DFMT_X1R5G5B5:
	case D3DFMT_A1R5G5B5:

		return DXGI_FORMAT_B5G5R5A1_UNORM;

	case D3DFMT_A4R4G4B4:

		return DXGI_FORMAT_R8G8B8A8_UNORM;

	case D3DFMT_R3G3B2:

		return DXGI_FORMAT_R8G8B8A8_UNORM;

	case D3DFMT_A8:

		return DXGI_FORMAT_A8_UNORM;

	case D3DFMT_A8R3G3B2:

		return DXGI_FORMAT_R8G8B8A8_UNORM;

	case D3DFMT_X4R4G4B4:

		return DXGI_FORMAT_R8G8B8A8_UNORM;

	case D3DFMT_A2B10G10R10:

		return DXGI_FORMAT_R10G10B10A2_UNORM;

	case D3DFMT_A8B8G8R8:
	case D3DFMT_X8B8G8R8:

		return DXGI_FORMAT_B8G8R8A8_UNORM;

	case D3DFMT_G16R16:

		return DXGI_FORMAT_R16G16_UNORM;

	case D3DFMT_A2R10G10B10:

		return DXGI_FORMAT_R10G10B10A2_UNORM;

	case D3DFMT_A16B16G16R16:

		return DXGI_FORMAT_R16G16B16A16_UNORM;

	case D3DFMT_R16F:

		return DXGI_FORMAT_R16_FLOAT;

	case D3DFMT_G16R16F:

		return DXGI_FORMAT_R16G16_FLOAT;

	case D3DFMT_A16B16G16R16F:

		return DXGI_FORMAT_R16G16B16A16_FLOAT;

	case D3DFMT_R32F:

		return DXGI_FORMAT_R32_FLOAT;

	case D3DFMT_G32R32F:

		return DXGI_FORMAT_R32G32_FLOAT;

	case D3DFMT_A32B32G32R32F:

		return DXGI_FORMAT_R32G32B32A32_FLOAT;

	case D3DFMT_D24S8:

		return DXGI_FORMAT_D24_UNORM_S8_UINT;

	}

	return DXGI_FORMAT_UNKNOWN;
}

//--------------------------------------------------------------------------------------
IMPL_FUNC_T(D3D10_DRIVER_TYPE, hsdk::direct3d::convert_DriverType_D3D9ToDXGI)(
	/* [r] */ D3DDEVTYPE _type)
{
	switch (_type)
	{
	case D3DDEVTYPE_HAL:

		return D3D10_DRIVER_TYPE_HARDWARE;

	case D3DDEVTYPE_REF:

		return D3D10_DRIVER_TYPE_REFERENCE;

	case D3DDEVTYPE_SW:

		return D3D10_DRIVER_TYPE_SOFTWARE;

	case D3DDEVTYPE_NULLREF:

		return D3D10_DRIVER_TYPE_NULL;

	}

	return D3D10_DRIVER_TYPE_NULL;
}

//--------------------------------------------------------------------------------------
IMPL_FUNC_T(D3DDEVTYPE, hsdk::direct3d::convert_DriverType_DXGITOD3D9)(
	/* [r] */ D3D10_DRIVER_TYPE _type)
{
	switch (_type)
	{
	case D3D10_DRIVER_TYPE_HARDWARE:

		return D3DDEVTYPE_HAL;

	case D3D10_DRIVER_TYPE_REFERENCE:

		return D3DDEVTYPE_REF;

	case D3D10_DRIVER_TYPE_SOFTWARE:

		return D3DDEVTYPE_SW;

	case D3D10_DRIVER_TYPE_NULL:

		return D3DDEVTYPE_NULLREF;
	}

	return D3DDEVTYPE_NULLREF;
}

//--------------------------------------------------------------------------------------
IMPL_FUNC_T(void, hsdk::direct3d::convert_DeviceDesc_9to10)(
	/* [w] */ D3D10_DEVICE_DESC & _out,
	/* [r] */ const D3D9_DEVICE_DESC & _in)
{
	_out.adapterOrdinal = _in.adapterOrdinal;
	_out.driverType = convert_DriverType_D3D9ToDXGI(_in.deviceType);

	_out.sd.BufferDesc.Width = _in.pp.BackBufferWidth;
	_out.sd.BufferDesc.Height = _in.pp.BackBufferHeight;

	_out.sd.BufferDesc.RefreshRate.Numerator = 0;
	_out.sd.BufferDesc.RefreshRate.Denominator = 0;
	
	_out.sd.BufferDesc.Format = convert_Format_D3D9ToDXGI(_in.pp.BackBufferFormat);

	if (_in.pp.MultiSampleType == D3DMULTISAMPLE_NONE)
	{
		_out.sd.SampleDesc.Count = 1;
		_out.sd.SampleDesc.Quality = 0;
	}
	else
	{
		_out.sd.SampleDesc.Count = _in.pp.MultiSampleType;
		_out.sd.SampleDesc.Quality = _in.pp.MultiSampleQuality;
	}	

	_out.sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	_out.sd.BufferCount = _in.pp.BackBufferCount;

	_out.sd.OutputWindow = _in.pp.hDeviceWindow;
	_out.sd.Windowed = _in.pp.Windowed;

	_out.autoCreateDepthStencil = _in.pp.EnableAutoDepthStencil;
	_out.autoDepthStencilFormat = convert_Format_D3D9ToDXGI(_in.pp.AutoDepthStencilFormat);

#if defined(DEBUG) || defined(_DEBUG)
	_out.createFlags = D3D10_CREATE_DEVICE_DEBUG;
#else
	pOut->CreateFlags = 0;
#endif

	switch (_in.pp.PresentationInterval)
	{
	case D3DPRESENT_INTERVAL_IMMEDIATE:
		_out.syncInterval = 0;
		break;
	case D3DPRESENT_INTERVAL_ONE:
		_out.syncInterval = 1;
		break;
	case D3DPRESENT_INTERVAL_TWO:
		_out.syncInterval = 2;
		break;
	case D3DPRESENT_INTERVAL_THREE:
		_out.syncInterval = 3;
		break;
	case D3DPRESENT_INTERVAL_FOUR:
		_out.syncInterval = 4;
		break;

	case D3DPRESENT_INTERVAL_DEFAULT:
	default:
		_out.syncInterval = 1;
		break;
	}
}

//--------------------------------------------------------------------------------------
IMPL_FUNC_T(void, hsdk::direct3d::build_OptimalDeviceDesc)(
	/* [w] */ D3D9_DEVICE_DESC & _out,
	/* [r] */ const D3D9_DEVICE_DESC & _in,
	/* [r] */ const Direct3D_DeviceMatchOptions & _matOpt)
{
	//---------------------
	// Adapter ordinal
	//---------------------   
	_out.adapterOrdinal = _matOpt.eAdapterOrdinal == IGNORE_INPUT
		? D3DADAPTER_DEFAULT : _in.adapterOrdinal;

	//---------------------
	// Device type
	//---------------------
	_out.deviceType = _matOpt.eDeviceType == IGNORE_INPUT
		? D3DDEVTYPE_HAL : _in.deviceType;

	//---------------------
	// Windowed
	//---------------------
	_out.pp.Windowed = _matOpt.eFullScreen == IGNORE_INPUT
		? TRUE : _in.pp.Windowed;

	//---------------------
	// Adapter format
	//---------------------
	_out.adapterFormat = _matOpt.eAdapterFormat == IGNORE_INPUT
		? D3DFMT_X8R8G8B8 : _in.adapterFormat;

	//---------------------
	// Vertex processing
	//---------------------
	_out.behaviorFlags = _matOpt.eVertexProcessing == IGNORE_INPUT
		? D3DCREATE_HARDWARE_VERTEXPROCESSING : _in.behaviorFlags;

	//---------------------
	// Resolution
	//---------------------
	if (_matOpt.eResolution == IGNORE_INPUT)
	{
		_out.pp.BackBufferWidth = 640;
		_out.pp.BackBufferHeight = 480;
	}
	else
	{
		_out.pp.BackBufferWidth = _in.pp.BackBufferWidth;
		_out.pp.BackBufferHeight = _in.pp.BackBufferHeight;
	}

	//---------------------
	// Back buffer format
	//---------------------
	_out.pp.BackBufferFormat = _matOpt.eBackBufferFormat == IGNORE_INPUT
		? D3DFMT_X8R8G8B8 : _in.pp.BackBufferFormat;

	//---------------------
	// Back buffer count
	//---------------------
	_out.pp.BackBufferCount = _matOpt.eBackBufferCount == IGNORE_INPUT
		? 1 : _in.pp.BackBufferCount;

	//---------------------
	// Multisample
	//---------------------
	if (_matOpt.eMultiSample == IGNORE_INPUT)
	{
		// Default to no multisampling 
		_out.pp.MultiSampleType = D3DMULTISAMPLE_NONE;
		_out.pp.MultiSampleQuality = 0;
	}
	else
	{
		_out.pp.MultiSampleType = _in.pp.MultiSampleType;
		_out.pp.MultiSampleQuality = _in.pp.MultiSampleQuality;
	}

	//---------------------
	// Swap effect
	//---------------------
	_out.pp.SwapEffect = _matOpt.eSwapEffect == IGNORE_INPUT
		? D3DSWAPEFFECT_DISCARD : _in.pp.SwapEffect;

	//---------------------
	// Depth stencil 
	//---------------------
	_out.pp.AutoDepthStencilFormat =
		_matOpt.eDepthFormat == IGNORE_INPUT &&
		_matOpt.eStencilFormat == IGNORE_INPUT
		? D3DFMT_D24S8 : _in.pp.AutoDepthStencilFormat;

	//---------------------
	// Present flags
	//---------------------
	_out.pp.Flags = _matOpt.ePresentFlags == IGNORE_INPUT
		? D3DPRESENTFLAG_DISCARD_DEPTHSTENCIL : _in.pp.Flags;

	//---------------------
	// Refresh rate
	//---------------------
	_out.pp.FullScreen_RefreshRateInHz = _matOpt.eRefreshRate == IGNORE_INPUT
		? 0 : _in.pp.FullScreen_RefreshRateInHz;

	//---------------------
	// Present interval
	//---------------------
	// For windowed and fullscreen, default to D3DPRESENT_INTERVAL_DEFAULT
	// which will wait for the vertical retrace period to prevent tearing.
	// For benchmarking, use D3DPRESENT_INTERVAL_IMMEDIATE which will
	// will wait not for the vertical retrace period but may introduce tearing.
	_out.pp.PresentationInterval = _matOpt.ePresentInterval == IGNORE_INPUT
		? D3DPRESENT_INTERVAL_DEFAULT : _in.pp.PresentationInterval;
}

//--------------------------------------------------------------------------------------
IMPL_FUNC_T(void, hsdk::direct3d::build_OptimalDeviceDesc)(
	/* [w] */ D3D10_DEVICE_DESC & _out,
	/* [r] */ const D3D10_DEVICE_DESC & _in,
	/* [r] */ const Direct3D_DeviceMatchOptions & _matOpt)
{
	//---------------------
	// Adapter ordinal
	//---------------------
	if (_matOpt.eAdapterOrdinal == IGNORE_INPUT)
		_out.adapterOrdinal = 0;
	else
		_out.adapterOrdinal = _in.adapterOrdinal;

	//---------------------
	// Device type
	//---------------------
	if (_matOpt.eDeviceType == IGNORE_INPUT)
		_out.driverType = D3D10_DRIVER_TYPE_HARDWARE;
	else
		_out.driverType = _in.driverType;

	//---------------------
	// Windowed
	//---------------------
	if (_matOpt.eFullScreen == IGNORE_INPUT)
		_out.sd.Windowed = FALSE;
	else
		_out.sd.Windowed = _in.sd.Windowed;

	//---------------------
	// Output #
	//---------------------
	if (_matOpt.eOutput == IGNORE_INPUT)
		_out.output = 0;
	else
		_out.output = _in.output;

	//---------------------
	// Create flags
	//---------------------
	_out.createFlags = _in.createFlags;

	//---------------------
	// Resolution
	//---------------------
	if (_matOpt.eResolution == IGNORE_INPUT)
	{
		// If windowed, default to 640x480
		// If fullscreen, default to the desktop res for quick mode change
		_out.sd.BufferDesc.Width = 640;
		_out.sd.BufferDesc.Height = 480;
	}
	else
	{
		_out.sd.BufferDesc.Width = _in.sd.BufferDesc.Width;
		_out.sd.BufferDesc.Height = _in.sd.BufferDesc.Height;
	}

	//---------------------
	// Back buffer format
	//---------------------
	if (_matOpt.eBackBufferFormat == IGNORE_INPUT)
		// Default to match the adapter format
		_out.sd.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM_SRGB;
	else
		_out.sd.BufferDesc.Format = _in.sd.BufferDesc.Format;

	//---------------------
	// Back buffer usage
	//---------------------
	_out.sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;

	//---------------------
	// Back buffer count
	//---------------------
	if (_matOpt.eBackBufferCount == IGNORE_INPUT)
		_out.sd.BufferCount = 2; // Default to triple buffering for perf gain
	else
		_out.sd.BufferCount = _in.sd.BufferCount;

	//---------------------
	// Multisample
	//---------------------
	if (_matOpt.eMultiSample == IGNORE_INPUT)
	{
		// Default to no multisampling 
		_out.sd.SampleDesc.Count = 1;
		_out.sd.SampleDesc.Quality = 0;
	}
	else
	{
		_out.sd.SampleDesc.Count = _in.sd.SampleDesc.Count;
		_out.sd.SampleDesc.Quality = _in.sd.SampleDesc.Quality;
	}

	//---------------------
	// Swap effect
	//---------------------
	if (_matOpt.eSwapEffect == IGNORE_INPUT)
		_out.sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	else
		_out.sd.SwapEffect = _in.sd.SwapEffect;

	//---------------------
	// Depth stencil 
	//---------------------
	if (_matOpt.eDepthFormat == IGNORE_INPUT &&
		_matOpt.eStencilFormat == IGNORE_INPUT)
	{
		_out.autoCreateDepthStencil = TRUE;
		_out.autoDepthStencilFormat = DXGI_FORMAT_D24_UNORM_S8_UINT;
	}
	else
	{
		_out.autoCreateDepthStencil = _in.autoCreateDepthStencil;
		_out.autoDepthStencilFormat = _in.autoDepthStencilFormat;
	}

	//---------------------
	// Present flags
	//---------------------
	if (_matOpt.ePresentFlags == IGNORE_INPUT)
		_out.presentFlags = 0;
	else
		_out.presentFlags = _in.presentFlags;

	//---------------------
	// Refresh rate
	//---------------------
	if (_matOpt.eRefreshRate == IGNORE_INPUT)
	{
		_out.sd.BufferDesc.RefreshRate.Numerator = 0;
		_out.sd.BufferDesc.RefreshRate.Denominator = 0;
	}
	else
		_out.sd.BufferDesc.RefreshRate = _in.sd.BufferDesc.RefreshRate;

	//---------------------
	// Present interval
	//---------------------
	if (_matOpt.ePresentInterval == IGNORE_INPUT)
	{
		// For windowed and fullscreen, default to 1 which will
		// wait for the vertical retrace period to prevent tearing.
		// For benchmarking, use 0 which will not wait for the
		// vertical retrace period but may introduce tearing.
		_out.syncInterval = 1;
	}
	else
	{
		_out.syncInterval = _in.syncInterval;
	}
}

//--------------------------------------------------------------------------------------
IMPL_FUNC_T(BOOL, hsdk::direct3d::is_ResetDevice)(
	/* [w] */ const Direct3D_DeviceDescs & _oldDesc,
	/* [w] */ const Direct3D_DeviceDescs & _newDesc)
{
	if (_oldDesc.version == NONE_DEVICE)
	{
		return false;
	}

	if (_oldDesc.version != _newDesc.version)
	{
		return false;
	}

	if (_newDesc.version == D3D9_DEVICE)
	{
		if ((_oldDesc.d3d9DeviceDesc.adapterOrdinal == _newDesc.d3d9DeviceDesc.adapterOrdinal) &&
			(_oldDesc.d3d9DeviceDesc.deviceType == _newDesc.d3d9DeviceDesc.deviceType) &&
			(_oldDesc.d3d9DeviceDesc.behaviorFlags == _newDesc.d3d9DeviceDesc.behaviorFlags))
		{
			return true;
		}

		return false;
	}
	else
	{
		if ((_oldDesc.d3d10DeviceDesc.adapterOrdinal == _newDesc.d3d10DeviceDesc.adapterOrdinal) &&
			(_oldDesc.d3d10DeviceDesc.driverType == _newDesc.d3d10DeviceDesc.driverType) &&
			(_oldDesc.d3d10DeviceDesc.createFlags == _newDesc.d3d10DeviceDesc.createFlags) &&
			(_oldDesc.d3d10DeviceDesc.sd.SampleDesc.Count == _newDesc.d3d10DeviceDesc.sd.SampleDesc.Count) &&
			(_oldDesc.d3d10DeviceDesc.sd.SampleDesc.Quality == _newDesc.d3d10DeviceDesc.sd.SampleDesc.Quality))
			return true;

		return false;
	}
}

//--------------------------------------------------------------------------------------
IMPL_FUNC_T(BOOL, hsdk::direct3d::is_WindowedFromDesc)(
	/* [r] */ const Direct3D_DeviceDescs & _desc)
{
	if (_desc.version == D3D9_DEVICE)
	{
		return _desc.d3d9DeviceDesc.pp.Windowed;
	}
	else if (_desc.version == D3D10_DEVICE)
	{
		return _desc.d3d10DeviceDesc.sd.Windowed;
	}

	return false;
}

//--------------------------------------------------------------------------------------
IMPL_FUNC_T(unsigned int, hsdk::direct3d::get_WidthFromDesc)(
	/* [r] */ const Direct3D_DeviceDescs & _desc)
{
	switch (_desc.version)
	{
	case D3D9_DEVICE:
		return _desc.d3d9DeviceDesc.pp.BackBufferWidth;
	case D3D10_DEVICE:
		return _desc.d3d10DeviceDesc.sd.BufferDesc.Width;
	default:
		return 0;
	}
}

//--------------------------------------------------------------------------------------
IMPL_FUNC_T(unsigned int, hsdk::direct3d::get_HeightFromDesc)(
	/* [r] */ const Direct3D_DeviceDescs & _desc)
{
	switch (_desc.version)
	{
	case D3D9_DEVICE:
		return _desc.d3d9DeviceDesc.pp.BackBufferHeight;
	case D3D10_DEVICE:
		return _desc.d3d10DeviceDesc.sd.BufferDesc.Height;
	default:
		return 0;
	}
}