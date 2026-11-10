#include "resource_contents.hpp"
#include <bit>
#include <stdexcept>
namespace reo::native::gameplay_world {
ResourceContents::ResourceContents(World& world,gameplay_scenario::SceneResources& resources,
    const gameplay_scenario::ResourceTemplates& templates,ResourceFrames& frames,ResourceFactory& factory):world_(world),resources_(resources),templates_(templates),factory_(factory),use_(world,resources,templates,frames){
    if(&factory.frames_!=&frames)throw std::invalid_argument("Native resource content factory foreign");
}
gameplay_scenario::SceneDescriptor ResourceContents::descriptor(std::uint8_t index)const{
    if(world_.closed())throw std::runtime_error("Native resource content world closed");
    const auto id=resources_.slot(index);const auto value=id?resources_.get(*id):std::nullopt;
    if(!value)throw std::runtime_error("Native resource content descriptor unavailable");
    return *value;
}
void ResourceContents::replace_direct(std::uint32_t full_resource,std::uint32_t full_content){
    const auto resource=std::uint8_t(full_resource);const auto content=std::uint16_t(full_content);auto value=descriptor(resource);
    value.attachment_id=content;value.template_index=std::bit_cast<std::uint8_t>(templates_.selector(std::bit_cast<std::int16_t>(content)));
    const auto id=resources_.slot(resource);if(resources_.replace(*id,value)!=gameplay_scenario::SceneStatus::completed)throw std::runtime_error("Native resource content descriptor changed");
    if(!value.primary)return;
    const auto model=std::dynamic_pointer_cast<ResourceModel>(value.primary);const auto owned=model?factory_.models_.identity_of(*model):ResourceModelId{};
    if(!owned)throw std::runtime_error("Native resource content instance foreign or retired");
    factory_.rebind(owned,content);
}
bool ResourceContents::replace_owned(std::uint32_t full_resource,std::uint32_t full_content){
    const auto resource=std::uint8_t(full_resource);auto value=descriptor(resource);
    if(!value.active||!value.ownership_tag||std::int32_t(value.attachment_id)==std::int32_t(std::bit_cast<std::int16_t>(std::uint16_t(full_content))))return false;
    replace_direct(resource,full_content);value=descriptor(resource);value.parameter=use_.initial_quantity(resource);
    const auto id=resources_.slot(resource);if(resources_.replace(*id,value)!=gameplay_scenario::SceneStatus::completed)throw std::runtime_error("Native resource content quantity changed");
    return true;
}
bool ResourceContents::remap(std::uint32_t full_resource){
    const auto resource=std::uint8_t(full_resource);const auto value=descriptor(resource);if(!value.active)return false;
    std::uint16_t next{};switch(value.attachment_id){case 0:next=0x1c5;break;case 1:next=0x1c8;break;case 0xb:next=0x1c6;break;default:return false;}
    replace_direct(resource,next);return true;
}
}
