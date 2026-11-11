#pragma once
#include "snapshot.hpp"
#include "../gameplay_world/primary_saved_state.hpp"
#include <optional>
namespace reo::native::gameplay_save {
// Decode only the primary initialization fields of the legacy second section.
// Remaining serialized bytes retain their existing codec ownership. This does
// not enable a resume or publish state into a running World by itself.
std::optional<gameplay_world::PrimarySavedActors> decode_primary_start_snapshot(std::span<const std::byte>)noexcept;
inline auto decode_primary_start_snapshot(const LiveState& state)noexcept{return decode_primary_start_snapshot(state.second);}
}
