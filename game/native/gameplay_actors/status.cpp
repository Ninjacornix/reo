#include "status.hpp"
#include <algorithm>

namespace reo::native::gameplay_actors {
bool periodic_damage_admitted(const StatusActor& a) noexcept {
    if(!(a.status&2) || (a.auxiliary_status&0x10000))return false;
    switch(a.motion_class){
    case 0x24:case 0x23:case 0x22:case 0x2f:case 0x2e:case 7:case 3:case 2:case 1:return true;
    case 0x1a:return a.secondary!=0x34;
    default:return false;
    }
}
void clear_status_fields(StatusActor& a,std::uint32_t code)noexcept{
    switch(std::uint8_t(code)){
    case 1:a.current=a.maximum;break;
    case 2:a.status&=~std::uint32_t(1);break;
    case 3:a.status&=~std::uint32_t(2);break;
    case 4:case 9:a.current=a.maximum;a.status&=~std::uint32_t(3);break;
    case 5:a.status&=~std::uint32_t(3);break;
    case 6:a.current=a.maximum;a.status&=~std::uint32_t(1);break;
    case 7:a.current=a.maximum;a.status&=~std::uint32_t(2);break;
    default:break;
    }
}
void clear_status(StatusActor& a,StatusSession& s,StatusServices& services,std::uint8_t code){
    clear_status_fields(a,code);services.publish(a,s,0x0e);
}
void tick_status(StatusActor& a,StatusSession& s,StatusServices& services,gameplay_session::Random& random){
    const std::uint16_t interval_one=s.clock_mode?10:20,interval_two=s.clock_mode?30:60;
    const std::uint16_t duration=std::uint16_t((s.clock_mode?1200:2400)+random.request(1)%(s.clock_mode?3300:6600));
    if(s.paused || (a.status&0x400000))return;
    if((a.status&0x18) && a.current!=0)a.status&=~std::uint32_t(0x18);
    if((a.status&1) && a.current>=2){
        if(s.timer_seconds()%4==0 && s.timer_subseconds()==0)services.feedback(a,s,6);
        a.damage_interval_one=std::min(a.damage_interval_one,interval_one);
        if(a.damage_interval_one==0)a.damage_interval_one=interval_one;
        else if(--a.damage_interval_one==0)apply_health(a,s,services,1,0);
    }
    if(!(a.status&2))return;
    a.status_duration=std::min(a.status_duration,duration);
    if(a.status_duration==0)return;
    if(a.current>=2){
        a.damage_interval_two=std::min(a.damage_interval_two,interval_two);
        if(a.damage_interval_two==0)a.damage_interval_two=interval_two;
        else if(--a.damage_interval_two==0 && periodic_damage_admitted(a)){
            apply_health(a,s,services,5,0);
            if(a.current==0)a.current=1;
            services.feedback(a,s,6);
        }
    }
    --a.status_duration;
    if(a.status_duration==0 || a.current<2){
        a.status_duration=0;a.damage_interval_two=0;
        clear_status(a,s,services,3);
    }
}
namespace {
void select(StatusActor& a,StatusSession& s,StatusServices& services,std::uint8_t primary,std::uint8_t secondary,ZeroHealthEffects* effects=nullptr){
    a.primary=primary;a.secondary=secondary;a.phase=0;a.subphase=0;
    if(effects)effects->snapshot(a,s);else services.snapshot(a,s);
}
void terminal(StatusActor& a,StatusSession& s,StatusServices& services,std::uint8_t secondary,ZeroHealthEffects* effects){
    if(effects)effects->cleanup(a,s);else services.cleanup(a,s);
    a.motion_class=0xa0;select(a,s,services,4,secondary,effects);
}
}
void select_zero_health_action(StatusActor& a,StatusSession& s,StatusServices& services,ZeroHealthEffects* effects){
    if(s.paused || s.session_state==1 || a.current!=0 || (a.primary!=1 && a.primary!=2))return;
    if(!(a.status&0x1f0)){
        if(a.category==1)terminal(a,s,services,0,effects);
        else if(a.auxiliary_status&0x100){if(effects)effects->recover(a,s);else services.recover(a,s);}
        return;
    }
    if(a.status&0x80){
        if(a.recovery_timer)--a.recovery_timer;
        if(a.recovery_timer || !(a.auxiliary_status&0x100))return;
    }else if(a.status&0x10)return;
    a.status|=0x120;terminal(a,s,services,3,effects);
}
bool override_hit_response(StatusActor& a,StatusSession& s,StatusServices& services){
    switch(a.motion_class){
    case 0x0b:if(a.secondary!=0x47)return false;a.response_class=2;select(a,s,services,3,0);break;
    case 0x31:select(a,s,services,3,0x15);break;
    case 0x27:select(a,s,services,3,0x14);break;
    case 0x30:
        if(a.secondary==0xc5)select(a,s,services,1,0xc7);
        else if(a.secondary==0xc8)select(a,s,services,1,0xca);
        else return false;
        break;
    case 0x28:a.current=0;break;
    case 0x1a:select(a,s,services,3,0x12);break;
    default:return false;
    }
    return true;
}
} // namespace reo::native::gameplay_actors
