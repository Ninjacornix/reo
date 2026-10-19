#pragma once
#include "parent_natural_runtime.h"
namespace reo_gpu_upstream {
class OriginalPerspectiveControl {
  public:
    virtual ~OriginalPerspectiveControl() = default;
    virtual bool atOriginalPerspective(uint8_t*, R5900Context&, PS2Runtime&) = 0;
};
inline bool dispatchOriginalPerspective(uint8_t* ram, R5900Context& ctx, PS2Runtime& runtime) {
    reo_parent_natural::AccessScope scope(&runtime, &ctx);
    auto target = reo_parent_natural::findActualOwnerTarget(ram);
    if (!target)
        return false;
    target->requireHealthy();
    auto* profile = dynamic_cast<OriginalPerspectiveControl*>(target.get());
    return profile && profile->atOriginalPerspective(ram, ctx, runtime);
}
} // namespace reo_gpu_upstream
