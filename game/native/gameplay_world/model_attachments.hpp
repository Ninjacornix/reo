#pragma once
#include "model_constraints.hpp"
#include "../animation/model_math.hpp"
#include "../animation/weapon_program.hpp"
#include "../gameplay_scenario/resource_templates.hpp"
#include "../gameplay_scenario/scene_resources.hpp"
namespace reo::native::gameplay_world {
class ResourceModels;
class ResourceModelWork;
struct ResourcePartPoses {
    std::int16_t asset_index{};
    std::uint16_t count{};
    std::array<animation::Matrix,6> poses;
};
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
class ResourceModel final : public gameplay_scenario::SceneFlagAttachment {
  public:
    ResourceModel(animation::Matrix adjustment, animation::Matrix initial_pose,
                  animation::Vector initial_position, std::uint32_t initial_flags)
        : correction(adjustment), pose(initial_pose), position(initial_position),
          flags(initial_flags) {}
    ResourceModel(const ResourceModel&)=delete;
    ResourceModel& operator=(const ResourceModel&)=delete;
    bool current()const noexcept{return !retired_;}
    void flag(std::uint32_t mask, bool set) noexcept override {
        flags = set ? flags | mask : flags & ~mask;
    }
    animation::Matrix correction, pose;
    animation::Vector position;
    std::uint32_t flags{};
    animation::WeaponProgramState program;
    bool active{},visible{};
    std::uint8_t physical_slot{},resource_slot{},draw_layer{};
    std::int16_t asset_index{};
    std::array<std::uint8_t,6> part_enabled{};
    std::array<animation::Matrix,6> parts{};
    std::array<std::uint16_t,3> angles{};
    std::uint16_t content_id{}; // original resource model36, not asset_index242
    std::uint8_t pulse_phase{};
    std::int16_t pulse_timer{},pulse_packed{};
    float pulse_distance{};
    animation::Vector axis_scale{}; // source22C, independent of the position at200
    std::shared_ptr<const ResourcePartPoses> base_parts;
    std::shared_ptr<ResourceModelWork> work;
  private:
    bool retired_{};
    void retire_data()noexcept;
    friend class ResourceModels;
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
