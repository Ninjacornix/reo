#pragma once
#include "weapon_fire.hpp"
#include "../gameplay_lighting/transient_lights.hpp"
namespace reo::native::gameplay_world {
// Supplies actual6B24F0 through the canonical task and dual-light owner.
// The other three effect families remain required reached consumers.
class TransientWeaponEffects final:public WeaponEffects {
public:
    TransientWeaponEffects(gameplay_update::Owner&,gameplay_scenario::Lighting&,
        gameplay_lighting::TransientLights&,WeaponEffects* remaining=nullptr);
    bool bound_to(const World&)const noexcept override;
    bool pose_work(const actors::EntityId&,const animation::Matrix&,animation::Vector,std::uint32_t)override;
    bool transient_light(const actors::EntityId&,animation::Vector)override;
    bool contact_style(const actors::EntityId&,const animation::Matrix&,animation::Vector,std::uint8_t)override;
    bool flight(const actors::EntityId&,const animation::Matrix&,std::uint32_t)override;
private:
    gameplay_update::Owner& update_;gameplay_scenario::Lighting& lights_;
    gameplay_lighting::TransientLights& transient_;WeaponEffects* remaining_;
};
}
