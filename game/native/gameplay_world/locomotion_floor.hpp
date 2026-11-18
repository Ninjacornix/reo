#pragma once
#include "world.hpp"
#include "../gameplay_collision/response.hpp"
namespace reo::native::gameplay_world {
struct LocomotionFloor {Position probe;std::uint8_t type{255};};
// Complete666BB0: the returned point remains the rotated probe position;
// neither616F20 call writes its returned height into that point.
LocomotionFloor probe_locomotion_floor(const Actor&,const gameplay_collision::response::Grid&);
}
