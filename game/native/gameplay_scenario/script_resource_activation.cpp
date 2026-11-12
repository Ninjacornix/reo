#include "script_resource_activation.hpp"
#include "../gameplay_world/resource_factory.hpp"
#include <stdexcept>
#include <utility>
namespace reo::native::gameplay_scenario {
ScriptResourceActivation::ScriptResourceActivation(gameplay_world::World& world,SceneResources& resources,
    const ResourceTemplates& templates,gameplay_world::ResourceModels& models,gameplay_world::ResourceFactory& factory):
    world_(world),resources_(resources),templates_(templates),models_(models),factory_(factory){
    if(!bound_to(world_))throw std::invalid_argument("Native script resource activation owners unavailable or foreign");
}
bool ScriptResourceActivation::bound_to(const gameplay_world::World& world,const SceneResources* resources,
    const ResourceTemplates* templates)const noexcept{
    return &world==&world_&&!world_.closed()&&models_.open()&&
        (!resources||resources==&resources_)&&(!templates||templates==&templates_)&&
        factory_.bound_to(world_,resources_,templates_,models_);
}
SceneStatus ScriptResourceActivation::command(std::int16_t authored,std::int16_t ticks)noexcept{
    if(authored<=0)return SceneStatus::completed;
    if(!bound_to(world_))return SceneStatus::provider_unavailable;
    const auto id=resources_.lookup(authored);if(!id)return SceneStatus::completed;
    auto descriptor=resources_.get(*id);if(!descriptor)return SceneStatus::invalid_identity;
    if(!descriptor->active||!descriptor->kind)return SceneStatus::completed;
    descriptor->flags|=1u;
    const bool construct=!descriptor->primary&&descriptor->room==world_.room&&descriptor->ownership_tag==0;
    if(construct)descriptor->flags&=~0x200000u;
    const auto replaced=resources_.replace(*id,*descriptor);if(replaced!=SceneStatus::completed)return replaced;
    if(!construct)return SceneStatus::completed;
    const auto created=factory_.create_delayed(descriptor->attachment_id,ticks);
    if(created.status==gameplay_world::ResourceModelStatus::full)return SceneStatus::completed;
    if(created.status!=gameplay_world::ResourceModelStatus::completed||!created.model)return SceneStatus::provider_unavailable;
    created.model->resource_slot=descriptor->instance_index;
    descriptor=resources_.get(*id);if(!descriptor)return SceneStatus::invalid_identity;
    descriptor->primary=created.model;
    return resources_.replace(*id,std::move(*descriptor));
}
}
