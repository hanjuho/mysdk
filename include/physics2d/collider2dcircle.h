#pragma once



#include "interface/collider2d.h"



namespace hsdk
{
	namespace physics2d
	{

		// ���� : 
		DLL_DECL_CLASS(Collider2DCircle)
			: public i::i_Collider2D
		{
		public:

			// ������.
			CLASS_DECL_CONSTRUCTOR(Collider2DCircle)(
				/* [r] */ float _radius,
				/* [r] */ float _density);
			
			// ���� : collider�� �Ӽ�
			INTERFACE_DECL_FUNC_T(unsigned int, type)(
				/* [x] */ void)const final;

			// ���� : 
			INTERFACE_DECL_FUNC_T(unsigned int, numOfVerties)(
				/* [x] */ void)const;

			// ���� : 
			INTERFACE_DECL_FUNC_T(Vector2D, vertex)(
				/* [r] */ unsigned int _index)const;

			// ���� : 
			INTERFACE_DECL_FUNC_T(const Vector2D *, vertices)(
				/* [x] */ void)const;

			// ���� : 
			INTERFACE_DECL_FUNC_T(Vector2D, normal)(
				/* [r] */ unsigned int _index)const;

			// ���� : 
			INTERFACE_DECL_FUNC_T(const Vector2D *, normals)(
				/* [x] */ void)const;

			// ���� : 
			INTERFACE_DECL_FUNC_T(float, density)(
				/* [x] */ void)const final;

			// ���� : 
			INTERFACE_DECL_FUNC_T(float, area)(
				/* [x] */ void)const final;

			// ���� : 
			INTERFACE_DECL_FUNC_T(float, radius)(
				/* [x] */ void)const final;

		private:

			// ���� : 
			float my_Radius;

			// ���� : 
			float my_Density;

		};

	}
}