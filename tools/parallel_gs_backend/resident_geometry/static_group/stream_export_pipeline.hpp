#pragma once
#include "stream_export_abi.hpp"
#include "tools/parallel_gs_backend/resident_geometry/enrollment/sha256.hpp"
#include "command_buffer.hpp"
#include "device.hpp"
#include <array>
#include <cstring>
#include <stdexcept>
#include <string>
#include <vector>
namespace reo_gpu_static_stream_export {
enum class Scope { OfflineComponent, ScopedLive };
struct Proofs {
    bool typedSource = false, wholeStateCarry = false, allOrderedEffects = false,
         allConsumerCerts = false, finalAuthority = false, lateRefusals = false,
         liveLiteralVif = false;
    constexpr bool complete() const noexcept {
        return typedSource && wholeStateCarry && allOrderedEffects && allConsumerCerts &&
               finalAuthority && lateRefusals && liveLiteralVif;
    }
};
struct View {
    const Vulkan::Buffer* buffer = nullptr;
    VkDeviceSize offset = 0;
};
struct Inputs {
    const Vulkan::Device* owner = nullptr;
    View state{}, data{}, tape{}, results{}, packedCertificates{};
    uint32_t jobs = 0, capacity = 0, generation = 0, sourceClass = 1;
};
struct Authority {
    const Vulkan::Device* owner = nullptr;
    View state{}, data{}, completion{};
};
class Pipeline {
    Vulkan::Device& device_;
    Scope scope_;
    Proofs proofs_{};
    std::array<Vulkan::Program*, 2> programs_{};
    static VkDeviceSize stateBytes() {
        return VkDeviceSize(StateSeed + 158u) * 4u;
    }
    static VkDeviceSize dataBytes() {
        return VkDeviceSize(DataFinal + 4096u) * 4u;
    }
    bool bounded(View view, VkDeviceSize size) const {
        if (!view.buffer)
            return false;
        const auto& ci = view.buffer->get_create_info();
        const auto align = device_.get_gpu_properties().limits.minStorageBufferOffsetAlignment;
        return (!align || view.offset % align == 0) && view.offset <= ci.size &&
               size <= ci.size - view.offset && ci.domain == Vulkan::BufferDomain::Device &&
               (ci.usage & VK_BUFFER_USAGE_STORAGE_BUFFER_BIT);
    }
    void check(const Inputs& in, const Authority& authority) const {
        if (in.owner != &device_ || authority.owner != &device_ || !in.jobs ||
            in.jobs > in.capacity || in.capacity > 128u || !in.generation ||
            (in.sourceClass != 1u && in.sourceClass != 2u) ||
            (scope_ == Scope::ScopedLive && !proofs_.complete()) ||
            (scope_ == Scope::OfflineComponent && in.sourceClass != 1u))
            throw std::invalid_argument("Invalid one-seed exporter ownership/proof scope");
        if (!bounded(in.state, stateBytes()) || !bounded(in.data, dataBytes()) ||
            !bounded(in.tape, VkDeviceSize(in.jobs) * TapeStride * 4u) ||
            !bounded(in.results, VkDeviceSize(64u + in.jobs * 64u) * 4u) ||
            !bounded(in.packedCertificates, VkDeviceSize(in.jobs) * CertWords * 4u) ||
            !bounded(authority.state, 632u) || !bounded(authority.data, 16384u) ||
            !bounded(authority.completion, 48u))
            throw std::invalid_argument("Out-of-bounds one-seed exporter views");
        const std::array<View, 5> sources{in.state, in.data, in.tape, in.results,
                                          in.packedCertificates};
        const std::array<VkDeviceSize, 5> sourceSizes{
            stateBytes(), dataBytes(), VkDeviceSize(in.jobs) * TapeStride * 4u,
            VkDeviceSize(64u + in.jobs * 64u) * 4u, VkDeviceSize(in.jobs) * CertWords * 4u};
        const std::array<View, 3> destinations{authority.state, authority.data,
                                               authority.completion};
        const std::array<VkDeviceSize, 3> destinationSizes{632u, 16384u, 48u};
        for (unsigned a = 0; a < 3; ++a)
            for (unsigned b = 0; b < 5; ++b)
                if (destinations[a].buffer == sources[b].buffer &&
                    destinations[a].offset < sources[b].offset + sourceSizes[b] &&
                    sources[b].offset < destinations[a].offset + destinationSizes[a])
                    throw std::invalid_argument(
                        "Authority overlaps producer staging or certificate view");
    }
    static void barrier(Vulkan::CommandBuffer& cmd, const Vulkan::Buffer& buffer,
                        VkPipelineStageFlags stage, VkAccessFlags2 flags) {
        cmd.buffer_barrier(buffer, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                           VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT, stage,
                           flags);
    }
    void record(Vulkan::CommandBuffer& cmd, unsigned stage, const Inputs& in,
                const Authority& authority) {
        check(in, authority);
        const std::array<View, 8> views{in.state,
                                        in.data,
                                        in.tape,
                                        in.results,
                                        in.packedCertificates,
                                        authority.state,
                                        authority.data,
                                        authority.completion};
        const std::array<VkDeviceSize, 8> sizes{stateBytes(),
                                                dataBytes(),
                                                VkDeviceSize(in.jobs) * TapeStride * 4u,
                                                VkDeviceSize(64u + in.jobs * 64u) * 4u,
                                                VkDeviceSize(in.jobs) * CertWords * 4u,
                                                632u,
                                                16384u,
                                                48u};
        for (const auto& view : views)
            barrier(cmd, *view.buffer, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                    VK_ACCESS_2_SHADER_STORAGE_READ_BIT | VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
        cmd.set_program(programs_.at(stage));
        for (unsigned b = 0; b < 8; ++b)
            cmd.set_storage_buffer(0, b, *views[b].buffer, views[b].offset, sizes[b]);
        const Push push{in.jobs, in.capacity, in.generation, 0u};
        cmd.push_constants(&push, 0, sizeof(push));
        cmd.dispatch(1, 1, 1);
        for (const auto& view : views)
            barrier(cmd, *view.buffer, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                    VK_ACCESS_2_SHADER_STORAGE_READ_BIT | VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
    }

  public:
    // Constructor and enqueue do not initialize a Device, submit commands, map
    // graphics, wait, or mutate proof gates. ROOT supplies the existing Device.
    Pipeline(Vulkan::Device& device, const std::array<std::vector<uint32_t>, 2>& modules,
             Scope scope, Proofs proofs = {})
        : device_(device), scope_(scope), proofs_(proofs) {
        if (scope == Scope::ScopedLive && !proofs.complete())
            throw std::invalid_argument("One-seed live exporter proofs incomplete");
        Vulkan::ResourceLayout layout{};
        layout.sets[0].storage_buffer_mask = 255u;
        layout.push_constant_size = 16u;
        for (unsigned b = 0; b < 8; ++b)
            layout.sets[0].meta[b].array_size = 1;
        static constexpr std::array<const char*, 2> expected{
            "59d84ef0268e370520360e700b012fd8b080f952eca8de024b613934ba1b119b",
            "cef30ef928f7a1181c5738db4c580f97bcbac7c0555814a15eb9fd55f5796d65"};
        for (unsigned stage = 0; stage < 2; ++stage) {
            const auto& code = modules[stage];
            if (code.size() < 5 || code[0] != 0x07230203u)
                throw std::invalid_argument("Invalid one-seed exporter module");
            std::vector<uint8_t> bytes(code.size() * 4u);
            std::memcpy(bytes.data(), code.data(), bytes.size());
            if (reo_gpu_catalog::sha256(bytes) != expected[stage])
                throw std::invalid_argument("Unpinned one-seed exporter module");
            auto* program = device.request_program(code.data(), code.size() * 4u, &layout);
            if (!program || !program->get_pipeline_layout())
                throw std::runtime_error("Exporter program creation failed");
            const auto& actual = program->get_pipeline_layout()->get_resource_layout();
            if (actual.descriptor_set_mask != 1u || actual.bindless_descriptor_set_mask ||
                actual.sets[0].storage_buffer_mask != 255u || actual.push_constant_range.offset ||
                actual.push_constant_range.size != 16u ||
                actual.stages_for_sets[0] != VK_SHADER_STAGE_COMPUTE_BIT)
                throw std::runtime_error("Exporter interface mismatch");
            for (unsigned b = 0; b < 8; ++b)
                if (actual.sets[0].meta[b].array_size != 1u ||
                    actual.stages_for_bindings[0][b] != VK_SHADER_STAGE_COMPUTE_BIT)
                    throw std::runtime_error("Exporter binding mismatch");
            programs_[stage] = program;
        }
    }
    void admit(Vulkan::CommandBuffer& cmd, const Inputs& in, const Authority& authority) {
        record(cmd, 0, in, authority);
    }
    void commit(Vulkan::CommandBuffer& cmd, const Inputs& in, const Authority& authority) {
        record(cmd, 1, in, authority);
    }
    // Existing separate consumer certificates may be copied GPU-side into the
    // aggregate. This is integer metadata transfer, not host geometry/readback.
    void packCertificate(Vulkan::CommandBuffer& cmd, const Inputs& in, const Authority& authority,
                         uint32_t job, View certificate) {
        check(in, authority);
        if (job >= in.jobs || !bounded(certificate, CertWords * 4u))
            throw std::invalid_argument("Invalid certificate pack view");
        if (certificate.buffer == in.packedCertificates.buffer)
            throw std::invalid_argument(
                "Use directly bound aggregate certificates without transfer");
        barrier(cmd, *certificate.buffer, VK_PIPELINE_STAGE_TRANSFER_BIT,
                VK_ACCESS_2_TRANSFER_READ_BIT);
        barrier(cmd, *in.packedCertificates.buffer, VK_PIPELINE_STAGE_TRANSFER_BIT,
                VK_ACCESS_2_TRANSFER_WRITE_BIT);
        cmd.copy_buffer(*in.packedCertificates.buffer,
                        in.packedCertificates.offset + VkDeviceSize(job) * CertWords * 4u,
                        *certificate.buffer, certificate.offset, CertWords * 4u);
    }
    void unpackCertificate(Vulkan::CommandBuffer& cmd, const Inputs& in, const Authority& authority,
                           uint32_t job, View certificate) {
        check(in, authority);
        if (job >= in.jobs || !bounded(certificate, CertWords * 4u))
            throw std::invalid_argument("Invalid certificate unpack view");
        if (certificate.buffer == in.packedCertificates.buffer)
            throw std::invalid_argument(
                "Use directly bound aggregate certificates without transfer");
        barrier(cmd, *in.packedCertificates.buffer, VK_PIPELINE_STAGE_TRANSFER_BIT,
                VK_ACCESS_2_TRANSFER_READ_BIT);
        barrier(cmd, *certificate.buffer, VK_PIPELINE_STAGE_TRANSFER_BIT,
                VK_ACCESS_2_TRANSFER_WRITE_BIT);
        cmd.copy_buffer(*certificate.buffer, certificate.offset, *in.packedCertificates.buffer,
                        in.packedCertificates.offset + VkDeviceSize(job) * CertWords * 4u,
                        CertWords * 4u);
        barrier(cmd, *certificate.buffer, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                VK_ACCESS_2_SHADER_STORAGE_READ_BIT | VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
    }
};
} // namespace reo_gpu_static_stream_export
