#pragma once
#include "pool_writer_scope.hpp"
#include <algorithm>
#include <array>
namespace reo_parent_natural {
class PoolControlWriterCatalogue final {
    friend class NativeTarget;
    static constexpr uint32_t Descriptor = 0x2afef0u, Table = 0x29fef0u, Count = 4096u;
    struct Site {
        uint32_t pc, word;
        uint8_t bytes;
    };
    static constexpr std::array<Site, 14> Sites{{{0x1a0da0u, 0xac860000u, 4},
                                                 {0x1a0da4u, 0xac850008u, 4},
                                                 {0x1a5b18u, 0xa0850000u, 1},
                                                 {0x1a0edcu, 0xac850000u, 4},
                                                 {0x1a0f1cu, 0xac640000u, 4},
                                                 {0x1a1074u, 0xac480000u, 4},
                                                 {0x1a1110u, 0xac460000u, 4},
                                                 {0x1a11a8u, 0xac430000u, 4},
                                                 {0x1a122cu, 0xac430000u, 4},
                                                 {0x1a13d8u, 0xac400000u, 4},
                                                 {0x1a1470u, 0xae120000u, 4},
                                                 {0x1a14c0u, 0xae120000u, 4},
                                                 {0x1a1534u, 0xae120000u, 4},
                                                 {0x1a1578u, 0xae120000u, 4}}};
    R5900Context* initializingContext_ = nullptr;
    PS2Runtime* initializingRuntime_ = nullptr;
    int32_t initializingTask_ = -1;
    std::thread::id initializingThread_;
    bool countCompleted_ = false, tableCompleted_ = false, initialized_ = false;
    uint32_t nextPointerByte_ = Table;
    PoolControlWriterCatalogue() = default;
    static bool requiresDescriptorHistory(uint32_t pc) noexcept {
        return pc == 0x1a5b18u || pc == 0x1a0edcu || pc == 0x1a0f1cu || pc == 0x1a1074u ||
               pc == 0x1a1110u || pc == 0x1a11a8u || pc == 0x1a122cu || pc == 0x1a13d8u ||
               pc == 0x1a1470u || pc == 0x1a14c0u || pc == 0x1a1534u || pc == 0x1a1578u;
    }
    bool protects(uint32_t at, uint32_t bytes) const noexcept {
        const uint64_t end = uint64_t(at) + bytes;
        if ((at < Descriptor + 4u && end > Descriptor) ||
            (at < Descriptor + 12u && end > Descriptor + 8u))
            return true;
        if (at >= Table + Count * 16u || end <= Table)
            return false;
        const uint32_t first = at < Table ? Table : at,
                       last = uint32_t(std::min<uint64_t>(end, Table + Count * 16u));
        for (uint32_t address = first; address < last; ++address)
            if ((address - Table) % 16u < 4u)
                return true;
        return false;
    }
    static uint32_t reg(const R5900Context& ctx, uint32_t index) {
        uint32_t result;
        std::memcpy(&result, &ctx.r[index], 4);
        return index ? result : 0u;
    }
    bool authenticate(uint8_t* ram, R5900Context& ctx, PS2Runtime& runtime, uint32_t at,
                      const void* data, uint32_t bytes, uint32_t pc) const {
        const Site* site = nullptr;
        for (const auto& item : Sites)
            if (item.pc == pc)
                site = &item;
        if (!site)
            return false;
        const auto* scope = actualPoolWriterScope;
        if (!scope)
            throw std::invalid_argument("Protected pool store lacks private original body scope");
        scope->requireActualSource(ram, ctx, runtime);
        uint32_t word;
        std::memcpy(&word, ram + pc, 4);
        if (ctx.pc != pc || word != site->word || bytes != site->bytes || !data)
            throw std::invalid_argument("Pool write differs from exact compiled source store");
        const uint32_t rs = (word >> 21) & 31u, rt = (word >> 16) & 31u;
        const uint32_t expectedAddress = reg(ctx, rs) + uint32_t(int32_t(int16_t(word & 65535u)));
        uint32_t value = reg(ctx, rt), provided = 0;
        std::memcpy(&provided, data, bytes);
        if (at != expectedAddress || (bytes == 1 ? provided != (value & 255u) : provided != value))
            throw std::invalid_argument("Pool permit differs from exact source operands");
        if (pc == 0x1a0da0u || pc == 0x1a0da4u) {
            if (scope->registryEntry_ != 0x1a0da0u || !scope->parent_ ||
                scope->parent_->registryEntry_ != 0x1a0d10u ||
                scope->parent_->body_ != sub_001A0D10_0x1a0d10 ||
                scope->parent_->context_ != &ctx || scope->parent_->runtime_ != &runtime ||
                runtime.lookupFunction(0x1a0d10u) != sub_001A0D10_0x1a0d10 || initialized_ ||
                reg(ctx, 4) != Descriptor || reg(ctx, 5) != Table || reg(ctx, 6) != Count ||
                at != (pc == 0x1a0da0u ? Descriptor : Descriptor + 8u))
                throw std::invalid_argument(
                    "Pool initializer lacks actual 1A0D10 to 1A0DA0 source chain");
            return true;
        }
        if (pc == 0x1a5b18u) {
            // Only pointer bytes are classified. Other memset bytes retain
            // their ordinary source guards and gain no pointer history here.
            if (at < Table || at >= Table + Count * 16u || (at - Table) % 16u >= 4u)
                return false;
            if (initialized_) {
                const uint32_t index = reg(ctx, 16u), offset = reg(ctx, 7u);
                if (scope->registryEntry_ != 0x1a5b10u || !scope->parent_ ||
                    scope->parent_->registryEntry_ != 0x1a1600u ||
                    scope->parent_->body_ != sub_001A1600_0x1a1600 ||
                    scope->parent_->context_ != &ctx || scope->parent_->runtime_ != &runtime ||
                    runtime.lookupFunction(0x1a1600u) != sub_001A1600_0x1a1600 ||
                    !countCompleted_ || !tableCompleted_ || index >= Count || offset >= 4u ||
                    reg(ctx, 5u) != 0u || reg(ctx, 6u) != 16u || at != Table + index * 16u + offset)
                    throw std::invalid_argument("Pool free-slot pointer clear lost actual 1A1600 "
                                                "body/index/zero/width lineage");
                return true;
            }
            if (scope->registryEntry_ != 0x1a5b10u || !countCompleted_ || !tableCompleted_ ||
                initialized_ || initializingContext_ != &ctx || initializingRuntime_ != &runtime ||
                initializingTask_ != ps2_sched::currentThread() ||
                initializingThread_ != std::this_thread::get_id() || at != nextPointerByte_ ||
                reg(ctx, 5) != 0u || reg(ctx, 6) != Count * 16u || reg(ctx, 7) != (at - Table))
                throw std::invalid_argument(
                    "Pool pointer clear lost completed initializer/source cursor");
            return true;
        }
        if (!initialized_ || at < Table || at >= Table + Count * 16u || (at - Table) % 16u ||
            bytes != 4u)
            throw std::invalid_argument(
                "Pool pointer store lacks completed initialized 16-byte table lineage");
        if (pc == 0x1a1470u || pc == 0x1a14c0u || pc == 0x1a1534u || pc == 0x1a1578u) {
            if (scope->registryEntry_ != 0x1a13f0u || reg(ctx, 17) != Descriptor ||
                runtime.lookupFunction(0x1a5b40u) != sub_001A5B40_0x1a5b40)
                throw std::invalid_argument(
                    "Pool relocation lacks actual original helper/copy body identity");
            return true;
        }
        if ((pc == 0x1a0edcu || pc == 0x1a0f1cu) && scope->registryEntry_ != 0x1a0e10u)
            throw std::invalid_argument(
                "Pool linear allocation pointer lacks exact original 1A0E10 body");
        const bool free = pc == 0x1a13d8u;
        if (free ? (scope->registryEntry_ != 0x1a1370u && scope->registryEntry_ != 0x1a0e10u)
                 : (scope->registryEntry_ != 0x1a0f70u && scope->registryEntry_ != 0x1a0e10u))
            throw std::invalid_argument("Pool pointer store came from foreign registered body");
        if (reg(ctx, free ? 4u : 19u) != Descriptor)
            throw std::invalid_argument("Pool store lost genuine descriptor operand");
        return true;
    }
    void completed(R5900Context& ctx, PS2Runtime& runtime, uint32_t at, uint32_t pc) noexcept {
        if (pc == 0x1a0da0u) {
            countCompleted_ = true;
            initializingContext_ = &ctx;
            initializingRuntime_ = &runtime;
            initializingTask_ = ps2_sched::currentThread();
            initializingThread_ = std::this_thread::get_id();
        }
        if (pc == 0x1a0da4u)
            tableCompleted_ = true;
        if (pc == 0x1a5b18u && !initialized_) {
            nextPointerByte_ = at + ((at - Table) % 16u == 3u ? 13u : 1u);
            if (nextPointerByte_ == Table + Count * 16u)
                initialized_ = true;
        }
    }
};
} // namespace reo_parent_natural
