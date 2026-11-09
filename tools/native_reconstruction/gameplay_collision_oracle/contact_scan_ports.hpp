#pragma once
#include "game/native/gameplay_collision/collision.hpp"
namespace contact_scan_oracle {
inline bool obstructed{};
inline unsigned occlusion_calls{};
inline std::vector<std::array<reo::native::gameplay_collision::Vec3, 2>> marks;
} // namespace contact_scan_oracle
inline void contact_scan_occlusion(std::uint8_t* m, R5900Context* c, PS2Runtime*) {
    ++contact_scan_oracle::occlusion_calls;
    c->g[2].lo = contact_scan_oracle::obstructed;
    ref_write(m, GPR_U32(c, 8), 0xffu);
    c->pc = GPR_U32(c, 31);
}
inline void o2_005719D0_0x5719d0(std::uint8_t* m, R5900Context* c, PS2Runtime*) {
    using V = reo::native::gameplay_collision::Vec3;
    contact_scan_oracle::marks.push_back(
        {ref_read<V>(m, GPR_U32(c, 4)), ref_read<V>(m, GPR_U32(c, 5))});
    c->pc = GPR_U32(c, 31);
}
