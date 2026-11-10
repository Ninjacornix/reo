#pragma once
#include "room_publication.hpp"
#include "../gameplay_world/world.hpp"
#include "../gameplay_world/actor_state.hpp"
#include "../gameplay_world/interaction_transitions.hpp"
#include "../gameplay_scenario/flags.hpp"
#include "../gameplay_collision/room_objects.hpp"
#include <bit>
#include <cmath>
namespace reo::native::gameplay_update {
// Typed initialized fields only. Original stack padding is not a native wire
// format. The actual transport must supply its sender/framing/queue admission.
struct ScenarioOwnerMessage {
    MessageRoute route{};std::uint16_t flag{};std::uint8_t value{};
    static constexpr unsigned channel=5,type=0,length=8,options=0,dispatch_mode=4;
};
struct ResourceOperationMessage {
    MessageRoute route{};std::uint16_t resource{};std::uint8_t actor{},operation{};
    static constexpr unsigned channel=5,type=9,length=8,options=0,dispatch_mode=4;
};
struct ResourcePositionMessage {
    MessageRoute route{};std::uint16_t resource{};std::uint8_t actor{},operation{};
    gameplay_world::Position position;
    static constexpr unsigned channel=5,type=9,length=20,options=0,dispatch_mode=4;
};
struct ActorStatusMessage {
    MessageRoute route{};std::uint32_t channel{},status{};std::int16_t health{};
    static constexpr unsigned type=14,length=12,options=0,dispatch_mode=4;
};
struct ActorActionMessage {
    MessageRoute route{};std::uint32_t channel{};std::uint16_t flags{};
    std::array<std::uint8_t,4> values{};std::uint8_t equipment{};
    static constexpr unsigned type=7,length=12,options=0,dispatch_mode=4;
};
enum class ActorMessageSelector:std::uint8_t {none=0,snapshot=1,state=2,interaction_request=3,interaction=4,contact_snapshot=5,alignment=6,action=7,peer=8,room_object=9,resource_pair=10,speech=11,carried=12,reserved=13,status=14,extra=15};
struct ActorSnapshotMessage {
    MessageRoute route{};std::uint32_t channel{};
    std::array<std::uint8_t,4> action{};gameplay_world::Position position;
    std::int16_t yaw{},health{};std::uint32_t status{};
    std::uint8_t selected_resource{},equipment{},interaction_resource{},grid{};
    std::int16_t aim_pitch_adjustment{},aim_target_pitch{};
    std::uint8_t room{},aim_target_index{},gauge_band{};
    std::optional<std::uint8_t> model_variant; // initialized only for category1
    std::array<std::uint8_t,2> resource_pair{};bool auxiliary_flag{};
    static constexpr unsigned type=1,length=44,options=0,dispatch_mode=4;
};
struct ActorStateMessage {
    MessageRoute route{};std::uint32_t channel{};gameplay_world::Position position;
    std::uint32_t status{};std::int16_t yaw{};std::uint8_t gauge_band{};
    static constexpr unsigned type=2,length=24,options=0,dispatch_mode=2;
};
struct ActorContactSnapshotMessage {
    MessageRoute route{};std::uint32_t channel{};
    std::array<std::uint8_t,4> action{};std::array<std::int16_t,3> position{};
    std::int16_t yaw{},health{};std::uint8_t room{};std::uint32_t status{};
    std::uint8_t source_kind{},source_slot{};
    gameplay_collision::delivery::Identity source_related;
    std::uint8_t response_class{},region{},auxiliary_a{},response_code{},response_flags{},gauge_band{};
    gameplay_collision::Vec3 direction;
    gameplay_world::actors::EntityId recorded_source;
    std::optional<std::uint8_t> model_variant;
    static constexpr unsigned type=5,length=52,options=0,dispatch_mode=4;
};
struct ActorInteractionMessage {
    MessageRoute route{};std::uint32_t channel{};std::array<std::uint8_t,4> values{};
    static constexpr unsigned type=4,length=8,options=0,dispatch_mode=4;
};
struct ActorInteractionRequestMessage {
    MessageRoute route{};std::uint32_t channel{};std::uint8_t pending{},scene_model{};
    gameplay_world::InteractionRequest request;
    static constexpr unsigned type=3,length=32,options=0,dispatch_mode=4;
};
struct ActorAlignmentMessage {
    MessageRoute route{};std::uint32_t channel{};gameplay_world::AlignmentTarget target;
    static constexpr unsigned type=6,length=20,options=0,dispatch_mode=4;
};
struct ActorResourcePairMessage {
    MessageRoute route{};std::uint32_t channel{};std::array<std::uint8_t,2> pair{};std::array<std::uint8_t,4> carried{};
    static constexpr unsigned type=10,length=16,options=0,dispatch_mode=4;
};
struct ActorRoomObjectMessage {
    MessageRoute route{};std::uint32_t channel{};std::uint8_t grid{};
    std::array<std::int8_t,2> coordinates{};
    static constexpr unsigned type=9,length=8,options=0,dispatch_mode=4;
};
struct ActorPeerMessage {
    MessageRoute route{};std::uint32_t channel{};std::uint16_t state{};
    gameplay_world::actors::ActorReference peer;std::array<std::int16_t,2> parameters{};
    static constexpr unsigned type=8,length=12,options=0,dispatch_mode=4;
};
struct ActorSpeechMessage {
    MessageRoute route{};std::uint32_t channel{},sequence{};
    std::int16_t target_identifier{},target_context{};
    std::int32_t response_state{};std::int8_t pending{},gauge_notice{},variant{};
    static constexpr unsigned type=11,length=20,options=0,dispatch_mode=4;
};
inline bool peer_reference_admitted(const gameplay_world::actors::ActorReference& reference)noexcept{
    using Reference=gameplay_world::actors::ActorReference;
    return reference.kind==Reference::Kind::primary?reference.identifier<gameplay_world::World::primary_capacity:
        reference.kind==Reference::Kind::auxiliary&&reference.identifier<=0x7fff;
}
struct ActorInventoryMessage {
    enum class Kind:std::uint8_t {carried=12,extra=15};
    MessageRoute route{};std::uint32_t channel{};Kind kind{};std::array<std::uint8_t,4> resources{};
    static constexpr unsigned length=8,options=0,dispatch_mode=4;
};
class GameplayMessageSink : public RoomClaimSink {
public:
    virtual ~GameplayMessageSink()=default;
    virtual bool send(const ScenarioOwnerMessage&)noexcept=0;
    virtual bool send(const ResourceOperationMessage&)noexcept=0;
    virtual bool send(const ResourcePositionMessage&)noexcept=0;
    virtual bool send(const ActorStatusMessage&)noexcept=0;
    virtual bool send(const ActorActionMessage&)noexcept{return false;}
    virtual bool send(const ActorInteractionMessage&)noexcept{return false;}
    virtual bool send(const ActorInteractionRequestMessage&)noexcept{return false;}
    virtual bool send(const ActorResourcePairMessage&)noexcept{return false;}
    virtual bool send(const ActorInventoryMessage&)noexcept{return false;}
    virtual bool send(const ActorStateMessage&)noexcept{return false;}
    virtual bool send(const ActorSnapshotMessage&)noexcept{return false;}
    virtual bool send(const ActorContactSnapshotMessage&)noexcept{return false;}
    virtual bool send(const ActorAlignmentMessage&)noexcept{return false;}
    virtual bool send(const ActorRoomObjectMessage&)noexcept{return false;}
    virtual bool send(const ActorPeerMessage&)noexcept{return false;}
    virtual bool send(const ActorSpeechMessage&)noexcept{return false;}
    bool send(const RoomClaimReleaseMessage&)noexcept override{return false;}
    virtual std::optional<std::uint32_t> room_owner(MessageRoute,std::uint16_t)noexcept{return{};}
};
// Complete admitted67DBD0 control/ownership path. Borrow canonical state once;
// live networking requires an explicit actual message consumer, with no no-op.
class StatePublication final {
public:
    StatePublication(gameplay_world::World& world,gameplay_scenario::FlagState& flags,GameplayMessageSink* messages=nullptr,const gameplay_collision::room_objects::Owner* objects=nullptr):world_(world),flags_(flags),messages_(messages),objects_(objects){}
    gameplay_world::InteractionTransition consume_interaction_request(const gameplay_world::actors::EntityId& id,std::uint32_t selector)noexcept{return gameplay_world::consume_interaction_request(world_,id,selector,messages_);}
    PublicationStatus release_actor_room(std::uint32_t slot)noexcept{return publish_actor_room_release(world_,slot,messages_);}
    PublicationStatus resource_position(std::uint32_t resource,std::uint32_t actor,std::uint32_t operation,std::optional<gameplay_world::Position> position)noexcept{
        if(world_.closed())return PublicationStatus::unavailable;
        const auto phase=world_.session().message_phase;if(phase!=1&&phase!=2)return PublicationStatus::completed;
        if(!position)return PublicationStatus::unavailable;
        if(world_.mode!=0&&world_.mode!=1)return PublicationStatus::completed;
        if(!messages_||!messages_->send(ResourcePositionMessage{world_.mode==0?MessageRoute::mode_zero:MessageRoute::mode_one,std::uint16_t(resource),std::uint8_t(actor),std::uint8_t(operation),*position}))return PublicationStatus::message_unavailable;
        return PublicationStatus::completed;
    }
    PublicationStatus actor_status(const gameplay_world::actors::EntityId& id)noexcept{return actor_message(id,ActorMessageSelector::status);}
    PublicationStatus actor_action(const gameplay_world::actors::EntityId& id)noexcept{return actor_message(id,ActorMessageSelector::action);}
    PublicationStatus periodic_actor_state(const gameplay_world::actors::EntityId& id)noexcept{
        if(world_.closed())return PublicationStatus::unavailable;
        if(world_.paused||world_.session().timer_subseconds()%30)return PublicationStatus::completed;
        const auto actor=world_.resolve(id);if(!actor)return PublicationStatus::unavailable;
        if(actor->slot!=world_.selected_actor||!gameplay_world::periodic_state_message_classified(*actor))return PublicationStatus::completed;
        return actor_message(id,ActorMessageSelector::state);
    }
    PublicationStatus actor_message(const gameplay_world::actors::EntityId& id,ActorMessageSelector selector)noexcept{
        const auto gate=message_actor(id,std::uint8_t(selector));if(!gate.actor)return gate.status;
        const auto& actor=gate.actor;
        switch(selector){
        case ActorMessageSelector::none:case ActorMessageSelector::reserved:return PublicationStatus::completed;
        case ActorMessageSelector::snapshot:{
            if(gameplay_world::state_message_classified(*actor))actor->status|=0x08000000u;
            else actor->status&=~0x08000000u;
            ActorSnapshotMessage message;message.action={actor->primary,actor->secondary,actor->phase,actor->subphase};
            message.room=std::uint8_t(actor->room);message.position=actor->position;
            message.yaw=actor->orientation[1];message.health=actor->current;message.status=actor->status;
            message.selected_resource=actor->selected_resource;message.equipment=actor->equipment_slot;
            if(!actor->interaction_resource||!actor->aim_pitch_adjustment||!actor->aim_target_pitch||!actor->aim_target_index)return PublicationStatus::unavailable;
            message.interaction_resource=*actor->interaction_resource;message.grid=actor->grid;
            message.aim_pitch_adjustment=*actor->aim_pitch_adjustment;message.aim_target_pitch=*actor->aim_target_pitch;message.aim_target_index=*actor->aim_target_index;
            const auto band=gameplay_world::selected_gauge_band(world_);if(!band)return PublicationStatus::unavailable;
            message.gauge_band=*band;message.resource_pair=actor->explicit_resource_pair;
            message.auxiliary_flag=bool(actor->auxiliary_status&0x20000000u);
            if(actor->category==1)message.model_variant=std::uint8_t(actor->model_variant);
            // This is the same744638 word reset by the World frame. Capture is
            // complete before suppression commits, and before any room lookup.
            world_.session().actor_message_suppression=1;
            return dispatch_actor(*actor,message);
        }
        case ActorMessageSelector::state:{
            if(gameplay_world::state_message_classified(*actor))actor->status|=0x08000000u;
            else actor->status&=~0x08000000u;
            ActorStateMessage message;message.position=actor->position;message.status=actor->status;message.yaw=actor->orientation[1];
            const auto band=gameplay_world::selected_gauge_band(world_);if(!band)return PublicationStatus::unavailable;
            message.gauge_band=*band;return dispatch_actor(*actor,message);
        }
        case ActorMessageSelector::contact_snapshot:{
            ActorContactSnapshotMessage message;message.action={actor->primary,actor->secondary,actor->phase,actor->subphase};
            const std::array<float,3> position{actor->position.x,actor->position.y,actor->position.z};
            for(unsigned i=0;i<3;++i){
                const float value=position[i];
                if(!std::isfinite(value)||value< -2147483648.f||!(value<2147483648.f))return PublicationStatus::unavailable;
                message.position[i]=std::bit_cast<std::int16_t>(std::uint16_t(std::int32_t(value)));
            }
            message.yaw=actor->orientation[1];message.health=actor->current;message.room=std::uint8_t(actor->room);message.status=actor->status;
            message.source_kind=actor->source_kind;message.source_slot=actor->source_slot;message.source_related=actor->contact.source_related;
            message.response_class=actor->response_class;message.region=actor->contact.region;message.auxiliary_a=actor->contact.auxiliary_a;
            message.response_code=actor->contact.response_code;message.response_flags=actor->response_flags;
            const auto band=gameplay_world::selected_gauge_band(world_);if(!band)return PublicationStatus::unavailable;
            message.gauge_band=*band;message.direction=actor->contact.direction;message.recorded_source=actor->contact.recorded_source;
            if(actor->category==1)message.model_variant=std::uint8_t(actor->model_variant);
            world_.session().actor_message_suppression=5;
            return dispatch_actor(*actor,message);
        }
        case ActorMessageSelector::status:{ActorStatusMessage message;message.status=actor->status;message.health=actor->current;return dispatch_actor(*actor,message);}
        case ActorMessageSelector::alignment:{
            if(!actor->alignment_target)return PublicationStatus::unavailable;
            ActorAlignmentMessage message;message.target=*actor->alignment_target;
            return dispatch_actor(*actor,message);
        }
        case ActorMessageSelector::interaction:{ActorInteractionMessage message;message.values={actor->interaction_kind,actor->interaction_mode,actor->interaction_slot,actor->interaction_detail};return dispatch_actor(*actor,message);}
        case ActorMessageSelector::interaction_request:{
            if(!actor->interaction_request||!actor->scene_model.slot())return PublicationStatus::unavailable;
            ActorInteractionRequestMessage message;message.pending=actor->transient_action;
            message.scene_model=*actor->scene_model.slot();message.request=*actor->interaction_request;
            return dispatch_actor(*actor,message);
        }
        case ActorMessageSelector::peer:{
            if(!actor->peer_request||!peer_reference_admitted(actor->peer_request->peer))return PublicationStatus::unavailable;
            ActorPeerMessage message;message.state=std::uint16_t(actor->transient_contact|(unsigned(actor->peer_request->state_high)<<8));message.peer=actor->peer_request->peer;message.parameters=actor->peer_request->parameters;
            if(world_.mode==0){
                const auto peer=world_.referenced_actor(message.peer);
                if(!peer)return message.peer.kind==gameplay_world::actors::ActorReference::Kind::auxiliary?PublicationStatus::completed:PublicationStatus::unavailable;
                peer->transient_contact=std::uint8_t(message.state);
                peer->peer_request=gameplay_world::PeerRequest{std::uint8_t(message.state>>8),{gameplay_world::actors::ActorReference::Kind::primary,actor->slot},message.parameters};
            }
            return dispatch_actor(*actor,message);
        }
        case ActorMessageSelector::room_object:{
            if(!objects_)return PublicationStatus::unavailable;
            const auto coordinates=objects_->source_coordinates(actor->grid);if(!coordinates)return PublicationStatus::unavailable;
            ActorRoomObjectMessage message;message.grid=actor->grid;message.coordinates=*coordinates;
            return dispatch_actor(*actor,message);
        }
        case ActorMessageSelector::resource_pair:{ActorResourcePairMessage message;message.pair=actor->explicit_resource_pair;message.carried=actor->inventory.carried;return dispatch_actor(*actor,message);}
        case ActorMessageSelector::speech:{
            if(!actor->speech.selection||!actor->speech.variant)return PublicationStatus::unavailable;
            const auto selection=*actor->speech.selection;
            ActorSpeechMessage message;message.sequence=selection.sequence;message.target_identifier=selection.target_identifier;
            message.target_context=selection.target_context;message.response_state=selection.response_state;
            message.pending=selection.pending;message.variant=*actor->speech.variant;
            const auto gauge=gameplay_world::selected_gauge_percentage(world_);if(!gauge)return PublicationStatus::unavailable;
            message.gauge_notice=std::int8_t(!(*gauge<90.f));actor->speech.gauge_notice=message.gauge_notice;
            return dispatch_actor(*actor,message);
        }
        case ActorMessageSelector::carried:case ActorMessageSelector::extra:{
            ActorInventoryMessage message;message.kind=selector==ActorMessageSelector::carried?ActorInventoryMessage::Kind::carried:ActorInventoryMessage::Kind::extra;
            if(selector==ActorMessageSelector::carried)message.resources=actor->inventory.carried;
            else for(unsigned i=0;i<4;++i)message.resources[i]=actor->inventory.storage[i+1];
            return dispatch_actor(*actor,message);
        }
        case ActorMessageSelector::action:{
            ActorActionMessage message;message.flags=actor->pending_notice;
            message.values={actor->equipment_notice_slot,actor->equipment_notice_peer,actor->equipment_notice_parameter,actor->equipment_notice_detail};message.equipment=actor->equipment_slot;
            // Complete1B02D0 is raw-mode==0. Capture precedes peer writes.
            if(world_.mode==0){
                const auto request=[&](std::uint8_t owner,std::uint8_t mode,bool copy_resource){
                    const auto peer=world_.primary(unsigned(owner)-1u);if(!peer)return false;
                    peer->interaction_kind=2;peer->interaction_mode=mode;
                    if(copy_resource)peer->interaction_slot=actor->interaction_slot;
                    return true;
                };
                if((actor->pending_notice&1u)&&actor->equipment_notice_peer&&!request(actor->equipment_notice_peer,0,true))return PublicationStatus::unavailable;
                if((actor->pending_notice&4u)&&actor->equipment_notice_parameter&&!request(actor->equipment_notice_parameter,1,false))return PublicationStatus::unavailable;
                if((actor->pending_notice&0x100u)&&actor->equipment_notice_parameter&&!request(actor->equipment_notice_parameter,0,true))return PublicationStatus::unavailable;
            }
            return dispatch_actor(*actor,message);
        }
        default:return PublicationStatus::unavailable;
        }
    }
    PublicationStatus resource_operation(std::uint32_t resource,std::uint32_t actor,std::uint32_t operation)noexcept{
        if(world_.closed())return PublicationStatus::unavailable;
        const auto phase=world_.session().message_phase;
        if((phase!=1&&phase!=2)||(world_.mode!=0&&world_.mode!=1))return PublicationStatus::completed;
        if(!messages_||!messages_->send(ResourceOperationMessage{world_.mode==0?MessageRoute::mode_zero:MessageRoute::mode_one,std::uint16_t(resource),std::uint8_t(actor),std::uint8_t(operation)}))return PublicationStatus::message_unavailable;
        return PublicationStatus::completed;
    }
    PublicationStatus publish(std::uint32_t index,std::uint32_t value,std::uint32_t replacement)noexcept{
        if(world_.closed()||world_.selected_actor>=4)return PublicationStatus::unavailable;
        const auto actor=world_.primary(world_.selected_actor);if(!actor)return PublicationStatus::unavailable;
        if(actor->status&0x5c0u)return PublicationStatus::completed;
        const auto phase=world_.session().message_phase;
        if(phase!=1&&phase!=2)return flags_.scenario_owner(index,std::uint8_t(replacement))?PublicationStatus::completed:PublicationStatus::unavailable;
        if(world_.mode==0||world_.mode==1){
            if(!messages_||!messages_->send(ScenarioOwnerMessage{world_.mode==0?MessageRoute::mode_zero:MessageRoute::mode_one,std::uint16_t(index),std::uint8_t(value)}))return PublicationStatus::message_unavailable;
        }
        // The real message consumer can synchronously change this byte. Read it
        // after dispatch, preserving the protectedFF sentinel in this branch.
        const auto previous=flags_.scenario_owner(index);if(!previous)return PublicationStatus::unavailable;
        if(*previous!=255&&!flags_.scenario_owner(index,std::uint8_t(replacement)))return PublicationStatus::unavailable;
        return PublicationStatus::completed;
    }
private:
    struct ActorAdmission {PublicationStatus status{PublicationStatus::completed};std::shared_ptr<gameplay_world::Actor> actor;};
    ActorAdmission message_actor(const gameplay_world::actors::EntityId& id,std::uint8_t selector)noexcept{
        if(world_.closed())return{PublicationStatus::unavailable,{}};
        const auto phase=world_.session().message_phase;
        if((phase!=1&&phase!=2)||world_.paused)return{};
        const auto actor=world_.resolve(id);if(!actor)return{PublicationStatus::unavailable,{}};
        if(actor->category==0){if(actor->slot!=world_.selected_actor)return{};}
        else if(actor->category==1){if(!(actor->status&0x10000000u))return{};}
        else return{};
        if((actor->status&4u)||world_.session().actor_message_suppression==selector)return{};
        return{PublicationStatus::completed,actor};
    }
    template<class Message>PublicationStatus dispatch_actor(const gameplay_world::Actor& actor,Message message)noexcept{
        if(world_.mode!=0&&world_.mode!=1)return PublicationStatus::completed;
        if(!messages_)return PublicationStatus::message_unavailable;
        if(actor.category==0)message.channel=std::uint32_t(actor.slot)+1u;
        else{
            const auto owner=messages_->room_owner(world_.mode==0?MessageRoute::mode_zero:MessageRoute::mode_one,world_.room);
            if(!owner)return PublicationStatus::unavailable;
            message.channel=*owner+1u;
        }
        // Synchronous room lookup may mutate mode. Payload stays captured.
        if(world_.mode!=0&&world_.mode!=1)return PublicationStatus::completed;
        message.route=world_.mode==0?MessageRoute::mode_zero:MessageRoute::mode_one;
        return messages_->send(message)?PublicationStatus::completed:PublicationStatus::message_unavailable;
    }
    gameplay_world::World& world_;gameplay_scenario::FlagState& flags_;GameplayMessageSink* messages_;
    const gameplay_collision::room_objects::Owner* objects_;
};
}
