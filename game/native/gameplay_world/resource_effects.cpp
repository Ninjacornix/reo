#include "resource_effects.hpp"
#include "../gameplay_update/update.hpp"
#include <cstring>
namespace reo::native::gameplay_world {
ResourceEffects::ResourceEffects(ResourceRecipes& lifecycle,gameplay_update::Owner& update,ResourceHealthUi* ui):lifecycle_(lifecycle),update_(update),health_(lifecycle,update,ui),deployment_(lifecycle,update){}
ResourceEffectResult ResourceEffects::apply(std::uint32_t full_resource,const actors::EntityId& id){
    health_result_.reset();deployment_result_.reset();completion_.reset();
    if(!update_.open())return{ResourceEffectStatus::unavailable};
    const auto resource=std::uint8_t(full_resource);auto& pairs=lifecycle_.pairs_;auto item=pairs.descriptor(resource);
    if(!item.active||item.parameter<=0||!item.ownership_tag)return{};
    std::uint32_t flags;std::memcpy(&flags,pairs.metadata(resource).encoded.data(),4);
    std::int8_t effect{};
    switch(flags&0x4cu){
    case 4:
        health_result_=health_.apply(resource,id);
        if(health_result_->status!=ResourceHealthStatus::completed)return{ResourceEffectStatus::health_unavailable};
        effect=std::int8_t(health_result_->value);break;
    case 8:
        deployment_result_=deployment_.effect(resource,id);
        if(deployment_result_->status!=ResourceModelStatus::completed)return{ResourceEffectStatus::deployment_unavailable};
        effect=deployment_result_->value;break;
    case 0x40:
        // Complete5B2760 is the stock constant-zero effect, with no accesses.
        break;
    default:break;
    }
    std::int8_t value{};item=pairs.descriptor(resource);
    if(item.parameter>0&&effect){
        if(effect==1)pairs.quantity(resource,std::int32_t(item.parameter)-1);
        value=1;
        const auto actor=update_.world().resolve(id);if(!actor)return{ResourceEffectStatus::unavailable};
        if(update_.world().locally_controlled(*actor)){
            completion_=update_.record_scenario_event(pairs.descriptor(resource).attachment_id);
            if(completion_->status!=gameplay_events::StatisticsStatus::completed)return{ResourceEffectStatus::statistics_unavailable};
        }
        // Flags were captured before the effect. Content/quantity are reread
        // after its synchronous consumers. This helper does not detach inventory.
        if(pairs.descriptor(resource).parameter<=0&&(flags&0x40000u)){
            pairs.destroy_owned(resource);value=2;
        }
    }
    if(effect==3)value=3;
    if(effect==4)value=2;
    return{ResourceEffectStatus::completed,value};
}
}
