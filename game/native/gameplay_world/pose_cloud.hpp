#pragma once
#include "pose_work_pool.hpp"
#include "../gameplay_effects/work.hpp"
#include "../gameplay_lighting/timed_lights.hpp"
namespace reo::native::gameplay_world {
class PoseCloudEffects {
public:
    virtual ~PoseCloudEffects()=default;
    virtual bool visual(transform_math::Vector)=0;
    virtual bool light(const actors::EntityId&,transform_math::Vector)=0;
};
enum class PoseCloudStep {completed,retire,unavailable};
// Complete5846C0. Retirement is applied by its canonical pose owner.
PoseCloudStep advance_pose_cloud(Actor&,PoseCloudEffects&);
class PoseCloudUpdates final:public PoseWorkUpdates,private PoseCloudEffects {
public:
    PoseCloudUpdates(World&,PoseWorkPool&,gameplay_effects::WorkBackend&,
        gameplay_lighting::TimedLights&,PoseWorkUpdates* remaining=nullptr);
    bool bound_to(const World&)const noexcept override;
    bool update(PoseWorkPool&,const actors::EntityId&,std::uint8_t)override;
private:
    World& world_;PoseWorkPool& pool_;gameplay_effects::WorkBackend& visuals_;
    gameplay_lighting::TimedLights& lights_;PoseWorkUpdates* remaining_;
    bool visual(transform_math::Vector)override;
    bool light(const actors::EntityId&,transform_math::Vector)override;
};
}
