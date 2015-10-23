#pragma once



#include "common.h"
#include "physics2dobject.h"
#include "collision2dlistener.h"



namespace hsdk
{
	namespace physics2d
	{
		namespace i
		{

			// ���� : 
			DLL_DECL_INTERFACE(i_Physics2DEngine)
			{

				// ���� : 
				DECL_STRUCT(SOURCE_DESC)
				{

					// ���� : 
					i_Physics2DObject * const object;

					// ���� : 
					i_Collision2DListener * const listener;

					// ���� : 
					long valid = true;

				};

				// ���� : 
				INTERFACE_DECL_FUNC_T(void, find)(
					_In_ i_Physics2DObject * _object,
					_In_ i_Boundary2DListener * _listener,
					_In_ float _distance,
					_In_ long _sort = false) = 0;
				
				// ���� : 
				INTERFACE_DECL_FUNC_T(void, operate)(
					_In_ i_Physics2DObject * _objA,
					_In_ i_Physics2DObject * _objB,
					_In_ const i::i_Terrain2D * _terrain,
					_In_ void * _param = nullptr) = 0;

				// ���� : 
				INTERFACE_DECL_FUNC(update)(
					_In_ SOURCE_DESC * (&_source),
					_In_ unsigned int _size) = 0;

				// ���� : 
				INTERFACE_DECL_FUNC_T(void, run)(
					_In_ const i_Terrain2D * _terrain,
					_In_ const Vector2D & _gravity,
					_In_ float _dt,
					_In_ void * _param = nullptr) = 0;

			};

		}
	}
}