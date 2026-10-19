#pragma once
#include "parent_natural_runtime.h"
namespace reo_gpu_upstream {
class OriginalStatePacketControl {
  public:
    virtual ~OriginalStatePacketControl() = default;
    virtual bool atOriginalStatePacket197900(uint8_t*, R5900Context&, PS2Runtime&) = 0;
};
// Genuine guarded197900 entry only. The actual source owner retains all
// admission/epoch/allocator/queue checks; this interface grants no ownership.
inline bool dispatchOriginalStatePacket197900(uint8_t* ram, R5900Context& ctx,
                                              PS2Runtime& runtime) {
    reo_parent_natural::AccessScope scope(&runtime, &ctx);
    auto target = reo_parent_natural::findActualOwnerTarget(ram);
    if (!target)
        return false;
    target->requireHealthy();
    auto* state = dynamic_cast<OriginalStatePacketControl*>(target.get());
    return state && state->atOriginalStatePacket197900(ram, ctx, runtime);
}
} // namespace reo_gpu_upstream
