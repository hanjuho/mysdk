#pragma once



#include "interface/common.h"
#include <algorithm>
#include <math.h>



namespace hsdk
{
	namespace physics2d
	{
		
		/*
		Copyright (c) 2013 Randy Gaul http://RandyGaul.net

		This software is provided 'as-is', without any express or implied
		warranty. In no event will the authors be held liable for any damages
		arising from the use of this software.

		Permission is granted to anyone to use this software for any purpose,
		including commercial applications, and to alter it and redistribute it
		freely, subject to the following restrictions:
		1. The origin of this software must not be misrepresented; you must not
		claim that you wrote the original software. If you use this software
		in _a product, an acknowledgment in the product documentation would be
		appreciated but is not required.
		2. Altered source versions must be plainly marked as such, and must not be
		misrepresented as being the original software.
		3. This notice may not be removed or altered from any source distribution.
		*/

		// ���� : 
		const float PI = 3.141592741f;

		// ���� : 
		const float EPSILON = 0.0001f;

		// ���� : 
		DLL_DECL_STRUCT(Vector2D)
		{

			// ���� : 
			union
			{

				float m[1][1];
				float v[2];

				struct
				{
					float x;
					float y;
				};

			};

			// ������.
			CLASS_DECL_CONSTRUCTOR(Vector2D)(void);

			// ������.
			CLASS_DECL_CONSTRUCTOR(Vector2D)(
				/* [r] */ float _x,
				/* [r] */ float _y);

			// ���� :
			CLASS_DECL_FUNC_T(Vector2D, operator-)(
				/* [x] */ void) const;

			// ���� :
			CLASS_DECL_FUNC_T(Vector2D, operator+)(
				/* [r] */ const Vector2D & _rhs) const;

			// ���� :
			CLASS_DECL_FUNC_T(Vector2D, operator-)(
				/* [r] */ const Vector2D & _rhs) const;

			// ���� :
			CLASS_DECL_FUNC_T(void, operator+=)(
				/* [r] */ const Vector2D & _rhs);

			// ���� :
			CLASS_DECL_FUNC_T(void, operator-=)(
				/* [r] */ const Vector2D & _rhs);

			// ���� :
			CLASS_DECL_FUNC_T(Vector2D, operator+)(
				/* [r] */ float _s) const;

			// ���� :
			CLASS_DECL_FUNC_T(Vector2D, operator-)(
				/* [r] */ float _s) const;

			// ���� :
			CLASS_DECL_FUNC_T(Vector2D, operator*)(
				/* [r] */ float _s) const;

			// ���� :
			CLASS_DECL_FUNC_T(Vector2D, operator/)(
				/* [r] */ float _s) const;

			// ���� :
			CLASS_DECL_FUNC_T(void, operator+=)(
				/* [r] */ float _s);

			// ���� :
			CLASS_DECL_FUNC_T(void, operator-=)(
				/* [r] */ float _s);

			// ���� :
			CLASS_DECL_FUNC_T(void, operator*=)(
				/* [r] */ float _s);

			// ���� :
			CLASS_DECL_FUNC_T(void, operator/=)(
				/* [r] */ float _s);

		};

		namespace vector2d
		{

			// ���� :
			inline DECL_FUNC_T(float, lenSqr)(
				/* [r] */ const Vector2D & _in)
			{
				return _in.x * _in.x + _in.y * _in.y;
			}

			// ���� :
			inline DECL_FUNC_T(float, len)(
				/* [r] */ const Vector2D & _in)
			{
				return std::sqrt(_in.x * _in.x + _in.y * _in.y);
			}

			// ���� :
			inline DECL_FUNC_T(Vector2D &, normalize)(
				/* [w] */ Vector2D & _out,
				/* [r] */ const Vector2D & _in)
			{
				float length = len(_in);
				if (length > EPSILON)
				{
					float invLen = 1.0f / length;
					_out = Vector2D(
						_in.x * invLen,
						_in.y * invLen);
				}

				return _out;
			}

			// ���� :
			inline DECL_FUNC_T(Vector2D &, rotate)(
				/* [w] */ Vector2D & _out,
				/* [r] */ const Vector2D & _in,
				/* [r] */ float _radians)
			{
				float c = std::cos(_radians);
				float s = std::sin(_radians);

				_out = Vector2D(
					_in.x * c - _in.y * s,
					_in.x * s + _in.y * c);

				return _out;
			}

			// ���� :
			inline DECL_FUNC_T(Vector2D, min)(
				/* [r] */ const Vector2D & _a,
				/* [r] */ const Vector2D & _b)
			{
				return Vector2D(
					std::min(_a.x, _b.x),
					std::min(_a.y, _b.y));
			}

			// ���� :
			inline DECL_FUNC_T(Vector2D, max)(
				/* [r] */ const Vector2D & _a,
				/* [r] */ const Vector2D & _b)
			{
				return Vector2D(
					std::max(_a.x, _b.x),
					std::max(_a.y, _b.y));
			}

			// ���� :
			inline DECL_FUNC_T(float, dot)(
				/* [r] */ const Vector2D & _a,
				/* [r] */ const Vector2D & _b)
			{
				return _a.x * _b.x + _a.y * _b.y;
			}

			// ���� :
			inline DECL_FUNC_T(float, distSqr)(
				/* [r] */ const Vector2D & _a,
				/* [r] */ const Vector2D & _b)
			{
				Vector2D c = _a - _b;
				return dot(c, c);
			}

			// ���� :
			inline DECL_FUNC_T(Vector2D, cross)(
				/* [r] */ const Vector2D & v,
				/* [r] */ float _a)
			{
				return Vector2D(
					_a * v.y, 
					-_a * v.x);
			}

			// ���� :
			inline DECL_FUNC_T(Vector2D, cross)(
				/* [r] */ float _a,
				/* [r] */ const Vector2D & _v)
			{
				return Vector2D(
					-_a * _v.y,
					_a * _v.x);
			}

			// ���� :
			inline DECL_FUNC_T(float, cross)(
				/* [r] */ const Vector2D & _a,
				/* [r] */ const Vector2D & _b)
			{
				return _a.x * _b.y - _a.y * _b.x;
			}

			// ���� : Comparison with tolerance of EPSILON
			inline DECL_FUNC_T(bool, equal)(
				/* [r] */ float _a,
				/* [r] */ float _b)
			{
				// <= instead of < for NaN comparison safety
				return std::abs(_a - _b) <= EPSILON;
			}

			// ���� :
			inline DECL_FUNC_T(float, sqr)(
				/* [r] */ float _a)
			{
				return _a * _a;
			}

			// ���� :
			inline DECL_FUNC_T(float, clamp)(
				/* [r] */ float _min,
				/* [r] */ float _max,
				/* [r] */ float _a)
			{
				if (_a < _min) return _min;
				if (_a > _max) return _max;
				return _a;
			}

			// ���� :
			inline DECL_FUNC_T(int, round)(
				/* [r] */ float _a)
			{
				return (int)(_a + 0.5f);
			}

			// ���� :
			inline DECL_FUNC_T(float, random)(
				/* [r] */ float _l,
				/* [r] */ float _h)
			{
				float r = (float)rand();
				r /= RAND_MAX;
				r = (_h - _l) * r + _l;
				return r;
			}

			// ���� :
			inline DECL_FUNC_T(bool, biasGreaterThan)(
				/* [r] */ float _a,
				/* [r] */ float _b)
			{
				const float k_biasRelative = 0.95f;
				const float k_biasAbsolute = 0.01f;
				return _a >= ((_b * k_biasRelative) + (_a * k_biasAbsolute));
			}

		}

	}
}
