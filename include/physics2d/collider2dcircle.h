#pragma once



#include "interface/collider2d.h"



namespace hsdk
{
	namespace physics2d
	{

		// 설명 : 
		DLL_DECL_CLASS(Collider2DCircle)
			: public i::i_Collider2D
		{
		public:

			// 생성자.
			CLASS_DECL_CONSTRUCTOR(Collider2DCircle)(
				/* [r] */ float _radius,
				/* [r] */ float _density);
			
			// 설명 : collider의 속성
			INTERFACE_DECL_FUNC_T(unsigned int, type)(
				/* [x] */ void)const final;

			// 설명 : 
			INTERFACE_DECL_FUNC_T(unsigned int, numOfVerties)(
				/* [x] */ void)const;

			// 설명 : 
			INTERFACE_DECL_FUNC_T(Vector2D, vertex)(
				/* [r] */ unsigned int _index)const;

			// 설명 : 
			INTERFACE_DECL_FUNC_T(const Vector2D *, vertices)(
				/* [x] */ void)const;

			// 설명 : 
			INTERFACE_DECL_FUNC_T(Vector2D, normal)(
				/* [r] */ unsigned int _index)const;

			// 설명 : 
			INTERFACE_DECL_FUNC_T(const Vector2D *, normals)(
				/* [x] */ void)const;

			// 설명 : 
			INTERFACE_DECL_FUNC_T(float, density)(
				/* [x] */ void)const final;

			// 설명 : 
			INTERFACE_DECL_FUNC_T(float, area)(
				/* [x] */ void)const final;

			// 설명 : 
			INTERFACE_DECL_FUNC_T(float, radius)(
				/* [x] */ void)const final;

		private:

			// 설명 : 
			float my_Radius;

			// 설명 : 
			float my_Density;

		};

	}
}