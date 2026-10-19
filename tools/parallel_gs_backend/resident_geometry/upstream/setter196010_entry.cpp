#include "tools/parallel_gs_backend/resident_geometry/upstream/original_setter_control.hpp"
void sub_00196010_0x196010(uint8_t*, R5900Context*, PS2Runtime*);
// Future native dispatcher seam, source-only/default-off. The GPU component
// executable does not link this original fallback; its numerical comparison
// original is a separate root-run executable.
void ReoOriginal196010Entry(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    if (!ram || !ctx || !runtime)
        throw std::invalid_argument("Original196010 dispatcher lacks actual guest scope");
    if (reo_gpu_upstream::dispatchOriginal196010(ram, *ctx, *runtime))
        return;
    sub_00196010_0x196010(ram, ctx, runtime);
}
bool ReoInstallOriginal196010Entry(PS2Runtime& runtime, bool explicitlyRequested = false) {
    if (!explicitlyRequested)
        return false;
    if (!runtime.hasFunction(0x196010u) ||
        runtime.lookupFunction(0x196010u) != sub_00196010_0x196010)
        throw std::invalid_argument("Original196010 installer lost its exact generated entry");
    runtime.registerFunction(0x196010u, ReoOriginal196010Entry);
    return true;
}
