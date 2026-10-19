#pragma once
#include "upstream/effects_ledger.hpp"
#include "source_instruction_origin.hpp"
#include <cstring>
#include "upstream/completed_delay_control.hpp"
namespace reo_source_closure {
// This checks actual integer instruction lineage, not a caller's claim that a
// GPR or a small value is a scalar. Numeric transfers and loads need their
// distinct reviewed input certificate and cannot enter this path.
template <class ReadRole>
inline void validateTypedContextControl(uint32_t at, uint32_t bytes, const void* data,
                                        uint32_t sourcePc,
                                        const reo_source_instrumentation::InstructionOrigin& origin,
                                        ReadRole&& role,
                                        const CompletedDelayControl* completedDelay = nullptr) {
    using I = reo_source_instrumentation::ContextWriteIntent;
    if (!data || !sourcePc || !origin.pc)
        throw std::invalid_argument("Typed control lacks genuine original instruction identity");
    const uint32_t op = origin.word >> 26, rs = (origin.word >> 21) & 31u,
                   rt = (origin.word >> 16) & 31u, rd = (origin.word >> 11) & 31u,
                   fn = origin.word & 63u;
    const bool pc = at == offsetof(R5900Context, pc) && bytes == 4,
               branch = at == offsetof(R5900Context, branch_pc) && bytes == 4,
               delay = at == offsetof(R5900Context, in_delay_slot) && bytes == 1;
    const bool controlFlow = (op == 0u && (fn == 8u || fn == 9u)) || op == 1u ||
                             (op >= 2u && op <= 7u) || (op >= 0x14u && op <= 0x17u) ||
                             (op == 0x11u && rs == 8u);
    // Generated source sets a new instruction PC before executing that site's
    // body. Its verified source origin may differ from the old pre-store PC;
    // the immutable permit remains bound to that actual old PC independently.
    if (pc && origin.intent == I::GeneratedPcProgress)
        return;
    if (!origin.word)
        throw std::invalid_argument(
            "Native/unknown opcode cannot acquire source control authority");
    if ((branch || delay) && origin.intent == I::GeneratedPcProgress && controlFlow)
        return;
    if (delay && completedDelay && completedDelay->matches(at, bytes, data, sourcePc, origin))
        return;
    if (sourcePc != origin.pc)
        throw std::invalid_argument("Nonmetadata scalar lost actual instruction PC");
    if (origin.intent != I::GenuineScalarControl || bytes > 8u || !bytes || at % 16u ||
        at / 16u == 0u || at / 16u > 31u)
        throw std::invalid_argument("Context numeric/RAW candidate cannot become scalar control");
    const uint32_t destination = at / 16u;
    // The Service separately rejects any opaque destination bytes. A genuine
    // integer operation can give a CPU-owned destination a new scalar role.
    const auto source = [&](uint32_t r, uint32_t consumedBytes = 8u) {
        if (r && !role(r, consumedBytes))
            throw std::invalid_argument("Integer source has no retained scalar role");
    };
    if (op == 0u) {
        if (fn == 0u || fn == 2u || fn == 3u) {
            if (destination != rd)
                throw std::invalid_argument("Shift destination differs");
            source(rt);
            return;
        }
        if (fn == 4u || fn == 6u || fn == 7u || fn == 0x14u || fn == 0x16u || fn == 0x17u ||
            (fn >= 0x20u && fn <= 0x27u) || fn == 0x2au || fn == 0x2bu || fn == 0x2cu ||
            fn == 0x2du || fn == 0x2eu || fn == 0x2fu) {
            if (destination != rd)
                throw std::invalid_argument("Integer destination differs");
            source(rs);
            source(rt);
            return;
        }
        // JALR has an instruction-derived control return, not a numeric result.
        if (fn == 9u && destination == rd && rd == 31u) {
            source(rs);
            return;
        }
    } else if (op >= 8u && op <= 0x0fu) {
        if (destination != rt)
            throw std::invalid_argument("Immediate destination differs");
        // ANDI zeroes every bit outside its unsigned16-bit mask. Only actual
        // source bytes selected by that mask can influence the scalar result.
        // The separate source-read guard still protects every byte really read
        // by generated code; this does not permit reading an opaque lane.
        if (op == 0x0cu) {
            const uint32_t mask = origin.word & 0xffffu;
            if (mask)
                source(rs, mask <= 0xffu ? 1u : 2u);
            return;
        }
        if (op != 0x0fu)
            source(rs);
        return;
    } else if ((op == 0x18u || op == 0x19u) && destination == rt) {
        source(rs);
        return;
    } else if (op == 3u && destination == 31u)
        return;
    throw std::invalid_argument("Opcode needs a separate source/control certificate");
}
} // namespace reo_source_closure
