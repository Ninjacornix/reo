#include "actor_counters.hpp"
#include <bit>
#include <cmath>
#include <limits>
namespace reo::native::gameplay_events {
bool record_actor_counters(ActorCounters& counters,float distance,std::int16_t current,std::int16_t maximum,std::uint32_t status)noexcept{
    if(!std::isfinite(distance))return false;
    //1920A0 preserves negative zero; only negative nonzero values are negated.
    if(distance<0)distance=-distance;
    const float total=float(std::bit_cast<std::int32_t>(counters.forward_distance))+distance;
    if(!std::isfinite(total))return false;
    const auto word=total>=2147483648.f?std::numeric_limits<std::int32_t>::max():total<=-2147483648.f?std::numeric_limits<std::int32_t>::min():std::int32_t(total);
    counters.forward_distance=std::bit_cast<std::uint32_t>(word);
    if(status&1u){++counters.status_one;return true;}
    if(status&2u){++counters.status_two;return true;}
    const auto denominator=maximum<current?current:maximum;
    const float ratio=float(current)/float(denominator);
    if(!(ratio<.75f))++counters.health_high;
    else if(!(ratio<.5f))++counters.health_middle;
    else if(!(ratio<.25f))++counters.health_middle;
    else ++counters.health_low;
    return true;
}
}
