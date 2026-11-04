#pragma once
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <stdexcept>

namespace reo::message_timing {
inline constexpr const char* capability = "[MOD-EXAMINE-TIME-1] multiplier";
inline unsigned scale = 1000;
inline unsigned parseScale(const char* text) {
    if (!text) return 1000;
    unsigned value = 0, length = 0;
    for (const char* p = text; *p; ++p) {
        if (*p < '0' || *p > '9' || ++length > 5)
            throw std::runtime_error("Invalid examine-message time scale");
        value = value * 10 + unsigned(*p - '0');
    }
    if (!length || value < 1000 || value > 10000)
        throw std::runtime_error("Examine-message time scale must be 1000 to 10000");
    return value;
}
inline uint16_t duration(unsigned ticks) {
    if (!ticks || ticks > 32767) return static_cast<uint16_t>(ticks);
    const unsigned extended = (ticks * scale + 999) / 1000;
    return static_cast<uint16_t>(extended > 32767 ? 32767 : extended);
}
inline void initialize() {
    const char* configured = std::getenv("REO_MOD_EXAMINE_TIME_SCALE");
    scale = parseScale(configured);
    if (configured) std::fprintf(stderr, "%s scale=%u\n", capability, scale);
}
}
