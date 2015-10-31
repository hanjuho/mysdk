#pragma once



#include "borderlayout.h"
#include <list>


namespace hsdk
{
	namespace frame
	{
		namespace layout
		{

			// 설명 :
			enum FLOW_LAYOUT
			{

				// 설명 : 
				FLOW_HORIZON,

				// 설명 : 
				FLOW_VERTICAL

			};

			// 설명 :
			DLL_DECL_CLASS(FlowLayout)
				: public i::frame::i_Layout
			{

			public:

				// 설명 :
				CLASS_DECL_CONSTRUCTOR(FlowLayout)(
					_X_ FLOW_LAYOUT _layout);

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
					_In_ float value);

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

				// 설명 :
				CLASS_DECL_FUNC_T(void, set_EachWidthAbs)(
					_In_ float _value);

				// 설명 :
				CLASS_DECL_FUNC_T(void, set_EachHeightAbs)(
					_In_ float _value);

			protected:

				// 설명 : 
				CLASS_DECL_FUNC_T(float, get_SpaceAbs)(
					_In_ i::frame::LAYOUT_SPACE _space)const;

				// 설명 :
				CLASS_DECL_FUNC_T(float, get_HGapAbs)(
					_In_ void)const;

				// 설명 :
				CLASS_DECL_FUNC_T(float, get_VGapAbs)(
					_X_ void)const;

			protected:

				// 설명 : 
				FLOW_LAYOUT my_Layout;

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
				std::list<float *> my_LinkedForm;

				// 설명 : 
				float my_EachWidthAbs = 128.0f;

				// 설명 : 
				float my_EachHeightAbs = 96.0f;

				// 설명 : 
				int my_NumHorizon = 0;

				// 설명 : 
				int my_NumVertical = 0;

			};

		}
	}
}