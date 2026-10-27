#pragma once
#include <atomic>
#include <cstdint>

// Movie pictures produced by the GPU movie route. With the widescreen camera on, the
// presenter shows movies at 4:3 while this (or the CPU route's IPU colour conversion
// count) keeps moving; 2D movies are not widened by the camera.
namespace reo_gpu_present {
inline std::atomic<uint64_t> gpuMovieFrames{0};
} // namespace reo_gpu_present
