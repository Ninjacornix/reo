#include "pose_timed_projectile.hpp"
#include <stdexcept>
namespace reo::native::gameplay_world {
RoomTimedPoseProjectiles::RoomTimedPoseProjectiles(World& world,PoseWorkPool& pool,gameplay_contact_world::RoomResources& rooms,
    gameplay_collision::delivery::Packets& packets,const gameplay_collision::delivery::Catalog& catalog,
    PoseTrails* trails,PoseTimingQuantum* quantum,ProjectileParentVariant* variants,PoseWorkUpdates* remaining)
    :world_(world),pool_(pool),rooms_(rooms),packets_(packets),catalog_(catalog),trails_(trails),quantum_(quantum),variants_(variants),remaining_(remaining){if(!bound_to(world))throw std::invalid_argument("Native timed pose projectile owners unavailable");}
bool RoomTimedPoseProjectiles::bound_to(const World& world)const noexcept{return &world==&world_&&pool_.bound_to(world)&&!packets_.closed()&&(!trails_||trails_->bound_to(world))&&(!quantum_||quantum_->bound_to(world))&&(!variants_||variants_->bound_to(world))&&(!remaining_||remaining_->bound_to(world));}
std::optional<std::uint8_t> RoomTimedPoseProjectiles::parent_variant(const actors::EntityId& parent){return variants_?variants_->read(parent):std::nullopt;}
std::optional<std::uint8_t> RoomTimedPoseProjectiles::quantum(){return quantum_?quantum_->read():std::nullopt;}
std::optional<gameplay_collision::response::Floor> RoomTimedPoseProjectiles::floor(transform_math::Vector point,std::uint8_t type){
    const auto number=world_.room;const auto room=rooms_.retain(number);const auto id=room?room->identity():gameplay_contact_world::RoomId{};
    if(!room||!id||room->room_number()!=number||!room->current(id)||world_.room!=number)return{};
    const auto sampled=room->geometry().floors.floor({point.x,point.y,point.z},type);
    return room->current(id)&&world_.room==number&&!world_.closed()?std::optional(sampled):std::nullopt;
}
bool RoomTimedPoseProjectiles::packet(const actors::EntityId& id,std::uint8_t descriptor,std::uint8_t bank){
    const auto actor=pool_.resolve(id);if(!actor)return false;
    const auto made=packets_.attach(catalog_,bank,descriptor,{id,*actor,actor->contact,actor->character,actor->position,actor->normalized_marker});
    return made.status==gameplay_collision::delivery::PacketStatus::completed||made.status==gameplay_collision::delivery::PacketStatus::full;
}
bool RoomTimedPoseProjectiles::trail(const actors::EntityId& parent,const actors::EntityId& motion,std::uint8_t mode){return trails_&&trails_->emit(parent,motion,mode);}
bool RoomTimedPoseProjectiles::retire(const actors::EntityId& id){return pool_.retire(id,true)==PoseWorkStatus::completed;}
bool RoomTimedPoseProjectiles::update(PoseWorkPool& pool,const actors::EntityId& id,std::uint8_t kind){
    if(&pool!=&pool_||!bound_to(world_))return false;
    if(kind!=17)return remaining_&&remaining_->update(pool,id,kind);
    const auto actor=pool.resolve(id);return actor&&advance_timed_pose_projectile(*actor,id,*this);
}
}
