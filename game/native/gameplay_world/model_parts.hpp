#pragma once
#include <cstddef>
#include <cstdint>
#include <span>

namespace reo::native::gameplay_world {
// Complete bounded1A31B0. The first top-level type2 record supplies its count.
// Missing type2 returns the source's zero result. Invalid extents throw.
std::uint32_t model_part_count(std::span<const std::byte>);
}
