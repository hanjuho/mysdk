#include "common.h"

//--------------------------------------------------------------------------------------
IMPL_FUNC_T(DXGI_FORMAT, hsdk::framework::convert_Format_D3D9ToDXGI)(
	_In_ D3DFORMAT _format)
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
IMPL_FUNC_T(D3D10_DRIVER_TYPE, hsdk::framework::convert_DriverType_D3D9ToDXGI)(
	_In_ D3DDEVTYPE _type)
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
IMPL_FUNC_T(D3DDEVTYPE, hsdk::framework::convert_DriverType_DXGIToD3D9)(
	_In_ D3D10_DRIVER_TYPE _type)
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