#pragma once



#include "interface/physics2dengine.h"
#include "manifold2d.h"
#include <list>
#include <vector>
#include <hash_map>



namespace hsdk
{
	namespace physics2d
	{

		// ���� : �浹 ����.
		DLL_DECL_CLASS(Physics2DEngine)
			: public i::i_Physics2DEngine
		{
		public:

			// ���� : 
			DECL_STRUCT(My_SOURCE_DESC)
			{

				// ������.
				CLASS_DECL_CONSTRUCTOR(My_SOURCE_DESC)(void);

				// ������.
				CLASS_DECL_CONSTRUCTOR(My_SOURCE_DESC)(
					/* [set] */ i::i_Physics2DObject * _object,
					/* [set] */ i::i_Collision2DListener * _listner,
					/* [r] */ long _valid);

				// �Ҹ���.
				CLASS_DECL_WARN_DESTRUCTOR(My_SOURCE_DESC)(void);

				// ���� : 
				CLASS_DECL_FUNC_T(void, operator =)(
					/* [r] */ const SOURCE_DESC & _desc);

				// ���� : 
				i::i_Physics2DObject * const object;

				// ���� : 
				i::i_Collision2DListener * const listener;

				// ���� : 
				long valid = true;

			};

			// ���� : 
			DECL_STRUCT(R_Manifold)
			{
				std::vector<My_SOURCE_DESC>::iterator a;
				std::vector<My_SOURCE_DESC>::iterator b;
				Manifold2D m;
			};

			// ���� : ���� �����, �浹�� �� ��ü�� �浹 ����.
			typedef std::list<R_Manifold> RESULT_CONTACT;

		public:

			// ���� : 
			INTERFACE_DECL_FUNC_T(void, find)(
				/* [r] */ i::i_Physics2DObject * _object,
				/* [r] */ i::i_Boundary2DListener * _listener,
				/* [r] */ float _distance,
				/* [r] */ long _sort = false)final;

			/*
			���� : �� ���� ������Ʈ�� �浹 ���踦 ����.
			$ ���� : _param�� ���Ǹ�(_param�� nullptr �� �� ����), �ݵ�� Manifold2D �̿��� ��.
			*/
			INTERFACE_DECL_FUNC_T(void, operate)(
				/* [r/w] */ i::i_Physics2DObject * _objA,
				/* [r/w] */ i::i_Physics2DObject * _objB,
				/* [r] */ const i::i_Terrain2D * _terrain,
				/* [r] */ void * _param = nullptr)final;

			/*
			���� : Physics2DEngine::run() �Լ��� ȣ������ �� ���Ǵ� ���� �ڿ��� ����.
			$ ���� : SOURCE_DESC::vaild�� ���� 0 �̸��� ��, ��ü�� ���ŵǸ� ������ �����.
			(vaild & 0x01) : delete SOURCE_DESC::object
			(vaild & 0x02) : delete SOURCE_DESC::listener
			*/
			INTERFACE_DECL_FUNC(update)(
				/* [r] */ SOURCE_DESC * (&_source),
				/* [r] */ unsigned int _size)final;

			/*
			���� : Physics2DEngine::update() �Լ��� ���� ���ŵ� ���� �ڿ��� �������� ���� ����� ����.
			$ ���� : _param �Ķ���ʹ� ������ ����.
			*/
			INTERFACE_DECL_FUNC_T(void, run)(
				/* [r] */ const i::i_Terrain2D * _terrain,
				/* [r] */ const Vector2D & _gravity,
				/* [r] */ float _dt,
				/* [r] */ void * _param = nullptr)final;

		private:

			// ���� : 
			static std::hash_map<unsigned int, std::vector<My_SOURCE_DESC>> RESOURCES;

		};

	}
}