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
					/* [r] */ i_Physics2DObject * _object,
					/* [r] */ i_Boundary2DListener * _listener,
					/* [r] */ float _distance,
					/* [r] */ long _sort = false) = 0;
				
				// ���� : 
				INTERFACE_DECL_FUNC_T(void, operate)(
					/* [r] */ i_Physics2DObject * _objA,
					/* [r] */ i_Physics2DObject * _objB,
					/* [r] */ const i::i_Terrain2D * _terrain,
					/* [r] */ void * _param = nullptr) = 0;

				// ���� : 
				INTERFACE_DECL_FUNC(update)(
					/* [r] */ SOURCE_DESC * (&_source),
					/* [r] */ unsigned int _size) = 0;

				// ���� : 
				INTERFACE_DECL_FUNC_T(void, run)(
					/* [r] */ const i_Terrain2D * _terrain,
					/* [r] */ const Vector2D & _gravity,
					/* [r] */ float _dt,
					/* [r] */ void * _param = nullptr) = 0;

			};

		}
	}
}