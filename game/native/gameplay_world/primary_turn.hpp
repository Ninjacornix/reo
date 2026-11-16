#pragma once
#include "idle_action.hpp"
namespace reo::native::gameplay_world {
std::int16_t primary_turn_step(const World&,const Actor&); // complete65F580
void update_turn_action(World&,Actor&,ActionAnimation&); //complete66BB10
}
