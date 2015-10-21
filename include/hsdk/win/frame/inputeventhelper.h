#pragma once



#include <hsdk/interface/frame/inputeventhelper.h>
#include <hsdk/interface/frame/mouseable.h>
#include <Windows.h>



namespace hsdk
{
	namespace win
	{
		namespace frame
		{

			// ���� : â�� ���� ��Ҹ� win32�� ����.
			DLL_DECL_CLASS(inputEventHelper)
				: public i::frame::i_inputEventHelper
			{
			public:

				// ������.
				CLASS_DECL_CONSTRUCTOR(inputEventHelper)(
					/* [r] */ i::frame::i_Component * _component);
				
				// ���� �Ҹ���.
				CLASS_DECL_DESTRUCTOR(inputEventHelper)(void);

				/*
				���� : component�� event �߻� ������ �����ϴ��� �˻�.
				$ ���� : ������� xy�� _component�ȿ� �־���ϸ�, i_Component::is_Visible�� ��ȯ ���� ���̾�� ��.
				*/
				INTERFACE_DECL_FUNC_T(bool, chain)(
					/* [r] */ const i::frame::i_Component * _component);

				/*
				���� : input event focus ����� ����.
				$ ���� : �� Ŭ���� ����Լ� �� onClick_Down������ update�� ȣ���.
				*/
				INTERFACE_DECL_FUNC_T(void, update)(
					/* [x] */ void);

				// ���� : mouse�� ��ư�� ������ �� �߻��ϴ� event.
				CLASS_DECL_FUNC_T(void, onClick_Down)(
					/* [r] */ i::frame::MOUSE_BUTTON _button,
					/* [r] */ int _x,
					/* [r] */ int _y);

				// ���� : mouse�� ��ư�� ���ȴٰ� ���� �߻��ϴ� event.
				CLASS_DECL_FUNC_T(void, onClick_Up)(
					/* [r] */ i::frame::MOUSE_BUTTON _button,
					/* [r] */ int _x,
					/* [r] */ int _y);

				// ���� : mouse�� ��ư�� ���� ä Ŀ���� �̵��ϸ� �߻��ϴ� event.
				CLASS_DECL_FUNC_T(void, onDrag)(
					/* [r] */ i::frame::MOUSE_BUTTON _button,
					/* [r] */ int _x,
					/* [r] */ int _y);

				// ���� : mouse�� Ŀ���� �̵���Ű�� �߻��ϴ� event.
				CLASS_DECL_FUNC_T(void, onMove)(
					/* [r] */ int _x,
					/* [r] */ int _y);

				// ���� : mouse�� wheel�� �����ϸ� �߻��ϴ� event.
				CLASS_DECL_FUNC_T(void, onWheel)(
					/* [r] */ int _x,
					/* [r] */ int _y,
					/* [r] */ int _w);

			public:
					
				/*
				���� : ���콺 ��ǥ. update�� ȣ���ϸ� xy�� �´� component�� ����
				$ ���� : 
				*/
				POINT xy;

			private:

				// ���� : event helper�� �ֽ��ϰ� �ִ� component
				i::frame::i_Component * my_FocusComponent;
				
			};

		}
	}
}