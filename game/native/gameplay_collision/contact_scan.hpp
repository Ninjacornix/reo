#pragma once
#include "delivery.hpp"
#include "directed.hpp"
namespace reo::native::gameplay_collision::delivery {
enum class Mode { segment, margin, angular };
struct Query {
    Mode mode{Mode::segment};
    Vec3 start, end, direction;
    float margin{};
    directed::Extents extents;
    std::uint8_t mask{}; // packet19, shared recipient/scene-query control bits
};
class Effects : public Feedback {
  public:
    // Additional canonical actor option C94 is owned by the actor's behavior
    // component. Its exact bit1000 predicate remains an explicit typed service.
    virtual bool class_two_mark_exempt(View) = 0;
    virtual void surface_mark(Vec3 point, Vec3 normalized_direction) = 0;
};
enum class DirectionPolicy { require_known_tail, selected_region_repair };
struct Context {
    Actors& actors;
    const Tables& tables;
    gameplay_session::Random& random;
    Effects& effects;
    std::span<const std::uint8_t> class_masks;
    bool special_mode{};
    std::uint8_t difficulty{};
    const spatial::Occlusion* obstacles{};
    // Explicit candidate source repair. The default retains the original
    // admission limit rather than silently changing global contact behavior.
    DirectionPolicy direction_policy{DirectionPolicy::require_known_tail};
};
struct ScanReport {
    Status status{Status::completed};
    std::uint32_t region_hits{}, deliveries{}, priority_overwrites{};
    actors::EntityId last_scanned, selected, advanced_direction_owner;
};
// Recipient IDs are the source enrollment order, including repeated entries.
// The caller retains native leases throughout; all delivery mutations touch the
// canonical HitActor/Component. A partial refusal must never be retried through
// an original implementation. output_point may contain a caller's initialized
// value; unknown is distinct from a known zero and is preserved on no overwrite.
ScanReport scan(std::span<const actors::EntityId> recipients, const Packet&, Query, Context&,
                std::optional<Vec3>& output_point);
} // namespace reo::native::gameplay_collision::delivery
