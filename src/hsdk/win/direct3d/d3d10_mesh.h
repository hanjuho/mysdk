#pragma once



#include "d3d10_common.h"



namespace hsdk
{
	namespace direct3d
	{

		// ���� : 
		DECL_STRUCT(D3D10MY_MATERIAL)
		{

			// ���� : 
			std::wstring name;

			// ���� : 
			D3DXVECTOR4 diffuse;

			// ���� : 
			D3DXVECTOR4 ambient;

			// ���� : 
			D3DXVECTOR4 specular;

			// ���� : 
			D3DXVECTOR4 emissive;

			// ���� : 
			float shininess;

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
			unsigned int material_id;

			// ���� : 
			unsigned int indexStart;

			// ���� : 
			unsigned int indexCount;

			// ���� : 
			unsigned int vertexbufferStart;

			// ���� : 
			unsigned int vertexbufferCount;

			// ���� : 
			D3D10_PRIMITIVE_TOPOLOGY primitiveType;

		};

		// ���� : 
		DECL_STRUCT(D3D10MY_VERTEXBUFFER)
		{
			
			// ���� :
			unsigned int numOfVertices;

			// ���� : 
			AutoRelease<ID3D10Buffer> vertexbuffer;

			// ���� : 
			unsigned int vertexbuffers_Strides;

			// ���� : 
			unsigned int vertexbuffers_Offsets;

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
			std::vector<D3D10MY_RENDER_DESC> subsets;

			// ���� :
			D3D10MY_VERTEXBUFFER vetexbuffer;

			// ���� : 
			D3D10MY_INDEXBUFFER indexbuffer;

			// ���� :
			std::vector<unsigned int> boneNode;

			// ���� : 
			D3DXVECTOR3 boundingBox;

		};

		// ���� : 
		DECL_STRUCT(D3D10_Mesh)
		{

			// ���� : Keep track of the path
			std::wstring meshPath;

			// ���� : 
			std::vector<D3D10MY_MATERIAL> materials;

			// ���� :
			std::vector<D3D10MY_MESH> meshs;

		};

		namespace mesh
		{

			//���� :
			DECL_FUNC_T(void, meshClear)(
				_Out_ D3D10_Mesh & _mesh);

		}
	}
}