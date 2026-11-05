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
} // namespace reo_gpu_present
