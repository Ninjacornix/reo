#pragma once
#include "device.hpp"
#include "command_buffer.hpp"
#include "upstream/Textures/AreaTex.h"
#include "upstream/Textures/SearchTex.h"
#include <filesystem>
#include <fstream>
#include <stdexcept>
#include <vector>

namespace reo_gpu_present {
// SMAA 1x High, on the existing graphics queue. No temporal history or readback.
class ResidentSmaa {
    Vulkan::Device& device_;
    Vulkan::Program *edgesProgram_, *weightsProgram_, *blendProgram_;
    Vulkan::ImageHandle area_, search_, scaled_, edges_, weights_;
    unsigned width_ = 0, height_ = 0;
    bool initialized_ = false;
    struct Extent {
        uint32_t sourceWidth, sourceHeight, width, height, flags;
        uint32_t fps = 0, frameMs = 0, ups = 0;
    };

    Vulkan::Program* load(const char* name, const std::vector<uint32_t>& vertex,
                          unsigned textures) {
#if defined(_WIN32)
        wchar_t executable[32768];
        DWORD length = GetModuleFileNameW(nullptr, executable, 32768);
        if (!length || length == 32768)
            throw std::runtime_error("SMAA executable path unavailable");
        auto path = std::filesystem::path(executable).parent_path() / "reo-gpu-present" / name;
#elif defined(__linux__)
        std::error_code error;
        const auto executable = std::filesystem::read_symlink("/proc/self/exe", error);
        if (error)
            throw std::runtime_error("SMAA executable path unavailable");
        auto path = executable.parent_path() / "reo-gpu-present" / name;
#else
        throw std::runtime_error("SMAA shader location is unsupported on this platform");
        std::filesystem::path path;
#endif
        std::ifstream file(path, std::ios::binary | std::ios::ate);
        if (!file)
            throw std::runtime_error(std::string("Missing SMAA shader: ") + name);
        auto size = file.tellg();
        if (size <= 0 || size > 4 * 1024 * 1024 || size % 4)
            throw std::runtime_error("Invalid SMAA shader size");
        std::vector<uint32_t> fragment(size_t(size) / 4);
        file.seekg(0);
        file.read(reinterpret_cast<char*>(fragment.data()), size);
        if (!file || fragment[0] != 0x07230203)
            throw std::runtime_error("Invalid SMAA SPIR-V");
        Vulkan::ResourceLayout vs{}, fs{};
        fs.sets[0].sampled_image_mask = (1u << textures) - 1u;
        fs.sets[0].fp_mask = fs.sets[0].sampled_image_mask;
        for (unsigned i = 0; i < textures; ++i)
            fs.sets[0].meta[i].array_size = 1;
        fs.output_mask = 1;
        fs.push_constant_size = sizeof(Extent);
        auto* program = device_.request_program(vertex.data(), vertex.size() * 4, fragment.data(),
                                                fragment.size() * 4, &vs, &fs);
        if (!program)
            throw std::runtime_error("SMAA pipeline unavailable");
        return program;
    }
    Vulkan::ImageHandle attachment(VkFormat format) {
        auto info = Vulkan::ImageCreateInfo::render_target(width_, height_, format);
        info.usage |= VK_IMAGE_USAGE_SAMPLED_BIT;
        info.initial_layout = VK_IMAGE_LAYOUT_UNDEFINED;
        auto image = device_.create_image(info);
        if (!image)
            throw std::runtime_error("SMAA attachment allocation failed");
        return image;
    }
    void begin(Vulkan::CommandBuffer& cmd, const Vulkan::Image& image) {
        cmd.image_barrier(
            image, initialized_ ? VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL : VK_IMAGE_LAYOUT_UNDEFINED,
            VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
            initialized_ ? VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT
                         : VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
            initialized_ ? VK_ACCESS_2_SHADER_SAMPLED_READ_BIT : 0,
            VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, VK_ACCESS_2_COLOR_ATTACHMENT_WRITE_BIT);
        Vulkan::RenderPassInfo pass{};
        pass.num_color_attachments = 1;
        pass.color_attachments[0] = &image.get_view();
        pass.clear_attachments = 1;
        pass.store_attachments = 1;
        cmd.begin_render_pass(pass);
        cmd.set_opaque_state();
        cmd.set_cull_mode(VK_CULL_MODE_NONE);
        cmd.set_depth_test(false, false);
        cmd.set_blend_enable(false);
    }
    void finish(Vulkan::CommandBuffer& cmd, const Vulkan::Image& image) {
        cmd.draw(3);
        cmd.end_render_pass();
        cmd.image_barrier(
            image, VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL, VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL,
            VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, VK_ACCESS_2_COLOR_ATTACHMENT_WRITE_BIT,
            VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, VK_ACCESS_2_SHADER_SAMPLED_READ_BIT);
    }

  public:
    ResidentSmaa(Vulkan::Device& device, const std::vector<uint32_t>& vertex) : device_(device) {
        edgesProgram_ = load("present_smaa_edge.frag.spv", vertex, 1);
        weightsProgram_ = load("present_smaa_weights.frag.spv", vertex, 3);
        blendProgram_ = load("present_smaa_blend.frag.spv", vertex, 2);
        const Vulkan::ImageInitialData areaData{areaTexBytes, 0, 0},
            searchData{searchTexBytes, 0, 0};
        area_ = device_.create_image(Vulkan::ImageCreateInfo::immutable_2d_image(
                                         AREATEX_WIDTH, AREATEX_HEIGHT, VK_FORMAT_R8G8_UNORM),
                                     &areaData);
        search_ = device_.create_image(Vulkan::ImageCreateInfo::immutable_2d_image(
                                           SEARCHTEX_WIDTH, SEARCHTEX_HEIGHT, VK_FORMAT_R8_UNORM),
                                       &searchData);
        if (!area_ || !search_)
            throw std::runtime_error("SMAA lookup texture upload failed");
        std::fprintf(stderr,
                     "[SMAA] 1x High; upstream 71c806a; edges/weights/neighbourhood on GPU\n");
    }
    // Caller has retired previous presentation work before resizing these images.
    void resize(unsigned width, unsigned height) {
        if (width_ == width && height_ == height)
            return;
        width_ = width;
        height_ = height;
        initialized_ = false;
        scaled_ = attachment(VK_FORMAT_R8G8B8A8_UNORM);
        edges_ = attachment(VK_FORMAT_R8G8_UNORM);
        weights_ = attachment(VK_FORMAT_R8G8B8A8_UNORM);
    }
    void prepare(Vulkan::CommandBuffer& cmd, const Vulkan::Image& source,
                 Vulkan::Program* scaleProgram, bool linear, uint32_t layoutFlags) {
        const auto& info = source.get_create_info();
        Extent extent{info.width, info.height, width_, height_, (linear ? 1u : 0u) | layoutFlags};
        begin(cmd, *scaled_);
        cmd.set_program(scaleProgram);
        cmd.set_texture(0, 0, source.get_view(),
                        linear ? Vulkan::StockSampler::LinearClamp
                               : Vulkan::StockSampler::NearestClamp);
        cmd.push_constants(&extent, 0, sizeof(extent));
        finish(cmd, *scaled_);

        begin(cmd, *edges_);
        cmd.set_program(edgesProgram_);
        cmd.set_texture(0, 0, scaled_->get_view(), Vulkan::StockSampler::LinearClamp);
        cmd.push_constants(&extent, 0, sizeof(extent));
        finish(cmd, *edges_);

        begin(cmd, *weights_);
        cmd.set_program(weightsProgram_);
        cmd.set_texture(0, 0, edges_->get_view(), Vulkan::StockSampler::LinearClamp);
        cmd.set_texture(0, 1, area_->get_view(), Vulkan::StockSampler::LinearClamp);
        cmd.set_texture(0, 2, search_->get_view(), Vulkan::StockSampler::LinearClamp);
        cmd.push_constants(&extent, 0, sizeof(extent));
        finish(cmd, *weights_);
        initialized_ = true;
    }
    void bindBlend(Vulkan::CommandBuffer& cmd) {
        cmd.set_program(blendProgram_);
        cmd.set_texture(0, 0, scaled_->get_view(), Vulkan::StockSampler::LinearClamp);
        cmd.set_texture(0, 1, weights_->get_view(), Vulkan::StockSampler::LinearClamp);
    }
};
} // namespace reo_gpu_present
