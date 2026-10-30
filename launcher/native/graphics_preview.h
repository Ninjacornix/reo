#pragma once
#include <stdint.h>
#include <windows.h>

#ifdef REO_PREVIEW_EXPORTS
#define REO_PREVIEW_API __declspec(dllexport)
#else
#define REO_PREVIEW_API __declspec(dllimport)
#endif

// All fields are four bytes, sequential, with no embedded pointers. Angles are
// degrees. Position/normal arrays are float3, UV arrays float2, indices uint32.
typedef struct ReoPreviewOptions {
    int32_t internal_resolution, texture_linear, anisotropy, antialiasing;
    int32_t aspect, widescreen, screen_fit, output_linear;
    int32_t brightness;
    float gamma;
    int32_t window_width, window_height, cover;
    float yaw, pitch, zoom;
    float opacity, background_r, background_g, background_b;
} ReoPreviewOptions;

typedef struct ReoPreviewStats {
    uint32_t render_width, render_height, output_width, output_height;
    uint64_t frames_presented;
    double gpu_milliseconds; // -1 until an asynchronous timestamp sample is ready.
    uint32_t feature_level, hardware;
} ReoPreviewStats;

#ifdef __cplusplus
extern "C" {
#endif
REO_PREVIEW_API void* reo_preview_create(HWND window);
REO_PREVIEW_API void reo_preview_destroy(void* handle);
REO_PREVIEW_API int reo_preview_resize(void* handle, int width, int height);
REO_PREVIEW_API void reo_preview_clear_scene(void* handle);
REO_PREVIEW_API int reo_preview_create_texture(void* handle, int width, int height, const uint8_t* rgba);
REO_PREVIEW_API int reo_preview_create_mesh(void* handle, const float* positions, const float* normals,
    const float* uv, int vertex_count, const uint32_t* indices, int index_count, int texture_id, int character);
REO_PREVIEW_API int reo_preview_update_mesh(void* handle, int mesh_id, const float* positions, const float* normals);
// Poll once before preparing a production frame: 1 = ready, 0 = pending/occluded,
// -1 = error. This never waits or flushes the GPU. Diagnostics may bypass it.
REO_PREVIEW_API int reo_preview_frame_ready(void* handle);
// 1 = presented, 2 = queue busy/occluded (not an error), 0 = error.
REO_PREVIEW_API int reo_preview_render(void* handle, const ReoPreviewOptions* options);
// Diagnostic only. Production presents GPU surfaces directly, with no readback.
REO_PREVIEW_API int reo_preview_readback(void* handle, uint8_t* bgra, int byte_count);
REO_PREVIEW_API int reo_preview_get_stats(void* handle, ReoPreviewStats* stats);
REO_PREVIEW_API const char* reo_preview_device_name(void* handle);
REO_PREVIEW_API const char* reo_preview_last_error(void);
#ifdef __cplusplus
}
#endif
