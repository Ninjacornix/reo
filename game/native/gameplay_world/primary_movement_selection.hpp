#pragma once
#include "primary_action_selection.hpp"
namespace reo::native::gameplay_world {
// Complete primary movement wrappers64B370..64C080 (secondary1..14).
// Interaction/aim boundaries are shared with the idle selection owner.
bool select_movement_action(World&,Actor&,const animation_events::Metadata&,PrimaryActionSelectionServices&);
bool select_pressed_turn(Actor&,const LocomotionActionRow&); //64E460
bool stop_turn(Actor&); //650550
bool stop_walk(Actor&); //650040
bool stop_run(Actor&); //6501D0
bool stop_sprint(Actor&); //650330
bool stop_backward(Actor&); //6503E0
bool resume_movement(Actor&,std::uint8_t secondary); //650580/5D0/620/670
}
