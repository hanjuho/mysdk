#pragma once



#include "../../../interface/frame/layout.h"


namespace hsdk
{
	namespace frame
	{
		namespace layout
		{

			// 설명 :
			DLL_DECL_CLASS(BorderLayout)
				: public i::frame::i_Layout
			{

			public:

				// 설명 :
				CLASS_DECL_CONSTRUCTOR(BorderLayout)(void);

				// 설명 : 
				INTERFACE_DECL_FUNC_T(void, reset)(
					_X_ void);

				// 설명 :
				INTERFACE_DECL_FUNC_T(void, resize)(
					_In_ float _width,
					_In_ float _height);

				// 설명 : 
				INTERFACE_DECL_FUNC(link_Form)(
					_Out_ float(&_rectangle)[4],
					_In_ i::frame::LAYOUT_COMPOSITION _composition);

				// 설명 : 
				INTERFACE_DECL_FUNC(unlink_Form)(
					_In_ float(&_rectangle)[4],
					_In_ i::frame::LAYOUT_COMPOSITION _composition);

				// 설명 :
				INTERFACE_DECL_FUNC_T(void, set_Space)(
					_In_ i::frame::LAYOUT_SPACE _space,
					_In_ float _value);

				// 설명 : 
				INTERFACE_DECL_FUNC_T(float, get_Space)(
					_In_ i::frame::LAYOUT_SPACE _space)const;

				// 설명 :
				INTERFACE_DECL_FUNC_T(void, set_HGap)(
					_In_ float _value);

				// 설명 :
				INTERFACE_DECL_FUNC_T(float, get_HGap)(
					_X_  void)const;

				// 설명 :
				INTERFACE_DECL_FUNC_T(void, set_VGap)(
					_In_ float _value);

				// 설명 :
				INTERFACE_DECL_FUNC_T(float, get_VGap)(
					_X_ void)const;

			protected:

				// 설명 : 
				CLASS_DECL_FUNC_T(float, get_WidthRate)(
					_X_ void)const;

				// 설명 : 
				CLASS_DECL_FUNC_T(float, get_HeightRate)(
					_X_ void)const;

				// 설명 : 
				CLASS_DECL_FUNC_T(float, get_SpaceAbs)(
					_In_ i::frame::LAYOUT_SPACE _space)const;

				// 설명 :
				CLASS_DECL_FUNC_T(float, get_HGapAbs)(
					_In_ void)const;

				// 설명 :
				CLASS_DECL_FUNC_T(float, get_VGapAbs)(
					_X_ void)const;

				// 설명 : 
				CLASS_DECL_FUNC_T(float, get_Left)(
					_In_ i::frame::LAYOUT_COMPOSITION _composition)const;

				// 설명 : 
				CLASS_DECL_FUNC_T(float, get_Top)(
					_In_ i::frame::LAYOUT_COMPOSITION _composition)const;

				// 설명 : 
				CLASS_DECL_FUNC_T(float, get_Right)(
					_In_ i::frame::LAYOUT_COMPOSITION _composition)const;

				// 설명 : 
				CLASS_DECL_FUNC_T(float, get_Bottom)(
					_In_ i::frame::LAYOUT_COMPOSITION _composition)const;

			protected:

				// 설명 : 레이아웃의 너비
				float my_Width = 0;

				// 설명 : 레이아웃의 높이
				float my_Height = 0;

				// 설명 : 레이아웃의 너비
				float my_VGap = 0;

				// 설명 : 레이아웃의 높이
				float my_HGap = 0;

				// 설명 : 
				float my_Frame[4];

				// 설명 : 
				float * my_LinkedForm[5];

			};

		}
	}
}