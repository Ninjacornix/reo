#include "pose_arcs.hpp"
#include <stdexcept>
namespace reo::native::gameplay_world {
RoomPoseArcs::RoomPoseArcs(World& world,PoseWorkPool& pool,gameplay_contact_world::RoomResources& rooms,PoseTrails* trails,PoseWorkUpdates* remaining)
    :world_(world),pool_(pool),rooms_(rooms),trails_(trails),remaining_(remaining){if(!bound_to(world))throw std::invalid_argument("Native pose arc owners unavailable");}
bool RoomPoseArcs::bound_to(const World& world)const noexcept{return &world==&world_&&pool_.bound_to(world)&&(!trails_||trails_->bound_to(world))&&(!remaining_||remaining_->bound_to(world));}
std::optional<gameplay_collision::response::Floor> RoomPoseArcs::floor(transform_math::Vector point){
    const auto number=world_.room;const auto room=rooms_.retain(number);const auto id=room?room->identity():gameplay_contact_world::RoomId{};
    if(!room||!id||room->room_number()!=number||!room->current(id)||world_.room!=number)return{};
    const auto result=room->geometry().floors.floor({point.x,point.y,point.z},255);return room->current(id)&&world_.room==number?std::optional(result):std::nullopt;
}
bool RoomPoseArcs::trail(const actors::EntityId& parent,const actors::EntityId& work,std::uint8_t mode){return trails_&&trails_->emit(parent,work,mode);}
bool RoomPoseArcs::update(PoseWorkPool& pool,const actors::EntityId& id,std::uint8_t kind){
    if(&pool!=&pool_||!bound_to(world_))return false;
    if(kind!=13&&kind!=16)return remaining_&&remaining_->update(pool,id,kind);
    const auto actor=pool.resolve(id);if(!actor)return false;
    const auto step=advance_quarter_turn_pose_arc(*actor,kind,id,*this);
    return step==PoseArcStep::completed||(step==PoseArcStep::retire&&pool.retire(id,true)==PoseWorkStatus::completed);
}
}
