#pragma once
#include "world.hpp"

namespace reo::native::gameplay_world {
// The action snapshot is distinct from the per-update previous position and
// orientation. This operation does not advance an animation or save a world.
void save_action_pose(Actor&)noexcept;

enum class MotionStatus {completed,shape_target_unavailable};
// Snapshot/decrement effects precede a missing final target. A caller must not
// retry through a legacy implementation after that partial result.
MotionStatus advance_collision_shape(Actor&)noexcept;

class MotionServices {
public:
    virtual ~MotionServices()=default;
    // Required native tagged-work queue owner. Numeric tags are retained;
    // rendering/effect meaning is not inferred. Actor/World refs are borrowed
    // for this synchronous call; retained work needs a native identity/lease.
    virtual void enqueue(World&,Actor&,std::uint16_t tag_one,std::uint16_t tag_two)=0;
};
void finish_motion(World&,Actor&,MotionServices&);

// Real canonical World consumer of the qualified auxiliary/finish policies.
// Remaining frame/AI/pose/geometry providers are explicitly forwarded. Failure
// retains prior effects and is never followed by a legacy retry.
class MotionFrameServices final:public Services {
public:
    MotionFrameServices(Services& frame,MotionServices& motion):frame_(frame),motion_(motion){}
    void begin_offline_frame(World&)override;
    void run(Stage,World&,Actor&)override;
    bool remote_motion(World&,Actor&)override;
    bool find_grid(World&,Actor&,std::int8_t&)override;
    void switch_grid(World&,std::int32_t,std::int32_t)override;
    float grid_response(World&,std::uint8_t)override;
private:
    Services& frame_;
    MotionServices& motion_;
};
} // namespace reo::native::gameplay_world
