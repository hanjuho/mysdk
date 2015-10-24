//--------------------------------------------------------------------------------------
// File: WICTextureLoader.h
//
// Function for loading a WIC image and creating a Direct3D 11 runtime texture for it
// (auto-generating mipmaps if possible)
//
// Note: Assumes application has already called CoInitializeEx
//
// Warning: CreateWICTexture* functions are not thread-safe if given a d3dContext instance for
//          auto-gen mipmap support.
//
// Note these functions are useful for images created as simple 2D textures. For
// more complex resources, DDSTextureLoader is an excellent light-weight runtime loader.
// For a full-featured DDS file reader, writer, and texture processing pipeline see
// the 'Texconv' sample and the 'DirectXTex' library.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//
// http://go.microsoft.com/fwlink/?LinkId=248926
// http://go.microsoft.com/fwlink/?LinkId=248929
//--------------------------------------------------------------------------------------

#ifdef _MSC_VER
#pragma once
#endif

#include "common.h"

#if defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP) && (_WIN32_WINNT <= _WIN32_WINNT_WIN8)
#error WIC is not supported on Windows Phone 8.0
#endif

#pragma warning(push)
#pragma warning(disable : 4005)
#include <stdint.h>
#pragma warning(pop)

#if defined(_MSC_VER) && (_MSC_VER<1610) && !defined(_In_reads_)
#define _In_reads_(exp)
#define _Out_writes_(exp)
#define _In_reads_bytes_(exp)
#endif

#ifndef _Use_decl_annotations_
#define _Use_decl_annotations_
#endif

namespace DirectX
{
	class Image
	{
	private:
		void * m_data;
		void(*m_deleter)(void*);
		DXGI_FORMAT m_format;
		int m_width;
		int m_height;
		int m_rowPitch;

		// 동적 메모리를 내부에서 관리하기 때문에 복사가 비효율 적임으로 막는다
		inline Image(const Image &); // delete
		inline Image& operator =(const Image &); // delete

	public:

		// 데이터
		// 초기화가 안되어있으면 NULL을 갖는다
		inline void * getData()
		{
			return m_data;
		}

		// 넓이
		// 초기화가 안되어있으면 쓰레기 값을 갖는다
		inline int getWidth()
		{
			return m_width;
		}

		// 높이
		// 초기화가 안되어있으면 쓰레기 값을 갖는다
		inline int getHeight()
		{
			return m_height;
		}

		// 넓이 바이트
		// 초기화가 안되어있으면 쓰레기 값을 갖는다
		inline int getRowPitch()
		{
			return m_rowPitch;
		}

		// 전체 바이트
		// 초기화가 안되어있으면 쓰레기 값을 갖는다
		inline size_t getSize()
		{
			return m_height * m_rowPitch;
		}

		// 텍스처 포맷
		// 초기화가 안되어있으면 쓰레기 값을 갖는다
		inline DXGI_FORMAT getFormat()
		{
			return m_format;
		}

		// data 를 복사하여 내부에서 동적할당 한다
		inline Image(const void * data, DXGI_FORMAT format, int width, int height, int rowPitch)
		{
			size_t size = rowPitch * height;
			m_data = malloc(size);
			m_deleter = free;
			m_format = format;
			m_width = width;
			m_height = height;
			m_rowPitch = rowPitch;
			memcpy(m_data, data, size);
		}

		// data 를 복사하여 내부에서 동적할당 한다
		inline Image(DXGI_FORMAT format, int width, int height, int rowPitch)
		{
			size_t size = rowPitch * height;
			m_data = malloc(size);
			m_deleter = free;
			m_format = format;
			m_width = width;
			m_height = height;
			m_rowPitch = rowPitch;
		}

		// 기본 생성자
		// data를 NULL로 초기화한다.
		inline Image()
		{
			m_data = nullptr;
		}

		inline Image(Image && _move)
		{
			m_data = _move.m_data;
			m_deleter = _move.m_deleter;
			m_format = _move.m_format;
			m_width = _move.m_width;
			m_height = _move.m_height;
			m_rowPitch = _move.m_rowPitch;
			_move.m_data = nullptr;
		}

		inline ~Image()
		{
			if (m_data != nullptr)
				m_deleter(m_data);
		}

		inline Image & operator =(Image && _move)
		{
			this->~Image();
			new(this) Image(std::move(_move));
			return *this;
		}
	};

	// CBS implement
	HRESULT LoadImageFromFile(
		_In_ ID3D10Device * d3dDevice,
		_In_z_ const wchar_t* szFileName,
		_Out_ Image* image,
		_In_ size_t maxsize = 0
		);

	// Standard version
	HRESULT CreateWICTextureFromMemory(_In_ ID3D10Device* d3dDevice,
		_In_reads_bytes_(wicDataSize) const uint8_t* wicData,
		_In_ size_t wicDataSize,
		_Out_opt_ ID3D10Resource** texture,
		_Out_opt_ ID3D10ShaderResourceView** textureView,
		_In_ size_t maxsize = 0
		);

	HRESULT CreateWICTextureFromFile(_In_ ID3D10Device* d3dDevice,
		_In_z_ const wchar_t* szFileName,
		_Out_opt_ ID3D10Resource** texture,
		_Out_opt_ ID3D10ShaderResourceView** textureView,
		_In_ size_t maxsize = 0
		);

	// Extended version
	HRESULT CreateWICTextureFromMemoryEx(_In_ ID3D10Device* d3dDevice,
		_In_reads_bytes_(wicDataSize) const uint8_t* wicData,
		_In_ size_t wicDataSize,
		_In_ size_t maxsize,
		_In_ D3D10_USAGE usage,
		_In_ unsigned int bindFlags,
		_In_ unsigned int cpuAccessFlags,
		_In_ unsigned int miscFlags,
		_In_ bool forceSRGB,
		_In_ bool forceURGB,
		_Out_opt_ ID3D10Resource** texture,
		_Out_opt_ ID3D10ShaderResourceView** textureView
		);

	HRESULT CreateWICTextureFromFileEx(_In_ ID3D10Device* d3dDevice,
		_In_z_ const wchar_t* szFileName,
		_In_ size_t maxsize,
		_In_ D3D10_USAGE usage,
		_In_ unsigned int bindFlags,
		_In_ unsigned int cpuAccessFlags,
		_In_ unsigned int miscFlags,
		_In_ bool forceSRGB,
		_In_ bool forceURGB,
		_Out_opt_ ID3D10Resource** texture,
		_Out_opt_ ID3D10ShaderResourceView** textureView
		);
}
