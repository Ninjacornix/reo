#pragma once
#include "room_pose_projectiles.hpp"
#include "../gameplay_effects/periodic_visuals.hpp"
namespace reo::native::gameplay_world {
// Actual5DEF90/653CC0 through the same168/256 visual owner. Other reached
// projectile constructors are delegated to explicit remaining capabilities.
class ForwardPoseVisuals final:public PoseProjectileActions {
public:
    // variant is the actual7123B0 scalar from the admitted asset/profile.
    ForwardPoseVisuals(World&,gameplay_effects::PeriodicVisuals&,std::uint8_t variant,PoseProjectileActions* remaining=nullptr);
    bool bound_to(const World&)const noexcept override;
    bool ground_flare(const actors::EntityId&)override;
    bool ground_trail(const actors::EntityId&)override;
    bool forward_visual(const actors::EntityId&)override;
    bool projectile_light(transform_math::Vector)override;
    std::optional<actors::EntityId> follower_visual(const actors::EntityId&)override;
    bool follower_position(const actors::EntityId&,transform_math::Vector)override;
private:
    World& world_;gameplay_effects::PeriodicVisuals& visuals_;std::uint8_t variant_;PoseProjectileActions* remaining_;
};
}
