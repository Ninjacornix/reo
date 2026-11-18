#include "inventory.hpp"
#include "../gameplay_scenario/inventory_compaction.hpp"
#include <algorithm>
#include <stdexcept>
namespace reo::native::gameplay_world {
WorldInventory::WorldInventory(World& world,gameplay_scenario::SceneResources& resources,
    const gameplay_scenario::ResourceTemplates& templates,ResourceFrames& frames):world_(world),resources_(resources),templates_(templates),frames_(frames){
    if(!frames_.open()||&frames_.world_!=&world_||&frames_.resources_!=&resources_||!frames_.templates_bound_to(templates_))throw std::invalid_argument("Native inventory owners unavailable or foreign");
}
std::shared_ptr<Actor> WorldInventory::actor(const actors::EntityId& id)const{
    const auto value=world_.closed()?nullptr:world_.resolve(id);if(!value)throw std::runtime_error("Native inventory actor foreign, stale or closed");return value;
}
gameplay_scenario::SceneDescriptor WorldInventory::descriptor(std::uint8_t index)const{
    const auto id=resources_.slot(index);const auto value=id?resources_.get(*id):std::nullopt;if(!value)throw std::runtime_error("Native inventory descriptor unavailable");return *value;
}
std::uint8_t WorldInventory::find(const actors::EntityId& id,std::uint8_t resource)const{
    const auto value=actor(id);for(unsigned i=0;i<4;++i)if(value->inventory.carried[i]==resource)return std::uint8_t(i);
    for(unsigned i=0;i<32;++i)if(value->inventory.storage[i]==resource)return std::uint8_t(i|0x80u);
    return 255;
}
bool WorldInventory::remove(const actors::EntityId& id,std::uint8_t resource){
    const auto slot=find(id,resource);if(slot==255)return false;const auto value=actor(id);
    if(slot&0x80)value->inventory.storage[slot&0x7f]=0;else value->inventory.carried[slot]=0;return true;
}
std::uint8_t WorldInventory::find_by_content(const actors::EntityId& id,std::uint32_t full_content)const{
    return resources_.find_inventory_content(actor(id)->inventory,full_content);
}
bool WorldInventory::detach_item(const actors::EntityId& id,std::uint8_t resource){
    if(!remove(id,resource))return false;
    const auto value=actor(id);
    if(value->secondary_equipped_resource==resource){frames_.release(resource,true);value->secondary_equipped_resource=0;value->resource_action=0;}
    if(value->selected_resource==resource){frames_.release(resource,true);value->selected_resource=0;value->resource_action=0;}
    return true;
}
void WorldInventory::compact(const actors::EntityId& id){
    const auto value=actor(id);
    gameplay_scenario::compact_inventory(value->inventory,value->character,resources_,templates_);
}
void WorldInventory::insert(const actors::EntityId& id,std::uint8_t resource){
    const auto value=actor(id);const auto empty=std::find(value->inventory.carried.begin(),value->inventory.carried.end(),0);
    if(empty!=value->inventory.carried.end())*empty=descriptor(resource).instance_index;
    compact(id);
}
std::optional<actors::EntityId> WorldInventory::resolve(gameplay_scenario::SceneOwnerReference reference)noexcept{
    if(world_.closed()||reference.family!=gameplay_scenario::SceneOwnerFamily::primary||reference.index>=4)return{};
    const auto value=world_.primary(reference.index);if(!value)return{};const auto id=world_.identity_of(*value);return id?std::optional(id):std::nullopt;
}
gameplay_scenario::SceneStatus WorldInventory::detach(gameplay_scenario::SceneResources& resources,const actors::EntityId& id,std::uint8_t item)noexcept{
    if(&resources!=&resources_)return gameplay_scenario::SceneStatus::invalid_identity;
    try{(void)detach_item(id,item);return gameplay_scenario::SceneStatus::completed;}catch(const std::exception&){return gameplay_scenario::SceneStatus::provider_unavailable;}
}
gameplay_scenario::SceneStatus WorldInventory::refresh(gameplay_scenario::SceneResources& resources,const actors::EntityId& id)noexcept{
    if(&resources!=&resources_)return gameplay_scenario::SceneStatus::invalid_identity;
    try{compact(id);return gameplay_scenario::SceneStatus::completed;}catch(const std::exception&){return gameplay_scenario::SceneStatus::provider_unavailable;}
}
}
