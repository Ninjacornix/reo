#pragma once
#include "weapon_fire.hpp"
#include "../gameplay_effects/periodic_visuals.hpp"
namespace reo::native::gameplay_world {
// Supplies the actual58E6D0 flight family from the same canonical effect work
// pool as other visuals. Other families require their concrete owners.
class FlightWeaponEffects final:public WeaponEffects {
public:
    FlightWeaponEffects(World&,gameplay_effects::PeriodicVisuals&,WeaponEffects* remaining=nullptr);
    bool bound_to(const World&)const noexcept override;
    bool pose_work(const actors::EntityId&,const animation::Matrix&,animation::Vector,std::uint32_t)override;
    bool transient_light(const actors::EntityId&,animation::Vector)override;
    bool contact_style(const actors::EntityId&,const animation::Matrix&,animation::Vector,std::uint8_t)override;
    bool flight(const actors::EntityId&,const animation::Matrix&,std::uint32_t)override;
private:
    World& world_;gameplay_effects::PeriodicVisuals& visuals_;WeaponEffects* remaining_;
};
}
