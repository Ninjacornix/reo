#pragma once
#include "parent/parent_context_abi.hpp"
#include "device.hpp"
#include <array>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <stdexcept>
#include <vector>
namespace reo_gpu_palette_parent {
class Producer;
}
namespace reo_parent_install {
class Service;
}
namespace reo_gpu_upstream {
constexpr uint32_t RamBytes = 0x2000000, SprBytes = 0x4000, ContextBytes = 1648,
                   CompletionBytes = 48;
constexpr uint32_t ReceiptMagic = 0x55505331u, ReceiptVersion = 1, ReceiptWords = 20,
                   ReceiptBytes = ReceiptWords * 4;
static_assert(sizeof(R5900Context) == ContextBytes);
enum class Bank : uint8_t { Ram, Spr, Context, Completion };
struct Stamp {
    uint64_t session = 0, epoch = 0, bankGeneration = 0, ordinal = 0;
};
inline bool same(const Stamp& a, const Stamp& b) {
    return a.session == b.session && a.epoch == b.epoch && a.bankGeneration == b.bankGeneration &&
           a.ordinal == b.ordinal;
}
// Only the actual parent Producer can associate these exact persistent banks.
// Same-Device declarations and arbitrary Buffer pointers cannot mint this token.
class Banks final {
    friend class reo_gpu_palette_parent::Producer;
    const void* issuer_;
    const Vulkan::Device* device_;
    Stamp stamp_;
    std::array<Vulkan::BufferHandle, 4> banks_;
    Banks(const void* issuer, const Vulkan::Device* device, Stamp stamp,
          std::array<Vulkan::BufferHandle, 4> banks)
        : issuer_(issuer), device_(device), stamp_(stamp), banks_(std::move(banks)) {}

  public:
    const void* issuer() const noexcept {
        return issuer_;
    }
    const Vulkan::Device* device() const noexcept {
        return device_;
    }
    const Stamp& stamp() const noexcept {
        return stamp_;
    }
    const Vulkan::Buffer& bank(Bank kind) const {
        return *banks_[unsigned(kind)];
    }
};
using BanksHandle = std::shared_ptr<const Banks>;
// The actual Service mints this from the original EE entry and integer control
// fields. No numerical matrix, VF/FPR/ACC shadow or source contents are inputs.
class Call final {
    friend class reo_parent_install::Service;
    const void* issuer_ = nullptr;
    Stamp stamp_{};
    uint32_t entry_ = 0, returnPc_ = 0, a0_ = 0, a1_ = 0, a2_ = 0;
    int32_t task_ = -1;
    Call(const void* issuer, Stamp stamp, uint32_t entry, uint32_t ra, uint32_t a0, uint32_t a1,
         uint32_t a2, int32_t task)
        : issuer_(issuer), stamp_(stamp), entry_(entry), returnPc_(ra), a0_(a0), a1_(a1), a2_(a2),
          task_(task) {}

  public:
    const Stamp& stamp() const noexcept {
        return stamp_;
    }
    const void* issuer() const noexcept {
        return issuer_;
    }
    uint32_t entry() const noexcept {
        return entry_;
    }
    uint32_t returnPc() const noexcept {
        return returnPc_;
    }
    uint32_t a0() const noexcept {
        return a0_;
    }
    uint32_t a1() const noexcept {
        return a1_;
    }
    uint32_t a2() const noexcept {
        return a2_;
    }
    int32_t task() const noexcept {
        return task_;
    }
};
using CallHandle = std::shared_ptr<const Call>;
struct Parameters {
    uint32_t sessionLo, sessionHi, epochLo, epochHi, bankLo, bankHi, ordinalLo, ordinalHi;
    uint32_t entry, returnPc, a0, a1, a2, contextWords, vfBase, accBase, pcWord, raWord, gprBase,
        reserved;
};
static_assert(sizeof(Parameters) == 80);
inline Parameters parameters(const Call& call) {
    const auto& s = call.stamp();
    return {uint32_t(s.session),
            uint32_t(s.session >> 32),
            uint32_t(s.epoch),
            uint32_t(s.epoch >> 32),
            uint32_t(s.bankGeneration),
            uint32_t(s.bankGeneration >> 32),
            uint32_t(s.ordinal),
            uint32_t(s.ordinal >> 32),
            call.entry(),
            call.returnPc(),
            call.a0(),
            call.a1(),
            call.a2(),
            ContextBytes / 4,
            uint32_t(offsetof(R5900Context, vu0_vf) / 4),
            uint32_t(offsetof(R5900Context, vu0_acc) / 4),
            uint32_t(offsetof(R5900Context, pc) / 4),
            uint32_t((offsetof(R5900Context, r) + 31 * 16) / 4),
            uint32_t(offsetof(R5900Context, r) / 4),
            0};
}
// Selected source domain: whole aligned matrices in actual RAM (normal and
// accelerated/KSEG RAM mirrors) or the real scratchpad, no IO/TLB inference.
struct View {
    Bank bank;
    uint32_t offset;
};
inline View matrixView(uint32_t address) {
    if (address & 15u)
        throw std::invalid_argument("Original matrix view is not aligned");
    if (address >= 0x70000000u && address <= 0x70000000u + SprBytes - 64u)
        return {Bank::Spr, address - 0x70000000u};
    const bool ram =
        address < RamBytes || (address >= 0x20000000u && address < 0x40000000u) ||
        (address >= 0x80000000u && address < 0xc0000000u && (address & 0x1fffffffu) < RamBytes);
    const uint32_t at = address & (RamBytes - 1);
    if (!ram || at > RamBytes - 64u)
        throw std::invalid_argument(
            "Original matrix view is outside bounded RAM/SPR source domain");
    return {Bank::Ram, at};
}
} // namespace reo_gpu_upstream
