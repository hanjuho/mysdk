#pragma once



#include "common.h"
#include <vector>



namespace hsdk
{
	namespace framework
	{
		// 설명 : 
		DECL_STRUCT(VideoCard_Output_info)
		{
			// 설명 : 
			DXGI_OUTPUT_DESC desc;

			// 설명 : 
			unsigned int ordinal;

			// 설명 : 
			unsigned int output;

			// 설명 : 
			AutoRelease<IDXGIOutput> dxgiOutput;

			// 설명 : Array of supported D3DDISPLAYMODEs
			std::vector<DXGI_MODE_DESC> displayModeList;

		};

		// 설명 : 
		DECL_STRUCT(VideoCard_info)
		{

			// 설명 : 
			unsigned int ordinal;

			// 설명 : 
			DXGI_ADAPTER_DESC desc;

			// 설명 : 
			AutoRelease<IDXGIAdapter> dxgiAdapter;

			// 설명 :  Array of VideoCard_Output_info
			std::vector<VideoCard_Output_info> output_infoList;

		};

		// 설명 : 
		DLL_DECL_CLASS(Framework_Outside)
		{

		public:

			// 설명 : 
			CLASS_DECL_FUNC(initialize)(
				_In_ IDXGIFactory * _dxgiFactory,
				_In_ BOOL _enumerateAllAdapterFormats = true,
				_In_ BOOL _is_in_GammaCorrectMode = true);

			// 설명 : 
			CLASS_DECL_FUNC(initialize_Outputs)(
				_Out_ VideoCard_Output_info & _output_info,
				_In_ unsigned int _index,
				_In_ IDXGIAdapter * _dxgiAdapter);

			// 설명 : 
			CLASS_DECL_FUNC(initialize_DisplayModes)(
				_Out_ VideoCard_Output_info & _output_info);

			// 설명 : 
			CLASS_DECL_FUNC_T(const VideoCard_info *, get_info)(
				_In_ unsigned int _adapterOrdinal);

			// 설명 : 
			CLASS_DECL_FUNC_T(const VideoCard_Output_info *, get_Output_info)(
				_In_ unsigned int _adapterOrdinal,
				_In_ unsigned int _output);

			// 설명 : Returns the HMONITOR attached to an adapter/output
			CLASS_DECL_FUNC_T(HMONITOR, get_MonitorFromAdapter)(
				_In_ const D3D10_DEVICE_DESC & _desc);

			// 설명 : Look for an adapter ordinal that is tied to a HMONITOR
			CLASS_DECL_FUNC_T(unsigned int, get_AdapterOrdinalFromMonitor)(
				_In_ HMONITOR _monitor);

			// 설명 : Look for a monitor ordinal that is tied to a HMONITOR (D3D10-only)
			CLASS_DECL_FUNC_T(unsigned int, get_OutputOrdinalFromMonitor)(
				_In_ HMONITOR _monitor);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, destroy)(
				_X_ void);

		};

		// 설명 : 
		extern HSDK_DLL Framework_Outside g_Direct3D_Outside;

	}
}