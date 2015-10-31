#pragma once



#include "borderlayout.h"
#include <list>


namespace hsdk
{
	namespace frame
	{
		namespace layout
		{

			// ���� :
			enum FLOW_LAYOUT
			{

				// ���� : 
				FLOW_HORIZON,

				// ���� : 
				FLOW_VERTICAL

			};

			// ���� :
			DLL_DECL_CLASS(FlowLayout)
				: public i::frame::i_Layout
			{

			public:

				// ���� :
				CLASS_DECL_CONSTRUCTOR(FlowLayout)(
					_X_ FLOW_LAYOUT _layout);

				// ���� : 
				INTERFACE_DECL_FUNC_T(void, reset)(
					_X_ void);

				// ���� :
				INTERFACE_DECL_FUNC_T(void, resize)(
					_In_ float _width,
					_In_ float _height);

				// ���� : 
				INTERFACE_DECL_FUNC(link_Form)(
					_Out_ float(&_rectangle)[4],
					_In_ i::frame::LAYOUT_COMPOSITION _composition);

				// ���� : 
				INTERFACE_DECL_FUNC(unlink_Form)(
					_In_ float(&_rectangle)[4],
					_In_ i::frame::LAYOUT_COMPOSITION _composition);

				// ���� :
				INTERFACE_DECL_FUNC_T(void, set_Space)(
					_In_ i::frame::LAYOUT_SPACE _space,
					_In_ float value);

				// ���� : 
				INTERFACE_DECL_FUNC_T(float, get_Space)(
					_In_ i::frame::LAYOUT_SPACE _space)const;

				// ���� :
				INTERFACE_DECL_FUNC_T(void, set_HGap)(
					_In_ float _value);

				// ���� :
				INTERFACE_DECL_FUNC_T(float, get_HGap)(
					_X_  void)const;

				// ���� :
				INTERFACE_DECL_FUNC_T(void, set_VGap)(
					_In_ float _value);

				// ���� :
				INTERFACE_DECL_FUNC_T(float, get_VGap)(
					_X_ void)const;

				// ���� :
				CLASS_DECL_FUNC_T(void, set_EachWidthAbs)(
					_In_ float _value);

				// ���� :
				CLASS_DECL_FUNC_T(void, set_EachHeightAbs)(
					_In_ float _value);

			protected:

				// ���� : 
				CLASS_DECL_FUNC_T(float, get_SpaceAbs)(
					_In_ i::frame::LAYOUT_SPACE _space)const;

				// ���� :
				CLASS_DECL_FUNC_T(float, get_HGapAbs)(
					_In_ void)const;

				// ���� :
				CLASS_DECL_FUNC_T(float, get_VGapAbs)(
					_X_ void)const;

			protected:

				// ���� : 
				FLOW_LAYOUT my_Layout;

				// ���� : ���̾ƿ��� �ʺ�
				float my_Width = 0;

				// ���� : ���̾ƿ��� ����
				float my_Height = 0;

				// ���� : ���̾ƿ��� �ʺ�
				float my_VGap = 0;

				// ���� : ���̾ƿ��� ����
				float my_HGap = 0;

				// ���� : 
				float my_Frame[4];

				// ���� : 
				std::list<float *> my_LinkedForm;

				// ���� : 
				float my_EachWidthAbs = 128.0f;

				// ���� : 
				float my_EachHeightAbs = 96.0f;

				// ���� : 
				int my_NumHorizon = 0;

				// ���� : 
				int my_NumVertical = 0;

			};

		}
	}
}