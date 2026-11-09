#pragma once
#include "model_constraints.hpp"
#include "../animation/model_math.hpp"
#include "../gameplay_scenario/resource_templates.hpp"
#include "../gameplay_scenario/scene_resources.hpp"
namespace reo::native::gameplay_world {
struct AttachmentMetadata {
    std::uint8_t kind{};
    std::array<animation::Vector, 2> offsets;
    std::array<transform_math::Angles, 2> angles;
};
class File1AttachmentProfiles final {
  public:
    const AttachmentMetadata& at(std::uint16_t action) const;
};
// The concrete native primary attachment capability retained by SceneResources.
// Construction requires the real resource owner's admitted matrices/position;
// this adapter does not invent a resource or turn absence into an identity pose.
class ResourceModel final : public gameplay_scenario::SceneAttachment {
  public:
    ResourceModel(animation::Matrix adjustment, animation::Matrix initial_pose,
                  animation::Vector initial_position, std::uint32_t initial_flags)
        : correction(adjustment), pose(initial_pose), position(initial_position),
          flags(initial_flags) {}
    void flag(std::uint32_t mask, bool set) noexcept override {
        flags = set ? flags | mask : flags & ~mask;
    }
    animation::Matrix correction, pose;
    animation::Vector position;
    std::uint32_t flags{};
};
class WorldResourceAttachments final {
  public:
    WorldResourceAttachments(World& world, gameplay_scenario::SceneResources& resources,
                             const gameplay_scenario::ResourceTemplates& templates)
        : world_(world), resources_(resources), templates_(templates) {}
    // Complete662DB0. A zero resource ID or known absent attachment/model returns;
    // foreign/stale owners, unknown capability kinds and unadmitted indices refuse.
    void bind(const actors::EntityId&, std::uint32_t resource, std::uint32_t node);

  private:
    World& world_;
    gameplay_scenario::SceneResources& resources_;
    const gameplay_scenario::ResourceTemplates& templates_;
    File1AttachmentProfiles profiles_;
};
// Complete primary3769F0 per-actor order: model update, selected node19, secondary
// node15. The caller still owns outer native frame scheduling.
ModelConstraintReport rebuild_primary_model_with_attachments(
    World&, const actors::EntityId&, const ModelCorrectionScales&,
    const gameplay_collision::response::Grid*, WorldResourceAttachments&);
} // namespace reo::native::gameplay_world
