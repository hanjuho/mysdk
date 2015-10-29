#pragma once



#include "container.h"
#include <hash_map>


namespace hsdk
{
	namespace frame
	{

		// ���� : â�� ���� ��Ҹ� win32�� ����.
		DLL_DECL_CLASS(RenderTargetContainer)
			: public Container
		{
		public:

			// ������
			CLASS_DECL_CONSTRUCTOR(RenderTargetContainer)(
				_In_ float _w,
				_In_ float _h,
				_In_ float _x = 0.0f,
				_In_ float _y = 0.0f,
				_In_ i::frame::FRAME_FORM _form = i::frame::ABSOLUTE_FORM);

			// ���� �Ҹ���.
			CLASS_DECL_DESTRUCTOR(RenderTargetContainer)(void);

			// ���� : component ����.
			INTERFACE_DECL_FUNC_T(void, update)(
				_X_ void);

			// ���� : component�� ��ǥ�� ����.
			INTERFACE_DECL_FUNC_T(void, reform)(
				_X_ void);

			// ���� : container�� ȭ�鿡 �ѷ���.
			INTERFACE_DECL_FUNC_T(void, render)(
				_X_ void);

			// ���� : 
			INTERFACE_DECL_FUNC_T(void, clear)(
				_X_ void);

		private:

			// 
			AutoRelease<ID3D10Texture2D> my_RenderTarget;

		};

	}
}