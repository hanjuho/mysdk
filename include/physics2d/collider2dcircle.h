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
				_In_ float _radius,
				_In_ float _density);
			
			// ���� : collider�� �Ӽ�
			INTERFACE_DECL_FUNC_T(unsigned int, type)(
				_X_ void)const final;

			// ���� : 
			INTERFACE_DECL_FUNC_T(unsigned int, numOfVerties)(
				_X_ void)const;

			// ���� : 
			INTERFACE_DECL_FUNC_T(Vector2D, vertex)(
				_In_ unsigned int _index)const;

			// ���� : 
			INTERFACE_DECL_FUNC_T(const Vector2D *, vertices)(
				_X_ void)const;

			// ���� : 
			INTERFACE_DECL_FUNC_T(Vector2D, normal)(
				_In_ unsigned int _index)const;

			// ���� : 
			INTERFACE_DECL_FUNC_T(const Vector2D *, normals)(
				_X_ void)const;

			// ���� : 
			INTERFACE_DECL_FUNC_T(float, density)(
				_X_ void)const final;

			// ���� : 
			INTERFACE_DECL_FUNC_T(float, area)(
				_X_ void)const final;

			// ���� : 
			INTERFACE_DECL_FUNC_T(float, radius)(
				_X_ void)const final;

		private:

			// ���� : 
			float my_Radius;

			// ���� : 
			float my_Density;

		};

	}
}