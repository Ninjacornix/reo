#pragma once
#include "pose_motion.hpp"
namespace reo::native::gameplay_world {
// Read the actual6BBBA0 producer retained by LinkedActorUpdates. A mode change
// does not rewrite this byte until the actual pass executes again.
class LinkedPoseTimingQuantum final:public PoseTimingQuantum {
public:
    explicit LinkedPoseTimingQuantum(World& world):world_(world){}
    bool bound_to(const World& world)const noexcept override{return &world==&world_&&!world.closed();}
    std::optional<std::uint8_t> read()const noexcept override{
        return bound_to(world_)?world_.session().linked_updates.clock_factor:std::nullopt;
    }
private:
    World& world_;
};
}
