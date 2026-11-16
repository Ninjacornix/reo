#include "reception.hpp"
#include <stdexcept>
namespace reo::native::gameplay_update {
ActorReception::ActorReception(gameplay_world::World& world,gameplay_collision::room_objects::Owner* objects,gameplay_weapon_resources::Equipment* equipment,gameplay_world::InventoryPresence* presence):world_(world),objects_(objects),equipment_(equipment),presence_(presence){
    if(equipment_&&!equipment_->bound_to(world_))throw std::invalid_argument("Native actor reception equipment belongs to another or closed World");
    if(presence_&&!presence_->bound_to(world_))throw std::invalid_argument("Native actor reception inventory presence belongs to another or closed World");
}
bool ActorReception::bind_room_membership(gameplay_session::RoomMembership* membership)noexcept{
    if(world_.closed()||world_.busy()||(membership_&&membership&&membership_!=membership))return false;
    membership_=membership;return true;
}
bool ActorReception::room_membership_ready(MessageRoute route)const noexcept{
    const auto mode=route==MessageRoute::mode_zero?0u:1u;
    return !world_.closed()&&world_.mode==mode&&membership_&&membership_->ready(std::uint8_t(mode));
}
bool ActorReception::begin_room_membership_update()noexcept{
    if(world_.mode>1||!room_membership_ready(world_.mode?MessageRoute::mode_one:MessageRoute::mode_zero))return false;
    return membership_->begin_update();
}
gameplay_session::RoomMembershipChanges ActorReception::collect_room_membership()noexcept{
    if(world_.mode>1||!room_membership_ready(world_.mode?MessageRoute::mode_one:MessageRoute::mode_zero))
        return{gameplay_session::RoomMembershipStatus::unavailable,{}};
    const auto& activity=world_.session().activity;
    return membership_->collect(world_.mode?activity.online:activity.single,world_.selected_actor);
}
std::optional<std::uint32_t> ActorReception::room_owner(MessageRoute route,std::uint16_t room)const noexcept{
    if(!room_membership_ready(route))return{};
    const auto owner=membership_->owner(room);
    return owner?std::optional<std::uint32_t>(std::uint32_t(*owner)):std::nullopt;
}
ReceptionResult ActorReception::receive(const RoomClaimBeginMessage& message,bool)noexcept{
    if(!room_membership_ready(message.route))return{ReceptionStatus::unavailable,{}};
    const auto& activity=world_.session().activity;
    const auto result=membership_->claim(message.sender,message.room,world_.mode?activity.online:activity.single);
    return{result==gameplay_session::RoomMembershipStatus::completed?ReceptionStatus::completed:ReceptionStatus::unavailable,{}};
}
ReceptionResult ActorReception::receive(const RoomClaimReleaseMessage& message,bool)noexcept{
    if(!room_membership_ready(message.route))return{ReceptionStatus::unavailable,{}};
    const auto& activity=world_.session().activity;
    const auto result=membership_->release(message.sender,message.room,world_.mode?activity.online:activity.single);
    return{result==gameplay_session::RoomMembershipStatus::completed?ReceptionStatus::completed:ReceptionStatus::unavailable,{}};
}
ReceptionResult ActorReception::receive(const RoomMembershipMessage& message,bool)noexcept{
    if(!room_membership_ready(message.route)||message.update.count>message.update.rows.size())return{ReceptionStatus::unavailable,{}};
    const auto result=membership_->receive(std::span(message.update.rows).first(message.update.count));
    return{result==gameplay_session::RoomMembershipStatus::completed?ReceptionStatus::completed:ReceptionStatus::unavailable,{}};
}
const gameplay_collision::room_objects::Owner* ActorReception::room_objects()const noexcept{
    return world_.closed()||(objects_scenario_&&world_.scenario!=*objects_scenario_)?nullptr:objects_;
}
bool ActorReception::bind_room_objects(std::uint16_t scenario,std::shared_ptr<gameplay_collision::room_objects::Owner> objects)noexcept{
    if(world_.closed()||world_.busy()||world_.scenario!=scenario||!objects||!objects->initialized())return false;
    if(room_objects()&&room_objects()!=objects.get())return false;
    objects_=objects.get();objects_scenario_=scenario;retained_objects_=std::move(objects);return true;
}
bool ActorReception::roster_room_objects_ready(std::uint16_t scenario,const gameplay_collision::room_objects::Owner* expected)const noexcept{
    return !world_.closed()&&world_.updating_&&world_.primary_object_startup_&&world_.scenario==scenario&&room_objects()==expected;
}
bool ActorReception::replace_roster_room_objects(std::uint16_t scenario,std::shared_ptr<gameplay_collision::room_objects::Owner> objects,const gameplay_collision::room_objects::Owner* expected)noexcept{
    if(!roster_room_objects_ready(scenario,expected))return false;
    objects_=objects.get();objects_scenario_=objects?std::optional<std::uint16_t>(scenario):std::nullopt;retained_objects_=std::move(objects);return true;
}
bool ActorReception::unbind_room_objects()noexcept{
    if(world_.closed()||world_.busy())return false;
    objects_=nullptr;objects_scenario_.reset();retained_objects_.reset();return true;
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
ReceptionResult ActorReception::receive(const SceneRecordParameterMessage& message,bool)noexcept{
    if(world_.closed())return{ReceptionStatus::unavailable,{}};
    const auto phase=world_.session().message_phase;if(phase!=1&&phase!=2)return{};
    // Complete67DD40 case6. This channel5 record update has none of the actor
    // channel/local-echo/selected-status/equipment admission or tail effects.
    world_.session().enemy_descriptors.record(message.ordinal)->parameter2e=message.value;
    return{};
}
ReceptionResult ActorReception::receive(const ActorAlignmentMessage& message,bool local_echo)noexcept{
    const auto admitted=begin(message.channel,local_echo);if(!admitted.actor)return{admitted.status,{}};
    auto& actor=*admitted.actor;actor.alignment_target=message.target;return finish(actor);
}
ReceptionResult ActorReception::receive(const ActorInteractionMessage& message,bool local_echo)noexcept{
    const auto admitted=begin(message.channel,local_echo);if(!admitted.actor)return{admitted.status,{}};
    auto& actor=*admitted.actor;actor.interaction_kind=message.values[0];actor.interaction_mode=message.values[1];actor.interaction_slot=message.values[2];actor.interaction_detail=message.values[3];return finish(actor);
}
ReceptionResult ActorReception::receive(const ActorInteractionRequestMessage& message,bool local_echo)noexcept{
    const auto admitted=begin(message.channel,local_echo);if(!admitted.actor)return{admitted.status,{}};
    auto& actor=*admitted.actor;actor.transient_action=message.pending;actor.scene_model=message.scene_model;
    actor.interaction_request=message.request;actor.related_target_state=0;
    return finish(actor);
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
    if(!room_objects()||!objects_->apply_source_coordinates(message.grid,message.coordinates))return{ReceptionStatus::unavailable,{}};
    return finish(actor);
}
ReceptionResult ActorReception::receive(const ActorPeerMessage& message,bool local_echo)noexcept{
    const auto admitted=begin(message.channel,local_echo);if(!admitted.actor)return{admitted.status,{}};
    auto& actor=*admitted.actor;actor.transient_contact=std::uint8_t(message.state);
    actor.peer_request=gameplay_world::PeerRequest{std::uint8_t(message.state>>8),message.peer,message.parameters};
    if(!peer_reference_admitted(message.peer))return{ReceptionStatus::unavailable,{}};
    const auto peer=world_.referenced_actor(message.peer);
    // Original missing auxiliary lookup exits before shared pose/equipment work,
    // after the base request has been stored. Keep that distinct prefix.
    if(!peer)return{message.peer.kind==gameplay_world::actors::ActorReference::Kind::auxiliary?ReceptionStatus::completed:ReceptionStatus::unavailable,{}};
    peer->transient_contact=std::uint8_t(message.state);
    peer->peer_request=gameplay_world::PeerRequest{std::uint8_t(message.state>>8),{gameplay_world::actors::ActorReference::Kind::primary,actor.slot},message.parameters};
    return finish(actor);
}
ReceptionResult ActorReception::receive(const ActorSpeechMessage& message,bool local_echo)noexcept{
    const auto admitted=begin(message.channel,local_echo);if(!admitted.actor)return{admitted.status,{}};
    auto& actor=*admitted.actor;
    // Missing view ownership is unknown, rather than an assumed closed UI.
    if(!presence_||presence_->refresh(message.channel-1u)!=gameplay_world::PresenceStatus::completed)return{ReceptionStatus::unavailable,{}};
    actor.speech.variant=message.variant;
    if(message.variant||actor.room==world_.room){
        actor.speech.selection=gameplay_world::SpeechSelection{message.sequence,message.target_identifier,
            std::bit_cast<std::int8_t>(std::uint8_t(message.target_context)),
            std::bit_cast<std::int8_t>(std::uint8_t(message.response_state)),message.pending};
        actor.speech.gauge_notice=message.gauge_notice;
    }
    return finish(actor);
}
}
