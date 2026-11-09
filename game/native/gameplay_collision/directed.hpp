#pragma once
#include "spatial.hpp"
namespace reo::native::gameplay_collision::directed {
// Positive shape extents feed atan2(second,first), not a caller-supplied angle.
struct Extents {float first{},second{};};
struct Pair {float first{},second{};};
Pair ratios(Extents)noexcept;
std::optional<spatial::Point> contact(Sphere,Vec3 origin,Vec3 direction,Extents)noexcept;
spatial::Scan scan(std::span<const spatial::Target>,const spatial::Source&,spatial::Policy,
                   Vec3 origin,Vec3 direction,Extents,const spatial::Occlusion* obstacles=nullptr);
}
