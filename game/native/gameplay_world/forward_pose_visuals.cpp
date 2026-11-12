#include "forward_pose_visuals.hpp"
#include <stdexcept>
namespace reo::native::gameplay_world {
ForwardPoseVisuals::ForwardPoseVisuals(World& world,gameplay_effects::PeriodicVisuals& visuals,std::uint8_t variant,PoseProjectileActions* remaining)
    :world_(world),visuals_(visuals),variant_(variant),remaining_(remaining){if(!bound_to(world))throw std::invalid_argument("Native forward projectile visual owners unavailable");}
bool ForwardPoseVisuals::bound_to(const World& world)const noexcept{return &world==&world_&&!world_.closed()&&visuals_.bound_to(world_.session().random)&&(!remaining_||remaining_->bound_to(world));}
bool ForwardPoseVisuals::forward_visual(const actors::EntityId& id){
    if(!bound_to(world_))return false;
    const auto made=visuals_.create_projectile_trail(world_,id,variant_);return made.status==gameplay_effects::WorkStatus::completed||made.status==gameplay_effects::WorkStatus::pool_full||made.status==gameplay_effects::WorkStatus::resource_missing;
}
bool ForwardPoseVisuals::ground_flare(const actors::EntityId& id){return bound_to(world_)&&remaining_&&remaining_->ground_flare(id);}
bool ForwardPoseVisuals::ground_trail(const actors::EntityId& id){return bound_to(world_)&&remaining_&&remaining_->ground_trail(id);}
bool ForwardPoseVisuals::projectile_light(transform_math::Vector point){return bound_to(world_)&&remaining_&&remaining_->projectile_light(point);}
std::optional<actors::EntityId> ForwardPoseVisuals::follower_visual(const actors::EntityId& id){
    if(!bound_to(world_))return{};
    const auto made=visuals_.create_surface_follower_visual(world_,id);
    if(made.status==gameplay_effects::WorkStatus::completed||made.status==gameplay_effects::WorkStatus::pool_full)return made.id;
    return{};
}
bool ForwardPoseVisuals::follower_position(const actors::EntityId& id,transform_math::Vector point){return bound_to(world_)&&visuals_.position_surface_follower_visual(id,point);}
}
