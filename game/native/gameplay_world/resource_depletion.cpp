#include "resource_depletion.hpp"
#include <bit>
#include <cstring>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {template<class T>T read(const gameplay_scenario::ResourceTemplate& row,unsigned at){T value;std::memcpy(&value,row.encoded.data()+at,sizeof value);return value;}}
ResourceDepletion::ResourceDepletion(ResourceRecipes& lifecycle,gameplay_effects::PeriodicVisuals& visuals,animation_events::BasicAudio& audio,gameplay_weapon_resources::Owner& weapons):lifecycle_(lifecycle),factory_(lifecycle.contents_.factory_),use_(lifecycle.pairs_.world_,lifecycle.pairs_.resources_,lifecycle.pairs_.templates_,lifecycle.pairs_.frames_),visuals_(visuals),audio_(audio),weapons_(weapons){
    auto& pairs=lifecycle_.pairs_;
    if(!visuals_.debris_bound_to(pairs.world_,factory_.models_,factory_)||!audio_.bound_to(pairs.world_,pairs.resources_,pairs.templates_)||!weapons_.bound_to(pairs.world_,pairs.resources_,pairs.templates_)||&audio_.owner_!=weapons_.audio_.get())throw std::invalid_argument("Native resource depletion owners unavailable, foreign or split audio");
}
void ResourceDepletion::reset()noexcept{debris_.reset();cue_.reset();refresh_.reset();}
ResourceDepletionResult ResourceDepletion::replace_core(std::uint32_t full_resource,const actors::EntityId& id){
    auto& pairs=lifecycle_.pairs_;if(pairs.world_.closed())return{ResourceDepletionStatus::closed};
    const auto resource=std::uint8_t(full_resource);const auto item=pairs.descriptor(resource);if(!item.active||!item.ownership_tag)return{};
    const auto flags=read<std::uint32_t>(pairs.metadata(resource),0);if(!(flags&1u)||!(flags&0x80000u))return{};
    const auto alternate=read<std::int16_t>(pairs.metadata(resource),10);if(item.parameter>0||alternate<0)return{};
    if(item.primary){
        const auto model=std::dynamic_pointer_cast<ResourceModel>(item.primary);if(!model)return{ResourceDepletionStatus::unavailable};
        if(model->visible){
            const auto model_id=factory_.models_.identity_of(*model);if(!model_id)return{ResourceDepletionStatus::visual_unavailable};
            debris_=visuals_.create_resource_debris(model_id);
            if(debris_->status==gameplay_effects::WorkStatus::unavailable)return{ResourceDepletionStatus::visual_unavailable};
            const auto actor=pairs.world_.resolve(id);if(!actor)return{ResourceDepletionStatus::unavailable};
            try{audio_.resource(*actor,5);cue_=audio_.last_result();}catch(const std::exception&){return{ResourceDepletionStatus::audio_unavailable};}
        }
    }
    lifecycle_.contents_.replace_direct(resource,std::uint16_t(alternate));pairs.quantity(resource,use_.initial_quantity(full_resource));
    // Actor access is reached after replacement when no visible primary exists.
    refresh_=weapons_.refresh(id);if(refresh_->status!=gameplay_weapon_resources::Status::completed)return{ResourceDepletionStatus::weapon_unavailable};
    return{ResourceDepletionStatus::completed,1};
}
ResourceDepletionResult ResourceDepletion::replace_depleted(std::uint32_t resource,const actors::EntityId& id){
    reset();try{return replace_core(resource,id);}catch(const std::exception&){return{ResourceDepletionStatus::unavailable};}
}
ResourceDepletionResult ResourceDepletion::use_cost(std::uint32_t full_resource,const actors::EntityId& id){
    reset();auto& pairs=lifecycle_.pairs_;if(pairs.world_.closed())return{ResourceDepletionStatus::closed};
    try{
        const auto resource=std::uint8_t(full_resource);const auto flags=read<std::uint32_t>(pairs.metadata(resource),0);
        if(pairs.world_.mode==0&&(pairs.world_.session().gameplay_flags&1u))return{ResourceDepletionStatus::completed,2};
        if(flags&0x2000000u){
            const auto actor=pairs.world_.resolve(id);if(!actor)return{ResourceDepletionStatus::unavailable};
            const int cost=actor->character==1?6:actor->character==4?2:4;
            pairs.quantity(resource,std::int32_t(pairs.descriptor(resource).parameter)-cost);
            if(pairs.descriptor(resource).parameter<=0)pairs.quantity(resource,1);
        }
        if(pairs.descriptor(resource).parameter<2&&(flags&0x80000u)){
            pairs.quantity(resource,0);const auto result=replace_core(pairs.descriptor(resource).instance_index,id);
            if(result.status!=ResourceDepletionStatus::completed)return result;
            // The source reports3 even if the replacement helper returned0.
            return{ResourceDepletionStatus::completed,3};
        }
        return{ResourceDepletionStatus::completed,std::int8_t((flags&0x1700000u)?1:2)};
    }catch(const std::exception&){return{ResourceDepletionStatus::unavailable};}
}
ResourceDepletionResult ResourceDepletion::use_owned(std::uint32_t full_resource,const actors::EntityId& id){
    reset();auto& pairs=lifecycle_.pairs_;if(pairs.world_.closed())return{ResourceDepletionStatus::closed};
    try{
        const auto resource=std::uint8_t(full_resource);auto item=pairs.descriptor(resource);
        // This publication precedes activity, quantity and owner admission.
        const auto publish=[&](const gameplay_scenario::SceneDescriptor& value){
            const auto key=pairs.resources_.slot(resource);
            if(!key||pairs.resources_.replace(*key,value)!=gameplay_scenario::SceneStatus::completed)throw std::runtime_error("Native use descriptor unavailable");
        };
        item.flags&=~0x40u;publish(item);
        if(!item.active||item.parameter<=0){item.flags|=0x40u;publish(item);return{};}
        if(!item.ownership_tag)return{};
        const auto flags=read<std::uint32_t>(pairs.metadata(resource),0);
        ResourceDepletionResult policy{};
        if(flags&1u){policy=use_cost(resource,id);if(policy.status!=ResourceDepletionStatus::completed)return policy;}
        std::int8_t result{};
        if(pairs.descriptor(resource).parameter>0&&policy.value){
            if(policy.value==1)pairs.quantity(resource,std::int32_t(pairs.descriptor(resource).parameter)-1);
            result=1;
            if(pairs.descriptor(resource).parameter<=0&&(flags&0x40000u)){
                pairs.destroy_owned(std::uint8_t(full_resource));
                result=2;
            }
        }
        if(policy.value==3)result=3;
        return{ResourceDepletionStatus::completed,result};
    }catch(const std::exception&){return{ResourceDepletionStatus::unavailable};}
}
}
