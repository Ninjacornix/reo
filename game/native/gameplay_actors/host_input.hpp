#pragma once
#include "input.hpp"
#include <cstdint>

namespace reo::native::gameplay_actors::input {
// Stock File1 analog-pad sample after the host has supplied focus-qualified
// button and stick observations. Buttons use DualShock active-low polarity.
struct AnalogPad {
    std::uint16_t buttons{0xffff};
    std::uint8_t right_x{128},right_y{128},left_x{128},left_y{128};
};
// Original 1A6140/1A5F50/1B06F0 default analog-pad profile. The returned
// sample is consumed by the existing 1B0B80 route; actor history remains there.
ControllerFrame normalize_analog_pad(const AnalogPad&);
}
