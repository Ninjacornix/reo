#include "resource_use.hpp"
#include <bit>
#include <stdexcept>
namespace reo::native::gameplay_world {
ResourceUse::ResourceUse(World& world,gameplay_scenario::SceneResources& resources,const gameplay_scenario::ResourceTemplates& templates,ResourceFrames& frames):world_(world),resources_(resources),templates_(templates),models_(frames.models_){
    if(!frames.open()||&frames.world_!=&world||&frames.resources_!=&resources||!frames.templates_bound_to(templates))throw std::invalid_argument("Native resource use owners unavailable or foreign");
}
gameplay_scenario::SceneDescriptor ResourceUse::descriptor(std::uint8_t index)const{
    if(world_.closed())throw std::runtime_error("Native resource use world closed");
    const auto id=resources_.slot(index);const auto value=id?resources_.get(*id):std::nullopt;
    if(!value)throw std::runtime_error("Native resource use descriptor unavailable");
    return *value;
}
void ResourceUse::configure(std::uint32_t full_resource,const ResourceUsePayload& payload){
    const auto resource=std::uint8_t(full_resource);auto value=descriptor(resource);if(!value.active)return;
    const auto id=resources_.slot(resource);value.flags&=~std::uint32_t(0x20000);
    if(resources_.replace(*id,value)!=gameplay_scenario::SceneStatus::completed)throw std::runtime_error("Native resource use descriptor changed");
    if(!value.primary)return;
    const auto model=std::dynamic_pointer_cast<ResourceModel>(value.primary);
    const auto owned=model?models_.identity_of(*model):ResourceModelId{};
    if(!owned||!model->current())throw std::runtime_error("Native resource use instance foreign or retired");
    model->flags=(model->flags&~std::uint32_t(0x20800))|0x180000u;model->use_delay=0;
    model->use_vector=payload.vector.value_or(animation::Vector{});
    model->use_parameters=payload.parameters.value_or(std::array<std::int16_t,4>{});
}
std::uint8_t ResourceUse::use(std::uint32_t full_resource,const ResourceUsePayload& payload){
    const auto resource=std::uint8_t(full_resource);auto value=descriptor(resource);if(!value.active)return 0;
    if(world_.mode==0&&(world_.session().gameplay_flags&1u)){configure(resource,payload);return 2;}
    value.parameter=std::bit_cast<std::int16_t>(std::uint16_t(std::uint16_t(value.parameter)-1u));
    const auto id=resources_.slot(resource);if(resources_.replace(*id,value)!=gameplay_scenario::SceneStatus::completed)throw std::runtime_error("Native resource use quantity changed");
    configure(resource,payload);return descriptor(resource).parameter>0?2:1;
}
std::int16_t ResourceUse::initial_quantity(std::uint32_t full_resource)const{
    const auto value=descriptor(std::uint8_t(full_resource));if(!value.active||value.template_index==255)return 0;
    if(value.attachment_id==0x3717)return world_.session().clock_mode?600:1200;
    if(value.template_index>=templates_.state().templates.size())throw std::runtime_error("Native resource initial quantity template unavailable");
    const auto& bytes=templates_.state().templates[value.template_index].encoded;
    return std::bit_cast<std::int16_t>(std::uint16_t(std::to_integer<std::uint8_t>(bytes[8])|(std::uint16_t(std::to_integer<std::uint8_t>(bytes[9]))<<8)));
}
void ResourceUse::visibility(std::uint32_t resource,std::uint32_t switch_value){
    const auto value=descriptor(std::uint8_t(resource));if(!value.active||!value.primary)return;
    const auto model=std::dynamic_pointer_cast<ResourceModel>(value.primary);const auto owned=model?models_.identity_of(*model):ResourceModelId{};
    if(!owned||!model->current())throw std::runtime_error("Native resource visibility instance foreign or retired");
    if(std::uint8_t(switch_value)==0)model->flags|=0x80000000u;else model->flags&=~0x80000000u;
}
}
