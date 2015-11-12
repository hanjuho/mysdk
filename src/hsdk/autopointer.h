#pragma once



#include "../hsdk_common.h"



namespace hsdk
{

	// 설명 : 포인터 변수 래퍼 객체.
	template <typename T> DECL_CLASS(AutoPointer)
	{
	public:

		typedef T TYPE;

		// 설명 : T * 로 취급.
		CLASS_DECL_FUNC_T(, operator T *)(
			_X_ void)const
		{
			return m_Ptr;
		}

		// 설명 : * 연산자에 대해 T &를 반환.
		CLASS_DECL_FUNC_T(T &, operator *)(
			_X_ void)const
		{
			return (*m_Ptr);
		}

		// 설명 : -> 연산자에 대해 T * 를 반환.
		CLASS_DECL_FUNC_T(T *, operator ->)(
			_X_ void)const
		{
			return m_Ptr;
		}

		// 설명 : & 연산자에 대해 T * CONST * 를 반환.
		CLASS_DECL_FUNC_T(T * const *, operator &)(
			_X_ void)const
		{
			return &m_Ptr;
		}

		// 설명 : & 연산자에 대해 T ** 를 반환.
		CLASS_DECL_FUNC_T(T **, operator &)(
			_X_ void)
		{
			return &m_Ptr;
		}

	protected:

		T * m_Ptr;

	};

}