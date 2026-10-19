#pragma once
#include <array>
#include <cstdint>
#include <cstring>
#include <stdexcept>
namespace reo_gpu_path1_metadata {
struct RegisterWrite {
    uint8_t address = 0;
    uint64_t value = 0;
};
struct CommandContract {
    enum class Kind { None, TexturedStrip, LiteralMaterialAD };
    Kind kind = Kind::None;
    uint64_t headerHigh = 0, registerList = 0;
    uint32_t inputLoopCount = 0, prim = 0;
    std::array<RegisterWrite, 6> ad{};
};
inline uint64_t raw64(const uint8_t* bytes) {
    uint64_t value;
    std::memcpy(&value, bytes, 8);
    return value;
}
// Only command metadata is decoded here. No source vertex/UV/color math, GIF
// geometry expansion or texture conversion belongs in this CPU coordinator.
// Caller must prove bytes are unchanged literal V4-32/mode0/unmasked/equal-cycle
// upload bytes for the actual input tag or copied control chain. GPU compares
// echoed command words before committing its whole launch; this metadata alone
// is NEVER a completeness certificate or a substitute for resident data.
inline bool describeLiteralPath1(const uint8_t* bytes, uint32_t size, CommandContract& out) {
    out = {};
    if (!bytes || size < 16)
        return false;
    const uint64_t low = raw64(bytes), regs = raw64(bytes + 8);
    const uint32_t count = uint32_t(low) & 32767u, flg = uint32_t(low >> 58) & 3u,
                   nreg = uint32_t(low >> 60) & 15u;
    const bool eop = (low & 32768u) != 0, pre = ((low >> 46) & 1u) != 0;
    const uint32_t prim = uint32_t(low >> 47) & 2047u;
    if (!eop || flg != 0 || (uint32_t(low) & 0xffff0000u))
        return false;
    if (pre && nreg == 3 && regs == 0x412u && (prim & 7u) == 4u && count > 0 && count <= 256) {
        // Known2EA supplied STQ/RGBA/XYZ2 strip; result loop count is count+2.
        // Full TEX0/TEX1/CLUT/TEST/ALPHA state comes from the ordered GS owner.
        out.kind = CommandContract::Kind::TexturedStrip;
        out.headerHigh = low >> 32;
        out.registerList = regs;
        out.inputLoopCount = count;
        out.prim = prim;
        return true;
    }
    if (pre || nreg != 1 || regs != 0xe || count != 6 || size != 112)
        return false;
    constexpr std::array<uint8_t, 6> expected{0x3b, 0x14, 0x06, 0x08, 0x34, 0x36};
    for (unsigned i = 0; i < 6; ++i) {
        const auto* record = bytes + 16 + i * 16;
        const auto address = raw64(record + 8);
        if (address != expected[i])
            return false;
        out.ad[i] = {expected[i], raw64(record)};
    }
    out.kind = CommandContract::Kind::LiteralMaterialAD;
    out.headerHigh = low >> 32;
    out.registerList = regs;
    out.inputLoopCount = count;
    return true;
}
// Expected GPU-side verification input. For a strip, compare words1..3 and
// EOP/PRE, but let the whole shader certify exact(count+2) low loop bits. For AD,
// compare all seven qwords to the literal uploaded chain. Status failure must
// become sticky before state commit, and downstream draw capacity becomes0.
struct alignas(16) GpuEchoContract {
    std::array<uint32_t, 4> kindCountFlags{};
    std::array<std::array<uint32_t, 4>, 7> qwords{};
};
static_assert(sizeof(GpuEchoContract) == 128);
inline GpuEchoContract echoContract(const CommandContract& c) {
    if (c.kind == CommandContract::Kind::None)
        throw std::invalid_argument("Unknown PATH1 contract");
    GpuEchoContract result{};
    result.kindCountFlags = {c.kind == CommandContract::Kind::TexturedStrip ? 1u : 2u,
                             c.inputLoopCount, c.prim, 0};
    result.qwords[0] = {32768u | c.inputLoopCount, uint32_t(c.headerHigh), uint32_t(c.registerList),
                        uint32_t(c.registerList >> 32)};
    if (c.kind == CommandContract::Kind::LiteralMaterialAD)
        for (unsigned i = 0; i < 6; ++i)
            result.qwords[i + 1] = {uint32_t(c.ad[i].value), uint32_t(c.ad[i].value >> 32),
                                    c.ad[i].address, 0};
    return result;
}
} // namespace reo_gpu_path1_metadata
