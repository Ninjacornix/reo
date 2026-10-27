#pragma once
#include "ps2_runtime.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Widescreen camera for File #1 (SLUS-20765 v2.00). The game stores its projection
// aspect as a float at 0x38CA78 (overlay 0 BSS); boot writes 4:3 (0x3FAAAAAB) once and
// nothing changes it later (REO_PEEK through boot, menus and scenario load). Writing a
// wider ratio there widens the 3D view; the presenter then stretches the 640-wide frame
// to the same ratio, so geometry keeps its proportions. Same value as the PCSX2
// widescreen patch (SLUS-20765_0245EF6D.pnach: 0x38CA78 = 0x3FE38E39 for 16:9).
// 2D elements (HUD, menus, movies) are drawn for 4:3 and appear stretched.
namespace reo::widescreen {
inline constexpr uint32_t kAspectAddress = 0x38ca78u;
inline constexpr uint32_t kOriginalAspect = 0x3faaaaabu; // 4:3, as written by the game
inline uint32_t target = 0;
inline void (*originalService)(uint8_t*, R5900Context*, PS2Runtime*) = nullptr;

inline void apply(uint8_t* ram) {
    uint32_t current = 0;
    std::memcpy(&current, ram + kAspectAddress, 4);
    // Replace only the game's own 4:3 value; anything else in this word is left alone.
    if (current == kOriginalAspect)
        std::memcpy(ram + kAspectAddress, &target, 4);
}
inline void service(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    // Original per-frame service, on the guest owner, before the frame is built.
    if (ctx->pc == 0x19f6c0u)
        apply(ram);
    originalService(ram, ctx, runtime);
}
inline void install(PS2Runtime& runtime) {
    const char* enabled = std::getenv("REO_WIDESCREEN");
    if (!enabled || std::strcmp(enabled, "1") != 0)
        return;
    const char* aspect = std::getenv("REO_DISPLAY_ASPECT");
    const float ratio = !aspect                             ? 0.0f
                        : std::strcmp(aspect, "16:9") == 0 ? 16.0f / 9.0f
                        : std::strcmp(aspect, "21:9") == 0 ? 43.0f / 18.0f // present_layout.glsl
                        : std::strcmp(aspect, "32:9") == 0 ? 32.0f / 9.0f
                                                           : 0.0f;
    if (ratio == 0.0f) {
        std::fprintf(stderr, "[WIDESCREEN-1] off: display aspect is 4:3\n");
        return;
    }
    std::memcpy(&target, &ratio, 4);
    originalService = runtime.lookupFunction(0x19f6c0u);
    if (!originalService || originalService == service)
        throw std::runtime_error("Widescreen frame service unavailable");
    runtime.registerFunction(0x19f6c0u, service);
    std::fprintf(stderr, "[WIDESCREEN-1] camera aspect=%s value=%08x\n", aspect, target);
}
} // namespace reo::widescreen
