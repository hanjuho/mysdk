#pragma once



#pragma comment(lib, "assimp.lib")
#pragma comment( lib, "d3dx10.lib" )



#include "../common.h"
#include <assimp/scene.h>
#include <assimp/cimport.h>
#include <assimp/postprocess.h>
#include <d3dx10.h>
#include <d3dx10math.h>
#include <string>
#include <vector>



namespace hsdk
{
	namespace direct3d
	{

		//--------------------------------------------------------------------------------------
		// AsyncLoading callbacks
		//--------------------------------------------------------------------------------------

		// 설명 : 
		typedef long (CALLBACK * CALLBACK_D3D10_CREATE_TEXTURE_FROMFILE)(
			_Out_ ID3D10ShaderResourceView ** _srv,
			_In_ ID3D10Device * _d3d10Device,
			_In_ const wchar_t * _filepath,
			_Inout_ void * _context);

		// 설명 : 
		typedef long (CALLBACK * CALLBACK_D3D10_CREATE_VERTEXBUFFER)(
			_Out_ ID3D10Buffer ** _buffer,
			_In_ ID3D10Device * _dev,
			_In_ D3D10_BUFFER_DESC _bufferDesc,
			_In_ const void * _data,
			_Inout_ void * _context);

		// 설명 : 
		typedef long (CALLBACK * CALLBACK_D3D10_CREATE_INDEXBUFFER)(
			_Out_ ID3D10Buffer ** _buffer,
			_In_ ID3D10Device * _dev,
			_In_ D3D10_BUFFER_DESC _bufferDesc,
			_In_ const void * _data,
			_Inout_ void * _context);

		//--------------------------------------------------------------------------------------
		//
		//--------------------------------------------------------------------------------------
		
		// 설명 :
		DECL_STRUCT(D3D10_BasicFormat)
		{

			// 설명 : 
			D3DXVECTOR3 pos;

			// 설명 : 
			D3DXVECTOR3 nor;

			// 설명 : 
			D3DXVECTOR2 tex;

		};

		// 설명 : 
		DECL_STRUCT(D3D10_SkinnedFormat)
		{

			// 설명 : 
			D3DXVECTOR3 pos;

			// 설명 : 
			D3DXVECTOR3 nor;

			// 설명 : 
			D3DXVECTOR2 tex;

			// 설명 :
			D3DXVECTOR4 color;

			// 설명 : 
			unsigned int bindexs[4];

			// 설명 : 
			float bweight[4];

		};

		// 설명 :
		DECL_STRUCT(D3D10_SkyBoxFormat)
		{

			// 설명 : 
			D3DXVECTOR3 pos;

		};

		//--------------------------------------------------------------------------------------
		//
		//--------------------------------------------------------------------------------------
		
		// 설명 : 
		DECL_STRUCT(D3D10MY_CONTEXT)
		{

			// 설명 : 
			AutoRelease<ID3D10Buffer> vertexBuffer;

			// 설명 :
			unsigned int textSlot = 0;

			// 설명 : 
			std::vector<D3DXMATRIX> textCoords;

			// 설명 :
			D3DXMATRIX matrix;

			// 설명 :
			D3DXVECTOR4 color;

			// 설명 :
			float intensity;

		};

	}
}