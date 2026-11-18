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
    std::uint8_t inhibited{},pending_reaction{},observation_flags{};
    std::uint16_t steering_value{};
    std::uint8_t steering_button_10{}, steering_button_20{};
    std::uint16_t periodic_counter{},room_memo{},reaction_countdown{};
    std::uint32_t action_counter{};
    std::int32_t forced_priority{};
    std::uint8_t peer_priority{},reference_request{};
    std::uint16_t owned_request{};
    std::uint8_t weight_mode{},room_reaction_gate{}; //1077/107E; shared observation inputs
    // 8122B0 snapshots physical primary records, including inactive ones.
    // 1075 itself is the canonical SpeechState::display_style, not a copy.
    std::uint8_t previous_motion_class_106f{},previous_display_style_1076{};
    std::uint8_t health_band_1078{},previous_health_band_1079{};
    std::uint8_t gauge_band_107a{},previous_gauge_band_107b{};
    std::uint8_t previous_room_reaction_gate{},reference_signal{};
    std::uint8_t threat_band{},previous_threat_band{},threat_slot{}; //106C..106E
    std::uint16_t reactive_hold{},reference_cooldown{},companion_hold{},observation_cooldown{},forced_content{};
    std::uint32_t forward_wall_ticks{},observation_timeout{};
    //1090 is a full word;825CC0 replaces only its low byte while goal B writes
    // a zero-extended equipment-slot byte. Do not split these mutable aliases.
    std::uint32_t goal_resource{};
    //10A8;702C50 selects the signed damage scaling policy consumed by81C500.
    std::uint8_t action_damage_policy{};
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
