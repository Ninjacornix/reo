#pragma once
namespace population_oracle {
namespace e = reo::native::gameplay_effects;
using Matrix = reo::native::transform_math::Matrix;
using V = reo::native::gameplay_collision::Vec3;
struct Creation {
    e::WorkRequest request;
    std::uint32_t at;
};
inline std::vector<Creation> creations;
inline std::optional<e::WorkRequest> pending_request;
struct Sound {
    std::uint8_t slot;
    V point;
    std::uint16_t event;
};
inline std::vector<Sound> sounds;
inline unsigned pattern{}, attempt{}, companion_lookup{}, companion_allocations{};
inline bool companion_present{}, companion_available{};
inline std::uint32_t companion = 0x500000;
inline bool fail(unsigned n) {
    return ((pattern >> n) & 1) != 0;
}
} // namespace population_oracle
inline void population_constructor_probe(std::uint8_t* m, R5900Context* c, PS2Runtime* runtime) {
    using namespace population_oracle;
    const auto callback = GPR_U32(c, 10);
    e::WorkRequest request;
    if (GPR_U32(c, 4))
        request.basis = ref_read<Matrix>(m, GPR_U32(c, 4));
    if (GPR_U32(c, 5)) {
        const auto v = ref_read<V>(m, GPR_U32(c, 5));
        request.position = {v.x, v.y, v.z};
    }
    request.variant = std::bit_cast<std::int16_t>(std::uint16_t(GPR_U32(c, 8)));
    request.effect = std::uint16_t(GPR_U32(c, 7));
    request.child_mask = GPR_U32(c, 6);
    request.flags = GPR_U32(c, 9);
    request.update = callback == 0x653010   ? e::WorkUpdate::ordinary
                     : callback == 0x6531d0 ? e::WorkUpdate::oriented
                                            : e::WorkUpdate::scaled;
    if (callback != 0x653010 && callback != 0x6531d0 && callback != 0x653e80)
        throw std::runtime_error("Unknown population updater");
    pending_request = request;
    o2_006525D0_0x6525d0(m, c, runtime);
    pending_request.reset();
}
inline void o2_00652390_0x652390(std::uint8_t* m, R5900Context* c, PS2Runtime*) {
    using namespace population_oracle;
    if (!pending_request || pending_request->effect != GPR_U32(c, 4))
        throw std::runtime_error("Full constructor resource identity");
    const auto index = attempt++, at = 0x510000 + 0x400 * index;
    creations.push_back({*pending_request, fail(index) ? 0u : at});
    if (!fail(index)) {
        std::memset(m + at, 0, 0x300);
        ref_write(m, at + 0x23e, std::uint16_t(0x8000));
        ref_write(m, at + 0xb4, 1.0f);
        ref_write(m, at + 0xb8, 1.0f);
        ref_write(m, at + 0xbc, 1.0f);
    }
    SET_GPR_U32(c, 2, fail(index) ? 0 : at);
    c->pc = GPR_U32(c, 31);
}
inline void o2_00652E20_0x652e20(std::uint8_t* m, R5900Context* c, PS2Runtime*) {
    using namespace population_oracle;
    const auto variant = std::bit_cast<std::int16_t>(std::uint16_t(GPR_U32(c, 6)));
    if (!pending_request || variant != pending_request->variant || variant != 0)
        throw std::runtime_error("Full6525D0 variant forwarding must come from t0 and equal zero");
    ref_write(m, GPR_U32(c, 4) + 0x290, variant);
    c->pc = GPR_U32(c, 31);
}
inline void o2_00590760_0x590760(std::uint8_t* m, R5900Context* c, PS2Runtime*) {
    ref_write(m, GPR_U32(c, 5), 0x560000u);
    ref_write(m, GPR_U32(c, 5) + 4, 0x570000u);
    c->pc = GPR_U32(c, 31);
}
inline void o2_00652470_0x652470(std::uint8_t* m, R5900Context* c, PS2Runtime*) {
    using namespace population_oracle;
    if (!pending_request || GPR_U32(c, 7) != pending_request->child_mask)
        throw std::runtime_error("Full6525D0 child admission mask must come from a2");
    ref_write(m, GPR_U32(c, 4) + 0x294, GPR_U32(c, 7));
    c->pc = GPR_U32(c, 31);
}
inline void o2_00652F90_0x652f90(std::uint8_t* m, R5900Context* c, PS2Runtime*) {
    ref_write(m, GPR_U32(c, 4) + 0x280, population_oracle::V{c->f[12], c->f[13], c->f[14]});
    c->pc = GPR_U32(c, 31);
}
inline void o2_005E0680_0x5e0680(std::uint8_t*, R5900Context* c, PS2Runtime*) {
    if (GPR_U32(c, 4) != 0x1d)
        throw std::runtime_error("Unexpected companion family");
    ++population_oracle::companion_lookup;
    SET_GPR_U32(c, 2, population_oracle::companion_present ? population_oracle::companion : 0);
    c->pc = GPR_U32(c, 31);
}
inline void o2_00651A30_0x651a30(std::uint8_t*, R5900Context* c, PS2Runtime*) {
    if (GPR_U32(c, 4) || GPR_U32(c, 5) || GPR_U32(c, 6) != 1)
        throw std::runtime_error("Unexpected companion allocation");
    ++population_oracle::companion_allocations;
    SET_GPR_U32(c, 2, population_oracle::companion_available ? population_oracle::companion : 0);
    c->pc = GPR_U32(c, 31);
}
inline void sub_001B8D40_0x1b8d40(std::uint8_t* m, R5900Context* c, PS2Runtime*) {
    population_oracle::sounds.push_back({std::uint8_t(GPR_U32(c, 4)),
                                         ref_read<population_oracle::V>(m, GPR_U32(c, 5)),
                                         std::uint16_t(GPR_U32(c, 6))});
    c->pc = GPR_U32(c, 31);
}
