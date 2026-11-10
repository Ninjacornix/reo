#pragma once
#include "execution.hpp"
namespace reo::native::gameplay_session {class Random;}
namespace reo::native::gameplay_ai {
struct ReactionScheduled {Status status{Status::unavailable};std::uint8_t random_draws{};bool written{};};
// Complete8130D0 for the eight authored character chance columns. Nonrandom
// branches do not require a character profile. Out-of-range event IDs are no-ops.
ReactionScheduled schedule_reaction(ExecutionState&,std::uint8_t character,
    std::uint32_t event,gameplay_session::Random&)noexcept;
}
