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

		// 설명 : 
		const float PI = 3.141592741f;

		// 설명 : 
		const float EPSILON = 0.0001f;

		// 설명 : 
		DLL_DECL_STRUCT(Vector2D)
		{

			// 설명 : 
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

			// 생성자.
			CLASS_DECL_CONSTRUCTOR(Vector2D)(void);

			// 생성자.
			CLASS_DECL_CONSTRUCTOR(Vector2D)(
				_In_ float _x,
				_In_ float _y);

			// 설명 :
			CLASS_DECL_FUNC_T(Vector2D, operator-)(
				_X_ void) const;

			// 설명 :
			CLASS_DECL_FUNC_T(Vector2D, operator+)(
				_In_ const Vector2D & _rhs) const;

			// 설명 :
			CLASS_DECL_FUNC_T(Vector2D, operator-)(
				_In_ const Vector2D & _rhs) const;

			// 설명 :
			CLASS_DECL_FUNC_T(void, operator+=)(
				_In_ const Vector2D & _rhs);

			// 설명 :
			CLASS_DECL_FUNC_T(void, operator-=)(
				_In_ const Vector2D & _rhs);

			// 설명 :
			CLASS_DECL_FUNC_T(Vector2D, operator+)(
				_In_ float _s) const;

			// 설명 :
			CLASS_DECL_FUNC_T(Vector2D, operator-)(
				_In_ float _s) const;

			// 설명 :
			CLASS_DECL_FUNC_T(Vector2D, operator*)(
				_In_ float _s) const;

			// 설명 :
			CLASS_DECL_FUNC_T(Vector2D, operator/)(
				_In_ float _s) const;

			// 설명 :
			CLASS_DECL_FUNC_T(void, operator+=)(
				_In_ float _s);

			// 설명 :
			CLASS_DECL_FUNC_T(void, operator-=)(
				_In_ float _s);

			// 설명 :
			CLASS_DECL_FUNC_T(void, operator*=)(
				_In_ float _s);

			// 설명 :
			CLASS_DECL_FUNC_T(void, operator/=)(
				_In_ float _s);

		};

		namespace vector2d
		{

			// 설명 :
			inline DECL_FUNC_T(float, lenSqr)(
				_In_ const Vector2D & _in)
			{
				return _in.x * _in.x + _in.y * _in.y;
			}

			// 설명 :
			inline DECL_FUNC_T(float, len)(
				_In_ const Vector2D & _in)
			{
				return std::sqrt(_in.x * _in.x + _in.y * _in.y);
			}

			// 설명 :
			inline DECL_FUNC_T(Vector2D &, normalize)(
				_Out_ Vector2D & _out,
				_In_ const Vector2D & _in)
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

			// 설명 :
			inline DECL_FUNC_T(Vector2D &, rotate)(
				_Out_ Vector2D & _out,
				_In_ const Vector2D & _in,
				_In_ float _radians)
			{
				float c = std::cos(_radians);
				float s = std::sin(_radians);

				_out = Vector2D(
					_in.x * c - _in.y * s,
					_in.x * s + _in.y * c);

				return _out;
			}

			// 설명 :
			inline DECL_FUNC_T(Vector2D, min)(
				_In_ const Vector2D & _a,
				_In_ const Vector2D & _b)
			{
				return Vector2D(
					std::min(_a.x, _b.x),
					std::min(_a.y, _b.y));
			}

			// 설명 :
			inline DECL_FUNC_T(Vector2D, max)(
				_In_ const Vector2D & _a,
				_In_ const Vector2D & _b)
			{
				return Vector2D(
					std::max(_a.x, _b.x),
					std::max(_a.y, _b.y));
			}

			// 설명 :
			inline DECL_FUNC_T(float, dot)(
				_In_ const Vector2D & _a,
				_In_ const Vector2D & _b)
			{
				return _a.x * _b.x + _a.y * _b.y;
			}

			// 설명 :
			inline DECL_FUNC_T(float, distSqr)(
				_In_ const Vector2D & _a,
				_In_ const Vector2D & _b)
			{
				Vector2D c = _a - _b;
				return dot(c, c);
			}

			// 설명 :
			inline DECL_FUNC_T(Vector2D, cross)(
				_In_ const Vector2D & v,
				_In_ float _a)
			{
				return Vector2D(
					_a * v.y, 
					-_a * v.x);
			}

			// 설명 :
			inline DECL_FUNC_T(Vector2D, cross)(
				_In_ float _a,
				_In_ const Vector2D & _v)
			{
				return Vector2D(
					-_a * _v.y,
					_a * _v.x);
			}

			// 설명 :
			inline DECL_FUNC_T(float, cross)(
				_In_ const Vector2D & _a,
				_In_ const Vector2D & _b)
			{
				return _a.x * _b.y - _a.y * _b.x;
			}

			// 설명 : Comparison with tolerance of EPSILON
			inline DECL_FUNC_T(bool, equal)(
				_In_ float _a,
				_In_ float _b)
			{
				// <= instead of < for NaN comparison safety
				return std::abs(_a - _b) <= EPSILON;
			}

			// 설명 :
			inline DECL_FUNC_T(float, sqr)(
				_In_ float _a)
			{
				return _a * _a;
			}

			// 설명 :
			inline DECL_FUNC_T(float, clamp)(
				_In_ float _min,
				_In_ float _max,
				_In_ float _a)
			{
				if (_a < _min) return _min;
				if (_a > _max) return _max;
				return _a;
			}

			// 설명 :
			inline DECL_FUNC_T(int, round)(
				_In_ float _a)
			{
				return (int)(_a + 0.5f);
			}

			// 설명 :
			inline DECL_FUNC_T(float, random)(
				_In_ float _l,
				_In_ float _h)
			{
				float r = (float)rand();
				r /= RAND_MAX;
				r = (_h - _l) * r + _l;
				return r;
			}

			// 설명 :
			inline DECL_FUNC_T(bool, biasGreaterThan)(
				_In_ float _a,
				_In_ float _b)
			{
				const float k_biasRelative = 0.95f;
				const float k_biasAbsolute = 0.01f;
				return _a >= ((_b * k_biasRelative) + (_a * k_biasAbsolute));
			}

		}

	}
}
