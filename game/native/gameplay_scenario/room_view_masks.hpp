#pragma once
#include <cstdint>
#include <optional>
namespace reo::native::gameplay_scenario {
struct RoomViewMasks {
    std::optional<std::uint32_t> first,second;
    // Actual5ECCA0 writes these before5ECF90 starts loading the scene.
    void begin_scene()noexcept{first=0;second=UINT32_MAX;}
    // Complete58FE80; the second word remains a distinct source value.
    std::optional<bool> visible(std::uint8_t channel)const noexcept{
        if(!first)return{};
        return (*first&(1u<<(channel&31u)))!=0;
    }
};
}
