#pragma once
#include "producer_contract27.hpp"
#include "command_buffer.hpp"
#include "device.hpp"
#include "tools/parallel_gs_backend/resident_geometry/enrollment/sha256.hpp"
#include <cstring>
#include <stdexcept>
#include <vector>
namespace reo_gpu_static_group {
struct Authority {
    const Vulkan::Device* owner = nullptr;
    const Vulkan::Buffer *state = nullptr, *data = nullptr, *completion = nullptr;
};
struct TypedTape {
    const Vulkan::Device* owner = nullptr;
    const Vulkan::Buffer* upload = nullptr;
    uint32_t words = 0, jobs = 0, raw = 0, generation = 0, sourceClass = 0;
};
struct ProducerViews {
    const Vulkan::Device* owner = nullptr;
    const Vulkan::Buffer *state = nullptr, *data = nullptr, *tape = nullptr, *results = nullptr,
                         *native = nullptr;
    uint32_t jobs = 0, generation = 0;
};
class ProducerPipeline {
    Vulkan::Device& device_;
    Scope scope_;
    LiveProofs proof_;
    uint32_t capacity_;
    std::array<Vulkan::Program*, 27> programs_{};
    std::array<Vulkan::BufferHandle, 8> banks_{};
    static constexpr uint32_t StateSeed = 73728, DataSeed = 1048576, DataFinal = 1052672,
                              PreDataBase = 1056768, ScratchWords = 39175168;
    static constexpr uint32_t MaxTapeWords = 16 + 128 * 16 + 32768 * 12 + 63 + 128 * 64;
    static void access(Vulkan::CommandBuffer& cmd, const Vulkan::Buffer& b,
                       VkPipelineStageFlags2 target, VkAccessFlags2 flags) {
        cmd.buffer_barrier(b, VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT,
                           VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT, target,
                           flags);
    }
    bool bounded(const Vulkan::Buffer* b, uint64_t size, VkBufferUsageFlags flags) const {
        return b && b->get_create_info().domain == Vulkan::BufferDomain::Device &&
               b->get_create_info().size >= size && (b->get_create_info().usage & flags) == flags;
    }

  public:
    ProducerPipeline(Vulkan::Device& d, const std::array<std::vector<uint32_t>, 27>& modules,
                     uint32_t capacity, Scope scope, LiveProofs proof = {})
        : device_(d), scope_(scope), proof_(proof), capacity_(capacity) {
        if (!capacity || capacity > 128 || (scope == Scope::ScopedLive && !proof.complete()))
            throw std::invalid_argument("Static group producer live scope is default off");
        Vulkan::ResourceLayout layout{};
        layout.sets[0].storage_buffer_mask = 255;
        layout.push_constant_size = 16;
        for (unsigned b = 0; b < 8; ++b)
            layout.sets[0].meta[b].array_size = 1;
        for (unsigned s = 0; s < 27; ++s) {
            const auto& code = modules[s];
            if (code.size() < 5 || code[0] != 0x07230203)
                throw std::invalid_argument("Static group module missing");
            std::vector<uint8_t> bytes(code.size() * 4);
            std::memcpy(bytes.data(), code.data(), bytes.size());
            if (reo_gpu_catalog::sha256(bytes) != StageHashes[s])
                throw std::invalid_argument("Static group exact27 module pin differs");
            auto* p = d.request_program(code.data(), bytes.size(), &layout);
            if (!p || !p->get_pipeline_layout())
                throw std::runtime_error("Static group program unavailable");
            const auto& a = p->get_pipeline_layout()->get_resource_layout();
            if (a.descriptor_set_mask != 1 || a.bindless_descriptor_set_mask ||
                a.sets[0].storage_buffer_mask != 255 || a.push_constant_range.offset ||
                a.push_constant_range.size != 16)
                throw std::invalid_argument("Static group shader interface mismatch");
            for (unsigned b = 0; b < 8; ++b)
                if (a.sets[0].meta[b].array_size != 1 ||
                    a.stages_for_bindings[0][b] != VK_SHADER_STAGE_COMPUTE_BIT)
                    throw std::invalid_argument("Static group shader binding mismatch");
            programs_[s] = p;
        }
        const std::array<uint64_t, 8> sizes{
            uint64_t(StateSeed + 158) * 4,   uint64_t(PreDataBase + 128 * 4096) * 4,
            uint64_t(capacity) * 65536 * 4,  (64 + 128 * 64) * 4,
            uint64_t(capacity) * 32768 * 16, uint64_t(ScratchWords) * 4,
            uint64_t(MaxTapeWords) * 4,      uint64_t(capacity) * 32};
        for (unsigned b = 0; b < 8; ++b) {
            if (sizes[b] > d.get_gpu_properties().limits.maxStorageBufferRange)
                throw std::invalid_argument("Static group allocation exceeds actual storage range");
            Vulkan::BufferCreateInfo ci{};
            ci.domain = Vulkan::BufferDomain::Device;
            ci.size = sizes[b];
            ci.usage = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT |
                       VK_BUFFER_USAGE_TRANSFER_DST_BIT;
            banks_[b] = d.create_buffer(ci);
            if (!banks_[b])
                throw std::runtime_error("Static group Device allocation failed");
        }
    }
    // Same Device/cache driver prewarm, copied from the actual bootstrap method.
    // This compiles pipelines and records no dispatch, descriptors or guest work.
    void prewarm() {
        auto cmd = device_.request_command_buffer(Vulkan::CommandBuffer::Type::Generic);
        if (!cmd)
            throw std::runtime_error("Static group prewarm command unavailable");
        for (auto* p : programs_) {
            cmd->set_program(p);
            Vulkan::DeferredPipelineCompile state{};
            cmd->extract_pipeline_state(state);
            auto pipeline = p->get_pipeline(state.hash);
            if (pipeline.pipeline == VK_NULL_HANDLE)
                pipeline = Vulkan::CommandBuffer::build_compute_pipeline(
                    &device_, state, Vulkan::CommandBuffer::CompileMode::Sync);
            if (pipeline.pipeline == VK_NULL_HANDLE)
                throw std::runtime_error("Static group driver prewarm failed");
        }
        device_.submit(cmd); // Empty ordinary lifecycle, no guest work or semantic completion.
    }
    ProducerViews record(Vulkan::CommandBuffer& cmd, const Authority& authority,
                         const TypedTape& tape) {
        if (authority.owner != &device_ || tape.owner != &device_ || !tape.upload || !tape.jobs ||
            tape.jobs > capacity_ || tape.raw > 32768 || !tape.generation || tape.words < 16 ||
            tape.words > MaxTapeWords ||
            (scope_ == Scope::ScopedLive ? (tape.sourceClass != 2 || !proof_.complete())
                                         : tape.sourceClass != 1) ||
            !(tape.upload->get_create_info().usage & VK_BUFFER_USAGE_TRANSFER_SRC_BIT) ||
            uint64_t(tape.words) * 4 > tape.upload->get_create_info().size ||
            !bounded(authority.state, 632,
                     VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT) ||
            !bounded(authority.data, 16384,
                     VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT) ||
            !bounded(authority.completion, 48,
                     VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT))
            throw std::invalid_argument("Static group foreign/stale/unbounded typed authority");
        // Clear and copy on THIS GS-owned command, preserving the proved init order.
        // There is no CPU VU state, per-job snapshot, readback or completion shortcut.
        for (unsigned b = 0; b < 8; ++b)
            if (b != 6) {
                access(cmd, *banks_[b], VK_PIPELINE_STAGE_2_TRANSFER_BIT,
                       VK_ACCESS_2_TRANSFER_WRITE_BIT);
                cmd.fill_buffer(*banks_[b], 0);
            }
        for (auto* b : {authority.state, authority.data, authority.completion})
            access(cmd, *b, VK_PIPELINE_STAGE_2_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
        for (unsigned b : {0u, 1u, 3u})
            access(cmd, *banks_[b], VK_PIPELINE_STAGE_2_TRANSFER_BIT,
                   VK_ACCESS_2_TRANSFER_WRITE_BIT);
        cmd.copy_buffer(*banks_[0], StateSeed * 4, *authority.state, 0, 632);
        cmd.copy_buffer(*banks_[1], DataSeed * 4, *authority.data, 0, 16384);
        cmd.copy_buffer(*banks_[3], 0, *authority.completion, 32, 4);
        access(cmd, *tape.upload, VK_PIPELINE_STAGE_2_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
        access(cmd, *banks_[6], VK_PIPELINE_STAGE_2_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT);
        cmd.copy_buffer(*banks_[6], 0, *tape.upload, 0, uint64_t(tape.words) * 4);
        const uint32_t push[4]{tape.jobs, capacity_, tape.generation, tape.words};
        for (unsigned s = 0; s < 27; ++s) {
            for (const auto& b : banks_)
                access(cmd, *b, VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT,
                       VK_ACCESS_2_SHADER_STORAGE_READ_BIT | VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
            cmd.set_program(programs_[s]);
            for (unsigned b = 0; b < 8; ++b)
                cmd.set_storage_buffer(0, b, *banks_[b]);
            cmd.push_constants(push, 0, 16);
            cmd.dispatch(grid(s, tape.jobs, tape.raw), 1, 1);
        }
        return {&device_,        banks_[0].get(), banks_[1].get(), banks_[2].get(),
                banks_[3].get(), banks_[4].get(), tape.jobs,       tape.generation};
    }
    // Group consumer/export must finish all reads before the next record call.
    // GS shading retains only its immutable triangles/certificates/receipts.
    const Vulkan::Buffer& results() const {
        return *banks_[3];
    }
};
} // namespace reo_gpu_static_group
