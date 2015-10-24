#pragma once
#pragma comment( lib, "d3dx10.lib" )



#include "../common.h"
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
			/* [r/w] */ void * _context);

		// 설명 : 
		typedef long (CALLBACK * CALLBACK_D3D10_CREATE_VERTEXBUFFER)(
			_Out_ ID3D10Buffer ** _buffer,
			_In_ ID3D10Device * _dev,
			_In_ D3D10_BUFFER_DESC _bufferDesc,
			_In_ const void * _data,
			/* [r/w] */ void * _context);

		// 설명 : 
		typedef long (CALLBACK * CALLBACK_D3D10_CREATE_INDEXBUFFER)(
			_Out_ ID3D10Buffer ** _buffer,
			_In_ ID3D10Device * _dev,
			_In_ D3D10_BUFFER_DESC _bufferDesc,
			_In_ const void * _data,
			/* [r/w] */ void * _context);

		//--------------------------------------------------------------------------------------
		//
		//--------------------------------------------------------------------------------------
		
		// 설명 :
		DECL_STRUCT(D3D10_BasicFormat)
		{

			// 설명 : 
			D3DXVECTOR3 pos;

			// 설명 : 
			D3DXVECTOR3 norm;

			// 설명 : 
			D3DXVECTOR2 tex;

		};

		// 설명 : 
		DECL_STRUCT(D3D10_SkinnedFormat)
		{

			// 설명 : 
			D3DXVECTOR3 pos;

			// 설명 : 
			D3DXVECTOR3 norm;

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
		DECL_STRUCT(D3D10MY_MATERIAL)
		{

			// 설명 : 
			std::wstring name;

			// 설명 : 
			float shininess;

			// 설명 : 
			D3DXVECTOR4 diffuse;

			// 설명 : 
			D3DXVECTOR4 ambient;

			// 설명 : 
			D3DXVECTOR4 specular;

			// 설명 : 
			D3DXVECTOR4 emissive;

			// 설명 : 
			AutoRelease<ID3D10ShaderResourceView> diffuseRV;

			// 설명 : 
			AutoRelease<ID3D10ShaderResourceView> normalRV;

			// 설명 : 
			AutoRelease<ID3D10ShaderResourceView> specularRV;

		};

		// 설명 : 
		DECL_STRUCT(D3D10MY_RENDER_DESC)
		{

			// 설명 : 
			D3D10_PRIMITIVE_TOPOLOGY primitiveType;

			// 설명 : 
			unsigned int material_id;

			// 설명 : 
			unsigned int indexStart;

			// 설명 : 
			unsigned int indexCount;

			// 설명 : 
			unsigned int vertexbufferStart;

			// 설명 : 
			unsigned int vertexbufferCount;

		};

		// 설명 : 
		DECL_STRUCT(D3D10MY_INDEXBUFFER)
		{

			// 설명 : 
			unsigned int numOfindices;

			// 설명 : 
			DXGI_FORMAT indexType;

			// 설명 : (This also forces the union to 64bits)
			AutoRelease<ID3D10Buffer> indexbuffer;

		};

		//
		DECL_STRUCT(D3D10MY_MESH)
		{

			// 설명 : 
			std::wstring name;

			// 설명 : 
			std::vector<D3D10MY_RENDER_DESC> render_Descs;

			// 설명 :
			unsigned int numOfVertices;

			// 설명 : 
			std::vector<unsigned int> vertexbuffers_Strides;

			// 설명 : 
			std::vector<unsigned int> vertexbuffers_Offsets;

			// 설명 : 
			std::vector<AutoRelease<ID3D10Buffer>> vertexbuffers;

			// 설명 : 
			D3D10MY_INDEXBUFFER indexbuffer;

			// 설명 : 
			D3DXVECTOR3 boundingBoxCenter;

			// 설명 : 
			D3DXVECTOR3 boundingBoxSize;

		};

		// 설명 : 
		DECL_STRUCT(D3D10MY_TEXTURE)
		{

			// 설명 : 
			D3DX10_IMAGE_INFO info;

			// 설명 : 
			AutoRelease<ID3D10ShaderResourceView> texture;

		};
	}
}