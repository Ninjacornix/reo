#pragma once
#include "world.hpp"
#include "../gameplay_collision/response.hpp"
namespace reo::native::gameplay_world {
// Read-only native room floor owner. No original collision buffer or address is
// retained. Both operations mutate the canonical actor, including transform
// rollback in resolve_surface for the original special surface/status case.
void sample_surface(Actor&,const gameplay_collision::response::Grid&)noexcept;
void resolve_surface(Actor&,const gameplay_collision::response::Grid&)noexcept;
}
