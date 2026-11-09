#pragma once
#include <vector>
namespace damage_oracle {
inline std::vector<std::uint32_t> trace;
inline bool change_room{};
} // namespace damage_oracle
inline void o2_006B5C60_0x6b5c60(std::uint8_t* m, R5900Context* c, PS2Runtime*) {
    const auto edge = GPR_U32(c, 4);
    damage_oracle::trace.insert(damage_oracle::trace.end(), {0x6b5c60, edge});
    const auto room = ref_read<std::uint16_t>(m, 0x3243dc);
    for (unsigned slot : {0u, 3u}) {
        const auto at = 0x4b9e20 + 12 * room + 2 * slot;
        ref_write(m, at, std::uint16_t(ref_read<std::uint16_t>(m, at) | (1u << edge)));
    }
    if (damage_oracle::change_room)
        ref_write(m, 0x3243dc, std::uint16_t((room + 1) % 128));
    c->pc = GPR_U32(c, 31);
}
inline void o2_0067DCB0_0x67dcb0(std::uint8_t*, R5900Context* c, PS2Runtime*) {
    damage_oracle::trace.insert(damage_oracle::trace.end(), {0x67dcb0, GPR_U32(c, 4), GPR_U32(c, 5),
                                                             GPR_U32(c, 6), GPR_U32(c, 7)});
    c->pc = GPR_U32(c, 31);
}
inline PS2Runtime::Fn PS2Runtime::lookupFunction(std::uint32_t) const {
    throw std::runtime_error("Undeclared room-damage oracle call");
}
