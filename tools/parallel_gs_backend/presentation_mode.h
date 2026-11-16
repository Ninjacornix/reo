#pragma once
#include "runtime/gs/display_sync.h"
#include <vulkan/vulkan.h>
#include <algorithm>
#include <cstdio>
#include <vector>

namespace reo_gpu_present {
inline VkPresentModeKHR selectPresentMode(reo::display_sync::Mode mode,
                                          const std::vector<VkPresentModeKHR>& available) {
    const auto has = [&](VkPresentModeKHR candidate) {
        return std::find(available.begin(), available.end(), candidate) != available.end();
    };
    if (mode == reo::display_sync::Mode::Off) {
        if (has(VK_PRESENT_MODE_IMMEDIATE_KHR))
            return VK_PRESENT_MODE_IMMEDIATE_KHR;
        if (has(VK_PRESENT_MODE_MAILBOX_KHR))
            return VK_PRESENT_MODE_MAILBOX_KHR;
    }
    if (mode == reo::display_sync::Mode::Adaptive && has(VK_PRESENT_MODE_FIFO_RELAXED_KHR))
        return VK_PRESENT_MODE_FIFO_RELAXED_KHR;
    return VK_PRESENT_MODE_FIFO_KHR;
}
inline VkPresentModeKHR configuredPresentMode(const std::vector<VkPresentModeKHR>& available) {
    const auto mode = reo::display_sync::configured();
    const auto selected = selectPresentMode(mode, available);
    std::fprintf(stderr, "[DISPLAY-SYNC] Vulkan requested=%s present-mode=%d\n",
                 reo::display_sync::name(mode), int(selected));
    return selected;
}
// Granite's DXGIInteropSwapchain requires importing a D3D12 timeline fence
// (handle type 0x8) and a shared D3D12 render target (handle type 0x40) into
// Vulkan. Some Windows Vulkan drivers (e.g. Intel Iris Xe 0.404.1994, #104)
// support Vulkan 1.3 and VK_KHR_win32_surface/VK_KHR_swapchain but not D3D12
// external handle import, and Granite's init_interop_device returns EXIT_FAILURE
// (1 -> true) when timeline fence creation fails. Pre-check both capabilities.
inline constexpr bool supportsDxgiExternalHandles(
    bool deviceLuidValid, bool supportsExternal, bool timelineSemaphore,
    VkExternalSemaphoreFeatureFlags d3d12FenceFeatures, bool d3d12ImageFormatSupported,
    VkExternalMemoryFeatureFlags d3d12ResourceMemoryFeatures) noexcept {
    return deviceLuidValid && supportsExternal && timelineSemaphore &&
           (d3d12FenceFeatures & VK_EXTERNAL_SEMAPHORE_FEATURE_IMPORTABLE_BIT) != 0 &&
           d3d12ImageFormatSupported &&
           (d3d12ResourceMemoryFeatures & VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT) != 0;
}
} // namespace reo_gpu_present
