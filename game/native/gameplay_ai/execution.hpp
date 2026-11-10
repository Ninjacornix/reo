#pragma once
#include <array>
#include <cstdint>
#include <optional>
namespace reo::native::gameplay_ai {
enum class Status {completed,unavailable};
// One logical actor component. Goal/action IDs and their phases are separate
// from the navigation route's edge action. Presence needs a real producer/import.
struct ExecutionState {
    std::uint16_t goal{},previous_goal{},action{},previous_action{};
    std::array<std::uint8_t,4> goal_phases{},action_phases{};
    std::array<std::uint16_t,4> goal_parameters{};
    std::uint8_t goal_refresh{},action_marker{};
    std::optional<std::uint8_t> weight_profile;
    std::array<std::uint8_t,8> base_weights{},reactive_weights{},status_weights{},combined_weights{};
    std::uint8_t inhibited{},reaction{},pending_reaction{},observation_flags{};
    std::uint16_t periodic_counter{},room_memo{},reaction_countdown{};
    std::uint32_t action_counter{};
    std::int32_t forced_priority{};
    friend bool operator==(const ExecutionState&,const ExecutionState&)=default;
};
struct WeightProfile {
    std::array<std::uint8_t,8> base;
    // Immutable authored parameters, decoded by their individual consumers.
    std::array<std::uint8_t,48> policy;
};
const WeightProfile* weight_profile(std::uint8_t)noexcept;
void set_goal(ExecutionState&,std::uint32_t)noexcept; // complete813380
void clear_action_phases(ExecutionState&)noexcept; // complete81A6F0
void set_action(ExecutionState&,std::uint32_t)noexcept; // complete81A6E0
std::uint32_t finish_goal_six(ExecutionState&)noexcept; // complete814B30
// Complete8123E0 for nonnegative indices. >=20 is the source no-op; negative
// original pointer arithmetic is an explicit unavailable profile, not a clamp.
Status select_weight_profile(ExecutionState&,std::int32_t)noexcept;
}
