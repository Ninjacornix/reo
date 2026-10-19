#pragma once
#include "upstream_bank_abi.hpp"
#include "ps2_runtime.h"
// These signatures match the actual File1 generated declaration header.
// Keep this private backend contract independent of its generated include path.
void sub_0018DCA0_0x18dca0(uint8_t*, R5900Context*, PS2Runtime*);
void sub_001A0D70_0x1a0d70(uint8_t*, R5900Context*, PS2Runtime*);
void sub_001A1330_0x1a1330(uint8_t*, R5900Context*, PS2Runtime*);
// Implemented beside the actual static override, not by a fixture or by
// comparing buffer pointer values. It returns the real registered code symbol.
PS2Runtime::RecompiledFunction reoActualPoolResolverPassthroughIdentity() noexcept;
namespace reo_parent_natural {
class NativeTarget;
}
namespace reo_gpu_upstream {
enum class QueueResolverKind : uint32_t { OriginalLookup = 1, NativeRawPointerPassthrough = 2 };
class QueueResolverBinding final {
    friend class reo_parent_natural::NativeTarget;
    friend class reo_parent_install::Service;
    friend class QueueControlAdapter;
    friend class QueueJournalPipeline;
    const void* issuer_;
    CallHandle call_;
    PS2Runtime* runtime_;
    R5900Context* actualEeContext_;
    QueueResolverKind kind_;
    int32_t actualTask_;
    std::array<PS2Runtime::RecompiledFunction, 3> actualFunctions_;
    QueueResolverBinding(const void* issuer, CallHandle call, PS2Runtime* runtime,
                         R5900Context* ctx, QueueResolverKind kind, int32_t task,
                         std::array<PS2Runtime::RecompiledFunction, 3> functions)
        : issuer_(issuer), call_(std::move(call)), runtime_(runtime), actualEeContext_(ctx),
          kind_(kind), actualTask_(task), actualFunctions_(functions) {}

  public:
    QueueResolverBinding(const QueueResolverBinding&) = delete;
    QueueResolverKind kind() const noexcept {
        return kind_;
    }
};
using QueueResolverBindingHandle = std::shared_ptr<const QueueResolverBinding>;
constexpr bool QueueResolverFunctionMapWriterCoverageImplemented = false;
} // namespace reo_gpu_upstream
