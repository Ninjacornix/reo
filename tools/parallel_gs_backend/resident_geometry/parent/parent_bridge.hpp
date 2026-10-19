#pragma once
// Conditional closed private protocol. Default gates false; no canonical install.
#include "parent_context_abi.hpp"
#include <array>
#include <algorithm>
#include <bitset>
#include <cstdint>
#include <cstring>
#include <memory>
#include <deque>
#include <stdexcept>
#include <vector>
namespace reo_parent_install {
class Service;
}
namespace reo_parent_live {
constexpr uint32_t RamBytes = 0x2000000u, PacketBytes = 0xfb0u, PayloadBytes = 0xf80u,
                   PayloadOffset = 0x20u;
static_assert(sizeof(R5900Context) == 1648);
enum class Space : uint8_t { Ram, Spr, Context };
enum class Phase : uint8_t {
    Allocated,
    InputsFrozen,
    Recorded,
    Submitted,
    Returned,
    UnpackJoined,
    Retired,
    Failed
};
enum class Entry : uint8_t { DeclinedBeforeOwnership, GuestHeld, ScalarReturned };
// Explicit controlled fixture tier supplies no installed hook/production proof.
enum class AdmissionTier : uint8_t { ScopedLive, OfflineComponent };
struct Range {
    Space space;
    uint32_t address, bytes;
};
struct Key {
    uint64_t session = 0, epoch = 0, allocation = 0, revision = 0, ordinal = 0;
};
inline bool same(const Key& a, const Key& b) {
    return a.session == b.session && a.epoch == b.epoch && a.allocation == b.allocation &&
           a.revision == b.revision && a.ordinal == b.ordinal;
}
struct Allocation {
    Key key;
    const void* memory = nullptr;
    R5900Context* context = nullptr;
    uint32_t pc = 0, packet = 0, frame = 0, descriptor = 0, mask = 0;
    int32_t task = -1;
};
enum class SourcePatchKind : uint8_t { ReviewedRaw, NativeScalar, CpuNumeric, IrqIntegerControl };
// The kind preserves source provenance through the existing ordered transport.
// It supplies no public authority to clear an ownership mask.
struct RawPatch {
    Range range;
    uint64_t actualWriterOrdinal = 0;
    uint32_t actualPC = 0;
    std::vector<uint8_t> bytes;
    SourcePatchKind kind = SourcePatchKind::ReviewedRaw;
};
inline void validateSourcePatchShape(const RawPatch& patch) {
    const uint32_t limit = patch.range.space == Space::Ram       ? RamBytes
                           : patch.range.space == Space::Spr     ? 0x4000u
                           : patch.range.space == Space::Context ? 1648u
                                                                 : 0u;
    if (!patch.actualWriterOrdinal || !patch.actualPC || !patch.range.bytes ||
        patch.range.address >= limit || patch.range.bytes > limit - patch.range.address ||
        patch.bytes.size() != patch.range.bytes ||
        (patch.kind != SourcePatchKind::ReviewedRaw &&
         patch.kind != SourcePatchKind::NativeScalar && patch.kind != SourcePatchKind::CpuNumeric &&
         patch.kind != SourcePatchKind::IrqIntegerControl) ||
        (patch.kind != SourcePatchKind::ReviewedRaw &&
         patch.kind != SourcePatchKind::IrqIntegerControl &&
         (patch.range.space != Space::Context || patch.range.bytes > 16u)) ||
        (patch.kind == SourcePatchKind::IrqIntegerControl &&
         (patch.range.space == Space::Spr || patch.range.bytes > 16u)) ||
        (patch.kind == SourcePatchKind::NativeScalar &&
         (patch.range.address != 32u || patch.range.bytes != 16u)))
        throw std::invalid_argument("Source transport lost exact range/writer/provenance");
}
struct Origin {
    uint32_t offset = 0, address = 0, bytes = 0;
    Key key;
    bool scratch = false;
};
struct Mailbox {
    std::array<uint32_t, 48> words{};
};
// These are scoped installed hook/transport reviews, not universal claims about
// every writer or about natural capture. Existing12 controlled cases prove only
// the parent numerical component. None of these transport gates is inferred.
struct Gates {
    bool rootWholeParent12 = false, exactProducerModulePins = false,
         sharedDeviceBankFactory = false;
    bool beforeFastAndSpecialAndDmaWrites = false, beforeRawRamConsumers = false,
         beforeDirectContextConsumers = false;
    bool snapshotOrOrderedSourceLease = false, realFenceScalarMailbox = false;
    bool typedDmaSliceConcatRemainder = false, actualUnpackOwnerBinding = false;
    bool ready() const {
        return rootWholeParent12 && exactProducerModulePins && sharedDeviceBankFactory &&
               beforeFastAndSpecialAndDmaWrites && beforeRawRamConsumers &&
               beforeDirectContextConsumers && snapshotOrOrderedSourceLease &&
               realFenceScalarMailbox && typedDmaSliceConcatRemainder && actualUnpackOwnerBinding;
    }
};
struct Produced {
    Key key;
    std::shared_ptr<const void> immutableGpuPayload;
    std::shared_ptr<const void> gpuContextLease;
};
class Backend;
class Receipt {
    friend class Backend;
    friend class Bridge;
    const Backend* issuer_ = nullptr;
    Key key_;
    uint64_t timeline_ = 0;
    uint32_t sticky_ = 0;
    Mailbox mailbox_;
};
class Backend {
  protected:
    Receipt completedControlReceipt(const Key& key, uint64_t actualCompletedTimeline,
                                    uint32_t sticky, const Mailbox& mailbox) const {
        Receipt r;
        r.issuer_ = this;
        r.key_ = key;
        r.timeline_ = actualCompletedTimeline;
        r.sticky_ = sticky;
        r.mailbox_ = mailbox;
        return r;
    }

  public:
    virtual ~Backend() = default;
    // Implemented only beside the existing GS Device. Record real ordered raw
    // patches plus the unchanged proved producer; return retains GPU resources.
    virtual Produced record(const Allocation&, const std::vector<RawPatch>&) = 0;
    virtual uint64_t submitAndHoldGuest(const Allocation&, const Produced&) = 0;
    virtual void recordActualUnpack(const Produced&, uint32_t command, uint32_t tops,
                                    const std::vector<Origin>&) = 0;
    virtual void recordActualRawContextOverwrite(const Allocation&, const RawPatch&) = 0;
    virtual void recordActualRawRamOverwrite(const Allocation&, const RawPatch&) = 0;
    virtual void rejectOwned(const Key&, uint32_t reason) = 0;
    virtual void observedBypass(const Allocation&, Space, uint32_t at, uint32_t bytes,
                                uint32_t actualPC) = 0;
};
inline uint32_t raw32(const void* p) {
    uint32_t w;
    std::memcpy(&w, p, 4);
    return w;
}
inline bool range(uint32_t at, uint32_t bytes, uint32_t limit) {
    return bytes && at < limit && bytes <= limit - at;
}
inline bool overlap(uint32_t a, uint32_t n, uint32_t b, uint32_t m) {
    return uint64_t(a) < uint64_t(b) + m && uint64_t(b) < uint64_t(a) + n;
}
// Source-proved closed RAM read ranges plus fullSPR. A frozen raw input frontier
// has no post-seam CPU reseeding of GPU-owned FP/VU0 words. Writer events must
// supply only changed actual CPU words, or same-Device GPU source copies.
inline std::vector<Range> sourceRanges(const Allocation& a, const uint8_t* ram) {
    if (!ram || a.pc != 0x19bbfcu || !a.context || a.frame < 0x60u ||
        ((a.packet | a.frame | a.descriptor) & 15u) || !range(a.packet, PacketBytes, RamBytes) ||
        !range(a.frame - 0x60u, 0xd0u, RamBytes) || !range(a.descriptor, 0x180u, RamBytes))
        throw std::invalid_argument("Not bounded actual19BBFC");
    const uint32_t pointer = raw32(ram + a.descriptor + 0x4cu);
    if ((pointer & 3u) || !range(pointer, 0x28u, RamBytes))
        throw std::invalid_argument("Parent source pointer outside RAM");
    return {{Space::Ram, 0x294000u, 0x1000u},
            {Space::Ram, 0x29fe40u, 0x10u},
            {Space::Ram, a.descriptor, 0x180u},
            {Space::Ram, pointer, 0x28u},
            {Space::Ram, a.packet, PacketBytes},
            {Space::Ram, a.frame - 0x60u, 0xd0u},
            {Space::Spr, 0, 0x4000u},
            {Space::Context, 0, 1648u}};
}
class Bridge {
    friend class reo_parent_install::Service;
    Backend& backend_;
    Gates gates_;
    Allocation actual_{};
    Produced produced_{};
    Phase phase_ = Phase::Retired;
    uint64_t lastAllocation_ = 0, lastOrdinal_ = 0, sealed_ = 0, unpackSealed_ = 0, retired_ = 0;
    std::bitset<1648> opaqueContext_;
    bool owns_ = false, contextLeaseActive_ = false;
    struct Waiting {
        Allocation actual;
        Produced produced;
        uint64_t parentTimeline = 0, unpackTimeline = 0;
        bool joined = false;
    };
    std::deque<Waiting> waiting_;
    std::vector<Range> opaqueRam_;
    void markOpaqueRam(uint32_t at, uint32_t bytes) {
        opaqueRam_.push_back({Space::Ram, at, bytes});
        std::sort(opaqueRam_.begin(), opaqueRam_.end(),
                  [](const Range& a, const Range& b) { return a.address < b.address; });
        std::vector<Range> merged;
        for (const auto& r : opaqueRam_) {
            if (!merged.empty() &&
                uint64_t(merged.back().address) + merged.back().bytes >= r.address) {
                const uint64_t end = std::max(uint64_t(merged.back().address) + merged.back().bytes,
                                              uint64_t(r.address) + r.bytes);
                merged.back().bytes = uint32_t(end - merged.back().address);
            } else
                merged.push_back(r);
        }
        opaqueRam_ = std::move(merged);
        if (opaqueRam_.size() > 65536)
            fail(99u);
    }
    std::vector<Range> clearedOpaqueRam(uint32_t at, uint32_t bytes) {
        std::vector<Range> next;
        next.reserve(opaqueRam_.size() + 1);
        for (const auto& r : opaqueRam_) {
            if (!overlap(at, bytes, r.address, r.bytes)) {
                next.push_back(r);
                continue;
            }
            if (r.address < at)
                next.push_back({Space::Ram, r.address, at - r.address});
            const uint64_t end = uint64_t(r.address) + r.bytes, stop = uint64_t(at) + bytes;
            if (end > stop)
                next.push_back({Space::Ram, uint32_t(stop), uint32_t(end - stop)});
        }
        if (next.size() > 65536)
            fail(99u);
        return next;
    }
    void fail(uint32_t reason) {
        phase_ = Phase::Failed;
        if (owns_ || contextLeaseActive_ || !waiting_.empty())
            backend_.rejectOwned(actual_.key, reason);
        throw std::runtime_error("Owned parent bridge refused; guest stays held");
    }
    void opaque(uint32_t byteOffset, uint32_t bytes) {
        for (uint32_t w = byteOffset; w < byteOffset + bytes; ++w)
            opaqueContext_.set(w);
    }
    void publishScalar(const Mailbox& m, uint8_t* ram, R5900Context& ctx) {
        // Headers/footer are VIF/DMA control, not F80 graphical payload. FP/VU0 and
        // graphical GPR temporaries stay in the opaque GPU context lease.
        std::memcpy(ram + actual_.packet, m.words.data() + 12, 32);
        std::memcpy(ram + actual_.packet + 0xfa0u, m.words.data() + 20, 16);
        for (unsigned i = 0; i < 3; ++i)
            std::memcpy(&ctx.r[16 + i], m.words.data() + 24 + i * 4, 16);
        std::memcpy(&ctx.r[31], m.words.data() + 36, 8);
        std::memcpy(&ctx.r[29], m.words.data() + 38, 8);
        std::memcpy(&ctx.r[2], m.words.data() + 40, 8);
        std::memcpy(&ctx.r[3], m.words.data() + 42, 8);
        ctx.branch_pc = m.words[9];
        std::memcpy(reinterpret_cast<uint8_t*>(&ctx) + offsetof(R5900Context, in_delay_slot),
                    &m.words[10], 4);
        ctx.pc = m.words[6];
    }
    // Service-only source policy. These bytes are integer lease metadata;
    // no caller GPR/FPR/VF value is inspected or copied by the Bridge.
    struct ContextLoan {
        const Bridge* issuer = nullptr;
        Allocation actual;
        Produced produced;
        Phase phase = Phase::Retired;
        std::bitset<1648> opaque;
        bool contextLeaseActive = false, owns = false;
        R5900Context* child = nullptr;
    };
    std::vector<Range> contextOpaqueSpans(const R5900Context& ctx) const {
        std::vector<Range> result;
        if (!hasContextLeaseFor(ctx))
            return result;
        for (uint32_t b = 0; b < 1648u;) {
            if (!opaqueContext_.test(b)) {
                ++b;
                continue;
            }
            uint32_t end = b + 1;
            while (end < 1648u && opaqueContext_.test(end))
                ++end;
            result.push_back({Space::Context, b, end - b});
            b = end;
        }
        return result;
    }
    ContextLoan prepareContextLoan(R5900Context& caller, R5900Context& child, int32_t task) const {
        if (&caller == &child || task < 1 || phase_ == Phase::Submitted || !waiting_.empty() ||
            (contextLeaseActive_ && (&caller != actual_.context || actual_.task != task)))
            throw std::invalid_argument(
                "Context loan overtook an actual held parent/upload or changed task");
        return {this,  actual_, produced_, phase_, opaqueContext_, contextLeaseActive_,
                owns_, &child};
    }
    void activateContextLoan(const ContextLoan& loan, int32_t task) {
        if (loan.issuer != this || !loan.child || phase_ == Phase::Submitted || !waiting_.empty())
            throw std::invalid_argument("Context loan is not the exact retired parent prefix");
        if (contextLeaseActive_) {
            actual_.context = loan.child;
            actual_.task = task;
        }
    }
    template <class ControlPatch>
    void clearLoanControlBytes(const ContextLoan& loan, const std::vector<ControlPatch>& controls) {
        if (loan.issuer != this || !loan.child)
            throw std::invalid_argument("Foreign callback control loan");
        for (const auto& c : controls) {
            if (c.at >= 1648u || !c.bytes || c.bytes > 1648u - c.at)
                throw std::invalid_argument("Callback control mask exceeds Context");
            for (uint32_t b = 0; b < c.bytes; ++b)
                opaqueContext_.reset(c.at + b);
        }
    }
    void restoreContextLoan(const ContextLoan& loan) {
        if (loan.issuer != this || !loan.child || phase_ == Phase::Submitted || !waiting_.empty())
            throw std::runtime_error(
                "Callback Context restore preceded real child parent/upload retirement");
        // RAM/SPR side effects, scalar writer revisions and all monotonic
        // allocation/submission/retirement counters remain globally ordered.
        actual_ = loan.actual;
        produced_ = loan.produced;
        phase_ = loan.phase;
        opaqueContext_ = loan.opaque;
        contextLeaseActive_ = loan.contextLeaseActive;
        owns_ = loan.owns;
    }

    ContextLoan prepareValidatedFreshContextLoan(R5900Context& caller, R5900Context& child,
                                                 int32_t task) const {
        // Service-only, after its exact IrqContextPause retired-prefix
        // certificate. Keep outstanding main receipt/upload objects intact.
        if (&caller == &child || task < 0 || (contextLeaseActive_ && actual_.context != &caller))
            throw std::invalid_argument(
                "Fresh IRQ Context loan lacks genuine distinct caller/initializer");
        return {this,  actual_, produced_, phase_, opaqueContext_, contextLeaseActive_,
                owns_, &child};
    }
    void activateValidatedFreshContextLoan(const ContextLoan& loan, int32_t task) {
        if (loan.issuer != this || !loan.child || task < 0)
            throw std::invalid_argument("Fresh IRQ Context activation belongs to foreign loan");
        actual_.context = loan.child;
        actual_.task = task;
        opaqueContext_.reset();
        contextLeaseActive_ = true;
        // The held main phase is saved in loan. Fresh initializer controls are
        // CPU-owned until their exact GPU source effects are issued; waiting_
        // and every main payload/receipt remain untouched and globally ordered.
        phase_ = Phase::Retired;
    }
    void restoreValidatedFreshContextLoan(const ContextLoan& loan) {
        if (loan.issuer != this || !loan.child || actual_.context != loan.child ||
            phase_ == Phase::Submitted)
            throw std::runtime_error("Fresh IRQ return preceded its actual child retirement");
        actual_ = loan.actual;
        produced_ = loan.produced;
        phase_ = loan.phase;
        opaqueContext_ = loan.opaque;
        contextLeaseActive_ = loan.contextLeaseActive;
        owns_ = loan.owns;
    }

  public:
    bool hasContextLeaseFor(const R5900Context& ctx) const noexcept {
        return contextLeaseActive_ && &ctx == actual_.context;
    }
    AdmissionTier tier_ = AdmissionTier::ScopedLive;
    Bridge(Backend& b, const Gates& g = {}, AdmissionTier tier = AdmissionTier::ScopedLive)
        : backend_(b), gates_(g), tier_(tier) {}
    Entry allocated(const Allocation& a, const std::vector<RawPatch>& actualOrderedPatches) {
        if (tier_ == AdmissionTier::ScopedLive && !gates_.ready())
            return Entry::DeclinedBeforeOwnership;
        // The original game builds several parents before the later DMA chain.
        // Each completed payload is immutable; never serialize the next parent on
        // an UNPACK that the caller has not issued yet.
        if (owns_ && (phase_ == Phase::Returned || phase_ == Phase::UnpackJoined)) {
            if (waiting_.size() >= 4096)
                fail(93u);
            waiting_.push_back(
                {actual_, produced_, sealed_, unpackSealed_, phase_ == Phase::UnpackJoined});
            owns_ = false;
            phase_ = Phase::Retired;
        }
        if (owns_ && phase_ != Phase::Retired)
            fail(93u);
        if (contextLeaseActive_ && (a.context != actual_.context || a.task != actual_.task))
            fail(93u);
        for (const auto& w : waiting_)
            if (overlap(a.packet, PacketBytes, w.actual.packet, PacketBytes))
                fail(93u);
        if (!a.memory || !a.context || a.pc != 0x19bbfcu || !a.key.session || !a.key.epoch ||
            !a.key.allocation || !a.key.revision || !a.key.ordinal ||
            a.key.allocation <= lastAllocation_ || a.key.ordinal <= lastOrdinal_ ||
            a.context->pc != a.pc || raw32(&a.context->r[2]) != a.packet ||
            raw32(&a.context->r[29]) != a.frame)
            throw std::invalid_argument("No exact actual allocator-return identity");
        for (const auto& p : actualOrderedPatches) {
            const uint32_t limit = p.range.space == Space::Ram   ? RamBytes
                                   : p.range.space == Space::Spr ? 0x4000u
                                                                 : 1648u;
            if (!p.actualWriterOrdinal || p.bytes.size() != p.range.bytes ||
                !range(p.range.address, p.range.bytes, limit))
                throw std::invalid_argument("Not actual ordered raw source write");
            if (p.range.space == Space::Context)
                for (uint32_t w = p.range.address; w < p.range.address + p.range.bytes; ++w)
                    if (opaqueContext_.test(w))
                        throw std::runtime_error("Stale CPU word cannot reseed GPU context");
            if (p.range.space == Space::Ram)
                for (const auto& r : opaqueRam_)
                    if (overlap(p.range.address, p.range.bytes, r.address, r.bytes))
                        throw std::runtime_error(
                            "Stale CPU packet/stack bytes cannot reseed GPU RAM");
        }
        actual_ = a;
        phase_ = Phase::InputsFrozen;
        owns_ = true;
        lastAllocation_ = a.key.allocation;
        lastOrdinal_ = a.key.ordinal;
        unpackSealed_ = 0;
        try {
            produced_ = backend_.record(a, actualOrderedPatches);
        } catch (...) {
            fail(94u);
        }
        if (!same(produced_.key, a.key) || !produced_.immutableGpuPayload ||
            !produced_.gpuContextLease)
            fail(94u);
        phase_ = Phase::Recorded;
        try {
            sealed_ = backend_.submitAndHoldGuest(a, produced_);
        } catch (...) {
            fail(95u);
        }
        if (!sealed_)
            fail(95u);
        phase_ = Phase::Submitted;
        return Entry::GuestHeld; // PC remains19BBFC. No busy clear or IRQ delivery.
    }
    Entry completed(const Receipt& r, uint8_t* ram, R5900Context& ctx) {
        if (!owns_ || phase_ != Phase::Submitted || r.issuer_ != &backend_ ||
            !same(r.key_, actual_.key) || r.timeline_ < sealed_ || &ctx != actual_.context || !ram)
            fail(96u);
        const auto& m = r.mailbox_.words;
        if (r.sticky_ || m[0] != 0x504c4231u || m[1] != 1u ||
            m[2] != uint32_t(actual_.key.ordinal) || m[3] != uint32_t(actual_.key.ordinal >> 32) ||
            m[4] || m[5] != 1u || m[11] != 3u || m[8] != actual_.packet ||
            m[7] != actual_.frame + 0x70u || m[6] != m[36] || ctx.pc != 0x19bbfcu ||
            raw32(&ctx.r[29]) != actual_.frame)
            fail(97u);
        publishScalar(r.mailbox_, ram, ctx);
        // Union of source-written graphical/context residues. Scalar mailbox ranges
        // above remain CPU-coherent. No value-derived dirty inference is used.
        for (unsigned reg : {1u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u})
            opaque(reg * 16u, 8u);
        for (unsigned reg : {0u, 1u, 2u, 3u, 4u, 5u, 12u})
            opaque(uint32_t(offsetof(R5900Context, f)) + reg * 4u, 4u);
        opaque(uint32_t(offsetof(R5900Context, fcr31)), 4u);
        opaque(uint32_t(offsetof(R5900Context, vu0_vf)) + 4u * 16u, 9u * 16u);
        opaque(uint32_t(offsetof(R5900Context, vu0_acc)), 16u);
        opaque(uint32_t(offsetof(R5900Context, vu0_q)), 4u);
        opaque(uint32_t(offsetof(R5900Context, vu0_info)), 4u);
        markOpaqueRam(actual_.packet + PayloadOffset, PayloadBytes);
        //199A90's96-byte private stack writes are GPU-generated. Parent saved
        //callee GPR metadata at frame..frame+70 remains source-preserved on CPU.
        markOpaqueRam(actual_.frame - 0x60u, 0x60u);
        contextLeaseActive_ = true;
        phase_ = Phase::Returned;
        return Entry::ScalarReturned;
    }
    void beforeContextAccess(R5900Context& ctx, uint32_t byteOffset, uint32_t bytes, uint32_t pc) {
        if (!contextLeaseActive_ || &ctx != actual_.context)
            return;
        if (!range(byteOffset, bytes, 1648u))
            fail(98u);
        for (uint32_t w = byteOffset; w < byteOffset + bytes; ++w)
            if (opaqueContext_.test(w)) {
                backend_.observedBypass(actual_, Space::Context, byteOffset, bytes, pc);
                fail(98u);
            }
    }
    void actualRawContextOverwrite(R5900Context& ctx, const RawPatch& patch,
                                   bool exactReviewedControlOrAssetSite) {
        if (!contextLeaseActive_ || &ctx != actual_.context)
            return;
        if (patch.kind != SourcePatchKind::ReviewedRaw || !exactReviewedControlOrAssetSite ||
            phase_ == Phase::Submitted || patch.range.space != Space::Context ||
            !patch.actualWriterOrdinal || patch.bytes.size() != patch.range.bytes ||
            !range(patch.range.address, patch.range.bytes, 1648u)) {
            backend_.observedBypass(actual_, Space::Context, patch.range.address, patch.range.bytes,
                                    patch.actualPC);
            fail(98u);
        }
        // The caller invokes this BEFORE the ordinary scalar/asset raw store. Its
        // RHS must already have passed every opaque-read guard. Never bless an FP
        // or graphics arithmetic site from its resulting byte value.
        try {
            backend_.recordActualRawContextOverwrite(actual_, patch);
        } catch (...) {
            fail(98u);
        }
        for (uint32_t w = patch.range.address; w < patch.range.address + patch.range.bytes; ++w)
            opaqueContext_.reset(w);
    }
    void beforeRawRamRead(uint32_t at, uint32_t bytes, uint32_t pc) {
        for (const auto& r : opaqueRam_)
            if (overlap(at, bytes, r.address, r.bytes)) {
                backend_.observedBypass(actual_, Space::Ram, at, bytes, pc);
                fail(99u);
            }
    }
    void actualRawRamOverwrite(const RawPatch& patch, bool exactReviewedControlOrAssetSite) {
        if (patch.kind != SourcePatchKind::ReviewedRaw || !exactReviewedControlOrAssetSite ||
            phase_ == Phase::Submitted || patch.range.space != Space::Ram ||
            !patch.actualWriterOrdinal || patch.bytes.size() != patch.range.bytes ||
            !range(patch.range.address, patch.range.bytes, RamBytes))
            fail(99u);
        for (const auto& w : waiting_)
            if (overlap(patch.range.address, patch.range.bytes, w.actual.packet + PayloadOffset,
                        PayloadBytes))
                fail(99u);
        if (owns_ && phase_ != Phase::Retired &&
            overlap(patch.range.address, patch.range.bytes, actual_.packet + PayloadOffset,
                    PayloadBytes))
            fail(99u);
        auto next = clearedOpaqueRam(patch.range.address, patch.range.bytes);
        try {
            backend_.recordActualRawRamOverwrite(actual_, patch);
        } catch (...) {
            fail(99u);
        }
        opaqueRam_.swap(next);
    }
    void beforeSourceWrite(Space space, uint32_t address, uint32_t bytes, uint32_t pc) {
        for (const auto& r : opaqueRam_)
            if (space == Space::Ram && overlap(address, bytes, r.address, r.bytes)) {
                backend_.observedBypass(actual_, space, address, bytes, pc);
                fail(99u);
            }
        if (!owns_ && waiting_.empty())
            return;
        for (const auto& w : waiting_)
            if (space == Space::Ram &&
                overlap(address, bytes, w.actual.packet + PayloadOffset, PayloadBytes)) {
                backend_.observedBypass(w.actual, space, address, bytes, pc);
                backend_.rejectOwned(w.actual.key, 99u);
                fail(99u);
            }
        if (space == Space::Ram &&
            overlap(address, bytes, actual_.packet + PayloadOffset, PayloadBytes)) {
            backend_.observedBypass(actual_, space, address, bytes, pc);
            fail(99u);
        }
        if (phase_ == Phase::Submitted) {
            backend_.observedBypass(actual_, space, address, bytes, pc);
            fail(99u);
        }
    }
    void originalUnpack(uint32_t command, uint32_t tops, const std::vector<Origin>& origins) {
        if (command != 0x6cf80000u || tops > 1023u || origins.empty())
            fail(100u);
        Waiting* old = nullptr;
        const Allocation* a = &actual_;
        const Produced* token = &produced_;
        if (!owns_ || phase_ != Phase::Returned || !same(origins.front().key, actual_.key)) {
            for (auto& w : waiting_)
                if (!w.joined && same(w.actual.key, origins.front().key)) {
                    old = &w;
                    break;
                }
            if (!old)
                fail(100u);
            a = &old->actual;
            token = &old->produced;
        }
        uint64_t cursor = 0;
        for (const auto& s : origins) {
            if (s.scratch || !s.bytes || s.offset != cursor ||
                s.address != uint64_t(a->packet) + PayloadOffset + cursor || !same(s.key, a->key) ||
                s.bytes > PayloadBytes - cursor)
                fail(100u);
            cursor += s.bytes;
        }
        if (cursor != PayloadBytes)
            fail(100u);
        try {
            backend_.recordActualUnpack(*token, command, tops, origins);
        } catch (...) {
            fail(100u);
        }
        if (old)
            old->joined = true;
        else
            phase_ = Phase::UnpackJoined;
    }
    void unpackSubmitted(const Key& key, uint64_t actualTimeline) {
        if (owns_ && same(key, actual_.key)) {
            if (phase_ != Phase::UnpackJoined || unpackSealed_ || actualTimeline <= sealed_)
                fail(101u);
            unpackSealed_ = actualTimeline;
            return;
        }
        for (auto& w : waiting_)
            if (same(key, w.actual.key)) {
                if (!w.joined || w.unpackTimeline || actualTimeline <= w.parentTimeline)
                    fail(101u);
                w.unpackTimeline = actualTimeline;
                return;
            }
        fail(101u);
    }
    void retire(const Key& key, uint64_t actualCompletedTimeline) {
        if (owns_ && same(key, actual_.key)) {
            if (phase_ != Phase::UnpackJoined || !unpackSealed_ ||
                actualCompletedTimeline < unpackSealed_)
                fail(101u);
            retired_ = actualCompletedTimeline;
            phase_ = Phase::Retired;
            return;
        }
        for (auto i = waiting_.begin(); i != waiting_.end(); ++i)
            if (same(key, i->actual.key)) {
                if (!i->joined || !i->unpackTimeline || actualCompletedTimeline < i->unpackTimeline)
                    fail(101u);
                waiting_.erase(i);
                retired_ = actualCompletedTimeline;
                return;
            }
        fail(101u);
    }
    void requireRetiredGsEpochCarry(uint64_t newerEpoch, uint64_t actuallyCompletedTimeline) const {
        if (!waiting_.empty() || phase_ == Phase::Failed ||
            (owns_ && (phase_ != Phase::Retired || actuallyCompletedTimeline < retired_ ||
                       newerEpoch <= actual_.key.epoch)))
            throw std::runtime_error("GS epoch carry requires actual parent and upload retirement");
    }
    void reset(uint64_t newerEpoch, uint64_t actuallyCompletedTimeline,
               bool actualColdOrGpuCoherentContext) {
        if (!waiting_.empty() ||
            (owns_ && (phase_ != Phase::Retired || actuallyCompletedTimeline < retired_ ||
                       newerEpoch <= actual_.key.epoch)))
            fail(102u);
        produced_ = {};
        owns_ = false;
        if (actualColdOrGpuCoherentContext) {
            opaqueContext_.reset();
            opaqueRam_.clear();
            contextLeaseActive_ = false;
        }
        // GS-only reset retains opaque CPU word guards. No stale CPU reseed.
    }
    Phase phase() const {
        return phase_;
    }
    static constexpr bool CanonicalInstalled = false;
};
} // namespace reo_parent_live
