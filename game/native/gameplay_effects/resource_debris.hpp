#pragma once
#include "../gameplay_session/session.hpp"
#include "../transform_math/transform_math.hpp"
namespace reo::native::gameplay_effects {
// Native type1B ballistic work. It owns copied pose/physics state, not a live
// model pointer. Source group selection does not allocate child records here.
struct ResourceDebrisState {
    std::uint8_t phase{},part{};bool visible{};
    std::uint16_t effect{};
    std::int16_t delay{};
    transform_math::Matrix basis{transform_math::identity()};
    transform_math::Vector initial_position,position,previous_position,velocity,acceleration;
    std::array<std::int16_t,3> angles{},angular_velocity{};
    float alpha{1},fade_step{};
};
struct ResourceDebrisStep {bool retire{},query_floor{};};
//58FBC0/58FBE0 and the pre-query58FD10 prefix. A phase1 step always requires
// the actual floor query, even when its alpha transition already selected2.
ResourceDebrisStep advance_resource_debris(ResourceDebrisState&,gameplay_session::Random&);
void complete_resource_debris_floor(ResourceDebrisState&,bool hit)noexcept;
}
