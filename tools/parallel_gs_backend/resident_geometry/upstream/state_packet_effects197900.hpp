#pragma once
#include "effects_packet.hpp"
#include <algorithm>
namespace reo_gpu_upstream {
using StatePacketEffectsPacket = CompositionEffectsPacket;
inline constexpr uint32_t StatePacketEffectsWords = CompositionEffectsWords,
                          StatePacketEffectsBytes = CompositionEffectsBytes;
inline bool statePacketContains(uint32_t begin, uint32_t bytes, uint32_t at, uint32_t n) {
    return n && at >= begin && at - begin < bytes && n <= bytes - (at - begin);
}
struct StatePacketContextWrite {
    uint32_t pc, offset, bytes, stage;
};
inline constexpr std::array<StatePacketContextWrite, 201> StatePacketContextWrites{{
    {0x197900u, 464u, 8u, 1u},  {0x197904u, 16u, 8u, 1u},   {0x19790cu, 32u, 8u, 1u},
    {0x197918u, 112u, 8u, 1u},  {0x197920u, 272u, 8u, 1u},  {0x197928u, 112u, 8u, 1u},
    {0x19792cu, 112u, 8u, 1u},  {0x197930u, 80u, 8u, 1u},   {0x197934u, 112u, 8u, 1u},
    {0x197938u, 112u, 8u, 1u},  {0x197940u, 112u, 8u, 1u},  {0x197944u, 80u, 8u, 1u},
    {0x197948u, 32u, 8u, 1u},   {0x19794cu, 48u, 8u, 1u},   {0x197954u, 32u, 8u, 1u},
    {0x197960u, 32u, 8u, 1u},   {0x197968u, 32u, 8u, 1u},   {0x197974u, 32u, 8u, 1u},
    {0x19797cu, 32u, 8u, 1u},   {0x197994u, 128u, 16u, 1u}, {0x19799cu, 128u, 8u, 1u},
    {0x1979a4u, 128u, 8u, 1u},  {0x1979acu, 128u, 8u, 1u},  {0x1979b4u, 128u, 8u, 1u},
    {0x1979bcu, 128u, 8u, 1u},  {0x1979c4u, 128u, 8u, 1u},  {0x1979c8u, 128u, 8u, 1u},
    {0x1979ccu, 48u, 8u, 1u},   {0x1979d0u, 32u, 8u, 1u},   {0x1979d8u, 32u, 8u, 1u},
    {0x1979e4u, 32u, 8u, 1u},   {0x1979ecu, 32u, 8u, 1u},   {0x1979f8u, 48u, 8u, 1u},
    {0x1979fcu, 32u, 8u, 1u},   {0x197a08u, 32u, 8u, 1u},   {0x197a10u, 32u, 8u, 1u},
    {0x197a20u, 48u, 8u, 1u},   {0x197a28u, 96u, 8u, 1u},   {0x197a30u, 96u, 8u, 1u},
    {0x197a38u, 96u, 8u, 1u},   {0x197a40u, 96u, 8u, 1u},   {0x197a44u, 96u, 8u, 1u},
    {0x197a48u, 48u, 8u, 1u},   {0x197a4cu, 32u, 8u, 1u},   {0x197a50u, 48u, 8u, 1u},
    {0x197a54u, 32u, 8u, 1u},   {0x197a58u, 64u, 8u, 1u},   {0x197a5cu, 32u, 8u, 1u},
    {0x197a60u, 48u, 8u, 1u},   {0x197a64u, 32u, 8u, 1u},   {0x197a68u, 80u, 8u, 1u},
    {0x197a6cu, 32u, 8u, 1u},   {0x197a70u, 64u, 8u, 1u},   {0x197a74u, 48u, 8u, 1u},
    {0x197a78u, 64u, 8u, 1u},   {0x197a7cu, 32u, 8u, 1u},   {0x197a84u, 256u, 8u, 1u},
    {0x197a88u, 64u, 8u, 1u},   {0x197a8cu, 496u, 8u, 1u},  {0x197a90u, 80u, 8u, 1u},
    {0x197a98u, 112u, 8u, 2u},  {0x197a9cu, 64u, 8u, 1u},   {0x197aa0u, 496u, 8u, 1u},
    {0x197aa4u, 80u, 8u, 1u},   {0x197aa8u, 112u, 8u, 2u},  {0x197aacu, 64u, 8u, 2u},
    {0x197ab0u, 48u, 8u, 2u},   {0x197ab4u, 64u, 8u, 2u},   {0x197ab8u, 80u, 8u, 2u},
    {0x197abcu, 64u, 8u, 2u},   {0x197ac0u, 96u, 8u, 2u},   {0x197ac4u, 48u, 8u, 2u},
    {0x197ac8u, 96u, 8u, 2u},   {0x197accu, 64u, 8u, 2u},   {0x197ad4u, 48u, 8u, 2u},
    {0x197adcu, 80u, 8u, 2u},   {0x197ae4u, 48u, 8u, 2u},   {0x197ae8u, 80u, 8u, 2u},
    {0x197aecu, 64u, 8u, 2u},   {0x197af0u, 48u, 8u, 2u},   {0x197af4u, 48u, 8u, 2u},
    {0x197af8u, 80u, 8u, 2u},   {0x197afcu, 64u, 8u, 2u},   {0x197b04u, 48u, 8u, 2u},
    {0x197b10u, 48u, 8u, 2u},   {0x197b18u, 16u, 8u, 2u},   {0x197b1cu, 272u, 8u, 2u},
    {0x197b20u, 16u, 8u, 2u},   {0x197b28u, 80u, 8u, 2u},   {0x197b2cu, 48u, 8u, 2u},
    {0x197b40u, 48u, 8u, 2u},   {0x197b54u, 16u, 8u, 2u},   {0x197b58u, 64u, 8u, 2u},
    {0x197b60u, 48u, 8u, 2u},   {0x197b64u, 16u, 8u, 2u},   {0x197b7cu, 80u, 8u, 2u},
    {0x197b80u, 112u, 8u, 2u},  {0x197b84u, 80u, 8u, 2u},   {0x197b88u, 96u, 8u, 2u},
    {0x197b8cu, 64u, 8u, 2u},   {0x197b90u, 496u, 8u, 2u},  {0x197b94u, 112u, 8u, 2u},
    {0x197b98u, 496u, 8u, 3u},  {0x197b9cu, 32u, 8u, 3u},   {0x197ba0u, 272u, 16u, 3u},
    {0x197ba4u, 256u, 16u, 3u}, {0x197bacu, 464u, 8u, 3u},  {0x18cfb0u, 464u, 8u, 3u},
    {0x18cfb4u, 32u, 8u, 3u},   {0x18cfc4u, 320u, 8u, 3u},  {0x18cfccu, 304u, 8u, 3u},
    {0x18cfd4u, 288u, 8u, 3u},  {0x18cfe0u, 16u, 8u, 3u},   {0x18cfe4u, 32u, 8u, 3u},
    {0x18cfe8u, 48u, 8u, 3u},   {0x18cfecu, 32u, 8u, 3u},   {0x18cff0u, 256u, 8u, 3u},
    {0x18cff4u, 64u, 8u, 3u},   {0x18cff8u, 48u, 8u, 3u},   {0x18cffcu, 16u, 8u, 3u},
    {0x18d004u, 272u, 8u, 3u},  {0x18d008u, 496u, 8u, 3u},  {0x18d00cu, 64u, 8u, 3u},
    {0x18d010u, 48u, 8u, 3u},   {0x18d014u, 80u, 8u, 3u},   {0x18d018u, 48u, 8u, 3u},
    {0x18d020u, 48u, 8u, 3u},   {0x18d024u, 64u, 8u, 3u},   {0x18d028u, 48u, 8u, 3u},
    {0x18d030u, 32u, 8u, 3u},   {0x18d038u, 48u, 8u, 3u},   {0x18d03cu, 32u, 8u, 3u},
    {0x18d044u, 96u, 8u, 3u},   {0x18d050u, 32u, 8u, 3u},   {0x18d05cu, 80u, 8u, 3u},
    {0x18d068u, 32u, 8u, 3u},   {0x18d074u, 48u, 8u, 3u},   {0x18d078u, 48u, 8u, 3u},
    {0x18d07cu, 48u, 8u, 3u},   {0x18d080u, 16u, 8u, 3u},   {0x18d08cu, 80u, 8u, 3u},
    {0x18d090u, 48u, 8u, 3u},   {0x18d094u, 80u, 8u, 3u},   {0x18d098u, 48u, 8u, 3u},
    {0x18d09cu, 48u, 8u, 3u},   {0x18d0a8u, 96u, 8u, 3u},   {0x18d0acu, 80u, 8u, 3u},
    {0x18d0b0u, 48u, 8u, 3u},   {0x18d0b8u, 80u, 8u, 3u},   {0x18d0c4u, 48u, 8u, 3u},
    {0x18d0c8u, 80u, 8u, 3u},   {0x18d0ccu, 48u, 8u, 3u},   {0x18d0d4u, 48u, 8u, 3u},
    {0x18d0e0u, 80u, 8u, 3u},   {0x18d0e4u, 48u, 8u, 3u},   {0x18d0e8u, 48u, 8u, 3u},
    {0x18d0fcu, 80u, 8u, 3u},   {0x18d100u, 48u, 8u, 3u},   {0x18d104u, 48u, 8u, 3u},
    {0x18d10cu, 32u, 8u, 3u},   {0x18d130u, 32u, 8u, 3u},   {0x18d138u, 32u, 8u, 3u},
    {0x18d140u, 496u, 8u, 3u},  {0x18d144u, 320u, 16u, 3u}, {0x18d148u, 304u, 16u, 3u},
    {0x18d14cu, 288u, 16u, 3u}, {0x18d150u, 272u, 16u, 3u}, {0x18d154u, 256u, 16u, 3u},
    {0x18d15cu, 464u, 8u, 3u},  {0x18ddd0u, 464u, 8u, 2u},  {0x18ddd4u, 32u, 8u, 2u},
    {0x18dddcu, 16u, 8u, 2u},   {0x18dde4u, 96u, 8u, 2u},   {0x18dde8u, 112u, 8u, 2u},
    {0x18ddecu, 256u, 8u, 2u},  {0x18ddf0u, 16u, 8u, 2u},   {0x18ddf4u, 32u, 8u, 2u},
    {0x18ddf8u, 48u, 8u, 2u},   {0x18ddfcu, 32u, 8u, 2u},   {0x18de00u, 32u, 8u, 2u},
    {0x18de04u, 64u, 8u, 2u},   {0x18de08u, 16u, 8u, 2u},   {0x18de14u, 496u, 8u, 2u},
    {0x18de1cu, 16u, 8u, 2u},   {0x18de20u, 32u, 8u, 2u},   {0x18de24u, 64u, 8u, 2u},
    {0x18de28u, 16u, 8u, 2u},   {0x18de30u, 496u, 8u, 2u},  {0x18de34u, 256u, 16u, 2u},
    {0x18de3cu, 464u, 8u, 2u},  {0x1a0d70u, 80u, 8u, 3u},   {0x1a0d74u, 64u, 8u, 3u},
    {0x1a0d7cu, 64u, 8u, 3u},   {0x1a1330u, 32u, 8u, 3u},   {0x1a1334u, 48u, 8u, 3u},
    {0x1a1338u, 16u, 8u, 3u},   {0x1a1340u, 32u, 8u, 3u},   {0x1a1354u, 32u, 8u, 3u},
    {0x1a1358u, 48u, 8u, 3u},   {0x1a135cu, 32u, 8u, 3u},   {0x1a1360u, 32u, 8u, 3u},
}};
struct StatePacketStore {
    uint32_t pc, bytes, stage;
};
inline constexpr std::array<StatePacketStore, 44> StatePacketStores{{
    {0x197908u, 8u, 1u},  {0x197910u, 16u, 1u}, {0x197914u, 16u, 1u}, {0x197ad0u, 8u, 2u},
    {0x197ad8u, 4u, 2u},  {0x197ae0u, 4u, 2u},  {0x197b00u, 8u, 2u},  {0x197b0cu, 8u, 2u},
    {0x197b30u, 8u, 2u},  {0x197b34u, 8u, 2u},  {0x197b3cu, 8u, 2u},  {0x197b44u, 8u, 2u},
    {0x197b48u, 8u, 2u},  {0x197b50u, 8u, 2u},  {0x197b5cu, 8u, 2u},  {0x197b68u, 8u, 2u},
    {0x197b6cu, 8u, 2u},  {0x197b70u, 8u, 2u},  {0x197b74u, 8u, 2u},  {0x197b78u, 8u, 2u},
    {0x18cfb8u, 8u, 3u},  {0x18cfbcu, 16u, 3u}, {0x18cfc0u, 16u, 3u}, {0x18cfc8u, 16u, 3u},
    {0x18cfd0u, 16u, 3u}, {0x18cfdcu, 16u, 3u}, {0x18d01cu, 4u, 3u},  {0x18d02cu, 4u, 3u},
    {0x18d034u, 4u, 3u},  {0x18d048u, 4u, 3u},  {0x18d04cu, 4u, 3u},  {0x18d058u, 4u, 3u},
    {0x18d0d0u, 4u, 3u},  {0x18d0dcu, 4u, 3u},  {0x18d108u, 4u, 3u},  {0x18d118u, 4u, 3u},
    {0x18d120u, 4u, 3u},  {0x18d124u, 4u, 3u},  {0x18d128u, 4u, 3u},  {0x18d134u, 4u, 3u},
    {0x18d13cu, 4u, 3u},  {0x18ddd8u, 8u, 2u},  {0x18dde0u, 16u, 2u}, {0x18de2cu, 4u, 2u},
}};
inline bool statePacketNumericContext(uint32_t pc, uint32_t at, uint32_t bytes, uint32_t stage) {
    return std::any_of(StatePacketContextWrites.begin(), StatePacketContextWrites.end(),
                       [&](const auto& w) {
                           return w.pc == pc && w.stage == stage &&
                                  statePacketContains(w.offset, w.bytes, at, bytes);
                       });
}
inline constexpr std::array<StatePacketContextWrite, 8> StatePacketHelperRestores{{
    {0x18d140u, 496u, 8u, 3u},
    {0x18d144u, 320u, 16u, 3u},
    {0x18d148u, 304u, 16u, 3u},
    {0x18d14cu, 288u, 16u, 3u},
    {0x18d150u, 272u, 16u, 3u},
    {0x18d154u, 256u, 16u, 3u},
    {0x18de30u, 496u, 8u, 2u},
    {0x18de34u, 256u, 16u, 2u},
}};
inline bool statePacketPreserved(uint32_t pc, uint32_t at, uint32_t bytes, uint32_t stage) {
    return std::any_of(StatePacketHelperRestores.begin(), StatePacketHelperRestores.end(),
                       [&](const auto& w) {
                           return w.pc == pc && w.stage == stage &&
                                  statePacketContains(w.offset, w.bytes, at, bytes);
                       }) ||
           stage == 3u && ((pc == 0x197b98u && statePacketContains(31u * 16u, 8u, at, bytes)) ||
                           (pc == 0x197ba0u && statePacketContains(17u * 16u, 16u, at, bytes)) ||
                           (pc == 0x197ba4u && statePacketContains(16u * 16u, 16u, at, bytes)));
}
// Exact original JAL opcode/low64 destination catalogue. These sites belong
// to the retained immutable197900 source image, never an inferred pointer.
inline uint32_t statePacketJalOpcode(uint32_t pc, uint32_t stage) {
    if (stage == 1u && (pc == 0x197a8cu || pc == 0x197aa0u))
        return 0x0c063774u;
    if (stage == 2u && pc == 0x197b90u)
        return 0x0c0633ecu;
    return 0u;
}
inline bool statePacketJalReturn(uint32_t pc, uint32_t at, uint32_t bytes, uint32_t stage,
                                 uint32_t branch) {
    const uint32_t opcode = statePacketJalOpcode(pc, stage);
    return pc == branch && (opcode >> 26u) == 3u &&
           ((opcode & 0x03ffffffu) << 2u) == (stage == 1u ? 0x18ddd0u : 0x18cfb0u) &&
           statePacketContains(31u * 16u, 8u, at, bytes);
}
inline bool statePacketControlRange(uint32_t role, uint32_t pc, uint32_t at, uint32_t bytes,
                                    uint32_t stage, uint32_t sourceBranch) {
    using R = reo_source_closure::Role;
    switch (R(role)) {
        case R::GenuineControlPc:
            return pc == sourceBranch &&
                   (statePacketContains(uint32_t(offsetof(R5900Context, pc)), 4u, at, bytes) ||
                    statePacketContains(uint32_t(offsetof(R5900Context, branch_pc)), 4u, at,
                                        bytes) ||
                    statePacketJalReturn(pc, at, bytes, stage, sourceBranch));
        case R::GenuineControlStack:
            return ((stage == 1u && pc == 0x197900u) || (stage == 2u && pc == 0x18de3cu) ||
                    (stage == 3u && pc == 0x197bacu)) &&
                   statePacketContains(29u * 16u, 8u, at, bytes);
        case R::GenuineScalarReturn:
            return (pc == sourceBranch &&
                    statePacketContains(uint32_t(offsetof(R5900Context, in_delay_slot)), 1u, at,
                                        bytes)) ||
                   (stage == 3u && pc == 0x197b9cu && statePacketContains(2u * 16u, 8u, at, bytes));
        default:
            return false;
    }
}
// Per-stage effects belong to this exact immutable GPU output. Metadata decoding
// authorizes no bank read or EE write. Service retains the real fence and call.
template <class CallMetadata>
inline StatePacketEffectsPacket decodeStatePacketEffectsMetadata(
    const CallMetadata& call, const Parameters& p, std::span<const uint32_t, ReceiptWords> receipt,
    std::span<const uint32_t, 32> control, std::span<const uint32_t> words, uint32_t stage,
    uint32_t priorInstructions) {
    using namespace reo_source_closure;
    if (stage < 1u || stage > 3u || words.size() != StatePacketEffectsWords)
        throw std::invalid_argument("197900 stage effects shape differs");
    const auto& s = call.stamp();
    const std::array<uint32_t, 8> stamp{p.sessionLo, p.sessionHi, p.epochLo,   p.epochHi,
                                        p.bankLo,    p.bankHi,    p.ordinalLo, p.ordinalHi};
    const auto before = receipt[17], after = receipt[18],
               branch = stage == 1u   ? control[15] - 8u
                        : stage == 2u ? 0x197b90u
                                      : 0x197ba8u;
    StatePacketEffectsPacket out;
    std::memcpy(&out.header, words.data(), sizeof(out.header));
    const auto& h = out.header;
    if (!call.issuer() || !s.session || !s.epoch || !s.bankGeneration || !s.ordinal ||
        call.entry() != 0x197900u || call.a0() || call.a1() || call.a2() || call.task() < 1 ||
        receipt[0] || receipt[1] != 0x53505231u || receipt[2] != 1u || receipt[3] != stage ||
        receipt[12] != p.entry || receipt[13] != p.returnPc || receipt[14] || receipt[15] ||
        receipt[16] || receipt[19] <= priorInstructions || receipt[19] > 65536u ||
        (stage == 1u && priorInstructions) || (stage > 1u && !priorInstructions) || h.status ||
        h.magic != EffectsMagic || h.version != EffectsVersion || h.committed != 1u ||
        h.stamp != stamp || h.originalEntry != p.entry || h.actualFinalPc != after ||
        h.actualTask != uint32_t(call.task()) || h.profile != 0x197900u ||
        h.dirtyCapacity != CompositionEffectsDirtyCapacity ||
        h.controlCapacity != CompositionEffectsControlCapacity || h.dirtyCount > h.dirtyCapacity ||
        h.controlCount > h.controlCapacity || control[0] || control[1] != 0x53504331u ||
        control[2] != 1u || control[3] != stage || control[12] != p.entry ||
        control[13] != p.returnPc || control[26] != uint32_t(call.task()) ||
        control[27] != branch || control[28] != 0x197900u || control[29] != stage ||
        control[30] != after || control[31] > 512u)
        throw std::invalid_argument("197900 stage source/effects envelope refused");
    for (unsigned k = 0; k < 8u; ++k)
        if (receipt[4u + k] != stamp[k] || control[4u + k] != stamp[k])
            throw std::invalid_argument("197900 stage stamp differs");
    if (stage == 1u) {
        if (before != 0x197900u || after != 0x18ddd0u || control[14] != after ||
            (control[15] != 0x197a94u && control[15] != 0x197aa8u) ||
            control[16] != (control[15] == 0x197a94u ? 48u : 64u) || control[17] ||
            control[18] != 16u || control[19])
            throw std::invalid_argument("197900 original allocation source differs");
    } else if (stage == 2u) {
        if ((before != 0x197a94u && before != 0x197aa8u) || after != 0x18cfb0u ||
            control[14] != after || control[15] != 0x197b98u || control[16] || control[17] ||
            control[19] || control[21] || control[22] != 0x29f6f0u || control[23] ||
            control[18] != (control[20] & 0x0fffffffu))
            throw std::invalid_argument("197900 original queue source differs");
    } else if (before != 0x197b98u || after != p.returnPc || control[14] ||
               control[15] != p.returnPc)
        throw std::invalid_argument("197900 actual final source return differs");
    const uint32_t consumed = stage == 1u ? 2u : stage == 2u ? 4u : 0u;
    for (uint32_t r = consumed; r < 4u; ++r)
        if (control[16u + r * 2u] || control[17u + r * 2u])
            throw std::invalid_argument("197900 unused numerical argument was exposed");
    out.dirty.resize(h.dirtyCount);
    out.control.resize(h.controlCount);
    for (uint32_t k = 0; k < h.dirtyCount; ++k) {
        auto& d = out.dirty[k];
        std::memcpy(&d, words.data() + 20u + k * 6u, sizeof(d));
        const auto cap = d.space == uint32_t(Space::Ram)       ? RamBytes
                         : d.space == uint32_t(Space::Spr)     ? SprBytes
                         : d.space == uint32_t(Space::Context) ? ContextBytes
                                                               : 0u;
        if (!cap || !d.bytes || d.offset >= cap || d.bytes > cap - d.offset ||
            d.sourceOrdinal <= priorInstructions || d.sourceOrdinal > receipt[19])
            throw std::invalid_argument("197900 dirty source span differs");
        if (d.space != uint32_t(Space::Context)) {
            const bool source =
                std::any_of(StatePacketStores.begin(), StatePacketStores.end(), [&](const auto& w) {
                    return w.stage == stage && w.pc == d.sourcePc && d.bytes <= w.bytes;
                });
            const bool saved =
                (stage == 1u &&
                 (d.sourcePc == 0x197908u || d.sourcePc == 0x197910u || d.sourcePc == 0x197914u)) ||
                (stage == 2u && (d.sourcePc == 0x18ddd8u || d.sourcePc == 0x18dde0u)) ||
                (stage == 3u &&
                 (d.sourcePc == 0x18cfb8u || d.sourcePc == 0x18cfbcu || d.sourcePc == 0x18cfc0u ||
                  d.sourcePc == 0x18cfc8u || d.sourcePc == 0x18cfd0u || d.sourcePc == 0x18cfdcu));
            if (!source ||
                d.role != uint32_t(saved ? Role::PrivateStackCarry : Role::OpaqueGraphicsNumeric))
                throw std::invalid_argument("197900 memory opcode/role differs");
        } else if (!((d.role == uint32_t(Role::OpaqueGraphicsNumeric) &&
                      statePacketNumericContext(d.sourcePc, d.offset, d.bytes, stage)) ||
                     (d.role == uint32_t(Role::PreservedIncomingLease) &&
                      statePacketPreserved(d.sourcePc, d.offset, d.bytes, stage)) ||
                     statePacketControlRange(d.role, d.sourcePc, d.offset, d.bytes, stage, branch)))
            throw std::invalid_argument("197900 Context opcode/role differs");
        for (uint32_t j = 0; j < k; ++j) {
            const auto& old = out.dirty[j];
            if (d.space == old.space && d.offset < old.offset + old.bytes &&
                old.offset < d.offset + d.bytes)
                throw std::invalid_argument("197900 stage final dirty spans overlap");
        }
    }
    bool pc = false, branchPc = false, delay = false, stack = false, boolean = false,
         jalReturn = false;
    const auto associated = [](const DirtySpan& d, const ControlWord& c) {
        return d.space == uint32_t(Space::Context) && d.role == c.role && d.sourcePc == c.sourcePc;
    };
    for (uint32_t k = 0; k < h.controlCount; ++k) {
        auto& c = out.control[k];
        std::memcpy(&c, words.data() + 20u + CompositionEffectsDirtyCapacity * 6u + k * 8u,
                    sizeof(c));
        if (!c.bytes || c.bytes > 16u ||
            !statePacketControlRange(c.role, c.sourcePc, c.contextOffset, c.bytes, stage, branch))
            throw std::invalid_argument("197900 scalar source role differs");
        for (uint32_t b = c.bytes; b < 16u; ++b)
            if ((c.bits[b / 4u] >> ((b & 3u) * 8u)) & 255u)
                throw std::invalid_argument("197900 scalar padding differs");
        for (uint32_t j = 0; j < k; ++j) {
            const auto& old = out.control[j];
            if (c.contextOffset < old.contextOffset + old.bytes &&
                old.contextOffset < c.contextOffset + c.bytes)
                throw std::invalid_argument("197900 scalar controls overlap");
        }
        uint32_t covered = 0u;
        for (const auto& d : out.dirty)
            if (associated(d, c)) {
                const auto begin = std::max(d.offset, c.contextOffset),
                           end = std::min(d.offset + d.bytes, c.contextOffset + c.bytes);
                if (begin < end)
                    covered += end - begin;
            }
        if (covered != c.bytes)
            throw std::invalid_argument("197900 scalar lacks full matching source dirty");
        if (c.contextOffset == offsetof(R5900Context, pc)) {
            pc = c.bytes == 4u && c.bits[0] == after;
            if (!pc)
                throw std::invalid_argument("197900 actual PC differs");
        }
        if (c.contextOffset == offsetof(R5900Context, branch_pc)) {
            branchPc = c.bytes == 4u && c.bits[0] == branch;
            if (!branchPc)
                throw std::invalid_argument("197900 actual branch PC differs");
        }
        if (c.contextOffset == offsetof(R5900Context, in_delay_slot)) {
            delay = c.bytes == 1u && !c.bits[0];
            if (!delay)
                throw std::invalid_argument("197900 actual delay differs");
        }
        if (c.contextOffset == 31u * 16u) {
            jalReturn = c.role == uint32_t(Role::GenuineControlPc) && c.bytes == 8u &&
                        statePacketJalReturn(c.sourcePc, c.contextOffset, c.bytes, stage, branch) &&
                        c.bits[0] == c.sourcePc + 8u && !c.bits[1];
            if (!jalReturn)
                throw std::invalid_argument("197900 exact JAL return-PC source/value differs");
        }
        if (c.contextOffset == 29u * 16u) {
            stack = c.bytes == 8u && c.bits[0] == control[24] && c.bits[1] == control[25];
            if (!stack)
                throw std::invalid_argument("197900 actual SP differs");
        }
        if (c.contextOffset == 2u * 16u) {
            boolean = c.bytes == 8u && c.bits[0] == 1u && !c.bits[1];
            if (!boolean)
                throw std::invalid_argument("197900 actual Boolean return differs");
        }
    }
    for (const auto& d : out.dirty)
        if (d.space == uint32_t(Space::Context) && d.role >= 3u && d.role <= 7u) {
            uint32_t covered = 0u;
            for (const auto& c : out.control)
                if (associated(d, c)) {
                    const auto begin = std::max(d.offset, c.contextOffset),
                               end = std::min(d.offset + d.bytes, c.contextOffset + c.bytes);
                    if (begin < end)
                        covered += end - begin;
                }
            if (covered != d.bytes)
                throw std::invalid_argument(
                    "197900 dirty control lacks complete scalar association");
        }
    if (!pc || !branchPc || !delay || ((stage == 1u || stage == 3u) && !stack) ||
        (stage == 3u && !boolean) || (stage < 3u && !jalReturn))
        throw std::invalid_argument("197900 stage required source controls absent");
    if (stage == 3u) {
        for (const auto& restore :
             std::array<StatePacketContextWrite, 3>{{{0x197b98u, 31u * 16u, 8u, 3u},
                                                     {0x197ba0u, 17u * 16u, 16u, 3u},
                                                     {0x197ba4u, 16u * 16u, 16u, 3u}}}) {
            uint32_t covered = 0u;
            for (const auto& d : out.dirty)
                if (d.space == uint32_t(Space::Context) && d.sourcePc == restore.pc &&
                    (d.role == uint32_t(Role::OpaqueGraphicsNumeric) ||
                     d.role == uint32_t(Role::PreservedIncomingLease))) {
                    const auto begin = std::max(d.offset, restore.offset),
                               end = std::min(d.offset + d.bytes, restore.offset + restore.bytes);
                    if (begin < end)
                        covered += end - begin;
                }
            if (covered != restore.bytes)
                throw std::invalid_argument("197900 exact saved-register restore absent");
        }
    }
    return out;
}
inline StatePacketEffectsPacket
decodeStatePacketEffects(const Call& call, std::span<const uint32_t, ReceiptWords> receipt,
                         std::span<const uint32_t, 32> control, std::span<const uint32_t> words,
                         uint32_t stage, uint32_t priorInstructions) {
    return decodeStatePacketEffectsMetadata(call, parameters(call), receipt, control, words, stage,
                                            priorInstructions);
}
} // namespace reo_gpu_upstream
