#pragma once
#include "idle_action.hpp"
#include "locomotion_floor.hpp"
namespace reo::native::gameplay_world {
std::uint8_t locomotion_floor_variant(const Actor&,const gameplay_collision::response::Grid&); //5D6910
void select_floor_locomotion(Actor&,std::uint8_t mode,const gameplay_collision::response::Grid&,ActionAnimation&); //66BDB0
void advance_floor_locomotion(Actor&,std::uint8_t clock_mode,const gameplay_collision::response::Grid&); //66C040
void finish_locomotion_step(Actor&,std::uint8_t clock_mode); //5D7BC0
float locomotion_transition_frame(Actor&,std::uint16_t,ActionAnimation&); //5D7890; class2 table pending owner qualification.
}
