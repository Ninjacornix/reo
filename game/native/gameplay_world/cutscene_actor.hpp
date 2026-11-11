#pragma once
#include "scripted_motion.hpp"
#include "surface_orientation.hpp"
namespace reo::native::gameplay_world {
class CutsceneActor final {
public:
    // Borrowed owners must outlive this synchronous callback consumer.
    CutsceneActor(World&,ScriptedActorMotion&,const gameplay_collision::response::Grid&);
    // Complete admitted6BA880, including its distinct nonzero cinematic-pause
    // gate. This does not schedule itself in the ordinary paused worker pass.
    void tick(const actors::EntityId&);
private:
    World& world_;
    ScriptedActorMotion& motion_;
    GridSurfaceOrientation pose_;
};
}
