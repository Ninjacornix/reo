#pragma once
#include <cstdint>
namespace reo::native::gameplay_scenario {
// Complete691AE0 comparison table7408B0. Both operands are loaded unsigned
// bytes; an unknown comparison selector always takes the false scan.
constexpr bool difficulty_matches(std::uint8_t current,std::uint8_t value,std::uint8_t selector)noexcept{
    switch(selector){
    case 0:return current==value;
    case 1:return current!=value;
    case 2:return current>=value;
    case 3:return current<=value;
    case 4:return current>value;
    case 5:return current<value;
    default:return false;
    }
}
}
