#pragma once
#include "device.hpp"
#include "command_buffer.hpp"
#include "tools/parallel_gs_backend/resident_geometry/enrollment/sha256.hpp"
#include <array>
#include <deque>
#include <stdexcept>
namespace reo_gpu_palette_parent {
class Producer;
}
namespace reo_source_adapter {
class RawBytePatch final {
    friend class reo_gpu_palette_parent::Producer;
    Vulkan::Device& device_;
    Vulkan::Program* program_ = nullptr;
    std::array<Vulkan::BufferHandle, 3> banks_;
    std::vector<Vulkan::BufferHandle> pending_;
    struct Submission {
        uint64_t timeline;
        std::vector<Vulkan::BufferHandle> inputs;
    };
    std::deque<Submission> inFlight_;
    uint64_t sealed_ = 0;
    RawBytePatch(Vulkan::Device& device, const std::vector<uint32_t>& code,
                 std::array<Vulkan::BufferHandle, 3> banks)
        : device_(device), banks_(std::move(banks)) {
        std::vector<uint8_t> rawCode(code.size() * 4);
        std::memcpy(rawCode.data(), code.data(), rawCode.size());
        if (reo_gpu_catalog::sha256(rawCode) !=
            "08ba20089316e27575d7e4b007074c23e661c094fb6929631f65cea8875447c3")
            throw std::invalid_argument("Raw byte transport module differs");
        for (unsigned b = 0; b < 3; ++b)
            if (!banks_[b] || banks_[b]->get_create_info().size != (b == 0   ? 0x2000000u
                                                                    : b == 1 ? 0x4000u
                                                                             : 1648u))
                throw std::invalid_argument(
                    "Raw byte transport requires actual shaped owner banks");
        Vulkan::ResourceLayout layout{};
        layout.sets[0].storage_buffer_mask = 15;
        for (unsigned b = 0; b < 4; ++b)
            layout.sets[0].meta[b].array_size = 1;
        layout.push_constant_size = 16;
        program_ = device_.request_program(code.data(), code.size() * 4, &layout);
        if (!program_ || !program_->get_pipeline_layout())
            throw std::runtime_error("Raw byte transport program absent");
        const auto& actual = program_->get_pipeline_layout()->get_resource_layout();
        if (actual.descriptor_set_mask != 1 || actual.bindless_descriptor_set_mask ||
            actual.sets[0].storage_buffer_mask != 15 ||
            actual.stages_for_sets[0] != VK_SHADER_STAGE_COMPUTE_BIT ||
            actual.push_constant_range.offset || actual.push_constant_range.size != 16 ||
            actual.push_constant_range.stageFlags != VK_SHADER_STAGE_COMPUTE_BIT)
            throw std::runtime_error("Raw byte transport layout differs");
        for (unsigned b = 0; b < 4; ++b)
            if (actual.sets[0].meta[b].array_size != 1 ||
                actual.stages_for_bindings[0][b] != VK_SHADER_STAGE_COMPUTE_BIT)
                throw std::runtime_error("Raw byte transport binding differs");
    }
    static void barrier(Vulkan::CommandBuffer& cmd, const Vulkan::Buffer& bank) {
        cmd.buffer_barrier(bank, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                           VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                           VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                           VK_ACCESS_2_SHADER_STORAGE_READ_BIT |
                               VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
    }
    void record(Vulkan::CommandBuffer& cmd, unsigned bank, uint32_t at, const void* data,
                uint32_t bytes) {
        const uint32_t limit = bank == 0 ? 0x2000000u : bank == 1 ? 0x4000u : 1648u;
        if (bank > 2 || !data || !bytes || at >= limit || bytes > limit - at ||
            bytes > 1024u * 1024u || pending_.size() >= 32768)
            throw std::invalid_argument("Raw byte transport unbounded/foreign range");
        std::vector<uint8_t> padded((bytes + 3u) & ~3u);
        std::memcpy(padded.data(), data, bytes);
        Vulkan::BufferCreateInfo ci{};
        ci.domain = Vulkan::BufferDomain::Device;
        ci.size = padded.size();
        ci.usage = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT;
        auto input = device_.create_buffer(ci, padded.data());
        if (!input)
            throw std::runtime_error("Raw byte immutable input allocation failed");
        pending_.push_back(input);
        for (const auto& b : banks_)
            barrier(cmd, *b);
        barrier(cmd, *input);
        const std::array<uint32_t, 4> push{bank, at, bytes, 0};
        cmd.set_program(program_);
        for (unsigned b = 0; b < 3; ++b)
            cmd.set_storage_buffer(0, b, *banks_[b]);
        cmd.set_storage_buffer(0, 3, *input);
        cmd.push_constants(push.data(), 0, 16);
        const uint32_t words = ((at & 3u) + bytes + 3u) / 4u;
        cmd.dispatch((words + 63u) / 64u, 1, 1);
        for (const auto& b : banks_)
            barrier(cmd, *b);
    }
    void seal(uint64_t timeline) {
        if (!timeline || timeline <= sealed_)
            throw std::invalid_argument("Raw byte input seal needs actual new owner submission");
        sealed_ = timeline;
        if (!pending_.empty()) {
            inFlight_.push_back({timeline, std::move(pending_)});
            pending_.clear();
        }
    }
    void retire(uint64_t timeline) {
        if (timeline > sealed_)
            throw std::invalid_argument("Raw byte completion exceeds actual prefix");
        while (!inFlight_.empty() && inFlight_.front().timeline <= timeline)
            inFlight_.pop_front();
    }

  public:
    RawBytePatch(const RawBytePatch&) = delete;
    ~RawBytePatch() {
        if (!pending_.empty() || !inFlight_.empty())
            device_.wait_idle();
    }
    static constexpr bool DeviceParityProved = false;
};
} // namespace reo_source_adapter
