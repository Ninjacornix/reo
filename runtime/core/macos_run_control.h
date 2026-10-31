#pragma once
#include <chrono>
#include <cmath>
#include <csignal>
#include <cstdlib>
#include <functional>
#include <fstream>
#include <string>
#include <thread>

namespace reo {
// Signals only set a signal-safe flag. A normal host thread requests the
// runtime's existing joined shutdown, preserving saves and diagnostic exports.
class ScopedMacRunControl {
    inline static volatile std::sig_atomic_t interrupted_ = 0;
    static void interrupt(int) { interrupted_ = 1; }
    using Handler = void (*)(int);
    Handler previousInt_, previousTerm_;
    std::jthread worker_;
public:
    explicit ScopedMacRunControl(std::function<void()> stop,
                                 std::function<void(const char*, const char*)> settings = {}) {
        interrupted_ = 0;
        previousInt_ = std::signal(SIGINT, interrupt);
        previousTerm_ = std::signal(SIGTERM, interrupt);
        double seconds = 0;
        if (const char* value = std::getenv("REO_MACOS_RUN_SECONDS")) {
            char* end = nullptr;
            const double parsed = std::strtod(value, &end);
            if (end != value && !*end && std::isfinite(parsed) && parsed > 0 && parsed <= 3600)
                seconds = parsed;
        }
        const char* live = std::getenv("REO_MACOS_LIVE_SETTINGS");
        const std::string livePath = live ? live : "";
        worker_ = std::jthread([stop = std::move(stop), settings = std::move(settings), livePath, seconds](std::stop_token token) {
            const auto start = std::chrono::steady_clock::now();
            unsigned polls = 0;
            while (!token.stop_requested()) {
                if (settings && !livePath.empty() && polls++ % 5 == 0) {
                    std::ifstream stream(livePath);
                    std::string audio, subtitles;
                    if (std::getline(stream, audio) && audio.size() <= 24 &&
                        std::getline(stream, subtitles) && subtitles.size() == 1)
                        settings(audio.c_str(), subtitles.c_str());
                }
                if (interrupted_ || (seconds > 0 &&
                    std::chrono::duration<double>(std::chrono::steady_clock::now() - start).count() >= seconds)) {
                    stop();
                    return;
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(50));
            }
        });
    }
    ~ScopedMacRunControl() {
        worker_.request_stop();
        worker_.join();
        std::signal(SIGINT, previousInt_);
        std::signal(SIGTERM, previousTerm_);
    }
};
}
