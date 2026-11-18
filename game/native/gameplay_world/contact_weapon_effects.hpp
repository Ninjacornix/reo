#pragma once
#include "weapon_fire.hpp"
#include "../gameplay_effects/contact_styles.hpp"
#include "../gameplay_effects/actor_contact_channels.hpp"
namespace reo::native::gameplay_world {
using ActorContactChannels=gameplay_effects::ActorContactBackend;
class ContactWeaponEffects final:public WeaponEffects {
public:
    ContactWeaponEffects(World&,gameplay_effects::WorkBackend&,ActorContactChannels* channels=nullptr,WeaponEffects* remaining=nullptr);
    bool bound_to(const World&)const noexcept override;
    bool pose_work(const actors::EntityId&,const animation::Matrix&,animation::Vector,std::uint32_t)override;
    bool transient_light(const actors::EntityId&,animation::Vector)override;
    bool contact_style(const actors::EntityId&,const animation::Matrix&,animation::Vector,std::uint8_t)override;
    bool flight(const actors::EntityId&,const animation::Matrix&,std::uint32_t)override;
private:
    World& world_;gameplay_effects::WorkBackend& work_;ActorContactChannels* channels_;WeaponEffects* remaining_;
};
}
