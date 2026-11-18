#include "animation_primitives.hpp"
namespace reo::native::gameplay_world::animation_events {
void notify_equipment_selection(Actor& actor,std::uint8_t selected)noexcept{
    if(actor.category!=0||actor.slot!=selected)return;
    actor.equipment_slot=actor.selected_resource;
    actor.pending_notice|=0x20;
    actor.equipment_notice_slot=actor.slot;
}
}
