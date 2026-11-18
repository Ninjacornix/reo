#include "pose_weapon_effects.hpp"
#include <stdexcept>
namespace reo::native::gameplay_world {
PoseWeaponEffects::PoseWeaponEffects(World& world,ResourcePoseWork& poses,WeaponEffects* remaining)
    :world_(world),poses_(poses),remaining_(remaining){if(!bound_to(world))throw std::invalid_argument("Native pose weapon-effect owners unavailable");}
bool PoseWeaponEffects::bound_to(const World& world)const noexcept{return &world==&world_&&poses_.bound_to(world)&&(!remaining_||remaining_->bound_to(world));}
bool PoseWeaponEffects::pose_work(const actors::EntityId& id,const animation::Matrix& basis,animation::Vector point,std::uint32_t resource){
    if(!bound_to(world_))return false;
    const auto result=poses_.create(id,basis,point,resource);
    return result.status==PoseWorkStatus::completed||result.status==PoseWorkStatus::full;
}
bool PoseWeaponEffects::transient_light(const actors::EntityId& id,animation::Vector point){return bound_to(world_)&&remaining_&&remaining_->transient_light(id,point);}
bool PoseWeaponEffects::contact_style(const actors::EntityId& id,const animation::Matrix& basis,animation::Vector point,std::uint8_t style){return bound_to(world_)&&remaining_&&remaining_->contact_style(id,basis,point,style);}
bool PoseWeaponEffects::flight(const actors::EntityId& id,const animation::Matrix& basis,std::uint32_t style){return bound_to(world_)&&remaining_&&remaining_->flight(id,basis,style);}
}
