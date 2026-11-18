#pragma once
#include "delivery.hpp"
#include "trace.hpp"
#include "../transform_math/transform_math.hpp"
namespace reo::native::gameplay_collision::delivery {
class ImpactVisuals {
  public:
    virtual ~ImpactVisuals() = default;
    // Full5DD6F0 population policy. The point is mutable: selected profiles
    // intentionally nudge it before creation, including allocation failure.
    virtual Status oriented(const transform_math::Matrix&, Vec3& point, std::uint8_t key) = 0;
    // Full5DD9D0 population policy. Actor identity remains separate from its
    // optional matrix; here5DD580 supplies a null matrix and a local point.
    virtual Status surface(View, const std::optional<transform_math::Matrix>&, Vec3& point,
                           std::uint8_t key) = 0;
};
// Complete5DD580 scene-event policy. Event1 mutates the real packet impact;
// event2 supplies a local floor point, whose mutation is not published back.
Status emit_contact_impact(const Packet&, Vec3& packet_impact, Actors&, ImpactVisuals&,
                           const std::optional<trace::Hit>& wall,
                           const std::optional<trace::Hit>& floor);
} // namespace reo::native::gameplay_collision::delivery
