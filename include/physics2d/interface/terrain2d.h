#pragma once



#include "common.h"



namespace hsdk
{
	namespace physics2d
	{
		namespace i
		{

			// ���� : 
			DLL_DECL_INTERFACE(i_Terrain2D)
			{

				// �Ҹ���.
				CLASS_DECL_DESTRUCTOR(i_Terrain2D)(void)
				{

				}

				// ���� : _x ��ǥ ������ ����, _dy�� ����.
				INTERFACE_DECL_FUNC_T(float, height)(
					/* [r] */ float _x,
					/* [w] */ float * _dy = nullptr)const = 0;

			};

		}
	}
}