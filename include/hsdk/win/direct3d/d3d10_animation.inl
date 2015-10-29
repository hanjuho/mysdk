#include "d3d10_animation.h"


//--------------------------------------------------------------------------------------
template<typename INPUT, typename OUTPUT> IMPL_FUNC_T(OUTPUT, hsdk::direct3d::animation::compute_VectorFromKeyFrame)(
	_In_ const std::vector<INPUT> & _keyFrame,
	_In_ aiAnimBehaviour _preFrameHint,
	_In_ aiAnimBehaviour _postFrameHint,
	_In_ double _duration,
	_In_ double _time)
{
	const INPUT * const begin = &_keyFrame[0];
	const INPUT * const end = &_keyFrame[_keyFrame.size() - 1];

	const INPUT * l = begin;
	const INPUT * r = end;

	for (;;)
	{
		const INPUT * c = (r - l) / 2 + l;
		if (c->mTime < _time)
		{
			l = c + 1;
		}
		else
		{
			r = c - 1;
		}

		if (l <= r)
		{
			continue;
		}

		break;
	}

	// out = a + (b - a) * d
	Assimp::Interpolator<OUTPUT> inter;
	OUTPUT out;

	if (r < begin)
	{
		switch (_preFrameHint)
		{
		case aiAnimBehaviour_REPEAT:
			inter(out, end->mValue, begin->mValue, (float)((_duration + _time - end->mTime) / (_duration - end->mTime + begin->mTime)));
			return out;
		default:
			return begin->mValue;
		}
	}

	if (l > end)
	{
		switch (_postFrameHint)
		{
		case aiAnimBehaviour_REPEAT:
			inter(out, end->mValue, begin->mValue, (float)((_time - end->mTime) / (_duration - end->mTime + begin->mTime)));
			return out;
		default:
			return end->mValue;
		}
	}

	inter(out, r->mValue, l->mValue, (float)((_time - r->mTime) / (l->mTime - r->mTime)));

	return out;
}