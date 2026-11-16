#pragma once
#include <cstdint>
namespace reo::native::gameplay_events {
// Fields of the same scenario statistics owner reset by37B990. These are
// semantic counters, not a second original-layout232-byte state buffer.
struct ActorCounters {
    std::uint32_t forward_distance{},resource_uses{},health_high{},health_middle{},health_low{},status_one{},status_two{};
    std::uint8_t used_resource{};
    std::uint16_t assistance_requests{}; //3B84EA;6507F0 increments with halfword wrap.
    std::uint8_t scripted_terminal{}; //3B84F6;68EF50 sets1,37B990 resets0.
};
//66A3A0's local actor counter tail. The caller owns category/local/status4 gates.
// Finite distance uses the source's signed-word->float/add/truncation order.
bool record_actor_counters(ActorCounters&,float forward_distance,std::int16_t current,std::int16_t maximum,std::uint32_t status)noexcept;
}
