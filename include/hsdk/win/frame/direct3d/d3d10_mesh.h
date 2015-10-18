#pragma once



#include "d3d10_common.h"



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

		// ���� : CDXUTSDKMesh class.  This class reads the sdkmesh file format for use by the samples
		DLL_DECL_CLASS(D3D10_Mesh)
		{

		public:

			// ������.
			CLASS_DECL_CONSTRUCTOR(D3D10_Mesh)(
				/* [r] */ CALLBACK_D3D10_CREATE_TEXTURE_FROMFILE _callback_Create_Texture_FromFile = nullptr,
				/* [r] */ CALLBACK_D3D10_CREATE_VERTEXBUFFER _callback_Create_VertexBuffer = nullptr,
				/* [r] */ CALLBACK_D3D10_CREATE_INDEXBUFFER _callback_Create_indexBuffer = nullptr,
				/* [r] */ void * _userContext = nullptr);

			// �Ҹ���.
			CLASS_DECL_DESTRUCTOR(D3D10_Mesh)(void);

			// ���� : 
			DECL_FUNC_T(void, destroy)(
				/* [x] */ void);

			// ���� :
			DECL_FUNC(setup0)(
				/* [r] */ ID3D10Device * _device,
				/* [r] */ unsigned int _numOfMaterials,
				/* [r] */ unsigned int _numOfMeshs);

			// ���� : 
			DECL_FUNC(setup1_Texture)(
				/* [r] */ const wchar_t * _filepath,
				/* [r] */ unsigned int _indexOfMaterial,
				/* [r] */ unsigned int _attribute);

			// ���� : 
			DECL_FUNC(setup1_Texture)(
				/* [r] */ unsigned int _indexOfMaterial,
				/* [r] */ unsigned int _attribute,
				/* [r] */ ID3D10ShaderResourceView * _resource);

			// ���� : 
			DECL_FUNC(setup1_Material)(
				/* [r] */ unsigned int _indexOfMaterial,
				/* [r] */ unsigned int _attribute,
				/* [r] */ const D3DXVECTOR4 & _value);

			// ���� :
			DECL_FUNC(setup1_Mesh)(
				/* [r] */ unsigned int _indexOfMesh,
				/* [r] */ unsigned int _numOfRenderDescs,
				/* [r] */ unsigned int _numOfVertexBuffers);

			// ���� :
			DECL_FUNC(setup2_RenderDesc)(
				/* [r] */ unsigned int _indexOfMesh,
				/* [r] */ unsigned int _indexOfRenderDesc,
				/* [r] */ unsigned int _material_id,
				/* [r] */ unsigned int _indexStart,
				/* [r] */ unsigned int _indexCount,
				/* [r] */ unsigned int _vertexbufferStart,
				/* [r] */ unsigned int _vertexbufferCount,
				/* [r] */ D3D10_PRIMITIVE_TOPOLOGY _primitiveType);

			// ���� : 
			DECL_FUNC(setup2_Vertexbuffer)(
				/* [r] */ unsigned int _indexOfMesh,
				/* [r] */ unsigned int _indexOfBuffer,
				/* [r] */ const D3D10_BUFFER_DESC & _desc,
				/* [r] */ const void * _vertices,
				/* [r] */ unsigned int _stride,
				/* [r] */ unsigned int _offset,
				/* [r] */ unsigned int _numOfVertices = 0);

			// ���� : 
			DECL_FUNC(setup2_indexbuffer)(
				/* [r] */ unsigned int _indexOfMesh,
				/* [r] */ const D3D10_BUFFER_DESC & _desc,
				/* [r] */ const void * _indices,
				/* [r] */ DXGI_FORMAT _format,
				/* [r] */ unsigned int _numOfindies = 0);

			// ���� : 
			DECL_FUNC(userSet_MeshPath)(
				/* [r] */ const wchar_t * _path);

			// ���� : 
			DECL_FUNC(userSet_MeshBoundingBox)(
				/* [r] */ unsigned int _indexOfMesh,
				/* [r] */ const D3DXVECTOR3 & _center,
				/* [r] */ const D3DXVECTOR3 & _size);

			// ���� : 
			DECL_FUNC(userSet_MaterialName)(
				/* [r] */ unsigned int _indexOfMaterial,
				/* [r] */ const wchar_t * _name);

			//--------------------------------------------------------------------------------------
			//Helpers (general)
			//--------------------------------------------------------------------------------------

			// ���� : 
			DECL_FUNC(loadLock)(
				/* [x] */ void);

			// ���� : 
			DECL_FUNC_T(long, is_Load)(
				/* [x] */ void)const;

			// ���� : 
			DECL_FUNC_T(const wchar_t *, get_MeshPath)(
				/* [x] */ void)const;

			// ���� : 
			DECL_FUNC_T(unsigned int, get_NumMeshes)(
				/* [x] */ void)const;

			// ���� : 
			DECL_FUNC_T(unsigned int, get_NumMaterials)(
				/* [x] */ void)const;

			// ���� : 
			DECL_FUNC_T(const D3D10MY_MATERIAL &, get_Material)(
				/* [r] */ unsigned int _indexOfMaterial)const;

			// ���� : 
			DECL_FUNC_T(const D3D10MY_MESH &, get_Mesh)(
				/* [r] */ unsigned int _indexOfMesh)const;

			// ���� : 
			DECL_FUNC_T(D3DXVECTOR3, get_Mesh_BBoxCenter)(
				/* [r] */ unsigned int _indexOfMesh)const;

			// ���� : 
			DECL_FUNC_T(D3DXVECTOR3, get_Mesh_BBoxSize)(
				/* [r] */ unsigned int _indexOfMesh)const;

		private:

			// ���� :
			volatile long my_LoadLock;

			// ���� : Keep track of the path
			std::wstring my_MeshPath;

			// ���� : 
			std::vector<D3D10MY_MATERIAL> my_Materials;

			// ���� :
			std::vector<D3D10MY_MESH> my_Meshs;

			// ���� : 
			ID3D10Device * my_refD3D10Device;

			// ���� :
			CALLBACK_D3D10_CREATE_TEXTURE_FROMFILE my_refCallback_Create_Texture_FromFile;

			// ���� :
			CALLBACK_D3D10_CREATE_VERTEXBUFFER my_refCallback_Create_VertexBuffer;

			// ���� :
			CALLBACK_D3D10_CREATE_INDEXBUFFER my_refCallback_Create_indexBuffer;

			// ���� :
			void * my_refUserContext;

		};

	}
}