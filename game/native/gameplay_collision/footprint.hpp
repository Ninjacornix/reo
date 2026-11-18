#pragma once
#include "room_objects.hpp"
namespace reo::native::gameplay_collision::footprint {
enum class Status {complete,missing_classification,invalid_geometry};
struct Result {Vec3 position;Status status{Status::complete};std::uint8_t passes{};};
// Source57C0B0, independently of static wall sweeps. Enabled is the native room
// owner's admitted movement-object count, matching source745D60!=0.
Result constrain(const room_objects::Owner&,Vec3 proposed,Vec3 previous,
                 bool enabled,bool height_layers,const response::Grid* floors=nullptr);
}
