#pragma once
#include "parent_natural_runtime.h"
#include "pre_entry_heap_source_scope.hpp"
#include "parent/parent_bridge.hpp"
#include <optional>
namespace reo_parent_natural {
class RawWriterJournal final {
    friend class NativeTarget;
    const uint8_t* ram_;
    const std::vector<Site>& sites_;
    uint64_t next_ = 1;
    uint32_t bytes_ = 0;
    std::optional<reo_parent_live::RawPatch> prepared_;
    std::vector<reo_parent_live::RawPatch> committed_;
    static constexpr uint32_t MaxBytes = 1024u * 1024u;
    void prepareAuthenticatedPacketHeader(uint32_t at, const void* data, uint32_t n, uint32_t pc) {
        if (prepared_ || !data || n != 4u || (at & 3u) || (pc != 0x124e50u && pc != 0x124e58u) ||
            !reo_parent_live::range(at, n, reo_parent_live::RamBytes) || n > MaxBytes - bytes_ ||
            committed_.size() >= 32768 || next_ == UINT64_MAX)
            throw std::runtime_error(
                "Exact integer IRQ packet header journal is invalid/overlapping/exhausted");
        committed_.reserve(committed_.size() + 1);
        reo_parent_live::RawPatch patch{{reo_parent_live::Space::Ram, at, n}, next_, pc, {}};
        const auto* bytes = static_cast<const uint8_t*>(data);
        patch.bytes.assign(bytes, bytes + n);
        prepared_ = std::move(patch);
    }
    void prepareAuthenticatedHeapControl(uint32_t at, const void* data, uint32_t n, uint32_t pc) {
        const auto* site = originalHeapControlSite(pc);
        if (prepared_ || !site || !originalHeapControlDestination(*site, at) || !data || n != 4u ||
            (at & 3u) || !reo_parent_live::range(at, n, reo_parent_live::RamBytes) ||
            n > MaxBytes - bytes_ || committed_.size() >= 32768 || next_ == UINT64_MAX)
            throw std::runtime_error(
                "Exact original heap control journal is invalid/overlapping/exhausted");
        committed_.reserve(committed_.size() + 1);
        reo_parent_live::RawPatch patch{{reo_parent_live::Space::Ram, at, n}, next_, pc, {}};
        const auto* bytes = static_cast<const uint8_t*>(data);
        patch.bytes.assign(bytes, bytes + n);
        prepared_ = std::move(patch);
    }
    void prepareValidatedPoolControl(uint32_t at, const void* data, uint32_t n, uint32_t pc) {
        if (prepared_ || !data || (n != 1u && n != 4u) || !pc ||
            !reo_parent_live::range(at, n, reo_parent_live::RamBytes) || n > MaxBytes - bytes_ ||
            committed_.size() >= 32768 || next_ == UINT64_MAX)
            throw std::runtime_error(
                "Source-certified pool journal is exhausted or overlaps an unfinished writer");
        committed_.reserve(committed_.size() + 1);
        reo_parent_live::RawPatch patch{{reo_parent_live::Space::Ram, at, n}, next_, pc, {}};
        const auto* bytes = static_cast<const uint8_t*>(data);
        patch.bytes.assign(bytes, bytes + n);
        prepared_ = std::move(patch);
    }
    void prepareAuthenticatedContextWrite(uint32_t at, const void* data, uint32_t n, uint32_t pc,
                                          reo_parent_live::SourcePatchKind kind) {
        using K = reo_parent_live::SourcePatchKind;
        if ((kind != K::NativeScalar && kind != K::CpuNumeric) || prepared_ || !data || !n ||
            n > 16 || !pc || at >= 1648u || n > 1648u - at || n > MaxBytes - bytes_ ||
            committed_.size() >= 32768 || next_ == UINT64_MAX ||
            (kind == K::NativeScalar && (at != 32u || n != 16u)))
            throw std::runtime_error(
                "Authenticated Context journal lacks exact source/provenance/capacity");
        committed_.reserve(committed_.size() + 1);
        reo_parent_live::RawPatch patch{
            {reo_parent_live::Space::Context, at, n}, next_, pc, {}, kind};
        const auto* value = static_cast<const uint8_t*>(data);
        patch.bytes.assign(value, value + n);
        prepared_ = std::move(patch);
    }
    void prepareAuthenticatedIrqControl(SourceSpace space, uint32_t at, const void* data,
                                        uint32_t n, uint32_t pc) {
        if (prepared_ || !data || !n || n > 16u || !pc || space == SourceSpace::Spr ||
            n > MaxBytes - bytes_ || committed_.size() >= 32768 || next_ == UINT64_MAX)
            throw std::runtime_error(
                "Original CPU IRQ control journal lacks exact capacity/source");
        committed_.reserve(committed_.size() + 1);
        reo_parent_live::RawPatch patch{{static_cast<reo_parent_live::Space>(space), at, n},
                                        next_,
                                        pc,
                                        {},
                                        reo_parent_live::SourcePatchKind::IrqIntegerControl};
        const auto* value = static_cast<const uint8_t*>(data);
        patch.bytes.assign(value, value + n);
        prepared_ = std::move(patch);
    }
    void prepareValidatedContextControl(uint32_t at, const void* data, uint32_t n, uint32_t pc) {
        if (prepared_ || !data || !n || n > 8 || !pc || at >= 1648u || n > 1648u - at ||
            n > MaxBytes - bytes_ || committed_.size() >= 32768 || next_ == UINT64_MAX)
            throw std::runtime_error(
                "Validated control journal is exhausted or overlaps an unfinished writer");
        committed_.reserve(committed_.size() + 1);
        reo_parent_live::RawPatch patch{{reo_parent_live::Space::Context, at, n}, next_, pc, {}};
        const auto* bytes = static_cast<const uint8_t*>(data);
        patch.bytes.assign(bytes, bytes + n);
        prepared_ = std::move(patch);
    }

  public:
    RawWriterJournal(const void* actualRam, const std::vector<Site>& sites)
        : ram_(static_cast<const uint8_t*>(actualRam)), sites_(sites) {
        if (!ram_)
            throw std::invalid_argument("Writer journal has no actual cold RAM");
    }
    bool reviewed(SourceSpace space, uint32_t at, uint32_t n, uint32_t pc) const {
        if (!n || pc >= reo_parent_live::RamBytes - 3u)
            return false;
        uint32_t actualWord;
        std::memcpy(&actualWord, ram_ + pc, 4);
        for (const auto& s : sites_)
            if ((s.kind == Site::Kind::ScalarControl || s.kind == Site::Kind::RawAsset) &&
                s.pc == pc && s.word == actualWord && s.space == space && n <= s.bytes &&
                at >= s.begin && uint64_t(at) + n <= uint64_t(s.begin) + s.bytes)
                return true;
        return false; // Graphics-result bytes never become RAW from value similarity.
    }
    bool reviewedScalar(SourceSpace space, uint32_t at, uint32_t n, uint32_t pc) const {
        if (!n || pc >= reo_parent_live::RamBytes - 3u)
            return false;
        uint32_t actualWord;
        std::memcpy(&actualWord, ram_ + pc, 4);
        for (const auto& s : sites_)
            if (s.kind == Site::Kind::ScalarControl && s.pc == pc && s.word == actualWord &&
                s.space == space && n <= s.bytes && at >= s.begin &&
                uint64_t(at) + n <= uint64_t(s.begin) + s.bytes)
                return true;
        return false;
    }
    void prepare(SourceSpace space, uint32_t at, const void* data, uint32_t n, uint32_t pc) {
        if (prepared_ || !data || !reviewed(space, at, n, pc) || n > MaxBytes - bytes_ ||
            committed_.size() >= 32768 || next_ == UINT64_MAX)
            throw std::runtime_error(
                "Unknown/graphics raw source site or exhausted actual writer journal");
        const uint32_t limit = space == SourceSpace::Ram   ? reo_parent_live::RamBytes
                               : space == SourceSpace::Spr ? 0x4000u
                                                           : 1648u;
        if (!reo_parent_live::range(at, n, limit))
            throw std::out_of_range("Actual source store outside bank");
        committed_.reserve(committed_.size() + 1); // completion cannot allocate after the CPU store
        reo_parent_live::RawPatch p{
            {static_cast<reo_parent_live::Space>(space), at, n}, next_, pc, {}};
        const auto* b = static_cast<const uint8_t*>(data);
        p.bytes.assign(b, b + n);
        prepared_ = std::move(p);
    }
    const reo_parent_live::RawPatch& prepared() const {
        if (!prepared_)
            throw std::logic_error("Actual raw store was not prepared");
        return *prepared_;
    }
    bool hasCompleted() const noexcept {
        return !committed_.empty();
    }
    bool hasPrepared() const noexcept {
        return bool(prepared_);
    }
    void completed(SourceSpace space, uint32_t at, uint32_t n, uint32_t pc) {
        if (!prepared_ || prepared_->range.space != static_cast<reo_parent_live::Space>(space) ||
            prepared_->range.address != at || prepared_->range.bytes != n ||
            prepared_->actualPC != pc)
            throw std::runtime_error("Source store completion lost its exact prepared event");
        bytes_ += n;
        committed_.push_back(std::move(*prepared_));
        prepared_.reset();
        ++next_;
    }
    std::vector<reo_parent_live::RawPatch> takeAtActualFrontier() {
        if (prepared_)
            throw std::runtime_error("Parent frontier overtook an uncompleted actual store");
        auto out = std::move(committed_);
        committed_.clear();
        bytes_ = 0;
        return out;
    }
};
} // namespace reo_parent_natural
