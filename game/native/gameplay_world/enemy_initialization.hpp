#pragma once
#include "world.hpp"
namespace reo::native::gameplay_world {
// Complete bounded6BB9F0, using the shared record seed and the existing BB6/BB8
// canonical halfwords. Unsupported source seed indices refuse before writes.
bool initialize_enemy_priorities(World&,const actors::EntityId&) noexcept;
}
