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

		// ���� : 
		typedef long (CALLBACK * CALLBACK_D3D10_CREATE_TEXTURE_FROMFILE)(
			_Out_ ID3D10ShaderResourceView ** _srv,
			_In_ ID3D10Device * _d3d10Device,
			_In_ const wchar_t * _filepath,
			_Inout_ void * _context);

		// ���� : 
		typedef long (CALLBACK * CALLBACK_D3D10_CREATE_VERTEXBUFFER)(
			_Out_ ID3D10Buffer ** _buffer,
			_In_ ID3D10Device * _dev,
			_In_ D3D10_BUFFER_DESC _bufferDesc,
			_In_ const void * _data,
			_Inout_ void * _context);

		// ���� : 
		typedef long (CALLBACK * CALLBACK_D3D10_CREATE_INDEXBUFFER)(
			_Out_ ID3D10Buffer ** _buffer,
			_In_ ID3D10Device * _dev,
			_In_ D3D10_BUFFER_DESC _bufferDesc,
			_In_ const void * _data,
			_Inout_ void * _context);

		//--------------------------------------------------------------------------------------
		//
		//--------------------------------------------------------------------------------------
		
		// ���� :
		DECL_STRUCT(D3D10_BasicFormat)
		{

			// ���� : 
			D3DXVECTOR3 pos;

			// ���� : 
			D3DXVECTOR3 nor;

			// ���� : 
			D3DXVECTOR2 tex;

		};

		// ���� : 
		DECL_STRUCT(D3D10_SkinnedFormat)
		{

			// ���� : 
			D3DXVECTOR3 pos;

			// ���� : 
			D3DXVECTOR3 nor;

			// ���� : 
			D3DXVECTOR2 tex;

			// ���� :
			D3DXVECTOR4 color;

			// ���� : 
			unsigned int bindexs[4];

			// ���� : 
			float bweight[4];

		};

		// ���� :
		DECL_STRUCT(D3D10_SkyBoxFormat)
		{

			// ���� : 
			D3DXVECTOR3 pos;

		};

		//--------------------------------------------------------------------------------------
		//
		//--------------------------------------------------------------------------------------
		
		// ���� : 
		DECL_STRUCT(D3D10MY_CONTEXT)
		{

			// ���� : 
			AutoRelease<ID3D10Buffer> vertexBuffer;

			// ���� :
			unsigned int textSlot = 0;

			// ���� : 
			std::vector<D3DXMATRIX> textCoords;

			// ���� :
			D3DXMATRIX matrix;

			// ���� :
			D3DXVECTOR4 color;

			// ���� :
			float intensity;

		};

	}
}