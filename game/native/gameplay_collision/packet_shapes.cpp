#include "packet_shapes.hpp"
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
Vec3 scale(Vec3 a, float f) {
    return {a.x * f, a.y * f, a.z * f};
}
float length(Vec3 a) {
    return std::sqrt((a.x * a.x + a.y * a.y) + a.z * a.z);
}
bool admitted(trace::SamplingStatus status) {
    return status != trace::SamplingStatus::capacity &&
           status != trace::SamplingStatus::nonprogress;
}
response::Filter filter(ShapeScene scene, std::uint32_t include, std::uint32_t exclude) {
    auto result = scene.filter;
    result.include = include;
    result.exclude = exclude;
    result.dynamic_kind_gate = false;
    return result;
}
struct RouteResult {
    Status status{Status::completed};
    std::optional<EdgeRoute> route;
};
RouteResult route_for(const trace::Hit& hit, const Template& response, RouteChannels& channels,
                      bool sweep_primary = false) {
    if ((!sweep_primary && !(hit.type & 0x4002)) || (response.query_flags & 8))
        return {};
    const auto edge = std::uint8_t((hit.type >> 24) & 15);
    if (hit.type & 2) {
        const auto state = channels.channel(edge);
        if (!state)
            return {Status::unadmitted_content, {}};
        if (!state->gate)
            return {Status::completed, EdgeRoute{1, edge}};
        return {};
    }
    return {Status::completed, EdgeRoute{2, std::uint8_t(edge + 16)}};
}
Status radius_status(radius::Status status) {
    if (status == radius::Status::complete)
        return Status::completed;
    return status == radius::Status::uninitialized_point ? Status::uninitialized_output_point
                                                         : Status::unadmitted_content;
}
ShapeResult sweep_query(PacketState& packet, PacketOwner owner, const SweepShape& shape,
                        ShapePose pose, ShapeScene scene, Context& context,
                        hit_regions::Queue& targets, PacketShapeEffects& effects) {
    const auto transformed =
        shape_geometry::transform(shape.center, {}, shape.joint, pose, owner.contact.position);
    if (!transformed)
        return {Status::unadmitted_content, false, {}};
    const auto end = transformed->origin;
    Vec3 start;
    if (!packet.previous_valid) {
        packet.previous_valid = 1;
        start = end;
    } else
        start = packet.previous;
    packet.previous = end;
    Query query;
    query.mode = Mode::margin;
    query.start = start;
    query.end = end;
    query.margin = float(shape.radius);
    query.mask = packet.mask;
    std::optional<Vec3> point;
    const auto scanned = scan(targets.entries(), packet.delivery, query, context, point);
    if (scanned.status != Status::completed)
        return {scanned.status, false, {}};
    ShapeResult result;
    if (scanned.region_hits) {
        result.contact = true;
        packet.delivery.event = 0;
        ++packet.contacts;
        return result;
    }
    std::optional<trace::Hit> wall, floor;
    if (packet.mask & 16) {
        if (!(packet.delivery.response.query_flags & 8)) {
            const auto hit = radius::query(scene.walls, start, end, float(shape.radius),
                                           filter(scene, 0x24002, 0), scene.dynamic);
            if (const auto status = radius_status(hit.status); status != Status::completed)
                return {status, false, {}};
            if (hit.hit) {
                wall = hit.hit;
                packet.impact = hit.hit->point;
                packet.delivery.event = 1;
                result.contact = true;
                const auto routed =
                    route_for(*hit.hit, packet.delivery.response, scene.channels, true);
                if (routed.status != Status::completed)
                    return {routed.status, true, {}};
                result.route = routed.route;
            }
        }
        if (!wall) {
            const auto hit = radius::query(scene.walls, start, end, float(shape.radius),
                                           filter(scene, 0x2ffff, 0x4002), scene.dynamic);
            if (const auto status = radius_status(hit.status); status != Status::completed)
                return {status, result.contact, result.route};
            if (hit.hit) {
                wall = hit.hit;
                packet.impact = hit.hit->point;
                packet.delivery.event = 1;
                result.contact = true;
            }
        }
        if (wall && owner.contact.actor.category == 9) {
            pose.projectile_point = packet.impact;
            pose.projectile_normal = wall->normal;
        }
    }
    if (!packet.delivery.event) {
        const auto ground = trace::floor(scene.floors, start, end);
        if (!admitted(ground.status))
            return {Status::unadmitted_content, result.contact, result.route};
        if (ground.hit) {
            floor = ground.hit;
            packet.delivery.event = 2;
            result.contact = true;
            result.route.reset();
            if (owner.contact.actor.category == 9 && std::uint8_t(ground.hit->type) == 0x81)
                pose.surface_valid = true;
        }
    }
    if (packet.delivery.event &&
        !(packet.delivery.response.query_flags & (1u << packet.delivery.event))) {
        const auto status =
            effects.scene_contact(packet.delivery, owner, packet.impact, wall, floor);
        if (status != Status::completed)
            return {status, result.contact, result.route};
    }
    if (result.contact)
        ++packet.contacts;
    return result;
}
} // namespace
namespace shape_geometry {
void clip_endpoint(Vec3 start, Vec3& end) noexcept {
    if (!(end.x < 0) && !(end.z < 0))
        return;
    float factor = 0;
    if (end.x < 0) {
        const auto delta = start.x - end.x;
        if (delta != 0)
            factor = std::abs(end.x / delta);
    }
    if (end.z < 0) {
        const auto delta = start.z - end.z;
        if (delta != 0) {
            const auto candidate = std::abs(end.z / delta);
            if (factor < candidate)
                factor = candidate;
        }
    }
    end.x = end.x + factor * (start.x - end.x);
    end.y = end.y + factor * (start.y - end.y);
    end.z = end.z + factor * (start.z - end.z);
    if (end.x < 0)
        end.x = 0;
    if (end.z < 0)
        end.z = 0;
}
std::optional<Transformed> transform(Vec3 origin, Vec3 direction,
                                     std::optional<std::uint16_t> joint, ShapePose pose,
                                     postmove::VectorRef position) noexcept {
    if (joint) {
        if (*joint >= pose.joints.size())
            return {};
        const auto& basis = pose.joints[*joint];
        return Transformed{basis.point(origin), basis.direction(direction)};
    }
    return Transformed{add(pose.root.direction(origin), Vec3(position)),
                       pose.root.direction(direction)};
}
} // namespace shape_geometry
ShapePipeline::ShapePipeline(Context& context, hit_regions::Queue& targets, PacketPoses& poses,
                             PacketScenes& scenes, PacketShapeEffects& effects)
    : context_(context), targets_(targets), poses_(poses), scenes_(scenes), effects_(effects) {}
ShapeResult ShapePipeline::query(PacketState& packet, PacketOwner owner) {
    if (!packet.definition)
        return {Status::unadmitted_content, false, {}};
    // The sweep's class2/primary3 early return precedes pose/cache mutations.
    const bool sweep = std::holds_alternative<SweepShape>(packet.definition->geometry);
    if (sweep && owner.contact.actor.category == 2 && owner.contact.actor.primary == 3)
        return {};
    auto pose = poses_.pose(owner);
    if (!pose)
        return {Status::unadmitted_content, false, {}};
    const auto scene = scenes_.scene(owner);
    if (!scene)
        return {Status::unadmitted_content, false, {}};
    if (sweep)
        return sweep_query(packet, owner, std::get<SweepShape>(packet.definition->geometry), *pose,
                           *scene, context_, targets_, effects_);
    const auto* segment = std::get_if<SegmentShape>(&packet.definition->geometry);
    const auto* margin = std::get_if<MarginShape>(&packet.definition->geometry);
    const auto* angular = std::get_if<AngularShape>(&packet.definition->geometry);
    if (!segment && !margin && !angular)
        return {Status::unadmitted_content, false, {}};
    const auto transformed =
        segment  ? shape_geometry::transform(segment->origin, segment->direction, segment->joint,
                                             *pose, owner.contact.position)
        : margin ? shape_geometry::transform(margin->origin, margin->direction, margin->joint,
                                             *pose, owner.contact.position)
                 : shape_geometry::transform(angular->origin, angular->direction, angular->joint,
                                             *pose, owner.contact.position);
    if (!transformed)
        return {Status::unadmitted_content, false, {}};
    const auto start = transformed->origin;
    const auto direction = transformed->direction;
    const auto range = float(segment ? segment->range : margin ? margin->range : angular->range);
    auto end = add(start, scale(direction, range));
    if (!angular)
        shape_geometry::clip_endpoint(start, end);
    auto distance_end = end;
    ShapeResult result;
    std::optional<trace::Hit> wall, floor;
    if (packet.mask & 16) {
        const auto hit =
            trace::shorten(scene->walls, start, end, filter(*scene, 0x2ffff, 0), scene->dynamic);
        if (!admitted(hit.status))
            return {Status::unadmitted_content, false, {}};
        if (hit.hit) {
            wall = hit.hit;
            packet.impact = hit.hit->point;
            end = packet.impact;
            packet.delivery.event = 1;
            result.contact = true;
            const auto routed = route_for(*hit.hit, packet.delivery.response, scene->channels);
            if (routed.status != Status::completed)
                return {routed.status, true, {}};
            result.route = routed.route;
        }
    }
    // Angular keeps a separate distance endpoint, but queries the floor along
    // the same wall-shortened scene segment. Only a floor hit replaces it.
    const auto ground = trace::floor(scene->floors, start, end);
    if (!admitted(ground.status))
        return {Status::unadmitted_content, result.contact, result.route};
    if (ground.hit) {
        floor = ground.hit;
        if (angular)
            distance_end = ground.hit->point;
        else
            end = ground.hit->point;
        packet.delivery.event = 2;
        result.contact = true;
        result.route.reset();
        if (owner.contact.actor.category == 9 && std::uint8_t(ground.hit->type) == 0x81)
            pose->surface_valid = true;
    }
    Query query;
    query.start = start;
    query.end = end;
    query.direction = direction;
    query.mask = packet.mask;
    if (angular) {
        query.mode = Mode::angular;
        const auto adjusted = ground.hit ? length(sub(distance_end, start)) : range;
        float extent = float(angular->extent);
        if (ground.hit) {
            const auto ratio = range == 0 ? std::numeric_limits<float>::max() : adjusted / range;
            extent = extent * ratio;
        }
        query.extents = {adjusted, extent};
    } else {
        query.mode = Mode::segment;
        query.margin = margin ? float(margin->margin) : 0;
    }
    std::optional<Vec3> output;
    const auto scanned = scan(targets_.entries(), packet.delivery, query, context_, output);
    if (scanned.status != Status::completed)
        return {scanned.status, result.contact, result.route};
    if (scanned.region_hits) {
        packet.delivery.event = 0;
        result.contact = true;
        result.route.reset();
    } else if (packet.delivery.event &&
               !(packet.delivery.response.query_flags & (1u << packet.delivery.event))) {
        const auto status =
            effects_.scene_contact(packet.delivery, owner, packet.impact, wall, floor);
        if (status != Status::completed)
            return {status, result.contact, result.route};
    }
    if (segment && effects_.debug_enabled()) {
        if (scanned.region_hits && !output)
            return {Status::uninitialized_output_point, result.contact, result.route};
        const auto status = effects_.debug_line(start, scanned.region_hits ? *output : end);
        if (status != Status::completed)
            return {status, result.contact, result.route};
    }
    if (result.contact)
        ++packet.contacts;
    return result;
}
} // namespace reo::native::gameplay_collision::delivery
