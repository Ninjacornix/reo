#pragma once
#include "device.hpp"
#include "command_buffer.hpp"
#include "wsi_dxgi.hpp"
#include <memory>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stdexcept>
#include <vector>
#include "smaa/resident_smaa.hpp"

namespace reo_gpu_present {
// Existing GS/geometry Vulkan Device and its serialized graphics owner are
// mandatory. This helper does not instantiate another renderer, Vulkan context,
// host image, OpenGL texture, staging buffer, readback or pixel transformation.
class ResidentDxgiPresenter {
    Vulkan::Device& device_;
    std::unique_ptr<Vulkan::DXGIInteropSwapchain> swapchain_;
    Vulkan::Program* program_ = nullptr;
    std::unique_ptr<ResidentSmaa> smaa_;
    Vulkan::ImageHandle heldSource_, target_;
    Vulkan::ImageViewHandle targetView_;
    HWND window_ = nullptr;
    unsigned width_ = 0, height_ = 0;
    uint64_t submitted_ = 0;
    struct Parameters {
        uint32_t sourceWidth, sourceHeight, destinationWidth, destinationHeight, linear;
    };
    static uint32_t layoutFlags() {
        const char* aspect = std::getenv("REO_DISPLAY_ASPECT");
        const char* fit = std::getenv("REO_DISPLAY_FIT");
        uint32_t ratio = aspect && std::strcmp(aspect, "16:9") == 0 ? 1u : 0u;
        uint32_t mode = !fit                               ? 0u
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
        float parsed = std::strtof(value, &end);
        if (end == value || *end || !std::isfinite(parsed))
            return 100;
        return uint32_t(std::lround(std::fmin(maximum, std::fmax(minimum, parsed)) * 100.0f));
    }

  public:
    ResidentDxgiPresenter(Vulkan::Device& device, const std::vector<uint32_t>& vertex,
                          const std::vector<uint32_t>& fragment)
        : device_(device) {
        std::fprintf(
            stderr, "[HOST-GRAPHICS] scaling=%s aa=%s texture-filter=%s\n",
            std::getenv("REO_DISPLAY_FILTER") ? std::getenv("REO_DISPLAY_FILTER") : "nearest",
            std::getenv("REO_POST_AA") ? std::getenv("REO_POST_AA") : "off",
            std::getenv("REO_TEXTURE_FILTER") ? std::getenv("REO_TEXTURE_FILTER") : "original");
        std::fprintf(stderr, "[HOST-GRAPHICS] brightness=%u%% gamma=%.2f\n",
                     colorPercent("REO_BRIGHTNESS", 0.5f, 1.5f),
                     colorPercent("REO_GAMMA", 0.5f, 2.0f) / 100.0);
        std::fprintf(stderr, "[HOST-GRAPHICS] aspect=%s fit=%s\n",
                     std::getenv("REO_DISPLAY_ASPECT") ? std::getenv("REO_DISPLAY_ASPECT") : "4:3",
                     std::getenv("REO_DISPLAY_FIT") ? std::getenv("REO_DISPLAY_FIT") : "fit");
        if (vertex.empty() || fragment.empty())
            throw std::invalid_argument("Empty presentation shader");
        Vulkan::ResourceLayout v{}, f{};
        f.sets[0].sampled_image_mask = 1;
        f.sets[0].fp_mask = 1;
        f.sets[0].meta[0].array_size = 1;
        f.output_mask = 1;
        f.push_constant_size = sizeof(Parameters);
        program_ = device_.request_program(vertex.data(), vertex.size() * 4, fragment.data(),
                                           fragment.size() * 4, &v, &f);
        if (!program_)
            throw std::runtime_error("GPU opaque presentation shader unavailable");
        const char* aa = std::getenv("REO_POST_AA");
        if (aa && std::strcmp(aa, "smaa") == 0)
            smaa_ = std::make_unique<ResidentSmaa>(device_, vertex);
        swapchain_ = std::make_unique<Vulkan::DXGIInteropSwapchain>();
        if (!swapchain_->init_interop_device(device_))
            throw std::runtime_error("Existing-device Granite DXGI interop unavailable");
    }
    ResidentDxgiPresenter(const ResidentDxgiPresenter&) = delete;
    ~ResidentDxgiPresenter() {
        device_.wait_idle();
        heldSource_.reset();
        targetView_.reset();
        target_.reset();
        swapchain_.reset();
    }

    // CPU supplies OS window extents only. Resize/attach is ordered by the owner,
    // with a teardown fence; it is never performed from the UI message thread.
    void attach(HWND window, unsigned width, unsigned height) {
        if (!window || !width || !height || width > 16384 || height > 16384)
            throw std::invalid_argument("Invalid presentation target");
        if (window_ == window && width_ == width && height_ == height)
            return;
        device_.wait_idle();
        targetView_.reset();
        target_.reset();
        // UNORM source and target preserve already merged byte RGB. No sRGB
        // texture decode or second PMODE/GS alpha blend is introduced. Optional
        // user brightness/gamma is applied once in the presentation shader.
        VkSurfaceFormatKHR format{VK_FORMAT_B8G8R8A8_UNORM, VK_COLOR_SPACE_SRGB_NONLINEAR_KHR};
        if (!swapchain_->init_swapchain(window, format, width, height, 3))
            throw std::runtime_error("Native DXGI swapchain unavailable");
        auto imageInfo = Vulkan::ImageCreateInfo::render_target(width, height, format.format);
        imageInfo.usage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
        imageInfo.initial_layout = VK_IMAGE_LAYOUT_UNDEFINED;
        target_ = device_.wrap_image(imageInfo, swapchain_->get_vulkan_image());
        if (!target_)
            throw std::runtime_error("Wrap DXGI target failed");
        Vulkan::ImageViewCreateInfo view{};
        view.image = target_.get();
        view.format = format.format;
        view.levels = 1;
        view.layers = 1;
        view.view_type = VK_IMAGE_VIEW_TYPE_2D;
        targetView_ = device_.create_image_view(view);
        if (!targetView_)
            throw std::runtime_error("Create DXGI target view failed");
        window_ = window;
        width_ = width;
        height_ = height;
        if (smaa_)
            smaa_->resize(width, height);
    }

    // Invoke after ordered GSInterface::vsync creates its completed merge image.
    // Granite's queued image dependencies preserve source completion. The real
    // DXGI acquire/release timeline protects its shared render target. Pacing is
    // the caller's existing guest VBlank clock; do not add a second sleep clock.
    Vulkan::Fence present(const Vulkan::ImageHandle& merged, bool displayVsync = false,
                          bool linear = false) {
        if (!window_ || !merged)
            throw std::invalid_argument("Missing resident scanout");
        const auto& source = merged->get_create_info();
        if (source.format != VK_FORMAT_R8G8B8A8_UNORM && source.format != VK_FORMAT_B8G8R8A8_UNORM)
            throw std::runtime_error("Resident presentation requires merged UNORM bytes");
        Vulkan::Semaphore acquire;
        if (!swapchain_->acquire(acquire) || !acquire)
            throw std::runtime_error("DXGI acquire failed");
        acquire->signal_external();
        if (!swapchain_->wait_latency(2))
            throw std::runtime_error("DXGI latency wait failed");
        // Public queue wait; no Device WSI private state/access is used.
        device_.add_wait_semaphore(Vulkan::CommandBuffer::Type::Generic, std::move(acquire),
                                   VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, true);
        auto cmd = device_.request_command_buffer();
        cmd->image_barrier(*merged, VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL,
                           VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                           VK_ACCESS_2_MEMORY_WRITE_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,
                           VK_ACCESS_2_SHADER_SAMPLED_READ_BIT);
        if (smaa_)
            smaa_->prepare(*cmd, *merged, program_, linear, layoutFlags());
        cmd->acquire_image_barrier(
            *target_, VK_IMAGE_LAYOUT_GENERAL, VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
            VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, VK_ACCESS_2_COLOR_ATTACHMENT_WRITE_BIT);
        Vulkan::RenderPassInfo pass{};
        pass.num_color_attachments = 1;
        pass.color_attachments[0] = targetView_.get();
        pass.store_attachments = 1;

        cmd->begin_render_pass(pass);
        cmd->set_opaque_state();
        cmd->set_cull_mode(VK_CULL_MODE_NONE);
        cmd->set_depth_test(false, false);
        cmd->set_blend_enable(false);
        static const bool fxaa = [] {
            const char* value = std::getenv("REO_POST_AA");
            return value && std::strcmp(value, "fxaa") == 0;
        }();
        if (smaa_)
            smaa_->bindBlend(*cmd);
        else {
            cmd->set_program(program_);
            cmd->set_texture(0, 0, merged->get_view(),
                             (linear || fxaa) ? Vulkan::StockSampler::LinearClamp
                                              : Vulkan::StockSampler::NearestClamp);
        }
        static const uint32_t color = (colorPercent("REO_BRIGHTNESS", 0.5f, 1.5f) << 8u) |
                                      (colorPercent("REO_GAMMA", 0.5f, 2.0f) << 16u);
        Parameters parameters{source.width, source.height, width_, height_,
                              (linear ? 1u : 0u) | (fxaa ? 2u : 0u) | color | layoutFlags()};
        cmd->push_constants(&parameters, 0, sizeof(parameters));
        cmd->draw(3);
        cmd->end_render_pass();
        // Pinned DXGIInteropSwapchain::present performs the actual external
        // release from PRESENT to GENERAL after waiting this signaled semaphore.
        cmd->image_barrier(
            *target_, VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL, VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,
            VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, VK_ACCESS_2_COLOR_ATTACHMENT_WRITE_BIT,
            VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, 0);
        Vulkan::Semaphore release;
        Vulkan::Fence drawComplete;
        device_.submit(cmd, &drawComplete, 1, &release);
        if (!release || !swapchain_->present(std::move(release), displayVsync))
            throw std::runtime_error("DXGI GPU present failed");
        heldSource_ = merged;
        ++submitted_;
        return drawComplete;
    }
    // Explicit offline diagnostic only. Normal present has no staging/map path.
    // Reacquire the actual shared target, copy GPU shader output once, and return
    // ownership through the same real DXGI synchronization before host mapping.
    std::vector<uint8_t> diagnosticShaderOutput() {
        Vulkan::Semaphore acquire;
        if (!swapchain_->acquire(acquire) || !acquire)
            throw std::runtime_error("Diagnostic DXGI acquire failed");
        acquire->signal_external();
        device_.add_wait_semaphore(Vulkan::CommandBuffer::Type::Generic, std::move(acquire),
                                   VK_PIPELINE_STAGE_TRANSFER_BIT, true);
        Vulkan::BufferCreateInfo info{};
        info.domain = Vulkan::BufferDomain::CachedHost;
        info.size = size_t(width_) * height_ * 4;
        info.usage = VK_BUFFER_USAGE_TRANSFER_DST_BIT;
        auto buffer = device_.create_buffer(info);
        if (!buffer)
            throw std::runtime_error("Diagnostic output allocation failed");
        auto cmd = device_.request_command_buffer();
        cmd->acquire_image_barrier(*target_, VK_IMAGE_LAYOUT_GENERAL,
                                   VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                   VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
        VkBufferImageCopy copy{};
        copy.imageSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1};
        copy.imageExtent = {width_, height_, 1};
        cmd->copy_image_to_buffer(*buffer, *target_, 1, &copy);
        cmd->buffer_barrier(*buffer, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT,
                            VK_PIPELINE_STAGE_HOST_BIT, VK_ACCESS_2_HOST_READ_BIT);
        cmd->image_barrier(*target_, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                           VK_IMAGE_LAYOUT_PRESENT_SRC_KHR, VK_PIPELINE_STAGE_TRANSFER_BIT,
                           VK_ACCESS_2_TRANSFER_READ_BIT,
                           VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, 0);
        Vulkan::Fence copied;
        Vulkan::Semaphore release;
        device_.submit(cmd, &copied, 1, &release);
        if (!swapchain_->present(std::move(release), false))
            throw std::runtime_error("Diagnostic DXGI release failed");
        copied->wait();
        const auto* bytes = static_cast<const uint8_t*>(
            device_.map_host_buffer(*buffer, Vulkan::MEMORY_ACCESS_READ_BIT));
        if (!bytes)
            throw std::runtime_error("Diagnostic output map failed");
        std::vector<uint8_t> result(info.size);
        std::memcpy(result.data(), bytes, result.size());
        device_.unmap_host_buffer(*buffer, Vulkan::MEMORY_ACCESS_READ_BIT);
        return result;
    }
    void retireSource() {
        heldSource_.reset();
    }
    uint64_t submittedFrames() const {
        return submitted_;
    }
    static constexpr uint64_t pixelReadbacks() {
        return 0;
    }
};
} // namespace reo_gpu_present
