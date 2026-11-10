#pragma once
#include "../gameplay_world/world.hpp"
#include "../gameplay_scenario/flags.hpp"
namespace reo::native::gameplay_update {
enum class MessageRoute {mode_zero,mode_one};
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
enum class ActorMessageSelector:std::uint8_t {none=0,interaction=4,action=7,resource_pair=10,carried=12,reserved=13,status=14,extra=15};
struct ActorInteractionMessage {
    MessageRoute route{};std::uint32_t channel{};std::array<std::uint8_t,4> values{};
    static constexpr unsigned type=4,length=8,options=0,dispatch_mode=4;
};
struct ActorResourcePairMessage {
    MessageRoute route{};std::uint32_t channel{};std::array<std::uint8_t,2> pair{};std::array<std::uint8_t,4> carried{};
    static constexpr unsigned type=10,length=16,options=0,dispatch_mode=4;
};
struct ActorInventoryMessage {
    enum class Kind:std::uint8_t {carried=12,extra=15};
    MessageRoute route{};std::uint32_t channel{};Kind kind{};std::array<std::uint8_t,4> resources{};
    static constexpr unsigned length=8,options=0,dispatch_mode=4;
};
class GameplayMessageSink {
public:
    virtual ~GameplayMessageSink()=default;
    virtual bool send(const ScenarioOwnerMessage&)noexcept=0;
    virtual bool send(const ResourceOperationMessage&)noexcept=0;
    virtual bool send(const ResourcePositionMessage&)noexcept=0;
    virtual bool send(const ActorStatusMessage&)noexcept=0;
    virtual bool send(const ActorActionMessage&)noexcept{return false;}
    virtual bool send(const ActorInteractionMessage&)noexcept{return false;}
    virtual bool send(const ActorResourcePairMessage&)noexcept{return false;}
    virtual bool send(const ActorInventoryMessage&)noexcept{return false;}
    virtual std::optional<std::uint32_t> room_owner(MessageRoute,std::uint16_t)noexcept{return{};}
};
enum class PublicationStatus {completed,unavailable,message_unavailable};
// Complete admitted67DBD0 control/ownership path. Borrow canonical state once;
// live networking requires an explicit actual message consumer, with no no-op.
class StatePublication final {
public:
    StatePublication(gameplay_world::World& world,gameplay_scenario::FlagState& flags,GameplayMessageSink* messages=nullptr):world_(world),flags_(flags),messages_(messages){}
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
    PublicationStatus actor_message(const gameplay_world::actors::EntityId& id,ActorMessageSelector selector)noexcept{
        const auto gate=message_actor(id,std::uint8_t(selector));if(!gate.actor)return gate.status;
        const auto& actor=gate.actor;
        switch(selector){
        case ActorMessageSelector::none:case ActorMessageSelector::reserved:return PublicationStatus::completed;
        case ActorMessageSelector::status:{ActorStatusMessage message;message.status=actor->status;message.health=actor->current;return dispatch_actor(*actor,message);}
        case ActorMessageSelector::interaction:{ActorInteractionMessage message;message.values={actor->interaction_kind,actor->interaction_mode,actor->interaction_slot,actor->interaction_detail};return dispatch_actor(*actor,message);}
        case ActorMessageSelector::resource_pair:{ActorResourcePairMessage message;message.pair=actor->explicit_resource_pair;message.carried=actor->inventory.carried;return dispatch_actor(*actor,message);}
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
};
}
