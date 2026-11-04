#pragma once
#include <cstdint>
#include <span>

namespace reo::pad2 {
struct Motors {
    uint16_t large = 0, small = 0;
    bool operator==(const Motors&) const = default;
};
enum class OutputKind { Unhandled, Profile, Motors };
struct Output {
    OutputKind kind = OutputKind::Unhandled;
    Motors motors{};
};
inline uint32_t word(std::span<const uint8_t> bytes, size_t offset) {
    return uint32_t(bytes[offset]) | uint32_t(bytes[offset+1]) << 8 |
           uint32_t(bytes[offset+2]) << 16 | uint32_t(bytes[offset+3]) << 24;
}
// SLUS-20765 libdbc 189800 queries the output profile with 01038002.
// 1A6F90 -> 189880 -> 189420 sends 0103400B: mask length, value
// length, packed values, then the actuator mask. Actuator 0 is one bit
// (small motor); actuator 1 is eight bits (large motor), packed LSB first.
inline Output decodeOutput(uint32_t rpc, uint32_t socket, std::span<const uint8_t> request,
                           Motors previous) {
    if(request.size()<12 || word(request,0)!=socket) return {};
    const auto command=word(request,4);
    if(rpc==0x8000131au && command==0x01038002u)
        return {OutputKind::Profile,{}};
    if(rpc!=0x8000131bu || command!=0x0103400bu) return {};
    const auto length=word(request,8);
    if(length<10 || length>request.size()-12) return {};
    const auto payload=request.subspan(12,length);
    const auto maskLength=word(payload,0),valueLength=word(payload,4);
    if(maskLength!=1 || valueLength<1 || valueLength>2 || 8+valueLength+maskLength>length)
        return {};
    const auto mask=payload[8+valueLength];
    if(!mask || (mask&~3u) || (mask==3 && valueLength!=2) || (mask!=3 && valueLength!=1))
        return {};
    auto motors=previous;
    if(mask&1) motors.small=(payload[8]&1) ? 65535 : 0;
    if(mask&2) {
        const uint8_t strength=mask==3 ? uint8_t((payload[8]>>1)|(payload[9]<<7)) : payload[8];
        motors.large=uint16_t(strength)*257u;
    }
    return {OutputKind::Motors,motors};
}
// libpad2 state fallback (File #2 0x12B280 -> 0x134518, the same library as
// File #1): when the record counter has not advanced since the last poll, the
// game asks dbcman for the port state with 0101800C and reads reply +8 (byte
// count), +C (state byte) and +20C (result). A zero count leaves the caller's
// state byte uninitialized, which the game reads as a disconnect.
inline bool isStateQuery(uint32_t rpc, std::span<const uint8_t> request) {
    return rpc==0x8000131au && request.size()>=12 && word(request,4)==0x0101800cu;
}
} // namespace reo::pad2
