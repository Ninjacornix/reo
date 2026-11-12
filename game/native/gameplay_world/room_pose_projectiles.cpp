#include "room_pose_projectiles.hpp"
#include <stdexcept>
namespace reo::native::gameplay_world {
RoomPoseProjectiles::RoomPoseProjectiles(World& world,PoseWorkPool& pool,gameplay_contact_world::RoomResources& rooms,
    gameplay_collision::delivery::Packets& packets,const gameplay_collision::delivery::Catalog& catalog,
    PresetPoseWork* presets,PoseTrails* trails,ActorOffsetSound* sound,PackedActorAudio* audio,PoseProjectileActions* actions,PoseWorkUpdates* remaining)
    :world_(world),pool_(pool),rooms_(rooms),packets_(packets),catalog_(catalog),presets_(presets),trails_(trails),sound_(sound),audio_(audio),actions_(actions),remaining_(remaining){
    if(!bound_to(world))throw std::invalid_argument("Native room pose projectile owners unavailable");
}
bool RoomPoseProjectiles::bound_to(const World& world)const noexcept{
    return &world==&world_&&pool_.bound_to(world)&&!packets_.closed()&&(!presets_||presets_->bound_to(world))&&(!trails_||trails_->bound_to(world))&&(!sound_||sound_->bound_to(world))&&(!audio_||audio_->bound_to(world))&&(!actions_||actions_->bound_to(world))&&(!remaining_||remaining_->bound_to(world));
}
std::optional<gameplay_collision::response::Floor> RoomPoseProjectiles::floor(transform_math::Vector point){
    const auto number=world_.room;const auto room=rooms_.retain(number);const auto id=room?room->identity():gameplay_contact_world::RoomId{};
    if(!room||!id||room->room_number()!=number||!room->current(id)||world_.room!=number)return{};
    const auto sampled=room->geometry().floors.floor({point.x,point.y,point.z},255);
    return room->current(id)&&world_.room==number&&!world_.closed()?std::optional(sampled):std::nullopt;
}
bool RoomPoseProjectiles::packet(const actors::EntityId& id,std::uint8_t descriptor,std::uint8_t bank){
    const auto actor=pool_.resolve(id);if(!actor)return false;
    const auto made=packets_.attach(catalog_,bank,descriptor,{id,*actor,actor->contact,actor->character,actor->position,actor->normalized_marker});
    return made.status==gameplay_collision::delivery::PacketStatus::completed||made.status==gameplay_collision::delivery::PacketStatus::full;
}
bool RoomPoseProjectiles::retire(const actors::EntityId& id){return pool_.retire(id,true)==PoseWorkStatus::completed;}
bool RoomPoseProjectiles::emitter_absent(const actors::EntityId& id)const{const auto actor=pool_.resolve(id);return actor&&actor->pose_work&&!actor->pose_work->emitter_owner;}
struct RoomPoseProjectiles::Ground final:GroundPoseEffects {
    RoomPoseProjectiles& owner;explicit Ground(RoomPoseProjectiles& value):owner(value){}
    std::optional<gameplay_collision::response::Floor> floor(transform_math::Vector p)override{return owner.floor(p);}
    bool packet(const actors::EntityId& id,std::uint8_t descriptor,std::uint8_t bank)override{return owner.packet(id,descriptor,bank);}
    bool flare(const actors::EntityId& id)override{return owner.emitter_absent(id)||(owner.actions_&&owner.actions_->ground_flare(id));}
    bool trail(const actors::EntityId& id)override{return owner.emitter_absent(id)||(owner.actions_&&owner.actions_->ground_trail(id));}
    bool retire(const actors::EntityId& id)override{return owner.retire(id);}
    bool sound(const actors::EntityId& id,std::uint8_t event)override{return owner.sound_&&owner.sound_->sound(id,event);}
};
struct RoomPoseProjectiles::Forward final:ForwardProjectileEffects {
    RoomPoseProjectiles& owner;explicit Forward(RoomPoseProjectiles& value):owner(value){}
    bool visual(const actors::EntityId& id)override{return owner.actions_&&owner.actions_->forward_visual(id);}
    bool sound(const actors::EntityId& id,std::uint8_t event)override{return owner.audio_&&owner.audio_->sound(id,event);}
    bool packet(const actors::EntityId& id,std::uint8_t descriptor,std::uint8_t bank)override{return owner.packet(id,descriptor,bank);}
    bool light(transform_math::Vector p)override{return owner.actions_&&owner.actions_->projectile_light(p);}
    bool retire(const actors::EntityId& id)override{return owner.retire(id);}
};
struct RoomPoseProjectiles::Follower final:SurfaceFollowerEffects {
    RoomPoseProjectiles& owner;explicit Follower(RoomPoseProjectiles& value):owner(value){}
    std::optional<actors::EntityId> visual(const actors::EntityId& id)override{return owner.actions_?owner.actions_->follower_visual(id):std::nullopt;}
    std::optional<gameplay_collision::response::Floor> floor(transform_math::Vector p)override{return owner.floor(p);}
    bool position(const actors::EntityId& id,transform_math::Vector p)override{return owner.actions_&&owner.actions_->follower_position(id,p);}
    bool retire(const actors::EntityId& id)override{return owner.retire(id);}
};
struct RoomPoseProjectiles::Split final:SplittingArcEffects {
    RoomPoseProjectiles& owner;explicit Split(RoomPoseProjectiles& value):owner(value){}
    std::optional<transform_math::Vector> primary_zero_position()override{const auto actor=owner.world_.primary(0);return actor?std::optional(transform_math::Vector{actor->position.x,actor->position.y,actor->position.z}):std::nullopt;}
    std::optional<gameplay_collision::response::Floor> floor(transform_math::Vector p)override{return owner.floor(p);}
    bool packet(const actors::EntityId& id,std::uint8_t descriptor,std::uint8_t bank)override{return owner.packet(id,descriptor,bank);}
    bool trail(const actors::EntityId& parent,const actors::EntityId& motion,std::uint8_t mode)override{return owner.trails_&&owner.trails_->emit(parent,motion,mode);}
    bool sound(const actors::EntityId& id,std::uint8_t event)override{return owner.sound_&&owner.sound_->sound(id,event);}
    bool preset(const actors::EntityId& id,const transform_math::Matrix& basis,transform_math::Vector point,const std::array<std::int16_t,4>& angles,std::uint8_t descriptor,std::uint8_t variant)override{
        if(!owner.presets_)return false;
        const auto made=owner.presets_->create(id,basis,point,angles,descriptor,variant);return made.status==PoseWorkStatus::completed||made.status==PoseWorkStatus::full;
    }
    bool retire(const actors::EntityId& id)override{return owner.retire(id);}
};
bool RoomPoseProjectiles::update(PoseWorkPool& pool,const actors::EntityId& id,std::uint8_t kind){
    if(&pool!=&pool_||!bound_to(world_))return false;
    const auto actor=pool.resolve(id);if(!actor)return false;
    switch(kind){
    case 6:{Ground effects(*this);return advance_ground_pose_flight(*actor,id,effects);}
    case 12:{Split effects(*this);return advance_splitting_pose_arc(*actor,id,effects);}
    case 15:{Forward effects(*this);return advance_forward_pose_projectile(*actor,id,effects);}
    case 100:{Follower effects(*this);return advance_pose_surface_follower(*actor,id,effects);}
    default:return remaining_&&remaining_->update(pool,id,kind);
    }
}
}
