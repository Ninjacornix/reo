#pragma once
#include "work.hpp"
namespace reo::native::gameplay_effects {
// Separate optional capability: existing WorkEdit vtables do not change.
// A consumer must obtain this actual generation-bound owner capability.
class ParticleEdit {
public:
    virtual ~ParticleEdit()=default;
    virtual bool configure_particle(std::uint8_t mode,std::int16_t delay,
        const std::array<float,6>& policy)noexcept=0;
};
struct ParticleSnapshot {
    std::uint8_t category{},mode{};
    std::int16_t delay{};
    std::uint16_t attributes{};
    transform_math::Vector scale,parameters208;
    float opacity{},feedback_scale{};
    std::uint32_t flags{};
    struct Child {std::uint32_t flags{};transform_math::Vector parameters;};
    std::size_t child_count{};
    std::array<Child,16> children;
};
}
