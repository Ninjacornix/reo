#pragma once
#include "upstream_bank_abi.hpp"
#include "context_layout.hpp"
#include "integer_controls.hpp"
#include "perspective_effects_packet.hpp"
#include "command_buffer.hpp"
#include "tools/parallel_gs_backend/resident_geometry/enrollment/sha256.hpp"
#include <deque>
namespace reo_gpu_upstream {
class Perspective18F710 final {
    friend class reo_gpu_palette_parent::Producer;

  public:
    class Output final {
        friend class Perspective18F710;
        const Perspective18F710* issuer_ = nullptr;
        BanksHandle banks_;
        CallHandle call_;
        Vulkan::BufferHandle receipt_, effects_;
        Output(const Perspective18F710* issuer, BanksHandle banks, CallHandle call,
               Vulkan::BufferHandle receipt, Vulkan::BufferHandle effects)
            : issuer_(issuer), banks_(std::move(banks)), call_(std::move(call)),
              receipt_(std::move(receipt)), effects_(std::move(effects)) {}

      public:
        const Call& call() const {
            return *call_;
        }
        const Vulkan::Buffer& receipt() const {
            return *receipt_;
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
    };
    using OutputHandle = std::shared_ptr<const Output>;

  private:
    Vulkan::Device& device_;
    BanksHandle banks_;
    const void* callIssuer_;
    Vulkan::Program* program_ = nullptr;
    uint64_t lastOrdinal_ = 0, lastSubmission_ = 0;
    std::vector<OutputHandle> pending_;
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
    Perspective18F710(Vulkan::Device& device, const std::vector<uint32_t>& module,
                      BanksHandle banks, const void* actualService)
        : device_(device), banks_(std::move(banks)), callIssuer_(actualService) {
        if (!banks_ || banks_->device() != &device_ || !banks_->issuer() || !callIssuer_)
            throw std::invalid_argument(
                "Perspective closure lacks actual opaque parent banks/Service");
        const std::array<uint32_t, 4> sizes{RamBytes, SprBytes, ContextBytes, CompletionBytes};
        for (unsigned bank = 0; bank < 4; ++bank) {
            const auto& b = banks_->bank(Bank(bank));
            const auto& ci = b.get_create_info();
            if (ci.size != sizes[bank] || ci.domain != Vulkan::BufferDomain::Device ||
                (ci.usage &
                 (VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT)) !=
                    (VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT))
                throw std::invalid_argument("Perspective closure owner bank shape differs");
        }
        if (module.size() < 5 || module[0] != 0x07230203u)
            throw std::invalid_argument("Perspective closure module absent");
        std::vector<uint8_t> code(module.size() * 4);
        std::memcpy(code.data(), module.data(), code.size());
        if (reo_gpu_catalog::sha256(code) !=
            "99abd0f43f71bb246f918f037c2053fb7de1eb55398986e16543c4d50ad03452")
            throw std::invalid_argument("Perspective closure exact source module pin differs");
        VkPhysicalDeviceFloatControlsProperties controls{};
        controls.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES;
        VkPhysicalDeviceProperties2 properties{};
        properties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2;
        properties.pNext = &controls;
        vkGetPhysicalDeviceProperties2(device_.get_physical_device(), &properties);
        if (!controls.shaderRoundingModeRTEFloat32 || !controls.shaderDenormPreserveFloat32 ||
            !controls.shaderSignedZeroInfNanPreserveFloat32)
            throw std::invalid_argument(
                "Perspective closure required strict original binary32 modes absent");
        Vulkan::ResourceLayout shape{};
        shape.sets[0].storage_buffer_mask = 63;
        shape.push_constant_size = sizeof(Parameters);
        for (unsigned b = 0; b < 6; ++b)
            shape.sets[0].meta[b].array_size = 1;
        program_ = device_.request_program(module.data(), module.size() * 4, &shape);
        if (!program_ || !program_->get_pipeline_layout())
            throw std::runtime_error("Perspective closure module unavailable");
        const auto& actual = program_->get_pipeline_layout()->get_resource_layout();
        if (actual.descriptor_set_mask != 1 || actual.bindless_descriptor_set_mask ||
            actual.sets[0].storage_buffer_mask != 63 || actual.push_constant_range.offset ||
            actual.push_constant_range.size != sizeof(Parameters) ||
            actual.push_constant_range.stageFlags != VK_SHADER_STAGE_COMPUTE_BIT)
            throw std::invalid_argument("Perspective closure resource layout differs");
        for (unsigned b = 0; b < 6; ++b)
            if (actual.sets[0].meta[b].array_size != 1 ||
                actual.stages_for_bindings[0][b] != VK_SHADER_STAGE_COMPUTE_BIT)
                throw std::invalid_argument("Perspective closure binding shape differs");
    }

  public:
    static bool supports(uint32_t pc) {
        return pc == 0x18f710u || pc == 0x18f754u || pc == 0x18f75cu || pc == 0x1921b0u ||
               pc == 0x1921c8u || pc == 0x18f570u || pc == 0x18fdf0u;
    }
    Perspective18F710(const Perspective18F710&) = delete;
    ~Perspective18F710() {
        if (!pending_.empty() || !inFlight_.empty())
            device_.wait_idle();
    }
    OutputHandle record(Vulkan::CommandBuffer& cmd, const CallHandle& call) {
        if (!call || call->issuer() != callIssuer_ || !supports(call->entry()) || call->task() < 1)
            throw std::invalid_argument(
                "Perspective closure call was not issued by actual Service");
        const auto& s = call->stamp();
        const auto& actual = banks_->stamp();
        if (!s.ordinal || s.ordinal <= lastOrdinal_ || s.session != actual.session ||
            s.epoch != actual.epoch || s.bankGeneration != actual.bankGeneration ||
            pending_.size() >= 4096)
            throw std::invalid_argument(
                "Perspective closure call identity stale/repeated/unbounded");
        // Actual stack/destination/source addresses are validated transactionally
        // by the GPU against its owned Context and memory views, including aliases.
        Vulkan::BufferCreateInfo ci{};
        ci.domain = Vulkan::BufferDomain::Device;
        ci.size = ReceiptBytes;
        ci.usage = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT |
                   VK_BUFFER_USAGE_TRANSFER_DST_BIT;
        auto receipt = device_.create_buffer(ci);
        if (!receipt)
            throw std::runtime_error("Perspective closure immutable receipt allocation failed");
        ci.size = PerspectiveEffectsBytes;
        auto effects = device_.create_buffer(ci);
        if (!effects)
            throw std::runtime_error("Perspective source effects allocation failed");
        auto output = std::shared_ptr<const Output>(
            new Output(this, banks_, call, std::move(receipt), std::move(effects)));
        pending_.push_back(output);
        lastOrdinal_ = s.ordinal;
        for (unsigned b = 0; b < 4; ++b)
            barrier(cmd, banks_->bank(Bank(b)));
        barrier(cmd, *output->receipt_);
        barrier(cmd, *output->effects_);
        auto p = parameters(*call);
        p.reserved = uint32_t(call->task());
        cmd.set_program(program_);
        for (unsigned b = 0; b < 4; ++b)
            cmd.set_storage_buffer(0, b, banks_->bank(Bank(b)));
        cmd.set_storage_buffer(0, 4, *output->receipt_);
        cmd.set_storage_buffer(0, 5, *output->effects_);
        cmd.push_constants(&p, 0, sizeof(p));
        cmd.dispatch(1, 1, 1);
        for (unsigned b = 0; b < 4; ++b)
            barrier(cmd, banks_->bank(Bank(b)));
        barrier(cmd, *output->receipt_);
        barrier(cmd, *output->effects_);
        return output;
    }
    bool owns(const OutputHandle& output) const noexcept {
        return output && output->issuer_ == this && output->banks_ == banks_;
    }
    void seal(uint64_t actualTimeline) {
        if (!actualTimeline || actualTimeline <= lastSubmission_)
            throw std::invalid_argument("Perspective closure seal requires new actual submission");
        lastSubmission_ = actualTimeline;
        if (!pending_.empty()) {
            inFlight_.push_back({actualTimeline, std::move(pending_)});
            pending_.clear();
        }
    }
    void retire(uint64_t actualTimeline) {
        if (actualTimeline > lastSubmission_)
            throw std::invalid_argument(
                "Perspective closure retirement exceeds actual sealed prefix");
        while (!inFlight_.empty() && inFlight_.front().timeline <= actualTimeline)
            inFlight_.pop_front();
    }
    // Receipt18 is actual GPU-restored finalPC,19 original FCR31 control bits.
    // Parent wait/EE context control delivery requires a profile-specific gate,
    // rather than Matrix191280's reserved18/19==zero assumptions.
    static constexpr bool NaturalSourceClosureImplemented = false;
    static constexpr bool OriginalNumericalParityProved = false;
    static constexpr bool CompleteWrapperClosure = false;
};
} // namespace reo_gpu_upstream
