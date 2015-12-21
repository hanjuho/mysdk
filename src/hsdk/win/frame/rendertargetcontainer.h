#pragma once



#include "container.h"
#include "../direct3d/d3d10_rendertarget.h"



namespace hsdk
{
	namespace frame
	{

		// ���� : â�� ���� ��Ҹ� win32�� ����.
		template<typename CONTAINER> DECL_CLASS(RenderTargetContainer)
			: public CONTAINER
		{
		public:

			// ������
			CLASS_DECL_CONSTRUCTOR(RenderTargetContainer)(
				_In_ PARENT_RELATION _relation = PARENT_RELATION_ABSOLUTE);

			// ���� �Ҹ���.
			CLASS_DECL_DESTRUCTOR(RenderTargetContainer)(void);

			// ���� : container�� ȭ�鿡 �ѷ���.
			INTERFACE_DECL_FUNC_T(void, render)(
				_X_ void);

			// ���� : component�� ��ǥ�� ����.
			INTERFACE_DECL_FUNC_T(void, reform)(
				_X_ void);

			// ���� : ȭ���� ���ŵ� �� ������Ʈ�� �ٽ� �׷��ְ� ����� ������ ���� TRUE�� ����.
			INTERFACE_DECL_FUNC_T(void, redraw)(
				_X_ void);

			// ���� : 
			INTERFACE_DECL_FUNC_T(void, reset)(
				_X_ void);

		protected:
			
			// ���� : 
			BOOL m_Render = TRUE;

		private:

			// ���� : 
			direct3d::D3D10_RenderTarget my_RenderTarget;

		};

	}
}



#include "rendertargetcontainer.inl"