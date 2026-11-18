#pragma once
#include "world.hpp"

namespace reo::native::gameplay_world {
// Complete664D00 classification. Numeric substates retain their source meaning;
// this predicate does not assign speculative action names.
inline bool state_message_classified(const Actor& actor)noexcept{
    const auto state=actor.secondary;
    return actor.primary==1&&(state<=0x0e||state==0x24||state==0x31||state==0x32||
        (state>=0x4a&&state<=0x55)||(state>=0x74&&state<=0x7c)||
        (state>=0x81&&state<=0x83)||(state>=0x98&&state<=0xa0)||
        state==0xcd||state==0xd0||state==0xd1);
}
//664F60 has a deliberately narrower state set than664D00.
inline bool periodic_state_message_classified(const Actor& actor)noexcept{
    return state_message_classified(actor)&&actor.secondary!=0x31&&
        actor.secondary!=0x32&&actor.secondary!=0x98;
}
// File#1 US71ADB0, indexed by B98. Other character profiles are unadmitted.
inline constexpr std::array<std::uint32_t,8> actor_gauge_limits{
    151200,273600,100800,345600,345600,201600,345600,100800};
inline float gauge_unsigned_float(std::uint32_t value)noexcept{
    if(!(value&0x80000000u))return float(std::int32_t(value));
    const auto half=float(std::int32_t((value>>1)|(value&1u)));
    return half+half;
}
// Complete667F90: the selected primary owns the gauge, independently of the
// actor whose message is being published. BAC's writers/import remain required.
inline std::optional<float> selected_gauge_percentage(const World& world,std::uint32_t value)noexcept{
    if(world.closed())return{};
    const auto actor=world.primary(world.selected_actor);
    if(!actor||actor->character>=actor_gauge_limits.size())return{};
    const auto ratio=gauge_unsigned_float(value)/gauge_unsigned_float(actor_gauge_limits[actor->character]);
    return 100.f*ratio;
}
inline std::optional<float> selected_gauge_percentage(const World& world)noexcept{
    const auto actor=world.primary(world.selected_actor);
    if(!actor||!actor->gauge_value)return{};
    return selected_gauge_percentage(world,*actor->gauge_value);
}
inline std::optional<std::uint8_t> selected_gauge_band(const World& world)noexcept{
    const auto value=selected_gauge_percentage(world);if(!value)return{};
    if(!(*value<90.f))return 3;
    if(!(*value<80.f))return 2;
    if(!(*value<50.f))return 1;
    return 0;
}
}
