#pragma once
#include "instruction_input_evidence.hpp"
#include <algorithm>
#include <cstring>
namespace reo_source_closure {
// A closed bit-transfer catalogue. It accepts no host FP/VU arithmetic result.
// Evidence authentication and both physical ownership ledgers are checked by
// NativeTarget before this shape policy can issue an immutable write permit.
template <class Evidence, class Resolve>
void validateGuardedCpuIngress(const Evidence& evidence, uint32_t at, const void* data,
                               uint32_t bytes,
                               const reo_source_instrumentation::InstructionOrigin& origin,
                               Resolve&& resolve) {
    using S = reo_parent_natural::SourceSpace;
    if (!data || !origin.pc || !origin.word || !bytes || bytes > 16)
        throw std::invalid_argument("CPU ingress lacks exact bounded original instruction");
    const uint32_t op = origin.word >> 26, rs = (origin.word >> 21) & 31u,
                   rt = (origin.word >> 16) & 31u, fs = (origin.word >> 11) & 31u;
    const auto exactRead = [&](uint32_t i, S space, uint32_t offset,
                               uint32_t count) -> const auto& {
        const auto& r = evidence.read(i);
        if (r.space != space || r.offset != offset || r.bytes != count)
            throw std::invalid_argument(
                "CPU ingress guarded read differs from complete original operand set");
        return r;
    };
    const auto same = [&](const void* source, uint32_t count) {
        if (bytes != count || std::memcmp(data, source, count))
            throw std::invalid_argument(
                "CPU bit-transfer value differs from its actual guarded input");
    };
    if (op == 0x11u && (rs == 0u || rs == 4u)) {
        // MFC1/MTC1: reserved encoding fields must remain zero.
        if (origin.word & 0x7ffu || evidence.transferCount())
            throw std::invalid_argument(
                "COP1 ingress is not the original plain bit-transfer encoding");
        if (rs == 0u) {
            if (!rt || at != rt * 16u || bytes != 8u || evidence.readCount() != 1u)
                throw std::invalid_argument("MFC1 actual destination/read set differs");
            const auto& r =
                exactRead(0, S::Context, uint32_t(offsetof(R5900Context, f)) + fs * 4u, 4u);
            uint32_t bits;
            std::memcpy(&bits, r.value.data(), 4);
            const uint64_t result = uint64_t(int64_t(int32_t(bits)));
            same(&result, 8);
            return;
        }
        if (at != uint32_t(offsetof(R5900Context, f)) + fs * 4u || bytes != 4u ||
            evidence.readCount() != (rt ? 1u : 0u))
            throw std::invalid_argument("MTC1 actual destination/read set differs");
        uint32_t bits = 0;
        if (rt) {
            const auto& r = exactRead(0, S::Context, rt * 16u, 4u);
            std::memcpy(&bits, r.value.data(), 4);
        }
        same(&bits, 4);
        return;
    }
    if (op != 0x31u && op != 0x1eu && op != 0x36u)
        throw std::invalid_argument("CPU opcode needs its separate numerical/source closure");
    const uint32_t width = op == 0x31u ? 4u : 16u;
    const uint32_t destination = op == 0x31u   ? uint32_t(offsetof(R5900Context, f)) + rt * 4u
                                 : op == 0x36u ? uint32_t(offsetof(R5900Context, vu0_vf)) + rt * 16u
                                               : rt * 16u;
    if ((op == 0x1eu && !rt) || at != destination || bytes != width ||
        evidence.transferCount() != 1u)
        throw std::invalid_argument("Original load actual destination/width differs");
    uint32_t base = 0;
    const uint32_t prefix = rs ? 1u : 0u;
    if (rs) {
        const auto& r = exactRead(0, S::Context, rs * 16u, 4u);
        std::memcpy(&base, r.value.data(), 4);
    }
    const auto& t = evidence.transfer(0);
    const uint32_t ea = base + uint32_t(int32_t(int16_t(origin.word & 0xffffu)));
    if (t.effectiveAddress != ea || t.bytes != width || t.firstRead != prefix)
        throw std::invalid_argument(
            "Actual load effective address/transfer differs from original guarded base");
    const auto view = resolve(ea, t.fast);
    if (!view.source || view.at >= view.limit)
        throw std::invalid_argument("CPU load has no actual RAM/SPR source view");
    const uint32_t first = std::min(width, view.limit - view.at), count = first == width ? 1u : 2u;
    if (count == 2u && (view.space != S::Ram || (!t.fast && PS2Runtime::isSpecialAddress(ea))))
        throw std::invalid_argument("CPU ingress crosses an unclosed special source view");
    if (t.readCount != count || evidence.readCount() != prefix + count)
        throw std::invalid_argument(
            "CPU load does not contain its complete exact wrapped read set");
    const auto& head = exactRead(prefix, view.space, view.at, first);
    if (std::memcmp(head.value.data(), t.value.data(), first))
        throw std::invalid_argument("CPU load first span differs from actual returned bytes");
    if (count == 2u) {
        const auto& tail = exactRead(prefix + 1, view.space, 0, width - first);
        if (std::memcmp(tail.value.data(), t.value.data() + first, width - first))
            throw std::invalid_argument("CPU load wrapped span differs from actual returned bytes");
    }
    same(t.value.data(), width);
}
inline constexpr bool CompleteCpuIngressCatalogue = false;
} // namespace reo_source_closure
