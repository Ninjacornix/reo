#pragma once
#include "resident_mesh_pool.hpp"
#include <cstring>
#include <vector>

namespace reo_gpu_pooled_strip {
struct alignas(16) Parameters {
    std::array<uint32_t, 4> limits{};
    std::array<int32_t, 4> offsetScissorLo{}, scissorHi{};
    std::array<uint32_t, 6> material{};
};
static_assert(sizeof(Parameters) == 80);
class Strip {
    Vulkan::Device& device_;
    Vulkan::Program* program_ = nullptr;
    Vulkan::BufferHandle parameters_;

  public:
    Strip(Vulkan::Device& device, const std::vector<uint32_t>& code) : device_(device) {
        if (code.size() < 5 || code[0] != 0x07230203)
            throw std::invalid_argument("Invalid pooled strip shader");
        Vulkan::ResourceLayout layout{};
        layout.sets[0].storage_buffer_mask = 0x1ffu;
        for (unsigned b = 0; b < 9; ++b)
            layout.sets[0].meta[b].array_size = 1;
        program_ = device_.request_program(code.data(), code.size() * 4, &layout);
        if (!program_ || !program_->get_pipeline_layout())
            throw std::runtime_error("Pooled strip program creation failed");
        const auto& actual = program_->get_pipeline_layout()->get_resource_layout();
        if (actual.descriptor_set_mask != 1 || actual.bindless_descriptor_set_mask ||
            actual.sets[0].storage_buffer_mask != 0x1ffu || actual.push_constant_range.size ||
            actual.stages_for_sets[0] != VK_SHADER_STAGE_COMPUTE_BIT)
            throw std::runtime_error("Unexpected pooled strip interface");
        for (unsigned b = 0; b < 9; ++b)
            if (actual.sets[0].meta[b].array_size != 1 ||
                actual.stages_for_bindings[0][b] != VK_SHADER_STAGE_COMPUTE_BIT)
                throw std::runtime_error("Unexpected pooled strip binding");
        Vulkan::BufferCreateInfo info{};
        info.domain = Vulkan::BufferDomain::Device;
        info.size = sizeof(Parameters);
        info.usage = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT;
        parameters_ = device_.create_buffer(info);
        if (!parameters_)
            throw std::runtime_error("Pooled strip parameter allocation failed");
    }
    void enqueue(Vulkan::CommandBuffer& cmd, const reo_gpu_mesh_pool::MeshPool& pool,
                 const reo_gpu_mesh_pool::MeshPool::Slice& slice, const Parameters& p,
                 const Vulkan::Buffer& sameOwnerGlobalCompletion) {
        pool.validate(slice);
        if (pool.owner() != &device_ || !p.limits[0] || p.limits[0] > 256 || p.limits[1] ||
            p.limits[2] < p.limits[0] || p.limits[2] > 256 || p.limits[3] ||
            sameOwnerGlobalCompletion.get_create_info().size != 48)
            throw std::invalid_argument("Invalid pooled strip command metadata");
        for (unsigned b = 0; b < 8; ++b)
            cmd.buffer_barrier(pool.bank(reo_gpu_mesh_pool::MeshPool::Binding(b)),
                               VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                               VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                               VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                               VK_ACCESS_2_SHADER_STORAGE_READ_BIT |
                                   VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
        cmd.buffer_barrier(sameOwnerGlobalCompletion, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                           VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                           VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                           VK_ACCESS_2_SHADER_STORAGE_READ_BIT |
                               VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
        cmd.buffer_barrier(*parameters_, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                           VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                           VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT);
        cmd.update_buffer_inline(*parameters_, 0, sizeof(p), &p);
        cmd.buffer_barrier(*parameters_, VK_PIPELINE_STAGE_TRANSFER_BIT,
                           VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                           VK_ACCESS_2_SHADER_STORAGE_READ_BIT);
        cmd.set_program(program_);
        pool.bind_output(cmd, 0, 0, reo_gpu_mesh_pool::MeshPool::NativeVertices, slice);
        pool.bind_output(cmd, 0, 1, reo_gpu_mesh_pool::MeshPool::History, slice);
        cmd.set_storage_buffer(0, 2, *parameters_);
        pool.bind_output(cmd, 0, 3, reo_gpu_mesh_pool::MeshPool::Positions, slice);
        pool.bind_output(cmd, 0, 4, reo_gpu_mesh_pool::MeshPool::Attributes, slice);
        pool.bind_output(cmd, 0, 5, reo_gpu_mesh_pool::MeshPool::Primitives, slice);
        pool.bind_output(cmd, 0, 6, reo_gpu_mesh_pool::MeshPool::ExpansionStatus, slice);
        pool.bind_output(cmd, 0, 7, reo_gpu_mesh_pool::MeshPool::CompletionTape, slice);
        cmd.set_storage_buffer(0, 8, sameOwnerGlobalCompletion);
        cmd.dispatch(1, 1, 1);
    }
    ParallelGS::ResidentPrimitiveInputs inputs(const reo_gpu_mesh_pool::MeshPool& pool,
                                               const reo_gpu_mesh_pool::MeshPool::Slice& slice,
                                               uint32_t capacity) const {
        if (pool.owner() != &device_)
            throw std::invalid_argument("Wrong pooled strip owner");
        auto result = pool.draw_inputs(slice, capacity);
        result.exactFixedTopologyCertificate = true;
        return result;
    }
};
} // namespace reo_gpu_pooled_strip
