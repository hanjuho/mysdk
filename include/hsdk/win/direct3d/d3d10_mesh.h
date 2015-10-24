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
				_In_ CALLBACK_D3D10_CREATE_TEXTURE_FROMFILE _callback_Create_Texture_FromFile = nullptr,
				_In_ CALLBACK_D3D10_CREATE_VERTEXBUFFER _callback_Create_VertexBuffer = nullptr,
				_In_ CALLBACK_D3D10_CREATE_INDEXBUFFER _callback_Create_indexBuffer = nullptr,
				_In_ void * _userContext = nullptr);

			// 소멸자.
			CLASS_DECL_DESTRUCTOR(D3D10_Mesh)(void);

			// 설명 : 
			DECL_FUNC_T(void, clear)(
				_X_ void);

			// 설명 :
			DECL_FUNC(setup0)(
				_In_ unsigned int _numOfMaterials,
				_In_ unsigned int _numOfMeshs);

			// 설명 : 
			DECL_FUNC(setup1_Texture)(
				_In_ const wchar_t * _directory,
				_In_ unsigned int _indexOfMaterial,
				_In_ unsigned int _attribute);

			// 설명 : 
			DECL_FUNC(setup1_Texture)(
				_In_ unsigned int _indexOfMaterial,
				_In_ unsigned int _attribute,
				_In_ ID3D10ShaderResourceView * _resource);

			// 설명 : 
			DECL_FUNC(setup1_Material)(
				_In_ unsigned int _indexOfMaterial,
				_In_ unsigned int _attribute,
				_In_ const D3DXVECTOR4 & _value);

			// 설명 : 
			DECL_FUNC(setup1_Shininess)(
				_In_ unsigned int _indexOfMaterial,
				_In_ float _shininess);

			// 설명 :
			DECL_FUNC(setup1_Mesh)(
				_In_ unsigned int _indexOfMesh,
				_In_ unsigned int _numOfRenderDescs,
				_In_ unsigned int _numOfVertexBuffers);

			// 설명 :
			DECL_FUNC(setup2_RenderDesc)(
				_In_ unsigned int _indexOfMesh,
				_In_ unsigned int _indexOfRenderDesc,
				_In_ unsigned int _material_id,
				_In_ unsigned int _indexStart,
				_In_ unsigned int _indexCount,
				_In_ unsigned int _vertexbufferStart,
				_In_ unsigned int _vertexbufferCount,
				_In_ D3D10_PRIMITIVE_TOPOLOGY _primitiveType);

			// 설명 : 
			DECL_FUNC(setup2_Vertexbuffer)(
				_In_ unsigned int _indexOfMesh,
				_In_ unsigned int _indexOfBuffer,
				_In_ const D3D10_BUFFER_DESC & _desc,
				_In_ const void * _vertices,
				_In_ unsigned int _stride,
				_In_ unsigned int _offset,
				_In_ unsigned int _numOfVertices = 0);

			// 설명 : 
			DECL_FUNC(setup2_indexbuffer)(
				_In_ unsigned int _indexOfMesh,
				_In_ const D3D10_BUFFER_DESC & _desc,
				_In_ const void * _indices,
				_In_ DXGI_FORMAT _format,
				_In_ unsigned int _numOfindies = 0);

			// 설명 : 
			DECL_FUNC(userSet_MeshPath)(
				_In_ const wchar_t * _directory);

			// 설명 : 
			DECL_FUNC(userSet_MeshBoundingBox)(
				_In_ unsigned int _indexOfMesh,
				_In_ const D3DXVECTOR3 & _center,
				_In_ const D3DXVECTOR3 & _size);

			// 설명 : 
			DECL_FUNC(userSet_MaterialName)(
				_In_ unsigned int _indexOfMaterial,
				_In_ const wchar_t * _name);

			//--------------------------------------------------------------------------------------
			//Helpers (general)
			//--------------------------------------------------------------------------------------

			// 설명 : 
			DECL_FUNC(loadLock)(
				_X_ void);

			// 설명 : 
			DECL_FUNC_T(long, is_Load)(
				_X_ void)const;

			// 설명 : 
			DECL_FUNC_T(const wchar_t *, get_MeshPath)(
				_X_ void)const;

			// 설명 : 
			DECL_FUNC_T(unsigned int, get_NumMeshes)(
				_X_ void)const;

			// 설명 : 
			DECL_FUNC_T(unsigned int, get_NumMaterials)(
				_X_ void)const;

			// 설명 : 
			DECL_FUNC_T(const D3D10MY_MATERIAL &, get_Material)(
				_In_ unsigned int _indexOfMaterial)const;

			// 설명 : 
			DECL_FUNC_T(const D3D10MY_MESH &, get_Mesh)(
				_In_ unsigned int _indexOfMesh)const;

			// 설명 : 
			DECL_FUNC_T(D3DXVECTOR3, get_Mesh_BBoxCenter)(
				_In_ unsigned int _indexOfMesh)const;

			// 설명 : 
			DECL_FUNC_T(D3DXVECTOR3, get_Mesh_BBoxSize)(
				_In_ unsigned int _indexOfMesh)const;

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