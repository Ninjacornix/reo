#pragma once
inline void sub_00107C68_0x107c68(std::uint8_t* m, R5900Context* c, PS2Runtime*) {
    std::memset(m + GPR_U32(c, 4), int(GPR_U32(c, 5) & 255), GPR_U32(c, 6));
    c->g[2].lo = GPR_U32(c, 4);
    c->pc = GPR_U32(c, 31);
}
