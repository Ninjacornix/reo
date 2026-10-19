#pragma once
#include "effects_packet.hpp"
#include <algorithm>
namespace reo_gpu_upstream {
inline constexpr uint32_t SetterEffectsProfile = 0x196010u;
inline constexpr uint32_t SetterEffectsDirtyCapacity = CompositionEffectsDirtyCapacity;
inline constexpr uint32_t SetterEffectsControlCapacity = CompositionEffectsControlCapacity;
inline constexpr uint32_t SetterEffectsWords = CompositionEffectsWords;
inline constexpr uint32_t SetterEffectsBytes = CompositionEffectsBytes;
// Same packet shape lets the existing interval ledger retain untouched lanes.
using SetterEffectsPacket = CompositionEffectsPacket;
inline constexpr bool setterEffectsCommand(uint32_t c) {
    return c == 0x10u || c == 0x11u || c == 0x16u || c == 0x17u || c == 0x19u || c == 0x67u ||
           (c >= 0x1au && c <= 0x5cu);
}
inline constexpr bool setterBooleanReturnPc(uint32_t pc) {
    switch (pc) {
        case 0x196044u:
        case 0x196080u:
        case 0x1960ecu:
        case 0x196194u:
        case 0x1961f4u:
        case 0x196ee0u:
            return true;
        default:
            return false;
    }
}
inline constexpr bool setterFcrWritePc(uint32_t pc) {
    switch (pc) {
        case 0x196198u:
        case 0x196704u:
        case 0x196750u:
        case 0x1967a0u:
        case 0x196c80u:
        case 0x196cccu:
        case 0x196d18u:
        case 0x196d60u:
            return true;
        default:
            return false;
    }
}
inline constexpr bool setterContains(uint32_t outer, uint32_t bytes, uint32_t at, uint32_t n) {
    return n && at >= outer && at - outer < bytes && n <= bytes - (at - outer);
}
// Exact context destinations of the frozen source instruction body, including
// masked VF/ACC widths. No numerical value participates in this catalogue.
// Frozen body SHA256: cf45ea629a6d6e0492efe94172c6a7e9556702355a59928a6ef8d830facb94b9
struct SetterContextWrite {
    uint32_t sourcePc, offset, bytes;
};
inline constexpr std::array<SetterContextWrite, 688> SetterContextWrites{{
    {0x191280u, 640u, 16u},  {0x191284u, 656u, 16u},  {0x191288u, 672u, 16u},
    {0x19128cu, 688u, 16u},  {0x191290u, 704u, 16u},  {0x191294u, 720u, 16u},
    {0x191298u, 736u, 16u},  {0x19129cu, 752u, 16u},  {0x1912a0u, 1152u, 16u},
    {0x1912a4u, 1152u, 16u}, {0x1912a8u, 1152u, 16u}, {0x1912acu, 704u, 16u},
    {0x1912b0u, 1152u, 16u}, {0x1912b4u, 1152u, 16u}, {0x1912b8u, 1152u, 16u},
    {0x1912bcu, 720u, 16u},  {0x1912c0u, 1152u, 16u}, {0x1912c4u, 1152u, 16u},
    {0x1912c8u, 1152u, 16u}, {0x1912ccu, 736u, 16u},  {0x1912d0u, 1152u, 16u},
    {0x1912d4u, 1152u, 16u}, {0x1912d8u, 1152u, 16u}, {0x1912dcu, 752u, 16u},
    {0x191d80u, 1516u, 4u},  {0x191d84u, 464u, 8u},   {0x191d88u, 1512u, 4u},
    {0x191d8cu, 48u, 8u},    {0x191d90u, 1508u, 4u},  {0x191da0u, 640u, 16u},
    {0x191da4u, 656u, 12u},  {0x191da8u, 656u, 4u},   {0x191dacu, 656u, 4u},
    {0x191db0u, 1120u, 4u},  {0x191db8u, 640u, 12u},  {0x191dc0u, 48u, 8u},
    {0x191dc4u, 1516u, 4u},  {0x191dc8u, 1512u, 4u},  {0x191dccu, 1508u, 4u},
    {0x191de0u, 464u, 8u},   {0x196010u, 464u, 8u},   {0x196020u, 256u, 8u},
    {0x196024u, 32u, 8u},    {0x196030u, 16u, 8u},    {0x196038u, 32u, 8u},
    {0x19603cu, 96u, 8u},    {0x196044u, 32u, 8u},    {0x196048u, 32u, 8u},
    {0x19604cu, 16u, 8u},    {0x196050u, 32u, 8u},    {0x196054u, 16u, 8u},
    {0x196058u, 64u, 8u},    {0x19605cu, 80u, 8u},    {0x196060u, 48u, 8u},
    {0x196064u, 64u, 8u},    {0x196068u, 32u, 8u},    {0x196070u, 96u, 8u},
    {0x19607cu, 80u, 8u},    {0x196080u, 32u, 8u},    {0x196088u, 496u, 8u},
    {0x19608cu, 32u, 8u},    {0x196094u, 32u, 8u},    {0x196098u, 16u, 8u},
    {0x1960a0u, 96u, 8u},    {0x1960a4u, 32u, 8u},    {0x1960a8u, 48u, 8u},
    {0x1960acu, 64u, 8u},    {0x1960b0u, 80u, 8u},    {0x1960b4u, 32u, 8u},
    {0x1960b8u, 80u, 8u},    {0x1960bcu, 48u, 8u},    {0x1960c0u, 80u, 8u},
    {0x1960c4u, 80u, 8u},    {0x1960c8u, 80u, 8u},    {0x1960ccu, 32u, 8u},
    {0x1960d0u, 48u, 8u},    {0x1960d8u, 64u, 8u},    {0x1960dcu, 80u, 8u},
    {0x1960ecu, 32u, 8u},    {0x1960f4u, 16u, 8u},    {0x1960fcu, 32u, 8u},
    {0x196100u, 272u, 8u},   {0x196104u, 32u, 8u},    {0x196108u, 48u, 8u},
    {0x19610cu, 96u, 8u},    {0x196110u, 48u, 8u},    {0x196114u, 32u, 8u},
    {0x196118u, 48u, 8u},    {0x19611cu, 64u, 8u},    {0x196120u, 48u, 8u},
    {0x196124u, 256u, 8u},   {0x196128u, 112u, 8u},   {0x19612cu, 80u, 8u},
    {0x196130u, 48u, 8u},    {0x196134u, 64u, 8u},    {0x196138u, 32u, 8u},
    {0x196140u, 96u, 8u},    {0x19614cu, 80u, 8u},    {0x196154u, 64u, 8u},
    {0x196158u, 32u, 8u},    {0x19615cu, 64u, 8u},    {0x196160u, 32u, 8u},
    {0x196164u, 48u, 8u},    {0x196168u, 32u, 8u},    {0x196170u, 32u, 8u},
    {0x196174u, 32u, 8u},    {0x19617cu, 32u, 8u},    {0x196180u, 32u, 8u},
    {0x196184u, 48u, 8u},    {0x196188u, 1508u, 4u},  {0x19618cu, 32u, 8u},
    {0x196190u, 1512u, 4u},  {0x196194u, 32u, 8u},    {0x196198u, 1508u, 4u},
    {0x19619cu, 48u, 8u},    {0x1961a0u, 48u, 8u},    {0x1961a4u, 48u, 8u},
    {0x1961b8u, 32u, 8u},    {0x1961c0u, 32u, 8u},    {0x1961ccu, 32u, 8u},
    {0x1961d4u, 16u, 8u},    {0x1961d8u, 32u, 8u},    {0x1961e0u, 32u, 8u},
    {0x1961ecu, 32u, 8u},    {0x1961f4u, 32u, 8u},    {0x1961f8u, 32u, 8u},
    {0x196200u, 32u, 8u},    {0x196208u, 16u, 8u},    {0x19620cu, 32u, 8u},
    {0x196214u, 32u, 8u},    {0x19621cu, 16u, 8u},    {0x196220u, 32u, 8u},
    {0x196228u, 16u, 8u},    {0x19622cu, 32u, 8u},    {0x196234u, 16u, 8u},
    {0x196238u, 32u, 8u},    {0x196240u, 16u, 8u},    {0x196244u, 32u, 8u},
    {0x19624cu, 32u, 8u},    {0x196254u, 16u, 8u},    {0x196258u, 32u, 8u},
    {0x196260u, 48u, 8u},    {0x196268u, 32u, 8u},    {0x196274u, 32u, 8u},
    {0x19627cu, 32u, 8u},    {0x196284u, 16u, 8u},    {0x196288u, 32u, 8u},
    {0x196290u, 64u, 8u},    {0x19629cu, 64u, 8u},    {0x1962a4u, 16u, 8u},
    {0x1962a8u, 64u, 8u},    {0x1962b0u, 144u, 8u},   {0x1962b8u, 64u, 8u},
    {0x1962c0u, 16u, 8u},    {0x1962c4u, 64u, 8u},    {0x1962ccu, 64u, 8u},
    {0x1962d4u, 16u, 8u},    {0x1962d8u, 64u, 8u},    {0x1962e0u, 16u, 8u},
    {0x1962e4u, 64u, 8u},    {0x1962ecu, 16u, 8u},    {0x1962f0u, 128u, 8u},
    {0x1962f8u, 16u, 8u},    {0x1962fcu, 64u, 8u},    {0x196304u, 64u, 8u},
    {0x196310u, 64u, 8u},    {0x196318u, 112u, 8u},   {0x196320u, 64u, 8u},
    {0x19632cu, 64u, 8u},    {0x196334u, 64u, 8u},    {0x19633cu, 96u, 8u},
    {0x196344u, 64u, 8u},    {0x19634cu, 16u, 8u},    {0x196350u, 32u, 8u},
    {0x196358u, 16u, 8u},    {0x19635cu, 32u, 8u},    {0x19636cu, 16u, 8u},
    {0x196378u, 48u, 8u},    {0x19637cu, 64u, 8u},    {0x196380u, 32u, 8u},
    {0x196384u, 48u, 8u},    {0x196388u, 16u, 8u},    {0x196390u, 16u, 8u},
    {0x196394u, 48u, 8u},    {0x196398u, 32u, 8u},    {0x19639cu, 16u, 8u},
    {0x1963a8u, 48u, 8u},    {0x1963acu, 64u, 8u},    {0x1963b0u, 32u, 8u},
    {0x1963b4u, 32u, 8u},    {0x1963b8u, 16u, 8u},    {0x1963c4u, 32u, 8u},
    {0x1963ccu, 16u, 8u},    {0x1963d0u, 32u, 8u},    {0x1963d8u, 16u, 8u},
    {0x1963dcu, 32u, 8u},    {0x1963e4u, 16u, 8u},    {0x1963e8u, 32u, 8u},
    {0x1963f0u, 16u, 8u},    {0x1963f4u, 32u, 8u},    {0x1963fcu, 16u, 8u},
    {0x196400u, 32u, 8u},    {0x196408u, 16u, 8u},    {0x19640cu, 32u, 8u},
    {0x196414u, 16u, 8u},    {0x196418u, 32u, 8u},    {0x196420u, 16u, 8u},
    {0x19642cu, 32u, 8u},    {0x196430u, 32u, 8u},    {0x196434u, 16u, 8u},
    {0x196440u, 32u, 8u},    {0x196444u, 32u, 8u},    {0x196448u, 16u, 8u},
    {0x196454u, 32u, 8u},    {0x196458u, 32u, 8u},    {0x19645cu, 16u, 8u},
    {0x196468u, 32u, 8u},    {0x19646cu, 32u, 8u},    {0x196470u, 16u, 8u},
    {0x19647cu, 32u, 8u},    {0x196480u, 32u, 8u},    {0x196484u, 16u, 8u},
    {0x196490u, 32u, 8u},    {0x196494u, 32u, 8u},    {0x196498u, 16u, 8u},
    {0x1964a4u, 32u, 8u},    {0x1964a8u, 32u, 8u},    {0x1964acu, 16u, 8u},
    {0x1964b8u, 32u, 8u},    {0x1964bcu, 32u, 8u},    {0x1964c0u, 16u, 8u},
    {0x1964ccu, 160u, 8u},   {0x1964d0u, 80u, 8u},    {0x1964d4u, 64u, 8u},
    {0x1964d8u, 64u, 8u},    {0x1964dcu, 16u, 8u},    {0x196520u, 16u, 8u},
    {0x196524u, 32u, 8u},    {0x196528u, 32u, 8u},    {0x19652cu, 16u, 8u},
    {0x196538u, 48u, 8u},    {0x19653cu, 32u, 8u},    {0x196548u, 64u, 8u},
    {0x196550u, 80u, 8u},    {0x196558u, 64u, 8u},    {0x19655cu, 32u, 8u},
    {0x196560u, 16u, 8u},    {0x196568u, 64u, 8u},    {0x19656cu, 32u, 8u},
    {0x196570u, 48u, 8u},    {0x196574u, 32u, 8u},    {0x196578u, 32u, 8u},
    {0x19657cu, 32u, 8u},    {0x196588u, 48u, 8u},    {0x19658cu, 80u, 8u},
    {0x196590u, 64u, 8u},    {0x196594u, 32u, 8u},    {0x196598u, 64u, 8u},
    {0x19659cu, 16u, 8u},    {0x1965a8u, 16u, 8u},    {0x1965acu, 32u, 8u},
    {0x1965b0u, 32u, 8u},    {0x1965b4u, 16u, 8u},    {0x1965c0u, 64u, 8u},
    {0x1965c4u, 48u, 8u},    {0x1965c8u, 32u, 8u},    {0x1965d0u, 32u, 8u},
    {0x1965d4u, 16u, 8u},    {0x1965d8u, 32u, 8u},    {0x1965e0u, 16u, 8u},
    {0x1965e4u, 32u, 8u},    {0x1965e8u, 32u, 8u},    {0x1965ecu, 16u, 8u},
    {0x1965f4u, 16u, 8u},    {0x1965f8u, 64u, 8u},    {0x196600u, 80u, 8u},
    {0x19660cu, 64u, 8u},    {0x196610u, 48u, 8u},    {0x196614u, 32u, 8u},
    {0x19661cu, 32u, 8u},    {0x196620u, 16u, 8u},    {0x196624u, 32u, 8u},
    {0x19662cu, 16u, 8u},    {0x196630u, 32u, 8u},    {0x196634u, 32u, 8u},
    {0x196638u, 16u, 8u},    {0x196640u, 16u, 8u},    {0x196644u, 64u, 8u},
    {0x19664cu, 80u, 8u},    {0x196658u, 64u, 8u},    {0x19665cu, 48u, 8u},
    {0x196660u, 32u, 8u},    {0x196664u, 32u, 8u},    {0x19666cu, 32u, 8u},
    {0x196670u, 16u, 8u},    {0x196674u, 32u, 8u},    {0x196678u, 32u, 8u},
    {0x196680u, 16u, 8u},    {0x196684u, 32u, 8u},    {0x196688u, 32u, 8u},
    {0x19668cu, 16u, 8u},    {0x196694u, 16u, 8u},    {0x196698u, 64u, 8u},
    {0x1966a0u, 80u, 8u},    {0x1966acu, 32u, 8u},    {0x1966b0u, 16u, 8u},
    {0x1966b8u, 16u, 8u},    {0x1966bcu, 64u, 8u},    {0x1966c0u, 32u, 8u},
    {0x1966c4u, 32u, 8u},    {0x1966ccu, 48u, 8u},    {0x1966d0u, 1508u, 4u},
    {0x1966d8u, 1512u, 4u},  {0x1966dcu, 32u, 8u},    {0x1966e0u, 48u, 8u},
    {0x1966e4u, 1508u, 4u},  {0x1966ecu, 1512u, 4u},  {0x1966f0u, 1512u, 4u},
    {0x1966f4u, 48u, 8u},    {0x1966f8u, 32u, 8u},    {0x1966fcu, 1508u, 4u},
    {0x196700u, 32u, 8u},    {0x196704u, 1508u, 4u},  {0x19670cu, 16u, 8u},
    {0x196718u, 1508u, 4u},  {0x196720u, 1512u, 4u},  {0x196724u, 48u, 8u},
    {0x196728u, 32u, 8u},    {0x19672cu, 48u, 8u},    {0x196730u, 1508u, 4u},
    {0x196738u, 1512u, 4u},  {0x19673cu, 1512u, 4u},  {0x196740u, 48u, 8u},
    {0x196744u, 32u, 8u},    {0x196748u, 1508u, 4u},  {0x196750u, 1508u, 4u},
    {0x196758u, 16u, 8u},    {0x196764u, 1508u, 4u},  {0x19676cu, 1512u, 4u},
    {0x196770u, 48u, 8u},    {0x196774u, 32u, 8u},    {0x196778u, 48u, 8u},
    {0x19677cu, 1508u, 4u},  {0x196784u, 1512u, 4u},  {0x196788u, 1512u, 4u},
    {0x19678cu, 48u, 8u},    {0x196790u, 32u, 8u},    {0x196794u, 1508u, 4u},
    {0x196798u, 64u, 8u},    {0x19679cu, 32u, 8u},    {0x1967a0u, 1508u, 4u},
    {0x1967a8u, 16u, 8u},    {0x1967b4u, 32u, 8u},    {0x1967b8u, 16u, 8u},
    {0x1967c8u, 16u, 8u},    {0x1967ccu, 64u, 8u},    {0x1967d8u, 64u, 8u},
    {0x1967e0u, 48u, 8u},    {0x1967e4u, 1508u, 4u},  {0x1967ecu, 1508u, 4u},
    {0x1967f0u, 32u, 8u},    {0x1967f4u, 48u, 8u},    {0x1967f8u, 1508u, 4u},
    {0x196800u, 1508u, 4u},  {0x196804u, 1508u, 4u},  {0x196808u, 16u, 8u},
    {0x19681cu, 64u, 8u},    {0x196820u, 32u, 8u},    {0x19682cu, 16u, 8u},
    {0x196840u, 1508u, 4u},  {0x196844u, 16u, 8u},    {0x196850u, 1508u, 4u},
    {0x196854u, 16u, 8u},    {0x196860u, 32u, 8u},    {0x196864u, 80u, 8u},
    {0x196868u, 64u, 8u},    {0x19686cu, 48u, 8u},    {0x196870u, 32u, 8u},
    {0x196874u, 64u, 8u},    {0x196878u, 16u, 8u},    {0x196884u, 16u, 8u},
    {0x196888u, 32u, 8u},    {0x19688cu, 32u, 8u},    {0x196890u, 16u, 8u},
    {0x1968a0u, 64u, 8u},    {0x1968acu, 64u, 8u},    {0x1968b0u, 48u, 8u},
    {0x1968b4u, 32u, 8u},    {0x1968b8u, 32u, 8u},    {0x1968bcu, 16u, 8u},
    {0x1968c8u, 32u, 8u},    {0x1968d0u, 16u, 8u},    {0x1968d4u, 32u, 8u},
    {0x1968d8u, 32u, 8u},    {0x1968dcu, 16u, 8u},    {0x1968e8u, 96u, 8u},
    {0x1968ecu, 32u, 8u},    {0x1968f0u, 80u, 8u},    {0x1968f4u, 64u, 8u},
    {0x1968f8u, 48u, 8u},    {0x1968fcu, 64u, 8u},    {0x196900u, 32u, 8u},
    {0x196908u, 96u, 8u},    {0x196914u, 80u, 8u},    {0x196920u, 96u, 8u},
    {0x196924u, 32u, 8u},    {0x196928u, 80u, 8u},    {0x19692cu, 64u, 8u},
    {0x196930u, 48u, 8u},    {0x196934u, 64u, 8u},    {0x196938u, 32u, 8u},
    {0x196940u, 96u, 8u},    {0x19694cu, 80u, 8u},    {0x196950u, 32u, 8u},
    {0x196954u, 64u, 8u},    {0x196958u, 64u, 8u},    {0x19695cu, 80u, 8u},
    {0x196964u, 96u, 8u},    {0x196968u, 64u, 8u},    {0x19696cu, 32u, 8u},
    {0x196970u, 96u, 8u},    {0x196974u, 64u, 8u},    {0x196978u, 80u, 8u},
    {0x196980u, 96u, 8u},    {0x19698cu, 32u, 8u},    {0x196990u, 80u, 8u},
    {0x196994u, 1556u, 4u},  {0x196998u, 96u, 8u},    {0x19699cu, 1560u, 4u},
    {0x1969a0u, 112u, 8u},   {0x1969a4u, 128u, 8u},   {0x1969acu, 64u, 8u},
    {0x1969b8u, 96u, 8u},    {0x1969bcu, 32u, 8u},    {0x1969c0u, 80u, 8u},
    {0x1969c4u, 64u, 8u},    {0x1969c8u, 48u, 8u},    {0x1969ccu, 64u, 8u},
    {0x1969d0u, 32u, 8u},    {0x1969d8u, 96u, 8u},    {0x1969e4u, 80u, 8u},
    {0x1969f0u, 32u, 8u},    {0x1969f4u, 48u, 8u},    {0x1969f8u, 48u, 8u},
    {0x1969fcu, 16u, 8u},    {0x196a00u, 48u, 8u},    {0x196a08u, 16u, 8u},
    {0x196a0cu, 48u, 8u},    {0x196a10u, 32u, 8u},    {0x196a14u, 16u, 8u},
    {0x196a20u, 32u, 8u},    {0x196a24u, 16u, 8u},    {0x196a30u, 48u, 8u},
    {0x196a34u, 32u, 8u},    {0x196a38u, 48u, 8u},    {0x196a3cu, 32u, 8u},
    {0x196a40u, 32u, 8u},    {0x196a4cu, 32u, 8u},    {0x196a58u, 32u, 8u},
    {0x196a64u, 32u, 8u},    {0x196a70u, 32u, 8u},    {0x196a84u, 32u, 8u},
    {0x196a90u, 32u, 8u},    {0x196a9cu, 32u, 8u},    {0x196aa4u, 16u, 8u},
    {0x196aa8u, 64u, 8u},    {0x196aacu, 48u, 8u},    {0x196ab0u, 32u, 8u},
    {0x196ab4u, 32u, 8u},    {0x196abcu, 32u, 8u},    {0x196ac0u, 16u, 8u},
    {0x196ac4u, 32u, 8u},    {0x196ac8u, 32u, 8u},    {0x196ad0u, 16u, 8u},
    {0x196ad4u, 32u, 8u},    {0x196ad8u, 32u, 8u},    {0x196adcu, 16u, 8u},
    {0x196ae4u, 16u, 8u},    {0x196ae8u, 64u, 8u},    {0x196af0u, 80u, 8u},
    {0x196afcu, 48u, 8u},    {0x196b00u, 32u, 8u},    {0x196b0cu, 16u, 8u},
    {0x196b14u, 16u, 8u},    {0x196b18u, 64u, 8u},    {0x196b20u, 80u, 8u},
    {0x196b2cu, 32u, 8u},    {0x196b30u, 64u, 8u},    {0x196b34u, 48u, 8u},
    {0x196b38u, 48u, 8u},    {0x196b3cu, 16u, 8u},    {0x196b48u, 16u, 8u},
    {0x196b4cu, 32u, 8u},    {0x196b50u, 32u, 8u},    {0x196b54u, 16u, 8u},
    {0x196b60u, 32u, 8u},    {0x196b64u, 80u, 8u},    {0x196b68u, 64u, 8u},
    {0x196b6cu, 32u, 8u},    {0x196b70u, 48u, 8u},    {0x196b74u, 64u, 8u},
    {0x196b78u, 16u, 8u},    {0x196b84u, 16u, 8u},    {0x196b88u, 32u, 8u},
    {0x196b8cu, 32u, 8u},    {0x196b90u, 16u, 8u},    {0x196b98u, 16u, 8u},
    {0x196b9cu, 64u, 8u},    {0x196ba4u, 80u, 8u},    {0x196bb0u, 32u, 8u},
    {0x196bb4u, 48u, 8u},    {0x196bb8u, 32u, 8u},    {0x196bbcu, 64u, 8u},
    {0x196bc0u, 32u, 8u},    {0x196bc4u, 16u, 8u},    {0x196bd0u, 48u, 8u},
    {0x196bd8u, 16u, 8u},    {0x196bdcu, 32u, 8u},    {0x196be0u, 32u, 8u},
    {0x196be4u, 16u, 8u},    {0x196bf0u, 32u, 8u},    {0x196bf4u, 80u, 8u},
    {0x196bf8u, 64u, 8u},    {0x196bfcu, 48u, 8u},    {0x196c00u, 32u, 8u},
    {0x196c04u, 64u, 8u},    {0x196c08u, 16u, 8u},    {0x196c14u, 16u, 8u},
    {0x196c18u, 32u, 8u},    {0x196c1cu, 48u, 8u},    {0x196c20u, 32u, 8u},
    {0x196c24u, 16u, 8u},    {0x196c30u, 64u, 8u},    {0x196c34u, 16u, 8u},
    {0x196c38u, 32u, 8u},    {0x196c3cu, 32u, 8u},    {0x196c48u, 1508u, 4u},
    {0x196c50u, 1512u, 4u},  {0x196c54u, 48u, 8u},    {0x196c58u, 32u, 8u},
    {0x196c5cu, 48u, 8u},    {0x196c60u, 1508u, 4u},  {0x196c68u, 1512u, 4u},
    {0x196c6cu, 1512u, 4u},  {0x196c70u, 48u, 8u},    {0x196c74u, 32u, 8u},
    {0x196c78u, 1508u, 4u},  {0x196c7cu, 32u, 8u},    {0x196c80u, 1508u, 4u},
    {0x196c88u, 16u, 8u},    {0x196c94u, 1508u, 4u},  {0x196c9cu, 1512u, 4u},
    {0x196ca0u, 48u, 8u},    {0x196ca4u, 32u, 8u},    {0x196ca8u, 48u, 8u},
    {0x196cacu, 1508u, 4u},  {0x196cb4u, 1512u, 4u},  {0x196cb8u, 1512u, 4u},
    {0x196cbcu, 48u, 8u},    {0x196cc0u, 32u, 8u},    {0x196cc4u, 1508u, 4u},
    {0x196cccu, 1508u, 4u},  {0x196cd4u, 16u, 8u},    {0x196ce0u, 1508u, 4u},
    {0x196ce8u, 1512u, 4u},  {0x196cecu, 48u, 8u},    {0x196cf0u, 32u, 8u},
    {0x196cf4u, 48u, 8u},    {0x196cf8u, 1508u, 4u},  {0x196d00u, 1512u, 4u},
    {0x196d04u, 1512u, 4u},  {0x196d08u, 48u, 8u},    {0x196d0cu, 32u, 8u},
    {0x196d10u, 1508u, 4u},  {0x196d14u, 32u, 8u},    {0x196d18u, 1508u, 4u},
    {0x196d20u, 16u, 8u},    {0x196d2cu, 1508u, 4u},  {0x196d34u, 1512u, 4u},
    {0x196d38u, 48u, 8u},    {0x196d3cu, 32u, 8u},    {0x196d40u, 48u, 8u},
    {0x196d44u, 1508u, 4u},  {0x196d4cu, 1512u, 4u},  {0x196d50u, 1512u, 4u},
    {0x196d54u, 32u, 8u},    {0x196d58u, 1508u, 4u},  {0x196d60u, 1508u, 4u},
    {0x196d68u, 16u, 8u},    {0x196d74u, 32u, 8u},    {0x196d78u, 16u, 8u},
    {0x196d84u, 32u, 8u},    {0x196d88u, 16u, 8u},    {0x196d94u, 64u, 8u},
    {0x196d98u, 48u, 8u},    {0x196d9cu, 32u, 8u},    {0x196da0u, 32u, 8u},
    {0x196da8u, 32u, 8u},    {0x196dacu, 16u, 8u},    {0x196db0u, 32u, 8u},
    {0x196db4u, 32u, 8u},    {0x196dbcu, 16u, 8u},    {0x196dc0u, 32u, 8u},
    {0x196dc4u, 32u, 8u},    {0x196dc8u, 16u, 8u},    {0x196dd4u, 48u, 8u},
    {0x196dd8u, 32u, 8u},    {0x196de0u, 32u, 8u},    {0x196de4u, 32u, 8u},
    {0x196de8u, 16u, 8u},    {0x196df0u, 48u, 8u},    {0x196df4u, 64u, 8u},
    {0x196df8u, 32u, 8u},    {0x196e04u, 32u, 8u},    {0x196e08u, 16u, 8u},
    {0x196e0cu, 32u, 8u},    {0x196e10u, 32u, 8u},    {0x196e18u, 16u, 8u},
    {0x196e1cu, 32u, 8u},    {0x196e20u, 32u, 8u},    {0x196e24u, 16u, 8u},
    {0x196e2cu, 16u, 8u},    {0x196e30u, 64u, 8u},    {0x196e38u, 80u, 8u},
    {0x196e44u, 32u, 8u},    {0x196e48u, 16u, 8u},    {0x196e54u, 48u, 8u},
    {0x196e58u, 32u, 8u},    {0x196e5cu, 48u, 8u},    {0x196e60u, 32u, 8u},
    {0x196e64u, 32u, 8u},    {0x196e78u, 32u, 8u},    {0x196e84u, 32u, 8u},
    {0x196e90u, 32u, 8u},    {0x196e98u, 16u, 8u},    {0x196e9cu, 64u, 8u},
    {0x196ea0u, 48u, 8u},    {0x196ea4u, 32u, 8u},    {0x196eacu, 32u, 8u},
    {0x196eb0u, 16u, 8u},    {0x196eb4u, 32u, 8u},    {0x196ebcu, 16u, 8u},
    {0x196ec0u, 32u, 8u},    {0x196ec4u, 32u, 8u},    {0x196ec8u, 16u, 8u},
    {0x196ed0u, 16u, 8u},    {0x196ed4u, 64u, 8u},    {0x196edcu, 80u, 8u},
    {0x196ee0u, 32u, 8u},    {0x196ee4u, 496u, 8u},   {0x196ee8u, 272u, 16u},
    {0x196eecu, 256u, 16u},  {0x196ef4u, 464u, 8u},   {0x1982d0u, 464u, 8u},
    {0x1982d4u, 80u, 8u},    {0x1982e0u, 256u, 8u},   {0x1982e8u, 64u, 8u},
    {0x1982ecu, 48u, 8u},    {0x1982f0u, 112u, 8u},   {0x1982f4u, 80u, 8u},
    {0x1982f8u, 64u, 8u},    {0x1982fcu, 96u, 8u},    {0x198300u, 48u, 8u},
    {0x198304u, 80u, 8u},    {0x198310u, 48u, 8u},    {0x198314u, 64u, 8u},
    {0x19831cu, 48u, 8u},    {0x198320u, 112u, 8u},   {0x198324u, 48u, 8u},
    {0x19832cu, 64u, 8u},    {0x198334u, 48u, 8u},    {0x198338u, 64u, 8u},
    {0x19833cu, 96u, 8u},    {0x198340u, 80u, 8u},    {0x198344u, 48u, 8u},
    {0x198348u, 80u, 8u},    {0x19834cu, 64u, 8u},    {0x198350u, 96u, 8u},
    {0x198354u, 48u, 8u},    {0x198358u, 96u, 8u},    {0x19835cu, 80u, 8u},
    {0x198364u, 80u, 8u},    {0x198368u, 64u, 8u},    {0x19836cu, 96u, 8u},
    {0x198378u, 496u, 8u},   {0x19837cu, 32u, 8u},    {0x198380u, 256u, 16u},
    {0x198388u, 464u, 8u},
}};
inline bool setterNumericContextRange(uint32_t pc, uint32_t at, uint32_t n) {
    return std::any_of(SetterContextWrites.begin(), SetterContextWrites.end(), [&](const auto& w) {
        return w.sourcePc == pc && setterContains(w.offset, w.bytes, at, n);
    });
}
inline constexpr uint32_t setterSourceStoreWidth(uint32_t pc) {
    switch (pc) {
        case 0x1912e0u:
        case 0x1912e4u:
        case 0x1912e8u:
        case 0x1912ecu:
        case 0x191dbcu:
        case 0x196018u:
        case 0x19601cu:
        case 0x1982dcu:
            return 16u;
        case 0x191d94u:
        case 0x191d98u:
        case 0x191d9cu:
        case 0x191dd0u:
        case 0x191dd4u:
        case 0x191dd8u:
        case 0x19602cu:
        case 0x19606cu:
        case 0x196074u:
        case 0x1960d4u:
        case 0x19613cu:
        case 0x196144u:
        case 0x19616cu:
        case 0x196178u:
        case 0x1961b4u:
        case 0x19638cu:
        case 0x1963a4u:
        case 0x1963c0u:
        case 0x19643cu:
        case 0x196450u:
        case 0x196464u:
        case 0x196478u:
        case 0x19648cu:
        case 0x1964a0u:
        case 0x1964b4u:
        case 0x1964c8u:
        case 0x1964e4u:
        case 0x196534u:
        case 0x196544u:
        case 0x196564u:
        case 0x196584u:
        case 0x1965a4u:
        case 0x1965bcu:
        case 0x1965dcu:
        case 0x1965f0u:
        case 0x196628u:
        case 0x19663cu:
        case 0x19667cu:
        case 0x196690u:
        case 0x1966b4u:
        case 0x196714u:
        case 0x196760u:
        case 0x1967b0u:
        case 0x1967c0u:
        case 0x196810u:
        case 0x196818u:
        case 0x196834u:
        case 0x19684cu:
        case 0x19685cu:
        case 0x196880u:
        case 0x196898u:
        case 0x1968c4u:
        case 0x1968e4u:
        case 0x196904u:
        case 0x19690cu:
        case 0x19693cu:
        case 0x196944u:
        case 0x1969d4u:
        case 0x1969dcu:
        case 0x196a04u:
        case 0x196a1cu:
        case 0x196a54u:
        case 0x196a60u:
        case 0x196a6cu:
        case 0x196a78u:
        case 0x196a80u:
        case 0x196a8cu:
        case 0x196a98u:
        case 0x196aa0u:
        case 0x196accu:
        case 0x196ae0u:
        case 0x196b10u:
        case 0x196b44u:
        case 0x196b5cu:
        case 0x196b80u:
        case 0x196b94u:
        case 0x196bccu:
        case 0x196becu:
        case 0x196c10u:
        case 0x196c2cu:
        case 0x196c44u:
        case 0x196c90u:
        case 0x196cdcu:
        case 0x196d28u:
        case 0x196d70u:
        case 0x196d80u:
        case 0x196d90u:
        case 0x196db8u:
        case 0x196dd0u:
        case 0x196decu:
        case 0x196e14u:
        case 0x196e28u:
        case 0x196e74u:
        case 0x196e80u:
        case 0x196e8cu:
        case 0x196e94u:
        case 0x196eb8u:
        case 0x196eccu:
        case 0x19830cu:
        case 0x198318u:
            return 4u;
        case 0x196014u:
        case 0x1982d8u:
        case 0x198308u:
        case 0x198328u:
        case 0x198330u:
        case 0x198360u:
        case 0x198374u:
            return 8u;
        default:
            return 0u;
    }
}
inline bool setterPreservedRegisterRange(uint32_t pc, uint32_t at, uint32_t n) {
    return (pc == 0x196eecu && setterContains(16u * 16u, 16u, at, n)) ||
           (pc == 0x196ee8u && setterContains(17u * 16u, 16u, at, n)) ||
           ((pc == 0x196088u || pc == 0x196ee4u) && setterContains(31u * 16u, 8u, at, n));
}
inline bool setterControlRange(const reo_source_closure::ControlWord& c) {
    using R = reo_source_closure::Role;
    const uint32_t at = c.contextOffset, n = c.bytes, pc = c.sourcePc;
    if (!n || n > 16u || at >= ContextBytes || n > ContextBytes - at)
        return false;
    switch (R(c.role)) {
        case R::GenuineControlPc:
            return n == 4u && pc == 0x196ef0u &&
                   (at == offsetof(R5900Context, pc) || at == offsetof(R5900Context, branch_pc));
        case R::GenuineControlFcr:
            return n == 4u && at == offsetof(R5900Context, fcr31) && setterFcrWritePc(pc);
        case R::GenuineControlStack:
            return n == 8u && at == 29u * 16u && pc == 0x196ef4u;
        case R::GenuineScalarReturn:
            return (n == 1u && at == offsetof(R5900Context, in_delay_slot) && pc == 0x196ef0u) ||
                   (n == 8u && at == 2u * 16u && setterBooleanReturnPc(pc)) ||
                   (n == 8u && at == 4u * 16u && pc == 0x1962a8u);
        default:
            return false;
    }
}
inline bool setterControlDirtyRange(const reo_source_closure::DirtySpan& d) {
    using R = reo_source_closure::Role;
    const uint32_t at = d.offset, n = d.bytes, pc = d.sourcePc;
    switch (R(d.role)) {
        case R::GenuineControlPc:
            return pc == 0x196ef0u &&
                   (setterContains(uint32_t(offsetof(R5900Context, pc)), 4u, at, n) ||
                    setterContains(uint32_t(offsetof(R5900Context, branch_pc)), 4u, at, n));
        case R::GenuineControlFcr:
            return setterFcrWritePc(pc) &&
                   setterContains(uint32_t(offsetof(R5900Context, fcr31)), 4u, at, n);
        case R::GenuineControlStack:
            return pc == 0x196ef4u && setterContains(29u * 16u, 8u, at, n);
        case R::GenuineScalarReturn:
            return (pc == 0x196ef0u &&
                    setterContains(uint32_t(offsetof(R5900Context, in_delay_slot)), 1u, at, n)) ||
                   (setterBooleanReturnPc(pc) && setterContains(2u * 16u, 8u, at, n)) ||
                   (pc == 0x1962a8u && setterContains(4u * 16u, 8u, at, n));
        default:
            return false;
    }
}
inline bool setterSameControlSource(const reo_source_closure::DirtySpan& d,
                                    const reo_source_closure::ControlWord& c) {
    return d.space == uint32_t(reo_source_closure::Space::Context) && d.role == c.role &&
           d.sourcePc == c.sourcePc;
}
// Validate integer metadata from the exact GPU output only. Actual Service
// issuance, immutable output association, true fence and input chronology are
// still required. This function neither certifies effects nor reads bank data.
template <class CallMetadata>
inline SetterEffectsPacket
decodeSetterEffectsMetadata(const CallMetadata& call, const Parameters& p,
                            std::span<const uint32_t, ReceiptWords> receipt,
                            std::span<const uint32_t> words) {
    using namespace reo_source_closure;
    if (words.size() != SetterEffectsWords)
        throw std::invalid_argument("Setter effects allocation differs");
    SetterEffectsPacket out;
    std::memcpy(&out.header, words.data(), sizeof(out.header));
    const auto& h = out.header;
    const auto& s = call.stamp();
    const std::array<uint32_t, 8> stamp{p.sessionLo, p.sessionHi, p.epochLo,   p.epochHi,
                                        p.bankLo,    p.bankHi,    p.ordinalLo, p.ordinalHi};
    if (!call.issuer() || !s.session || !s.epoch || !s.bankGeneration || !s.ordinal ||
        call.task() < 1 || call.entry() != SetterEffectsProfile || call.a0() > 255u ||
        !setterEffectsCommand(call.a0()) || call.a1() || call.a2() || receipt[0] ||
        receipt[1] != ReceiptMagic || receipt[2] != ReceiptVersion || receipt[3] != 1u ||
        h.status || h.magic != EffectsMagic || h.version != EffectsVersion || h.committed != 1u ||
        h.stamp != stamp || h.originalEntry != call.entry() || h.actualFinalPc != receipt[18] ||
        receipt[18] != call.returnPc() || h.actualTask != uint32_t(call.task()) ||
        h.profile != SetterEffectsProfile || h.dirtyCapacity != SetterEffectsDirtyCapacity ||
        h.controlCapacity != SetterEffectsControlCapacity || h.dirtyCount > h.dirtyCapacity ||
        h.controlCount > h.controlCapacity)
        throw std::invalid_argument("Setter effects source/control envelope refused");
    for (unsigned k = 0; k < 8u; ++k)
        if (receipt[4u + k] != stamp[k])
            throw std::invalid_argument("Setter receipt stamp differs");
    if (receipt[12] != call.entry() || receipt[13] != call.returnPc() || receipt[14] != call.a0() ||
        receipt[15] != call.a1() || receipt[16] != call.a2() || receipt[17] != call.entry())
        throw std::invalid_argument("Setter receipt call differs");
    const uint32_t controlBase = 20u + SetterEffectsDirtyCapacity * 6u;
    out.dirty.resize(h.dirtyCount);
    out.control.resize(h.controlCount);
    for (uint32_t k = 0; k < h.dirtyCount; ++k) {
        auto& d = out.dirty[k];
        std::memcpy(&d, words.data() + 20u + k * 6u, sizeof(d));
        const auto space = Space(d.space);
        const uint32_t cap = space == Space::Ram       ? RamBytes
                             : space == Space::Spr     ? SprBytes
                             : space == Space::Context ? ContextBytes
                                                       : 0u;
        if (!cap || !d.bytes || d.offset >= cap || d.bytes > cap - d.offset || !d.sourcePc ||
            !d.sourceOrdinal || d.sourceOrdinal > 65536u)
            throw std::invalid_argument("Setter dirty source span refused");
        if (space != Space::Context) {
            const uint32_t width = setterSourceStoreWidth(d.sourcePc);
            if ((d.role != uint32_t(Role::OpaqueGraphicsNumeric) &&
                 d.role != uint32_t(Role::PrivateStackCarry)) ||
                !width || d.bytes > width)
                throw std::invalid_argument("Setter memory source role refused");
        } else {
            const bool numeric = d.role == uint32_t(Role::OpaqueGraphicsNumeric) &&
                                 setterNumericContextRange(d.sourcePc, d.offset, d.bytes);
            const bool preserved = d.role == uint32_t(Role::PreservedIncomingLease) &&
                                   setterPreservedRegisterRange(d.sourcePc, d.offset, d.bytes);
            if (!numeric && !preserved && !setterControlDirtyRange(d))
                throw std::invalid_argument("Setter Context source role refused");
        }
        for (uint32_t j = 0; j < k; ++j) {
            const auto& old = out.dirty[j];
            if (d.space == old.space && d.offset < old.offset + old.bytes &&
                old.offset < d.offset + d.bytes)
                throw std::invalid_argument("Setter final source spans overlap");
        }
    }
    bool pc = false, branch = false, delay = false, stack = false, boolean = false,
         selector = false;
    for (uint32_t k = 0; k < h.controlCount; ++k) {
        auto& c = out.control[k];
        std::memcpy(&c, words.data() + controlBase + k * 8u, sizeof(c));
        if (!setterControlRange(c))
            throw std::invalid_argument("Setter scalar source role refused");
        for (uint32_t b = c.bytes; b < 16u; ++b)
            if ((c.bits[b / 4u] >> ((b & 3u) * 8u)) & 255u)
                throw std::invalid_argument("Setter scalar padding differs");
        for (uint32_t j = 0; j < k; ++j) {
            const auto& old = out.control[j];
            if (c.contextOffset < old.contextOffset + old.bytes &&
                old.contextOffset < c.contextOffset + c.bytes)
                throw std::invalid_argument("Setter scalar controls overlap");
        }
        // Dirties are disjoint, so the overlap sum proves complete association.
        uint32_t covered = 0u;
        for (const auto& d : out.dirty)
            if (setterSameControlSource(d, c)) {
                const uint32_t begin = std::max(d.offset, c.contextOffset),
                               end = std::min(d.offset + d.bytes, c.contextOffset + c.bytes);
                if (begin < end)
                    covered += end - begin;
            }
        if (covered != c.bytes)
            throw std::invalid_argument("Setter scalar lacks complete matching dirty source");
        if (c.contextOffset == offsetof(R5900Context, pc)) {
            pc = c.bits[0] == receipt[18];
            if (!pc)
                throw std::invalid_argument("Setter final PC differs");
        }
        if (c.contextOffset == offsetof(R5900Context, branch_pc)) {
            branch = c.bits[0] == 0x196ef0u;
            if (!branch)
                throw std::invalid_argument("Setter final branch PC differs");
        }
        if (c.contextOffset == offsetof(R5900Context, in_delay_slot)) {
            delay = c.bits[0] == 0u;
            if (!delay)
                throw std::invalid_argument("Setter final delay state differs");
        }
        if (c.contextOffset == 29u * 16u)
            stack = true;
        // Exact ADDIU a0,zero,0x11 (word24040011), command11 only.
        // The GPU-authored output is a scalar selector; no graphics value gains RAW.
        if (c.contextOffset == 4u * 16u) {
            if (call.a0() != 0x11u || c.bytes != 8u || c.sourcePc != 0x1962a8u ||
                c.role != uint32_t(Role::GenuineScalarReturn) || c.bits[0] != 0x11u ||
                c.bits[1] != 0u)
                throw std::invalid_argument("Setter source selector literal differs");
            selector = true;
        }
        if (c.contextOffset == 2u * 16u) {
            boolean = c.bits[0] == 1u && c.bits[1] == 0u;
            if (!boolean)
                throw std::invalid_argument("Setter Boolean return differs");
        }
        if (c.contextOffset == offsetof(R5900Context, fcr31) &&
            (c.bits[0] != receipt[19] || (c.bits[0] & 0x00100000u) == 0u))
            throw std::invalid_argument("Setter actual FCR update differs");
    }
    for (const auto& d : out.dirty)
        if (d.space == uint32_t(Space::Context) && d.role >= 3u && d.role <= 7u) {
            uint32_t covered = 0u;
            for (const auto& c : out.control)
                if (setterSameControlSource(d, c)) {
                    const uint32_t begin = std::max(d.offset, c.contextOffset),
                                   end = std::min(d.offset + d.bytes, c.contextOffset + c.bytes);
                    if (begin < end)
                        covered += end - begin;
                }
            if (covered != d.bytes)
                throw std::invalid_argument(
                    "Setter control dirty source lacks complete scalar association");
        }
    const auto restored = [&](uint32_t at, uint32_t n, uint32_t source) {
        uint32_t covered = 0u;
        for (const auto& d : out.dirty)
            if (d.space == uint32_t(Space::Context) && d.sourcePc == source &&
                (d.role == uint32_t(Role::OpaqueGraphicsNumeric) ||
                 d.role == uint32_t(Role::PreservedIncomingLease))) {
                const uint32_t begin = std::max(d.offset, at),
                               end = std::min(d.offset + d.bytes, at + n);
                if (begin < end)
                    covered += end - begin;
            }
        return covered == n;
    };
    if ((call.a0() == 0x11u && !selector) || !pc || !branch || !delay || !stack || !boolean ||
        !restored(16u * 16u, 16u, 0x196eecu) || !restored(17u * 16u, 16u, 0x196ee8u) ||
        !(restored(31u * 16u, 8u, 0x196088u) || restored(31u * 16u, 8u, 0x196ee4u)))
        throw std::invalid_argument("Setter actual return or saved-register writes absent");
    return out;
}
inline SetterEffectsPacket decodeSetterEffects(const Call& call,
                                               std::span<const uint32_t, ReceiptWords> receipt,
                                               std::span<const uint32_t> words) {
    return decodeSetterEffectsMetadata(call, parameters(call), receipt, words);
}
} // namespace reo_gpu_upstream
