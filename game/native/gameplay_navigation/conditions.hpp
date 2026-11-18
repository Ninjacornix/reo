#pragma once
#include "bank.hpp"
namespace reo::native::gameplay_navigation {
// Ephemeral facts read from the canonical actor; this is not another owner.
struct ActorFacts {std::uint8_t character{},slot{},ai_control{};};
struct ConditionResult {QueryStatus status{QueryStatus::unavailable};std::int32_t index{-1};};
struct AdmissionResult {QueryStatus status{QueryStatus::unavailable};bool allowed{};};
struct LinkResult {QueryStatus status{QueryStatus::unavailable};std::optional<std::size_t> index;};
ConditionResult applicable_condition(const RoomGraph&,std::int32_t,ActorFacts)noexcept; // complete81A0E0
AdmissionResult admit_condition(const RoomGraph&,std::int32_t,ActorFacts,std::optional<std::uint16_t> room_flags)noexcept; // complete819220
std::optional<std::size_t> find_link(const Asset&,std::int32_t room,std::int32_t variant,std::int32_t node)noexcept; // complete8193A0
LinkResult find_admitted_link(const Bank&,ActorFacts,std::int32_t room,std::int32_t variant,std::int32_t node,std::optional<std::uint16_t> room_flags)noexcept; //819410/819360
}
