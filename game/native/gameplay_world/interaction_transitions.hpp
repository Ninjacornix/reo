#pragma once
#include "world.hpp"
namespace reo::native::gameplay_update {class RoomClaimSink;}
namespace reo::native::gameplay_world {
enum class InteractionTransitionStatus {idle,rejected,completed,unavailable};
struct InteractionTransition {
    InteractionTransitionStatus status{InteractionTransitionStatus::unavailable};
    bool original_result{};
};
//64EF10's table-driven branch through the canonical pending/request/pose owner.
// Offline remote-actor room reconstruction and selectors outside the admitted
// two-column table profile refuse after the pending-byte consumption prefix.
InteractionTransition consume_interaction_request(World&,const actors::EntityId&,std::uint32_t selector,gameplay_update::RoomClaimSink* = nullptr)noexcept;
bool begin_interaction_hold(World&,const actors::EntityId&)noexcept; //6696C0
bool resume_offline_interaction(World&,const actors::EntityId&)noexcept; //668F20; actual scene selection remains required when not rejected by source status
}
