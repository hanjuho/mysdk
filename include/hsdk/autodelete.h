#pragma once



#include "autopointer.h"



namespace hsdk
{

	/*
	설명 : 동적 생성 변수를 정적 생성 변수처럼 관리하는 객체.
	$ 주의 : 이 객체를 상속하는 것은 권장하지 않음.
	*/
	template <typename T> DECL_CLASS(AutoDelete) final
		: public AutoPointer<T>
	{
	public:

		// 생성자.
		CLASS_DECL_CONSTRUCTOR(AutoDelete)(
			/* [x] */ void)
		{
			m_Ptr = nullptr;
		}

		// 생성자.
		CLASS_DECL_CONSTRUCTOR(AutoDelete)(
			_In_ T * _ptr)
		{
			m_Ptr = _ptr;
		}

		// 생성자.
		CLASS_DECL_CONSTRUCTOR(AutoDelete)(
			_In_ AutoDelete && _move)
		{
			m_Ptr = _move.m_Ptr;
			_move.m_Ptr = nullptr;
		}

		// 소멸자.
		CLASS_DECL_WARN_DESTRUCTOR(AutoDelete)(
			/* [x] */ void)
		{
			DEL_POINTER(m_Ptr);
		}

		// 설명 : = 연산자에 대해 AutoDelete & 를 반환, 이전 포인터가 삭제됨을 보장.
		CLASS_DECL_FUNC_T(AutoDelete &, operator =)(
			_In_ T * _move)
		{
			this->~AutoDelete();
			new(this) AutoDelete(_move);
			return *this;
		}

		// 설명 : = 연산자에 대해 AutoDelete & 를 반환, 이전 포인터가 삭제됨을 보장.
		CLASS_DECL_FUNC_T(AutoDelete &, operator =)(
			_In_ AutoDelete && _move)
		{
			this->~AutoDelete();
			new(this) AutoDelete(_move);
			return *this;
		}

		/*
		설명 : 이 생성자는 객체에서 기본으로 제공하기 때문에 포인터 복제 발생.
		$ 경고 : 사용하지 않을 것을 권장.
		*/
		explicit AutoDelete(
			_In_ const AutoDelete & _copy)
		{
			throw HSDK_FAIL;
		}

		/*
		설명 : 이 연산자는 객체에서 기본으로 제공하기 때문에 포인터 복제 발생.
		$ 경고 : 사용하지 않을 것을 권장함
		*/
		AutoDelete & operator = (
			_In_ const AutoDelete & _copy)
		{
			throw HSDK_FAIL;
		}
	};

}