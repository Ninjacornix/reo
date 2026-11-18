#pragma once
#include <vector>
namespace route_oracle {
inline std::uint8_t mutation{};
inline std::int32_t authority{};
inline std::array<bool, 16> present;
inline std::vector<std::uint32_t> trace;
inline std::uint32_t target(unsigned i) {
    return 0x10000 + 0x100 * i;
}
inline std::uint32_t mask(unsigned room) {
    return 0x4b9a80 + 12 * room + 0x3a4;
}
inline void finish(R5900Context* c) {
    c->pc = GPR_U32(c, 31);
}
} // namespace route_oracle
inline void o2_00570A30_0x570a30(std::uint8_t* m, R5900Context* c, PS2Runtime*) {
    using namespace route_oracle;
    const auto room = GPR_U32(c, 4), edge = GPR_U32(c, 5);
    trace.insert(trace.end(), {0x570a30, room, edge, GPR_U32(c, 6)});
    if (mutation & 1) {
        const auto at = mask(ref_read<std::uint16_t>(m, 0x3243dc));
        ref_write(m, at, std::uint16_t(ref_read<std::uint16_t>(m, at) | (1u << (edge & 31))));
    }
    if (mutation & 2)
        ref_write(m, 0x3243dc, std::uint16_t((ref_read<std::uint16_t>(m, 0x3243dc) + 1) % 512));
    if (mutation & 4)
        for (unsigned i = 0; i < 16; ++i) {
            ref_write(m, target(i) + 0x44,
                      (ref_read<std::uint32_t>(m, target(i) + 0x44) + 1) % 512);
            ref_write(m, target(i) + 0x48, (ref_read<std::uint32_t>(m, target(i) + 0x48) + 1) % 64);
        }
    finish(c);
}
inline void o2_005706B0_0x5706b0(std::uint8_t*, R5900Context* c, PS2Runtime*) {
    route_oracle::trace.insert(route_oracle::trace.end(),
                               {0x5706b0, GPR_U32(c, 4), GPR_U32(c, 5), GPR_U32(c, 6)});
    route_oracle::finish(c);
}
inline void o2_005819C0_0x5819c0(std::uint8_t*, R5900Context* c, PS2Runtime*) {
    const auto edge = GPR_U32(c, 4);
    route_oracle::trace.insert(route_oracle::trace.end(), {0x5819c0, edge});
    c->g[2].lo = route_oracle::present[edge] ? route_oracle::target(edge) : 0;
    route_oracle::finish(c);
}
inline void sub_001B0310_0x1b0310(std::uint8_t*, R5900Context* c, PS2Runtime*) {
    route_oracle::trace.push_back(0x1b0310);
    c->g[2].lo = std::uint64_t(std::int64_t(route_oracle::authority));
    route_oracle::finish(c);
}
inline void sub_001AFDD0_0x1afdd0(std::uint8_t* m, R5900Context* c, PS2Runtime*) {
    using namespace route_oracle;
    const auto p = GPR_U32(c, 5);
    trace.insert(trace.end(),
                 {0x1afdd0, GPR_U32(c, 4), GPR_U32(c, 6), GPR_U32(c, 7), m[p], m[p + 1], m[p + 4]});
    for (unsigned i = 0; i < m[p + 4]; ++i)
        trace.insert(trace.end(), {m[p + 8 + 4 * i], m[p + 9 + 4 * i],
                                   ref_read<std::uint16_t>(m, p + 10 + 4 * i)});
    finish(c);
}
inline PS2Runtime::Fn PS2Runtime::lookupFunction(std::uint32_t at) const {
    if (at == 0x1b0310)
        return sub_001B0310_0x1b0310;
    if (at == 0x1afdd0)
        return sub_001AFDD0_0x1afdd0;
    throw std::runtime_error("Undeclared route oracle call");
}
