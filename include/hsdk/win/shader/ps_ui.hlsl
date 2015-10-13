#include "common.hlsli"

// ���� : �ؽ�ó, ID3D11ShaderResourceView�� �����ȴ�.
Texture2D c_texture : register (t0);

// ���� : �ϵ��� texture�� �о���̴� ����� �����Ѵ�.[Ȯ��ġ ����]
SamplerState c_sampler : register (s0);

/*
���� : UV ��ǥ�� ���� texture�κ��� ���� pixel color�� ����.
*/
float4 main(UI_OUTPUT input) : SV_TARGET
{
	return c_texture.Sample(c_sampler, input.tex);
}