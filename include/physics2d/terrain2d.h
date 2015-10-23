#pragma once



#include "interface/terrain2d.h"
#include <string>
#include <vector>



namespace hsdk
{
	namespace physics2d
	{

		/*
		설명 : 물리 지형.
		$ 참고 1 : 맵 전체를 이미지로 투영한 모습으로 표현.
		$ 참고 2 : 높이맵을 적용할 수도 있지만, 사용자 정의도 가능.
		*/
		DLL_DECL_CLASS(Terrain2D)
			: public i::i_Terrain2D
		{
		public:

			// 생성자.
			CLASS_DECL_CONSTRUCTOR(Terrain2D)(
				_In_ float _posX,
				_In_ float _minY,
				_In_ unsigned int _width,
				_In_ unsigned int _numOfCells);

			// 설명 : RAW 이미지에 기록된 음영을 지형의 굴곡으로 변환.
			CLASS_DECL_FUNC(initialize)(
				_In_ const wchar_t * _fileName,
				_In_ float _intensity);

			// 설명 : 사용자가 정의한 지형의 굴곡.
			CLASS_DECL_FUNC_T(void, initialize)(
				_In_ const float * _map,
				_In_ unsigned int _offset,
				_In_ unsigned int _size);

			// 설명 : 점정의 높이를 인의적으로 설정.
			CLASS_DECL_FUNC_T(void, set_Height)(
				_In_ unsigned int _index,
				_In_ float _height);

			// 설명 : _index 번째 버퍼의 높이를 반환.
			CLASS_DECL_FUNC_T(float, get_Height)(
				_In_ unsigned int _index)const;

			// 설명 : _x 좌표 위의 지역에 해당되는 index를 반환.
			CLASS_DECL_FUNC_T(unsigned int, indexOfCell)(
				_In_ float _x)const;

			// 설명 : _x 좌표 지형의 높이를 반환.
			INTERFACE_DECL_FUNC_T(float, height)(
				_In_ float _x,
				_Out_ float * _dy = nullptr)const;

			// 설명 : 
			const float posX;

			// 설명 : 
			const float minY;

			// 설명 : 
			const unsigned int width;

			// 설명 : 
			const unsigned int numOfCells;
			
			// 설명 : 
			const float cellSpace;

		private:

			// 설명 : 
			std::vector<float> my_HeightMap;

		};

	}
}