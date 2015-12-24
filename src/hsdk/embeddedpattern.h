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

	// ���� : Data�� �����ϴ� User�� �������� ���� Ŭ����. �� ����� �Ӻ���� �ý��۰� ��� �̸��� �Ӻ���� ��Ű��ó �����̶� ����.
	template<typename DATA, typename USE, typename KEY = std::wstring> DECL_INTERFACE(EMBEDDED_ARCHITECTURE_PATTERN)
	{

		/*
		���� : �޸� ���簡 �Ͼ�� ������ DATA�� ���� �Լ��� ���� ���� ġ������ �� ����.
		& ���� : DATA�� ���� ������ Factory���� ����.
		*/
		typedef	DATA	DATA, &REF_DATA, *PTR_DATA;

		/*
		���� : USE�� ����ϴ� ��ü�� ��������� ������ USE�� �ǵ����̸� �������̽��� ����.
		*/
		typedef	USE		USE, &REF_USE, *PTR_USE;

		/*
		���� : USE�� ã�Ƴ��� Ű.
		*/
		typedef	KEY		KEY, &REF_KEY, *PTR_KEY;

		/*
		���� : USER�� �Ļ� Ŭ����, SOFTWARE�� DATA�� �����ϴ� ������ ����.
		$ ����1 : DATA�� �Ҹ�Ǹ� SOFTWARE::invaild�� ȣ��.
		$ ����2 : SOFTWARE Ÿ�� ������ ������ �ʱ�ȭ�ϸ� �ݵ�� AddRef�� ȣ��.
		$ ����3 : SOFTWARE Ÿ�� ������ ������ �Ҹ�Ǳ� �� �ݵ�� release�� ȣ��.
		$ ����4 : SOFTWARE::release�� ȣ��Ǿ� �������� 0�� �Ǹ� ��ü�� �Ҹ�.
		*/
		typedef DECL_CLASS(User)
			: public USE
		{
		public:

			// ������.
			CLASS_DECL_CONSTRUCTOR(User)(
				_In_ unsigned int _id)
				: my_ID(_id), my_Ref(1)
			{

			}

			// ���� : 
			CLASS_DECL_FUNC_T(unsigned int, get_ID)(
				_X_ void)const
			{
				return my_ID;
			}

			// ���� : ���� ī��Ʈ�� �ϳ���ŭ ����.
			CLASS_DECL_FUNC(AddRef)(void)
			{
				return InterlockedIncrement(&my_Ref);
			}

			/*
			���� : ���� ī��Ʈ �ϳ���ŭ ����.
			$ ���� : ���� ī��Ʈ�� 0�� �Ǹ� ������.
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

			// ���� : 
			INTERFACE_DECL_FUNC(invalid)(
				_X_ void) 
			{
				return HSDK_NOTIMPL;
			}

		protected:

			// �Ҹ���.
			CLASS_DECL_DESTRUCTOR(User)(void)
			{

			}

		private:

			// ���� : 
			unsigned int my_ID;

			// ���� : 
			volatile long my_Ref;

		} *PTR_USER;

		// ���� : DATA, SOFTWARE�� ����.
		typedef DECL_INTERFACE(i_Factory)
		{

			// �Ҹ���.
			CLASS_DECL_DESTRUCTOR(i_Factory)(void)
			{

			}

			// ���� : 
			INTERFACE_DECL_FUNC(create_User)(
				_Out_ PTR_USER * _user,
				_In_ const REF_KEY _key,
				_In_ void * _context = nullptr) = 0;

			// ���� : 
			INTERFACE_DECL_FUNC(create_User)(
				_Out_ PTR_USER * _user,
				_In_ unsigned int _id,
				_In_ const PTR_DATA _data,
				_In_ void * _context = nullptr) = 0;

			// ���� : 
			INTERFACE_DECL_FUNC(create_ID)(
				_Out_ unsigned int * _id,
				_In_ const REF_KEY _key) = 0;

			// ���� : 
			INTERFACE_DECL_FUNC(get_Data)(
				_Out_ PTR_DATA * _data,
				_In_ const REF_KEY _key) = 0;

		} *PTR_FACTORY;

		/*
		���� : EMBEDDED_ARCHITECTURE_PATTERN���� PACKAGEBUNDLE�� ������ �� �ִ� ������ ������ ����.
		$ ����1 : PTR_USER _user �Ķ���Ϳ� ���� ���� ��, Software::AddRef�� ȣ���� ���� ����.
		$ ����2 : 1���� ������ ��� ����� ���� _user�� �ݵ�� Software::Release�� ȣ���� ���� ����.
		*/
		typedef DECL_INTERFACE(i_Container)
		{

			// �Ҹ���.
			CLASS_DECL_DESTRUCTOR(i_Container)(void)
			{

			}

			// ���� : 
			INTERFACE_DECL_FUNC(push)(
				/* [set] */ PTR_USER * _user) = 0;

			// ���� : 
			INTERFACE_DECL_FUNC_T(void, pop)(
				_In_ PTR_USER * _user) = 0;

			// ���� : 
			INTERFACE_DECL_FUNC_T(void, pop)(
				_In_ unsigned int _id) = 0;

			// ���� : 
			INTERFACE_DECL_FUNC_T(void, clear)(
				_In_ const REF_KEY _key) = 0;

			// ���� : 
			INTERFACE_DECL_FUNC_T(void, clear_All)(
				_X_ void) = 0;

			// ���� : 
			INTERFACE_DECL_FUNC(move)(
				_In_ const REF_KEY _from,
				_In_ unsigned int _id,
				_In_ const REF_KEY _to,
				_Out_ PTR_USER * _user = nullptr) = 0;

			// ���� : 
			INTERFACE_DECL_FUNC(move_all)(
				_In_ const REF_KEY _from,
				_In_ const REF_KEY _to,
				_In_ unsigned int _size,
				_Out_ PTR_USER * _uerbuffer = nullptr) = 0;

			// ���� : 
			INTERFACE_DECL_FUNC_T(void, sort)(
				_X_ void) = 0;

			// ���� : 
			INTERFACE_DECL_FUNC_T(unsigned int, size)(
				_In_ const REF_KEY _key) = 0;

			// ���� : 
			INTERFACE_DECL_FUNC_T(unsigned int, size_All)(
				_X_ void) = 0;

		} *PTR_CONTAINER;

		// ���� : EMBEDDED_ARCHITECTURE_PATTERN���� PACKAGEBUNDLE�� �˻��� �� �ִ� ������ ������ ����.
		typedef DECL_INTERFACE(i_Finder)
		{

			// �Ҹ���.
			CLASS_DECL_DESTRUCTOR(i_Finder)(void)
			{

			}

			// ���� : ������� _id ������ Ž��
			INTERFACE_DECL_FUNC(find_Explicit)(
				_Out_ PTR_USER * _user,
				_In_ unsigned int _id)const = 0;

			// ���� : ������� _key ������ ��� Ž��
			INTERFACE_DECL_FUNC(find_Explicit_All)(
				_Out_ PTR_USER * _userbuffer,
				_In_ const REF_KEY _key,
				_In_ unsigned int _size)const = 0;

			// ���� : ������� _key�� �Ϲ����� _data�� Ž��
			INTERFACE_DECL_FUNC(find_implicit)(
				_Out_ PTR_USER * _user,
				_In_ const REF_KEY _key,
				_In_ const LPVOID _data,
				_In_ unsigned int _format,
				_In_ unsigned int _size)const = 0;

			// ���� : ������� _key�� �Ϲ����� _data�� ��� Ž��
			INTERFACE_DECL_FUNC(find_implicit_All)(
				_Out_ PTR_USER * _userbuffer,
				_In_ const LPVOID _data,
				_In_ unsigned int _format,
				_In_ unsigned int _size)const = 0;

		} *PTR_FINDER;

		// ���� : 
		INTERFACE_DECL_FUNC_T(PTR_FACTORY, get_Factory)(
			_X_ void) = 0;

		// ���� : 
		INTERFACE_DECL_FUNC_T(PTR_CONTAINER, get_Container)(
			_X_ void) = 0;

		// ���� : 
		INTERFACE_DECL_FUNC_T(PTR_FINDER, get_Finder)(
			_X_ void) = 0;

	};

}