#pragma once
#include <cstdint>

namespace reo::native::gameplay_scenario {
struct DisplayRectangle {std::int16_t x{},y{},width{},height{};std::uint32_t color{};};
struct DisplayFadeState {
    std::uint8_t phase{};
    std::uint32_t status{},color{};
    float alpha{},step{};
    DisplayRectangle rectangle;
};
// Native1BB5C0/1BB650 and1BB480 state transitions. The scheduler's actual
// callback initialization byte is borrowed; there is no second frame counter
// or implicit presentation-driven advancement here.
void start_display_fade(DisplayFadeState&,bool rising,std::int16_t duration,
                        std::uint8_t clock_mode,std::uint32_t color)noexcept;
void advance_display_fade(DisplayFadeState&,std::uint8_t& callback_initialized)noexcept;
bool display_fade_finished(const DisplayFadeState&)noexcept;
} // namespace reo::native::gameplay_scenario
