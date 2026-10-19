#pragma once
#include <array>
#include <chrono>
#include <cstdio>
#include <cstdlib>

// Default-off, bounded host wall times. Nested scopes overlap; these are not
// GPU timestamps and must not be summed into a claimed frame time.
namespace reo_resident_live::owner_timing {
enum Stage {
    Enqueue,
    Allocate,
    Record,
    DrawSubmit,
    Retire,
    Guard,
    Import,
    Export,
    CompletionSubmit,
    FenceWait,
    UploadSubmit,
    StageCount
};
inline constexpr const char* names[] = {
    "enqueue", "allocate", "record",           "drawSubmit", "retire",      "guard",
    "import",  "export",   "completionSubmit", "fenceWait",  "uploadSubmit"};
using Clock = std::chrono::steady_clock;
struct Counters {
    bool enabled =
        std::getenv("REO_GPU_OWNER_TIMING") && std::atoi(std::getenv("REO_GPU_OWNER_TIMING")) != 0;
    double from = std::getenv("REO_GPU_OWNER_TIMING_FROM")
                      ? std::atof(std::getenv("REO_GPU_OWNER_TIMING_FROM"))
                      : 0;
    double until = std::getenv("REO_GPU_OWNER_TIMING_UNTIL")
                       ? std::atof(std::getenv("REO_GPU_OWNER_TIMING_UNTIL"))
                       : 180;
    Clock::time_point epoch = Clock::now(), last = epoch;
    unsigned reports = 0;
    std::array<unsigned long long, StageCount> ns{}, count{};
    std::array<unsigned long long, 4> routes{};
    std::array<unsigned long long, 5> retireReasons{};
    std::array<unsigned long long, 3> retireKinds{};
};
inline thread_local Counters counters;
struct Scope {
    Stage stage;
    bool active = false;
    Clock::time_point begin;
    explicit Scope(Stage s) : stage(s) {
        if (!counters.enabled || counters.reports >= 24)
            return;
        begin = Clock::now();
        const double elapsed = std::chrono::duration<double>(begin - counters.epoch).count();
        active = elapsed >= counters.from && elapsed <= counters.until;
    }
    ~Scope() {
        if (!active)
            return;
        const auto end = Clock::now();
        counters.ns[stage] +=
            std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
        ++counters.count[stage];
        if (stage != Retire || end - counters.last < std::chrono::seconds(1))
            return;
        std::fprintf(stderr, "[GPU-OWNER-TIMING] elapsed=%.6f interval_ms=%.3f scopes_overlap=1",
                     std::chrono::duration<double>(end - counters.epoch).count(),
                     std::chrono::duration<double, std::milli>(end - counters.last).count());
        for (unsigned i = 0; i < StageCount; ++i)
            std::fprintf(stderr, " %s_n=%llu %s_us=%llu", names[i], counters.count[i], names[i],
                         counters.ns[i] / 1000);
        std::fprintf(stderr,
                     " retire_dma=%llu retire_flush=%llu retire_read=%llu retire_reset=%llu "
                     "retire_stop=%llu clean_empty=%llu dirty_empty=%llu with_jobs=%llu",
                     counters.retireReasons[0], counters.retireReasons[1],
                     counters.retireReasons[2], counters.retireReasons[3],
                     counters.retireReasons[4], counters.retireKinds[0], counters.retireKinds[1],
                     counters.retireKinds[2]);
        counters.retireReasons = {};
        counters.retireKinds = {};
        std::fprintf(
            stderr, " route_unknown=%llu route_fast=%llu route_completeC=%llu route_prefix=%llu\n",
            counters.routes[0], counters.routes[1], counters.routes[2], counters.routes[3]);
        counters.routes = {};
        counters.ns = {};
        counters.count = {};
        counters.last = end;
        ++counters.reports;
    }
};
} // namespace reo_resident_live::owner_timing
