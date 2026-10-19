#pragma once
#include "batched_stream_abi.hpp"
#include "device.hpp"
#include "command_buffer.hpp"
#include "resident_draw.hpp"
#include <algorithm>
#include <functional>
#include <stdexcept>
#include <vector>

namespace reo_gpu_batched_stream_consumer {
struct Inputs {
    const Vulkan::Device* owner = nullptr;
    const Vulkan::Buffer *tape = nullptr, *native = nullptr, *results = nullptr;
};
class Output {
    Vulkan::Device& device_;
    std::array<Vulkan::BufferHandle, 5> banks_{};
    std::vector<JobParameters> parameters_;
    uint64_t epoch_ = 0;
    uint32_t generation_ = 0, maxSlots_ = 0;

  public:
    Output(Vulkan::Device& d, std::vector<JobParameters> parameters, uint64_t epoch,
           uint32_t generation)
        : device_(d), parameters_(std::move(parameters)), epoch_(epoch), generation_(generation) {
        if (parameters_.empty() || parameters_.size() > MaxJobs || !epoch || !generation)
            throw std::invalid_argument("Invalid batched consumer generation/count");
        const auto alignment = d.get_gpu_properties().limits.minStorageBufferOffsetAlignment;
        if (!alignment || OutputAlignment % alignment)
            throw std::invalid_argument(
                "GS slice padding does not satisfy Device storage alignment");
        const uint32_t jobs = uint32_t(parameters_.size());
        for (uint32_t job = 0; job < jobs; ++job) {
            const auto& p = parameters_[job];
            const uint32_t n = p.fixed[0], capacity = p.fixed[1], kind = p.source[0];
            if (p.fixed[4] != 0x5273fa3eu || p.fixed[5] || p.fixed[6] != generation ||
                p.fixed[7] != job || kind > 2 || p.source[2] != jobs || p.source[3] ||
                p.source[4] != ABI || p.source[5] != Version || p.source[6] != 64 || p.source[7] ||
                capacity > MaxTriangles ||
                (kind == 1 ? (n == 0 || n > MaxRawVertices || capacity != 11 * n)
                           : (n != 0 || capacity != 0)))
                throw std::invalid_argument("Unbounded/unordered raw batched consumer metadata");
            for (auto reserved : p.reserved)
                if (reserved)
                    throw std::invalid_argument("Reserved batched metadata");
            maxSlots_ = std::max(maxSlots_, capacity);
        }
        const auto sizes = outputBytes(jobs);
        for (unsigned b = 0; b < 5; ++b) {
            if (sizes[b] > d.get_gpu_properties().limits.maxStorageBufferRange)
                throw std::invalid_argument("Batched output exceeds actual SSBO range");
            Vulkan::BufferCreateInfo ci{};
            ci.domain = Vulkan::BufferDomain::Device;
            ci.size = sizes[b];
            ci.usage = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT |
                       VK_BUFFER_USAGE_TRANSFER_DST_BIT;
            banks_[b] = d.create_buffer(ci);
            if (!banks_[b])
                throw std::runtime_error("Batched immutable output allocation failed");
        }
    }
    const Vulkan::Device* owner() const {
        return &device_;
    }
    uint64_t epoch() const {
        return epoch_;
    }
    uint32_t jobs() const {
        return uint32_t(parameters_.size());
    }
    uint32_t generation() const {
        return generation_;
    }
    uint32_t maximumSlots() const {
        return maxSlots_;
    }
    const Vulkan::Buffer& bank(unsigned b) const {
        return *banks_.at(b);
    }
    const std::vector<JobParameters>& parameters() const {
        return parameters_;
    }
    uint32_t chunks(uint32_t job) const {
        if (job >= jobs())
            throw std::out_of_range("Batched job");
        return (parameters_[job].fixed[1] + 255u) / 256u;
    }
    ParallelGS::ResidentPrimitiveInputs inputs(uint32_t job, uint32_t chunk, uint64_t epoch) const {
        if (epoch != epoch_ || job >= jobs() || chunk >= chunks(job) ||
            parameters_[job].source[0] != 1u)
            throw std::invalid_argument("Stale/unproved batched geometry view");
        ParallelGS::ResidentPrimitiveInputs in{};
        in.owner = &device_;
        in.positions = banks_[0];
        in.attributes = banks_[1];
        in.primitives = banks_[2];
        in.positionOffset = positionOffset(job, chunk);
        in.attributeOffset = attributeOffset(job, chunk);
        in.primitiveOffset = primitiveOffset(job, chunk);
        in.primitiveCount = std::min(256u, parameters_[job].fixed[1] - chunk * 256u);
        in.exactFixedTopologyCertificate = true;
        return in;
    }
};
class Pipeline {
    Vulkan::Device& device_;
    std::array<Vulkan::Program*, 4> programs_{};
    std::function<void(unsigned, bool, Vulkan::CommandBuffer&)> timestampHook_;
    static void access(Vulkan::CommandBuffer& c, const Vulkan::Buffer& b,
                       VkPipelineStageFlags2 target, VkAccessFlags2 flags) {
        c.buffer_barrier(b, VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT,
                         VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT, target, flags);
    }
    void check(const Inputs& in, const Output& out, uint64_t epoch) const {
        if (in.owner != &device_ || out.owner() != &device_ || epoch != out.epoch() || !in.tape ||
            !in.native || !in.results)
            throw std::invalid_argument("Foreign/stale batched consumer ownership");
        const uint64_t count = out.jobs();
        const Vulkan::Buffer* b[3]{in.tape, in.native, in.results};
        const uint64_t need[3]{count * TapeWords * 4, count * NativeUvec4 * 16,
                               (64 + count * 64) * 4};
        for (unsigned i = 0; i < 3; ++i) {
            const auto& ci = b[i]->get_create_info();
            if (ci.domain != Vulkan::BufferDomain::Device ||
                !(ci.usage & VK_BUFFER_USAGE_STORAGE_BUFFER_BIT) || ci.size < need[i] ||
                ci.size > device_.get_gpu_properties().limits.maxStorageBufferRange)
                throw std::invalid_argument("Batched producer view out of bounds");
        }
    }
    void stage(Vulkan::CommandBuffer& c, const Inputs& in, Output& out, unsigned stage) {
        const Vulkan::Buffer* b[8]{in.tape,      in.native,    in.results,   &out.bank(4),
                                   &out.bank(0), &out.bank(1), &out.bank(2), &out.bank(3)};
        for (auto* value : b)
            access(c, *value, VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT,
                   VK_ACCESS_2_SHADER_STORAGE_READ_BIT | VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
        const Push push{out.jobs(), out.jobs(), out.maximumSlots(), out.generation()};
        c.set_program(programs_[stage]);
        for (unsigned i = 0; i < 8; ++i)
            c.set_storage_buffer(0, i, *b[i]);
        c.push_constants(&push, 0, sizeof(push));
        if (timestampHook_)
            timestampHook_(stage, true, c);
        if (stage == 1)
            c.dispatch(std::max(1u, (out.maximumSlots() + 63) / 64), out.jobs(), 1);
        else
            c.dispatch(out.jobs(), 1, 1);
        if (timestampHook_)
            timestampHook_(stage, false, c);
    }

  public:
    void setTimestampHook(std::function<void(unsigned, bool, Vulkan::CommandBuffer&)> hook) {
        timestampHook_ = std::move(hook);
    }
    Pipeline(Vulkan::Device& d, const std::array<std::vector<uint32_t>, 4>& modules) : device_(d) {
        Vulkan::ResourceLayout l{};
        l.sets[0].storage_buffer_mask = 255;
        for (unsigned b = 0; b < 8; ++b)
            l.sets[0].meta[b].array_size = 1;
        l.push_constant_size = 16;
        for (unsigned s = 0; s < 4; ++s) {
            const auto& code = modules[s];
            if (code.size() < 5 || code[0] != 0x07230203u)
                throw std::invalid_argument("Invalid batched consumer SPV");
            programs_[s] = d.request_program(code.data(), code.size() * 4, &l);
            if (!programs_[s] || !programs_[s]->get_pipeline_layout())
                throw std::runtime_error("Batched consumer program unavailable");
            const auto& a = programs_[s]->get_pipeline_layout()->get_resource_layout();
            if (a.descriptor_set_mask != 1u || a.bindless_descriptor_set_mask ||
                a.sets[0].storage_buffer_mask != 255u || a.push_constant_range.size != 16u)
                throw std::invalid_argument("Batched consumer interface differs");
            for (unsigned b = 0; b < 8; ++b)
                if (a.sets[0].meta[b].array_size != 1u ||
                    a.stages_for_bindings[0][b] != VK_SHADER_STAGE_COMPUTE_BIT)
                    throw std::invalid_argument("Batched consumer binding differs");
        }
    }
    // Exactly two passes for ALL jobs; raw Parameters/Echo upload is one command.
    void prepare(Vulkan::CommandBuffer& c, const Inputs& in, Output& out, uint64_t epoch) {
        check(in, out, epoch);
        access(c, out.bank(4), VK_PIPELINE_STAGE_2_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT);
        c.update_buffer_inline(out.bank(4), 0, out.parameters().size() * sizeof(JobParameters),
                               out.parameters().data());
        stage(c, in, out, 0);
        stage(c, in, out, 1);
    }
    void seal(Vulkan::CommandBuffer& c, const Inputs& in, Output& out, uint64_t epoch) {
        check(in, out, epoch);
        stage(c, in, out, 2);
    }
    // Caller records frozen group_admission and group_commit BETWEEN seal and
    // publicationGate, directly using out.bank(3) packed1048-word certificates.
    void publicationGate(Vulkan::CommandBuffer& c, const Inputs& in, Output& out, uint64_t epoch) {
        check(in, out, epoch);
        stage(c, in, out, 3);
        for (unsigned b = 0; b < 3; ++b)
            access(c, out.bank(b), VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT,
                   VK_ACCESS_2_MEMORY_READ_BIT);
    }
};
} // namespace reo_gpu_batched_stream_consumer
