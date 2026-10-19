#pragma once
#include "upstream_bank_abi.hpp"
#include "context_layout.hpp"
#include "viewport_effects_packet.hpp"
#include "command_buffer.hpp"
#include "tools/parallel_gs_backend/resident_geometry/enrollment/sha256.hpp"
#include <deque>
namespace reo_gpu_upstream {
// Numerical/graphics source is complete in the shader. Control-return issuance
// is private to actual Service and still requires its genuine allocator/queue
// call, scalar/heap write journal and context ownership proof before activation.
class Viewport final {
    friend class reo_gpu_palette_parent::Producer;

  public:
    static constexpr uint32_t ControlWords = 32, ControlBytes = ControlWords * 4;
    class Output final {
        friend class Viewport;
        friend class reo_parent_install::Service;
        const Viewport* issuer_;
        BanksHandle banks_;
        CallHandle call_;
        Vulkan::BufferHandle receipt_, control_, effects_, carry_, transaction_;
        uint32_t inputPhase_;
        Output(const Viewport* issuer, BanksHandle banks, CallHandle call,
               Vulkan::BufferHandle receipt, Vulkan::BufferHandle control,
               Vulkan::BufferHandle effects, Vulkan::BufferHandle carry,
               Vulkan::BufferHandle transaction, uint32_t phase)
            : issuer_(issuer), banks_(std::move(banks)), call_(std::move(call)),
              receipt_(std::move(receipt)), control_(std::move(control)),
              effects_(std::move(effects)), carry_(std::move(carry)),
              transaction_(std::move(transaction)), inputPhase_(phase) {}

      public:
        const Call& call() const {
            return *call_;
        }
        const Vulkan::Buffer& receipt() const {
            return *receipt_;
        }
        const Vulkan::Buffer& control() const {
            return *control_;
        }
        const BanksHandle& banks() const {
            return banks_;
        }
        const Vulkan::Buffer& effects() const {
            return *effects_;
        }
        const Vulkan::BufferHandle& effectsHandle() const {
            return effects_;
        }
        const Vulkan::Buffer& provenanceCarry() const {
            return *carry_;
        }
        uint32_t inputPhase() const noexcept {
            return inputPhase_;
        }
    };
    using OutputHandle = std::shared_ptr<const Output>;
    class ControlReturn final {
        friend class reo_parent_install::Service;
        friend class Viewport;
        const void* issuer_;
        OutputHandle prior_;
        uint32_t phase_, callee_, continuation_;
        int32_t task_;
        uint64_t realFenceOrdinal_;
        Vulkan::BufferHandle exactHelperReceipt_, exactQueueJournal_;
        // Only actual Service may invoke after genuine GPU-control completion,
        // real original CPU callee return and ordered scalar/heap write transfer.
        ControlReturn(const void* issuer, OutputHandle prior, uint32_t phase, uint32_t callee,
                      uint32_t continuation, int32_t task, uint64_t realFenceOrdinal,
                      Vulkan::BufferHandle helperReceipt = {},
                      Vulkan::BufferHandle queueJournal = {})
            : issuer_(issuer), prior_(std::move(prior)), phase_(phase), callee_(callee),
              continuation_(continuation), task_(task), realFenceOrdinal_(realFenceOrdinal),
              exactHelperReceipt_(std::move(helperReceipt)),
              exactQueueJournal_(std::move(queueJournal)) {}

      public:
        ControlReturn(const ControlReturn&) = delete;
        ControlReturn& operator=(const ControlReturn&) = delete;
    };
    using ControlReturnHandle = std::shared_ptr<const ControlReturn>;

  private:
    Vulkan::Device& device_;
    BanksHandle banks_;
    const void* callIssuer_;
    std::array<Vulkan::Program*, ViewportModuleCount> programs_{};
    Vulkan::BufferHandle initialControl_, initialCarry_, emptyHelper_;
    uint64_t lastOrdinal_ = 0, lastSubmission_ = 0;
    std::vector<OutputHandle> pending_;
    std::vector<OutputHandle> resumed_;
    struct Submission {
        uint64_t timeline;
        std::vector<OutputHandle> outputs;
    };
    std::deque<Submission> inFlight_;
    static void barrier(Vulkan::CommandBuffer& cmd, const Vulkan::Buffer& b) {
        cmd.buffer_barrier(b, VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT,
                           VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                           VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT,
                           VK_ACCESS_2_SHADER_STORAGE_READ_BIT |
                               VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
    }
    Vulkan::BufferHandle buffer(uint32_t bytes, const void* initial = nullptr) {
        Vulkan::BufferCreateInfo ci{};
        ci.domain = Vulkan::BufferDomain::Device;
        ci.size = bytes;
        ci.usage = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT |
                   VK_BUFFER_USAGE_TRANSFER_DST_BIT;
        auto b = device_.create_buffer(ci, initial);
        if (!b)
            throw std::runtime_error("Viewport immutable control allocation failed");
        return b;
    }
    OutputHandle dispatch(Vulkan::CommandBuffer& cmd, CallHandle call, uint32_t phase,
                          const Vulkan::Buffer& prior, const Vulkan::Buffer& provenance,
                          const Vulkan::Buffer& helperReceipt,
                          const Vulkan::Buffer& helperJournal) {
        auto output = std::shared_ptr<const Output>(
            new Output(this, banks_, std::move(call), buffer(ReceiptBytes), buffer(ControlBytes),
                       buffer(ViewportEffectsBytes), buffer(ViewportCarryBytes),
                       buffer(ViewportTransactionBytes), phase));
        pending_.push_back(output);
        for (unsigned b = 0; b < 4; ++b)
            barrier(cmd, banks_->bank(Bank(b)));
        barrier(cmd, *output->receipt_);
        barrier(cmd, prior);
        barrier(cmd, *output->control_);
        barrier(cmd, *output->effects_);
        barrier(cmd, *output->carry_);
        barrier(cmd, provenance);
        barrier(cmd, helperReceipt);
        barrier(cmd, helperJournal);
        ViewportParameters p{parameters(*output->call_), uint32_t(output->call_->task())};
        p.call.reserved = phase;
        for (unsigned b = 0; b < 4; ++b)
            cmd.set_storage_buffer(0, b, banks_->bank(Bank(b)));
        cmd.set_storage_buffer(0, 4, *output->receipt_);
        cmd.set_storage_buffer(0, 5, prior);
        cmd.set_storage_buffer(0, 6, *output->control_);
        cmd.set_storage_buffer(0, 7, *output->effects_);
        cmd.set_storage_buffer(0, 8, provenance);
        cmd.set_storage_buffer(0, 9, *output->carry_);
        cmd.set_storage_buffer(0, 10, helperJournal);
        cmd.set_storage_buffer(0, 11, helperReceipt);
        cmd.set_storage_buffer(0, 12, *output->transaction_);
        cmd.push_constants(&p, 0, sizeof(p));
        // A fixed original call-graph schedule. Segment PC tests and every
        // calculation run on GPU; no numerical/branch readback selects a pass.
        constexpr std::array<unsigned, 18> schedule{0, 1, 2, 3, 4, 3, 1, 5, 1,
                                                    6, 1, 6, 1, 7, 8, 9, 1, 10};
        for (const auto part : schedule) {
            barrier(cmd, *output->transaction_);
            barrier(cmd, *output->carry_);
            cmd.set_program(programs_[part]);
            cmd.dispatch(1, 1, 1);
        }
        for (unsigned b = 0; b < 4; ++b)
            barrier(cmd, banks_->bank(Bank(b)));
        barrier(cmd, *output->receipt_);
        barrier(cmd, *output->control_);
        barrier(cmd, *output->effects_);
        barrier(cmd, *output->carry_);
        return output;
    }
    void validateCall(const CallHandle& call) const {
        if (!call || call->issuer() != callIssuer_ || !supports(call->entry()) ||
            insideClosedSource(call->returnPc()) || call->task() < 1)
            throw std::invalid_argument("Viewport original call was not issued by actual Service "
                                        "or its return needs another source scope");
        const auto mask = argumentMask(call->entry());
        if (((mask & 2u) == 0u && call->a0()) || ((mask & 4u) == 0u && call->a1()) ||
            ((mask & 8u) == 0u && call->a2()))
            throw std::invalid_argument(
                "Viewport unused control fields must remain zero transport placeholders");
        const auto& s = call->stamp();
        const auto& b = banks_->stamp();
        if (!s.ordinal || s.session != b.session || s.epoch != b.epoch ||
            s.bankGeneration != b.bankGeneration)
            throw std::invalid_argument("Viewport original call source bank is stale/foreign");
    }

  public:
    static bool supports(uint32_t entry) {
        return entry == 0x18f970u || entry == 0x18fce0u || entry == 0x18f880u ||
               entry == 0x18f7e0u || entry == 0x197490u;
    }
    // Only incoming argument words consumed by this exact root can be
    // compared against genuine CPU-owned control. Unused GPU carry is opaque.
    // Shared entry control-mask convention: ReturnPC1,A02,A14,A28.
    static uint32_t argumentMask(uint32_t entry) {
        return entry == 0x18f7e0u ? 3u : entry == 0x18fce0u ? 9u : supports(entry) ? 15u : 0u;
    }
    static bool insideClosedSource(uint32_t pc) {
        return (pc >= 0x18f7e0u && pc < 0x18fe20u) || (pc >= 0x191280u && pc < 0x1912f8u) ||
               (pc >= 0x191500u && pc < 0x191524u) || (pc >= 0x197490u && pc < 0x197780u);
    }

  private:
    // The actual persistent-bank Producer mints exactly one pipeline for its
    // bank lifecycle. A second public instance must not reset token chronology.
    Viewport(Vulkan::Device& device, const std::vector<uint32_t>& module, BanksHandle banks,
             const void* actualService)
        : device_(device), banks_(std::move(banks)), callIssuer_(actualService) {
        if (!banks_ || banks_->device() != &device_ || !banks_->issuer() || !callIssuer_)
            throw std::invalid_argument("Viewport requires actual parent-owned persistent banks");
        const std::array<uint32_t, 4> sizes{RamBytes, SprBytes, ContextBytes, CompletionBytes};
        for (unsigned b = 0; b < 4; ++b) {
            const auto& ci = banks_->bank(Bank(b)).get_create_info();
            if (ci.size != sizes[b] || ci.domain != Vulkan::BufferDomain::Device ||
                (ci.usage &
                 (VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT)) !=
                    (VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT))
                throw std::invalid_argument("Viewport persistent bank shape differs");
        }
        if (module.size() < 8 || module[0] != ViewportBundleMagic || module[1] != 1u ||
            module[2] != ViewportModuleCount || module[3] != sizeof(ViewportParameters) ||
            module[4] != 412u || module[5] != ViewportCarryWords ||
            module[6] != ViewportTransactionWords || module[7])
            throw std::invalid_argument("Viewport source module is absent");
        std::vector<uint8_t> bytes(module.size() * 4);
        std::memcpy(bytes.data(), module.data(), bytes.size());
        if (reo_gpu_catalog::sha256(bytes) !=
            "9512e1e750326ecc00f9fa61e7ade5104cfabd1390afda4ee580c524a63b552d")
            throw std::invalid_argument("Viewport exact whole source module pin differs");
        VkPhysicalDeviceFloatControlsProperties controls{};
        controls.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES;
        VkPhysicalDeviceProperties2 properties{};
        properties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2;
        properties.pNext = &controls;
        vkGetPhysicalDeviceProperties2(device_.get_physical_device(), &properties);
        if (!controls.shaderRoundingModeRTEFloat32 || !controls.shaderDenormPreserveFloat32 ||
            !controls.shaderSignedZeroInfNanPreserveFloat32)
            throw std::invalid_argument("Viewport strict original float modes absent");
        Vulkan::ResourceLayout shape{};
        shape.sets[0].storage_buffer_mask = 8191;
        shape.push_constant_size = sizeof(ViewportParameters);
        for (unsigned b = 0; b < 13; ++b)
            shape.sets[0].meta[b].array_size = 1;
        if (properties.properties.limits.maxPerStageDescriptorStorageBuffers < 13u)
            throw std::invalid_argument(
                "Viewport transactional fragments need thirteen storage bindings");
        size_t offset = 8;
        for (unsigned part = 0; part < ViewportModuleCount; ++part) {
            if (offset >= module.size())
                throw std::invalid_argument("Viewport fragment bundle is truncated");
            const size_t count = module[offset++];
            if (count < 5 || count > 128u * 1024u / 4u || count > module.size() - offset ||
                module[offset] != 0x07230203u)
                throw std::invalid_argument("Viewport bounded fragment shape differs");
            auto* program = device_.request_program(module.data() + offset, count * 4u, &shape);
            offset += count;
            if (!program || !program->get_pipeline_layout())
                throw std::runtime_error("Viewport fragment creation failed");
            const auto& actual = program->get_pipeline_layout()->get_resource_layout();
            if (actual.descriptor_set_mask != 1 || actual.bindless_descriptor_set_mask ||
                actual.sets[0].storage_buffer_mask != 8191 || actual.push_constant_range.offset ||
                actual.push_constant_range.size != sizeof(ViewportParameters) ||
                actual.push_constant_range.stageFlags != VK_SHADER_STAGE_COMPUTE_BIT)
                throw std::invalid_argument("Viewport thirteen-buffer fragment ABI differs");
            for (unsigned b = 0; b < 13; ++b)
                if (actual.sets[0].meta[b].array_size != 1 ||
                    actual.stages_for_bindings[0][b] != VK_SHADER_STAGE_COMPUTE_BIT)
                    throw std::invalid_argument("Viewport fragment binding shape differs");
            programs_[part] = program;
        }
        if (offset != module.size())
            throw std::invalid_argument("Viewport fragment bundle has trailing data");
        const std::array<uint32_t, ControlWords> zero{};
        initialControl_ = buffer(ControlBytes, zero.data());
        const std::array<uint32_t, 24> empty{};
        emptyHelper_ = buffer(uint32_t(sizeof(empty)), empty.data());
        std::vector<uint32_t> emptyCarry(ViewportCarryWords, 0);
        initialCarry_ = buffer(ViewportCarryBytes, emptyCarry.data());
    }

  public:
    Viewport(const Viewport&) = delete;
    ~Viewport() {
        if (!pending_.empty() || !inFlight_.empty())
            device_.wait_idle();
    }
    OutputHandle record(Vulkan::CommandBuffer& cmd, const CallHandle& call) {
        validateCall(call);
        if (call->stamp().ordinal <= lastOrdinal_ || pending_.size() >= 4096)
            throw std::invalid_argument("Viewport source chronology repeated/exhausted");
        lastOrdinal_ = call->stamp().ordinal;
        return dispatch(cmd, call, 0, *initialControl_, *initialCarry_, *emptyHelper_,
                        *emptyHelper_);
    }
    OutputHandle resume(Vulkan::CommandBuffer& cmd, const ControlReturnHandle& token) {
        if (!token || token->issuer_ != callIssuer_ || !owns(token->prior_) ||
            token->task_ != token->prior_->call().task() || !token->realFenceOrdinal_)
            throw std::invalid_argument(
                "Viewport control return is not actual completed Service work");
        if (token->phase_ == 1) {
            if (token->callee_ != 0x18ddd0u ||
                (token->continuation_ != 0x197524u && token->continuation_ != 0x197538u))
                throw std::invalid_argument("Viewport allocator returned to foreign continuation");
        } else if (token->phase_ == 2) {
            if (token->callee_ != 0x18cfb0u || token->continuation_ != 0x197750u)
                throw std::invalid_argument("Viewport queue returned to foreign continuation");
        } else
            throw std::invalid_argument(
                "Viewport control phase is not an original CPU transport call");
        if (!token->exactHelperReceipt_ ||
            token->exactHelperReceipt_->get_create_info().size != ReceiptBytes ||
            (token->phase_ == 2u && !token->exactQueueJournal_) ||
            (token->phase_ == 1u && token->exactQueueJournal_))
            throw std::invalid_argument(
                "Viewport resume lacks the exact actual completed helper output/journal");
        if (std::find(resumed_.begin(), resumed_.end(), token->prior_) != resumed_.end() ||
            resumed_.size() >= 4096)
            throw std::invalid_argument(
                "Viewport actual control return was consumed twice/exhausted");
        validateCall(token->prior_->call_);
        resumed_.push_back(token->prior_);
        return dispatch(cmd, token->prior_->call_, token->phase_, *token->prior_->control_,
                        *token->prior_->carry_, *token->exactHelperReceipt_,
                        token->exactQueueJournal_ ? *token->exactQueueJournal_ : *emptyHelper_);
    }
    bool owns(const OutputHandle& output) const noexcept {
        return output && output->issuer_ == this && output->banks_ == banks_;
    }
    void seal(uint64_t realTimeline) {
        if (!realTimeline || realTimeline <= lastSubmission_)
            throw std::invalid_argument("Viewport seal lacks newer actual timeline");
        lastSubmission_ = realTimeline;
        if (!pending_.empty()) {
            inFlight_.push_back({realTimeline, std::move(pending_)});
            pending_.clear();
        }
    }
    void retire(uint64_t realTimeline) {
        if (realTimeline > lastSubmission_)
            throw std::invalid_argument("Viewport completed timeline exceeds actual seal");
        while (!inFlight_.empty() && inFlight_.front().timeline <= realTimeline)
            inFlight_.pop_front();
    }
    // All byte writes in the exact pinned module reject protected heap aliases
    // before transactional bank commit. Only an inherited prior RAW lease is
    // preserved; this does not mint a generic RAW label from host shadows.
    static constexpr bool PreservesInheritedHeapControlLease = true;
    static constexpr bool ActualCpuControlReturnIssuerImplemented = false;
    static constexpr bool NaturalSourceClosureImplemented = false;
};
} // namespace reo_gpu_upstream
