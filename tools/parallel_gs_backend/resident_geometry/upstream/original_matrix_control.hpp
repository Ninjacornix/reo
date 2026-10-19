#pragma once
#include "parent_natural_runtime.h"
namespace reo_gpu_upstream {
class OriginalMatrixControl {
  public:
    virtual ~OriginalMatrixControl() = default;
    virtual bool atOriginal191280(uint8_t*, R5900Context&, PS2Runtime&) = 0;
};
// This may replace the original entry only after the full natural source,
// context/native-copy and reset closure is complete. Selection stays false in
// the copied NativeTarget; absent/unselected ownership runs the original body.
inline bool dispatchOriginal191280(uint8_t* ram, R5900Context& ctx, PS2Runtime& runtime) {
    reo_parent_natural::AccessScope scope(&runtime, &ctx);
    auto target = reo_parent_natural::findActualOwnerTarget(ram);
    if (!target)
        return false;
    target->requireHealthy();
    auto* exact = dynamic_cast<OriginalMatrixControl*>(target.get());
    if (!exact)
        return false;
    return exact->atOriginal191280(ram, ctx, runtime);
}
} // namespace reo_gpu_upstream
