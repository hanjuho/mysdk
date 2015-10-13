#include "common.hlsli"

// ���� : output.pos�� 0,0 �������� Frame�� w, h ������ ũ��, -1 ~ 1 ������ ������ ��ȯ�ؾ� ��.
// ���� : c_wide(0, 0, w, h)
float4 c_wide : register(b0);

// ���� : clip
// ���� : c_clip(x1, y1, x2, y2)
float4 c_clip : register(b0);

/*
���� : ���� ��ǥ�� -1 ~ 1 ������ ��, UI ��ǥ�� ��ȯ�ϴ� ���ؽ� ���̴�.
*/
UI_OUTPUT main(UI_INPUT input)
{
	UI_OUTPUT output;

	// -1 ~ 1 ������ ������ ��ȯ
	output.pos = float4(
		((input.pos.x / c_wide[2]) * 2.0f) - 1.0f,
		1.0f - ((input.pos.y / c_wide[3]) * 2.0f),
		0.0f,
		1.0f);

	//
	output.tex = input.tex;

	return output;
}