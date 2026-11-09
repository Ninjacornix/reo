#pragma once
#include "object_interactions.hpp"
namespace reo::native::gameplay_collision::object_queries {
namespace objects = room_objects;
enum class Status { complete, missing_grid, mask_bounds, unrepresentable_position };
struct Predicate {
    bool value{};
    Status status{Status::complete};
};
struct Class {
    std::uint8_t value{1};
    Status status{Status::complete};
};
struct Height {
    std::int8_t value{};
    Status status{Status::complete};
    bool used_slot31_fallback{};
};
struct Located {
    bool written{};
    std::optional<objects::ObjectId> object;
    std::uint8_t authored_ordinal{255};
    Status status{Status::complete};
};
Predicate padded_direction(const objects::Owner&, objects::ObjectId, std::uint8_t direction);
Predicate leading_edge(const objects::Owner&, objects::ObjectId, std::uint8_t direction,
                       const objects::Grid::Mask&);
// Combined occupancy publication follows the original admission gates. Caller
// supplies its one canonical mask; failed preconditions leave it untouched.
Predicate allowed_direction(const objects::Owner&, objects::ObjectId, std::uint8_t direction,
                            std::span<const room_geometry::Occupant>,
                            objects::Grid::Mask& combined);
Class classify_direction(const objects::Owner&, objects::ObjectId, std::uint16_t heading,
                         std::span<const room_geometry::Occupant>, objects::Grid::Mask& combined);
Located elevated(const objects::Owner&, const objects::InteractionOwner&, Vec3);
Height enter(const objects::Owner&, objects::InteractionOwner&, std::uint8_t source_slot,
             Vec3 actor_position, bool input_gate);
Height exit(const objects::Owner&, objects::InteractionOwner&, Vec3 actor_position,
            bool input_gate);
float height_offset(const objects::Owner&, objects::ObjectId) noexcept;
struct Approach {
    Vec3 position;
    std::uint16_t heading{};
};
bool approach(const objects::Owner&, objects::ObjectId, std::uint16_t actor_heading,
              Approach&) noexcept;
Predicate probe(const objects::Owner&, const objects::InteractionOwner&, objects::ObjectId,
                std::uint8_t original_source_slot, const actors::Basis&, Vec3 local_probe,
                Vec3 actor_position, std::uint16_t actor_heading);
} // namespace reo::native::gameplay_collision::object_queries
