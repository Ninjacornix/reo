#include "actor_resource_operations.hpp"
#include "resource_auxiliary_lists.hpp"
#include "resource_ownership.hpp"
#include <stdexcept>
namespace reo::native::gameplay_world {
ActorResourceOperations::ActorResourceOperations(ResourceRecipes& resources):resources_(resources),world_(resources.pairs_.world_){
    if(world_.closed())throw std::invalid_argument("Native actor resource world closed");
}
bool ActorResourceOperations::clear_claims()noexcept{
    return !world_.closed()&&clear_resource_claims(resources_.pairs_.resources_);
}
std::shared_ptr<Actor> ActorResourceOperations::actor(const actors::EntityId& id)const{
    const auto value=world_.closed()?nullptr:world_.resolve(id);
    if(!value)throw std::runtime_error("Native actor resource capability foreign, retired or closed");
    return value;
}
bool ActorResourceOperations::eligible(const Actor& actor,std::uint8_t mode)const noexcept{
    return actor.category==1||(mode!=0&&mode!=1)||(mode==0?actor.slot==world_.selected_actor:actor.slot!=world_.selected_actor);
}
void ActorResourceOperations::notice(Actor& actor,std::uint16_t mask,std::uint8_t resource)noexcept{
    actor.pending_notice|=mask;actor.equipment_notice_slot=resource;
}
std::int8_t ActorResourceOperations::transfer_quantity(const actors::EntityId& id,std::uint32_t full_mode,std::uint32_t first,std::uint32_t second,std::uint32_t amount){
    const auto value=actor(id);const auto mode=std::uint8_t(full_mode);if(!eligible(*value,mode))return -1;
    const auto result=resources_.pairs_.transfer_owned(first,second,amount);if(!result)return 0;
    std::int8_t handled{};
    if(result>=1&&result<=3){
        handled=result;
        if(result==2||result==3){(void)resources_.inventory_.detach_item(id,std::uint8_t(result==2?first:second));resources_.inventory_.compact(id);}
    }
    if(mode!=1){notice(*value,0x1000,std::uint8_t(first));value->equipment_notice_peer=std::uint8_t(second);value->equipment_notice_parameter=std::uint8_t(amount);}
    return handled;
}
std::int8_t ActorResourceOperations::release_instances(const actors::EntityId& id,std::uint32_t full_mode,std::uint32_t resource){
    const auto value=actor(id);const auto mode=std::uint8_t(full_mode);if(!eligible(*value,mode))return -1;
    resources_.pairs_.frames_.release(std::uint8_t(resource));if(mode!=1)notice(*value,0x800,std::uint8_t(resource));return 1;
}
std::int8_t ActorResourceOperations::remap_content(const actors::EntityId& id,std::uint32_t full_mode,std::uint32_t resource){
    const auto value=actor(id);const auto mode=std::uint8_t(full_mode);if(!eligible(*value,mode))return -1;
    const auto result=resources_.contents_.remap(resource);
    if(result&&value->selected_resource==std::uint8_t(resource)){resources_.pairs_.frames_.release(std::uint8_t(resource),true);value->selected_resource=0;value->resource_action=0;}
    if(mode!=1){notice(*value,0x8000,std::uint8_t(resource));}return std::int8_t(result);
}
bool ActorResourceOperations::transfer_inventory_ready(const actors::EntityId& id,std::uint32_t full_mode)const noexcept{
    const auto value=world_.closed()?nullptr:world_.resolve(id);if(!value)return false;
    const auto mode=std::uint8_t(full_mode);
    if(value->category!=0||(mode==0&&value->slot!=world_.selected_actor)||(mode==1&&value->slot==world_.selected_actor))return true;
    if(value->selected_resource&&!resources_.pairs_.frames_.release_ready(value->selected_resource))return false;
    if(value->auxiliary_status&0x02000000u)return true;
    if(!value->inventory.carried[0]&&!value->inventory.storage[0])return true;
    try{
        ResourceAuxiliaryLists lists(resources_.inventory_);
        if(!lists.append_ready(value->slot,value->inventory.carried,4))return false;
        return value->character!=6||lists.append_ready(value->slot,value->inventory.storage,32);
    }catch(...){return false;}
}
std::int8_t ActorResourceOperations::transfer_inventory(const actors::EntityId& id,std::uint32_t full_mode){
    const auto value=actor(id);const auto mode=std::uint8_t(full_mode);
    if(value->category!=0||(mode==0&&value->slot!=world_.selected_actor)||(mode==1&&value->slot==world_.selected_actor))return -1;
    if(value->selected_resource){resources_.pairs_.frames_.release(value->selected_resource,true);value->selected_resource=0;value->resource_action=0;}
    if(value->auxiliary_status&0x02000000u)return -1;
    value->auxiliary_status|=0x02000000u;
    if(!value->inventory.carried[0]&&!value->inventory.storage[0])return -1;
    ResourceAuxiliaryLists lists(resources_.inventory_);
    auto count=lists.append(value->slot,value->inventory.carried,4);
    if(value->character==6)count=std::int8_t(count+lists.append(value->slot,value->inventory.storage,32));
    value->inventory.carried.fill(0);value->inventory.storage.fill(0);
    if(mode!=1)value->pending_notice|=0x2000u;
    return count;
}
}
