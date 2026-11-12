#include "linked_flight_effects.hpp"
#include <stdexcept>
namespace reo::native::gameplay_world {
ResourceLinkedFlightEffects::ResourceLinkedFlightEffects(World& world,gameplay_contact_world::RoomResources& rooms,
    ResourcePoseWork& poses,gameplay_lighting::TimedLights& lights,PackedActorAudio& audio,
    gameplay_collision::delivery::Packets& packets,const gameplay_collision::delivery::Catalog& catalog)
    :world_(world),rooms_(rooms),poses_(poses),lights_(lights),audio_(audio),packets_(packets),catalog_(catalog){
    if(!bound_to(world))throw std::invalid_argument("Native linked flight effect owners unavailable");
}
bool ResourceLinkedFlightEffects::bound_to(const World& world)const noexcept{
    return &world==&world_&&poses_.bound_to(world)&&lights_.bound_to(world)&&audio_.bound_to(world)&&!packets_.closed();
}
std::optional<gameplay_collision::response::Floor> ResourceLinkedFlightEffects::floor(transform_math::Vector point){
    if(!bound_to(world_))return{};
    const auto number=world_.room;const auto room=rooms_.retain(number);const auto id=room?room->identity():gameplay_contact_world::RoomId{};
    if(!room||!id||room->room_number()!=number||!room->current(id)||world_.room!=number)return{};
    const auto result=room->geometry().floors.floor({point.x,point.y,point.z},255);
    return room->current(id)&&world_.room==number?std::optional(result):std::nullopt;
}
bool ResourceLinkedFlightEffects::burst(const actors::EntityId& parent,transform_math::Vector point){
    if(!bound_to(world_))return false;
    const auto made=poses_.attach(parent,0x6a,20,0,nullptr,&point,2);
    return made.status==PoseWorkStatus::completed||made.status==PoseWorkStatus::full;
}
bool ResourceLinkedFlightEffects::light(const actors::EntityId& parent,transform_math::Vector point){
    if(!bound_to(world_))return false;
    const auto made=lights_.create_ungated(parent,{point.x,point.y,point.z});
    return made.status==gameplay_lighting::TimedStatus::completed||made.status==gameplay_lighting::TimedStatus::task_full;
}
bool ResourceLinkedFlightEffects::sound(const actors::EntityId& work,std::uint8_t value){return bound_to(world_)&&audio_.sound(work,value);}
bool ResourceLinkedFlightEffects::packet(const actors::EntityId& work,std::uint8_t descriptor){
    if(!bound_to(world_))return false;
    const auto actor=world_.resolve(work);if(!actor)return false;
    const auto made=packets_.attach(catalog_,0,descriptor,{work,*actor,actor->contact,actor->character,actor->position,actor->normalized_marker});
    return made.status==gameplay_collision::delivery::PacketStatus::completed||made.status==gameplay_collision::delivery::PacketStatus::full;
}
}
