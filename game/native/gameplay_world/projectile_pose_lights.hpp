#pragma once
#include "room_pose_projectiles.hpp"
#include "../gameplay_lighting/transient_lights.hpp"
#include "../gameplay_contact_world/contacts.hpp"
namespace reo::native::gameplay_world {
// Actual6B25B0 through canonical linked tasks, both scene light arrays and
// the current retained room floor. Other actions require explicit providers.
class ProjectilePoseLights final:public PoseProjectileActions {
public:
    ProjectilePoseLights(gameplay_update::Owner&,gameplay_scenario::Lighting&,gameplay_lighting::TransientLights&,gameplay_contact_world::RoomResources&,PoseProjectileActions* remaining=nullptr);
    bool bound_to(const World&)const noexcept override;
    bool ground_flare(const actors::EntityId&)override;
    bool ground_trail(const actors::EntityId&)override;
    bool forward_visual(const actors::EntityId&)override;
    bool projectile_light(transform_math::Vector)override;
    std::optional<actors::EntityId> follower_visual(const actors::EntityId&)override;
    bool follower_position(const actors::EntityId&,transform_math::Vector)override;
private:
    gameplay_update::Owner& update_;gameplay_scenario::Lighting& lights_;
    gameplay_lighting::TransientLights& transient_;gameplay_contact_world::RoomResources& rooms_;PoseProjectileActions* remaining_;
};
}
