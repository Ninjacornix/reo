#pragma once
#include <cstdint>
#include <optional>
namespace reo::native::gameplay_session {
// Canonical Session facts for the two distinct game modes. Their actual
// initialization/network producers must establish them; unknown is not zero.
struct ActivityState {std::optional<std::int8_t> single,online;};
// Complete1AFE70/1B0300/811770/810F30 query behavior for known native facts.
// Other main modes return1 without consuming either optional overlay-mode fact.
std::optional<std::int32_t> activity_mode(std::uint8_t main_mode,const ActivityState&)noexcept;
}
