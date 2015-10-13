/*

*/
struct UI_INPUT
{
	float4 pos	: POSITION;
	float2 tex	: TEXCOORD0;
};

/*

*/
struct UI_OUTPUT
{
	float4 pos	: SV_POSITION;
	float2 tex	: TEXCOORD0;
};