#pragma once



#include "component.h"



namespace hsdk
{
	namespace win
	{
		namespace frame
		{

			// ���� :
			DLL_DECL_CLASS(ButtonCompo)
				: public Component
			{

			public:

				// ������.
				CLASS_DECL_CONSTRUCTOR(ButtonCompo)(
					_In_ float _x = 0.0f,
					_In_ float _y = 0.0f,
					_In_ float _w = 0.0f,
					_In_ float _h = 0.0f);

				// ���� : mouse�� ��ư�� ������ �� �߻��ϴ� event.
				INTERFACE_DECL_FUNC_T(void, onClick_Down)(
					_In_ i::frame::MOUSE_BUTTON _button,
					_In_ int _x,
					_In_ int _y);

				// ���� : mouse�� ��ư�� ���ȴٰ� ���� �߻��ϴ� event.
				INTERFACE_DECL_FUNC_T(void, onClick_Up)(
					_In_ i::frame::MOUSE_BUTTON _button,
					_In_ int _x,
					_In_ int _y);

				// ���� : component�� ȭ�鿡 �ѷ���.
				INTERFACE_DECL_FUNC_T(void, render)(
					_X_ void);

			protected:

				float m_GraphicsRenderState = 1.0f;

			};

		}
	}
}