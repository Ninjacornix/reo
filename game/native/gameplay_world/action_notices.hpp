#pragma once
#include "world.hpp"

namespace reo::native::gameplay_world {
// Complete6651F0. The action-one set differs from664D00's periodic snapshot
// classification. Only action2/substate2 reads the selected descriptor. Its
// three source read sites all suppress for zero quantity and publish otherwise.
inline std::optional<bool> suppress_action_notice(const Actor& actor,
    std::uint32_t previous_primary,std::uint32_t previous_secondary,
    std::optional<std::int16_t> selected_quantity)noexcept {
    const auto state=actor.secondary;
    if(actor.primary==1)
        return (state>=1&&state<=0x0e)||state==0x31||state==0x32||
            (state>=0x4a&&state<=0x55)||(state>=0x74&&state<=0x7c)||
            (state>=0x81&&state<=0x83)||(state>=0x98&&state<=0xa0)||
            (state>=0xa3&&state<=0xab)||state==0xcd||state==0xd0||state==0xd1;
    if(actor.primary!=2)return false;
    if(state==2){
        if(!selected_quantity)return {};
        return *selected_quantity==0;
    }
    if(state==9&&std::uint8_t(previous_primary)==2&&
       (std::uint8_t(previous_secondary)==5||std::uint8_t(previous_secondary)==6))return true;
    return state==0||state==1||state==5||state==6||state==7||state==10;
}
}
