#pragma once
#include "../transform_math/transform_math.hpp"
#include "../gameplay_session/session.hpp"
#include <optional>
namespace reo::native::gameplay_effects {
// Native semantic state for654720. This policy does not allocate work/children,
// play sound, create gameplay tasks, or claim that those consumers are present.
struct ResourceCompanionState {
    std::uint8_t phase{},pending{},frozen{},emitted{},resource_slot{},subtype{};
    std::uint16_t content{},attributes{},child_attributes{};
    std::int16_t delay{},remaining{},age{},loop_lifetime{};
    float alpha{1},fade_delta{},material_scale{},camera_offset{};
    bool visible{};
    transform_math::Vector local_offset,position,scale{1,1,1};
    transform_math::Matrix basis{transform_math::identity()};
    std::array<std::int16_t,3> angles{};
};
struct ResourceCompanionModel {
    bool active{},visible{};
    std::uint16_t content{};
    std::uint8_t resource_slot{};
    std::uint32_t flags{};
    std::uint16_t draw_tag{};
    transform_math::Vector position,scale;
    transform_math::Matrix pose;
};
struct ResourceCompanionActor {std::uint8_t primary{},secondary{};};
struct ResourceCompanionStep {
    bool render{},retire{},fade_children{},spawn_gameplay{};
    std::optional<std::uint16_t> resource_cue;
    std::int16_t sample_time{};
};
ResourceCompanionStep advance_resource_companion(ResourceCompanionState&,
    const ResourceCompanionModel&,const std::optional<ResourceCompanionActor>&,
    gameplay_session::Random&);
}
