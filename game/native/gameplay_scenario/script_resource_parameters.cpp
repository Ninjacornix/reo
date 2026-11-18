#include "script_resource_parameters.hpp"
#include "resource_templates.hpp"
#include "../gameplay_world/inventory.hpp"
#include "../gameplay_world/resource_factory.hpp"
#include <algorithm>
#include <bit>
#include <stdexcept>
#include <utility>
namespace reo::native::gameplay_scenario {
bool script_resource_parameter_noop(const gameplay_world::World& world,std::uint16_t resource)noexcept{
    return !world.closed()&&world.mode==0&&(world.session().gameplay_flags&1u)&&resource==31;
}
ScriptResourceParameters::ScriptResourceParameters(gameplay_world::World& world,SceneResources& resources,
    const ResourceTemplates& templates,gameplay_world::ResourceModels& models,
    gameplay_world::ResourceFactory& factory,gameplay_world::WorldInventory& inventory)
    :world_(world),resources_(resources),templates_(templates),models_(models),factory_(factory),inventory_(inventory){
    if(!bound_to(world))throw std::invalid_argument("Native script resource parameter owners unavailable or foreign");
}
bool ScriptResourceParameters::bound_to(const gameplay_world::World& world,const SceneResources* resources,
    const ResourceTemplates* templates)const noexcept{
    return &world_==&world&&!world_.closed()&&models_.open()&&
        (!resources||resources==&resources_)&&(!templates||templates==&templates_)&&
        factory_.bound_to(world_,resources_,templates_,models_)&&inventory_.bound_to(world_,resources_,templates_,models_);
}
ScriptResourceParameters::Prepared ScriptResourceParameters::prepare(std::uint16_t resource,std::int16_t quantity)const noexcept{
    if(script_resource_parameter_noop(world_,resource))return{SceneStatus::completed};
    if(!bound_to(world_))return{};
    const auto found=resources_.lookup_attached(std::bit_cast<std::int16_t>(resource));
    if(!found)return{SceneStatus::completed};
    const auto descriptor=resources_.get(found->id);if(!descriptor)return{};
    if(!descriptor->active)return{SceneStatus::completed};
    const auto self=resources_.slot(descriptor->instance_index);const auto metadata=self?resources_.get(*self):std::nullopt;
    if(!metadata)return{};
    const auto index=metadata->active&&metadata->template_index!=255?metadata->template_index:std::uint8_t(128);
    if(index>=templates_.state().templates.size())return{};
    const auto& encoded=templates_.state().templates[index].encoded;
    const auto maximum=std::bit_cast<std::int16_t>(std::uint16_t(std::to_integer<std::uint16_t>(encoded[8])|
        (std::to_integer<std::uint16_t>(encoded[9])<<8)));
    quantity=std::min(quantity,maximum);
    // 5B4380 uses fallback128 for the upper bound. The separate5B43F0
    // predicate returns zero for inactive/FF metadata instead of that fallback.
    const bool detach=metadata->active&&metadata->template_index!=255&&
        (templates_.flags(index)&0x40000u)&&quantity==0;
    if(detach&&(found->owner.family!=SceneOwnerFamily::primary||found->owner.index>=4||!world_.primary(found->owner.index)))return{};
    return{SceneStatus::completed,found,quantity,detach};
}
bool ScriptResourceParameters::ready(std::uint16_t resource,std::int16_t quantity)const noexcept{
    return prepare(resource,quantity).status==SceneStatus::completed;
}
SceneStatus ScriptResourceParameters::command(std::uint16_t resource,std::int16_t quantity)noexcept{
    const auto prepared=prepare(resource,quantity);if(prepared.status!=SceneStatus::completed)return prepared.status;
    if(!prepared.resource)return SceneStatus::completed;
    if(prepared.detach)return resources_.detach(*prepared.resource,&factory_,&inventory_);
    auto descriptor=resources_.get(prepared.resource->id);if(!descriptor)return SceneStatus::invalid_identity;
    descriptor->parameter=prepared.quantity;
    return resources_.replace(prepared.resource->id,std::move(*descriptor));
}
}
