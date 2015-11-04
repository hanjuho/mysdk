#pragma once



#include "component.h"



namespace hsdk
{
	namespace i
	{
		namespace frame
		{

			// ���� : ��ǥ����� �ð��� ��Ҹ� ������ �� �ִ� ��ü�� �߻�ȭ
			DECL_INTERFACE(i_Graphics)
			{

				// ���� �Ҹ���
				CLASS_DECL_DESTRUCTOR(i_Graphics)(void)
				{

				}

				// ���� :
				INTERFACE_DECL_FUNC_T(void, set_Background)(
					_In_ const float(&_color)[4]) = 0;

				// ���� : �̹����� ����.
				INTERFACE_DECL_FUNC_T(void, set_image)(
					_In_ const wchar_t * _filename) = 0;

				/*
				���� : �̹����� �� ����.
				���� : _clip(x, y, w, h)
				*/
				INTERFACE_DECL_FUNC_T(void, set_imageDetail)(
					_In_ const float(&_clip)[4]) = 0;

				// ���� : ��Ʈ�� ����.
				INTERFACE_DECL_FUNC_T(void, set_Font)(
					_In_ const wchar_t * _fontname,
					_In_ unsigned int _fontsize) = 0;

				// ���� :
				INTERFACE_DECL_FUNC_T(void, set_FontColor)(
					_In_ const float(&_color)[4]) = 0;

				// ���� : �ؽ�Ʈ�� ����.
				INTERFACE_DECL_FUNC_T(void, set_Text)(
					_In_ const wchar_t * _text) = 0;

			};

		}
	}
}