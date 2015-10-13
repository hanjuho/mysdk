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
				/* [r] */ float _posX,
				/* [r] */ float _minY,
				/* [r] */ unsigned int _width,
				/* [r] */ unsigned int _numOfCells);

			// ���� : RAW �̹����� ��ϵ� ������ ������ �������� ��ȯ.
			CLASS_DECL_FUNC(initialize)(
				/* [r] */ const wchar_t * _fileName,
				/* [r] */ float _intensity);

			// ���� : ����ڰ� ������ ������ ����.
			CLASS_DECL_FUNC_T(void, initialize)(
				/* [r] */ const float * _map,
				/* [r] */ unsigned int _offset,
				/* [r] */ unsigned int _size);

			// ���� : ������ ���̸� ���������� ����.
			CLASS_DECL_FUNC_T(void, set_Height)(
				/* [r] */ unsigned int _index,
				/* [r] */ float _height);

			// ���� : _index ��° ������ ���̸� ��ȯ.
			CLASS_DECL_FUNC_T(float, get_Height)(
				/* [r] */ unsigned int _index)const;

			// ���� : _x ��ǥ ���� ������ �ش�Ǵ� index�� ��ȯ.
			CLASS_DECL_FUNC_T(unsigned int, indexOfCell)(
				/* [r] */ float _x)const;

			// ���� : _x ��ǥ ������ ���̸� ��ȯ.
			INTERFACE_DECL_FUNC_T(float, height)(
				/* [r] */ float _x,
				/* [w] */ float * _dy = nullptr)const;

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