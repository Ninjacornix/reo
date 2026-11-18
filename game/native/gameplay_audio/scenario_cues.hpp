#pragma once
#include <cstdint>
namespace reo::native::gameplay_audio {
// Complete1B8870 within the five bounded208-entry File1 tables. Other
// scenarios preserve the caller's full unsigned word without narrowing.
std::uint32_t scenario_cue(std::uint16_t scenario,std::uint32_t event);
}
