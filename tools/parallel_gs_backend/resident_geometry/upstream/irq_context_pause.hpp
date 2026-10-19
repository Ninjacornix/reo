#pragma once
#include "irq_initializer_lifetime.hpp"
#include "device.hpp"
#include <condition_variable>
uint32_t ps2IoRegLockDepth() noexcept;
namespace reo_gpu_upstream {
class Banks;
using BanksHandle = std::shared_ptr<const Banks>;
} // namespace reo_gpu_upstream
namespace reo_parent_install {
// Constructor and transitions are exclusive to the actual parent Service.
// A private reservation blocks main EE publication while the guest lock is
// released for a real ordered owner/fence wait. No bool or arbitrary source
// key can certify an in-flight main Context as safe to borrow.
class IrqContextPause final {
    friend class Service;
    const Service* issuer_;
    PS2Runtime* runtime_;
    R5900Context* caller_;
    std::shared_ptr<const void> callerLifetime_;
    reo_parent_natural::IrqInitializerHandle initializer_;
    reo_gpu_upstream::BanksHandle savedBanks_;
    uint64_t epoch_, contextRevision_, upstreamCut_, captureOrdinal_;
    // These are genuine Service registry objects. They hold exact original
    // calls/outputs/fences/frontiers alive; no numerical bytes are extracted.
    std::vector<std::shared_ptr<const void>> heldEntries_;
    std::vector<const void*> registryIdentity_;
    Vulkan::Fence fence_;
    uint64_t timeline_ = 0, retiredPrefix_ = 0;
    bool recorded_ = false, waiting_ = false, waited_ = false, freshIssued_ = false,
         closed_ = false;
    IrqContextPause(const Service* issuer, PS2Runtime* runtime, R5900Context* caller,
                    std::shared_ptr<const void> lifetime,
                    reo_parent_natural::IrqInitializerHandle init,
                    reo_gpu_upstream::BanksHandle banks, uint64_t epoch, uint64_t revision,
                    uint64_t cut, uint64_t ordinal)
        : issuer_(issuer), runtime_(runtime), caller_(caller), callerLifetime_(std::move(lifetime)),
          initializer_(std::move(init)), savedBanks_(std::move(banks)), epoch_(epoch),
          contextRevision_(revision), upstreamCut_(cut), captureOrdinal_(ordinal) {}

  public:
    IrqContextPause(const IrqContextPause&) = delete;
    const reo_parent_natural::IrqInitializerHandle& initializer() const noexcept {
        return initializer_;
    }
    R5900Context& caller() const noexcept {
        return *caller_;
    }
};
using IrqContextPauseHandle = std::shared_ptr<const IrqContextPause>;
inline constexpr bool ActualIrqContextPauseSourceClosureInstalled = false;
} // namespace reo_parent_install
