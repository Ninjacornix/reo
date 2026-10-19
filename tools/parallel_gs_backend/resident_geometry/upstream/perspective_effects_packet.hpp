#pragma once
#include "effects_packet.hpp"
#include "integer_controls.hpp"
namespace reo_gpu_upstream {
constexpr uint32_t PerspectiveEffectsDirtyCapacity = 512, PerspectiveEffectsControlCapacity = 128;
constexpr uint32_t PerspectiveEffectsWords =
    20 + PerspectiveEffectsDirtyCapacity * 6 + PerspectiveEffectsControlCapacity * 8;
constexpr uint32_t PerspectiveEffectsBytes = PerspectiveEffectsWords * 4;
// The common record shape allows the source ledger to retain each incoming
// lane's prior authority. This decoder has its own exact module/profile rules.
using PerspectiveEffectsPacket = CompositionEffectsPacket;
inline bool perspectiveEntry(uint32_t pc) {
    return pc == 0x18f710u || pc == 0x18f754u || pc == 0x18f75cu || pc == 0x1921b0u ||
           pc == 0x1921c8u || pc == 0x18f570u || pc == 0x18fdf0u;
}
inline bool perspectiveSourcePc(uint32_t pc) {
    if (pc & 3u)
        return false;
    return (pc >= 0x18f570u && pc <= 0x18f690u) || (pc >= 0x18f710u && pc <= 0x18f7d4u) ||
           (pc >= 0x18fdf0u && pc <= 0x18fe18u) || (pc >= 0x1921b0u && pc <= 0x1921e0u);
}
inline bool perspectiveControlRange(const reo_source_closure::ControlWord& c) {
    using R = reo_source_closure::Role;
    if (!c.bytes || c.bytes > 16 || c.contextOffset >= ContextBytes ||
        c.bytes > ContextBytes - c.contextOffset)
        return false;
    const auto within = [&](uint32_t at, uint32_t bytes) {
        return c.contextOffset >= at && c.contextOffset + c.bytes <= at + bytes;
    };
    switch (R(c.role)) {
        case R::GenuineControlPc:
            return (c.contextOffset == offsetof(R5900Context, pc) && c.bytes == 4) ||
                   (c.contextOffset == offsetof(R5900Context, branch_pc) && c.bytes == 4) ||
                   ((c.sourcePc == 0x18f7bcu || c.sourcePc == 0x1921d8u) && within(31 * 16, 8));
        case R::GenuineControlFcr:
            return c.contextOffset == offsetof(R5900Context, fcr31) && c.bytes == 4 &&
                   (c.sourcePc == 0x18f578u || c.sourcePc == 0x18f58cu || c.sourcePc == 0x18f5f4u ||
                    c.sourcePc == 0x18f774u || c.sourcePc == 0x18f778u || c.sourcePc == 0x18f798u ||
                    c.sourcePc == 0x18f7a0u || c.sourcePc == 0x18f7acu);
        case R::GenuineControlStack:
            return within(29 * 16, 8) && (c.sourcePc == 0x18f7d4u || c.sourcePc == 0x1921e0u);
        case R::GenuineScalarReturn:
            return c.contextOffset == offsetof(R5900Context, in_delay_slot) && c.bytes == 1;
        case R::GenuineControlPointer:
            switch (c.sourcePc) {
                case 0x18f724u:
                    return within(5 * 16, 8);
                case 0x18f72cu:
                    return within(16 * 16, 8);
                case 0x18f730u:
                case 0x18f758u:
                case 0x1921c4u:
                    return within(4 * 16, 8);
                case 0x1921b4u:
                    return within(9 * 16, 8);
                case 0x1921bcu:
                    return within(6 * 16, 8);
                case 0x18f570u:
                case 0x18f584u:
                    return within(1 * 16, 8);
                case 0x18f598u:
                case 0x18f59cu:
                case 0x18fdf0u:
                case 0x18fdf4u:
                    return within(3 * 16, 8);
                case 0x18f5e4u:
                case 0x18f5e8u:
                    return within(5 * 16, 8);
                default:
                    return false;
            }
        default:
            return false;
    }
}
// Only integer metadata from this exact immutable GPU output is inspected.
// Inherited FCR, a JR's input RA and physical whole-bank copies are not writes.
// No numerical RAM/SPR/Context value is downloaded or turned into RAW authority.
inline PerspectiveEffectsPacket
decodePerspectiveEffectsMetadata(const Parameters& p, uint32_t actualTask,
                                 std::span<const uint32_t, ReceiptWords> receipt,
                                 std::span<const uint32_t> words) {
    using namespace reo_source_closure;
    if (words.size() != PerspectiveEffectsWords || !perspectiveEntry(p.entry) || !actualTask)
        throw std::invalid_argument("Perspective effects allocation/profile differs");
    PerspectiveEffectsPacket out;
    std::memcpy(&out.header, words.data(), sizeof(out.header));
    const auto& h = out.header;
    const std::array<uint32_t, 8> stamp{p.sessionLo, p.sessionHi, p.epochLo,   p.epochHi,
                                        p.bankLo,    p.bankHi,    p.ordinalLo, p.ordinalHi};
    if (receipt[0] || receipt[1] != ReceiptMagic || receipt[2] != ReceiptVersion ||
        receipt[3] != 1 || h.status || h.magic != EffectsMagic || h.version != EffectsVersion ||
        h.committed != 1 || h.stamp != stamp || h.originalEntry != p.entry ||
        h.actualFinalPc != receipt[18] || h.actualTask != actualTask || h.profile != 0x18f710u ||
        h.dirtyCapacity != PerspectiveEffectsDirtyCapacity ||
        h.controlCapacity != PerspectiveEffectsControlCapacity || h.dirtyCount > h.dirtyCapacity ||
        h.controlCount > h.controlCapacity)
        throw std::invalid_argument("Perspective effects source/control envelope refused");
    for (unsigned k = 0; k < 8; ++k)
        if (receipt[4 + k] != stamp[k])
            throw std::invalid_argument("Perspective receipt stamp differs");
    if (receipt[12] != p.entry || receipt[13] != p.returnPc || receipt[14] != p.a0 ||
        receipt[15] != p.a1 || receipt[16] != p.a2 || receipt[17] != p.entry)
        throw std::invalid_argument("Perspective receipt call differs");
    const uint32_t controlBase = 20 + PerspectiveEffectsDirtyCapacity * 6;
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
            !perspectiveSourcePc(d.sourcePc) || !d.sourceOrdinal || d.sourceOrdinal > 65536 ||
            d.role < 1 || d.role > 9 || d.role == 8 ||
            (space != Space::Context && d.role != 1 && d.role != 9) ||
            (space == Space::Context && d.role == 9))
            throw std::invalid_argument("Perspective dirty source span refused");
        for (uint32_t j = 0; j < k; ++j) {
            const auto& old = out.dirty[j];
            if (d.space == old.space && d.offset < old.offset + old.bytes &&
                old.offset < d.offset + d.bytes)
                throw std::invalid_argument("Perspective source spans overlap");
        }
        if (space == Space::Context)
            for (uint32_t b = d.offset; b < d.offset + d.bytes; ++b)
                authored[b] = &d;
    }
    bool pc = false;
    std::array<bool, ContextBytes> published{};
    for (uint32_t k = 0; k < h.controlCount; ++k) {
        auto& c = out.control[k];
        std::memcpy(&c, words.data() + controlBase + k * 8, sizeof(c));
        if (!perspectiveSourcePc(c.sourcePc) || !perspectiveControlRange(c))
            throw std::invalid_argument("Perspective scalar source role refused");
        for (uint32_t b = 0; b < c.bytes; ++b) {
            const auto at = c.contextOffset + b;
            const auto* d = authored[at];
            if (published[at] || !d || d->role != c.role || d->sourcePc != c.sourcePc)
                throw std::invalid_argument("Perspective scalar lacks exact authored dirty role");
            published[at] = true;
        }
        for (uint32_t b = c.bytes; b < 16; ++b)
            if ((c.bits[b / 4] >> ((b & 3) * 8)) & 255)
                throw std::invalid_argument("Perspective scalar padding differs");
        if (c.contextOffset == offsetof(R5900Context, pc))
            pc = c.bytes == 4 && c.role == uint32_t(Role::GenuineControlPc) &&
                 c.bits[0] == receipt[18];
        if (c.contextOffset == offsetof(R5900Context, fcr31) && c.bits[0] != receipt[19])
            throw std::invalid_argument("Perspective authored FCR differs from receipt");
    }
    for (uint32_t b = 0; b < ContextBytes; ++b)
        if (authored[b] && authored[b]->role >= 3 && authored[b]->role <= 7 && !published[b])
            throw std::invalid_argument("Perspective authored scalar control absent");
    if (!pc)
        throw std::invalid_argument("Perspective actual return PC absent");
    return out;
}
inline PerspectiveEffectsPacket
decodePerspectiveEffects(const Call& call, std::span<const uint32_t, ReceiptWords> receipt,
                         std::span<const uint32_t> words) {
    return decodePerspectiveEffectsMetadata(parameters(call), uint32_t(call.task()), receipt,
                                            words);
}
} // namespace reo_gpu_upstream
