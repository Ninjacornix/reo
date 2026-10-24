#pragma once
#include "device.hpp"
#include "command_buffer.hpp"
#include "smaa/resident_smaa.hpp"
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <limits>
#include <memory>
#include <stdexcept>
#include <vector>

// Keep Xlib's global macros out of the runtime and Vulkan/GS C++ interfaces.
struct _XDisplay;
extern "C" _XDisplay* XOpenDisplay(const char*);
extern "C" int XCloseDisplay(_XDisplay*);

namespace reo_gpu_present {
class ResidentXlibPresenter {
    Vulkan::Device& device_;
    _XDisplay* display_ = nullptr;
    VkSurfaceKHR surface_ = VK_NULL_HANDLE;
    VkSwapchainKHR swapchain_ = VK_NULL_HANDLE;
    uintptr_t window_ = 0;
    unsigned width_ = 0, height_ = 0, requestedWidth_ = 0, requestedHeight_ = 0;
    bool outdated_ = false;
    uint64_t submitted_ = 0;
    Vulkan::Program* program_ = nullptr;
    std::unique_ptr<ResidentSmaa> smaa_;
    std::vector<Vulkan::ImageHandle> images_;
    std::vector<Vulkan::ImageViewHandle> views_;
    std::vector<Vulkan::Semaphore> presented_;
    Vulkan::ImageHandle heldSource_;
    struct Parameters {
        uint32_t sourceWidth, sourceHeight, destinationWidth, destinationHeight, flags;
        // Match the shared final-pass shader ABI. The Windows launcher supplies
        // overlay readings; this reference presenter keeps the overlay off.
        uint32_t fps = 0, frameMs = 0, ups = 0;
    };
    static uint32_t layoutFlags() {
        const char* aspect = std::getenv("REO_DISPLAY_ASPECT");
        const char* fit = std::getenv("REO_DISPLAY_FIT");
        const uint32_t ratio = aspect && std::strcmp(aspect, "16:9") == 0 ? 1u : 0u;
        const uint32_t mode = !fit                               ? 0u
                              : std::strcmp(fit, "stretch") == 0 ? 1u
                              : std::strcmp(fit, "center") == 0  ? 2u
                              : std::strcmp(fit, "fill") == 0    ? 3u
                                                                 : 0u;
        return (ratio << 24u) | (mode << 26u);
    }
    static uint32_t colorPercent(const char* name, float minimum, float maximum) {
        const char* value = std::getenv(name);
        if (!value)
            return 100;
        char* end = nullptr;
        const float parsed = std::strtof(value, &end);
        if (end == value || *end || !std::isfinite(parsed))
            return 100;
        return uint32_t(std::lround(std::fmin(maximum, std::fmax(minimum, parsed)) * 100.0f));
    }
    static void require(VkResult result, const char* operation) {
        if (result != VK_SUCCESS)
            throw std::runtime_error(std::string(operation) + " failed: " + std::to_string(result));
    }
    VkQueue queue() const {
        return device_.get_queue_info().queues[Vulkan::QUEUE_INDEX_GRAPHICS];
    }
    void destroySwapchain() {
        device_.wait_idle();
        heldSource_.reset();
        presented_.clear();
        views_.clear();
        images_.clear();
        if (swapchain_)
            device_.get_device_table().vkDestroySwapchainKHR(device_.get_device(), swapchain_,
                                                             nullptr);
        swapchain_ = VK_NULL_HANDLE;
    }
    void destroySurface() {
        destroySwapchain();
        if (surface_)
            vkDestroySurfaceKHR(device_.get_instance(), surface_, nullptr);
        surface_ = VK_NULL_HANDLE;
    }
    void createSurface(uintptr_t window) {
        struct XlibSurfaceInfo {
            VkStructureType sType;
            const void* next;
            VkFlags flags;
            _XDisplay* display;
            unsigned long window;
        };
        using Create = VkResult(VKAPI_PTR*)(VkInstance, const XlibSurfaceInfo*,
                                            const VkAllocationCallbacks*, VkSurfaceKHR*);
        if (!display_)
            display_ = XOpenDisplay(nullptr);
        if (!display_)
            throw std::runtime_error("Cannot open the Linux X11 display");
        const auto create = reinterpret_cast<Create>(
            vkGetInstanceProcAddr(device_.get_instance(), "vkCreateXlibSurfaceKHR"));
        if (!create)
            throw std::runtime_error("VK_KHR_xlib_surface was not enabled");
        const XlibSurfaceInfo info{VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR, nullptr, 0,
                                   display_, static_cast<unsigned long>(window)};
        require(create(device_.get_instance(), &info, nullptr, &surface_), "Xlib Vulkan surface");
        VkBool32 supported = VK_FALSE;
        require(vkGetPhysicalDeviceSurfaceSupportKHR(
                    device_.get_physical_device(),
                    device_.get_queue_info().family_indices[Vulkan::QUEUE_INDEX_GRAPHICS], surface_,
                    &supported),
                "Vulkan present support");
        if (!supported)
            throw std::runtime_error(
                "The existing graphics queue cannot present to this X11 window");
    }

  public:
    ResidentXlibPresenter(Vulkan::Device& device, const std::vector<uint32_t>& vertex,
                          const std::vector<uint32_t>& fragment)
        : device_(device) {
        if (vertex.empty() || fragment.empty())
            throw std::invalid_argument("Empty Linux presentation shader");
        Vulkan::ResourceLayout vs{}, fs{};
        fs.sets[0].sampled_image_mask = fs.sets[0].fp_mask = 1;
        fs.sets[0].meta[0].array_size = 1;
        fs.output_mask = 1;
        fs.push_constant_size = sizeof(Parameters);
        program_ = device_.request_program(vertex.data(), vertex.size() * 4, fragment.data(),
                                           fragment.size() * 4, &vs, &fs);
        if (!program_)
            throw std::runtime_error("Linux presentation shader unavailable");
        const char* aa = std::getenv("REO_POST_AA");
        if (aa && std::strcmp(aa, "smaa") == 0)
            smaa_ = std::make_unique<ResidentSmaa>(device_, vertex);
    }
    ResidentXlibPresenter(const ResidentXlibPresenter&) = delete;
    ~ResidentXlibPresenter() {
        destroySurface();
        if (display_)
            XCloseDisplay(display_);
    }
    void attach(uintptr_t window, unsigned width, unsigned height) {
        if (!window || !width || !height || width > 16384 || height > 16384)
            throw std::invalid_argument("Invalid Linux presentation target");
        if (!outdated_ && window_ == window && requestedWidth_ == width &&
            requestedHeight_ == height)
            return;
        destroySwapchain();
        if (window_ != window || !surface_) {
            destroySurface();
            createSurface(window);
        }
        VkSurfaceCapabilitiesKHR capabilities{};
        require(vkGetPhysicalDeviceSurfaceCapabilitiesKHR(device_.get_physical_device(), surface_,
                                                          &capabilities),
                "Surface capabilities");
        if (!(capabilities.supportedUsageFlags & VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT))
            throw std::runtime_error("The Linux surface cannot receive GPU rendering");
        uint32_t count = 0;
        require(vkGetPhysicalDeviceSurfaceFormatsKHR(device_.get_physical_device(), surface_,
                                                     &count, nullptr),
                "Surface format count");
        std::vector<VkSurfaceFormatKHR> formats(count);
        require(vkGetPhysicalDeviceSurfaceFormatsKHR(device_.get_physical_device(), surface_,
                                                     &count, formats.data()),
                "Surface formats");
        VkFormat format = VK_FORMAT_UNDEFINED;
        for (const auto& entry : formats)
            if ((entry.format == VK_FORMAT_B8G8R8A8_UNORM ||
                 entry.format == VK_FORMAT_R8G8B8A8_UNORM || entry.format == VK_FORMAT_UNDEFINED) &&
                entry.colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR) {
                format =
                    entry.format == VK_FORMAT_UNDEFINED ? VK_FORMAT_B8G8R8A8_UNORM : entry.format;
                break;
            }
        if (format == VK_FORMAT_UNDEFINED)
            throw std::runtime_error("Linux presentation requires a byte-preserving UNORM surface");
        VkExtent2D extent = capabilities.currentExtent;
        if (extent.width == std::numeric_limits<uint32_t>::max())
            extent = {std::clamp(width, capabilities.minImageExtent.width,
                                 capabilities.maxImageExtent.width),
                      std::clamp(height, capabilities.minImageExtent.height,
                                 capabilities.maxImageExtent.height)};
        uint32_t imageCount = std::max(3u, capabilities.minImageCount);
        if (capabilities.maxImageCount)
            imageCount = std::min(imageCount, capabilities.maxImageCount);
        VkSwapchainCreateInfoKHR info{VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR};
        info.surface = surface_;
        info.minImageCount = imageCount;
        info.imageFormat = format;
        info.imageColorSpace = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;
        info.imageExtent = extent;
        info.imageArrayLayers = 1;
        info.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
        info.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
        info.preTransform = capabilities.currentTransform;
        info.compositeAlpha = static_cast<VkCompositeAlphaFlagBitsKHR>(
            capabilities.supportedCompositeAlpha & (~capabilities.supportedCompositeAlpha + 1u));
        // Guest VBlank remains the simulation clock. FIFO is the universal WSI fallback.
        uint32_t modeCount = 0;
        require(vkGetPhysicalDeviceSurfacePresentModesKHR(device_.get_physical_device(), surface_,
                                                          &modeCount, nullptr),
                "Present mode count");
        std::vector<VkPresentModeKHR> modes(modeCount);
        require(vkGetPhysicalDeviceSurfacePresentModesKHR(device_.get_physical_device(), surface_,
                                                          &modeCount, modes.data()),
                "Present modes");
        info.presentMode =
            std::find(modes.begin(), modes.end(), VK_PRESENT_MODE_MAILBOX_KHR) != modes.end()
                ? VK_PRESENT_MODE_MAILBOX_KHR
                : VK_PRESENT_MODE_FIFO_KHR;
        info.clipped = VK_TRUE;
        const auto& table = device_.get_device_table();
        require(table.vkCreateSwapchainKHR(device_.get_device(), &info, nullptr, &swapchain_),
                "Linux swapchain");
        require(table.vkGetSwapchainImagesKHR(device_.get_device(), swapchain_, &count, nullptr),
                "Swapchain image count");
        std::vector<VkImage> handles(count);
        require(
            table.vkGetSwapchainImagesKHR(device_.get_device(), swapchain_, &count, handles.data()),
            "Swapchain images");
        for (auto handle : handles) {
            auto imageInfo =
                Vulkan::ImageCreateInfo::render_target(extent.width, extent.height, format);
            imageInfo.usage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
            imageInfo.initial_layout = VK_IMAGE_LAYOUT_UNDEFINED;
            auto image = device_.wrap_image(imageInfo, handle);
            if (!image)
                throw std::runtime_error("Cannot wrap Linux swapchain image");
            Vulkan::ImageViewCreateInfo viewInfo{};
            viewInfo.image = image.get();
            viewInfo.format = format;
            viewInfo.view_type = VK_IMAGE_VIEW_TYPE_2D;
            viewInfo.levels = 1;
            viewInfo.layers = 1;
            auto view = device_.create_image_view(viewInfo);
            if (!view)
                throw std::runtime_error("Cannot create Linux swapchain image view");
            images_.push_back(std::move(image));
            views_.push_back(std::move(view));
        }
        presented_.resize(images_.size());
        window_ = window;
        width_ = extent.width;
        height_ = extent.height;
        requestedWidth_ = width;
        requestedHeight_ = height;
        if (smaa_)
            smaa_->resize(width_, height_);
        outdated_ = false;
    }
    Vulkan::Fence present(const Vulkan::ImageHandle& source, bool = false, bool linear = false,
                          unsigned retries = 0) {
        if (!source || !swapchain_)
            throw std::invalid_argument("Missing native Linux scanout");
        const auto& description = source->get_create_info();
        if (description.format != VK_FORMAT_R8G8B8A8_UNORM &&
            description.format != VK_FORMAT_B8G8R8A8_UNORM)
            throw std::runtime_error("Linux presentation requires merged UNORM bytes");
        auto acquire = device_.request_legacy_semaphore();
        uint32_t index = 0;
        const auto& table = device_.get_device_table();
        auto result = table.vkAcquireNextImageKHR(device_.get_device(), swapchain_, UINT64_MAX,
                                                  acquire->get_semaphore(), VK_NULL_HANDLE, &index);
        if (result == VK_ERROR_OUT_OF_DATE_KHR) {
            if (retries >= 2)
                throw std::runtime_error("Linux surface changed repeatedly during acquisition");
            outdated_ = true;
            attach(window_, requestedWidth_, requestedHeight_);
            return present(source, false, linear, retries + 1);
        }
        if (result != VK_SUBOPTIMAL_KHR)
            require(result, "Acquire Linux swapchain image");
        outdated_ = result == VK_SUBOPTIMAL_KHR;
        acquire->signal_external();
        acquire->set_signal_is_foreign_queue();
        device_.add_wait_semaphore(Vulkan::CommandBuffer::Type::Generic, std::move(acquire),
                                   VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, true);
        // The acquire wait orders reuse of the previous presentation semaphore.
        auto priorPresent = std::move(presented_.at(index));
        auto command = device_.request_command_buffer();
        command->image_barrier(
            *source, VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL, VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL,
            VK_PIPELINE_STAGE_ALL_COMMANDS_BIT, VK_ACCESS_2_MEMORY_WRITE_BIT,
            VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, VK_ACCESS_2_SHADER_SAMPLED_READ_BIT);
        if (smaa_)
            smaa_->prepare(*command, *source, program_, linear, layoutFlags());
        auto& image = images_.at(index);
        command->image_barrier(
            *image, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
            VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, 0, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
            VK_ACCESS_2_COLOR_ATTACHMENT_WRITE_BIT);
        Vulkan::RenderPassInfo pass{};
        pass.num_color_attachments = 1;
        pass.color_attachments[0] = views_.at(index).get();
        pass.store_attachments = 1;
        command->begin_render_pass(pass);
        command->set_opaque_state();
        command->set_cull_mode(VK_CULL_MODE_NONE);
        command->set_depth_test(false, false);
        command->set_blend_enable(false);
        const char* aa = std::getenv("REO_POST_AA");
        const bool fxaa = aa && std::strcmp(aa, "fxaa") == 0;
        if (smaa_)
            smaa_->bindBlend(*command);
        else {
            command->set_program(program_);
            command->set_texture(0, 0, source->get_view(),
                                 (linear || fxaa) ? Vulkan::StockSampler::LinearClamp
                                                  : Vulkan::StockSampler::NearestClamp);
        }
        const uint32_t color = (colorPercent("REO_BRIGHTNESS", 0.5f, 1.5f) << 8u) |
                               (colorPercent("REO_GAMMA", 0.5f, 2.0f) << 16u);
        const Parameters parameters{description.width, description.height, width_, height_,
                                    (linear ? 1u : 0u) | (fxaa ? 2u : 0u) | color | layoutFlags()};
        command->push_constants(&parameters, 0, sizeof(parameters));
        command->draw(3);
        command->end_render_pass();
        command->image_barrier(
            *image, VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL, VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,
            VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, VK_ACCESS_2_COLOR_ATTACHMENT_WRITE_BIT,
            VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, 0);
        device_.submit(command);
        auto release = device_.request_legacy_semaphore();
        Vulkan::Fence complete;
        device_.submit_empty(Vulkan::CommandBuffer::Type::Generic, &complete, release.get());
        const VkSemaphore signal = release->get_semaphore();
        VkPresentInfoKHR presentInfo{VK_STRUCTURE_TYPE_PRESENT_INFO_KHR};
        presentInfo.waitSemaphoreCount = 1;
        presentInfo.pWaitSemaphores = &signal;
        presentInfo.swapchainCount = 1;
        presentInfo.pSwapchains = &swapchain_;
        presentInfo.pImageIndices = &index;
        result = table.vkQueuePresentKHR(queue(), &presentInfo);
        release->wait_external();
        presented_[index] = std::move(release);
        if (result == VK_ERROR_OUT_OF_DATE_KHR || result == VK_SUBOPTIMAL_KHR)
            outdated_ = true;
        else
            require(result, "Linux queue presentation");
        heldSource_ = source;
        ++submitted_;
        return complete;
    }
    void retireSource() {
        heldSource_.reset();
    }
    uint64_t submittedFrames() const {
        return submitted_;
    }
    std::vector<uint8_t> diagnosticShaderOutput() {
        throw std::runtime_error("Linux swapchain diagnostic capture is not implemented");
    }
};
} // namespace reo_gpu_present
