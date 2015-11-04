#pragma once



#include "d3d10_common.h"



namespace hsdk
{
	namespace direct3d
	{

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
			float shininess;

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
			unsigned int material_id;

			// 설명 : 
			unsigned int indexStart;

			// 설명 : 
			unsigned int indexCount;

			// 설명 : 
			unsigned int vertexbufferStart;

			// 설명 : 
			unsigned int vertexbufferCount;

			// 설명 : 
			D3D10_PRIMITIVE_TOPOLOGY primitiveType;

		};

		// 설명 : 
		DECL_STRUCT(D3D10MY_VERTEXBUFFER)
		{
			
			// 설명 :
			unsigned int numOfVertices;

			// 설명 : 
			AutoRelease<ID3D10Buffer> vertexbuffer;

			// 설명 : 
			unsigned int vertexbuffers_Strides;

			// 설명 : 
			unsigned int vertexbuffers_Offsets;

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
			std::vector<D3D10MY_RENDER_DESC> subsets;

			// 설명 :
			D3D10MY_VERTEXBUFFER vetexbuffer;

			// 설명 : 
			D3D10MY_INDEXBUFFER indexbuffer;

			// 설명 :
			std::vector<unsigned int> boneNode;

			// 설명 : 
			D3DXVECTOR3 boundingBox;

		};

		// 설명 : 
		DECL_STRUCT(D3D10_Mesh)
		{

			// 설명 : Keep track of the path
			std::wstring meshPath;

			// 설명 : 
			std::vector<D3D10MY_MATERIAL> materials;

			// 설명 :
			std::vector<D3D10MY_MESH> meshs;

		};

		namespace mesh
		{

			//설명 :
			DECL_FUNC_T(void, meshClear)(
				_Out_ D3D10_Mesh & _mesh);

		}
	}
}