#pragma once



#include "common.h"
#include <vector>



namespace hsdk
{
	namespace framework
	{
		// ���� : 
		DECL_STRUCT(VideoCard_Output_info)
		{
			// ���� : 
			DXGI_OUTPUT_DESC desc;

			// ���� : 
			unsigned int ordinal;

			// ���� : 
			unsigned int output;

			// ���� : 
			AutoRelease<IDXGIOutput> dxgiOutput;

			// ���� : Array of supported D3DDISPLAYMODEs
			std::vector<DXGI_MODE_DESC> displayModeList;

		};

		// ���� : 
		DECL_STRUCT(VideoCard_info)
		{

			// ���� : 
			unsigned int ordinal;

			// ���� : 
			DXGI_ADAPTER_DESC desc;

			// ���� : 
			AutoRelease<IDXGIAdapter> dxgiAdapter;

			// ���� :  Array of VideoCard_Output_info
			std::vector<VideoCard_Output_info> output_infoList;

		};

		// ���� : 
		DLL_DECL_CLASS(Framework_Outside)
		{

		public:

			// ���� : 
			CLASS_DECL_FUNC(initialize)(
				_In_ IDXGIFactory * _dxgiFactory,
				_In_ BOOL _enumerateAllAdapterFormats = true,
				_In_ BOOL _is_in_GammaCorrectMode = true);

			// ���� : 
			CLASS_DECL_FUNC(initialize_Outputs)(
				_Out_ VideoCard_Output_info & _output_info,
				_In_ unsigned int _index,
				_In_ IDXGIAdapter * _dxgiAdapter);

			// ���� : 
			CLASS_DECL_FUNC(initialize_DisplayModes)(
				_Out_ VideoCard_Output_info & _output_info);

			// ���� : 
			CLASS_DECL_FUNC_T(const VideoCard_info *, get_info)(
				_In_ unsigned int _adapterOrdinal);

			// ���� : 
			CLASS_DECL_FUNC_T(const VideoCard_Output_info *, get_Output_info)(
				_In_ unsigned int _adapterOrdinal,
				_In_ unsigned int _output);

			// ���� : Returns the HMONITOR attached to an adapter/output
			CLASS_DECL_FUNC_T(HMONITOR, get_MonitorFromAdapter)(
				_In_ const D3D10_DEVICE_DESC & _desc);

			// ���� : Look for an adapter ordinal that is tied to a HMONITOR
			CLASS_DECL_FUNC_T(unsigned int, get_AdapterOrdinalFromMonitor)(
				_In_ HMONITOR _monitor);

			// ���� : Look for a monitor ordinal that is tied to a HMONITOR (D3D10-only)
			CLASS_DECL_FUNC_T(unsigned int, get_OutputOrdinalFromMonitor)(
				_In_ HMONITOR _monitor);

			// ���� : 
			CLASS_DECL_FUNC_T(void, destroy)(
				_X_ void);

		};

		// ���� : 
		extern HSDK_DLL Framework_Outside g_Direct3D_Outside;

	}
}