#pragma once
#include "upstream/effects_packet.hpp"
#include "parent/parent_bridge.hpp"
#include <algorithm>
namespace reo_source_closure {
namespace protocol = reo_parent_live;
struct LedgerTransition {
    std::vector<protocol::Range> opaque;
    std::array<uint8_t, 1648> scalar{};
};
inline void normalizeOpaque(std::vector<protocol::Range>& rows) {
    std::sort(rows.begin(), rows.end(), [](const auto& a, const auto& b) {
        return a.space == b.space ? a.address < b.address : unsigned(a.space) < unsigned(b.space);
    });
    size_t out = 0;
    for (const auto& r : rows) {
        if (!r.bytes)
            continue;
        if (out && rows[out - 1].space == r.space &&
            uint64_t(r.address) <= uint64_t(rows[out - 1].address) + rows[out - 1].bytes) {
            auto& prior = rows[out - 1];
            prior.bytes = uint32_t(
                std::max(uint64_t(prior.address) + prior.bytes, uint64_t(r.address) + r.bytes) -
                prior.address);
        } else
            rows[out++] = r;
    }
    rows.resize(out);
}
inline std::vector<protocol::Range> subtractOpaque(const std::vector<protocol::Range>& old,
                                                   protocol::Range cut) {
    std::vector<protocol::Range> next;
    next.reserve(old.size() + 1);
    for (const auto& r : old) {
        if (r.space != cut.space ||
            !protocol::overlap(r.address, r.bytes, cut.address, cut.bytes)) {
            next.push_back(r);
            continue;
        }
        if (r.address < cut.address)
            next.push_back({r.space, r.address, cut.address - r.address});
        const auto end = uint64_t(r.address) + r.bytes, stop = uint64_t(cut.address) + cut.bytes;
        if (end > stop)
            next.push_back({r.space, uint32_t(stop), uint32_t(end - stop)});
    }
    return next;
}
// CPU interval operations process only source metadata. No numerical RAM/SPR
// or Context shadow is read, compared, reclassified or downloaded here.
inline LedgerTransition
prepareGpuEffects(const std::vector<protocol::Range>& old, const std::array<uint8_t, 1648>& scalar,
                  const reo_gpu_upstream::CompositionEffectsPacket& packet) {
    LedgerTransition next{old, scalar};
    next.opaque.reserve(old.size() + packet.dirty.size());
    for (const auto& d : packet.dirty) {
        if (d.space == uint32_t(Space::Context) && d.role == uint32_t(Role::PreservedIncomingLease))
            continue;
        next.opaque.push_back({protocol::Space(d.space), d.offset, d.bytes});
        if (d.space == uint32_t(Space::Context))
            std::fill(next.scalar.begin() + d.offset, next.scalar.begin() + d.offset + d.bytes, 0);
    }
    normalizeOpaque(next.opaque);
    return next;
}
inline LedgerTransition
prepareEeControlPublication(const std::vector<protocol::Range>& old,
                            const std::array<uint8_t, 1648>& scalar,
                            const reo_gpu_upstream::CompositionEffectsPacket& packet) {
    LedgerTransition next{old, scalar};
    for (const auto& c : packet.control) {
        next.opaque =
            subtractOpaque(next.opaque, {protocol::Space::Context, c.contextOffset, c.bytes});
        std::fill(next.scalar.begin() + c.contextOffset,
                  next.scalar.begin() + c.contextOffset + c.bytes, uint8_t(c.role));
    }
    return next;
}
inline bool scalarControlLane(const std::array<uint8_t, 1648>& roles, uint32_t offset,
                              uint32_t bytes) {
    if (!bytes || offset >= roles.size() || bytes > roles.size() - offset)
        return false;
    return std::all_of(roles.begin() + offset, roles.begin() + offset + bytes,
                       [](uint8_t role) { return role >= 3 && role <= 7; });
}
} // namespace reo_source_closure
