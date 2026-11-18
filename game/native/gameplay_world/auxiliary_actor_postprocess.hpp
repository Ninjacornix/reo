#pragma once
#include "primary_actor_postprocess.hpp"
namespace reo::native::gameplay_world {
enum class AuxiliaryPostprocessStatus {completed,unavailable,inactive_nonadvancing,no_memory,busy,closed};
struct AuxiliaryPostprocessReport {
    AuxiliaryPostprocessStatus status{AuxiliaryPostprocessStatus::completed};
    std::size_t visited{},same_room{},weapons{},scene_triggers{},surface_transitions{},secondary_poses{};
    actors::EntityId failed{};
};
// Actual6832F0. The source compares against the currently selected primary's
// room and applies scene effects before clearing the auxiliary request bit.
class AuxiliaryActorPostprocess final {
public:
    AuxiliaryActorPostprocess(World&,gameplay_scene::Records&,gameplay_scenario::SceneMatrixPrograms&,
        gameplay_scenario::FlagState&,const gameplay_collision::response::Grid* = nullptr,
        ActorWeaponActions* = nullptr)noexcept;
    ~AuxiliaryActorPostprocess();
    AuxiliaryActorPostprocess(const AuxiliaryActorPostprocess&)=delete;
    AuxiliaryActorPostprocess& operator=(const AuxiliaryActorPostprocess&)=delete;
    AuxiliaryPostprocessReport run()noexcept;
private:
    World& world_;gameplay_scene::Records& records_;gameplay_scenario::SceneMatrixPrograms& programs_;
    gameplay_scenario::FlagState& flags_;const gameplay_collision::response::Grid* floors_;
    ActorWeaponActions* weapons_;bool running_{};
};
}
