#version 450
// GS-style MODULATE: texture x vertex colour (vertex colour already scaled so 1.0 = 128),
// alpha test (discard alpha 0), blending set by the pass.
layout(location = 0) in vec4 v_color;
layout(location = 1) in vec2 v_uv;
layout(set = 0, binding = 0) uniform sampler2D tex;
layout(location = 0) out vec4 color;
void main() {
    vec4 t = texture(tex, v_uv);
    vec4 c = vec4(t.rgb * v_color.rgb, t.a * v_color.a);
    if (c.a <= 0.0) discard;
    color = vec4(min(c.rgb, vec3(1.0)), min(c.a, 1.0));
}
