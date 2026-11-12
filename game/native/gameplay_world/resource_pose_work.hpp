#pragma once
#include "pose_work_pool.hpp"
#include "resource_models.hpp"
#include "animation_events.hpp"
#include "../gameplay_scenario/resource_templates.hpp"
#include "../gameplay_collision/contact_packets.hpp"
namespace reo::native::gameplay_world {
struct ResourcePoseCreated {
    PoseWorkStatus status{PoseWorkStatus::unavailable};
    actors::EntityId work;
    gameplay_collision::delivery::PacketId packet;
};
// Complete5823E0 constructor. Borrowed owners are canonical and outlive calls;
// contact packet exhaustion does not roll back its already allocated work.
class ResourcePoseWork final {
public:
    ResourcePoseWork(World&,PoseWorkPool&,gameplay_scenario::SceneResources&,
        const gameplay_scenario::ResourceTemplates&,gameplay_collision::delivery::Packets&,
        const gameplay_collision::delivery::Catalog&);
    bool bound_to(const World&)const noexcept;
    ResourcePoseCreated create(const actors::EntityId&,const transform_math::Matrix&,
        transform_math::Vector,std::uint32_t resource);
    // Complete5822A0: nullable position/basis preserve the allocated zero record.
    // Descriptor and kind narrow separately. Unsupported bank domains refuse
    // after the constructor prefix rather than wrapping a live bank identity.
    ResourcePoseCreated attach(const actors::EntityId&,std::uint32_t descriptor,
        std::uint32_t kind,std::uint32_t bank,const transform_math::Matrix*,
        const transform_math::Vector*,std::int32_t lifetime);
private:
    World& world_;PoseWorkPool& pool_;gameplay_scenario::SceneResources& resources_;
    const gameplay_scenario::ResourceTemplates& templates_;
    gameplay_collision::delivery::Packets& packets_;
    const gameplay_collision::delivery::Catalog& catalog_;
    animation_events::File1Metadata metadata_;
};
}
