#version 450
// Native renderer: world-space vertex -> the game's pixel projection (512x448 frame).
// view_projection is the game's row-vector view x pixel projection uploaded row-major, so in GLSL
// p = M * v; p.xy are pixels x w, p.w the view depth. Depth is linear in w.
layout(location = 0) in vec3 position;
layout(location = 1) in vec4 color;
layout(location = 2) in vec2 uv;
layout(push_constant) uniform Push { mat4 view_projection; vec4 screen; } push;
layout(location = 0) out vec4 v_color;
layout(location = 1) out vec2 v_uv;
void main() {
    vec4 p = push.view_projection * vec4(position, 1.0);
    float w = p.w;
    gl_Position = vec4(p.x * push.screen.x - w, p.y * push.screen.y - w, w * w * push.screen.z, w);
    v_color = color;
    v_uv = uv;
}
