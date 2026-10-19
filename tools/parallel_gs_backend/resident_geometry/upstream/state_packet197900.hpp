#pragma once
#include "upstream_bank_abi.hpp"
#include "effects_packet.hpp"
#include "tools/parallel_gs_backend/resident_geometry/enrollment/sha256.hpp"
#include "command_buffer.hpp"
#include <algorithm>
#include <deque>
namespace reo_gpu_upstream {
// Three bounded original197900 GPU stages. The actual Service owns protected
// allocator/queue orchestration; packet construction remains in these shaders.
class StatePacket197900 final {
    friend class reo_gpu_palette_parent::Producer;
    friend class reo_parent_install::Service;

  public:
    static constexpr uint32_t ControlWords = 32, ControlBytes = ControlWords * 4;
    static constexpr uint32_t ScratchWords = 12246, ScratchBytes = ScratchWords * 4;
    class Output final {
        friend class StatePacket197900;
        friend class reo_parent_install::Service;
        const StatePacket197900* issuer_;
        BanksHandle banks_;
        CallHandle call_;
        Vulkan::BufferHandle receipt_, control_, effects_, scratch_;
        uint32_t stage_;
        mutable uint64_t realTimeline_ = 0;
        Output(const StatePacket197900* issuer, BanksHandle banks, CallHandle call,
               Vulkan::BufferHandle receipt, Vulkan::BufferHandle control,
               Vulkan::BufferHandle effects, Vulkan::BufferHandle scratch, uint32_t stage)
            : issuer_(issuer), banks_(std::move(banks)), call_(std::move(call)),
              receipt_(std::move(receipt)), control_(std::move(control)),
              effects_(std::move(effects)), scratch_(std::move(scratch)), stage_(stage) {}

      public:
        const Call& call() const noexcept {
            return *call_;
        }
        const Vulkan::Buffer& receipt() const noexcept {
            return *receipt_;
        }
        const Vulkan::Buffer& control() const noexcept {
            return *control_;
        }
        const Vulkan::Buffer& effects() const noexcept {
            return *effects_;
        }
        uint32_t stage() const noexcept {
            return stage_;
        }
    };
    using OutputHandle = std::shared_ptr<const Output>;
    class ControlReturn final {
        friend class reo_parent_install::Service;
        friend class StatePacket197900;
        const void* issuer_;
        OutputHandle prior_;
        uint32_t completedStage_, callee_, continuation_;
        int32_t task_;
        uint64_t actualFenceOrdinal_;
        Vulkan::BufferHandle actualGpuCalleeReceipt_, actualGpuCalleeJournal_;
        std::shared_ptr<const void> actualCalleeLifetime_;
        // Only actual Service may construct this after the real source-qualified
        // allocator/queue GPU output has completed. The GPU revalidates its exact
        // receipt stamp/magic/context/continuation before any packet/Context write.
        ControlReturn(const void* issuer, OutputHandle prior, uint32_t stage, uint32_t callee,
                      uint32_t continuation, int32_t task, uint64_t actualFenceOrdinal,
                      Vulkan::BufferHandle actualGpuCalleeReceipt,
                      Vulkan::BufferHandle actualGpuCalleeJournal,
                      std::shared_ptr<const void> actualCalleeLifetime)
            : issuer_(issuer), prior_(std::move(prior)), completedStage_(stage), callee_(callee),
              continuation_(continuation), task_(task), actualFenceOrdinal_(actualFenceOrdinal),
              actualGpuCalleeReceipt_(std::move(actualGpuCalleeReceipt)),
              actualGpuCalleeJournal_(std::move(actualGpuCalleeJournal)),
              actualCalleeLifetime_(std::move(actualCalleeLifetime)) {}

      public:
        ControlReturn(const ControlReturn&) = delete;
    };
    using ControlReturnHandle = std::shared_ptr<const ControlReturn>;

  private:
    Vulkan::Device& device_;
    BanksHandle banks_;
    const void* actualService_;
    std::array<Vulkan::Program*, 3> programs_{};
    Vulkan::BufferHandle zeroControl_, zeroReceipt_;
    uint64_t lastOrdinal_ = 0, lastSubmission_ = 0;
    CallHandle activeCall_;
    std::vector<OutputHandle> pending_, resumed_;
    struct Submission {
        uint64_t timeline;
        std::vector<OutputHandle> outputs;
    };
    std::deque<Submission> inFlight_;
    static void barrier(Vulkan::CommandBuffer& cmd, const Vulkan::Buffer& buffer) {
        cmd.buffer_barrier(buffer, VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT,
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
        auto result = device_.create_buffer(ci, initial);
        if (!result)
            throw std::runtime_error("197900 exact stage buffer allocation failed");
        return result;
    }
    StatePacket197900(Vulkan::Device& device, const std::array<std::vector<uint32_t>, 3>& modules,
                      BanksHandle banks, const void* actualService)
        : device_(device), banks_(std::move(banks)), actualService_(actualService) {
        if (!banks_ || banks_->device() != &device_ || !banks_->issuer() || !actualService_)
            throw std::invalid_argument("197900 lacks genuine Producer/Service banks");
        const std::array<uint32_t, 4> sizes{RamBytes, SprBytes, ContextBytes, CompletionBytes};
        for (unsigned bank = 0; bank < 4; ++bank) {
            const auto& ci = banks_->bank(Bank(bank)).get_create_info();
            if (ci.size != sizes[bank] || ci.domain != Vulkan::BufferDomain::Device ||
                (ci.usage & VK_BUFFER_USAGE_STORAGE_BUFFER_BIT) == 0)
                throw std::invalid_argument("197900 exact bank shape differs");
        }
        const std::array<const char*, 3> pins{
            "4abb37170c0c62505b9fa9f24f7d8aecbb048b1b37dfa2578ef46880ff250249",
            "7f52eafc0fafa4f9b341af4d4a29d85b4a59a451ac979dec65e80377af2a7d8c",
            "aa2fac258de837e5214b63e4110999571dd48669aba5b8697ea2af54f6e5ee85"};
        Vulkan::ResourceLayout shape{};
        shape.sets[0].storage_buffer_mask = 2047;
        shape.push_constant_size = sizeof(Parameters);
        for (unsigned binding = 0; binding < 11; ++binding)
            shape.sets[0].meta[binding].array_size = 1;
        for (unsigned stage = 0; stage < 3; ++stage) {
            const auto& module = modules[stage];
            if (module.size() < 5 || module[0] != 0x07230203u)
                throw std::invalid_argument("197900 stage module missing");
            std::vector<uint8_t> bytes(module.size() * 4);
            std::memcpy(bytes.data(), module.data(), bytes.size());
            if (reo_gpu_catalog::sha256(bytes) != pins[stage])
                throw std::invalid_argument("197900 stage source pin differs");
            auto* program = device_.request_program(module.data(), module.size() * 4, &shape);
            if (!program || !program->get_pipeline_layout())
                throw std::runtime_error("197900 exact stage program unavailable");
            const auto& actual = program->get_pipeline_layout()->get_resource_layout();
            if (actual.descriptor_set_mask != 1 || actual.bindless_descriptor_set_mask ||
                actual.sets[0].storage_buffer_mask != 2047 || actual.push_constant_range.offset ||
                actual.push_constant_range.size != sizeof(Parameters) ||
                actual.push_constant_range.stageFlags != VK_SHADER_STAGE_COMPUTE_BIT)
                throw std::invalid_argument("197900 stage physical ABI differs");
            for (unsigned binding = 0; binding < 11; ++binding)
                if (actual.sets[0].meta[binding].array_size != 1 ||
                    actual.stages_for_bindings[0][binding] != VK_SHADER_STAGE_COMPUTE_BIT)
                    throw std::invalid_argument("197900 exact stage binding differs");
            programs_[stage] = program;
        }
        const std::array<uint32_t, ControlWords> zero{};
        zeroControl_ = buffer(ControlBytes, zero.data());
        zeroReceipt_ = buffer(ReceiptBytes, zero.data());
    }
    void validateCall(const CallHandle& call) const {
        if (!call || call->issuer() != actualService_ || call->entry() != 0x197900u || call->a0() ||
            call->a1() || call->a2() || call->task() < 1 ||
            (call->returnPc() >= 0x197900u && call->returnPc() < 0x197bb0u))
            throw std::invalid_argument(
                "197900 lacks genuine original initial call/return identity");
        const auto& s = call->stamp();
        const auto& b = banks_->stamp();
        if (!s.ordinal || s.session != b.session || s.epoch != b.epoch ||
            s.bankGeneration != b.bankGeneration)
            throw std::invalid_argument("197900 source banks stale/foreign");
    }
    OutputHandle dispatch(Vulkan::CommandBuffer& cmd, const CallHandle& call, uint32_t stage,
                          const Vulkan::Buffer& prior, const Vulkan::Buffer& completed,
                          const Vulkan::Buffer& journal, Vulkan::BufferHandle scratch) {
        if (stage < 1 || stage > 3 || pending_.size() >= 4096)
            throw std::invalid_argument("197900 source stage invalid/unbounded");
        if (!scratch)
            scratch = buffer(ScratchBytes);
        auto result = std::shared_ptr<const Output>(
            new Output(this, banks_, call, buffer(ReceiptBytes), buffer(ControlBytes),
                       buffer(CompositionEffectsBytes), std::move(scratch), stage));
        pending_.push_back(result);
        for (unsigned b = 0; b < 4; ++b)
            barrier(cmd, banks_->bank(Bank(b)));
        barrier(cmd, *result->receipt_);
        barrier(cmd, prior);
        barrier(cmd, *result->control_);
        barrier(cmd, *result->effects_);
        barrier(cmd, *result->scratch_);
        barrier(cmd, completed);
        barrier(cmd, journal);
        auto p = parameters(*call);
        p.reserved = uint32_t(call->task());
        cmd.set_program(programs_[stage - 1]);
        for (unsigned b = 0; b < 4; ++b)
            cmd.set_storage_buffer(0, b, banks_->bank(Bank(b)));
        cmd.set_storage_buffer(0, 4, *result->receipt_);
        cmd.set_storage_buffer(0, 5, prior);
        cmd.set_storage_buffer(0, 6, *result->control_);
        cmd.set_storage_buffer(0, 7, *result->effects_);
        cmd.set_storage_buffer(0, 8, *result->scratch_);
        cmd.set_storage_buffer(0, 9, completed);
        cmd.set_storage_buffer(0, 10, journal);
        cmd.push_constants(&p, 0, sizeof(p));
        cmd.dispatch(1, 1, 1);
        for (unsigned b = 0; b < 4; ++b)
            barrier(cmd, banks_->bank(Bank(b)));
        barrier(cmd, *result->receipt_);
        barrier(cmd, *result->control_);
        barrier(cmd, *result->effects_);
        barrier(cmd, *result->scratch_);
        return result;
    }
    OutputHandle record(Vulkan::CommandBuffer& cmd, const CallHandle& call) {
        validateCall(call);
        if (activeCall_ || call->stamp().ordinal <= lastOrdinal_)
            throw std::invalid_argument(
                "197900 overtook an active source call or repeated chronology");
        lastOrdinal_ = call->stamp().ordinal;
        activeCall_ = call;
        return dispatch(cmd, call, 1, *zeroControl_, *zeroReceipt_, *zeroReceipt_, {});
    }
    OutputHandle resume(Vulkan::CommandBuffer& cmd, const ControlReturnHandle& token) {
        if (!token || token->issuer_ != actualService_ || !owns(token->prior_) ||
            activeCall_ != token->prior_->call_ || token->task_ != activeCall_->task() ||
            !token->prior_->realTimeline_ ||
            token->actualFenceOrdinal_ < token->prior_->realTimeline_ ||
            !token->actualGpuCalleeReceipt_ || !token->actualCalleeLifetime_ ||
            token->actualGpuCalleeReceipt_->get_create_info().domain !=
                Vulkan::BufferDomain::Device ||
            token->actualGpuCalleeReceipt_->get_create_info().size != ReceiptBytes ||
            (token->actualGpuCalleeReceipt_->get_create_info().usage &
             VK_BUFFER_USAGE_STORAGE_BUFFER_BIT) == 0)
            throw std::invalid_argument(
                "197900 continuation lacks actual completed GPU source output/fence");
        const auto stage = token->completedStage_;
        if (stage != token->prior_->stage_ ||
            !((stage == 1u && token->callee_ == 0x18ddd0u &&
               (token->continuation_ == 0x197a94u || token->continuation_ == 0x197aa8u)) ||
              (stage == 2u && token->callee_ == 0x18cfb0u && token->continuation_ == 0x197b98u)))
            throw std::invalid_argument("197900 callee/continuation source identity differs");
        if (std::find(resumed_.begin(), resumed_.end(), token->prior_) != resumed_.end() ||
            resumed_.size() >= 4096)
            throw std::invalid_argument("197900 actual continuation consumed twice/unbounded");
        if (stage == 2u && (!token->actualGpuCalleeJournal_ ||
                            token->actualGpuCalleeJournal_->get_create_info().domain !=
                                Vulkan::BufferDomain::Device ||
                            token->actualGpuCalleeJournal_->get_create_info().size < 96u ||
                            (token->actualGpuCalleeJournal_->get_create_info().usage &
                             VK_BUFFER_USAGE_STORAGE_BUFFER_BIT) == 0))
            throw std::invalid_argument(
                "197900 queue continuation lacks exact immutable actual source journal");
        validateCall(activeCall_);
        resumed_.push_back(token->prior_);
        return dispatch(
            cmd, activeCall_, stage + 1, *token->prior_->control_, *token->actualGpuCalleeReceipt_,
            token->actualGpuCalleeJournal_ ? *token->actualGpuCalleeJournal_ : *zeroReceipt_,
            token->prior_->scratch_);
    }
    bool owns(const OutputHandle& output) const noexcept {
        return output && output->issuer_ == this && output->banks_ == banks_;
    }
    void seal(uint64_t actualTimeline) {
        if (!actualTimeline || actualTimeline <= lastSubmission_)
            throw std::invalid_argument("197900 seal lacks new actual timeline");
        lastSubmission_ = actualTimeline;
        if (!pending_.empty()) {
            for (const auto& p : pending_)
                p->realTimeline_ = actualTimeline;
            inFlight_.push_back({actualTimeline, std::move(pending_)});
            pending_.clear();
        }
    }
    void retire(uint64_t actualTimeline) {
        if (actualTimeline > lastSubmission_)
            throw std::invalid_argument("197900 retirement exceeds actual sealed prefix");
        while (!inFlight_.empty() && inFlight_.front().timeline <= actualTimeline) {
            for (const auto& p : inFlight_.front().outputs)
                if (p->stage_ == 3u && activeCall_ == p->call_)
                    activeCall_.reset();
            inFlight_.pop_front();
        }
    }

  public:
    StatePacket197900(const StatePacket197900&) = delete;
    ~StatePacket197900() {
        if (!pending_.empty() || !inFlight_.empty())
            device_.wait_idle();
    }
    static constexpr bool ActualDeviceParityProved = false;
    static constexpr bool NativeAllocatorQueueSourceIssuanceImplemented = false;
    static constexpr bool NaturalSourceClosureImplemented = false;
};
} // namespace reo_gpu_upstream
