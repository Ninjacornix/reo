#include "session.hpp"
#include <bit>

namespace reo::native::gameplay_session {
namespace {
std::uint16_t advance(std::uint16_t value)noexcept{
    return std::uint16_t((std::uint32_t(value?value:1)*176)%0xff53);
}
std::uint8_t byte(std::byte value)noexcept{return std::to_integer<std::uint8_t>(value);}
}
void Random::seed(std::uint8_t value)noexcept{state_={value,value,0};}
std::uint16_t Random::request(std::uint32_t selector)noexcept{
    switch(selector){
    case 0:return state_.secondary;
    case 1:state_.primary=advance(state_.primary);return state_.primary;
    case 2:return state_.observed;
    case 3:state_.secondary=advance(state_.secondary);return state_.secondary;
    default:return 0;
    }
}
void capture_options(const Options& o,SavedOptions& s)noexcept{
    s[0]=std::byte(o.audio_mode);s[1]=std::byte(o.music_volume);s[2]=std::byte(o.effects_volume);
    s[3]=std::byte(o.controller_profile);s[4]=std::byte(o.vibration);s[5]=std::byte(o.brightness);
    s[6]=std::byte(std::bit_cast<std::uint8_t>(o.screen_x));s[7]=std::byte(std::bit_cast<std::uint8_t>(o.screen_y));
}
void sanitize_options(Options& o)noexcept{
    if(o.controller_profile>=6)o.controller_profile=0;
    o.vibration&=1;o.audio_mode&=1;
    if(o.effects_volume>=8)o.effects_volume=7;
    if(o.music_volume>=8)o.music_volume=7;
    if(o.screen_x< -10 || o.screen_x>10)o.screen_x=0;
    if(o.screen_y< -10 || o.screen_y>10)o.screen_y=0;
    if(o.brightness<56 || o.brightness>164)o.brightness=128;
}
void initialize_saved_options(SavedOptions& s,OptionServices& services){
    constexpr std::array<std::uint8_t,16> values{0,7,7,0,1,128,0,0,1,0,0,0,0,0,0,0};
    for(std::size_t i=0;i<s.size();++i)s[i]=std::byte(values[i]);
    services.defaults_changed(s);
}
void restore_options(const SavedOptions& s,Options& o,OptionServices& services){
    o.audio_mode=byte(s[0]);o.music_volume=byte(s[1]);o.effects_volume=byte(s[2]);
    o.controller_profile=byte(s[3]);o.vibration=byte(s[4]);o.brightness=byte(s[5]);
    o.screen_x=std::bit_cast<std::int8_t>(byte(s[6]));o.screen_y=std::bit_cast<std::int8_t>(byte(s[7]));
    services.screen_offset(o,o.screen_x,o.screen_y);
    services.audio_mode(o,o.audio_mode);
    services.effects_volume(o,o.effects_volume);
    services.music_volume(o,o.music_volume);
}
} // namespace reo::native::gameplay_session
