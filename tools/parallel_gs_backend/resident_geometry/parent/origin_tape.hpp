#pragma once
#include "parent_bridge.hpp"
#include <algorithm>
namespace reo_parent_live {
// Revision/epoch/ordinal are frozen when the real DMA reads the source, not
// later reconstructed by pointer/value equality. Header origins may have no
// parent key; only an exact F80 slice enters the parent bridge.
class OriginTape {
    uint32_t bytes_ = 0;
    std::vector<Origin> spans_;

  public:
    static constexpr size_t MaxSpans = 32768;
    explicit OriginTape(uint32_t bytes = 0) : bytes_(bytes) {}
    void appendActualDmaRead(uint32_t offset, uint32_t address, uint32_t bytes, const Key& key,
                             bool scratch) {
        if (!bytes || offset > bytes_ || bytes > UINT32_MAX - offset || spans_.size() >= MaxSpans)
            throw std::runtime_error("Actual DMA origin tape exhausted or discontinuous");
        spans_.push_back({offset, address, bytes, key, scratch});
        bytes_ = std::max(bytes_, offset + bytes);
    }
    OriginTape slice(uint32_t offset, uint32_t bytes) const {
        if (offset > bytes_ || bytes > bytes_ - offset)
            throw std::out_of_range("Origin slice outside real parser bytes");
        OriginTape out(bytes);
        for (const auto& s : spans_) {
            const uint64_t end = uint64_t(s.offset) + s.bytes, limit = uint64_t(offset) + bytes;
            if (end <= offset || s.offset >= limit)
                continue;
            const uint32_t low = std::max(s.offset, offset), high = uint32_t(std::min(end, limit));
            out.spans_.push_back(
                {low - offset, s.address + (low - s.offset), high - low, s.key, s.scratch});
        }
        return out;
    }
    static OriginTape concatenate(const OriginTape& a, const OriginTape& b) {
        if (b.bytes_ > UINT32_MAX - a.bytes_ || a.spans_.size() + b.spans_.size() > MaxSpans)
            throw std::overflow_error("Origin concatenate exhausted; no silent clear");
        OriginTape out(a.bytes_ + b.bytes_);
        out.spans_ = a.spans_;
        for (auto s : b.spans_) {
            s.offset += a.bytes_;
            out.spans_.push_back(s);
        }
        return out;
    }
    uint32_t bytes() const {
        return bytes_;
    }
    const std::vector<Origin>& spans() const {
        return spans_;
    }
};
} // namespace reo_parent_live
