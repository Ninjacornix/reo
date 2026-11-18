#include "inherited_pose_trails.hpp"
#include <stdexcept>
namespace reo::native::gameplay_world {
InheritedPoseTrailEffects::InheritedPoseTrailEffects(std::shared_ptr<World> world,gameplay_effects::PeriodicVisuals& visuals,gameplay_contact_world::RoomResources& rooms,gameplay_effects::InheritedTrailActions* actions)
    :world_(std::move(world)),visuals_(visuals),rooms_(rooms),actions_(actions){if(!world_||!bound_to(*world_))throw std::invalid_argument("Native inherited trail owners unavailable");}
bool InheritedPoseTrailEffects::bound_to(const World& world)const noexcept{return world_.get()==&world&&!world.closed()&&visuals_.admitted()&&visuals_.bound_to(world.session().random)&&(!actions_||actions_->bound_to(world));}
bool InheritedPoseTrailEffects::emit(const actors::EntityId& parent,const actors::EntityId& motion,std::uint8_t mode){return emit_at(parent,motion,mode,{},0);}
bool InheritedPoseTrailEffects::emit_at(const actors::EntityId& parent,const actors::EntityId& motion,std::uint8_t mode,std::optional<transform_math::Vector> point,std::int32_t delay){
    if(!world_||!bound_to(*world_)||mode!=1)return false;
    const auto made=visuals_.create_inherited_trails({world_,&rooms_,actions_,parent,motion,point,delay});
    return made.status!=gameplay_effects::WorkStatus::unavailable;
}
}
