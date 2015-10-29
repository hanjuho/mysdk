#pragma once



#include "container.h"
#include <hash_map>


namespace hsdk
{
	namespace frame
	{

		// 설명 : 창의 구성 요소를 win32로 구현.
		DLL_DECL_CLASS(RenderTargetContainer)
			: public Container
		{
		public:

			// 생성자
			CLASS_DECL_CONSTRUCTOR(RenderTargetContainer)(
				_In_ float _w,
				_In_ float _h,
				_In_ float _x = 0.0f,
				_In_ float _y = 0.0f,
				_In_ i::frame::FRAME_FORM _form = i::frame::ABSOLUTE_FORM);

			// 가상 소멸자.
			CLASS_DECL_DESTRUCTOR(RenderTargetContainer)(void);

			// 설명 : component 갱신.
			INTERFACE_DECL_FUNC_T(void, update)(
				_X_ void);

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

			// 
			AutoRelease<ID3D10Texture2D> my_RenderTarget;

		};

	}
}