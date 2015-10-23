#pragma once



#include "autopointer.h"



namespace hsdk
{

	/*
	설명 : 동적으로 생성되는 COM 객체를 정적 객체로 관리하는 객체.
	$ 주의 : 이 객체를 상속하는 것은 권장하지 않음.
	*/
	template <typename T> DECL_CLASS(AutoRelease) final
		: public AutoPointer<T>
	{
	public:

		// 생성자.
		CLASS_DECL_CONSTRUCTOR(AutoRelease)(
			/* [x] */ void)
		{
			m_Ptr = nullptr;
		}

		// 생성자.
		CLASS_DECL_CONSTRUCTOR(AutoRelease)(
			_In_ T * _ptr)
		{
			m_Ptr = _ptr;
			IF_TRUE(m_Ptr)
			{
				m_Ptr->AddRef();
			}
		}

		// 생성자.
		CLASS_DECL_CONSTRUCTOR(AutoRelease)(
			_In_ const AutoRelease & _copy)
		{
			m_Ptr = _copy.m_Ptr;
			IF_TRUE(m_Ptr)
			{
				m_Ptr->AddRef();
			}
		}

		// 생성자.
		CLASS_DECL_CONSTRUCTOR(AutoRelease)(
			_In_ AutoRelease && _move)
		{
			m_Ptr = _move.m_Ptr;
			_move.m_Ptr = nullptr;
		}

		// 소멸자.
		CLASS_DECL_WARN_DESTRUCTOR(AutoRelease)(void)
		{
			DEL_COM(m_Ptr);
		}

		/*
		설명 : 객체의 복사본을 만들어내는 함수.
		$ 주의 : 포인터를 복사(Addref함수가 호출됨).
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

		// 설명 : = 연산자에 대해 AutoDelete & 를 반환, 이전 포인터가 삭제됨을 보장.
		CLASS_DECL_FUNC_T(AutoRelease &, operator =)(
			_In_ const AutoRelease & _copy)
		{
			this->~AutoRelease();
			new(this) AutoRelease(_copy);
			return *this;
		}

		// 설명 : = 연산자에 대해 AutoDelete & 를 반환, 이전 포인터가 삭제됨을 보장.
		CLASS_DECL_FUNC_T(AutoRelease &, operator =)(
			_In_ AutoRelease && _move)
		{
			this->~AutoRelease();
			new(this) AutoRelease(std::move(_move));
			return *this;
		}
	};

}