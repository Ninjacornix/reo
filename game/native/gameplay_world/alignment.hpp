#pragma once
#include "world.hpp"
namespace reo::native::gameplay_world {
// Contact geometry is the canonical Actor projectile/contact pose. A rejected
// angular limit retains the previous (possibly unknown) alignment target.
bool prepare_contact_alignment(Actor&,std::uint32_t angular_limit,float offset);
}
