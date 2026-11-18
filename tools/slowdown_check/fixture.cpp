// Synthetic transport/monitor fixture. Contains no game data and does not
// simulate or claim to reproduce a real slowdown.
#include "../../runtime/diagnostics/slowdown_recorder.h"
#include "../../runtime/gs/frame_pacing.h"
#include <chrono>
#include <cstdio>
#include <thread>
#include <vector>
using namespace reo::slowdown;
int main(int argc, char** argv) {
    if (argc > 1 && std::strcmp(argv[1], "--no-recorder") == 0) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        return 0;
    }
    configure("synthetic-slowdown-fixture-v1");
    if (!active())
        return 2;
    if (argc > 1 && std::strcmp(argv[1], "--flood") == 0) {
        for (uint64_t n = 0; n < 200000; ++n)
            emit(2, n, n ^ 0x12345678, n + 7, n * 3, n * 5, 3);
        return 0;
    }
    if (argc > 1 && std::strcmp(argv[1], "--overflow") == 0) {
        // Full ring never blocks or overwrites. Nine lifetime producers exceed
        // the eight ring limit even if OS thread IDs happen to be reused.
        for (unsigned n = 0; n < 9; ++n) {
            std::thread worker([n] {
                for (unsigned i = 0; i < capacity + 10; ++i)
                    emit(2, n, i);
            });
            worker.join();
        }
        return 0;
    }
    capability(2);
    reo::performance::FrameTrace frames;
    const auto start = std::chrono::steady_clock::now();
    uint64_t tick = 0, counter = 0;
    while (std::chrono::steady_clock::now() - start < std::chrono::milliseconds(8500)) {
        // Original game fields: room=1, quantum=2, gameplay phase=2, cached room=1.
        emit(1, counter * 2, counter, 1ull | (2ull << 16) | (2ull << 24) | (1ull << 48));
        ++counter;
        {
            auto frame = frames.begin(++tick);
            frame.scanout();
            if (tick == 20)
                std::this_thread::sleep_for(std::chrono::milliseconds(180));
            frame.presented();
        }
        // 15 original updates per second: intentional synthetic slow clock.
        std::this_thread::sleep_for(std::chrono::milliseconds(66));
    }
    return 0;
}
