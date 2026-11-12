#include "flight_weapon_effects.hpp"
#include <stdexcept>
namespace reo::native::gameplay_world {
FlightWeaponEffects::FlightWeaponEffects(World& world,gameplay_effects::PeriodicVisuals& visuals,WeaponEffects* remaining):world_(world),visuals_(visuals),remaining_(remaining){
    if(!bound_to(world_))throw std::invalid_argument("Native weapon flight effects require canonical World and visual owners");
}
bool FlightWeaponEffects::bound_to(const World& world)const noexcept{return &world_==&world&&visuals_.flights_bound_to(world)&&(!remaining_||remaining_->bound_to(world));}
bool FlightWeaponEffects::flight(const actors::EntityId& actor,const animation::Matrix& basis,std::uint32_t style){
    if(!bound_to(world_))return false;
    const auto result=visuals_.create_resource_flight(actor,basis,style);
    return result.status==gameplay_effects::WorkStatus::completed||result.status==gameplay_effects::WorkStatus::pool_full||result.status==gameplay_effects::WorkStatus::resource_missing;
}
bool FlightWeaponEffects::pose_work(const actors::EntityId& actor,const animation::Matrix& basis,animation::Vector point,std::uint32_t resource){return bound_to(world_)&&remaining_&&remaining_->pose_work(actor,basis,point,resource);}
bool FlightWeaponEffects::transient_light(const actors::EntityId& actor,animation::Vector point){return bound_to(world_)&&remaining_&&remaining_->transient_light(actor,point);}
bool FlightWeaponEffects::contact_style(const actors::EntityId& actor,const animation::Matrix& basis,animation::Vector point,std::uint8_t style){return bound_to(world_)&&remaining_&&remaining_->contact_style(actor,basis,point,style);}
}
