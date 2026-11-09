#pragma once
#include "scene_record_attachment.hpp"
namespace reo::native::gameplay_scenario {
struct ResourceFootprint {
    gameplay_collision::Quad bounds;
    std::int32_t lower{},upper{};
};
// Full5927F0 and591860 height arithmetic for the admitted20 owned shape rows.
// Finite native values replace descriptor/stack addresses and register state.
ResourceFootprint resource_footprint(transform_math::Vector,std::uint16_t yaw,std::int8_t profile);
enum class ResourceCollisionStatus {completed,full,invalid_identity,unavailable};
struct ResourceCollisionCreated {
    ResourceCollisionStatus status{ResourceCollisionStatus::unavailable};
    std::shared_ptr<SceneRecordAttachment> attachment;
};
// Concrete591860/5C62F0 consumer. It uses the SAME128 scene records as controls
// and collision queries, with no separate capacity or mirrored mutable record.
class ResourceCollisions final {
public:
    ResourceCollisions(SceneResources&,std::shared_ptr<gameplay_scene::Records>);
    ResourceCollisionCreated replace(const SceneResourceId&)noexcept;
private:
    SceneResources& resources_;
    std::shared_ptr<gameplay_scene::Records> records_;
};
}
