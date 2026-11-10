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
class GameplayMessageSink {
public:
    virtual ~GameplayMessageSink()=default;
    virtual bool send(const ScenarioOwnerMessage&)noexcept=0;
    virtual bool send(const ResourceOperationMessage&)noexcept=0;
};
enum class PublicationStatus {completed,unavailable,message_unavailable};
// Complete admitted67DBD0 control/ownership path. Borrow canonical state once;
// live networking requires an explicit actual message consumer, with no no-op.
class StatePublication final {
public:
    StatePublication(gameplay_world::World& world,gameplay_scenario::FlagState& flags,GameplayMessageSink* messages=nullptr):world_(world),flags_(flags),messages_(messages){}
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
    gameplay_world::World& world_;gameplay_scenario::FlagState& flags_;GameplayMessageSink* messages_;
};
}
