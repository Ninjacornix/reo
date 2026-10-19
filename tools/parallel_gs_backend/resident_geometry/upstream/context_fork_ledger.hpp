#pragma once
#include "upstream/effects_ledger.hpp"
#include "callback_context_handoff.hpp"
#include <algorithm>
namespace reo_context_handoff {
namespace protocol = reo_parent_live;
struct CpuSpan {
    uint32_t offset, bytes;
};
inline std::vector<CpuSpan> callerCpuOwnedSpans(const std::vector<protocol::Range>& opaque) {
    std::vector<std::pair<uint32_t, uint32_t>> intervals;
    for (const auto& r : opaque)
        if (r.space == protocol::Space::Context) {
            if (!r.bytes || r.address >= 1648u || r.bytes > 1648u - r.address)
                throw std::invalid_argument("Fork source Context span outside bank");
            intervals.emplace_back(r.address, r.address + r.bytes);
        }
    std::sort(intervals.begin(), intervals.end());
    std::vector<CpuSpan> result;
    uint32_t end = 0;
    for (const auto& r : intervals) {
        if (r.first > end)
            result.push_back({end, r.first - end});
        end = std::max(end, r.second);
    }
    if (end < 1648u)
        result.push_back({end, 1648u - end});
    return result;
}
inline void initializeCpuOwnedShadow(const R5900Context& caller, R5900Context& child,
                                     const std::vector<CpuSpan>& spans) {
    // The allocation's fresh bytes are retained for opaque ranges. There is
    // deliberately no whole-Context copy, numerical download or byte equality.
    const auto* src = reinterpret_cast<const uint8_t*>(&caller);
    auto* dst = reinterpret_cast<uint8_t*>(&child);
    for (const auto& s : spans) {
        if (!s.bytes || s.offset >= 1648u || s.bytes > 1648u - s.offset)
            throw std::invalid_argument("CPU-owned fork span outside actual Context");
        std::memcpy(dst + s.offset, src + s.offset, s.bytes);
    }
}
struct ControlPatch {
    uint32_t at, bytes, role;
    std::array<uint8_t, 8> value{};
};
inline std::vector<ControlPatch>
rpcControlPatches(const reo_parent_natural::RpcCallbackControls& c) {
    if (!c.entry || !c.returnSentinel)
        throw std::invalid_argument("Callback requires actual entry and return sentinel");
    std::vector<ControlPatch> out;
    out.reserve(7);
    const auto gpr = [&](uint32_t r, uint32_t v, uint32_t role) {
        ControlPatch p{r * 16u, 8u, role, {}};
        const uint64_t bits = uint64_t(int64_t(int32_t(v)));
        std::memcpy(p.value.data(), &bits, 8);
        out.push_back(p);
    };
    for (uint32_t k = 0; k < 4; ++k)
        gpr(4 + k, c.arguments[k], 7);
    if (c.stackTop)
        gpr(29, c.stackTop, 6);
    gpr(31, c.returnSentinel, 3);
    ControlPatch pc{uint32_t(offsetof(R5900Context, pc)), 4u, 3u, {}};
    std::memcpy(pc.value.data(), &c.entry, 4);
    out.push_back(pc);
    return out;
}
inline void applyCpuControlPatches(R5900Context& child, std::array<uint8_t, 1648>& roles,
                                   std::vector<protocol::Range>& opaque,
                                   const std::vector<ControlPatch>& patches) {
    auto next = opaque;
    for (const auto& p : patches) {
        if (!p.bytes || p.bytes > 8u || p.at >= 1648u || p.bytes > 1648u - p.at || p.role < 3u ||
            p.role > 7u)
            throw std::invalid_argument("Callback scalar patch is not bounded");
        next = reo_source_closure::subtractOpaque(next, {protocol::Space::Context, p.at, p.bytes});
    }
    auto* dst = reinterpret_cast<uint8_t*>(&child);
    for (const auto& p : patches) {
        std::memcpy(dst + p.at, p.value.data(), p.bytes);
        for (uint32_t b = 0; b < p.bytes; ++b)
            roles[p.at + b] = uint8_t(p.role);
    }
    opaque.swap(next);
}
} // namespace reo_context_handoff
