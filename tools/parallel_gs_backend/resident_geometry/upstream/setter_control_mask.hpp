#pragma once
#include "integer_controls.hpp"
namespace reo_gpu_upstream {
inline constexpr uint32_t SetterCommandMask = 0xffu;
inline constexpr uint32_t setterIntegerControls(uint32_t entry) {
    return entry == 0x196010u ? ReturnPC | A0 : 0u;
}
// A0 authenticates only the source ANDI command byte. A1/A2 metadata are
// ignored/zero; their actual numerical/pointer values stay in GPU Context.
inline constexpr uint32_t setterCommandMetadata(uint32_t raw) {
    return raw & SetterCommandMask;
}
} // namespace reo_gpu_upstream
