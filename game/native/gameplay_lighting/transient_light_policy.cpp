#include "transient_lights.hpp"
#include <bit>
#include <cmath>
#include <stdexcept>
namespace reo::native::gameplay_lighting {
namespace {
constexpr float f(std::uint32_t value){return std::bit_cast<float>(value);}
float finite(float value){if(!std::isfinite(value))throw std::domain_error("Native transient light finite arithmetic required");return value;}
float interpolate(float first,float second,float t){return finite(first+finite(finite(second-first)*t));}
float attenuation(float t){
    //371760's ordered quadratic De Casteljau Y lane: start(0,0),
    // control70B350(3,0), endpoint70B358(3,.01). Preserve the two levels.
    const float a=interpolate(0,0,t),b=interpolate(0,f(0x3c23d70a),t);
    return finite(f(0x3a83126f)+interpolate(a,b,t));
}
std::int16_t decrement(std::int16_t value){return std::bit_cast<std::int16_t>(std::uint16_t(std::uint16_t(value)-1u));}
}
Definition transient_definition(const std::array<float,3>& position)noexcept{
    Definition value;value.vector0={1,1,1,0};value.position=position;
    value.attenuation=f(0x3a83126f);value.parameter=f(0x442f0000);return value;
}
TransientStep advance_transient_light(TransientState& state,std::array<bool,2> present){
    TransientStep result;
    if(state.phase==2){result.retire=true;return result;}
    if(state.phase!=0&&state.phase!=1)return result;
    if(state.phase==0){state.remaining={3,3};state.phase=1;}
    for(unsigned i=0;i<2;++i)if(present[i]){
        state.remaining[i]=decrement(state.remaining[i]);
        if(state.remaining[i]>0){const float t=float(3-int(state.remaining[i]))/3.f;result.attenuation[i]=attenuation(t);}
        else{result.release[i]=true;present[i]=false;}
    }
    if(!present[0]&&!present[1])++state.phase;
    return result;
}
}
