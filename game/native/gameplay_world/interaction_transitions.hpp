#pragma once
#include "world.hpp"
namespace reo::native::gameplay_world {
enum class InteractionTransitionStatus {idle,rejected,completed,unavailable};
struct InteractionTransition {
    InteractionTransitionStatus status{InteractionTransitionStatus::unavailable};
    bool original_result{};
};
//64EF10's table-driven branch through the canonical pending/request/pose owner.
// Network room-transition branches and selectors outside the admitted two-column
// table profile refuse after the original pending-byte consumption prefix.
InteractionTransition consume_interaction_request(World&,const actors::EntityId&,std::uint32_t selector)noexcept;
}
