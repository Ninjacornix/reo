#include "model_attachments.hpp"
#include "../animation/constraint_math.hpp"
#include <bit>
#include <cmath>
#include <limits>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
#include "attachment_profile.inc"
float finite(float v) {
    if (!std::isfinite(v))
        throw std::domain_error("Native resource attachment finite arithmetic required");
    return v;
}
void normalize(animation::Matrix& pose, unsigned column) {
    const auto& c = pose[column];
    const auto squared = animation::constraint_math::squared_length({c[0], c[1], c[2]});
    const float factor =
        squared > 0 ? finite(1.f / std::sqrt(squared)) : std::numeric_limits<float>::max();
    for (unsigned i = 0; i < 3; ++i)
        pose[column][i] = finite(pose[column][i] * factor);
}
animation::Matrix rotation(animation::Vector radians) {
    animation::Parameters p{};
    p[3] = radians.x;
    p[4] = radians.y;
    p[5] = radians.z;
    return animation::unscaled_pose(p);
}
animation::Vector translation(const animation::Matrix& m) {
    return {m[3][0], m[3][1], m[3][2]};
}
} // namespace
const AttachmentMetadata& File1AttachmentProfiles::at(std::uint16_t action) const {
    if (action >= action_metadata.size())
        throw std::out_of_range("Native attachment action metadata unavailable");
    return action_metadata[action];
}
void WorldResourceAttachments::bind(const actors::EntityId& id, std::uint32_t full_resource,
                                    std::uint32_t node) {
    const auto resource = std::uint8_t(full_resource);
    if (!resource)
        return;
    const auto descriptor_id = resources_.slot(resource);
    const auto descriptor = resources_.get(*descriptor_id);
    if (!descriptor || !descriptor->primary)
        return;
    const auto target = std::dynamic_pointer_cast<ResourceModel>(descriptor->primary);
    if (!target)
        throw std::runtime_error("Native resource attachment capability kind unavailable");
    if(!target->current())throw std::runtime_error("Native resource attachment retired");
    const auto actor = world_.resolve(id);
    if (!actor)
        throw std::runtime_error("Native attachment actor foreign or retired");
    if (!actor->model)
        return;
    const auto model = actor->model;
    const auto publication = model->retain();
    if (!publication)
        throw std::runtime_error(
            "Native attachment requires a completed canonical joint publication");
    if (node >= publication->joints.size())
        throw std::out_of_range("Native attachment model node unavailable");
    target->pose = publication->joints[node];
    for (unsigned c = 0; c < 3; ++c)
        normalize(target->pose, c);
    const auto action = descriptor->active && descriptor->template_index != 255
                            ? templates_.action_kind(descriptor->template_index)
                            : 0;
    const auto& metadata = profiles_.at(std::uint16_t(std::int16_t(action)));
    if (actor->motion_style >= 2)
        throw std::out_of_range("Native attachment style outside qualified profile");
    auto offset = metadata.offsets[actor->motion_style];
    offset.x = finite(offset.x * actor->model_scale.x);
    offset.y = finite(offset.y * actor->model_scale.y);
    offset.z = finite(offset.z * actor->model_scale.z);
    if (node == 15)
        offset.x = finite(offset.x * -1.f);
    animation::Matrix adjustment;
    if (actor->motion_class == 128 && profiles_.at(actor->resource_action).kind == 12) {
        if (actor->secondary == 0 || actor->secondary == 7) {
            target->pose = animation::constraint_math::product(target->pose, target->correction);
            target->position = translation(target->pose);
            return;
        }
        adjustment = rotation({std::bit_cast<float>(0xbe61c776u), std::bit_cast<float>(0xbf688332u),
                               std::bit_cast<float>(0x3e5792fbu)});
        adjustment[3][0] = std::bit_cast<float>(0xc0c7df3bu);
        adjustment[3][1] = std::bit_cast<float>(0xc0dcdd2fu);
        adjustment[3][2] = std::bit_cast<float>(0x40c2c083u);
    } else {
        const auto angles = metadata.angles[actor->motion_style];
        const auto angle = [](std::uint16_t v) {
            return finite(finite(std::bit_cast<float>(0x40c90fdbu) * float(v)) / 65536.f);
        };
        adjustment = rotation({angle(angles[0]), angle(angles[1]), angle(angles[2])});
        adjustment[3][0] = offset.x;
        adjustment[3][1] = offset.y;
        adjustment[3][2] = offset.z;
    }
    if (node == 15)
        for (unsigned c = 0; c < 3; ++c)
            adjustment[c][0] = finite(adjustment[c][0] * -1.f);
    target->pose = animation::constraint_math::product(target->pose, adjustment);
    target->position = translation(target->pose);
}
ModelConstraintReport rebuild_primary_model_with_attachments(
    World& world, const actors::EntityId& id, const ModelCorrectionScales& scales,
    const gameplay_collision::response::Grid* floors, WorldResourceAttachments& attachments) {
    const auto actor = world.resolve(id);
    if (!actor)
        throw std::runtime_error("Native primary model actor foreign or retired");
    const auto report =
        rebuild_model_constraints(world, *actor, ModelPoseKind::primary, scales, floors);
    if (!actor->active)
        return report;
    if (world.resolve(id) != actor)
        throw std::runtime_error("Native primary model owner retired during model services");
    attachments.bind(id, actor->selected_resource, 19);
    attachments.bind(id, actor->secondary_resource, 15);
    return report;
}
} // namespace reo::native::gameplay_world
