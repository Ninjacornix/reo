#pragma once
// Source-only successor to the diagnostic allocation-only sidecar. This class
// never reads the F80 payload and never mints a GPU upload token. The actual
// Service must first complete T1 before its adapter can publish a source range.
#include "parent/parent_bridge.hpp"
#include "parent/origin_tape.hpp"
#include <functional>
#include <limits>
#include <map>
#include <utility>

namespace reo_parent_natural {
namespace protocol = reo_parent_live;
template <class ActualService> class Gateway;

class TypedOrigins final {
    template <class ActualService> friend class Gateway;

  public:
    class Tape final {
        friend class TypedOrigins;
        std::shared_ptr<const void> issuer_;
        protocol::OriginTape origins_;
        Tape(std::shared_ptr<const void> issuer, protocol::OriginTape origins)
            : issuer_(std::move(issuer)), origins_(std::move(origins)) {}

      public:
        Tape(const Tape&) = default;
        Tape& operator=(const Tape&) = default;
        uint32_t bytes() const {
            return origins_.bytes();
        }
    };

  private:
    struct Published {
        protocol::Allocation allocation;
        bool joined = false;
    };
    const void* memory_ = nullptr;
    uint64_t session_ = 0, epoch_ = 0;
    // Independent opaque issuer identity, not a pointer/value-derived source
    // key. No public constructor or origin/key setter exists on Tape.
    std::shared_ptr<const void> issuer_ = std::make_shared<const uint8_t>(0);
    std::vector<Published> published_;
    struct Frozen {
        uint32_t bytes = 0;
        Tape tape;
    };
    std::map<const uint8_t*, Frozen> copied_;
    void check(const Tape& tape) const {
        if (tape.issuer_ != issuer_)
            throw std::invalid_argument("Foreign typed DMA tape issuer");
    }

    void publishAfterT1(const protocol::Allocation& a) {
        if (a.memory != memory_ || a.key.session != session_ || a.key.epoch != epoch_ ||
            !a.key.allocation || !a.key.revision || !a.key.ordinal ||
            !protocol::range(a.packet, protocol::PacketBytes, protocol::RamBytes))
            throw std::invalid_argument("Parent source publication has foreign identity");
        if (published_.size() >= 4096)
            throw std::overflow_error("Parent source registry requires genuine T2 retirement");
        for (const auto& p : published_)
            if (protocol::same(p.allocation.key, a.key) ||
                protocol::overlap(a.packet, protocol::PacketBytes, p.allocation.packet,
                                  protocol::PacketBytes))
                throw std::invalid_argument("Repeated or still-live parent source allocation");
        published_.push_back({a, false});
    }

  public:
    static constexpr bool NaturalHooksInstalled = false;
    static constexpr size_t MaxCopies = 128;
    TypedOrigins(const void* actualRamIdentity, uint64_t session, uint64_t epoch)
        : memory_(actualRamIdentity), session_(session), epoch_(epoch) {
        if (!memory_ || !session_ || !epoch_)
            throw std::invalid_argument("Typed DMA origin transport lacks actual owner identity");
    }
    TypedOrigins(const TypedOrigins&) = delete;
    TypedOrigins& operator=(const TypedOrigins&) = delete;

    // Freeze the exact original source key at the actual DMA read. Split raw
    // control/header spans from overlapping opaque F80 ranges. Scratchpad and
    // unowned source spans retain an empty key, never an inferred parent ID.
    Tape emptyTape() const {
        return Tape(issuer_, protocol::OriginTape{});
    }
    Tape slice(const Tape& source, uint32_t offset, uint32_t bytes) const {
        check(source);
        return Tape(issuer_, source.origins_.slice(offset, bytes));
    }
    Tape concatenate(const Tape& first, const Tape& second) const {
        check(first);
        check(second);
        return Tape(issuer_, protocol::OriginTape::concatenate(first.origins_, second.origins_));
    }
    Tape actualDmaRead(uint32_t address, uint32_t bytes, bool scratch) const {
        const uint32_t limit = scratch ? 0x4000u : protocol::RamBytes;
        if (!protocol::range(address, bytes, limit))
            throw std::out_of_range("Actual DMA source outside its real memory bank");
        protocol::OriginTape out;
        uint32_t cursor = 0;
        while (cursor < bytes) {
            const uint32_t current = address + cursor;
            uint32_t count = bytes - cursor;
            const Published* source = nullptr;
            if (!scratch) {
                for (const auto& p : published_) {
                    const uint32_t begin = p.allocation.packet + protocol::PayloadOffset;
                    const uint32_t end = begin + protocol::PayloadBytes;
                    if (current >= begin && current < end) {
                        if (p.joined)
                            throw std::runtime_error(
                                "Repeated DMA consumption of an already joined parent payload");
                        source = &p;
                        count = std::min(count, end - current);
                        break;
                    }
                    if (begin > current)
                        count = std::min(count, begin - current);
                }
            }
            out.appendActualDmaRead(cursor, current, count,
                                    source ? source->allocation.key : protocol::Key{}, scratch);
            cursor += count;
        }
        return Tape(issuer_, std::move(out));
    }

    // Copy only raw headers/commands/asset bytes into the parser's byte stream.
    // A leased slice gets deterministic padding without dereferencing its CPU
    // source. The same typed tape must reach UNPACK admission before any raw
    // lane copy, diagnostics hashing, or literal-command upload can read it.
    using RawReader = std::function<void(bool, uint32_t, uint8_t*, uint32_t)>;
    void appendParserBytes(std::vector<uint8_t>& destination, Tape& destinationOrigins,
                           uint32_t address, uint32_t bytes, bool scratch,
                           const RawReader& readRaw) const {
        if (!readRaw || destination.size() != destinationOrigins.bytes() ||
            destination.size() > UINT32_MAX || bytes > UINT32_MAX - destination.size())
            throw std::invalid_argument("DMA copied bytes and typed origin tape diverged");
        const auto source = actualDmaRead(address, bytes, scratch);
        const auto joined = concatenate(destinationOrigins, source);
        const size_t old = destination.size();
        destination.resize(old + bytes, 0u);
        for (const auto& span : source.origins_.spans())
            if (!span.key.allocation)
                readRaw(span.scratch, span.address, destination.data() + old + span.offset,
                        span.bytes);
        destinationOrigins = joined;
    }

    void bindActualCopiedStream(const void* memory, const uint8_t* actualCopiedBase,
                                uint32_t actualBytes, Tape origins) {
        check(origins);
        if (memory != memory_ || !actualCopiedBase || !actualBytes ||
            origins.bytes() != actualBytes || copied_.count(actualCopiedBase))
            throw std::invalid_argument("Typed DMA binding is foreign, duplicate or incomplete");
        if (copied_.size() >= MaxCopies)
            throw std::overflow_error("Typed DMA copies exhausted; no implicit source clear");
        copied_.emplace(actualCopiedBase, Frozen{actualBytes, std::move(origins)});
    }

    Tape consumeActualCopiedStream(const void* memory, const uint8_t* actualCopiedBase,
                                   uint32_t actualBytes) {
        auto found = copied_.find(actualCopiedBase);
        if (found == copied_.end() || memory != memory_ || found->second.bytes != actualBytes)
            throw std::invalid_argument("Missing, foreign or reused original DMA-origin binding");
        auto out = std::move(found->second.tape);
        copied_.erase(found);
        return out;
    }

    // Partial payload overlap always refuses before a raw parser consumer.
    // Exact UNPACK slices must retain every source byte and all five key fields.
    bool hasOpaque(const Tape& tape, uint32_t offset, uint32_t bytes) const {
        check(tape);
        const auto selected = tape.origins_.slice(offset, bytes);
        for (const auto& s : selected.spans())
            if (s.key.allocation)
                return true;
        return false;
    }
    void requireRaw(const Tape& tape, uint32_t offset, uint32_t bytes) const {
        if (hasOpaque(tape, offset, bytes))
            throw std::runtime_error("CPU parser tried to consume an opaque parent payload");
    }
    std::vector<protocol::Origin> exactParentUnpack(const Tape& tape, uint32_t offset,
                                                    uint32_t bytes, uint32_t command, uint32_t tops,
                                                    uint32_t cycle, uint32_t mode) const {
        if (bytes != protocol::PayloadBytes || command != 0x6cf80000u || tops > 1023u ||
            cycle != 0x0404u || mode)
            throw std::invalid_argument(
                "Opaque parent UNPACK is not the exact original 4/4 command");
        check(tape);
        auto selected = tape.origins_.slice(offset, bytes);
        const auto& spans = selected.spans();
        if (spans.empty())
            throw std::invalid_argument("Opaque UNPACK lost its immutable source origins");
        const Published* p = nullptr;
        for (const auto& candidate : published_)
            if (protocol::same(candidate.allocation.key, spans.front().key)) {
                p = &candidate;
                break;
            }
        if (!p || p->joined)
            throw std::invalid_argument("Opaque source is foreign or already consumed");
        uint32_t cursor = 0;
        for (const auto& s : spans) {
            if (s.scratch || !s.bytes || s.offset != cursor ||
                !protocol::same(s.key, p->allocation.key) ||
                s.address != p->allocation.packet + protocol::PayloadOffset + cursor ||
                s.bytes > bytes - cursor)
                throw std::invalid_argument(
                    "Opaque source slice has a gap, reordering or stale revision");
            cursor += s.bytes;
        }
        if (cursor != bytes)
            throw std::invalid_argument("Opaque source slice is truncated");
        return spans;
    }

  private:
    class EpochCarry final {
        friend class TypedOrigins;
        template <class ActualService> friend class Gateway;
        const TypedOrigins* issuer_;
        uint64_t oldEpoch_, newEpoch_;
        std::shared_ptr<const void> oldTapeIssuer_, newTapeIssuer_;
        EpochCarry(const TypedOrigins* issuer, uint64_t oldEpoch, uint64_t newEpoch,
                   std::shared_ptr<const void> oldIssuer, std::shared_ptr<const void> newIssuer)
            : issuer_(issuer), oldEpoch_(oldEpoch), newEpoch_(newEpoch),
              oldTapeIssuer_(std::move(oldIssuer)), newTapeIssuer_(std::move(newIssuer)) {}

      public:
        EpochCarry(const EpochCarry&) = delete;
        EpochCarry(EpochCarry&&) = default;
    };
    EpochCarry prepareGsEpochCarry(uint64_t newEpoch) const {
        if (newEpoch <= epoch_ || !published_.empty() || !copied_.empty())
            throw std::runtime_error("GS source epoch carry would discard unretired DMA origins");
        return EpochCarry(this, epoch_, newEpoch, issuer_, std::make_shared<const uint8_t>(0));
    }
    bool consumeGsEpochCarry(EpochCarry& carry) noexcept {
        if (carry.issuer_ != this || carry.oldEpoch_ != epoch_ || carry.oldTapeIssuer_ != issuer_ ||
            !carry.newTapeIssuer_ || !published_.empty() || !copied_.empty())
            return false;
        issuer_.swap(carry.newTapeIssuer_);
        epoch_ = carry.newEpoch_;
        carry.issuer_ = nullptr;
        return true;
    }
    void markJoined(const protocol::Key& key) {
        for (auto& p : published_)
            if (protocol::same(p.allocation.key, key)) {
                if (p.joined)
                    throw std::invalid_argument("Repeated parent upload source join");
                p.joined = true;
                return;
            }
        throw std::invalid_argument("No actual source for upload join");
    }
    void retireAfterActualT2(const protocol::Key& key) {
        for (auto i = published_.begin(); i != published_.end(); ++i)
            if (protocol::same(i->allocation.key, key)) {
                if (!i->joined)
                    throw std::invalid_argument("Parent source retired without actual upload join");
                published_.erase(i);
                return;
            }
        throw std::invalid_argument("Absent parent source retirement");
    }
};
} // namespace reo_parent_natural
