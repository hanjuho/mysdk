#include "common.hlsli"

// 설명 : 텍스처, ID3D11ShaderResourceView와 대응된다.
Texture2D c_texture : register (t0);

// 설명 : 하드웨어가 texture를 읽어들이는 방식을 결정한다.[확실치 않음]
SamplerState c_sampler : register (s0);

/*
설명 : UV 좌표를 통해 texture로부터 최종 pixel color를 결정.
*/
float4 main(UI_OUTPUT input) : SV_TARGET
{
	return c_texture.Sample(c_sampler, input.tex);
}