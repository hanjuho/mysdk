#pragma once



#include "d3d10_common.h"



namespace hsdk
{
	namespace direct3d
	{

		// ���� : 
		DECL_STRUCT(D3D10MY_FONTINFO)
		{

			// ���� : 
			float left;

			// ���� : 
			float right;

			// ���� : 
			int size;

		};

		// ���� : 
		DECL_CLASS(D3D10_Font)
		{
		public:

			// ���� :
			INTERFACE_DECL_FUNC(initialize)(
				_In_ const char * _fontDirecoty,
				_In_ const wchar_t * _fontTableDirecoty);

			// ���� :
			INTERFACE_DECL_FUNC_T(void, destory)(
				_X_ void);

			// ���� : 
			INTERFACE_DECL_FUNC(build_Text)(
				_Out_ D3D10MY_CONTEXT & _context,
				_In_ const char * _text)const;

			// ���� : 
			INTERFACE_DECL_FUNC_T(ID3D10ShaderResourceView *, font)(
				_X_ void)const;

		private:

			// ���� : 
			INTERFACE_DECL_FUNC(create_ContexBuffer)(
				_Out_ ID3D10Buffer ** _buffer,
				_In_ unsigned int _width,
				_In_ D3D10_USAGE _usage = D3D10_USAGE_DEFAULT)const;

		protected:

			// ���� : 
			std::vector<D3D10MY_FONTINFO> my_DataTable;

			// ���� : 
			AutoRelease<ID3D10ShaderResourceView> my_Texture;

		};

	}
}
