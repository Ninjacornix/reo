#include "host_input.hpp"
#include "../transform_math/transform_math.hpp"
#include <algorithm>
#include <array>
#include <bit>
#include <cmath>

namespace reo::native::gameplay_actors::input {
namespace {
// Owned default analog-pad table at 231050, selected by 1A6760 for type73.
constexpr std::array<std::uint16_t,16> masks{
    0x1000,0x4000,0x8000,0x2000,0x40,0x20,0x2,0x1,
    0x80,0x10,0x8,0x4,0x200,0x400,0x100,0x800};
constexpr std::array<std::uint8_t,16> low_nibble{0,1,2,0,4,5,6,4,8,9,10,8,0,1,2,0};
constexpr std::array<std::uint8_t,16> directions{8,9,9,1,1,5,5,4,4,6,6,2,2,10,10,8};
constexpr float pi=std::bit_cast<float>(0x40490fdbu),two_pi=std::bit_cast<float>(0x40c90fdbu);
constexpr float turn_per_degree=std::bit_cast<float>(0x43360b61u),axis_scale=std::bit_cast<float>(0x3fbae148u);
std::int16_t axis(std::uint8_t value)noexcept{
    const int raw=value;const int shifted=raw>=128?std::max(raw-168,0):std::min(raw,87)-87;
    return std::int16_t(float(shifted)*axis_scale);
}
struct Stick {std::int16_t x{},y{},magnitude{},degrees{},heading{};std::uint8_t directions{};};
Stick stick(std::uint8_t raw_x,std::uint8_t raw_y){
    Stick s;s.x=axis(raw_x);s.y=axis(raw_y);float angle=0;
    if(s.x||s.y){
        const double radians=std::atan2(double(-int(s.y)),double(s.x));
        angle=float(radians);
        if(std::fabs(double(angle))>std::fabs(radians))angle=std::nextafter(angle,0.f);
        if(angle<0)angle+=two_pi;
    }
    s.magnitude=std::int16_t(std::min(127,int(std::sqrt(double(int(s.x)*s.x+int(s.y)*s.y)))));
    // Cold 1A5C80 initializes the two radial thresholds to one.
    if(s.magnitude<1){s.x=s.y=s.magnitude=0;angle=0;}
    s.degrees=std::int16_t(360.f*(angle/two_pi));
    if(s.magnitude>=37)s.directions=directions[std::size_t(float(s.degrees)/22.5f)];
    float degrees=(180.f*angle)/pi;if(degrees<0)degrees+=360.f;
    const auto turn=std::uint16_t(std::uint32_t(turn_per_degree*degrees));
    s.heading=std::bit_cast<std::int16_t>(std::uint16_t(turn-0x4000u));return s;
}
}
ControllerFrame normalize_analog_pad(const AnalogPad& pad){
    transform_math::require_profile();const auto pressed=std::uint16_t(~pad.buttons);
    // 1A6760 assembles the first wire byte as the high half before 1A6140
    // applies the owned mask table. The host's typed bit field is low-first.
    const auto buttons=std::uint16_t((pressed<<8)|(pressed>>8));std::uint32_t held=0;
    for(unsigned i=0;i<masks.size();++i)if(buttons&masks[i])held|=1u<<i;
    held=(held&0xfff0u)|low_nibble[held&15u];
    const auto left=stick(pad.left_x,pad.left_y),right=stick(pad.right_x,pad.right_y);
    held|=std::uint32_t(left.directions)<<16;held|=std::uint32_t(right.directions)<<20;
    return{held,{left.magnitude,left.heading,left.x,left.y,right.magnitude,right.heading,right.x,right.y}};
}
}
