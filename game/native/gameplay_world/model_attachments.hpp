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
    std::array<animation::Matrix,6> parts{};
    ResourceModel(animation::Matrix adjustment, animation::Matrix initial_pose,
                  animation::Vector initial_position, std::uint32_t initial_flags)
        : correction(parts[5]), pose(initial_pose), position(initial_position),
          flags(initial_flags) {correction=adjustment;}
    ResourceModel(const ResourceModel&)=delete;
    ResourceModel& operator=(const ResourceModel&)=delete;
    bool current()const noexcept{return !retired_;}
    void flag(std::uint32_t mask, bool set) noexcept override {
        flags = set ? flags | mask : flags & ~mask;
    }
    //662DB0's correction is the very same matrix as weapon part5 (source180).
    // Keep the named view without a second mutable pose or guest-memory alias.
    animation::Matrix& correction;
    animation::Matrix pose;
    animation::Vector position;
    std::uint32_t flags{};
    animation::WeaponProgramState program;
    bool active{},visible{};
    std::uint8_t category{}; // original renderer category2
    std::uint16_t draw_tag{}; // original238; semantic render consumer remains separate
    std::uint8_t physical_slot{},resource_slot{},draw_layer{};
    std::int16_t asset_index{};
    std::array<std::uint8_t,6> part_enabled{};
    std::array<std::uint16_t,3> angles{};
    std::uint16_t content_id{}; // original resource model36, not asset_index242
    std::uint8_t pulse_phase{};
    std::int16_t pulse_timer{},pulse_packed{};
    float pulse_distance{};
    animation::Vector axis_scale{}; // source22C, independent of the position at200
    animation::Vector use_vector{}; // source20C; copied use payload, distinct from position200
    std::array<std::int16_t,4> use_parameters{}; // source224; distinct from orientation21C
    std::int16_t use_delay{}; // sourceC; cleared by use configuration
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
    bool bound_to(const World& world)const noexcept{return &world_==&world&&!world_.closed();}
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
