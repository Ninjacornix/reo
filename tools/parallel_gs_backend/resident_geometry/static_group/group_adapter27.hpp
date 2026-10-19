#pragma once
#include "producer_pipeline27.hpp"
#include "batched_pipeline1.hpp"
#include "stream_export_pipeline.hpp"
#include <memory>
namespace reo_gpu_static_group {
struct GroupModules {
    std::array<std::vector<uint32_t>, 27> producer;
    std::array<std::vector<uint32_t>, 4> consumer;
    std::array<std::vector<uint32_t>, 2> exporter;
};
struct GroupOutput {
    std::shared_ptr<reo_gpu_batched_stream_consumer::Output> triangles;
    Vulkan::BufferHandle receipts;
    std::vector<uint64_t> launchOrdinals;
    uint64_t epoch = 0, bankGeneration = 0;
    uint32_t transactionGeneration = 0;
};
// Implemented by the separate same-Device projected-material owner. Its GPU
// pass compares the immutable preview command table to THESE sealed output
// Parameters and joins THIS producer's first-sticky before exporter admission.
class PreviewCertificate {
  public:
    virtual ~PreviewCertificate() = default;
    virtual const Vulkan::Device* owner() const = 0;
    virtual uint64_t epoch() const = 0;
    virtual uint32_t transactionGeneration() const = 0;
    virtual void recordSourceCertificate(Vulkan::CommandBuffer&,
                                         const reo_gpu_batched_stream_consumer::Inputs&,
                                         const reo_gpu_batched_stream_consumer::Output&) const = 0;
};
class GroupAdapter {
    Vulkan::Device& device_;
    Scope scope_;
    ProducerPipeline producer_;
    reo_gpu_batched_stream_consumer::Pipeline consumer_;
    reo_gpu_static_stream_export::Pipeline exporter_;
    GroupModules modules_;
    static void access(Vulkan::CommandBuffer& cmd, const Vulkan::Buffer& b,
                       VkPipelineStageFlags2 target, VkAccessFlags2 flags) {
        cmd.buffer_barrier(b, VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT,
                           VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT, target,
                           flags);
    }

  public:
    GroupAdapter(Vulkan::Device& d, GroupModules modules, uint32_t capacity, Scope scope,
                 LiveProofs proof = {}, reo_gpu_static_stream_export::Proofs exportProof = {})
        : device_(d), scope_(scope), producer_(d, modules.producer, capacity, scope, proof),
          consumer_(d, modules.consumer),
          exporter_(d, modules.exporter,
                    scope == Scope::ScopedLive
                        ? reo_gpu_static_stream_export::Scope::ScopedLive
                        : reo_gpu_static_stream_export::Scope::OfflineComponent,
                    exportProof),
          modules_(std::move(modules)) {
        constexpr const char* expected[6]{
            "e68b9c2d48ce1c908ffa72183fd98376e158ccd5d4593bfce8309088b03a1b52",
            "97d571bdad6ad73f7c86c9d09504d3edb30dda43f79e51f82905b5cab9ca0264",
            "0b7f9e0e9c940e4165760b4508d4fb8d76c0dbf474d3c8612ff04800bdefd81e",
            "e00ed6e44aabc640d375e55f4652e3a8b1f3899363728e8ba5e976beb4c0466a",
            "59d84ef0268e370520360e700b012fd8b080f952eca8de024b613934ba1b119b",
            "cef30ef928f7a1181c5738db4c580f97bcbac7c0555814a15eb9fd55f5796d65"};
        for (unsigned s = 0; s < 6; ++s) {
            const auto& code = s < 4 ? modules_.consumer[s] : modules_.exporter[s - 4];
            std::vector<uint8_t> bytes(code.size() * 4);
            std::memcpy(bytes.data(), code.data(), bytes.size());
            if (reo_gpu_catalog::sha256(bytes) != expected[s])
                throw std::invalid_argument("Static group exact consumer/export pin differs");
        }
    }
    void prewarm() {
        producer_.prewarm();
        auto cmd = device_.request_command_buffer(Vulkan::CommandBuffer::Type::Generic);
        if (!cmd)
            throw std::runtime_error("Static group consumer prewarm unavailable");
        auto compile = [&](const std::vector<uint32_t>& code) {
            Vulkan::ResourceLayout l{};
            l.sets[0].storage_buffer_mask = 255;
            l.push_constant_size = 16;
            for (unsigned b = 0; b < 8; ++b)
                l.sets[0].meta[b].array_size = 1;
            auto* p = device_.request_program(code.data(), code.size() * 4, &l);
            if (!p)
                throw std::runtime_error("Static group consumer/export module unavailable");
            cmd->set_program(p);
            Vulkan::DeferredPipelineCompile state{};
            cmd->extract_pipeline_state(state);
            auto pipeline = p->get_pipeline(state.hash);
            if (pipeline.pipeline == VK_NULL_HANDLE)
                pipeline = Vulkan::CommandBuffer::build_compute_pipeline(
                    &device_, state, Vulkan::CommandBuffer::CompileMode::Sync);
            if (pipeline.pipeline == VK_NULL_HANDLE)
                throw std::runtime_error("Static group consumer/export driver prewarm failed");
        };
        for (const auto& code : modules_.consumer)
            compile(code);
        for (const auto& code : modules_.exporter)
            compile(code);
        device_.submit(cmd);
    }
    // Material parameters MUST come from the certified same-Device projected
    // preview lease. Raw command fields remain CPU metadata; no VF/XYZ is read.
    // This helper neither creates that lease nor commits GS frontend state.
    GroupOutput record(Vulkan::CommandBuffer& cmd, const Authority& authority,
                       const TypedTape& tape,
                       std::vector<reo_gpu_batched_stream_consumer::JobParameters> materials,
                       std::vector<uint64_t> ordinals, uint64_t epoch, uint64_t bankGeneration,
                       const PreviewCertificate* preview = nullptr) {
        if (!epoch || !bankGeneration || materials.size() != tape.jobs ||
            ordinals.size() != tape.jobs)
            throw std::invalid_argument(
                "Static group immutable material/ordinal envelope mismatch");
        if (scope_ == Scope::ScopedLive &&
            (!preview || preview->owner() != &device_ || preview->epoch() != epoch ||
             preview->transactionGeneration() != tape.generation))
            throw std::invalid_argument(
                "Static group lacks its exact material preview source certificate");
        for (uint32_t j = 0; j < tape.jobs; ++j)
            if (!ordinals[j] || (j && ordinals[j] != ordinals[j - 1] + 1))
                throw std::invalid_argument("Static group launch sequence changed");
        auto output = std::make_shared<reo_gpu_batched_stream_consumer::Output>(
            device_, std::move(materials), epoch, tape.generation);
        const auto produced = producer_.record(cmd, authority, tape);
        const reo_gpu_batched_stream_consumer::Inputs in{&device_, produced.tape, produced.native,
                                                         produced.results};
        consumer_.prepare(cmd, in, *output, epoch);
        consumer_.seal(cmd, in, *output, epoch);
        if (preview)
            preview->recordSourceCertificate(cmd, in, *output);
        const reo_gpu_static_stream_export::Inputs staged{&device_,
                                                          {produced.state, 0},
                                                          {produced.data, 0},
                                                          {produced.tape, 0},
                                                          {produced.results, 0},
                                                          {&output->bank(3), 0},
                                                          tape.jobs,
                                                          tape.jobs,
                                                          tape.generation,
                                                          tape.sourceClass};
        const reo_gpu_static_stream_export::Authority authoritative{
            &device_, {authority.state, 0}, {authority.data, 0}, {authority.completion, 0}};
        exporter_.admit(cmd, staged, authoritative);
        exporter_.commit(cmd, staged, authoritative);
        consumer_.publicationGate(cmd, in, *output, epoch);
        Vulkan::BufferCreateInfo ci{};
        ci.domain = Vulkan::BufferDomain::Device;
        ci.size = uint64_t(tape.jobs) * 48;
        ci.usage = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT |
                   VK_BUFFER_USAGE_TRANSFER_DST_BIT;
        auto receipts = device_.create_buffer(ci);
        if (!receipts)
            throw std::runtime_error("Static group immutable receipt allocation failed");
        access(cmd, *receipts, VK_PIPELINE_STAGE_2_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT);
        cmd.fill_buffer(*receipts, 0);
        access(cmd, *produced.results, VK_PIPELINE_STAGE_2_TRANSFER_BIT,
               VK_ACCESS_2_TRANSFER_READ_BIT);
        access(cmd, *produced.tape, VK_PIPELINE_STAGE_2_TRANSFER_BIT,
               VK_ACCESS_2_TRANSFER_READ_BIT);
        access(cmd, *receipts, VK_PIPELINE_STAGE_2_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT);
        for (uint32_t j = 0; j < tape.jobs; ++j) {
            const uint64_t target = uint64_t(j) * 48;
            // Existing completion words0..7 are actual per-call producer receipts.
            cmd.copy_buffer(*receipts, target, *produced.results, uint64_t(64 + j * 64) * 4, 32);
            cmd.copy_buffer(*receipts, target + 32, *produced.results, 0, 4); // shared final sticky
            cmd.copy_buffer(*receipts, target + 36, *produced.tape, uint64_t(j * 65536 + 15) * 4,
                            4); // raw input N, not claimed fast count
            cmd.copy_buffer(*receipts, target + 40, *produced.results, 3 * 4, 4); // actual Mode1/2
            cmd.copy_buffer(*receipts, target + 44, *produced.tape, uint64_t(j * 65536 + 22) * 4,
                            4); // actual local ordinal
        }
        // These are immutable after recording. Producer staging may be reused only
        // after all consumer/export/copy reads above, on the same command timeline.
        return {std::move(output), std::move(receipts), std::move(ordinals), epoch,
                bankGeneration,    tape.generation};
    }
};
} // namespace reo_gpu_static_group
