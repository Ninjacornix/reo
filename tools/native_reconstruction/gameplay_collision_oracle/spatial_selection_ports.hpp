#pragma once
namespace selection_oracle {
inline std::array<std::array<std::array<float, 3>, 2>, 2> points;
inline std::array<std::array<bool, 2>, 2> enabled;
inline unsigned calls{};
} // namespace selection_oracle
inline void spatial_controlled_point(std::uint8_t* m, R5900Context* c, PS2Runtime*) {
    const auto at = GPR_U32(c, 6);
    if (at < 0xa0000 || at >= 0xa2000)
        throw std::runtime_error("Controlled geometry identity outside two actors");
    const auto actor = (at - 0xa0000) / 0x1000, region = ((at - 0xa0000) % 0x1000) / 12;
    if (actor >= 2 || region >= 2)
        throw std::runtime_error("Controlled region identity outside fixture");
    ++selection_oracle::calls;
    c->g[2].lo = selection_oracle::enabled[actor][region];
    if (c->g[2].lo)
        ref_write(m, GPR_U32(c, 7), selection_oracle::points[actor][region]);
    c->pc = GPR_U32(c, 31);
}
