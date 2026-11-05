#pragma once
// Optional CPU elapsed timing on the serialized actual movie/GS owner only.
// No synchronization, allocation, IO, GPU query, or new wait on the record path.
// Durations include descheduling; they never identify a CPU/GPU bottleneck.
#include <array>
#include <cerrno>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <limits>

namespace reo::movie_timing {
enum class Boundary : unsigned {
    OwnerControl, Decode, Output, ReleasePartialFence, BatchFence, UploadFence, Count
};
inline const char* name(Boundary boundary) noexcept {
    constexpr const char* names[] = {"owner_control", "decode", "output",
        "release_partial_fence", "batch_fence", "upload_fence"};
    const auto index = static_cast<unsigned>(boundary);
    return index < static_cast<unsigned>(Boundary::Count) ? names[index] : "invalid";
}
inline uint64_t now() noexcept {
    return uint64_t(std::chrono::duration_cast<std::chrono::nanoseconds>(
        std::chrono::steady_clock::now().time_since_epoch()).count());
}
struct Aggregate {
    uint64_t calls = 0, elapsedSum = 0, elapsedMax = 0, slowCalls = 0;
};
struct Event {
    Boundary boundary{};
    uint64_t generation = 0, serial = 0, begin = 0, end = 0;
};
// Export-only injection for deterministic open/write/flush/close failure checks.
struct FileIo {
    std::FILE* (*open)(const char*, const char*) = std::fopen;
    int (*flush)(std::FILE*) = std::fflush;
    int (*close)(std::FILE*) = std::fclose;
};
class Recorder {
  public:
    static constexpr size_t Capacity = 4096;
    static constexpr uint64_t SlowThresholdNs = 2'000'000;
    using Clock = uint64_t (*)() noexcept;

  private:
    std::array<char, 4096> path_{};
    std::array<Event, Capacity> events_{};
    std::array<Aggregate, static_cast<unsigned>(Boundary::Count)> aggregates_{};
    size_t retained_ = 0;
    uint64_t epoch_ = 0, ownerBegin_ = 0, dropped_ = 0, invalid_ = 0;
    bool saturated_ = false, enabled_ = false, exported_ = false, exportOkay_ = false;
    Clock clock_ = now;
    uint64_t add(uint64_t a, uint64_t b) noexcept {
        if (b > std::numeric_limits<uint64_t>::max() - a) {
            saturated_ = true;
            return std::numeric_limits<uint64_t>::max();
        }
        return a + b;
    }

  public:
    // Passing an explicit path/clock supports isolated deterministic tests.
    // Production reads the opt-in environment once at owner construction.
    explicit Recorder(uint64_t epoch, const char* path = std::getenv("REO_MOVIE_TIMING_FILE"),
                      Clock clock = now) noexcept : epoch_(epoch), clock_(clock ? clock : now) {
        if (!path || !*path)
            return;
        size_t count = 0;
        while (count < path_.size() && path[count])
            ++count;
        if (count == path_.size()) {
            std::fputs("[MOVIE-TIMING] unavailable: output path exceeds4095 bytes\n", stderr);
            return;
        }
        for (size_t i = 0; i < count; ++i)
            path_[i] = path[i];
        enabled_ = true;
        ownerBegin_ = clock_();
    }
    Recorder(const Recorder&) = delete;
    Recorder& operator=(const Recorder&) = delete;
    bool enabled() const noexcept { return enabled_ && !exported_; }
    uint64_t clock() const noexcept { return clock_(); }
    const Aggregate& aggregate(Boundary boundary) const noexcept {
        return aggregates_[static_cast<unsigned>(boundary)];
    }
    size_t retained() const noexcept { return retained_; }
    uint64_t dropped() const noexcept { return dropped_; }
    uint64_t invalid() const noexcept { return invalid_; }
    bool saturated() const noexcept { return saturated_; }
    void observe(Boundary boundary, uint64_t begin, uint64_t end,
                 uint64_t generation = 0, uint64_t serial = 0) noexcept {
        if (!enabled())
            return;
        const auto index = static_cast<unsigned>(boundary);
        if (index >= aggregates_.size() || end < begin) {
            invalid_ = add(invalid_, 1);
            return;
        }
        auto& aggregate = aggregates_[index];
        const auto elapsed = end - begin;
        aggregate.calls = add(aggregate.calls, 1);
        aggregate.elapsedSum = add(aggregate.elapsedSum, elapsed);
        if (elapsed > aggregate.elapsedMax)
            aggregate.elapsedMax = elapsed;
        if (elapsed < SlowThresholdNs)
            return;
        aggregate.slowCalls = add(aggregate.slowCalls, 1);
        if (retained_ == events_.size()) {
            dropped_ = add(dropped_, 1);
            return;
        }
        events_[retained_++] = {boundary, generation, serial, begin, end};
    }
    // Call once after this owner has stopped/cancelled all movie work. This is
    // teardown IO, never a producer/poll path. Append preserves earlier epochs.
    // Concurrent owners sharing one path are not admitted; caller owns path.
    bool exportAfterOwnerStop(const FileIo& io = {}) noexcept {
        if (!enabled_)
            return true;
        if (exported_)
            return exportOkay_;
        exported_ = true;
        auto* file = io.open(path_.data(), "ab");
        if (!file) {
            std::fprintf(stderr, "[MOVIE-TIMING] export failed: open errno=%d path=%s\n",
                         errno, path_.data());
            return false;
        }
        bool okay = true;
        auto emit = [&](const char* format, auto... args) noexcept {
            if (!okay)
                return;
            int result;
            if constexpr (sizeof...(args) == 0)
                result = std::fputs(format, file);
            else
                result = std::fprintf(file, format, args...);
            if (result < 0)
                okay = false;
        };
        emit("\n# reo_movie_timing_schema=1\n# owner_begin_ns=%llu\n# epoch=%llu\n",
             static_cast<unsigned long long>(ownerBegin_), static_cast<unsigned long long>(epoch_));
        emit("# slow_threshold_ns=%llu\n# event_capacity=%zu\n# elapsed_includes_descheduling=1\n",
             static_cast<unsigned long long>(SlowThresholdNs), Capacity);
        emit("# dropped_slow_events=%llu\n# invalid_intervals=%llu\n# aggregates_saturated=%u\n",
             static_cast<unsigned long long>(dropped_), static_cast<unsigned long long>(invalid_),
             unsigned(saturated_));
        emit("# aggregate,boundary,calls,elapsed_sum_ns,elapsed_max_ns,slow_calls\n");
        for (unsigned i = 0; i < aggregates_.size(); ++i) {
            const auto& value = aggregates_[i];
            emit("# aggregate,%s,%llu,%llu,%llu,%llu\n", name(static_cast<Boundary>(i)),
                 static_cast<unsigned long long>(value.calls),
                 static_cast<unsigned long long>(value.elapsedSum),
                 static_cast<unsigned long long>(value.elapsedMax),
                 static_cast<unsigned long long>(value.slowCalls));
        }
        emit("boundary,generation,serial,begin_ns,end_ns,elapsed_ns\n");
        for (size_t i = 0; i < retained_; ++i) {
            const auto& event = events_[i];
            emit("%s,%llu,%llu,%llu,%llu,%llu\n", name(event.boundary),
                 static_cast<unsigned long long>(event.generation),
                 static_cast<unsigned long long>(event.serial),
                 static_cast<unsigned long long>(event.begin),
                 static_cast<unsigned long long>(event.end),
                 static_cast<unsigned long long>(event.end - event.begin));
        }
        // A missing trailer means partial/truncated, even if some rows parse.
        emit("# owner_complete=1 retained=%zu\n", retained_);
        okay = (std::ferror(file) == 0) && okay;
        if (io.flush(file) != 0)
            okay = false;
        if (io.close(file) != 0)
            okay = false;
        if (!okay) {
            std::fprintf(stderr, "[MOVIE-TIMING] export failed: write/flush/close; partial output possible path=%s\n",
                         path_.data());
            return false;
        }
        std::fprintf(stderr, "[MOVIE-TIMING] exported owner epoch=%llu retained=%zu dropped=%llu invalid=%llu saturated=%u path=%s\n",
                     static_cast<unsigned long long>(epoch_), retained_,
                     static_cast<unsigned long long>(dropped_), static_cast<unsigned long long>(invalid_),
                     unsigned(saturated_), path_.data());
        exportOkay_ = true;
        return true;
    }
};
class Span {
    Recorder* recorder_ = nullptr;
    Boundary boundary_{};
    uint64_t begin_ = 0, generation_ = 0, serial_ = 0;
  public:
    Span(Recorder* recorder, Boundary boundary, uint64_t generation = 0,
         uint64_t serial = 0) noexcept
        : recorder_(recorder && recorder->enabled() ? recorder : nullptr), boundary_(boundary),
          generation_(generation), serial_(serial) {
        if (recorder_)
            begin_ = recorder_->clock();
    }
    Span(const Span&) = delete;
    Span& operator=(const Span&) = delete;
    ~Span() {
        if (recorder_)
            recorder_->observe(boundary_, begin_, recorder_->clock(), generation_, serial_);
    }
};
} // namespace reo::movie_timing
