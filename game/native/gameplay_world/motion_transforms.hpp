#pragma once
#include "world.hpp"
#include "../transform_math/transform_math.hpp"

namespace reo::native::gameplay_world {
// Uses the owned actor's root delta, orientation, model scale and multiplier.
// No host delta-time scaling or original instruction execution is involved.
void integrate_local_motion(Actor&);
class MotionTransformServices {
public:
    virtual ~MotionTransformServices()=default;
    // Required native floor/surface-orientation owner. It sees cleared impulses
    // and the canonical current basis/position. Its mutations remain visible.
    virtual void orient_surface(World&,Actor&)=0;
};
void rebuild_actor_pose(World&,Actor&,MotionTransformServices&);

// Real World consumer. Behavior, network-motion admission, other frame stages
// and the remaining native surface/pose owner remain explicit providers.
class MotionTransformFrameServices final:public Services {
public:
    MotionTransformFrameServices(Services& frame,MotionTransformServices& pose):frame_(frame),pose_(pose){}
    void begin_offline_frame(World&)override;
    void run(Stage,World&,Actor&)override;
    bool remote_motion(World&,Actor&)override;
    bool find_grid(World&,Actor&,std::int8_t&)override;
    void switch_grid(World&,std::int32_t,std::int32_t)override;
    float grid_response(World&,std::uint8_t)override;
private:
    Services& frame_;
    MotionTransformServices& pose_;
};
} // namespace reo::native::gameplay_world
