#pragma once
#include <vector>
namespace delivery_oracle {
inline std::vector<std::uint32_t> feedback;
}
inline void sub_001B0340_0x1b0340(std::uint8_t* m, R5900Context* c, PS2Runtime*) {
    delivery_oracle::feedback.push_back(0x1b0340);
    delivery_oracle::feedback.push_back(GPR_U32(c, 4));
    c->g[2].lo = ref_read<std::uint32_t>(m, 64);
    c->pc = GPR_U32(c, 31);
}
inline void sub_001BA9F0_0x1ba9f0(std::uint8_t*, R5900Context* c, PS2Runtime*) {
    delivery_oracle::feedback.push_back(0x1ba9f0);
    delivery_oracle::feedback.push_back(GPR_U32(c, 4));
    c->pc = GPR_U32(c, 31);
}
