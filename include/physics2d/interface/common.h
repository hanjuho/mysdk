#pragma once



#include "../../hsdk_common.h"



namespace hsdk
{
	namespace physics2d
	{
		DECL_STRUCT(Vector2D);
		DECL_STRUCT(Matrix2D);
		DECL_STRUCT(Manifold2D);

		namespace i
		{
			DECL_STRUCT(i_Terrain2D);
			DECL_STRUCT(i_Collider2D);
			DECL_STRUCT(i_RigidBody2D);
			DECL_STRUCT(i_Physics2DObject);
			DECL_STRUCT(i_Physics2DEngine);
			DECL_STRUCT(i_Collision2DListener);
			DECL_STRUCT(i_Boundary2DListener);
		}
	}
}