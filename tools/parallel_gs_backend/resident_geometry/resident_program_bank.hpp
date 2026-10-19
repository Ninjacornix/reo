#pragma once
#include "resident_whole_pooled.hpp"
#include <unordered_map>
namespace reo_resident_live {
struct ProgramModule {
    uint64_t bindingId = 0;
    std::vector<uint32_t> spirv;
    bool canResume = false;
    std::vector<uint32_t> resumeSpirv;
    bool freshLiteralSourcePreserved = false, resumeLiteralSourcePreserved = false;
};
// All registered whole microprograms share these authoritative raw banks.
class ProgramBank {
    Vulkan::Device& device_;
    struct Entry {
        Vulkan::Program* program;
        bool canResume;
        Vulkan::Program* resumeProgram;
    };
    std::unordered_map<uint64_t, Entry> programs_;
    Vulkan::BufferHandle state_, data_, completion_, command_;
    Vulkan::BufferHandle make(size_t bytes, const void* initial) {
        Vulkan::BufferCreateInfo info{};
        info.domain = Vulkan::BufferDomain::Device;
        info.size = bytes;
        info.usage = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT |
                     VK_BUFFER_USAGE_TRANSFER_SRC_BIT;
        auto buffer = device_.create_buffer(info, initial);
        if (!buffer)
            throw std::runtime_error("Resident program bank allocation failed");
        return buffer;
    }

  public:
    const void* deviceIdentity() const noexcept {
        return &device_;
    }
    ProgramBank(Vulkan::Device& device, const std::vector<ProgramModule>& modules,
                const void* coldState, const void* coldData)
        : device_(device) {
        if (!coldState || !coldData || modules.empty())
            throw std::invalid_argument("Missing resident cold bank/modules");
        Vulkan::ResourceLayout layout{};
        layout.sets[0].storage_buffer_mask = 0x7fu;
        for (unsigned b = 0; b < 7; ++b)
            layout.sets[0].meta[b].array_size = 1;
        layout.push_constant_size = sizeof(reo_gpu_whole_pooled::Push);
        const auto loadProgram = [&](const std::vector<uint32_t>& code) {
            if (code.size() < 5 || code[0] != 0x07230203)
                throw std::invalid_argument("Invalid complete-program module SPIR-V");
            auto* program = device_.request_program(code.data(), code.size() * 4, &layout);
            if (!program || !program->get_pipeline_layout())
                throw std::runtime_error("Whole-program module creation failed");
            const auto& actual = program->get_pipeline_layout()->get_resource_layout();
            if (actual.descriptor_set_mask != 1 || actual.bindless_descriptor_set_mask ||
                actual.sets[0].storage_buffer_mask != 0x7fu ||
                actual.stages_for_sets[0] != VK_SHADER_STAGE_COMPUTE_BIT ||
                actual.push_constant_range.offset ||
                actual.push_constant_range.size != sizeof(reo_gpu_whole_pooled::Push) ||
                actual.push_constant_range.stageFlags != VK_SHADER_STAGE_COMPUTE_BIT)
                throw std::runtime_error("Unexpected complete-program7SSBO interface");
            for (unsigned b = 0; b < 7; ++b)
                if (actual.sets[0].meta[b].array_size != 1 ||
                    actual.stages_for_bindings[0][b] != VK_SHADER_STAGE_COMPUTE_BIT)
                    throw std::runtime_error("Unexpected complete-program binding");
            return program;
        };
        for (const auto& module : modules) {
            if (!module.bindingId || programs_.count(module.bindingId))
                throw std::invalid_argument("Invalid/duplicate resident whole-program module");
            auto* program = loadProgram(module.spirv);
            // Optional generic operation4 uses the SAME raw state/data/event/
            // completion/echo banks. It reads its resident PC on the GPU. Both
            // modules receive the identical explicit seven-SSBO interface audit.
            auto* resume = module.resumeSpirv.empty() ? program : loadProgram(module.resumeSpirv);
            programs_.emplace(module.bindingId, Entry{program, module.canResume, resume});
        }
        state_ = make(632, coldState);
        data_ = make(16384, coldData);
        const uint32_t zeros[32]{};
        completion_ = make(48, zeros);
        command_ = make(128, zeros);
    }
    bool covers(uint64_t binding) const noexcept {
        return programs_.count(binding) != 0;
    }
    void enqueue(Vulkan::CommandBuffer& cmd, uint64_t binding,
                 const reo_gpu_whole_pooled::Push& push,
                 const reo_gpu_path1_metadata::GpuEchoContract& echo,
                 const reo_gpu_mesh_pool::MeshPool& pool,
                 const reo_gpu_mesh_pool::MeshPool::Slice& slice) {
        const auto found = programs_.find(binding);
        pool.validate(slice);
        if (found == programs_.end() || pool.owner() != &device_ ||
            (push.operation != 0 && push.operation != 4) ||
            (push.operation == 4 && !found->second.canResume) || push.maxPairs != 65536 ||
            !push.capacity || push.capacity > 256 || push.reserved0 || push.reserved1)
            throw std::invalid_argument("Unsupported complete resident program dispatch");
        cmd.buffer_barrier(*command_, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                           VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                           VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT);
        cmd.update_buffer_inline(*command_, 0, sizeof(echo), &echo);
        cmd.buffer_barrier(*command_, VK_PIPELINE_STAGE_TRANSFER_BIT,
                           VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                           VK_ACCESS_2_SHADER_STORAGE_READ_BIT);
        for (const auto* buffer : {state_.get(), data_.get(), completion_.get()})
            cmd.buffer_barrier(*buffer, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                               VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                               VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                               VK_ACCESS_2_SHADER_STORAGE_READ_BIT |
                                   VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
        cmd.set_program(push.operation == 4 ? found->second.resumeProgram : found->second.program);
        cmd.set_storage_buffer(0, 0, *state_);
        cmd.set_storage_buffer(0, 1, *data_);
        pool.bind_output(cmd, 0, 2, reo_gpu_mesh_pool::MeshPool::Events, slice);
        cmd.set_storage_buffer(0, 3, *completion_);
        pool.bind_output(cmd, 0, 4, reo_gpu_mesh_pool::MeshPool::NativeVertices, slice);
        pool.bind_output(cmd, 0, 5, reo_gpu_mesh_pool::MeshPool::History, slice);
        cmd.set_storage_buffer(0, 6, *command_);
        cmd.push_constants(&push, 0, sizeof(push));
        cmd.dispatch(1, 1, 1);
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
    const Vulkan::Buffer& data() const {
        return *data_;
    }
    const Vulkan::Buffer& state() const {
        return *state_;
    }
    const Vulkan::Buffer& completion() const {
        return *completion_;
    }
    const Vulkan::Buffer& command() const {
        return *command_;
    }
};
class BytePatch {
    Vulkan::Device& device_;
    Vulkan::Program* program_ = nullptr;
    Vulkan::BufferHandle payload_;

  public:
    BytePatch(Vulkan::Device& device, const std::vector<uint32_t>& code) : device_(device) {
        if (code.size() < 5 || code[0] != 0x07230203)
            throw std::invalid_argument("Invalid resident byte-patch shader");
        Vulkan::ResourceLayout layout{};
        layout.sets[0].storage_buffer_mask = 7;
        for (unsigned b = 0; b < 3; ++b)
            layout.sets[0].meta[b].array_size = 1;
        layout.push_constant_size = 16;
        program_ = device_.request_program(code.data(), code.size() * 4, &layout);
        if (!program_)
            throw std::runtime_error("Resident byte-patch shader creation failed");
        Vulkan::BufferCreateInfo info{};
        info.domain = Vulkan::BufferDomain::Device;
        info.size = 4096;
        info.usage = VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_STORAGE_BUFFER_BIT;
        payload_ = device_.create_buffer(info);
        if (!payload_)
            throw std::runtime_error("Resident byte-patch payload allocation failed");
    }
    void enqueue(Vulkan::CommandBuffer& cmd, const ProgramBank& bank,
                 const Vulkan::Buffer& destination, uint32_t offset, const uint8_t* bytes,
                 uint32_t count) {
        const auto available = destination.get_create_info().size;
        if (!bytes || !count || count > 4096 || offset >= available || count > available - offset ||
            available > 16384)
            throw std::out_of_range("Ordered raw resident byte write bounds");
        std::vector<uint8_t> padded((count + 3u) & ~3u, 0);
        std::memcpy(padded.data(), bytes, count);
        cmd.buffer_barrier(*payload_, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                           VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                           VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT);
        cmd.update_buffer_inline(*payload_, 0, padded.size(), padded.data());
        cmd.buffer_barrier(*payload_, VK_PIPELINE_STAGE_TRANSFER_BIT,
                           VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                           VK_ACCESS_2_SHADER_STORAGE_READ_BIT);
        for (const auto* buffer : {&destination, &bank.completion()})
            cmd.buffer_barrier(*buffer, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                               VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                               VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                               VK_ACCESS_2_SHADER_STORAGE_READ_BIT |
                                   VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
        cmd.set_program(program_);
        cmd.set_storage_buffer(0, 0, destination);
        cmd.set_storage_buffer(0, 1, *payload_);
        cmd.set_storage_buffer(0, 2, bank.completion());
        const uint32_t push[4]{offset, count, 0, 0};
        cmd.push_constants(push, 0, sizeof(push));
        cmd.dispatch(1, 1, 1);
    }
};
class EffectValidate {
    Vulkan::Device& device_;
    Vulkan::Program* program_ = nullptr;

  public:
    EffectValidate(Vulkan::Device& device, const std::vector<uint32_t>& code) : device_(device) {
        if (code.size() < 5 || code[0] != 0x07230203)
            throw std::invalid_argument("Invalid resident effect validator shader");
        Vulkan::ResourceLayout layout{};
        layout.sets[0].storage_buffer_mask = 31;
        for (unsigned b = 0; b < 5; ++b)
            layout.sets[0].meta[b].array_size = 1;
        program_ = device_.request_program(code.data(), code.size() * 4, &layout);
        if (!program_)
            throw std::runtime_error("Resident effect validator shader creation failed");
    }
    void enqueue(Vulkan::CommandBuffer& cmd, const ProgramBank& bank,
                 const reo_gpu_mesh_pool::MeshPool& pool,
                 const reo_gpu_mesh_pool::MeshPool::Slice& slice) {
        pool.validate(slice);
        if (pool.owner() != &device_)
            throw std::invalid_argument("Foreign resident effect owner");
        for (const auto binding :
             {reo_gpu_mesh_pool::MeshPool::Events, reo_gpu_mesh_pool::MeshPool::CompletionTape,
              reo_gpu_mesh_pool::MeshPool::ExpansionStatus})
            cmd.buffer_barrier(pool.bank(binding), VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                               VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                               VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                               VK_ACCESS_2_SHADER_STORAGE_READ_BIT |
                                   VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
        cmd.buffer_barrier(bank.completion(), VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                           VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                           VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                           VK_ACCESS_2_SHADER_STORAGE_READ_BIT |
                               VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
        cmd.set_program(program_);
        pool.bind_output(cmd, 0, 0, reo_gpu_mesh_pool::MeshPool::Events, slice);
        pool.bind_output(cmd, 0, 1, reo_gpu_mesh_pool::MeshPool::CompletionTape, slice);
        cmd.set_storage_buffer(0, 2, bank.command());
        pool.bind_output(cmd, 0, 3, reo_gpu_mesh_pool::MeshPool::ExpansionStatus, slice);
        cmd.set_storage_buffer(0, 4, bank.completion());
        cmd.dispatch(1, 1, 1);
    }
};
} // namespace reo_resident_live
