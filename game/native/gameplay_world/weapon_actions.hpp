#pragma once
#include "primary_actor_postprocess.hpp"
#include "resource_depletion.hpp"
#include "resource_deployment.hpp"
#include "animation_events.hpp"
namespace reo::native::gameplay_update {class Owner;}
namespace reo::native::gameplay_world {
// The reached65E880 firing/effect owner. Missing firing work refuses only
// when the original metadata and primary-model gates actually require it.
class ActorWeaponFire {
public:
    virtual ~ActorWeaponFire()=default;
    virtual bool bound_to(const World&,const gameplay_scenario::SceneResources&,
                          const gameplay_scenario::ResourceTemplates&)const noexcept=0;
    virtual bool fire(const actors::EntityId&,std::uint8_t resource)=0;
};
struct ActorResourceUsed {
    bool available{};
    std::int8_t value{};
};
// Canonical65EC40/65E750 resource use, statistics, audio and inventory owner.
// The firing branch additionally requires the actual65E880 consumer above.
class ResourceWeaponActions final:public ActorWeaponActions {
public:
    ResourceWeaponActions(gameplay_update::Owner&,gameplay_scenario::SceneResources&,
        const gameplay_scenario::ResourceTemplates&,WorldInventory&,ResourceDepletion&,
        ResourceDeployment&,animation_events::BasicAudio&,ActorWeaponFire* = nullptr);
    bool bound_to(const World&)const noexcept override;
    bool refresh(const actors::EntityId&)override;
    ActorResourceUsed use(const actors::EntityId&,std::uint32_t resource);
private:
    gameplay_update::Owner& update_;World& world_;
    gameplay_scenario::SceneResources& resources_;const gameplay_scenario::ResourceTemplates& templates_;
    WorldInventory& inventory_;ResourceDepletion& depletion_;ResourceDeployment& deployment_;
    animation_events::BasicAudio& audio_;ActorWeaponFire* fire_;
    animation_events::File1Metadata metadata_;
    bool attack(const actors::EntityId&,std::uint8_t resource);
};
}
