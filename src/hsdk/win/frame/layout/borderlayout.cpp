#include "borderlayout.h"
#include <Windows.h>
#include <float.h>



using namespace hsdk::frame::layout;
using namespace hsdk::i::frame;


//--------------------------------------------------------------------------------------
CLASS_IMPL_CONSTRUCTOR(BorderLayout, BorderLayout)(void)
{
	ZeroMemory(my_Frame, sizeof(my_Frame));
	ZeroMemory(my_LinkedForm, sizeof(my_LinkedForm));
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(BorderLayout, void, reset)(
	_X_ void)
{
	ZeroMemory(my_LinkedForm, sizeof(my_LinkedForm));
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(BorderLayout, void, resize)(
	_In_ float _width,
	_In_ float _height)
{
	my_Width = _width;
	my_Height = _height;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(BorderLayout, link_Form)(
	_Out_ float(&_rectangle)[4],
	_In_ LAYOUT_COMPOSITION _composition)
{
	if (_composition == COMPOSITION_CENTER)
	{
		_composition = COMPOSITION_DEFALUT;
	}

	// ���̾ƿ��� �̹� �ִٸ� ���� �ź�
	if (my_LinkedForm[_composition])
	{
		return E_ACCESSDENIED;
	}

	float left = get_Left(_composition);
	float top = get_Top(_composition);
	float right = get_Right(_composition);
	float bottom = get_Bottom(_composition);

	float width = right - left;
	float height = bottom - top;

	switch (_composition)
	{
		// ����
	case COMPOSITION_EAST:

		// ������ �ʺ� �����ϴٸ� (�߾�, ��, ��)�κ��� �ڸ��� ������
		if (width < DBL_EPSILON)
		{
			// �ּ� �ʺ�
			const float my_WAbs = (my_Width * get_WidthRate()) * 0.3f;

			// �߾�
			if (my_LinkedForm[COMPOSITION_DEFALUT])
			{
				// ���ο� ���̾ƿ� �ʺ� = �߾� ���̾ƿ� ���� �ʺ� - (���� ���̾ƿ� �ּ� �ʺ� + ���̾ƿ� ��)
				float new_Right = my_LinkedForm[COMPOSITION_DEFALUT][SPACE_RIGHT] - (my_WAbs + get_VGapAbs());
				if (0 < new_Right)
				{
					my_LinkedForm[COMPOSITION_DEFALUT][SPACE_RIGHT] = new_Right;
					if (my_LinkedForm[COMPOSITION_SOUTH])
					{
						my_LinkedForm[COMPOSITION_SOUTH][SPACE_RIGHT] = new_Right;
					}

					left = right - my_WAbs;
				}
			}
			// ����
			else if (my_LinkedForm[COMPOSITION_SOUTH])
			{
				// ���ο� ���̾ƿ� �ʺ� = ���� ���̾ƿ� ���� �ʺ� - (���� ���̾ƿ� �ּ� �ʺ� + ���̾ƿ� ��)
				float new_Right = my_LinkedForm[COMPOSITION_SOUTH][SPACE_RIGHT] - (my_WAbs + get_VGapAbs());
				if (0 < new_Right)
				{
					my_LinkedForm[COMPOSITION_SOUTH][SPACE_RIGHT] = new_Right;

					left = right - my_WAbs;
				}
			}
			// ����
			else if (my_LinkedForm[COMPOSITION_WEST])
			{
				// ���ο� ���̾ƿ� �ʺ� = ���� ���̾ƿ� ���� �ʺ� - (���� ���̾ƿ� �ּ� �ʺ� + ���̾ƿ� ��)
				float new_Right = my_LinkedForm[COMPOSITION_WEST][SPACE_RIGHT] - (my_WAbs + get_VGapAbs());
				if (0 < new_Right)
				{
					my_LinkedForm[COMPOSITION_WEST][SPACE_RIGHT] = new_Right;

					left = right - my_WAbs;
				}
			}
		}

		// ������ ���̰� �����ϴٸ� ����� ����

		break;

		// ����
	case COMPOSITION_WEST:

		if (width < DBL_EPSILON)
		{
			// �ּ� �ʺ�
			const float my_WAbs = (my_Width * get_WidthRate()) * 0.3f;

			// �߾�
			if (my_LinkedForm[COMPOSITION_DEFALUT])
			{
				float hgap = get_HGapAbs();

				// ���ο� ���̾ƿ� �ʺ� = �߾� ���̾ƿ� ���� �ʺ� - (���� ���̾ƿ� �ּ� �ʺ� + ���̾ƿ� ��)
				float new_Right = my_LinkedForm[COMPOSITION_DEFALUT][SPACE_RIGHT] - (my_WAbs + hgap);
				if (0 < new_Right)
				{
					right = left + my_WAbs;

					// ���ο� ���̾ƿ� ��ǥ X = ���� ���̾ƿ� X2 + ���̾ƿ� ��
					my_LinkedForm[COMPOSITION_DEFALUT][SPACE_LEFT] = right + hgap;
					my_LinkedForm[COMPOSITION_DEFALUT][SPACE_RIGHT] = new_Right;
					if (my_LinkedForm[COMPOSITION_SOUTH])
					{
						my_LinkedForm[COMPOSITION_SOUTH][SPACE_LEFT] = right + hgap;
						my_LinkedForm[COMPOSITION_SOUTH][SPACE_RIGHT] = new_Right;
					}
				}
			}
			// ����
			else if (my_LinkedForm[COMPOSITION_SOUTH])
			{
				float hgap = get_HGapAbs();

				// ���ο� ���̾ƿ� �ʺ� = ���� ���̾ƿ� ���� �ʺ� - (���� ���̾ƿ� �ּ� �ʺ� + ���̾ƿ� ��)
				float new_Right = my_LinkedForm[COMPOSITION_SOUTH][SPACE_RIGHT] - (my_WAbs + hgap);
				if (0 < new_Right)
				{
					right = left + my_WAbs;

					// ���ο� ���̾ƿ� ��ǥ X = ���� ���̾ƿ� X2 + ���̾ƿ� ��
					my_LinkedForm[COMPOSITION_SOUTH][SPACE_LEFT] = right + hgap;
					my_LinkedForm[COMPOSITION_SOUTH][SPACE_RIGHT] = new_Right;
				}
			}
			// ����
			else if (my_LinkedForm[COMPOSITION_EAST])
			{
				float hgap = get_HGapAbs();

				// ���ο� ���̾ƿ� �ʺ� = ���� ���̾ƿ� ���� �ʺ� - (���� ���̾ƿ� �ּ� �ʺ� + ���̾ƿ� ��)
				float new_Right = my_LinkedForm[COMPOSITION_EAST][SPACE_RIGHT] - (my_WAbs + hgap);
				if (0 < new_Right)
				{
					right = left + my_WAbs;

					// ���ο� ���̾ƿ� ��ǥ X = ���� ���̾ƿ� X2 + ���̾ƿ� ��
					my_LinkedForm[COMPOSITION_EAST][SPACE_LEFT] = right + hgap;
					my_LinkedForm[COMPOSITION_EAST][SPACE_RIGHT] = new_Right;
				}
			}
		}

		break;

		// ����
	case COMPOSITION_SOUTH:

		if (width < DBL_EPSILON)
		{
			// �߾�
			if (my_LinkedForm[COMPOSITION_DEFALUT])
			{
				left = my_LinkedForm[COMPOSITION_WEST][SPACE_LEFT];
				right = left + my_LinkedForm[COMPOSITION_WEST][SPACE_RIGHT];
			}
		}

		if (height < DBL_EPSILON)
		{
			// �ּ� ����
			const float my_HAbs = (my_Height * get_HeightRate()) * 0.3f;

			// �߾�
			if (my_LinkedForm[COMPOSITION_DEFALUT])
			{
				// ���ο� ���̾ƿ� ���� = �߾� ���̾ƿ� ���� ���� - (���� ���̾ƿ� �ּ� ���� + ���̾ƿ� ��)
				float new_Bottom = my_LinkedForm[COMPOSITION_DEFALUT][SPACE_BOTTOM] - (my_HAbs + get_VGapAbs());
				if (0 < new_Bottom)
				{
					my_LinkedForm[COMPOSITION_DEFALUT][SPACE_BOTTOM] = new_Bottom;
					top = bottom - my_HAbs;
				}
			}

			// ���� ���̾ƿ��� �� �̻� ���̿� ������ �� ����
		}

		break;

	case COMPOSITION_NORTH:

		if (height < DBL_EPSILON)
		{
			const float my_HAbs = (my_Height * get_HeightRate()) * 0.2f;
			bottom = top + my_HAbs;

			// ���ο� ���̾ƿ� Y2 = ���� ���̾ƿ� Y2 + ���̾ƿ� ��
			float new_Top = bottom + get_VGapAbs();

			// ����
			if (my_LinkedForm[COMPOSITION_EAST])
			{
				my_LinkedForm[COMPOSITION_EAST][SPACE_TOP] = new_Top;
				my_LinkedForm[COMPOSITION_EAST][SPACE_BOTTOM] =
					get_SpaceAbs(SPACE_BOTTOM) - new_Top;
			}

			// ����
			if (my_LinkedForm[COMPOSITION_WEST])
			{
				my_LinkedForm[COMPOSITION_WEST][SPACE_TOP] = new_Top;
				my_LinkedForm[COMPOSITION_WEST][SPACE_BOTTOM] =
					get_SpaceAbs(SPACE_BOTTOM) - new_Top;
			}

			// �߾�
			if (my_LinkedForm[COMPOSITION_DEFALUT])
			{
				my_LinkedForm[COMPOSITION_DEFALUT][SPACE_TOP] = new_Top;
				if (my_LinkedForm[COMPOSITION_SOUTH])
				{
					if (my_LinkedForm[COMPOSITION_SOUTH][SPACE_BOTTOM] < my_HAbs)
					{
						// �𸣰ڴ�
					}
				}
				else
				{
					my_LinkedForm[COMPOSITION_DEFALUT][SPACE_BOTTOM] -= my_HAbs;
				}
			}
		}

		break;

		// �߾�
	case COMPOSITION_DEFALUT:
	case COMPOSITION_CENTER:

		if (width < DBL_EPSILON)
		{
			// ���� ���̾ƿ� ���� �ʺ�
			const float my_WAbs = my_Width * get_WidthRate();
			const float hgap = get_HGapAbs();

			// ����
			if (my_LinkedForm[COMPOSITION_WEST])
			{
				float west_W = my_LinkedForm[COMPOSITION_WEST][SPACE_RIGHT];
				float min_W = my_WAbs * 0.3f;

				// ���� ���̾ƿ� �ʺ� �ּ� �ʺ񺸴� ũ�ٸ�
				if (min_W < west_W)
				{
					my_LinkedForm[COMPOSITION_WEST][SPACE_RIGHT] = min_W;
					left = (my_LinkedForm[COMPOSITION_WEST][SPACE_LEFT] + min_W + hgap);
				}
			}

			// ����
			if (my_LinkedForm[COMPOSITION_EAST])
			{
				float west_W = my_LinkedForm[COMPOSITION_EAST][SPACE_RIGHT];
				float min_W = my_WAbs * 0.3f;

				// ���� ���̾ƿ� �ʺ� �ּ� �ʺ񺸴� ũ�ٸ�
				if (min_W < west_W)
				{
					float newLeft = get_SpaceAbs(SPACE_RIGHT) - min_W;
					my_LinkedForm[COMPOSITION_EAST][SPACE_LEFT] = newLeft;
					my_LinkedForm[COMPOSITION_EAST][SPACE_RIGHT] = min_W;

					right = newLeft - hgap;
				}
			}
		}

		if (height < DBL_EPSILON)
		{
			const float my_HAbs = my_Height * get_HeightRate();

			// ����
			if (my_LinkedForm[COMPOSITION_SOUTH])
			{
				float west_H = my_LinkedForm[COMPOSITION_SOUTH][SPACE_BOTTOM];
				float min_H = my_HAbs * 0.3f;

				// ���� ���̾ƿ� ���̰� �ּ� ���̺��� ũ�ٸ�
				if (min_H < west_H)
				{
					float newTop = min_H + get_SpaceAbs(SPACE_TOP);

					my_LinkedForm[COMPOSITION_SOUTH][SPACE_TOP] = newTop;
					my_LinkedForm[COMPOSITION_SOUTH][SPACE_BOTTOM] = min_H;

					bottom = newTop - get_VGapAbs();
				}
			}
		}

		break;

	default:

		break;
	}

	width = right - left;
	height = bottom - top;

	IF_FALSE(0 < width && 0 < height)
	{
		return E_INVALIDARG;
	}

	_rectangle[SPACE_LEFT] = left;
	_rectangle[SPACE_TOP] = top;
	_rectangle[SPACE_RIGHT] = width;
	_rectangle[SPACE_BOTTOM] = height;

	my_LinkedForm[_composition] = _rectangle;

	return S_OK;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(BorderLayout, unlink_Form)(
	_In_ float(&_rectangle)[4],
	_In_ LAYOUT_COMPOSITION _composition)
{
	if (my_LinkedForm[_composition] == _rectangle)
	{
		my_LinkedForm[_composition] = nullptr;
		return S_OK;
	}

	return E_INVALIDARG;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(BorderLayout, void, set_Space)(
	_In_ LAYOUT_SPACE _space,
	_In_ float _value)
{
	IF_FALSE(_value < 1.0f)
	{
		return;
	}

	switch (_space)
	{
	case SPACE_LEFT:

		my_Frame[SPACE_LEFT] = min(_value, 1.0f - (my_Frame[SPACE_RIGHT] + (my_HGap * 2)));

		return;
	case SPACE_TOP:

		my_Frame[SPACE_TOP] = min(_value, 1.0f - (my_Frame[SPACE_BOTTOM] + (my_VGap * 2)));

		return;
	case SPACE_RIGHT:

		my_Frame[SPACE_RIGHT] = min(_value, 1.0f - (my_Frame[SPACE_LEFT] + (my_HGap * 2)));

		return;
	case SPACE_BOTTOM:

		my_Frame[SPACE_BOTTOM] = min(_value, 1.0f - (my_Frame[SPACE_TOP] + (my_VGap * 2)));

		return;
	default:
		return;
	}
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(BorderLayout, float, get_Space)(
	_In_ LAYOUT_SPACE _space)const
{
	return my_Frame[_space];
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(BorderLayout, void, set_HGap)(
	_In_ float _value)
{
	IF_FALSE(_value < 0.5f)
	{
		return;
	}

	my_HGap = min(_value, (1.0f - (my_Frame[SPACE_LEFT] + my_Frame[SPACE_RIGHT])) * 0.5f);
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(BorderLayout, float, get_HGap)(
	_X_  void)const
{
	return my_HGap;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(BorderLayout, void, set_VGap)(
	_In_ float _value)
{
	IF_FALSE(_value < 0.5f)
	{
		return;
	}

	my_VGap = min(_value, (1.0f - (my_Frame[SPACE_TOP] + my_Frame[SPACE_BOTTOM])) * 0.5f);
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(BorderLayout, float, get_VGap)(
	_X_ void)const
{
	return my_VGap;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(BorderLayout, float, get_WidthRate)(
	_X_ void)const
{
	return 1.0f - (my_Frame[SPACE_LEFT] + my_Frame[SPACE_RIGHT] + (my_HGap * 2.0f));
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(BorderLayout, float, get_HeightRate)(
	_X_ void)const
{
	return 1.0f - (my_Frame[SPACE_TOP] + my_Frame[SPACE_BOTTOM] + (my_VGap * 2.0f));
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(BorderLayout, float, get_SpaceAbs)(
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
CLASS_IMPL_FUNC_T(BorderLayout, float, get_HGapAbs)(
	_In_ void)const
{
	return my_Width * my_HGap;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(BorderLayout, float, get_VGapAbs)(
	_X_ void)const
{
	return my_Height * my_VGap;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(BorderLayout, float, get_Left)(
	_In_ LAYOUT_COMPOSITION _composition)const
{
	float value = get_SpaceAbs(SPACE_LEFT);
	float hgap = get_HGapAbs();

	switch (_composition)
	{
		// ����
	case COMPOSITION_WEST:

		// ����
	case COMPOSITION_NORTH:

		return value;

		// ����
	case COMPOSITION_EAST:

	{
							 // �߾�
							 if (my_LinkedForm[COMPOSITION_DEFALUT])
							 {
								 value = my_LinkedForm[COMPOSITION_DEFALUT][SPACE_LEFT] +
									 my_LinkedForm[COMPOSITION_DEFALUT][SPACE_RIGHT];

								 // ���̾ƿ��� ���̸�ŭ �ٽ� ����
								 value += hgap;
							 }
							 // ����
							 else if (my_LinkedForm[COMPOSITION_WEST])
							 {
								 value += my_LinkedForm[COMPOSITION_WEST][SPACE_RIGHT];

								 // ���̾ƿ��� ���̸�ŭ �ٽ� ����
								 value += hgap;
							 }
	}

		return value;

		// ����
	case COMPOSITION_SOUTH:

	{
							  // ����
							  if (my_LinkedForm[COMPOSITION_WEST])
							  {
								  value += my_LinkedForm[COMPOSITION_WEST][SPACE_RIGHT];

								  // ���̾ƿ��� ���̸�ŭ �ٽ� ����
								  value += hgap;
							  }
	}

		return value;

		// �߾�
	case COMPOSITION_DEFALUT:
	case COMPOSITION_CENTER:

	{
							   // ����
							   if (my_LinkedForm[COMPOSITION_WEST])
							   {
								   value += my_LinkedForm[COMPOSITION_WEST][SPACE_RIGHT];

								   // ���̾ƿ��� ���̸�ŭ �ٽ� ����
								   value += hgap;
							   }
	}

		return value;

	default:

		return 0.0f;

	}
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(BorderLayout, float, get_Top)(
	_In_ LAYOUT_COMPOSITION _composition)const
{
	float value;

	// ����
	if (my_LinkedForm[COMPOSITION_NORTH])
	{
		// ������ �ֻ���, ������
		value = my_LinkedForm[COMPOSITION_NORTH][SPACE_TOP] +
			my_LinkedForm[COMPOSITION_NORTH][SPACE_BOTTOM];

		// ���̾ƿ��� ���̸�ŭ �ٽ� ����
		value += get_VGapAbs();
	}
	else
	{
		value = get_SpaceAbs(SPACE_TOP);

		if (_composition == COMPOSITION_NORTH)
		{
			return value;
		}
	}

	switch (_composition)
	{
		// ����
	case COMPOSITION_EAST:

		// ����
	case COMPOSITION_WEST:

		// �߾�
	case COMPOSITION_DEFALUT:
	case COMPOSITION_CENTER:

		return value;

		// ����
	case COMPOSITION_SOUTH:

	{
							  // �߾�
							  if (my_LinkedForm[COMPOSITION_DEFALUT])
							  {
								  value += my_LinkedForm[COMPOSITION_DEFALUT][SPACE_BOTTOM];

								  // ���̾ƿ��� ���̸�ŭ �ٽ� ����
								  value += get_VGapAbs();
							  }
	}

		return value;

	default:

		return 0.0f;

	}
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(BorderLayout, float, get_Right)(
	_In_ LAYOUT_COMPOSITION _composition)const
{
	float value = get_SpaceAbs(SPACE_RIGHT);
	float hgap = get_HGapAbs();

	switch (_composition)
	{
		// ����
	case COMPOSITION_EAST:

		// ����
	case COMPOSITION_NORTH:

		return value;

		// ����
	case COMPOSITION_WEST:

	{
							 // �߾�
							 if (my_LinkedForm[COMPOSITION_DEFALUT])
							 {
								 value = my_LinkedForm[COMPOSITION_DEFALUT][SPACE_LEFT];

								 // ���̾ƿ��� ���̸�ŭ �ٽ� ����
								 value -= hgap;
							 }
							 // ����
							 else if (my_LinkedForm[COMPOSITION_EAST])
							 {
								 value = my_LinkedForm[COMPOSITION_EAST][SPACE_LEFT];

								 // ���̾ƿ��� ���̸�ŭ �ٽ� ����
								 value -= hgap;
							 }
	}

		return value;

		// ����
	case COMPOSITION_SOUTH:

	{
							  // ����
							  if (my_LinkedForm[COMPOSITION_EAST])
							  {
								  value = my_LinkedForm[COMPOSITION_EAST][SPACE_LEFT];

								  // ���̾ƿ��� ���̸�ŭ �ٽ� ����
								  value -= hgap;
							  }
	}

		return value;

		// �߾�
	case COMPOSITION_DEFALUT:
	case COMPOSITION_CENTER:

	{
							   // ����
							   if (my_LinkedForm[COMPOSITION_EAST])
							   {
								   value = my_LinkedForm[COMPOSITION_EAST][SPACE_LEFT];

								   // ���̾ƿ��� ���̸�ŭ �ٽ� ����
								   value -= hgap;
							   }
	}

		return value;

	default:

		return 0.0f;

	}
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(BorderLayout, float, get_Bottom)(
	_In_ LAYOUT_COMPOSITION _composition)const
{
	float value = get_SpaceAbs(SPACE_BOTTOM);
	float vgap = get_VGapAbs();

	switch (_composition)
	{
		// ����
	case COMPOSITION_EAST:

		// ����
	case COMPOSITION_WEST:

		// ����
	case COMPOSITION_SOUTH:

		return value;

	case COMPOSITION_NORTH:

	{
							  // ����
							  if (my_LinkedForm[COMPOSITION_EAST])
							  {
								  value = my_LinkedForm[COMPOSITION_EAST][SPACE_TOP];

								  // ���̾ƿ��� ���̸�ŭ �ٽ� ����
								  value -= vgap;
							  }
							  // ����
							  else if (my_LinkedForm[COMPOSITION_WEST])
							  {
								  value = my_LinkedForm[COMPOSITION_WEST][SPACE_TOP];

								  // ���̾ƿ��� ���̸�ŭ �ٽ� ����
								  value -= vgap;
							  }
							  // �߾�
							  else if (my_LinkedForm[COMPOSITION_CENTER])
							  {
								  value = my_LinkedForm[COMPOSITION_CENTER][SPACE_TOP];

								  value -= vgap;

							  }
							  // ����
							  else if (my_LinkedForm[COMPOSITION_SOUTH])
							  {
								  value = my_LinkedForm[COMPOSITION_SOUTH][SPACE_TOP];

								  // ���̾ƿ��� ���̸�ŭ �ٽ� ����
								  value -= vgap;
							  }
	}
		return value;

		// �߾�
	case COMPOSITION_DEFALUT:
	case COMPOSITION_CENTER:

	{
							   // ����
							   if (my_LinkedForm[COMPOSITION_SOUTH])
							   {
								   value = my_LinkedForm[COMPOSITION_SOUTH][SPACE_TOP];

								   // ���̾ƿ��� ���̸�ŭ �ٽ� ����
								   value -= vgap;
							   }
	}
		return value;

	default:

		return 0.0f;

	}
}