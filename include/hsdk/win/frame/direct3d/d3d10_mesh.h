#pragma once



#include "d3d10_common.h"
#include <vector>



//--------------------------------------------------------------------------------------
// File: SDKMesh.h
//
// Disclaimer:  
//   The SDK Mesh format (.sdkmesh) is not a recommended file format for shipping titles.  
//   It was designed to meet the specific needs of the SDK samples.  Any real-world 
//   applications should avoid this file format in favor of a destination format that 
//   meets the specific needs of the application.
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------



namespace hsdk
{
	namespace direct3d
	{
		//--------------------------------------------------------------------------------------
		// AsyncLoading callbacks
		//--------------------------------------------------------------------------------------

		// 설명 : 
		typedef long (CALLBACK * CALLBACK_D3D10_CREATE_TEXTURE_FROMFILE)(
			/* [w] */ ID3D10ShaderResourceView ** _srv,
			/* [r] */ ID3D10Device * _d3d10Device,
			/* [r] */ const wchar_t * _szFileName,
			/* [r/w] */ void * _context);

		// 설명 : 
		typedef long (CALLBACK * CALLBACK_D3D10_CREATE_VERTEXBUFFER)(
			/* [w] */ ID3D10Buffer ** _buffer,
			/* [r] */ ID3D10Device * _dev,
			/* [r] */ D3D10_BUFFER_DESC _bufferDesc,
			/* [r] */ const void * _data,
			/* [r/w] */ void * _context);

		// 설명 : 
		typedef long (CALLBACK * CALLBACK_D3D10_CREATE_INDEXBUFFER)(
			/* [w] */ ID3D10Buffer ** _buffer,
			/* [r] */ ID3D10Device * _dev,
			/* [r] */ D3D10_BUFFER_DESC _bufferDesc,
			/* [r] */ const void * _data,
			/* [r/w] */ void * _context);


		// 설명 : 
		DECL_STRUCT(D3D10MY_MATERIAL)
		{

			// 설명 : 
			std::wstring name;

			// 설명 : 
			D3DXVECTOR4 diffuse;

			// 설명 : 
			D3DXVECTOR4 ambient;

			// 설명 : 
			D3DXVECTOR4 specular;

			// 설명 : 
			D3DXVECTOR4 emissive;

			// 설명 : 
			AutoRelease<ID3D10Texture2D> diffuseTexture;

			// 설명 : 
			AutoRelease<ID3D10Texture2D> normalTexture;

			// 설명 : 
			AutoRelease<ID3D10Texture2D> specularTexture;

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

		// 설명 : CDXUTSDKMesh class.  This class reads the sdkmesh file format for use by the samples
		DLL_DECL_CLASS(D3D10_Mesh)
		{

		public:

			// 생성자.
			CLASS_DECL_CONSTRUCTOR(D3D10_Mesh)(
				/* [r] */ CALLBACK_D3D10_CREATE_TEXTURE_FROMFILE _callback_Create_Texture_FromFile = nullptr,
				/* [r] */ CALLBACK_D3D10_CREATE_VERTEXBUFFER _callback_Create_VertexBuffer = nullptr,
				/* [r] */ CALLBACK_D3D10_CREATE_INDEXBUFFER _callback_Create_indexBuffer = nullptr,
				/* [r] */ void * _userContext = nullptr);

			// 소멸자.
			CLASS_DECL_DESTRUCTOR(D3D10_Mesh)(void);

			// 설명 : 
			DECL_FUNC_T(void, destroy)(
				/* [x] */ void);

			// 설명 :
			DECL_FUNC(setup)(
				/* [r] */ ID3D10Device * _device,
				/* [r] */ unsigned int _numOfMaterials,
				/* [r] */ unsigned int _numOfMeshs);

			// 설명 : 
			DECL_FUNC(setup_Texture)(
				/* [r] */ const wchar_t * _path,
				/* [r] */ unsigned int _indexOfMaterial,
				/* [r] */ unsigned int _attribute);

			// 설명 : 
			DECL_FUNC(setup_Texture)(
				/* [r] */ unsigned int _indexOfMaterial,
				/* [r] */ unsigned int _attribute,
				/* [r] */ ID3D10ShaderResourceView * _resource);

			// 설명 : 
			DECL_FUNC(setup_Material)(
				/* [r] */ unsigned int _indexOfMaterial,
				/* [r] */ unsigned int _attribute,
				/* [r] */ const D3DXVECTOR4 & _value);

			// 설명 :
			DECL_FUNC(setup_Mesh)(
				/* [r] */ unsigned int _indexOfMesh,
				/* [r] */ unsigned int _numOfRenderDescs,
				/* [r] */ unsigned int _numOfVertexBuffers);

			// 설명 :
			DECL_FUNC(setup_RenderDesc)(
				/* [r] */ unsigned int _indexOfMesh,
				/* [r] */ unsigned int _indexOfRenderDesc,
				/* [r] */ unsigned int _material_id,
				/* [r] */ unsigned int _indexStart,
				/* [r] */ unsigned int _indexCount,
				/* [r] */ unsigned int _vertexbufferStart,
				/* [r] */ unsigned int _vertexbufferCount,
				/* [r] */ D3D10_PRIMITIVE_TOPOLOGY _primitiveType);

			// 설명 : 
			DECL_FUNC(setup_Vertexbuffer)(
				/* [r] */ unsigned int _indexOfMesh,
				/* [r] */ unsigned int _indexOfBuffer,
				/* [r] */ const D3D10_BUFFER_DESC & _desc,
				/* [r] */ const void * _vertices,
				/* [r] */ unsigned int _stride,
				/* [r] */ unsigned int _offset,
				/* [r] */ unsigned int _numOfVertices = 0);

			// 설명 : 
			DECL_FUNC(setup_indexbuffer)(
				/* [r] */ unsigned int _indexOfMesh,
				/* [r] */ const D3D10_BUFFER_DESC & _desc,
				/* [r] */ const void * _indices,
				/* [r] */ DXGI_FORMAT _format,
				/* [r] */ unsigned int _numOfindies = 0);

			// 설명 : 
			DECL_FUNC(userSet_MeshPath)(
				/* [r] */ const wchar_t * _path);

			// 설명 : 
			DECL_FUNC(userSet_MeshBoundingBox)(
				/* [r] */ unsigned int _indexOfMesh,
				/* [r] */ const D3DXVECTOR3 & _center,
				/* [r] */ const D3DXVECTOR3 & _size);

			// 설명 : 
			DECL_FUNC(userSet_MaterialName)(
				/* [r] */ unsigned int _indexOfMaterial,
				/* [r] */ const wchar_t * _name);

			//--------------------------------------------------------------------------------------
			//Helpers (general)
			//--------------------------------------------------------------------------------------

			// 설명 : 
			DECL_FUNC(loadLock)(
				/* [x] */ void);

			// 설명 : 
			DECL_FUNC_T(long, is_Load)(
				/* [x] */ void)const;

			// 설명 : 
			DECL_FUNC_T(const wchar_t *, get_MeshPath)(
				/* [x] */ void)const;

			// 설명 : 
			DECL_FUNC_T(unsigned int, get_NumMeshes)(
				/* [x] */ void)const;

			// 설명 : 
			DECL_FUNC_T(unsigned int, get_NumMaterials)(
				/* [x] */ void)const;

			// 설명 : 
			DECL_FUNC_T(const D3D10MY_MATERIAL &, get_Material)(
				/* [r] */ unsigned int _indexOfMaterial)const;

			// 설명 : 
			DECL_FUNC_T(const D3D10MY_MESH &, get_Mesh)(
				/* [r] */ unsigned int _indexOfMesh)const;

			// 설명 : 
			DECL_FUNC_T(D3DXVECTOR3, get_Mesh_BBoxCenter)(
				/* [r] */ unsigned int _indexOfMesh)const;

			// 설명 : 
			DECL_FUNC_T(D3DXVECTOR3, get_Mesh_BBoxSize)(
				/* [r] */ unsigned int _indexOfMesh)const;

		private:

			// 설명 :
			volatile long my_LoadLock;

			// 설명 : Keep track of the path
			std::wstring my_MeshPath;

			// 설명 : 
			std::vector<D3D10MY_MATERIAL> my_Materials;

			// 설명 :
			std::vector<D3D10MY_MESH> my_Meshs;

			// 설명 : 
			ID3D10Device * my_refD3D10Device;

			// 설명 :
			CALLBACK_D3D10_CREATE_TEXTURE_FROMFILE my_refCallback_Create_Texture_FromFile;

			// 설명 :
			CALLBACK_D3D10_CREATE_VERTEXBUFFER my_refCallback_Create_VertexBuffer;

			// 설명 :
			CALLBACK_D3D10_CREATE_INDEXBUFFER my_refCallback_Create_indexBuffer;

			// 설명 :
			void * my_refUserContext;

		};

	}
}