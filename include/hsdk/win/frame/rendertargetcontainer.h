#pragma once



#include "container.h"
#include "../direct3d/d3d10_rendertarget.h"


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
				_In_ float _y = 0.0f);

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

			direct3d::D3D10_RenderTarget my_RenderTarget;

		};

	}
}