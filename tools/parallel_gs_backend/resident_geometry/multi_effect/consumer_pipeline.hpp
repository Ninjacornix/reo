#pragma once
#include "device.hpp"
#include "command_buffer.hpp"
#include "resident_draw.hpp"
#include "consumer_cert.hpp"
#include <algorithm>
#include <array>
#include <cstring>
#include <stdexcept>
#include <vector>
namespace reo_gpu_static_consumer {
struct alignas(16) Parameters {
    std::array<uint32_t, 4> limits{}, identity{}, mainTag{}, geometry{};
    std::array<int32_t, 4> offsetScissorLo{}, scissorHi{};
    std::array<uint32_t, 8> material{};
};
static_assert(sizeof(Parameters) == 128);
// All three input views belong to the same producer Device and remain alive
// through real GS retirement. No graphical data are mapped or returned.
struct Inputs {
    const Vulkan::Device* owner = nullptr;
    const Vulkan::Buffer* tape = nullptr;
    VkDeviceSize tapeOffset = 0;
    const Vulkan::Buffer* native = nullptr;
    VkDeviceSize nativeOffset = 0;
    const Vulkan::Buffer* results = nullptr;
};
class Output {
    Vulkan::Device& device_;
    std::array<Vulkan::BufferHandle, 5> banks_{}; //positions/attributes/primitives/cert/parameters
    uint32_t capacity_ = 0, rawVertices_ = 0;
    uint64_t epoch_ = 0;
    Vulkan::BufferHandle allocate(VkDeviceSize size) {
        Vulkan::BufferCreateInfo ci{};
        ci.domain = Vulkan::BufferDomain::Device;
        ci.size = size;
        ci.usage = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT |
                   VK_BUFFER_USAGE_TRANSFER_DST_BIT;
        auto b = device_.create_buffer(ci);
        if (!b)
            throw std::runtime_error("Static output allocation failed");
        return b;
    }

  public:
    Output(Vulkan::Device& d, uint32_t rawVertices, uint64_t epoch)
        : device_(d), capacity_(11u * rawVertices), rawVertices_(rawVertices), epoch_(epoch) {
        if (!epoch || !rawVertices || rawVertices > 247u)
            throw std::invalid_argument("Unbounded static output");
        banks_[0] = allocate(VkDeviceSize(capacity_) * 3u * 16u);
        banks_[1] = allocate(VkDeviceSize(capacity_) * 3u * 24u);
        banks_[2] = allocate(VkDeviceSize(capacity_) * 32u);
        banks_[3] = allocate(Words * 4u);
        banks_[4] = allocate(sizeof(Parameters));
    }
    const Vulkan::Device* owner() const {
        return &device_;
    }
    const Vulkan::Buffer& bank(unsigned b) const {
        return *banks_.at(b);
    }
    uint32_t capacity() const {
        return capacity_;
    }
    uint32_t rawVertices() const {
        return rawVertices_;
    }
    uint64_t epoch() const {
        return epoch_;
    }
    uint32_t chunks() const {
        return (capacity_ + 255u) / 256u;
    }
    ParallelGS::ResidentPrimitiveInputs inputs(uint32_t chunk, uint64_t expectedEpoch) const {
        if (expectedEpoch != epoch_ || chunk >= chunks())
            throw std::invalid_argument("Stale/unbounded static draw slice");
        uint32_t first = chunk * 256u, count = std::min(256u, capacity_ - first);
        ParallelGS::ResidentPrimitiveInputs in{};
        in.owner = &device_;
        in.positions = banks_[0];
        in.attributes = banks_[1];
        in.primitives = banks_[2];
        in.positionOffset = VkDeviceSize(first) * 3u * 16u;
        in.attributeOffset = VkDeviceSize(first) * 3u * 24u;
        in.primitiveOffset = VkDeviceSize(first) * 32u;
        in.primitiveCount = count;
        in.exactFixedTopologyCertificate = true;
        return in;
    }
};
class Pipeline {
    Vulkan::Device& device_;
    std::array<Vulkan::Program*, 4> programs_{};
    static void access(Vulkan::CommandBuffer& cmd, const Vulkan::Buffer& buffer,
                       VkPipelineStageFlags target, VkAccessFlags2 flags) {
        cmd.buffer_barrier(buffer, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                           VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT, target,
                           flags);
    }

  public:
    // Module order is validate_tape,expand_tape,seal_consumer,publication_gate.
    // Caller pins exact
    // immutable source/SPV closure before constructing this private Pipeline.
    Pipeline(Vulkan::Device& d, const std::array<std::vector<uint32_t>, 4>& modules) : device_(d) {
        Vulkan::ResourceLayout layout{};
        layout.sets[0].storage_buffer_mask = 255u;
        for (unsigned b = 0; b < 8; ++b)
            layout.sets[0].meta[b].array_size = 1;
        for (unsigned s = 0; s < 4; ++s) {
            const auto& code = modules[s];
            if (code.size() < 5 || code[0] != 0x07230203u)
                throw std::invalid_argument("Invalid static consumer module");
            auto* p = device_.request_program(code.data(), code.size() * 4, &layout);
            if (!p || !p->get_pipeline_layout())
                throw std::runtime_error("Static consumer program creation failed");
            const auto& a = p->get_pipeline_layout()->get_resource_layout();
            if (a.descriptor_set_mask != 1u || a.bindless_descriptor_set_mask ||
                a.sets[0].storage_buffer_mask != 255u || a.push_constant_range.size ||
                a.stages_for_sets[0] != VK_SHADER_STAGE_COMPUTE_BIT)
                throw std::runtime_error("Static consumer interface mismatch");
            for (unsigned b = 0; b < 8; ++b)
                if (a.sets[0].meta[b].array_size != 1u ||
                    a.stages_for_bindings[0][b] != VK_SHADER_STAGE_COMPUTE_BIT)
                    throw std::runtime_error("Static consumer binding mismatch");
            programs_[s] = p;
        }
    }
    void prepareParameters(Vulkan::CommandBuffer& cmd, const Inputs& in, Output& out,
                           const Parameters& p, uint64_t epoch) {
        if (in.owner != &device_ || out.owner() != &device_ || out.epoch() != epoch || !in.tape ||
            !in.native || !in.results || p.limits[0] != out.rawVertices() ||
            p.limits[1] != out.capacity() || !p.limits[2] || p.limits[2] > 495u ||
            p.limits[3] != 3213u ||
            (p.identity[0] != 0x5273fa3eu && p.identity[0] != 0x65d42fafu &&
             p.identity[0] != 0x57026e22u) ||
            p.identity[1] != 0u || !p.identity[2] || p.identity[3] >= 128u ||
            p.geometry[0] >= 1024u || p.geometry[1] >= 1024u ||
            (p.geometry[2] != 0u && p.geometry[2] != 3u && p.geometry[2] != 4u &&
             p.geometry[2] != 5u) ||
            p.geometry[3] != 65536u)
            throw std::invalid_argument("Invalid static consumer owner/metadata");
        const auto alignment = device_.get_gpu_properties().limits.minStorageBufferOffsetAlignment;
        auto bounded = [&](const Vulkan::Buffer& b, VkDeviceSize offset, VkDeviceSize size) {
            const auto& ci = b.get_create_info();
            return (!alignment || offset % alignment == 0) && offset <= ci.size &&
                   size <= ci.size - offset && ci.domain == Vulkan::BufferDomain::Device &&
                   (ci.usage & VK_BUFFER_USAGE_STORAGE_BUFFER_BIT);
        };
        if (!bounded(*in.tape, in.tapeOffset, 65536u * 4u) ||
            !bounded(*in.native, in.nativeOffset, 32768u * 16u) ||
            !bounded(*in.results, 0, 64u * 4u))
            throw std::invalid_argument("Static producer view out of bounds");
        access(cmd, out.bank(4), VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT);
        cmd.update_buffer_inline(out.bank(4), 0, sizeof(p), &p);
    }
    void prepare(Vulkan::CommandBuffer& cmd, const Inputs& in, Output& out, const Parameters& p,
                 uint64_t epoch) {
        prepareParameters(cmd, in, out, p, epoch);
        const Vulkan::Buffer* all[8]{in.tape,      in.native,    in.results,   &out.bank(4),
                                     &out.bank(0), &out.bank(1), &out.bank(2), &out.bank(3)};
        for (unsigned s = 0; s < 2; ++s) {
            for (const auto* b : all)
                access(cmd, *b, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                       VK_ACCESS_2_SHADER_STORAGE_READ_BIT | VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
            cmd.set_program(programs_[s]);
            cmd.set_storage_buffer(0, 0, *in.tape, in.tapeOffset, 65536u * 4u);
            cmd.set_storage_buffer(0, 1, *in.native, in.nativeOffset, 32768u * 16u);
            cmd.set_storage_buffer(0, 2, *in.results);
            for (unsigned b = 3; b < 8; ++b)
                cmd.set_storage_buffer(0, b, *all[b]);
            cmd.dispatch(s == 1 ? (out.capacity() + 63u) / 64u : 1u, 1, 1);
        }
    }
    // Call only AFTER prepare has completed recording for every job sharing the
    // producer's sticky word. A later malformed job must blank earlier output.
    void seal(Vulkan::CommandBuffer& cmd, const Inputs& in, Output& out, uint64_t epoch) {
        if (in.owner != &device_ || out.owner() != &device_ || out.epoch() != epoch || !in.tape ||
            !in.native || !in.results)
            throw std::invalid_argument("Stale static sealing owner");
        const Vulkan::Buffer* all[8]{in.tape,      in.native,    in.results,   &out.bank(4),
                                     &out.bank(0), &out.bank(1), &out.bank(2), &out.bank(3)};
        for (const auto* b : all)
            access(cmd, *b, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                   VK_ACCESS_2_SHADER_STORAGE_READ_BIT | VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
        cmd.set_program(programs_[2]);
        cmd.set_storage_buffer(0, 0, *in.tape, in.tapeOffset, 65536u * 4u);
        cmd.set_storage_buffer(0, 1, *in.native, in.nativeOffset, 32768u * 16u);
        cmd.set_storage_buffer(0, 2, *in.results);
        for (unsigned b = 3; b < 8; ++b)
            cmd.set_storage_buffer(0, b, *all[b]);
        cmd.dispatch(1, 1, 1);
        // Only after ALL sealing passes may the producer validate every certificate
        // and export authority. GS shading follows that guarded group export.
        access(cmd, out.bank(3), VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
               VK_ACCESS_2_SHADER_STORAGE_READ_BIT);
    }
    void publicationGate(Vulkan::CommandBuffer& cmd, const Inputs& in, Output& out,
                         uint64_t epoch) {
        if (in.owner != &device_ || out.owner() != &device_ || out.epoch() != epoch || !in.tape ||
            !in.native || !in.results)
            throw std::invalid_argument("Stale static publication owner");
        const Vulkan::Buffer* all[8]{in.tape,      in.native,    in.results,   &out.bank(4),
                                     &out.bank(0), &out.bank(1), &out.bank(2), &out.bank(3)};
        for (const auto* b : all)
            access(cmd, *b, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                   VK_ACCESS_2_SHADER_STORAGE_READ_BIT | VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
        cmd.set_program(programs_[3]);
        cmd.set_storage_buffer(0, 0, *in.tape, in.tapeOffset, 65536u * 4u);
        cmd.set_storage_buffer(0, 1, *in.native, in.nativeOffset, 32768u * 16u);
        cmd.set_storage_buffer(0, 2, *in.results);
        for (unsigned b = 3; b < 8; ++b)
            cmd.set_storage_buffer(0, b, *all[b]);
        cmd.dispatch(1, 1, 1);
        for (unsigned b = 0; b < 3; ++b)
            access(cmd, out.bank(b), VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                   VK_ACCESS_2_MEMORY_READ_BIT);
    }
};
} // namespace reo_gpu_static_consumer
