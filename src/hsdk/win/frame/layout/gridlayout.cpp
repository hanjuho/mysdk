#include "gridlayout.h"
#include <Windows.h>
#include <float.h>



using namespace hsdk::frame::layout;
using namespace hsdk::i::frame;


//--------------------------------------------------------------------------------------
CLASS_IMPL_CONSTRUCTOR(GridLayout, GridLayout)(
	_In_ int _row,
	_In_ int _col)
	: my_NumHorizon(max(1, _row)), my_NumVertical(max(1, _col))
{
	ZeroMemory(my_Frame, sizeof(my_Frame));
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(GridLayout, void, reset)(
	_X_ void)
{
	my_LinkedForm.clear();
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(GridLayout, void, resize)(
	_In_ float _width,
	_In_ float _height)
{
	my_Width = _width;
	my_Height = _height;

	my_EachWidthAbs = (_width * get_WidthRate()) / (float)(my_NumHorizon);
	my_EachHeightAbs = (_height * get_HeightRate()) / (float)(my_NumVertical);

	set_Space(SPACE_LEFT, my_Frame[SPACE_LEFT]);
	set_Space(SPACE_TOP, my_Frame[SPACE_TOP]);
	set_Space(SPACE_RIGHT, my_Frame[SPACE_RIGHT]);
	set_Space(SPACE_BOTTOM, my_Frame[SPACE_BOTTOM]);
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(GridLayout, link_Form)(
	_Out_ float(&_rectangle)[4],
	_In_ LAYOUT_COMPOSITION _composition)
{
	unsigned int size = my_LinkedForm.size();

	unsigned int column;
	unsigned int row;
	
	column = (size / my_NumHorizon);
	row = size % my_NumHorizon;

	float left = get_SpaceAbs(SPACE_LEFT) + (row * my_EachWidthAbs) + (get_HGapAbs() * row);
	float top = get_SpaceAbs(SPACE_TOP) + (column * my_EachHeightAbs) + (get_VGapAbs() * column);
	float right = left + my_EachWidthAbs;
	float bottom = top + my_EachHeightAbs;

	_rectangle[0] = left;
	_rectangle[1] = top;
	_rectangle[2] = right - left;
	_rectangle[3] = bottom - top;
	my_LinkedForm.push_back(_rectangle);

	return S_OK;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(GridLayout, unlink_Form)(
	_In_ float(&_rectangle)[4],
	_In_ LAYOUT_COMPOSITION _composition)
{
	return S_OK;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(GridLayout, void, set_Space)(
	_In_ LAYOUT_SPACE _space,
	_In_ float _value)
{
	IF_FALSE(_value < 1.0f)
	{
		return;
	}

	float over;
	switch (_space)
	{
	case SPACE_LEFT:

		over = abs(1.0f - (my_Frame[SPACE_RIGHT] + (my_HGap * my_NumHorizon)));
		my_Frame[SPACE_LEFT] = min(_value, over);

		return;
	case SPACE_TOP:

		over = abs(1.0f - (my_Frame[SPACE_BOTTOM] + (my_VGap * my_NumVertical)));
		my_Frame[SPACE_TOP] = min(_value, over);

		return;
	case SPACE_RIGHT:

		over = abs(1.0f - (my_Frame[SPACE_LEFT] + (my_HGap * my_NumHorizon)));
		my_Frame[SPACE_RIGHT] = min(_value, over);

		return;
	case SPACE_BOTTOM:

		over = abs(1.0f - (my_Frame[SPACE_TOP] + (my_VGap * my_NumVertical)));
		my_Frame[SPACE_BOTTOM] = min(_value, over);

		return;
	default:
		return;
	}
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(GridLayout, float, get_Space)(
	_In_ LAYOUT_SPACE _space)const
{
	return my_Frame[_space];
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(GridLayout, void, set_HGap)(
	_In_ float _value)
{
	my_HGap = _value;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(GridLayout, float, get_HGap)(
	_X_  void)const
{
	return my_HGap;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(GridLayout, void, set_VGap)(
	_In_ float _value)
{
	my_VGap = _value;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(GridLayout, float, get_VGap)(
	_X_ void)const
{
	return my_VGap;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(GridLayout, float, get_WidthRate)(
	_X_ void)const
{
	return 1.0f - (my_Frame[SPACE_LEFT] + my_Frame[SPACE_RIGHT] + (my_HGap * (my_NumHorizon - 1)));
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(GridLayout, float, get_HeightRate)(
	_X_ void)const
{
	return 1.0f - (my_Frame[SPACE_TOP] + my_Frame[SPACE_BOTTOM] + (my_VGap * (my_NumVertical - 1)));
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(GridLayout, float, get_SpaceAbs)(
	_In_ LAYOUT_SPACE _space)const
{
	switch (_space)
	{
	case hsdk::i::frame::SPACE_LEFT:

		return my_Width * my_Frame[_space];

	case hsdk::i::frame::SPACE_TOP:

		return my_Height * my_Frame[_space];

	case hsdk::i::frame::SPACE_RIGHT:

		return my_Width * (1.0f - my_Frame[_space]);

	case hsdk::i::frame::SPACE_BOTTOM:

		return my_Height * (1.0f - my_Frame[_space]);

	default:
		return 0.0f;
	}
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(GridLayout, float, get_HGapAbs)(
	_In_ void)const
{
	return my_Width * my_HGap;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(GridLayout, float, get_VGapAbs)(
	_X_ void)const
{
	return my_Height * my_VGap;
}