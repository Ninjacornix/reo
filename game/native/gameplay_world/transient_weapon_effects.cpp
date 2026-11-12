#include "transient_weapon_effects.hpp"
#include "../gameplay_update/update.hpp"
#include <stdexcept>
namespace reo::native::gameplay_world {
TransientWeaponEffects::TransientWeaponEffects(gameplay_update::Owner& update,gameplay_scenario::Lighting& lights,
    gameplay_lighting::TransientLights& transient,WeaponEffects* remaining)
    :update_(update),lights_(lights),transient_(transient),remaining_(remaining){
    if(!bound_to(update.world()))throw std::invalid_argument("Native weapon lights require the same canonical session owners");
}
bool TransientWeaponEffects::bound_to(const World& world)const noexcept{
    return &update_.world()==&world&&update_.open()&&transient_.bound_to(update_,lights_)&&(!remaining_||remaining_->bound_to(world));
}
bool TransientWeaponEffects::transient_light(const actors::EntityId& actor,animation::Vector point){
    if(!bound_to(update_.world()))return false;
    const auto result=transient_.create(actor,{point.x,point.y,point.z});
    // Source task allocation failure is a normal no-effect return. Either
    // child light pool can fill independently after successful task admission.
    return result.status==gameplay_lighting::TransientStatus::completed||result.status==gameplay_lighting::TransientStatus::task_full;
}
bool TransientWeaponEffects::pose_work(const actors::EntityId& actor,const animation::Matrix& basis,animation::Vector point,std::uint32_t resource){
    return bound_to(update_.world())&&remaining_&&remaining_->pose_work(actor,basis,point,resource);
}
bool TransientWeaponEffects::contact_style(const actors::EntityId& actor,const animation::Matrix& basis,animation::Vector point,std::uint8_t style){
    return bound_to(update_.world())&&remaining_&&remaining_->contact_style(actor,basis,point,style);
}
bool TransientWeaponEffects::flight(const actors::EntityId& actor,const animation::Matrix& basis,std::uint32_t style){
    return bound_to(update_.world())&&remaining_&&remaining_->flight(actor,basis,style);
}
}
