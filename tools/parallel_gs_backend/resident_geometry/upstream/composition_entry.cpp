#include "original_composition_control.hpp"
void sub_0018F6A0_0x18f6a0(uint8_t*, R5900Context*, PS2Runtime*);
void ReoOriginal18F6A0Entry(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    if (!ram || !ctx || !runtime)
        throw std::invalid_argument("Original composition dispatcher lacks actual guest scope");
    if (reo_gpu_upstream::dispatchOriginalComposition(ram, *ctx, *runtime))
        return;
    sub_0018F6A0_0x18f6a0(ram, ctx, runtime);
}
bool ReoInstallOriginalCompositionEntry(PS2Runtime& runtime, bool explicitlyRequested = false) {
    if (!explicitlyRequested)
        return false;
    // This focused source interceptor changes only the genuine fresh root.
    // Interior entries need a real continuation issuer and remain unselected.
    if (!runtime.hasFunction(0x18f6a0) || runtime.lookupFunction(0x18f6a0) != sub_0018F6A0_0x18f6a0)
        throw std::invalid_argument("Composition installer lost exact generated mapping");
    runtime.registerFunction(0x18f6a0, ReoOriginal18F6A0Entry);
    return true;
}
