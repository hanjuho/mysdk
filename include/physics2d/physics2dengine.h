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

		// 설명 : 충돌 계산기.
		DLL_DECL_CLASS(Physics2DEngine)
			: public i::i_Physics2DEngine
		{
		public:

			// 설명 : 
			DECL_STRUCT(My_SOURCE_DESC)
			{

				// 생성자.
				CLASS_DECL_CONSTRUCTOR(My_SOURCE_DESC)(void);

				// 생성자.
				CLASS_DECL_CONSTRUCTOR(My_SOURCE_DESC)(
					/* [set] */ i::i_Physics2DObject * _object,
					/* [set] */ i::i_Collision2DListener * _listner,
					_In_ long _valid);

				// 소멸자.
				CLASS_DECL_WARN_DESTRUCTOR(My_SOURCE_DESC)(void);

				// 설명 : 
				CLASS_DECL_FUNC_T(void, operator =)(
					_In_ const SOURCE_DESC & _desc);

				// 설명 : 
				i::i_Physics2DObject * const object;

				// 설명 : 
				i::i_Collision2DListener * const listener;

				// 설명 : 
				long valid = true;

			};

			// 설명 : 
			DECL_STRUCT(R_Manifold)
			{
				std::vector<My_SOURCE_DESC>::iterator a;
				std::vector<My_SOURCE_DESC>::iterator b;
				Manifold2D m;
			};

			// 설명 : 엔진 결과물, 충돌한 두 강체의 충돌 정보.
			typedef std::list<R_Manifold> RESULT_CONTACT;

		public:

			// 설명 : 
			INTERFACE_DECL_FUNC_T(void, find)(
				_In_ i::i_Physics2DObject * _object,
				_In_ i::i_Boundary2DListener * _listener,
				_In_ float _distance,
				_In_ long _sort = false)final;

			/*
			설명 : 두 물리 오브젝트의 충돌 관계를 서술.
			$ 참고 : _param가 사용되며(_param는 nullptr 일 수 없음), 반드시 Manifold2D 이여야 함.
			*/
			INTERFACE_DECL_FUNC_T(void, operate)(
				_Inout_ i::i_Physics2DObject * _objA,
				_Inout_ i::i_Physics2DObject * _objB,
				_In_ const i::i_Terrain2D * _terrain,
				_In_ void * _param = nullptr)final;

			/*
			설명 : Physics2DEngine::run() 함수를 호출했을 때 사용되는 연산 자원을 갱신.
			$ 참고 : SOURCE_DESC::vaild의 값이 0 미만일 때, 객체가 제거되면 다음이 수행됨.
			(vaild & 0x01) : delete SOURCE_DESC::object
			(vaild & 0x02) : delete SOURCE_DESC::listener
			*/
			INTERFACE_DECL_FUNC(update)(
				_In_ SOURCE_DESC * (&_source),
				_In_ unsigned int _size)final;

			/*
			설명 : Physics2DEngine::update() 함수를 통해 갱신된 연산 자원을 바탕으로 물리 계산을 수행.
			$ 참고 : _param 파라미터는 사용되지 않음.
			*/
			INTERFACE_DECL_FUNC_T(void, run)(
				_In_ const i::i_Terrain2D * _terrain,
				_In_ const Vector2D & _gravity,
				_In_ float _dt,
				_In_ void * _param = nullptr)final;

		private:

			// 설명 : 
			static std::hash_map<unsigned int, std::vector<My_SOURCE_DESC>> RESOURCES;

		};

	}
}