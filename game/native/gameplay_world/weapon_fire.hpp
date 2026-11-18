#pragma once
#include "weapon_actions.hpp"
#include "resource_programs.hpp"
#include "resource_health_effects.hpp"
namespace reo::native::gameplay_world {
// Reached constructors have distinct lifetimes and failure semantics. These
// required consumers cannot be replaced with recorded requests in a game host.
class WeaponEffects {
public:
    virtual ~WeaponEffects()=default;
    virtual bool bound_to(const World&)const noexcept=0;
    virtual bool pose_work(const actors::EntityId&,const animation::Matrix&,
                           animation::Vector,std::uint32_t resource)=0; //5823E0
    virtual bool transient_light(const actors::EntityId&,animation::Vector)=0; //6B24F0
    virtual bool contact_style(const actors::EntityId&,const animation::Matrix&,
                              animation::Vector,std::uint8_t)=0; //5DD270
    virtual bool flight(const actors::EntityId&,const animation::Matrix&,
                        std::uint32_t style)=0; //58E6D0
};
// Complete65E880 preparation and branch order. Audio and program selection use
// their actual canonical owners; effect creation and feedback require owners.
class ResourceWeaponFire final:public ActorWeaponFire {
public:
    ResourceWeaponFire(World&,gameplay_scenario::SceneResources&,
        const gameplay_scenario::ResourceTemplates&,animation_events::BasicAudio&,
        WorldResourcePrograms&,ResourceHealthUi*,WeaponEffects*);
    bool bound_to(const World&,const gameplay_scenario::SceneResources&,
                  const gameplay_scenario::ResourceTemplates&)const noexcept override;
    bool fire(const actors::EntityId&,std::uint8_t resource)override;
    bool fire_resource(const actors::EntityId&,std::uint32_t resource);
private:
    World& world_;gameplay_scenario::SceneResources& resources_;
    const gameplay_scenario::ResourceTemplates& templates_;
    animation_events::BasicAudio& audio_;WorldResourcePrograms& programs_;
    ResourceHealthUi* ui_;WeaponEffects* effects_;animation_events::File1Metadata metadata_;
};
}
