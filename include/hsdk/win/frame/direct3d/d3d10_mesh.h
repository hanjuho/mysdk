#pragma once



#include "d3d10_common.h"



namespace hsdk
{
	namespace direct3d
	{

		// 설명 : 
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
			DECL_FUNC_T(void, clear)(
				/* [x] */ void);

			// 설명 :
			DECL_FUNC(setup0)(
				/* [r] */ unsigned int _numOfMaterials,
				/* [r] */ unsigned int _numOfMeshs);

			// 설명 : 
			DECL_FUNC(setup1_Texture)(
				/* [r] */ const wchar_t * _directory,
				/* [r] */ unsigned int _indexOfMaterial,
				/* [r] */ unsigned int _attribute);

			// 설명 : 
			DECL_FUNC(setup1_Texture)(
				/* [r] */ unsigned int _indexOfMaterial,
				/* [r] */ unsigned int _attribute,
				/* [r] */ ID3D10ShaderResourceView * _resource);

			// 설명 : 
			DECL_FUNC(setup1_Material)(
				/* [r] */ unsigned int _indexOfMaterial,
				/* [r] */ unsigned int _attribute,
				/* [r] */ const D3DXVECTOR4 & _value);

			// 설명 : 
			DECL_FUNC(setup1_Shininess)(
				/* [r] */ unsigned int _indexOfMaterial,
				/* [r] */ float _shininess);

			// 설명 :
			DECL_FUNC(setup1_Mesh)(
				/* [r] */ unsigned int _indexOfMesh,
				/* [r] */ unsigned int _numOfRenderDescs,
				/* [r] */ unsigned int _numOfVertexBuffers);

			// 설명 :
			DECL_FUNC(setup2_RenderDesc)(
				/* [r] */ unsigned int _indexOfMesh,
				/* [r] */ unsigned int _indexOfRenderDesc,
				/* [r] */ unsigned int _material_id,
				/* [r] */ unsigned int _indexStart,
				/* [r] */ unsigned int _indexCount,
				/* [r] */ unsigned int _vertexbufferStart,
				/* [r] */ unsigned int _vertexbufferCount,
				/* [r] */ D3D10_PRIMITIVE_TOPOLOGY _primitiveType);

			// 설명 : 
			DECL_FUNC(setup2_Vertexbuffer)(
				/* [r] */ unsigned int _indexOfMesh,
				/* [r] */ unsigned int _indexOfBuffer,
				/* [r] */ const D3D10_BUFFER_DESC & _desc,
				/* [r] */ const void * _vertices,
				/* [r] */ unsigned int _stride,
				/* [r] */ unsigned int _offset,
				/* [r] */ unsigned int _numOfVertices = 0);

			// 설명 : 
			DECL_FUNC(setup2_indexbuffer)(
				/* [r] */ unsigned int _indexOfMesh,
				/* [r] */ const D3D10_BUFFER_DESC & _desc,
				/* [r] */ const void * _indices,
				/* [r] */ DXGI_FORMAT _format,
				/* [r] */ unsigned int _numOfindies = 0);

			// 설명 : 
			DECL_FUNC(userSet_MeshPath)(
				/* [r] */ const wchar_t * _directory);

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