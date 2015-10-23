#pragma once



#include "autopointer.h"



namespace hsdk
{

	/*
	���� : �������� �����Ǵ� COM ��ü�� ���� ��ü�� �����ϴ� ��ü.
	$ ���� : �� ��ü�� ����ϴ� ���� �������� ����.
	*/
	template <typename T> DECL_CLASS(AutoRelease) final
		: public AutoPointer<T>
	{
	public:

		// ������.
		CLASS_DECL_CONSTRUCTOR(AutoRelease)(
			/* [x] */ void)
		{
			m_Ptr = nullptr;
		}

		// ������.
		CLASS_DECL_CONSTRUCTOR(AutoRelease)(
			_In_ T * _ptr)
		{
			m_Ptr = _ptr;
			IF_TRUE(m_Ptr)
			{
				m_Ptr->AddRef();
			}
		}

		// ������.
		CLASS_DECL_CONSTRUCTOR(AutoRelease)(
			_In_ const AutoRelease & _copy)
		{
			m_Ptr = _copy.m_Ptr;
			IF_TRUE(m_Ptr)
			{
				m_Ptr->AddRef();
			}
		}

		// ������.
		CLASS_DECL_CONSTRUCTOR(AutoRelease)(
			_In_ AutoRelease && _move)
		{
			m_Ptr = _move.m_Ptr;
			_move.m_Ptr = nullptr;
		}

		// �Ҹ���.
		CLASS_DECL_WARN_DESTRUCTOR(AutoRelease)(void)
		{
			DEL_COM(m_Ptr);
		}

		/*
		���� : ��ü�� ���纻�� ������ �Լ�.
		$ ���� : �����͸� ����(Addref�Լ��� ȣ���).
		*/
		CLASS_DECL_FUNC_T(void, clone)(
			_Out_ T * (&_out))const
		{
			IF_TRUE(m_Ptr)
			{
				m_Ptr->AddRef();
			}

			_out = m_Ptr;
		}

		// ���� : = �����ڿ� ���� AutoDelete & �� ��ȯ, ���� �����Ͱ� �������� ����.
		CLASS_DECL_FUNC_T(AutoRelease &, operator =)(
			_In_ const AutoRelease & _copy)
		{
			this->~AutoRelease();
			new(this) AutoRelease(_copy);
			return *this;
		}

		// ���� : = �����ڿ� ���� AutoDelete & �� ��ȯ, ���� �����Ͱ� �������� ����.
		CLASS_DECL_FUNC_T(AutoRelease &, operator =)(
			_In_ AutoRelease && _move)
		{
			this->~AutoRelease();
			new(this) AutoRelease(std::move(_move));
			return *this;
		}
	};

}