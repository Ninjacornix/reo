#include "timer_hud.hpp"
#include <algorithm>
#include <bit>
namespace reo::native::gameplay_scenario {
namespace {
std::int16_t add(std::int16_t value,std::int32_t amount)noexcept{
    return std::bit_cast<std::int16_t>(std::uint16_t(std::uint32_t(std::uint16_t(value))+std::uint32_t(amount)));
}
}
std::optional<TimerHudGlyph> timer_hud_glyph(std::uint8_t slot,std::uint8_t glyph,std::uint32_t rgba)noexcept{
    constexpr std::array<std::int16_t,8> positions{512,524,536,544,556,568,576,588};
    struct Region{std::int16_t u,v,width,height;};
    constexpr std::array<Region,12> regions{{{0,0,12,20},{12,0,12,20},{24,0,12,20},{36,0,12,20},{48,0,12,20},
        {0,20,12,20},{12,20,12,20},{24,20,12,20},{36,20,12,20},{48,20,12,20},{0,40,8,20},{8,40,56,20}}};
    if(slot>=positions.size()||glyph>=regions.size())return{};
    const auto& r=regions[glyph];return TimerHudGlyph{positions[slot],24,r.width,r.height,rgba,r.u,r.v,
        std::int16_t(r.u+r.width),std::int16_t(r.v+r.height)};
}
TimerHudFrame timer_hud(TimerHudPulse& state,const std::array<std::int16_t,8>& countdowns,
    std::uint32_t primary,std::uint32_t alternate,bool use_alternate,bool pulse)noexcept{
    TimerHudFrame result;
    if(!pulse){
        const auto index=std::bit_cast<std::int32_t>(use_alternate?alternate:primary);
        if(index>=8)return result; // Original returns after setup, before ack.
        if(index<0){result.status=TimerHudStatus::unavailable_counter;return result;}
        const auto count=std::int32_t(countdowns[std::size_t(index)]);
        const auto minutes=std::clamp(count/1800,0,99),seconds=std::clamp((count%1800)/30,0,59),hundredths=std::clamp((count%30)*100/30,0,99);
        const std::array<std::uint8_t,8> digits{std::uint8_t(minutes/10),std::uint8_t(minutes%10),10,
            std::uint8_t(seconds/10),std::uint8_t(seconds%10),10,std::uint8_t(hundredths/10),std::uint8_t(hundredths%10)};
        for(unsigned i=0;i<digits.size();++i)result.glyphs[result.count++]=*timer_hud_glyph(std::uint8_t(i),digits[i],0xc0ffffffu);
    }else{
        if(!state.falling){state.value=add(state.value,16);if(state.value>=256){state.falling=1;state.value=255;}}
        else{state.value=add(state.value,-16);if(state.value<0){state.falling=0;state.value=0;}}
        const auto rgba=std::uint32_t(std::uint8_t(state.value))<<24|0x00e01010u;
        state.value=add(state.value,state.delta);
        if(std::uint16_t(state.value)&0x100u){state.delta=add(0,-std::int32_t(state.delta));state.value=add(state.value,state.delta);}
        result.glyphs[result.count++]=*timer_hud_glyph(0,11,rgba);
    }
    result.restore=result.acknowledge=true;return result;
}
}
