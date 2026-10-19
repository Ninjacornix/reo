#pragma once
#include "consumer_pipeline.hpp"
#include "group_recording.hpp"
#include "tail_owner_adapter.hpp"
#include "resident_program_bank.hpp"
#include "../owner_timing.hpp"
#include "query_pool.hpp"
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <fstream>
namespace reo_gpu_static_consumer {
struct LiveBundle {
    bool activationRequested = false;
    uint64_t binding = 0;
    uint32_t family = 0;
    std::array<uint8_t, 16384> exactImage{};
    std::vector<uint32_t> producer, admission, commit;
    std::vector<uint32_t> pooledTail;
    // Exact static fast-ready2 order: prefix,geometry,clip,compose,selectedC.
    // Root pins all five complete modules; an empty array selects scalar C only.
    std::array<std::vector<uint32_t>, 5> fastProducer{};
    std::vector<uint32_t> fusedPipeline; // Full producer/consumer/authority pipeline,16 SSBOs.
    std::vector<uint32_t> fusedProducer; // Optional exact static four-stage composition.
    std::array<std::vector<uint32_t>, 4> consumer;
};
struct LiveJob {
    Item item;
    std::array<Vulkan::BufferHandle, 8> producerBanks;
    Vulkan::BufferHandle receipt;
    std::array<Vulkan::QueryPoolHandle, 9> stageTimes{};
    // Optional diagnostic retention of the actual pre-dispatch bank. Never a
    // replacement authority or a successful-completion certificate.
    Vulkan::BufferHandle diagnosticInput;
    std::array<uint32_t, 8> diagnosticMeta{};
    uint64_t ordinal = 0, epoch = 0, generation = 0;
};
class LivePath {
    Vulkan::Device& device_;
    ParallelGS::GSInterface& gs_;
    LiveBundle bundle_;
    Pipeline consumer_;
    TailOwner tail_;
    Vulkan::Program *producer_ = nullptr, *admission_ = nullptr, *commit_ = nullptr;
    std::array<Vulkan::BufferHandle, 8> scratch_{};
    std::array<Vulkan::Program*, 5> fast_{};
    bool hasFast_ = false;
    Vulkan::Program* fused_ = nullptr;
    Vulkan::Program* pipeline_ = nullptr;
    static void barrier(Vulkan::CommandBuffer& cmd, const Vulkan::Buffer& b,
                        VkPipelineStageFlags target, VkAccessFlags2 access) {
        cmd.buffer_barrier(b, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                           VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT, target,
                           access);
    }
    Vulkan::BufferHandle make(VkDeviceSize size) {
        Vulkan::BufferCreateInfo ci{};
        ci.domain = Vulkan::BufferDomain::Device;
        ci.size = size;
        ci.usage = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT |
                   VK_BUFFER_USAGE_TRANSFER_DST_BIT;
        auto b = device_.create_buffer(ci);
        if (!b)
            throw std::runtime_error("Multi-effect resident allocation failed");
        return b;
    }
    Vulkan::Program* load(const std::vector<uint32_t>& code, uint32_t push, unsigned buffers = 8) {
        if (code.size() < 5 || code[0] != 0x07230203u)
            throw std::invalid_argument("Unpinned multi-effect program");
        Vulkan::ResourceLayout l{};
        const uint32_t mask = (1u << buffers) - 1u;
        l.sets[0].storage_buffer_mask = mask;
        for (unsigned b = 0; b < buffers; ++b)
            l.sets[0].meta[b].array_size = 1;
        l.push_constant_size = push;
        auto* p = device_.request_program(code.data(), code.size() * 4, &l);
        if (!p || !p->get_pipeline_layout())
            throw std::runtime_error("Multi-effect program unavailable");
        const auto& a = p->get_pipeline_layout()->get_resource_layout();
        if (a.descriptor_set_mask != 1u || a.bindless_descriptor_set_mask ||
            a.sets[0].storage_buffer_mask != mask || a.push_constant_range.size != push)
            throw std::runtime_error("Multi-effect program interface mismatch");
        return p;
    }

  public:
    uint64_t binding() const {
        return bundle_.binding;
    }
    LivePath(Vulkan::Device& d, ParallelGS::GSInterface& gs, LiveBundle bundle)
        : device_(d), gs_(gs), bundle_(std::move(bundle)), consumer_(d, bundle_.consumer),
          tail_(d, gs) {
        if (!bundle_.activationRequested || !bundle_.binding)
            throw std::invalid_argument("Multi-effect resident route is default off");
        producer_ = load(bundle_.producer, 16);
        admission_ = load(bundle_.admission, 0);
        commit_ = load(bundle_.commit, 0);
        for (const auto& code : bundle_.fastProducer)
            hasFast_ |= !code.empty();
        if (hasFast_) {
            if (bundle_.family != 0x5273fa3eu)
                throw std::invalid_argument("Fast static stages cannot alias another image family");
            for (unsigned s = 0; s < 5; ++s)
                fast_[s] = load(bundle_.fastProducer[s], 16);
        }
        if (!bundle_.fusedProducer.empty()) {
            if (!hasFast_ || bundle_.family != 0x5273fa3eu)
                throw std::invalid_argument(
                    "Fused static producer requires its exact fast/fallback closure");
            fused_ = load(bundle_.fusedProducer, 16);
        }
        if (!bundle_.fusedPipeline.empty()) {
            if (!hasFast_ || bundle_.family != 0x5273fa3eu ||
                device_.get_gpu_properties().limits.maxPerStageDescriptorStorageBuffers < 16u)
                throw std::invalid_argument(
                    "Full static pipeline requires exact static closure and16 storage bindings");
            pipeline_ = load(bundle_.fusedPipeline, 16, 16);
        }
        VkDeviceSize sizes[8]{576 * 4, 8192 * 4,   65536 * 4,
                              128 * 4, 32768 * 16, hasFast_ ? 284544u * 4u : 4u,
                              256,     32};
        for (unsigned b = 0; b < 8; ++b)
            scratch_[b] = make(sizes[b]);
    }
    bool image(const std::array<uint8_t, 16384>& image) const {
        return image == bundle_.exactImage;
    }
    bool covers(const reo_resident_live::Operation& op) const {
        return op.kind == reo_resident_live::Kind::Launch && op.program && op.program->complete() &&
               op.program->accepts(op.startPC, op.resume) &&
               op.program->bindingId == bundle_.binding &&
               op.program->exactImage == bundle_.exactImage && op.program->literalSourcePreserved &&
               op.effect.type == reo_resident_live::LiteralEffect::Type::Strip &&
               op.maxPairs == 65536u && op.effect.echo[0] == 1u && op.effect.echo[4] > 32768u &&
               (op.effect.echo[4] & 32767u) <= 247u && ((op.effect.echo[5] >> 15u) & 7u) == 4u &&
               op.effect.echo[6] == 0x412u && op.effect.echo[7] == 0u && op.top < 1024u &&
               op.itop < 1024u;
    }
    std::shared_ptr<LiveJob> allocate(const reo_resident_live::Operation& op, uint64_t epoch,
                                      uint64_t generation) {
        if (!covers(op) || !epoch || !generation || generation > 0xffffffffu)
            throw std::invalid_argument("Unadmitted exact-image multi-effect launch");
        auto job = std::make_shared<LiveJob>();
        job->ordinal = op.ordinal;
        job->epoch = epoch;
        job->generation = generation;
        // All staging reads finish before publicationGate; real GS shading reads
        // only immutable per-job triangle/certificate arrays. Explicit next-use
        // barriers therefore permit one persistent scratch slot, not ~1MiB/job.
        job->producerBanks = scratch_;
        job->receipt = make(48u);
        const char* capture = std::getenv("REO_GPU_STATIC_FAILURE_DIR");
        if (capture && *capture) {
            job->diagnosticInput = make(632u + 16384u);
            job->diagnosticMeta = {0x43415556u, 1u,     632u,    16384u,
                                   op.startPC,  op.top, op.itop, op.resume ? 1u : 0u};
        }
        auto& item = job->item;
        uint32_t n = op.effect.echo[4] & 32767u;
        item.output = std::make_shared<Output>(device_, n, epoch);
        item.input = {&device_, job->producerBanks[2].get(), 0, job->producerBanks[4].get(),
                      0,        job->producerBanks[3].get()};
        item.parameters.limits = {n, 11 * n, 495, 3213};
        item.parameters.identity = {bundle_.family, 0, uint32_t(generation), 0};
        // Registry binding64 and interface marker are distinct. Root supplies the
        // marker for the pinned producer; full image equality remains mandatory.
        if (item.parameters.identity[0] != 0x5273fa3eu &&
            item.parameters.identity[0] != 0x65d42fafu &&
            item.parameters.identity[0] != 0x57026e22u)
            throw std::invalid_argument("Wrong multi-effect family marker");
        std::memcpy(item.parameters.mainTag.data(), op.effect.echo.data() + 4, 16);
        item.parameters.geometry = {op.top, op.itop, op.resume ? 4u : 0u, 65536};
        if (!tail_.admit(op.program->exactImage.data(), bundle_.exactImage.data(), 16384, item,
                         epoch))
            throw std::runtime_error("Multi-effect exact image/command metadata admission failed");
        return job;
    }
    void record(Vulkan::CommandBuffer& cmd, const reo_resident_live::ProgramBank& authority,
                const reo_resident_live::Operation& op, LiveJob& job,
                const ParallelGS::ResidentMaterial& material) {
        auto& banks = job.producerBanks;
        auto& item = job.item;
        item.parameters = tail_.parameters(material, item.parameters);
        // Bounded diagnostic timestamps; never queried until the existing producer
        // fence completes. No WAIT_BIT, no extra submit and no graphics readback.
        static const bool stageTiming = [] {
            const char* e = std::getenv("REO_GPU_STAGE_TIMING");
            return e && std::atoi(e) != 0;
        }();
        static thread_local unsigned timedJobs = 0;
        const double age =
            std::chrono::duration<double>(reo_resident_live::owner_timing::Clock::now() -
                                          reo_resident_live::owner_timing::counters.epoch)
                .count();
        const bool measure = stageTiming && hasFast_ && age >= 110.0 && timedJobs < 16;
        if (measure)
            ++timedJobs;
        const auto mark = [&](unsigned index) {
            if (measure)
                job.stageTimes[index] = cmd.write_timestamp(VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT);
        };
        mark(0);

        for (auto* b : {&authority.state(), &authority.data(), &authority.completion()})
            barrier(cmd, *b, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
        if (job.diagnosticInput) {
            barrier(cmd, *job.diagnosticInput, VK_PIPELINE_STAGE_TRANSFER_BIT,
                    VK_ACCESS_2_TRANSFER_WRITE_BIT);
            cmd.copy_buffer(*job.diagnosticInput, 0, authority.state(), 0, 632);
            cmd.copy_buffer(*job.diagnosticInput, 632, authority.data(), 0, 16384);
        }
        for (const auto& b : banks)
            barrier(cmd, *b, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT);
        cmd.copy_buffer(*banks[0], 0, authority.state(), 0, 632);
        cmd.copy_buffer(*banks[1], 0, authority.data(), 0, 16384);
        cmd.fill_buffer(*banks[3], 0);
        cmd.buffer_barrier(*banks[3], VK_PIPELINE_STAGE_TRANSFER_BIT,
                           VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT,
                           VK_ACCESS_2_TRANSFER_WRITE_BIT);
        cmd.copy_buffer(*banks[3], 0, authority.completion(), 32, 4);
        std::array<uint32_t, 64> echo{};
        std::memcpy(echo.data(), op.effect.echo.data(), 128);
        cmd.update_buffer_inline(*banks[6], 0, 256, echo.data());
        const uint32_t jobs[8]{op.startPC,          65536, op.top, op.itop,
                               op.resume ? 4u : 0u, 495,   3213,   item.parameters.identity[0]};
        cmd.update_buffer_inline(*banks[7], 0, 32, jobs);
        for (const auto& b : banks)
            barrier(cmd, *b, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                    VK_ACCESS_2_SHADER_STORAGE_READ_BIT | VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
        mark(1);
        const uint32_t push[4]{1, 1, uint32_t(job.generation), 0};
        if (pipeline_) {
            // Reuse every original owner/epoch/range/parameter guard. Only its dispatch
            // is replaced: no certificate or completion predicate is bypassed.
            consumer_.prepareParameters(cmd, item.input, *item.output, item.parameters, job.epoch);
            const Vulkan::Buffer* all[16]{
                banks[0].get(),         banks[1].get(),        banks[2].get(),
                banks[3].get(),         banks[4].get(),        banks[5].get(),
                banks[6].get(),         banks[7].get(),        &item.output->bank(4),
                &item.output->bank(0),  &item.output->bank(1), &item.output->bank(2),
                &item.output->bank(3),  &authority.state(),    &authority.data(),
                &authority.completion()};
            for (auto* b : all)
                barrier(cmd, *b, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                        VK_ACCESS_2_SHADER_STORAGE_READ_BIT | VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
            cmd.set_program(pipeline_);
            for (unsigned b = 0; b < 16; ++b)
                cmd.set_storage_buffer(0, b, *all[b]);
            cmd.push_constants(push, 0, 16);
            cmd.dispatch(1, 1, 1);
            mark(2);
            if (measure)
                for (unsigned i = 3; i < 9; ++i)
                    job.stageTimes[i] = job.stageTimes[2];
            for (unsigned b = 0; b < 3; ++b)
                barrier(cmd, item.output->bank(b), VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                        VK_ACCESS_2_MEMORY_READ_BIT);
            return;
        }
        if (fused_) {
            cmd.set_program(fused_);
            for (unsigned b = 0; b < 8; ++b)
                cmd.set_storage_buffer(0, b, *banks[b]);
            cmd.push_constants(push, 0, 16);
            cmd.dispatch(1, 1, 1);
            mark(2);
            // Prefix/geometry/clip/compose have rendezvoused inside one workgroup.
            // A genuine path2 decline still runs the unchanged complete-C GPU shader.
            for (const auto& b : banks)
                barrier(cmd, *b, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                        VK_ACCESS_2_SHADER_STORAGE_READ_BIT | VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
            mark(3);
            mark(4);
            mark(5);
            cmd.set_program(fast_[4]);
            for (unsigned b = 0; b < 8; ++b)
                cmd.set_storage_buffer(0, b, *banks[b]);
            cmd.push_constants(push, 0, 16);
            cmd.dispatch(1, 1, 1);
            mark(6);
        } else if (hasFast_) {
            for (unsigned stage = 0; stage < 5; ++stage) {
                for (const auto& b : banks)
                    barrier(cmd, *b, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                            VK_ACCESS_2_SHADER_STORAGE_READ_BIT |
                                VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
                cmd.set_program(fast_[stage]);
                for (unsigned b = 0; b < 8; ++b)
                    cmd.set_storage_buffer(0, b, *banks[b]);
                cmd.push_constants(push, 0, 16);
                cmd.dispatch(stage == 2u ? 50u : 1u, 1, 1);
                mark(stage + 2u);
            }
        } else {
            cmd.set_program(producer_);
            for (unsigned b = 0; b < 8; ++b)
                cmd.set_storage_buffer(0, b, *banks[b]);
            cmd.push_constants(push, 0, 16);
            cmd.dispatch(1, 1, 1);
        }
        consumer_.prepare(cmd, item.input, *item.output, item.parameters, job.epoch);
        consumer_.seal(cmd, item.input, *item.output, job.epoch);
        mark(7);
        const Vulkan::Buffer* all[8]{&authority.state(),    &authority.data(),      banks[0].get(),
                                     banks[1].get(),        banks[2].get(),         banks[3].get(),
                                     &item.output->bank(3), &authority.completion()};
        for (auto* p : {admission_, commit_}) {
            for (auto* b : all)
                barrier(cmd, *b, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                        VK_ACCESS_2_SHADER_STORAGE_READ_BIT | VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
            cmd.set_program(p);
            for (unsigned b = 0; b < 8; ++b)
                cmd.set_storage_buffer(0, b, *all[b]);
            cmd.dispatch(1, 1, 1);
        }
        consumer_.publicationGate(cmd, item.input, *item.output, job.epoch);
        mark(8);
    }
    void submit(const LiveJob& job, const ParallelGS::ResidentMaterial& material) {
        for (uint32_t i = 0; i < job.item.output->chunks(); ++i) {
            auto m = material;
            auto inputs = job.item.output->inputs(i, job.epoch);
            m.pass.num_primitives = inputs.primitiveCount;
            if (!gs_.submit_resident_material_projected(m, inputs))
                throw std::runtime_error("Multi-effect real GS material declined");
        }
    }
    void reportTiming(const LiveJob& job) {
        if (!job.stageTimes[8])
            return;
        uint64_t ticks[9]{};
        for (unsigned i = 0; i < 9; ++i) {
            const auto& q = job.stageTimes[i];
            if (!q)
                return;
            if (device_.get_device_table().vkGetQueryPoolResults(
                    device_.get_device(), q->get_query_pool(), q->get_query_pool_index(), 1,
                    sizeof(uint64_t), ticks + i, sizeof(uint64_t),
                    VK_QUERY_RESULT_64_BIT) != VK_SUCCESS)
                return;
        }
        const char* names[]{"upload",   pipeline_ ? "pipeline" : fused_ ? "fused" : "prefix",
                            "geometry", "clip",
                            "compose",  "selectedC",
                            "consumer", "authority"};
        std::fprintf(stderr, "[GPU-STAGE-TIMING] ordinal=%llu total_us=%.3f",
                     static_cast<unsigned long long>(job.ordinal),
                     device_.convert_device_timestamp_delta(ticks[0], ticks[8]) * 1e6);
        for (unsigned i = 0; i < 8; ++i)
            std::fprintf(stderr, " %s_us=%.3f", names[i],
                         device_.convert_device_timestamp_delta(ticks[i], ticks[i + 1]) * 1e6);
        std::fprintf(stderr, "\n");
    }
    bool retire(const LiveJob& job, const reo_resident_live::Retired& receipt) {
        return tail_.retire(job.item, receipt, job.generation, job.ordinal);
    }
    void captureFailure(const LiveJob& job) {
        const char* directory = std::getenv("REO_GPU_STATIC_FAILURE_DIR");
        if (!directory || !*directory || !job.diagnosticInput)
            return;
        Vulkan::BufferCreateInfo ci{};
        ci.domain = Vulkan::BufferDomain::CachedHost;
        ci.size = 632u + 16384u;
        ci.usage = VK_BUFFER_USAGE_TRANSFER_DST_BIT;
        auto readback = device_.create_buffer(ci);
        if (!readback)
            throw std::runtime_error("Failure capture allocation failed");
        auto cmd = device_.request_command_buffer();
        barrier(*cmd, *job.diagnosticInput, VK_PIPELINE_STAGE_TRANSFER_BIT,
                VK_ACCESS_2_TRANSFER_READ_BIT);
        cmd->copy_buffer(*readback, 0, *job.diagnosticInput, 0, ci.size);
        cmd->buffer_barrier(*readback, VK_PIPELINE_STAGE_TRANSFER_BIT,
                            VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_HOST_BIT,
                            VK_ACCESS_2_HOST_READ_BIT);
        Vulkan::Fence fence;
        device_.submit(cmd, &fence);
        fence->wait();
        const auto* bytes = static_cast<const uint8_t*>(
            device_.map_host_buffer(*readback, Vulkan::MEMORY_ACCESS_READ_BIT));
        if (!bytes)
            throw std::runtime_error("Failure capture mapping failed");
        try {
            const auto base =
                std::filesystem::path(directory) / ("ordinal-" + std::to_string(job.ordinal));
            std::filesystem::create_directories(base.parent_path());
            const auto save = [&](const char* suffix, const void* data, size_t size) {
                const auto path = base.string() + suffix;
                if (std::filesystem::exists(path))
                    throw std::runtime_error("Preserve existing static failure capture");
                std::ofstream out(path, std::ios::binary);
                out.write(static_cast<const char*>(data), size);
                if (!out)
                    throw std::runtime_error("Static failure capture write failed");
            };
            auto captureMeta = job.diagnosticMeta;
            if (captureMeta[7])
                std::memcpy(&captureMeta[4], bytes + 604, 4);
            save(".code.bin", bundle_.exactImage.data(), bundle_.exactImage.size());
            save(".state.bin", bytes, 632);
            save(".data.bin", bytes + 632, 16384);
            save(".meta.bin", captureMeta.data(), 32);
            save(".dispatch-meta.bin", job.diagnosticMeta.data(), 32);
            std::fprintf(stderr, "[GPU-STATIC-FAILURE-CAPTURE] ordinal=%llu prefix=%s\n",
                         static_cast<unsigned long long>(job.ordinal), base.string().c_str());
        } catch (...) {
            device_.unmap_host_buffer(*readback, Vulkan::MEMORY_ACCESS_READ_BIT);
            throw;
        }
        device_.unmap_host_buffer(*readback, Vulkan::MEMORY_ACCESS_READ_BIT);
    }
};
} // namespace reo_gpu_static_consumer
