#pragma once
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <cstring>

namespace reo::performance {
inline bool enabled() {
    static const bool value = [] {
        const char* option = std::getenv("REO_PERFORMANCE_OVERLAY");
        return option && std::strcmp(option, "1") == 0;
    }();
    return value;
}
inline std::atomic<uint64_t> updates{0};
// Modern camera crosshair, drawn by the present shader (bit 30 of the fps push word).
// Steady-clock milliseconds of the last camera frame that wanted it; the presenter
// draws it only while that is recent, so menus and cutscenes never keep it.
inline std::atomic<int64_t> crosshair_ms{0};
inline int64_t steady_ms() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::steady_clock::now().time_since_epoch()).count();
}
inline void request_crosshair(bool wanted) { crosshair_ms.store(wanted ? steady_ms() : 0); }
inline bool crosshair_visible() {
    const auto at = crosshair_ms.load(std::memory_order_relaxed);
    return at != 0 && steady_ms() - at < 100;
}

// Actor callbacks run more than once per game frame. Count the original room
// frame once, including wrap/reset, rather than counting every player and AI.
class UpdateTracker {
    uint32_t previous_ = 0;
    bool initialized_ = false;
public:
    bool observe(uint32_t frame) {
        if (initialized_ && frame == previous_) return false;
        previous_ = frame; initialized_ = true;
        return true;
    }
};
struct Reading {
    uint32_t fps = 0, frameMs = 0, ups = 0; // Tenths; zero is a real measured rate.
};
class Meter {
    bool initialized_ = false;
    uint64_t startNs_ = 0, startFrames_ = 0, startUpdates_ = 0;
    Reading reading_{};
    static uint32_t tenths(double value) {
        return uint32_t(std::lround(value > 9999.9 ? 99999.0 : value * 10.0));
    }
public:
    Reading sample(uint64_t nowNs, uint64_t frames, uint64_t gameUpdates) {
        if (!initialized_) {
            initialized_ = true; startNs_ = nowNs;
            startFrames_ = frames; startUpdates_ = gameUpdates;
        } else if (nowNs - startNs_ >= 1000000000ull) {
            const double seconds = double(nowNs - startNs_) * 1e-9;
            const auto count = frames - startFrames_;
            reading_.fps = tenths(double(count) / seconds);
            reading_.frameMs = count ? tenths(seconds * 1000.0 / double(count)) : 0;
            reading_.ups = tenths(double(gameUpdates - startUpdates_) / seconds);
            startNs_ = nowNs; startFrames_ = frames; startUpdates_ = gameUpdates;
        }
        return reading_;
    }
};
}
