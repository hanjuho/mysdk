#pragma once



#include "d3d10_common.h"
#include "d3d10_mesh.h"



namespace hsdk
{
	namespace direct3d
	{

		// 설명 :
		DLL_DECL_CLASS(D3D10_Renderer)
		{

		public:

			// 설명 :
			CLASS_DECL_FUNC(initialize)(
				_X_ const wchar_t * _shaderFilePath);

			// 설명 :
			CLASS_DECL_FUNC_T(void, destroy)(
				_X_ void);

			// 설명 :
			CLASS_DECL_FUNC_T(void, render_Skinned)(
				_In_ D3DXMATRIX & _world,
				_In_ const D3D10_Mesh & _mesh,
				_In_ D3DXMATRIX * _boneMatrixs,
				_In_ unsigned int _matrixSize);

			// 설명 :
			CLASS_DECL_FUNC_T(void, render_SkyBox)(
				_In_ D3DXMATRIX & _world,
				_In_ const D3D10_Mesh & _mesh);

			// 설명 :
			CLASS_DECL_FUNC_T(void, render_UIRectangle)(
				_In_ D3DXMATRIX & _world,
				_In_ D3DXVECTOR4 & _color,
				_In_ float _persent = 1.0f);

			// 설명 :
			CLASS_DECL_FUNC_T(void, render_UITexture)(
				_In_ D3DXMATRIX & _world,
				_In_ ID3D10ShaderResourceView * _texture,
				_In_ D3DXMATRIX & _texcoord,
				_In_ float _persent = 1.0f);
			
			// 설명 :
			CLASS_DECL_FUNC_T(void, render_Font)(
				_In_ D3DXMATRIX & _world,
				_In_ D3D10MY_CONTEXT & _context,
				_In_ ID3D10ShaderResourceView * _fontTable,
				_In_ float _persent = 1.0f);

		private:

			// 설명 :
			CLASS_DECL_FUNC(initialize_Shader)(
				_X_ const wchar_t * _directory);

			// 설명 :
			CLASS_DECL_FUNC(initialize_Layout)(
				_X_ void);

		};

		// 설명 : 
		extern HSDK_DLL D3D10_Renderer g_D3D10_Renderer;

		// 설명 :
		extern HSDK_DLL D3DXMATRIX g_D3D10_ViewMatrix;

		// 설명 :
		extern HSDK_DLL D3DXMATRIX g_D3D10_ProjMatrix;

	}
}