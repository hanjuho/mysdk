#pragma once



#include "vector2d.h"



namespace hsdk
{
	namespace physics2d
	{

		// 설명 : 
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

			// 생성자.
			CLASS_DECL_CONSTRUCTOR(Matrix2D)(void);

			// 생성자.
			CLASS_DECL_CONSTRUCTOR(Matrix2D)(
				/* [r] */ float _radians);

			// 생성자
			CLASS_DECL_CONSTRUCTOR(Matrix2D)(
				/* [r] */ float _a,
				/* [r] */ float _b,
				/* [r] */ float _c,
				/* [r] */ float _d);

			// 설명 : 
			CLASS_DECL_FUNC_T(const Vector2D, operator*)(
				/* [r] */ const Vector2D & _rhs) const;

			// 설명 : 
			CLASS_DECL_FUNC_T(const Matrix2D, operator*)(
				/* [r] */ const Matrix2D & _rhs) const;

			// 설명 : 
			CLASS_DECL_FUNC_T(void, operator=)(
				/* [r] */ const Matrix2D & _rhs);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, operator=)(
				/* [r] */ float _radians);

		};

		namespace matrix2d
		{

			// 설명 : 
			inline CLASS_DECL_FUNC_T(void, rotate)(
				/* [w] */ Matrix2D & _mat,
				/* [r] */ float _radians)
			{
				float c = std::cos(_radians);
				float s = std::sin(_radians);

				_mat.m00 = c; 
				_mat.m01 = -s;
				_mat.m10 = s; 
				_mat.m11 = c;
			}

			// 설명 :
			inline CLASS_DECL_FUNC_T(Matrix2D, abs)(
				/* [r] */ const Matrix2D & _mat)
			{
				return Matrix2D(
					std::abs(_mat.m00), 
					std::abs(_mat.m01),
					std::abs(_mat.m10), 
					std::abs(_mat.m11));
			}

			// 설명 :
			inline CLASS_DECL_FUNC_T(Vector2D, axisX)(
				/* [r] */ const Matrix2D & _mat)
			{
				return Vector2D(
					_mat.m00, 
					_mat.m10);
			}

			// 설명 :
			inline CLASS_DECL_FUNC_T(Vector2D, axisY)(
				/* [r] */ const Matrix2D & _mat)
			{
				return Vector2D(
					_mat.m01,
					_mat.m11);
			}

			// 설명 :
			inline CLASS_DECL_FUNC_T(Matrix2D &, transpose)(
				/* [w] */ Matrix2D & _out,
				/* [r] */ const Matrix2D & _in)
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