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

			// 생성자
			CLASS_DECL_CONSTRUCTOR(MultiContainer)(
				_In_ PARENT_RELATION _relation = PARENT_RELATION_ABSOLUTE);

			// 가상 소멸자.
			CLASS_DECL_DESTRUCTOR(MultiContainer)(void);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, select_Buffer)(
				_In_ unsigned int _index,
				_In_ bool _store = true);

			// 설명 : 
			CLASS_DECL_FUNC_T(unsigned int, get_CurrentBuffer)(
				_X_ void);

			// 설명 : container가 가진 전부를 초기화, Graphics, Layout, Component가 모두 사라짐.
			INTERFACE_DECL_FUNC_T(void, reset)(
				_X_ void);

			// 설명 : 현재 버퍼에 있는 component를 메모리 상에서 모두 제거.
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



#include "multicontainer.inl"