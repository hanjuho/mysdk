#pragma once



#include "common.h"



namespace hsdk
{
	namespace framework
	{

		// 설명 : 
		DECL_CLASS(Framework_Camera)
		{
		public:

			// 생성자.
			CLASS_DECL_STRUCTOR(Framework_Camera)(void);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, multiply)(
				_In_ const float * _mMatrix);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, move_XDir)(
				_In_ float _value);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, move_YDir)(
				_In_ float _value);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, move_ZDir)(
				_In_ float _value);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, rotate_XAxis)(
				_In_ float _angle,
				_In_ bool _hinge = false);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, rotate_YAxis)(
				_In_ float _angle,
				_In_ bool _hinge = false);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, rotate_ZAxis)(
				_In_ float _angle,
				_In_ bool _hinge = false);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, set_Position)(
				_In_ const float * _vPos);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, set_Target)(
				_In_ const float * _vPos,
				_In_ bool _withPos = false);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, set_Hinge)(
				_In_ float _length);

			// 설명 : 
			CLASS_DECL_FUNC_T(float, get_Hinge)(
				_X_ void);

			// 설명 : 
			CLASS_DECL_FUNC_T(const float *, get_XDir)(
				_X_ void)const;

			// 설명 : 
			CLASS_DECL_FUNC_T(const float *, get_YDir)(
				_X_ void)const;

			// 설명 : 
			CLASS_DECL_FUNC_T(const float *, get_ZDir)(
				_X_ void)const;

			// 설명 : 
			CLASS_DECL_FUNC_T(const float *, get_Position)(
				_X_ void)const;

			// 설명 : 
			CLASS_DECL_FUNC_T(void, compute_ViewMatrix)(
				_X_ float * _mView)const;

		private:

			// 설명 : 
			float my_Length;

			// 설명 : 
			D3DXVECTOR3	my_vPos;

			// 설명 : 
			D3DXVECTOR3	my_vXDir;

			// 설명 : 
			D3DXVECTOR3	my_vYDir;

			// 설명 : 
			D3DXVECTOR3	my_vZDir;

		};

	}
}