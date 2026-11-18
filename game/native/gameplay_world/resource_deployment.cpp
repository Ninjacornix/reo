#include "resource_deployment.hpp"
#include "../gameplay_update/update.hpp"
#include <bit>
#include <cmath>
#include <cstring>
#include <stdexcept>
namespace reo::native::gameplay_world {
ResourceDeployment::ResourceDeployment(ResourceRecipes& lifecycle,gameplay_update::Owner& update):lifecycle_(lifecycle),update_(update),factory_(lifecycle.contents_.factory_){
    if(&lifecycle_.pairs_.world_!=&update_.world()||!update_.open()||!factory_.models_.open())throw std::invalid_argument("Native resource deployment owners unavailable or foreign");
}
bool ResourceDeployment::bound_to(const World& world,const gameplay_scenario::SceneResources& resources,
    const gameplay_scenario::ResourceTemplates& templates)const noexcept{
    const auto& pairs=lifecycle_.pairs_;
    return &pairs.world_==&world && &pairs.resources_==&resources && &pairs.templates_==&templates && update_.open();
}
ResourceDeploymentValue ResourceDeployment::count()const{
    if(!update_.open()||!factory_.models_.open())return{ResourceModelStatus::closed,0};
    std::uint8_t count{};unsigned visited{};
    for(auto id=factory_.models_.head();id;id=factory_.models_.next(id)){
        if(++visited>64)return{ResourceModelStatus::unavailable,0};
        const auto model=factory_.models_.retain(id);if(!model)return{ResourceModelStatus::foreign_or_stale,0};
        if(!model->active||!model->visible||model->content_id!=0x3200)continue;
        if(lifecycle_.pairs_.descriptor(model->resource_slot).active)++count;
    }
    return{ResourceModelStatus::completed,std::bit_cast<std::int8_t>(count)};
}
ResourceDeploymentValue ResourceDeployment::admission(std::uint32_t resource)const{
    if(!update_.open())return{ResourceModelStatus::closed,0};
    const auto index=std::uint8_t(resource);const auto item=lifecycle_.pairs_.descriptor(index);if(!item.active||item.parameter<=0||!item.ownership_tag)return{};
    std::uint32_t flags;std::memcpy(&flags,lifecycle_.pairs_.metadata(index).encoded.data(),4);
    if(flags&4u)return{ResourceModelStatus::completed,1};
    if(flags&1u)return{ResourceModelStatus::completed,1};
    if(flags&8u){
        if(item.attachment_id!=0x3201)return{ResourceModelStatus::completed,1};
        const auto live=count();if(live.status!=ResourceModelStatus::completed)return live;
        return{ResourceModelStatus::completed,std::int8_t(live.value<11)};
    }
    return{ResourceModelStatus::completed,std::int8_t(bool(flags&0x40u))};
}
ResourceModelCreated ResourceDeployment::place(const actors::EntityId& id,std::uint32_t full_resource,const Position& position){
    if(!update_.open())return{ResourceModelStatus::closed,{},{}};
    const auto resource=std::uint16_t(full_resource);if(resource>=256)return{ResourceModelStatus::unavailable,{},{}};
    auto& pairs=lifecycle_.pairs_;auto item=pairs.descriptor(std::uint8_t(resource));if(item.attachment_id!=0x3201)return{ResourceModelStatus::completed,{},{}};
    lifecycle_.contents_.replace_direct(resource,0x3200);item=pairs.descriptor(std::uint8_t(resource));item.ownership_tag=0;item.flags=(item.flags|0x200000u)&~0x800u;const auto key=pairs.resources_.slot(resource);
    if(!key||pairs.resources_.replace(*key,item)!=gameplay_scenario::SceneStatus::completed)return{ResourceModelStatus::foreign_or_stale,{},{}};
    const auto actor=update_.world().resolve(id);if(!actor)return{ResourceModelStatus::unavailable,{},{}};
    item.room=std::uint8_t(actor->room);if(pairs.resources_.replace(*key,item)!=gameplay_scenario::SceneStatus::completed)return{ResourceModelStatus::foreign_or_stale,{},{}};
    if(!std::isfinite(position.x)||!std::isfinite(position.y)||!std::isfinite(position.z))return{ResourceModelStatus::unavailable,{},{}};
    item.position={position.x,position.y+2.0f,position.z};item.yaw=item.tilt=item.authored_id=0;
    if(pairs.resources_.replace(*key,item)!=gameplay_scenario::SceneStatus::completed)return{ResourceModelStatus::foreign_or_stale,{},{}};
    if(update_.world().room!=item.room)return{ResourceModelStatus::completed,{},{}};
    auto result=factory_.create(item.attachment_id,1);if(result.status!=ResourceModelStatus::completed)return result;
    auto& model=*result.model;model.position=item.position;model.flags=item.flags;model.resource_slot=item.instance_index;item.primary=result.model;
    if(pairs.resources_.replace(*key,item)!=gameplay_scenario::SceneStatus::completed){result.status=ResourceModelStatus::foreign_or_stale;return result;}
    if(!factory_.floors_||factory_.scene_room_!=update_.world().room){result.status=ResourceModelStatus::unavailable;return result;}
    model.draw_layer=factory_.floors_->floor({model.position.x,model.position.y,model.position.z},255).material;return result;
}
ResourceDeploymentValue ResourceDeployment::effect(std::uint32_t resource,const actors::EntityId& id){
    if(!update_.open())return{ResourceModelStatus::closed,0};
    const auto index=std::uint8_t(resource);if(lifecycle_.pairs_.descriptor(index).attachment_id!=0x3201)return{};
    const auto live=count();if(live.status!=ResourceModelStatus::completed)return live;if(live.value>=11)return{};
    const auto actor=update_.world().resolve(id);if(!actor)return{ResourceModelStatus::unavailable,0};
    if(update_.record_resource_position(lifecycle_.pairs_.descriptor(index).instance_index,actor->slot,3,actor->position)!=gameplay_update::PublicationStatus::completed)return{ResourceModelStatus::unavailable,0};
    const auto result=place(id,lifecycle_.pairs_.descriptor(index).instance_index,actor->position);
    if(result.status!=ResourceModelStatus::completed&&result.status!=ResourceModelStatus::full)return{result.status,0};
    return{ResourceModelStatus::completed,4};
}
}
