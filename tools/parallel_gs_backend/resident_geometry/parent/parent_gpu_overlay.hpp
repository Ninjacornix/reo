#pragma once
// Isolated same-owner whole-parent producer. No live installer or activation.
#include "../upstream/context_fork_ledger.hpp"
#include "resident_palette.hpp"
#include "resident_lease_unpack.hpp"
#include "packet_chronology.hpp"
#include "upstream/matrix191280.hpp"
#include "upstream/perspective18f710.hpp"
#include "upstream/viewport_pipeline.hpp"
#include "upstream/setter_pipeline.hpp"
#include "upstream/queue_header_pipeline.hpp"
#include "upstream/queue_journal_pipeline.hpp"
#include "upstream/allocator18ddd0.hpp"
#include "upstream/state_packet197900.hpp"
#include "../raw_byte_patch.hpp"
#include <array>
#include <cstddef>
#include <cstdint>
#include "../upstream/composition_pipeline.hpp"
#include <deque>
#include <memory>
#include <stdexcept>
#include <vector>

namespace reo_gpu_palette_parent {
constexpr uint32_t RamBytes = 0x2000000, SprBytes = 0x4000, PacketBytes = 0xfb0;
constexpr uint32_t StackBytes = 0xd0, PayloadBytes = 0xf80, PayloadOffset = 0x20;
static_assert(sizeof(R5900Context) == 1648);
static_assert(offsetof(R5900Context, r) == 0 && offsetof(R5900Context, in_delay_slot) % 4 == 0);
struct Push {
    uint32_t packet, frame, descriptor, mask;
};
static_assert(sizeof(Push) == 16);
struct Modules {
    std::vector<uint32_t> prepare, leaf, finish, commit;
    std::vector<uint32_t> setter196010;
    std::vector<uint32_t> sourceBytePatch; // Optional exact byte RAW transport.
    std::vector<uint32_t> matrix191280; // Absent by default; first upstream numerical closure only.
    std::vector<uint32_t> perspective18F710; // Absent by default; same trusted upstream banks.
    std::vector<uint32_t> viewportAllocator18DDD0; // Optional exact normal-control module.
    std::vector<uint32_t> viewport18F970, viewportQueueHeaders,
        viewportQueueJournal; // Same banks, absent/default-off.
    std::vector<uint32_t>
        composition18F6A0; // Appended optional member; existing aggregate order stays exact.
    std::vector<std::vector<uint32_t>>
        setter196010Additional; // Disjoint exact finite modules, same actual banks/chronology.
    std::array<std::vector<uint32_t>, 3> statePacket197900;
    std::vector<uint32_t> statePacketAllocator, statePacketQueueHeaders, statePacketQueueJournal;
};
enum class Tier { OfflineComponent, ScopedLive };
struct Proofs {
    bool independentWholeParentDeviceParity = false, wholePostAllocationPhases = false;
    bool authoritativeRawInputProducers = false, vu0ConsumersAndRealContextWait = false;
    bool packetWritersAndExactSourceChronology = false, sameDeviceOrderedUnpack = false;
    bool complete() const noexcept {
        return independentWholeParentDeviceParity && wholePostAllocationPhases &&
               authoritativeRawInputProducers && vu0ConsumersAndRealContextWait &&
               packetWritersAndExactSourceChronology && sameDeviceOrderedUnpack;
    }
};
struct AllocationReturn {
    uint64_t session = 0, epoch = 0, allocation = 0, revision = 0, ordinal = 0;
    uint32_t actualPC = 0, packet = 0, frame = 0, descriptor = 0, mask = 0;
    const void* contextIdentity = nullptr;
};
// This opaque token is minted only by this owner, retains the immutable GPU
// bytes, and names the genuine allocation/revision chronology. No pointer or
// content equality can infer an allocation ID or manufacture UNPACK origin.
class Produced {
    friend class Producer;
    const void* ownerIdentity_ = nullptr;
    AllocationReturn allocation_{};
    std::shared_ptr<const reo_palette_lease::Payload> lease_;

  public:
    const AllocationReturn& allocation() const noexcept {
        return allocation_;
    }
};
class Producer {
    friend class reo_parent_install::Service;
    std::unique_ptr<reo_source_adapter::RawBytePatch> sourceBytePatch_;
    std::vector<uint32_t> setterModule_;
    std::vector<std::vector<uint32_t>> setterAdditionalModules_;
    std::unique_ptr<reo_gpu_upstream::Setter196010> setter196010_;
    std::vector<std::unique_ptr<reo_gpu_upstream::Setter196010>> setterAdditional_;
    bool setterProgramsDrained() const noexcept {
        const auto drained = [](const auto& p) {
            return !p || (p->pending_.empty() && p->inFlight_.empty());
        };
        if (!drained(setter196010_))
            return false;
        for (const auto& p : setterAdditional_)
            if (!drained(p))
                return false;
        return true;
    }
    reo_gpu_upstream::Setter196010* setterForCommand(uint32_t command) const noexcept {
        auto* selected = setter196010_ && setter196010_->supportsModuleCommand(command)
                             ? setter196010_.get()
                             : nullptr;
        for (const auto& p : setterAdditional_)
            if (p->supportsModuleCommand(command)) {
                if (selected)
                    return nullptr;
                selected = p.get();
            }
        return selected;
    }
    Vulkan::Device& device_;
    const void* guestContextIdentity_ = nullptr;
    Tier tier_;
    Proofs proofs_;
    Vulkan::BufferHandle ram_, spr_, context_, completion_;
    Vulkan::BufferHandle workContext_, workPacket_, workStack_, matrices_, leafData_, meta_;
    Vulkan::Program *prepare_ = nullptr, *finish_ = nullptr, *commit_ = nullptr;
    reo_gpu_palette::Producer leaf_;
    uint64_t bankGeneration_ = 0, lastAllocation_ = 0, lastOrdinal_ = 0, epoch_ = 0, session_ = 0;
    uint64_t submitted_ = 0;
    uint64_t upstreamRecordedOrdinal_ = 0;
    const void* upstreamService_ = nullptr;
    std::vector<uint32_t> viewportAllocatorModule_;
    std::unique_ptr<reo_gpu_upstream::Allocator18DDD0> viewportAllocator18DDD0_;
    std::array<std::vector<uint32_t>, 3> stateModules_;
    std::vector<uint32_t> stateAllocatorModule_, stateHeadersModule_, stateJournalModule_;
    std::unique_ptr<reo_gpu_upstream::StatePacket197900> statePacket197900_;
    std::unique_ptr<reo_gpu_upstream::Allocator18DDD0> stateAllocator_;
    std::unique_ptr<reo_gpu_upstream::QueueHeaderMetadataPipeline> stateQueueHeaders_;
    std::unique_ptr<reo_gpu_upstream::QueueJournalPipeline> stateQueueJournal_;

    std::vector<uint32_t> viewportModule_, viewportHeadersModule_, viewportJournalModule_;
    std::unique_ptr<reo_gpu_upstream::Viewport> viewport18F970_;
    std::unique_ptr<reo_gpu_upstream::QueueHeaderMetadataPipeline> viewportQueueHeaders_;
    std::unique_ptr<reo_gpu_upstream::QueueJournalPipeline> viewportQueueJournal_;
    std::vector<uint32_t> perspectiveModule_;
    std::unique_ptr<reo_gpu_upstream::Perspective18F710> perspective18F710_;
    std::vector<uint32_t> compositionModule_;
    std::unique_ptr<reo_gpu_upstream::Composition18F6A0> composition18F6A0_;
    std::vector<uint32_t> matrixModule_;
    reo_gpu_upstream::BanksHandle upstreamBanks_;
    std::unique_ptr<reo_gpu_upstream::Matrix191280> matrix191280_;
    class ContextImage final {
        friend class Producer;
        friend class reo_parent_install::Service;
        const Producer* issuer_;
        Vulkan::BufferHandle buffer_;
        reo_gpu_upstream::BanksHandle banks_;
        const void* actualContext_;
        uint64_t serial_;
        ContextImage(const Producer* issuer, Vulkan::BufferHandle buffer,
                     reo_gpu_upstream::BanksHandle banks, const void* actualContext,
                     uint64_t serial)
            : issuer_(issuer), buffer_(std::move(buffer)), banks_(std::move(banks)),
              actualContext_(actualContext), serial_(serial) {}
    };
    using ContextImageHandle = std::shared_ptr<const ContextImage>;
    uint64_t contextImageSerial_ = 0;
    uint64_t contextBankGenerationAllocator_ = 0;
    static void contextTransferBarrier(Vulkan::CommandBuffer& cmd, const Vulkan::Buffer& buffer,
                                       VkAccessFlags2 access) {
        cmd.buffer_barrier(buffer, VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT,
                           VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                           VK_PIPELINE_STAGE_2_TRANSFER_BIT, access);
    }
    void requireContextMathRetired() const {
        const auto drained = [](const auto& p) {
            return !p || (p->pending_.empty() && p->inFlight_.empty());
        };
        if (!pending_.empty() || !inFlight_.empty() || !setterProgramsDrained() ||
            !drained(matrix191280_) || !drained(perspective18F710_) || !drained(viewport18F970_) ||
            !drained(viewportAllocator18DDD0_) || !drained(viewportQueueHeaders_) ||
            !drained(viewportQueueJournal_) || !drained(statePacket197900_) ||
            !drained(stateAllocator_) || !drained(stateQueueHeaders_) ||
            !drained(stateQueueJournal_))
            throw std::runtime_error("Context switch preceded real numerical/parent retirement");
        const auto composition = [&]<class Owner>(const Owner& owner) {
            if constexpr (requires { owner.composition18F6A0_; })
                return drained(owner.composition18F6A0_);
            else
                return true;
        };
        if (!composition(*this))
            throw std::runtime_error("Context switch preceded complete effects retirement");
        const auto irqDrained = [&]<class Owner>(const Owner& owner) {
            if constexpr (requires { owner.irq18D160_; })
                return drained(owner.irq18D160_);
            else
                return true;
        };
        if (!irqDrained(*this))
            throw std::runtime_error("IRQ Context switch preceded genuine stage retirement");
    }
    ContextImageHandle retainActualContextImage(const void* actualContext) {
        if (!actualContext || actualContext != guestContextIdentity_ || !upstreamBanks_ ||
            contextImageSerial_ == UINT64_MAX)
            throw std::invalid_argument("Context image is foreign or generation exhausted");
        return std::shared_ptr<const ContextImage>(
            new ContextImage(this, context_, upstreamBanks_, actualContext, ++contextImageSerial_));
    }
    void bindActualContextImage(const ContextImageHandle& image, uint64_t ordinal) {
        requireContextMathRetired();
        if (!image || image->issuer_ != this || !image->buffer_ || !image->banks_ ||
            !image->actualContext_ || !image->serial_ || !upstreamBanks_ || !ordinal ||
            ordinal != upstreamRecordedOrdinal_ + 1)
            throw std::invalid_argument(
                "Context binding lacks exact owner image/source chronology");
        // A restored caller uses the retained exact identity. A real held
        // caller receipt must not become stale merely because an IRQ ran.
        auto next = image->banks_;
        const auto& stamp = next->stamp();
        if (next->issuer() != this || next->device() != &device_ || stamp.session != session_ ||
            stamp.epoch != epoch_ || !stamp.bankGeneration)
            throw std::invalid_argument("Context image is stale or belongs to another owner epoch");
        if (setter196010_)
            setter196010_->banks_ = next;
        for (auto& p : setterAdditional_)
            p->banks_ = next;
        if (matrix191280_)
            matrix191280_->banks_ = next;
        if (perspective18F710_)
            perspective18F710_->banks_ = next;
        if (viewport18F970_)
            viewport18F970_->banks_ = next;
        if (viewportAllocator18DDD0_)
            viewportAllocator18DDD0_->banks_ = next;
        if (viewportQueueHeaders_)
            viewportQueueHeaders_->banks_ = next;
        if (viewportQueueJournal_)
            viewportQueueJournal_->banks_ = next;
        if (statePacket197900_)
            statePacket197900_->banks_ = next;
        if (stateAllocator_)
            stateAllocator_->banks_ = next;
        if (stateQueueHeaders_)
            stateQueueHeaders_->banks_ = next;
        if (stateQueueJournal_)
            stateQueueJournal_->banks_ = next;
        const auto composition = [&]<class Owner>(Owner& owner) {
            if constexpr (requires { owner.composition18F6A0_; })
                if (owner.composition18F6A0_)
                    owner.composition18F6A0_->banks_ = next;
        };
        composition(*this);
        const auto irqBind = [&]<class Owner>(Owner& owner) {
            if constexpr (requires { owner.irq18D160_; })
                if (owner.irq18D160_)
                    owner.irq18D160_->banks_ = next;
        };
        irqBind(*this);
        // Previously recorded byte transports retain their command-buffer
        // descriptor bindings. Future transports address the new exact bank.
        if (sourceBytePatch_)
            sourceBytePatch_->banks_[2] = image->buffer_;
        context_ = image->buffer_;
        guestContextIdentity_ = image->actualContext_;
        upstreamBanks_ = std::move(next);
        bankGeneration_ = stamp.bankGeneration;
        upstreamRecordedOrdinal_ = ordinal;
    }
    ContextImageHandle forkActualContextImage(
        Vulkan::CommandBuffer& cmd, const void* actualCaller, const void* actualChild,
        const std::vector<reo_context_handoff::ControlPatch>& controls, uint64_t ordinal) {
        requireContextMathRetired();
        if (!actualCaller || actualCaller != guestContextIdentity_ || !actualChild ||
            actualChild == actualCaller || contextImageSerial_ == UINT64_MAX)
            throw std::invalid_argument(
                "GPU Context fork lacks genuine distinct source identities");
        Vulkan::BufferCreateInfo ci{};
        ci.domain = Vulkan::BufferDomain::Device;
        ci.size = 1648u;
        ci.usage = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT |
                   VK_BUFFER_USAGE_TRANSFER_DST_BIT;
        auto child = device_.create_buffer(ci);
        if (!child)
            throw std::runtime_error("GPU Context fork allocation failed");
        const auto nextGeneration = std::max(contextBankGenerationAllocator_, bankGeneration_);
        if (nextGeneration == UINT64_MAX)
            throw std::overflow_error("Context bank generation exhausted");
        auto banks = std::shared_ptr<const reo_gpu_upstream::Banks>(
            new reo_gpu_upstream::Banks(this, &device_, {session_, epoch_, nextGeneration + 1, 0},
                                        {ram_, spr_, child, completion_}));
        auto image = std::shared_ptr<const ContextImage>(
            new ContextImage(this, child, std::move(banks), actualChild, contextImageSerial_ + 1));
        // Validate all control metadata before a copy or active-bank mutation.
        for (const auto& p : controls)
            if (!p.bytes || p.bytes > 8u || (p.at & 3u) || (p.bytes & 3u) || p.at >= 1648u ||
                p.bytes > 1648u - p.at || p.role < 3u || p.role > 7u)
                throw std::invalid_argument(
                    "GPU callback control patch is outside exact lower lanes");
        contextTransferBarrier(cmd, *context_, VK_ACCESS_2_TRANSFER_READ_BIT);
        contextTransferBarrier(cmd, *child, VK_ACCESS_2_TRANSFER_WRITE_BIT);
        cmd.copy_buffer(*child, *context_);
        for (const auto& p : controls) {
            cmd.buffer_barrier(*child, VK_PIPELINE_STAGE_2_TRANSFER_BIT,
                               VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_2_TRANSFER_BIT,
                               VK_ACCESS_2_TRANSFER_WRITE_BIT);
            cmd.update_buffer_inline(*child, p.at, p.bytes, p.value.data());
        }
        barrier(cmd, *child);
        bindActualContextImage(image, ordinal);
        contextBankGenerationAllocator_ = nextGeneration + 1;
        ++contextImageSerial_;
        return image;
    }
    ContextImageHandle recordFreshActualContextImage(Vulkan::CommandBuffer& cmd,
                                                     const R5900Context& actualFresh,
                                                     const void* actualIdentity, uint64_t ordinal) {
        // Caller: actual Service after authentic fresh initializer/lifetime
        // certification. This never accepts another Context's numeric shadow.
        requireContextMathRetired();
        const auto nextGeneration = std::max(contextBankGenerationAllocator_, bankGeneration_);
        if (contextImageSerial_ == UINT64_MAX || nextGeneration == UINT64_MAX || !actualIdentity ||
            actualIdentity == guestContextIdentity_)
            throw std::invalid_argument("Fresh Context image is not a new authentic initializer");
        Vulkan::BufferCreateInfo ci{};
        ci.domain = Vulkan::BufferDomain::Device;
        ci.size = 1648u;
        ci.usage = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT |
                   VK_BUFFER_USAGE_TRANSFER_DST_BIT;
        auto buffer = device_.create_buffer(ci, &actualFresh);
        if (!buffer)
            throw std::runtime_error("Fresh Context initializer allocation failed");
        auto banks = std::shared_ptr<const reo_gpu_upstream::Banks>(
            new reo_gpu_upstream::Banks(this, &device_, {session_, epoch_, nextGeneration + 1, 0},
                                        {ram_, spr_, buffer, completion_}));
        auto image = std::shared_ptr<const ContextImage>(new ContextImage(
            this, buffer, std::move(banks), actualIdentity, contextImageSerial_ + 1));
        barrier(cmd, *buffer);
        bindActualContextImage(image, ordinal);
        contextBankGenerationAllocator_ = nextGeneration + 1;
        ++contextImageSerial_;
        return image;
    }

    struct Lifetime {
        Vulkan::BufferHandle payload, ram, spr, context, completion;
        AllocationReturn allocation;
    };
    struct Submission {
        uint64_t timeline = 0;
        std::vector<std::shared_ptr<const Lifetime>> leases;
    };
    std::vector<std::shared_ptr<const Lifetime>> pending_;
    std::deque<Submission> inFlight_;
    static bool range(uint32_t at, uint32_t bytes) {
        return bytes && at < RamBytes && bytes <= RamBytes - at;
    }
    Vulkan::BufferHandle allocate(uint32_t bytes, const void* cold = nullptr) {
        Vulkan::BufferCreateInfo info{};
        info.domain = Vulkan::BufferDomain::Device;
        info.size = bytes;
        info.usage = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT |
                     VK_BUFFER_USAGE_TRANSFER_DST_BIT;
        auto value = device_.create_buffer(info, cold);
        if (!value)
            throw std::runtime_error("Whole-parent bank allocation failed");
        return value;
    }
    Vulkan::Program* program(const std::vector<uint32_t>& words) {
        if (words.size() < 5 || words[0] != 0x07230203u)
            throw std::invalid_argument("Whole-parent module is missing");
        Vulkan::ResourceLayout shape{};
        shape.sets[0].storage_buffer_mask = 0xff;
        for (unsigned b = 0; b < 8; ++b)
            shape.sets[0].meta[b].array_size = 1;
        shape.push_constant_size = sizeof(Push);
        auto* value = device_.request_program(words.data(), words.size() * 4, &shape);
        if (!value || !value->get_pipeline_layout())
            throw std::runtime_error("Whole-parent program creation failed");
        const auto& actual = value->get_pipeline_layout()->get_resource_layout();
        if (actual.descriptor_set_mask != 1 || actual.bindless_descriptor_set_mask ||
            actual.sets[0].storage_buffer_mask != 0xff ||
            actual.stages_for_sets[0] != VK_SHADER_STAGE_COMPUTE_BIT ||
            actual.push_constant_range.offset || actual.push_constant_range.size != sizeof(Push) ||
            actual.push_constant_range.stageFlags != VK_SHADER_STAGE_COMPUTE_BIT)
            throw std::runtime_error("Whole-parent module resource ABI differs");
        for (unsigned b = 0; b < 8; ++b)
            if (actual.sets[0].meta[b].array_size != 1 ||
                actual.stages_for_bindings[0][b] != VK_SHADER_STAGE_COMPUTE_BIT)
                throw std::runtime_error("Whole-parent module binding differs");
        return value;
    }
    static void barrier(Vulkan::CommandBuffer& cmd, const Vulkan::Buffer& buffer) {
        cmd.buffer_barrier(buffer, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                           VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                           VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                           VK_ACCESS_2_SHADER_STORAGE_READ_BIT |
                               VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
    }
    static void copy(Vulkan::CommandBuffer& cmd, const Vulkan::Buffer& destination, uint32_t to,
                     const Vulkan::Buffer& source, uint32_t from, uint32_t bytes) {
        cmd.buffer_barrier(source, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                           VK_ACCESS_2_MEMORY_WRITE_BIT | VK_ACCESS_2_MEMORY_READ_BIT,
                           VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
        cmd.buffer_barrier(destination, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                           VK_ACCESS_2_MEMORY_WRITE_BIT | VK_ACCESS_2_MEMORY_READ_BIT,
                           VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT);
        cmd.copy_buffer(destination, to, source, from, bytes);
        barrier(cmd, destination);
    }
    void stage(Vulkan::CommandBuffer& cmd, Vulkan::Program* program, const Push& push,
               const std::array<const Vulkan::Buffer*, 8>& banks) {
        for (auto* b : banks)
            barrier(cmd, *b);
        cmd.set_program(program);
        for (unsigned b = 0; b < 8; ++b)
            cmd.set_storage_buffer(0, b, *banks[b]);
        cmd.push_constants(&push, 0, sizeof(push));
        cmd.dispatch(1, 1, 1);
    }

  public:
    // All Device buffers are created here. The live owner must construct this
    // only once at its real cold authority boundary; no per-parent host seed.
    // OfflineComponent is an explicit fixture seam, never a live proof bypass.
    Producer(Vulkan::Device& device, const Modules& modules, const void* coldRam,
             const void* coldSpr, const R5900Context& coldContext, uint64_t bankGeneration,
             Tier tier, const Proofs& proofs = {}, const void* initialContextBytes = nullptr)
        : compositionModule_(modules.composition18F6A0), setterModule_(modules.setter196010),
          setterAdditionalModules_(modules.setter196010Additional),
          stateModules_(modules.statePacket197900),
          stateAllocatorModule_(modules.statePacketAllocator),
          stateHeadersModule_(modules.statePacketQueueHeaders),
          stateJournalModule_(modules.statePacketQueueJournal), device_(device),
          guestContextIdentity_(&coldContext), tier_(tier), proofs_(proofs),
          leaf_(device, modules.leaf), bankGeneration_(bankGeneration),
          viewportAllocatorModule_(modules.viewportAllocator18DDD0),
          viewportModule_(modules.viewport18F970),
          viewportHeadersModule_(modules.viewportQueueHeaders),
          viewportJournalModule_(modules.viewportQueueJournal),
          perspectiveModule_(modules.perspective18F710), matrixModule_(modules.matrix191280) {
        if (!coldRam || !coldSpr || !bankGeneration ||
            (tier == Tier::ScopedLive && !proofs.complete()))
            throw std::invalid_argument(
                "Whole-parent live input/consumer/source scope is incomplete");
        ram_ = allocate(RamBytes, coldRam);
        spr_ = allocate(SprBytes, coldSpr);
        context_ =
            allocate(sizeof(coldContext), initialContextBytes ? initialContextBytes : &coldContext);
        if (!modules.sourceBytePatch.empty())
            sourceBytePatch_ = std::unique_ptr<reo_source_adapter::RawBytePatch>(
                new reo_source_adapter::RawBytePatch(device_, modules.sourceBytePatch,
                                                     {ram_, spr_, context_}));
        const std::array<uint32_t, 12> zero{};
        completion_ = allocate(48, zero.data());
        workContext_ = allocate(sizeof(coldContext));
        workPacket_ = allocate(PacketBytes);
        workStack_ = allocate(StackBytes);
        matrices_ = allocate(2112);
        leafData_ = allocate(16384);
        std::array<uint32_t, 40> constants{};
        constants[0] = uint32_t(sizeof(R5900Context) / 4);
        constants[1] = offsetof(R5900Context, pc) / 4;
        constants[2] = offsetof(R5900Context, vu0_vf) / 4;
        constants[3] = offsetof(R5900Context, vu0_acc) / 4;
        constants[4] = offsetof(R5900Context, vu0_q) / 4;
        constants[5] = offsetof(R5900Context, vu0_i) / 4;
        constants[6] = offsetof(R5900Context, f) / 4;
        constants[7] = offsetof(R5900Context, fcr31) / 4;
        constants[8] = offsetof(R5900Context, in_delay_slot) / 4;
        constants[9] = offsetof(R5900Context, branch_pc) / 4;
        constants[10] = offsetof(R5900Context, vu0_info) / 4;
        meta_ = allocate(sizeof(constants), constants.data());
        prepare_ = program(modules.prepare);
        finish_ = program(modules.finish);
        commit_ = program(modules.commit);
    }
    Producer(const Producer&) = delete;
    Producer& operator=(const Producer&) = delete;
    ~Producer() {
        if (!pending_.empty() || !inFlight_.empty())
            device_.wait_idle();
    }
    Produced enqueue(Vulkan::CommandBuffer& cmd, const AllocationReturn& actual) {
        if (actual.actualPC != 0x19bbfcu || !actual.contextIdentity ||
            (tier_ == Tier::ScopedLive && actual.contextIdentity != guestContextIdentity_) ||
            !actual.session || !actual.epoch || !actual.allocation || !actual.revision ||
            !actual.ordinal || actual.allocation <= lastAllocation_ ||
            actual.ordinal <= lastOrdinal_ ||
            ((actual.packet | actual.frame | actual.descriptor) & 15u) ||
            !range(actual.packet, PacketBytes) || actual.frame < 0x60u ||
            !range(actual.frame - 0x60u, StackBytes) || !range(actual.descriptor, 0x180) ||
            (epoch_ && actual.epoch != epoch_) || (session_ && actual.session != session_) ||
            pending_.size() >= 4096)
            throw std::invalid_argument("Not a new bounded actual post-allocation parent identity");
        lastAllocation_ = actual.allocation;
        lastOrdinal_ = actual.ordinal;
        epoch_ = actual.epoch;
        session_ = actual.session;
        const Push push{actual.packet, actual.frame, actual.descriptor, actual.mask};
        copy(cmd, *workContext_, 0, *context_, 0, sizeof(R5900Context));
        copy(cmd, *workPacket_, 0, *ram_, actual.packet, PacketBytes);
        copy(cmd, *workStack_, 0, *ram_, actual.frame - 0x60u, StackBytes);
        stage(cmd, prepare_, push,
              {ram_.get(), spr_.get(), workContext_.get(), workPacket_.get(), workStack_.get(),
               meta_.get(), matrices_.get(), completion_.get()});
        copy(cmd, *leafData_, 0, *workPacket_, PayloadOffset, PayloadBytes);
        reo_gpu_palette::Inputs leafInput{};
        leafInput.owner = &device_;
        leafInput.matrices = matrices_;
        leafInput.context = workContext_;
        leafInput.vu1Data = leafData_;
        leafInput.ownerCompletion = completion_;
        leaf_.enqueue(cmd, leafInput, actual.mask);
        stage(cmd, finish_, push,
              {ram_.get(), spr_.get(), workContext_.get(), workPacket_.get(), workStack_.get(),
               meta_.get(), leafData_.get(), completion_.get()});
        auto payload = allocate(PayloadBytes);
        stage(cmd, commit_, push,
              {ram_.get(), context_.get(), workContext_.get(), workPacket_.get(), workStack_.get(),
               meta_.get(), payload.get(), completion_.get()});
        auto lifetime = std::make_shared<Lifetime>();
        lifetime->payload = payload;
        lifetime->ram = ram_;
        lifetime->spr = spr_;
        lifetime->context = context_;
        lifetime->completion = completion_;
        lifetime->allocation = actual;
        pending_.push_back(lifetime);
        auto lease = std::make_shared<reo_palette_lease::Payload>();
        lease->device = &device_;
        lease->buffer = payload;
        lease->completion = completion_.get();
        lease->lifetime = lifetime;
        lease->sourceOffset = 0;
        lease->identity = {actual.session,
                           bankGeneration_,
                           actual.allocation,
                           actual.ordinal,
                           actual.packet + PayloadOffset,
                           PayloadBytes};
        Produced token;
        token.ownerIdentity_ = this;
        token.allocation_ = actual;
        token.lease_ = std::move(lease);
        return token;
    }
    void enqueueOriginalUnpack(Vulkan::CommandBuffer& cmd,
                               reo_gpu_vif_upload::ResidentLeaseUnpack& unpack,
                               const Produced& token, uint32_t command, uint32_t tops,
                               const reo_palette_authority::OriginSpan* origins, size_t count) {
        const auto& a = token.allocation_;
        if (tier_ != Tier::ScopedLive || !proofs_.complete() || token.ownerIdentity_ != this ||
            !token.lease_ || command != 0x6cf80000u || tops > 1023u || a.session != session_ ||
            a.epoch != epoch_ || !origins || !count)
            throw std::runtime_error(
                "Unproved or foreign GPU parent source cannot enter live UNPACK");
        uint64_t cursor = 0;
        for (size_t i = 0; i < count; ++i) {
            const auto& s = origins[i];
            if (s.scratch || !s.bytes || s.offset != cursor ||
                s.address != uint64_t(a.packet) + PayloadOffset + cursor ||
                s.allocation != a.allocation || s.revision != a.revision ||
                s.bytes > PayloadBytes - cursor)
                throw std::runtime_error(
                    "Original typed UNPACK origins differ from immutable parent chronology");
            cursor += s.bytes;
        }
        if (cursor != PayloadBytes)
            throw std::runtime_error("Incomplete original248-qword palette upload");
        unpack.enqueueResident(cmd, command, tops, *token.lease_, a.session, bankGeneration_,
                               a.allocation, a.packet + PayloadOffset);
    }
    // Root's offline oracle may inspect this token without setting live flags.
    const reo_palette_lease::Payload& offlinePayload(const Produced& token) const {
        if (tier_ != Tier::OfflineComponent || token.ownerIdentity_ != this || !token.lease_)
            throw std::invalid_argument("Not this offline fixture output");
        return *token.lease_;
    }
    void sealOwnerSubmission(uint64_t actualTimeline) {
        if (!actualTimeline || actualTimeline <= submitted_)
            throw std::invalid_argument("Parent seal requires actual new GS timeline");
        submitted_ = actualTimeline;
        leaf_.sealOwnerSubmission(actualTimeline);
        if (sourceBytePatch_)
            sourceBytePatch_->seal(actualTimeline);
        if (setter196010_)
            setter196010_->seal(actualTimeline);
        for (auto& p : setterAdditional_)
            p->seal(actualTimeline);
        if (matrix191280_)
            matrix191280_->seal(actualTimeline);
        if (perspective18F710_)
            perspective18F710_->seal(actualTimeline);
        if (composition18F6A0_)
            composition18F6A0_->seal(actualTimeline);
        if (viewport18F970_)
            viewport18F970_->seal(actualTimeline);
        if (viewportAllocator18DDD0_)
            viewportAllocator18DDD0_->seal(actualTimeline);
        if (viewportQueueHeaders_)
            viewportQueueHeaders_->seal(actualTimeline);
        if (viewportQueueJournal_)
            viewportQueueJournal_->seal(actualTimeline);
        if (statePacket197900_)
            statePacket197900_->seal(actualTimeline);
        if (stateAllocator_)
            stateAllocator_->seal(actualTimeline);
        if (stateQueueHeaders_)
            stateQueueHeaders_->seal(actualTimeline);
        if (stateQueueJournal_)
            stateQueueJournal_->seal(actualTimeline);
        if (!pending_.empty()) {
            inFlight_.push_back({actualTimeline, std::move(pending_)});
            pending_.clear();
        }
    }
    void retireCompletedOwnerSubmission(uint64_t completed) {
        if (completed > submitted_)
            throw std::invalid_argument("Completion exceeds actual sealed prefix");
        leaf_.retireCompletedOwnerSubmission(completed);
        if (sourceBytePatch_)
            sourceBytePatch_->retire(completed);
        if (setter196010_)
            setter196010_->retire(completed);
        for (auto& p : setterAdditional_)
            p->retire(completed);
        if (matrix191280_)
            matrix191280_->retire(completed);
        if (perspective18F710_)
            perspective18F710_->retire(completed);
        if (composition18F6A0_)
            composition18F6A0_->retire(completed);
        if (viewport18F970_)
            viewport18F970_->retire(completed);
        if (viewportAllocator18DDD0_)
            viewportAllocator18DDD0_->retire(completed);
        if (viewportQueueHeaders_)
            viewportQueueHeaders_->retire(completed);
        if (viewportQueueJournal_)
            viewportQueueJournal_->retire(completed);
        if (statePacket197900_)
            statePacket197900_->retire(completed);
        if (stateAllocator_)
            stateAllocator_->retire(completed);
        if (stateQueueHeaders_)
            stateQueueHeaders_->retire(completed);
        if (stateQueueJournal_)
            stateQueueJournal_->retire(completed);
        while (!inFlight_.empty() && inFlight_.front().timeline <= completed)
            inFlight_.pop_front();
    }
    void resetAfterRealRetirement(uint64_t newerEpoch, uint64_t session) {
        if (!pending_.empty() || !inFlight_.empty() || newerEpoch <= epoch_ || !session)
            throw std::runtime_error(
                "Parent reset requires real prior retirement and a newer epoch");
        // Retag only an actually retired prefix. The numerical buffers stay
        // on the same Device; old outputs retain their immutable old token.
        // The real Service/owner must separately transfer its source ledger.
        const auto drained = [](const auto& profile) {
            return !profile || (profile->pending_.empty() && profile->inFlight_.empty());
        };
        if (!drained(sourceBytePatch_) || !setterProgramsDrained() || !drained(matrix191280_) ||
            !drained(perspective18F710_) || !drained(viewport18F970_) ||
            !drained(viewportAllocator18DDD0_) || !drained(viewportQueueHeaders_) ||
            !drained(viewportQueueJournal_) || !drained(statePacket197900_) ||
            !drained(stateAllocator_) || !drained(stateQueueHeaders_) ||
            !drained(stateQueueJournal_))
            throw std::runtime_error("Upstream epoch carry preceded actual profile retirement");
        const auto compositionDrained = [&]<class Owner>(const Owner& owner) {
            if constexpr (requires { owner.composition18F6A0_; })
                return drained(owner.composition18F6A0_);
            else
                return true;
        };
        if (!compositionDrained(*this))
            throw std::runtime_error("Composition effects preceded true epoch retirement");
        reo_gpu_upstream::BanksHandle next;
        if (upstreamBanks_) {
            const auto& old = upstreamBanks_->stamp();
            if (old.session != session || newerEpoch <= old.epoch ||
                old.bankGeneration != bankGeneration_)
                throw std::invalid_argument(
                    "Upstream epoch carry changed actual cold session/bank generation");
            // Reserve the new identity before changing any active profile.
            next = std::shared_ptr<const reo_gpu_upstream::Banks>(new reo_gpu_upstream::Banks(
                this, &device_, {session, newerEpoch, bankGeneration_, 0},
                {ram_, spr_, context_, completion_}));
        }
        if (next) {
            if (setter196010_)
                setter196010_->banks_ = next;
            for (auto& p : setterAdditional_)
                p->banks_ = next;
            if (matrix191280_)
                matrix191280_->banks_ = next;
            if (perspective18F710_)
                perspective18F710_->banks_ = next;
            if (viewport18F970_)
                viewport18F970_->banks_ = next;
            if (viewportAllocator18DDD0_)
                viewportAllocator18DDD0_->banks_ = next;
            if (viewportQueueHeaders_)
                viewportQueueHeaders_->banks_ = next;
            if (viewportQueueJournal_)
                viewportQueueJournal_->banks_ = next;
            if (statePacket197900_)
                statePacket197900_->banks_ = next;
            if (stateAllocator_)
                stateAllocator_->banks_ = next;
            if (stateQueueHeaders_)
                stateQueueHeaders_->banks_ = next;
            if (stateQueueJournal_)
                stateQueueJournal_->banks_ = next;
            const auto carryComposition = [&]<class Owner>(Owner& owner) {
                if constexpr (requires { owner.composition18F6A0_; })
                    if (owner.composition18F6A0_)
                        owner.composition18F6A0_->banks_ = next;
            };
            carryComposition(*this);
            upstreamBanks_ = std::move(next);
        }
        epoch_ = newerEpoch;
        session_ = session;
        // Never reset allocation/ordinal counters or reseed a stale CPU bank.
    }
    // Bridge access preserves the opaque token and immutable lifetime. This
    // alone does not enable live admission or prove natural DMA chronology.
    const reo_palette_lease::Payload& bridgePayload(const Produced& token) const {
        if (token.ownerIdentity_ != this || !token.lease_)
            throw std::invalid_argument("Foreign parent bridge token");
        return *token.lease_;
    }
    const void* bridgeDeviceIdentity() const noexcept {
        return &device_;
    }
    void bridgeRawWrite(Vulkan::CommandBuffer& cmd, unsigned space, uint32_t at, const void* raw,
                        uint32_t bytes) {
        if (sourceBytePatch_) {
            sourceBytePatch_->record(cmd, space, at, raw, bytes);
            return;
        }
        auto* bank = space == 0   ? ram_.get()
                     : space == 1 ? spr_.get()
                     : space == 2 ? context_.get()
                                  : nullptr;
        const uint32_t limit = space == 0 ? RamBytes : space == 1 ? SprBytes : sizeof(R5900Context);
        if (!bank || !raw || !bytes || (at & 3u) || (bytes & 3u) || at >= limit ||
            bytes > limit - at)
            throw std::invalid_argument(
                "Parent raw write must preserve exact recorded source range");
        cmd.buffer_barrier(*bank, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                           VK_ACCESS_2_MEMORY_WRITE_BIT | VK_ACCESS_2_MEMORY_READ_BIT,
                           VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT);
        cmd.update_buffer_inline(*bank, at, bytes, raw);
        barrier(cmd, *bank);
    }
    void bridgeSourceWrite(Vulkan::CommandBuffer& cmd, const reo_parent_live::RawPatch& patch) {
        reo_parent_live::validateSourcePatchShape(patch);
        // This copies authored CPU bytes only. Numeric provenance stays numeric;
        // no RAW origin tape, scalar role or old numerical read is minted here.
        bridgeRawWrite(cmd, unsigned(patch.range.space), patch.range.address, patch.bytes.data(),
                       patch.range.bytes);
    }

  private:
    void bindOriginalUpstreamOwner(uint64_t session, uint64_t epoch, const void* service) {
        if (compositionModule_.empty() && matrixModule_.empty() && perspectiveModule_.empty() &&
            viewportModule_.empty() && viewportHeadersModule_.empty() &&
            viewportJournalModule_.empty() && setterModule_.empty() &&
            setterAdditionalModules_.empty() &&
            std::all_of(stateModules_.begin(), stateModules_.end(),
                        [](const auto& module) { return module.empty(); }) &&
            stateAllocatorModule_.empty() && stateHeadersModule_.empty() &&
            stateJournalModule_.empty())
            return;
        if (upstreamBanks_ || !session || !epoch || !service)
            throw std::invalid_argument("Repeated/incomplete upstream cold owner binding");
        if ((session_ && session_ != session) || (epoch_ && epoch_ != epoch))
            throw std::invalid_argument(
                "Upstream cold owner conflicts with existing parent identity");
        // Fork/restore must use the very same authenticated cold identity even
        // before the first palette-parent enqueue. Never restart ordinals.
        session_ = session;
        epoch_ = epoch;
        upstreamService_ = service;
        upstreamBanks_ = std::shared_ptr<const reo_gpu_upstream::Banks>(
            new reo_gpu_upstream::Banks(this, &device_, {session, epoch, bankGeneration_, 0},
                                        {ram_, spr_, context_, completion_}));
        if (!setterModule_.empty())
            setter196010_ =
                std::unique_ptr<reo_gpu_upstream::Setter196010>(new reo_gpu_upstream::Setter196010(
                    device_, setterModule_, upstreamBanks_, service));
        for (const auto& module : setterAdditionalModules_)
            setterAdditional_.push_back(std::unique_ptr<reo_gpu_upstream::Setter196010>(
                new reo_gpu_upstream::Setter196010(device_, module, upstreamBanks_, service)));
        for (uint32_t command = 0; command < 256u; ++command) {
            uint32_t issuers =
                setter196010_ && setter196010_->supportsModuleCommand(command) ? 1u : 0u;
            for (const auto& p : setterAdditional_)
                issuers += p->supportsModuleCommand(command) ? 1u : 0u;
            if (issuers > 1u)
                throw std::invalid_argument("Overlapping setter source module command sets");
        }

        if (!compositionModule_.empty())
            composition18F6A0_ = std::unique_ptr<reo_gpu_upstream::Composition18F6A0>(
                new reo_gpu_upstream::Composition18F6A0(device_, compositionModule_, upstreamBanks_,
                                                        service));
        if (!matrixModule_.empty())
            matrix191280_ =
                std::unique_ptr<reo_gpu_upstream::Matrix191280>(new reo_gpu_upstream::Matrix191280(
                    device_, matrixModule_, upstreamBanks_, service));
        if (!perspectiveModule_.empty())
            perspective18F710_ = std::unique_ptr<reo_gpu_upstream::Perspective18F710>(
                new reo_gpu_upstream::Perspective18F710(device_, perspectiveModule_, upstreamBanks_,
                                                        service));
        if (!viewportModule_.empty())
            viewport18F970_ = std::unique_ptr<reo_gpu_upstream::Viewport>(
                new reo_gpu_upstream::Viewport(device_, viewportModule_, upstreamBanks_, service));
        if (!viewportAllocatorModule_.empty()) {
            if (!viewport18F970_)
                throw std::invalid_argument(
                    "Allocator module requires its exact viewport source owner");
            viewportAllocator18DDD0_ = std::unique_ptr<reo_gpu_upstream::Allocator18DDD0>(
                new reo_gpu_upstream::Allocator18DDD0(device_, service, upstreamBanks_,
                                                      viewportAllocatorModule_));
        }
        if (!viewportHeadersModule_.empty())
            viewportQueueHeaders_ = std::unique_ptr<reo_gpu_upstream::QueueHeaderMetadataPipeline>(
                new reo_gpu_upstream::QueueHeaderMetadataPipeline(
                    device_, this, service, upstreamBanks_, viewportHeadersModule_));
        if (!viewportJournalModule_.empty())
            viewportQueueJournal_ = std::unique_ptr<reo_gpu_upstream::QueueJournalPipeline>(
                new reo_gpu_upstream::QueueJournalPipeline(device_, service, upstreamBanks_,
                                                           viewportJournalModule_));
        const bool stateAny = std::any_of(stateModules_.begin(), stateModules_.end(),
                                          [](const auto& m) { return !m.empty(); });
        if (stateAny) {
            for (const auto& m : stateModules_)
                if (m.empty())
                    throw std::invalid_argument("197900 needs all three source stages");
            statePacket197900_ = std::unique_ptr<reo_gpu_upstream::StatePacket197900>(
                new reo_gpu_upstream::StatePacket197900(device_, stateModules_, upstreamBanks_,
                                                        service));
        }
        if (!stateAllocatorModule_.empty() || !stateHeadersModule_.empty() ||
            !stateJournalModule_.empty()) {
            if (!statePacket197900_ || stateAllocatorModule_.empty() ||
                stateHeadersModule_.empty() || stateJournalModule_.empty())
                throw std::invalid_argument(
                    "197900 actual allocator/queue source modules must be complete");
            stateAllocator_ = std::unique_ptr<reo_gpu_upstream::Allocator18DDD0>(
                new reo_gpu_upstream::Allocator18DDD0(device_, service, upstreamBanks_,
                                                      stateAllocatorModule_));
            stateQueueHeaders_ = std::unique_ptr<reo_gpu_upstream::QueueHeaderMetadataPipeline>(
                new reo_gpu_upstream::QueueHeaderMetadataPipeline(
                    device_, this, service, upstreamBanks_, stateHeadersModule_));
            stateQueueJournal_ = std::unique_ptr<reo_gpu_upstream::QueueJournalPipeline>(
                new reo_gpu_upstream::QueueJournalPipeline(device_, service, upstreamBanks_,
                                                           stateJournalModule_));
        }
    }
    void verifyOriginalUpstreamOrder(const reo_gpu_upstream::CallHandle& call) const {
        if (!upstreamBanks_ || !call || call->issuer() != upstreamService_ ||
            upstreamRecordedOrdinal_ == UINT64_MAX)
            throw std::invalid_argument("Foreign or exhausted actual upstream owner recorder");
        const auto& a = upstreamBanks_->stamp();
        const auto& b = call->stamp();
        if (a.session != b.session || a.epoch != b.epoch || a.bankGeneration != b.bankGeneration ||
            b.ordinal != upstreamRecordedOrdinal_ + 1)
            throw std::invalid_argument(
                "Original upstream recording overtook its shared issued chronology");
    }
    void prewarmOriginalUpstream() {
        if (!composition18F6A0_ && !matrix191280_ && !perspective18F710_ && !viewport18F970_ &&
            !viewportQueueHeaders_ && !viewportQueueJournal_ && !setter196010_ &&
            setterAdditional_.empty() && !sourceBytePatch_ && !statePacket197900_)
            return;
        auto cmd = device_.request_command_buffer();
        if (!cmd)
            throw std::runtime_error("Actual upstream prewarm command allocation failed");
        try {
            const auto compile = [&](Vulkan::Program* program) {
                if (!program)
                    throw std::runtime_error("Actual upstream prewarm program absent");
                cmd->set_program(program);
                Vulkan::DeferredPipelineCompile state{};
                cmd->extract_pipeline_state(state);
                auto pipeline = program->get_pipeline(state.hash);
                if (pipeline.pipeline == VK_NULL_HANDLE)
                    pipeline = Vulkan::CommandBuffer::build_compute_pipeline(
                        &device_, state, Vulkan::CommandBuffer::CompileMode::Sync);
                if (pipeline.pipeline == VK_NULL_HANDLE)
                    throw std::runtime_error("Actual upstream synchronous driver prewarm refused");
            };
            if (sourceBytePatch_)
                compile(sourceBytePatch_->program_);
            if (setter196010_)
                compile(setter196010_->program_);
            for (const auto& p : setterAdditional_)
                compile(p->program_);
            if (composition18F6A0_)
                compile(composition18F6A0_->program_);
            if (matrix191280_)
                compile(matrix191280_->program_);
            if (perspective18F710_)
                compile(perspective18F710_->program_);
            if (viewport18F970_)
                for (auto* program : viewport18F970_->programs_)
                    compile(program);
            if (viewportAllocator18DDD0_)
                compile(viewportAllocator18DDD0_->program_);
            if (viewportQueueHeaders_)
                compile(viewportQueueHeaders_->program_);
            if (viewportQueueJournal_)
                compile(viewportQueueJournal_->program_);
            if (statePacket197900_)
                for (auto* p : statePacket197900_->programs_)
                    compile(p);
            if (stateAllocator_)
                compile(stateAllocator_->program_);
            if (stateQueueHeaders_)
                compile(stateQueueHeaders_->program_);
            if (stateQueueJournal_)
                compile(stateQueueJournal_->program_);
            // No descriptors, bank access, dispatch or guest result. This follows
            // the existing real same-Device catalogue cache/prewarm lifecycle.
        } catch (...) {
            device_.submit_discard(cmd);
            throw;
        }
        device_.submit_discard(cmd);
    }
    reo_gpu_upstream::Setter196010::OutputHandle
    recordOriginalSetter(Vulkan::CommandBuffer& cmd, const reo_gpu_upstream::CallHandle& call) {
        auto* setter = call ? setterForCommand(call->a0() & 255u) : nullptr;
        if (!setter)
            throw std::runtime_error("Original setter command lacks one exact loaded module");
        verifyOriginalUpstreamOrder(call);
        auto output = setter->record(cmd, call);
        upstreamRecordedOrdinal_ = call->stamp().ordinal;
        return output;
    }
    reo_gpu_upstream::Matrix191280::OutputHandle
    recordOriginal191280(Vulkan::CommandBuffer& cmd, const reo_gpu_upstream::CallHandle& call) {
        if (!matrix191280_)
            throw std::runtime_error("Original191280 module is default off");
        verifyOriginalUpstreamOrder(call);
        auto output = matrix191280_->record(cmd, call);
        upstreamRecordedOrdinal_ = call->stamp().ordinal;
        return output;
    }
    reo_gpu_upstream::Composition18F6A0::OutputHandle
    recordOriginalComposition(Vulkan::CommandBuffer& cmd,
                              const reo_gpu_upstream::CallHandle& call) {
        if (!composition18F6A0_)
            throw std::runtime_error("Actual composition module is default off");
        verifyOriginalUpstreamOrder(call);
        auto output = composition18F6A0_->record(cmd, call);
        upstreamRecordedOrdinal_ = call->stamp().ordinal;
        return output;
    }
    reo_gpu_upstream::Perspective18F710::OutputHandle
    recordOriginalPerspective(Vulkan::CommandBuffer& cmd,
                              const reo_gpu_upstream::CallHandle& call) {
        if (!perspective18F710_)
            throw std::runtime_error("Original perspective profile is default off");
        verifyOriginalUpstreamOrder(call);
        auto output = perspective18F710_->record(cmd, call);
        upstreamRecordedOrdinal_ = call->stamp().ordinal;
        return output;
    }
    reo_gpu_upstream::Viewport::OutputHandle
    recordOriginalViewport(Vulkan::CommandBuffer& cmd, const reo_gpu_upstream::CallHandle& call) {
        if (!viewport18F970_)
            throw std::runtime_error("Viewport module is default off");
        verifyOriginalUpstreamOrder(call);
        auto output = viewport18F970_->record(cmd, call);
        upstreamRecordedOrdinal_ = call->stamp().ordinal;
        return output;
    }

    reo_gpu_upstream::Allocator18DDD0*
    allocatorForCall(const reo_gpu_upstream::CallHandle& call) const {
        return call && call->entry() == 0x197900u ? stateAllocator_.get()
                                                  : viewportAllocator18DDD0_.get();
    }
    reo_gpu_upstream::QueueHeaderMetadataPipeline*
    queueHeaderForCall(const reo_gpu_upstream::CallHandle& call) const {
        return call && call->entry() == 0x197900u ? stateQueueHeaders_.get()
                                                  : viewportQueueHeaders_.get();
    }
    reo_gpu_upstream::QueueJournalPipeline*
    queueJournalForCall(const reo_gpu_upstream::CallHandle& call) const {
        return call && call->entry() == 0x197900u ? stateQueueJournal_.get()
                                                  : viewportQueueJournal_.get();
    }
    void
    validateOriginalAllocator(const reo_gpu_upstream::AllocatorHeapCaptureHandle& capture) const {
        auto* allocator = capture ? allocatorForCall(capture->call_) : nullptr;
        if (!allocator || !capture || capture->issuer_ != upstreamService_ ||
            capture->banks_ != upstreamBanks_ ||
            capture->call_->stamp().ordinal != upstreamRecordedOrdinal_ ||
            (capture->stateStage_
                 ? (!statePacket197900_ || !statePacket197900_->owns(capture->stateStage_))
                 : (!viewport18F970_ || !viewport18F970_->owns(capture->originalStage_))))
            throw std::invalid_argument("Allocator is not this actual held source continuation");
        allocator->validateCapture(capture);
    }
    reo_gpu_upstream::Allocator18DDD0::OutputHandle
    recordOriginalAllocator(Vulkan::CommandBuffer& cmd,
                            const reo_gpu_upstream::AllocatorHeapCaptureHandle& capture) {
        validateOriginalAllocator(capture);
        return allocatorForCall(capture->call_)->record(cmd, capture);
    }
    reo_gpu_upstream::StatePacket197900::OutputHandle
    recordOriginalStatePacket(Vulkan::CommandBuffer& cmd,
                              const reo_gpu_upstream::CallHandle& call) {
        if (!statePacket197900_)
            throw std::invalid_argument("197900 absent/default off");
        verifyOriginalUpstreamOrder(call);
        auto output = statePacket197900_->record(cmd, call);
        upstreamRecordedOrdinal_ = call->stamp().ordinal;
        return output;
    }
    reo_gpu_upstream::StatePacket197900::OutputHandle resumeOriginalStatePacket(
        Vulkan::CommandBuffer& cmd,
        const reo_gpu_upstream::StatePacket197900::ControlReturnHandle& token) {
        if (!statePacket197900_)
            throw std::invalid_argument("197900 absent/default off");
        return statePacket197900_->resume(cmd, token);
    }
    reo_gpu_upstream::Viewport::OutputHandle
    resumeOriginalViewport(Vulkan::CommandBuffer& cmd,
                           const reo_gpu_upstream::Viewport::ControlReturnHandle& returned) {
        if (!viewport18F970_)
            throw std::runtime_error("Viewport module is default off");
        return viewport18F970_->resume(cmd, returned);
    }

  public:
    const Vulkan::Buffer& ram() const {
        return *ram_;
    }
    const Vulkan::Buffer& scratchpad() const {
        return *spr_;
    }
    const Vulkan::Buffer& context() const {
        return *context_;
    }
    const Vulkan::Buffer& completion() const {
        return *completion_;
    }
    const Vulkan::Buffer& resultMetadata() const {
        return *meta_;
    }
    static constexpr bool CanonicalInstallerPresent = false;
};
} // namespace reo_gpu_palette_parent
