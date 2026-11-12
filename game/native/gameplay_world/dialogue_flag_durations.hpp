#pragma once
#include <bit>
#include <cstdint>
#include <span>
namespace reo::native::gameplay_world {
// Complete6B80A0. This operation borrows the owner's existing flag bank and
// counters; it does not keep a second flag bank or manufacture initialization.
inline void advance_dialogue_flag_durations(std::span<const std::uint32_t,16> flags,
    std::span<std::int32_t,512> ticks)noexcept{
    for(unsigned i=0;i<ticks.size();++i)ticks[i]=(flags[i/32]&(1u<<(i%32)))?std::bit_cast<std::int32_t>(std::uint32_t(ticks[i])+1u):0;
}
}
