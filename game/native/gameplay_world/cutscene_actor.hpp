#pragma once
#include "scripted_motion.hpp"
#include "surface_orientation.hpp"
namespace reo::native::gameplay_world {
// Actual primary/NPC action-six secondary handler67BE90. The caller owns
// dispatch, common-frame root integration and basis publication.
class PrimaryCutsceneAction final {
public:
    PrimaryCutsceneAction(World&,ScriptedActorMotion&);
    void tick(const actors::EntityId&);
private:
    World& world_;
    ScriptedActorMotion& motion_;
};
class CutsceneActor final {
public:
    // Borrowed owners must outlive this synchronous callback consumer.
    CutsceneActor(World&,ScriptedActorMotion&,const gameplay_collision::response::Grid&);
    // Complete admitted linked-family6BA880, including its nonzero cinematic-pause
    // gate. This does not schedule itself in the ordinary paused worker pass.
    void tick(const actors::EntityId&);
private:
    World& world_;
    ScriptedActorMotion& motion_;
    GridSurfaceOrientation pose_;
};
}
