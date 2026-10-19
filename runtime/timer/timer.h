#pragma once

#include <cstdint>

namespace reo {

/*
 * Timer System
 *
 * Replaces PS2 EE timer hardware and vsync timing.
 * The PS2 has 4 EE timers (16/32-bit counters) that games use
 * for timing, delays, and frame pacing.
 *
 * We use Windows QueryPerformanceCounter for high-resolution timing.
 */

class Timer {
  public:
    Timer() = default;

    void init();

    // Get elapsed microseconds since init
    uint64_t elapsed_us() const;

    // Get elapsed as PS2 bus clock ticks (~147.456 MHz)
    uint64_t bus_clock_ticks() const;

    // Get elapsed as EE clock ticks (~294.912 MHz)
    uint64_t ee_clock_ticks() const;

    // Frame timing
    void begin_frame();
    void end_frame();
    void wait_for_vsync(int target_fps = 60);

    double frame_time_ms() const {
        return m_frame_time_ms;
    }
    double fps() const {
        return m_fps;
    }

  private:
    uint64_t m_start_ticks = 0;
    uint64_t m_freq = 0;
    uint64_t m_frame_start = 0;
    double m_frame_time_ms = 0.0;
    double m_fps = 0.0;
};

} // namespace reo
