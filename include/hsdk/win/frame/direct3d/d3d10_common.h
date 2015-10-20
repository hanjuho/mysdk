#pragma once
#pragma comment( lib, "d3dx10.lib" )



#include "common.h"
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
			/* [w] */ ID3D10ShaderResourceView ** _srv,
			/* [r] */ ID3D10Device * _d3d10Device,
			/* [r] */ const wchar_t * _filepath,
			/* [r/w] */ void * _context);

		// ���� : 
		typedef long (CALLBACK * CALLBACK_D3D10_CREATE_VERTEXBUFFER)(
			/* [w] */ ID3D10Buffer ** _buffer,
			/* [r] */ ID3D10Device * _dev,
			/* [r] */ D3D10_BUFFER_DESC _bufferDesc,
			/* [r] */ const void * _data,
			/* [r/w] */ void * _context);

		// ���� : 
		typedef long (CALLBACK * CALLBACK_D3D10_CREATE_INDEXBUFFER)(
			/* [w] */ ID3D10Buffer ** _buffer,
			/* [r] */ ID3D10Device * _dev,
			/* [r] */ D3D10_BUFFER_DESC _bufferDesc,
			/* [r] */ const void * _data,
			/* [r/w] */ void * _context);

		//--------------------------------------------------------------------------------------
		//
		//--------------------------------------------------------------------------------------

		// ���� :
		DECL_STRUCT(D3D10_BasicFormat)
		{

			// ���� : 
			D3DXVECTOR3 pos;

			// ���� : 
			D3DXVECTOR3 norm;

			// ���� : 
			D3DXVECTOR2 tex;

		};

		// ���� : 
		DECL_STRUCT(D3D10_SkinnedFormat)
		{

			// ���� : 
			D3DXVECTOR3 pos;

			// ���� : 
			D3DXVECTOR3 norm;

			// ���� : 
			D3DXVECTOR2 tex;

			// ���� :
			D3DXVECTOR4 color;

			// ���� : 
			unsigned int bindex;

			// ���� : 
			D3DXVECTOR4 bweight;

		};

		// ���� :
		DECL_STRUCT(D3D10_TextureFormat)
		{

			// ���� : 
			D3DXVECTOR3 pos;

			// ���� : 
			D3DXVECTOR3 norm;

			// ���� : 
			unsigned int bindex;

		}; 

		//--------------------------------------------------------------------------------------
		//
		//--------------------------------------------------------------------------------------

		// ���� : 
		DECL_STRUCT(D3D10MY_MATERIAL)
		{

			// ���� : 
			std::wstring name;

			// ���� : 
			unsigned int shininess;

			// ���� : 
			D3DXVECTOR4 diffuse;

			// ���� : 
			D3DXVECTOR4 ambient;

			// ���� : 
			D3DXVECTOR4 specular;

			// ���� : 
			D3DXVECTOR4 emissive;

			// ���� : 
			AutoRelease<ID3D10ShaderResourceView> diffuseRV;

			// ���� : 
			AutoRelease<ID3D10ShaderResourceView> normalRV;

			// ���� : 
			AutoRelease<ID3D10ShaderResourceView> specularRV;

		};

		// ���� : 
		DECL_STRUCT(D3D10MY_RENDER_DESC)
		{

			// ���� : 
			D3D10_PRIMITIVE_TOPOLOGY primitiveType;

			// ���� : 
			unsigned int material_id;

			// ���� : 
			unsigned int indexStart;

			// ���� : 
			unsigned int indexCount;

			// ���� : 
			unsigned int vertexbufferStart;

			// ���� : 
			unsigned int vertexbufferCount;

		};

		// ���� : 
		DECL_STRUCT(D3D10MY_INDEXBUFFER)
		{

			// ���� : 
			unsigned int numOfindices;

			// ���� : 
			DXGI_FORMAT indexType;

			// ���� : (This also forces the union to 64bits)
			AutoRelease<ID3D10Buffer> indexbuffer;

		};

		//
		DECL_STRUCT(D3D10MY_MESH)
		{

			// ���� : 
			std::wstring name;

			// ���� : 
			std::vector<D3D10MY_RENDER_DESC> render_Descs;

			// ���� :
			unsigned int numOfVertices;

			// ���� : 
			std::vector<unsigned int> vertexbuffers_Strides;

			// ���� : 
			std::vector<unsigned int> vertexbuffers_Offsets;

			// ���� : 
			std::vector<AutoRelease<ID3D10Buffer>> vertexbuffers;

			// ���� : 
			D3D10MY_INDEXBUFFER indexbuffer;

			// ���� : 
			D3DXVECTOR3 boundingBoxCenter;

			// ���� : 
			D3DXVECTOR3 boundingBoxSize;

		};

		// ���� : 
		DECL_STRUCT(D3D10MY_TEXTURE)
		{

			// ���� : 
			D3DX10_IMAGE_INFO info;

			// ���� : 
			AutoRelease<ID3D10ShaderResourceView> texture;

		};
	}
}