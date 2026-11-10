#include "update.hpp"
#include <bit>

namespace reo::native::gameplay_update {
namespace {
bool event_completed(gameplay_events::Status value){
    return value==gameplay_events::Status::completed||value==gameplay_events::Status::priority_rejected||value==gameplay_events::Status::full;
}
}
GaugeStatus Owner::record_gauge_crossing(const world::actors::EntityId& id,std::uint32_t before,std::uint32_t after){
    if(!open())return GaugeStatus::unavailable;
    const auto actor=world_.resolve(id);if(!actor)return GaugeStatus::unavailable;
    if(!world_.locally_controlled(*actor))return GaugeStatus::completed;
    const auto old=world::selected_gauge_percentage(world_,before);
    const auto next=world::selected_gauge_percentage(world_,after);
    if(!old||!next)return GaugeStatus::unavailable;
    // Complete667E90: only the first upward threshold crossing is recorded.
    unsigned event{};
    if(*old<50.f&&!(*next<50.f))event=0x21;
    else if(*old<70.f&&!(*next<70.f))event=0x22;
    else if(*old<90.f&&!(*next<90.f))event=0x23;
    if(!event)return GaugeStatus::completed;
    return event_completed(record_event(event,0,0).status)?GaugeStatus::completed:GaugeStatus::event_unavailable;
}
GaugeResult Owner::adjust_actor_gauge(const world::actors::EntityId& id,std::uint32_t full_amount,std::uint32_t full_mode){
    if(!open())return{GaugeStatus::unavailable};
    const auto actor=world_.resolve(id);if(!actor)return{GaugeStatus::unavailable};
    if(actor->category==1||(actor->category==0&&actor->slot!=world_.selected_actor))return{};
    const auto mode=std::bit_cast<std::int8_t>(std::uint8_t(full_mode));
    const auto amount=std::uint16_t(full_amount);
    if(mode==1){
        if(!actor->gauge_value)return{GaugeStatus::unavailable};
        const auto value=*actor->gauge_value-std::uint32_t(amount);
        actor->gauge_value=std::bit_cast<std::int32_t>(value)>0?value:0u;
        return{};
    }
    if(mode!=0)return{};
    if(actor->gauge_modifier_one||actor->gauge_modifier_two||actor->linked_model_variant||
       (actor->auxiliary_status&0x1000u)||(actor->status&0x400000u))return{};
    if(!actor->gauge_value)return{GaugeStatus::unavailable};
    const auto crossing=record_gauge_crossing(id,*actor->gauge_value,*actor->gauge_value+std::uint32_t(amount));
    if(crossing!=GaugeStatus::completed)return{crossing};
    // Reread after the original threshold-event boundary; all actors and the
    // cooperative pool belong to this same synchronous native update owner.
    actor->gauge_value=*actor->gauge_value+std::uint32_t(amount);
    if(!world::selected_gauge_percentage(world_))return{GaugeStatus::unavailable};
    // The original near100% branch calls pure668110(actor,100), discarding its
    // result. There is no state effect to project into this native operation.
    if(actor->character>=world::actor_gauge_limits.size())return{GaugeStatus::unavailable};
    const auto cap=world::actor_gauge_limits[actor->character];
    if(*actor->gauge_value<cap)return{};
    actor->gauge_value=cap;
    if(world_.locally_controlled(*actor)&&!(actor->auxiliary_status&0x10000000u)){
        actor->auxiliary_status|=0x10000000u;
        if(!event_completed(record_event(0x24,0,0).status))return{GaugeStatus::event_unavailable};
    }
    return{GaugeStatus::completed,1};
}
}
