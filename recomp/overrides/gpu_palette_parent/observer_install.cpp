#include "parent_observer.hpp"
#include "ps2_recompiled_functions.h"
void reo_palette_parent_observed(uint8_t*, R5900Context*, PS2Runtime*);
bool ReoInstallPaletteParentFrontierObserver(PS2Runtime& runtime) {
    const char* path = std::getenv("REO_GPU_PALETTE_PARENT_DIR");
    if (!path || !*path)
        return false;
    // Do not replace another observer/producer or accidentally bless an override.
    const reo_palette_parent::Fn expected = sub_0019BBD0_0x19bbd0;
    for (auto pc : reo_palette_parent::ParentPCs)
        if (runtime.lookupFunction(pc) != expected)
            return false;
    const std::array<std::pair<uint32_t, reo_palette_parent::Fn>, 5> callees{
        {{0x18ddd0, sub_0018DDD0_0x18ddd0},
         {0x1994e0, sub_001994E0_0x1994e0},
         {0x199cd0, sub_00199CD0_0x199cd0},
         {0x199870, sub_00199870_0x199870},
         {0x199a90, sub_00199A90_0x199a90}}};
    for (const auto& [pc, fn] : callees)
        if (runtime.lookupFunction(pc) != fn)
            return false;
    if (runtime.lookupFunction(0x18de1c) != sub_0018DDD0_0x18ddd0)
        return false;
    if (!reo_palette_parent::open(path))
        return false;
    for (auto pc : reo_palette_parent::ParentPCs)
        runtime.registerFunction(pc, reo_palette_parent_observed);
    return true;
}
