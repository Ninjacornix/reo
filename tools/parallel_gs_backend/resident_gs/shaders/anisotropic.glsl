// SPDX-License-Identifier: LGPL-3.0-or-later
layout(set=0,binding=23) uniform sampler aniso_wrap;

vec4 sample_anisotropic(uint primitive_index, uint tex, uint filtering,
                        vec2 uv, vec3 stq, bool perspective,
                        TransformedAttributes attrs)
{
    uint level = bitfieldExtract(tex, 27, 3);
    uint index = bitfieldExtract(tex, TEX_TEXTURE_INDEX_OFFSET, TEX_TEXTURE_INDEX_BITS);
    if (level == 0u || level > 4u || !perspective ||
        (index & (1u << (TEX_TEXTURE_INDEX_BITS - 1))) != 0u)
        return sample_texture(tex, filtering, uv, stq.z, perspective);
    TexInfo info = texture_info.data[index];
    bool clamp_s = (tex & TEX_SAMPLER_CLAMP_S_BIT) != 0u;
    bool clamp_t = (tex & TEX_SAMPLER_CLAMP_T_BIT) != 0u;
    // Preserve GS region addressing and per-sample render-target reconstruction.
    if (info.arrayed != 0 || any(notEqual(info.bias,vec2(0.0))) ||
        (clamp_s && (info.region.x != 0.0 || info.region.z != 1.0/info.sizes.z-1.0)) ||
        (clamp_t && (info.region.y != 0.0 || info.region.w != 1.0/info.sizes.w-1.0)) ||
        abs(stq.z) < 1e-12)
        return sample_texture(tex, filtering, uv, stq.z, perspective);

    PrimitiveSetup prim = primitive_setup.data[primitive_index];
    float step_size = float(PGS_RASTER_SUBPIXELS) / float(SAMPLING_RATE_DIM);
    vec3 dx = (attrs.stqf1.xyz * float(prim.b.x) + attrs.stqf2.xyz * float(prim.c.x)) * prim.inv_area * step_size;
    vec3 dy = (attrs.stqf1.xyz * float(prim.b.y) + attrs.stqf2.xyz * float(prim.c.y)) * prim.inv_area * step_size;
    vec2 du = (dx.xy - uv * dx.z) / stq.z;
    vec2 dv = (dy.xy - uv * dy.z) / stq.z;
    vec2 texel_du = du * info.sizes.xy;
    vec2 texel_dv = dv * info.sizes.xy;
    if (any(isnan(du)) || any(isinf(du)) || any(isnan(dv)) || any(isinf(dv)) ||
        max(dot(texel_du,texel_du),dot(texel_dv,texel_dv)) <= 1.0)
        return sample_texture(tex, filtering, uv, stq.z, perspective);
    vec2 scale = info.sizes.xy * info.sizes.zw;
    vec2 coord = uv * scale;
    // Near clamped edges retain the original GS sampler. Elsewhere a wrapping
    // sampler has the same footprint, without four extra sampler descriptors.
    vec2 extent = 0.5 * (abs(texel_du) + abs(texel_dv)) + 1.0;
    vec2 center = uv * info.sizes.xy;
    if ((clamp_s && (center.x < info.region.x + extent.x || center.x > info.region.z - extent.x)) ||
        (clamp_t && (center.y < info.region.y + extent.y || center.y > info.region.w - extent.y)))
        return sample_texture(tex,filtering,uv,stq.z,perspective);
    vec4 color = textureGrad(sampler2D(bindless_textures[index],aniso_wrap),coord,du*scale,dv*scale);
    return roundEven(color * 255.0);
}
