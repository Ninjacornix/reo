#pragma once
#include "resident_vif_commands.h"
#include "consumer_cert.hpp"
#include <array>
#include <stdexcept>
namespace reo_gpu_static_consumer {
// Completion metadata only, read at the existing real DMA/wait retirement.
// These values cannot feed graphical setup, shape selection, or draw counts.
inline reo_resident_live::Retired retirement(uint64_t epoch, uint64_t bankGeneration,
                                             uint64_t ordinal, const std::array<uint32_t, 32>& tape,
                                             const std::array<uint32_t, 11>& cert,
                                             uint32_t globalSticky, uint32_t expectedFamily,
                                             uint32_t generation, uint32_t job) {
    uint32_t error = globalSticky ? globalSticky : tape[0] ? tape[0] : cert[Sticky];
    if (tape[1] != 0x53543532u || tape[2] != 1u || tape[3] != expectedFamily || tape[4] != 0u ||
        tape[5] != 1u || tape[6] > 495u || tape[20] != 0u || tape[21] != generation ||
        tape[22] != job || cert[Ready] != 1u || cert[Committed] != 1u ||
        cert[PublicationReady] != 1u || cert[Generation] != generation || cert[JobOrdinal] != job ||
        cert[MagicWord] != Magic || cert[VersionWord] != Version)
        if (!error)
            error = 87u;
    return {epoch, bankGeneration,          ordinal, tape[10], tape[6],
            error, (tape[12] & 255u) == 1u, false};
}
// Existing Retired.eventCount and actual wait receipt validation already admit
// uint32 multi-events. No shared/generated runtime ABI modification is needed.
// The new owner branch must bypass the old one-event EffectValidate and use
// this certificate, preserving original ordinal/generation/E/error checks.
} // namespace reo_gpu_static_consumer
