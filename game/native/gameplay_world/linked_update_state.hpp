#pragma once
#include <array>
#include <bit>
#include <cstdint>
#include <optional>
namespace reo::native::gameplay_world {
struct LinkedActorFrameState {
    std::uint8_t center_cache_state{},transient_marker{}; // C8B/C98
};
struct LinkedUpdateState {
    std::uint8_t previous_seconds{}; // source3B5040
    std::int8_t expiry_countdown{5}; // initialized File1 o0 byte37FD80
    std::optional<std::uint8_t> clock_factor; // known only after the actual pass
    std::array<std::uint8_t,4> work_counters{}; //755350, consumers name their roles
    bool prepare(std::uint8_t seconds,std::uint8_t mode)noexcept {
        clock_factor=mode?2:1;work_counters={};
        if(seconds==previous_seconds)return false;
        previous_seconds=seconds;
        expiry_countdown=std::bit_cast<std::int8_t>(std::uint8_t(std::uint8_t(expiry_countdown)-1u));
        if(expiry_countdown>0)return false;
        expiry_countdown=5;return true;
    }
};
}
