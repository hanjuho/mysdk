#pragma once



#include "container.h"



namespace hsdk
{
	namespace frame
	{

		// ���� :
		template<unsigned int INDEX> DECL_CLASS(MultiContainer)
			: public Container
		{
		public:

			// ������
			CLASS_DECL_CONSTRUCTOR(MultiContainer)(
				_In_ PARENT_RELATION _relation = PARENT_RELATION_ABSOLUTE);

			// ���� �Ҹ���.
			CLASS_DECL_DESTRUCTOR(MultiContainer)(void);

			// ���� : 
			CLASS_DECL_FUNC_T(void, select_Buffer)(
				_In_ unsigned int _index,
				_In_ bool _store = true);

			// ���� : 
			CLASS_DECL_FUNC_T(unsigned int, get_CurrentBuffer)(
				_X_ void);

			// ���� : container�� ���� ���θ� �ʱ�ȭ, Graphics, Layout, Component�� ��� �����.
			INTERFACE_DECL_FUNC_T(void, reset)(
				_X_ void);

			// ���� : ���� ���ۿ� �ִ� component�� �޸� �󿡼� ��� ����.
			INTERFACE_DECL_FUNC_T(void, clear)(
				_X_ void);

		protected:

			// ���� :
			unsigned int m_CurrentBuffer = 0;

			// ���� : 
			std::list<Component *> m_Buffer[INDEX];

		};

	}
}



#include "multicontainer.inl"