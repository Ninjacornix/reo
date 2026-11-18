#pragma once
#include "world.hpp"
namespace reo::native::gameplay_world {
// Complete65ED70/65F060: consumes the canonical metric cache and actual model
// point, retaining identities across the selection. Missing producers throw.
actors::EntityId select_weapon_target(World&,Actor&,float maximum_distance);
void prepare_weapon_target(World&,Actor&,bool automatic);
}
