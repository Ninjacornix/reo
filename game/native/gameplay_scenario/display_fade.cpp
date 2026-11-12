#include "display_fade.hpp"
#include <bit>
namespace reo::native::gameplay_scenario {
void start_display_fade(DisplayFadeState& value,bool rising,std::int16_t duration,
                        std::uint8_t mode,std::uint32_t color)noexcept{
    if(value.phase!=1&&value.phase!=2)value.alpha=rising?0.0f:1.0f;
    const auto shifted=std::int32_t(duration)>>(mode&31u);
    auto narrowed=std::bit_cast<std::int16_t>(std::uint16_t(shifted));if(!narrowed)narrowed=1;
    value.color=color;value.step=(rising?1.0f:-1.0f)/float(narrowed);
    value.phase=rising?1:2;value.status=rising?1:2;
}
void advance_display_fade(DisplayFadeState& value,std::uint8_t& initialized)noexcept{
    if(!initialized){initialized=1;value={};value.rectangle.width=640;value.rectangle.height=480;return;}
    if(value.phase==1){
        value.alpha+=value.step;
        if(!(value.alpha<=1.0f)){value.alpha=1.0f;value.phase=99;value.status=99;}
    }else if(value.phase==2){
        value.alpha+=value.step;
        if(value.alpha<0.0f){value.alpha=0.0f;value.status=99;value.phase=0;}
    }else if(value.phase&&!value.status)value.phase=0;
}
bool display_fade_finished(const DisplayFadeState& value)noexcept{return value.status==99;}
} // namespace reo::native::gameplay_scenario
