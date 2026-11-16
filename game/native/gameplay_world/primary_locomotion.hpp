#pragma once
#include "locomotion_animation.hpp"
namespace reo::native::gameplay_world {
//66C160/66C4B0/66C840 selected by ordinary secondary states3..11.
void update_locomotion_action(World&,Actor&,const gameplay_collision::response::Grid&,ActionAnimation&);
}
