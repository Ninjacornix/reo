#pragma once
#include "world.hpp"
#include "../animation/playback.hpp"
namespace reo::native::gameplay_world {
struct ScriptedMotionBanks {
    // Actual scene owners provide these immutable banks. Modes other than
    // exactly1 select other_modes, while any nonzero mode halves tick rate.
    std::shared_ptr<const animation::MotionBank> mode_one,other_modes,track_two;
};
class ScriptedActorMotion final {
public:
    // The World is borrowed and must outlive this synchronous consumer.
    ScriptedActorMotion(World& world,ScriptedMotionBanks banks):world_(world),banks_(std::move(banks)){}
    bool bound_to(const World& world)const noexcept{return &world_==&world&&!world_.closed();}
    // Complete admitted67BFF0 linked and bounded primary-family policy through real native
    // configuration/advancement. Missing required resources throw visibly;
    // effects preceding a failure are retained, with no legacy retry.
    void tick(const actors::EntityId&);
private:
    World& world_;
    ScriptedMotionBanks banks_;
};
}
