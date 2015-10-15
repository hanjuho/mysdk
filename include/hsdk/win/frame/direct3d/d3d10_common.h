#pragma once
#pragma comment( lib, "d3dx10.lib" )



#include "common.h"
#include <d3dx10.h>
#include <d3dx10math.h>



namespace hsdk
{
	namespace direct3d
	{

		// ���� : 
		DECL_STRUCT(D3D10_UIFormat)
		{

			// ���� : 
			D3DXVECTOR3 pos;

			// ���� : 
			D3DCOLORVALUE color;

			// ���� : 
			D3DXVECTOR2 tex;

		};

		// ���� :
		DECL_STRUCT(D3D10_SkyFormat)
		{

			// ���� : 
			D3DXVECTOR3 pos;

			// ���� : 
			D3DXVECTOR3 norm;

			// ���� : 
			D3DXVECTOR2 tex;

		};

	}
}