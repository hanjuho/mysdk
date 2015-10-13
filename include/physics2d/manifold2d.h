#pragma once



#include "interface/rigidbody2d.h"
#include "interface/physics2dobject.h"
#include "vector2d.h"



namespace hsdk
{
	namespace physics2d
	{
		
		// 설명 : 
		DLL_DECL_STRUCT(Manifold2D)
		{
			
			// Points of contact during collision
			Vector2D contacts[2];

			// Number of contacts that occured during collision
			unsigned int contact_count;

			// Depth of penetration from collision
			float penetration;

			// From B to A
			Vector2D normal;

			// 설명 : Mixed restitution.
			float e;

			// 설명 : Mixed dynamic friction.
			float df;

			// 설명 : Mixed static friction.
			float sf;

		};

		namespace manifold
		{

			// 설명 : 
			DLL_DECL_FUNC_T(void, initialize)(
				/* [w] */ Manifold2D & _m,
				/* [r] */ const i::i_RigidBody2D * _abody,
				/* [r] */ const i::i_RigidBody2D * _bbody);

			// 설명 : 
			DLL_DECL_FUNC_T(void, impulse_Apply)(
				/* [w] */ Manifold2D & _m,
				/* [r] */ const Vector2D & _apos,
				/* [r] */ i::i_RigidBody2D * _abody,
				/* [r] */ const Vector2D & _bpos,
				/* [r] */ i::i_RigidBody2D * _bbody,
				/* [r] */ float _glength);
		}

	}
}