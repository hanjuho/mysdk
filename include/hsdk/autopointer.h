#pragma once



#include "../hsdk_common.h"



namespace hsdk
{

	// ���� : ������ ���� ���� ��ü.
	template <typename T> DECL_CLASS(AutoPointer)
	{
	public:

		typedef T TYPE;

		/*
		���� : ��ü�� ��ȿȭ.
		$ ��� : ��ȯ�� �����ʹ� ����ڰ� ������ ���� ����.
		*/
		CLASS_DECL_FUNC_T(void, invalid)(
			/* [w] */ T * (&_pointer))
		{
			_pointer = m_Ptr;
			m_Ptr = nullptr;
		}

		// ���� : T * �� ���.
		CLASS_DECL_FUNC_T(, operator T *)(
			/* [x] */ void)const
		{
			return m_Ptr;
		}

		// ���� : * �����ڿ� ���� T &�� ��ȯ.
		CLASS_DECL_FUNC_T(T &, operator *)(
			/* [x] */ void)const
		{
			return (*m_Ptr);
		}

		// ���� : -> �����ڿ� ���� T * �� ��ȯ.
		CLASS_DECL_FUNC_T(T *, operator ->)(
			/* [x] */ void)const
		{
			return m_Ptr;
		}

		// ���� : & �����ڿ� ���� T * CONST * �� ��ȯ.
		CLASS_DECL_FUNC_T(T * const *, operator &)(
			/* [x] */ void)const
		{
			return &m_Ptr;
		}

		// ���� : & �����ڿ� ���� T ** �� ��ȯ.
		CLASS_DECL_FUNC_T(T **, operator &)(
			/* [x] */ void)
		{
			return &m_Ptr;
		}

	protected:

		T * m_Ptr;

	};

}