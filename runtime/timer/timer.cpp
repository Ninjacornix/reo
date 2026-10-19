#include "timer.h"
#include <cstdio>

#ifdef REO_PLATFORM_WINDOWS
#include <windows.h>
#endif

namespace reo {

void Timer::init() {
#ifdef REO_PLATFORM_WINDOWS
    LARGE_INTEGER freq, now;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&now);
    m_freq = freq.QuadPart;
    m_start_ticks = now.QuadPart;
#endif
    printf("[TIMER] High-resolution timer: %llu Hz\n", (unsigned long long)m_freq);
}

uint64_t Timer::elapsed_us() const {
#ifdef REO_PLATFORM_WINDOWS
    LARGE_INTEGER now;
    QueryPerformanceCounter(&now);
    uint64_t elapsed = now.QuadPart - m_start_ticks;
    return (elapsed * 1000000ULL) / m_freq;
#else
    return 0;
#endif
}

uint64_t Timer::bus_clock_ticks() const {
    // PS2 bus clock: 147.456 MHz
    return (elapsed_us() * 147456ULL) / 1000000ULL;
}

uint64_t Timer::ee_clock_ticks() const {
    // PS2 EE clock: 294.912 MHz
    return (elapsed_us() * 294912ULL) / 1000000ULL;
}

void Timer::begin_frame() {
#ifdef REO_PLATFORM_WINDOWS
    LARGE_INTEGER now;
    QueryPerformanceCounter(&now);
    m_frame_start = now.QuadPart;
#endif
}

void Timer::end_frame() {
#ifdef REO_PLATFORM_WINDOWS
    LARGE_INTEGER now;
    QueryPerformanceCounter(&now);
    uint64_t frame_ticks = now.QuadPart - m_frame_start;
    m_frame_time_ms = (double)frame_ticks * 1000.0 / (double)m_freq;
    m_fps = (m_frame_time_ms > 0) ? 1000.0 / m_frame_time_ms : 0.0;
#endif
}

void Timer::wait_for_vsync(int target_fps) {
#ifdef REO_PLATFORM_WINDOWS
    double target_ms = 1000.0 / target_fps;
    LARGE_INTEGER now;

    // Spin-wait for precision (Sleep is too coarse)
    for (;;) {
        QueryPerformanceCounter(&now);
        uint64_t frame_ticks = now.QuadPart - m_frame_start;
        double elapsed_ms = (double)frame_ticks * 1000.0 / (double)m_freq;

        if (elapsed_ms >= target_ms)
            break;

        // Sleep for most of the remaining time to save CPU
        double remaining = target_ms - elapsed_ms;
        if (remaining > 2.0) {
            Sleep(1);
        }
    }
#endif
}

} // namespace reo
