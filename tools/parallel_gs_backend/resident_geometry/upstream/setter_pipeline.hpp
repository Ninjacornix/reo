#pragma once
#include "upstream_bank_abi.hpp"
#include "command_buffer.hpp"
#include "setter_control_mask.hpp"
#include "setter_effects_packet.hpp"
#include "tools/parallel_gs_backend/resident_geometry/enrollment/sha256.hpp"
#include <deque>
namespace reo_gpu_upstream {
class Setter196010 final {
    friend class reo_gpu_palette_parent::Producer;

  public:
    class Output final {
        friend class Setter196010;
        const Setter196010* issuer_ = nullptr;
        BanksHandle banks_;
        CallHandle call_;
        Vulkan::BufferHandle receipt_, scalar_, effects_, scratch_;
        Output(const Setter196010* issuer, BanksHandle banks, CallHandle call,
               Vulkan::BufferHandle receipt, Vulkan::BufferHandle scalar,
               Vulkan::BufferHandle effects, Vulkan::BufferHandle scratch)
            : issuer_(issuer), banks_(std::move(banks)), call_(std::move(call)),
              receipt_(std::move(receipt)), scalar_(std::move(scalar)),
              effects_(std::move(effects)), scratch_(std::move(scratch)) {}

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
        const Vulkan::Buffer& scalar() const {
            return *scalar_;
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
    uint32_t moduleKind_ = 0;
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
    static bool isInternalSetterReturn(uint32_t target) noexcept {
        switch (target) {
            case 0x196060u:
            case 0x196084u:
            case 0x19608cu:
            case 0x196090u:
            case 0x1960ccu:
            case 0x1960f0u:
            case 0x196130u:
            case 0x196158u:
            case 0x1961b8u:
            case 0x1961bcu:
            case 0x196378u:
            case 0x1963a8u:
            case 0x19642cu:
            case 0x196440u:
            case 0x196454u:
            case 0x196468u:
            case 0x19647cu:
            case 0x196490u:
            case 0x1964a4u:
            case 0x1964b8u:
            case 0x1964ccu:
            case 0x196520u:
            case 0x196538u:
            case 0x196554u:
            case 0x19655cu:
            case 0x196568u:
            case 0x196588u:
            case 0x1965c0u:
            case 0x196604u:
            case 0x19660cu:
            case 0x196650u:
            case 0x196658u:
            case 0x1966a4u:
            case 0x1966acu:
            case 0x1966dcu:
            case 0x1966f4u:
            case 0x196724u:
            case 0x196740u:
            case 0x196770u:
            case 0x19678cu:
            case 0x1967c4u:
            case 0x1967dcu:
            case 0x1967f0u:
            case 0x196808u:
            case 0x196814u:
            case 0x19681cu:
            case 0x196838u:
            case 0x196840u:
            case 0x196850u:
            case 0x196860u:
            case 0x19689cu:
            case 0x1968a4u:
            case 0x1968acu:
            case 0x1968e8u:
            case 0x1968f8u:
            case 0x196920u:
            case 0x196930u:
            case 0x196968u:
            case 0x196984u:
            case 0x19698cu:
            case 0x1969b0u:
            case 0x1969b8u:
            case 0x1969c8u:
            case 0x1969f0u:
            case 0x196a20u:
            case 0x196a4cu:
            case 0x196a58u:
            case 0x196a64u:
            case 0x196a70u:
            case 0x196a7cu:
            case 0x196a84u:
            case 0x196a90u:
            case 0x196a9cu:
            case 0x196aa4u:
            case 0x196af4u:
            case 0x196afcu:
            case 0x196b24u:
            case 0x196b2cu:
            case 0x196b60u:
            case 0x196b98u:
            case 0x196ba8u:
            case 0x196bb0u:
            case 0x196bf0u:
            case 0x196c30u:
            case 0x196c54u:
            case 0x196c70u:
            case 0x196ca0u:
            case 0x196cbcu:
            case 0x196cecu:
            case 0x196d08u:
            case 0x196d38u:
            case 0x196d54u:
            case 0x196d74u:
            case 0x196d84u:
            case 0x196d94u:
            case 0x196dd4u:
            case 0x196de8u:
            case 0x196e3cu:
            case 0x196e44u:
            case 0x196e70u:
            case 0x196e78u:
            case 0x196e84u:
            case 0x196e90u:
            case 0x196e98u:
            case 0x196ee0u:
            case 0x196ee4u:
            case 0x196ee8u:
            case 0x1970fcu:
            case 0x19710cu:
            case 0x19711cu:
            case 0x197138u:
            case 0x197158u:
            case 0x197168u:
            case 0x197174u:
            case 0x197180u:
            case 0x1971a8u:
            case 0x1971b0u:
            case 0x1971b8u:
            case 0x1971d8u:
            case 0x1971e8u:
            case 0x1971ecu:
            case 0x197210u:
            case 0x197224u:
            case 0x197230u:
            case 0x1972a0u:
            case 0x1972a8u:
            case 0x1972b0u:
            case 0x1972b8u:
            case 0x1972c0u:
            case 0x1972c8u:
            case 0x1972d0u:
            case 0x1972d8u:
            case 0x1972e4u:
            case 0x197304u:
            case 0x197324u:
            case 0x197338u:
            case 0x19734cu:
            case 0x19736cu:
            case 0x197378u:
            case 0x197384u:
            case 0x197398u:
            case 0x1973b8u:
            case 0x197428u:
            case 0x197430u:
            case 0x197438u:
            case 0x197440u:
            case 0x197448u:
            case 0x197450u:
            case 0x197458u:
            case 0x19745cu:
            case 0x197460u:
                return true;
            default:
                return false;
        }
    }
    Setter196010(Vulkan::Device& device, const std::vector<uint32_t>& module, BanksHandle banks,
                 const void* actualService)
        : device_(device), banks_(std::move(banks)), callIssuer_(actualService) {
        if (!banks_ || banks_->device() != &device_ || !banks_->issuer() || !callIssuer_)
            throw std::invalid_argument("196010 lacks actual opaque parent banks/Service");
        const std::array<uint32_t, 4> sizes{RamBytes, SprBytes, ContextBytes, CompletionBytes};
        for (unsigned bank = 0; bank < 4; ++bank) {
            const auto& b = banks_->bank(Bank(bank));
            const auto& ci = b.get_create_info();
            if (ci.size != sizes[bank] || ci.domain != Vulkan::BufferDomain::Device ||
                (ci.usage &
                 (VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT)) !=
                    (VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT))
                throw std::invalid_argument("196010 owner bank shape differs");
        }
        if (module.size() < 5 || module[0] != 0x07230203u)
            throw std::invalid_argument("196010 module absent");
        std::vector<uint8_t> code(module.size() * 4);
        std::memcpy(code.data(), module.data(), code.size());
        const auto moduleIdentity = reo_gpu_catalog::sha256(code);
        moduleKind_ =
            moduleIdentity == "91ae5d95413e36484c8548dbe6f4d3f6d08ded59e0ff0f0538844a47107e8571"
                ? 1u
                : 0u;
        if (moduleIdentity == "1a9b42db9fe56afebeaf91be0415a55351d36ee979e226bc95be6621d4c732b0")
            moduleKind_ = 3u;
        if (moduleIdentity == "f12a42933bc3865816f950a6fd283545d7dc6b8fe38d6d3c47d422f26fc6c9fe")
            moduleKind_ = 4u;
        if (moduleIdentity == "ede0582c30e8e143fa816822146378d71b975f9fb5f4c93bd8526cf4fd4d0fb6")
            moduleKind_ = 5u;
        if (moduleIdentity == "38e1ddb70d27594ea89b0c6c03b754f864906bab46f8eb0fc1091de3e94c2656")
            moduleKind_ = 6u;
        if (moduleIdentity == "f9fda6222c6de88653897a6263bd6ba8297dca1fdaa44f0298dd7eaa5dedcc74")
            moduleKind_ = 7u;
        if (moduleIdentity == "52cfc36453a5b26e13c6eca71acd845328811dcded5b5be67185b7a3aa2c1532")
            moduleKind_ = 8u;
        if (moduleKind_ == 0u &&
            moduleIdentity != "dedb7f6e1edf5e836cc38957964325ca824a2fb2c9871eed48588603bf698786")
            throw std::invalid_argument("196010 exact source module pin differs");
        VkPhysicalDeviceFloatControlsProperties controls{};
        controls.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES;
        VkPhysicalDeviceProperties2 properties{};
        properties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2;
        properties.pNext = &controls;
        vkGetPhysicalDeviceProperties2(device_.get_physical_device(), &properties);
        if (!controls.shaderRoundingModeRTEFloat32 || !controls.shaderDenormPreserveFloat32 ||
            !controls.shaderSignedZeroInfNanPreserveFloat32)
            throw std::invalid_argument("196010 required strict original binary32 modes absent");
        Vulkan::ResourceLayout shape{};
        shape.sets[0].storage_buffer_mask = 255;
        shape.push_constant_size = sizeof(Parameters);
        for (unsigned b = 0; b < 8; ++b)
            shape.sets[0].meta[b].array_size = 1;
        program_ = device_.request_program(module.data(), module.size() * 4, &shape);
        if (!program_ || !program_->get_pipeline_layout())
            throw std::runtime_error("196010 module unavailable");
        const auto& actual = program_->get_pipeline_layout()->get_resource_layout();
        if (actual.descriptor_set_mask != 1 || actual.bindless_descriptor_set_mask ||
            actual.sets[0].storage_buffer_mask != 255 || actual.push_constant_range.offset ||
            actual.push_constant_range.size != sizeof(Parameters) ||
            actual.push_constant_range.stageFlags != VK_SHADER_STAGE_COMPUTE_BIT)
            throw std::invalid_argument("196010 resource layout differs");
        for (unsigned b = 0; b < 8; ++b)
            if (actual.sets[0].meta[b].array_size != 1 ||
                actual.stages_for_bindings[0][b] != VK_SHADER_STAGE_COMPUTE_BIT)
                throw std::invalid_argument("196010 binding shape differs");
    }

  public:
    Setter196010(const Setter196010&) = delete;
    ~Setter196010() {
        if (!pending_.empty() || !inFlight_.empty())
            device_.wait_idle();
    }
    OutputHandle record(Vulkan::CommandBuffer& cmd, const CallHandle& call) {
        if (!call || isInternalSetterReturn(call->returnPc()) || call->issuer() != callIssuer_ ||
            call->entry() != 0x196010u || !supportsModuleCommand(call->a0() & 255u) ||
            call->task() < 1)
            throw std::invalid_argument("196010 call was not issued by actual Service");
        const auto& s = call->stamp();
        const auto& actual = banks_->stamp();
        if (!s.ordinal || s.ordinal <= lastOrdinal_ || s.session != actual.session ||
            s.epoch != actual.epoch || s.bankGeneration != actual.bankGeneration ||
            pending_.size() >= 4096)
            throw std::invalid_argument("196010 call identity stale/repeated/unbounded");
        // Source pointer/stack/write views are validated transactionally on GPU.
        Vulkan::BufferCreateInfo ci{};
        ci.domain = Vulkan::BufferDomain::Device;
        ci.size = ReceiptBytes;
        ci.usage = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT |
                   VK_BUFFER_USAGE_TRANSFER_DST_BIT;
        auto receipt = device_.create_buffer(ci);
        if (!receipt)
            throw std::runtime_error("196010 immutable receipt allocation failed");
        ci.size = 64;
        auto scalar = device_.create_buffer(ci);
        if (!scalar)
            throw std::runtime_error("Setter scalar receipt allocation failed");
        ci.size = CompositionEffectsBytes;
        auto effects = device_.create_buffer(ci);
        if (!effects)
            throw std::runtime_error("Setter exact effects allocation failed");
        ci.size = 41776u;
        ci.usage = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT;
        auto scratch = device_.create_buffer(ci);
        if (!scratch)
            throw std::runtime_error("Setter Device scratch allocation failed");
        auto output = std::shared_ptr<const Output>(
            new Output(this, banks_, call, std::move(receipt), std::move(scalar),
                       std::move(effects), std::move(scratch)));
        pending_.push_back(output);
        lastOrdinal_ = s.ordinal;
        for (unsigned b = 0; b < 4; ++b)
            barrier(cmd, banks_->bank(Bank(b)));
        barrier(cmd, *output->receipt_);
        barrier(cmd, *output->scalar_);
        barrier(cmd, *output->effects_);
        barrier(cmd, *output->scratch_);
        auto p = parameters(*call);
        p.reserved = uint32_t(call->task());
        cmd.set_program(program_);
        for (unsigned b = 0; b < 4; ++b)
            cmd.set_storage_buffer(0, b, banks_->bank(Bank(b)));
        cmd.set_storage_buffer(0, 4, *output->receipt_);
        cmd.set_storage_buffer(0, 5, *output->scalar_);
        cmd.set_storage_buffer(0, 6, *output->effects_);
        cmd.set_storage_buffer(0, 7, *output->scratch_);
        cmd.push_constants(&p, 0, sizeof(p));
        cmd.dispatch(1, 1, 1);
        for (unsigned b = 0; b < 4; ++b)
            barrier(cmd, banks_->bank(Bank(b)));
        barrier(cmd, *output->receipt_);
        barrier(cmd, *output->scalar_);
        barrier(cmd, *output->effects_);
        barrier(cmd, *output->scratch_);
        return output;
    }
    bool owns(const OutputHandle& output) const noexcept {
        return output && output->issuer_ == this && output->banks_ == banks_;
    }
    void seal(uint64_t actualTimeline) {
        if (!actualTimeline || actualTimeline <= lastSubmission_)
            throw std::invalid_argument("196010 seal requires new actual submission");
        lastSubmission_ = actualTimeline;
        if (!pending_.empty()) {
            inFlight_.push_back({actualTimeline, std::move(pending_)});
            pending_.clear();
        }
    }
    void retire(uint64_t actualTimeline) {
        if (actualTimeline > lastSubmission_)
            throw std::invalid_argument("196010 retirement exceeds actual sealed prefix");
        while (!inFlight_.empty() && inFlight_.front().timeline <= actualTimeline)
            inFlight_.pop_front();
    }
    static bool supportsCommand(uint32_t c) {
        return (c >= 0x1au && c <= 0x5cu) || c == 0x10u || c == 0x11u || c == 0x16u || c == 0x17u ||
               c == 0x19u || c == 0x67u;
    }
    bool supportsModuleCommand(uint32_t c) const noexcept {
        const std::array<uint32_t, 6> finite{0x10u, 0x11u, 0x16u, 0x17u, 0x19u, 0x67u};
        if (moduleKind_ >= 3u)
            return moduleKind_ < 9u && c == finite[moduleKind_ - 3u];
        return moduleKind_ == 1u ? (c >= 0x1au && c <= 0x59u)
                                 : (moduleKind_ == 0u && c >= 0x5au && c <= 0x5cu);
    }
    static constexpr uint32_t DeviceScratchWords = 10444u,
                              DeviceScratchBytes = DeviceScratchWords * 4u;
    static constexpr bool ExactSourceEffectsNumericallyProved = false;
    static constexpr bool OriginalNumericalParityProved = false;
    static constexpr bool RegisteredContinuationProvenanceImplemented = false;
    static constexpr bool AllocatorQueueClosureImplemented = false;
    static constexpr bool NaturalSourceClosureImplemented = false;
};
} // namespace reo_gpu_upstream
