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

				// ���� : ���� ����
				SPACE_LEFT,

				// ���� : �� ����
				SPACE_TOP,

				// ���� : ������ ����
				SPACE_RIGHT,

				// ���� : �Ʒ� ����
				SPACE_BOTTOM

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
			DLL_DECL_INTERFACE(i_Layout)
			{

				// ���� : 
				INTERFACE_DECL_FUNC_T(void, reset)(
					_X_ void) = 0;

				// ���� :
				INTERFACE_DECL_FUNC_T(void, resize)(
					_In_ float _width,
					_In_ float _height) = 0;

				// ���� : 
				INTERFACE_DECL_FUNC(link_Form)(
					_Out_ float(&_rectangle)[4],
					_In_ LAYOUT_COMPOSITION _composition) = 0;

				// ���� : 
				INTERFACE_DECL_FUNC(unlink_Form)(
					_In_ float(&_rectangle)[4],
					_In_ LAYOUT_COMPOSITION _composition) = 0;

				// ���� :
				INTERFACE_DECL_FUNC_T(void, set_Space)(
					_In_ LAYOUT_SPACE _space,
					_In_ float value) = 0;

				// ���� : 
				INTERFACE_DECL_FUNC_T(float, get_Space)(
					_In_ LAYOUT_SPACE _space)const = 0;

				// ���� :
				INTERFACE_DECL_FUNC_T(void, set_HGap)(
					_In_ float _value) = 0;

				// ���� :
				INTERFACE_DECL_FUNC_T(float, get_HGap)(
					_X_  void)const = 0;

				// ���� :
				INTERFACE_DECL_FUNC_T(void, set_VGap)(
					_In_ float _value) = 0;

				// ���� :
				INTERFACE_DECL_FUNC_T(float, get_VGap)(
					_X_ void)const = 0;

			};

		}
	}
}