#pragma once
namespace shape_oracle {
using V = reo::native::gameplay_collision::Vec3;
struct Surface {
    std::uint8_t event{}, type{};
    V point, normal;
};
inline std::vector<Surface> surfaces;
inline std::vector<std::array<V, 2>> lines;
inline bool debug{};
inline unsigned debug_queries{};
struct WallQuery {
    V start, end;
    std::uint32_t include{}, exclude{}, result{};
};
inline std::vector<WallQuery> wall_queries;
struct AngularQuery {
    V start, direction, region;
    float first{}, second{}, radius{};
    std::uint32_t count{}, result{}, actor{}, mask{}, category{};
};
inline std::vector<AngularQuery> angular_queries;
} // namespace shape_oracle
inline void shape_wall_probe(std::uint8_t* m, R5900Context* c, PS2Runtime* runtime) {
    shape_oracle::WallQuery query{ref_read<shape_oracle::V>(m, GPR_U32(c, 4)),
                                  ref_read<shape_oracle::V>(m, GPR_U32(c, 5)), GPR_U32(c, 8),
                                  GPR_U32(c, 9), 0};
    o2_005795E0_0x5795e0(m, c, runtime);
    query.result = GPR_U32(c, 2);
    shape_oracle::wall_queries.push_back(query);
}
inline void shape_angular_probe(std::uint8_t* m, R5900Context* c, PS2Runtime* runtime) {
    const auto target = ref_read<std::uint32_t>(m, 0x3c2600);
    const auto sphere = ref_read<std::uint32_t>(m, target + 0x1dc);
    const auto definition = ref_read<std::uint32_t>(m, target + 0x1d8);
    shape_oracle::AngularQuery query{ref_read<shape_oracle::V>(m, GPR_U32(c, 5)),
                                     ref_read<shape_oracle::V>(m, GPR_U32(c, 6)),
                                     ref_read<shape_oracle::V>(m, sphere),
                                     c->f[13],
                                     c->f[12],
                                     ref_read<float>(m, definition + 12),
                                     ref_read<std::uint16_t>(m, 0x3c25f8),
                                     0,
                                     target,
                                     m[GPR_U32(c, 4) + 0x19],
                                     m[target + 2]};
    o2_0057B6F0_0x57b6f0(m, c, runtime);
    query.result = GPR_U32(c, 2);
    shape_oracle::angular_queries.push_back(query);
}
inline void o2_005DD580_0x5dd580(std::uint8_t* m, R5900Context* c, PS2Runtime*) {
    const auto packet = GPR_U32(c, 4);
    const auto event = m[packet + 0x1b];
    using V = shape_oracle::V;
    shape_oracle::surfaces.push_back({event,
                                      event == 2 ? std::uint8_t(GPR_U32(c, 8)) : std::uint8_t(0),
                                      ref_read<V>(m, event == 1 ? packet + 0x1c : GPR_U32(c, 5)),
                                      ref_read<V>(m, event == 1 ? GPR_U32(c, 6) : GPR_U32(c, 7))});
    c->pc = GPR_U32(c, 31);
}
inline void sub_001B82A0_0x1b82a0(std::uint8_t*, R5900Context* c, PS2Runtime*) {
    if (GPR_U32(c, 4) != 0x3d)
        throw std::runtime_error("Unexpected shape debug selector");
    ++shape_oracle::debug_queries;
    c->g[2].lo = shape_oracle::debug;
    c->pc = GPR_U32(c, 31);
}
inline void sub_001AF780_0x1af780(std::uint8_t*, R5900Context* c, PS2Runtime*) {
    c->pc = GPR_U32(c, 31);
}
inline void sub_00194FD0_0x194fd0(std::uint8_t* m, R5900Context* c, PS2Runtime*) {
    const auto p = GPR_U32(c, 4);
    using V = shape_oracle::V;
    shape_oracle::lines.push_back({ref_read<V>(m, p), ref_read<V>(m, p + 12)});
    c->pc = GPR_U32(c, 31);
}
