#pragma once



#include "container.h"



namespace hsdk
{
	namespace frame
	{

		// 설명 :
		template<unsigned int INDEX> DECL_CLASS(MultiContainer)
			: public Container
		{
		public:
			
			// 가상 소멸자.
			CLASS_DECL_DESTRUCTOR(MultiContainer)(void);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, select_Buffer)(
				_In_ unsigned int _index,
				_In_ bool _store = true);
			
			// 설명 : component를 메모리 상에서 모두 제거, reset() 또는 소멸자에 의해서도 호출됨.
			INTERFACE_DECL_FUNC_T(void, clear)(
				_X_ void);

		protected:

			// 설명 :
			unsigned int m_CurrentBuffer = 0;

			// 설명 : 
			std::list<Component *> m_Buffer[INDEX];

		};

	}
}