#pragma once
#include "resource_pose_work.hpp"
namespace reo::native::gameplay_world {
// Concrete descriptor, following, contact-stop and owner-delay consumers.
// Other reached pose kinds require their concrete consumer via remaining.
class ResourcePoseUpdates final:public PoseWorkUpdates {
public:
    ResourcePoseUpdates(World&,PoseWorkPool&,gameplay_scenario::SceneResources&,
        const gameplay_scenario::ResourceTemplates&,gameplay_collision::delivery::Packets&,
        const gameplay_collision::delivery::Catalog&,PoseWorkUpdates* remaining=nullptr);
    bool bound_to(const World&)const noexcept override;
    bool update(PoseWorkPool&,const actors::EntityId&,std::uint8_t)override;
private:
    World& world_;PoseWorkPool& pool_;gameplay_scenario::SceneResources& resources_;
    const gameplay_scenario::ResourceTemplates& templates_;
    gameplay_collision::delivery::Packets& packets_;const gameplay_collision::delivery::Catalog& catalog_;
    PoseWorkUpdates* remaining_;animation_events::File1Metadata metadata_;
};
}
