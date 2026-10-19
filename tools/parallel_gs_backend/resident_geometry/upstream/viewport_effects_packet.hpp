#pragma once
#include "effects_packet.hpp"
#include "effects_ledger.hpp"
namespace reo_gpu_upstream {
struct ViewportParameters {
    Parameters call;
    uint32_t actualTask;
};
static_assert(sizeof(ViewportParameters) == 84);
constexpr uint32_t ViewportEffectsDirtyCapacity = 4096, ViewportEffectsControlCapacity = 128;
constexpr uint32_t ViewportEffectsWords =
    20 + ViewportEffectsDirtyCapacity * 6 + ViewportEffectsControlCapacity * 8;
constexpr uint32_t ViewportEffectsBytes = ViewportEffectsWords * 4;
constexpr uint32_t ViewportCarryWords = 20 + 1648 * 5 + 2048 * 7,
                   ViewportCarryBytes = ViewportCarryWords * 4;
constexpr uint32_t ViewportTransactionWords = 20 + 412 + 2048 * 2,
                   ViewportTransactionBytes = ViewportTransactionWords * 4;
constexpr uint32_t ViewportBundleMagic = 0x56504231, ViewportModuleCount = 11;
using ViewportEffectsPacket = CompositionEffectsPacket;
inline bool viewportEffectsEntry(uint32_t pc) {
    return pc == 0x18f7e0 || pc == 0x18f880 || pc == 0x18f970 || pc == 0x18fce0 || pc == 0x197490;
}
inline bool viewportEffectsSourcePc(uint32_t pc) {
    if (pc & 3)
        return false;
    return (pc >= 0x18f7e0 && pc <= 0x18fe1c) || (pc >= 0x191280 && pc <= 0x1912f4) ||
           (pc >= 0x191500 && pc <= 0x191520) || (pc >= 0x197490 && pc <= 0x19777c) ||
           (pc >= 0x18ddd0 && pc <= 0x18de3c) || (pc >= 0x18cfb0 && pc <= 0x18d15c) ||
           pc == 0x18dca0 || pc == 0x18dca8 || pc == 0x18dcac ||
           (pc >= 0x1a0d70 && pc <= 0x1a0d7c) || (pc >= 0x1a1330 && pc <= 0x1a1364);
}
inline bool viewportControlRange(const reo_source_closure::ControlWord& c) {
    using R = reo_source_closure::Role;
    if (!c.bytes || c.bytes > 16 || c.contextOffset >= ContextBytes ||
        c.bytes > ContextBytes - c.contextOffset)
        return false;
    const auto within = [&](uint32_t at, uint32_t n) {
        return c.contextOffset >= at && c.contextOffset + c.bytes <= at + n;
    };
    switch (R(c.role)) {
        case R::GenuineControlPc:
            return (c.contextOffset == offsetof(R5900Context, pc) && c.bytes == 4) ||
                   (c.contextOffset == offsetof(R5900Context, branch_pc) && c.bytes == 4) ||
                   within(31 * 16, 8);
        case R::GenuineControlFcr:
            return c.contextOffset == offsetof(R5900Context, fcr31) && c.bytes == 4 &&
                   (c.sourcePc == 0x18f824 || c.sourcePc == 0x18f83c || c.sourcePc == 0x18f854 ||
                    c.sourcePc == 0x18f85c || c.sourcePc == 0x18fbd8 || c.sourcePc == 0x18fc2c);
        case R::GenuineControlStack:
            return within(29 * 16, 8);
        case R::GenuineScalarReturn:
            return (c.contextOffset == offsetof(R5900Context, in_delay_slot) && c.bytes == 1) ||
                   (within(2 * 16, 8) && c.sourcePc == 0x197754);
        case R::GenuineControlPointer:
            switch (c.sourcePc) {
                case 0x197518:
                case 0x19752c:
                case 0x197744:
                    return within(4 * 16, 8);
                case 0x197520:
                case 0x197534:
                case 0x197734:
                case 0x19773c:
                    return within(5 * 16, 8);
                case 0x197738:
                case 0x19774c:
                    return within(7 * 16, 8);
                case 0x197740:
                    return within(6 * 16, 8);
                default:
                    return false;
            }
        default:
            return false;
    }
}
// Pure integer metadata decoding. Actual Output/Call/queue/allocator/fence
// capability and the retained incoming Context authority stay with Service.
inline ViewportEffectsPacket decodeViewportEffectsMetadata(
    const Parameters& p, uint32_t actualTask, std::span<const uint32_t, ReceiptWords> receipt,
    std::span<const uint32_t, 32> control, std::span<const uint32_t> words, uint32_t priorStage,
    uint32_t expectedBeforePc) {
    using namespace reo_source_closure;
    if (words.size() != ViewportEffectsWords || !viewportEffectsEntry(p.entry) || !actualTask ||
        p.reserved > 2)
        throw std::invalid_argument("Viewport effects allocation/profile differs");
    ViewportEffectsPacket out;
    std::memcpy(&out.header, words.data(), sizeof(out.header));
    const auto& h = out.header;
    const std::array<uint32_t, 8> stamp{p.sessionLo, p.sessionHi, p.epochLo,   p.epochHi,
                                        p.bankLo,    p.bankHi,    p.ordinalLo, p.ordinalHi};
    if (receipt[0] || receipt[1] != ReceiptMagic || receipt[2] != ReceiptVersion ||
        receipt[3] > 1 || control[0] || control[1] != 0x56504331 || control[2] != 1 ||
        control[3] > 2 || control[31] || h.status || h.magic != EffectsMagic ||
        h.version != EffectsVersion || h.committed != 1 || h.stamp != stamp ||
        h.originalEntry != p.entry || h.actualFinalPc != receipt[18] ||
        h.actualTask != actualTask || h.profile != 0x18f970 ||
        h.dirtyCapacity != ViewportEffectsDirtyCapacity ||
        h.controlCapacity != ViewportEffectsControlCapacity || h.dirtyCount > h.dirtyCapacity ||
        h.controlCount > h.controlCapacity || receipt[3] != (control[3] == 0 ? 1u : 0u) ||
        control[29] != priorStage + uint32_t(control[3] != 0) || !control[30] ||
        control[30] > 65536 || receipt[17] != expectedBeforePc)
        throw std::invalid_argument("Viewport exact whole-stage envelope refused");
    for (unsigned k = 0; k < 8; ++k)
        if (receipt[4 + k] != stamp[k] || control[4 + k] != stamp[k])
            throw std::invalid_argument("Viewport stage stamp differs");
    if (receipt[12] != p.entry || receipt[13] != p.returnPc || receipt[14] != p.a0 ||
        receipt[15] != p.a1 || receipt[16] != p.a2 || control[12] != p.entry ||
        control[13] != p.returnPc ||
        (control[3] == 0 ? (receipt[18] != p.returnPc || control[14] || control[15])
                         : receipt[18] != control[14]))
        throw std::invalid_argument("Viewport actual call/continuation differs");
    // No numerical unused arguments or clobbered scalar result may be downloaded.
    const uint32_t args = control[3] == 1 ? 2 : control[3] == 2 ? 4 : 0;
    for (uint32_t r = args; r < 4; ++r)
        if (control[16 + r * 2] || control[17 + r * 2])
            throw std::invalid_argument("Viewport unused argument is not a transport placeholder");
    if (control[3] == 0) {
        for (unsigned k = 24; k < 28; ++k)
            if (control[k])
                throw std::invalid_argument(
                    "Viewport unused final stack/link is not a placeholder");
    }
    if (!(control[3] == 0 && (p.entry == 0x18f880 || p.entry == 0x197490)) && control[28])
        throw std::invalid_argument("Viewport numerical v0 cannot be downloaded");
    out.dirty.resize(h.dirtyCount);
    out.control.resize(h.controlCount);
    std::array<const DirtySpan*, ContextBytes> authored{};
    for (uint32_t k = 0; k < h.dirtyCount; ++k) {
        auto& d = out.dirty[k];
        std::memcpy(&d, words.data() + 20 + k * 6, sizeof(d));
        const auto space = Space(d.space);
        const uint32_t cap = space == Space::Ram       ? RamBytes
                             : space == Space::Spr     ? SprBytes
                             : space == Space::Context ? ContextBytes
                                                       : 0;
        if (!cap || !d.bytes || d.offset >= cap || d.bytes > cap - d.offset ||
            !viewportEffectsSourcePc(d.sourcePc) || !d.sourceOrdinal ||
            d.sourceOrdinal > control[30] || d.role < 1 || d.role > 9 || d.role == 8 ||
            (space != Space::Context && d.role != 1 && d.role != 9) ||
            (space == Space::Context && d.role == 9))
            throw std::invalid_argument("Viewport dirty source span refused");
        for (uint32_t j = 0; j < k; ++j) {
            const auto& old = out.dirty[j];
            if (d.space == old.space && d.offset < old.offset + old.bytes &&
                old.offset < d.offset + d.bytes)
                throw std::invalid_argument("Viewport source spans overlap");
        }
        if (space == Space::Context)
            for (uint32_t b = d.offset; b < d.offset + d.bytes; ++b)
                authored[b] = &d;
    }
    bool pc = false;
    std::array<bool, ContextBytes> published{};
    constexpr uint32_t controls = 20 + ViewportEffectsDirtyCapacity * 6;
    for (uint32_t k = 0; k < h.controlCount; ++k) {
        auto& c = out.control[k];
        std::memcpy(&c, words.data() + controls + k * 8, sizeof(c));
        if (!viewportEffectsSourcePc(c.sourcePc) || !viewportControlRange(c))
            throw std::invalid_argument("Viewport scalar source role refused");
        for (uint32_t b = 0; b < c.bytes; ++b) {
            const auto at = c.contextOffset + b;
            const auto* d = authored[at];
            if (published[at] || !d || d->role != c.role || d->sourcePc != c.sourcePc)
                throw std::invalid_argument("Viewport scalar lacks authored exact source role");
            published[at] = true;
        }
        for (uint32_t b = c.bytes; b < 16; ++b)
            if ((c.bits[b / 4] >> ((b & 3) * 8)) & 255)
                throw std::invalid_argument("Viewport scalar padding differs");
        if (c.contextOffset == offsetof(R5900Context, pc))
            pc = c.bytes == 4 && c.role == uint32_t(Role::GenuineControlPc) &&
                 c.bits[0] == receipt[18];
        if (c.contextOffset == offsetof(R5900Context, fcr31) && c.bits[0] != receipt[19])
            throw std::invalid_argument("Viewport authored FCR differs");
    }
    for (uint32_t b = 0; b < ContextBytes; ++b)
        if (authored[b] && authored[b]->role >= 3 && authored[b]->role <= 7 && !published[b])
            throw std::invalid_argument("Viewport authored control absent");
    if (!pc)
        throw std::invalid_argument("Viewport actual stage PC absent");
    return out;
}
inline ViewportEffectsPacket decodeViewportEffects(const Call& call, uint32_t inputPhase,
                                                   std::span<const uint32_t, ReceiptWords> receipt,
                                                   std::span<const uint32_t, 32> control,
                                                   std::span<const uint32_t> words,
                                                   uint32_t priorStage, uint32_t expectedBeforePc) {
    auto p = parameters(call);
    p.reserved = inputPhase;
    return decodeViewportEffectsMetadata(p, uint32_t(call.task()), receipt, control, words,
                                         priorStage, expectedBeforePc);
}
// Incoming means the exact byte at original function entry, including a save
// that crossed multiple real helper returns. Reinstating its prior authority
// uses only the retained source ledger; no CPU numeric shadow is inspected.
inline reo_source_closure::LedgerTransition prepareViewportGpuEffects(
    const std::vector<reo_parent_live::Range>& old, const std::array<uint8_t, 1648>& scalar,
    const std::vector<reo_parent_live::Range>& atEntry,
    const std::array<uint8_t, 1648>& scalarAtEntry, const ViewportEffectsPacket& packet) {
    namespace sc = reo_source_closure;
    auto next = sc::prepareGpuEffects(old, scalar, packet);
    for (const auto& d : packet.dirty)
        if (d.space == uint32_t(sc::Space::Context) &&
            d.role == uint32_t(sc::Role::PreservedIncomingLease)) {
            next.opaque = sc::subtractOpaque(next.opaque,
                                             {reo_parent_live::Space::Context, d.offset, d.bytes});
            for (const auto& prior : atEntry)
                if (prior.space == reo_parent_live::Space::Context) {
                    const auto lo = std::max(prior.address, d.offset),
                               hi = std::min(prior.address + prior.bytes, d.offset + d.bytes);
                    if (lo < hi)
                        next.opaque.push_back({prior.space, lo, hi - lo});
                }
            std::copy(scalarAtEntry.begin() + d.offset, scalarAtEntry.begin() + d.offset + d.bytes,
                      next.scalar.begin() + d.offset);
        }
    sc::normalizeOpaque(next.opaque);
    return next;
}
} // namespace reo_gpu_upstream
