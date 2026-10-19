#pragma once
#include "parent_natural_runtime.h"
namespace reo_gpu_upstream {
class OriginalViewportControl {
  public:
    virtual ~OriginalViewportControl() = default;
    virtual bool atOriginalViewport(uint8_t*, R5900Context&, PS2Runtime&) = 0;
};
inline bool dispatchOriginalViewport(uint8_t* ram, R5900Context& ctx, PS2Runtime& runtime) {
    reo_parent_natural::AccessScope scope(&runtime, &ctx);
    auto target = reo_parent_natural::findActualOwnerTarget(ram);
    if (!target)
        return false;
    target->requireHealthy();
    auto* exact = dynamic_cast<OriginalViewportControl*>(target.get());
    return exact ? exact->atOriginalViewport(ram, ctx, runtime) : false;
}
} // namespace reo_gpu_upstream
