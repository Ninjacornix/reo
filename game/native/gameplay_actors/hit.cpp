#include "hit.hpp"
#include <bit>
#include <stdexcept>

namespace reo::native::gameplay_actors {
namespace {
void action(HitActor& a,HitSession& s,HitServices& services,std::uint8_t primary,std::uint8_t secondary){
    a.primary=primary;a.secondary=secondary;a.phase=0;a.subphase=0;
    services.snapshot(a,s);
}
}
void consume_pending_hit(HitActor& a,HitSession& s,HitServices& services,std::span<const std::int16_t> amounts){
    if(s.paused || s.suppress_hits){a.pending_hit=0;return;}
    if(!a.pending_hit)return;
    a.pending_hit=0;a.notice_flags|=1;
    if(a.category==0 && a.special_kind==2 && a.damage_kind==9){
        a.status|=0x40000800;a.current=0;a.status|=0x20;
        services.cleanup(a,s);a.motion_class=0xa0;action(a,s,services,4,0);
        a.notice_flags|=1;services.publish(a,s,5);return;
    }
    if(a.status&0x200008)return;
    if(a.category==1 && !services.selected_authority(s,s.selected_actor))return;
    if(a.response_lock && a.source_kind==0)return;
    if(a.status&0x80){
        if(a.response_class>=amounts.size())throw std::out_of_range("Unadmitted native hit timer class");
        const auto amount=amounts[a.response_class];
        if(std::int32_t(std::bit_cast<std::int16_t>(a.recovery_timer))-amount<=0)a.recovery_timer=1;
        else a.recovery_timer=std::uint16_t(a.recovery_timer-std::uint16_t(amount));
        if(a.damage_kind>=0x10)a.damage_kind=1;
        action(a,s,services,3,a.damage_kind);a.notice_flags|=1;return;
    }
    if(a.source_kind==0 && services.locally_controlled(a,s)){
        const auto source=a.source_slot;
        if(services.partner_flags(source&3)&0x80)services.event(a,s,0x25,services.partner_character(source));
    }
    if((a.response_flags&2) && !(a.status&0x400000))services.add_status(a,s,1);
    if((a.response_flags&4) && !(a.status&0x400000))services.add_status(a,s,2);
    a.transient_contact=0;a.transient_action=0;a.transient_equipment=0;
    if(services.locally_controlled(a,s))services.close_inventory(a,s);
    if(a.category==0 && a.primary==1 && a.secondary==0x16){
        const auto slot=a.interaction_slot;
        if(services.scene_owner(slot)!=std::uint32_t(a.slot)+1)services.detach_scene(a,s,2,slot);
    }
    if(a.category==0 && a.primary==1 && a.secondary==0x24){
        services.detach_scene(a,s,1,a.equipment_slot);
        services.release_equipment(a,s,a.equipment_slot);
    }
    if(a.category==0 && a.primary==2 && a.secondary==0x0b){a.status|=0x80000000;services.cancel_action(a,s);}
    a.status&=~std::uint32_t(0x80000);
    if(a.category==0)services.clear_owner_interaction(a,s);
    if(a.progression_amount)services.apply_progression(a,s,a.progression_amount);
    if(services.locally_controlled(a,s))services.refresh_statistics(a,s);
    services.finish_contact_state(a,s);
    if(services.locally_controlled(a,s) && !(a.response_flags&1))s.contact_recorded=1;
    if(a.damage_kind>=0x80){
        if((a.status&0x800000) || (a.status&0xb8))return;
        if(override_hit_response(a,s,services))return;
        action(a,s,services,5,std::uint8_t(a.damage_kind-0x80));
        services.clear_hit_relations(a,s);
    }else{
        const auto previous=a.current;
        if(a.damage_word>0)services.feedback(a,s,3);
        if(apply_health(a,s,services,std::uint16_t(a.damage_word),0)){
            a.current=0;
            if(override_hit_response(a,s,services))return;
            if(previous>=2)a.current=1;
        }else if(override_hit_response(a,s,services))return;
        action(a,s,services,3,a.damage_kind);services.publish(a,s,5);
    }
    a.notice_flags|=1;
    if(services.authority_filter(s) && a.category==1){
        a.status|=0x10000000;services.publish(a,s,5);a.status&=~std::uint32_t(0x10000000);
    }
}
} // namespace reo::native::gameplay_actors
