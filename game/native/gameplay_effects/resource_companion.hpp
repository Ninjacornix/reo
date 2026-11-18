#pragma once
#include "../transform_math/transform_math.hpp"
#include "../gameplay_session/session.hpp"
#include "../gameplay_actors/entity.hpp"
#include <optional>
namespace reo::native::gameplay_world {class World;class ResourceModels;}
namespace reo::native::gameplay_scenario {class SceneResources;class ResourceTemplates;}
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
// Cross-subsystem side effects are supplied by the concrete native audio/light
// composition. A policy-only fixture does not satisfy this ownership contract.
class ResourceCompanionActions {
public:
    virtual ~ResourceCompanionActions()=default;
    virtual bool bound_to(const gameplay_world::World&,const gameplay_scenario::SceneResources&,const gameplay_world::ResourceModels&,const gameplay_scenario::ResourceTemplates&)const noexcept=0;
    virtual bool light(const gameplay_actors::EntityId&,transform_math::Vector)noexcept=0;
    virtual bool cue(const gameplay_actors::EntityId&,std::uint16_t)noexcept=0;
};
}
