#pragma once
#include "parent_natural_runtime.h"
namespace reo_gpu_upstream {
class OriginalCompositionControl {
  public:
    virtual ~OriginalCompositionControl() = default;
    virtual bool atOriginalComposition(uint8_t*, R5900Context&, PS2Runtime&) = 0;
};
// No externally supplied proof fields can bypass the actual source closure.
inline constexpr bool CompositionNaturalSourceClosureImplemented = false;
inline bool dispatchOriginalComposition(uint8_t* ram, R5900Context& ctx, PS2Runtime& runtime) {
    reo_parent_natural::AccessScope scope(&runtime, &ctx);
    auto target = reo_parent_natural::findActualOwnerTarget(ram);
    if (!target)
        return false;
    target->requireHealthy();
    auto* exact = dynamic_cast<OriginalCompositionControl*>(target.get());
    if (!exact)
        return false;
    return exact->atOriginalComposition(ram, ctx, runtime);
}
} // namespace reo_gpu_upstream
