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

			// 설명 : 
			DLL_DECL_INTERFACE(i_Physics2DEngine)
			{

				// 설명 : 
				DECL_STRUCT(SOURCE_DESC)
				{

					// 설명 : 
					i_Physics2DObject * const object;

					// 설명 : 
					i_Collision2DListener * const listener;

					// 설명 : 
					long valid = true;

				};

				// 설명 : 
				INTERFACE_DECL_FUNC_T(void, find)(
					/* [r] */ i_Physics2DObject * _object,
					/* [r] */ i_Boundary2DListener * _listener,
					/* [r] */ float _distance,
					/* [r] */ long _sort = false) = 0;
				
				// 설명 : 
				INTERFACE_DECL_FUNC_T(void, operate)(
					/* [r] */ i_Physics2DObject * _objA,
					/* [r] */ i_Physics2DObject * _objB,
					/* [r] */ const i::i_Terrain2D * _terrain,
					/* [r] */ void * _param = nullptr) = 0;

				// 설명 : 
				INTERFACE_DECL_FUNC(update)(
					/* [r] */ SOURCE_DESC * (&_source),
					/* [r] */ unsigned int _size) = 0;

				// 설명 : 
				INTERFACE_DECL_FUNC_T(void, run)(
					/* [r] */ const i_Terrain2D * _terrain,
					/* [r] */ const Vector2D & _gravity,
					/* [r] */ float _dt,
					/* [r] */ void * _param = nullptr) = 0;

			};

		}
	}
}