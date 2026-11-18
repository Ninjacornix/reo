#include "analog_control.hpp"
#include "head_reaction.hpp"
#include "../transform_math/heading.hpp"
#include <array>
#include <bit>
#include <limits>

namespace reo::native::gameplay_world {
namespace {
std::int16_t signed16(std::uint32_t value)noexcept{return std::bit_cast<std::int16_t>(std::uint16_t(value));}
std::uint16_t word(std::int32_t value)noexcept{return std::uint16_t(value);}
}

AnalogControlStatus update_analog_control(World& world,Actor& actor,
    transform_math::Vector camera_eye,transform_math::Vector camera_aim,
    std::uint8_t& camera_latch,std::optional<std::uint8_t> request_blocked,
    std::optional<bool> dialogue_suppressed){
    if(!actor.analog_control)return AnalogControlStatus::unavailable;
    auto& state=*actor.analog_control;
    auto& frame=actor.input;
    std::uint32_t direction_mask{};
    bool control_notice{};
    const bool response_locked=actor.response_lock!=0;
    {
        // The global request byte is fetched only when BD0 is zero.
        if(response_locked){frame={};}
        else{
            if(!request_blocked)return AnalogControlStatus::unavailable;
            if(*request_blocked)frame={};
        }
    }
    const bool local=world.locally_controlled(actor);
    if(local){
        if(world.session().inventory_owner==0){
            if(!dialogue_suppressed)return AnalogControlStatus::unavailable;
            (void)*dialogue_suppressed;
        }
    }

    if(frame.analog[0]<16){
        state.heading_active=0;
        actor.status&=~0x2000u;
        if(!(actor.status&0x80u))return AnalogControlStatus::completed;
        const auto held=frame.held;
        // 6622C4 returns through the epilogue when held&2 is clear. It leaves
        // F80/F78/F7C unchanged after the status/FAA writes above.
        if(!(held&2u))return AnalogControlStatus::completed;
        const auto both=held&0xcu;
        if(both){direction_mask&=~2u;direction_mask|=both;}
        else direction_mask|=4u;
        frame.held=(frame.held&~0xfu)|direction_mask;
        frame.pressed=frame.held&~frame.history[0];
        frame.released=frame.history[0]&~frame.held;
        return AnalogControlStatus::completed;
    }

    actor.status|=0x2000u;
    // High magnitude first selects one of two source paths. These motion
    // classes update the directional nibble and return before the camera
    // latch/heading/table path.
    const auto motion=actor.motion_class;
    bool angle_state=motion==0x31||motion==0x27||motion==0x80||motion==0xb0||motion==0x1a;
    if(actor.character==1&&motion==0x41)angle_state=true;
    if(angle_state){
        // Original6623E4..428 adds0x2000 then ANDs0xC000. The intervening
        // E000/A000/6000/2000 comparisons are unreachable after that mask.
        const auto sector=std::uint16_t(word(frame.analog[1])+0x2000u)&0xc000u;
        switch(sector){case 0xc000u:direction_mask=8;break;case 0x8000u:direction_mask=2;break;case 0x4000u:direction_mask=4;break;default:direction_mask=1;break;}
        frame.held=(frame.held&~0xfu)|direction_mask;
        frame.pressed=frame.held&~frame.history[0];
        frame.released=frame.history[0]&~frame.held;
        return AnalogControlStatus::completed;
    }

    // Source6624E0..528 consumes camera state on every high-magnitude pass.
    // The latch clear is a delay-slot effect before calling the heading helper.
    if(camera_latch&&actor.ai_control==0){state.heading_active=1;state.previous_input_heading=frame.analog[1];}
    camera_latch=0;
    std::uint16_t camera_heading{};
    try{camera_heading=transform_math::direction_turn(camera_aim.x-camera_eye.x,camera_aim.z-camera_eye.z);}
    catch(...){return AnalogControlStatus::unavailable;}
    const auto combined=std::uint16_t((camera_heading&0xfff0u)+(std::uint16_t(frame.analog[1])&0xfff0u));
    state.control_target_heading=signed16(combined);
    const auto difference=std::uint16_t(combined-std::uint16_t(actor.orientation[1]));
    constexpr std::array<std::array<std::uint16_t,2>,5> primary{{
        {{0xff00,0x0100}},{{0xc800,0x3800}},{{0xb000,0x5000}},{{0x8800,0x7800}},{{0x8000,0x8000}}
    }};
    constexpr std::array<std::array<std::uint16_t,2>,5> secondary{{
        {{0xfd00,0x0300}},{{0xc800,0x3800}},{{0xb000,0x5000}},{{0x8800,0x7800}},{{0x8000,0x8000}}
    }};
    unsigned sector_index=0;
    const auto& table=motion==0x16?secondary:primary;
    for(unsigned i=0;i<5;++i){
        const auto lo=table[i][0],hi=table[i][1];
        // 662598/5A8 use signed SLT after both operands have been zero
        // extended to 16 bits. Each pair is a wrapped interval: [lo,ffff]
        // union [0,hi].
        if(difference>=lo||difference<=hi){sector_index=i;break;}
    }
    if(state.heading_active){
        const auto wrapped=std::uint16_t(std::uint16_t(state.previous_input_heading)-std::uint16_t(frame.analog[1])+0x071c);
        if(wrapped<0x0e39)sector_index=motion==2?4:0;
    }
    // 662658..7C4 dispatches the table ordinal before forming the low action
    // nibble. Ordinals3/4 have AI/status gates and the real65F0C0 selection.
    if(sector_index==0)direction_mask|=1;
    else if(sector_index==1||sector_index==2){
        direction_mask|=1;
        direction_mask|=(difference&0x8000u)?8u:4u;
    }else if(sector_index==3||sector_index==4){
        if(actor.ai_control!=0||(actor.status&0x80u)){
            direction_mask=1u|((difference&0x8000u)?8u:4u);
        }else if(motion==2){
            bool has_head_target{};
            try{has_head_target=bool(select_head_target(world,actor,320.f,0,std::numeric_limits<std::int16_t>::min(),0));}
            catch(...){return AnalogControlStatus::unavailable;}
            if(!has_head_target||(frame.pressed&0x10u)){
                direction_mask=0x12;
                frame.history[0]&=~0x10u;
                control_notice=true;
            }else{
                direction_mask=1u|((difference&0x8000u)?8u:4u);
            }
        }else{
            direction_mask=1u|((difference&0x8000u)?8u:4u);
        }
    }
    frame.held=(frame.held&~0xfu)|(direction_mask&0xfu);
    if(control_notice)frame.held|=0x10u;
    if(response_locked)frame.held=0;
    frame.pressed=frame.held&~frame.history[0];
    frame.released=frame.history[0]&~frame.held;
    return AnalogControlStatus::completed;
}
} // namespace reo::native::gameplay_world
