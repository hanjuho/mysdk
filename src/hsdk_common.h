#pragma once
#pragma warning(disable : 4251)



#include <sal.h>



#define _X_
#define _Ref_



// ��ȯ ���� HRESULT�� ������ �Լ� ����.
#define DECL_FUNC(func)	\
	__declspec(nothrow) long __stdcall func

// ���� ��ȯ �� �Լ� ����.
#define DECL_FUNC_T(value, func) \
	__declspec(nothrow) value __stdcall func

// ������/�Ҹ��ڰ� ���� ���� ���� Ŭ���� ����.
#define DECL_INTERFACE(name) \
struct __declspec(novtable) name

// ����ü ����.
#define DECL_STRUCT(name) \
struct name

// Ŭ���� ����.
#define DECL_CLASS(name) \
class name



#ifdef HSDK_EXPORT
// ��������.
#define HSDK_DLL \
	__declspec(dllexport)
#else
// �ҷ�����.
#define HSDK_DLL \
	__declspec(dllimport)
#endif



// DECL_EXPORT DECL_FUNC ����.
#define DLL_DECL_FUNC(func) \
	HSDK_DLL DECL_FUNC(func)

// DECL_EXPORT DECL_FUNC_T ����.
#define DLL_DECL_FUNC_T(type, func)	\
	HSDK_DLL DECL_FUNC_T(type, func)

// DECL_EXPORT DECL_INTERFACE ����.
#define DLL_DECL_INTERFACE(name) \
struct HSDK_DLL __declspec(novtable) name

// DECL_EXPORT DECL_STRUCT ����.
#define DLL_DECL_STRUCT(name) \
struct HSDK_DLL name

// DECL_EXPORT DECL_CLASS ����.
#define DLL_DECL_CLASS(name) \
class HSDK_DLL name



// ��ȯ ���� HRESULT�� ������ ���� �Լ� ����.
#define INTERFACE_DECL_FUNC(func) \
	__declspec(nothrow) virtual long func

// ���� ��ȯ �� ���� �Լ� ����.
#define INTERFACE_DECL_FUNC_T(type, func) \
	__declspec(nothrow) virtual type func

// ����� ������ ����.
#define	CLASS_DECL_CONSTRUCTOR(_class) \
	explicit _class

/*
���� �Ҹ��� ����.
$ ���� : ���� �Ҹ��ڴ� �Ϲ� ���� �Լ��� ���������� �޸𸮸� �߰����� �޸𸮰� ������,
$ ������ ���� �Լ��� ���� Ŭ������ �������� ZeroMemory�� ȣ������ �� ���� �Լ� �����Ͱ� �ʱ�ȭ �ʿ� ����.
*/
#define	CLASS_DECL_DESTRUCTOR(_class) \
	virtual ~_class

/*
(����� ������) / (���� �Ҹ���) ����.
*/
#define CLASS_DECL_STRUCTOR(_class)	\
	CLASS_DECL_DESTRUCTOR(_class)(void); \
	CLASS_DECL_CONSTRUCTOR(_class)

/*
�Ϲ� �Ҹ��� ����.
$ ���� : A Ŭ������ ���� Ŭ������ B Ŭ������ A Ŭ���� �������� ������� ���� �Ҵ��� ���� ��,
$ �� A Ŭ������ �����Ͱ� A Ŭ������ ������ �� ä�� �Ҹ�ȴٸ� B Ŭ������ �Ҹ��ڴ� ȣ����� �ʴ� ���� ����.
*/
#define	CLASS_DECL_WARN_DESTRUCTOR(_class) \
	~_class

/*
(����� ������) / (�Ϲ� �Ҹ���) ����.
$ ���� : CLASS_DECL_WARN_DESTRUCTOR�� ���� ����.
*/
#define CLASS_DECL_WARN_STRUCTOR(_class)	\
	CLASS_DECL_WARN_DESTRUCTOR(_class)(void); \
	CLASS_DECL_CONSTRUCTOR(_class)

// ��ȯ ���� HRESULT�� ������ ��� �Լ� ����.
#define CLASS_DECL_FUNC(func) \
	__declspec(nothrow) long func

// ���� ��ȯ �� ��� �Լ� ����.
#define CLASS_DECL_FUNC_T(type, func) \
	__declspec(nothrow) type func

// ��ȯ ���� HRESULT�� ������ ���� ��� �Լ� ����.
#define CLASS_DECL_OPEN_FUNC(func) \
	__declspec(nothrow) static HRESULT func

// ���� ��ȯ �� ���� ��� �Լ� ����.
#define CLASS_DECL_OPEN_FUNC_T(type, func) \
	__declspec(nothrow) static type func



// ��ȯ ���� HRESULT�� ������ �Լ� ����.
#define IMPL_FUNC(func) \
	long __stdcall func

// ���� ��ȯ �� �Լ� ����.
#define IMPL_FUNC_T(value, func)	\
	value __stdcall func

// ������ ����.
#define CLASS_IMPL_CONSTRUCTOR(_parent, _class) \
	_parent::_class

// �Ҹ��� ����.
#define CLASS_IMPL_DESTRUCTOR(_parent, _class) \
	_parent::~_class

// ��ȯ ���� HRESULT�� ������ ��� �Լ� ����.
#define CLASS_IMPL_FUNC(_class,_func) \
	long _class::_func

// ���� ��ȯ �� ��� �Լ� ����.
#define CLASS_IMPL_FUNC_T(_class, _type, _func) \
	_type _class::_func



// atrr���� flag�� ���Ե� ��.
#define ADD_FLAG(atrr, flag) \
	(atrr | flag)

// atrr���� flag�� ���ܵ� ��.
#define SUB_FLAG(atrr, flag) \
	(atrr ^ flag)

// flag�� atrr�� ������ �� (����ũ).
#define IS_FLAG(atrr, flag) \
	(atrr & flag)



// hr�� ����.
#define IF_SUCCEEDED(hr) \
if (0 <= (long)(hr))

// hr�� ����.
#define IF_FAILED(hr) \
if (0 > (long)(hr))

// b�� ��.
#define IF_TRUE(b) \
if (b)

// b�� ����.
#define IF_FALSE(b)	\
if (!(b))

// p�� ��ȿ.
#define IF_VALID(p)	\
if (p)

// p�� ��ȿ.
#define IF_INVALID(p) \
if (nullptr == p)

// hr ��ȿ ����
#define HSDK_FAIL \
	0x80000000

// hr ��ȿ ����
#define HSDK_NOTIMPL \
	0xFFFFFFFF



// p�� �Ұ��ϰ�, ��ȿȭ.
#define DEL_POINTER(p) \
	IF_VALID(p){ delete p; p = nullptr; }

// array p�� �Ұ��ϰ�, ��ȿȭ.
#define DEL_POINTER_ARRAY(p) \
	IF_VALID(p){ delete[] p; p = nullptr; }

// com��ü�� �Ұ��ϰ�, ��ȿȭ.
#define DEL_COM(com) \
	IF_VALID(com){ com->Release(); com = nullptr; }

// com��ü�� ���� �Ұ��ϰ�, ��ȿȭ.
#define ERASE_COM(com) \
	IF_VALID(com){ while (com->Release()); com = nullptr; }



// ��ȯ ���� ������ �Լ� �ʱ�ȭ.
#define INIT_FUNC \
{return 0; }

// ���� ��ȯ �� �Լ� �ʱ�ȭ.
#define INIT_FUNC_T(value) \
{return value; }