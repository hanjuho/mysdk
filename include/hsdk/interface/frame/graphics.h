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

				// ���� :
				INTERFACE_DECL_FUNC_T(void, set_Background)(
					/* [r] */ const float(&_color)[4]) = 0;

				// ���� : �̹����� ����.
				INTERFACE_DECL_FUNC_T(void, set_image)(
					/* [r] */ const wchar_t * _filename) = 0;

				/*
				���� : �̹����� �� ����.
				���� : _clip(x, y, w, h)
				*/
				INTERFACE_DECL_FUNC_T(void, set_imageDetail)(
					/* [r] */ const float(&_clip)[4]) = 0;

				// ���� : ��Ʈ�� ����.
				INTERFACE_DECL_FUNC_T(void, set_Font)(
					/* [r] */ const wchar_t * _fontname,
					/* [r] */ unsigned int _fontsize) = 0;

				// ���� :
				INTERFACE_DECL_FUNC_T(void, set_FontColor)(
					/* [r] */ const float(&_color)[4]) = 0;

				// ���� : �ؽ�Ʈ�� ����.
				INTERFACE_DECL_FUNC_T(void, set_Text)(
					/* [r] */ const wchar_t * _text) = 0;

			};

		}
	}
}