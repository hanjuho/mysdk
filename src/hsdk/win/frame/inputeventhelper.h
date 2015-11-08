#pragma once



#include "../../interface/frame/inputeventhelper.h"
#include "../../interface/frame/mouseable.h"
#include <Windows.h>



namespace hsdk
{
	namespace frame
	{

		// ���� : â�� ���� ��Ҹ� win32�� ����.
		DECL_CLASS(inputEventHelper)
			: public i::frame::i_inputEventHelper
		{
		public:

			// ������.
			CLASS_DECL_CONSTRUCTOR(inputEventHelper)(
				_In_ i::frame::i_Component * _component);

			// ���� �Ҹ���.
			CLASS_DECL_DESTRUCTOR(inputEventHelper)(void);

			/*
			���� : component�� event �߻� ������ �����ϴ��� �˻�.
			$ ���� : ������� xy�� _component�ȿ� �־���ϸ�, i_Component::is_Visible�� ��ȯ ���� ���̾�� ��.
			*/
			INTERFACE_DECL_FUNC_T(bool, chain)(
				_In_ const i::frame::i_Component * _component);

			/*
			���� : input event focus ����� ����.
			$ ���� : �� Ŭ���� ����Լ� �� onClick_Down������ update�� ȣ���.
			*/
			INTERFACE_DECL_FUNC_T(void, update)(
				_X_ void);

			// ���� : mouse�� ��ư�� ������ �� �߻��ϴ� event.
			CLASS_DECL_FUNC_T(void, onClick_Down)(
				_In_ i::frame::MOUSE_BUTTON _button,
				_In_ int _x,
				_In_ int _y);

			// ���� : mouse�� ��ư�� ���ȴٰ� ���� �߻��ϴ� event.
			CLASS_DECL_FUNC_T(void, onClick_Up)(
				_In_ i::frame::MOUSE_BUTTON _button,
				_In_ int _x,
				_In_ int _y);

			// ���� : mouse�� ��ư�� ���� ä Ŀ���� �̵��ϸ� �߻��ϴ� event.
			CLASS_DECL_FUNC_T(void, onDrag)(
				_In_ i::frame::MOUSE_BUTTON _button,
				_In_ int _x,
				_In_ int _y);

			// ���� : mouse�� Ŀ���� �̵���Ű�� �߻��ϴ� event.
			CLASS_DECL_FUNC_T(void, onMove)(
				_In_ int _x,
				_In_ int _y);

			// ���� : mouse�� wheel�� �����ϸ� �߻��ϴ� event.
			CLASS_DECL_FUNC_T(void, onWheel)(
				_In_ int _x,
				_In_ int _y,
				_In_ int _w);

			// ���� : 
			CLASS_DECL_FUNC_T(void, restore)(
				_In_ i::frame::i_Component * _component);

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