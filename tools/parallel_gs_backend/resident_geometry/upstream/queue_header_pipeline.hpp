#pragma once
#include "queue_control_adapter.hpp"
namespace reo_gpu_upstream {
class ProtectedCounterImport final {
    friend class reo_gpu_palette_parent::Producer;
    friend class reo_parent_install::Service;
    friend class QueueHeaderMetadataPipeline;
    const void* actualService_;
    BanksHandle banks_;
    ProtectedQueueSnapshotHandle snapshot_;
    Vulkan::BufferHandle exactScalarCertificate_;
    // An actual FIFO owner uploads the protected CPU snapshot's exact logical
    // pointer/revision certificate, then mirrors the same scalar RAM field.
    ProtectedCounterImport(const void* service, BanksHandle banks,
                           ProtectedQueueSnapshotHandle snapshot, Vulkan::BufferHandle certificate)
        : actualService_(service), banks_(std::move(banks)), snapshot_(std::move(snapshot)),
          exactScalarCertificate_(std::move(certificate)) {}

  public:
    ProtectedCounterImport(const ProtectedCounterImport&) = delete;
};
using ProtectedCounterImportHandle = std::shared_ptr<const ProtectedCounterImport>;

class QueueHeaderMetadataPipeline final {
    friend class reo_gpu_palette_parent::Producer;
    friend class reo_parent_install::Service;

  public:
    static constexpr uint32_t HeaderWords = 40, HeaderBytes = 160, CounterBytes = 80;
    class Output final {
        friend class QueueHeaderMetadataPipeline;
        const QueueHeaderMetadataPipeline* owner_;
        QueueControlCallHandle call_;
        ProtectedCounterImportHandle counter_;
        Vulkan::BufferHandle metadata_;
        uint64_t realTimeline_ = 0;
        Output(const QueueHeaderMetadataPipeline* owner, QueueControlCallHandle call,
               ProtectedCounterImportHandle counter, Vulkan::BufferHandle metadata)
            : owner_(owner), call_(std::move(call)), counter_(std::move(counter)),
              metadata_(std::move(metadata)) {}

      public:
        const Vulkan::Buffer& metadata() const {
            return *metadata_;
        }
    };
    using OutputHandle = std::shared_ptr<const Output>;

  private:
    Vulkan::Device& device_;
    const void* actualProducer_;
    const void* actualService_;
    BanksHandle banks_;
    Vulkan::Program* program_ = nullptr;
    bool statePacket197900_ = false;
    uint64_t lastOrdinal_ = 0, lastSubmission_ = 0;
    std::vector<std::shared_ptr<Output>> pending_;
    std::vector<OutputHandle> certified_;
    struct Submission {
        uint64_t timeline;
        std::vector<std::shared_ptr<Output>> outputs;
    };
    std::deque<Submission> inFlight_;
    static bool same(const Stamp& a, const Stamp& b) {
        return a.session == b.session && a.epoch == b.epoch &&
               a.bankGeneration == b.bankGeneration && a.ordinal == b.ordinal;
    }
    static void barrier(Vulkan::CommandBuffer& cmd, const Vulkan::Buffer& b) {
        cmd.buffer_barrier(b, VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT,
                           VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                           VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT,
                           VK_ACCESS_2_SHADER_STORAGE_READ_BIT |
                               VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
    }
    QueueHeaderMetadataPipeline(Vulkan::Device& device, const void* producer, const void* service,
                                BanksHandle banks, const std::vector<uint32_t>& module)
        : device_(device), actualProducer_(producer), actualService_(service),
          banks_(std::move(banks)) {
        if (!producer || !service || !banks_ || banks_->device() != &device ||
            banks_->issuer() != producer)
            throw std::invalid_argument(
                "Queue header query lacks actual persistent Producer/Service");
        if (module.size() < 5 || module[0] != 0x07230203u)
            throw std::invalid_argument("Queue header source module absent");
        std::vector<uint8_t> bytes(module.size() * 4);
        std::memcpy(bytes.data(), module.data(), bytes.size());
        const auto moduleIdentity = reo_gpu_catalog::sha256(bytes);
        statePacket197900_ =
            moduleIdentity == "3b4ef85f0b4147a9a049b5e3cd6d577886fd8e37720cacbe09dff011428b0ae5";
        if (!statePacket197900_ &&
            moduleIdentity != "656bf97ab9d9f372bf082f7e579e00936133fc8bbe87111ba6b4b7725137009f")
            throw std::invalid_argument("Queue header exact source module pin differs");
        Vulkan::ResourceLayout shape{};
        shape.sets[0].storage_buffer_mask = 127;
        shape.push_constant_size = sizeof(Parameters);
        for (unsigned b = 0; b < 7; ++b)
            shape.sets[0].meta[b].array_size = 1;
        program_ = device.request_program(module.data(), module.size() * 4, &shape);
        if (!program_ || !program_->get_pipeline_layout())
            throw std::runtime_error("Queue header source module creation failed");
        const auto& layout = program_->get_pipeline_layout()->get_resource_layout();
        if (layout.descriptor_set_mask != 1 || layout.bindless_descriptor_set_mask ||
            layout.sets[0].storage_buffer_mask != 127 || layout.push_constant_range.offset ||
            layout.push_constant_range.size != sizeof(Parameters) ||
            layout.push_constant_range.stageFlags != VK_SHADER_STAGE_COMPUTE_BIT)
            throw std::invalid_argument("Queue header shared-bank shader ABI differs");
        for (unsigned b = 0; b < 7; ++b)
            if (layout.sets[0].meta[b].array_size != 1 ||
                layout.stages_for_bindings[0][b] != VK_SHADER_STAGE_COMPUTE_BIT)
                throw std::invalid_argument("Queue header shader binding differs");
    }
    void validateRecord(const QueueControlCallHandle& call,
                        const ProtectedCounterImportHandle& counter) const {
        if (!call || !counter || call->issuer_ != actualService_ || call->banks_ != banks_ ||
            !call->originalCall_ || call->originalCall_->issuer() != actualService_ ||
            !same(call->stamp_, call->originalCall_->stamp()) ||
            counter->actualService_ != actualService_ || counter->banks_ != banks_ ||
            !counter->snapshot_ || counter->snapshot_->issuer_ != actualService_ ||
            counter->snapshot_->actualTask_ != call->actualTask_ ||
            !same(call->stamp_, counter->snapshot_->stamp_) || !call->immutableOriginalControl_ ||
            !counter->exactScalarCertificate_ || !call->exactControlFence_ ||
            !counter->snapshot_->protectedCpuRevision_ || call->actualTask_ < 1)
            throw std::invalid_argument("Queue header query source/counter identity differs");
        if (statePacket197900_ !=
            (call->originalJal_ == 0x197b90u && call->continuation_ == 0x197b98u &&
             call->originalCall_->entry() == 0x197900u))
            throw std::invalid_argument("Queue header exact loaded source profile differs");
        const auto& s = call->stamp_;
        const auto& b = banks_->stamp();
        if (!s.ordinal || s.ordinal <= lastOrdinal_ || s.session != b.session ||
            s.epoch != b.epoch || s.bankGeneration != b.bankGeneration || pending_.size() >= 4096)
            throw std::invalid_argument("Queue header query chronology stale/repeated");
        auto exactShape = [](const Vulkan::Buffer& buffer, uint32_t bytes) {
            const auto& ci = buffer.get_create_info();
            return ci.size == bytes && ci.domain == Vulkan::BufferDomain::Device &&
                   (ci.usage &
                    (VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT)) ==
                       (VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT);
        };
        if (!exactShape(*call->immutableOriginalControl_, Viewport::ControlBytes) ||
            !exactShape(*counter->exactScalarCertificate_, CounterBytes))
            throw std::invalid_argument("Queue header control buffer shape differs");
    }
    OutputHandle record(Vulkan::CommandBuffer& cmd, const QueueControlCallHandle& call,
                        const ProtectedCounterImportHandle& counter) {
        validateRecord(call, counter);
        const auto& s = call->stamp_;
        Vulkan::BufferCreateInfo ci{};
        ci.domain = Vulkan::BufferDomain::Device;
        ci.size = HeaderBytes;
        ci.usage = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT |
                   VK_BUFFER_USAGE_TRANSFER_DST_BIT;
        auto metadata = device_.create_buffer(ci);
        if (!metadata)
            throw std::runtime_error("Queue header immutable metadata allocation failed");
        auto output = std::shared_ptr<Output>(new Output(this, call, counter, std::move(metadata)));
        pending_.push_back(output);
        lastOrdinal_ = s.ordinal;
        for (unsigned k = 0; k < 4; ++k)
            barrier(cmd, banks_->bank(Bank(k)));
        barrier(cmd, *call->immutableOriginalControl_);
        barrier(cmd, *counter->exactScalarCertificate_);
        barrier(cmd, *output->metadata_);
        const auto p = parameters(*call->originalCall_);
        cmd.set_program(program_);
        for (unsigned k = 0; k < 4; ++k)
            cmd.set_storage_buffer(0, k, banks_->bank(Bank(k)));
        cmd.set_storage_buffer(0, 4, *call->immutableOriginalControl_);
        cmd.set_storage_buffer(0, 5, *output->metadata_);
        cmd.set_storage_buffer(0, 6, *counter->exactScalarCertificate_);
        cmd.push_constants(&p, 0, sizeof(p));
        cmd.dispatch(1, 1, 1);
        barrier(cmd, *output->metadata_);
        return output;
    }
    void seal(uint64_t realTimeline) {
        if (!realTimeline || realTimeline <= lastSubmission_)
            throw std::invalid_argument("Queue metadata seal lacks actual newer timeline");
        lastSubmission_ = realTimeline;
        if (!pending_.empty()) {
            for (const auto& output : pending_)
                output->realTimeline_ = realTimeline;
            inFlight_.push_back({realTimeline, std::move(pending_)});
            pending_.clear();
        }
    }
    QueueHeaderLeaseHandle certify(const OutputHandle& output, uint64_t actuallyCompletedTimeline,
                                   const std::array<uint32_t, HeaderWords>& gpuWords) {
        if (!output || output->owner_ != this || !output->realTimeline_ ||
            output->realTimeline_ > actuallyCompletedTimeline ||
            actuallyCompletedTimeline > lastSubmission_ ||
            std::find(certified_.begin(), certified_.end(), output) != certified_.end() ||
            certified_.size() >= 4096)
            throw std::invalid_argument("Queue header metadata is uncompleted/foreign/reused");
        const auto& call = *output->call_;
        const auto& snapshot = *output->counter_->snapshot_;
        const auto& s = call.stamp_;
        const std::array<uint32_t, 8> stamp{
            uint32_t(s.session),     uint32_t(s.session >> 32),  uint32_t(s.epoch),
            uint32_t(s.epoch >> 32), uint32_t(s.bankGeneration), uint32_t(s.bankGeneration >> 32),
            uint32_t(s.ordinal),     uint32_t(s.ordinal >> 32)};
        if (gpuWords[0] || gpuWords[1] != 0x51484c31u || gpuWords[2] != 1u ||
            (gpuWords[3] != 0u && gpuWords[3] != 5u) ||
            !std::equal(stamp.begin(), stamp.end(), gpuWords.begin() + 4) ||
            gpuWords[12] != call.originalJal_ || gpuWords[13] != call.continuation_ ||
            gpuWords[14] != call.originalCall_->entry() ||
            gpuWords[15] != call.originalCall_->returnPc() || gpuWords[17] != 0x18cfb0u ||
            (uint64_t(gpuWords[18]) | (uint64_t(gpuWords[19]) << 32)) !=
                snapshot.protectedCpuRevision_)
            throw std::invalid_argument("Queue actual GPU header receipt differs");
        std::optional<uint32_t> previous;
        for (const auto& word : snapshot.words_)
            if (word.sourcePc == 0x18d068u && word.address == 0x29f728u &&
                word.field == QueueField::ProtectedCpuQueue) {
                if (previous)
                    throw std::invalid_argument(
                        "Queue protected previous-pointer snapshot ambiguous");
                previous = word.value;
            }
        if (!previous || *previous != gpuWords[16] || gpuWords[3] != (*previous ? 5u : 0u))
            throw std::invalid_argument(
                "Queue header metadata did not derive from exact protected prior pointer");
        const std::array<uint32_t, 5> sites{0x18d0a8u, 0x18d0e0u, 0x18d0d0u, 0x18d0dcu, 0x18d108u};
        std::vector<QueueWord> words;
        for (unsigned k = 0; k < gpuWords[3]; ++k) {
            const unsigned i = 20 + k * 4;
            const uint32_t address = *previous + (k == 3 ? 4u : 0u);
            if (gpuWords[i] != sites[k] || gpuWords[i + 1] != address || gpuWords[i + 3] != 3u)
                throw std::invalid_argument("Queue exact source header field receipt differs");
            words.push_back(
                {sites[k], address, gpuWords[i + 2], QueueField::OwnerDmaHeaderControl});
        }
        auto lease = std::shared_ptr<const QueueHeaderLease>(new QueueHeaderLease(
            actualProducer_, banks_, s, output->realTimeline_, snapshot.protectedCpuRevision_,
            output->metadata_, std::move(words)));
        certified_.push_back(output);
        return lease;
    }
    void releaseCertified(const OutputHandle& output, const QueueHeaderLeaseHandle& lease,
                          uint64_t completed) {
        if (!output || !lease || output->owner_ != this ||
            lease->actualCertifiedMetadata_ != output->metadata_ || !output->realTimeline_ ||
            output->realTimeline_ > completed || completed > lastSubmission_)
            throw std::invalid_argument("Queue header release lacks exact retired source lifetime");
        auto found = std::find(certified_.begin(), certified_.end(), output);
        if (found == certified_.end())
            throw std::invalid_argument("Queue header release repeated/foreign");
        certified_.erase(found);
    }
    void retire(uint64_t actuallyCompletedTimeline) {
        if (actuallyCompletedTimeline > lastSubmission_)
            throw std::invalid_argument("Queue header retirement exceeds actual sealed prefix");
        while (!inFlight_.empty() && inFlight_.front().timeline <= actuallyCompletedTimeline)
            inFlight_.pop_front();
    }

  public:
    QueueHeaderMetadataPipeline(const QueueHeaderMetadataPipeline&) = delete;
    ~QueueHeaderMetadataPipeline() {
        if (!pending_.empty() || !inFlight_.empty())
            device_.wait_idle();
    }
    static constexpr bool ActualFifoReadbackAndCounterImportImplemented = false;
};
} // namespace reo_gpu_upstream
