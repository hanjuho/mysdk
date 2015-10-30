#pragma once



#include "common.h"


namespace hsdk
{
	namespace i
	{
		namespace frame
		{

			// 설명 : 
			enum LAYOUT_SPACE
			{

				// 설명 : 위 여백
				SPACE_TOP,

				// 설명 : 아래 여백
				SPACE_BOTTOM,

				// 설명 : 왼쪽 여백
				SPACE_LEFT,

				// 설명 : 오른쪽 여백
				SPACE_RIGHT,

				// 설명 : 컴포넌트 간의 간격 
				SPACE_COMPONENT

			};

			// 설명 : 
			enum LAYOUT_COMPOSITION
			{

				// 설명 :
				COMPOSITION_DEFALUT,

				// 설명 : 위 여백
				COMPOSITION_EAST,

				// 설명 : 아래 여백
				COMPOSITION_WEST,

				// 설명 : 왼쪽 여백
				COMPOSITION_SOUTH,

				// 설명 : 오른쪽 여백
				COMPOSITION_NORTH,

				// 설명 : 컴포넌트 간의 간격 
				COMPOSITION_CENTER

			};

			// 설명 : 
			DECL_INTERFACE(i_Layout)
			{

				// 설명 :
				INTERFACE_DECL_FUNC_T(void, resize)(
					_In_ float _width,
					_In_ float _hegith);

				// 설명 :
				INTERFACE_DECL_FUNC_T(void, set_Space)(
					_In_ LAYOUT_SPACE _space,
					_In_ float value) = 0;

				// 설명 : 
				INTERFACE_DECL_FUNC_T(float, get_Space)(
					_In_ LAYOUT_SPACE _space)const = 0;

				// 설명 : 
				INTERFACE_DECL_FUNC(get_Position)(
					_Out_ float(&_rectangle)[4],
					_In_ LAYOUT_COMPOSITION _composition)const = 0;

				// 설명 : 
				INTERFACE_DECL_FUNC(get_Position)(
					_Out_ float(&_rectangle)[4],
					_In_ unsigned int _index)const = 0;

				// 설명 : 
				INTERFACE_DECL_FUNC_T(void, reset)(
					_X_ void) = 0;

			};

		}
	}
}