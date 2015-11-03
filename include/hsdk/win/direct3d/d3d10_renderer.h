#pragma once



#include "d3d10_common.h"
#include "d3d10_mesh.h"
#include "d3d10_animation.h"



namespace hsdk
{
	namespace direct3d
	{

		// Ό³Έν : 
		enum VS_FLAG
		{

			// Ό³Έν : 
			VS_CALLFUNCTION_0 = 1024

		};

		// Ό³Έν : 
		enum PS_FLAG
		{

			// diffuse
			PS_TEXTURE_0 = 1,

			// normal
			PS_TEXTURE_1 = 2,

			// specular
			PS_TEXTURE_2 = 4,

			// ΉΜΑ€
			PS_TEXTURE_3 = 8,

			// diffuse
			PS_MARERIAL_0 = 16,

			// ambient
			PS_MARERIAL_1 = 32,

			// specular
			PS_MARERIAL_2 = 64,

			// emissive
			PS_MARERIAL_3 = 128,

			// 
			PS_LIGHT = 256,

			// 
			PS_CALLFUNCTION_0 = 4096,

			// Ό³Έν : 
			PS_TEXMATRIX_0 = 65536

		};

		// Ό³Έν :
		DECL_STRUCT(D3D10_RenderVariable)
		{

			//-----------------------------------------------------------------------------------------
			// Globals
			//-----------------------------------------------------------------------------------------

			// World matrix for object
			ID3D10EffectMatrixVariable * mWorld;

			// View matrix for object
			ID3D10EffectMatrixVariable * mView;

			// Projection matrix for object
			ID3D10EffectMatrixVariable * mProj;

			// World * View matrix
			ID3D10EffectMatrixVariable * mWorldView;

			// World * View * Projection matrix
			ID3D10EffectMatrixVariable * mWorldViewProj;

			//
			ID3D10EffectMatrixVariable * mTexture;

			//-----------------------------------------------------------------------------------------
			// Color
			//-----------------------------------------------------------------------------------------

			// Ό³Έν : 
			ID3D10EffectVectorVariable * vDiffuse;

			// Ό³Έν : 
			ID3D10EffectVectorVariable * vAmbient;

			// Ό³Έν : 
			ID3D10EffectVectorVariable * vSpecular;

			// Ό³Έν : 
			ID3D10EffectVectorVariable * vEmissive;

			// Ό³Έν : 
			ID3D10EffectScalarVariable * shininess;

			//-----------------------------------------------------------------------------------------
			// light
			//-----------------------------------------------------------------------------------------

			// Ό³Έν : 
			ID3D10EffectVectorVariable * vLightDir;

			//-----------------------------------------------------------------------------------------
			// Texture
			//-----------------------------------------------------------------------------------------

			// Ό³Έν : 
			ID3D10EffectShaderResourceVariable * texDiffuse;

			// Ό³Έν : 
			ID3D10EffectShaderResourceVariable * texNormal;

			// Ό³Έν : 
			ID3D10EffectShaderResourceVariable * texSpecular;

			//-----------------------------------------------------------------------------------------
			// SkyBox
			//-----------------------------------------------------------------------------------------

			// Ό³Έν : 
			ID3D10EffectMatrixVariable * mSkyBox;

			// Ό³Έν : 
			ID3D10EffectShaderResourceVariable * texSkyBox;

			//-----------------------------------------------------------------------------------------
			// Bone
			//-----------------------------------------------------------------------------------------

			// Ό³Έν : 
			ID3D10EffectMatrixVariable * mBone;

			//-----------------------------------------------------------------------------------------
			// flag, parameter
			//-----------------------------------------------------------------------------------------

			// Ό³Έν : 
			ID3D10EffectScalarVariable * vsFlag;

			// Ό³Έν : 
			ID3D10EffectScalarVariable * vsTime;

			// Ό³Έν : 
			ID3D10EffectScalarVariable * psFlag;

			// Ό³Έν : 
			ID3D10EffectScalarVariable * psTime;

		};

		// Ό³Έν :
		DLL_DECL_CLASS(D3D10_Renderer)
		{

		public:

			// Ό³Έν :
			CLASS_DECL_FUNC(initialize)(
				_X_ const wchar_t * _shaderFilePath);

			// Ό³Έν :
			CLASS_DECL_FUNC_T(void, destroy)(
				_X_ void);

			// Ό³Έν :
			CLASS_DECL_FUNC_T(void, render_Skinned)(
				_In_ D3D10_Mesh & _mesh,
				_In_ D3D10_Animation & _animation,
				_In_ D3D10_Animation_Recorder & _pos,
				_In_ unsigned int _pass = 0);

			// Ό³Έν :
			CLASS_DECL_FUNC_T(void, render_Mesh)(
				_In_ D3D10_Mesh & _mesh);

			// Ό³Έν :
			CLASS_DECL_FUNC_T(void, render_SkyBox)(
				_In_ D3D10_Mesh & _mesh);

			// Ό³Έν :
			CLASS_DECL_FUNC_T(void, render_UITexture)(
				_In_ ID3D10ShaderResourceView * _texture,
				_In_ const D3DXMATRIX * _texcoord);

			// Ό³Έν :
			CLASS_DECL_FUNC_T(void, render_UIRectangle)(
				_In_ D3DXVECTOR4 * _color);

			// Ό³Έν :
			CLASS_DECL_FUNC_T(void, render_Font)(
				_In_ D3D10MY_CONTEXT & _context,
				_In_ ID3D10ShaderResourceView * _fontTable);

			// Ό³Έν : 
			DECL_FUNC_T(void, set_MatrixWorld)(
				_In_ const D3DXMATRIX * _matrix);

			// Ό³Έν : 
			DECL_FUNC_T(void, set_MatrixView)(
				_In_ const D3DXMATRIX * _matrix);

			// Ό³Έν : 
			DECL_FUNC_T(void, set_MatrixProj)(
				_In_ const D3DXMATRIX * _matrix);

			// Ό³Έν : 
			DECL_FUNC_T(void, set_MatrixWorldView)(
				_In_ const D3DXMATRIX * _matrix);

			// Ό³Έν : 
			DECL_FUNC_T(void, set_MatrixWorldViewProj)(
				_In_ const D3DXMATRIX * _matrix);

			// Ό³Έν : 
			DECL_FUNC_T(void, set_MatrixTexture)(
				_In_ const D3DXMATRIX * _matrix);

			// Ό³Έν : 
			DECL_FUNC_T(void, set_ColorDiffuse)(
				_In_ float * _color);

			// Ό³Έν : 
			DECL_FUNC_T(void, set_ColorAmbient)(
				_In_ float * _color);

			// Ό³Έν : 
			DECL_FUNC_T(void, set_ColorSpecular)(
				_In_ float * _color);

			// Ό³Έν : 
			DECL_FUNC_T(void, set_ColorEmissive)(
				_In_ float * _color);

			// Ό³Έν : 
			DECL_FUNC_T(void, set_ScalarShininess)(
				_In_ float _value);

			// Ό³Έν : 
			DECL_FUNC_T(void, set_LightDir)(
				_In_ float * _color);

			// Ό³Έν : 
			DECL_FUNC_T(void, set_TextureDiffuse)(
				_In_ ID3D10ShaderResourceView * _texture);

			// Ό³Έν : 
			DECL_FUNC_T(void, set_TextureNormal)(
				_In_ ID3D10ShaderResourceView * _texture);

			// Ό³Έν : 
			DECL_FUNC_T(void, set_TextureSpecular)(
				_In_ ID3D10ShaderResourceView * _texture);

			// Ό³Έν : 
			DECL_FUNC_T(void, set_MatrixSkyBox)(
				_In_ const D3DXMATRIX * _matrix);

			// Ό³Έν : 
			DECL_FUNC_T(void, set_TextureSkyBox)(
				_In_ ID3D10ShaderResourceView * _texture);

			// Ό³Έν : 
			DECL_FUNC_T(void, set_MatricesBone)(
				_In_ const D3DXMATRIX * _matrices,
				_In_ unsigned int _size);

			// Ό³Έν : 
			DECL_FUNC_T(void, set_ScalarVSFlag)(
				_In_ unsigned int _value);

			// Ό³Έν : 
			DECL_FUNC_T(void, set_ScalarVSTime)(
				_In_ float _value);

			// Ό³Έν : 
			DECL_FUNC_T(void, set_ScalarPSFlag)(
				_In_ unsigned int _value);

			// Ό³Έν : 
			DECL_FUNC_T(void, set_ScalarPSTime)(
				_In_ float _value);

		private:

			// Ό³Έν :
			CLASS_DECL_FUNC(initialize_Shader)(
				_X_ const wchar_t * _directory);

			// Ό³Έν :
			CLASS_DECL_FUNC(initialize_Layout)(
				_X_ void);

			// Ό³Έν :
			CLASS_DECL_FUNC(initialize_TextureCacheBuffer)(
				_X_ void);

		};

		// Ό³Έν : 
		extern HSDK_DLL D3D10_Renderer g_D3D10_Renderer;

		// Ό³Έν : 
		extern HSDK_DLL const D3D10_RenderVariable & g_D3D10_RenderVariable;

		// Ό³Έν :
		extern HSDK_DLL const D3DXMATRIX g_D3D10_identityMatrix;

		// Ό³Έν :
		extern HSDK_DLL D3DXMATRIX g_D3D10_ViewMatrix;

		// Ό³Έν :
		extern HSDK_DLL D3DXMATRIX g_D3D10_ProjMatrix;

		// Ό³Έν :
		extern HSDK_DLL D3DXMATRIX g_D3D10_ViewProjMatrix;

	}
}