#pragma once
#include "motion_transforms.hpp"
namespace reo::native::gameplay_world {
// Shared66A2E0 callback used by the NPC constructor. The supplied frame
// service must own native behavior dispatch; pose/root work is concrete here.
class CommonActorFrame final {
public:
    CommonActorFrame(World& world,Services& behavior,MotionTransformServices& pose):world_(world),behavior_(behavior),pose_(pose){}
    void tick(const actors::EntityId&);
private:
    World& world_;Services& behavior_;MotionTransformServices& pose_;
    bool running_{};
};
}
