#pragma once



#include "common.h"



namespace hsdk
{
	namespace framework
	{

		// ���� : 
		DLL_DECL_CLASS(Framework_Camera)
		{
		public:

			// ������.
			CLASS_DECL_STRUCTOR(Framework_Camera)(void);

			// ���� : 
			CLASS_DECL_FUNC_T(void, multiply)(
				_In_ const float * _mMatrix);

			// ���� : 
			CLASS_DECL_FUNC_T(void, set_Position)(
				_In_ const float * _vPos);

			// ���� : 
			CLASS_DECL_FUNC_T(void, set_Target)(
				_In_ const float * _vPos);

			// ���� : 
			CLASS_DECL_FUNC_T(void, move_XDir)(
				_In_ float _value);

			// ���� : 
			CLASS_DECL_FUNC_T(void, move_YDir)(
				_In_ float _value);

			// ���� : 
			CLASS_DECL_FUNC_T(void, move_ZDir)(
				_In_ float _value);

			// ���� : 
			CLASS_DECL_FUNC_T(void, rotate_XAxis)(
				_In_ float _angle);

			// ���� : 
			CLASS_DECL_FUNC_T(void, rotate_YAxis)(
				_In_ float _angle);

			// ���� : 
			CLASS_DECL_FUNC_T(void, rotate_ZAxis)(
				_In_ float _angle);

			// ���� : 
			CLASS_DECL_FUNC_T(const float *, get_XDir)(
				_X_ void)const;

			// ���� : 
			CLASS_DECL_FUNC_T(const float *, get_YDir)(
				_X_ void)const;

			// ���� : 
			CLASS_DECL_FUNC_T(const float *, get_ZDir)(
				_X_ void)const;

			// ���� : 
			CLASS_DECL_FUNC_T(const float *, get_Position)(
				_X_ void)const;

			// ���� : 
			CLASS_DECL_FUNC_T(void, compute_ViewMatrix)(
				_X_ float * _mView)const;

		private:

			// ���� : 
			D3DXVECTOR3	my_vPos;

			// ���� : 
			D3DXVECTOR3	my_vXDir;

			// ���� : 
			D3DXVECTOR3	my_vYDir;

			// ���� : 
			D3DXVECTOR3	my_vZDir;

		};

	}
}