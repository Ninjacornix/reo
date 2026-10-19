// SPDX-License-Identifier: GPL-3.0-only
#pragma once

#include <chrono>
#include <cstdint>
#include <mutex>

namespace reo_network {
class EeCountClock {
  public:
    static constexpr uint64_t Frequency = 294912000;

    static constexpr uint32_t countAt(uint64_t nanoseconds) noexcept {
        return static_cast<uint32_t>((nanoseconds / 1000000000) * Frequency +
                                     (nanoseconds % 1000000000) * Frequency / 1000000000);
    }

    uint32_t read() const noexcept {
        const auto elapsed = std::chrono::steady_clock::now() - origin_;
        return countAt(static_cast<uint64_t>(
            std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count()));
    }

  private:
    const std::chrono::steady_clock::time_point origin_ = std::chrono::steady_clock::now();
};

class ElapsedSecondsClock {
  public:
    using Clock = std::chrono::steady_clock;

    float read(bool reset, float previousSeconds, Clock::time_point now = Clock::now()) {
        std::lock_guard lock(mutex_);
        if (reset || !initialized_) {
            origin_ = now;
            offset_ = previousSeconds;
            initialized_ = true;
        }
        return offset_ + std::chrono::duration<float>(now - origin_).count();
    }

  private:
    std::mutex mutex_;
    Clock::time_point origin_{};
    float offset_ = 0;
    bool initialized_ = false;
};
} // namespace reo_network
