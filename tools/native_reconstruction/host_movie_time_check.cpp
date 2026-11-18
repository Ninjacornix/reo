#include "game/native/host_movie/playback_time.hpp"
#include <cstdio>
#include <cstdlib>
#include <limits>

int main(){
    using reo::native::host_movie::playback_time;
    auto check=[](bool okay){if(!okay)std::abort();};
    for(double seconds:{0.0,1001.0/30000.0,205.0048,376.943233333,96000.0}){
        const auto value=playback_time(seconds);check(bool(value)&&value->units==1000);
        const auto represented=static_cast<double>(value->count)/value->units;
        check(represented<=seconds&&seconds-represented<0.001000001);
    }
    check(!playback_time(-0.1));
    check(!playback_time(std::numeric_limits<double>::infinity()));
    check(!playback_time(std::numeric_limits<double>::quiet_NaN()));
    check(!playback_time(static_cast<double>(std::numeric_limits<std::int32_t>::max())/1000+1));
    check(playback_time(205.0048)->count!=6144); // A frame ordinal is not elapsed seconds.
    std::puts("{\"status\":\"native rational playback clock passed\",\"game_run\":false}");
}
