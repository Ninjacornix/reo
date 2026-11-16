#pragma once
#include "../gameplay_world/world.hpp"
#include "../gameplay_navigation/bank.hpp"
namespace reo::native::gameplay_scenario {
inline bool offline_room_variant_ready(const gameplay_world::World& world)noexcept{
    const auto bank=world.navigation_if_created();
    return bank&&bank->refresh_source_ready();
}
//701840 has its own handler: unlike ordinary68ECA0, the low-byte store is
// followed by a complete815E70(2) refresh over the retained source owner.
inline bool set_offline_room_variant(gameplay_world::World& world,std::uint32_t room,std::uint32_t value)noexcept{
    if(!offline_room_variant_ready(world)||room>=gameplay_session::RoomVariants::capacity)return false;
    if(!world.session().room_variants.store(room,value))return false;
    return world.navigation().refresh_rooms_mode_two(); // Preserve the committed store if refresh refuses.
}
}
