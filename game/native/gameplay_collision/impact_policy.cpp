#include "impact_policy.hpp"
#include <cmath>
#include <limits>
namespace reo::native::gameplay_collision::delivery {
namespace {
Vec3 add(Vec3 a, Vec3 b) {
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}
Vec3 sub(Vec3 a, Vec3 b) {
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}
Vec3 normalize(Vec3 v) {
    const float x = v.x * v.x, y = v.y * v.y, z = v.z * v.z;
    const float xy = x + y, squared = xy + z;
    const float reciprocal =
        squared > 0 ? 1.0f / std::sqrt(squared) : std::numeric_limits<float>::max();
    return {v.x * reciprocal, v.y * reciprocal, v.z * reciprocal};
}
Vec3 cross(Vec3 a, Vec3 b) {
    return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}
transform_math::Matrix basis(Vec3 forward, Vec3 auxiliary, bool transpose) {
    auxiliary = normalize(auxiliary);
    forward = normalize(forward);
    const auto right = normalize(cross(auxiliary, forward)), up = cross(forward, right);
    transform_math::Matrix result{};
    if (transpose) {
        result[0] = {right.x, up.x, forward.x, 0};
        result[1] = {right.y, up.y, forward.y, 0};
        result[2] = {right.z, up.z, forward.z, 0};
    } else {
        result[0] = {right.x, right.y, right.z, 0};
        result[1] = {up.x, up.y, up.z, 0};
        result[2] = {forward.x, forward.y, forward.z, 0};
    }
    result[3] = {0, 0, 0, 1};
    return result;
}
} // namespace
Status emit_contact_impact(const Packet& packet, Vec3& impact, Actors& actors,
                           ImpactVisuals& visuals, const std::optional<trace::Hit>& wall,
                           const std::optional<trace::Hit>& floor) {
    if (!packet.cached_related)
        return Status::completed;
    auto owner = actors.find(packet.cached_related);
    if (!owner)
        return Status::missing_actor;
    if (owner->actor.category != 0)
        return Status::completed;
    if (packet.event == 1) {
        if (!wall)
            return Status::uninitialized_output_point;
        const auto matrix = basis(wall->normal, {0, 1, 0}, false);
        return visuals.oriented(matrix, impact, packet.key);
    }
    if (packet.event == 2) {
        if (!floor)
            return Status::uninitialized_output_point;
        // Preserve original FP32 sum-then-difference cancellation. Substituting
        // the normal directly changes large-coordinate source results.
        const auto eye = add(floor->point, floor->normal);
        const auto matrix = basis(sub(eye, floor->point), {0, 0, 1}, true);
        auto point = floor->point;
        if ((std::uint8_t(floor->type) & 0x81) == 0x81) {
            point.y = point.y + 1.0f;
            return visuals.surface(*owner, std::nullopt, point, packet.key);
        }
        return visuals.oriented(matrix, point, packet.key);
    }
    return Status::completed;
}
} // namespace reo::native::gameplay_collision::delivery
