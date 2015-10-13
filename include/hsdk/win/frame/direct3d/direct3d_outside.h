#pragma once



#include "common.h"
#include <vector>



namespace hsdk
{
	namespace direct3d
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
		DLL_DECL_CLASS(Direct3D_Outside)
		{

		public:

			// ���� : 
			CLASS_DECL_FUNC(initialize)(
				/* [r] */ IDXGIFactory * _dxgiFactory,
				/* [r] */ BOOL _enumerateAllAdapterFormats = true,
				/* [r] */ BOOL _is_in_GammaCorrectMode = true);

			// ���� : 
			CLASS_DECL_FUNC(initialize_Outputs)(
				/* [w] */ VideoCard_Output_info & _output_info,
				/* [r] */ unsigned int _index,
				/* [r] */ IDXGIAdapter * _dxgiAdapter);

			// ���� : 
			CLASS_DECL_FUNC(initialize_DisplayModes)(
				/* [w] */ VideoCard_Output_info & _output_info);

			// ���� : 
			CLASS_DECL_FUNC_T(const VideoCard_info *, get_info)(
				/* [r] */ unsigned int _adapterOrdinal);

			// ���� : 
			CLASS_DECL_FUNC_T(const VideoCard_Output_info *, get_Output_info)(
				/* [r] */ unsigned int _adapterOrdinal,
				/* [r] */ unsigned int _output);

			// ���� : Returns the HMONITOR attached to an adapter/output
			CLASS_DECL_FUNC_T(HMONITOR, get_MonitorFromAdapter)(
				/* [r] */ const D3D10_DEVICE_DESC & _desc);

			// ���� : Look for an adapter ordinal that is tied to a HMONITOR
			CLASS_DECL_FUNC_T(unsigned int, get_AdapterOrdinalFromMonitor)(
				/* [r] */ HMONITOR _monitor,
				/* [r] */ IDirect3D9 * _d3d9 = nullptr);

			// ���� : Look for a monitor ordinal that is tied to a HMONITOR (D3D10-only)
			CLASS_DECL_FUNC_T(unsigned int, get_OutputOrdinalFromMonitor)(
				/* [r] */ HMONITOR _monitor);

			// ���� : 
			CLASS_DECL_FUNC_T(void, destroy)(
				/* [x] */ void);
			
			//// ���� : 
			//CLASS_DECL_FUNC(initialize_DeviceCombos)(IDXGIFactory* pFactory, CD3D10EnumAdapterInfo* pAdapterInfo);

			//// ���� : 
			//CLASS_DECL_FUNC(initialize_DeviceCombosNoAdapter)(CD3D10EnumAdapterInfo* pAdapterInfo);


		};

	}
}