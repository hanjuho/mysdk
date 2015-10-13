#pragma once



#include "interface/collider2d.h"
#include <vector>



namespace hsdk
{
	namespace physics2d
	{

		// ���� : 
		DLL_DECL_CLASS(Collider2DPolygon)
			: public i::i_Collider2D
		{
		public:

			// ������.
			CLASS_DECL_CONSTRUCTOR(Collider2DPolygon)(
				/* [r] */ float _density);

			// ���� : collider�� �Ӽ�.
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

			// ���� : Half width and half height.
			CLASS_DECL_FUNC_T(void, set_Box)(
				/* [r] */ float _hw,
				/* [r] */ float _hh);

			// ���� : vertex = Vector2D.
			CLASS_DECL_FUNC_T(void, set_Polygon)(
				/* [r] */ const Vector2D * _vertices,
				/* [r] */ unsigned int _size);

			// ���� : The extreme point along a direction within a Collider2DPolygon.
			CLASS_DECL_FUNC_T(Vector2D, support)(
				/* [r] */ const Vector2D & _dir)const;
		
		protected:

			// ���� : 
			float m_Density;

			// ���� : 
			float m_Area;

			// ���� :
			float m_Radius;

		private:

			//
			std::vector<Vector2D> my_Vertices;

			//
			std::vector<Vector2D> my_Normals;

		};

	}
}