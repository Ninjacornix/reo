#include "runtime/media/movie_timing.h"
#include <cassert>
#include <cstdlib>
#include <new>
#include <stdexcept>
#include <string>

static bool forbidAllocation = false;
void* operator new(std::size_t size) {
    if (forbidAllocation) std::abort();
    if (auto* value = std::malloc(size ? size : 1)) return value;
    throw std::bad_alloc();
}
void operator delete(void* value) noexcept { std::free(value); }
void operator delete(void* value, std::size_t) noexcept { std::free(value); }
static uint64_t tick = 100, clocks = 0;
static uint64_t clockNow() noexcept { ++clocks; return tick; }
static int failFlush(std::FILE* file) { std::fflush(file); return EOF; }
static int failClose(std::FILE* file) { std::fclose(file); return EOF; }
static std::FILE* readOnly(const char* path, const char*) { return std::fopen(path, "rb"); }

int main(int argc, char** argv) {
    using namespace reo::movie_timing;
    assert(argc == 3);
    const std::string path = argv[1], badPath = argv[2];
    {
        Recorder disabled(1, nullptr, clockNow);
        Span span(&disabled, Boundary::OwnerControl);
        disabled.observe(Boundary::Decode, 0, 9000000);
        assert(!disabled.enabled() && disabled.retained() == 0 && clocks == 0);
        assert(disabled.exportAfterOwnerStop());
        Recorder empty(1, "", clockNow);
        Span emptySpan(&empty, Boundary::Output);
        assert(!empty.enabled() && clocks == 0);
    }
    {
        Recorder recorder(7, path.c_str(), clockNow);
        assert(recorder.enabled() && clocks == 1);
        forbidAllocation = true;
        recorder.observe(Boundary::Decode, 100, 101, 8, 9);
        recorder.observe(Boundary::Decode, 100, 2000100, 8, 10);
        recorder.observe(Boundary::Decode, 100, 99);
        recorder.observe(Boundary::Count, 100, 101);
        {
            Span span(&recorder, Boundary::Output, 11, 12);
            tick += 3000000;
        }
        forbidAllocation = false;
        assert(recorder.aggregate(Boundary::Decode).calls == 2);
        assert(recorder.aggregate(Boundary::Decode).elapsedSum == 2000001);
        assert(recorder.aggregate(Boundary::Decode).elapsedMax == 2000000);
        assert(recorder.aggregate(Boundary::Decode).slowCalls == 1);
        assert(recorder.retained() == 2 && recorder.invalid() == 2);
        // No IO has occurred before explicit teardown export.
        auto* before = std::fopen(path.c_str(), "rb");
        assert(!before);
        assert(recorder.exportAfterOwnerStop());
        assert(!recorder.enabled());
        recorder.observe(Boundary::Decode, 0, 9000000);
        assert(recorder.aggregate(Boundary::Decode).calls == 2);
        assert(recorder.exportAfterOwnerStop()); // no duplicate section
    }
    {
        SequenceCounter counter{UINT64_MAX - 1, false};
        assert(counter.advance() && counter.value == UINT64_MAX && !counter.saturated);
        assert(!counter.advance() && counter.value == UINT64_MAX && counter.saturated);
        assert(!counter.advance());
    }
    {
        tick = 100;
        Recorder recorder(8, path.c_str(), clockNow);
        forbidAllocation = true;
        constexpr auto count = Recorder::Capacity + 100;
        for (size_t i = 0; i < count; ++i) {
            const auto end = 1'000'000'000ull + i * 10'000'000ull;
            const auto elapsed = i == 0 ? 50'000'000ull : i + 1 == count ? 7'000'000ull : 2'000'000ull;
            recorder.observe(i + 1 == count ? Boundary::OwnerControl : Boundary::BatchFence,
                             end - elapsed, end, 13, i);
        }
        assert(recorder.recentRetained() == Recorder::Capacity);
        assert(recorder.longestRetained() == Recorder::LongestCapacity);
        assert(recorder.retained() == Recorder::Capacity + Recorder::LongestCapacity - 1);
        assert(recorder.dropped() == 37 && recorder.slowEventsSeen() == count);
        recorder.observe(Boundary::UploadFence, 100, UINT64_MAX);
        recorder.observe(Boundary::UploadFence, 100, UINT64_MAX);
        forbidAllocation = false;
        assert(recorder.saturated());
        assert(recorder.aggregate(Boundary::UploadFence).elapsedSum == UINT64_MAX);
        // Sum saturation does not make the independent sequence/loss count unknown.
        assert(recorder.missingCountExact() && recorder.dropped() == 41);
        assert(recorder.retained() == 4157);
        assert(recorder.exportAfterOwnerStop());
    }
    {
        Recorder recorder(9, badPath.c_str(), clockNow);
        assert(!recorder.exportAfterOwnerStop());
        assert(!recorder.exportAfterOwnerStop()); // failure remains failure
    }
    {
        Recorder recorder(10, path.c_str(), clockNow);
        FileIo io;
        io.flush = failFlush;
        assert(!recorder.exportAfterOwnerStop(io));
    }
    {
        Recorder recorder(11, path.c_str(), clockNow);
        FileIo io;
        io.close = failClose;
        assert(!recorder.exportAfterOwnerStop(io));
    }
    {
        Recorder recorder(12, path.c_str(), clockNow);
        FileIo io;
        io.open = readOnly;
        assert(!recorder.exportAfterOwnerStop(io));
    }
    {
        Recorder recorder(13, path.c_str(), clockNow);
        try {
            Span span(&recorder, Boundary::OwnerControl, 17, 19);
            tick += 4000000;
            throw 1;
        } catch (int) {}
        assert(recorder.aggregate(Boundary::OwnerControl).calls == 1);
        assert(recorder.aggregate(Boundary::OwnerControl).elapsedSum == 4000000);
        assert(recorder.exportAfterOwnerStop());
    }
    std::puts("movie timing deterministic checks passed");
}
