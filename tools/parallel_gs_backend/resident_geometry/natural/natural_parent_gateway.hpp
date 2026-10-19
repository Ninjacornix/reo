#pragma once
#include "typed_origin_transport.hpp"
#include <optional>
#include <atomic>
namespace reo_resident_live {
class ParallelArrayOwner;
}

namespace reo_parent_natural {
class NativeTarget;
// This gateway deliberately has no source snapshot/reseed method. Its caller
// must supply actual ordered raw-writer patches from a certified producer.
// Code pins/proof gates and live hooks are still false in this source overlay.
template <class ActualService> class Gateway final {
    ActualService& service_;
    const void* actualMemory_ = nullptr;
    R5900Context* actualContext_ = nullptr;
    uint64_t session_ = 0, epoch_ = 0, allocations_ = 0, ordinals_ = 0, revision_ = 1;
    std::atomic<bool> failed_{false};
    struct Pending {
        uint32_t frame = 0, descriptor = 0, outerReturn = 0;
        int32_t task = -1;
    };
    std::optional<Pending> allocator_;
    TypedOrigins origins_;
    void requireHealthy() const {
        if (failed_)
            throw std::runtime_error("Natural source hook is sticky-failed");
        service_.requireHealthy();
    }
    static uint64_t increment(uint64_t& counter) {
        if (counter == UINT64_MAX)
            throw std::overflow_error("Actual source chronology exhausted");
        return ++counter;
    }
    friend class NativeTarget;
    class EpochCarry final {
        friend class Gateway;
        const Gateway* issuer_;
        uint64_t oldEpoch_, newEpoch_, revision_, allocations_, ordinals_;
        TypedOrigins::EpochCarry origins_;
        EpochCarry(const Gateway* issuer, uint64_t oldEpoch, uint64_t newEpoch, uint64_t revision,
                   uint64_t allocations, uint64_t ordinals, TypedOrigins::EpochCarry origins)
            : issuer_(issuer), oldEpoch_(oldEpoch), newEpoch_(newEpoch), revision_(revision),
              allocations_(allocations), ordinals_(ordinals), origins_(std::move(origins)) {}

      public:
        EpochCarry(const EpochCarry&) = delete;
        EpochCarry(EpochCarry&&) = default;
    };
    EpochCarry prepareGsEpochCarry(uint64_t newEpoch) const {
        requireHealthy();
        if (newEpoch <= epoch_ || allocator_)
            throw std::runtime_error("GS source epoch carry overtook an original allocation");
        return EpochCarry(this, epoch_, newEpoch, revision_, allocations_, ordinals_,
                          origins_.prepareGsEpochCarry(newEpoch));
    }
    bool consumeGsEpochCarry(EpochCarry& carry) noexcept {
        if (carry.issuer_ != this || carry.oldEpoch_ != epoch_ || carry.revision_ != revision_ ||
            carry.allocations_ != allocations_ || carry.ordinals_ != ordinals_ || allocator_ ||
            failed_.load(std::memory_order_acquire) ||
            !origins_.consumeGsEpochCarry(carry.origins_))
            return false;
        epoch_ = carry.newEpoch_;
        carry.issuer_ = nullptr;
        return true;
    }
    class WriterCompletion final {
        friend class Gateway;
        const Gateway* issuer_;
        uint64_t revision_, session_, epoch_;
        bool consumed_ = false;
        WriterCompletion(const Gateway* issuer, uint64_t revision, uint64_t session, uint64_t epoch)
            : issuer_(issuer), revision_(revision), session_(session), epoch_(epoch) {}

      public:
        WriterCompletion(const WriterCompletion&) = delete;
    };
    WriterCompletion prepareCertifiedControlWriterCompletion() const {
        requireHealthy();
        if (revision_ == UINT64_MAX)
            throw std::overflow_error(
                "Actual certified control writer revision exhausted before store");
        return WriterCompletion(this, revision_, session_, epoch_);
    }
    bool consumeCertifiedControlWriterCompletion(WriterCompletion& token) noexcept {
        // Private issuer/revision/session/epoch capability. Source+protocol
        // locks span reservation/store/consume. Never silently wrap or publish
        // a successor if this terminal owned completion contract is broken.
        if (token.issuer_ != this || token.consumed_ || token.revision_ != revision_ ||
            token.session_ != session_ || token.epoch_ != epoch_ || revision_ == UINT64_MAX ||
            failed_.load(std::memory_order_acquire)) {
            failed_.store(true, std::memory_order_release);
            return false;
        }
        token.consumed_ = true;
        ++revision_;
        return true;
    }

  public:
    static constexpr bool SourceWriterCoverageCertified = false;
    static constexpr bool GeneratedDirectContextCoverageCertified = false;
    static constexpr bool ParserLiteralProvenanceInstalled = false;
    static constexpr bool ProductionActivation = false;
    Gateway(ActualService& service, const void* ramIdentity, R5900Context& actualContext,
            uint64_t actualFactorySession, uint64_t actualOwnerEpoch)
        : service_(service), actualMemory_(ramIdentity), actualContext_(&actualContext),
          session_(actualFactorySession), epoch_(actualOwnerEpoch),
          origins_(ramIdentity, actualFactorySession, actualOwnerEpoch) {
        if (!ramIdentity || !session_ || !epoch_)
            throw std::invalid_argument("Actual factory identity missing");
    }
    Gateway(const Gateway&) = delete;
    Gateway& operator=(const Gateway&) = delete;

    // Called at the original allocator entry after the caller JAL delay slot,
    // before18DDD0 modifies SP or argument GPRs. Scheduler supplies task ID
    // directly; never copy an opaque1648B context merely to call GetThreadId.
    void beforeActualAllocator(const uint8_t* ram, R5900Context& ctx, int32_t actualTask) {
        requireHealthy();
        if (&ctx != actualContext_ || ram != actualMemory_ || ctx.pc != 0x18ddd0u ||
            protocol::raw32(&ctx.r[4]) != protocol::PacketBytes ||
            protocol::raw32(&ctx.r[5]) != 16u || protocol::raw32(&ctx.r[31]) != 0x19bbfcu ||
            actualTask < 1 || allocator_)
            throw std::invalid_argument("Not a genuine scoped parent allocator call");
        const uint32_t frame = protocol::raw32(&ctx.r[29]),
                       descriptor = protocol::raw32(&ctx.r[18]);
        if (frame < 0x60u || ((frame | descriptor) & 15u) ||
            !protocol::range(frame - 0x60u, 0xd0u, protocol::RamBytes) ||
            !protocol::range(descriptor, 0x180u, protocol::RamBytes))
            throw std::invalid_argument("Actual parent allocator stack/descriptor outside RAM");
        service_.hookProtocol().beforeRawRamRead(frame + 0x30u, 4u, ctx.pc);
        allocator_ = Pending{frame, descriptor, protocol::raw32(ram + frame + 0x30u), actualTask};
    }

    // At the real19BBFC continuation BEFORE its first original packet write.
    // Allocation/revision/ordinal are minted from this actual callback sequence;
    // no caller-supplied allocation key, pointer reuse or payload equality.
    protocol::Allocation prepareActualAllocatorReturn(uint8_t* ram, R5900Context& ctx,
                                                      int32_t actualTask) {
        requireHealthy();
        if (!allocator_ || &ctx != actualContext_ || ram != actualMemory_ || ctx.pc != 0x19bbfcu ||
            actualTask != allocator_->task || protocol::raw32(&ctx.r[29]) != allocator_->frame ||
            protocol::raw32(&ctx.r[18]) != allocator_->descriptor ||
            protocol::raw32(&ctx.r[31]) != 0x19bbfcu)
            throw std::invalid_argument("Allocator completion lacks its original parent join");
        const auto p = *allocator_;
        const uint32_t packet = protocol::raw32(&ctx.r[2]);
        if ((packet & 15u) || !protocol::range(packet, protocol::PacketBytes, protocol::RamBytes))
            throw std::invalid_argument("Actual allocator did not return the bounded packet");
        service_.hookProtocol().beforeRawRamRead(p.frame + 0x30u, 4u, ctx.pc);
        service_.hookProtocol().beforeRawRamRead(p.descriptor + 0x54u, 4u, ctx.pc);
        if (protocol::raw32(ram + p.frame + 0x30u) != p.outerReturn)
            throw std::invalid_argument(
                "Parent saved return changed during its original allocation");
        protocol::Allocation a{
            {session_, epoch_, increment(allocations_), revision_, increment(ordinals_)},
            ram,
            &ctx,
            ctx.pc,
            packet,
            p.frame,
            p.descriptor,
            protocol::raw32(ram + p.descriptor + 0x54u),
            actualTask};
        // Check the original descriptor indirection and source ranges before
        // GPU ownership. This validation reads scalar pointers only.
        service_.hookProtocol().beforeRawRamRead(p.descriptor + 0x4cu, 4u, ctx.pc);
        protocol::sourceRanges(a, ram);
        allocator_.reset();
        return a;
    }
    bool recordActualParentOnOwner(const protocol::Allocation& a,
                                   const std::vector<protocol::RawPatch>& patches) {
        requireHealthy();
        try {
            const auto entry = service_.allocateAtActualFrontier(a, patches);
            if (entry == protocol::Entry::DeclinedBeforeOwnership)
                return false;
            if (entry != protocol::Entry::GuestHeld)
                throw std::runtime_error("Owner did not hold genuine T1");
            return true;
        } catch (...) {
            failed_ = true;
            throw;
        }
    }
    using ReturnTicket = std::shared_ptr<const typename ActualService::ParentReturn>;
    ReturnTicket waitActualParentOnOwner(const protocol::Key& key) {
        requireHealthy();
        return service_.waitActualParentOnOwner(key);
    }
    void commitActualParentOnEe(const protocol::Allocation& a, const ReturnTicket& ticket,
                                uint8_t* ram, R5900Context& ctx) {
        requireHealthy();
        if (!ticket || !protocol::same(ticket->key(), a.key))
            throw std::invalid_argument("Parent EE ticket lost exact source key");
        try {
            if (service_.commitActualParentOnEe(ticket, ram, ctx) !=
                protocol::Entry::ScalarReturned)
                throw std::runtime_error("Actual T1 did not return its EE scalar mailbox");
            origins_.publishAfterT1(a);
        } catch (...) {
            failed_ = true;
            throw;
        }
    }

    // This event belongs AFTER a successful actual reviewed raw store. It is a
    // chronology counter only. It cannot lift an opaque guard or seed data.
    void prepareActualRawWriterCompletion() const {
        requireHealthy();
        if (revision_ == UINT64_MAX)
            throw std::overflow_error("Actual writer revision exhausted before store");
    }
    void actualRawWriterCompleted() {
        requireHealthy();
        increment(revision_);
    }

    void beforeRamRead(uint32_t physical, uint32_t bytes, uint32_t pc) {
        requireHealthy();
        service_.hookProtocol().beforeRawRamRead(physical, bytes, pc);
    }
    void beforeSourceWrite(protocol::Space space, uint32_t physical, uint32_t bytes, uint32_t pc) {
        requireHealthy();
        service_.hookProtocol().beforeSourceWrite(space, physical, bytes, pc);
    }
    void beforeContextReadOrUnknownWrite(R5900Context& ctx, uint32_t offset, uint32_t bytes,
                                         uint32_t pc) {
        requireHealthy();
        service_.hookProtocol().beforeContextAccess(ctx, offset, bytes, pc);
    }
    // Bridge verifies the actual reviewed RAW overwrite and orders it on the
    // same Device before lifting a guard. Arithmetic output never uses this API.
    void beforeReviewedRawContextOverwrite(R5900Context& ctx, const protocol::RawPatch& actualPatch,
                                           bool exactSourceReviewedScalarOrAssetSite) {
        requireHealthy();
        service_.hookProtocol().actualRawContextOverwrite(ctx, actualPatch,
                                                          exactSourceReviewedScalarOrAssetSite);
    }
    void beforeReviewedRawRamOverwrite(const protocol::RawPatch& actualPatch,
                                       bool exactSourceReviewedScalarOrAssetSite) {
        requireHealthy();
        service_.hookProtocol().actualRawRamOverwrite(actualPatch,
                                                      exactSourceReviewedScalarOrAssetSite);
    }

    TypedOrigins& origins() {
        requireHealthy();
        return origins_;
    }

    // The actual parser invokes this before its existing raw UNPACK path. Only
    // Service.joinActualUnpack mints a token retaining the genuine GPU lease.
    auto joinOriginalOpaqueUnpack(const TypedOrigins::Tape& tape, uint32_t offset, uint32_t bytes,
                                  uint32_t command, uint32_t tops, uint32_t cycle, uint32_t mode) {
        requireHealthy();
        const auto source =
            origins_.exactParentUnpack(tape, offset, bytes, command, tops, cycle, mode);
        try {
            auto operation = service_.joinActualUnpack(command, tops, source);
            origins_.markJoined(source.front().key);
            return operation;
        } catch (...) {
            failed_ = true;
            throw;
        }
    }
    // Root must wire this callback ONLY from the actual owner's T2 retirement
    // path after Service has validated/waited/retired the real upload fence.
    // There is deliberately no public receipt number or Fence minting method.
    // An owner-only callback seam is still needed; arbitrary caller completion
    // cannot erase a source registry entry in this slice.
  private:
    friend class reo_resident_live::ParallelArrayOwner;
    friend class NativeTarget;
    void afterActualOwnerT2Retirement(const protocol::Key& key) {
        requireHealthy();
        origins_.retireAfterActualT2(key);
    }
};
} // namespace reo_parent_natural
