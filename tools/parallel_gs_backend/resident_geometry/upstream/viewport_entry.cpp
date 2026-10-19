#include "original_viewport_control.hpp"
void sub_0018F970_0x18f970(uint8_t*, R5900Context*, PS2Runtime*);
void sub_0018FCE0_0x18fce0(uint8_t*, R5900Context*, PS2Runtime*);
void sub_0018F880_0x18f880(uint8_t*, R5900Context*, PS2Runtime*);
void sub_0018F7E0_0x18f7e0(uint8_t*, R5900Context*, PS2Runtime*);
void sub_00197490_0x197490(uint8_t*, R5900Context*, PS2Runtime*);
using ViewportOriginal = void (*)(uint8_t*, R5900Context*, PS2Runtime*);
static void originalViewportEntry(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime,
                                  ViewportOriginal original) {
    if (!ram || !ctx || !runtime)
        throw std::invalid_argument("Viewport dispatcher lacks genuine guest scope");
    if (reo_gpu_upstream::dispatchOriginalViewport(ram, *ctx, *runtime))
        return;
    original(ram, ctx, runtime);
}
void ReoOriginal18F970Entry(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    originalViewportEntry(ram, ctx, runtime, sub_0018F970_0x18f970);
}
void ReoOriginal18FCE0Entry(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    originalViewportEntry(ram, ctx, runtime, sub_0018FCE0_0x18fce0);
}
void ReoOriginal18F880Entry(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    originalViewportEntry(ram, ctx, runtime, sub_0018F880_0x18f880);
}
void ReoOriginal18F7E0Entry(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    originalViewportEntry(ram, ctx, runtime, sub_0018F7E0_0x18f7e0);
}
void ReoOriginal197490Entry(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    originalViewportEntry(ram, ctx, runtime, sub_00197490_0x197490);
}
bool ReoInstallOriginalViewportEntries(PS2Runtime& runtime, bool explicitlyRequested = false) {
    if (!explicitlyRequested)
        return false;
    struct Entry {
        uint32_t pc;
        ViewportOriginal original, wrapper;
    };
    const Entry entries[] = {{0x18f970u, sub_0018F970_0x18f970, ReoOriginal18F970Entry},
                             {0x18fce0u, sub_0018FCE0_0x18fce0, ReoOriginal18FCE0Entry},
                             {0x18f880u, sub_0018F880_0x18f880, ReoOriginal18F880Entry},
                             {0x18f7e0u, sub_0018F7E0_0x18f7e0, ReoOriginal18F7E0Entry},
                             {0x197490u, sub_00197490_0x197490, ReoOriginal197490Entry}};
    for (const auto& e : entries)
        if (!runtime.hasFunction(e.pc) || runtime.lookupFunction(e.pc) != e.original)
            throw std::invalid_argument("Viewport installer lost original generated entry");
    for (const auto& e : entries)
        runtime.registerFunction(e.pc, e.wrapper);
    return true;
}
