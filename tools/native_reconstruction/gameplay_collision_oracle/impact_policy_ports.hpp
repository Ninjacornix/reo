#pragma once
namespace impact_oracle {
using Matrix = reo::native::transform_math::Matrix;
using V = reo::native::gameplay_collision::Vec3;
struct Call {
    std::uint8_t kind{}, key{};
    std::uint32_t actor{};
    Matrix matrix;
    V point;
};
inline std::vector<Call> calls;
} // namespace impact_oracle
inline void o2_005DD6F0_0x5dd6f0(std::uint8_t* m, R5900Context* c, PS2Runtime*) {
    using namespace impact_oracle;
    const auto at = GPR_U32(c, 6);
    const auto point = ref_read<V>(m, at);
    calls.push_back({1, std::uint8_t(GPR_U32(c, 7)), 0, ref_read<Matrix>(m, GPR_U32(c, 5)), point});
    ref_write(m, at, V{point.x + 2, point.y + 3, point.z + 5});
    c->pc = GPR_U32(c, 31);
}
inline void o2_005DD9D0_0x5dd9d0(std::uint8_t* m, R5900Context* c, PS2Runtime*) {
    using namespace impact_oracle;
    if (GPR_U32(c, 5))
        throw std::runtime_error("Surface helper matrix must be null");
    const auto at = GPR_U32(c, 6);
    const auto point = ref_read<V>(m, at);
    calls.push_back({2, std::uint8_t(GPR_U32(c, 7)), GPR_U32(c, 4), {}, point});
    ref_write(m, at, V{point.x + 2, point.y + 3, point.z + 5});
    c->pc = GPR_U32(c, 31);
}
