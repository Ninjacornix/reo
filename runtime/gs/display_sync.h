#pragma once
#include <cmath>
#include <cstdlib>
#include <cstring>

namespace reo::display_sync {
enum class Mode { On, Off, Adaptive };
inline Mode parse(const char* value) {
    if (value && std::strcmp(value, "off") == 0)
        return Mode::Off;
    if (value && std::strcmp(value, "adaptive") == 0)
        return Mode::Adaptive;
    return Mode::On;
}
inline Mode configured() {
    static const Mode mode = parse(std::getenv("REO_VSYNC"));
    return mode;
}
inline const char* name(Mode mode) {
    return mode == Mode::Off ? "off" : mode == Mode::Adaptive ? "adaptive" : "on";
}
inline int swapInterval(Mode mode, bool adaptiveSupported) {
    return mode == Mode::Off ? 0 : mode == Mode::Adaptive && adaptiveSupported ? -1 : 1;
}

// DXGI has no negative swap interval. Select interval 0 for a cadence below
// refresh and 1 otherwise. Hysteresis absorbs host scheduling jitter, including
// the original NTSC 59.94 Hz clock on a nominal 60 Hz display. No guest clocks,
// sleeps or simulation limits belong here.
class Adaptive {
    double previous_ = 0;
    bool havePrevious_ = false;
    bool synchronized_ = true;

  public:
    bool synchronized(Mode mode, double nowSeconds, double refreshHz) {
        const double elapsed = nowSeconds - previous_;
        const bool sample = havePrevious_ && elapsed > 0 && std::isfinite(elapsed);
        previous_ = nowSeconds;
        havePrevious_ = std::isfinite(nowSeconds);
        if (mode == Mode::Off)
            return false;
        if (mode == Mode::On || !std::isfinite(refreshHz) || refreshHz < 10 || !sample)
            return synchronized_ = true;
        const double threshold = synchronized_ ? 1.03 : 1.01;
        synchronized_ = elapsed * refreshHz <= threshold;
        return synchronized_;
    }
};
} // namespace reo::display_sync
