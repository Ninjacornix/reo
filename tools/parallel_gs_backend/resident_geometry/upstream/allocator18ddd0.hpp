#pragma once
#include "upstream_bank_abi.hpp"
#include "viewport_pipeline.hpp"
#include "state_packet197900.hpp"
#include "command_buffer.hpp"
#include "tools/parallel_gs_backend/resident_geometry/enrollment/sha256.hpp"
#include <deque>
namespace reo_parent_natural {
class NativeTarget;
class ProtectedScalarCapture;
using ProtectedScalarCaptureHandle = std::shared_ptr<const ProtectedScalarCapture>;
} // namespace reo_parent_natural
namespace reo_gpu_upstream {
// Issued by actual Service after protected CPU capture. Its transaction is a
// capture/lifetime ID, not a guessed source-write revision. The separate real
// NativeTarget protected-scalar frontier must remain retained until commit.
class AllocatorHeapCapture final {
    friend class reo_parent_install::Service;
    friend class Allocator18DDD0;
    friend class reo_parent_natural::NativeTarget;
    friend class reo_gpu_palette_parent::Producer;
    const void* issuer_;
    BanksHandle banks_;
    CallHandle call_;
    Viewport::OutputHandle originalStage_;
    StatePacket197900::OutputHandle stateStage_;
    const void* actualRuntime_;
    R5900Context* actualEeContext_;
    int32_t task_;
    uint64_t transaction_;
    uint32_t limit_, cursor_, continuation_, sourceWord_;
    reo_parent_natural::ProtectedScalarCaptureHandle protectedScalarFrontier_;
    AllocatorHeapCapture(const void* issuer, BanksHandle banks, CallHandle call,
                         Viewport::OutputHandle stage, const void* runtime, R5900Context* ctx,
                         int32_t task, uint64_t transaction, uint32_t limit, uint32_t cursor,
                         uint32_t continuation, uint32_t word,
                         reo_parent_natural::ProtectedScalarCaptureHandle frontier)
        : issuer_(issuer), banks_(std::move(banks)), call_(std::move(call)),
          originalStage_(std::move(stage)), actualRuntime_(runtime), actualEeContext_(ctx),
          task_(task), transaction_(transaction), limit_(limit), cursor_(cursor),
          continuation_(continuation), sourceWord_(word),
          protectedScalarFrontier_(std::move(frontier)) {}
    AllocatorHeapCapture(const void* issuer, BanksHandle banks, CallHandle call,
                         StatePacket197900::OutputHandle stage, const void* runtime,
                         R5900Context* ctx, int32_t task, uint64_t transaction, uint32_t limit,
                         uint32_t cursor, uint32_t continuation, uint32_t word,
                         reo_parent_natural::ProtectedScalarCaptureHandle frontier)
        : issuer_(issuer), banks_(std::move(banks)), call_(std::move(call)),
          stateStage_(std::move(stage)), actualRuntime_(runtime), actualEeContext_(ctx),
          task_(task), transaction_(transaction), limit_(limit), cursor_(cursor),
          continuation_(continuation), sourceWord_(word),
          protectedScalarFrontier_(std::move(frontier)) {}
    const Vulkan::Buffer& sourceControl() const {
        return stateStage_ ? stateStage_->control() : originalStage_->control();
    }

  public:
    AllocatorHeapCapture(const AllocatorHeapCapture&) = delete;
};
using AllocatorHeapCaptureHandle = std::shared_ptr<const AllocatorHeapCapture>;

class Allocator18DDD0 final {
    friend class reo_gpu_palette_parent::Producer;
    friend class reo_parent_install::Service;

  public:
    class Output final {
        friend class Allocator18DDD0;
        friend class reo_parent_install::Service;
        friend class reo_parent_natural::NativeTarget;
        const Allocator18DDD0* issuer_;
        AllocatorHeapCaptureHandle capture_;
        Vulkan::BufferHandle certificate_, receipt_;
        uint64_t timeline_ = 0;
        Output(const Allocator18DDD0* issuer, AllocatorHeapCaptureHandle capture,
               Vulkan::BufferHandle certificate, Vulkan::BufferHandle receipt)
            : issuer_(issuer), capture_(std::move(capture)), certificate_(std::move(certificate)),
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
    uint64_t lastCapture_ = 0, lastSubmission_ = 0;
    std::vector<std::shared_ptr<Output>> pending_;
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
    Vulkan::BufferHandle make(uint32_t bytes, const void* data = nullptr) {
        Vulkan::BufferCreateInfo ci{};
        ci.domain = Vulkan::BufferDomain::Device;
        ci.size = bytes;
        ci.usage = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT |
                   VK_BUFFER_USAGE_TRANSFER_DST_BIT;
        auto buffer = device_.create_buffer(ci, data);
        if (!buffer)
            throw std::runtime_error("Allocator immutable control buffer allocation failed");
        return buffer;
    }
    Allocator18DDD0(Vulkan::Device& device, const void* service, BanksHandle banks,
                    const std::vector<uint32_t>& module)
        : device_(device), actualService_(service), banks_(std::move(banks)) {
        if (!service || !banks_ || banks_->device() != &device || !banks_->issuer())
            throw std::invalid_argument("Allocator lacks actual persistent Producer/Service banks");
        if (module.size() < 5 || module[0] != 0x07230203u)
            throw std::invalid_argument("Allocator source module missing");
        std::vector<uint8_t> bytes(module.size() * 4);
        std::memcpy(bytes.data(), module.data(), bytes.size());
        const auto moduleIdentity = reo_gpu_catalog::sha256(bytes);
        statePacket197900_ =
            moduleIdentity == "32a03c43312a9487df6a0178c0392e04e854d73c33510976fd1a415361a26810";
        if (!statePacket197900_ &&
            moduleIdentity != "f5c89921eedb56b3874fa0493a6424d5bf09a7807cfb04bfed972cdc7e1f7e6c")
            throw std::invalid_argument("Allocator exact source module pin differs");
        Vulkan::ResourceLayout shape{};
        shape.sets[0].storage_buffer_mask = 127;
        shape.push_constant_size = sizeof(Parameters);
        for (unsigned k = 0; k < 7; ++k)
            shape.sets[0].meta[k].array_size = 1;
        program_ = device.request_program(module.data(), module.size() * 4, &shape);
        if (!program_ || !program_->get_pipeline_layout())
            throw std::runtime_error("Allocator source program creation failed");
        const auto& layout = program_->get_pipeline_layout()->get_resource_layout();
        if (layout.descriptor_set_mask != 1 || layout.bindless_descriptor_set_mask ||
            layout.sets[0].storage_buffer_mask != 127 || layout.push_constant_range.offset ||
            layout.push_constant_range.size != sizeof(Parameters) ||
            layout.push_constant_range.stageFlags != VK_SHADER_STAGE_COMPUTE_BIT)
            throw std::invalid_argument("Allocator seven-buffer physical ABI differs");
        for (unsigned k = 0; k < 7; ++k)
            if (layout.sets[0].meta[k].array_size != 1 ||
                layout.stages_for_bindings[0][k] != VK_SHADER_STAGE_COMPUTE_BIT)
                throw std::invalid_argument("Allocator binding shape differs");
    }
    void validateCapture(const AllocatorHeapCaptureHandle& capture) const {
        if (!capture || capture->issuer_ != actualService_ || capture->banks_ != banks_ ||
            !capture->call_ || capture->call_->issuer() != actualService_ ||
            (statePacket197900_
                 ? (!capture->stateStage_ || capture->originalStage_ ||
                    capture->call_->entry() != 0x197900u || capture->stateStage_->stage() != 1u ||
                    &capture->stateStage_->call() != capture->call_.get())
                 : (!capture->originalStage_ || capture->stateStage_ ||
                    &capture->originalStage_->call() != capture->call_.get())) ||
            !capture->actualRuntime_ || !capture->actualEeContext_ || capture->task_ < 1 ||
            capture->task_ != capture->call_->task() || !capture->protectedScalarFrontier_ ||
            capture->sourceWord_ != 0xac24fdc0u ||
            (statePacket197900_
                 ? (capture->continuation_ != 0x197a94u && capture->continuation_ != 0x197aa8u)
                 : (capture->continuation_ != 0x197524u && capture->continuation_ != 0x197538u)) ||
            capture->cursor_ < 16u || capture->cursor_ > capture->limit_ ||
            capture->limit_ > RamBytes || capture->transaction_ <= lastCapture_ ||
            pending_.size() >= 4096)
            throw std::invalid_argument("Allocator source capture is stale/foreign/unprotected");
        const auto& s = capture->call_->stamp();
        const auto& b = banks_->stamp();
        if (!s.ordinal || s.session != b.session || s.epoch != b.epoch ||
            s.bankGeneration != b.bankGeneration)
            throw std::invalid_argument("Allocator source bank stamp differs");
    }
    OutputHandle record(Vulkan::CommandBuffer& cmd, const AllocatorHeapCaptureHandle& capture) {
        validateCapture(capture);
        const auto& s = capture->call_->stamp();
        const std::array<uint32_t, ReceiptWords> certificate{0u,
                                                             0x48415031u,
                                                             1u,
                                                             ReceiptBytes,
                                                             uint32_t(s.session),
                                                             uint32_t(s.session >> 32),
                                                             uint32_t(s.epoch),
                                                             uint32_t(s.epoch >> 32),
                                                             uint32_t(s.bankGeneration),
                                                             uint32_t(s.bankGeneration >> 32),
                                                             uint32_t(s.ordinal),
                                                             uint32_t(s.ordinal >> 32),
                                                             uint32_t(capture->transaction_),
                                                             uint32_t(capture->transaction_ >> 32),
                                                             capture->limit_,
                                                             capture->cursor_,
                                                             capture->continuation_,
                                                             uint32_t(capture->task_),
                                                             capture->sourceWord_,
                                                             0u};
        auto output = std::shared_ptr<Output>(
            new Output(this, capture, make(ReceiptBytes, certificate.data()), make(ReceiptBytes)));
        pending_.push_back(output);
        lastCapture_ = capture->transaction_;
        for (unsigned k = 0; k < 4; ++k)
            barrier(cmd, banks_->bank(Bank(k)));
        barrier(cmd, capture->sourceControl());
        barrier(cmd, *output->certificate_);
        barrier(cmd, *output->receipt_);
        const auto p = parameters(*capture->call_);
        cmd.set_program(program_);
        for (unsigned k = 0; k < 4; ++k)
            cmd.set_storage_buffer(0, k, banks_->bank(Bank(k)));
        cmd.set_storage_buffer(0, 4, capture->sourceControl());
        cmd.set_storage_buffer(0, 5, *output->certificate_);
        cmd.set_storage_buffer(0, 6, *output->receipt_);
        cmd.push_constants(&p, 0, sizeof(p));
        cmd.dispatch(1, 1, 1);
        for (unsigned k = 0; k < 4; ++k)
            barrier(cmd, banks_->bank(Bank(k)));
        barrier(cmd, *output->receipt_);
        return output;
    }
    void seal(uint64_t realTimeline) {
        if (!realTimeline || realTimeline <= lastSubmission_)
            throw std::invalid_argument("Allocator seal lacks newer actual timeline");
        lastSubmission_ = realTimeline;
        if (!pending_.empty()) {
            for (const auto& output : pending_)
                output->timeline_ = realTimeline;
            inFlight_.push_back({realTimeline, std::move(pending_)});
            pending_.clear();
        }
    }
    void retire(uint64_t realTimeline) {
        if (realTimeline > lastSubmission_)
            throw std::invalid_argument("Allocator completion exceeds actual sealed prefix");
        while (!inFlight_.empty() && inFlight_.front().timeline <= realTimeline)
            inFlight_.pop_front();
    }

  public:
    Allocator18DDD0(const Allocator18DDD0&) = delete;
    ~Allocator18DDD0() {
        if (!pending_.empty() || !inFlight_.empty())
            device_.wait_idle();
    }
    static constexpr bool OverflowWaitAndQueueClosureImplemented = false;
    static constexpr bool NaturalActivationImplemented = false;
};
} // namespace reo_gpu_upstream
