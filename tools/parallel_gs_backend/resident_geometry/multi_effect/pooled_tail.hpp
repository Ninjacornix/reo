#pragma once
#include "consumer_cert.hpp"
#include "resident_mesh_pool.hpp"
namespace reo_gpu_static_consumer {
class PooledTail {
    Vulkan::Device& device_;
    Vulkan::Program* program_ = nullptr;
    Vulkan::BufferHandle parameters_;
    static void access(Vulkan::CommandBuffer& c, const Vulkan::Buffer& b,
                       VkPipelineStageFlags target, VkAccessFlags2 a) {
        c.buffer_barrier(b, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                         VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT, target, a);
    }

  public:
    PooledTail(Vulkan::Device& d, const std::vector<uint32_t>& code) : device_(d) {
        if (code.size() < 5 || code[0] != 0x07230203u)
            throw std::invalid_argument("Unpinned pooled semantic tail shader");
        Vulkan::ResourceLayout l{};
        l.sets[0].storage_buffer_mask = 255;
        for (unsigned b = 0; b < 8; ++b)
            l.sets[0].meta[b].array_size = 1;
        program_ = d.request_program(code.data(), code.size() * 4, &l);
        if (!program_ || !program_->get_pipeline_layout())
            throw std::runtime_error("Pooled semantic tail program missing");
        const auto& a = program_->get_pipeline_layout()->get_resource_layout();
        if (a.descriptor_set_mask != 1u || a.bindless_descriptor_set_mask ||
            a.sets[0].storage_buffer_mask != 255u || a.push_constant_range.size)
            throw std::runtime_error("Pooled semantic tail interface differs");
        Vulkan::BufferCreateInfo ci{};
        ci.domain = Vulkan::BufferDomain::Device;
        ci.size = 32;
        ci.usage = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT;
        parameters_ = d.create_buffer(ci);
        if (!parameters_)
            throw std::runtime_error("Pooled semantic tail parameters missing");
    }
    Vulkan::BufferHandle allocate() {
        Vulkan::BufferCreateInfo ci{};
        ci.domain = Vulkan::BufferDomain::Device;
        ci.size = Words * 4;
        ci.usage = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT |
                   VK_BUFFER_USAGE_TRANSFER_DST_BIT;
        auto b = device_.create_buffer(ci);
        if (!b)
            throw std::runtime_error("Pooled semantic tail allocation missing");
        return b;
    }
    void enqueue(Vulkan::CommandBuffer& cmd, const reo_gpu_mesh_pool::MeshPool& pool,
                 const reo_gpu_mesh_pool::MeshPool::Slice& slice, const Vulkan::Buffer& global,
                 const Vulkan::Buffer& cert, uint32_t generation, uint32_t prim,
                 uint32_t operation) {
        pool.validate(slice);
        if (pool.owner() != &device_ || !generation || prim > 2047u || (prim & 7u) != 4u ||
            (operation != 0u && operation != 4u))
            throw std::invalid_argument("Pooled semantic tail metadata mismatch");
        uint32_t parameters[8]{generation, 0, prim, Magic, 256, 1, operation, Version};
        access(cmd, *parameters_, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT);
        cmd.update_buffer_inline(*parameters_, 0, 32, parameters);
        for (auto b :
             {reo_gpu_mesh_pool::MeshPool::Events, reo_gpu_mesh_pool::MeshPool::NativeVertices,
              reo_gpu_mesh_pool::MeshPool::History, reo_gpu_mesh_pool::MeshPool::CompletionTape,
              reo_gpu_mesh_pool::MeshPool::ExpansionStatus})
            access(cmd, pool.bank(b), VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                   VK_ACCESS_2_SHADER_STORAGE_READ_BIT);
        access(cmd, global, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
               VK_ACCESS_2_SHADER_STORAGE_READ_BIT | VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
        access(cmd, cert, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
               VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
        access(cmd, *parameters_, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
               VK_ACCESS_2_SHADER_STORAGE_READ_BIT);
        cmd.set_program(program_);
        pool.bind_output(cmd, 0, 0, reo_gpu_mesh_pool::MeshPool::Events, slice);
        pool.bind_output(cmd, 0, 1, reo_gpu_mesh_pool::MeshPool::NativeVertices, slice);
        pool.bind_output(cmd, 0, 2, reo_gpu_mesh_pool::MeshPool::History, slice);
        pool.bind_output(cmd, 0, 3, reo_gpu_mesh_pool::MeshPool::CompletionTape, slice);
        cmd.set_storage_buffer(0, 4, global);
        pool.bind_output(cmd, 0, 5, reo_gpu_mesh_pool::MeshPool::ExpansionStatus, slice);
        cmd.set_storage_buffer(0, 6, cert);
        cmd.set_storage_buffer(0, 7, *parameters_);
        cmd.dispatch(1, 1, 1);
    }
};
} // namespace reo_gpu_static_consumer
