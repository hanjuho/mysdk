#pragma once



#include "d3d10_common.h"



namespace hsdk
{
	namespace direct3d
	{

		// ���� : 
		DLL_DECL_CLASS(D3D10_Mesh)
		{

		public:

			// ������.
			CLASS_DECL_CONSTRUCTOR(D3D10_Mesh)(
				_In_ CALLBACK_D3D10_CREATE_TEXTURE_FROMFILE _callback_Create_Texture_FromFile = nullptr,
				_In_ CALLBACK_D3D10_CREATE_VERTEXBUFFER _callback_Create_VertexBuffer = nullptr,
				_In_ CALLBACK_D3D10_CREATE_INDEXBUFFER _callback_Create_indexBuffer = nullptr,
				_In_ void * _userContext = nullptr);

			// �Ҹ���.
			CLASS_DECL_DESTRUCTOR(D3D10_Mesh)(void);

			// ���� : 
			DECL_FUNC_T(void, clear)(
				_X_ void);

			// ���� :
			DECL_FUNC(setup0)(
				_In_ unsigned int _numOfMaterials,
				_In_ unsigned int _numOfMeshs);

			// ���� : 
			DECL_FUNC(setup1_Texture)(
				_In_ const wchar_t * _directory,
				_In_ unsigned int _indexOfMaterial,
				_In_ unsigned int _attribute);

			// ���� : 
			DECL_FUNC(setup1_Texture)(
				_In_ unsigned int _indexOfMaterial,
				_In_ unsigned int _attribute,
				_In_ ID3D10ShaderResourceView * _resource);

			// ���� : 
			DECL_FUNC(setup1_Material)(
				_In_ unsigned int _indexOfMaterial,
				_In_ unsigned int _attribute,
				_In_ const D3DXVECTOR4 & _value);

			// ���� : 
			DECL_FUNC(setup1_Shininess)(
				_In_ unsigned int _indexOfMaterial,
				_In_ float _shininess);

			// ���� :
			DECL_FUNC(setup1_Mesh)(
				_In_ unsigned int _indexOfMesh,
				_In_ unsigned int _numOfRenderDescs,
				_In_ unsigned int _numOfVertexBuffers);

			// ���� :
			DECL_FUNC(setup2_RenderDesc)(
				_In_ unsigned int _indexOfMesh,
				_In_ unsigned int _indexOfRenderDesc,
				_In_ unsigned int _material_id,
				_In_ unsigned int _indexStart,
				_In_ unsigned int _indexCount,
				_In_ unsigned int _vertexbufferStart,
				_In_ unsigned int _vertexbufferCount,
				_In_ D3D10_PRIMITIVE_TOPOLOGY _primitiveType);

			// ���� : 
			DECL_FUNC(setup2_Vertexbuffer)(
				_In_ unsigned int _indexOfMesh,
				_In_ unsigned int _indexOfBuffer,
				_In_ const D3D10_BUFFER_DESC & _desc,
				_In_ const void * _vertices,
				_In_ unsigned int _stride,
				_In_ unsigned int _offset,
				_In_ unsigned int _numOfVertices = 0);

			// ���� : 
			DECL_FUNC(setup2_indexbuffer)(
				_In_ unsigned int _indexOfMesh,
				_In_ const D3D10_BUFFER_DESC & _desc,
				_In_ const void * _indices,
				_In_ DXGI_FORMAT _format,
				_In_ unsigned int _numOfindies = 0);

			// ���� : 
			DECL_FUNC(userSet_MeshPath)(
				_In_ const wchar_t * _directory);

			// ���� : 
			DECL_FUNC(userSet_MeshBoundingBox)(
				_In_ unsigned int _indexOfMesh,
				_In_ const D3DXVECTOR3 & _center,
				_In_ const D3DXVECTOR3 & _size);

			// ���� : 
			DECL_FUNC(userSet_MaterialName)(
				_In_ unsigned int _indexOfMaterial,
				_In_ const wchar_t * _name);

			//--------------------------------------------------------------------------------------
			//Helpers (general)
			//--------------------------------------------------------------------------------------

			// ���� : 
			DECL_FUNC(loadLock)(
				_X_ void);

			// ���� : 
			DECL_FUNC_T(long, is_Load)(
				_X_ void)const;

			// ���� : 
			DECL_FUNC_T(const wchar_t *, get_MeshPath)(
				_X_ void)const;

			// ���� : 
			DECL_FUNC_T(unsigned int, get_NumMeshes)(
				_X_ void)const;

			// ���� : 
			DECL_FUNC_T(unsigned int, get_NumMaterials)(
				_X_ void)const;

			// ���� : 
			DECL_FUNC_T(const D3D10MY_MATERIAL &, get_Material)(
				_In_ unsigned int _indexOfMaterial)const;

			// ���� : 
			DECL_FUNC_T(const D3D10MY_MESH &, get_Mesh)(
				_In_ unsigned int _indexOfMesh)const;

			// ���� : 
			DECL_FUNC_T(D3DXVECTOR3, get_Mesh_BBoxCenter)(
				_In_ unsigned int _indexOfMesh)const;

			// ���� : 
			DECL_FUNC_T(D3DXVECTOR3, get_Mesh_BBoxSize)(
				_In_ unsigned int _indexOfMesh)const;

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