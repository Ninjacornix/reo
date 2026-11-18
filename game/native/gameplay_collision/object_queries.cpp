#include "object_queries.hpp"
#include <bit>
#include <cmath>
namespace reo::native::gameplay_collision::object_queries {
namespace {
std::int8_t narrow(int n) {
    return std::bit_cast<std::int8_t>(std::uint8_t(n));
}
std::optional<int> integer(float n) {
    if (!std::isfinite(n) || double(n) < -2147483648.0 || double(n) >= 2147483648.0)
        return {};
    return int(std::trunc(n));
}
std::optional<std::int8_t> band(float y, float origin) {
    const auto n = integer((y - origin) + 1.0f);
    return n ? std::optional<std::int8_t>(narrow(*n / 50)) : std::nullopt;
}
Predicate clear(const objects::Grid::Mask& mask, int x, int z) {
    if (x < 0 || z < 0 || x >= 96 || z >= 96)
        return {false, Status::mask_bounds};
    return {(mask[std::size_t(x) * 3 + unsigned(z) / 32] & (1u << (unsigned(z) & 31))) == 0};
}
Vec3 add(Vec3 a, Vec3 b) {
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}
} // namespace
Predicate padded_direction(const objects::Owner& owner, objects::ObjectId id,
                           std::uint8_t direction) {
    const auto* o = owner.get(id);
    if (!o)
        return {};
    const auto* grid = owner.grid();
    if (!grid)
        return {false, Status::missing_grid};
    if (o->x < 0 || o->z < 0 || o->x >= grid->width || o->z >= grid->depth)
        return {};
    const auto depth = direction == 2 || direction == 8;
    const auto count = depth ? o->depth : o->width;
    if (direction != 1 && direction != 2 && direction != 4 && direction != 8)
        return {};
    for (int i = 0; i < count; ++i) {
        int x = o->x, z = o->z, owner_x = x, owner_z = z;
        if (direction == 2) {
            x += o->width + 1;
            z += i + 1;
            owner_x += o->width;
            owner_z += i;
        } else if (direction == 1) {
            x += i + 1;
            z += o->depth + 1;
            owner_x += i;
            owner_z += o->depth;
        } else if (direction == 8) {
            z += i + 1;
            --owner_x;
            owner_z += i;
        } else {
            x += i + 1;
            owner_x += i;
            --owner_z;
        }
        const auto admitted = clear(grid->padded, x, z);
        if (!admitted.value)
            return admitted;
        if (owner.at_cell(narrow(owner_x), narrow(owner_z)))
            return {};
    }
    return {true};
}
Predicate leading_edge(const objects::Owner& owner, objects::ObjectId id, std::uint8_t direction,
                       const objects::Grid::Mask& mask) {
    const auto* o = owner.get(id);
    if (!o)
        return {};
    const auto* grid = owner.grid();
    if (!grid)
        return {false, Status::missing_grid};
    const auto r = owner.footprint(*o);
    if (direction == 2 || direction == 8) {
        const auto x = direction == 2 ? r.max_x : r.min_x - 1;
        if ((direction == 2 && x >= grid->width) || (direction == 8 && x < 0))
            return {};
        for (auto z = r.min_z; z < r.max_z; ++z) {
            if (z < 0 || z >= grid->depth)
                return {};
            const auto admitted = clear(mask, x, z);
            if (!admitted.value)
                return admitted;
        }
        return {true};
    }
    if (direction == 1 || direction == 4) {
        const auto z = direction == 1 ? r.max_z : r.min_z - 1;
        if ((direction == 1 && z >= grid->depth) || (direction == 4 && z < 0))
            return {};
        for (auto x = r.min_x; x < r.max_x; ++x) {
            if (x < 0 || x >= grid->width)
                return {};
            const auto admitted = clear(mask, x, z);
            if (!admitted.value)
                return admitted;
        }
        return {true};
    }
    return {};
}
Predicate allowed_direction(const objects::Owner& owner, objects::ObjectId id,
                            std::uint8_t direction, std::span<const room_geometry::Occupant> actors,
                            objects::Grid::Mask& combined) {
    const auto* o = owner.get(id);
    if (!o || !direction || (o->control_flags & 0x10) || o->count > 0 ||
        owner.type(o->type)->request_threshold <= 0)
        return {};
    if (!owner.grid())
        return {false, Status::missing_grid};
    combined = room_geometry::combined_occupancy(owner, actors);
    return leading_edge(owner, id, std::uint8_t(o->allowed_directions & direction), combined);
}
Class classify_direction(const objects::Owner& owner, objects::ObjectId id, std::uint16_t heading,
                         std::span<const room_geometry::Occupant> actors,
                         objects::Grid::Mask& combined) {
    const auto* o = owner.get(id);
    if (!o || (o->control_flags & 0x10))
        return {};
    if (o->control_flags & 2)
        return {4};
    if (o->control_flags & 0x20)
        return {3};
    const auto direction =
        std::uint8_t(objects::InteractionOwner::direction(heading) & o->allowed_directions);
    const auto allowed = allowed_direction(owner, id, direction, actors, combined);
    if (!allowed.value)
        return {1, allowed.status};
    return {std::uint8_t(!o->direction || o->direction == direction ? 0 : 2)};
}
Located elevated(const objects::Owner& owner, const objects::InteractionOwner& interactions,
                 Vec3 point) {
    const auto* grid = owner.grid();
    if (!grid)
        return {false, {}, 255, Status::missing_grid};
    if (point.y - grid->origin.y < 50)
        return {};
    const auto cell = owner.cell_at(point);
    if (!cell.inside)
        return {};
    const auto found = owner.at_cell(narrow(cell.x), narrow(cell.z));
    return {true, found, found ? *interactions.source_ordinal(*found) : std::uint8_t(255)};
}
Height enter(const objects::Owner& owner, objects::InteractionOwner& interactions,
             std::uint8_t slot, Vec3 point, bool gate) {
    const auto id = interactions.masked(slot);
    if (!id)
        return {};
    const auto* o = owner.get(*id);
    if ((o->control_flags & 2) || o->count >= owner.type(o->type)->capacity)
        return {};
    const auto* grid = owner.grid();
    if (!grid)
        return {0, Status::missing_grid};
    const auto height = band(point.y, grid->origin.y);
    if (!height)
        return {0, Status::unrepresentable_position};
    if (!gate)
        interactions.increment(*id);
    return {narrow((int(o->height) - *height) / 2)};
}
Height exit(const objects::Owner& owner, objects::InteractionOwner& interactions, Vec3 point,
            bool gate) {
    const auto* grid = owner.grid();
    if (!grid)
        return {0, Status::missing_grid};
    const auto height = band(point.y, grid->origin.y);
    if (!height)
        return {0, Status::unrepresentable_position};
    if (*height <= 0)
        return {};
    const auto located = elevated(owner, interactions, point);
    if (located.status != Status::complete)
        return {0, located.status};
    const auto id = interactions.masked(located.authored_ordinal);
    if (!id || owner.get(*id)->count <= 0)
        return {0, Status::complete, !located.object};
    if (!gate)
        interactions.decrement(*id);
    return {narrow(*height / 2), Status::complete, !located.object};
}
float height_offset(const objects::Owner& owner, objects::ObjectId id) noexcept {
    const auto* o = owner.get(id);
    return !o || (o->control_flags & 4) ? 0.0f : float(50 * int(o->height));
}
bool approach(const objects::Owner& owner, objects::ObjectId id, std::uint16_t heading,
              Approach& result) noexcept {
    const auto* o = owner.get(id);
    if (!o)
        return false;
    const auto dx = 25 * int(o->width), dz = 25 * int(o->depth);
    switch (objects::InteractionOwner::direction(heading)) {
        case 1:
            result.position.z = o->center.z - float(50 + dz);
            result.heading = 0;
            break;
        case 2:
            result.position.x = o->center.x - float(50 + dx);
            result.heading = 0x4000;
            break;
        case 4:
            result.position.z = o->center.z + float(50 + dz);
            result.heading = 0x8000;
            break;
        case 8:
            result.position.x = o->center.x + float(50 + dx);
            result.heading = 0xc000;
            break;
    }
    return true;
}
Predicate probe(const objects::Owner& owner, const objects::InteractionOwner& interactions,
                objects::ObjectId id, std::uint8_t source_slot, const actors::Basis& basis,
                Vec3 local, Vec3 actor_position, std::uint16_t heading) {
    const auto* o = owner.get(id);
    if (!o)
        return {};
    const auto* grid = owner.grid();
    if (!grid)
        return {false, Status::missing_grid};
    const auto point = add(basis.direction(local), actor_position);
    const auto cell = owner.cell_at(point);
    if (cell.inside) {
        const auto found = owner.at_cell(narrow(cell.x), narrow(cell.z));
        if (found && *interactions.source_ordinal(*found) == source_slot)
            return {};
    }
    const auto origin = integer_xz(grid->origin);
    if (!origin)
        return {false, Status::unrepresentable_position};
    const auto direction =
        std::uint8_t(objects::InteractionOwner::direction(heading) & o->allowed_directions);
    if (direction == 2 || direction == 8) {
        const auto low = origin->z + 50 * int(o->z);
        return {point.z >= float(low) && point.z <= float(low + 50 * int(o->depth))};
    }
    if (direction == 1 || direction == 4) {
        const auto low = origin->x + 50 * int(o->x);
        return {point.x >= float(low) && point.x <= float(low + 50 * int(o->width))};
    }
    return {};
}
} // namespace reo::native::gameplay_collision::object_queries
