#pragma once
#include "ps2_runtime.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Widescreen camera. The game keeps its projection aspect as a 4:3 float (0x3FAAAAAB)
// in overlay 0 data, read by three lwc1 f15 in the projection code:
//   File #1 (SLUS-20765): 0x38CA78, read at 0x3757C8/0x3759A0/0x375A04
//   File #2 (SLUS-20984): 0x3A9448, read at 0x391F38/0x391FF0/0x392054 (same three
//   functions by the address map; same constant in ovl0.elf)
// REO_PEEK (File #1): 0 until overlay 0 loads, then 4:3 for the whole session. Writing a
// wider ratio there widens the 3D view; the presenter then stretches the 640-wide frame
// to the same ratio, so geometry keeps its proportions. File #1 matches the PCSX2
// widescreen patch (SLUS-20765_0245EF6D.pnach: 0x38CA78 = 0x3FE38E39 for 16:9).
// 2D elements (HUD, menus, text) are drawn for 4:3 and appear stretched; the presenter
// shows movies at 4:3 (movie_frame_signal.h).
namespace reo::widescreen {
struct Addresses {
    uint32_t aspect;       // overlay 0 projection aspect float
    uint32_t frameService; // original per-frame service
};
inline constexpr Addresses File1{0x38ca78u, 0x19f6c0u};
inline constexpr Addresses File2{0x3a9448u, 0x1edcb0u};
inline constexpr uint32_t kOriginalAspect = 0x3faaaaabu; // 4:3, as the game stores it
inline Addresses game = File1;
inline uint32_t target = 0;
inline void (*originalService)(uint8_t*, R5900Context*, PS2Runtime*) = nullptr;

inline void apply(uint8_t* ram) {
    uint32_t current = 0;
    std::memcpy(&current, ram + game.aspect, 4);
    // Replace only the game's own 4:3 value; anything else in this word is left alone.
    if (current == kOriginalAspect)
        std::memcpy(ram + game.aspect, &target, 4);
}
inline void service(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    // Original per-frame service, on the guest owner, before the frame is built.
    if (ctx->pc == game.frameService)
        apply(ram);
    originalService(ram, ctx, runtime);
}
inline void install(PS2Runtime& runtime, Addresses addresses = File1) {
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
    game = addresses;
    originalService = runtime.lookupFunction(game.frameService);
    if (!originalService || originalService == service)
        throw std::runtime_error("Widescreen frame service unavailable");
    runtime.registerFunction(game.frameService, service);
    std::fprintf(stderr, "[WIDESCREEN-1] camera aspect=%s value=%08x address=%08x\n", aspect, target, game.aspect);
}
} // namespace reo::widescreen
