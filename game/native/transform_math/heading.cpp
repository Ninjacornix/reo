#include "heading.hpp"
#include "transform_math.hpp"
#include <array>
#include <bit>
#include <cmath>
#include <stdexcept>
namespace reo::native::transform_math {
namespace {
#include "heading_profile.inc"
constexpr float value(std::uint32_t word){return std::bit_cast<float>(word);}
float term(unsigned index){return value(atan_words[index]);}
void finite(float x){if(!std::isfinite(x))throw std::domain_error("Native heading finite profile required");}
float atan_value(float input){
    const auto bits=std::bit_cast<std::uint32_t>(input),magnitude=bits&0x7fffffffu;
    if(magnitude>0x507fffffu){const float result=term(3)+term(7);return bits>>31?-result:result;}
    float x=input;int part=-1;
    if(magnitude<=0x3edfffffu){if(magnitude<=0x30ffffffu)return input;}
    else{
        x=value(magnitude);
        if(magnitude<=0x3f97ffffu){
            if(magnitude<=0x3f2fffffu){x=((x+x)-1.f)/(x+2.f);part=0;}
            else{x=(x-1.f)/(x+1.f);part=1;}
        }else if(magnitude<=0x401bffffu){x=(x-1.5f)/((1.5f*x)+1.f);part=2;}
        else{x=-1.f/x;part=3;}
    }
    const float square=x*x,fourth=square*square;
    const float even=square*(term(8)+fourth*(term(10)+fourth*(term(12)+fourth*(term(14)+fourth*(term(16)+fourth*term(18))))));
    const float odd=fourth*(term(9)+fourth*(term(11)+fourth*(term(13)+fourth*(term(15)+fourth*term(17)))));
    if(part<0)return x-x*(even+odd);
    const float result=term(unsigned(part))-((x*(even+odd)-term(unsigned(part)+4))-x);
    return bits>>31?-result:result;
}
}
float arctangent(float x){require_profile();finite(x);return atan_value(x);}
float quadrant_angle(float y,float x){
    require_profile();finite(y);finite(x);
    const auto xb=std::bit_cast<std::uint32_t>(x),yb=std::bit_cast<std::uint32_t>(y);
    if(xb==0x3f800000u)return atan_value(y);
    const auto ax=xb&0x7fffffffu,ay=yb&0x7fffffffu;
    const unsigned quadrant=((xb>>30)&2u)|(yb>>31);
    constexpr float pi=value(0x40490fdau),half_pi=value(0x3fc90fdau),low=value(0x34222168u);
    // The owned quadrant implementation groups subnormal magnitudes with zero;
    // its positive-X result still preserves the original Y bits.
    if(ay<=0x007fffffu){if(quadrant<2)return y;return quadrant==2?pi:-pi;}
    if(ax<=0x007fffffu)return yb>>31?-half_pi:half_pi;
    const auto exponent_delta=std::bit_cast<std::int32_t>(ay-ax)>>23;
    float angle=half_pi;
    if(exponent_delta<61){
        if((xb>>31)&&exponent_delta< -60)angle=0.f;
        else angle=atan_value(std::fabs(y/x));
    }
    if(quadrant==0)return angle;
    if(quadrant==1)return value(std::bit_cast<std::uint32_t>(angle)^0x80000000u);
    if(quadrant==2)return pi-(angle-low);
    return (angle-low)-pi;
}
std::uint16_t direction_turn(float x,float z){
    finite(x);finite(z);if(x==0.f)x=value(0x38d1b717u);
    const auto angle=quadrant_angle(x,z);
    float degrees=(180.f*angle)/value(0x40490fdbu);
    if(degrees<0.f)degrees+=360.f;
    const float turn=value(0x43360b61u)*degrees;
    if(!(turn>=0.f&&turn<65537.f))throw std::domain_error("Native heading turn conversion unavailable");
    return std::uint16_t(std::uint32_t(turn));
}
}
