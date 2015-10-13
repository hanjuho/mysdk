#pragma once



#include "../hsdk_common.h"



namespace hsdk
{

	// 설명 : 포인터 변수 래퍼 객체.
	template <typename T> DECL_CLASS(AutoPointer)
	{
	public:

		typedef T TYPE;

		/*
		설명 : 객체를 무효화.
		$ 경고 : 반환된 포인터는 사용자가 삭제할 것을 권장.
		*/
		CLASS_DECL_FUNC_T(void, invalid)(
			/* [w] */ T * (&_pointer))
		{
			_pointer = m_Ptr;
			m_Ptr = nullptr;
		}

		// 설명 : T * 로 취급.
		CLASS_DECL_FUNC_T(, operator T *)(
			/* [x] */ void)const
		{
			return m_Ptr;
		}

		// 설명 : * 연산자에 대해 T &를 반환.
		CLASS_DECL_FUNC_T(T &, operator *)(
			/* [x] */ void)const
		{
			return (*m_Ptr);
		}

		// 설명 : -> 연산자에 대해 T * 를 반환.
		CLASS_DECL_FUNC_T(T *, operator ->)(
			/* [x] */ void)const
		{
			return m_Ptr;
		}

		// 설명 : & 연산자에 대해 T * CONST * 를 반환.
		CLASS_DECL_FUNC_T(T * const *, operator &)(
			/* [x] */ void)const
		{
			return &m_Ptr;
		}

		// 설명 : & 연산자에 대해 T ** 를 반환.
		CLASS_DECL_FUNC_T(T **, operator &)(
			/* [x] */ void)
		{
			return &m_Ptr;
		}

	protected:

		T * m_Ptr;

	};

}