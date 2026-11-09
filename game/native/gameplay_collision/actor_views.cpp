#include "actor_views.hpp"
#include <cmath>
#include <stdexcept>
namespace reo::native::gameplay_collision::actors {
namespace {
Vec3 add(Vec3 a, Vec3 b) {
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}
Vec3 sub(Vec3 a, Vec3 b) {
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}
Vec3 mul(Vec3 a, float b) {
    return {a.x * b, a.y * b, a.z * b};
}
float dot(Vec3 a, Vec3 b) {
    return (a.x * b.x + a.y * b.y) + a.z * b.z;
}
float length(Vec3 a) {
    return std::sqrt(dot(a, a));
}
View* find(std::span<View> actors, EntityId id) {
    for (auto& actor : actors)
        if (actor.id == id)
            return &actor;
    return nullptr;
}
Vec3 center(const View& actor, const Center& c) {
    if (!c.first_joint && !c.second_joint)
        return Vec3(actor.position);
    const auto point = [&](std::uint16_t index, Vec3 offset) {
        if (index >= actor.joints.size())
            throw std::invalid_argument("Native view collision joint is not in retained pose");
        return actor.joints[index].point(offset);
    };
    if (!c.first_joint)
        return point(*c.second_joint, c.second_offset);
    if (!c.second_joint)
        return point(*c.first_joint, c.first_offset);
    return add(
        mul(add(point(*c.first_joint, c.first_offset), point(*c.second_joint, c.second_offset)),
            0.5f),
        sub(Vec3(actor.position), Vec3(actor.previous)));
}
Vec3 midpoint(const Shape& shape) {
    if (const auto* s = std::get_if<Sphere>(&shape))
        return s->center;
    return std::get<response::Capsule>(shape).midpoint;
}
float bound(const Shape& shape) {
    if (const auto* s = std::get_if<Sphere>(&shape))
        return s->radius;
    return std::get<response::Capsule>(shape).bound_radius;
}
std::optional<Contact> contact(const Shape& current, const Shape& target) {
    if (const auto* first = std::get_if<Sphere>(&current)) {
        if (const auto* second = std::get_if<Sphere>(&target))
            return sphere_contact(*first, *second);
        auto result = response::capsule_sphere(std::get<response::Capsule>(target), *first);
        if (result)
            result->correction = mul(result->correction, -1);
        return result;
    }
    if (const auto* second = std::get_if<Sphere>(&target))
        return response::capsule_sphere(std::get<response::Capsule>(current), *second);
    return response::capsules(std::get<response::Capsule>(target),
                              std::get<response::Capsule>(current));
}
} // namespace
View references(Actor& a) noexcept {
    return {a.id,         a.position,    a.previous, a.candidate_direction, a.joints,
            a.definition, a.actor_class, a.priority, a.separation_count,    a.contact,
            a.peer,       a.room,        a.summary,  a.boundary_clamped};
}
Shape build(const View& actor, const ShapeDefinition& definition, Vec3 accumulated) {
    auto first = center(actor, definition.first);
    first.x += accumulated.x;
    first.z += accumulated.z;
    if (definition.kind == ShapeKind::sphere)
        return Sphere{first, definition.radius};
    auto second = center(actor, definition.second);
    second.x += accumulated.x;
    second.z += accumulated.z;
    return response::make_capsule(first, second, definition.radius);
}
bool ViewRegistry::add(Registration entry) {
    if (!entry.actor || count_ == entries_.size())
        return false;
    entries_[count_++] = std::move(entry);
    return true;
}
SolveReport ViewRegistry::solve(std::span<View> actors, bool limited, bool fast) {
    for (std::size_t i = 0; i < count_; ++i) {
        const auto* actor = find(actors, entries_[i].actor);
        if (!actor)
            throw std::invalid_argument("Stale native collision actor view");
        if (actor->definition && actor->definition->radius > 0)
            (void)build(*actor, *actor->definition);
    }
    for (std::size_t i = 0; i < actors.size(); ++i)
        for (std::size_t j = 0; j < i; ++j)
            if (actors[i].id && actors[i].id == actors[j].id)
                throw std::invalid_argument("Ambiguous native actor view identity");
    std::array<Vec3, 32> accumulated{};
    SolveReport report;
    for (std::size_t i = 0; i < count_; ++i) {
        auto* actor = find(actors, entries_[i].actor);
        if (actor->actor_class == 0)
            actor->contact = false;
    }
    for (std::size_t i = 0; i < count_; ++i) {
        const auto& entry = entries_[i];
        auto& actor = *find(actors, entry.actor);
        if (!actor.definition || actor.definition->radius <= 0)
            continue;
        ++report.visited;
        const auto shape = build(actor, *actor.definition, accumulated[i]);
        actor.summary = summarize(shape);
        if (!entry.source_mask)
            continue;
        std::optional<std::size_t> selected;
        float overlap = 0.0010000000474974513f;
        for (std::size_t j = 0; j < count_; ++j) {
            const auto& other = entries_[j];
            if (!(entry.source_mask & other.collision_class) || other.actor == entry.actor)
                continue;
            auto& target = *find(actors, other.actor);
            if (!target.definition || target.definition->radius <= 0)
                continue;
            ++report.candidates;
            const auto candidate = build(target, *target.definition);
            const auto delta = sub(midpoint(candidate), midpoint(shape));
            auto combined = bound(shape) + target.definition->radius;
            if (const auto* capsule = std::get_if<response::Capsule>(&candidate))
                combined += length(sub(capsule->start, capsule->midpoint));
            const auto penetration = combined - length(delta);
            if (!(penetration > overlap))
                continue;
            if (entry.collision_class == 1 && dot(Vec3(actor.candidate_direction), delta) < 0)
                continue;
            overlap = penetration;
            selected = j;
        }
        if (!selected)
            continue;
        const auto j = *selected;
        auto& target = *find(actors, entries_[j].actor);
        const auto target_shape = build(target, *target.definition, accumulated[j]);
        const auto collision = contact(shape, target_shape);
        if (collision) {
            ++report.contacts;
            if (actor.actor_class == 0) {
                actor.contact = true;
                actor.peer = target.id;
            }
            if (target.actor_class == 0) {
                target.contact = true;
                target.peer = actor.id;
            }
        }
        if (entry.collision_class == 1 || entry.collision_class == 2) {
            if (!collision) {
                actor.separation_count = 0;
                continue;
            }
            Body first{Vec3(actor.position), Vec3(actor.previous), accumulated[i], actor.priority,
                       actor.separation_count},
                second{Vec3(target.position), Vec3(target.previous), accumulated[j],
                       target.priority, target.separation_count};
            (void)separate(first, second, collision->correction, limited, fast);
            actor.position = first.position;
            target.position = second.position;
            accumulated[i] = first.accumulated;
            accumulated[j] = second.accumulated;
            actor.separation_count = first.separation_count;
            target.separation_count = second.separation_count;
        } else if (collision) {
            actor.position.x = actor.previous.x;
            actor.position.z = actor.previous.z;
        }
    }
    clear();
    return report;
}
bool ViewBoundary::set(std::uint8_t kind, EntityId id) noexcept {
    if (kind != 0 || !id)
        return false;
    owner_ = std::move(id);
    return true;
}
void ViewBoundary::apply(std::span<View> actors, bool offline, std::uint16_t room,
                         EntityId selected) const noexcept {
    if (!owner_)
        return;
    const auto* boundary = find(actors, owner_);
    if (!boundary)
        return;
    for (auto& actor : actors) {
        if (offline ? actor.room != room : actor.id != selected)
            continue;
        const auto maximum = boundary->position.z - 200;
        if (actor.position.z > maximum && actor.position.y < -870) {
            actor.position.z = maximum;
            actor.boundary_clamped = true;
        }
    }
}
} // namespace reo::native::gameplay_collision::actors
