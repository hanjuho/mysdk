#pragma once



#include "../hsdk_common.h"



namespace hsdk
{

	// ���� : ������ ���� ���� ��ü.
	template <typename T> DECL_CLASS(AutoPointer)
	{
	public:

		typedef T TYPE;

		// ���� : T * �� ���.
		CLASS_DECL_FUNC_T(, operator T *)(
			_X_ void)const
		{
			return m_Ptr;
		}

		// ���� : * �����ڿ� ���� T &�� ��ȯ.
		CLASS_DECL_FUNC_T(T &, operator *)(
			_X_ void)const
		{
			return (*m_Ptr);
		}

		// ���� : -> �����ڿ� ���� T * �� ��ȯ.
		CLASS_DECL_FUNC_T(T *, operator ->)(
			_X_ void)const
		{
			return m_Ptr;
		}

		// ���� : & �����ڿ� ���� T * CONST * �� ��ȯ.
		CLASS_DECL_FUNC_T(T * const *, operator &)(
			_X_ void)const
		{
			return &m_Ptr;
		}

		// ���� : & �����ڿ� ���� T ** �� ��ȯ.
		CLASS_DECL_FUNC_T(T **, operator &)(
			_X_ void)
		{
			return &m_Ptr;
		}

	protected:

		T * m_Ptr;

	};

}