#include "original_perspective_control.hpp"
void sub_0018F710_0x18f710(uint8_t*, R5900Context*, PS2Runtime*);
void sub_001921B0_0x1921b0(uint8_t*, R5900Context*, PS2Runtime*);
void sub_0018F570_0x18f570(uint8_t*, R5900Context*, PS2Runtime*);
void sub_0018FDF0_0x18fdf0(uint8_t*, R5900Context*, PS2Runtime*);
static void scope(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    if (!ram || !ctx || !runtime)
        throw std::invalid_argument("Original perspective dispatcher lost actual guest scope");
}
void ReoOriginal18F710Entry(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    scope(ram, ctx, runtime);
    if (reo_gpu_upstream::dispatchOriginalPerspective(ram, *ctx, *runtime))
        return;
    sub_0018F710_0x18f710(ram, ctx, runtime);
}
void ReoOriginal1921B0Entry(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    scope(ram, ctx, runtime);
    if (reo_gpu_upstream::dispatchOriginalPerspective(ram, *ctx, *runtime))
        return;
    sub_001921B0_0x1921b0(ram, ctx, runtime);
}
void ReoOriginal18F570Entry(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    scope(ram, ctx, runtime);
    if (reo_gpu_upstream::dispatchOriginalPerspective(ram, *ctx, *runtime))
        return;
    sub_0018F570_0x18f570(ram, ctx, runtime);
}
void ReoOriginal18FDF0Entry(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    scope(ram, ctx, runtime);
    if (reo_gpu_upstream::dispatchOriginalPerspective(ram, *ctx, *runtime))
        return;
    sub_0018FDF0_0x18fdf0(ram, ctx, runtime);
}
bool ReoInstallOriginalPerspectiveEntries(PS2Runtime& runtime, bool explicitlyRequested = false) {
    if (!explicitlyRequested)
        return false;
    // This replaces only the exact seven selected generated entries. The
    // trusted NativeTarget's hard-false source/continuation gate remains the
    // independent prerequisite for numerical GPU selection.
    struct Entry {
        uint32_t pc;
        PS2Runtime::RecompiledFunction original, replacement;
    };
    const Entry entries[]{{0x18f710, sub_0018F710_0x18f710, ReoOriginal18F710Entry},
                          {0x18f754, sub_0018F710_0x18f710, ReoOriginal18F710Entry},
                          {0x18f75c, sub_0018F710_0x18f710, ReoOriginal18F710Entry},
                          {0x1921b0, sub_001921B0_0x1921b0, ReoOriginal1921B0Entry},
                          {0x1921c8, sub_001921B0_0x1921b0, ReoOriginal1921B0Entry},
                          {0x18f570, sub_0018F570_0x18f570, ReoOriginal18F570Entry},
                          {0x18fdf0, sub_0018FDF0_0x18fdf0, ReoOriginal18FDF0Entry}};
    for (const auto& e : entries)
        if (!runtime.hasFunction(e.pc) || runtime.lookupFunction(e.pc) != e.original)
            throw std::invalid_argument("Perspective installer lost exact generated entry mapping");
    for (const auto& e : entries)
        runtime.registerFunction(e.pc, e.replacement);
    return true;
}
