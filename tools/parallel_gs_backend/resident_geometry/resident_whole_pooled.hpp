#pragma once
#include "resident_mesh_pool.hpp"
#include "literal_path1_contract.h"
#include <vector>

namespace reo_gpu_whole_pooled {
struct Push {
    uint32_t entryPC, maxPairs, top, itop, operation, capacity, reserved0, reserved1;
};
static_assert(sizeof(Push) == 32);
// Persistent raw VU state/data and sticky error belong to one GS Device. Each
// launch writes its own immutable output slice; renderer submission can batch
// earlier meshes without their data being overwritten by the next launch.
class Whole2ea {
    Vulkan::Device& device_;
    Vulkan::Program* program_ = nullptr;
    Vulkan::BufferHandle state_, data_, completion_, command_;
    Vulkan::BufferHandle make(size_t size, const void* initial) {
        Vulkan::BufferCreateInfo info{};
        info.domain = Vulkan::BufferDomain::Device;
        info.size = size;
        info.usage = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT |
                     VK_BUFFER_USAGE_TRANSFER_DST_BIT;
        auto b = device_.create_buffer(info, initial);
        if (!b)
            throw std::runtime_error("Pooled whole-program bank allocation failed");
        return b;
    }

  public:
    Whole2ea(Vulkan::Device& device, const std::vector<uint32_t>& spirv, const void* coldState,
             const void* coldData)
        : device_(device) {
        if (!coldState || !coldData || spirv.size() < 5 || spirv[0] != 0x07230203)
            throw std::invalid_argument("Invalid pooled whole-program cold inputs");
        Vulkan::ResourceLayout layout{};
        layout.sets[0].storage_buffer_mask = 0x7fu;
        for (unsigned b = 0; b < 7; ++b)
            layout.sets[0].meta[b].array_size = 1;
        layout.push_constant_size = sizeof(Push);
        program_ = device_.request_program(spirv.data(), spirv.size() * 4, &layout);
        if (!program_ || !program_->get_pipeline_layout())
            throw std::runtime_error("Pooled whole-program shader creation failed");
        const auto& actual = program_->get_pipeline_layout()->get_resource_layout();
        if (actual.descriptor_set_mask != 1 || actual.bindless_descriptor_set_mask ||
            actual.sets[0].storage_buffer_mask != 0x7fu ||
            actual.stages_for_sets[0] != VK_SHADER_STAGE_COMPUTE_BIT ||
            actual.push_constant_range.offset || actual.push_constant_range.size != sizeof(Push) ||
            actual.push_constant_range.stageFlags != VK_SHADER_STAGE_COMPUTE_BIT)
            throw std::runtime_error("Unexpected pooled whole-program interface");
        for (unsigned b = 0; b < 7; ++b)
            if (actual.sets[0].meta[b].array_size != 1 ||
                actual.stages_for_bindings[0][b] != VK_SHADER_STAGE_COMPUTE_BIT)
                throw std::runtime_error("Unexpected pooled whole-program binding");
        state_ = make(632, coldState);
        data_ = make(16384, coldData);
        const uint32_t zeros[32]{};
        completion_ = make(48, zeros);
        command_ = make(128, zeros);
    }
    Whole2ea(const Whole2ea&) = delete;
    Whole2ea& operator=(const Whole2ea&) = delete;
    void enqueue(Vulkan::CommandBuffer& cmd, const Push& push,
                 const reo_gpu_path1_metadata::GpuEchoContract& command,
                 const reo_gpu_mesh_pool::MeshPool& pool,
                 const reo_gpu_mesh_pool::MeshPool::Slice& slice) {
        pool.validate(slice);
        if (pool.owner() != &device_ || push.operation != 0 || push.maxPairs != 65536 ||
            !push.capacity || push.capacity > 256 || push.reserved0 || push.reserved1)
            throw std::invalid_argument("Pooled path requires a complete admitted launch");
        cmd.buffer_barrier(*command_, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                           VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                           VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT);
        cmd.update_buffer_inline(*command_, 0, sizeof(command), &command);
        cmd.buffer_barrier(*command_, VK_PIPELINE_STAGE_TRANSFER_BIT,
                           VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                           VK_ACCESS_2_SHADER_STORAGE_READ_BIT);
        for (const auto* b : {state_.get(), data_.get(), completion_.get()})
            cmd.buffer_barrier(*b, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                               VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                               VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                               VK_ACCESS_2_SHADER_STORAGE_READ_BIT |
                                   VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
        cmd.set_program(program_);
        cmd.set_storage_buffer(0, 0, *state_);
        cmd.set_storage_buffer(0, 1, *data_);
        pool.bind_output(cmd, 0, 2, reo_gpu_mesh_pool::MeshPool::Events, slice);
        cmd.set_storage_buffer(0, 3, *completion_);
        pool.bind_output(cmd, 0, 4, reo_gpu_mesh_pool::MeshPool::NativeVertices, slice);
        pool.bind_output(cmd, 0, 5, reo_gpu_mesh_pool::MeshPool::History, slice);
        cmd.set_storage_buffer(0, 6, *command_);
        cmd.push_constants(&push, 0, sizeof(push));
        cmd.dispatch(1, 1, 1);
        // Preserve actual per-job completion before the next kernel overwrites
        // transient words. Sticky word8 stays in the shared authoritative bank.
        cmd.buffer_barrier(*completion_, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                           VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT,
                           VK_ACCESS_2_TRANSFER_READ_BIT);
        cmd.copy_buffer(pool.bank(reo_gpu_mesh_pool::MeshPool::CompletionTape),
                        slice.offsets[reo_gpu_mesh_pool::MeshPool::CompletionTape], *completion_, 0,
                        48);
        cmd.buffer_barrier(pool.bank(reo_gpu_mesh_pool::MeshPool::CompletionTape),
                           VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT,
                           VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                           VK_ACCESS_2_SHADER_STORAGE_READ_BIT);
    }
    const Vulkan::Buffer& state() const {
        return *state_;
    }
    const Vulkan::Buffer& data() const {
        return *data_;
    }
    const Vulkan::Buffer& completion() const {
        return *completion_;
    }
    static constexpr bool LiveCoverageCertificate = false;
};
} // namespace reo_gpu_whole_pooled
