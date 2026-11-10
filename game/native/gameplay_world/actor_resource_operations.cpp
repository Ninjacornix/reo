#include "actor_resource_operations.hpp"
#include <stdexcept>
namespace reo::native::gameplay_world {
ActorResourceOperations::ActorResourceOperations(ResourceRecipes& resources):resources_(resources),world_(resources.pairs_.world_){
    if(world_.closed())throw std::invalid_argument("Native actor resource world closed");
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
}
