#pragma once
#include "explicit_source_write.hpp"
#include <stdexcept>
#include <type_traits>
namespace reo_source_adapter {
using namespace reo_parent_natural;
class WriteTransaction final {
    std::shared_ptr<ControlTarget> target_;
    ExplicitSourceWriteTarget* exact_ = nullptr;
    SourceWritePermit permit_;
    SourceSpace space_;
    uint32_t at_, bytes_, pc_;
    R5900Context* ctx_;
    bool completed_ = false;

  public:
    WriteTransaction(const void* ram, SourceSpace space, uint32_t at, const void* value,
                     uint32_t bytes, R5900Context& ctx)
        : space_(space), at_(at), bytes_(bytes), pc_(ctx.pc), ctx_(&ctx) {
        target_ = findActualOwnerTarget(ram);
        if (!target_)
            return;
        target_->requireHealthy();
        if (!target_->ownsAnySource() && !target_->readyForSelection()) {
            target_.reset();
            return;
        }
        if (currentRuntime() != target_->runtimeIdentity() || currentContext() != &ctx)
            throw std::runtime_error("Source write lacks genuine guest invocation scope");
        exact_ = dynamic_cast<ExplicitSourceWriteTarget*>(target_.get());
        if (!exact_)
            throw std::runtime_error("Owned source lacks explicit matched write API");
        permit_ = exact_->beginSourceWrite(space, at, value, bytes, &ctx, pc_);
        if (!permit_)
            throw std::runtime_error("Owned source failed to issue exact write permit");
        try {
            exact_->authorizeSourceWrite(permit_, space, at, value, bytes, &ctx, pc_);
        } catch (...) {
            exact_->abandonSourceWrite(permit_);
            throw;
        }
    }
    ~WriteTransaction() {
        if (exact_ && !completed_)
            exact_->abandonSourceWrite(permit_);
    }
    WriteTransaction(const WriteTransaction&) = delete;
    const void* actualBytes(const void* unownedValue) const noexcept {
        return permit_ ? permit_->data() : unownedValue;
    }
    void completed() {
        if (completed_)
            throw std::logic_error("Source write completed twice");
        if (exact_)
            exact_->finishSourceWrite(permit_, space_, at_, ctx_, pc_);
        completed_ = true;
    }
};
template <class T> T readContext(R5900Context& ctx, uint32_t at) {
    static_assert(std::is_trivially_copyable_v<T>);
    if (at > sizeof(ctx) || sizeof(T) > sizeof(ctx) - at)
        throw std::out_of_range("Context read outside1648 ABI");
    if (auto* runtime = currentRuntime()) {
        auto target = findActualOwnerTarget(runtime->memory().getRDRAM());
        if (target && (target->ownsAnySource() || target->readyForSelection()) &&
            target->contextIdentity() == &ctx && !ps2ActualGuestExecutionDepth(runtime))
            throw std::runtime_error("Context read lacks actual guest execution lease");
    }
    ps2ParentBeforeContextRead(&ctx, at, sizeof(T));
    T value;
    std::memcpy(&value, reinterpret_cast<uint8_t*>(&ctx) + at, sizeof(T));
    return value;
}
template <class T>
void writeContext(const void* ram, R5900Context& ctx, uint32_t at, const T& value) {
    static_assert(std::is_trivially_copyable_v<T>);
    if (at > sizeof(ctx) || sizeof(T) > sizeof(ctx) - at)
        throw std::out_of_range("Context write outside1648 ABI");
    WriteTransaction transaction(ram, SourceSpace::Context, at, &value, sizeof(T), ctx);
    std::memcpy(reinterpret_cast<uint8_t*>(&ctx) + at, transaction.actualBytes(&value), sizeof(T));
    transaction.completed();
}
// Native RAW copies guard the source before capturing it and prepare the
// exact destination transaction before mutation. GPU numerics need a lease.
inline void copyCheckedRaw(const void* ram, R5900Context& ctx, SourceSpace space, uint32_t source,
                           uint32_t destination, uint32_t bytes, void* dst, const void* src) {
    if (!dst || !src || !bytes || bytes > 1024 * 1024)
        throw std::invalid_argument("Native source copy invalid/unbounded");
    auto target = findActualOwnerTarget(ram);
    if (target) {
        target->requireHealthy();
        if (target->ownsAnySource() || target->readyForSelection()) {
            if (currentRuntime() != target->runtimeIdentity() || currentContext() != &ctx ||
                !ps2ActualGuestExecutionDepth(target->runtimeIdentity()))
                throw std::runtime_error("Native copy lacks actual guest ownership");
            const auto* bank = space == SourceSpace::Context
                                   ? reinterpret_cast<const uint8_t*>(&ctx)
                                   : static_cast<const uint8_t*>(space == SourceSpace::Ram
                                                                     ? target->ramIdentity()
                                                                     : target->sprIdentity());
            const uint32_t limit = space == SourceSpace::Ram   ? 0x2000000u
                                   : space == SourceSpace::Spr ? 0x4000u
                                                               : 1648u;
            if (source >= limit || bytes > limit - source || destination >= limit ||
                bytes > limit - destination || src != bank + source || dst != bank + destination)
                throw std::invalid_argument("Native copy views differ from actual guarded bank");
            target->read(space, source, bytes, &ctx, ctx.pc);
        }
    }
    // Capture only after the source guard. Permit owns the exact immutable
    // bytes used for the subsequent store, including overlaps/host aliasing.
    std::vector<uint8_t> capture(static_cast<const uint8_t*>(src),
                                 static_cast<const uint8_t*>(src) + bytes);
    WriteTransaction transaction(ram, space, destination, capture.data(), bytes, ctx);
    std::memcpy(dst, transaction.actualBytes(capture.data()), bytes);
    transaction.completed();
}
static_assert(sizeof(R5900Context) == 1648);
constexpr bool TypedOpaqueCopyLeaseImplemented = false;
} // namespace reo_source_adapter
