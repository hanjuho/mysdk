#pragma once
#pragma warning(disable : 4251)



#include "../hsdk_common.h"
#include "autorelease.h"
#include <map>
#include <vector>
#include <string>
#include <Windows.h>



#define DEL_SOFTWARE(p) IF_INVALID(p){p->Release(); p = nullptr;}



namespace hsdk
{

	// 설명 : Data를 공유하는 User를 패턴으로 만든 클래스. 그 모습이 임베디드 시스템과 닮아 이름을 임베디드 아키텍처 패턴이라 지음.
	template<typename DATA, typename USE, typename KEY = std::wstring> DECL_INTERFACE(EMBEDDED_ARCHITECTURE_PATTERN)
	{

		/*
		설명 : 메모리 복사가 일어나기 때문에 DATA가 가상 함수를 갖는 것은 치명적일 수 있음.
		& 참고 : DATA의 변수 생성은 Factory에서 결정.
		*/
		typedef	DATA	DATA, &REF_DATA, *PTR_DATA;

		/*
		설명 : USE를 상속하는 객체가 만들어지기 때문에 USE는 되도록이면 인터페이스가 좋음.
		*/
		typedef	USE		USE, &REF_USE, *PTR_USE;

		/*
		설명 : USE를 찾아내는 키.
		*/
		typedef	KEY		KEY, &REF_KEY, *PTR_KEY;

		/*
		설명 : USER의 파생 클래스, SOFTWARE는 DATA에 접근하는 수단을 제공.
		$ 참고1 : DATA가 소멸되면 SOFTWARE::invaild가 호츨.
		$ 참고2 : SOFTWARE 타입 포인터 변수를 초기화하면 반드시 AddRef을 호출.
		$ 참고3 : SOFTWARE 타입 포인터 변수가 소멸되기 전 반드시 release를 호출.
		$ 참고4 : SOFTWARE::release가 호출되어 참조값이 0이 되면 객체가 소멸.
		*/
		typedef DECL_CLASS(User)
			: public USE
		{
		public:

			// 생성자.
			CLASS_DECL_CONSTRUCTOR(User)(
				_In_ unsigned int _id)
				: my_ID(_id), my_Ref(1)
			{

			}

			// 설명 : 
			CLASS_DECL_FUNC_T(unsigned int, get_ID)(
				_X_ void)const
			{
				return my_ID;
			}

			// 설명 : 참조 카운트를 하나만큼 증가.
			CLASS_DECL_FUNC(AddRef)(void)
			{
				return InterlockedIncrement(&my_Ref);
			}

			/*
			설명 : 참조 카운트 하나만큼 감소.
			$ 참고 : 참조 카운트가 0이 되면 삭제됨.
			*/
			CLASS_DECL_FUNC(Release)(void)
			{
				long ref = InterlockedDecrement(&my_Ref);
				if (ref == 0)
				{
					invalid();
					delete this;
				}

				return ref;
			}

			// 설명 : 
			INTERFACE_DECL_FUNC(invalid)(
				_X_ void) 
			{
				return HSDK_NOTIMPL;
			}

		protected:

			// 소멸자.
			CLASS_DECL_DESTRUCTOR(User)(void)
			{

			}

		private:

			// 설명 : 
			unsigned int my_ID;

			// 설명 : 
			volatile long my_Ref;

		} *PTR_USER;

		// 설명 : DATA, SOFTWARE를 생성.
		typedef DECL_INTERFACE(i_Factory)
		{

			// 소멸자.
			CLASS_DECL_DESTRUCTOR(i_Factory)(void)
			{

			}

			// 설명 : 
			INTERFACE_DECL_FUNC(create_User)(
				_Out_ PTR_USER * _user,
				_In_ const REF_KEY _key,
				_In_ void * _context = nullptr) = 0;

			// 설명 : 
			INTERFACE_DECL_FUNC(create_User)(
				_Out_ PTR_USER * _user,
				_In_ unsigned int _id,
				_In_ const PTR_DATA _data,
				_In_ void * _context = nullptr) = 0;

			// 설명 : 
			INTERFACE_DECL_FUNC(create_ID)(
				_Out_ unsigned int * _id,
				_In_ const REF_KEY _key) = 0;

			// 설명 : 
			INTERFACE_DECL_FUNC(get_Data)(
				_Out_ PTR_DATA * _data,
				_In_ const REF_KEY _key) = 0;

		} *PTR_FACTORY;

		/*
		설명 : EMBEDDED_ARCHITECTURE_PATTERN에서 PACKAGEBUNDLE을 수정할 수 있는 유일한 수단을 제공.
		$ 참고1 : PTR_USER _user 파라미터에 값이 왔을 때, Software::AddRef를 호출할 것을 권장.
		$ 참고2 : 1번이 충족된 경우 사용이 끝난 _user는 반드시 Software::Release를 호출할 것을 권장.
		*/
		typedef DECL_INTERFACE(i_Container)
		{

			// 소멸자.
			CLASS_DECL_DESTRUCTOR(i_Container)(void)
			{

			}

			// 설명 : 
			INTERFACE_DECL_FUNC(push)(
				/* [set] */ PTR_USER * _user) = 0;

			// 설명 : 
			INTERFACE_DECL_FUNC_T(void, pop)(
				_In_ PTR_USER * _user) = 0;

			// 설명 : 
			INTERFACE_DECL_FUNC_T(void, pop)(
				_In_ unsigned int _id) = 0;

			// 설명 : 
			INTERFACE_DECL_FUNC_T(void, clear)(
				_In_ const REF_KEY _key) = 0;

			// 설명 : 
			INTERFACE_DECL_FUNC_T(void, clear_All)(
				_X_ void) = 0;

			// 설명 : 
			INTERFACE_DECL_FUNC(move)(
				_In_ const REF_KEY _from,
				_In_ unsigned int _id,
				_In_ const REF_KEY _to,
				_Out_ PTR_USER * _user = nullptr) = 0;

			// 설명 : 
			INTERFACE_DECL_FUNC(move_all)(
				_In_ const REF_KEY _from,
				_In_ const REF_KEY _to,
				_In_ unsigned int _size,
				_Out_ PTR_USER * _uerbuffer = nullptr) = 0;

			// 설명 : 
			INTERFACE_DECL_FUNC_T(void, sort)(
				_X_ void) = 0;

			// 설명 : 
			INTERFACE_DECL_FUNC_T(unsigned int, size)(
				_In_ const REF_KEY _key) = 0;

			// 설명 : 
			INTERFACE_DECL_FUNC_T(unsigned int, size_All)(
				_X_ void) = 0;

		} *PTR_CONTAINER;

		// 설명 : EMBEDDED_ARCHITECTURE_PATTERN에서 PACKAGEBUNDLE을 검색할 수 있는 유일한 수단을 제공.
		typedef DECL_INTERFACE(i_Finder)
		{

			// 소멸자.
			CLASS_DECL_DESTRUCTOR(i_Finder)(void)
			{

			}

			// 설명 : 명시적인 _id 만으로 탐색
			INTERFACE_DECL_FUNC(find_Explicit)(
				_Out_ PTR_USER * _user,
				_In_ unsigned int _id)const = 0;

			// 설명 : 명시적인 _key 만으로 모두 탐색
			INTERFACE_DECL_FUNC(find_Explicit_All)(
				_Out_ PTR_USER * _userbuffer,
				_In_ const REF_KEY _key,
				_In_ unsigned int _size)const = 0;

			// 설명 : 명시적인 _key와 암묵적인 _data로 탐색
			INTERFACE_DECL_FUNC(find_implicit)(
				_Out_ PTR_USER * _user,
				_In_ const REF_KEY _key,
				_In_ const LPVOID _data,
				_In_ unsigned int _format,
				_In_ unsigned int _size)const = 0;

			// 설명 : 명시적인 _key와 암묵적인 _data로 모두 탐색
			INTERFACE_DECL_FUNC(find_implicit_All)(
				_Out_ PTR_USER * _userbuffer,
				_In_ const LPVOID _data,
				_In_ unsigned int _format,
				_In_ unsigned int _size)const = 0;

		} *PTR_FINDER;

		// 설명 : 
		INTERFACE_DECL_FUNC_T(PTR_FACTORY, get_Factory)(
			_X_ void) = 0;

		// 설명 : 
		INTERFACE_DECL_FUNC_T(PTR_CONTAINER, get_Container)(
			_X_ void) = 0;

		// 설명 : 
		INTERFACE_DECL_FUNC_T(PTR_FINDER, get_Finder)(
			_X_ void) = 0;

	};

}