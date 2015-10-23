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
				_Out_ Manifold2D & _m,
				_In_ const i::i_RigidBody2D * _abody,
				_In_ const i::i_RigidBody2D * _bbody);

			// 설명 : 
			DLL_DECL_FUNC_T(void, impulse_Apply)(
				_Out_ Manifold2D & _m,
				_In_ const Vector2D & _apos,
				_In_ i::i_RigidBody2D * _abody,
				_In_ const Vector2D & _bpos,
				_In_ i::i_RigidBody2D * _bbody,
				_In_ float _glength);
		}

	}
}