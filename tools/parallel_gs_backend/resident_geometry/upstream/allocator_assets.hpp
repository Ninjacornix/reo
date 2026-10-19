#pragma once
#include "viewport_assets.hpp"
namespace reo_gpu_upstream {
inline void attachViewportAllocatorAsset(reo_gpu_palette_parent::Modules& modules,
                                         const std::filesystem::path& directory,
                                         bool explicitlyRequested = false) {
    if (!explicitlyRequested)
        return;
    if (!modules.viewportAllocator18DDD0.empty())
        throw std::invalid_argument("Allocator asset already attached");
    auto words = viewportAsset(directory / "allocator18ddd0_effects.spv",
                               "f5c89921eedb56b3874fa0493a6424d5bf09a7807cfb04bfed972cdc7e1f7e6c");
    modules.viewportAllocator18DDD0 = std::move(words);
    // Asset attachment changes no proof, route, readiness or source authority.
}
} // namespace reo_gpu_upstream
