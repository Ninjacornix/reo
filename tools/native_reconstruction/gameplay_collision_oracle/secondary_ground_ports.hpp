#pragma once
#include "game/native/transform_math/transform_math.hpp"
#include <vector>
namespace secondary_oracle {
inline std::vector<std::uint32_t> wall_calls;
inline std::vector<reo::native::transform_math::Vector> rotation_inputs;
} // namespace secondary_oracle
inline void o2_005DA420_0x5da420(std::uint8_t* m, R5900Context* c, PS2Runtime*) {
    const auto at = GPR_U32(c, 4);
    secondary_oracle::wall_calls.push_back(at);
    ref_write(m, at + 0x38, ref_read<float>(m, at + 0x38) + 1.25f);
    ref_write(m, at + 0x40, ref_read<float>(m, at + 0x40) - 0.5f);
    c->pc = GPR_U32(c, 31);
}
inline void o0_00370320_0x370320(std::uint8_t* m, R5900Context* c, PS2Runtime*) {
    namespace t = reo::native::transform_math;
    auto matrix = t::identity();
    t::reset_euler_axes(matrix, {std::uint16_t(GPR_U32(c, 4)), std::uint16_t(GPR_U32(c, 5)),
                                 std::uint16_t(GPR_U32(c, 6))});
    ref_write(m, GPR_U32(c, 7), matrix);
    c->pc = GPR_U32(c, 31);
}
inline void sub_0018FDF0_0x18fdf0(std::uint8_t* m, R5900Context* c, PS2Runtime*) {
    ref_write(m, GPR_U32(c, 4), reo::native::transform_math::identity());
    c->pc = GPR_U32(c, 31);
}
inline void sub_00192180_0x192180(std::uint8_t*, R5900Context* c, PS2Runtime*) {
    c->f[0] = std::atan2(c->f[12], c->f[13]);
    c->pc = GPR_U32(c, 31);
}
inline void sub_001919D0_0x1919d0(std::uint8_t* m, R5900Context* c, PS2Runtime*) {
    using Vector = reo::native::transform_math::Vector;
    const auto input = ref_read<Vector>(m, GPR_U32(c, 5));
    secondary_oracle::rotation_inputs.push_back(input);
    const auto matrix = ref_read<reo::native::transform_math::Matrix>(m, GPR_U32(c, 6));
    ref_write(m, GPR_U32(c, 4), reo::native::transform_math::direction(matrix, input));
    c->pc = GPR_U32(c, 31);
}
