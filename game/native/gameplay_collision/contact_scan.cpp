#include "contact_scan.hpp"
#include <bit>
#include <cmath>
#include <limits>
namespace reo::native::gameplay_collision::delivery {
namespace {
Vec3 sub(Vec3 a, Vec3 b) {
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}
float length(Vec3 v) {
    return std::sqrt((v.x * v.x + v.y * v.y) + v.z * v.z);
}
Vec3 normalized(Vec3 v) {
    const auto n = length(v);
    const float s = n > 0 ? 1 / n : std::numeric_limits<float>::max();
    return {v.x * s, v.y * s, v.z * s};
}
std::int32_t add(std::int32_t a, std::int32_t b) {
    return std::bit_cast<std::int32_t>(std::uint32_t(a) + std::uint32_t(b));
}
void clamp(gameplay_actors::HitActor& actor) {
    float value = float(actor.damage_word);
    if (value < -32768)
        value = -32768;
    else if (!(value <= 32767))
        value = 32767;
    actor.damage_word = std::int32_t(value);
}
struct Applied {
    Status status{Status::completed};
    bool overwritten{};
};
Applied apply(View target, View clamp_target, const Packet& packet, const spatial::Contact& hit,
              const Query& query, bool per_actor, float& retained_multiplier, Context& context,
              std::optional<Vec3>& output_point) {
    ++target.actor.pending_hit;
    auto source = context.actors.find(packet.source);
    if (!source)
        return {Status::missing_actor};
    auto resolved = source->actor.category == 9
                        ? (source->contact.related ? context.actors.find(source->contact.related)
                                                   : std::optional<View>{})
                        : source;
    const auto pair = pair_kind(resolved ? &resolved->actor : nullptr, target.actor);
    std::uint8_t kind{};
    if (pair == 0 || pair == 2) {
        retained_multiplier =
            multiplier(*resolved, packet, context.tables, context.random, context.effects);
        const auto result = pair == 0 ? category_value(target, *resolved, packet.response,
                                                       retained_multiplier, context.tables)
                                      : flat_value(target, *resolved, packet.response,
                                                   retained_multiplier, context.tables);
        if (result.status != Status::completed)
            return {result.status};
        target.actor.damage_word = add(target.actor.damage_word, result.value.amount);
        kind = result.value.kind;
    } else if (pair == 1 || pair == 3) {
        const auto row = context.tables.random.find(packet.response.base);
        if (row == context.tables.random.end())
            return {Status::unadmitted_content};
        const auto first = context.random.request(1) & 7;
        target.actor.damage_word =
            add(target.actor.damage_word, row->second.damage[context.difficulty & 3][first]);
        const auto second = context.random.request(1) & 7;
        target.actor.progression_amount =
            std::uint16_t(target.actor.progression_amount +
                          row->second.progression[context.difficulty & 3][second]);
        kind = packet.response.kind;
    } else {
        target.actor.damage_word = add(target.actor.damage_word, packet.response.base);
        target.actor.progression_amount =
            std::uint16_t(target.actor.progression_amount + packet.response.progression);
        kind = packet.response.kind;
    }
    // The original global path clamps the last scanned actor, including one
    // that did not produce the selected hit. This is not normalized to target.
    clamp(clamp_target.actor);
    const auto& t = packet.response;
    if (!(target.contact.priority < t.priority))
        return {};
    target.contact.priority = t.priority;
    target.contact.template_kind = t.value_id;
    target.actor.response_flags = t.response_flags;
    roll_response(target, t, context.random);
    target.actor.damage_kind = t.damage_kind;
    target.actor.response_class = kind;
    target.contact.response_code = t.response_code;
    target.contact.auxiliary_a = t.auxiliary_a;
    target.contact.auxiliary_b = t.auxiliary_b;
    const auto point = hit.point.value;
    if (query.mode == Mode::margin && per_actor)
        target.contact.direction = normalized(sub(query.start, hit.region_center));
    if (query.mode != Mode::segment || !per_actor) {
        target.contact.recorded_source = packet.source;
        target.contact.recorded_related = packet.cached_related;
    }
    const auto provenance = record_provenance(target, packet, context.actors);
    if (provenance != Status::completed)
        return {provenance, true};
    target.contact.point = point;
    if (query.mode == Mode::segment) {
        output_point = point;
        target.contact.direction = normalized(sub(query.end, query.start));
    } else if (!per_actor) {
        // Source S3 points one past the last admitted actor's region array.
        // Preserve all known earlier writes, then refuse the unknown read.
        if (context.direction_policy == DirectionPolicy::require_known_tail)
            return {Status::unknown_advanced_direction, true};
        target.contact.direction = normalized(sub(query.start, hit.region_center));
    } else if (query.mode == Mode::angular)
        target.contact.direction = normalized(sub(query.start, hit.region_center));
    target.contact.region = hit.region;
    if (!(retained_multiplier <= 1))
        convert_response(target);
    return {Status::completed, true};
}
} // namespace
ScanReport scan(std::span<const actors::EntityId> recipients, const Packet& packet, Query query,
                Context& context, std::optional<Vec3>& output_point) {
    ScanReport result;
    if (recipients.size() > 64) {
        result.status = Status::invalid_roster;
        return result;
    }
    auto source = context.actors.find(packet.source);
    if (!source) {
        result.status = Status::missing_actor;
        return result;
    }
    const bool per_actor = (packet.response.flags & 1) != 0;
    const bool occlusion = query.mode != Mode::margin && (packet.response.query_flags & 0x20) != 0;
    if (occlusion && !context.obstacles) {
        result.status = Status::unadmitted_content;
        return result;
    }
    const spatial::Policy policy{query.mask, context.special_mode, per_actor, occlusion,
                                 context.class_masks};
    std::optional<spatial::Contact> selected;
    float selected_distance{}, retained_multiplier = 1;
    for (const auto& id : recipients) {
        auto actor = context.actors.find(id);
        if (!actor) {
            result.status = Status::missing_actor;
            return result;
        }
        result.last_scanned = id;
        if (id == source->id || id == source->contact.related)
            continue;
        spatial::Target target;
        target.entity = id;
        target.identity = {actor->actor.category, identity(*actor).token};
        target.movement_flags = actor->actor.status;
        spatial::Status admission{};
        if (!spatial::admits(target, policy, admission)) {
            if (admission != spatial::Status::complete) {
                result.status = Status::unadmitted_content;
                return result;
            }
            continue;
        }
        result.advanced_direction_owner = id;
        std::optional<spatial::Contact> actor_hit;
        float actor_distance{};
        const auto regions = actor->contact.regions.spheres();
        for (std::size_t i = 0; i < regions.size(); ++i) {
            const auto& region = regions[i];
            if (occlusion && context.obstacles->blocked(query.start, region.center))
                continue;
            std::optional<spatial::Point> point;
            if (query.mode == Mode::angular)
                point = directed::contact(region, query.start, query.direction, query.extents);
            else if (query.mode == Mode::margin)
                point = query.start.x == query.end.x && query.start.y == query.end.y &&
                                query.start.z == query.end.z
                            ? spatial::overlap(region, query.end, query.margin)
                            : spatial::sphere_margin(query.start, query.end, region, query.margin);
            else
                point = query.margin <= 0
                            ? spatial::sphere_segment(query.start, query.end, region)
                            : spatial::sphere_margin(query.start, query.end, region, query.margin);
            if (!point)
                continue;
            ++result.region_hits;
            spatial::Contact hit{id, target.identity, std::uint8_t(i), *point, region.center};
            const auto distance = length(sub(query.start, point->value));
            if (per_actor) {
                if (!actor_hit || distance < actor_distance) {
                    actor_hit = hit;
                    actor_distance = distance;
                }
                if (query.mode != Mode::segment)
                    break;
            } else if (!selected || distance < selected_distance) {
                selected = hit;
                selected_distance = distance;
            }
        }
        if (actor_hit) {
            result.selected = id;
            const auto applied = apply(*actor, *actor, packet, *actor_hit, query, true,
                                       retained_multiplier, context, output_point);
            ++result.deliveries;
            result.priority_overwrites += applied.overwritten;
            if (applied.status != Status::completed) {
                result.status = applied.status;
                return result;
            }
        }
    }
    if (selected) {
        auto actor = context.actors.find(selected->target),
             last = context.actors.find(result.last_scanned);
        if (!actor || !last) {
            result.status = Status::missing_actor;
            return result;
        }
        result.selected = selected->target;
        const auto applied = apply(*actor, *last, packet, *selected, query, false,
                                   retained_multiplier, context, output_point);
        ++result.deliveries;
        result.priority_overwrites += applied.overwritten;
        if (applied.status != Status::completed) {
            result.status = applied.status;
            return result;
        }
    }
    if (query.mode == Mode::segment && result.region_hits && query.margin > 0 &&
        !(packet.response.query_flags & 1) && result.selected) {
        auto actor = context.actors.find(result.selected);
        if (!actor) {
            result.status = Status::missing_actor;
            return result;
        }
        const bool exempt =
            (actor->actor.category == 0 && (actor->actor.status & 8)) ||
            (actor->actor.category == 2 && context.effects.class_two_mark_exempt(*actor));
        if (!exempt) {
            if (!output_point) {
                result.status = Status::uninitialized_output_point;
                return result;
            }
            auto direction = sub(query.end, query.start);
            if (direction.x == 0 && direction.y == 0 && direction.z == 0)
                direction = {1, 0, 0};
            else
                direction = normalized(direction);
            context.effects.surface_mark(*output_point, direction);
        }
    }
    return result;
}
} // namespace reo::native::gameplay_collision::delivery
