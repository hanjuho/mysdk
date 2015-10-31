#pragma once



#include "../../../interface/frame/layout.h"


namespace hsdk
{
	namespace frame
	{
		namespace layout
		{

			// ���� :
			DLL_DECL_CLASS(BorderLayout)
				: public i::frame::i_Layout
			{

			public:

				// ���� :
				CLASS_DECL_CONSTRUCTOR(BorderLayout)(void);

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
					_In_ float _value);

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

			protected:

				// ���� : 
				CLASS_DECL_FUNC_T(float, get_WidthRate)(
					_X_ void)const;

				// ���� : 
				CLASS_DECL_FUNC_T(float, get_HeightRate)(
					_X_ void)const;

				// ���� : 
				CLASS_DECL_FUNC_T(float, get_SpaceAbs)(
					_In_ i::frame::LAYOUT_SPACE _space)const;

				// ���� :
				CLASS_DECL_FUNC_T(float, get_HGapAbs)(
					_In_ void)const;

				// ���� :
				CLASS_DECL_FUNC_T(float, get_VGapAbs)(
					_X_ void)const;

				// ���� : 
				CLASS_DECL_FUNC_T(float, get_Left)(
					_In_ i::frame::LAYOUT_COMPOSITION _composition)const;

				// ���� : 
				CLASS_DECL_FUNC_T(float, get_Top)(
					_In_ i::frame::LAYOUT_COMPOSITION _composition)const;

				// ���� : 
				CLASS_DECL_FUNC_T(float, get_Right)(
					_In_ i::frame::LAYOUT_COMPOSITION _composition)const;

				// ���� : 
				CLASS_DECL_FUNC_T(float, get_Bottom)(
					_In_ i::frame::LAYOUT_COMPOSITION _composition)const;

			protected:

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
				float * my_LinkedForm[5];

			};

		}
	}
}