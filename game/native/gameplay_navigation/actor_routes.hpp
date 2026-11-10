#pragma once
#include "cross_room.hpp"
namespace reo::native::gameplay_navigation {
// Canonical logical actor component. No guest offsets, register context or
// embedded source pointer. Presence must be established by a real producer.
struct ActorRouteState {
    std::int8_t current_node{},destination_node{},last_current_node{};
    Position final_position;
    CrossRoomOutput output;
    std::uint16_t previous_action{},action{},destination_room{};
    std::uint8_t completed{},selection_mode{},refresh{};
};
// Complete bounded8173D0: local policy0 or cross-room dispatch, followed by the
// last-current-node write even on completed no-path results.
CrossRoomResult refresh_actor_route(Bank&,ActorFacts,std::uint32_t status,
    std::uint16_t current_room,const RoomFlags&,ActorRouteState&,CrossRoomProfile={})noexcept;
// Complete bounded816EF0: refresh, publish occupancy, choose the first direct
// action or last reverse match at a link node, then final-position substitution.
// Completed -1 is the original route failure; completed0 is its ordinary return.
CrossRoomResult update_actor_route_action(Bank&,ActorFacts,std::uint32_t status,
    std::uint16_t current_room,const RoomFlags&,ActorRouteState&,CrossRoomProfile={})noexcept;
}
