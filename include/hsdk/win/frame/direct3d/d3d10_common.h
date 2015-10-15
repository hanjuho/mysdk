#pragma once
#pragma comment( lib, "d3dx10.lib" )



#include "common.h"
#include <d3dx10.h>
#include <d3dx10math.h>



namespace hsdk
{
	namespace direct3d
	{

		// 설명 : 
		DECL_STRUCT(D3D10_UIFormat)
		{

			// 설명 : 
			D3DXVECTOR3 pos;

			// 설명 : 
			D3DCOLORVALUE color;

			// 설명 : 
			D3DXVECTOR2 tex;

		};

		// 설명 :
		DECL_STRUCT(D3D10_SkyFormat)
		{

			// 설명 : 
			D3DXVECTOR3 pos;

			// 설명 : 
			D3DXVECTOR3 norm;

			// 설명 : 
			D3DXVECTOR2 tex;

		};

	}
}