#pragma once



#include "interface/terrain2d.h"
#include <string>
#include <vector>



namespace hsdk
{
	namespace physics2d
	{

		/*
		���� : ���� ����.
		$ ���� 1 : �� ��ü�� �̹����� ������ ������� ǥ��.
		$ ���� 2 : ���̸��� ������ ���� ������, ����� ���ǵ� ����.
		*/
		DLL_DECL_CLASS(Terrain2D)
			: public i::i_Terrain2D
		{
		public:

			// ������.
			CLASS_DECL_CONSTRUCTOR(Terrain2D)(
				_In_ float _posX,
				_In_ float _minY,
				_In_ unsigned int _width,
				_In_ unsigned int _numOfCells);

			// ���� : RAW �̹����� ��ϵ� ������ ������ �������� ��ȯ.
			CLASS_DECL_FUNC(initialize)(
				_In_ const wchar_t * _fileName,
				_In_ float _intensity);

			// ���� : ����ڰ� ������ ������ ����.
			CLASS_DECL_FUNC_T(void, initialize)(
				_In_ const float * _map,
				_In_ unsigned int _offset,
				_In_ unsigned int _size);

			// ���� : ������ ���̸� ���������� ����.
			CLASS_DECL_FUNC_T(void, set_Height)(
				_In_ unsigned int _index,
				_In_ float _height);

			// ���� : _index ��° ������ ���̸� ��ȯ.
			CLASS_DECL_FUNC_T(float, get_Height)(
				_In_ unsigned int _index)const;

			// ���� : _x ��ǥ ���� ������ �ش�Ǵ� index�� ��ȯ.
			CLASS_DECL_FUNC_T(unsigned int, indexOfCell)(
				_In_ float _x)const;

			// ���� : _x ��ǥ ������ ���̸� ��ȯ.
			INTERFACE_DECL_FUNC_T(float, height)(
				_In_ float _x,
				_Out_ float * _dy = nullptr)const;

			// ���� : 
			const float posX;

			// ���� : 
			const float minY;

			// ���� : 
			const unsigned int width;

			// ���� : 
			const unsigned int numOfCells;
			
			// ���� : 
			const float cellSpace;

		private:

			// ���� : 
			std::vector<float> my_HeightMap;

		};

	}
}