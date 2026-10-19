#pragma once
#include "parent_gpu_transport.hpp"
#include "resident_vif_commands.h"
#include "../resident_program_bank.hpp"
#include "gs_interface.hpp"
#include "../protected_scalar_capture.hpp"
#include "../upstream/protected_queue_capture.hpp"
#include "../upstream/certified_control_commit.hpp"
#include "../upstream/certified_queue_commit.hpp"
#include "ps2_guest_sched.h"
#include "parent_first_entry.h"
#include "source_instruction_access.hpp"
#include "irq_cpu_control.h"
#include "../upstream/effects_ledger.hpp"
#include "../upstream/state_packet_effects197900.hpp"
#include "../upstream/typed_context_controls.hpp"
#include "../upstream/irq_context_pause.hpp"
#include <algorithm>
#include <limits>
#include <optional>
#include <mutex>
#include <atomic>

extern uint32_t ps2IoRegLockDepth() noexcept;
namespace reo_resident_live {
class ParallelArrayOwner;
}
namespace reo_parent_natural {
class NativeTarget;
}
namespace reo_parent_install {

namespace protocol = reo_parent_live;
struct ColdSource {
    const void* ram = nullptr;
    const void* spr = nullptr;
    R5900Context* actualContext = nullptr;
    // Keeps the genuine cold memory/context identities alive. The caller must
    // provide a reviewed cold boundary, not a recurring captured host shadow.
    std::shared_ptr<const void> lifetime;
    reo_parent_natural::ColdEntryHandle capturedEntry; // Immutable one-time actual EE entry image.
};
struct RetainedEntryBody {
    uint32_t entry = 0;
    PS2Runtime::RecompiledFunction body = nullptr;
};
struct Configuration {
    bool boundedRetainedInvocations = false;
    std::vector<RetainedEntryBody> retainedEntryBodies;
    bool enabled = false;
    uint64_t session = 0;
    std::shared_ptr<const ColdSource> cold;
    reo_gpu_palette_parent::Modules producer;
    protocol::TransportModules transport;
    protocol::Gates gates{};
    reo_gpu_palette_parent::Proofs producerProofs{};
    protocol::AdmissionTier tier = protocol::AdmissionTier::ScopedLive;
};

// One service is constructed within the actual GS/VIF owner, once. It is not a
// Route entry and does not construct a Device, infer origins, or perform math.
class Service final : private protocol::Backend {

    friend class reo_parent_natural::NativeTarget;

  public:
    class ParentReturn final {
        friend class Service;
        const Service* issuer_ = nullptr;
        protocol::Key key_;
        protocol::Receipt receipt_;
        ParentReturn(const Service* issuer, const protocol::Key& key, protocol::Receipt receipt)
            : issuer_(issuer), key_(key), receipt_(std::move(receipt)) {}

      public:
        ParentReturn(const ParentReturn&) = delete;
        ParentReturn& operator=(const ParentReturn&) = delete;
        const protocol::Key& key() const noexcept {
            return key_;
        }
    };

  private:
    class SourceEpochCarry final {
        friend class Service;
        friend class reo_parent_natural::NativeTarget;
        const Service* issuer_;
        const reo_parent_natural::NativeTarget* sourceOwner_;
        std::shared_ptr<const ColdSource> source_;
        reo_gpu_upstream::BanksHandle banks_;
        uint64_t oldEpoch_, newEpoch_, sourceSequence_;
        std::vector<protocol::Range> opaque_;
        std::array<uint8_t, 1648> roles_;
        SourceEpochCarry(const Service* issuer, const reo_parent_natural::NativeTarget* owner,
                         std::shared_ptr<const ColdSource> source,
                         reo_gpu_upstream::BanksHandle banks, uint64_t oldEpoch, uint64_t newEpoch,
                         uint64_t sourceSequence, std::vector<protocol::Range> opaque,
                         std::array<uint8_t, 1648> roles)
            : issuer_(issuer), sourceOwner_(owner), source_(std::move(source)),
              banks_(std::move(banks)), oldEpoch_(oldEpoch), newEpoch_(newEpoch),
              sourceSequence_(sourceSequence), opaque_(std::move(opaque)), roles_(roles) {}

      public:
        SourceEpochCarry(const SourceEpochCarry&) = delete;
    };
    mutable std::recursive_mutex hostProtocolMutex_;

    friend class reo_resident_live::ParallelArrayOwner;
    Vulkan::Device& device_;
    ParallelGS::GSInterface& gs_;
    std::shared_ptr<reo_resident_live::ProgramBank> target_;
    Configuration configuration_;
    uint64_t epoch_ = 0, generation_ = 0, issued_ = 0, completed_ = 0;
    std::atomic<uint32_t> failed_{0};
    Vulkan::Fence lastUploadFence_;
    Vulkan::Fence firstEntryUploadFence_;
    reo_parent_natural::ColdEntryHandle firstEntryUploaded_;
    std::unique_ptr<reo_gpu_palette_parent::Producer> producer_;
    std::unique_ptr<protocol::Transport> transport_;
    protocol::Bridge bridge_;
    struct Entry {
        protocol::Transport::Queued queued;
        Vulkan::Fence parentFence, uploadFence;
        Vulkan::BufferHandle stickyHost;
        uint64_t parentTimeline = 0, uploadTimeline = 0;
        bool parentReturned = false, recorded = false, issuedToParser = false;
        std::shared_ptr<const reo_resident_live::OpaqueLeaseUpload> token;
        std::shared_ptr<const ParentReturn> returnTicket;
    };
    std::vector<std::shared_ptr<Entry>> entries_;
    std::optional<reo_resident_live::Operation> parserOperation_;
    class RetainedInvocation;
    class RetainedInvocationScope;
    uint64_t upstreamOrdinal_ = 0;
    struct ViewportEntry {
        bool authenticBoundedMathCall =
            false; // NativeTarget only, after actual ColdEntry scope/fence checks.
        std::weak_ptr<RetainedInvocation> retainedInvocation;
        bool retainedInvocationBound = false;
        reo_gpu_upstream::CallHandle call;
        reo_gpu_upstream::Viewport::OutputHandle output;
        reo_gpu_upstream::StatePacket197900::OutputHandle stateOutput;
        Vulkan::BufferHandle stateEffectsHost;
        uint32_t statePriorInstructions = 0;
        reo_gpu_upstream::StatePacketEffectsPacket statePacket;
        std::vector<std::shared_ptr<const reo_source_closure::CertifiedEffects>> stateCertificates;
        std::vector<protocol::Range> stateInitialOpaque;
        std::array<uint8_t, 1648> stateInitialRoles{};

        Vulkan::Fence fence;
        Vulkan::BufferHandle receiptHost, controlHost, effectsHost;
        uint64_t timeline = 0;
        uint32_t priorStage = 0, expectedBeforePc = 0, allocatorSourceWord = 0;
        reo_gpu_upstream::QueueResolverBindingHandle queueResolver;
        reo_gpu_upstream::ProtectedQueueCaptureHandle queueCapture;
        reo_parent_natural::ProtectedScalarCaptureHandle heapFrontier;
        std::shared_ptr<reo_parent_natural::ControlTarget> heapSourceOwner;
        bool heapFrontierReleased = false;
        std::vector<protocol::Range> incomingContextOpaque;
        std::array<uint8_t, 1648> incomingScalarRoles{};
        reo_gpu_upstream::ViewportEffectsPacket packet;
        std::shared_ptr<const reo_source_closure::CertifiedEffects> certificate;
        bool waiting = false, waited = false, committed = false, controlHeld = false;
        std::array<uint32_t, reo_gpu_upstream::ReceiptWords> receipt{};
        std::array<uint32_t, reo_gpu_upstream::Viewport::ControlWords> control{};
    };
    std::vector<std::shared_ptr<ViewportEntry>> viewportEntries_;
    std::unique_ptr<reo_gpu_upstream::QueueControlAdapter> viewportQueueAdapter_;
    struct AllocatorEntry {
        reo_gpu_upstream::AllocatorHeapCaptureHandle capture;
        reo_gpu_upstream::Allocator18DDD0::OutputHandle output;
        std::shared_ptr<reo_parent_natural::ControlTarget> sourceOwner;
        Vulkan::Fence fence;
        Vulkan::BufferHandle host;
        uint64_t timeline = 0, resumeTimeline = 0;
        bool waiting = false, waited = false, cpuCommitted = false, returnIssued = false,
             resumed = false;
        std::array<uint32_t, reo_gpu_upstream::ReceiptWords> receipt{};
        reo_parent_natural::CertifiedControlCommitHandle commit;
        reo_parent_natural::ProtectedScalarCaptureHandle successorFrontier;
        reo_gpu_upstream::Viewport::ControlReturnHandle returned;
        reo_gpu_upstream::StatePacket197900::ControlReturnHandle stateReturned;
    };
    std::vector<std::shared_ptr<AllocatorEntry>> allocatorEntries_;
    struct QueueEntry {
        reo_gpu_upstream::CallHandle original;
        reo_gpu_upstream::ProtectedQueueCaptureHandle capture;
        reo_gpu_upstream::QueueControlCallHandle call;
        reo_gpu_upstream::ProtectedQueueSnapshotHandle snapshot;
        reo_gpu_upstream::ProtectedCounterImportHandle imported;
        reo_gpu_upstream::QueueHeaderMetadataPipeline::OutputHandle query;
        reo_gpu_upstream::QueueHeaderLeaseHandle headers;
        reo_gpu_upstream::QueueControlAdapter::PlanHandle plan;
        Vulkan::Fence queryFence;
        Vulkan::BufferHandle queryHost;
        uint64_t queryTimeline = 0;
        bool queryWaiting = false, queryWaited = false;
        reo_gpu_upstream::QueueJournalPipeline::OutputHandle journal;
        Vulkan::Fence journalFence;
        Vulkan::BufferHandle journalHost;
        uint64_t journalTimeline = 0, resumeTimeline = 0;
        bool journalWaiting = false, journalWaited = false, cpuCommitted = false,
             returnIssued = false, resumed = false;
        std::array<uint32_t, reo_gpu_upstream::ReceiptWords> journalReceipt{};
        reo_parent_natural::CertifiedQueueCommitHandle commit;
        reo_parent_natural::ProtectedScalarCaptureHandle successorFrontier;
        reo_gpu_upstream::Viewport::ControlReturnHandle returned;
        reo_gpu_upstream::StatePacket197900::ControlReturnHandle stateReturned;
    };
    std::vector<std::shared_ptr<QueueEntry>> queueEntries_;

    struct MatrixEntry {
        std::weak_ptr<RetainedInvocation> retainedInvocation;
        bool retainedInvocationBound = false;
        reo_gpu_upstream::CallHandle call;
        reo_gpu_upstream::Matrix191280::OutputHandle output;
        Vulkan::Fence fence;
        Vulkan::BufferHandle host;
        uint64_t timeline = 0;
        bool waited = false, committed = false;
        std::array<uint32_t, reo_gpu_upstream::ReceiptWords> receipt{};
    };
    std::vector<std::shared_ptr<MatrixEntry>> matrixEntries_;
    struct PerspectiveEntry {
        std::weak_ptr<RetainedInvocation> retainedInvocation;
        bool retainedInvocationBound = false;
        reo_gpu_upstream::CallHandle call;
        reo_gpu_upstream::Perspective18F710::OutputHandle output;
        Vulkan::Fence fence;
        Vulkan::BufferHandle host, hostEffects;
        uint64_t timeline = 0;
        bool waiting = false, waited = false, committed = false;
        std::array<uint32_t, reo_gpu_upstream::ReceiptWords> receipt{};
        reo_gpu_upstream::PerspectiveEffectsPacket packet;
        std::shared_ptr<const reo_source_closure::CertifiedEffects> certificate;
    };
    std::vector<std::shared_ptr<PerspectiveEntry>> perspectiveEntries_;

    std::vector<protocol::Range> upstreamOpaque_;
    struct CompositionEntry {
        std::weak_ptr<RetainedInvocation> retainedInvocation;
        bool retainedInvocationBound = false;
        reo_gpu_upstream::CallHandle call;
        reo_gpu_upstream::Composition18F6A0::OutputHandle output;
        Vulkan::Fence fence;
        Vulkan::BufferHandle host, hostEffects;
        uint64_t timeline = 0;
        bool waiting = false, waited = false, committed = false;
        uint32_t inputSp = 0;
        std::vector<protocol::Range> held;
        std::array<uint32_t, reo_gpu_upstream::ReceiptWords> receipt{};
        reo_gpu_upstream::CompositionEffectsPacket packet;
        std::shared_ptr<const reo_source_closure::CertifiedEffects> certificate;
    };
    std::vector<std::shared_ptr<CompositionEntry>> compositionEntries_;
    std::array<uint8_t, 1648> compositionScalarRoles_{};
    uint64_t completedCompositionTimeline_ = 0;
    struct CallbackEntry {
        const Service* issuer = nullptr;
        R5900Context* caller = nullptr;
        std::shared_ptr<reo_parent_natural::GuestContextStorage> storage;
        std::shared_ptr<const void> lifetime;
        std::shared_ptr<const void> callerLifetime;
        reo_parent_natural::RpcCallbackControls controls;
        reo_parent_natural::RpcCallbackInvocationHandle source;
        reo_parent_natural::IrqInitializerHandle freshInitializer;
        IrqContextPauseHandle irqPause;
        bool mainHeldT1 = false;
        reo_gpu_palette_parent::Producer::ContextImageHandle callerImage, childImage;
        protocol::Bridge::ContextLoan bridgeLoan;
        std::vector<protocol::Range> callerContextOpaque;
        std::array<uint8_t, 1648> callerRoles{};
        std::vector<protocol::Range> childContextOpaque;
        std::array<uint8_t, 1648> childRoles{};
        std::vector<reo_context_handoff::ControlPatch> patches;
        Vulkan::Fence forkFence, closeFence;
        uint64_t forkOrdinal = 0, closeOrdinal = 0, forkTimeline = 0, closeTimeline = 0;
        int32_t task = -1;
        bool recorded = false, waited = false, closed = false;
    };
    std::vector<std::shared_ptr<CallbackEntry>> callbacks_;
    uint64_t activeContextRevision_ = 1;
    std::atomic<R5900Context*> callbackActiveContext_{nullptr};
    std::atomic<R5900Context*> pausedMainContext_{nullptr};
    std::vector<std::shared_ptr<IrqContextPause>> irqPauses_;
    uint64_t irqPauseOrdinal_ = 0;
    mutable std::mutex irqReservationWaitMutex_;
    std::condition_variable irqReservationChanged_;
    std::atomic<uint64_t> irqReservationRevision_{1};

  private:
    void mirrorOriginalCpuIrqControlOnOwner(const reo_parent_natural::IrqCpuLeaseHandle& lease,
                                            const protocol::RawPatch& patch) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        if (!lease || !lease->activeOnOwner() || lease->epoch() != epoch_ || callbacks_.empty() ||
            callbacks_.back()->freshInitializer != lease->initializer() ||
            !callbacks_.back()->waited || callbacks_.back()->closed ||
            patch.kind != protocol::SourcePatchKind::IrqIntegerControl ||
            patch.range.space != protocol::Space::Ram)
            throw std::invalid_argument(
                "CPU IRQ mirror lost actual fresh Context/pause/source issuer");
        exactFreshIrqFrame(callbacks_.back());
        protocol::validateSourcePatchShape(patch);
        std::vector<protocol::Range> next;
        next.reserve(upstreamOpaque_.size() + 1u);
        for (const auto& r : upstreamOpaque_) {
            if (r.space != protocol::Space::Ram ||
                !protocol::overlap(r.address, r.bytes, patch.range.address, patch.range.bytes)) {
                next.push_back(r);
                continue;
            }
            const uint64_t a = r.address, b = a + r.bytes, x = patch.range.address,
                           y = x + patch.range.bytes;
            if (a < x)
                next.push_back({r.space, r.address, uint32_t(x - a)});
            if (y < b)
                next.push_back({r.space, uint32_t(y), uint32_t(b - y)});
        }
        auto fence = gs_.submit_resident_completion(
            [&](Vulkan::CommandBuffer& cmd) { producer_->bridgeSourceWrite(cmd, patch); });
        if (!fence)
            throw std::runtime_error(
                "Original CPU IRQ scalar mirror lacks actual same-Device fence");
        fence->wait();
        if (!lease->activeOnOwner())
            throw std::runtime_error("CPU IRQ mirror outlived actual source scope");
        requireHealthy();
        upstreamOpaque_.swap(next);
    }
    void recordReviewedSourceOverwrite(const protocol::RawPatch& patch) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        if (patch.kind != protocol::SourcePatchKind::ReviewedRaw)
            throw std::invalid_argument("Numeric source cannot enter reviewed RAW overwrite");
        if (!viewportEntries_.empty())
            throw std::invalid_argument(
                "Ordinary RAW mirror cannot overtake protected viewport scope");
        const uint32_t limit = patch.range.space == protocol::Space::Ram   ? protocol::RamBytes
                               : patch.range.space == protocol::Space::Spr ? 0x4000u
                                                                           : 1648u;
        if (!patch.actualWriterOrdinal || patch.bytes.size() != patch.range.bytes ||
            !protocol::range(patch.range.address, patch.range.bytes, limit))
            throw std::invalid_argument("Reviewed actual source patch is invalid");
        // Allocate the exact range subtraction before recording. A partial
        // RAW write lifts only its own bytes, never adjacent opaque lanes.
        std::vector<protocol::Range> remaining;
        remaining.reserve(upstreamOpaque_.size() + 1);
        for (const auto& range : upstreamOpaque_) {
            if (range.space != patch.range.space ||
                !protocol::overlap(range.address, range.bytes, patch.range.address,
                                   patch.range.bytes)) {
                remaining.push_back(range);
                continue;
            }
            if (range.address < patch.range.address)
                remaining.push_back(
                    {range.space, range.address, patch.range.address - range.address});
            const uint64_t end = uint64_t(range.address) + range.bytes,
                           stop = uint64_t(patch.range.address) + patch.range.bytes;
            if (end > stop)
                remaining.push_back({range.space, uint32_t(stop), uint32_t(end - stop)});
        }
        try {
            gs_.record_resident_command(
                [&](Vulkan::CommandBuffer& cmd) { producer_->bridgeSourceWrite(cmd, patch); });
            upstreamOpaque_.swap(remaining);
        } catch (...) {
            firstSticky(154u);
            throw;
        }
    }
    struct SetterEntry {
        std::weak_ptr<RetainedInvocation> retainedInvocation;
        bool retainedInvocationBound = false;
        reo_gpu_upstream::CallHandle call;
        reo_gpu_upstream::Setter196010::OutputHandle output;
        Vulkan::Fence fence;
        Vulkan::BufferHandle host, hostEffects;
        uint64_t timeline = 0;
        bool waited = false, committed = false;
        std::array<uint32_t, 36> words{};
        reo_gpu_upstream::SetterEffectsPacket packet;
        std::shared_ptr<const reo_source_closure::CertifiedEffects> certificate;
    };
    std::vector<std::shared_ptr<SetterEntry>> setterEntries_;

  private:
    bool admitsOriginalSetterOnEe(const R5900Context& ctx) const {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        uint8_t command;
        std::memcpy(&command, &ctx.r[4], 1);
        return ctx.pc == 0x196010u && producer_->setterForCommand(command & 255u) != nullptr;
    }
    reo_gpu_upstream::CallHandle prepareOriginalSetterOnEe(uint8_t* ram, R5900Context& ctx,
                                                           int32_t task) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        if (!compositionEntries_.empty())
            throw std::invalid_argument("Upstream call cannot overtake actual composition return");
        // This test occurs BEFORE entry allocation/ordinal advance/ownership.
        // 0E needs1982D0 allocator+queue;18 needs viewport; interior entries
        // need an actual continuation token. No guessed command is admitted.
        if (!admitsOriginalSetterOnEe(ctx) || ram != configuration_.cold->ram ||
            &ctx != activeSourceContextIdentity() || task < 1 ||
            setterEntries_.size() + matrixEntries_.size() + perspectiveEntries_.size() +
                    viewportEntries_.size() >=
                4096 ||
            upstreamOrdinal_ == UINT64_MAX)
            throw std::invalid_argument("Setter original command/source entry is not closed");
        for (const auto& e : matrixEntries_)
            if (!e->committed)
                throw std::invalid_argument("Setter cannot overtake matrix return");
        for (const auto& e : perspectiveEntries_)
            if (!e->committed)
                throw std::invalid_argument("Setter cannot overtake perspective return");
        for (const auto& e : viewportEntries_)
            if (!e->committed)
                throw std::invalid_argument("Setter cannot overtake viewport control return");
        for (const auto& e : setterEntries_)
            if (!e->committed)
                throw std::invalid_argument("Setter cannot overtake setter return");
        const auto raw = [&](unsigned r) {
            uint32_t x;
            std::memcpy(&x, &ctx.r[r], 4);
            return x;
        };
        uint8_t command;
        std::memcpy(&command, &ctx.r[4], 1);
        auto call = std::shared_ptr<const reo_gpu_upstream::Call>(new reo_gpu_upstream::Call(
            this, {configuration_.session, epoch_, generation_, upstreamOrdinal_ + 1}, ctx.pc,
            raw(31), command, 0, 0, task));
        auto e = std::make_shared<SetterEntry>();
        e->call = call;
        setterEntries_.push_back(e);
        upstreamOrdinal_ = call->stamp().ordinal;
        return call;
    }
    std::shared_ptr<SetterEntry>
    exactOriginalSetter(const reo_gpu_upstream::CallHandle& call) const {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        if (!call || call->issuer() != this || call->stamp().session != configuration_.session ||
            call->stamp().epoch != epoch_ || call->stamp().bankGeneration != generation_)
            throw std::invalid_argument("Setter call is foreign/stale");
        for (const auto& e : setterEntries_)
            if (e->call == call)
                return e;
        throw std::invalid_argument("Setter call was not issued at this original frontier");
    }
    void recordOriginalSetterOnOwner(const reo_gpu_upstream::CallHandle& call,
                                     const std::vector<protocol::RawPatch>& patches) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        auto e = exactOriginalSetter(call);
        (void)requireBoundRetainedInvocation(e);
        if (e->output || e->fence || e->committed)
            throw std::invalid_argument("Setter call already recorded");
        try {
            producer_->verifyOriginalUpstreamOrder(call); // Before any RAW prefix recording.
            Vulkan::BufferCreateInfo ci{};
            ci.domain = Vulkan::BufferDomain::CachedHost;
            ci.size = 144;
            ci.usage = VK_BUFFER_USAGE_TRANSFER_DST_BIT;
            e->host = device_.create_buffer(ci);
            if (!e->host)
                throw std::runtime_error("Setter scalar/control host allocation failed");
            ci.size = reo_gpu_upstream::SetterEffectsBytes;
            e->hostEffects = device_.create_buffer(ci);
            if (!e->hostEffects)
                throw std::runtime_error("Setter exact effects host allocation failed");
            gs_.record_resident_command([&](Vulkan::CommandBuffer& cmd) {
                // Reviewed original scalar/raw journal only. Computed graphics
                // buffers/uniforms and GPU outputs cannot enter as RawPatch.
                for (const auto& patch : patches)
                    producer_->bridgeSourceWrite(cmd, patch);
                e->output = producer_->recordOriginalSetter(cmd, call);
            });
            e->fence = gs_.submit_resident_completion([&](Vulkan::CommandBuffer& cmd) {
                const auto& receipt = e->output->receipt();
                const auto& scalar = e->output->scalar();
                for (const auto* b : {&receipt, &scalar})
                    cmd.buffer_barrier(*b, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                       VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                                       VK_PIPELINE_STAGE_TRANSFER_BIT,
                                       VK_ACCESS_2_TRANSFER_READ_BIT);
                cmd.copy_buffer(*e->host, 0, receipt, 0, 80);
                cmd.copy_buffer(*e->host, 80, scalar, 0, 64);
                const auto& effects = e->output->effects();
                cmd.buffer_barrier(effects, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                   VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                                   VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
                cmd.copy_buffer(*e->hostEffects, effects);
                cmd.buffer_barrier(*e->hostEffects, VK_PIPELINE_STAGE_TRANSFER_BIT,
                                   VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_HOST_BIT,
                                   VK_ACCESS_2_HOST_READ_BIT);
                cmd.buffer_barrier(*e->host, VK_PIPELINE_STAGE_TRANSFER_BIT,
                                   VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_HOST_BIT,
                                   VK_ACCESS_2_HOST_READ_BIT);
            });
            if (!e->fence)
                throw std::runtime_error("Setter has no genuine GS return fence");
            e->timeline = newTimeline();
            transport_->sealed(e->timeline);
        } catch (...) {
            observeOwnerSticky(149u);
            throw;
        }
    }
    void waitOriginalSetterOnOwner(const reo_gpu_upstream::CallHandle& call) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        auto e = exactOriginalSetter(call);
        if (!e->output || !e->fence || e->waited || e->committed)
            throw std::invalid_argument("Setter lacks new genuine return");
        try {
            e->fence->wait();
            const auto* raw = device_.map_host_buffer(*e->host, Vulkan::MEMORY_ACCESS_READ_BIT);
            if (!raw)
                throw std::runtime_error("Setter receipt map failed");
            std::memcpy(e->words.data(), raw, 144);
            device_.unmap_host_buffer(*e->host, Vulkan::MEMORY_ACCESS_READ_BIT);
            const auto& w = e->words;
            const auto p = reo_gpu_upstream::parameters(*call);
            if (w[0] || w[1] != reo_gpu_upstream::ReceiptMagic || w[2] != 1 || w[3] != 1 ||
                w[4] != p.sessionLo || w[5] != p.sessionHi || w[6] != p.epochLo ||
                w[7] != p.epochHi || w[8] != p.bankLo || w[9] != p.bankHi || w[10] != p.ordinalLo ||
                w[11] != p.ordinalHi || w[12] != p.entry || w[13] != p.returnPc || w[14] != p.a0 ||
                w[15] != p.a1 || w[16] != p.a2 || w[17] != p.entry || w[20] ||
                w[21] != 0x53544331u || w[32] != w[18] || w[33] != w[19] ||
                w[34] != (p.a0 & 255u) || w[35] != 1u)
                throw std::runtime_error("Setter actual profile receipt refused");
            for (unsigned k = 0; k < 8; ++k)
                if (w[22 + k] != w[4 + k])
                    throw std::runtime_error(
                        "Setter scalar receipt transaction association differs");
            std::vector<uint32_t> metadata(reo_gpu_upstream::SetterEffectsWords);
            const auto* effects =
                device_.map_host_buffer(*e->hostEffects, Vulkan::MEMORY_ACCESS_READ_BIT);
            if (!effects)
                throw std::runtime_error("Setter integer effects map failed");
            std::memcpy(metadata.data(), effects, reo_gpu_upstream::SetterEffectsBytes);
            device_.unmap_host_buffer(*e->hostEffects, Vulkan::MEMORY_ACCESS_READ_BIT);
            auto packet = reo_gpu_upstream::decodeSetterEffects(
                *call,
                std::span<const uint32_t, reo_gpu_upstream::ReceiptWords>(
                    e->words.data(), reo_gpu_upstream::ReceiptWords),
                metadata);
            for (const auto& control : packet.control)
                if (control.contextOffset == 32u && control.bytes == 8u &&
                    (control.bits[0] != w[30] || control.bits[1] != w[31]))
                    throw std::runtime_error(
                        "Setter scalar value differs from exact source effects");
            auto next = reo_source_closure::prepareGpuEffects(upstreamOpaque_,
                                                              compositionScalarRoles_, packet);
            auto certificate = std::shared_ptr<const reo_source_closure::CertifiedEffects>(
                new reo_source_closure::CertifiedEffects(
                    this, e->output->banks(), call, e->output->effectsHandle(), e->timeline,
                    packet.header, packet.dirty, packet.control));
            // Only logical original last writes gain GPU ownership. Incoming
            // restorations and every untouched byte keep their prior ledger.
            e->packet = std::move(packet);
            e->certificate = std::move(certificate);
            upstreamOpaque_.swap(next.opaque);
            compositionScalarRoles_ = next.scalar;
            e->waited = true;
            completed_ = std::max(completed_, e->timeline);
            transport_->retired(e->timeline);
        } catch (...) {
            observeOwnerSticky(150u);
            throw;
        }
    }
    void commitOriginalSetterOnEe(const reo_gpu_upstream::CallHandle& call, uint8_t* ram,
                                  R5900Context& ctx, int32_t task) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        auto e = exactOriginalSetter(call);
        if (!e->waited || e->committed || !e->certificate || ram != configuration_.cold->ram ||
            &ctx != activeSourceContextIdentity() || ctx.pc != call->entry() ||
            task != call->task())
            throw std::invalid_argument("Setter actual EE owner was not reacquired");
        const auto raw = [&](unsigned r) {
            uint32_t v;
            std::memcpy(&v, &ctx.r[r], 4);
            return v;
        };
        uint8_t command;
        std::memcpy(&command, &ctx.r[4], 1);
        if (raw(31) != call->returnPc() || command != call->a0())
            throw std::invalid_argument("Setter original control fields changed during hold");
        auto retained = requireBoundRetainedInvocation(e);
        validateRetainedCommitOnEe(retained, call, e->timeline);
        auto next = reo_source_closure::prepareEeControlPublication(
            upstreamOpaque_, compositionScalarRoles_, e->packet);
        // These are source-certified integer controls only. No untouched FCR,
        // restored numeric lane, saved-register upper half or whole shadow copy.
        auto* destination = reinterpret_cast<uint8_t*>(&ctx);
        for (const auto& control : e->packet.control) {
            std::memcpy(destination + control.contextOffset, control.bits.data(), control.bytes);
            if (bridge_.hasContextLeaseFor(ctx))
                for (uint32_t byte = 0; byte < control.bytes; ++byte)
                    bridge_.opaqueContext_.reset(control.contextOffset + byte);
        }
        upstreamOpaque_.swap(next.opaque);
        compositionScalarRoles_ = next.scalar;
        e->committed = true;
        publishRetainedCommit(retained, e->timeline);
        setterEntries_.erase(std::remove(setterEntries_.begin(), setterEntries_.end(), e),
                             setterEntries_.end());
    }

  public:
    uint64_t newTimeline() {
        if (issued_ == std::numeric_limits<uint64_t>::max())
            throw std::overflow_error("Parent owner timeline exhausted");
        return ++issued_; // Number is assigned only to a stored genuine fence.
    }
    std::shared_ptr<Entry> find(const protocol::Key& key) const {
        for (const auto& e : entries_)
            if (protocol::same(e->queued.allocation.key, key))
                return e;
        throw std::invalid_argument("Opaque parent allocation absent from this owner registry");
    }
    Vulkan::BufferHandle hostSticky() {
        Vulkan::BufferCreateInfo c{};
        c.domain = Vulkan::BufferDomain::CachedHost;
        c.size = 4;
        c.usage = VK_BUFFER_USAGE_TRANSFER_DST_BIT;
        auto result = device_.create_buffer(c);
        if (!result)
            throw std::runtime_error("Parent scalar sticky allocation failed");
        return result;
    }
    void copySticky(Vulkan::CommandBuffer& cmd, Entry& e) {
        cmd.buffer_barrier(target_->completion(), VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                           VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                           VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
        cmd.copy_buffer(*e.stickyHost, 0, target_->completion(), 32, 4);
        cmd.buffer_barrier(*e.stickyHost, VK_PIPELINE_STAGE_TRANSFER_BIT,
                           VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_HOST_BIT,
                           VK_ACCESS_2_HOST_READ_BIT);
    }
    uint32_t actualSticky(const Entry& e) {
        const auto* p = device_.map_host_buffer(*e.stickyHost, Vulkan::MEMORY_ACCESS_READ_BIT);
        if (!p)
            throw std::runtime_error("Parent scalar sticky map failed");
        uint32_t w;
        std::memcpy(&w, p, 4);
        device_.unmap_host_buffer(*e.stickyHost, Vulkan::MEMORY_ACCESS_READ_BIT);
        return w;
    }
    protocol::Produced record(const protocol::Allocation& a,
                              const std::vector<protocol::RawPatch>& patches) override {
        requireHealthy();
        if (!viewportEntries_.empty())
            throw std::invalid_argument(
                "Parent recording cannot overtake a genuine held viewport scope");
        if (a.key.session != configuration_.session || a.key.epoch != epoch_ ||
            a.context != activeSourceContextIdentity() || a.memory != configuration_.cold->ram)
            throw std::invalid_argument(
                "Parent frontier does not belong to persistent factory identity");
        if (entries_.size() >= 4096)
            throw std::overflow_error("Parent lease registry exhausted");
        auto e = std::make_shared<Entry>();
        e->stickyHost = hostSticky();
        gs_.record_resident_command(
            [&](Vulkan::CommandBuffer& cmd) { e->queued = transport_->record(cmd, a, patches); });
        entries_.push_back(e);
        return e->queued.bridge;
    }
    uint64_t submitAndHoldGuest(const protocol::Allocation& a,
                                const protocol::Produced& p) override {
        auto e = find(a.key);
        if (e->parentFence || p.immutableGpuPayload != e->queued.bridge.immutableGpuPayload ||
            p.gpuContextLease != e->queued.bridge.gpuContextLease)
            throw std::invalid_argument("Foreign/repeated parent return receipt");
        e->parentFence = gs_.submit_resident_completion(
            [&](Vulkan::CommandBuffer& cmd) { copySticky(cmd, *e); });
        if (!e->parentFence)
            throw std::runtime_error("Actual parent submission has no fence");
        e->parentTimeline = newTimeline();
        transport_->sealed(e->parentTimeline);
        return e->parentTimeline;
    }
    void recordActualUnpack(const protocol::Produced& p, uint32_t command, uint32_t tops,
                            const std::vector<protocol::Origin>&) override {
        auto e = find(p.key);
        if (parserOperation_ || !e->parentReturned || e->token ||
            p.immutableGpuPayload != e->queued.bridge.immutableGpuPayload ||
            p.gpuContextLease != e->queued.bridge.gpuContextLease)
            throw std::invalid_argument(
                "Lease join lacks a completed same-owner source or repeats an upload");
        const auto& a = e->queued.allocation;
        reo_resident_live::LeaseUploadStamp s{a.key.session,
                                              a.key.epoch,
                                              generation_,
                                              a.key.allocation,
                                              a.key.revision,
                                              a.key.ordinal,
                                              a.packet + protocol::PayloadOffset,
                                              protocol::PayloadBytes,
                                              command,
                                              tops};
        if (!reo_resident_live::validLeaseUploadStamp(s))
            throw std::invalid_argument("Invalid exact parent UNPACK stamp");
        e->token = std::shared_ptr<const reo_resident_live::OpaqueLeaseUpload>(
            new reo_resident_live::OpaqueLeaseUpload(s, this, e->queued.lease->lifetime));
        reo_resident_live::Operation op{};
        op.kind = reo_resident_live::Kind::OpaqueLeaseUnpack;
        op.command = command;
        op.latchedTops = tops;
        op.opaqueLease = e->token;
        parserOperation_ = std::move(op);
    }
    void recordActualRawContextOverwrite(const protocol::Allocation&,
                                         const protocol::RawPatch& p) override {
        recordReviewedSourceOverwrite(p);
    }
    void recordActualRawRamOverwrite(const protocol::Allocation&,
                                     const protocol::RawPatch& p) override {
        recordReviewedSourceOverwrite(p);
    }
    void firstSticky(uint32_t reason) noexcept {
        uint32_t clean = 0;
        failed_.compare_exchange_strong(clean, reason ? reason : 99u, std::memory_order_release,
                                        std::memory_order_relaxed);
    }
    void rejectOwned(const protocol::Key&, uint32_t reason) override {
        firstSticky(reason);
    }
    void observedBypass(const protocol::Allocation&, protocol::Space, uint32_t, uint32_t,
                        uint32_t) override {
        firstSticky(99u);
    }

  public:
    static void validateDeferredConfiguration(const Configuration& c) {
        if (!c.enabled || (c.tier == protocol::AdmissionTier::ScopedLive &&
                           (!c.gates.ready() || !c.producerProofs.complete())))
            throw std::invalid_argument("Incomplete deferred first-entry parent proof scope");
    }
    static void validateConfiguration(const Configuration& c) {
        if (!c.enabled || !c.session || !c.cold || !c.cold->ram || !c.cold->spr ||
            !c.cold->actualContext || !c.cold->lifetime ||
            (c.tier == protocol::AdmissionTier::ScopedLive &&
             (!c.gates.ready() || !c.producerProofs.complete())))
            throw std::invalid_argument("Incomplete default-off parent factory source/proof scope");
    }
    Service(Vulkan::Device& d, ParallelGS::GSInterface& gs,
            std::shared_ptr<reo_resident_live::ProgramBank> target,
            reo_gpu_vif_upload::ResidentVifUnpack& unpack, const Configuration& c, uint64_t epoch,
            uint64_t generation)
        : device_(d), gs_(gs), target_(std::move(target)), configuration_(c), epoch_(epoch),
          generation_(generation), bridge_(*this, c.gates, c.tier) {
        validateConfiguration(c);
        if (!target_ || target_->deviceIdentity() != &device_ ||
            unpack.ownerDeviceIdentity() != &device_ ||
            unpack.destinationBankIdentity() != &target_->data() ||
            unpack.completionBankIdentity() != &target_->completion() || !epoch || !generation)
            throw std::invalid_argument(
                "Incomplete default-off parent installation scope/cold identity");
        const auto tier = c.tier == protocol::AdmissionTier::ScopedLive
                              ? reo_gpu_palette_parent::Tier::ScopedLive
                              : reo_gpu_palette_parent::Tier::OfflineComponent;
        const auto& captured = c.cold->capturedEntry;
        if (captured) {
            captured->requireOnOwner();
            if (captured->ramIdentity() != c.cold->ram || captured->sprIdentity() != c.cold->spr ||
                &captured->context() != c.cold->actualContext ||
                captured->contextLifetime() != c.cold->lifetime || captured->epoch() != epoch_ ||
                captured->generation() != generation_)
                throw std::invalid_argument(
                    "Parent first-entry image differs from genuine cold identities");
        }
        producer_ = std::make_unique<reo_gpu_palette_parent::Producer>(
            device_, c.producer, captured ? captured->initialRam() : c.cold->ram,
            captured ? captured->initialSpr() : c.cold->spr, *c.cold->actualContext, generation_,
            tier, c.producerProofs, captured ? captured->initialContext() : nullptr);
        producer_->bindOriginalUpstreamOwner(c.session, epoch_, this);
        if (producer_->viewportQueueHeaders_ || producer_->viewportQueueJournal_)
            viewportQueueAdapter_ = std::unique_ptr<reo_gpu_upstream::QueueControlAdapter>(
                new reo_gpu_upstream::QueueControlAdapter(this, producer_->upstreamBanks_));
        producer_->prewarmOriginalUpstream();
        transport_ = std::make_unique<protocol::Transport>(
            device_, *producer_, c.transport, target_->completion(), unpack,
            std::static_pointer_cast<const void>(target_), c.session, generation_);
    }

  private:
    void finishFirstEntryUploadOnOwner(reo_gpu_vif_upload::ResidentVifUnpack& unpack) {
        requireHealthy();
        if (!configuration_.cold->capturedEntry || firstEntryUploadFence_ || firstEntryUploaded_)
            throw std::runtime_error(
                "Cold enrollment has no unconsumed immutable authentic entry image");
        auto fence = gs_.submit_resident_completion([&](Vulkan::CommandBuffer& cmd) {
            const std::array<const Vulkan::Buffer*, 8> banks{
                &target_->state(),         &target_->data(),
                &target_->completion(),    &unpack.controls(),
                producer_->ram_.get(),     producer_->spr_.get(),
                producer_->context_.get(), producer_->completion_.get()};
            for (const auto* bank : banks)
                cmd.buffer_barrier(*bank, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                   VK_ACCESS_2_MEMORY_WRITE_BIT, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                   VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT);
        });
        if (!fence)
            throw std::runtime_error("Authentic first-entry upload has no real same-Device fence");
        fence->wait();
        configuration_.cold->capturedEntry->requireOnOwner();
        requireHealthy();
        firstEntryUploadFence_ = fence;
        firstEntryUploaded_ = configuration_.cold->capturedEntry;
        retainedSourceBanks_ = producer_->upstreamBanks_;
        retainedSourceFence_ = fence;
        retainedSourceEpoch_ = epoch_;
        retainedSourceGeneration_ = generation_;
    }
    void requireFirstEntryUploadOnOwner(const reo_parent_natural::ColdEntryHandle& capture) const {
        requireHealthy();
        if (!capture || !firstEntryUploadFence_ || firstEntryUploaded_ != capture ||
            configuration_.cold->capturedEntry != capture || capture->epoch() != epoch_ ||
            capture->generation() != generation_)
            throw std::invalid_argument(
                "First-entry history requires this actual same-Device upload fence/capture");
        capture->requireOnOwner();
    }
#include "../upstream/retained_invocation_service.inl"
    bool hasOriginalPerspective() const noexcept {
        return bool(producer_->perspective18F710_);
    }
    reo_gpu_upstream::CallHandle prepareOriginalPerspectiveOnEe(uint8_t* ram, R5900Context& ctx,
                                                                int32_t task) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        if (!compositionEntries_.empty())
            throw std::invalid_argument("Upstream call cannot overtake actual composition return");
        for (const auto& entry : setterEntries_)
            if (!entry->committed)
                throw std::invalid_argument("Upstream call cannot overtake setter receipt");
        if (!hasOriginalPerspective() || !viewportEntries_.empty() ||
            ram != configuration_.cold->ram || &ctx != activeSourceContextIdentity() ||
            !reo_gpu_upstream::Perspective18F710::supports(ctx.pc) || task < 1 ||
            !perspectiveEntries_.empty() || !matrixEntries_.empty() ||
            upstreamOrdinal_ == UINT64_MAX)
            throw std::invalid_argument("Not this actual perspective EE entry/task");
        const auto raw = [&](unsigned r) {
            uint32_t v;
            std::memcpy(&v, &ctx.r[r], 4);
            return v;
        };
        const auto controls = reo_gpu_upstream::perspectiveIntegerControls(ctx.pc);
        // Read only actual CPU-owned integer call controls; all numerical
        // operands and stack calculations remain in the resident GPU banks.
        if (controls & reo_gpu_upstream::ReturnPC)
            guardKnownContextRead(ctx, 31u * 16u, 4u);
        if (controls & reo_gpu_upstream::A0)
            guardKnownContextRead(ctx, 4u * 16u, 4u);
        if (controls & reo_gpu_upstream::A1)
            guardKnownContextRead(ctx, 5u * 16u, 4u);
        if (controls & reo_gpu_upstream::A2)
            guardKnownContextRead(ctx, 6u * 16u, 4u);
        auto call = std::shared_ptr<const reo_gpu_upstream::Call>(new reo_gpu_upstream::Call(
            this, {configuration_.session, epoch_, generation_, upstreamOrdinal_ + 1}, ctx.pc,
            controls & reo_gpu_upstream::ReturnPC ? raw(31) : 0u,
            controls & reo_gpu_upstream::A0 ? raw(4) : 0u,
            controls & reo_gpu_upstream::A1 ? raw(5) : 0u,
            controls & reo_gpu_upstream::A2 ? raw(6) : 0u, task));
        auto entry = std::make_shared<PerspectiveEntry>();
        entry->call = call;
        perspectiveEntries_.push_back(entry);
        upstreamOrdinal_ = call->stamp().ordinal;
        if (controls & reo_gpu_upstream::ReturnPC)
            for (uint32_t b = 0; b < 4; ++b)
                compositionScalarRoles_[31u * 16u + b] = 3;
        for (unsigned r = 4; r <= 6; ++r)
            if (controls & (1u << (r - 3)))
                for (uint32_t b = 0; b < 4; ++b)
                    compositionScalarRoles_[r * 16u + b] = 5;
        return call;
    }
    std::shared_ptr<PerspectiveEntry>
    exactOriginalPerspective(const reo_gpu_upstream::CallHandle& call) const {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        if (!call || call->issuer() != this || call->stamp().session != configuration_.session ||
            call->stamp().epoch != epoch_ || call->stamp().bankGeneration != generation_)
            throw std::invalid_argument("Foreign/stale original perspective call");
        for (const auto& entry : perspectiveEntries_)
            if (entry->call == call)
                return entry;
        throw std::invalid_argument("Perspective call was never issued by actual EE frontier");
    }
    void recordOriginalPerspectiveOnOwner(const reo_gpu_upstream::CallHandle& call,
                                          const std::vector<protocol::RawPatch>& patches) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        auto entry = exactOriginalPerspective(call);
        (void)requireBoundRetainedInvocation(entry);
        if (entry->output || entry->fence || entry->waiting || entry->waited || entry->committed)
            throw std::invalid_argument("Repeated original perspective recording");
        try {
            producer_->verifyOriginalUpstreamOrder(call); // Before any staged RAW overwrite.

            Vulkan::BufferCreateInfo ci{};
            ci.domain = Vulkan::BufferDomain::CachedHost;
            ci.size = reo_gpu_upstream::ReceiptBytes;
            ci.usage = VK_BUFFER_USAGE_TRANSFER_DST_BIT;
            entry->host = device_.create_buffer(ci);
            ci.size = reo_gpu_upstream::PerspectiveEffectsBytes;
            entry->hostEffects = device_.create_buffer(ci);
            if (!entry->host || !entry->hostEffects)
                throw std::runtime_error("Perspective integer metadata allocation failed");
            gs_.record_resident_command([&](Vulkan::CommandBuffer& cmd) {
                for (const auto& patch : patches)
                    producer_->bridgeSourceWrite(cmd, patch);
                entry->output = producer_->recordOriginalPerspective(cmd, call);
            });
            entry->fence = gs_.submit_resident_completion([&](Vulkan::CommandBuffer& cmd) {
                const auto copy = [&](const Vulkan::Buffer& src, const Vulkan::Buffer& dst) {
                    cmd.buffer_barrier(src, VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT,
                                       VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                                       VK_PIPELINE_STAGE_2_TRANSFER_BIT,
                                       VK_ACCESS_2_TRANSFER_READ_BIT);
                    cmd.copy_buffer(dst, src);
                    cmd.buffer_barrier(dst, VK_PIPELINE_STAGE_2_TRANSFER_BIT,
                                       VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_2_HOST_BIT,
                                       VK_ACCESS_2_HOST_READ_BIT);
                };
                copy(entry->output->receipt(), *entry->host);
                copy(entry->output->effects(), *entry->hostEffects);
            });
            if (!entry->fence)
                throw std::runtime_error("Perspective has no genuine owner receipt fence");
            entry->timeline = newTimeline();
            transport_->sealed(entry->timeline);
        } catch (...) {
            observeOwnerSticky(142u);
            throw;
        }
    }
    void waitOriginalPerspectiveOnOwner(const reo_gpu_upstream::CallHandle& call) {
        std::unique_lock<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        auto entry = exactOriginalPerspective(call);
        if (!entry->output || !entry->fence || entry->waiting || entry->waited || entry->committed)
            throw std::invalid_argument("No new perspective owner return");
        entry->waiting = true;
        auto fence = entry->fence;
        lock.unlock();
        try {
            fence->wait();
            lock.lock();
            requireHealthy();
            exactOriginalPerspective(call);
            const auto* memory =
                device_.map_host_buffer(*entry->host, Vulkan::MEMORY_ACCESS_READ_BIT);
            if (!memory)
                throw std::runtime_error("Perspective integer receipt map failed");
            std::memcpy(entry->receipt.data(), memory, reo_gpu_upstream::ReceiptBytes);
            device_.unmap_host_buffer(*entry->host, Vulkan::MEMORY_ACCESS_READ_BIT);
            std::vector<uint32_t> words(reo_gpu_upstream::PerspectiveEffectsWords);
            const auto* metadata =
                device_.map_host_buffer(*entry->hostEffects, Vulkan::MEMORY_ACCESS_READ_BIT);
            if (!metadata)
                throw std::runtime_error("Perspective effects map failed");
            std::memcpy(words.data(), metadata, reo_gpu_upstream::PerspectiveEffectsBytes);
            device_.unmap_host_buffer(*entry->hostEffects, Vulkan::MEMORY_ACCESS_READ_BIT);
            auto packet = reo_gpu_upstream::decodePerspectiveEffects(*call, entry->receipt, words);
            auto next = reo_source_closure::prepareGpuEffects(upstreamOpaque_,
                                                              compositionScalarRoles_, packet);
            auto certified = std::shared_ptr<const reo_source_closure::CertifiedEffects>(
                new reo_source_closure::CertifiedEffects(
                    this, entry->output->banks(), call, entry->output->effectsHandle(),
                    entry->timeline, packet.header, packet.dirty, packet.control));
            entry->packet = std::move(packet);
            entry->certificate = std::move(certified);
            upstreamOpaque_.swap(next.opaque);
            compositionScalarRoles_ = next.scalar;
            entry->waiting = false;
            entry->waited = true;
            completed_ = std::max(completed_, entry->timeline);
            transport_->retired(entry->timeline);
        } catch (...) {
            if (!lock.owns_lock())
                lock.lock();
            entry->waiting = false;
            observeOwnerSticky(143u);
            throw;
        }
    }
    void commitOriginalPerspectiveOnEe(const reo_gpu_upstream::CallHandle& call, uint8_t* ram,
                                       R5900Context& ctx, int32_t task) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        auto entry = exactOriginalPerspective(call);
        if (!entry->waited || entry->waiting || entry->committed || !entry->certificate ||
            ram != configuration_.cold->ram || &ctx != activeSourceContextIdentity() ||
            task != call->task() || ctx.pc != call->entry())
            throw std::invalid_argument(
                "Perspective control return lost reacquired actual EE owner");
        const auto raw = [&](unsigned r) {
            uint32_t v;
            std::memcpy(&v, &ctx.r[r], 4);
            return v;
        };
        const auto controls = reo_gpu_upstream::perspectiveIntegerControls(call->entry());
        if (((controls & reo_gpu_upstream::ReturnPC) && raw(31) != call->returnPc()) ||
            ((controls & reo_gpu_upstream::A0) && raw(4) != call->a0()) ||
            ((controls & reo_gpu_upstream::A1) && raw(5) != call->a1()) ||
            ((controls & reo_gpu_upstream::A2) && raw(6) != call->a2()))
            throw std::invalid_argument(
                "Perspective integer call fields changed before true return");
        auto retained = requireBoundRetainedInvocation(entry);
        validateRetainedCommitOnEe(retained, call, entry->timeline);
        auto next = reo_source_closure::prepareEeControlPublication(
            upstreamOpaque_, compositionScalarRoles_, entry->packet);
        auto* target = reinterpret_cast<uint8_t*>(&ctx);
        for (const auto& control : entry->packet.control)
            std::memcpy(target + control.contextOffset, control.bits.data(), control.bytes);
        upstreamOpaque_.swap(next.opaque);
        compositionScalarRoles_ = next.scalar;
        entry->committed = true;
        publishRetainedCommit(retained, entry->timeline);
        perspectiveEntries_.erase(
            std::remove(perspectiveEntries_.begin(), perspectiveEntries_.end(), entry),
            perspectiveEntries_.end());
    }

  private:
  private:
    void wakeActualIrqReservationWaiters() {
        // Protocol mutation occurs before this call. Waiters never acquire
        // protocol while holding waitMutex: revision is the sole predicate.
        {
            std::lock_guard<std::mutex> waitLock(irqReservationWaitMutex_);
            irqReservationRevision_.fetch_add(1, std::memory_order_release);
        }
        irqReservationChanged_.notify_all();
    }
    std::vector<const void*> actualIrqRegistryIdentity() const {
        std::vector<const void*> ids;
        const auto add = [&](const auto& table) {
            for (const auto& e : table)
                ids.push_back(e.get());
        };
        add(entries_);
        add(matrixEntries_);
        add(perspectiveEntries_);
        add(setterEntries_);
        add(compositionEntries_);
        add(viewportEntries_);
        add(allocatorEntries_);
        add(queueEntries_);
        return ids;
    }
    void requireActualIrqRetiredHeldPrefix(const std::shared_ptr<IrqContextPause>& pause) const {
        if (!pause || pause->issuer_ != this || pause->closed_ || pause->epoch_ != epoch_ ||
            pause->contextRevision_ != activeContextRevision_ ||
            pause->caller_ != activeSourceContextIdentity() ||
            pause->savedBanks_ != producer_->upstreamBanks_ ||
            pause->upstreamCut_ != upstreamOrdinal_ ||
            pause->registryIdentity_ != actualIrqRegistryIdentity() || parserOperation_)
            throw std::invalid_argument("IRQ pause lost exact caller/banks/source registry prefix");
        // A held normal viewport queue/frontier is an active protected lease,
        // not a completed scalar-return object. IRQ may not consume its queue
        // counters while an earlier source plan owns them. This precise scope
        // waits for main publication; no synthetic lease transfer is admitted.
        if (!allocatorEntries_.empty() || !queueEntries_.empty())
            throw std::runtime_error("IRQ pause cannot borrow an outstanding protected "
                                     "allocator/queue control transaction");
        for (const auto& e : entries_) {
            if (!e->parentFence || !e->parentTimeline || e->parentTimeline > completed_ ||
                !e->returnTicket)
                throw std::runtime_error("IRQ pause preceded genuinely completed parent T1");
            if (e->recorded &&
                (!e->uploadFence || !e->uploadTimeline || e->uploadTimeline > completed_))
                throw std::runtime_error("IRQ pause preceded actual recorded upload completion");
        }
        const auto scalar = [&](const auto& table) {
            for (const auto& e : table)
                if (!e->output || !e->fence || !e->timeline || !e->waited ||
                    e->timeline > completed_ || e->receipt[0])
                    throw std::runtime_error(
                        "IRQ pause preceded actual scalar profile receipt validation");
        };
        scalar(matrixEntries_);
        scalar(perspectiveEntries_);
        for (const auto& e : setterEntries_)
            if (!e->output || !e->fence || !e->timeline || !e->waited || e->timeline > completed_ ||
                e->words[0])
                throw std::runtime_error("IRQ pause preceded actual setter control validation");
        for (const auto& e : compositionEntries_)
            if (!e->output || !e->fence || !e->timeline || !e->waited || e->waiting ||
                !e->certificate || e->timeline > completed_ || e->receipt[0])
                throw std::runtime_error(
                    "IRQ pause preceded actual composition/effects validation");
        for (const auto& e : viewportEntries_)
            if (!e->output || !e->fence || !e->timeline || !e->waited || e->waiting ||
                e->controlHeld || e->timeline > completed_ || e->receipt[0] ||
                e->receipt[3] != 1u || (e->heapFrontier && !e->heapFrontierReleased) ||
                (e->queueCapture && !e->committed))
                throw std::runtime_error(
                    "IRQ pause preceded final released viewport control frontier");
    }
    std::shared_ptr<IrqContextPause> exactActualIrqPause(const IrqContextPauseHandle& pause) const {
        if (!pause || pause->issuer_ != this || irqPauses_.empty() ||
            irqPauses_.back().get() != pause.get() || pause->closed_)
            throw std::invalid_argument(
                "IRQ pause reservation is foreign, retired or not the actual top frame");
        return irqPauses_.back();
    }
    IrqContextPauseHandle
    prepareActualIrqContextPauseOnEe(const reo_parent_natural::IrqInitializerHandle& init) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        if (!init || !irqPauses_.empty() || activeCallbackLoanDepth() != 0u ||
            irqPauseOrdinal_ == UINT64_MAX || !producer_->upstreamBanks_)
            throw std::invalid_argument(
                "IRQ pause cannot invent/reenter a Context loan or exhaust identity");
        init->validateBeforeAnyIrqInstructionOnEe();
        auto* caller = activeSourceContextIdentity();
        auto lifetime = activeSourceContextLifetime();
        if (caller == &init->context() || !reo_parent_natural::matchesActualGuestContextStorage(
                                              init->runtime(), *caller, lifetime))
            throw std::invalid_argument("IRQ pause lacks genuine distinct caller lifetime");
        auto p = std::shared_ptr<IrqContextPause>(new IrqContextPause(
            this, &init->runtime(), caller, std::move(lifetime), init, producer_->upstreamBanks_,
            epoch_, activeContextRevision_, upstreamOrdinal_, irqPauseOrdinal_ + 1u));
        p->registryIdentity_ = actualIrqRegistryIdentity();
        const auto hold = [&](const auto& table) {
            for (const auto& e : table)
                p->heldEntries_.push_back(std::static_pointer_cast<const void>(e));
        };
        hold(entries_);
        hold(matrixEntries_);
        hold(perspectiveEntries_);
        hold(setterEntries_);
        hold(compositionEntries_);
        hold(viewportEntries_);
        hold(allocatorEntries_);
        hold(queueEntries_);
        // All allocations and source-state checks precede reservation. Main
        // commit dispatches must wait outside guest/source/protocol/IO locks.
        requireActualIrqRetiredHeldPrefix(p);
        irqPauses_.push_back(p);
        ++irqPauseOrdinal_;
        return p;
    }
    void recordActualIrqContextPauseOnOwner(const IrqContextPauseHandle& token) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        auto p = exactActualIrqPause(token);
        requireActualIrqRetiredHeldPrefix(p);
        if (p->recorded_ || p->waiting_ || p->waited_ || p->freshIssued_)
            throw std::invalid_argument("IRQ pause owner barrier repeats");
        try {
            // GS FIFO admission already ordered every earlier source command.
            // This is a real submission fence, never an early STR/completion.
            p->fence_ = gs_.submit_resident_completion([](Vulkan::CommandBuffer&) {});
            if (!p->fence_)
                throw std::runtime_error("IRQ pause lacks actual GS prefix fence");
            p->timeline_ = newTimeline();
            transport_->sealed(p->timeline_);
            p->recorded_ = true;
        } catch (...) {
            observeOwnerSticky(181u);
            throw;
        }
    }
    void waitActualIrqContextPauseOnOwner(const IrqContextPauseHandle& token) {
        std::unique_lock<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        auto p = exactActualIrqPause(token);
        requireActualIrqRetiredHeldPrefix(p);
        if (!p->recorded_ || !p->fence_ || !p->timeline_ || p->waiting_ || p->waited_ ||
            p->freshIssued_)
            throw std::invalid_argument("IRQ pause lacks new real source prefix");
        p->waiting_ = true;
        auto fence = p->fence_;
        lock.unlock();
        try {
            fence->wait();
            lock.lock();
            requireHealthy();
            if (exactActualIrqPause(token) != p)
                throw std::runtime_error("IRQ pause lifetime changed while fence waited");
            requireActualIrqRetiredHeldPrefix(p);
            transport_->retired(p->timeline_);
            completed_ = std::max(completed_, p->timeline_);
            p->retiredPrefix_ = p->timeline_;
            p->waiting_ = false;
            p->waited_ = true;
        } catch (...) {
            if (!lock.owns_lock())
                lock.lock();
            p->waiting_ = false;
            observeOwnerSticky(182u);
            wakeActualIrqReservationWaiters();
            throw;
        }
    }
    // Generic fresh Context receiver calls only after its actual final close
    // fence and exact saved caller Banks/Context policy have been restored.
    void closeActualIrqContextPauseAfterRestore(const IrqContextPauseHandle& token) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        auto p = exactActualIrqPause(token);
        if (!p->waited_ || p->waiting_ || !p->freshIssued_ || !p->retiredPrefix_ ||
            producer_->upstreamBanks_ != p->savedBanks_ ||
            activeSourceContextIdentity() != p->caller_ ||
            !reo_parent_natural::matchesActualGuestContextStorage(*p->runtime_, *p->caller_,
                                                                  p->callerLifetime_))
            throw std::invalid_argument(
                "IRQ reservation ended before exact real Context restoration");
        p->closed_ = true;
        irqPauses_.pop_back();
        wakeActualIrqReservationWaiters();
    }
    void requireNoActualIrqReservationForContext(const R5900Context& ctx) const {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        for (const auto& p : irqPauses_)
            if (!p->closed_ && p->caller_ == &ctx)
                throw std::runtime_error(
                    "Main EE return remains held through actual IRQ Context reservation");
    }

  public:
    void waitForActualIrqReservationOnEe(PS2Runtime& runtime, R5900Context& ctx) {
        const auto task = ps2_sched::currentThread();
        if (reo_parent_natural::currentRuntime() != &runtime ||
            reo_parent_natural::currentContext() != &ctx ||
            !ps2ActualGuestExecutionDepth(&runtime) || ps2IoRegLockDepth() != 0u)
            throw std::invalid_argument(
                "IRQ reservation wait lacks genuine unlocked guest/context task");
        for (;;) {
            std::shared_ptr<IrqContextPause> held;
            uint64_t revision = 0;
            {
                std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
                requireHealthy();
                for (const auto& p : irqPauses_)
                    if (!p->closed_ && p->caller_ == &ctx) {
                        held = p;
                        break;
                    }
                revision = irqReservationRevision_.load(std::memory_order_acquire);
            }
            if (!held)
                return;
            // The mutex here is only the notification mutex. No source,
            // protocol or I/O lock may surround this actual guest release.
            {
                PS2Runtime::GuestExecutionReleaseScope release(&runtime);
                std::unique_lock<std::mutex> waitLock(irqReservationWaitMutex_);
                irqReservationChanged_.wait_for(waitLock, std::chrono::milliseconds(10), [&] {
                    return irqReservationRevision_.load(std::memory_order_acquire) != revision ||
                           failed_.load(std::memory_order_acquire) || runtime.isStopRequested();
                });
            }
            if (runtime.isStopRequested() || ps2_sched::currentThread() != task ||
                reo_parent_natural::currentRuntime() != &runtime ||
                reo_parent_natural::currentContext() != &ctx)
                throw std::runtime_error(
                    "Main return lost actual guest/context ownership after IRQ reservation");
        }
    }

  private:
    bool isActualTaskZeroIrqContext(const R5900Context& ctx) const noexcept {
        try {
            std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
            for (const auto& e : callbacks_)
                if (!e->closed && e->freshInitializer && e->task == 0 && e->storage->get() == &ctx)
                    return true;
        } catch (...) {
            return false;
        }
        return false;
    }
    R5900Context* actualPausedMainContextIdentity() const noexcept {
        return pausedMainContext_.load(std::memory_order_acquire);
    }
    std::shared_ptr<CallbackEntry>
    prepareFreshIrqContextOnEe(const reo_parent_natural::IrqInitializerHandle& initializer,
                               const IrqContextPauseHandle& pause) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        auto p = exactActualIrqPause(pause);
        if (!initializer || p->initializer_ != initializer || !p->waited_ || p->waiting_ ||
            p->freshIssued_ || p->closed_ || !p->fence_ || !p->timeline_ || !p->retiredPrefix_ ||
            p->retiredPrefix_ > completed_ || p->epoch_ != epoch_ ||
            p->contextRevision_ != activeContextRevision_ ||
            p->caller_ != activeSourceContextIdentity() ||
            p->savedBanks_ != producer_->upstreamBanks_ || !callbacks_.empty() ||
            upstreamOrdinal_ == UINT64_MAX || activeContextRevision_ == UINT64_MAX)
            throw std::invalid_argument(
                "Fresh Context lacks exact retired main pause/initializer source");
        initializer->validateBeforeAnyIrqInstructionOnEe();
        requireActualIrqRetiredHeldPrefix(p);
        if (initializer->task() < 0 || &initializer->runtime() != p->runtime_ ||
            &initializer->context() == p->caller_ ||
            !reo_parent_natural::matchesActualGuestContextStorage(*p->runtime_, *p->caller_,
                                                                  p->callerLifetime_))
            throw std::invalid_argument(
                "Fresh IRQ frame changed real caller/initializer runtime/lifetime");
        auto e = std::make_shared<CallbackEntry>();
        e->issuer = this;
        e->caller = p->caller_;
        e->callerLifetime = p->callerLifetime_;
        e->freshInitializer = initializer;
        e->irqPause = pause;
        e->storage = initializer->storage();
        e->lifetime = reo_parent_natural::retainActualGuestContextStorage(initializer->runtime(),
                                                                          initializer->context());
        e->task = initializer->task();
        e->controls.entry = initializer->handler();
        e->controls.returnSentinel = 0;
        e->bridgeLoan =
            bridge_.prepareValidatedFreshContextLoan(*e->caller, *e->storage->get(), e->task);
        e->callerRoles = compositionScalarRoles_;
        for (const auto& r : upstreamOpaque_)
            if (r.space == protocol::Space::Context)
                e->callerContextOpaque.push_back(r);
        // Only the exact source initializer's authored integer controls get
        // roles. Its literal-zero/VF0 bytes are CPU-owned input, not RAW proof.
        const auto scalar = [&](uint32_t at, uint32_t bytes, uint8_t role) {
            for (uint32_t b = 0; b < bytes; ++b)
                e->childRoles[at + b] = role;
        };
        scalar(28u * 16u, 8u, 5);
        scalar(29u * 16u, 8u, 6);
        scalar(31u * 16u, 8u, 3);
        for (uint32_t r = 4; r < 8; ++r)
            scalar(r * 16u, 8u, 7);
        scalar(uint32_t(offsetof(R5900Context, pc)), 4u, 3);
        e->forkOrdinal = upstreamOrdinal_ + 1;
        callbacks_.push_back(e);
        upstreamOrdinal_ = e->forkOrdinal;
        p->freshIssued_ = true;
        return e;
    }
    void exactFreshIrqFrame(const std::shared_ptr<CallbackEntry>& e) const {
        exactCallback(e);
        auto p = exactActualIrqPause(e->irqPause);
        if (!e->freshInitializer || p->initializer_ != e->freshInitializer || !p->waited_ ||
            !p->freshIssued_ || p->closed_ || p->caller_ != e->caller ||
            p->savedBanks_ != e->callerImage->banks_)
            throw std::invalid_argument(
                "Fresh IRQ frame lost immutable caller image/pause association");
    }
    void recordFreshIrqContextOnOwner(const std::shared_ptr<CallbackEntry>& e) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        exactCallback(e);
        auto p = exactActualIrqPause(e->irqPause);
        if (!e->freshInitializer || p->initializer_ != e->freshInitializer || !p->freshIssued_ ||
            !p->waited_ || p->closed_ || p->savedBanks_ != producer_->upstreamBanks_ ||
            e->recorded || e->forkFence)
            throw std::invalid_argument(
                "Fresh IRQ frame cannot record without its exact first pause");
        try {
            auto next = upstreamOpaque_;
            next.erase(
                std::remove_if(next.begin(), next.end(),
                               [](const auto& r) { return r.space == protocol::Space::Context; }),
                next.end());
            gs_.record_resident_command([&](Vulkan::CommandBuffer& cmd) {
                e->callerImage = producer_->retainActualContextImage(e->caller);
                // Only source-issued fresh bytes are uploaded. The main CPU
                // Context and every opaque parent numerical lane stay untouched.
                R5900Context initial{};
                std::memcpy(&initial, e->freshInitializer->certifiedInitialImage().data(),
                            sizeof(initial));
                e->childImage = producer_->recordFreshActualContextImage(
                    cmd, initial, e->storage->get(), e->forkOrdinal);
            });
            bridge_.activateValidatedFreshContextLoan(e->bridgeLoan, e->task);
            upstreamOpaque_.swap(next);
            compositionScalarRoles_ = e->childRoles;
            generation_ = producer_->bankGeneration_;
            e->recorded = true;
            pausedMainContext_.store(e->caller, std::memory_order_release);
            callbackActiveContext_.store(e->storage->get(), std::memory_order_release);
            ++activeContextRevision_;
            e->forkFence = gs_.submit_resident_completion([](Vulkan::CommandBuffer&) {});
            if (!e->forkFence)
                throw std::runtime_error("Fresh IRQ Context lacks genuine fork fence");
            e->forkTimeline = newTimeline();
            transport_->sealed(e->forkTimeline);
        } catch (...) {
            observeOwnerSticky(174u);
            throw;
        }
    }
    void waitFreshIrqContextOnOwner(const std::shared_ptr<CallbackEntry>& e) {
        // Same real-fence discipline as RPC; main retained entries are not
        // removed or falsely committed while the fresh child becomes active.
        waitOriginalRpcForkOnOwner(e);
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        exactFreshIrqFrame(e);
    }
    void recordFreshIrqReturnOnOwner(const std::shared_ptr<CallbackEntry>& e,
                                     const std::vector<protocol::RawPatch>& ingress) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        exactFreshIrqFrame(e);
        if (!e->waited || e->closeFence || upstreamOrdinal_ == UINT64_MAX)
            throw std::invalid_argument("Fresh IRQ return lacks actual first retirement");
        producer_->requireContextMathRetired();
        e->closeOrdinal = upstreamOrdinal_ + 1;
        upstreamOrdinal_ = e->closeOrdinal;
        try {
            gs_.record_resident_command([&](Vulkan::CommandBuffer& cmd) {
                for (const auto& patch : ingress)
                    if (!(patch.kind == protocol::SourcePatchKind::IrqIntegerControl &&
                          patch.range.space == protocol::Space::Ram))
                        producer_->bridgeSourceWrite(cmd, patch);
            });
            e->closeFence = gs_.submit_resident_completion([](Vulkan::CommandBuffer&) {});
            if (!e->closeFence)
                throw std::runtime_error("Fresh IRQ return requires its genuine final fence");
            e->closeTimeline = newTimeline();
            transport_->sealed(e->closeTimeline);
        } catch (...) {
            observeOwnerSticky(175u);
            throw;
        }
    }
    void waitAndRestoreFreshIrqOnOwner(const std::shared_ptr<CallbackEntry>& e) {
        std::unique_lock<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        exactFreshIrqFrame(e);
        if (!e->closeFence || !e->closeTimeline)
            throw std::invalid_argument("Fresh IRQ restore lacks actual close submission");
        auto fence = e->closeFence;
        lock.unlock();
        try {
            fence->wait();
            lock.lock();
            requireHealthy();
            exactFreshIrqFrame(e);
            transport_->retired(e->closeTimeline);
            completed_ = std::max(completed_, e->closeTimeline);
            auto childPolicy = prepareRetiredContextPolicy(e);
            auto next = upstreamOpaque_;
            next.erase(
                std::remove_if(next.begin(), next.end(),
                               [](const auto& r) { return r.space == protocol::Space::Context; }),
                next.end());
            next.insert(next.end(), e->callerContextOpaque.begin(), e->callerContextOpaque.end());
            reo_source_closure::normalizeOpaque(next);
            producer_->bindActualContextImage(e->callerImage, e->closeOrdinal);
            bridge_.restoreValidatedFreshContextLoan(e->bridgeLoan);
            generation_ = producer_->bankGeneration_;
            upstreamOpaque_.swap(next);
            compositionScalarRoles_ = e->callerRoles;
            callbackActiveContext_.store(e->caller, std::memory_order_release);
            pausedMainContext_.store(nullptr, std::memory_order_release);
            e->closed = true;
            callbacks_.pop_back();
            ++activeContextRevision_;
            retiredContextPolicies_.push_back(std::move(childPolicy));
            // Opens main publication only after exact saved-bank restoration.
            closeActualIrqContextPauseAfterRestore(e->irqPause);
        } catch (...) {
            if (!lock.owns_lock())
                lock.lock();
            observeOwnerSticky(176u);
            throw;
        }
    }
    struct RetiredContextPolicy {
        R5900Context* context = nullptr;
        std::shared_ptr<const void> lifetime;
        reo_gpu_palette_parent::Producer::ContextImageHandle image;
        std::vector<protocol::Range> opaque;
        std::bitset<1648> bridgeOpaque;
    };
    std::vector<RetiredContextPolicy> retiredContextPolicies_;
    RetiredContextPolicy prepareRetiredContextPolicy(const std::shared_ptr<CallbackEntry>& e) {
        if (retiredContextPolicies_.size() >= 4096u)
            throw std::runtime_error("Retained Context policy capacity exhausted before restore");
        retiredContextPolicies_.reserve(retiredContextPolicies_.size() + 1);
        RetiredContextPolicy policy;
        policy.context = e->storage->get();
        policy.lifetime = e->lifetime;
        policy.image = e->childImage;
        for (const auto& range : upstreamOpaque_)
            if (range.space == protocol::Space::Context)
                policy.opaque.push_back(range);
        if (bridge_.hasContextLeaseFor(*policy.context))
            policy.bridgeOpaque = bridge_.opaqueContext_;
        return policy;
    }
    void guardRetiredContextRead(const R5900Context& ctx, uint32_t at, uint32_t bytes) const {
        for (const auto& policy : retiredContextPolicies_)
            if (policy.context == &ctx) {
                for (const auto& range : policy.opaque)
                    if (protocol::overlap(at, bytes, range.address, range.bytes))
                        throw std::runtime_error(
                            "Retired Context numerical bytes retain their actual GPU image lease");
                for (uint32_t b = 0; b < bytes; ++b)
                    if (policy.bridgeOpaque.test(at + b))
                        throw std::runtime_error(
                            "Retired Context parent bytes retain their opaque GPU lease");
            }
    }
    bool observeRetiredContextEnd(const R5900Context& ctx) noexcept {
        try {
            std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
            auto before = retiredContextPolicies_.size();
            retiredContextPolicies_.erase(
                std::remove_if(retiredContextPolicies_.begin(), retiredContextPolicies_.end(),
                               [&](const auto& p) { return p.context == &ctx; }),
                retiredContextPolicies_.end());
            return before != retiredContextPolicies_.size();
        } catch (...) {
            return false;
        }
    }

    R5900Context* activeSourceContextIdentity() const noexcept {
        auto* active = callbackActiveContext_.load(std::memory_order_acquire);
        return active ? active : configuration_.cold->actualContext;
    }
    std::shared_ptr<const void> activeSourceContextLifetime() const {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        for (auto i = callbacks_.rbegin(); i != callbacks_.rend(); ++i)
            if ((*i)->recorded && !(*i)->closed)
                return (*i)->lifetime;
        return configuration_.cold->lifetime;
    }
    void requireCallbackQuiescence() const {
        requireHealthy();
        if (!entries_.empty() || parserOperation_ || !queueEntries_.empty() ||
            !viewportEntries_.empty() || !allocatorEntries_.empty() || !matrixEntries_.empty() ||
            !perspectiveEntries_.empty() || !setterEntries_.empty() || !compositionEntries_.empty())
            throw std::runtime_error(
                "Callback Context handoff overtook a real source/control/upload prefix");
    }
    bool isFrozenCallbackCaller(const R5900Context& ctx) const {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        for (const auto& e : callbacks_)
            if (!e->closed && e->caller == &ctx)
                return true;
        for (const auto& p : retiredContextPolicies_)
            if (p.context == &ctx)
                return true;
        return false;
    }
    void guardSavedCallbackContextRead(const R5900Context& ctx, uint32_t at, uint32_t bytes) const {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        guardRetiredContextRead(ctx, at, bytes);
        for (auto i = callbacks_.rbegin(); i != callbacks_.rend(); ++i) {
            const auto& e = **i;
            if (e.caller != &ctx || e.closed)
                continue;
            if (e.freshInitializer && e.mainHeldT1)
                throw std::runtime_error(
                    "Parked main Context remains wholly held through genuine IRQ reservation");
            for (const auto& range : e.callerContextOpaque)
                if (protocol::overlap(at, bytes, range.address, range.bytes))
                    throw std::runtime_error(
                        "Saved caller Context bytes remain GPU-owned through callback");
            for (uint32_t b = 0; b < bytes; ++b)
                if (e.bridgeLoan.contextLeaseActive && e.bridgeLoan.opaque.test(at + b))
                    throw std::runtime_error(
                        "Saved parent caller Context lease remains opaque through callback");
            return;
        }
    }
    std::vector<protocol::Range> prepareTypedContextControlTransition(const R5900Context& ctx,
                                                                      uint32_t at,
                                                                      uint32_t bytes) const {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        if (&ctx != activeSourceContextIdentity() || !bytes || at >= 1648u || bytes > 1648u - at)
            throw std::invalid_argument(
                "Scalar transition belongs to a foreign or unbounded Context");
        // Construct this exact interval split before the real CPU store. The
        // operand-role check has already certified the original scalar source;
        // a blind overwrite does not inspect an old opaque destination.
        return reo_source_closure::subtractOpaque(upstreamOpaque_,
                                                  {protocol::Space::Context, at, bytes});
    }
    void completeTypedContextControlTransition(const R5900Context& ctx, uint32_t at, uint32_t bytes,
                                               uint8_t role,
                                               std::vector<protocol::Range>& prepared) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        if (&ctx != activeSourceContextIdentity() || !bytes || at >= 1648u || bytes > 1648u - at ||
            (role != 0u && (role < 3u || role > 7u)))
            throw std::invalid_argument("Completed scalar transition lost actual Context role");
        // No allocation, numeric comparison, upper-lane copy or RAW credit.
        upstreamOpaque_.swap(prepared);
        if (bridge_.hasContextLeaseFor(ctx))
            for (uint32_t byte = 0; byte < bytes; ++byte)
                bridge_.opaqueContext_.reset(at + byte);
        for (uint32_t byte = 0; byte < bytes; ++byte)
            compositionScalarRoles_[at + byte] = role;
    }
    std::shared_ptr<CallbackEntry> prepareOriginalRpcCallbackOnEe(
        PS2Runtime& runtime, R5900Context& caller,
        std::shared_ptr<reo_parent_natural::GuestContextStorage> storage,
        std::shared_ptr<const void> lifetime,
        const reo_parent_natural::RpcCallbackInvocationHandle& invocation, int32_t task) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireCallbackQuiescence();
        if (!invocation || &invocation->runtime() != &runtime || &invocation->caller() != &caller)
            throw std::invalid_argument(
                "RPC source event was not issued by the real original helper");
        invocation->validateBeforeActualForkOnEe();
        const auto& controls = invocation->controls();
        if (&caller != activeSourceContextIdentity() || !storage || !lifetime || task < 1 ||
            task != ps2_sched::currentThread() || !runtime.hasFunction(controls.entry) ||
            controls.returnSentinel != 0x00fff000u || callbacks_.size() >= 16 ||
            upstreamOrdinal_ == UINT64_MAX || activeContextRevision_ == UINT64_MAX ||
            !reo_parent_natural::matchesActualGuestContextStorage(runtime, caller,
                                                                  activeSourceContextLifetime()) ||
            !reo_parent_natural::matchesActualGuestContextStorage(runtime, *storage->get(),
                                                                  lifetime))
            throw std::invalid_argument(
                "Callback is not a genuine same-task caller/child lifetime");
        auto e = std::make_shared<CallbackEntry>();
        e->issuer = this;
        e->caller = &caller;
        e->callerLifetime = activeSourceContextLifetime();
        e->storage = std::move(storage);
        e->lifetime = std::move(lifetime);
        e->controls = controls;
        e->source = invocation;
        e->task = task;
        e->bridgeLoan = bridge_.prepareContextLoan(caller, *e->storage->get(), task);
        std::vector<protocol::Range> combined = upstreamOpaque_;
        auto bridgeOpaque = bridge_.contextOpaqueSpans(caller);
        combined.insert(combined.end(), bridgeOpaque.begin(), bridgeOpaque.end());
        reo_source_closure::normalizeOpaque(combined);
        auto spans = reo_context_handoff::callerCpuOwnedSpans(combined);
        for (const auto& span : spans) {
            guardKnownContextRead(caller, span.offset, span.bytes);
            bridge_.beforeContextAccess(caller, span.offset, span.bytes, caller.pc);
        }
        reo_context_handoff::initializeCpuOwnedShadow(caller, *e->storage->get(), spans);
        for (const auto& range : upstreamOpaque_)
            if (range.space == protocol::Space::Context)
                e->callerContextOpaque.push_back(range);
        e->callerRoles = compositionScalarRoles_;
        e->patches = reo_context_handoff::rpcControlPatches(controls);
        e->childRoles = compositionScalarRoles_;
        reo_context_handoff::applyCpuControlPatches(*e->storage->get(), e->childRoles, combined,
                                                    e->patches);
        for (const auto& range : combined)
            if (range.space == protocol::Space::Context)
                e->childContextOpaque.push_back(range);
        e->forkOrdinal = upstreamOrdinal_ + 1;
        callbacks_.push_back(e);
        upstreamOrdinal_ = e->forkOrdinal;
        return e;
    }
    void exactCallback(const std::shared_ptr<CallbackEntry>& e) const {
        if (!e || e->issuer != this || e->closed || callbacks_.empty() || callbacks_.back() != e)
            throw std::invalid_argument(
                "Callback frame is foreign/stale or closes out of nesting order");
    }
    void requireCallbackCallerLifetimeOnEe(PS2Runtime& runtime,
                                           const std::shared_ptr<CallbackEntry>& e) const {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        exactCallback(e);
        if (!reo_parent_natural::matchesActualGuestContextStorage(runtime, *e->caller,
                                                                  e->callerLifetime))
            throw std::runtime_error("Callback original caller storage ended before restoration");
    }
    bool retainsSourceContextIdentity(const R5900Context& ctx) const noexcept {
        try {
            std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
            if (&ctx == configuration_.cold->actualContext)
                return true;
            for (const auto& e : callbacks_)
                if (!e->closed && (e->caller == &ctx || e->storage->get() == &ctx))
                    return true;
            for (const auto& p : retiredContextPolicies_)
                if (p.context == &ctx)
                    return true;
        } catch (...) {
            return true;
        } // A failed ownership query must retain/refuse.
        return false;
    }
    void recordOriginalRpcForkOnOwner(const std::shared_ptr<CallbackEntry>& e,
                                      const std::vector<protocol::RawPatch>& ingress) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireCallbackQuiescence();
        exactCallback(e);
        if (e->recorded || e->forkFence)
            throw std::invalid_argument("Callback fork was already recorded");
        try {
            // Reserve all policy allocation before active-bank or CPU changes.
            auto nextOpaque = upstreamOpaque_;
            nextOpaque.erase(
                std::remove_if(nextOpaque.begin(), nextOpaque.end(),
                               [](const auto& r) { return r.space == protocol::Space::Context; }),
                nextOpaque.end());
            nextOpaque.insert(nextOpaque.end(), e->childContextOpaque.begin(),
                              e->childContextOpaque.end());
            auto& child = *e->storage->get();
            gs_.record_resident_command([&](Vulkan::CommandBuffer& cmd) {
                for (const auto& patch : ingress)
                    producer_->bridgeSourceWrite(cmd, patch);
                e->callerImage = producer_->retainActualContextImage(e->caller);
                e->childImage = producer_->forkActualContextImage(cmd, e->caller, &child,
                                                                  e->patches, e->forkOrdinal);
            });
            bridge_.activateContextLoan(e->bridgeLoan, e->task);
            bridge_.clearLoanControlBytes(e->bridgeLoan, e->patches);
            upstreamOpaque_.swap(nextOpaque);
            compositionScalarRoles_ = e->childRoles;
            generation_ = producer_->bankGeneration_;
            e->recorded = true;
            callbackActiveContext_.store(&child, std::memory_order_release);
            ++activeContextRevision_;
            e->forkFence = gs_.submit_resident_completion([](Vulkan::CommandBuffer&) {});
            if (!e->forkFence)
                throw std::runtime_error("Context fork lacks its real producer fence");
            e->forkTimeline = newTimeline();
            transport_->sealed(e->forkTimeline);
        } catch (...) {
            observeOwnerSticky(170u);
            throw;
        }
    }
    void waitOriginalRpcForkOnOwner(const std::shared_ptr<CallbackEntry>& e) {
        std::unique_lock<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        exactCallback(e);
        if (!e->recorded || !e->forkFence || e->waited)
            throw std::invalid_argument("Callback fork has no new genuine fence");
        auto fence = e->forkFence;
        lock.unlock();
        try {
            fence->wait();
            lock.lock();
            requireHealthy();
            exactCallback(e);
            e->waited = true;
            completed_ = std::max(completed_, e->forkTimeline);
            transport_->retired(e->forkTimeline);
        } catch (...) {
            if (!lock.owns_lock())
                lock.lock();
            observeOwnerSticky(171u);
            throw;
        }
    }
    void recordOriginalRpcCloseOnOwner(const std::shared_ptr<CallbackEntry>& e,
                                       const std::vector<protocol::RawPatch>& ingress) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireCallbackQuiescence();
        exactCallback(e);
        if (!e->waited || e->closeFence || upstreamOrdinal_ == UINT64_MAX)
            throw std::invalid_argument("Callback close lacks actual completed source prefix");
        e->closeOrdinal = upstreamOrdinal_ + 1;
        upstreamOrdinal_ = e->closeOrdinal;
        try {
            // Keep the child bank active until every actual tail command has
            // been submitted and fenced. Restoring a pointer is not completion.
            gs_.record_resident_command([&](Vulkan::CommandBuffer& cmd) {
                for (const auto& patch : ingress)
                    producer_->bridgeSourceWrite(cmd, patch);
            });
            e->closeFence = gs_.submit_resident_completion([](Vulkan::CommandBuffer&) {});
            if (!e->closeFence)
                throw std::runtime_error("Callback close requires its actual producer fence");
            e->closeTimeline = newTimeline();
            transport_->sealed(e->closeTimeline);
        } catch (...) {
            observeOwnerSticky(172u);
            throw;
        }
    }
    void waitAndRestoreOriginalRpcOnOwner(const std::shared_ptr<CallbackEntry>& e) {
        std::unique_lock<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        exactCallback(e);
        if (!e->closeFence || !e->closeTimeline)
            throw std::invalid_argument("Callback restore lacks actual sealed close");
        auto fence = e->closeFence;
        lock.unlock();
        try {
            fence->wait();
            lock.lock();
            requireHealthy();
            exactCallback(e);
            transport_->retired(e->closeTimeline);
            completed_ = std::max(completed_, e->closeTimeline);
            auto childPolicy = prepareRetiredContextPolicy(e);
            auto nextOpaque = upstreamOpaque_;
            nextOpaque.erase(
                std::remove_if(nextOpaque.begin(), nextOpaque.end(),
                               [](const auto& r) { return r.space == protocol::Space::Context; }),
                nextOpaque.end());
            nextOpaque.insert(nextOpaque.end(), e->callerContextOpaque.begin(),
                              e->callerContextOpaque.end());
            reo_source_closure::normalizeOpaque(nextOpaque);
            producer_->bindActualContextImage(e->callerImage, e->closeOrdinal);
            bridge_.restoreContextLoan(e->bridgeLoan);
            generation_ = producer_->bankGeneration_;
            upstreamOpaque_.swap(nextOpaque);
            compositionScalarRoles_ = e->callerRoles;
            e->closed = true;
            callbackActiveContext_.store(e->caller, std::memory_order_release);
            callbacks_.pop_back();
            ++activeContextRevision_;
            retiredContextPolicies_.push_back(std::move(childPolicy));
        } catch (...) {
            if (!lock.owns_lock())
                lock.lock();
            observeOwnerSticky(173u);
            throw;
        }
    }

  public:
    uint32_t activeCallbackLoanDepth() const {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        return uint32_t(callbacks_.size());
    }
    uint64_t activeSourceContextRevision() const {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        return activeContextRevision_;
    }

  private:
    std::shared_ptr<CompositionEntry>
    exactOriginalComposition(const reo_gpu_upstream::CallHandle& call) const {
        if (!call || call->issuer() != this || call->stamp().session != configuration_.session ||
            call->stamp().epoch != epoch_ || call->stamp().bankGeneration != generation_)
            throw std::invalid_argument("Foreign/stale actual composition call");
        for (const auto& e : compositionEntries_)
            if (e->call == call)
                return e;
        throw std::invalid_argument("Composition call was never issued on actual EE entry");
    }
    bool hasOriginalComposition() const noexcept {
        return bool(producer_->composition18F6A0_);
    }
    static protocol::Range compositionView(uint32_t address, uint32_t bytes) {
        if (!bytes)
            throw std::invalid_argument("Empty composition source view");
        const auto key = [](uint32_t a) -> std::pair<protocol::Space, uint32_t> {
            if (a >= 0x70000000u && a < 0x70004000u)
                return {protocol::Space::Spr, a - 0x70000000u};
            if (a < 0x02000000u || (a >= 0x20000000u && a < 0x40000000u) ||
                (a >= 0x80000000u && a < 0xc0000000u && (a & 0x1fffffffu) < 0x02000000u))
                return {protocol::Space::Ram, a & 0x01ffffffu};
            throw std::invalid_argument("Composition source memory is outside actual RAM/SPR");
        };
        auto first = key(address), last = key(address + bytes - 1);
        if (first.first != last.first || uint64_t(first.second) + bytes - 1 != last.second)
            throw std::invalid_argument(
                "Composition source view crosses an unsupported bank boundary");
        return {first.first, first.second, bytes};
    }
    reo_gpu_upstream::CallHandle prepareOriginalCompositionOnEe(uint8_t* ram, R5900Context& ctx,
                                                                int32_t task) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        // Interior continuations require their own genuine token; this actual
        // source entry never manufactures one from an old register shadow.
        if (!hasOriginalComposition() || ctx.pc != 0x18f6a0u || ram != configuration_.cold->ram ||
            &ctx != activeSourceContextIdentity() || task < 1 || !compositionEntries_.empty() ||
            !matrixEntries_.empty() || !perspectiveEntries_.empty() || !setterEntries_.empty() ||
            !viewportEntries_.empty() || upstreamOrdinal_ == UINT64_MAX)
            throw std::invalid_argument("Composition actual entry/task is not available");
        guardKnownContextRead(ctx, 31u * 16u, 8u);
        guardKnownContextRead(ctx, 29u * 16u, 8u);
        guardKnownContextRead(ctx, 4u * 16u, 4u);
        const auto raw = [&](unsigned slot) {
            uint32_t value;
            std::memcpy(&value, &ctx.r[slot], 4);
            return value;
        };
        auto e = std::make_shared<CompositionEntry>();
        e->inputSp = raw(29);
        e->held.reserve(12);
        e->held.push_back(compositionView(e->inputSp - 128u, 128u));
        e->held.push_back(compositionView(0x70003700u + (raw(4) << 6), 64u));
        for (const auto range : {protocol::Range{protocol::Space::Ram, 0x22fe20u, 32u},
                                 {protocol::Space::Ram, 0x241c88u, 12u},
                                 {protocol::Space::Ram, 0x294e00u, 64u},
                                 {protocol::Space::Ram, 0x2941a0u, 52u},
                                 {protocol::Space::Ram, 0x294dc0u, 64u},
                                 {protocol::Space::Ram, 0x294d00u, 64u},
                                 {protocol::Space::Ram, 0x294d40u, 128u},
                                 {protocol::Space::Spr, 0x3f00u, 64u},
                                 {protocol::Space::Spr, 0x3f80u, 64u},
                                 {protocol::Space::Context, 0, 1648u}})
            e->held.push_back(range);
        // This is address-only input/output lease construction. Numerical
        // operands remain in the genuine persistent Context/RAM/SPR banks.
        auto call = std::shared_ptr<const reo_gpu_upstream::Call>(new reo_gpu_upstream::Call(
            this, {configuration_.session, epoch_, generation_, upstreamOrdinal_ + 1}, ctx.pc,
            raw(31), raw(4), 0, 0, task));
        e->call = call;
        compositionEntries_.push_back(e);
        upstreamOrdinal_ = call->stamp().ordinal;
        // These are the exact original call's already CPU-owned integer inputs,
        // guarded before reading. Saved/restored Role2 inherits this existing
        // input role; equal bytes alone never establish control authority.
        for (uint32_t b = 0; b < 8; ++b) {
            compositionScalarRoles_[31u * 16u + b] = 3;
            compositionScalarRoles_[29u * 16u + b] = 6;
        }
        for (uint32_t b = 0; b < 4; ++b)
            compositionScalarRoles_[4u * 16u + b] = 7;
        return call;
    }
    const std::vector<protocol::Range>&
    originalCompositionHeldRanges(const reo_gpu_upstream::CallHandle& call) const {
        return exactOriginalComposition(call)->held;
    }
    void recordOriginalCompositionOnOwner(const reo_gpu_upstream::CallHandle& call,
                                          const std::vector<protocol::RawPatch>& patches) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        auto e = exactOriginalComposition(call);
        (void)requireBoundRetainedInvocation(e);
        if (e->output || e->fence || e->waiting || e->waited || e->committed)
            throw std::invalid_argument("Repeated composition owner recording");
        try {
            producer_->verifyOriginalUpstreamOrder(call);
            Vulkan::BufferCreateInfo ci{};
            ci.domain = Vulkan::BufferDomain::CachedHost;
            ci.usage = VK_BUFFER_USAGE_TRANSFER_DST_BIT;
            ci.size = reo_gpu_upstream::ReceiptBytes;
            e->host = device_.create_buffer(ci);
            ci.size = reo_gpu_upstream::CompositionEffectsBytes;
            e->hostEffects = device_.create_buffer(ci);
            if (!e->host || !e->hostEffects)
                throw std::runtime_error("Actual composition metadata staging allocation failed");
            gs_.record_resident_command([&](Vulkan::CommandBuffer& cmd) {
                for (const auto& p : patches)
                    producer_->bridgeSourceWrite(cmd, p);
                e->output = producer_->recordOriginalComposition(cmd, call);
            });
            e->fence = gs_.submit_resident_completion([&](Vulkan::CommandBuffer& cmd) {
                const auto copy = [&](const Vulkan::Buffer& src, const Vulkan::Buffer& dst) {
                    cmd.buffer_barrier(src, VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT,
                                       VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                                       VK_PIPELINE_STAGE_2_TRANSFER_BIT,
                                       VK_ACCESS_2_TRANSFER_READ_BIT);
                    cmd.copy_buffer(dst, src);
                    cmd.buffer_barrier(dst, VK_PIPELINE_STAGE_2_TRANSFER_BIT,
                                       VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_2_HOST_BIT,
                                       VK_ACCESS_2_HOST_READ_BIT);
                };
                copy(e->output->receipt(), *e->host);
                copy(e->output->effects(), *e->hostEffects);
            });
            if (!e->fence)
                throw std::runtime_error("Composition requires its genuine producer fence");
            e->timeline = newTimeline();
            transport_->sealed(e->timeline);
        } catch (...) {
            observeOwnerSticky(160u);
            throw;
        }
    }
    void waitOriginalCompositionOnOwner(const reo_gpu_upstream::CallHandle& call) {
        std::unique_lock<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        auto e = exactOriginalComposition(call);
        if (!e->output || !e->fence || e->waiting || e->waited || e->committed)
            throw std::invalid_argument("Composition has no new actual metadata return");
        e->waiting = true;
        auto fence = e->fence;
        lock.unlock();
        try {
            fence->wait();
            lock.lock();
            requireHealthy();
            exactOriginalComposition(call);
            const auto* receipt = device_.map_host_buffer(*e->host, Vulkan::MEMORY_ACCESS_READ_BIT);
            if (!receipt)
                throw std::runtime_error("Composition receipt map failed");
            std::memcpy(e->receipt.data(), receipt, reo_gpu_upstream::ReceiptBytes);
            device_.unmap_host_buffer(*e->host, Vulkan::MEMORY_ACCESS_READ_BIT);
            std::vector<uint32_t> words(reo_gpu_upstream::CompositionEffectsWords);
            const auto* metadata =
                device_.map_host_buffer(*e->hostEffects, Vulkan::MEMORY_ACCESS_READ_BIT);
            if (!metadata)
                throw std::runtime_error("Composition effects map failed");
            std::memcpy(words.data(), metadata, reo_gpu_upstream::CompositionEffectsBytes);
            device_.unmap_host_buffer(*e->hostEffects, Vulkan::MEMORY_ACCESS_READ_BIT);
            auto packet = reo_gpu_upstream::decodeCompositionEffects(*call, e->receipt, words);
            auto next = reo_source_closure::prepareGpuEffects(upstreamOpaque_,
                                                              compositionScalarRoles_, packet);
            // Only the actual Service can mint this certificate from its own
            // exact output, retained immutable banks/call and real fence.
            auto certified = std::shared_ptr<const reo_source_closure::CertifiedEffects>(
                new reo_source_closure::CertifiedEffects(
                    this, e->output->banks(), call, e->output->effectsHandle(), e->timeline,
                    packet.header, packet.dirty, packet.control));
            e->packet = std::move(packet);
            e->certificate = std::move(certified);
            upstreamOpaque_.swap(next.opaque);
            compositionScalarRoles_ = next.scalar;
            e->waiting = false;
            e->waited = true;
            completedCompositionTimeline_ = std::max(completedCompositionTimeline_, e->timeline);
            completed_ = std::max(completed_, e->timeline);
            transport_->retired(e->timeline);
        } catch (...) {
            if (!lock.owns_lock())
                lock.lock();
            e->waiting = false;
            observeOwnerSticky(161u);
            throw;
        }
    }
    void commitOriginalCompositionOnEe(const reo_gpu_upstream::CallHandle& call, uint8_t* ram,
                                       R5900Context& ctx, int32_t task) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        auto e = exactOriginalComposition(call);
        if (!e->waited || e->waiting || e->committed || !e->certificate ||
            ram != configuration_.cold->ram || &ctx != activeSourceContextIdentity() ||
            ctx.pc != call->entry() || task != call->task())
            throw std::invalid_argument("Composition did not regain its actual EE entry/task");
        const auto raw = [&](unsigned slot) {
            uint32_t value;
            std::memcpy(&value, &ctx.r[slot], 4);
            return value;
        };
        if (raw(31) != call->returnPc() || raw(4) != call->a0() || raw(29) != e->inputSp)
            throw std::invalid_argument(
                "Composition held integer controls changed before real return");
        auto retained = requireBoundRetainedInvocation(e);
        validateRetainedCommitOnEe(retained, call, e->timeline);
        auto next = reo_source_closure::prepareEeControlPublication(
            upstreamOpaque_, compositionScalarRoles_, e->packet);
        // Allocation/validation completed before any EE byte or ledger changes.
        auto* target = reinterpret_cast<uint8_t*>(&ctx);
        for (const auto& c : e->packet.control)
            std::memcpy(target + c.contextOffset, c.bits.data(), c.bytes);
        upstreamOpaque_.swap(next.opaque);
        compositionScalarRoles_ = next.scalar;
        e->committed = true;
        publishRetainedCommit(retained, e->timeline);
        // The original saved-RA slot may alias genuine numerical output.
        // decodeCompositionEffects already bound this PC to the exact GPU
        // receipt, original write ledger and final completed source fence.
        // Only Service records it; no caller-provided return-PC override.
        if (retained)
            retained->finalPc_ = e->packet.header.actualFinalPc;
        compositionEntries_.erase(
            std::remove(compositionEntries_.begin(), compositionEntries_.end(), e),
            compositionEntries_.end());
    }

  public:
    bool hasPendingCompositionEffects() const {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        return !compositionEntries_.empty();
    }
    uint64_t lastCompletedCompositionEffectsTimeline() const {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        return completedCompositionTimeline_;
    }
    void guardKnownContextRead(const R5900Context& ctx, uint32_t offset, uint32_t bytes) const {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        if (!bytes || offset >= 1648u || bytes > 1648u - offset)
            throw std::invalid_argument("Context source access exceeds exact lane bounds");
        if (&ctx != activeSourceContextIdentity()) {
            guardSavedCallbackContextRead(ctx, offset, bytes);
            return;
        } // Unenrolled CPU-owned Context is separate.
        beforeUpstreamSourceAccess(protocol::Space::Context, offset, bytes);
    }
    void guardKnownContextWrite(
        const R5900Context& ctx, uint32_t offset, uint32_t bytes, const void* actualBytes,
        uint32_t sourcePc, const reo_source_instrumentation::InstructionOrigin& origin,
        const reo_source_closure::CompletedDelayControl* completedDelay = nullptr) const {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        if (&ctx != activeSourceContextIdentity() || !bytes || offset >= 1648u ||
            bytes > 1648u - offset)
            throw std::invalid_argument(
                "Source control belongs to foreign or unbounded physical Context");
        reo_source_closure::validateTypedContextControl(
            offset, bytes, actualBytes, sourcePc, origin,
            [&](uint32_t r, uint32_t n) {
                return reo_source_closure::scalarControlLane(compositionScalarRoles_, r * 16u, n);
            },
            completedDelay);
    }

    void completedTypedContextControlOnEe(const R5900Context& ctx, uint32_t at, uint32_t bytes,
                                          uint8_t role) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        if (&ctx != activeSourceContextIdentity() || !bytes || at >= 1648u || bytes > 1648u - at ||
            role < 3u || role > 7u)
            throw std::invalid_argument("Completed scalar writer lost exact Context/role");
        for (uint32_t b = 0; b < bytes; ++b)
            compositionScalarRoles_[at + b] = role;
    }

  private:
    bool hasOriginal191280() const noexcept {
        return bool(producer_->matrix191280_);
    }
    reo_gpu_upstream::CallHandle prepareOriginal191280OnEe(uint8_t* ram, R5900Context& ctx,
                                                           int32_t task) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        if (!compositionEntries_.empty())
            throw std::invalid_argument("Upstream call cannot overtake actual composition return");
        for (const auto& entry : setterEntries_)
            if (!entry->committed)
                throw std::invalid_argument("Upstream call cannot overtake setter receipt");
        if (!hasOriginal191280() || !viewportEntries_.empty() || ram != configuration_.cold->ram ||
            &ctx != activeSourceContextIdentity() || ctx.pc != 0x191280u || task < 1 ||
            !perspectiveEntries_.empty() || matrixEntries_.size() >= 4096 ||
            upstreamOrdinal_ == UINT64_MAX)
            throw std::invalid_argument("Not this actual original191280 EE entry/task");
        const auto raw = [&](unsigned r) {
            uint32_t v;
            std::memcpy(&v, &ctx.r[r], 4);
            return v;
        };
        reo_gpu_upstream::matrixView(raw(4));
        reo_gpu_upstream::matrixView(raw(5));
        reo_gpu_upstream::matrixView(raw(6));
        auto call = std::shared_ptr<const reo_gpu_upstream::Call>(new reo_gpu_upstream::Call(
            this, {configuration_.session, epoch_, generation_, upstreamOrdinal_ + 1}, ctx.pc,
            raw(31), raw(4), raw(5), raw(6), task));
        auto entry = std::make_shared<MatrixEntry>();
        entry->call = call;
        matrixEntries_.push_back(entry);
        upstreamOrdinal_ = call->stamp().ordinal;
        return call;
    }
    std::shared_ptr<MatrixEntry>
    exactOriginal191280(const reo_gpu_upstream::CallHandle& call) const {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        if (!call || call->issuer() != this || call->stamp().session != configuration_.session ||
            call->stamp().epoch != epoch_ || call->stamp().bankGeneration != generation_)
            throw std::invalid_argument("Foreign/stale original191280 call");
        for (const auto& entry : matrixEntries_)
            if (entry->call == call)
                return entry;
        throw std::invalid_argument("Original191280 call was never issued by actual EE frontier");
    }
    void recordOriginal191280OnOwner(const reo_gpu_upstream::CallHandle& call,
                                     const std::vector<protocol::RawPatch>& patches) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        auto entry = exactOriginal191280(call);
        (void)requireBoundRetainedInvocation(entry);
        if (entry->output || entry->fence || entry->committed)
            throw std::invalid_argument("Repeated original191280 recording");
        try {
            producer_->verifyOriginalUpstreamOrder(call); // Before any staged RAW overwrite.

            Vulkan::BufferCreateInfo ci{};
            ci.domain = Vulkan::BufferDomain::CachedHost;
            ci.size = reo_gpu_upstream::ReceiptBytes;
            ci.usage = VK_BUFFER_USAGE_TRANSFER_DST_BIT;
            entry->host = device_.create_buffer(ci);
            if (!entry->host)
                throw std::runtime_error("Original191280 integer receipt allocation failed");
            // Patches are genuine scalar/control/asset source events from the
            // reviewed journal. CPU-produced matrices cannot use this seam.
            gs_.record_resident_command([&](Vulkan::CommandBuffer& cmd) {
                for (const auto& patch : patches)
                    producer_->bridgeSourceWrite(cmd, patch);
                entry->output = producer_->recordOriginal191280(cmd, call);
            });
            entry->fence = gs_.submit_resident_completion([&](Vulkan::CommandBuffer& cmd) {
                const auto& receipt = entry->output->receipt();
                cmd.buffer_barrier(receipt, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                   VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                                   VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
                cmd.copy_buffer(*entry->host, receipt);
                cmd.buffer_barrier(*entry->host, VK_PIPELINE_STAGE_TRANSFER_BIT,
                                   VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_HOST_BIT,
                                   VK_ACCESS_2_HOST_READ_BIT);
            });
            if (!entry->fence)
                throw std::runtime_error("Original191280 has no genuine owner receipt fence");
            entry->timeline = newTimeline();
            transport_->sealed(entry->timeline);
        } catch (...) {
            observeOwnerSticky(122u);
            throw;
        }
    }
    void waitOriginal191280OnOwner(const reo_gpu_upstream::CallHandle& call) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        auto entry = exactOriginal191280(call);
        if (!entry->output || !entry->fence || entry->waited || entry->committed)
            throw std::invalid_argument("No new original191280 owner return");
        try {
            entry->fence->wait();
            const auto* memory =
                device_.map_host_buffer(*entry->host, Vulkan::MEMORY_ACCESS_READ_BIT);
            if (!memory)
                throw std::runtime_error("Original191280 integer receipt map failed");
            std::memcpy(entry->receipt.data(), memory, reo_gpu_upstream::ReceiptBytes);
            device_.unmap_host_buffer(*entry->host, Vulkan::MEMORY_ACCESS_READ_BIT);
            const auto& w = entry->receipt;
            const auto p = reo_gpu_upstream::parameters(*call);
            if (w[0] || w[1] != reo_gpu_upstream::ReceiptMagic || w[2] != 1u || w[3] != 1u ||
                w[4] != p.sessionLo || w[5] != p.sessionHi || w[6] != p.epochLo ||
                w[7] != p.epochHi || w[8] != p.bankLo || w[9] != p.bankHi || w[10] != p.ordinalLo ||
                w[11] != p.ordinalHi || w[12] != p.entry || w[13] != p.returnPc || w[14] != p.a0 ||
                w[15] != p.a1 || w[16] != p.a2 || w[17] != p.entry || w[18] || w[19])
                throw std::runtime_error("Actual original191280 source/control receipt refused");
            entry->waited = true;
            completed_ = std::max(completed_, entry->timeline);
            transport_->retired(entry->timeline);
            // Context carry and destination remain in genuine GPU banks.
            const auto view = reo_gpu_upstream::matrixView(call->a0());
            const auto own = [&](protocol::Range range) {
                for (const auto& old : upstreamOpaque_)
                    if (old.space == range.space && old.address == range.address &&
                        old.bytes == range.bytes)
                        return;
                if (upstreamOpaque_.size() >= 4096)
                    throw std::overflow_error("Upstream source ownership frontier exhausted");
                upstreamOpaque_.push_back(range);
            };
            own({view.bank == reo_gpu_upstream::Bank::Spr ? protocol::Space::Spr
                                                          : protocol::Space::Ram,
                 view.offset, 64});
            own({protocol::Space::Context, uint32_t(offsetof(R5900Context, vu0_vf) + 4 * 16),
                 8 * 16});
            own({protocol::Space::Context, uint32_t(offsetof(R5900Context, vu0_acc)), 16});
        } catch (...) {
            observeOwnerSticky(123u);
            throw;
        }
    }
    void commitOriginal191280OnEe(const reo_gpu_upstream::CallHandle& call, uint8_t* ram,
                                  R5900Context& ctx, int32_t task) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        auto entry = exactOriginal191280(call);
        if (!entry->waited || entry->committed || ram != configuration_.cold->ram ||
            &ctx != activeSourceContextIdentity() || task != call->task() ||
            ctx.pc != call->entry())
            throw std::invalid_argument(
                "Original191280 scalar return lost actual reacquired EE owner");
        const auto raw = [&](unsigned r) {
            uint32_t v;
            std::memcpy(&v, &ctx.r[r], 4);
            return v;
        };
        if (raw(31) != call->returnPc() || raw(4) != call->a0() || raw(5) != call->a1() ||
            raw(6) != call->a2())
            throw std::invalid_argument(
                "Original191280 integer call fields changed before true return");
        auto retained = requireBoundRetainedInvocation(entry);
        validateRetainedCommitOnEe(retained, call, entry->timeline);
        ctx.pc = entry->receipt[13];
        entry->committed = true;
        publishRetainedCommit(retained, entry->timeline);
        // Original JR has no additional scalar result or context copy. Only
        // PC is published; VF4..11/ACC and memory stay opaque on GPU.
        matrixEntries_.erase(std::remove(matrixEntries_.begin(), matrixEntries_.end(), entry),
                             matrixEntries_.end());
    }
    void beforeUpstreamSourceAccess(protocol::Space space, uint32_t at, uint32_t bytes) const {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        for (const auto& range : upstreamOpaque_)
            if (range.space == space && protocol::overlap(at, bytes, range.address, range.bytes))
                throw std::runtime_error(
                    "CPU source access overlaps GPU original191280 output/carry");
    }

  public:
  private:
    bool hasOriginalViewport() const noexcept {
        return bool(producer_->viewport18F970_);
    }
    reo_gpu_upstream::CallHandle prepareOriginalViewportOnEe(uint8_t* ram, R5900Context& ctx,
                                                             int32_t task) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        if (!compositionEntries_.empty())
            throw std::invalid_argument("Upstream call cannot overtake actual composition return");
        for (const auto& entry : setterEntries_)
            if (!entry->committed)
                throw std::invalid_argument("Upstream call cannot overtake setter receipt");
        if (!hasOriginalViewport() || !viewportEntries_.empty() || !matrixEntries_.empty() ||
            !perspectiveEntries_.empty() || ram != configuration_.cold->ram ||
            &ctx != activeSourceContextIdentity() ||
            !reo_gpu_upstream::Viewport::supports(ctx.pc) || task < 1 ||
            viewportEntries_.size() >= 4096 || upstreamOrdinal_ == UINT64_MAX)
            throw std::invalid_argument(
                "Viewport preparation is not this genuine original EE frontier");
        const auto raw = [&](unsigned n) {
            uint32_t value;
            std::memcpy(&value, &ctx.r[n], 4);
            return value;
        };
        const auto mask = reo_gpu_upstream::Viewport::argumentMask(ctx.pc);
        guardKnownContextRead(ctx, 31u * 16u, 4u);
        for (unsigned r = 4; r <= 6; ++r)
            if (mask & (1u << (r - 3)))
                guardKnownContextRead(ctx, r * 16u, 4u);
        if (reo_gpu_upstream::Viewport::insideClosedSource(raw(31)))
            throw std::invalid_argument(
                "Viewport outer source continuation requires enclosing GPU scope");
        auto call = std::shared_ptr<const reo_gpu_upstream::Call>(new reo_gpu_upstream::Call(
            this, {configuration_.session, epoch_, generation_, upstreamOrdinal_ + 1}, ctx.pc,
            raw(31), (mask & 2u) ? raw(4) : 0u, (mask & 4u) ? raw(5) : 0u,
            (mask & 8u) ? raw(6) : 0u, task));
        auto entry = std::make_shared<ViewportEntry>();
        entry->call = call;
        entry->expectedBeforePc = call->entry();
        entry->incomingScalarRoles = compositionScalarRoles_;
        for (const auto& range : upstreamOpaque_)
            if (range.space == protocol::Space::Context)
                entry->incomingContextOpaque.push_back(range);
        viewportEntries_.push_back(entry);
        ++upstreamOrdinal_;
        return call;
    }
    std::shared_ptr<ViewportEntry>
    exactOriginalViewport(const reo_gpu_upstream::CallHandle& call) const {
        if (!call || call->issuer() != this || call->stamp().session != configuration_.session ||
            call->stamp().epoch != epoch_ || call->stamp().bankGeneration != generation_)
            throw std::invalid_argument("Viewport call issuer/bank identity is stale/foreign");
        for (const auto& entry : viewportEntries_)
            if (entry->call == call)
                return entry;
        throw std::invalid_argument("Viewport call was not issued by actual Service");
    }
    void recordOriginalViewportOnOwner(const reo_gpu_upstream::CallHandle& call,
                                       const std::vector<protocol::RawPatch>& patches) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        auto entry = exactOriginalViewport(call);
        (void)requireBoundRetainedInvocation(entry);
        if (hasOriginalViewportAllocator() && !entry->heapFrontier)
            throw std::invalid_argument("Viewport allocator needs prior protected heap origin");
        if (entry->output || entry->fence || entry->waited || entry->committed)
            throw std::invalid_argument("Viewport original entry was already recorded");
        producer_->verifyOriginalUpstreamOrder(call); // before any raw bank mutation
        try {
            Vulkan::BufferCreateInfo ci{};
            ci.domain = Vulkan::BufferDomain::CachedHost;
            ci.size = reo_gpu_upstream::ReceiptBytes;
            ci.usage = VK_BUFFER_USAGE_TRANSFER_DST_BIT;
            entry->receiptHost = device_.create_buffer(ci);
            ci.size = reo_gpu_upstream::Viewport::ControlBytes;
            entry->controlHost = device_.create_buffer(ci);
            ci.size = reo_gpu_upstream::ViewportEffectsBytes;
            entry->effectsHost = device_.create_buffer(ci);
            if (!entry->receiptHost || !entry->controlHost || !entry->effectsHost)
                throw std::runtime_error("Viewport immutable integer readback allocation failed");
            gs_.record_resident_command([&](Vulkan::CommandBuffer& cmd) {
                for (const auto& patch : patches)
                    producer_->bridgeSourceWrite(cmd, patch);
                if (entry->heapFrontier) {
                    // Latest certified CPU control, not graphics outputs.
                    const uint32_t limit = entry->heapFrontier->word(0x29fdbcu),
                                   cursor = entry->heapFrontier->word(0x29fdc0u);
                    producer_->bridgeRawWrite(cmd, unsigned(protocol::Space::Ram), 0x29fdbcu,
                                              &limit, 4);
                    producer_->bridgeRawWrite(cmd, unsigned(protocol::Space::Ram), 0x29fdc0u,
                                              &cursor, 4);
                }
                entry->output = producer_->recordOriginalViewport(cmd, call);
            });
            entry->fence = gs_.submit_resident_completion([&](Vulkan::CommandBuffer& cmd) {
                const auto copy = [&](const Vulkan::Buffer& source,
                                      const Vulkan::Buffer& destination) {
                    cmd.buffer_barrier(source, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                       VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                                       VK_PIPELINE_STAGE_TRANSFER_BIT,
                                       VK_ACCESS_2_TRANSFER_READ_BIT);
                    cmd.copy_buffer(destination, source);
                    cmd.buffer_barrier(destination, VK_PIPELINE_STAGE_TRANSFER_BIT,
                                       VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_HOST_BIT,
                                       VK_ACCESS_2_HOST_READ_BIT);
                };
                copy(entry->output->receipt(), *entry->receiptHost);
                copy(entry->output->control(), *entry->controlHost);
                copy(entry->output->effects(), *entry->effectsHost);
            });
            if (!entry->fence)
                throw std::runtime_error("Viewport has no genuine existing GS completion fence");
            entry->timeline = newTimeline();
            transport_->sealed(entry->timeline);
        } catch (...) {
            observeOwnerSticky(160u);
            throw;
        }
    }
    void retainCertifiedViewportRamControls(const std::shared_ptr<ViewportEntry>& viewport,
                                            const reo_gpu_upstream::ViewportEffectsPacket& packet,
                                            reo_source_closure::LedgerTransition& next) {
        const auto retain = [&](uint32_t pc, uint32_t address) {
            if (!protocol::range(address, 4u, protocol::RamBytes))
                throw std::invalid_argument("Certified viewport control exceeds RAM");
            for (uint32_t byte = address; byte < address + 4u; ++byte) {
                bool exact = false;
                for (const auto& d : packet.dirty)
                    if (d.space == 0u && byte >= d.offset && byte < d.offset + d.bytes) {
                        if (d.sourcePc != pc || d.role != 1u)
                            throw std::invalid_argument("Certified helper control was overwritten "
                                                        "by a different GPU source");
                        exact = true;
                    }
                if (!exact)
                    throw std::invalid_argument(
                        "Certified helper control lacks its actual authored GPU write");
            }
            next.opaque = reo_source_closure::subtractOpaque(next.opaque,
                                                             {protocol::Space::Ram, address, 4u});
        };
        for (const auto& e : allocatorEntries_)
            if (e->capture->call_ == viewport->call && e->resumeTimeline == viewport->timeline) {
                if (!e->cpuCommitted || !e->resumed || !e->commit ||
                    !(viewport->call->entry() == 0x197900u ? bool(e->stateReturned)
                                                           : bool(e->returned)) ||
                    !e->successorFrontier || e->commit->issuer_ != this ||
                    e->commit->output_ != e->output || e->commit->realTimeline_ != e->timeline ||
                    e->commit->sourcePc_ != 0x18de2cu || e->commit->sourceWord_ != 0xac24fdc0u ||
                    e->commit->address_ != 0x29fdc0u)
                    throw std::invalid_argument(
                        "Viewport carry lost its actual already-certified allocator control");
                retain(e->commit->sourcePc_, e->commit->address_);
            }
        for (const auto& e : queueEntries_)
            if (e->original == viewport->call && e->resumeTimeline == viewport->timeline) {
                if (!e->cpuCommitted || !e->resumed || !e->commit ||
                    !(viewport->call->entry() == 0x197900u ? bool(e->stateReturned)
                                                           : bool(e->returned)) ||
                    !e->successorFrontier || e->commit->issuer_ != this ||
                    e->commit->output_ != e->journal ||
                    e->commit->actualTimeline_ != e->journalTimeline)
                    throw std::invalid_argument(
                        "Viewport carry lost its actual already-certified queue controls");
                std::map<uint32_t, uint32_t> last;
                for (const auto& store : e->commit->stores_)
                    last[store.address] = store.sourcePc;
                for (const auto& [address, pc] : last)
                    retain(pc, address);
            }
    }
    void waitOriginalViewportOnOwner(const reo_gpu_upstream::CallHandle& call) {
        std::shared_ptr<ViewportEntry> entry;
        {
            std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
            requireHealthy();
            entry = exactOriginalViewport(call);
            if (!entry->output || !entry->fence || entry->waiting || entry->waited ||
                entry->committed)
                throw std::invalid_argument("Viewport has no new genuine owner stage");
            entry->waiting = true;
        }
        // The caller is genuinely held. No source/protocol lock survives this
        // actual GPU wait, and the live EE context/RAM are never written here.
        try {
            entry->fence->wait();
            std::array<uint32_t, reo_gpu_upstream::ReceiptWords> receipt{};
            std::array<uint32_t, reo_gpu_upstream::Viewport::ControlWords> control{};
            const auto read = [&](const Vulkan::Buffer& buffer, void* out, size_t bytes) {
                auto* memory = device_.map_host_buffer(buffer, Vulkan::MEMORY_ACCESS_READ_BIT);
                if (!memory)
                    throw std::runtime_error("Viewport integer control map failed");
                std::memcpy(out, memory, bytes);
                device_.unmap_host_buffer(buffer, Vulkan::MEMORY_ACCESS_READ_BIT);
            };
            std::vector<uint32_t> effects(reo_gpu_upstream::ViewportEffectsWords);
            read(*entry->effectsHost, effects.data(), reo_gpu_upstream::ViewportEffectsBytes);
            read(*entry->receiptHost, receipt.data(), sizeof(receipt));
            read(*entry->controlHost, control.data(), sizeof(control));
            std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
            requireHealthy();
            if (exactOriginalViewport(call) != entry || !entry->waiting || entry->waited ||
                entry->committed)
                throw std::invalid_argument(
                    "Viewport held stage identity changed during true wait");
            const auto p = reo_gpu_upstream::parameters(*call);
            if (receipt[0] || receipt[1] != reo_gpu_upstream::ReceiptMagic || receipt[2] != 1u ||
                receipt[3] > 1u || receipt[4] != p.sessionLo || receipt[5] != p.sessionHi ||
                receipt[6] != p.epochLo || receipt[7] != p.epochHi || receipt[8] != p.bankLo ||
                receipt[9] != p.bankHi || receipt[10] != p.ordinalLo ||
                receipt[11] != p.ordinalHi || receipt[12] != p.entry || receipt[13] != p.returnPc ||
                receipt[14] != p.a0 || receipt[15] != p.a1 || receipt[16] != p.a2 ||
                receipt[17] != entry->expectedBeforePc || control[0] || control[1] != 0x56504331u ||
                control[2] != 1u || control[3] > 2u ||
                !std::equal(receipt.begin() + 4, receipt.begin() + 12, control.begin() + 4) ||
                control[12] != p.entry || control[13] != p.returnPc || control[31])
                throw std::runtime_error(
                    "Viewport actual immutable source/control receipt refused");
            if (control[3] == 0u) {
                if (receipt[3] != 1u || receipt[18] != p.returnPc || control[14] || control[15] ||
                    control[29] != entry->priorStage)
                    throw std::runtime_error("Viewport final true return profile differs");
            } else {
                if (receipt[3] != 0u || control[29] != entry->priorStage + 1u ||
                    receipt[18] != control[14] || control[26] != control[15] || control[27] != 0u)
                    throw std::runtime_error("Viewport held control-call state differs");
                if (control[3] == 1u) {
                    if (control[14] != 0x18ddd0u ||
                        (control[15] != 0x197524u && control[15] != 0x197538u) ||
                        control[18] != 16u || control[19] || control[17] ||
                        (control[16] != 48u && control[16] != 64u))
                        throw std::runtime_error("Viewport true allocation request differs");
                } else if (control[14] != 0x18cfb0u || control[15] != 0x197750u || control[16] ||
                           control[17] || control[22] != 0x29f6f0u || control[23])
                    throw std::runtime_error("Viewport true queue-control request differs");
            }
            auto packet = reo_gpu_upstream::decodeViewportEffects(
                *call, entry->output->inputPhase(), receipt, control, effects, entry->priorStage,
                entry->expectedBeforePc);
            auto next = reo_gpu_upstream::prepareViewportGpuEffects(
                upstreamOpaque_, compositionScalarRoles_, entry->incomingContextOpaque,
                entry->incomingScalarRoles, packet);
            retainCertifiedViewportRamControls(entry, packet, next);
            auto certificate = std::shared_ptr<const reo_source_closure::CertifiedEffects>(
                new reo_source_closure::CertifiedEffects(
                    this, entry->output->banks(), call, entry->output->effectsHandle(),
                    entry->timeline, packet.header, packet.dirty, packet.control));
            entry->packet = std::move(packet);
            entry->certificate = std::move(certificate);
            upstreamOpaque_.swap(next.opaque);
            compositionScalarRoles_ = next.scalar;
            entry->receipt = receipt;
            entry->control = control;
            entry->waiting = false;
            entry->waited = true;
            entry->controlHeld = control[3] != 0u;
            completed_ = std::max(completed_, entry->timeline);
            transport_->retired(entry->timeline);
        } catch (...) {
            std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
            observeOwnerSticky(161u);
            throw;
        }
    }
    void commitOriginalViewportOnEe(const reo_gpu_upstream::CallHandle& call, uint8_t* ram,
                                    R5900Context& ctx, int32_t task) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        auto entry = exactOriginalViewport(call);
        if (!entry->waited || entry->waiting || entry->committed || !entry->certificate ||
            entry->controlHeld || (entry->heapFrontier && !entry->heapFrontierReleased) ||
            entry->receipt[3] != 1u || ram != configuration_.cold->ram ||
            &ctx != activeSourceContextIdentity() || task != call->task() ||
            ctx.pc != call->entry())
            throw std::invalid_argument("Viewport final scalar return requires actual reacquired "
                                        "EE owner and completed whole source");
        const auto raw = [&](unsigned n) {
            uint32_t value;
            std::memcpy(&value, &ctx.r[n], 4);
            return value;
        };
        const auto mask = reo_gpu_upstream::Viewport::argumentMask(call->entry());
        if (raw(31) != call->returnPc() || ((mask & 2u) && raw(4) != call->a0()) ||
            ((mask & 4u) && raw(5) != call->a1()) || ((mask & 8u) && raw(6) != call->a2()))
            throw std::invalid_argument(
                "Viewport actual original consumed control changed before true return");
        auto retained = requireBoundRetainedInvocation(entry);
        validateRetainedCommitOnEe(retained, call, entry->timeline);
        auto next = reo_source_closure::prepareEeControlPublication(
            upstreamOpaque_, compositionScalarRoles_, entry->packet);
        auto* target = reinterpret_cast<uint8_t*>(&ctx);
        for (const auto& control : entry->packet.control) {
            std::memcpy(target + control.contextOffset, control.bits.data(), control.bytes);
            if (bridge_.hasContextLeaseFor(ctx))
                for (uint32_t byte = 0; byte < control.bytes; ++byte)
                    bridge_.opaqueContext_.reset(control.contextOffset + byte);
        }
        upstreamOpaque_.swap(next.opaque);
        compositionScalarRoles_ = next.scalar;
        entry->committed = true;
        publishRetainedCommit(retained, entry->timeline);
        allocatorEntries_.erase(std::remove_if(allocatorEntries_.begin(), allocatorEntries_.end(),
                                               [&](const auto& allocator) {
                                                   return allocator->capture->call_ == call;
                                               }),
                                allocatorEntries_.end());
        viewportEntries_.erase(std::remove(viewportEntries_.begin(), viewportEntries_.end(), entry),
                               viewportEntries_.end());
    }

  private:
    bool hasOriginalStatePacket197900() const noexcept {
        return bool(producer_->statePacket197900_) && bool(producer_->stateAllocator_) &&
               bool(producer_->stateQueueHeaders_) && bool(producer_->stateQueueJournal_);
    }
    reo_gpu_upstream::CallHandle
    prepareOriginalStatePacket197900OnEe(uint8_t* ram, R5900Context& ctx, int32_t task) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        if (!hasOriginalStatePacket197900() || ctx.pc != 0x197900u ||
            ram != configuration_.cold->ram || &ctx != activeSourceContextIdentity() || task < 1 ||
            !viewportEntries_.empty() || !matrixEntries_.empty() || !perspectiveEntries_.empty() ||
            !compositionEntries_.empty() || upstreamOrdinal_ == UINT64_MAX)
            throw std::invalid_argument("197900 is not the exact empty original EE frontier");
        for (const auto& e : setterEntries_)
            if (!e->committed)
                throw std::invalid_argument("197900 cannot overtake an enclosing setter call");
        uint32_t ra;
        std::memcpy(&ra, &ctx.r[31], 4);
        if (ra >= 0x197900u && ra < 0x197bb0u)
            throw std::invalid_argument(
                "197900 nested self-return requires enclosing source closure");
        auto call = std::shared_ptr<const reo_gpu_upstream::Call>(new reo_gpu_upstream::Call(
            this, {configuration_.session, epoch_, generation_, upstreamOrdinal_ + 1u}, 0x197900u,
            ra, 0u, 0u, 0u, task));
        auto entry = std::make_shared<ViewportEntry>();
        entry->call = call;
        entry->expectedBeforePc = call->entry();
        entry->stateInitialOpaque = upstreamOpaque_;
        entry->stateInitialRoles = compositionScalarRoles_;
        viewportEntries_.push_back(entry);
        ++upstreamOrdinal_;
        return call;
    }
    std::shared_ptr<ViewportEntry>
    exactOriginalStatePacket197900(const reo_gpu_upstream::CallHandle& call) const {
        if (!call || call->entry() != 0x197900u)
            throw std::invalid_argument("197900 foreign source Call");
        return exactOriginalViewport(call);
    }
    void allocateStateMetadata(const std::shared_ptr<ViewportEntry>& entry) {
        Vulkan::BufferCreateInfo ci{};
        ci.domain = Vulkan::BufferDomain::CachedHost;
        ci.usage = VK_BUFFER_USAGE_TRANSFER_DST_BIT;
        ci.size = reo_gpu_upstream::ReceiptBytes;
        entry->receiptHost = device_.create_buffer(ci);
        ci.size = reo_gpu_upstream::StatePacket197900::ControlBytes;
        entry->controlHost = device_.create_buffer(ci);
        ci.size = reo_gpu_upstream::StatePacketEffectsBytes;
        entry->stateEffectsHost = device_.create_buffer(ci);
        if (!entry->receiptHost || !entry->controlHost || !entry->stateEffectsHost)
            throw std::runtime_error("197900 immutable stage metadata allocation failed");
    }
    void submitStateMetadata(const std::shared_ptr<ViewportEntry>& entry) {
        entry->fence = gs_.submit_resident_completion([&](Vulkan::CommandBuffer& cmd) {
            const auto copy = [&](const Vulkan::Buffer& from, const Vulkan::Buffer& to) {
                cmd.buffer_barrier(from, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                   VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                                   VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
                cmd.copy_buffer(to, from);
                cmd.buffer_barrier(to, VK_PIPELINE_STAGE_TRANSFER_BIT,
                                   VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_HOST_BIT,
                                   VK_ACCESS_2_HOST_READ_BIT);
            };
            copy(entry->stateOutput->receipt(), *entry->receiptHost);
            copy(entry->stateOutput->control(), *entry->controlHost);
            copy(entry->stateOutput->effects(), *entry->stateEffectsHost);
        });
        if (!entry->fence)
            throw std::runtime_error("197900 lacks actual GS stage completion fence");
        entry->timeline = newTimeline();
        transport_->sealed(entry->timeline);
    }
    void recordOriginalStatePacket197900OnOwner(const reo_gpu_upstream::CallHandle& call,
                                                const std::vector<protocol::RawPatch>& patches) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        auto entry = exactOriginalStatePacket197900(call);
        (void)requireBoundRetainedInvocation(entry);
        if (entry->stateOutput || entry->output || entry->waited || entry->committed ||
            !entry->heapFrontier || !entry->queueCapture || !entry->queueResolver)
            throw std::invalid_argument(
                "197900 actual pre-dispatch source/heap/queue capture missing or repeated");
        producer_->verifyOriginalUpstreamOrder(call);
        try {
            allocateStateMetadata(entry);
            gs_.record_resident_command([&](Vulkan::CommandBuffer& cmd) {
                for (const auto& p : patches)
                    producer_->bridgeSourceWrite(cmd, p);
                const uint32_t limit = entry->heapFrontier->word(0x29fdbcu),
                               cursor = entry->heapFrontier->word(0x29fdc0u);
                producer_->bridgeRawWrite(cmd, unsigned(protocol::Space::Ram), 0x29fdbcu, &limit,
                                          4);
                producer_->bridgeRawWrite(cmd, unsigned(protocol::Space::Ram), 0x29fdc0u, &cursor,
                                          4);
                entry->stateOutput = producer_->recordOriginalStatePacket(cmd, call);
            });
            submitStateMetadata(entry);
        } catch (...) {
            observeOwnerSticky(190u);
            throw;
        }
    }
    void waitOriginalStatePacket197900OnOwner(const reo_gpu_upstream::CallHandle& call) {
        std::shared_ptr<ViewportEntry> entry;
        {
            std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
            requireHealthy();
            entry = exactOriginalStatePacket197900(call);
            if (!entry->stateOutput || !entry->fence || entry->waiting || entry->waited ||
                entry->committed)
                throw std::invalid_argument("197900 no new actual stage fence");
            entry->waiting = true;
        }
        try {
            entry->fence->wait();
            std::array<uint32_t, reo_gpu_upstream::ReceiptWords> receipt{};
            std::array<uint32_t, 32> control{};
            std::vector<uint32_t> metadata(reo_gpu_upstream::StatePacketEffectsWords);
            const auto read = [&](const Vulkan::Buffer& from, void* out, size_t bytes) {
                const auto* p = device_.map_host_buffer(from, Vulkan::MEMORY_ACCESS_READ_BIT);
                if (!p)
                    throw std::runtime_error("197900 integer metadata map failed");
                std::memcpy(out, p, bytes);
                device_.unmap_host_buffer(from, Vulkan::MEMORY_ACCESS_READ_BIT);
            };
            read(*entry->receiptHost, receipt.data(), sizeof(receipt));
            read(*entry->controlHost, control.data(), sizeof(control));
            read(*entry->stateEffectsHost, metadata.data(),
                 reo_gpu_upstream::StatePacketEffectsBytes);
            std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
            requireHealthy();
            if (exactOriginalStatePacket197900(call) != entry || !entry->waiting || entry->waited ||
                entry->stateOutput->realTimeline_ != entry->timeline ||
                receipt[17] != entry->expectedBeforePc)
                throw std::invalid_argument("197900 exact immutable stage lifetime changed");
            auto packet = reo_gpu_upstream::decodeStatePacketEffects(
                *call, receipt, control, metadata, entry->stateOutput->stage(),
                entry->statePriorInstructions);
            auto next = reo_source_closure::prepareGpuEffects(upstreamOpaque_,
                                                              compositionScalarRoles_, packet);
            // The original incoming lease is the scope entry, before stage1
            // clobbered these same saved registers. No byte-value comparison.
            for (const auto& d : packet.dirty)
                if (d.space == uint32_t(reo_source_closure::Space::Context) &&
                    d.role == uint32_t(reo_source_closure::Role::PreservedIncomingLease)) {
                    next.opaque = reo_source_closure::subtractOpaque(
                        next.opaque, {protocol::Space::Context, d.offset, d.bytes});
                    for (const auto& old : entry->stateInitialOpaque)
                        if (old.space == protocol::Space::Context) {
                            const auto begin = std::max(old.address, d.offset),
                                       end = std::min(old.address + old.bytes, d.offset + d.bytes);
                            if (begin < end)
                                next.opaque.push_back(
                                    {protocol::Space::Context, begin, end - begin});
                        }
                    std::copy(entry->stateInitialRoles.begin() + d.offset,
                              entry->stateInitialRoles.begin() + d.offset + d.bytes,
                              next.scalar.begin() + d.offset);
                }
            reo_source_closure::normalizeOpaque(next.opaque);
            retainCertifiedViewportRamControls(entry, packet, next);
            auto certified = std::shared_ptr<const reo_source_closure::CertifiedEffects>(
                new reo_source_closure::CertifiedEffects(
                    this, producer_->upstreamBanks_, call, entry->stateOutput->effects_,
                    entry->timeline, packet.header, packet.dirty, packet.control));
            entry->receipt = receipt;
            entry->control = control;
            entry->statePacket = std::move(packet);
            entry->stateCertificates.push_back(std::move(certified));
            entry->statePriorInstructions = receipt[19];
            entry->waiting = false;
            entry->waited = true;
            entry->controlHeld = control[3] != 3u;
            upstreamOpaque_ = std::move(next.opaque);
            compositionScalarRoles_ = next.scalar;
            completed_ = std::max(completed_, entry->timeline);
            transport_->retired(entry->timeline);
        } catch (...) {
            std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
            observeOwnerSticky(191u);
            throw;
        }
    }
    void resumeOriginalStatePacket197900OnOwner(
        const reo_gpu_upstream::CallHandle& call,
        const reo_gpu_upstream::StatePacket197900::ControlReturnHandle& token) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        auto entry = exactOriginalStatePacket197900(call);
        (void)requireBoundRetainedInvocation(entry);
        if (!token || token->issuer_ != this || entry->stateOutput != token->prior_ ||
            !entry->waited || entry->waiting || !entry->controlHeld || entry->committed)
            throw std::invalid_argument("197900 continuation lacks exact held output");
        try {
            entry->expectedBeforePc = token->continuation_;
            allocateStateMetadata(entry);
            gs_.record_resident_command([&](Vulkan::CommandBuffer& cmd) {
                entry->stateOutput = producer_->resumeOriginalStatePacket(cmd, token);
            });
            entry->waited = false;
            entry->controlHeld = false;
            submitStateMetadata(entry);
        } catch (...) {
            observeOwnerSticky(192u);
            throw;
        }
    }
    reo_gpu_upstream::StatePacket197900::ControlReturnHandle
    issueStateAllocatorReturnOnEe(const reo_gpu_upstream::AllocatorHeapCaptureHandle& capture) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        auto allocator = exactAllocator(capture);
        auto entry = exactOriginalStatePacket197900(capture->call_);
        if (!capture->stateStage_ || capture->stateStage_ != entry->stateOutput ||
            !allocator->cpuCommitted || allocator->returnIssued || allocator->receipt[3] != 1u ||
            !allocator->successorFrontier || entry->heapFrontier != allocator->successorFrontier)
            throw std::invalid_argument(
                "197900 allocation return lacks actual protected scalar commit");
        auto token = std::shared_ptr<const reo_gpu_upstream::StatePacket197900::ControlReturn>(
            new reo_gpu_upstream::StatePacket197900::ControlReturn(
                this, entry->stateOutput, 1u, 0x18ddd0u, capture->continuation_, capture->task_,
                allocator->timeline, allocator->output->receipt_, {}, allocator->output));
        allocator->stateReturned = token;
        allocator->returnIssued = true;
        return token;
    }
    void resumeStateAllocatorOnOwner(
        const reo_gpu_upstream::AllocatorHeapCaptureHandle& capture,
        const reo_gpu_upstream::StatePacket197900::ControlReturnHandle& token) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        auto allocator = exactAllocator(capture);
        if (allocator->resumed || allocator->stateReturned != token || !allocator->cpuCommitted)
            throw std::invalid_argument("197900 allocation continuation repeated/foreign");
        resumeOriginalStatePacket197900OnOwner(capture->call_, token);
        allocator->resumed = true;
        allocator->resumeTimeline = exactOriginalStatePacket197900(capture->call_)->timeline;
    }
    reo_gpu_upstream::StatePacket197900::ControlReturnHandle
    issueStateQueueReturnOnEe(const reo_gpu_upstream::QueueControlCallHandle& call) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        auto queue = exactViewportQueue(call);
        auto entry = exactOriginalStatePacket197900(queue->original);
        if (!queue->cpuCommitted || queue->returnIssued || !queue->successorFrontier ||
            !queue->journalWaited ||
            entry->stateOutput->control_ != call->immutableOriginalControl_)
            throw std::invalid_argument(
                "197900 queue return lacks actual completed/counter-committed output");
        auto token = std::shared_ptr<const reo_gpu_upstream::StatePacket197900::ControlReturn>(
            new reo_gpu_upstream::StatePacket197900::ControlReturn(
                this, entry->stateOutput, 2u, 0x18cfb0u, call->continuation_, call->actualTask_,
                queue->journalTimeline, queue->journal->receipt_, queue->journal->sourceJournal_,
                queue->journal));
        queue->stateReturned = token;
        queue->returnIssued = true;
        return token;
    }
    void
    resumeStateQueueOnOwner(const reo_gpu_upstream::QueueControlCallHandle& call,
                            const reo_gpu_upstream::StatePacket197900::ControlReturnHandle& token) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        auto queue = exactViewportQueue(call);
        if (queue->resumed || queue->stateReturned != token || !queue->cpuCommitted)
            throw std::invalid_argument("197900 queue continuation repeated/foreign");
        resumeOriginalStatePacket197900OnOwner(queue->original, token);
        queue->resumed = true;
        queue->resumeTimeline = exactOriginalStatePacket197900(queue->original)->timeline;
    }
    void commitOriginalStatePacket197900OnEe(const reo_gpu_upstream::CallHandle& call, uint8_t* ram,
                                             R5900Context& ctx, int32_t task) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        auto entry = exactOriginalStatePacket197900(call);
        if (!entry->waited || entry->waiting || entry->controlHeld || entry->committed ||
            entry->stateOutput->stage() != 3u || entry->receipt[3] != 3u ||
            !entry->heapFrontierReleased || ram != configuration_.cold->ram ||
            &ctx != activeSourceContextIdentity() || ctx.pc != call->entry() ||
            task != call->task())
            throw std::invalid_argument("197900 final EE publication precedes completed source or "
                                        "actual task reacquisition");
        uint32_t ra;
        std::memcpy(&ra, &ctx.r[31], 4);
        if (ra != call->returnPc())
            throw std::invalid_argument("197900 original incoming RA changed");
        auto retained = requireBoundRetainedInvocation(entry);
        validateRetainedCommitOnEe(retained, call, entry->timeline);
        auto next = reo_source_closure::prepareEeControlPublication(
            upstreamOpaque_, compositionScalarRoles_, entry->statePacket);
        for (const auto& c : entry->statePacket.control)
            std::memcpy(reinterpret_cast<uint8_t*>(&ctx) + c.contextOffset, c.bits.data(), c.bytes);
        upstreamOpaque_ = std::move(next.opaque);
        compositionScalarRoles_ = next.scalar;
        entry->committed = true;
        publishRetainedCommit(retained, entry->timeline);
        allocatorEntries_.erase(
            std::remove_if(allocatorEntries_.begin(), allocatorEntries_.end(),
                           [&](const auto& a) { return a->capture->call_ == call; }),
            allocatorEntries_.end());
        viewportEntries_.erase(std::remove(viewportEntries_.begin(), viewportEntries_.end(), entry),
                               viewportEntries_.end());
    }
    static constexpr bool StatePacketNaturalSourceClosureImplemented = false;

    bool hasOriginalViewportAllocator() const noexcept {
        return bool(producer_->viewportAllocator18DDD0_);
    }
    void
    bindViewportHeapOriginOnEe(const reo_gpu_upstream::CallHandle& call,
                               const std::shared_ptr<reo_parent_natural::ControlTarget>& owner,
                               const reo_parent_natural::ProtectedScalarCaptureHandle& frontier,
                               R5900Context& ctx) {
        // The ordinary NativeTarget capture must precede this first dispatch.
        // A generic opaque read cannot mint or refresh this inherited lease.
        auto* protectedOwner =
            owner ? dynamic_cast<reo_parent_natural::ProtectedScalarCaptureTarget*>(owner.get())
                  : nullptr;
        if (!protectedOwner || !frontier || owner->ramIdentity() != configuration_.cold->ram ||
            owner->contextIdentity() != &ctx || frontier->runtime() != owner->runtimeIdentity() ||
            frontier->context() != &ctx || frontier->epoch() != epoch_ ||
            frontier->task() != call->task() || !frontier->completedWriter(0x29fdbcu) ||
            !frontier->completedWriter(0x29fdc0u))
            throw std::invalid_argument(
                "Viewport heap origin lacks prior actual RAW scalar writers");
        protectedOwner->validateProtectedScalars(frontier, &ctx);
        owner->read(reo_parent_natural::SourceSpace::Ram, 0x18de2cu, 4, &ctx, ctx.pc);
        uint32_t sourceWord;
        std::memcpy(&sourceWord, static_cast<const uint8_t*>(configuration_.cold->ram) + 0x18de2cu,
                    4);
        if (sourceWord != 0xac24fdc0u)
            throw std::invalid_argument(
                "Viewport inherited original allocator instruction differs");
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        auto entry = exactOriginalViewport(call);
        if (!producer_->allocatorForCall(call) ||
            (call->entry() != 0x197900u &&
             !producer_->viewport18F970_->PreservesInheritedHeapControlLease) ||
            entry->output || entry->stateOutput || entry->heapFrontier || entry->heapSourceOwner ||
            ctx.pc != call->entry())
            throw std::invalid_argument(
                "Viewport heap lease must bind before its exact guarded GPU module starts");
        entry->heapFrontier = frontier;
        entry->heapSourceOwner = owner;
        entry->allocatorSourceWord = sourceWord;
    }
    std::shared_ptr<AllocatorEntry>
    exactAllocator(const reo_gpu_upstream::AllocatorHeapCaptureHandle& capture) const {
        if (!capture || capture->issuer_ != this || capture->banks_ != producer_->upstreamBanks_ ||
            capture->call_->stamp().session != configuration_.session ||
            capture->call_->stamp().epoch != epoch_ ||
            capture->call_->stamp().bankGeneration != generation_)
            throw std::invalid_argument("Allocator capture issuer/epoch/bank differs");
        for (const auto& entry : allocatorEntries_)
            if (entry->capture == capture)
                return entry;
        throw std::invalid_argument("Allocator capture was not issued by actual Service");
    }
    reo_gpu_upstream::AllocatorHeapCaptureHandle
    prepareOriginalAllocatorOnEe(const reo_gpu_upstream::CallHandle& call, PS2Runtime& runtime,
                                 uint8_t* ram, R5900Context& ctx) {
        if (!call)
            throw std::invalid_argument("Allocator has no genuine original viewport call");
        std::shared_ptr<ViewportEntry> viewport;
        std::shared_ptr<reo_parent_natural::ControlTarget> sourceOwner;
        reo_parent_natural::ProtectedScalarCaptureHandle frontier;
        {
            std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
            requireHealthy();
            viewport = exactOriginalViewport(call);
            if (!producer_->allocatorForCall(call) ||
                (call->entry() != 0x197900u &&
                 !producer_->viewport18F970_->PreservesInheritedHeapControlLease) ||
                ram != configuration_.cold->ram || &ctx != activeSourceContextIdentity() ||
                ctx.pc != call->entry() || !viewport->waited || !viewport->controlHeld ||
                viewport->control[3] != 1u || viewport->committed ||
                allocatorEntries_.size() >= 4096 || !viewport->heapFrontier ||
                viewport->heapFrontierReleased)
                throw std::invalid_argument(
                    "Allocator does not extend this genuine held viewport stage");
            frontier = viewport->heapFrontier;
            sourceOwner = viewport->heapSourceOwner;
        }
        auto* protectedOwner =
            sourceOwner
                ? dynamic_cast<reo_parent_natural::ProtectedScalarCaptureTarget*>(sourceOwner.get())
                : nullptr;
        if (!protectedOwner || sourceOwner->runtimeIdentity() != &runtime ||
            sourceOwner->contextIdentity() != &ctx || sourceOwner->ramIdentity() != ram ||
            sourceOwner->epoch() != call->stamp().epoch ||
            ps2ActualGuestExecutionDepth(&runtime) == 0u ||
            ps2_sched::currentThread() != call->task())
            throw std::invalid_argument(
                "Allocator lacks actual protected EE source/task/execution ownership");
        // Only the pre-dispatch RAW frontier, or its private certified scalar
        // successor, is inherited. No generic read of opaque RAM is performed.
        protectedOwner->validateProtectedScalars(frontier, &ctx);
        if (!frontier || frontier->runtime() != &runtime || frontier->context() != &ctx ||
            frontier->task() != call->task() || frontier->epoch() != call->stamp().epoch ||
            !frontier->completedWriter(0x29fdbcu) || !frontier->completedWriter(0x29fdc0u))
            throw std::invalid_argument("Allocator heap lacks authentic completed scalar writers");
        const uint32_t word = viewport->allocatorSourceWord;
        if (word != 0xac24fdc0u)
            throw std::invalid_argument("Allocator inherited original scalar event differs");
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        if (exactOriginalViewport(call) != viewport || !viewport->controlHeld ||
            viewport->control[3] != 1u || viewport->heapFrontier != frontier)
            throw std::invalid_argument("Allocator original held stage changed during capture");
        for (const auto& old : allocatorEntries_)
            if (old->capture->call_ == call)
                throw std::invalid_argument(
                    "This original held viewport stage already has an allocator capture");
        reo_gpu_upstream::AllocatorHeapCaptureHandle capture;
        if (call->entry() == 0x197900u)
            capture = std::shared_ptr<const reo_gpu_upstream::AllocatorHeapCapture>(
                new reo_gpu_upstream::AllocatorHeapCapture(
                    this, producer_->upstreamBanks_, call, viewport->stateOutput, &runtime, &ctx,
                    call->task(), frontier->captureOrdinal(), frontier->word(0x29fdbcu),
                    frontier->word(0x29fdc0u), viewport->control[15], word, frontier));
        else
            capture = std::shared_ptr<const reo_gpu_upstream::AllocatorHeapCapture>(
                new reo_gpu_upstream::AllocatorHeapCapture(
                    this, producer_->upstreamBanks_, call, viewport->output, &runtime, &ctx,
                    call->task(), frontier->captureOrdinal(), frontier->word(0x29fdbcu),
                    frontier->word(0x29fdc0u), viewport->control[15], word, frontier));
        auto entry = std::make_shared<AllocatorEntry>();
        entry->capture = capture;
        entry->sourceOwner = sourceOwner;
        allocatorEntries_.push_back(entry);
        return capture;
    }
    void
    recordOriginalAllocatorOnOwner(const reo_gpu_upstream::AllocatorHeapCaptureHandle& capture) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        auto entry = exactAllocator(capture);
        if (entry->output || entry->fence || entry->waited || entry->cpuCommitted)
            throw std::invalid_argument("Allocator original capture was already recorded");
        auto viewport = exactOriginalViewport(capture->call_);
        if ((capture->stateStage_ ? viewport->stateOutput != capture->stateStage_
                                  : viewport->output != capture->originalStage_) ||
            viewport->heapFrontier != capture->protectedScalarFrontier_ || !viewport->waited ||
            viewport->waiting || !viewport->controlHeld || viewport->control[3] != 1u ||
            viewport->control[15] != capture->continuation_ ||
            viewport->allocatorSourceWord != capture->sourceWord_ || viewport->committed)
            throw std::invalid_argument(
                "Allocator held source stage/frontier changed before RAW mirror");
        producer_->validateOriginalAllocator(
            capture); // Refuse chronology before either RAW mirror.
        try {
            Vulkan::BufferCreateInfo ci{};
            ci.domain = Vulkan::BufferDomain::CachedHost;
            ci.size = reo_gpu_upstream::ReceiptBytes;
            ci.usage = VK_BUFFER_USAGE_TRANSFER_DST_BIT;
            entry->host = device_.create_buffer(ci);
            if (!entry->host)
                throw std::runtime_error("Allocator scalar receipt readback allocation failed");
            gs_.record_resident_command([&](Vulkan::CommandBuffer& cmd) {
                // Only two actual captured scalar-control fields are mirrored.
                const uint32_t limit = capture->limit_, cursor = capture->cursor_;
                producer_->bridgeRawWrite(cmd, unsigned(protocol::Space::Ram), 0x29fdbcu, &limit,
                                          4);
                producer_->bridgeRawWrite(cmd, unsigned(protocol::Space::Ram), 0x29fdc0u, &cursor,
                                          4);
                entry->output = producer_->recordOriginalAllocator(cmd, capture);
            });
            entry->fence = gs_.submit_resident_completion([&](Vulkan::CommandBuffer& cmd) {
                const auto& source = entry->output->receipt();
                cmd.buffer_barrier(source, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                   VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                                   VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
                cmd.copy_buffer(*entry->host, source);
                cmd.buffer_barrier(*entry->host, VK_PIPELINE_STAGE_TRANSFER_BIT,
                                   VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_HOST_BIT,
                                   VK_ACCESS_2_HOST_READ_BIT);
            });
            if (!entry->fence)
                throw std::runtime_error("Allocator has no actual original GS completion fence");
            entry->timeline = newTimeline();
            transport_->sealed(entry->timeline);
        } catch (...) {
            observeOwnerSticky(172u);
            throw;
        }
    }
    void waitOriginalAllocatorOnOwner(const reo_gpu_upstream::AllocatorHeapCaptureHandle& capture) {
        std::shared_ptr<AllocatorEntry> entry;
        {
            std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
            requireHealthy();
            entry = exactAllocator(capture);
            if (!entry->output || !entry->fence || entry->waiting || entry->waited)
                throw std::invalid_argument("Allocator has no new actual owner output");
            entry->waiting = true;
        }
        try {
            entry->fence->wait();
            std::array<uint32_t, reo_gpu_upstream::ReceiptWords> receipt{};
            auto* bytes = device_.map_host_buffer(*entry->host, Vulkan::MEMORY_ACCESS_READ_BIT);
            if (!bytes)
                throw std::runtime_error("Allocator scalar result mapping failed");
            std::memcpy(receipt.data(), bytes, sizeof(receipt));
            device_.unmap_host_buffer(*entry->host, Vulkan::MEMORY_ACCESS_READ_BIT);
            std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
            requireHealthy();
            if (exactAllocator(capture) != entry || entry->waited || !entry->waiting)
                throw std::invalid_argument("Allocator immutable result lifetime changed");
            const auto p = reo_gpu_upstream::parameters(*capture->call_);
            if (receipt[0] || receipt[1] != 0x414c5231u || receipt[2] != 1u ||
                (receipt[3] != 1u && receipt[3] != 2u) || receipt[4] != p.sessionLo ||
                receipt[5] != p.sessionHi || receipt[6] != p.epochLo || receipt[7] != p.epochHi ||
                receipt[8] != p.bankLo || receipt[9] != p.bankHi || receipt[10] != p.ordinalLo ||
                receipt[11] != p.ordinalHi ||
                (uint64_t(receipt[12]) | (uint64_t(receipt[13]) << 32)) != capture->transaction_ ||
                receipt[14] != capture->cursor_ || receipt[17] != capture->continuation_ ||
                receipt[19] != uint32_t(capture->task_))
                throw std::runtime_error(
                    "Allocator actual output/transaction/source receipt refused");
            if (receipt[3] == 1u) {
                if (!receipt[16] || (receipt[16] & 15u) || receipt[16] < capture->cursor_ ||
                    receipt[15] != receipt[16] + ((capture->continuation_ == 0x197524u ||
                                                   capture->continuation_ == 0x197a94u)
                                                      ? 48u
                                                      : 64u) ||
                    receipt[15] > capture->limit_)
                    throw std::runtime_error("Allocator source pointer/heap result differs");
            } else if (receipt[15] != capture->cursor_ || receipt[16])
                throw std::runtime_error("Allocator overflow did not remain genuinely held");
            entry->receipt = receipt;
            entry->waiting = false;
            entry->waited = true;
            completed_ = std::max(completed_, entry->timeline);
            transport_->retired(entry->timeline);
        } catch (...) {
            std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
            observeOwnerSticky(173u);
            throw;
        }
    }
    reo_parent_natural::CertifiedControlCommitHandle
    issueAllocatorCommitOnEe(const reo_gpu_upstream::AllocatorHeapCaptureHandle& capture) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        auto entry = exactAllocator(capture);
        if (!entry->waited || entry->waiting || entry->cpuCommitted || entry->commit ||
            entry->receipt[3] != 1u || !entry->fence || entry->output->timeline_ != entry->timeline)
            throw std::invalid_argument("Allocator CPU commit lacks exact completed normal output");
        entry->commit = std::shared_ptr<const reo_parent_natural::CertifiedControlCommit>(
            new reo_parent_natural::CertifiedControlCommit(
                this, entry->output, capture->protectedScalarFrontier_, entry->timeline, 0x18de2cu,
                0xac24fdc0u, 0x29fdc0u, capture->cursor_, entry->receipt[15]));
        return entry->commit;
    }
    std::shared_ptr<AllocatorEntry>
    validateAllocatorCommitOnEe(const reo_parent_natural::CertifiedControlCommitHandle& commit,
                                R5900Context& ctx) const {
        requireHealthy();
        if (!commit || commit->issuer_ != this || commit->sourcePc_ != 0x18de2cu ||
            commit->sourceWord_ != 0xac24fdc0u || commit->address_ != 0x29fdc0u ||
            !commit->output_ || !commit->capture_)
            throw std::invalid_argument("Allocator commit is not an actual certified scalar event");
        auto entry = exactAllocator(commit->output_->capture_);
        const auto& capture = *entry->capture;
        if (entry->commit != commit || entry->output != commit->output_ ||
            entry->timeline != commit->realTimeline_ || !entry->waited || entry->cpuCommitted ||
            entry->receipt[3] != 1u || capture.protectedScalarFrontier_ != commit->capture_ ||
            capture.actualEeContext_ != &ctx || ctx.pc != capture.call_->entry() ||
            ps2ActualGuestExecutionDepth(
                static_cast<PS2Runtime*>(const_cast<void*>(capture.actualRuntime_))) == 0u ||
            ps2_sched::currentThread() != capture.task_ || commit->before_ != capture.cursor_ ||
            commit->after_ != entry->receipt[15])
            throw std::invalid_argument(
                "Allocator certified scalar ownership/result changed before commit");
        return entry;
    }
    reo_gpu_upstream::Viewport::ControlReturnHandle
    issueAllocatorReturnOnEe(const reo_gpu_upstream::AllocatorHeapCaptureHandle& capture) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        auto entry = exactAllocator(capture);
        if (!entry->cpuCommitted || entry->returnIssued || entry->receipt[3] != 1u)
            throw std::invalid_argument(
                "Allocator return precedes true protected heap commit or repeats");
        auto returned = std::shared_ptr<const reo_gpu_upstream::Viewport::ControlReturn>(
            new reo_gpu_upstream::Viewport::ControlReturn(
                this, capture->originalStage_, 1u, 0x18ddd0u, capture->continuation_,
                capture->task_, entry->timeline, entry->output->receipt_));
        entry->returned = returned;
        entry->returnIssued = true;
        return returned;
    }
    void resumeAllocatorViewportOnOwner(
        const reo_gpu_upstream::AllocatorHeapCaptureHandle& capture,
        const reo_gpu_upstream::Viewport::ControlReturnHandle& returned) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        auto allocator = exactAllocator(capture);
        auto entry = exactOriginalViewport(capture->call_);
        if (!allocator->cpuCommitted || !allocator->returnIssued || allocator->resumed ||
            allocator->returned != returned || !allocator->successorFrontier ||
            entry->heapFrontier != allocator->successorFrontier ||
            entry->output != capture->originalStage_ || !entry->waited || entry->waiting ||
            !entry->controlHeld || entry->committed)
            throw std::invalid_argument(
                "Viewport resume is not this exact certified normal allocation return");
        try {
            Vulkan::BufferCreateInfo ci{};
            ci.domain = Vulkan::BufferDomain::CachedHost;
            ci.size = reo_gpu_upstream::ReceiptBytes;
            ci.usage = VK_BUFFER_USAGE_TRANSFER_DST_BIT;
            auto receiptHost = device_.create_buffer(ci);
            ci.size = reo_gpu_upstream::Viewport::ControlBytes;
            auto controlHost = device_.create_buffer(ci);
            ci.size = reo_gpu_upstream::ViewportEffectsBytes;
            auto effectsHost = device_.create_buffer(ci);
            if (!receiptHost || !controlHost || !effectsHost)
                throw std::runtime_error("Viewport resumed scalar buffers missing");
            reo_gpu_upstream::Viewport::OutputHandle output;
            gs_.record_resident_command([&](Vulkan::CommandBuffer& cmd) {
                output = producer_->resumeOriginalViewport(cmd, returned);
            });
            auto fence = gs_.submit_resident_completion([&](Vulkan::CommandBuffer& cmd) {
                const auto copy = [&](const Vulkan::Buffer& source,
                                      const Vulkan::Buffer& destination) {
                    cmd.buffer_barrier(source, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                       VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                                       VK_PIPELINE_STAGE_TRANSFER_BIT,
                                       VK_ACCESS_2_TRANSFER_READ_BIT);
                    cmd.copy_buffer(destination, source);
                    cmd.buffer_barrier(destination, VK_PIPELINE_STAGE_TRANSFER_BIT,
                                       VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_HOST_BIT,
                                       VK_ACCESS_2_HOST_READ_BIT);
                };
                copy(output->receipt(), *receiptHost);
                copy(output->control(), *controlHost);
                copy(output->effects(), *effectsHost);
            });
            if (!fence)
                throw std::runtime_error("Viewport resumed stage has no actual GS fence");
            const uint64_t timeline = newTimeline();
            transport_->sealed(timeline);
            entry->priorStage = entry->control[29];
            entry->expectedBeforePc = capture->continuation_;
            entry->output = std::move(output);
            entry->fence = std::move(fence);
            entry->receiptHost = std::move(receiptHost);
            entry->controlHost = std::move(controlHost);
            entry->effectsHost = std::move(effectsHost);
            entry->certificate.reset();
            entry->timeline = timeline;
            entry->waited = false;
            entry->waiting = false;
            entry->controlHeld = false;
            allocator->resumeTimeline = timeline;
            allocator->resumed = true;
        } catch (...) {
            observeOwnerSticky(174u);
            throw;
        }
    }
    uint32_t viewportControlPhaseOnEe(const reo_gpu_upstream::CallHandle& call) const {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        auto entry = exactOriginalViewport(call);
        if (!entry->waited || entry->waiting || entry->committed)
            throw std::invalid_argument("Viewport phase has no immutable completed stage");
        return entry->control[3];
    }
    void releaseFinalViewportHeapOriginOnEe(const reo_gpu_upstream::CallHandle& call,
                                            R5900Context& ctx) {
        std::shared_ptr<ViewportEntry> entry;
        reo_parent_natural::ProtectedScalarCaptureHandle frontier;
        std::shared_ptr<reo_parent_natural::ControlTarget> owner;
        {
            std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
            requireHealthy();
            entry = exactOriginalViewport(call);
            if (!entry->waited || entry->controlHeld || entry->committed ||
                entry->receipt[3] != (call->entry() == 0x197900u ? 3u : 1u) ||
                ctx.pc != call->entry())
                throw std::invalid_argument(
                    "Heap origin release precedes exact final viewport return");
            for (const auto& allocator : allocatorEntries_)
                if (allocator->capture->call_ == call &&
                    (!allocator->cpuCommitted || !allocator->resumed ||
                     !allocator->resumeTimeline || allocator->resumeTimeline > entry->timeline))
                    throw std::invalid_argument(
                        "Final viewport return precedes allocator continuation fence");
            frontier = entry->heapFrontier;
            owner = entry->heapSourceOwner;
        }
        if (frontier) {
            auto* protectedOwner =
                owner ? dynamic_cast<reo_parent_natural::ProtectedScalarCaptureTarget*>(owner.get())
                      : nullptr;
            if (!protectedOwner)
                throw std::logic_error("Viewport lost its genuine protected heap issuer");
            protectedOwner->releaseProtectedScalars(frontier, &ctx);
        }
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        if (exactOriginalViewport(call) != entry || entry->heapFrontier != frontier)
            throw std::invalid_argument("Final heap lease changed while releasing");
        entry->heapFrontierReleased = true;
    }
    static constexpr bool AllocatorOverflowSourceClosureImplemented = false;
    static constexpr bool AllocatorCompleteNativeWriterCoverageImplemented = false;

  public:
  private:
    Vulkan::BufferHandle heldSourceControl(const std::shared_ptr<ViewportEntry>& e) const {
        return e->stateOutput ? e->stateOutput->control_ : e->output->control_;
    }
    bool hasViewportQueueModules() const noexcept {
        return bool(producer_->viewportQueueHeaders_) && bool(producer_->viewportQueueJournal_);
    }
    std::shared_ptr<QueueEntry>
    exactViewportQueue(const reo_gpu_upstream::QueueControlCallHandle& call) const {
        if (!call || call->issuer_ != this || call->banks_ != producer_->upstreamBanks_)
            throw std::invalid_argument("Queue call is foreign/unissued");
        for (const auto& entry : queueEntries_)
            if (entry->call == call)
                return entry;
        throw std::invalid_argument("Queue call not issued by actual held viewport Service");
    }
    reo_gpu_upstream::QueueControlCallHandle
    prepareViewportQueueOnEe(const reo_gpu_upstream::CallHandle& original, R5900Context& ctx) {
        std::shared_ptr<ViewportEntry> viewport;
        reo_gpu_upstream::ProtectedQueueCaptureHandle capture;
        {
            std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
            requireHealthy();
            viewport = exactOriginalViewport(original);
            if (!viewport->waited || viewport->waiting || !viewport->controlHeld ||
                viewport->control[3] != 2u || viewport->committed || !viewport->queueCapture ||
                queueEntries_.size() >= 4096 || ctx.pc != original->entry())
                throw std::invalid_argument(
                    "Queue capture does not extend this exact genuine held viewport stage");
            for (const auto& old : queueEntries_)
                if (old->original == original)
                    throw std::invalid_argument("Queue stage was already captured");
            capture = viewport->queueCapture;
        }
        // Strong actual NativeTarget capture and range leases are inherited;
        // no ordinary RAM read occurs after the numerical GPU source.
        auto owner = viewport->heapSourceOwner;
        auto* native =
            owner ? dynamic_cast<reo_parent_natural::ProtectedScalarCaptureTarget*>(owner.get())
                  : nullptr;
        if (!native || capture->issuer_ != this || capture->call_ != original ||
            capture->resolver_ != viewport->queueResolver ||
            capture->frontier_->context() != &ctx ||
            capture->frontier_->task() != original->task() ||
            capture->frontier_->epoch() != epoch_ || !capture->frontier_->completedSequence())
            throw std::invalid_argument("Queue lost its genuine protected source frontier");
        native->validateProtectedScalars(capture->frontier_, &ctx);
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        if (exactOriginalViewport(original) != viewport || viewport->queueCapture != capture ||
            viewport->control[3] != 2u)
            throw std::invalid_argument("Queue held source changed during reacquired EE capture");
        const auto& c = viewport->control;
        const auto pair = [&](unsigned k) { return uint64_t(c[k]) | (uint64_t(c[k + 1]) << 32); };
        auto call = std::shared_ptr<const reo_gpu_upstream::QueueControlCall>(
            new reo_gpu_upstream::QueueControlCall(
                this, producer_->upstreamBanks_, original->stamp(), original->task(), original,
                heldSourceControl(viewport), viewport->timeline,
                {pair(16), pair(18), pair(20), pair(22)}, pair(24),
                original->entry() == 0x197900u ? uint64_t(c[15]) : pair(26), c[15] - 8, c[15],
                capture->resolver_));
        const uint32_t previous = capture->frontier_->word(0x29f728u),
                       queueSp = uint32_t(call->sp_);
        if (previous) {
            if ((previous & 3u) || !protocol::range(previous, 8, reo_gpu_upstream::RamBytes) ||
                queueSp < 96u ||
                protocol::overlap(previous, 8, queueSp - 96u,
                                  original->entry() == 0x197900u ? 144u : 96u) ||
                protocol::overlap(previous, 8, 0x29fdb4u, 16) ||
                protocol::overlap(previous, 8, 0x29f6f0u, 60) ||
                protocol::overlap(previous, 8, 0x241bf0u, 24) ||
                protocol::overlap(previous, 8, 0x18cfb0u, 0x1b0u) ||
                protocol::overlap(previous, 8, 0x18de2cu, 4))
                throw std::invalid_argument(
                    "Queue previous header aliases protected source/control/private stack");
        }
        if (previous)
            for (const auto& value : capture->lookup_)
                if (protocol::overlap(previous, 8, value.address, 4))
                    throw std::invalid_argument(
                        "Queue previous header aliases retained original pool metadata");
        std::vector<reo_gpu_upstream::QueueWord> words;
        const auto add = [&](uint32_t site, uint32_t at, reo_gpu_upstream::QueueField role) {
            words.push_back({site, at, capture->frontier_->word(at), role});
        };
        const uint32_t index = capture->frontier_->word(0x29fdb4u);
        if (index > 1u)
            throw std::invalid_argument(
                "Queue protected double-buffer index outside source domain");
        const uint32_t b = 0x29f6f0u + index * 4u;
        add(0x18cfe4u, 0x29f6f4u, reo_gpu_upstream::QueueField::ProtectedCpuQueue);
        add(0x18cfe8u, 0x29fdb4u, reo_gpu_upstream::QueueField::ProtectedCpuQueue);
        for (uint32_t site : {0x18cff8u, 0x18d010u, 0x18d01cu})
            add(site, b + 20u, reo_gpu_upstream::QueueField::ProtectedCpuQueue);
        add(0x18d00cu, b + 12u, reo_gpu_upstream::QueueField::ProtectedCpuQueue);
        for (uint32_t site : {0x18d020u, 0x18d02cu, 0x18d038u, 0x18d048u})
            add(site, b + 28u, reo_gpu_upstream::QueueField::ProtectedCpuQueue);
        add(0x18d03cu, 0x29f6f4u, reo_gpu_upstream::QueueField::ProtectedCpuQueue);
        for (uint32_t site : {0x18d05cu, 0x18d04cu, 0x18d118u, 0x18d124u, 0x18d134u})
            add(site, 0x29f724u, reo_gpu_upstream::QueueField::ProtectedCpuQueue);
        for (uint32_t site : {0x18d068u, 0x18d058u, 0x18d120u, 0x18d128u, 0x18d13cu})
            add(site, 0x29f728u, reo_gpu_upstream::QueueField::ProtectedCpuQueue);
        for (const auto& value : capture->lookup_)
            words.push_back({value.sourcePc, value.address, value.bits,
                             reo_gpu_upstream::QueueField::ProtectedCpuLookup});
        for (const auto& code : capture->jumpTable_)
            words.push_back({code.sourcePc, code.address, code.bits,
                             reo_gpu_upstream::QueueField::ProtectedCpuLookup});
        // Only the selected ring word is a blind source overwrite. Its old
        // contents can be numeric/opaque and are never read by CPU planning.
        const uint32_t capacity = capture->frontier_->word(0x29f6f4u),
                       ringBase = capture->resolvedRing_,
                       ringIndex = capture->frontier_->word(b + 28u);
        std::optional<reo_gpu_upstream::ProtectedQueueSnapshot::RingDestination> ring;
        if (capacity && ringIndex < capacity && !(ringBase & 3u) &&
            ringBase < reo_gpu_upstream::RamBytes &&
            uint64_t(ringBase) + uint64_t(ringIndex) * 4u + 4u <= reo_gpu_upstream::RamBytes) {
            const uint32_t dest = ringBase + ringIndex * 4u, sp = uint32_t(call->sp_);
            if (protocol::overlap(dest, 4, 0x29fdb4u, 16) ||
                protocol::overlap(dest, 4, 0x29f6f0u, 60) ||
                protocol::overlap(dest, 4, 0x241bf0u, 24) ||
                protocol::overlap(dest, 4, sp - 96u, original->entry() == 0x197900u ? 144u : 96u))
                throw std::invalid_argument(
                    "Queue ring aliases retained controls/code/private stack");
            for (const auto& value : capture->lookup_)
                if (protocol::overlap(dest, 4, value.address, 4))
                    throw std::invalid_argument(
                        "Queue managed ring aliases retained original pool metadata");
            for (const auto& code : capture->writeCode_)
                if (protocol::overlap(dest, 4, code.address, 4))
                    throw std::invalid_argument("Queue ring overwrites retained write source");
            ring = reo_gpu_upstream::ProtectedQueueSnapshot::RingDestination{
                0x18d034u, dest, ringBase, capacity, ringIndex};
        }
        auto snapshot = std::shared_ptr<const reo_gpu_upstream::ProtectedQueueSnapshot>(
            new reo_gpu_upstream::ProtectedQueueSnapshot(
                this, capture->frontier_->runtime(), original->stamp(),
                capture->frontier_->completedSequence(), original->task(), std::move(words),
                capture, std::move(ring)));
        auto entry = std::make_shared<QueueEntry>();
        entry->original = original;
        entry->capture = capture;
        entry->call = call;
        entry->snapshot = snapshot;
        queueEntries_.push_back(entry);
        return call;
    }
    void recordViewportQueueHeaderOnOwner(const reo_gpu_upstream::QueueControlCallHandle& call) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        auto entry = exactViewportQueue(call);
        if (entry->query || entry->queryFence || entry->queryWaited ||
            !producer_->queueHeaderForCall(entry->original))
            throw std::invalid_argument("Queue header query absent/reused/default-off");
        auto viewport = exactOriginalViewport(entry->original);
        if (viewport->queueCapture != entry->capture ||
            heldSourceControl(viewport) != call->immutableOriginalControl_ || !viewport->waited ||
            viewport->control[3] != 2u)
            throw std::invalid_argument("Queue header source stage changed before owner query");
        try {
            const auto& s = call->stamp_;
            const uint64_t revision = entry->snapshot->protectedCpuRevision_;
            const uint32_t previous = entry->capture->frontier_->word(0x29f728u);
            const std::array<uint32_t, 20> certificate{0u,
                                                       0x51504331u,
                                                       1u,
                                                       1u,
                                                       uint32_t(s.session),
                                                       uint32_t(s.session >> 32),
                                                       uint32_t(s.epoch),
                                                       uint32_t(s.epoch >> 32),
                                                       uint32_t(s.bankGeneration),
                                                       uint32_t(s.bankGeneration >> 32),
                                                       uint32_t(s.ordinal),
                                                       uint32_t(s.ordinal >> 32),
                                                       0x29f728u,
                                                       previous,
                                                       uint32_t(revision),
                                                       uint32_t(revision >> 32),
                                                       uint32_t(call->actualTask_),
                                                       0u,
                                                       0u,
                                                       0u};
            Vulkan::BufferCreateInfo ci{};
            ci.domain = Vulkan::BufferDomain::Device;
            ci.size = 80;
            ci.usage = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT |
                       VK_BUFFER_USAGE_TRANSFER_DST_BIT;
            auto exact = device_.create_buffer(ci, certificate.data());
            if (!exact)
                throw std::runtime_error(
                    "Queue exact protected integer certificate allocation failed");
            entry->imported = std::shared_ptr<const reo_gpu_upstream::ProtectedCounterImport>(
                new reo_gpu_upstream::ProtectedCounterImport(this, producer_->upstreamBanks_,
                                                             entry->snapshot, std::move(exact)));
            ci.domain = Vulkan::BufferDomain::CachedHost;
            ci.size = 160;
            ci.usage = VK_BUFFER_USAGE_TRANSFER_DST_BIT;
            entry->queryHost = device_.create_buffer(ci);
            if (!entry->queryHost)
                throw std::runtime_error("Queue immutable header receipt allocation failed");
            producer_->queueHeaderForCall(entry->original)
                ->validateRecord(call, entry->imported); // Before any bank mirror.
            gs_.record_resident_command([&](Vulkan::CommandBuffer& cmd) {
                // Every imported word is an inherited protected integer
                // control, never the padded CPU image of an opaque packet.
                const uint32_t selected = entry->capture->frontier_->word(0x29fdb4u),
                               base = 0x29f6f0u + selected * 4u;
                for (uint32_t at :
                     {0x29f6f4u, base + 12u, base + 20u, base + 28u, 0x29f724u, 0x29f728u}) {
                    const uint32_t word = entry->capture->frontier_->word(at);
                    producer_->bridgeRawWrite(cmd, unsigned(protocol::Space::Ram), at, &word, 4);
                }
                for (const auto& value : entry->capture->lookup_)
                    producer_->bridgeRawWrite(cmd, unsigned(protocol::Space::Ram), value.address,
                                              &value.bits, 4);
                const uint32_t index = entry->capture->frontier_->word(0x29fdb4u);
                producer_->bridgeRawWrite(cmd, unsigned(protocol::Space::Ram), 0x29fdb4u, &index,
                                          4);
                entry->query = producer_->queueHeaderForCall(entry->original)
                                   ->record(cmd, call, entry->imported);
            });
            entry->queryFence = gs_.submit_resident_completion([&](Vulkan::CommandBuffer& cmd) {
                const auto& buffer = entry->query->metadata();
                cmd.buffer_barrier(buffer, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                   VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                                   VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
                cmd.copy_buffer(*entry->queryHost, buffer);
                cmd.buffer_barrier(*entry->queryHost, VK_PIPELINE_STAGE_TRANSFER_BIT,
                                   VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_HOST_BIT,
                                   VK_ACCESS_2_HOST_READ_BIT);
            });
            if (!entry->queryFence)
                throw std::runtime_error("Queue header lacks actual existing GS completion fence");
            entry->queryTimeline = newTimeline();
            transport_->sealed(entry->queryTimeline);
        } catch (...) {
            observeOwnerSticky(180u);
            throw;
        }
    }
    void waitViewportQueueHeaderOnOwner(const reo_gpu_upstream::QueueControlCallHandle& call) {
        std::shared_ptr<QueueEntry> entry;
        {
            std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
            requireHealthy();
            entry = exactViewportQueue(call);
            if (!entry->query || !entry->queryFence || entry->queryWaiting || entry->queryWaited)
                throw std::invalid_argument("Queue header has no new genuine owner completion");
            entry->queryWaiting = true;
        }
        try {
            entry->queryFence->wait();
            std::array<uint32_t, 40> words{};
            auto* bytes =
                device_.map_host_buffer(*entry->queryHost, Vulkan::MEMORY_ACCESS_READ_BIT);
            if (!bytes)
                throw std::runtime_error("Queue integer header receipt map failed");
            std::memcpy(words.data(), bytes, sizeof(words));
            device_.unmap_host_buffer(*entry->queryHost, Vulkan::MEMORY_ACCESS_READ_BIT);
            std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
            requireHealthy();
            if (exactViewportQueue(call) != entry || !entry->queryWaiting || entry->queryWaited)
                throw std::invalid_argument(
                    "Queue header immutable lifetime changed during true wait");
            entry->headers = producer_->queueHeaderForCall(entry->original)
                                 ->certify(entry->query, entry->queryTimeline, words);
            entry->queryWaiting = false;
            entry->queryWaited = true;
            completed_ = std::max(completed_, entry->queryTimeline);
            transport_->retired(entry->queryTimeline);
        } catch (...) {
            std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
            observeOwnerSticky(181u);
            throw;
        }
    }
    static constexpr bool ViewportActualAllocatorReturnIssuerImplemented = false;
    static constexpr bool ViewportActualQueueCounterCommitImplemented = false;
    static constexpr bool ViewportIrqHeaderConsumersImplemented = false;
    static constexpr bool ViewportNaturalSourceClosureImplemented = false;

  public:
  private:
  private:
    void prepareViewportQueuePlanOnEe(const reo_gpu_upstream::QueueControlCallHandle& call,
                                      R5900Context& ctx) {
        std::shared_ptr<QueueEntry> entry;
        {
            std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
            requireHealthy();
            entry = exactViewportQueue(call);
            if (!entry->queryWaited || entry->queryWaiting || !entry->headers || entry->plan ||
                entry->journal || !producer_->queueJournalForCall(entry->original) ||
                ctx.pc != entry->original->entry())
                throw std::invalid_argument(
                    "Queue plan requires exact held GPU header receipt on reacquired EE");
        }
        std::shared_ptr<ViewportEntry> viewport;
        {
            std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
            viewport = exactOriginalViewport(entry->original);
        }
        auto* owner = dynamic_cast<reo_parent_natural::ProtectedScalarCaptureTarget*>(
            viewport->heapSourceOwner.get());
        if (!owner)
            throw std::logic_error("Queue source frontier lost actual NativeTarget");
        owner->validateProtectedScalars(entry->capture->frontier_, &ctx);
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        if (exactViewportQueue(call) != entry || entry->plan || !entry->queryWaited)
            throw std::invalid_argument("Queue plan source changed during EE verification");
        reo_gpu_upstream::QueueControlAdapter adapter(this, producer_->upstreamBanks_);
        auto plan =
            adapter.plan(call, entry->headers,
                         entry->snapshot); // Every read/destination validates before recording.
        producer_->queueJournalForCall(entry->original)->validateRecord(plan);
        entry->plan = std::move(plan);
    }
    void recordViewportQueueJournalOnOwner(const reo_gpu_upstream::QueueControlCallHandle& call) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        auto entry = exactViewportQueue(call);
        if (!entry->plan || entry->journal || entry->journalFence || entry->journalWaited ||
            !producer_->queueJournalForCall(entry->original))
            throw std::invalid_argument("Queue journal absent/repeated/default-off");
        auto viewport = exactOriginalViewport(entry->original);
        if (viewport->queueCapture != entry->capture || !viewport->waited ||
            !viewport->controlHeld || viewport->control[3] != 2u ||
            heldSourceControl(viewport) != call->immutableOriginalControl_)
            throw std::invalid_argument(
                "Queue genuine held viewport stage changed before ordered record");
        producer_->queueJournalForCall(entry->original)->validateRecord(entry->plan);
        try {
            Vulkan::BufferCreateInfo ci{};
            ci.domain = Vulkan::BufferDomain::CachedHost;
            ci.size = reo_gpu_upstream::ReceiptBytes;
            ci.usage = VK_BUFFER_USAGE_TRANSFER_DST_BIT;
            entry->journalHost = device_.create_buffer(ci);
            if (!entry->journalHost)
                throw std::runtime_error("Queue journal immutable receipt allocation failed");
            gs_.record_resident_command([&](Vulkan::CommandBuffer& cmd) {
                entry->journal =
                    producer_->queueJournalForCall(entry->original)->record(cmd, entry->plan);
            });
            entry->journalFence = gs_.submit_resident_completion([&](Vulkan::CommandBuffer& cmd) {
                const auto& b = entry->journal->receipt();
                cmd.buffer_barrier(b, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                   VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                                   VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
                cmd.copy_buffer(*entry->journalHost, b);
                cmd.buffer_barrier(*entry->journalHost, VK_PIPELINE_STAGE_TRANSFER_BIT,
                                   VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_HOST_BIT,
                                   VK_ACCESS_2_HOST_READ_BIT);
            });
            if (!entry->journalFence)
                throw std::runtime_error("Queue journal lacks genuine GS completion fence");
            entry->journalTimeline = newTimeline();
            transport_->sealed(entry->journalTimeline);
        } catch (...) {
            observeOwnerSticky(182u);
            throw;
        }
    }
    void waitViewportQueueJournalOnOwner(const reo_gpu_upstream::QueueControlCallHandle& call) {
        std::shared_ptr<QueueEntry> entry;
        {
            std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
            requireHealthy();
            entry = exactViewportQueue(call);
            if (!entry->journal || !entry->journalFence || entry->journalWaiting ||
                entry->journalWaited)
                throw std::invalid_argument("Queue ordered event has no new true owner wait");
            entry->journalWaiting = true;
        }
        try {
            entry->journalFence->wait();
            std::array<uint32_t, reo_gpu_upstream::ReceiptWords> words{};
            auto* data =
                device_.map_host_buffer(*entry->journalHost, Vulkan::MEMORY_ACCESS_READ_BIT);
            if (!data)
                throw std::runtime_error("Queue immutable receipt mapping failed");
            std::memcpy(words.data(), data, sizeof(words));
            device_.unmap_host_buffer(*entry->journalHost, Vulkan::MEMORY_ACCESS_READ_BIT);
            std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
            requireHealthy();
            if (exactViewportQueue(call) != entry || entry->journalWaited ||
                !entry->journalWaiting || entry->journal->realTimeline_ != entry->journalTimeline)
                throw std::invalid_argument("Queue event/fence lifetime changed");
            const auto p = reo_gpu_upstream::parameters(*entry->original);
            if (words[0] || words[1] != 0x514a5231u || words[2] != 1u || words[3] != 1u ||
                words[4] != p.sessionLo || words[5] != p.sessionHi || words[6] != p.epochLo ||
                words[7] != p.epochHi || words[8] != p.bankLo || words[9] != p.bankHi ||
                words[10] != p.ordinalLo || words[11] != p.ordinalHi ||
                words[12] != call->originalJal_ || words[13] != call->continuation_ ||
                (uint64_t(words[14]) | (uint64_t(words[15]) << 32)) != entry->plan->returnValue_ ||
                (uint64_t(words[16]) | (uint64_t(words[17]) << 32)) !=
                    entry->snapshot->protectedCpuRevision_ ||
                words[18] != call->continuation_)
                throw std::runtime_error("Queue exact actual output/control receipt refused");
            entry->journalReceipt = words;
            entry->journalWaiting = false;
            entry->journalWaited = true;
            completed_ = std::max(completed_, entry->journalTimeline);
            transport_->retired(entry->journalTimeline);
        } catch (...) {
            std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
            observeOwnerSticky(183u);
            throw;
        }
    }
    reo_parent_natural::CertifiedQueueCommitHandle
    issueViewportQueueCommitOnEe(const reo_gpu_upstream::QueueControlCallHandle& call) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        auto entry = exactViewportQueue(call);
        if (!entry->journalWaited || entry->journalWaiting || entry->cpuCommitted ||
            entry->commit || entry->journalReceipt[3] != 1u ||
            entry->journal->realTimeline_ != entry->journalTimeline)
            throw std::invalid_argument("Queue commit lacks exact genuinely completed event");
        std::vector<reo_parent_natural::CertifiedQueueCommit::Store> stores;
        stores.reserve(16);
        for (const auto& op : entry->plan->ordered_) {
            if (op.op != reo_gpu_upstream::QueueOperation::ProtectedCpuWord &&
                op.op != reo_gpu_upstream::QueueOperation::ManagedRingOverwrite)
                continue;
            std::optional<uint32_t> word;
            for (const auto& code : entry->capture->writeCode_)
                if (code.sourcePc == op.sourcePc) {
                    if (word)
                        throw std::logic_error("Queue write source duplicate");
                    word = code.bits;
                }
            if (!word)
                throw std::invalid_argument(
                    "Queue store has no retained original instruction witness");
            stores.push_back({op.sourcePc, *word, op.address, op.word1, op.word0,
                              op.op == reo_gpu_upstream::QueueOperation::ManagedRingOverwrite});
        }
        if (stores.empty() || stores.size() > 16)
            throw std::invalid_argument("Queue source scalar store event domain differs");
        entry->commit = std::shared_ptr<const reo_parent_natural::CertifiedQueueCommit>(
            new reo_parent_natural::CertifiedQueueCommit(
                this, entry->journal, call, entry->capture->frontier_, entry->journalTimeline,
                std::move(stores)));
        return entry->commit;
    }
    std::shared_ptr<QueueEntry>
    validateViewportQueueCommitOnEe(const reo_parent_natural::CertifiedQueueCommitHandle& commit,
                                    R5900Context& ctx) const {
        requireHealthy();
        if (!commit || commit->issuer_ != this || !commit->call_ || !commit->output_ ||
            !commit->frontier_)
            throw std::invalid_argument("Queue scalar event foreign/unissued");
        auto entry = exactViewportQueue(commit->call_);
        if (entry->commit != commit || entry->journal != commit->output_ ||
            entry->capture->frontier_ != commit->frontier_ || entry->cpuCommitted ||
            !entry->journalWaited || entry->journalWaiting ||
            entry->journalTimeline != commit->actualTimeline_ ||
            entry->journal->realTimeline_ != commit->actualTimeline_ ||
            entry->journalReceipt[3] != 1u || ctx.pc != entry->original->entry() ||
            commit->frontier_->context() != &ctx ||
            ps2_sched::currentThread() != entry->original->task() ||
            ps2ActualGuestExecutionDepth(commit->frontier_->runtime()) == 0u)
            throw std::invalid_argument(
                "Queue scalar commit lost completed source/fence/protected EE identity");
        return entry;
    }
    reo_gpu_upstream::Viewport::ControlReturnHandle
    issueViewportQueueReturnOnEe(const reo_gpu_upstream::QueueControlCallHandle& call) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        auto entry = exactViewportQueue(call);
        auto viewport = exactOriginalViewport(entry->original);
        if (!entry->cpuCommitted || entry->returnIssued || !entry->successorFrontier ||
            !entry->journalWaited || heldSourceControl(viewport) != call->immutableOriginalControl_)
            throw std::invalid_argument(
                "Queue return precedes actual scalar publication or repeats");
        entry->returned = std::shared_ptr<const reo_gpu_upstream::Viewport::ControlReturn>(
            new reo_gpu_upstream::Viewport::ControlReturn(
                this, viewport->output, 2u, 0x18cfb0u, call->continuation_, call->actualTask_,
                entry->journalTimeline, entry->journal->receipt_, entry->journal->sourceJournal_));
        entry->returnIssued = true;
        return entry->returned;
    }
    void
    resumeViewportQueueOnOwner(const reo_gpu_upstream::QueueControlCallHandle& call,
                               const reo_gpu_upstream::Viewport::ControlReturnHandle& returned) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        auto queue = exactViewportQueue(call);
        auto entry = exactOriginalViewport(queue->original);
        if (!queue->cpuCommitted || !queue->returnIssued || queue->returned != returned ||
            queue->resumed || !entry->waited || !entry->controlHeld || entry->control[3] != 2u ||
            entry->committed || entry->output != returned->prior_)
            throw std::invalid_argument("Queue viewport resume is not its genuine "
                                        "completed/counter-committed control return");
        try {
            Vulkan::BufferCreateInfo ci{};
            ci.domain = Vulkan::BufferDomain::CachedHost;
            ci.size = reo_gpu_upstream::ReceiptBytes;
            ci.usage = VK_BUFFER_USAGE_TRANSFER_DST_BIT;
            auto receipt = device_.create_buffer(ci);
            ci.size = reo_gpu_upstream::Viewport::ControlBytes;
            auto control = device_.create_buffer(ci);
            ci.size = reo_gpu_upstream::ViewportEffectsBytes;
            auto effects = device_.create_buffer(ci);
            if (!receipt || !control || !effects)
                throw std::runtime_error("Queue continuation immutable receipts absent");
            reo_gpu_upstream::Viewport::OutputHandle output;
            gs_.record_resident_command([&](Vulkan::CommandBuffer& cmd) {
                output = producer_->resumeOriginalViewport(cmd, returned);
            });
            auto fence = gs_.submit_resident_completion([&](Vulkan::CommandBuffer& cmd) {
                const auto copy = [&](const Vulkan::Buffer& a, const Vulkan::Buffer& b) {
                    cmd.buffer_barrier(a, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                       VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                                       VK_PIPELINE_STAGE_TRANSFER_BIT,
                                       VK_ACCESS_2_TRANSFER_READ_BIT);
                    cmd.copy_buffer(b, a);
                    cmd.buffer_barrier(b, VK_PIPELINE_STAGE_TRANSFER_BIT,
                                       VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_HOST_BIT,
                                       VK_ACCESS_2_HOST_READ_BIT);
                };
                copy(output->receipt(), *receipt);
                copy(output->control(), *control);
                copy(output->effects(), *effects);
            });
            if (!fence)
                throw std::runtime_error("Queue continuation lacks true GS fence");
            const uint64_t timeline = newTimeline();
            transport_->sealed(timeline);
            entry->priorStage = entry->control[29];
            entry->expectedBeforePc = call->continuation_;
            entry->output = std::move(output);
            entry->fence = std::move(fence);
            entry->receiptHost = std::move(receipt);
            entry->controlHost = std::move(control);
            entry->effectsHost = std::move(effects);
            entry->certificate.reset();
            entry->timeline = timeline;
            entry->waited = false;
            entry->waiting = false;
            entry->controlHeld = false;
            queue->resumeTimeline = timeline;
            queue->resumed = true;
        } catch (...) {
            observeOwnerSticky(184u);
            throw;
        }
    }
    void releaseFinalViewportQueueOnEe(const reo_gpu_upstream::CallHandle& original,
                                       R5900Context& ctx) {
        std::shared_ptr<QueueEntry> queue;
        std::shared_ptr<ViewportEntry> viewport;
        {
            std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
            requireHealthy();
            viewport = exactOriginalViewport(original);
            for (const auto& e : queueEntries_)
                if (e->original == original)
                    queue = e;
            if (!queue)
                return;
            if (!viewport->waited || viewport->controlHeld || viewport->committed ||
                viewport->receipt[3] != (original->entry() == 0x197900u ? 3u : 1u) ||
                !queue->cpuCommitted || !queue->resumed || !queue->resumeTimeline ||
                queue->resumeTimeline > viewport->timeline || ctx.pc != original->entry())
                throw std::invalid_argument(
                    "Queue lease retirement precedes true final viewport completion");
        }
        auto* owner = dynamic_cast<reo_parent_natural::ProtectedScalarCaptureTarget*>(
            viewport->heapSourceOwner.get());
        if (!owner)
            throw std::logic_error("Queue final scalar issuer absent");
        owner->releaseProtectedScalars(queue->successorFrontier, &ctx);
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        if (exactOriginalViewport(original) != viewport || exactViewportQueue(queue->call) != queue)
            throw std::invalid_argument("Queue release lifetime changed");
        producer_->queueHeaderForCall(original)->releaseCertified(queue->query, queue->headers,
                                                                  queue->queryTimeline);
        producer_->queueJournalForCall(original)->releaseConsumed(queue->journal,
                                                                  queue->journalTimeline);
        queueEntries_.erase(std::remove(queueEntries_.begin(), queueEntries_.end(), queue),
                            queueEntries_.end());
    }

    void requireCompleteViewportQueueIssuer() const {
        requireHealthy();
        {
            std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
            if (viewportEntries_.size() == 1u) {
                const auto& entry = viewportEntries_.front();
                if (entry->retainedInvocationBound) {
                    auto ticket = requireBoundRetainedInvocation(entry);
                    if ((entry->call->entry() != 0x197900u &&
                         !reo_gpu_upstream::Viewport::supports(entry->call->entry())) ||
                        !entry->queueCapture || !entry->queueResolver || !entry->heapSourceOwner)
                        throw std::invalid_argument("Retained queue lacks its exact original "
                                                    "protected capture/resolver/heap issuer");
                    return;
                }
            }
        }
        // Component execution is tied to the one genuinely issued original
        // Call, never to a caller readiness flag. General selection stays off.
        {
            std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
            if (configuration_.tier == protocol::AdmissionTier::OfflineComponent &&
                !configuration_.gates.ready() && !configuration_.producerProofs.complete() &&
                configuration_.cold && configuration_.cold->capturedEntry &&
                viewportEntries_.size() == 1u) {
                const auto& entry = viewportEntries_.front();
                const auto& cold = configuration_.cold->capturedEntry;
                if (entry->authenticBoundedMathCall && entry->call &&
                    entry->call->entry() == cold->originalEntry() &&
                    entry->call->task() == cold->task() &&
                    entry->call->stamp().session == configuration_.session &&
                    entry->call->stamp().epoch == epoch_ &&
                    entry->call->stamp().bankGeneration == generation_ &&
                    (entry->call->entry() == 0x197900u ||
                     reo_gpu_upstream::Viewport::supports(entry->call->entry()))) {
                    cold->requireOnOwner();
                    return;
                }
            }
        }
        // These missing closures cannot be supplied by a caller flag or by
        // merely loading a module. Refusal precedes any owned bank mutation.
        if (!reo_gpu_upstream::QueueControlAdapter::ActualGpuHeaderLeaseIssuerImplemented ||
            !reo_gpu_upstream::QueueControlAdapter::ActualProtectedSnapshotIssuerImplemented ||
            !reo_gpu_upstream::QueueControlAdapter::ActualOrderedCommitImplemented ||
            !ViewportActualQueueCounterCommitImplemented || !ViewportIrqHeaderConsumersImplemented)
            throw std::runtime_error(
                "Viewport queue capture/counter/IRQ ownership is not yet complete");
    }
    reo_gpu_upstream::QueueControlAdapter::PlanHandle
    planViewportQueueOnOwner(const reo_gpu_upstream::QueueControlCallHandle& call,
                             const reo_gpu_upstream::QueueHeaderLeaseHandle& headers,
                             const reo_gpu_upstream::ProtectedQueueSnapshotHandle& snapshot) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireCompleteViewportQueueIssuer();
        if (!viewportQueueAdapter_)
            throw std::runtime_error("Viewport queue adapter is absent/default off");
        return viewportQueueAdapter_->plan(call, headers, snapshot);
    }

  public:
    void requireHealthy() const {
        if (failed_.load(std::memory_order_acquire))
            throw std::runtime_error(
                "Owned parent pipeline has a sticky refusal; CPU fallback forbidden");
    }
    void observeOwnerSticky(uint32_t actualCompletedStatus) noexcept {
        if (actualCompletedStatus)
            firstSticky(actualCompletedStatus);
    }
    protocol::Bridge& hookProtocol() {
        requireHealthy();
        return bridge_;
    } // Hooks are deliberately not installed in this slice.
    protocol::Entry allocateAtActualFrontier(const protocol::Allocation& a,
                                             const std::vector<protocol::RawPatch>& p) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        return bridge_.allocated(a, p);
    }
    std::recursive_mutex& hostProtocolMutex() const noexcept {
        return hostProtocolMutex_;
    }
    std::shared_ptr<const ParentReturn> waitActualParentOnOwner(const protocol::Key& key) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        auto e = find(key);
        if (!e->parentFence || e->parentReturned || e->returnTicket)
            throw std::logic_error("No new actual parent T1 control receipt");
        e->parentFence->wait();
        completed_ = std::max(completed_, e->parentTimeline);
        auto mailbox = transport_->controlAfterRealFence(e->queued, true);
        auto receipt = completedControlReceipt(key, e->parentTimeline, actualSticky(*e), mailbox);
        e->returnTicket =
            std::shared_ptr<const ParentReturn>(new ParentReturn(this, key, std::move(receipt)));
        transport_->retired(e->parentTimeline);
        // This owner-side method never reads/writes guest RAM/context and never
        // calls Bridge.completed. T1 success is still held until EE commit.
        return e->returnTicket;
    }
    protocol::Entry commitActualParentOnEe(const std::shared_ptr<const ParentReturn>& ticket,
                                           uint8_t* ram, R5900Context& ctx) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        if (!ticket || ticket->issuer_ != this)
            throw std::invalid_argument("Foreign parent scalar-return ticket");
        auto e = find(ticket->key_);
        if (e->parentReturned || e->returnTicket != ticket)
            throw std::invalid_argument("Unissued/repeated parent scalar commit");
        auto returned = bridge_.completed(ticket->receipt_, ram, ctx);
        e->parentReturned = true;
        return returned; // HOST scalar publication only, under actual EE scope.
    }
    protocol::Entry finishActualParent(const protocol::Key& key, uint8_t* ram, R5900Context& ctx) {
        // Existing controlled component caller retains its old synchronous ABI.
        // The connected natural dispatcher uses the two explicit methods above.
        return commitActualParentOnEe(waitActualParentOnOwner(key), ram, ctx);
    }
    reo_resident_live::Operation joinActualUnpack(uint32_t command, uint32_t tops,
                                                  const std::vector<protocol::Origin>& origins) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        bridge_.originalUnpack(command, tops, origins);
        if (!parserOperation_)
            throw std::logic_error("Actual source join did not mint an upload operation");
        auto result = std::move(*parserOperation_);
        parserOperation_.reset();
        auto e = find(origins.front().key);
        e->issuedToParser = true;
        return result;
    }
    void validateUpload(const reo_resident_live::Operation& op) const {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        if (op.kind != reo_resident_live::Kind::OpaqueLeaseUnpack || !op.opaqueLease ||
            op.opaqueLease->issuer_ != this || !op.opaqueLease->lifetime_ || !op.payload.empty())
            throw std::invalid_argument("Foreign/nonopaque parent upload operation");
        const auto& s = op.opaqueLease->stamp();
        if (!reo_resident_live::validLeaseUploadStamp(s) || s.epoch != epoch_ ||
            s.bankGeneration != generation_ || s.session != configuration_.session ||
            s.command != op.command || s.tops != op.latchedTops)
            throw std::invalid_argument("Stale/foreign parent upload stamp");
        auto e = find({s.session, s.epoch, s.allocation, s.revision, s.ordinal});
        if (e->token != op.opaqueLease || !e->parentReturned || !e->issuedToParser || e->recorded ||
            e->uploadTimeline)
            throw std::invalid_argument("Unissued, repeated or retired immutable upload token");
    }
    void appendUpload(Vulkan::CommandBuffer& cmd, const reo_resident_live::Operation& op) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        validateUpload(op);
        const auto& s = op.opaqueLease->stamp();
        auto e = find({s.session, s.epoch, s.allocation, s.revision, s.ordinal});
        transport_->actualUnpack(cmd, e->queued, op.command, op.latchedTops);
        e->recorded = true;
    }

  private:
    void sealActualUploads(const Vulkan::Fence& realFence) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        bool pending = false;
        for (const auto& e : entries_)
            pending |= e->recorded && !e->uploadTimeline;
        if (!pending)
            return;
        if (!realFence)
            throw std::invalid_argument("Opaque upload has no real owner fence");
        if (realFence == lastUploadFence_)
            throw std::invalid_argument(
                "Cannot reuse an older upload fence for newly recorded bytes");
        for (const auto& e : entries_)
            if (e->parentFence == realFence)
                throw std::invalid_argument("Parent T1 fence cannot seal a later VIF upload T2");
        const auto timeline = newTimeline();
        lastUploadFence_ = realFence;
        for (auto& e : entries_)
            if (e->recorded && !e->uploadTimeline) {
                e->uploadFence = realFence;
                e->uploadTimeline = timeline;
                bridge_.unpackSubmitted(e->queued.allocation.key, timeline);
            }
        transport_->sealed(timeline);
    }
    std::vector<protocol::Key> retireActualUploads(Vulkan::Fence realFence) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        std::vector<protocol::Key> retiredKeys;
        requireHealthy();
        if (!realFence)
            throw std::invalid_argument("No genuine upload completion receipt");
        realFence->wait();
        uint64_t retired = 0;
        for (auto i = entries_.begin(); i != entries_.end();) {
            auto& e = *i;
            if (e->uploadTimeline && e->uploadFence == realFence) {
                bridge_.retire(e->queued.allocation.key, e->uploadTimeline);
                retiredKeys.push_back(e->queued.allocation.key);
                retired = std::max(retired, e->uploadTimeline);
                i = entries_.erase(i);
            } else
                ++i;
        }
        if (retired) {
            transport_->retired(retired);
            completed_ = std::max(completed_, retired);
        }
        // Registry drops only after T2. Operation copies can retain it longer.
        return retiredKeys; // Minted only after actual matching upload fence retirement.
    }

  private:
    std::unique_ptr<const SourceEpochCarry> prepareSourceGsEpochCarryCertificate(
        const reo_parent_natural::NativeTarget* owner, std::shared_ptr<const ColdSource> source,
        uint64_t oldEpoch, uint64_t newEpoch, uint64_t completedSourceSequence) const {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        if (!owner || source != configuration_.cold || oldEpoch != epoch_ || newEpoch <= oldEpoch ||
            !completedSourceSequence)
            throw std::invalid_argument(
                "GS source certificate lacks its genuine current owner frontier");
        return std::unique_ptr<const SourceEpochCarry>(new SourceEpochCarry(
            this, owner, std::move(source), producer_->upstreamBanks_, oldEpoch, newEpoch,
            completedSourceSequence, upstreamOpaque_, compositionScalarRoles_));
    }
    void gsOnlyResetWithSourceCarryOnOwner(
        const SourceEpochCarry& carry,
        const std::vector<protocol::RawPatch>& actualCompletedSource) {
        std::unique_lock<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        const auto exactOpaque = [](const auto& a, const auto& b) {
            return a.space == b.space && a.address == b.address && a.bytes == b.bytes;
        };
        if (carry.issuer_ != this || !carry.sourceOwner_ || carry.source_ != configuration_.cold ||
            carry.banks_ != producer_->upstreamBanks_ || carry.oldEpoch_ != epoch_ ||
            carry.newEpoch_ <= epoch_ || !carry.sourceSequence_ ||
            carry.roles_ != compositionScalarRoles_ ||
            carry.opaque_.size() != upstreamOpaque_.size() ||
            !std::equal(carry.opaque_.begin(), carry.opaque_.end(), upstreamOpaque_.begin(),
                        exactOpaque))
            throw std::invalid_argument("GS epoch carry lost its exact source/bank/ledger issuer");
        if (!entries_.empty() || parserOperation_ || !compositionEntries_.empty() ||
            !queueEntries_.empty() || !viewportEntries_.empty() || !allocatorEntries_.empty() ||
            !matrixEntries_.empty() || !perspectiveEntries_.empty() || !setterEntries_.empty())
            throw std::runtime_error("GS source carry preceded genuine call/upload retirement");
        if (!activeRetainedInvocation_.expired())
            throw std::runtime_error(
                "GS source carry cannot overtake a retained actual EE invocation");
        bridge_.requireRetiredGsEpochCarry(carry.newEpoch_, completed_);
        uint64_t lastWriter = 0;
        for (const auto& patch : actualCompletedSource) {
            const uint32_t limit = patch.range.space == protocol::Space::Ram   ? protocol::RamBytes
                                   : patch.range.space == protocol::Space::Spr ? 0x4000u
                                                                               : 1648u;
            if (!patch.actualWriterOrdinal || patch.actualWriterOrdinal <= lastWriter ||
                patch.bytes.size() != patch.range.bytes ||
                !protocol::range(patch.range.address, patch.range.bytes, limit))
                throw std::invalid_argument(
                    "GS source carry has no exact completed source journal");
            beforeUpstreamSourceAccess(patch.range.space, patch.range.address, patch.range.bytes);
            if (patch.range.space == protocol::Space::Context)
                bridge_.beforeContextAccess(*configuration_.cold->actualContext,
                                            patch.range.address, patch.range.bytes, patch.actualPC);
            lastWriter = patch.actualWriterOrdinal;
        }
        // One genuine ordered completion covers the deferred controls and any
        // earlier actual source mirrors. No guest callback is made by this work.
        const uint64_t timeline = newTimeline();
        auto fence = gs_.submit_resident_completion([&](Vulkan::CommandBuffer& command) {
            for (const auto& patch : actualCompletedSource)
                producer_->bridgeSourceWrite(command, patch);
        });
        if (!fence)
            throw std::runtime_error("GS source epoch carry has no genuine completion fence");
        producer_->sealOwnerSubmission(timeline);
        lock.unlock();
        fence->wait();
        lock.lock();
        requireHealthy();
        producer_->retireCompletedOwnerSubmission(timeline);
        completed_ = std::max(completed_, timeline);
        bridge_.requireRetiredGsEpochCarry(carry.newEpoch_, completed_);
        // Allocate/validate the new bank identity before changing Bridge state.
        // All four actual numerical buffers and every ownership role survive.
        producer_->resetAfterRealRetirement(carry.newEpoch_, configuration_.session);
        bridge_.reset(carry.newEpoch_, completed_, false);
        epoch_ = carry.newEpoch_;
        retainedSourceBanks_ = producer_->upstreamBanks_;
        retainedSourceFence_ = fence;
        retainedSourceEpoch_ = epoch_;
        retainedSourceGeneration_ = generation_;
    }

  public:
    void gsOnlyResetAfterDrain(uint64_t newEpoch) {
        std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
        requireHealthy();
        if (!callbacks_.empty())
            throw std::runtime_error("GS epoch reset during active callback Context loan");
        if (!compositionEntries_.empty() || !entries_.empty() || parserOperation_ ||
            !setterEntries_.empty())
            throw std::runtime_error("GS reset before all actual parent/upload retirement");
        if (!queueEntries_.empty() || !viewportEntries_.empty() || !allocatorEntries_.empty() ||
            !matrixEntries_.empty() || !perspectiveEntries_.empty() || !setterEntries_.empty() ||
            !upstreamOpaque_.empty())
            throw std::runtime_error(
                "Original upstream reset lacks context/source handoff certificate");
        if (newEpoch == epoch_)
            return;
        bridge_.reset(newEpoch, completed_, false);
        producer_->resetAfterRealRetirement(newEpoch, configuration_.session);
        epoch_ = newEpoch;
    }
    void requireVuBankResetCertificate() const {
        // This first slice has no context transfer/cold reseed certificate API.
        // Do not destroy a service retaining opaque CPU-context guards.
        throw std::runtime_error(
            "Parent context handoff/cold reset is not installed; retain actual GPU ownership");
    }
    static constexpr bool NaturalWriterKeysInstalled = false, AllocatorHookInstalled = false,
                          ParserHookInstalled = false;
};
} // namespace reo_parent_install
