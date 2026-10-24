#pragma once
#include <algorithm>
#include <cstddef>

namespace reo::graphics {
inline bool warmupSampling(unsigned samples, bool ordered, bool dynamic, unsigned x, unsigned y) {
    if (dynamic || !ordered) return true;
    if (x == 0 && y == 0) return true; // UI and demoted passes still use Native.
    switch (samples) {
    case 1: return false;
    case 2: return x == 0 && y == 1;
    case 4: return x == 1 && y == 1;
    case 8: return x == 1 && y == 2;
    case 16: return x == 2 && y == 2;
    default: return true;
    }
}
inline std::size_t warmupWorkers(std::size_t tasks, unsigned hardwareThreads) {
    if (!tasks) return 0;
    return std::min(tasks, std::min(std::size_t(2), std::max(std::size_t(1), std::size_t(hardwareThreads / 2))));
}
struct WarmupRange { std::size_t begin, end; };
inline WarmupRange warmupRange(std::size_t tasks, std::size_t worker, std::size_t workers) {
    return {tasks * worker / workers, tasks * (worker + 1) / workers};
}
}
