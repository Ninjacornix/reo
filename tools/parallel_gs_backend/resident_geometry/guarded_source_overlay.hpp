#pragma once
// Private matched source overlay, included AFTER the unchanged public macros.
// Generated/direct field rewriting is a separate explicit source closure.
#include "ps2_runtime_macros.h"
#include "source_native_adapter.hpp"
#include "third_party/PS2Recomp/ps2xRuntime/src/lib/instruction_input_evidence.hpp"
#include "third_party/PS2Recomp/ps2xRuntime/src/lib/pre_entry_control_journal.h"
#include "third_party/PS2Recomp/ps2xRuntime/src/lib/parent_source_failure.h"
namespace reo_source_adapter {
struct MemoryView {
    SourceSpace space = SourceSpace::Ram;
    uint32_t at = 0, limit = 0;
    bool source = false;
};
inline MemoryView actualMemoryView(PS2Runtime& runtime, uint32_t address, bool fast) {
    if (fast || !PS2Runtime::isSpecialAddress(address))
        return {SourceSpace::Ram, address & PS2_RAM_MASK, PS2_RAM_SIZE, true};
    const bool scratch = runtime.memory().isScratchpad(address);
    const uint32_t physical = runtime.memory().translateAddress(address);
    if (scratch)
        return {SourceSpace::Spr, physical, PS2_SCRATCHPAD_SIZE, true};
    if (physical < PS2_RAM_SIZE)
        return {SourceSpace::Ram, physical, PS2_RAM_SIZE, true};
    return {}; // MMIO/VU windows retain original runtime side effects.
}
inline std::shared_ptr<ControlTarget> scopedMemoryOwner(const void* ram, R5900Context& ctx) {
    std::shared_ptr<ControlTarget> target;
    try {
        target = findActualOwnerTarget(ram);
        if (!target)
            return {};
        target->requireHealthy();
        if (!target->ownsAnySource() && !target->readyForSelection())
            return {};
        if (currentRuntime() != target->runtimeIdentity() || currentContext() != &ctx ||
            !ps2ActualGuestExecutionDepth(target->runtimeIdentity()))
            throw std::runtime_error("Guarded source memory lacks actual guest lease");
        return target;
    } catch (...) {
        if (target || currentRuntime())
            reo_parent_natural::throwOwnedSourceFailure(target ? target->runtimeIdentity()
                                                               : currentRuntime());
        throw;
    }
}
template <class T, class OriginalRead>
T guardedRead(PS2Runtime& runtime, const void* ram, R5900Context& ctx, uint32_t address, bool fast,
              OriginalRead&& original) {
    auto target = scopedMemoryOwner(ram, ctx);
    MemoryView view{};
    uint32_t first = 0;
    if (target)
        try {
            view = actualMemoryView(runtime, address, fast);
            if (view.source) {
                if (view.at >= view.limit)
                    throw std::out_of_range("Guarded source outside actual bank");
                first = std::min<uint32_t>(sizeof(T), view.limit - view.at);
                target->read(view.space, view.at, first, &ctx, ctx.pc);
                if (first < sizeof(T)) {
                    if (view.space != SourceSpace::Ram ||
                        (!fast && PS2Runtime::isSpecialAddress(address)))
                        throw std::out_of_range("Unclosed special source crossing");
                    target->read(view.space, 0, sizeof(T) - first, &ctx, ctx.pc);
                }
            }
        } catch (...) {
            reo_parent_natural::throwOwnedSourceFailure(&runtime);
        }
    // Ordinary guest/MMIO faults retain their existing runtime handling.
    T result = original();
    if (target && view.source)
        try {
            reo_source_instrumentation::recordActualGuardedMemoryInput(
                target, ctx, address, fast, view.space, view.at, first, &result, sizeof(T));
        } catch (...) {
            reo_parent_natural::throwOwnedSourceFailure(&runtime);
        }
    return result;
}

template <class T, class OriginalWrite>
void guardedWrite(PS2Runtime& runtime, const void* ram, R5900Context& ctx, uint32_t address,
                  T value, bool fast, OriginalWrite&& original) {
    auto target = scopedMemoryOwner(ram, ctx);
    if (!target) {
        // Actual startup integer writes retain source history before the first
        // GPU owner exists. Unknown writes invalidate; values never grant roles.
        auto view = actualMemoryView(runtime, address, fast);
        if (view.source && view.space == SourceSpace::Ram) {
            if (sizeof(T) > view.limit - view.at) {
                invalidateActualPreEntryControlBytes(ram, 0, view.limit);
                original(value);
                return;
            }
            auto permit = prepareActualPreEntryControlWrite(
                runtime, ram, ctx, view.at, &value, sizeof(T),
                reo_source_instrumentation::actualInstructionOrigin);
            try {
                original(value);
                completeActualPreEntryControlWrite(permit);
            } catch (...) {
                abandonActualPreEntryControlWrite(permit);
                throw;
            }
        } else
            original(value);
        return;
    }
    MemoryView view;
    try {
        view = actualMemoryView(runtime, address, fast);
    } catch (...) {
        reo_parent_natural::throwOwnedSourceFailure(&runtime);
    }
    if (!view.source) {
        original(value);
        return;
    }
    try {
        if (view.at >= view.limit || sizeof(T) > view.limit - view.at)
            throw std::out_of_range(
                "Owned multi-view source store needs a grouped permit before mutation");
        WriteTransaction transaction(ram, view.space, view.at, &value, sizeof(T), ctx);
        T captured;
        std::memcpy(&captured, transaction.actualBytes(&value), sizeof(T));
        original(captured);
        transaction.completed();
    } catch (...) {
        reo_parent_natural::throwOwnedSourceFailure(&runtime);
    }
}
template <class T> T gprRead(R5900Context* ctx, unsigned reg) {
    if (reg >= 32)
        throw std::out_of_range("GPR index");
    if (!reg)
        return T{};
    return readContext<T>(*ctx, reg * 16u);
}
template <class T> void gprWrite(const void* ram, R5900Context* ctx, unsigned reg, T value) {
    if (reg >= 32)
        throw std::out_of_range("GPR index");
    if (reg)
        writeContext(ram, *ctx, reg * 16u, value);
}
constexpr bool DirectFieldRewriteComplete = false;
constexpr bool OwnedGroupedWrapStoreImplemented = false;
constexpr bool MmioAndVuWindowSourceClosureComplete = false;
} // namespace reo_source_adapter

#undef FAST_READ8
#undef FAST_READ16
#undef FAST_READ32
#undef FAST_READ64
#undef FAST_READ128
#undef FAST_WRITE8
#undef FAST_WRITE16
#undef FAST_WRITE32
#undef FAST_WRITE64
#undef FAST_WRITE128
#undef READ8
#undef READ16
#undef READ32
#undef READ64
#undef READ128
#undef WRITE8
#undef WRITE16
#undef WRITE32
#undef WRITE64
#undef WRITE128

#define REO_GUARDED_FAST_READ(T, N, A)                                                             \
    ([&]() -> T {                                                                                  \
        const uint32_t reo_at = (uint32_t)(A);                                                     \
        return reo_source_adapter::guardedRead<T>(*runtime, rdram, *ctx, reo_at, true,             \
                                                  [&] { return Ps2FastRead##N(rdram, reo_at); });  \
    }())
#define REO_GUARDED_READ(T, N, A)                                                                  \
    ([&]() -> T {                                                                                  \
        const uint32_t reo_at = (uint32_t)(A);                                                     \
        return reo_source_adapter::guardedRead<T>(*runtime, rdram, *ctx, reo_at, false, [&] {      \
            return PS2Runtime::isSpecialAddress(reo_at) ? runtime->Load##N(rdram, ctx, reo_at)     \
                                                        : Ps2FastRead##N(rdram, reo_at);           \
        });                                                                                        \
    }())
#define REO_GUARDED_FAST_WRITE(T, N, A, V)                                                         \
    do {                                                                                           \
        const uint32_t reo_at = (uint32_t)(A);                                                     \
        const T reo_value = (T)(V);                                                                \
        reo_source_adapter::guardedWrite(                                                          \
            *runtime, rdram, *ctx, reo_at, reo_value, true,                                        \
            [&](T reo_bits) { Ps2FastWrite##N(rdram, reo_at, reo_bits); });                        \
    } while (0)
#define REO_GUARDED_WRITE(T, N, A, V)                                                              \
    do {                                                                                           \
        const uint32_t reo_at = (uint32_t)(A);                                                     \
        const T reo_value = (T)(V);                                                                \
        reo_source_adapter::guardedWrite(                                                          \
            *runtime, rdram, *ctx, reo_at, reo_value, false, [&](T reo_bits) {                     \
                if (PS2Runtime::isSpecialAddress(reo_at))                                          \
                    runtime->Store##N(rdram, ctx, reo_at, reo_bits);                               \
                else {                                                                             \
                    uint64_t reo_lo = 0, reo_hi = 0;                                               \
                    std::memcpy(&reo_lo, &reo_bits, std::min<size_t>(sizeof(T), 8));               \
                    if constexpr (sizeof(T) > 8)                                                   \
                        std::memcpy(&reo_hi, reinterpret_cast<const uint8_t*>(&reo_bits) + 8, 8);  \
                    ps2TraceGuestWrite(rdram, reo_at, sizeof(T), reo_lo, reo_hi, "WRITE" #N, ctx); \
                    Ps2FastWrite##N(rdram, reo_at, reo_bits);                                      \
                }                                                                                  \
            });                                                                                    \
    } while (0)
#define FAST_READ8(A) REO_GUARDED_FAST_READ(uint8_t, 8, A)
#define FAST_READ16(A) REO_GUARDED_FAST_READ(uint16_t, 16, A)
#define FAST_READ32(A) REO_GUARDED_FAST_READ(uint32_t, 32, A)
#define FAST_READ64(A) REO_GUARDED_FAST_READ(uint64_t, 64, A)
#define FAST_READ128(A) REO_GUARDED_FAST_READ(__m128i, 128, A)
#define READ8(A) REO_GUARDED_READ(uint8_t, 8, A)
#define READ16(A) REO_GUARDED_READ(uint16_t, 16, A)
#define READ32(A) REO_GUARDED_READ(uint32_t, 32, A)
#define READ64(A) REO_GUARDED_READ(uint64_t, 64, A)
#define READ128(A) REO_GUARDED_READ(__m128i, 128, A)
#define FAST_WRITE8(A, V) REO_GUARDED_FAST_WRITE(uint8_t, 8, A, V)
#define FAST_WRITE16(A, V) REO_GUARDED_FAST_WRITE(uint16_t, 16, A, V)
#define FAST_WRITE32(A, V) REO_GUARDED_FAST_WRITE(uint32_t, 32, A, V)
#define FAST_WRITE64(A, V) REO_GUARDED_FAST_WRITE(uint64_t, 64, A, V)
#define FAST_WRITE128(A, V) REO_GUARDED_FAST_WRITE(__m128i, 128, A, V)
#define WRITE8(A, V) REO_GUARDED_WRITE(uint8_t, 8, A, V)
#define WRITE16(A, V) REO_GUARDED_WRITE(uint16_t, 16, A, V)
#define WRITE32(A, V) REO_GUARDED_WRITE(uint32_t, 32, A, V)
#define WRITE64(A, V) REO_GUARDED_WRITE(uint64_t, 64, A, V)
#define WRITE128(A, V) REO_GUARDED_WRITE(__m128i, 128, A, V)

#undef GPR_U32
#undef GPR_S32
#undef GPR_U64
#undef GPR_S64
#undef GPR_VEC
#undef SET_GPR_U32
#undef SET_GPR_S32
#undef SET_GPR_U64
#undef SET_GPR_S64
#undef SET_GPR_VEC
#define GPR_U32(C, R) reo_source_adapter::gprRead<uint32_t>(C, R)
#define GPR_S32(C, R) reo_source_adapter::gprRead<int32_t>(C, R)
#define GPR_U64(C, R) reo_source_adapter::gprRead<uint64_t>(C, R)
#define GPR_S64(C, R) reo_source_adapter::gprRead<int64_t>(C, R)
#define GPR_VEC(C, R) reo_source_adapter::gprRead<__m128i>(C, R)
#define SET_GPR_U32(C, R, V)                                                                       \
    do {                                                                                           \
        const unsigned reo_reg = (R);                                                              \
        if (reo_reg)                                                                               \
            reo_source_adapter::gprWrite(rdram, C, reo_reg, (uint64_t)(int64_t)(int32_t)(V));      \
    } while (0)
#define SET_GPR_S32(C, R, V) SET_GPR_U32(C, R, V)
#define SET_GPR_U64(C, R, V)                                                                       \
    do {                                                                                           \
        const unsigned reo_reg = (R);                                                              \
        if (reo_reg)                                                                               \
            reo_source_adapter::gprWrite(rdram, C, reo_reg, (uint64_t)(V));                        \
    } while (0)
#define SET_GPR_S64(C, R, V) SET_GPR_U64(C, R, V)
#define SET_GPR_VEC(C, R, V)                                                                       \
    do {                                                                                           \
        const unsigned reo_reg = (R);                                                              \
        if (reo_reg)                                                                               \
            reo_source_adapter::gprWrite(rdram, C, reo_reg, (__m128i)(V));                         \
    } while (0)
