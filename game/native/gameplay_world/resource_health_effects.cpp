#include "resource_health_effects.hpp"
#include "../gameplay_update/update.hpp"
#include <array>
#include <bit>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
constexpr std::array<std::int16_t,19> healing{
#include "resource_healing_profile.inc"
};
}
ResourceHealthEffects::ResourceHealthEffects(ResourceRecipes& lifecycle,gameplay_update::Owner& update,ResourceHealthUi* ui):lifecycle_(lifecycle),update_(update),ui_(ui){
    if(&lifecycle_.pairs_.world_!=&update_.world()||!update_.open()||(ui_&&!ui_->bound_to(update_.world())))throw std::invalid_argument("Native item health owners unavailable or foreign");
}
ResourceHealthResult ResourceHealthEffects::publish(std::uint32_t resource,std::uint32_t mask,const actors::EntityId& id){
    last_event_.reset();if(!update_.open())return{ResourceHealthStatus::unavailable};
    auto& world=update_.world();auto item=lifecycle_.pairs_.descriptor(std::uint8_t(resource));
    if(item.ownership_tag<1||item.ownership_tag>4)return{ResourceHealthStatus::unavailable};
    const auto owner=world.primary(item.ownership_tag-1);if(!owner)return{ResourceHealthStatus::unavailable};
    if(!world.locally_controlled(*owner))return{};
    const auto target=world.resolve(id);if(!target)return{ResourceHealthStatus::unavailable};
    // The source rereads descriptor owner/content after the local-actor gate.
    item=lifecycle_.pairs_.descriptor(std::uint8_t(resource));unsigned event{},first{};
    if(unsigned(item.ownership_tag)-1u!=target->slot){event=0x1f;first=target->character;}
    else if(mask&8u){event=4;first=item.attachment_id;}
    else if(mask&4u){event=3;first=item.attachment_id;}
    else if((mask&2u)&&(item.attachment_id==0x13c||item.attachment_id==0x13d)){event=2;first=item.attachment_id;}
    else if(mask&3u){event=1;first=item.attachment_id;}
    else return{};
    const auto result=update_.record_event(event,first,0);last_event_=result.status;
    if(result.status!=gameplay_events::Status::completed&&result.status!=gameplay_events::Status::priority_rejected&&result.status!=gameplay_events::Status::full)return{ResourceHealthStatus::event_unavailable};
    return{ResourceHealthStatus::completed,1};
}
ResourceHealthResult ResourceHealthEffects::apply(std::uint32_t full_resource,const actors::EntityId& id){
    last_event_.reset();if(!update_.open())return{ResourceHealthStatus::unavailable};
    if(!id)return{};
    auto& world=update_.world();const auto actor=world.resolve(id);if(!actor)return{ResourceHealthStatus::unavailable};
    if(actor->status&0x1e0u)return{};
    const auto resource=std::uint8_t(full_resource);auto& pairs=lifecycle_.pairs_;const auto item=pairs.descriptor(resource);const auto mask=std::to_integer<std::uint8_t>(pairs.metadata(resource).encoded[10]);
    unsigned events{},pending{};bool changed{};
    if(actor->current<actor->maximum&&(mask&1u)){
        std::int16_t amount=300;
        if(!(actor->status&8u)){
            if(item.attachment_id<300||item.attachment_id>318)return{ResourceHealthStatus::healing_unavailable};
            amount=healing[item.attachment_id-300];
        }
        actor->current=std::bit_cast<std::int16_t>(std::uint16_t(std::int32_t(actor->current)+amount));
        if(actor->current>actor->maximum)actor->current=actor->maximum;
        changed=true;events|=1u;
    }
    if(mask&0xeu){
        if(mask&2u)actor->auxiliary_status|=0x20u;
        else if(mask&4u)actor->auxiliary_status|=8u;
        else if(mask&8u)actor->auxiliary_status|=0x10u;
        changed=true;events|=2u;
    }
    if((mask&0x10u)&&(actor->status&1u)){pending|=2u;changed=true;events|=4u;}
    if((mask&0x20u)&&(actor->status&2u)){pending|=4u;changed=true;events|=8u;}
    if(item.attachment_id==0x138&&!(actor->auxiliary_status&0x1000u)){
        actor->auxiliary_status|=0x1000u;changed=true;
        if(world.locally_controlled(*actor)){
            world.session().inventory_owner=0;
            if(!ui_||!ui_->bound_to(world)||!ui_->close())return{ResourceHealthStatus::ui_unavailable};
            if(!ui_->feedback(id,6))return{ResourceHealthStatus::ui_unavailable};
            if(!ui_->message({0,80,380,60,24,32}))return{ResourceHealthStatus::ui_unavailable};
            if(!ui_->message({0,80,408,60,24,33}))return{ResourceHealthStatus::ui_unavailable};
        }
    }
    if(!changed)return{};
    if(pending){
        const auto selector=pending==2?2u:pending==4?3u:5u;
        if(update_.clear_actor_status(id,selector)!=gameplay_update::PublicationStatus::completed)return{ResourceHealthStatus::message_unavailable};
    }
    const auto event=publish(resource,events,id);if(event.status!=ResourceHealthStatus::completed)return event;
    return{ResourceHealthStatus::completed,1};
}
}
