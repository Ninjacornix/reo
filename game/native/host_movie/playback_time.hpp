#pragma once
#include <cmath>
#include <cstdint>
#include <limits>
#include <optional>

namespace reo::native::host_movie {
struct RationalTime {std::int32_t count{},units{1000};};

// A bounded rational view of the native media clock, independent of frame
// delivery or display rate. Milliseconds keep the signed public count usable
// for long playlists; sub-millisecond precision is not claimed.
inline std::optional<RationalTime> playback_time(double seconds)noexcept {
    const auto milliseconds=seconds*1000.0;
    if(!std::isfinite(seconds)||seconds<0||
       milliseconds>static_cast<double>(std::numeric_limits<std::int32_t>::max()))return{};
    return RationalTime{static_cast<std::int32_t>(milliseconds),1000};
}
}
