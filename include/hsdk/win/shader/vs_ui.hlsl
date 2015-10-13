#include "common.hlsli"

// 설명 : output.pos는 0,0 에서부터 Frame의 w, h 까지의 크기, -1 ~ 1 사이의 값으로 변환해야 함.
// 참고 : c_wide(0, 0, w, h)
float4 c_wide : register(b0);

// 설명 : clip
// 참고 : c_clip(x1, y1, x2, y2)
float4 c_clip : register(b0);

/*
설명 : 절대 좌표를 -1 ~ 1 사이의 값, UI 좌표로 변환하는 버텍스 쉐이더.
*/
UI_OUTPUT main(UI_INPUT input)
{
	UI_OUTPUT output;

	// -1 ~ 1 사이의 값으로 변환
	output.pos = float4(
		((input.pos.x / c_wide[2]) * 2.0f) - 1.0f,
		1.0f - ((input.pos.y / c_wide[3]) * 2.0f),
		0.0f,
		1.0f);

	//
	output.tex = input.tex;

	return output;
}