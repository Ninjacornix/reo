#pragma once
#include "pose_work_pool.hpp"
namespace reo::native::gameplay_world {
enum class PoseMotionStep {completed,retire,unavailable,unhandled};
// Complete584160/583BF0 over the actual specialty/common actor fields.
// The74F200 byte is independent of clock_mode3243CC. Unknown stays unknown.
PoseMotionStep advance_pose_motion(Actor&,std::uint8_t kind,std::optional<std::uint8_t> quantum);
class PoseTimingQuantum {
public:
    virtual ~PoseTimingQuantum()=default;
    virtual bool bound_to(const World&)const noexcept=0;
    // Read-only view of the actual producer; this must not run simulation work.
    virtual std::optional<std::uint8_t> read()const noexcept=0;
};
class PoseMotionUpdates final:public PoseWorkUpdates {
public:
    PoseMotionUpdates(World&,PoseWorkPool&,PoseTimingQuantum* =nullptr,PoseWorkUpdates* remaining=nullptr);
    bool bound_to(const World&)const noexcept override;
    bool update(PoseWorkPool&,const actors::EntityId&,std::uint8_t)override;
private:
    World& world_;PoseWorkPool& pool_;PoseTimingQuantum* quantum_;PoseWorkUpdates* remaining_;
};
}
