#pragma once



#include "common.h"


namespace hsdk
{
	namespace i
	{
		namespace frame
		{

			// ���� : 
			enum LAYOUT_SPACE
			{

				// ���� : �� ����
				SPACE_TOP,

				// ���� : �Ʒ� ����
				SPACE_BOTTOM,

				// ���� : ���� ����
				SPACE_LEFT,

				// ���� : ������ ����
				SPACE_RIGHT,

				// ���� : ������Ʈ ���� ���� 
				SPACE_COMPONENT

			};

			// ���� : 
			enum LAYOUT_COMPOSITION
			{

				// ���� :
				COMPOSITION_DEFALUT,

				// ���� : �� ����
				COMPOSITION_EAST,

				// ���� : �Ʒ� ����
				COMPOSITION_WEST,

				// ���� : ���� ����
				COMPOSITION_SOUTH,

				// ���� : ������ ����
				COMPOSITION_NORTH,

				// ���� : ������Ʈ ���� ���� 
				COMPOSITION_CENTER

			};

			// ���� : 
			DECL_INTERFACE(i_Layout)
			{

				// ���� :
				INTERFACE_DECL_FUNC_T(void, resize)(
					_In_ float _width,
					_In_ float _hegith);

				// ���� :
				INTERFACE_DECL_FUNC_T(void, set_Space)(
					_In_ LAYOUT_SPACE _space,
					_In_ float value) = 0;

				// ���� : 
				INTERFACE_DECL_FUNC_T(float, get_Space)(
					_In_ LAYOUT_SPACE _space)const = 0;

				// ���� : 
				INTERFACE_DECL_FUNC(get_Position)(
					_Out_ float(&_rectangle)[4],
					_In_ LAYOUT_COMPOSITION _composition)const = 0;

				// ���� : 
				INTERFACE_DECL_FUNC(get_Position)(
					_Out_ float(&_rectangle)[4],
					_In_ unsigned int _index)const = 0;

				// ���� : 
				INTERFACE_DECL_FUNC_T(void, reset)(
					_X_ void) = 0;

			};

		}
	}
}