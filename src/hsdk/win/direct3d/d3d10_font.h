#pragma once



#include "d3d10_common.h"



namespace hsdk
{
	namespace direct3d
	{

		// 설명 : 
		DECL_STRUCT(D3D10MY_FONTINFO)
		{

			// 설명 : 
			float left;

			// 설명 : 
			float right;

			// 설명 : 
			int size;

		};

		// 설명 : 
		DECL_CLASS(D3D10_Font)
		{
		public:

			// 설명 :
			INTERFACE_DECL_FUNC(initialize)(
				_In_ const char * _fontDirecoty,
				_In_ const wchar_t * _fontTableDirecoty);

			// 설명 :
			INTERFACE_DECL_FUNC_T(void, destory)(
				_X_ void);

			// 설명 : 
			INTERFACE_DECL_FUNC(build_Text)(
				_Out_ D3D10MY_CONTEXT & _context,
				_In_ const char * _text)const;

			// 설명 : 
			INTERFACE_DECL_FUNC_T(ID3D10ShaderResourceView *, font)(
				_X_ void)const;

		private:

			// 설명 : 
			INTERFACE_DECL_FUNC(create_ContexBuffer)(
				_Out_ ID3D10Buffer ** _buffer,
				_In_ unsigned int _width,
				_In_ D3D10_USAGE _usage = D3D10_USAGE_DEFAULT)const;

		protected:

			// 설명 : 
			std::vector<D3D10MY_FONTINFO> my_DataTable;

			// 설명 : 
			AutoRelease<ID3D10ShaderResourceView> my_Texture;

		};

	}
}
