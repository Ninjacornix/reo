#pragma once
#include "world.hpp"
#include "../gameplay_collision/trace.hpp"

namespace reo::native::gameplay_world {
enum class ForwardContactStatus { completed, unavailable };
struct ForwardContactResult {
    ForwardContactStatus status{ForwardContactStatus::unavailable};
    std::uint16_t original_result{};
};

// Source-equivalent65F4A0 over the current room's ordered wall grid. The
// contact point/normal are the existing canonical ProjectileContact pair;
// +540 is the original low-byte query-result latch.
ForwardContactResult probe_forward_contact(
    Actor&, const gameplay_collision::response::Grid&,
    std::uint32_t include, std::uint32_t exclude, float signed_offset,
    std::span<const gameplay_collision::response::Triangle> dynamic = {});
}
