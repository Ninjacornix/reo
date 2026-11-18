#pragma once
#include "world.hpp"
namespace reo::native::gameplay_world {
// Complete bounded6BB9F0, using the shared record seed and the existing BB6/BB8
// canonical halfwords. Unsupported source seed indices refuse before writes.
bool initialize_enemy_priorities(World&,const actors::EntityId&) noexcept;
// Complete bounded6EFAF0 over canonical actor state and initialized profiles.
std::optional<std::uint8_t> actor_body_priority(const World&,const Actor&) noexcept;
// Complete bounded6BBDA0 for the actual linked enemy family created by6BB040.
// Admission precedes actor/RNG mutation. The World-owned fifty-node pool is
// required; model/resource creation remains the surrounding caller's work.
bool bind_enemy_record(World&,const actors::EntityId&,
                       const gameplay_scenario::EnemyDescriptor&) noexcept;
}
