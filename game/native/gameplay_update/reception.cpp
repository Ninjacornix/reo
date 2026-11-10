#include "reception.hpp"
#include <stdexcept>
namespace reo::native::gameplay_update {
ActorReception::ActorReception(gameplay_world::World& world,gameplay_collision::room_objects::Owner* objects,gameplay_weapon_resources::Equipment* equipment):world_(world),objects_(objects),equipment_(equipment){
    if(equipment_&&!equipment_->bound_to(world_))throw std::invalid_argument("Native actor reception equipment belongs to another or closed World");
}
ActorReception::Admission ActorReception::begin(std::uint32_t channel,bool local_echo)noexcept{
    if(world_.closed())return{ReceptionStatus::unavailable,{}};
    const auto phase=world_.session().message_phase;if(phase!=1&&phase!=2)return{};
    const auto index=channel-1u;if(!local_echo&&index==world_.selected_actor)return{};
    const auto actor=world_.primary(index);if(!actor)return{ReceptionStatus::unavailable,{}};
    actor->pending_notice=0;
    const auto selected=world_.primary(world_.selected_actor);if(!selected)return{ReceptionStatus::unavailable,{}};
    if(selected->status&4u)return{};
    return{ReceptionStatus::completed,actor};
}
ReceptionResult ActorReception::finish(gameplay_world::Actor& actor)noexcept{
    actor.previous_position=actor.position;actor.previous_orientation=actor.orientation;actor.root_motion_delta={};
    if(!actor.selected_resource)return{};
    if(!equipment_)return{ReceptionStatus::unavailable,{}};
    const auto result=equipment_->reconcile(world_.identity_of(actor));
    return{result.status==gameplay_scenario::SceneStatus::completed?ReceptionStatus::completed:ReceptionStatus::unavailable,result};
}
ReceptionResult ActorReception::receive(const ActorStatusMessage& message,bool local_echo)noexcept{
    const auto admitted=begin(message.channel,local_echo);if(!admitted.actor)return{admitted.status,{}};
    auto& actor=*admitted.actor;actor.status=message.status;actor.current=message.health;return finish(actor);
}
ReceptionResult ActorReception::receive(const ActorAlignmentMessage& message,bool local_echo)noexcept{
    const auto admitted=begin(message.channel,local_echo);if(!admitted.actor)return{admitted.status,{}};
    auto& actor=*admitted.actor;actor.alignment_target=message.target;return finish(actor);
}
ReceptionResult ActorReception::receive(const ActorInteractionMessage& message,bool local_echo)noexcept{
    const auto admitted=begin(message.channel,local_echo);if(!admitted.actor)return{admitted.status,{}};
    auto& actor=*admitted.actor;actor.interaction_kind=message.values[0];actor.interaction_mode=message.values[1];actor.interaction_slot=message.values[2];actor.interaction_detail=message.values[3];return finish(actor);
}
ReceptionResult ActorReception::receive(const ActorInventoryMessage& message,bool local_echo)noexcept{
    const auto admitted=begin(message.channel,local_echo);if(!admitted.actor)return{admitted.status,{}};
    auto& actor=*admitted.actor;
    switch(message.kind){
    case ActorInventoryMessage::Kind::carried:actor.inventory.carried=message.resources;break;
    case ActorInventoryMessage::Kind::extra:for(unsigned i=0;i<4;++i)actor.inventory.storage[i+1]=message.resources[i];break;
    default:return{ReceptionStatus::unavailable,{}};
    }
    return finish(actor);
}
ReceptionResult ActorReception::receive(const ActorResourcePairMessage& message,bool local_echo)noexcept{
    const auto admitted=begin(message.channel,local_echo);if(!admitted.actor)return{admitted.status,{}};
    auto& actor=*admitted.actor;actor.explicit_resource_pair=message.pair;actor.inventory.carried=message.carried;return finish(actor);
}
ReceptionResult ActorReception::receive(const ActorRoomObjectMessage& message,bool local_echo)noexcept{
    const auto admitted=begin(message.channel,local_echo);if(!admitted.actor)return{admitted.status,{}};
    auto& actor=*admitted.actor;actor.grid=message.grid;
    if(!objects_||!objects_->apply_source_coordinates(message.grid,message.coordinates))return{ReceptionStatus::unavailable,{}};
    return finish(actor);
}
}
