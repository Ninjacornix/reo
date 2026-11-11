#pragma once
#include <cstdint>
namespace reo::native::gameplay_world { class World; }
namespace reo::native::gameplay_scenario {
bool character_remap_ready(const gameplay_world::World&) noexcept;
// Complete bounded68FC00. The two adjacent source aliases resolve through the
// actual placement request and interpreter channel owners.
bool remap_missing_characters(gameplay_world::World&,std::uint8_t script_channel) noexcept;
}
