#pragma once
#include "parent_context_abi.hpp"
#include "device.hpp"
#include "command_buffer.hpp"
#include <array>
#include <cstddef>
#include <cstdint>
#include <deque>
#include <stdexcept>
#include <vector>
namespace reo_gpu_palette {
struct Inputs {
    const Vulkan::Device* owner = nullptr;
    Vulkan::BufferHandle matrices, context, vu1Data, ownerCompletion;
};
struct Parameters {
    uint32_t mask, bones, contextWords, vfWords, accWords, qWord, pcWord, raWord;
};
static_assert(sizeof(Parameters) == 32);
static_assert(sizeof(R5900Context) % 4 == 0);
static_assert(offsetof(R5900Context, vu0_vf) % 4 == 0 && offsetof(R5900Context, vu0_acc) % 4 == 0);
class Producer {
    Vulkan::Device& device_;
    Vulkan::Program* program_ = nullptr;
    Vulkan::BufferHandle result_;
    struct Retirement {
        uint64_t value = 0;
        std::vector<Inputs> banks;
    };
    std::vector<Inputs> pending_;
    std::deque<Retirement> retired_;
    uint64_t submittedValue_ = 0;
    static void buffer(const Vulkan::BufferHandle& b, size_t size) {
        if (!b || b->get_create_info().domain != Vulkan::BufferDomain::Device ||
            b->get_create_info().size != size ||
            !(b->get_create_info().usage & VK_BUFFER_USAGE_STORAGE_BUFFER_BIT))
            throw std::invalid_argument("Palette requires exact resident bank shape");
    }

  public:
    Producer(Vulkan::Device& owner, const std::vector<uint32_t>& code) : device_(owner) {
        if (code.size() < 5 || code[0] != 0x07230203)
            throw std::invalid_argument("Missing native palette SPIRV");
        Vulkan::ResourceLayout layout{};
        layout.sets[0].storage_buffer_mask = 31u;
        layout.push_constant_size = sizeof(Parameters);
        for (unsigned b = 0; b < 5; ++b)
            layout.sets[0].meta[b].array_size = 1;
        program_ = device_.request_program(code.data(), code.size() * 4, &layout);
        if (!program_ || !program_->get_pipeline_layout())
            throw std::runtime_error("Native palette shader creation failed");
        const auto& actual = program_->get_pipeline_layout()->get_resource_layout();
        if (actual.descriptor_set_mask != 1 || actual.bindless_descriptor_set_mask ||
            actual.sets[0].storage_buffer_mask != 31u ||
            actual.stages_for_sets[0] != VK_SHADER_STAGE_COMPUTE_BIT ||
            actual.push_constant_range.offset ||
            actual.push_constant_range.size != sizeof(Parameters) ||
            actual.push_constant_range.stageFlags != VK_SHADER_STAGE_COMPUTE_BIT)
            throw std::runtime_error("Native palette explicit resource layout differs");
        for (unsigned b = 0; b < 5; ++b)
            if (actual.stages_for_bindings[0][b] != VK_SHADER_STAGE_COMPUTE_BIT ||
                actual.sets[0].meta[b].array_size != 1)
                throw std::runtime_error("Native palette binding differs");
        Vulkan::BufferCreateInfo info{};
        info.domain = Vulkan::BufferDomain::Device;
        info.size = 32;
        info.usage = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT |
                     VK_BUFFER_USAGE_TRANSFER_DST_BIT;
        const std::array<uint32_t, 8> zero{};
        result_ = device_.create_buffer(info, zero.data());
        if (!result_)
            throw std::runtime_error("Native palette status allocation failed");
    }
    Producer(const Producer&) = delete;
    Producer& operator=(const Producer&) = delete;
    ~Producer() {
        // Only owner teardown waits. Normal palette launches are asynchronous;
        // all borrowed bank handles live until genuine queue retirement.
        if (!pending_.empty() || !retired_.empty())
            device_.wait_idle();
    }
    void enqueue(Vulkan::CommandBuffer& cmd, const Inputs& input, uint32_t boneMask) {
        if (input.owner != &device_)
            throw std::invalid_argument("Palette bank belongs to a different Device");
        buffer(input.matrices, 2112);
        buffer(input.context, sizeof(R5900Context));
        buffer(input.vu1Data, 16384);
        buffer(input.ownerCompletion, 48);
        const std::array<const Vulkan::Buffer*, 4> identities{
            input.matrices.get(), input.context.get(), input.vu1Data.get(),
            input.ownerCompletion.get()};
        for (unsigned a = 0; a < 4; ++a)
            for (unsigned b = a + 1; b < 4; ++b)
                if (identities[a] == identities[b])
                    throw std::invalid_argument("Palette bank aliases another binding");
        if (pending_.size() >= 4096)
            throw std::overflow_error("Palette ownership prefix must submit before another batch");
        pending_.push_back(input);
        const std::array<const Vulkan::Buffer*, 5> barrierBanks{
            input.matrices.get(), input.context.get(), input.vu1Data.get(),
            input.ownerCompletion.get(), result_.get()};
        for (const auto* b : barrierBanks)
            cmd.buffer_barrier(*b, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                               VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                               VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                               VK_ACCESS_2_SHADER_STORAGE_READ_BIT |
                                   VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
        const Parameters p{boneMask,
                           32,
                           uint32_t(sizeof(R5900Context) / 4),
                           uint32_t(offsetof(R5900Context, vu0_vf) / 4),
                           uint32_t(offsetof(R5900Context, vu0_acc) / 4),
                           uint32_t(offsetof(R5900Context, vu0_q) / 4),
                           uint32_t(offsetof(R5900Context, pc) / 4),
                           uint32_t((offsetof(R5900Context, r) + 31 * 16) / 4)};
        cmd.set_program(program_);
        cmd.set_storage_buffer(0, 0, *input.matrices);
        cmd.set_storage_buffer(0, 1, *input.context);
        cmd.set_storage_buffer(0, 2, *input.vu1Data);
        cmd.set_storage_buffer(0, 3, *result_);
        cmd.set_storage_buffer(0, 4, *input.ownerCompletion);
        cmd.push_constants(&p, 0, sizeof(p));
        cmd.dispatch(1, 1, 1);
        // Existing whole-program/VIF consumer must observe these committed rows
        // and the same sticky owner word before any subsequent geometry launch.
        for (const auto* b :
             {input.context.get(), input.vu1Data.get(), input.ownerCompletion.get()})
            cmd.buffer_barrier(
                *b, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT, VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT,
                VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                VK_ACCESS_2_SHADER_STORAGE_READ_BIT | VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
    }
    const Vulkan::Buffer& result() const {
        return *result_;
    }
    void sealOwnerSubmission(uint64_t actualTimelineValue) {
        if (!actualTimelineValue || actualTimelineValue <= submittedValue_)
            throw std::invalid_argument(
                "Palette retirement needs a new actual GS submission timeline");
        submittedValue_ = actualTimelineValue;
        if (!pending_.empty()) {
            Retirement r;
            r.value = actualTimelineValue;
            r.banks = std::move(pending_);
            retired_.push_back(std::move(r));
            pending_.clear();
        }
    }
    void retireCompletedOwnerSubmission(uint64_t actualCompletedValue) {
        while (!retired_.empty() && retired_.front().value <= actualCompletedValue)
            retired_.pop_front();
    }
    // Source-only producer slice. Animation keys/hierarchy/camera, exact live
    // transient input provenance and guest-visible owner wait remain uncovered.
    static constexpr bool LiveCoverageCertificate = false;
};
} // namespace reo_gpu_palette
