#pragma once



#include "autopointer.h"



namespace hsdk
{

	/*
	���� : ���� ���� ������ ���� ���� ����ó�� �����ϴ� ��ü.
	$ ���� : �� ��ü�� ����ϴ� ���� �������� ����.
	*/
	template <typename T> DECL_CLASS(AutoDelete) final
		: public AutoPointer<T>
	{
	public:

		// ������.
		CLASS_DECL_CONSTRUCTOR(AutoDelete)(
			/* [x] */ void)
		{
			m_Ptr = nullptr;
		}

		// ������.
		CLASS_DECL_CONSTRUCTOR(AutoDelete)(
			/* [r] */ T * _ptr)
		{
			m_Ptr = _ptr;
		}

		// ������.
		CLASS_DECL_CONSTRUCTOR(AutoDelete)(
			/* [r] */ AutoDelete && _move)
		{
			m_Ptr = _move.m_Ptr;
			_move.m_Ptr = nullptr;
		}

		// �Ҹ���.
		CLASS_DECL_WARN_DESTRUCTOR(AutoDelete)(
			/* [x] */ void)
		{
			DEL_POINTER(m_Ptr);
		}

		// ���� : = �����ڿ� ���� AutoDelete & �� ��ȯ, ���� �����Ͱ� �������� ����.
		CLASS_DECL_FUNC_T(AutoDelete &, operator =)(
			/* [r] */ T * _move)
		{
			this->~AutoDelete();
			new(this) AutoDelete(_move);
			return *this;
		}

		// ���� : = �����ڿ� ���� AutoDelete & �� ��ȯ, ���� �����Ͱ� �������� ����.
		CLASS_DECL_FUNC_T(AutoDelete &, operator =)(
			/* [r] */ AutoDelete && _move)
		{
			this->~AutoDelete();
			new(this) AutoDelete(_move);
			return *this;
		}

		/*
		���� : �� �����ڴ� ��ü���� �⺻���� �����ϱ� ������ ������ ���� �߻�.
		$ ��� : ������� ���� ���� ����.
		*/
		explicit AutoDelete(
			/* [r] */ const AutoDelete & _copy)
		{
			throw HSDK_FAIL;
		}

		/*
		���� : �� �����ڴ� ��ü���� �⺻���� �����ϱ� ������ ������ ���� �߻�.
		$ ��� : ������� ���� ���� ������
		*/
		AutoDelete & operator = (
			/* [r] */ const AutoDelete & _copy)
		{
			throw HSDK_FAIL;
		}
	};

}