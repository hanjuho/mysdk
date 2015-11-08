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
			
			// ���� �Ҹ���.
			CLASS_DECL_DESTRUCTOR(MultiContainer)(void);

			// ���� : 
			CLASS_DECL_FUNC_T(void, select_Buffer)(
				_In_ unsigned int _index,
				_In_ bool _store = true);
			
			// ���� : component�� �޸� �󿡼� ��� ����, reset() �Ǵ� �Ҹ��ڿ� ���ؼ��� ȣ���.
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