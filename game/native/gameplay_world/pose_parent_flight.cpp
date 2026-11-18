#include "pose_parent_flight.hpp"
#include <stdexcept>
namespace reo::native::gameplay_world {
RoomParentPoseFlight::RoomParentPoseFlight(World& world,PoseWorkPool& pool,gameplay_contact_world::RoomResources& rooms,PoseTrails* trails,ActorOffsetSound* sound,PoseWorkUpdates* remaining)
    :world_(world),pool_(pool),rooms_(rooms),trails_(trails),sound_(sound),remaining_(remaining){if(!bound_to(world))throw std::invalid_argument("Native parent pose flight owners unavailable");}
bool RoomParentPoseFlight::bound_to(const World& world)const noexcept{return &world==&world_&&pool_.bound_to(world)&&(!trails_||trails_->bound_to(world))&&(!sound_||sound_->bound_to(world))&&(!remaining_||remaining_->bound_to(world));}
std::optional<ParentFlightLaunch> RoomParentPoseFlight::launch(const actors::EntityId& id){
    const auto parent=world_.resolve(id);if(!parent)return{};
    const auto& b=parent->collision.basis;
    return ParentFlightLaunch{parent->primary,parent->secondary,{{{b.x.x,b.x.y,b.x.z,0},{b.y.x,b.y.y,b.y.z,0},{b.z.x,b.z.y,b.z.z,0},{b.translation.x,b.translation.y,b.translation.z,1}}}};
}
std::optional<gameplay_collision::response::Floor> RoomParentPoseFlight::floor(transform_math::Vector point){
    const auto number=world_.room;const auto room=rooms_.retain(number);const auto id=room?room->identity():gameplay_contact_world::RoomId{};
    if(!room||!id||room->room_number()!=number||!room->current(id)||world_.room!=number)return{};
    const auto sampled=room->geometry().floors.floor({point.x,point.y,point.z},255);
    return room->current(id)&&world_.room==number&&!world_.closed()?std::optional(sampled):std::nullopt;
}
bool RoomParentPoseFlight::trail(const actors::EntityId& parent,const actors::EntityId& motion,std::uint8_t mode){return trails_&&trails_->emit(parent,motion,mode);}
bool RoomParentPoseFlight::sound(const actors::EntityId& parent,std::uint8_t event){return sound_&&sound_->sound(parent,event);}
bool RoomParentPoseFlight::update(PoseWorkPool& pool,const actors::EntityId& id,std::uint8_t kind){
    if(&pool!=&pool_||!bound_to(world_))return false;
    if(kind!=18)return remaining_&&remaining_->update(pool,id,kind);
    const auto actor=pool.resolve(id);if(!actor)return false;
    const auto step=advance_parent_pose_flight(*actor,id,world_.session().clock_mode,*this);
    return step==ParentFlightStep::completed||(step==ParentFlightStep::retire&&pool.retire(id,true)==PoseWorkStatus::completed);
}
}
