#pragma once



#include "d3d10_common.h"



namespace hsdk
{
	namespace direct3d
	{

		// �ͷ����� �𵨷� ��ȯ���� ���� ����
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

			// ���� : 
			DLL_DECL_FUNC_T(void, build_Terrain)(
				_Out_ D3D10_Terrain & _terrain,
				_In_ unsigned long _width,
				_In_ unsigned long _height,
				_In_ unsigned long _row,
				_In_ unsigned long _column);

			// ���� : RAW �̹����� ��ϵ� ������ ������ �������� ��ȯ
			DLL_DECL_FUNC(load_RawFromFile)(
				_Out_ float * _rawbuffer,
				_In_ const wchar_t * _fileName,
				_In_ unsigned int _size,
				_In_ unsigned int _displacement = 255);

		}
	}
}