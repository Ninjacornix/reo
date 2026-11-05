#pragma once
// Optional CPU elapsed timing on the serialized actual movie/GS owner only.
// No synchronization, allocation, IO, GPU query, or new wait on the record path.
// Durations include descheduling; they never identify a CPU/GPU bottleneck.
#include <array>
#include <algorithm>
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
    uint64_t sequence = 0, generation = 0, serial = 0, begin = 0, end = 0;
};
struct SequenceCounter {
    uint64_t value = 0;
    bool saturated = false;
    bool advance() noexcept {
        if (value == std::numeric_limits<uint64_t>::max()) {
            saturated = true;
            return false;
        }
        ++value;
        return true;
    }
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
    static constexpr size_t LongestCapacity = 64;
    static constexpr uint64_t SlowThresholdNs = 2'000'000;
    using Clock = uint64_t (*)() noexcept;

  private:
    std::array<char, 4096> path_{};
    std::array<Event, Capacity> recent_{};
    std::array<Event, LongestCapacity> longest_{};
    std::array<Aggregate, static_cast<unsigned>(Boundary::Count)> aggregates_{};
    size_t recentCount_ = 0, recentNext_ = 0, longestCount_ = 0, worst_ = 0;
    SequenceCounter slow_{};
    uint64_t epoch_ = 0, ownerBegin_ = 0, invalid_ = 0;
    bool saturated_ = false, enabled_ = false, exported_ = false, exportOkay_ = false;
    Clock clock_ = now;
    uint64_t add(uint64_t a, uint64_t b) noexcept {
        if (b > std::numeric_limits<uint64_t>::max() - a) {
            saturated_ = true;
            return std::numeric_limits<uint64_t>::max();
        }
        return a + b;
    }
    const Event& recent(size_t index) const noexcept {
        return recent_[(recentNext_ + Capacity - recentCount_ + index) % Capacity];
    }
    static bool better(const Event& a, const Event& b) noexcept {
        const auto left = a.end - a.begin, right = b.end - b.begin;
        return left > right || (left == right && a.sequence < b.sequence);
    }
    void longest(const Event& event) noexcept {
        if (longestCount_ < LongestCapacity)
            longest_[longestCount_++] = event;
        else if (better(event, longest_[worst_]))
            longest_[worst_] = event;
        else
            return;
        worst_ = 0;
        for (size_t i = 1; i < longestCount_; ++i)
            if (better(longest_[worst_], longest_[i]))
                worst_ = i;
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
    size_t recentRetained() const noexcept { return recentCount_; }
    size_t longestRetained() const noexcept { return longestCount_; }
    uint64_t slowEventsSeen() const noexcept { return slow_.value; }
    bool missingCountExact() const noexcept { return !slow_.saturated; }
    size_t retained() const noexcept {
        auto unique = recentCount_;
        for (size_t i = 0; i < longestCount_; ++i)
            if (!recentCount_ || longest_[i].sequence < recent(0).sequence ||
                longest_[i].sequence > recent(recentCount_ - 1).sequence)
                ++unique;
        return unique;
    }
    // UINT64_MAX is an explicitly flagged unknown sentinel after sequence
    // exhaustion, not a claim that exactly that many records are missing.
    uint64_t dropped() const noexcept {
        return missingCountExact() ? slow_.value - retained() : std::numeric_limits<uint64_t>::max();
    }
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
        if (!slow_.advance()) {
            saturated_ = true;
            return;
        }
        const Event event{boundary, slow_.value, generation, serial, begin, end};
        recent_[recentNext_] = event;
        recentNext_ = (recentNext_ + 1) % Capacity;
        if (recentCount_ < Capacity)
            ++recentCount_;
        longest(event);
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
        const auto retained = this->retained();
        const auto missing = dropped();
        emit("\n# reo_movie_timing_schema=2\n# owner_begin_ns=%llu\n# epoch=%llu\n",
             static_cast<unsigned long long>(ownerBegin_), static_cast<unsigned long long>(epoch_));
        emit("# slow_threshold_ns=%llu\n# event_capacity=%zu\n# elapsed_includes_descheduling=1\n",
             static_cast<unsigned long long>(SlowThresholdNs), Capacity + LongestCapacity);
        emit("# recent_capacity=%zu\n# longest_capacity=%zu\n# slow_events_seen=%llu\n",
             Capacity, LongestCapacity, static_cast<unsigned long long>(slow_.value));
        emit("# retained_recent=%zu\n# retained_longest=%zu\n# retained_unique=%zu\n",
             recentCount_, longestCount_, retained);
        emit("# missing_count_exact=%u\n# sequence_saturated=%u\n",
             unsigned(missingCountExact()), unsigned(slow_.saturated));
        emit("# dropped_slow_events=%llu\n# invalid_intervals=%llu\n# aggregates_saturated=%u\n",
             static_cast<unsigned long long>(missing), static_cast<unsigned long long>(invalid_),
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
        emit("sequence,retention,boundary,generation,serial,begin_ns,end_ns,elapsed_ns\n");
        auto top = longest_;
        std::sort(top.begin(), top.begin() + longestCount_, [](const Event& a, const Event& b) {
            return a.sequence < b.sequence;
        });
        auto row = [&](const Event& event, const char* retention) noexcept {
            emit("%llu,%s,%s,%llu,%llu,%llu,%llu,%llu\n",
                 static_cast<unsigned long long>(event.sequence), retention, name(event.boundary),
                 static_cast<unsigned long long>(event.generation),
                 static_cast<unsigned long long>(event.serial),
                 static_cast<unsigned long long>(event.begin),
                 static_cast<unsigned long long>(event.end),
                 static_cast<unsigned long long>(event.end - event.begin));
        };
        size_t i = 0, j = 0;
        while (i < recentCount_ || j < longestCount_) {
            if (j == longestCount_ || (i < recentCount_ && recent(i).sequence < top[j].sequence))
                row(recent(i++), "recent");
            else if (i == recentCount_ || top[j].sequence < recent(i).sequence)
                row(top[j++], "longest");
            else {
                row(recent(i++), "recent+longest");
                ++j;
            }
        }
        // A missing trailer means partial/truncated, even if some rows parse.
        emit("# owner_complete=1 retained=%zu\n", retained);
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
                     static_cast<unsigned long long>(epoch_), retained,
                     static_cast<unsigned long long>(missing), static_cast<unsigned long long>(invalid_),
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
