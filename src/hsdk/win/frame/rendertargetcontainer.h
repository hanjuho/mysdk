#pragma once



#include "container.h"
#include "../direct3d/d3d10_rendertarget.h"


namespace hsdk
{
	namespace frame
	{

		// 설명 : 창의 구성 요소를 win32로 구현.
		DECL_CLASS(RenderTargetContainer)
			: public Container
		{
		public:

			// 생성자
			CLASS_DECL_CONSTRUCTOR(RenderTargetContainer)(
				_In_ PARENT_RELATION _relation = PARENT_RELATION_ABSOLUTE);

			// 가상 소멸자.
			CLASS_DECL_DESTRUCTOR(RenderTargetContainer)(void);

			// 설명 : component의 좌표를 갱신.
			INTERFACE_DECL_FUNC_T(void, reform)(
				_X_ void);

			// 설명 : container를 화면에 뿌려줌.
			INTERFACE_DECL_FUNC_T(void, render)(
				_X_ void);

			// 설명 : 
			INTERFACE_DECL_FUNC_T(void, clear)(
				_X_ void);

		private:

			// 설명 : 
			direct3d::D3D10_RenderTarget my_RenderTarget;

		};

	}
}