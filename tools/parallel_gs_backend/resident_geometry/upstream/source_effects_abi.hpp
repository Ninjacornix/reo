#pragma once
#include "upstream_bank_abi.hpp"
#include <array>
#include <cstdint>
#include <vector>
namespace reo_source_closure {
// Proposed same-transaction integer metadata ABI. Do not create these records
// from a CPU output snapshot or certify them by comparing numerical values.
enum class Role : uint32_t {
    OpaqueGraphicsNumeric = 1,
    PreservedIncomingLease = 2,
    GenuineControlPc = 3,
    GenuineControlFcr = 4,
    GenuineControlPointer = 5,
    GenuineControlStack = 6,
    GenuineScalarReturn = 7,
    ReviewedRawAssetCopy = 8,
    PrivateStackCarry = 9
};
enum class Space : uint32_t { Ram = 0, Spr = 1, Context = 2 };
struct DirtySpan {
    uint32_t space, offset, bytes, role, sourcePc, sourceOrdinal;
};
static_assert(sizeof(DirtySpan) == 24);
struct ControlWord {
    uint32_t contextOffset, bytes, role, sourcePc;
    std::array<uint32_t, 4> bits;
};
static_assert(sizeof(ControlWord) == 32);
struct Header {
    uint32_t status, magic, version, committed;
    std::array<uint32_t, 8> stamp;
    uint32_t originalEntry, actualFinalPc, actualTask, profile;
    uint32_t dirtyCount, controlCount, dirtyCapacity, controlCapacity;
};
static_assert(sizeof(Header) == 80);
constexpr uint32_t EffectsMagic = 0x53454631, EffectsVersion = 1;
// Input and output stay associated with actual immutable Output/Banks/Call,
// true parent fence and bank source chronology, not a same-Device declaration.
// The actual Service is the only issuer after its genuine readback validates
// the complete GPU module/profile/span/role output against that association.
class CertifiedEffects final {
    friend class reo_parent_install::Service;
    const void* issuer_;
    reo_gpu_upstream::BanksHandle banks_;
    reo_gpu_upstream::CallHandle call_;
    Vulkan::BufferHandle exactGpuEffects_;
    uint64_t trueFenceOrdinal_;
    Header header_;
    std::vector<DirtySpan> dirty_;
    std::vector<ControlWord> control_;
    CertifiedEffects(const void* issuer, reo_gpu_upstream::BanksHandle banks,
                     reo_gpu_upstream::CallHandle call, Vulkan::BufferHandle effects,
                     uint64_t fence, Header header, std::vector<DirtySpan> dirty,
                     std::vector<ControlWord> control)
        : issuer_(issuer), banks_(std::move(banks)), call_(std::move(call)),
          exactGpuEffects_(std::move(effects)), trueFenceOrdinal_(fence), header_(header),
          dirty_(std::move(dirty)), control_(std::move(control)) {}

  public:
    CertifiedEffects(const CertifiedEffects&) = delete;
    const Header& header() const noexcept {
        return header_;
    }
    const std::vector<DirtySpan>& dirty() const noexcept {
        return dirty_;
    }
    const std::vector<ControlWord>& control() const noexcept {
        return control_;
    }
};
constexpr bool ActualGpuEffectsIssuerImplemented = false;
constexpr bool ExactLaneOriginAndNativeBoundaryClosureImplemented = false;
} // namespace reo_source_closure
