#include "framework_camera.h"



using namespace hsdk::framework;


//--------------------------------------------------------------------------------------
CLASS_IMPL_CONSTRUCTOR(Framework_Camera, Framework_Camera)(void)
: my_vPos(0.0f, 0.0f, 0.0f),
my_vXDir(1.0f, 0.0f, 0.0f),
my_vYDir(0.0f, 1.0f, 0.0f),
my_vZDir(0.0f, 0.0f, 1.0f), my_Length(1.0f)
{

}

//--------------------------------------------------------------------------------------
CLASS_IMPL_DESTRUCTOR(Framework_Camera, Framework_Camera)(void)
{

}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Framework_Camera, void, multiply)(
	_In_ const float * _mMatrix)
{
	D3DXVec3TransformNormal(&my_vXDir, &my_vXDir, LPD3DXMATRIX(_mMatrix));
	D3DXVec3TransformNormal(&my_vYDir, &my_vYDir, LPD3DXMATRIX(_mMatrix));
	D3DXVec3TransformNormal(&my_vZDir, &my_vZDir, LPD3DXMATRIX(_mMatrix));
	D3DXVec3TransformCoord(&my_vPos, &my_vPos, LPD3DXMATRIX(_mMatrix));
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Framework_Camera, void, move_XDir)(
	_In_ float _value)
{
	my_vPos += my_vXDir * _value;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Framework_Camera, void, move_YDir)(
	_In_ float _value)
{
	my_vPos += my_vYDir * _value;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Framework_Camera, void, move_ZDir)(
	_In_ float _value)
{
	my_vPos += my_vZDir * _value;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Framework_Camera, void, rotate_XAxis)(
	_In_ float _angle,
	_In_ bool _hinge)
{
	if (_hinge)
	{
		my_vPos += (my_vZDir * my_Length);
	}

	D3DXMATRIX T;
	D3DXMatrixRotationAxis(&T, &my_vXDir, _angle);

	D3DXVec3TransformCoord(&my_vYDir, &my_vYDir, &T);
	D3DXVec3TransformCoord(&my_vZDir, &my_vZDir, &T);

	if (_hinge)
	{
		my_vPos -= (my_vZDir * my_Length);
	}
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Framework_Camera, void, rotate_YAxis)(
	_In_ float _angle,
	_In_ bool _hinge)
{
	if (_hinge)
	{
		my_vPos += (my_vZDir * my_Length);
	}

	D3DXMATRIX T;
	D3DXMatrixRotationAxis(&T, &my_vYDir, _angle);

	D3DXVec3TransformCoord(&my_vXDir, &my_vXDir, &T);
	D3DXVec3TransformCoord(&my_vZDir, &my_vZDir, &T);

	if (_hinge)
	{
		my_vPos -= (my_vZDir * my_Length);
	}
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Framework_Camera, void, rotate_ZAxis)(
	_In_ float _angle,
	_In_ bool _hinge)
{
	if (_hinge)
	{
		my_vPos += (my_vZDir * my_Length);
	}

	D3DXMATRIX T;
	D3DXMatrixRotationAxis(&T, &my_vZDir, _angle);

	D3DXVec3TransformCoord(&my_vXDir, &my_vXDir, &T);
	D3DXVec3TransformCoord(&my_vYDir, &my_vYDir, &T);

	if (_hinge)
	{
		my_vPos -= (my_vZDir * my_Length);
	}
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Framework_Camera, void, set_Position)(
	_In_ const float * _vPos)
{
	my_vPos.x = _vPos[0];
	my_vPos.y = _vPos[1];
	my_vPos.z = _vPos[2];
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Framework_Camera, void, set_Target)(
	_In_ const float * _vPos,
	_In_ bool _withPos)
{
	if (_withPos)
	{
		my_vPos = D3DXVECTOR3(_vPos) - (my_vZDir * my_Length);
	}
	else
	{
		my_Length = D3DXVec3Length(&(my_vPos - D3DXVECTOR3(_vPos)));
	}

	// �޾ƿ� ���� �븻�� ���
	D3DXVECTOR3 nor = (D3DXVECTOR3)_vPos - my_vPos;
	D3DXVec3Normalize(&nor, &nor);

	D3DXVec3Cross(&my_vYDir, &nor, &my_vXDir);
	D3DXVec3Normalize(&my_vYDir, &my_vYDir);

	D3DXVec3Cross(&my_vXDir, &nor, &my_vYDir);
	D3DXVec3Normalize(&my_vXDir, &my_vXDir);

	my_vZDir = nor;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Framework_Camera, void, set_Hinge)(
	_In_ float _length)
{
	my_Length = _length;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Framework_Camera, float, get_Hinge)(
	_X_ void)
{
	return my_Length;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Framework_Camera, const float *, get_XDir)(
	_X_ void)const
{
	return my_vXDir;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Framework_Camera, const float *, get_YDir)(
	_X_ void)const
{
	return my_vYDir;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Framework_Camera, const float *, get_ZDir)(
	_X_ void)const
{
	return my_vZDir;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Framework_Camera, const float *, get_Position)(
	_X_ void)const
{
	return my_vPos;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Framework_Camera, void, compute_ViewMatrix)(
	_X_ float * _mView)const
{
	float x = -D3DXVec3Dot(&my_vXDir, &my_vPos);
	float y = -D3DXVec3Dot(&my_vYDir, &my_vPos);
	float z = -D3DXVec3Dot(&my_vZDir, &my_vPos);

	_mView[0] = my_vXDir.x;	_mView[1] = my_vYDir.x;	_mView[2] = my_vZDir.x;		_mView[3] = 0.0f;
	_mView[4] = my_vXDir.y;	_mView[5] = my_vYDir.y;	_mView[6] = my_vZDir.y;		_mView[7] = 0.0f;
	_mView[8] = my_vXDir.z;	_mView[9] = my_vYDir.z;	_mView[10] = my_vZDir.z;	_mView[11] = 0.0f;
	_mView[12] = x;			_mView[13] = y;			_mView[14] = z;				_mView[15] = 1.0f;
}