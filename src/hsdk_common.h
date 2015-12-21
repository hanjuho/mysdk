#pragma once
#pragma warning(disable : 4251)



#include <sal.h>



#define _X_
#define _Ref_



// 반환 값이 HRESULT로 고정된 함수 선언.
#define DECL_FUNC(func)	\
	__declspec(nothrow) long __stdcall func

// 임의 반환 값 함수 선언.
#define DECL_FUNC_T(value, func) \
	__declspec(nothrow) value __stdcall func

// 생성자/소멸자가 없는 순수 가상 클래스 선언.
#define DECL_INTERFACE(name) \
struct __declspec(novtable) name

// 구조체 선언.
#define DECL_STRUCT(name) \
struct name

// 클래스 선언.
#define DECL_CLASS(name) \
class name



#ifdef HSDK_EXPORT
// 내보내기.
#define HSDK_DLL \
	__declspec(dllexport)
#else
// 불러오기.
#define HSDK_DLL \
	__declspec(dllimport)
#endif



// DECL_EXPORT DECL_FUNC 선언.
#define DLL_DECL_FUNC(func) \
	HSDK_DLL DECL_FUNC(func)

// DECL_EXPORT DECL_FUNC_T 선언.
#define DLL_DECL_FUNC_T(type, func)	\
	HSDK_DLL DECL_FUNC_T(type, func)

// DECL_EXPORT DECL_INTERFACE 선언.
#define DLL_DECL_INTERFACE(name) \
struct HSDK_DLL __declspec(novtable) name

// DECL_EXPORT DECL_STRUCT 선언.
#define DLL_DECL_STRUCT(name) \
struct HSDK_DLL name

// DECL_EXPORT DECL_CLASS 선언.
#define DLL_DECL_CLASS(name) \
class HSDK_DLL name



// 반환 값이 HRESULT로 고정된 가상 함수 선언.
#define INTERFACE_DECL_FUNC(func) \
	__declspec(nothrow) virtual long func

// 임의 반환 값 가상 함수 선언.
#define INTERFACE_DECL_FUNC_T(type, func) \
	__declspec(nothrow) virtual type func

// 명시적 생성자 선언.
#define	CLASS_DECL_CONSTRUCTOR(_class) \
	explicit _class

/*
가상 소멸자 선언.
$ 주의 : 가상 소멸자는 일반 가상 함수와 마찬가지로 메모리를 추가적인 메모리가 생성됨,
$ 때문에 가상 함수가 없는 클래스로 보일지라도 ZeroMemory를 호출했을 때 가상 함수 포인터가 초기화 됨에 주의.
*/
#define	CLASS_DECL_DESTRUCTOR(_class) \
	virtual ~_class

/*
(명시적 생성자) / (가상 소멸자) 선언.
*/
#define CLASS_DECL_STRUCTOR(_class)	\
	CLASS_DECL_DESTRUCTOR(_class)(void); \
	CLASS_DECL_CONSTRUCTOR(_class)

/*
일반 소멸자 선언.
$ 주의 : A 클래스의 하위 클래스인 B 클래스를 A 클래스 포인터의 모습으로 동적 할당을 했을 때,
$ 그 A 클래스의 포인터가 A 클래스의 포인터 인 채로 소멸된다면 B 클래스의 소멸자는 호출되지 않는 점에 주의.
*/
#define	CLASS_DECL_WARN_DESTRUCTOR(_class) \
	~_class

/*
(명시적 생성자) / (일반 소멸자) 선언.
$ 주의 : CLASS_DECL_WARN_DESTRUCTOR의 설명 참조.
*/
#define CLASS_DECL_WARN_STRUCTOR(_class)	\
	CLASS_DECL_WARN_DESTRUCTOR(_class)(void); \
	CLASS_DECL_CONSTRUCTOR(_class)

// 반환 값이 HRESULT로 고정된 멤버 함수 선언.
#define CLASS_DECL_FUNC(func) \
	__declspec(nothrow) long func

// 임의 반환 값 멤버 함수 선언.
#define CLASS_DECL_FUNC_T(type, func) \
	__declspec(nothrow) type func

// 반환 값이 HRESULT로 고정된 정적 멤버 함수 선언.
#define CLASS_DECL_OPEN_FUNC(func) \
	__declspec(nothrow) static HRESULT func

// 임의 반환 값 정적 멤버 함수 선언.
#define CLASS_DECL_OPEN_FUNC_T(type, func) \
	__declspec(nothrow) static type func



// 반환 값이 HRESULT로 고정된 함수 정의.
#define IMPL_FUNC(func) \
	long __stdcall func

// 임의 반환 값 함수 정의.
#define IMPL_FUNC_T(value, func)	\
	value __stdcall func

// 생성자 정의.
#define CLASS_IMPL_CONSTRUCTOR(_parent, _class) \
	_parent::_class

// 소멸자 정의.
#define CLASS_IMPL_DESTRUCTOR(_parent, _class) \
	_parent::~_class

// 반환 값이 HRESULT로 고정된 멤버 함수 정의.
#define CLASS_IMPL_FUNC(_class,_func) \
	long _class::_func

// 임의 반환 값 멤버 함수 정의.
#define CLASS_IMPL_FUNC_T(_class, _type, _func) \
	_type _class::_func



// atrr에서 flag가 포함된 값.
#define ADD_FLAG(atrr, flag) \
	(atrr | flag)

// atrr에서 flag가 제외된 값.
#define SUB_FLAG(atrr, flag) \
	(atrr ^ flag)

// flag에 atrr가 투영된 값 (마스크).
#define IS_FLAG(atrr, flag) \
	(atrr & flag)



// hr이 성공.
#define IF_SUCCEEDED(hr) \
if (0 <= (long)(hr))

// hr이 실패.
#define IF_FAILED(hr) \
if (0 > (long)(hr))

// b가 참.
#define IF_TRUE(b) \
if (b)

// b가 거짓.
#define IF_FALSE(b)	\
if (!(b))

// p가 유효.
#define IF_VALID(p)	\
if (p)

// p가 무효.
#define IF_INVALID(p) \
if (nullptr == p)

// hr 무효 상태
#define HSDK_FAIL \
	0x80000000

// hr 무효 상태
#define HSDK_NOTIMPL \
	0xFFFFFFFF



// p를 소거하고, 무효화.
#define DEL_POINTER(p) \
	IF_VALID(p){ delete p; p = nullptr; }

// array p를 소거하고, 무효화.
#define DEL_POINTER_ARRAY(p) \
	IF_VALID(p){ delete[] p; p = nullptr; }

// com객체를 소거하고, 무효화.
#define DEL_COM(com) \
	IF_VALID(com){ com->Release(); com = nullptr; }

// com객체를 완전 소거하고, 무효화.
#define ERASE_COM(com) \
	IF_VALID(com){ while (com->Release()); com = nullptr; }



// 반환 값이 정수인 함수 초기화.
#define INIT_FUNC \
{return 0; }

// 임의 반환 값 함수 초기화.
#define INIT_FUNC_T(value) \
{return value; }