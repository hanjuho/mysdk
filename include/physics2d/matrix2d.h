#pragma once



#include "vector2d.h"



namespace hsdk
{
	namespace physics2d
	{

		// ���� : 
		DLL_DECL_STRUCT(Matrix2D)
		{

			union
			{
				struct
				{
					float m00, m01;
					float m10, m11;
				};

				float m[2][2];
				float v[4];
			};

			// ������.
			CLASS_DECL_CONSTRUCTOR(Matrix2D)(void);

			// ������.
			CLASS_DECL_CONSTRUCTOR(Matrix2D)(
				_In_ float _radians);

			// ������
			CLASS_DECL_CONSTRUCTOR(Matrix2D)(
				_In_ float _a,
				_In_ float _b,
				_In_ float _c,
				_In_ float _d);

			// ���� : 
			CLASS_DECL_FUNC_T(const Vector2D, operator*)(
				_In_ const Vector2D & _rhs) const;

			// ���� : 
			CLASS_DECL_FUNC_T(const Matrix2D, operator*)(
				_In_ const Matrix2D & _rhs) const;

			// ���� : 
			CLASS_DECL_FUNC_T(void, operator=)(
				_In_ const Matrix2D & _rhs);

			// ���� : 
			CLASS_DECL_FUNC_T(void, operator=)(
				_In_ float _radians);

		};

		namespace matrix2d
		{

			// ���� : 
			inline CLASS_DECL_FUNC_T(void, rotate)(
				_Out_ Matrix2D & _mat,
				_In_ float _radians)
			{
				float c = std::cos(_radians);
				float s = std::sin(_radians);

				_mat.m00 = c; 
				_mat.m01 = -s;
				_mat.m10 = s; 
				_mat.m11 = c;
			}

			// ���� :
			inline CLASS_DECL_FUNC_T(Matrix2D, abs)(
				_In_ const Matrix2D & _mat)
			{
				return Matrix2D(
					std::abs(_mat.m00), 
					std::abs(_mat.m01),
					std::abs(_mat.m10), 
					std::abs(_mat.m11));
			}

			// ���� :
			inline CLASS_DECL_FUNC_T(Vector2D, axisX)(
				_In_ const Matrix2D & _mat)
			{
				return Vector2D(
					_mat.m00, 
					_mat.m10);
			}

			// ���� :
			inline CLASS_DECL_FUNC_T(Vector2D, axisY)(
				_In_ const Matrix2D & _mat)
			{
				return Vector2D(
					_mat.m01,
					_mat.m11);
			}

			// ���� :
			inline CLASS_DECL_FUNC_T(Matrix2D &, transpose)(
				_Out_ Matrix2D & _out,
				_In_ const Matrix2D & _in)
			{
				_out = Matrix2D(
					_in.m00,
					_in.m10,
					_in.m01,
					_in.m11);

				return _out;
			}

		}
	}
}