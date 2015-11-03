#pragma once



#include "d3d10_common.h"



namespace hsdk
{
	namespace direct3d
	{

		// 터레인을 모델로 변환했을 때의 정보
		DECL_STRUCT(D3D10_Terrain)
		{
			unsigned long width;
			unsigned long height;
			unsigned long row;
			unsigned long col;
			unsigned long vertices;
			unsigned long triangles;
			unsigned long verticsPerRow;
			unsigned long verticsPerCol;
			double xCellSpacing;
			double zCellSpacing;
		};

		namespace terrain
		{

			// 설명 : 
			DLL_DECL_FUNC_T(void, build_Terrain)(
				_Out_ D3D10_Terrain & _terrain,
				_In_ unsigned long _width,
				_In_ unsigned long _height,
				_In_ unsigned long _row,
				_In_ unsigned long _column);

			// 설명 : RAW 이미지에 기록된 음영을 지형의 굴곡으로 변환
			DLL_DECL_FUNC(load_RawFromFile)(
				_Out_ float * _rawbuffer,
				_In_ const wchar_t * _fileName,
				_In_ unsigned int _size,
				_In_ unsigned int _displacement = 255);

		}
	}
}