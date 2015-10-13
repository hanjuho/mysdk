#pragma once



#include "d3d10_common.h"
#include "d3d10_mesh.h"
#include "direct3d.h"



//--------------------------------------------------------------------------------------
// Hard Defines for the various structures
//--------------------------------------------------------------------------------------
#define SDKMESH_FILE_VERSION 101
#define MAX_VERTEX_ELEMENTS 32
#define MAX_VERTEX_STREAMS 16
#define MAX_FRAME_NAME 100
#define MAX_MESH_NAME 100
#define MAX_SUBSET_NAME 100
#define MAX_MATERIAL_NAME 100
#define MAX_TEXTURE_NAME MAX_PATH
#define MAX_MATERIAL_PATH MAX_PATH



namespace hsdk
{
	namespace direct3d
	{

		// ���� : Enumerated Types.  These will have mirrors in both D3D9 and D3D10
		enum D3D10MESH_PRIMITIVE_TYPE
		{

			PT_TRIANGLE_LIST = 0,
			PT_TRIANGLE_STRIP,
			PT_LINE_LIST,
			PT_LINE_STRIP,
			PT_POINT_LIST,
			PT_TRIANGLE_LIST_ADJ,
			PT_TRIANGLE_STRIP_ADJ,
			PT_LINE_LIST_ADJ,
			PT_LINE_STRIP_ADJ,

		};

		// ���� : 
		enum D3D10MESH_INDEX_TYPE
		{

			IT_16BIT = 0,
			IT_32BIT,

		};

		// ���� : 
		enum D3D10FRAME_TRANSFORM_TYPE
		{

			FTT_RELATIVE = 0,

			// ���� : This is not currently used but is here to support absolute transformations in the future
			FTT_ABSOLUTE,

		};

		// ���� : Structures.  Unions with pointers are forced to 64bit.
		DECL_STRUCT(D3D10MESH_DESC)
		{

			// ���� : Basic Info and sizes
			unsigned int version;
			unsigned char isBigEndian;
			unsigned long long headerSize;
			unsigned long long nonBufferDataSize;
			unsigned long long bufferDataSize;

			// ���� : Stats
			unsigned int numVertexBuffers;
			unsigned int numindexBuffers;
			unsigned int numMeshes;
			unsigned int numTotalSubsets;
			unsigned int numFrames;
			unsigned int numMaterials;

			// ���� : Offsets to Data
			unsigned long long vertexStreamHeadersOffset;
			unsigned long long indexStreamHeadersOffset;
			unsigned long long meshDataOffset;
			unsigned long long subsetDataOffset;
			unsigned long long frameDataOffset;
			unsigned long long materialDataOffset;

		};

		// ���� : 
		DECL_STRUCT(D3D10MESH_VERTEX_BUFFER_DESC)
		{

			unsigned long long numVertices;
			unsigned long long sizeBytes;
			unsigned long long strideBytes;
			D3DVERTEXELEMENT9 decl[MAX_VERTEX_ELEMENTS];

			unsigned long long dataOffset;

		};

		// ���� : 
		DECL_STRUCT(D3D10MESH_INDEX_BUFFER_DESC)
		{

			unsigned long long numindices;
			unsigned long long sizeBytes;
			unsigned int indexType;

			unsigned long long dataOffset;

		};

		// ���� : 
		DECL_STRUCT(D3D10MESH_MESH)
		{

			wchar_t name[MAX_MESH_NAME];
			unsigned char numVertexBuffers;
			unsigned int vertexBuffers[MAX_VERTEX_STREAMS];
			unsigned int indexBuffer;
			unsigned int numSubsets;

			// ���� : aka bones
			unsigned int numFrame_influences;

			D3DXVECTOR3 BoundingBoxCenter;
			D3DXVECTOR3 BoundingBoxExtents;

			union
			{
				// ���� :Offset to list of subsets (This also forces the union to 64bits)
				unsigned long long subsetOffset;

				// ���� :Pointer to list of subsets
				unsigned int * subsets;
			};

			union
			{
				// ���� :Offset to list of frame influences (This also forces the union to 64bits)
				unsigned long long frame_influenceOffset;

				// ���� :Pointer to list of frame influences
				unsigned int * frame_influences;
			};

		};

		// ���� : 
		DECL_STRUCT(D3D10MESH_SUBSET)
		{

			wchar_t name[MAX_SUBSET_NAME];
			unsigned int material_id;
			unsigned int primitiveType;
			unsigned long long indexStart;
			unsigned long long indexCount;
			unsigned long long vertexStart;
			unsigned long long vertexCount;

		};

		// ���� : 
		DECL_STRUCT(D3D10MESH_FRAME)
		{

			wchar_t name[MAX_FRAME_NAME];
			unsigned int mesh;
			unsigned int parentFrame;
			unsigned int childFrame;
			unsigned int siblingFrame;
			D3DXMATRIX matrix;

			// ���� : Used to index which set of keyframes transforms this frame
			unsigned int animationDataIndex;

		};

		// ���� : 
		DECL_STRUCT(D3D10MESH_MATERIAL)
		{

			wchar_t name[MAX_MATERIAL_NAME];

			// Use MaterialInstancePath
			wchar_t materialInstancePath[MAX_MATERIAL_PATH];

			// Or fall back to d3d8-type materials
			wchar_t szDiffuseTexture[MAX_TEXTURE_NAME];
			wchar_t szNormalTexture[MAX_TEXTURE_NAME];
			wchar_t szSpecularTexture[MAX_TEXTURE_NAME];

			D3DXVECTOR4 diffuse;
			D3DXVECTOR4 ambient;
			D3DXVECTOR4 specular;
			D3DXVECTOR4 emissive;

			float power;
		};

		// ���� : 
		DECL_STRUCT(D3D10ANIMATION_FILE_DESC)
		{

			unsigned int version;
			unsigned char isBigEndian;
			unsigned int frameTransformType;
			unsigned int numFrames;
			unsigned int numAnimationKeys;
			unsigned int animationFPS;
			unsigned long long animationDataSize;
			unsigned long long animationDataOffset;

		};

		// ���� : 
		DECL_STRUCT(D3D10ANIMATION_DATA)
		{

			D3DXVECTOR3 translation;
			D3DXVECTOR4 orientation;
			D3DXVECTOR3 scaling;

		};

		// ���� : 
		DECL_STRUCT(D3D10ANIMATION_FRAME_DATA)
		{

			wchar_t frameName[MAX_FRAME_NAME];

			unsigned long long dataOffset;
			D3D10ANIMATION_DATA * animationData;

		};

		// ���� :
		enum D3D10SAMPLER_STATE
		{
			SAMPLER_DEFAULT
		};


		// ���� : 
		inline D3D10_PRIMITIVE_TOPOLOGY convert_PrimitiveType(
			D3D10MESH_PRIMITIVE_TYPE PrimType)
		{
			switch (PrimType)
			{

			case PT_TRIANGLE_LIST:

				return D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST;

			case PT_TRIANGLE_STRIP:

				return D3D10_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP;

			case PT_LINE_LIST:

				return D3D10_PRIMITIVE_TOPOLOGY_LINELIST;

			case PT_LINE_STRIP:

				return D3D10_PRIMITIVE_TOPOLOGY_LINESTRIP;

			case PT_POINT_LIST:

				return D3D10_PRIMITIVE_TOPOLOGY_POINTLIST;

			case PT_TRIANGLE_LIST_ADJ:

				return D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ;

			case PT_TRIANGLE_STRIP_ADJ:

				return D3D10_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP_ADJ;

			case PT_LINE_LIST_ADJ:

				return D3D10_PRIMITIVE_TOPOLOGY_LINELIST_ADJ;

			case PT_LINE_STRIP_ADJ:

				return D3D10_PRIMITIVE_TOPOLOGY_LINESTRIP_ADJ;

			default:

				return D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST;

			};
		}

		// ���� : 
		DLL_DECL_CLASS(D3D10_Manager)
			: public Direct3D
		{
		public:

			//--------------------------------------------------------------------------------------
			//
			//--------------------------------------------------------------------------------------

			// ���� :
			CLASS_DECL_FUNC(initialize_Manager)(
				/* [x] */ void);

			//--------------------------------------------------------------------------------------
			//
			//--------------------------------------------------------------------------------------

			// ���� :
			CLASS_DECL_FUNC(get_Rasterize)(
				/* [w] */ ID3D10RasterizerState ** _rasterize,
				/* [r] */ D3D10_CULL_MODE _cullmode,
				/* [r] */ D3D10_FILL_MODE _fillmode)
			{
				return E_FAIL;
			}

			// ���� :
			CLASS_DECL_FUNC(get_Sampler)(
				/* [w] */ ID3D10SamplerState ** _sampler,
				/* [r] */ D3D10SAMPLER_STATE _state)
			{
				return E_FAIL;
			}

			// ���� : _directory�� �ִ� pixel file�� �ε�.
			CLASS_DECL_FUNC(get_Texture)(
				/* [w] */ ID3D10ShaderResourceView ** _texture,
				/* [r] */ const wchar_t * _directory)
			{
				return E_FAIL;
			}

			//--------------------------------------------------------------------------------------
			//
			//--------------------------------------------------------------------------------------

			/*
			���� : ����� ���� UV ��ǥ�� ���� ���ؽ� ���� ����.
			$ ���� : ���ؽ�(float3, float2) * 4.
			*/
			CLASS_DECL_FUNC(create_Panel)(
				/* [w] */ ID3D10Buffer ** _buffer,
				/* [r] */ const XMFLOAT2(&_uvs)[4],
				/* [r] */ D3D10_USAGE _usage)
			{
				return E_FAIL;
			}

			/*
			���� : ����� ���� UV ��ǥ�� ���� ���ؽ� ���� ����.
			$ ���� : ���ؽ�(float3, float2) * 4.
			*/
			CLASS_DECL_FUNC(create_SkyBox)(
				/* [w] */ ID3D10Buffer ** _buffer,
				/* [r] */ const XMFLOAT2(&_uvs)[4],
				/* [r] */ D3D10_USAGE _usage)
			{
				return E_FAIL;
			}

			// ���� : 
			CLASS_DECL_FUNC(create_MeshFromFile)(
				/* [w] */ D3D10_Mesh & _mesh,
				/* [r] */ const wchar_t * _szFileName,
				/* [r] */ bool _createAdjacencyIndices);

			// ���� : 
			CLASS_DECL_FUNC(create_MeshFromMemory)(
				/* [w] */ D3D10_Mesh & _mesh,
				/* [r] */ const wchar_t * _resourcePath,
				/* [r] */ unsigned char * _data,
				/* [r] */ unsigned int _dataBytes,
				/* [r] */ bool _createAdjacencyIndices);

		};

	}
}