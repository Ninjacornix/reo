#pragma once
#include "../transform_math/transform_math.hpp"
#include <cstdint>
#include <optional>
namespace reo::native::gameplay_effects {
// Actual58DB50 subtype0 billboard lifetime, independent of shared-pool admission.
struct SurfaceFollowerVisual {
    std::uint8_t phase{};bool visible{};
    std::int16_t column{},row{},interval{},delay{};
    std::uint32_t flags{};
    transform_math::Vector position,scale;
    std::array<float,4> color{};
    std::array<float,2> tile_step{},tile_origin{},tile_extent{},tile_cursor{};
};
// Null is the original null parent, not missing telemetry. A present parent is
// retained by the visual owner even after its original generation retires.
bool advance_surface_follower_visual(SurfaceFollowerVisual&,std::optional<transform_math::Vector> parent);
}
