#include "scenario_cues.hpp"
#include <array>
#include <stdexcept>
namespace reo::native::gameplay_audio {
namespace {
#include "scenario_cues_profile.inc"
}
std::uint32_t scenario_cue(std::uint16_t scenario,std::uint32_t event){
    unsigned index;
    switch(scenario){case 1:index=0;break;case 2:index=1;break;case 0x1c:index=2;break;case 0x23:index=3;break;case 0x29:index=4;break;default:return event;}
    if(event>=208)throw std::out_of_range("Native scenario audio event outside immutable table");
    return std::uint32_t(std::int32_t(scenario_cues[index][event]));
}
}
