#pragma once
#include "parent_gpu_overlay.hpp"
#include "parent_bridge.hpp"
namespace reo_parent_live {
struct TransportModules {
    std::vector<uint32_t> mailbox, relay;
};
// Instantiate only INSIDE the root GS factory with its actual VIF target,
// completion and retirement lifetime. Caller-supplied foreign buffers are not
// a proof of Device identity; this helper is default-off and not installed.
class Transport {
    Vulkan::Device& device_;
    reo_gpu_palette_parent::Producer& producer_;
    const Vulkan::Buffer& vifCompletion_;
    reo_gpu_vif_upload::ResidentLeaseUnpack& unpack_;
    std::shared_ptr<const void> vifBankLifetime_;
    uint64_t targetSession_ = 0, targetBankGeneration_ = 0, lastSealed_ = 0;
    Vulkan::Program *mailboxProgram_ = nullptr, *relayProgram_ = nullptr;
    struct Lifetime {
        reo_gpu_palette_parent::Produced token;
        Vulkan::BufferHandle mailbox, controlHost;
        std::shared_ptr<const void> parentLife, targetLife;
    };
    Vulkan::BufferHandle buffer(uint32_t bytes, Vulkan::BufferDomain domain) {
        Vulkan::BufferCreateInfo i{};
        i.domain = domain;
        i.size = bytes;
        i.usage = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT |
                  VK_BUFFER_USAGE_TRANSFER_DST_BIT;
        auto b = device_.create_buffer(i);
        if (!b)
            throw std::runtime_error("Parent bridge control allocation failed");
        return b;
    }
    Vulkan::Program* program(const std::vector<uint32_t>& words, unsigned bindings) {
        if (words.size() < 5 || words[0] != 0x07230203u)
            throw std::invalid_argument("Missing pinned integer bridge module");
        Vulkan::ResourceLayout shape{};
        shape.sets[0].storage_buffer_mask = (1u << bindings) - 1u;
        shape.push_constant_size = 16;
        for (unsigned b = 0; b < bindings; ++b)
            shape.sets[0].meta[b].array_size = 1;
        auto* p = device_.request_program(words.data(), words.size() * 4, &shape);
        if (!p || !p->get_pipeline_layout())
            throw std::runtime_error("Bridge module creation failed");
        const auto& a = p->get_pipeline_layout()->get_resource_layout();
        if (a.descriptor_set_mask != 1 || a.bindless_descriptor_set_mask ||
            a.sets[0].storage_buffer_mask != shape.sets[0].storage_buffer_mask ||
            a.push_constant_range.size != 16 || a.push_constant_range.offset)
            throw std::runtime_error("Bridge shader interface differs");
        return p;
    }
    static void barrier(Vulkan::CommandBuffer& cmd, const Vulkan::Buffer& b) {
        cmd.buffer_barrier(b, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                           VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                           VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                           VK_ACCESS_2_SHADER_STORAGE_READ_BIT |
                               VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
    }
    void stage(Vulkan::CommandBuffer& cmd, Vulkan::Program* p,
               const std::vector<const Vulkan::Buffer*>& banks,
               const std::array<uint32_t, 4>& push) {
        cmd.set_program(p);
        for (unsigned b = 0; b < banks.size(); ++b) {
            barrier(cmd, *banks[b]);
            cmd.set_storage_buffer(0, b, *banks[b]);
        }
        cmd.push_constants(push.data(), 0, 16);
        cmd.dispatch(1, 1, 1);
    }

  public:
    struct Queued {
        Produced bridge;
        std::shared_ptr<Lifetime> life;
        std::shared_ptr<const reo_palette_lease::Payload> lease;
        Allocation allocation;
    };
    Transport(Vulkan::Device& device, reo_gpu_palette_parent::Producer& producer,
              const TransportModules& modules, const Vulkan::Buffer& actualOwnerCompletion,
              reo_gpu_vif_upload::ResidentLeaseUnpack& actualOwnerUnpack,
              std::shared_ptr<const void> ownerLifetime, uint64_t actualOwnerSession,
              uint64_t actualOwnerBankGeneration)
        : device_(device), producer_(producer), vifCompletion_(actualOwnerCompletion),
          unpack_(actualOwnerUnpack), vifBankLifetime_(std::move(ownerLifetime)),
          targetSession_(actualOwnerSession), targetBankGeneration_(actualOwnerBankGeneration) {
        if (producer.bridgeDeviceIdentity() != &device || !vifBankLifetime_ || !targetSession_ ||
            !targetBankGeneration_ || actualOwnerCompletion.get_create_info().size < 48)
            throw std::invalid_argument(
                "Parent bridge must be composed in actual same-Device GS factory");
        mailboxProgram_ = program(modules.mailbox, 5);
        relayProgram_ = program(modules.relay, 4);
    }
    Queued record(Vulkan::CommandBuffer& cmd, const Allocation& a,
                  const std::vector<RawPatch>& patches) {
        for (const auto& p : patches)
            producer_.bridgeSourceWrite(cmd, p);
        reo_gpu_palette_parent::AllocationReturn actual{
            a.key.session, a.key.epoch, a.key.allocation, a.key.revision, a.key.ordinal, a.pc,
            a.packet,      a.frame,     a.descriptor,     a.mask,         a.context};
        auto token = producer_.enqueue(cmd, actual);
        const auto& source = producer_.bridgePayload(token);
        if (source.device != &device_ || a.key.session != targetSession_ ||
            source.identity.session != targetSession_ ||
            source.identity.bankGeneration != targetBankGeneration_)
            throw std::invalid_argument("Foreign or stale immutable GPU parent lease");
        auto life = std::make_shared<Lifetime>();
        life->token = token;
        life->parentLife = source.lifetime;
        life->targetLife = vifBankLifetime_;
        life->mailbox = buffer(sizeof(Mailbox), Vulkan::BufferDomain::Device);
        life->controlHost = buffer(sizeof(Mailbox), Vulkan::BufferDomain::CachedHost);
        stage(cmd, mailboxProgram_,
              {&producer_.context(), &producer_.ram(), &producer_.completion(),
               &producer_.resultMetadata(), life->mailbox.get()},
              {a.packet, a.frame, uint32_t(a.key.ordinal), uint32_t(a.key.ordinal >> 32)});
        stage(cmd, relayProgram_,
              {&producer_.completion(), &producer_.resultMetadata(), &vifCompletion_,
               life->mailbox.get()},
              {uint32_t(a.key.ordinal), uint32_t(a.key.ordinal >> 32), 0, 0});
        cmd.buffer_barrier(*life->mailbox, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                           VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT,
                           VK_ACCESS_2_TRANSFER_READ_BIT);
        cmd.copy_buffer(*life->controlHost, *life->mailbox);
        cmd.buffer_barrier(*life->controlHost, VK_PIPELINE_STAGE_TRANSFER_BIT,
                           VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_HOST_BIT,
                           VK_ACCESS_2_HOST_READ_BIT);
        // Rebind ONLY the companion failure guard after its actual GPU relay. The
        // immutable bytes/sourceidentity/lifetime remain those minted by producer.
        auto lease = std::make_shared<reo_palette_lease::Payload>(source);
        lease->completion = &vifCompletion_;
        lease->lifetime = life;
        Produced bridge{a.key, std::static_pointer_cast<const void>(lease),
                        std::static_pointer_cast<const void>(life)};
        return {bridge, life, lease, a};
    }
    void actualUnpack(Vulkan::CommandBuffer& cmd, const Queued& q, uint32_t command,
                      uint32_t tops) {
        // Actual prior typedSTCYCL0404/STMOD writes must already be recorded by
        // the VIF parser. Do not normalize them to the component fixture's0101.
        unpack_.enqueueResident(cmd, command, tops, *q.lease, targetSession_, targetBankGeneration_,
                                q.allocation.key.allocation, q.allocation.packet + PayloadOffset);
    }
    void orderedRawContextOverwrite(Vulkan::CommandBuffer& cmd, const RawPatch& patch) {
        producer_.bridgeSourceWrite(cmd, patch);
    }
    void orderedRawRamOverwrite(Vulkan::CommandBuffer& cmd, const RawPatch& patch) {
        producer_.bridgeSourceWrite(cmd, patch);
    }
    Mailbox controlAfterRealFence(const Queued& q, bool actualFenceCompleted) {
        if (!actualFenceCompleted)
            throw std::runtime_error("Parent return requires actual completed owner receipt");
        const void* p =
            device_.map_host_buffer(*q.life->controlHost, Vulkan::MEMORY_ACCESS_READ_BIT);
        if (!p)
            throw std::runtime_error("Control mailbox map failed");
        Mailbox m;
        std::memcpy(&m, p, sizeof(m));
        device_.unmap_host_buffer(*q.life->controlHost, Vulkan::MEMORY_ACCESS_READ_BIT);
        return m;
    }
    void sealed(uint64_t actualTimeline) {
        if (!actualTimeline || actualTimeline < lastSealed_)
            throw std::invalid_argument("Parent relay seal is not actual monotonic owner timeline");
        if (actualTimeline == lastSealed_)
            return;
        producer_.sealOwnerSubmission(actualTimeline);
        lastSealed_ = actualTimeline;
    }
    void retired(uint64_t actualCompletedTimeline) {
        producer_.retireCompletedOwnerSubmission(actualCompletedTimeline);
    }
};
} // namespace reo_parent_live
