#include "resource_frames.hpp"
#include <bit>
#include <stdexcept>
namespace reo::native::gameplay_world {
void ResourceFrames::admit(const ResourceModelId& id,const ResourceModel& model)const{
    if(world_.closed()||models_.retain(id).get()!=&model||!model.current())throw std::runtime_error("Native resource frame model owner unavailable, foreign or retired");
}
gameplay_scenario::SceneDescriptor ResourceFrames::descriptor(std::uint8_t slot)const{
    const auto id=resources_.slot(slot);const auto value=id?resources_.get(*id):std::nullopt;
    if(!value)throw std::runtime_error("Native resource frame descriptor unavailable");
    return *value;
}
void ResourceFrames::release(std::uint8_t slot,bool clear_owner_flag){
    const auto id=resources_.slot(slot);auto current=id?resources_.get(*id):std::nullopt;
    if(!current)throw std::runtime_error("Native resource release identity unavailable");
    if(!current->active)return;
    if(current->secondary)throw std::runtime_error("Native resource secondary release consumer unavailable");
    if(current->primary){
        const auto model=std::dynamic_pointer_cast<ResourceModel>(current->primary);
        const auto owned=model?models_.identity_of(*model):ResourceModelId{};
        if(!owned||models_.retire(owned)!=ResourceModelStatus::completed)throw std::runtime_error("Native resource release primary owner unavailable");
        current->primary.reset();
    }
    if(clear_owner_flag)current->flags&=~0x20000u;
    if(resources_.replace(*id,*current)!=gameplay_scenario::SceneStatus::completed)throw std::runtime_error("Native resource release descriptor changed");
}
const ResourcePartPoses& ResourceFrames::bases(const ResourceModel& model)const{
    if(!model.base_parts||model.asset_index<0||model.base_parts->asset_index!=model.asset_index||model.base_parts->count>6)throw std::runtime_error("Native resource asset base poses unavailable");
    return *model.base_parts;
}
void ResourceFrames::common(const ResourceModelId& id,ResourceModel& model){
    admit(id,model);
    if(!model.active)return;
    model.visible=!(model.flags&0x80000000u);
    if(model.flags&0x20000u){
        const auto entry=descriptor(model.resource_slot);const auto owner=std::bit_cast<std::int16_t>(std::uint16_t(entry.ownership_tag-1u));
        if(owner<0){model.visible=false;return;}
        if(owner>=4)throw std::runtime_error("Native extended resource actor owner unavailable");
        const auto actor=world_.primary(unsigned(owner));
        if(!actor||!actor->active||(actor->status&0x5e0u)){release(model.resource_slot,true);return;}
        if(actor->room!=world_.room||!actor->visible){model.visible=false;return;}
        const auto& session=world_.session();
        if((session.resource_hide_selected&&world_.selected_actor==owner)||(session.resource_hide_others&&world_.selected_actor!=owner)){model.visible=false;return;}
        model.draw_layer=actor->surface_material;
        return;
    }
    if((model.flags&0x800u)&&!(model.flags&0x400u))throw std::runtime_error("Native resource room pulse consumer unavailable");
    if((model.flags&0x100000u)&&(model.flags&0x40000000u))throw std::runtime_error("Native resource reconstruction consumer unavailable");
    if(model.flags&0x80000u)throw std::runtime_error("Native resource1904A0 pose profile unavailable");
}
void ResourceFrames::weapon(const ResourceModelId& id,ResourceModel& model){
    common(id,model);
    if(!model.current()||!(model.flags&0x20000u))return;
    const auto entry=descriptor(model.resource_slot);auto& state=model.program;
    std::shared_ptr<Actor> actor;
    if(entry.ownership_tag&&entry.ownership_tag<5){
        actor=world_.primary(entry.ownership_tag-1u);
        if(!actor)throw std::runtime_error("Native weapon owner actor unavailable");
        if(actor->status&0x200u){const auto& source=bases(model);for(unsigned part=0;part<source.count;++part){model.part_enabled[part]=1;model.parts[part]=source.poses[part];}}
    }else state.phase=0;
    if(state.phase==0){state.elapsed=0;state.completed.fill(0);return;}
    if(state.phase!=1)return;
    if(!actor||!state.source||!state.selected||actor->weapon_programs!=state.source)throw std::runtime_error("Native weapon program binding unavailable or replaced");
    for(unsigned part=0;part<6;++part){
        auto& completed=state.completed[part];if(completed==63)continue;
        const auto& program=state.selected->parts[part];
        if(!program){completed=63;continue;}
        std::array<float,6> values{};
        for(unsigned axis=0;axis<6;++axis){const auto bit=std::uint8_t(1u<<axis);if(completed&bit)continue;
            const auto& curve=program->curves[axis];if(!curve){completed|=bit;continue;}
            const auto sampled=curve->sample(state.elapsed);values[axis]=sampled.value;if(sampled.finished)completed|=bit;
        }
        // Source extracts a static base translation but never uses its result.
        // The six curve values are written directly, preserving matrix W.
        (void)bases(model);
        animation::Parameters parameters{};for(unsigned i=0;i<3;++i){parameters[3+i]=values[3+i];parameters[6+i]=values[i];}
        auto pose=animation::unscaled_pose(parameters);for(unsigned i=0;i<4;++i)pose[i][3]=model.parts[part][i][3];model.parts[part]=pose;
    }
    state.elapsed=std::bit_cast<std::int16_t>(std::uint16_t(std::uint16_t(state.elapsed)+2u));
    bool finished=true;for(unsigned part=0;part<6;++part)if(state.completed[part]!=63)finished=false;
    if(finished)state.phase=0;
}
void WeaponModelWork::update(ResourceModels& models,const ResourceModelId& id,ResourceModel& model){
    if(!frames_.bound_to(models))throw std::runtime_error("Native weapon work owner foreign");
    frames_.weapon(id,model);
}
void CommonModelWork::update(ResourceModels& models,const ResourceModelId& id,ResourceModel& model){
    if(!frames_.bound_to(models))throw std::runtime_error("Native common work owner foreign");
    frames_.common(id,model);
}
}
