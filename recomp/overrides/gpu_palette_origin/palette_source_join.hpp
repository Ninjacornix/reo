#pragma once
// Read-only exact original call join. No float arithmetic or guest writes.
#include "ps2_runtime.h"
#include <array>
#include <cstdint>
#include <cstring>
namespace reo_palette_join {
constexpr uint32_t RamBytes = 32u * 1024u * 1024u, PacketBytes = 0xfb0u, PayloadBytes = 248u * 16u;
struct Site {
    uint32_t parent, calleeReturn, loop, loopReturn, followingCopy, light, material;
};
constexpr Site Sites[2]{
    {0x19b1c0u, 0x19b38cu, 0x19b340u, 0x19b38cu, 0u, 0x19b430u, 0x19b440u},
    {0x19bbd0u, 0x19bd9cu, 0x19bd50u, 0x19bd9cu, 0x19bdacu, 0x19be4cu, 0x19be5cu}};
struct Metadata {
    uint32_t parent = 0, returnPC = 0, descriptor = 0, packet = 0, bone = 0, mask = 0;
    uint32_t normalDestination = 0, positionDestination = 0, boneSource = 0, commonSource = 0;
    uint32_t positionPayloadOffset = 0, normalPayloadOffset = 0;
};
struct ImmutableCall {
    Metadata metadata{};
    std::array<uint8_t, 64> common{}, bone{};
    std::array<uint8_t, sizeof(R5900Context)> context{};
};
inline uint32_t rawWord(const uint8_t* p) {
    uint32_t word;
    std::memcpy(&word, p, 4);
    return word;
}
inline uint32_t gpr(const R5900Context& ctx, unsigned index) {
    uint32_t word;
    std::memcpy(&word, &ctx.r[index], 4);
    return word;
}
inline bool mainRange(uint32_t address, uint32_t bytes) {
    return address < RamBytes && bytes <= RamBytes - address;
}
inline bool captureBeforeMath(const uint8_t* rdram, const uint8_t* scratchpad,
                              const R5900Context& ctx, ImmutableCall& result) {
    if (!rdram || !scratchpad || ctx.pc != 0x1994e0u)
        return false;
    const uint32_t ret = gpr(ctx, 31), packet = gpr(ctx, 2), bone = gpr(ctx, 8),
                   descriptor = gpr(ctx, 18);
    const Site* site = nullptr;
    for (const auto& candidate : Sites)
        if (candidate.calleeReturn == ret)
            site = &candidate;
    if (!site || bone >= 32 || (packet & 15u) || !mainRange(packet, PacketBytes) ||
        !mainRange(descriptor, 0x180))
        return false;
    const uint32_t mask = rawWord(rdram + descriptor + 0x54);
    if (!(mask & (1u << bone)) || rawWord(rdram + packet) != 0x200000fau ||
        rawWord(rdram + packet + 0x18) != 0x01000404u ||
        rawWord(rdram + packet + 0x1c) != 0x6cf80000u)
        return false;
    const uint32_t position = packet + 0x1a0u + 64u * bone, normal = packet + 0x9a0u + 48u * bone;
    if (gpr(ctx, 4) != normal || gpr(ctx, 5) != position ||
        gpr(ctx, 6) != 0x70003700u + 64u * bone || gpr(ctx, 7) != 0x70003f40u)
        return false;
    Metadata m{};
    m.parent = site->parent;
    m.returnPC = ret;
    m.descriptor = descriptor;
    m.packet = packet;
    m.bone = bone;
    m.mask = mask;
    m.normalDestination = normal;
    m.positionDestination = position;
    m.boneSource = gpr(ctx, 6);
    m.commonSource = gpr(ctx, 7);
    m.positionPayloadOffset = 0x180u + 64u * bone;
    m.normalPayloadOffset = 0x980u + 48u * bone;
    result.metadata = m;
    std::memcpy(result.common.data(), scratchpad + 0x3f40, 64);
    std::memcpy(result.bone.data(), scratchpad + 0x3700 + 64u * bone, 64);
    std::memcpy(result.context.data(), &ctx, sizeof(ctx));
    return true;
}
// True final VU0 residue of1994E0 only: VF4..11 (128B), ACC (16B), Q (4B).
// No VI/P/I/flags or GPR writes. JR publishes original RA; GPU pending state
// must never be passed as completed state to a generated CPU VU0 consumer.
constexpr uint32_t WrittenVu0Registers = 0x00000ff0u;
constexpr bool WritesAccumulator = true, WritesQ = true, WritesVuFlags = false;
constexpr bool LiveProducerAdmission = false;
} // namespace reo_palette_join
