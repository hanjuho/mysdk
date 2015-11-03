#pragma once



#include "d3d10_common.h"
#include "d3d10_mesh.h"
#include "d3d10_animation.h"
#include "d3d10_terrain.h"



namespace hsdk
{
	namespace direct3d
	{

		// 설명 :
		enum D3D10SAMPLER_STATE
		{
			SAMPLER_DEFAULT
		};

		// 설명 : 
		DLL_DECL_CLASS(D3D10_Factory)
		{
		public:

			// 설명 :
			CLASS_DECL_FUNC_T(void, clear)(
				_X_ void);

			// 설명 :
			CLASS_DECL_FUNC(get_Rasterize)(
				_Out_ ID3D10RasterizerState ** _rasterize,
				_In_ D3D10_CULL_MODE _cullmode,
				_In_ D3D10_FILL_MODE _fillmode)
			{
				return E_FAIL;
			}

			// 설명 :
			CLASS_DECL_FUNC(get_Sampler)(
				_Out_ ID3D10SamplerState ** _sampler,
				_In_ D3D10SAMPLER_STATE _state)
			{
				return E_FAIL;
			}

			// 설명 : _directory에 있는 pixel file을 로드.
			CLASS_DECL_FUNC(get_Texture)(
				_Out_ ID3D10ShaderResourceView ** _texture,
				_In_ const wchar_t * _directory,
				_In_ const D3DX10_IMAGE_INFO ** _info = nullptr);

			// 설명 :
			CLASS_DECL_FUNC_T(const D3DX10_IMAGE_INFO *, get_Texture_info)(
				_In_ const wchar_t * _directory);
			
			// 설명 :
			CLASS_DECL_FUNC(create_Texture)(
				_Out_ ID3D10ShaderResourceView ** _texture,
				_In_ const wchar_t * _directory);

			// 설명 : 
			CLASS_DECL_FUNC(create_SkyBoxTexture)(
				_Out_ ID3D10ShaderResourceView ** _texture,
				_In_ unsigned int _width,
				_In_ unsigned int _height,
				_In_ const wchar_t * _front,
				_In_ const wchar_t * _back, 
				_In_ const wchar_t * _left, 
				_In_ const wchar_t * _right, 
				_In_ const wchar_t * _top,
				_In_ const wchar_t * _bottom);

			// 설명 : 
			CLASS_DECL_FUNC(build_MeshBox)(
				_Out_ D3D10_Mesh & _mesh,
				_In_ D3DXVECTOR4 color,
				_In_ float _size);

			// 설명 : 
			CLASS_DECL_FUNC(build_MeshTerran)(
				_Out_ D3D10_Mesh & _mesh,
				_In_ const D3D10_Terrain & _terrain,
				_In_ const float * _heightbuffer);

			// 설명 : 
			CLASS_DECL_FUNC(build_MeshSkyBox)(
				_Out_ D3D10_Mesh & _mesh,
				_In_ float _size);

			// 설명 : 
			CLASS_DECL_FUNC(build_MeshFromFile)(
				_Out_ D3D10_Mesh & _mesh,
				_In_ const wchar_t * _szFilePath,
				_In_ const wchar_t * _szFileName,
				_Out_ D3D10_Animation * _meshAnimation = nullptr);

		};

		// 설명 :
		extern HSDK_DLL D3D10_Factory g_D3D10_Factory;

	}
}