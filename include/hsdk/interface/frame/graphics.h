#pragma once



#include "component.h"



namespace hsdk
{
	namespace i
	{
		namespace frame
		{

			// ���� : ��ǥ����� �ð��� ��Ҹ� ������ �� �ִ� ��ü�� �߻�ȭ
			DLL_DECL_INTERFACE(i_Graphics)
			{

				// ���� �Ҹ���
				CLASS_DECL_DESTRUCTOR(i_Graphics)(void)
				{

				}

				// ���� : �̹����� ����.
				INTERFACE_DECL_FUNC_T(void, set_image)(
					/* [r] */ const wchar_t * _filename) = 0;
				
				/*
				���� : �̹����� �� ����.
				���� : _rectangle(x, y, w, h)
				*/
				INTERFACE_DECL_FUNC_T(void, set_imageDetail)(
					/* [r] */ float _imageW,
					/* [r] */ float _imageH,
					/* [r] */ const float(&_rectangle)[4]) = 0;

				// ���� : ��Ʈ�� ����.
				INTERFACE_DECL_FUNC_T(void, set_Font)(
					/* [r] */ const wchar_t * _fontname,
					/* [r] */ unsigned int _fontsize) = 0;

				// ���� : �ؽ�Ʈ�� ����.
				INTERFACE_DECL_FUNC_T(void, set_Text)(
					/* [r] */ const wchar_t * _text) = 0;

			};

		}
	}
}