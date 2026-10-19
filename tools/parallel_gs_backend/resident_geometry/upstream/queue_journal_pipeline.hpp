#pragma once
#include "queue_header_pipeline.hpp"
namespace reo_gpu_upstream {
// True owner-side application only. It updates the GPU bank's exact context,
// opaque stack and DMA links. The live CPU queue counter commit is a distinct
// protected Service step and is not implemented or implied by this class.
class QueueJournalPipeline final {
    friend class reo_gpu_palette_parent::Producer;
    friend class reo_parent_install::Service;

  public:
    class Output final {
        friend class QueueJournalPipeline;
        friend class reo_parent_install::Service;
        const QueueJournalPipeline* owner_;
        QueueControlAdapter::PlanHandle plan_;
        Vulkan::BufferHandle sourceJournal_, receipt_;
        uint64_t realTimeline_ = 0;
        Output(const QueueJournalPipeline* owner, QueueControlAdapter::PlanHandle plan,
               Vulkan::BufferHandle journal, Vulkan::BufferHandle receipt)
            : owner_(owner), plan_(std::move(plan)), sourceJournal_(std::move(journal)),
              receipt_(std::move(receipt)) {}

      public:
        const Vulkan::Buffer& receipt() const {
            return *receipt_;
        }
    };
    using OutputHandle = std::shared_ptr<const Output>;

  private:
    Vulkan::Device& device_;
    const void* actualService_;
    BanksHandle banks_;
    Vulkan::Program* program_ = nullptr;
    bool statePacket197900_ = false;
    uint64_t lastOrdinal_ = 0, lastSubmission_ = 0;
    std::vector<std::shared_ptr<Output>> pending_;
    std::vector<QueueControlAdapter::PlanHandle> consumed_;
    struct Submission {
        uint64_t timeline;
        std::vector<std::shared_ptr<Output>> outputs;
    };
    std::deque<Submission> inFlight_;
    static void barrier(Vulkan::CommandBuffer& cmd, const Vulkan::Buffer& b) {
        cmd.buffer_barrier(b, VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT,
                           VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                           VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT,
                           VK_ACCESS_2_SHADER_STORAGE_READ_BIT |
                               VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
    }
    Vulkan::BufferHandle make(uint32_t bytes, const void* initial = nullptr) {
        Vulkan::BufferCreateInfo ci{};
        ci.domain = Vulkan::BufferDomain::Device;
        ci.size = bytes;
        ci.usage = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT |
                   VK_BUFFER_USAGE_TRANSFER_DST_BIT;
        auto buffer = device_.create_buffer(ci, initial);
        if (!buffer)
            throw std::runtime_error("Queue ordered application buffer allocation failed");
        return buffer;
    }
    QueueJournalPipeline(Vulkan::Device& device, const void* actualService, BanksHandle banks,
                         const std::vector<uint32_t>& module)
        : device_(device), actualService_(actualService), banks_(std::move(banks)) {
        if (!actualService || !banks_ || banks_->device() != &device || !banks_->issuer())
            throw std::invalid_argument("Queue application lacks actual persistent owner banks");
        if (module.size() < 5 || module[0] != 0x07230203u)
            throw std::invalid_argument("Queue application module absent");
        std::vector<uint8_t> bytes(module.size() * 4);
        std::memcpy(bytes.data(), module.data(), bytes.size());
        const auto moduleIdentity = reo_gpu_catalog::sha256(bytes);
        statePacket197900_ =
            moduleIdentity == "b4c3c39ac8d7834c256b06b8c541f35ccb2f0da80f4b9d9d77134a4528e376f3";
        if (!statePacket197900_ &&
            moduleIdentity != "dc538490b598748af2e4e14d5b0b73663689fece9ac9f94f24c8ffee8474d026")
            throw std::invalid_argument("Queue application exact source module pin differs");
        Vulkan::ResourceLayout shape{};
        shape.sets[0].storage_buffer_mask = 127;
        shape.push_constant_size = sizeof(Parameters);
        for (unsigned b = 0; b < 7; ++b)
            shape.sets[0].meta[b].array_size = 1;
        program_ = device.request_program(module.data(), module.size() * 4, &shape);
        if (!program_ || !program_->get_pipeline_layout())
            throw std::runtime_error("Queue application module creation failed");
        const auto& layout = program_->get_pipeline_layout()->get_resource_layout();
        if (layout.descriptor_set_mask != 1 || layout.bindless_descriptor_set_mask ||
            layout.sets[0].storage_buffer_mask != 127 || layout.push_constant_range.offset ||
            layout.push_constant_range.size != sizeof(Parameters) ||
            layout.push_constant_range.stageFlags != VK_SHADER_STAGE_COMPUTE_BIT)
            throw std::invalid_argument("Queue application shared-bank shader ABI differs");
        for (unsigned b = 0; b < 7; ++b)
            if (layout.sets[0].meta[b].array_size != 1 ||
                layout.stages_for_bindings[0][b] != VK_SHADER_STAGE_COMPUTE_BIT)
                throw std::invalid_argument("Queue application shader binding differs");
    }
    void validateRecord(const QueueControlAdapter::PlanHandle& plan) const {
        if (!plan || plan->issuer_ != actualService_ || !plan->call_ || !plan->headers_ ||
            !plan->counters_ || plan->call_->issuer_ != actualService_ ||
            plan->call_->banks_ != banks_ || plan->headers_->banks_ != banks_ ||
            plan->headers_->owner_ != banks_->issuer() ||
            plan->counters_->issuer_ != actualService_ || !plan->call_->originalCall_ ||
            plan->call_->originalCall_->issuer() != actualService_ ||
            !same(plan->call_->stamp_, plan->call_->originalCall_->stamp()) ||
            !same(plan->call_->stamp_, plan->headers_->stamp_) ||
            !same(plan->call_->stamp_, plan->counters_->stamp_) ||
            plan->headers_->protectedCpuRevision_ != plan->counters_->protectedCpuRevision_ ||
            !plan->headers_->exactFence_ || !plan->call_->exactControlFence_)
            throw std::invalid_argument("Queue application actual source plan differs");
        if (statePacket197900_ !=
            (plan->call_->originalJal_ == 0x197b90u && plan->call_->continuation_ == 0x197b98u &&
             plan->call_->originalCall_->entry() == 0x197900u))
            throw std::invalid_argument("Queue journal exact loaded source profile differs");
        const auto& s = plan->call_->stamp_;
        const auto& b = banks_->stamp();
        if (!s.ordinal || s.ordinal <= lastOrdinal_ || s.session != b.session ||
            s.epoch != b.epoch || s.bankGeneration != b.bankGeneration || pending_.size() >= 4096 ||
            consumed_.size() >= 4096 ||
            std::find(consumed_.begin(), consumed_.end(), plan) != consumed_.end() ||
            plan->ordered_.empty() || plan->ordered_.size() > 4096)
            throw std::invalid_argument("Queue application source plan stale/reused/unbounded");
    }
    OutputHandle record(Vulkan::CommandBuffer& cmd, const QueueControlAdapter::PlanHandle& plan) {
        validateRecord(plan);
        const auto& s = plan->call_->stamp_;
        std::vector<uint32_t> words{0u,
                                    0x514a5031u,
                                    2u,
                                    uint32_t(plan->ordered_.size()),
                                    uint32_t(s.session),
                                    uint32_t(s.session >> 32),
                                    uint32_t(s.epoch),
                                    uint32_t(s.epoch >> 32),
                                    uint32_t(s.bankGeneration),
                                    uint32_t(s.bankGeneration >> 32),
                                    uint32_t(s.ordinal),
                                    uint32_t(s.ordinal >> 32),
                                    plan->call_->originalJal_,
                                    plan->call_->continuation_,
                                    uint32_t(plan->counters_->protectedCpuRevision_),
                                    uint32_t(plan->counters_->protectedCpuRevision_ >> 32),
                                    uint32_t(plan->call_->actualTask_),
                                    plan->instructions_,
                                    uint32_t(plan->returnValue_),
                                    uint32_t(plan->returnValue_ >> 32),
                                    uint32_t(plan->call_->resolver_->kind_),
                                    0x51524231u,
                                    24u,
                                    0u};
        for (const auto& op : plan->ordered_) {
            words.push_back(uint32_t(op.op));
            words.push_back(op.sourcePc);
            words.push_back(op.address);
            words.push_back(op.word0);
            words.push_back(op.word1);
        }
        auto output = std::shared_ptr<Output>(new Output(
            this, plan, make(uint32_t(words.size() * 4), words.data()), make(ReceiptBytes)));
        pending_.push_back(output);
        consumed_.push_back(plan);
        lastOrdinal_ = s.ordinal;
        for (unsigned k = 0; k < 4; ++k)
            barrier(cmd, banks_->bank(Bank(k)));
        barrier(cmd, *output->sourceJournal_);
        barrier(cmd, *plan->call_->immutableOriginalControl_);
        barrier(cmd, *output->receipt_);
        auto p = parameters(*plan->call_->originalCall_);
        p.reserved = uint32_t(plan->ordered_.size());
        cmd.set_program(program_);
        for (unsigned k = 0; k < 4; ++k)
            cmd.set_storage_buffer(0, k, banks_->bank(Bank(k)));
        cmd.set_storage_buffer(0, 4, *output->sourceJournal_);
        cmd.set_storage_buffer(0, 5, *plan->call_->immutableOriginalControl_);
        cmd.set_storage_buffer(0, 6, *output->receipt_);
        cmd.push_constants(&p, 0, sizeof(p));
        cmd.dispatch(1, 1, 1);
        for (unsigned k = 0; k < 4; ++k)
            barrier(cmd, banks_->bank(Bank(k)));
        barrier(cmd, *output->receipt_);
        return output;
    }
    void seal(uint64_t actualTimeline) {
        if (!actualTimeline || actualTimeline <= lastSubmission_)
            throw std::invalid_argument("Queue application seal requires actual newer timeline");
        lastSubmission_ = actualTimeline;
        if (!pending_.empty()) {
            for (const auto& output : pending_)
                output->realTimeline_ = actualTimeline;
            inFlight_.push_back({actualTimeline, std::move(pending_)});
            pending_.clear();
        }
    }
    void releaseConsumed(const OutputHandle& output, uint64_t actuallyCompletedTimeline) {
        if (!output || output->owner_ != this || !output->realTimeline_ ||
            output->realTimeline_ > actuallyCompletedTimeline ||
            actuallyCompletedTimeline > lastSubmission_)
            throw std::invalid_argument(
                "Queue application release lacks exact genuinely retired event");
        auto found = std::find(consumed_.begin(), consumed_.end(), output->plan_);
        if (found == consumed_.end())
            throw std::invalid_argument("Queue application release repeated/foreign");
        consumed_.erase(found);
    }
    void retire(uint64_t actuallyCompletedTimeline) {
        if (actuallyCompletedTimeline > lastSubmission_)
            throw std::invalid_argument(
                "Queue application retirement exceeds actual sealed prefix");
        while (!inFlight_.empty() && inFlight_.front().timeline <= actuallyCompletedTimeline)
            inFlight_.pop_front();
    }

  public:
    QueueJournalPipeline(const QueueJournalPipeline&) = delete;
    ~QueueJournalPipeline() {
        if (!pending_.empty() || !inFlight_.empty())
            device_.wait_idle();
    }
    static constexpr bool ActualProtectedCpuCounterCommitImplemented = false;
    static constexpr bool ActualFifoLifecycleImplemented = false;
};
} // namespace reo_gpu_upstream
