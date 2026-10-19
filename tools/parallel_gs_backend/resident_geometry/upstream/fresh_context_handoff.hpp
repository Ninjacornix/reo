#pragma once
#include "tools/parallel_gs_backend/resident_geometry/upstream/callback_context_handoff.hpp"
#include "irq_initializer_lifetime.hpp"
namespace reo_parent_natural {
class IrqContextTarget {
  public:
    virtual ~IrqContextTarget() = default;
    // Called immediately inside the genuine IRQ EntryScope before reading
    // the fresh Context PC or executing its first registered handler step.
    virtual CallbackFrameHandle enterActualIrqContext(const IrqInitializerHandle&) = 0;
};
inline constexpr bool ActualFreshIrqContextSourceClosureImplemented = false;
} // namespace reo_parent_natural
