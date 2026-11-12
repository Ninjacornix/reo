#include "weapon_actions.hpp"
#include "../gameplay_update/update.hpp"
#include <stdexcept>
namespace reo::native::gameplay_world {
ResourceWeaponActions::ResourceWeaponActions(gameplay_update::Owner& update,gameplay_scenario::SceneResources& resources,
    const gameplay_scenario::ResourceTemplates& templates,WorldInventory& inventory,ResourceDepletion& depletion,
    ResourceDeployment& deployment,animation_events::BasicAudio& audio,ActorWeaponFire* fire)
    :update_(update),world_(update.world()),resources_(resources),templates_(templates),inventory_(inventory),
     depletion_(depletion),deployment_(deployment),audio_(audio),fire_(fire){
    if(!bound_to(world_))throw std::invalid_argument("Native weapon actions require canonical update/resource/audio owners");
}
bool ResourceWeaponActions::bound_to(const World& world)const noexcept{
    return &world_==&world && update_.open() && inventory_.bound_to(world_,resources_,templates_) &&
        depletion_.bound_to(world_,resources_,templates_) && deployment_.bound_to(world_,resources_,templates_) &&
        audio_.bound_to(world_,resources_,templates_);
}
ActorResourceUsed ResourceWeaponActions::use(const actors::EntityId& id,std::uint32_t resource){
    if(!bound_to(world_))return{};
    const auto actor=world_.resolve(id);if(!actor)return{};
    if(std::uint8_t(resource)==0)return{true,0};
    const auto used=depletion_.use_owned(resource,id);
    if(used.status!=ResourceDepletionStatus::completed||world_.resolve(id)!=actor)return{};
    if(world_.locally_controlled(*actor)&&used.value!=0){
        if(!update_.completion_statistics().resource_use(metadata_.action_flags(actor->resource_action)))return{};
    }
    if(used.value==0)audio_.resource(*actor,1);
    else if(used.value==2){
        //5F2120 removes the first inventory reference. Equipment-model
        // retirement belongs to the earlier depletion call, not this helper.
        (void)inventory_.remove(id,actor->selected_resource);
        actor->selected_resource=0;
        //5F1F70 returns zero immediately for a cleared selected resource.
        actor->resource_action=0;
        inventory_.compact(id);
    }
    return{true,used.value};
}
bool ResourceWeaponActions::attack(const actors::EntityId& id,std::uint8_t resource){
    const auto actor=world_.resolve(id);if(!actor)return false;
    if(!(metadata_.action_flags(actor->resource_action)&0x10u))return true;
    const auto key=resources_.slot(resource);const auto item=key?resources_.get(*key):std::nullopt;
    if(!item)return false;
    if(!item->primary)return true;
    return fire_ && fire_->bound_to(world_,resources_,templates_) && fire_->fire(id,resource);
}
bool ResourceWeaponActions::refresh(const actors::EntityId& id){
    if(!bound_to(world_))return false;
    const auto actor=world_.resolve(id);if(!actor)return false;
    actor->status&=~std::uint32_t(0x80000000u);
    const auto resource=actor->selected_resource;if(!resource)return true;
    if(actor->category==0&&actor->slot==world_.selected_actor){
        const auto used=use(id,resource);
        if(!used.available)return false;
        return used.value==0||attack(id,resource);
    }
    if(actor->category==0){
        const auto key=resources_.slot(resource);const auto item=key?resources_.get(*key):std::nullopt;
        if(!item)return false;
        if(item->flags&0x40u){audio_.resource(*actor,1);return true;}
    }else if(actor->category==1){
        const auto admitted=deployment_.admission(resource);
        if(admitted.status!=ResourceModelStatus::completed)return false;
        if(admitted.value==0){audio_.resource(*actor,1);return true;}
        if(admitted.value==1){const auto used=use(id,resource);if(!used.available)return false;return used.value==0||attack(id,resource);}
    }
    return attack(id,resource);
}
}
