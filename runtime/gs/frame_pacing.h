#pragma once
// Bounded host-only timing, enabled only by an explicit diagnostic output path.
// Records stay in memory until the graphics owner has stopped; no per-frame IO.
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

namespace reo::performance {
class FrameTrace {
    struct Row { uint64_t tick, begin, scanout, presented, end; };
    std::string path_;
    std::vector<Row> rows_;
    uint64_t dropped_ = 0;
    static uint64_t now() {
        return uint64_t(std::chrono::duration_cast<std::chrono::nanoseconds>(
            std::chrono::steady_clock::now().time_since_epoch()).count());
    }
public:
    FrameTrace() {
        const char* path = std::getenv("REO_FRAME_PACING_FILE");
        if (path && *path) { path_ = path; rows_.reserve(32768); }
    }
    ~FrameTrace() {
        if (path_.empty()) return;
        auto* f = std::fopen(path_.c_str(), "wb");
        if (!f) return;
        std::fprintf(f, "# dropped=%llu\ntick,begin_ns,scanout_ns,present_ns,end_ns\n",
                     static_cast<unsigned long long>(dropped_));
        for (const auto& r : rows_)
            std::fprintf(f, "%llu,%llu,%llu,%llu,%llu\n",
                static_cast<unsigned long long>(r.tick), static_cast<unsigned long long>(r.begin),
                static_cast<unsigned long long>(r.scanout), static_cast<unsigned long long>(r.presented),
                static_cast<unsigned long long>(r.end));
        std::fclose(f);
    }
    class Span {
        FrameTrace& trace_;
        Row row_{};
    public:
        Span(FrameTrace& trace, uint64_t tick) : trace_(trace) {
            if (!trace_.path_.empty()) { row_.tick = tick; row_.begin = now(); }
        }
        void scanout() { if (row_.begin) row_.scanout = now(); }
        void presented() { if (row_.begin) row_.presented = now(); }
        ~Span() {
            if (!row_.begin) return;
            row_.end = now();
            if (trace_.rows_.size() < 32768) trace_.rows_.push_back(row_);
            else ++trace_.dropped_;
        }
    };
    Span begin(uint64_t tick) { return Span(*this, tick); }
};
}
