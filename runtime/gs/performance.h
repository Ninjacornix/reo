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
// Start at the main menu (REO_SKIP_INTRO=1). The boot logos run fast (REO_TURBO until
// the front menu exists) and the title is confirmed automatically (reo_hw_bridge.cpp);
// meanwhile the screen stays black and audio is muted. A 30 s limit shows the game
// normally if the boot waits for input (e.g. a memory card prompt).
inline bool skip_intro() {
    static const bool value = [] {
        const char* v = std::getenv("REO_SKIP_INTRO");
        return v && std::strcmp(v, "1") == 0;
    }();
    return value;
}
inline std::atomic<bool> intro_finished{false};
inline bool intro_hidden() {
    if (!skip_intro() || intro_finished.load(std::memory_order_relaxed)) return false;
    using clock = std::chrono::steady_clock;
    static const clock::time_point started = clock::now();
    if (clock::now() - started > std::chrono::seconds(30)) { intro_finished.store(true); return false; }
    return true;
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
