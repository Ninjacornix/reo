#pragma once
#include "resource_frames.hpp"
#include "../gameplay_effects/actor_contact_channels.hpp"
namespace reo::native::gameplay_world {
// Actual572290 uses the same owned action offset and fixed Y/X basis as65E880.
// Both consumers share one implementation in weapon_fire.cpp.
class ResourceActorContactPoses final:public gameplay_effects::ActorContactPoses {
public:
    ResourceActorContactPoses(World&,gameplay_scenario::SceneResources&);
    bool bound_to(const World&)const noexcept override;
    bool rebind(const actors::EntityId&,gameplay_effects::ActorContactState&)override;
private:
    World& world_;gameplay_scenario::SceneResources& resources_;
};
}
