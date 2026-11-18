#pragma once
#include "actor_scene_triggers.hpp"
#include "actor_surface_transition.hpp"
#include "head_reaction.hpp"
#include "../gameplay_events/statistics.hpp"
namespace reo::native::gameplay_world {
// The actual65EC40 equipment-use owner must bind this World. Missing reached
// work refuses; the interface supplies no successful default implementation.
class ActorWeaponActions {
public:
    virtual ~ActorWeaponActions()=default;
    virtual bool bound_to(const World&)const noexcept=0;
    virtual bool refresh(const actors::EntityId&)=0;
};
enum class PrimaryPostprocessStatus {completed,unavailable,no_memory,busy,closed};
struct PrimaryPostprocessReport {
    PrimaryPostprocessStatus status{PrimaryPostprocessStatus::completed};
    std::size_t visited{},same_room{},weapons{},scene_triggers{},surface_transitions{},reactions{},statistics{};
    actors::EntityId failed{};
};
// Actual66A3A0 phase, separate from common frame66A2E0 and model publication.
// Borrowed canonical owners outlive this serialized synchronous frame worker.
class PrimaryActorPostprocess final {
public:
    PrimaryActorPostprocess(World&,gameplay_scene::Records&,gameplay_scenario::SceneMatrixPrograms&,gameplay_scenario::FlagState&,gameplay_events::Statistics&,const gameplay_collision::response::Grid* floors,ActorWeaponActions* weapons=nullptr)noexcept;
    ~PrimaryActorPostprocess();
    PrimaryActorPostprocess(const PrimaryActorPostprocess&)=delete;
    PrimaryActorPostprocess& operator=(const PrimaryActorPostprocess&)=delete;
    PrimaryPostprocessReport run(const HeadReactionContext& = {})noexcept;
private:
    World& world_;gameplay_scene::Records& records_;gameplay_scenario::SceneMatrixPrograms& programs_;
    gameplay_scenario::FlagState& flags_;gameplay_events::Statistics& statistics_;
    const gameplay_collision::response::Grid* floors_;ActorWeaponActions* weapons_;bool running_{};
};
}
