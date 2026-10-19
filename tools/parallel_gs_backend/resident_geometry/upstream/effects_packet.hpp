#pragma once
#include "source_effects_abi.hpp"
#include "context_layout.hpp"
#include <cstring>
#include <span>
namespace reo_gpu_upstream {
constexpr uint32_t CompositionEffectsDirtyCapacity = 2048, CompositionEffectsControlCapacity = 128;
constexpr uint32_t CompositionEffectsWords =
    20 + CompositionEffectsDirtyCapacity * 6 + CompositionEffectsControlCapacity * 8;
constexpr uint32_t CompositionEffectsBytes = CompositionEffectsWords * 4;
struct CompositionEffectsPacket {
    reo_source_closure::Header header{};
    std::vector<reo_source_closure::DirtySpan> dirty;
    std::vector<reo_source_closure::ControlWord> control;
};
inline bool compositionControlRange(const reo_source_closure::ControlWord& c) {
    using R = reo_source_closure::Role;
    const uint32_t at = c.contextOffset, n = c.bytes;
    if (!n || n > 16 || at > ContextBytes || n > ContextBytes - at)
        return false;
    switch (R(c.role)) {
        case R::GenuineControlPc:
            return (at == offsetof(R5900Context, pc) && n == 4) ||
                   (at == offsetof(R5900Context, branch_pc) && n == 4) ||
                   (at >= 31 * 16 && at + n <= 31 * 16 + 8);
        case R::GenuineControlFcr:
            return at == offsetof(R5900Context, fcr31) && n == 4;
        case R::GenuineControlStack:
            return at >= 29 * 16 && at + n <= 29 * 16 + 8;
        case R::GenuineScalarReturn:
            return at == offsetof(R5900Context, in_delay_slot) && n == 1;
        case R::GenuineControlPointer:
            for (auto r : {1u, 2u, 3u, 4u, 5u, 6u, 9u, 16u})
                if (at >= r * 16 && at + n <= r * 16 + 8)
                    return true;
            return false;
        default:
            return false;
    }
}
// This validates only integer metadata from the exact selected GPU output. It
// does not mint a lease or authorize CPU bank reads. Actual Service issuance,
// prior-lane inheritance, held-input ranges and EE publication remain required.
inline CompositionEffectsPacket
decodeCompositionEffects(const Call& call, std::span<const uint32_t, ReceiptWords> receipt,
                         std::span<const uint32_t> words) {
    using namespace reo_source_closure;
    if (words.size() != CompositionEffectsWords)
        throw std::invalid_argument("Composition effects allocation differs");
    CompositionEffectsPacket out;
    std::memcpy(&out.header, words.data(), sizeof(out.header));
    const auto& h = out.header;
    const auto p = parameters(call);
    const std::array<uint32_t, 8> stamp{p.sessionLo, p.sessionHi, p.epochLo,   p.epochHi,
                                        p.bankLo,    p.bankHi,    p.ordinalLo, p.ordinalHi};
    if (receipt[0] || receipt[1] != ReceiptMagic || receipt[2] != ReceiptVersion ||
        receipt[3] != 1 || h.status || h.magic != EffectsMagic || h.version != EffectsVersion ||
        h.committed != 1 || h.stamp != stamp || h.originalEntry != call.entry() ||
        h.actualFinalPc != receipt[18] || h.actualTask != uint32_t(call.task()) ||
        h.profile != 0x18f6a0 || h.dirtyCapacity != CompositionEffectsDirtyCapacity ||
        h.controlCapacity != CompositionEffectsControlCapacity || h.dirtyCount > h.dirtyCapacity ||
        h.controlCount > h.controlCapacity)
        throw std::invalid_argument("Composition effects source/control envelope refused");
    for (unsigned k = 0; k < 8; ++k)
        if (receipt[4 + k] != stamp[k])
            throw std::invalid_argument("Composition receipt stamp differs");
    if (receipt[12] != call.entry() || receipt[13] != call.returnPc() || receipt[14] != call.a0() ||
        receipt[15] != call.a1() || receipt[16] != call.a2() || receipt[17] != call.entry())
        throw std::invalid_argument("Composition receipt call differs");
    const uint32_t controlBase = 20 + CompositionEffectsDirtyCapacity * 6;
    out.dirty.resize(h.dirtyCount);
    out.control.resize(h.controlCount);
    for (uint32_t k = 0; k < h.dirtyCount; ++k) {
        auto& d = out.dirty[k];
        std::memcpy(&d, words.data() + 20 + k * 6, sizeof(d));
        const auto space = Space(d.space);
        const uint32_t cap = space == Space::Ram       ? RamBytes
                             : space == Space::Spr     ? SprBytes
                             : space == Space::Context ? ContextBytes
                                                       : 0;
        if (!cap || !d.bytes || d.offset >= cap || d.bytes > cap - d.offset || !d.sourcePc ||
            !d.sourceOrdinal || d.sourceOrdinal > 65536 || d.role < 1 || d.role > 9 ||
            d.role == 8 || (space != Space::Context && d.role != 1 && d.role != 9) ||
            (space == Space::Context && d.role == 9))
            throw std::invalid_argument("Composition dirty source span refused");
        // The final source writes are disjoint. This is metadata validation,
        // never comparison against host numerical bank values.
        for (uint32_t j = 0; j < k; ++j) {
            const auto& old = out.dirty[j];
            if (d.space == old.space && d.offset < old.offset + old.bytes &&
                old.offset < d.offset + d.bytes)
                throw std::invalid_argument("Composition source spans overlap");
        }
    }
    bool pc = false, fcr = false;
    for (uint32_t k = 0; k < h.controlCount; ++k) {
        auto& c = out.control[k];
        std::memcpy(&c, words.data() + controlBase + k * 8, sizeof(c));
        if (!c.sourcePc || !compositionControlRange(c))
            throw std::invalid_argument("Composition scalar source role refused");
        for (uint32_t b = c.bytes; b < 16; ++b)
            if ((c.bits[b / 4] >> ((b & 3) * 8)) & 255)
                throw std::invalid_argument("Composition scalar padding differs");
        for (uint32_t j = 0; j < k; ++j) {
            const auto& old = out.control[j];
            if (c.contextOffset < old.contextOffset + old.bytes &&
                old.contextOffset < c.contextOffset + c.bytes)
                throw std::invalid_argument("Composition scalar controls overlap");
        }
        if (c.contextOffset == offsetof(R5900Context, pc)) {
            pc = c.bytes == 4 && c.role == uint32_t(Role::GenuineControlPc) &&
                 c.bits[0] == receipt[18];
        }
        if (c.contextOffset == offsetof(R5900Context, fcr31)) {
            fcr = c.bytes == 4 && c.role == uint32_t(Role::GenuineControlFcr) &&
                  c.bits[0] == receipt[19];
        }
    }
    if (!pc || !fcr)
        throw std::invalid_argument("Composition actual return controls absent");
    return out;
}
} // namespace reo_gpu_upstream
