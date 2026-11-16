#include "background.hpp"
namespace reo::native::gameplay_presentation {
bool BackgroundState::select(std::uint32_t index)noexcept{
    constexpr std::array<std::array<std::uint8_t,3>,16> colors{{
        {{0,0,0}},{{192,0,0}},{{0,192,0}},{{0,0,192}},{{192,192,0}},{{0,192,192}},{{192,0,192}},{{192,192,192}},
        {{64,0,0}},{{0,64,0}},{{0,0,64}},{{0,64,32}},{{64,64,64}},{{0,0,0}},{{0,0,0}},{{0,0,0}}
    }};
    if(index>=colors.size())return false;
    const auto rgb=colors[index];rgb_=rgb;parameter14_=0xff000000u|(std::uint32_t(rgb[0])<<16)|(std::uint32_t(rgb[1])<<8)|rgb[2];return true;
}
}
