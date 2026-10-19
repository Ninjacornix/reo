sampler2D scene : register(s0);
float gain : register(c0);
float gammaValue : register(c1);

float4 main(float2 uv : TEXCOORD) : COLOR
{
    float4 color = tex2D(scene, uv);
    return float4(pow(saturate(color.rgb * gain), 1.0 / gammaValue), color.a);
}
