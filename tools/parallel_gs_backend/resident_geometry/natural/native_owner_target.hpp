#pragma once
#include "parent/parent_owner_service.hpp"
#include "parent_natural_runtime.h"
#include "parent_context_lifecycle.h"
#include "source_instruction_origin.hpp"
#include "native_control_return.hpp"
#include "instruction_input_evidence.hpp"
#include "upstream/guarded_cpu_ingress.hpp"
#include "parent_source_failure.h"
#include "natural_parent_gateway.hpp"
#include "raw_writer_journal.hpp"
#include "pool_control_writer_catalogue.hpp"
#include "pre_entry_queue_source_scope.hpp"
#include "pre_entry_heap_source_scope.hpp"
#include "../explicit_source_write.hpp"
#include "../protected_scalar_capture.hpp"
#include "upstream/original_matrix_control.hpp"
#include "upstream/original_perspective_control.hpp"
#include "upstream/original_viewport_control.hpp"
#include "upstream/queue_resolver_binding.hpp"
#include "upstream/protected_queue_capture.hpp"
#include "upstream/original_setter_control.hpp"
#include "upstream/original_state_packet_control.hpp"
#include "upstream/original_composition_control.hpp"
#include "upstream/callback_context_handoff.hpp"
#include "upstream/fresh_context_handoff.hpp"
#include "ps2_guest_sched.h"
#include "irq_cpu_control.h"
#include <atomic>
extern uint32_t ps2IoRegLockDepth() noexcept;
namespace reo_resident_live {
class ParallelArrayOwner;
}
namespace reo_parent_natural {
namespace protocol = reo_parent_live;
class NativeTarget final : public ControlTarget,
                           public IrqCpuControlTarget,
                           public ContextLifetimeTarget,
                           public CallbackContextTarget,
                           public IrqContextTarget,
                           public ExplicitSourceWriteTarget,
                           public reo_source_instrumentation::TypedSourceWriteTarget,
                           public NativeControlWriteTarget,
                           public reo_source_instrumentation::CpuInputWriteTarget,
                           public ProtectedScalarCaptureTarget,
                           public CertifiedControlCommitTarget,
                           public reo_gpu_upstream::OriginalCompositionControl,
                           public reo_gpu_upstream::OriginalMatrixControl,
                           public reo_gpu_upstream::OriginalPerspectiveControl,
                           public reo_gpu_upstream::OriginalViewportControl,
                           public reo_gpu_upstream::OriginalSetterControl,
                           public reo_gpu_upstream::OriginalStatePacketControl,
                           public std::enable_shared_from_this<NativeTarget> {
    friend class reo_resident_live::ParallelArrayOwner;
    reo_parent_install::Service& service_;
    Configuration configuration_;
    std::shared_ptr<const reo_parent_install::ColdSource> cold_;
    Gateway<reo_parent_install::Service> gateway_;
    RawWriterJournal journal_;
    PoolControlWriterCatalogue poolControlWriters_;
    bool pendingPoolControlHistory_ = false;
    std::atomic<bool> owned_{false}, heldT1_{false}, failed_{false}, stopped_{false};
    std::atomic<bool> contextEnded_{false};
    std::atomic<bool> boundedCompositionHold_{false};
    bool authenticColdSetterConsumed_ = false;
    bool authenticColdMathConsumed_ = false;
    std::atomic<uint64_t> epoch_{0};
    mutable std::recursive_mutex sourceMutex_;
    std::vector<protocol::Range> frozenRanges_;
    static std::shared_ptr<const reo_parent_install::ColdSource>
    checkedCold(std::shared_ptr<const reo_parent_install::ColdSource> cold) {
        if (!cold || !cold->ram || !cold->spr || !cold->actualContext || !cold->lifetime)
            throw std::invalid_argument("Connected parent cold source is incomplete");
        return cold;
    }
    struct Tape final : OriginHandle {
        const NativeTarget* issuer;
        TypedOrigins::Tape value;
        Tape(const NativeTarget* i, TypedOrigins::Tape v) : issuer(i), value(std::move(v)) {}
        uint32_t bytes() const noexcept override {
            return value.bytes();
        }
    };
    const Tape& exact(const Origins& x) const {
        const auto* t = dynamic_cast<const Tape*>(x.get());
        if (!t || t->issuer != this)
            throw std::invalid_argument("Foreign connected owner DMA tape");
        return *t;
    }
    Origins wrap(TypedOrigins::Tape x) const {
        return std::make_shared<const Tape>(this, std::move(x));
    }
    R5900Context* heldSourceContextIdentity() const noexcept {
        auto* parked = service_.actualPausedMainContextIdentity();
        return parked ? parked : contextIdentity();
    }
    void heldReadGuard(SourceSpace space, uint32_t at, uint32_t bytes, R5900Context* ctx) const {
        if (space == SourceSpace::Context && ctx == contextIdentity() &&
            freshContextHeld_.load(std::memory_order_acquire))
            throw std::runtime_error(
                "Fresh IRQ Context is held behind its genuine source/control fence");
        if (!heldT1_.load(std::memory_order_acquire) ||
            (space == SourceSpace::Context && ctx != heldSourceContextIdentity()))
            return;
        if (space == SourceSpace::Context && ctx == heldSourceContextIdentity())
            throw std::runtime_error("Actual parent EE context is held behind T1");
        // Reads of unrelated scalar RAM remain possible for legitimate IRQ
        // work; input RAM is read-only until true T1, all SPR is frozen.
        if (space == SourceSpace::Spr && !boundedCompositionHold_.load(std::memory_order_acquire))
            throw std::runtime_error("Actual parent SPR input lease is held behind T1");
        for (const auto& range : frozenRanges_)
            if (range.space == static_cast<protocol::Space>(space) &&
                protocol::overlap(at, bytes, range.address, range.bytes))
                throw std::runtime_error(
                    "Actual upstream source read overtook its held T1 bank lease");
    }
    void heldWriteGuard(SourceSpace space, uint32_t at, uint32_t n, R5900Context* ctx) const {
        if (space == SourceSpace::Context && ctx == contextIdentity() &&
            freshContextHeld_.load(std::memory_order_acquire))
            throw std::runtime_error(
                "Fresh IRQ Context is held behind its genuine source/control fence");
        if (!heldT1_.load(std::memory_order_acquire) ||
            (space == SourceSpace::Context && ctx != heldSourceContextIdentity()))
            return;
        if (space == SourceSpace::Context && ctx == heldSourceContextIdentity())
            throw std::runtime_error("Actual EE context write overtook T1");
        for (const auto& r : frozenRanges_)
            if (r.space == static_cast<protocol::Space>(space) &&
                protocol::overlap(at, n, r.address, r.bytes))
                throw std::runtime_error("Actual raw input write overtook parent T1 source lease");
    }
    void ownerAfterActualT2(const protocol::Key& key) {
        std::lock_guard<std::recursive_mutex> lock(sourceMutex_);
        gateway_.afterActualOwnerT2Retirement(key);
    }
    void ownerStopped() {
        stopped_.store(true, std::memory_order_release);
    }
    void ownerGsOnlyResetAfterDrain(uint64_t newEpoch) {
        std::lock_guard<std::recursive_mutex> sourceLock(sourceMutex_);
        requireHealthy();
        const auto hasContextLoan = []<class Owner>(const Owner& owner) {
            if constexpr (requires { owner.activeCallbackLoanDepth(); })
                return owner.activeCallbackLoanDepth() != 0;
            else
                return true; // No loan-depth proof cannot authorize an epoch carry.
        };
        if (hasContextLoan(*this))
            throw std::runtime_error("GS epoch carry requires the genuine caller Context restored");
        const uint64_t oldEpoch = epoch_.load(std::memory_order_acquire);
        if (newEpoch == oldEpoch)
            return;
        if (newEpoch <= oldEpoch || heldT1_.load(std::memory_order_acquire) ||
            !pendingSourceWrite_.expired() || journal_.hasPrepared() || pendingScalarHistory_ ||
            !certifiedAllocatorEvents_.empty() || !certifiedQueueEvents_.empty() ||
            !hasGenuineContextStorage() || contextIdentity() != cold_->actualContext)
            throw std::runtime_error(
                "GS source reset has pending source/control/context authority");
        for (const auto& lease : protectedCaptures_)
            if (!lease.expired())
                throw std::runtime_error(
                    "GS source reset overtook an actual protected scalar lease");
        // No source or IRQ callback can acquire guest ownership in the owner
        // control. This source lease protects the reset's completed journal.
        auto sourceCarry = gateway_.prepareGsEpochCarry(newEpoch);
        std::unique_ptr<const reo_parent_install::Service::SourceEpochCarry> certificate;
        {
            std::lock_guard<std::recursive_mutex> protocolLock(service_.hostProtocolMutex());
            certificate = service_.prepareSourceGsEpochCarryCertificate(this, cold_, oldEpoch,
                                                                        newEpoch, nextSourceWrite_);
        }
        service_.gsOnlyResetWithSourceCarryOnOwner(*certificate, journal_.committed_);
        if (!gateway_.consumeGsEpochCarry(sourceCarry)) {
            failed_.store(true, std::memory_order_release);
            service_.observeOwnerSticky(181u);
            throw std::runtime_error("GS source epoch carry lost its reserved source frontier");
        }
        journal_.committed_.clear();
        journal_.bytes_ = 0;
        deferredContextControls_ = 0;
        // Source sequence, protected writer history, allocations and ordinals
        // never restart. Atomic publication also makes scoped cache refresh safe.
        epoch_.store(newEpoch, std::memory_order_release);
    }

  public:
    // The direct-context/native-copy closure and upstream GPU source kernels
    // have not been supplied. A caller cannot activate this successor merely
    // by setting the externally reported coverage fields to true.
    static constexpr bool KnownSourceClosureImplemented = false;
    NativeTarget(reo_parent_install::Service& s,
                 std::shared_ptr<const reo_parent_install::ColdSource> cold, const Configuration& c,
                 uint64_t session, uint64_t epoch)
        : service_(s), configuration_(c), cold_(checkedCold(std::move(cold))),
          gateway_(s, cold_->ram, *cold_->actualContext, session, epoch),
          journal_(cold_->ram, configuration_.rawSites), epoch_(epoch) {
        if (!configuration_.actualRuntime ||
            configuration_.actualRuntime->memory().getRDRAM() != cold_->ram ||
            configuration_.actualRuntime->memory().getScratchpad() != cold_->spr)
            throw std::invalid_argument("Connected source belongs to a foreign actual Runtime");
        if (configuration_.authenticColdSetterCommand &&
            (!configuration_.authenticColdComponentEnrollment ||
             configuration_.authenticColdSetterCommand != 0x5au || !cold_->capturedEntry ||
             configuration_.authenticColdComponentEntry != 0x196010u ||
             !configuration_.authenticColdComponentBody ||
             service_.configuration_.tier != protocol::AdmissionTier::OfflineComponent ||
             configuration_.coverage.complete() || service_.configuration_.gates.ready() ||
             service_.configuration_.producerProofs.complete()))
            throw std::invalid_argument(
                "One-shot cold Setter component lacks its bounded actual source/fence scope");
        if (cold_->capturedEntry)
            service_.requireFirstEntryUploadOnOwner(cold_->capturedEntry);
        adoptActualPreEntryControlHistory();
    }

  private:
    void adoptActualPreEntryControlHistory() {
        if (!cold_->capturedEntry)
            return;
        const auto& entry = cold_->capturedEntry;
        entry->requireOnOwner();
        const auto& snapshot = entry->preEntryControls();
        if (!snapshot)
            throw std::invalid_argument(
                "Authentic first graphics capture lacks its sealed pre-owner control journal");
        snapshot->requireAuthenticColdOwner(*runtimeIdentity(), *cold_->actualContext,
                                            ramIdentity(), cold_->lifetime);
        if (snapshot->lastWriterOrdinal() == UINT64_MAX || snapshot->rows().size() > 65536u)
            throw std::overflow_error(
                "Pre-entry writer history cannot carry into actual owner generation");
        controlHistory_.reserve(snapshot->rows().size());
        for (const auto& event : snapshot->rows()) {
            if (&event.runtime() != runtimeIdentity() || event.ramIdentity() != ramIdentity() ||
                !event.writerOrdinal() || event.writerOrdinal() > snapshot->lastWriterOrdinal() ||
                !event.originalBodyIdentity() || !event.contextLifetime() ||
                !protocol::range(event.address(), 4u, protocol::RamBytes) || (event.address() & 3u))
                throw std::invalid_argument(
                    "Foreign/incomplete original pre-entry completed control event");
            uint32_t frozenBits;
            std::memcpy(&frozenBits,
                        static_cast<const uint8_t*>(entry->initialRam()) + event.address(), 4u);
            if (frozenBits != event.bits() || controlHistory(event.address()))
                throw std::runtime_error(
                    "Completed pre-entry event differs from immutable one-time actual cold source");
            controlHistory_.push_back({event.address(), event.bits(), event.pc(), event.word(),
                                       event.writerOrdinal(), true, 15u});
            for (auto& revision : protectedRevisions_)
                if (revision.address == event.address())
                    revision.completedWriter = event.writerOrdinal();
        }
        nextSourceWrite_ = snapshot->lastWriterOrdinal() + 1u;
        if (snapshot->poolInitializationCompleted()) {
            poolControlWriters_.countCompleted_ = true;
            poolControlWriters_.tableCompleted_ = true;
            poolControlWriters_.initialized_ = true;
            poolControlWriters_.nextPointerByte_ =
                PoolControlWriterCatalogue::Table + PoolControlWriterCatalogue::Count * 16u;
        }
    }

  public:
    bool hasGenuineContextStorage() const {
        return matchesActualGuestContextStorage(*runtimeIdentity(), *contextIdentity(),
                                                service_.activeSourceContextLifetime());
    }
    const void* ramIdentity() const noexcept override {
        return cold_->ram;
    }
    const void* sprIdentity() const noexcept override {
        return cold_->spr;
    }
    R5900Context* contextIdentity() const noexcept override {
        return service_.activeSourceContextIdentity();
    }
    PS2Runtime* runtimeIdentity() const noexcept override {
        return configuration_.actualRuntime;
    }
    uint64_t epoch() const noexcept override {
        return epoch_;
    }
    bool readyForSelection() const noexcept override {
        return KnownSourceClosureImplemented && configuration_.requested &&
               configuration_.coverage.complete() && !stopped_.load() && !failed_.load();
    }
    bool ownsAnySource() const noexcept override {
        return owned_.load(std::memory_order_acquire);
    }
    void requireHealthy() const override {
        if (failed_.load() || stopped_.load() || contextEnded_.load(std::memory_order_acquire))
            throw std::runtime_error("Connected parent owner has a sticky refusal/stop");
        service_.requireHealthy();
    }
    bool retainsActualGuestContextIdentity(const R5900Context& ctx) const noexcept override {
        return service_.retainsSourceContextIdentity(ctx);
    }
    void observeActualGuestContextEnd(PS2Runtime& runtime, R5900Context& ctx,
                                      int32_t task) noexcept override {
        if (&runtime == runtimeIdentity() && service_.observeRetiredContextEnd(ctx))
            return;
        if (&runtime != runtimeIdentity() || !retainsActualGuestContextIdentity(ctx) ||
            (task < 1 && !service_.isActualTaskZeroIrqContext(ctx)))
            return;
        contextEnded_.store(true, std::memory_order_release);
        // An ended source cannot become a new task's cold input. GPU/source
        // retirement retains its allocation through the real ColdSource lease.
        if (owned_.load(std::memory_order_acquire))
            try {
                runtime.requestStop();
            } catch (...) {
            }
    }
    bool atOriginal196010(uint8_t* ram, R5900Context& ctx, PS2Runtime& rt) override {
        const bool retainedMode = service_.hasRetainedInvocationAdmission();
        const bool coldComponent = !retainedMode && configuration_.authenticColdSetterCommand != 0u;
        if (!readyForSelection() && !coldComponent && !retainedMode)
            return false; // Global readiness remains hard false.
        if (&rt != runtimeIdentity() || &ctx != contextIdentity() || ctx.pc != 0x196010u ||
            rt.isStopRequested())
            throw std::invalid_argument("Original196010 lost actual guest entry ownership");
        if (ps2IoRegLockDepth() != 0)
            throw std::logic_error("Original196010 cannot wait under recursive IO ownership");
        std::unique_ptr<reo_parent_install::Service::RetainedInvocationScope> invocationScope;
        reo_parent_install::Service::RetainedInvocationHandle invocation;
        reo_gpu_upstream::CallHandle call;
        std::vector<protocol::RawPatch> patches;
        try {
            {
                std::lock_guard<std::recursive_mutex> sourceLock(sourceMutex_);
                std::lock_guard<std::recursive_mutex> protocolLock(service_.hostProtocolMutex());
                if (retainedMode) {
                    invocationScope = service_.beginRetainedInvocationOnEe(
                        rt, ram, ctx, 0x196010u, rt.lookupFunction(0x196010u));
                    invocation = invocationScope->ticket();
                }
                if (coldComponent) {
                    const auto& capture = cold_->capturedEntry;
                    requireHealthy();
                    if (!capture || authenticColdSetterConsumed_ ||
                        !configuration_.authenticColdComponentEnrollment ||
                        configuration_.authenticColdSetterCommand != 0x5au ||
                        ram != capture->ramIdentity() || &rt != &capture->runtime() ||
                        &ctx != &capture->context() || ctx.pc != capture->originalEntry() ||
                        capture->originalEntry() != 0x196010u ||
                        capture->originalBodyIdentity() !=
                            configuration_.authenticColdComponentBody ||
                        rt.lookupFunction(0x196010u) != capture->originalBodyIdentity() ||
                        ps2_sched::currentThread() != capture->task() || currentRuntime() != &rt ||
                        currentContext() != &ctx || !ps2ActualGuestExecutionDepth(&rt) ||
                        reo_source_instrumentation::actualInstructionOrigin.pc ||
                        reo_source_instrumentation::actualInstructionOrigin.word)
                        throw std::invalid_argument(
                            "Cold Setter is not the one authentic pre-instruction entry");
                    capture->requireOnEe();
                    service_.requireFirstEntryUploadOnOwner(capture);
                    uint8_t command;
                    std::memcpy(&command, &ctx.r[4], 1);
                    if (command != configuration_.authenticColdSetterCommand)
                        throw std::invalid_argument(
                            "Cold Setter command exceeds its one proved profile");
                    authenticColdSetterConsumed_ = true;
                }
                if (!service_.admitsOriginalSetterOnEe(ctx))
                    throw std::invalid_argument(
                        "Original setter command/continuation lacks complete GPU source closure");
                call = service_.prepareOriginalSetterOnEe(ram, ctx, ps2_sched::currentThread());
                if (invocation)
                    service_.bindRetainedInvocationOnEe(invocation, call);
                frozenRanges_.clear();
                frozenRanges_.push_back({protocol::Space::Ram, 0, reo_gpu_upstream::RamBytes});
                frozenRanges_.push_back({protocol::Space::Spr, 0, reo_gpu_upstream::SprBytes});
                frozenRanges_.push_back(
                    {protocol::Space::Context, 0, reo_gpu_upstream::ContextBytes});
                patches = journal_.takeAtActualFrontier();
                deferredContextControls_ = 0;
                heldT1_.store(true, std::memory_order_release);
            }
            auto self = shared_from_this();
            auto request = requestActualOwnerControl(
                epoch_,
                [self, call, invocation, patches = std::move(patches)](ControlTarget& actual) {
                    if (&actual != self.get())
                        throw std::invalid_argument("Original196010 reached foreign owner FIFO");
                    if (invocation)
                        self->service_.requireRetainedInvocationOnOwner(invocation, call);
                    self->service_.recordOriginalSetterOnOwner(call, patches);
                    self->owned_.store(true, std::memory_order_release);
                    self->service_.waitOriginalSetterOnOwner(call);
                    if (invocation)
                        self->service_.requireRetainedInvocationOnOwner(invocation, call);
                });
            {
                PS2Runtime::GuestExecutionReleaseScope release(&rt);
                request->wait();
            }
            if (rt.isStopRequested() || ps2_sched::currentThread() != call->task())
                throw std::runtime_error("Original196010 did not reacquire genuine guest task");
            {
                std::lock_guard<std::recursive_mutex> lock(sourceMutex_);
                service_.commitOriginalSetterOnEe(call, ram, ctx, ps2_sched::currentThread());
                if (invocation)
                    service_.finishRetainedInvocationOnEe(invocation, call);
                heldT1_.store(false, std::memory_order_release);
            }
            return true;
        } catch (...) {
            failed_.store(true, std::memory_order_release);
            throw;
        }
    }
    class RpcFrame final : public CallbackFrame {
        std::shared_ptr<NativeTarget> owner_;
        std::shared_ptr<reo_parent_install::Service::CallbackEntry> entry_;
        bool closed_ = false;

      public:
        RpcFrame(std::shared_ptr<NativeTarget> owner,
                 std::shared_ptr<reo_parent_install::Service::CallbackEntry> entry)
            : owner_(std::move(owner)), entry_(std::move(entry)) {}
        ~RpcFrame() override {
            if (!closed_) {
                owner_->failed_.store(true, std::memory_order_release);
                try {
                    owner_->runtimeIdentity()->requestStop();
                } catch (...) {
                }
            }
        }
        R5900Context& context() noexcept override {
            return *entry_->storage->get();
        }
        bool ownsNumericLanes() const noexcept override {
            return true;
        }
        uint32_t returnedScalarV0() override {
            auto* runtime = owner_->runtimeIdentity();
            try {
                owner_->requireHealthy();
                auto& child = context();
                if (currentRuntime() != runtime || !ps2ActualGuestExecutionDepth(runtime) ||
                    ps2_sched::currentThread() != entry_->task)
                    throw std::invalid_argument(
                        "Callback scalar return lost actual helper/task execution");
                AccessScope actual(runtime, &child);
                owner_->read(SourceSpace::Context, 2u * 16u, 4u, &child, child.pc);
                std::lock_guard<std::recursive_mutex> lock(owner_->service_.hostProtocolMutex());
                if (!reo_source_closure::scalarControlLane(owner_->service_.compositionScalarRoles_,
                                                           2u * 16u, 4u))
                    throw std::runtime_error(
                        "Callback v0 has no source-certified scalar-return role");
                uint32_t result;
                std::memcpy(&result, &child.r[2], 4);
                return result;
            } catch (...) {
                owner_->failed_.store(true, std::memory_order_release);
                throwOwnedSourceFailure(runtime);
            }
        }
        void closeAfterActualCallbackReturn() override {
            auto self = owner_;
            auto* runtime = self->runtimeIdentity();
            try {
                self->requireHealthy();
                auto& child = context();
                if (closed_ || currentRuntime() != runtime ||
                    !ps2ActualGuestExecutionDepth(runtime) ||
                    ps2_sched::currentThread() != entry_->task || ps2IoRegLockDepth() != 0u)
                    throw std::invalid_argument(
                        "Callback close lost actual helper/task/IO ownership");
                {
                    AccessScope actual(runtime, &child);
                    self->read(SourceSpace::Context, uint32_t(offsetof(R5900Context, pc)), 4u,
                               &child, child.pc);
                    std::lock_guard<std::recursive_mutex> lock(self->service_.hostProtocolMutex());
                    if (!reo_source_closure::scalarControlLane(
                            self->service_.compositionScalarRoles_,
                            uint32_t(offsetof(R5900Context, pc)), 4u) ||
                        (child.pc != 0u && child.pc != entry_->controls.returnSentinel))
                        throw std::runtime_error(
                            "Callback has not reached its actual source-certified return boundary");
                }
                self->service_.requireCallbackCallerLifetimeOnEe(*runtime, entry_);
                std::vector<protocol::RawPatch> ingress;
                {
                    AccessScope actual(runtime, &child);
                    std::lock_guard<std::recursive_mutex> source(self->sourceMutex_);
                    if (!self->pendingSourceWrite_.expired() || self->freshContextHeld_.load() ||
                        (!entry_->freshInitializer && self->heldT1_.load()))
                        throw std::runtime_error(
                            "Callback close overtook an unfinished source instruction/frontier");
                    ingress = self->journal_.takeAtActualFrontier();
                    self->deferredContextControls_ = 0;
                    self->heldT1_.store(true, std::memory_order_release);
                }
                auto request = requestActualOwnerControl(
                    self->epoch_,
                    [self, entry = entry_, ingress = std::move(ingress)](ControlTarget& target) {
                        if (&target != self.get())
                            throw std::invalid_argument(
                                "Callback close reached a foreign actual FIFO");
                        if (entry->freshInitializer) {
                            self->service_.recordFreshIrqReturnOnOwner(entry, ingress);
                            self->service_.waitAndRestoreFreshIrqOnOwner(entry);
                        } else {
                            self->service_.recordOriginalRpcCloseOnOwner(entry, ingress);
                            self->service_.waitAndRestoreOriginalRpcOnOwner(entry);
                        }
                    });
                {
                    PS2Runtime::GuestExecutionReleaseScope release(runtime);
                    request->wait();
                }
                self->requireHealthy();
                if (runtime->isStopRequested() || ps2_sched::currentThread() != entry_->task)
                    throw std::runtime_error("Callback did not regain genuine caller ownership");
                std::lock_guard<std::recursive_mutex> source(self->sourceMutex_);
                self->gateway_.actualContext_ = entry_->caller;
                self->heldT1_.store(entry_->freshInitializer ? entry_->mainHeldT1 : false,
                                    std::memory_order_release);
                if (!entry_->freshInitializer)
                    self->frozenRanges_.clear();
                closed_ = true;
            } catch (...) {
                self->failed_.store(true, std::memory_order_release);
                throwOwnedSourceFailure(runtime);
            }
        }
    };
    uint32_t activeCallbackLoanDepth() const {
        return service_.activeCallbackLoanDepth();
    }
    std::atomic<bool> freshContextHeld_{false};
    void holdFreshIrqContextForActualSourceOnEe(const IrqInitializerHandle& initializer) {
        requireHealthy();
        if (!initializer)
            throw std::invalid_argument("Fresh IRQ hold lacks source initializer");
        initializer->validateActualSourceOnEe();
        std::lock_guard<std::recursive_mutex> source(sourceMutex_);
        std::lock_guard<std::recursive_mutex> lock(service_.hostProtocolMutex());
        if (contextIdentity() != &initializer->context() || service_.callbacks_.empty() ||
            service_.callbacks_.back()->freshInitializer != initializer ||
            !pendingSourceWrite_.expired() || freshContextHeld_.load())
            throw std::invalid_argument(
                "Fresh IRQ source hold is foreign, overlapping or unissued");
        freshContextHeld_.store(true, std::memory_order_release);
    }
    void releaseFreshIrqContextAfterActualSourceOnEe(const IrqInitializerHandle& initializer) {
        requireHealthy();
        if (!initializer)
            throw std::invalid_argument("Fresh IRQ release lacks source initializer");
        initializer->validateActualSourceOnEe();
        std::lock_guard<std::recursive_mutex> source(sourceMutex_);
        std::lock_guard<std::recursive_mutex> lock(service_.hostProtocolMutex());
        if (contextIdentity() != &initializer->context() || service_.callbacks_.empty() ||
            service_.callbacks_.back()->freshInitializer != initializer ||
            !freshContextHeld_.load() || !pendingSourceWrite_.expired())
            throw std::invalid_argument(
                "Fresh IRQ source release is foreign, unheld or has unfinished CPU store");
        const auto completed = [&]<class Owner>(const Owner& owner) {
            if constexpr (requires { owner.irqStageEntries_; })
                return owner.irqStageEntries_.empty();
            else
                return false;
        };
        if (!completed(service_) ||
            !reo_source_closure::scalarControlLane(service_.compositionScalarRoles_,
                                                   uint32_t(offsetof(R5900Context, pc)), 4u) ||
            initializer->context().pc != 0u)
            throw std::runtime_error(
                "Fresh IRQ source release preceded real final/control EE publication");
        freshContextHeld_.store(false, std::memory_order_release);
    }
    CallbackFrameHandle enterActualIrqContext(const IrqInitializerHandle& initializer) override {
        auto* runtime = runtimeIdentity();
        try {
            if ((!ActualFreshIrqContextSourceClosureImplemented ||
                 !ActualIrqInitializerRegistrationInstalled ||
                 !reo_parent_install::ActualIrqContextPauseSourceClosureInstalled) &&
                !(OriginalCpuIrqControlCoverageImplemented &&
                  reo_irq_integer::actualCpuContextAdmission == initializer.get()))
                throw std::runtime_error(
                    "Authentic fresh IRQ Context/control route remains default off");
            requireHealthy();
            if (!initializer || &initializer->runtime() != runtime || ps2IoRegLockDepth() != 0u)
                throw std::invalid_argument(
                    "IRQ frame lost actual runtime/initializer/unlocked entry");
            initializer->validateBeforeAnyIrqInstructionOnEe();
            auto& child = initializer->context();
            actualSourceScope(&child, child.pc);
            std::shared_ptr<reo_parent_install::Service::CallbackEntry> frame;
            reo_parent_install::IrqContextPauseHandle pause;
            bool mainHeld = false;
            {
                std::lock_guard<std::recursive_mutex> source(sourceMutex_);
                std::lock_guard<std::recursive_mutex> protocolLock(service_.hostProtocolMutex());
                if (!pendingSourceWrite_.expired() || journal_.hasPrepared() ||
                    journal_.hasCompleted() || deferredContextControls_ || gateway_.allocator_)
                    throw std::runtime_error("Fresh IRQ entry overtook an actual source "
                                             "instruction/ordered ingress/allocator");
                // Retained main source fields remain protected while the real
                // IRQ runs; its private reservation prevents main EE commits.
                pause = service_.prepareActualIrqContextPauseOnEe(initializer);
                mainHeld = heldT1_.load(std::memory_order_acquire);
                heldT1_.store(true, std::memory_order_release);
            }
            auto self = shared_from_this();
            auto request = requestActualOwnerControl(epoch_, [self, pause](ControlTarget& target) {
                if (&target != self.get())
                    throw std::invalid_argument("IRQ pause reached foreign actual owner FIFO");
                self->service_.recordActualIrqContextPauseOnOwner(pause);
                self->service_.waitActualIrqContextPauseOnOwner(pause);
            });
            {
                PS2Runtime::GuestExecutionReleaseScope release(runtime);
                request->wait();
            }
            requireHealthy();
            initializer->validateBeforeAnyIrqInstructionOnEe();
            {
                std::lock_guard<std::recursive_mutex> source(sourceMutex_);
                frame = service_.prepareFreshIrqContextOnEe(initializer, pause);
                frame->mainHeldT1 = mainHeld;
            }
            auto activate = requestActualOwnerControl(epoch_, [self, frame](ControlTarget& target) {
                if (&target != self.get())
                    throw std::invalid_argument(
                        "Fresh IRQ Context reached foreign actual owner FIFO");
                self->service_.recordFreshIrqContextOnOwner(frame);
                self->service_.waitFreshIrqContextOnOwner(frame);
            });
            {
                PS2Runtime::GuestExecutionReleaseScope release(runtime);
                activate->wait();
            }
            requireHealthy();
            initializer->validateActualSourceOnEe();
            {
                std::lock_guard<std::recursive_mutex> source(sourceMutex_);
                gateway_.actualContext_ = frame->storage->get();
                // Retain the old main T1 state. heldRead/WriteGuard resolve the
                // parked main identity rather than blocking fresh child fields.
                heldT1_.store(mainHeld, std::memory_order_release);
            }
            return std::make_shared<RpcFrame>(self, std::move(frame));
        } catch (...) {
            failed_.store(true, std::memory_order_release);
            throwOwnedSourceFailure(runtime);
        }
    }

    CallbackFrameHandle
    forkActualRpcCallback(const RpcCallbackInvocationHandle& invocation) override {
        auto* actualRuntime = runtimeIdentity();
        // Only the reviewed original helper may select this route once its
        // arguments, allocator and all source-access boundaries are closed.
        try {
            if (!ActualRpcControlSourceClosureImplemented)
                throw std::runtime_error("Actual RPC controls/source closure is default off");
            if (!invocation)
                throw std::invalid_argument("RPC fork lacks actual original invocation authority");
            invocation->validateBeforeActualForkOnEe();
            auto& runtime = invocation->runtime();
            auto& caller = invocation->caller();
            requireHealthy();
            actualSourceScope(&caller, caller.pc);
            if (&runtime != runtimeIdentity() || &caller != contextIdentity() ||
                ps2_sched::currentThread() < 1 || ps2IoRegLockDepth() != 0u ||
                !hasGenuineContextStorage() || heldT1_.load())
                throw std::invalid_argument(
                    "RPC fork lost actual caller lifetime/task/IO ownership");
            auto storage =
                std::make_shared<GuestContextStorage>(runtime, ps2_sched::currentThread());
            std::shared_ptr<const void> lifetime;
            {
                AccessScope child(&runtime, storage->get());
                lifetime = retainActualGuestContextStorage(runtime, *storage->get());
            }
            std::shared_ptr<reo_parent_install::Service::CallbackEntry> entry;
            std::vector<protocol::RawPatch> ingress;
            {
                std::lock_guard<std::recursive_mutex> source(sourceMutex_);
                std::lock_guard<std::recursive_mutex> protocolLock(service_.hostProtocolMutex());
                if (!pendingSourceWrite_.expired() || !protectedCaptures_.empty() ||
                    gateway_.allocator_)
                    throw std::runtime_error(
                        "RPC fork overtook exact permit/protected allocator capture");
                entry = service_.prepareOriginalRpcCallbackOnEe(runtime, caller, std::move(storage),
                                                                std::move(lifetime), invocation,
                                                                ps2_sched::currentThread());
                ingress = journal_.takeAtActualFrontier();
                deferredContextControls_ = 0;
                heldT1_.store(true, std::memory_order_release);
                frozenRanges_ = {{protocol::Space::Context, 0, 1648u}};
            }
            auto self = shared_from_this();
            auto request = requestActualOwnerControl(
                epoch_, [self, entry, ingress = std::move(ingress)](ControlTarget& target) {
                    if (&target != self.get())
                        throw std::invalid_argument(
                            "Context fork reached foreign actual owner FIFO");
                    self->service_.recordOriginalRpcForkOnOwner(entry, ingress);
                    self->service_.waitOriginalRpcForkOnOwner(entry);
                });
            {
                PS2Runtime::GuestExecutionReleaseScope release(&runtime);
                request->wait();
            }
            requireHealthy();
            if (runtime.isStopRequested() || ps2_sched::currentThread() != entry->task)
                throw std::runtime_error("RPC fork did not regain genuine task execution");
            {
                std::lock_guard<std::recursive_mutex> source(sourceMutex_);
                gateway_.actualContext_ = entry->storage->get();
                heldT1_.store(false, std::memory_order_release);
                frozenRanges_.clear();
            }
            return std::make_shared<RpcFrame>(self, std::move(entry));
        } catch (...) {
            failed_.store(true, std::memory_order_release);
            throwOwnedSourceFailure(actualRuntime);
        }
    }

    bool atOriginalComposition(uint8_t* ram, R5900Context& ctx, PS2Runtime& rt) override {
        const bool retained = service_.hasRetainedInvocationAdmission();
        const bool coldComponent = authenticColdMathRequested(ctx.pc);
        if ((!readyForSelection() ||
             !reo_gpu_upstream::CompositionNaturalSourceClosureImplemented) &&
            !retained && !coldComponent)
            return false;
        if (&rt != runtimeIdentity() || &ctx != contextIdentity() || ctx.pc != 0x18f6a0u ||
            rt.isStopRequested() || !hasGenuineContextStorage())
            throw std::invalid_argument("Composition original EE entry changed");
        if (ps2IoRegLockDepth() != 0)
            throw std::logic_error("Composition cannot wait under recursive IO ownership");
        reo_gpu_upstream::CallHandle call;
        std::vector<protocol::RawPatch> patches;
        std::unique_ptr<reo_parent_install::Service::RetainedInvocationScope> retainedScope;
        reo_parent_install::Service::RetainedInvocationHandle invocation;
        try {
            {
                std::lock_guard<std::recursive_mutex> sourceLock(sourceMutex_);
                std::lock_guard<std::recursive_mutex> protocolLock(service_.hostProtocolMutex());
                if (retained) {
                    retainedScope = service_.beginRetainedInvocationOnEe(rt, ram, ctx, ctx.pc,
                                                                         rt.lookupFunction(ctx.pc));
                    invocation = retainedScope->ticket();
                } else if (coldComponent)
                    consumeAuthenticColdMathEntry(ram, ctx, rt);
                call =
                    service_.prepareOriginalCompositionOnEe(ram, ctx, ps2_sched::currentThread());
                if (invocation)
                    service_.bindRetainedInvocationOnEe(invocation, call);
                frozenRanges_ = service_.originalCompositionHeldRanges(call);
                patches = journal_.takeAtActualFrontier();
                deferredContextControls_ = 0;
                boundedCompositionHold_.store(true, std::memory_order_release);
                heldT1_.store(true, std::memory_order_release);
            }
            auto self = shared_from_this();
            auto request = requestActualOwnerControl(epoch_, [self, call, invocation,
                                                              patches = std::move(patches)](
                                                                 ControlTarget& actual) {
                if (&actual != self.get())
                    throw std::invalid_argument("Composition reached foreign actual owner FIFO");
                if (invocation)
                    self->service_.requireRetainedInvocationOnOwner(invocation, call);
                self->service_.recordOriginalCompositionOnOwner(call, patches);
                self->owned_.store(true, std::memory_order_release);
                self->service_.waitOriginalCompositionOnOwner(call);
                if (invocation)
                    self->service_.requireRetainedInvocationOnOwner(invocation, call);
            });
            {
                PS2Runtime::GuestExecutionReleaseScope release(&rt);
                request->wait();
            }
            requireHealthy();
            if (rt.isStopRequested() || ps2_sched::currentThread() != call->task())
                throw std::runtime_error("Composition did not regain original guest task");
            {
                std::lock_guard<std::recursive_mutex> sourceLock(sourceMutex_);
                service_.commitOriginalCompositionOnEe(call, ram, ctx, ps2_sched::currentThread());
                if (invocation)
                    service_.finishRetainedInvocationOnEe(invocation, call);
                heldT1_.store(false, std::memory_order_release);
                boundedCompositionHold_.store(false, std::memory_order_release);
            }
            return true;
        } catch (...) {
            failed_.store(true, std::memory_order_release);
            throwOwnedSourceFailure(runtimeIdentity());
        }
    }

    bool atOriginalPerspective(uint8_t* ram, R5900Context& ctx, PS2Runtime& rt) override {
        const bool retainedComponent = retainedMathRequested(ctx.pc);
        if (!readyForSelection() && !retainedComponent)
            return false;
        if (&rt != runtimeIdentity() || &ctx != contextIdentity() ||
            !reo_gpu_upstream::Perspective18F710::supports(ctx.pc) || rt.isStopRequested())
            throw std::invalid_argument("Perspective lost actual guest entry ownership");
        if (ps2IoRegLockDepth() != 0)
            throw std::logic_error("Perspective cannot wait under recursive IO ownership");
        reo_gpu_upstream::CallHandle call;
        std::vector<protocol::RawPatch> patches;
        std::unique_ptr<reo_parent_install::Service::RetainedInvocationScope> invocation;
        reo_parent_install::Service::RetainedInvocationHandle ticket;
        try {
            {
                std::lock_guard<std::recursive_mutex> sourceLock(sourceMutex_);
                std::lock_guard<std::recursive_mutex> protocolLock(service_.hostProtocolMutex());
                if (retainedComponent) {
                    invocation = service_.beginRetainedInvocationOnEe(rt, ram, ctx, ctx.pc,
                                                                      rt.lookupFunction(ctx.pc));
                    ticket = invocation->ticket();
                }
                call =
                    service_.prepareOriginalPerspectiveOnEe(ram, ctx, ps2_sched::currentThread());
                if (ticket)
                    service_.bindRetainedInvocationOnEe(ticket, call);
                frozenRanges_ = {{protocol::Space::Ram, 0, reo_gpu_upstream::RamBytes},
                                 {protocol::Space::Spr, 0, reo_gpu_upstream::SprBytes},
                                 {protocol::Space::Context, 0, reo_gpu_upstream::ContextBytes}};
                patches = journal_.takeAtActualFrontier();
                deferredContextControls_ = 0;
                heldT1_.store(true, std::memory_order_release);
            }
            auto self = shared_from_this();
            auto request = requestActualOwnerControl(
                epoch_, [self, call, ticket, patches = std::move(patches)](ControlTarget& actual) {
                    if (&actual != self.get())
                        throw std::invalid_argument(
                            "Perspective reached foreign actual owner FIFO");
                    if (ticket)
                        self->service_.requireRetainedInvocationOnOwner(ticket, call);
                    self->service_.recordOriginalPerspectiveOnOwner(call, patches);
                    self->owned_.store(true, std::memory_order_release);
                    self->service_.waitOriginalPerspectiveOnOwner(call);
                    if (ticket)
                        self->service_.requireRetainedInvocationOnOwner(ticket, call);
                });
            {
                PS2Runtime::GuestExecutionReleaseScope release(&rt);
                request->wait();
            }
            if (rt.isStopRequested() || ps2_sched::currentThread() != call->task())
                throw std::runtime_error("Perspective did not reacquire genuine guest task");
            {
                std::lock_guard<std::recursive_mutex> lock(sourceMutex_);
                service_.commitOriginalPerspectiveOnEe(call, ram, ctx, ps2_sched::currentThread());
                if (ticket)
                    service_.finishRetainedInvocationOnEe(ticket, call);
                heldT1_.store(false, std::memory_order_release);
            }
            return true;
        } catch (...) {
            failed_.store(true, std::memory_order_release);
            throw;
        }
    }

    bool atOriginal191280(uint8_t* ram, R5900Context& ctx, PS2Runtime& rt) override {
        const bool retainedComponent = retainedMathRequested(ctx.pc);
        if (!readyForSelection() && !retainedComponent)
            return false;
        if (&rt != runtimeIdentity() || &ctx != contextIdentity() || ctx.pc != 0x191280u ||
            rt.isStopRequested())
            throw std::invalid_argument("Original191280 lost actual guest entry ownership");
        if (ps2IoRegLockDepth() != 0)
            throw std::logic_error("Original191280 cannot wait under recursive IO ownership");
        reo_gpu_upstream::CallHandle call;
        std::vector<protocol::RawPatch> patches;
        std::unique_ptr<reo_parent_install::Service::RetainedInvocationScope> invocation;
        reo_parent_install::Service::RetainedInvocationHandle ticket;
        try {
            {
                std::lock_guard<std::recursive_mutex> sourceLock(sourceMutex_);
                std::lock_guard<std::recursive_mutex> protocolLock(service_.hostProtocolMutex());
                if (retainedComponent) {
                    invocation = service_.beginRetainedInvocationOnEe(rt, ram, ctx, ctx.pc,
                                                                      rt.lookupFunction(ctx.pc));
                    ticket = invocation->ticket();
                }
                call = service_.prepareOriginal191280OnEe(ram, ctx, ps2_sched::currentThread());
                if (ticket)
                    service_.bindRetainedInvocationOnEe(ticket, call);
                frozenRanges_.clear();
                for (uint32_t address : {call->a0(), call->a1(), call->a2()}) {
                    const auto view = reo_gpu_upstream::matrixView(address);
                    frozenRanges_.push_back({view.bank == reo_gpu_upstream::Bank::Spr
                                                 ? protocol::Space::Spr
                                                 : protocol::Space::Ram,
                                             view.offset, 64});
                }
                patches = journal_.takeAtActualFrontier();
                deferredContextControls_ = 0;
                heldT1_.store(true, std::memory_order_release);
            }
            auto self = shared_from_this();
            auto request = requestActualOwnerControl(
                epoch_, [self, call, ticket, patches = std::move(patches)](ControlTarget& actual) {
                    if (&actual != self.get())
                        throw std::invalid_argument("Original191280 reached foreign owner FIFO");
                    if (ticket)
                        self->service_.requireRetainedInvocationOnOwner(ticket, call);
                    self->service_.recordOriginal191280OnOwner(call, patches);
                    self->owned_.store(true, std::memory_order_release);
                    self->service_.waitOriginal191280OnOwner(call);
                    if (ticket)
                        self->service_.requireRetainedInvocationOnOwner(ticket, call);
                });
            {
                PS2Runtime::GuestExecutionReleaseScope release(&rt);
                request->wait();
            }
            if (rt.isStopRequested() || ps2_sched::currentThread() != call->task())
                throw std::runtime_error("Original191280 did not reacquire genuine guest task");
            {
                std::lock_guard<std::recursive_mutex> lock(sourceMutex_);
                service_.commitOriginal191280OnEe(call, ram, ctx, ps2_sched::currentThread());
                if (ticket)
                    service_.finishRetainedInvocationOnEe(ticket, call);
                heldT1_.store(false, std::memory_order_release);
            }
            return true;
        } catch (...) {
            failed_.store(true, std::memory_order_release);
            throw;
        }
    }

  private:
    bool retainedMathRequested(uint32_t entry) const noexcept {
        if (!service_.hasRetainedInvocationAdmission())
            return false;
        for (const auto& original : service_.configuration_.retainedEntryBodies)
            if (original.entry == entry)
                return true;
        return false;
    }
    bool authenticColdMathRequested(uint32_t entry) const noexcept {
        return configuration_.authenticColdComponentEnrollment &&
               !configuration_.authenticColdSetterCommand &&
               configuration_.authenticColdComponentEntry == entry &&
               (entry == 0x197900u || entry == 0x18f6a0u ||
                reo_gpu_upstream::Viewport::supports(entry));
    }
    void consumeAuthenticColdMathEntry(uint8_t* ram, R5900Context& ctx, PS2Runtime& rt) {
        const auto& capture = cold_->capturedEntry;
        requireHealthy();
        if (!capture || authenticColdMathConsumed_ || !authenticColdMathRequested(ctx.pc) ||
            service_.configuration_.tier != protocol::AdmissionTier::OfflineComponent ||
            service_.configuration_.gates.ready() ||
            service_.configuration_.producerProofs.complete() || ram != capture->ramIdentity() ||
            &rt != &capture->runtime() || &ctx != &capture->context() ||
            ctx.pc != capture->originalEntry() ||
            capture->originalBodyIdentity() != configuration_.authenticColdComponentBody ||
            rt.lookupFunction(ctx.pc) != capture->originalBodyIdentity() ||
            ps2_sched::currentThread() != capture->task() || currentRuntime() != &rt ||
            currentContext() != &ctx || !ps2ActualGuestExecutionDepth(&rt) ||
            reo_source_instrumentation::actualInstructionOrigin.pc ||
            reo_source_instrumentation::actualInstructionOrigin.word)
            throw std::invalid_argument(
                "Cold math is not its one authentic registered pre-instruction entry/task/body");
        capture->requireOnEe();
        service_.requireFirstEntryUploadOnOwner(capture);
        authenticColdMathConsumed_ = true;
    }

  public:
    bool atOriginalViewport(uint8_t* ram, R5900Context& ctx, PS2Runtime& rt) override {
        // All source/native-copy, queue and IRQ gates stay hard false. Loading
        // the now-connected normal allocator cannot promote this route.
        const bool retainedComponent = retainedMathRequested(ctx.pc);
        const bool coldComponent = authenticColdMathRequested(ctx.pc) && !retainedComponent;
        if ((!readyForSelection() || !service_.ViewportNaturalSourceClosureImplemented ||
             !reo_gpu_upstream::Viewport::NaturalSourceClosureImplemented) &&
            !coldComponent && !retainedComponent)
            return false;
        if (&rt != runtimeIdentity() || &ctx != contextIdentity() ||
            !reo_gpu_upstream::Viewport::supports(ctx.pc) || rt.isStopRequested())
            throw std::invalid_argument("Viewport original EE entry identity differs");
        if (ps2IoRegLockDepth() != 0)
            throw std::logic_error("Viewport cannot wait under recursive IO ownership");
        reo_gpu_upstream::CallHandle call;
        std::vector<protocol::RawPatch> patches;
        std::unique_ptr<reo_parent_install::Service::RetainedInvocationScope> invocation;
        reo_parent_install::Service::RetainedInvocationHandle ticket;
        try {
            {
                std::lock_guard<std::recursive_mutex> sourceLock(sourceMutex_);
                if (coldComponent)
                    consumeAuthenticColdMathEntry(ram, ctx, rt);
                if (retainedComponent) {
                    invocation = service_.beginRetainedInvocationOnEe(rt, ram, ctx, ctx.pc,
                                                                      rt.lookupFunction(ctx.pc));
                    ticket = invocation->ticket();
                }
                call = service_.prepareOriginalViewportOnEe(ram, ctx, ps2_sched::currentThread());
                if (ticket)
                    service_.bindRetainedInvocationOnEe(ticket, call);
                if (coldComponent)
                    service_.exactOriginalViewport(call)->authenticBoundedMathCall = true;
                if (service_.hasOriginalViewportAllocator()) {
                    // Ordinary capture occurs before GPU ownership. If a prior
                    // opaque producer owns these words, it strictly refuses;
                    // future exact effects certificates must supply that seam.
                    auto frontier = captureProtectedScalars(&ctx, {0x29fdbcu, 0x29fdc0u});
                    service_.bindViewportHeapOriginOnEe(call, shared_from_this(), frontier, ctx);
                }
                if ((call->entry() == 0x18f880u || call->entry() == 0x197490u) &&
                    service_.hasViewportQueueModules()) {
                    auto resolver = captureQueueResolverOnEe(call, ctx);
                    auto queueCapture = captureViewportQueueBeforeGpuOnEe(call, resolver, ctx);
                    std::lock_guard<std::recursive_mutex> protocolLock(
                        service_.hostProtocolMutex());
                    auto entry = service_.exactOriginalViewport(call);
                    entry->queueResolver = std::move(resolver);
                    entry->queueCapture = std::move(queueCapture);
                    if (!entry->heapSourceOwner)
                        entry->heapSourceOwner = shared_from_this();
                }
                frozenRanges_ = {{protocol::Space::Ram, 0, reo_gpu_upstream::RamBytes},
                                 {protocol::Space::Spr, 0, reo_gpu_upstream::SprBytes},
                                 {protocol::Space::Context, 0, reo_gpu_upstream::ContextBytes}};
                patches = journal_.takeAtActualFrontier();
                deferredContextControls_ = 0;
                heldT1_.store(true, std::memory_order_release);
            }
            auto self = shared_from_this();
            auto request = requestActualOwnerControl(
                epoch_, [self, call, ticket, patches = std::move(patches)](ControlTarget& actual) {
                    if (&actual != self.get())
                        throw std::invalid_argument(
                            "Viewport callback reached a foreign actual owner FIFO");
                    if (ticket)
                        self->service_.requireRetainedInvocationOnOwner(ticket, call);
                    self->service_.recordOriginalViewportOnOwner(call, patches);
                    self->owned_.store(true, std::memory_order_release);
                    self->service_.waitOriginalViewportOnOwner(call);
                    if (ticket)
                        self->service_.requireRetainedInvocationOnOwner(ticket, call);
                });
            {
                PS2Runtime::GuestExecutionReleaseScope release(&rt);
                request->wait();
            }
            if (rt.isStopRequested() || ps2_sched::currentThread() != call->task())
                throw std::runtime_error("Viewport did not reacquire true guest task ownership");
            for (uint32_t allocations = 0u; service_.viewportControlPhaseOnEe(call) == 1u;
                 ++allocations) {
                // 197510 chooses either 19751C/48 or 197530/64. They are
                // alternatives, not two sequential allocations.
                if (allocations >= 1u)
                    throw std::runtime_error(
                        "Viewport exceeded its one source-derived allocation call");
                auto capture = service_.prepareOriginalAllocatorOnEe(call, rt, ram, ctx);
                auto allocation = requestActualOwnerControl(epoch_, [self, capture, call, ticket](
                                                                        ControlTarget& actual) {
                    if (&actual != self.get())
                        throw std::invalid_argument("Allocator reached foreign actual owner FIFO");
                    if (ticket)
                        self->service_.requireRetainedInvocationOnOwner(ticket, call);
                    self->service_.recordOriginalAllocatorOnOwner(capture);
                    self->service_.waitOriginalAllocatorOnOwner(capture);
                    if (ticket)
                        self->service_.requireRetainedInvocationOnOwner(ticket, call);
                });
                {
                    PS2Runtime::GuestExecutionReleaseScope release(&rt);
                    allocation->wait();
                }
                if (rt.isStopRequested() || ps2_sched::currentThread() != call->task())
                    throw std::runtime_error("Allocator did not reacquire original guest task");
                // Overflow remains truly held and cannot issue this token.
                auto commit = service_.issueAllocatorCommitOnEe(capture);
                commitCertifiedControlOnEe(commit, &ctx);
                auto returned = service_.issueAllocatorReturnOnEe(capture);
                auto resumed = requestActualOwnerControl(
                    epoch_, [self, capture, returned, call, ticket](ControlTarget& actual) {
                        if (&actual != self.get())
                            throw std::invalid_argument(
                                "Allocator continuation reached foreign actual owner FIFO");
                        if (ticket)
                            self->service_.requireRetainedInvocationOnOwner(ticket, call);
                        self->service_.resumeAllocatorViewportOnOwner(capture, returned);
                        self->service_.waitOriginalViewportOnOwner(call);
                        if (ticket)
                            self->service_.requireRetainedInvocationOnOwner(ticket, call);
                    });
                {
                    PS2Runtime::GuestExecutionReleaseScope release(&rt);
                    resumed->wait();
                }
                if (rt.isStopRequested() || ps2_sched::currentThread() != call->task())
                    throw std::runtime_error("Viewport continuation lost actual guest ownership");
            }
            if (service_.viewportControlPhaseOnEe(call) == 2u) {
                // Source/native/IRQ gates must be complete before selecting
                // this route. This private connected transport stays default-off.
                service_.requireCompleteViewportQueueIssuer();
                auto queue = service_.prepareViewportQueueOnEe(call, ctx);
                auto headers = requestActualOwnerControl(
                    epoch_, [self, queue, call, ticket](ControlTarget& actual) {
                        if (&actual != self.get())
                            throw std::invalid_argument("Queue header reached foreign actual FIFO");
                        if (ticket)
                            self->service_.requireRetainedInvocationOnOwner(ticket, call);
                        self->service_.recordViewportQueueHeaderOnOwner(queue);
                        self->service_.waitViewportQueueHeaderOnOwner(queue);
                        if (ticket)
                            self->service_.requireRetainedInvocationOnOwner(ticket, call);
                    });
                {
                    PS2Runtime::GuestExecutionReleaseScope release(&rt);
                    headers->wait();
                }
                if (rt.isStopRequested() || ps2_sched::currentThread() != call->task())
                    throw std::runtime_error("Queue header lost protected original EE task");
                service_.prepareViewportQueuePlanOnEe(queue, ctx);
                auto ordered = requestActualOwnerControl(epoch_, [self, queue, call,
                                                                  ticket](ControlTarget& actual) {
                    if (&actual != self.get())
                        throw std::invalid_argument("Queue journal reached foreign actual FIFO");
                    if (ticket)
                        self->service_.requireRetainedInvocationOnOwner(ticket, call);
                    self->service_.recordViewportQueueJournalOnOwner(queue);
                    self->service_.waitViewportQueueJournalOnOwner(queue);
                    if (ticket)
                        self->service_.requireRetainedInvocationOnOwner(ticket, call);
                });
                {
                    PS2Runtime::GuestExecutionReleaseScope release(&rt);
                    ordered->wait();
                }
                if (rt.isStopRequested() || ps2_sched::currentThread() != call->task())
                    throw std::runtime_error("Queue journal lost protected original EE task");
                auto commit = service_.issueViewportQueueCommitOnEe(queue);
                commitCertifiedQueueOnEe(commit, ctx);
                auto returned = service_.issueViewportQueueReturnOnEe(queue);
                auto resume = requestActualOwnerControl(
                    epoch_, [self, queue, returned, call, ticket](ControlTarget& actual) {
                        if (&actual != self.get())
                            throw std::invalid_argument(
                                "Queue continuation reached foreign actual FIFO");
                        if (ticket)
                            self->service_.requireRetainedInvocationOnOwner(ticket, call);
                        self->service_.resumeViewportQueueOnOwner(queue, returned);
                        self->service_.waitOriginalViewportOnOwner(call);
                        if (ticket)
                            self->service_.requireRetainedInvocationOnOwner(ticket, call);
                    });
                {
                    PS2Runtime::GuestExecutionReleaseScope release(&rt);
                    resume->wait();
                }
                if (rt.isStopRequested() || ps2_sched::currentThread() != call->task())
                    throw std::runtime_error("Queue final stage lost protected original EE task");
            }
            {
                std::lock_guard<std::recursive_mutex> sourceLock(sourceMutex_);
                service_.releaseFinalViewportQueueOnEe(call, ctx);
                service_.releaseFinalViewportHeapOriginOnEe(call, ctx);
                service_.commitOriginalViewportOnEe(call, ram, ctx, ps2_sched::currentThread());
                if (ticket)
                    service_.finishRetainedInvocationOnEe(ticket, call);
                certifiedAllocatorEvents_.erase(
                    std::remove_if(certifiedAllocatorEvents_.begin(),
                                   certifiedAllocatorEvents_.end(),
                                   [&](const auto& event) {
                                       return event.commit->output_->capture_->call_ == call;
                                   }),
                    certifiedAllocatorEvents_.end());
                certifiedQueueEvents_.erase(
                    std::remove_if(certifiedQueueEvents_.begin(), certifiedQueueEvents_.end(),
                                   [&](const auto& event) {
                                       return event.commit->call_->originalCall_ == call;
                                   }),
                    certifiedQueueEvents_.end());
                heldT1_.store(false, std::memory_order_release);
            }
            return true;
        } catch (...) {
            failed_.store(true, std::memory_order_release);
            throw;
        }
    }

    bool atOriginalStatePacket197900(uint8_t* ram, R5900Context& ctx, PS2Runtime& rt) override {
        // All source/native-copy, queue and IRQ gates stay hard false. Loading
        // the now-connected normal allocator cannot promote this route.
        const bool retainedMode = service_.hasRetainedInvocationAdmission();
        const bool coldComponent = !retainedMode && authenticColdMathRequested(ctx.pc);
        if ((!readyForSelection() || !service_.StatePacketNaturalSourceClosureImplemented) &&
            !coldComponent && !retainedMode)
            return false;
        if (&rt != runtimeIdentity() || &ctx != contextIdentity() || ctx.pc != 0x197900u ||
            rt.isStopRequested())
            throw std::invalid_argument("Viewport original EE entry identity differs");
        if (ps2IoRegLockDepth() != 0)
            throw std::logic_error("Viewport cannot wait under recursive IO ownership");
        std::unique_ptr<reo_parent_install::Service::RetainedInvocationScope> invocationScope;
        reo_parent_install::Service::RetainedInvocationHandle invocation;
        reo_gpu_upstream::CallHandle call;
        std::vector<protocol::RawPatch> patches;
        try {
            {
                std::lock_guard<std::recursive_mutex> sourceLock(sourceMutex_);
                if (retainedMode) {
                    invocationScope = service_.beginRetainedInvocationOnEe(
                        rt, ram, ctx, 0x197900u, rt.lookupFunction(0x197900u));
                    invocation = invocationScope->ticket();
                }
                if (coldComponent)
                    consumeAuthenticColdMathEntry(ram, ctx, rt);
                call = service_.prepareOriginalStatePacket197900OnEe(ram, ctx,
                                                                     ps2_sched::currentThread());
                if (invocation)
                    service_.bindRetainedInvocationOnEe(invocation, call);
                if (coldComponent)
                    service_.exactOriginalViewport(call)->authenticBoundedMathCall = true;
                if (service_.hasOriginalStatePacket197900()) {
                    // Ordinary capture occurs before GPU ownership. If a prior
                    // opaque producer owns these words, it strictly refuses;
                    // future exact effects certificates must supply that seam.
                    auto frontier = captureProtectedScalars(&ctx, {0x29fdbcu, 0x29fdc0u});
                    service_.bindViewportHeapOriginOnEe(call, shared_from_this(), frontier, ctx);
                }
                if (service_.hasOriginalStatePacket197900()) {
                    auto resolver = captureQueueResolverOnEe(call, ctx);
                    auto queueCapture = captureViewportQueueBeforeGpuOnEe(call, resolver, ctx);
                    std::lock_guard<std::recursive_mutex> protocolLock(
                        service_.hostProtocolMutex());
                    auto entry = service_.exactOriginalViewport(call);
                    entry->queueResolver = std::move(resolver);
                    entry->queueCapture = std::move(queueCapture);
                    if (!entry->heapSourceOwner)
                        entry->heapSourceOwner = shared_from_this();
                }
                frozenRanges_ = {{protocol::Space::Ram, 0, reo_gpu_upstream::RamBytes},
                                 {protocol::Space::Spr, 0, reo_gpu_upstream::SprBytes},
                                 {protocol::Space::Context, 0, reo_gpu_upstream::ContextBytes}};
                patches = journal_.takeAtActualFrontier();
                deferredContextControls_ = 0;
                heldT1_.store(true, std::memory_order_release);
            }
            auto self = shared_from_this();
            auto request = requestActualOwnerControl(
                epoch_,
                [self, call, invocation, patches = std::move(patches)](ControlTarget& actual) {
                    if (&actual != self.get())
                        throw std::invalid_argument(
                            "Viewport callback reached a foreign actual owner FIFO");
                    if (invocation)
                        self->service_.requireRetainedInvocationOnOwner(invocation, call);
                    self->service_.recordOriginalStatePacket197900OnOwner(call, patches);
                    self->owned_.store(true, std::memory_order_release);
                    self->service_.waitOriginalStatePacket197900OnOwner(call);
                    if (invocation)
                        self->service_.requireRetainedInvocationOnOwner(invocation, call);
                });
            {
                PS2Runtime::GuestExecutionReleaseScope release(&rt);
                request->wait();
            }
            if (rt.isStopRequested() || ps2_sched::currentThread() != call->task())
                throw std::runtime_error("Viewport did not reacquire true guest task ownership");
            for (uint32_t allocations = 0u; service_.viewportControlPhaseOnEe(call) == 1u;
                 ++allocations) {
                // 197A80 chooses either 197A8C/48 or 197AA0/64. They are
                // alternatives, not two sequential allocations.
                if (allocations >= 1u)
                    throw std::runtime_error(
                        "Viewport exceeded its one source-derived allocation call");
                auto capture = service_.prepareOriginalAllocatorOnEe(call, rt, ram, ctx);
                auto allocation = requestActualOwnerControl(
                    epoch_, [self, capture, call, invocation](ControlTarget& actual) {
                        if (&actual != self.get())
                            throw std::invalid_argument(
                                "Allocator reached foreign actual owner FIFO");
                        if (invocation)
                            self->service_.requireRetainedInvocationOnOwner(invocation, call);
                        self->service_.recordOriginalAllocatorOnOwner(capture);
                        self->service_.waitOriginalAllocatorOnOwner(capture);
                        if (invocation)
                            self->service_.requireRetainedInvocationOnOwner(invocation, call);
                    });
                {
                    PS2Runtime::GuestExecutionReleaseScope release(&rt);
                    allocation->wait();
                }
                if (rt.isStopRequested() || ps2_sched::currentThread() != call->task())
                    throw std::runtime_error("Allocator did not reacquire original guest task");
                // Overflow remains truly held and cannot issue this token.
                auto commit = service_.issueAllocatorCommitOnEe(capture);
                commitCertifiedControlOnEe(commit, &ctx);
                auto returned = service_.issueStateAllocatorReturnOnEe(capture);
                auto resumed = requestActualOwnerControl(
                    epoch_, [self, capture, returned, call, invocation](ControlTarget& actual) {
                        if (&actual != self.get())
                            throw std::invalid_argument(
                                "Allocator continuation reached foreign actual owner FIFO");
                        if (invocation)
                            self->service_.requireRetainedInvocationOnOwner(invocation, call);
                        self->service_.resumeStateAllocatorOnOwner(capture, returned);
                        self->service_.waitOriginalStatePacket197900OnOwner(call);
                        if (invocation)
                            self->service_.requireRetainedInvocationOnOwner(invocation, call);
                    });
                {
                    PS2Runtime::GuestExecutionReleaseScope release(&rt);
                    resumed->wait();
                }
                if (rt.isStopRequested() || ps2_sched::currentThread() != call->task())
                    throw std::runtime_error("Viewport continuation lost actual guest ownership");
            }
            if (service_.viewportControlPhaseOnEe(call) == 2u) {
                // Source/native/IRQ gates must be complete before selecting
                // this route. This private connected transport stays default-off.
                auto queue = service_.prepareViewportQueueOnEe(call, ctx);
                auto headers = requestActualOwnerControl(
                    epoch_, [self, queue, call, invocation](ControlTarget& actual) {
                        if (&actual != self.get())
                            throw std::invalid_argument("Queue header reached foreign actual FIFO");
                        if (invocation)
                            self->service_.requireRetainedInvocationOnOwner(invocation, call);
                        self->service_.recordViewportQueueHeaderOnOwner(queue);
                        self->service_.waitViewportQueueHeaderOnOwner(queue);
                        if (invocation)
                            self->service_.requireRetainedInvocationOnOwner(invocation, call);
                    });
                {
                    PS2Runtime::GuestExecutionReleaseScope release(&rt);
                    headers->wait();
                }
                if (rt.isStopRequested() || ps2_sched::currentThread() != call->task())
                    throw std::runtime_error("Queue header lost protected original EE task");
                service_.prepareViewportQueuePlanOnEe(queue, ctx);
                auto ordered = requestActualOwnerControl(epoch_, [self, queue, call, invocation](
                                                                     ControlTarget& actual) {
                    if (&actual != self.get())
                        throw std::invalid_argument("Queue journal reached foreign actual FIFO");
                    if (invocation)
                        self->service_.requireRetainedInvocationOnOwner(invocation, call);
                    self->service_.recordViewportQueueJournalOnOwner(queue);
                    self->service_.waitViewportQueueJournalOnOwner(queue);
                    if (invocation)
                        self->service_.requireRetainedInvocationOnOwner(invocation, call);
                });
                {
                    PS2Runtime::GuestExecutionReleaseScope release(&rt);
                    ordered->wait();
                }
                if (rt.isStopRequested() || ps2_sched::currentThread() != call->task())
                    throw std::runtime_error("Queue journal lost protected original EE task");
                auto commit = service_.issueViewportQueueCommitOnEe(queue);
                commitCertifiedQueueOnEe(commit, ctx);
                auto returned = service_.issueStateQueueReturnOnEe(queue);
                auto resume = requestActualOwnerControl(
                    epoch_, [self, queue, returned, call, invocation](ControlTarget& actual) {
                        if (&actual != self.get())
                            throw std::invalid_argument(
                                "Queue continuation reached foreign actual FIFO");
                        if (invocation)
                            self->service_.requireRetainedInvocationOnOwner(invocation, call);
                        self->service_.resumeStateQueueOnOwner(queue, returned);
                        self->service_.waitOriginalStatePacket197900OnOwner(call);
                        if (invocation)
                            self->service_.requireRetainedInvocationOnOwner(invocation, call);
                    });
                {
                    PS2Runtime::GuestExecutionReleaseScope release(&rt);
                    resume->wait();
                }
                if (rt.isStopRequested() || ps2_sched::currentThread() != call->task())
                    throw std::runtime_error("Queue final stage lost protected original EE task");
            }
            {
                std::lock_guard<std::recursive_mutex> sourceLock(sourceMutex_);
                service_.releaseFinalViewportQueueOnEe(call, ctx);
                service_.releaseFinalViewportHeapOriginOnEe(call, ctx);
                service_.commitOriginalStatePacket197900OnEe(call, ram, ctx,
                                                             ps2_sched::currentThread());
                if (invocation)
                    service_.finishRetainedInvocationOnEe(invocation, call);
                certifiedAllocatorEvents_.erase(
                    std::remove_if(certifiedAllocatorEvents_.begin(),
                                   certifiedAllocatorEvents_.end(),
                                   [&](const auto& event) {
                                       return event.commit->output_->capture_->call_ == call;
                                   }),
                    certifiedAllocatorEvents_.end());
                certifiedQueueEvents_.erase(
                    std::remove_if(certifiedQueueEvents_.begin(), certifiedQueueEvents_.end(),
                                   [&](const auto& event) {
                                       return event.commit->call_->originalCall_ == call;
                                   }),
                    certifiedQueueEvents_.end());
                heldT1_.store(false, std::memory_order_release);
            }
            return true;
        } catch (...) {
            failed_.store(true, std::memory_order_release);
            throw;
        }
    }

    void beforeAllocator(uint8_t* ram, R5900Context& ctx, PS2Runtime& rt) override {
        if (!readyForSelection())
            return;
        if (&rt != runtimeIdentity())
            throw std::invalid_argument("Parent allocator uses a foreign actual Runtime");
        std::lock_guard<std::recursive_mutex> lock(sourceMutex_);
        std::lock_guard<std::recursive_mutex> protocolLock(service_.hostProtocolMutex());
        gateway_.beforeActualAllocator(ram, ctx, ps2_sched::currentThread());
    }
    bool atAllocatorReturn(uint8_t* ram, R5900Context& ctx, PS2Runtime& rt) override {
        if (!readyForSelection())
            return false;
        if (&rt != runtimeIdentity() || &ctx != contextIdentity() || rt.isStopRequested())
            throw std::runtime_error("Parent frontier lost actual EE ownership");
        if (ps2IoRegLockDepth() != 0)
            throw std::logic_error("Parent T1 wait cannot start under recursive IO ownership");
        protocol::Allocation a;
        std::vector<protocol::RawPatch> patches;
        {
            std::lock_guard<std::recursive_mutex> lock(sourceMutex_);
            std::lock_guard<std::recursive_mutex> protocolLock(service_.hostProtocolMutex());
            a = gateway_.prepareActualAllocatorReturn(ram, ctx, ps2_sched::currentThread());
            frozenRanges_ = protocol::sourceRanges(a, ram);
            patches = journal_.takeAtActualFrontier();
            deferredContextControls_ = 0;
            heldT1_.store(true, std::memory_order_release);
        }
        try {
            auto self = shared_from_this();
            auto ticket = std::make_shared<Gateway<reo_parent_install::Service>::ReturnTicket>();
            auto accepted = std::make_shared<bool>(false);
            auto request = requestActualOwnerControl(epoch_, [self, a, patches = std::move(patches),
                                                              ticket,
                                                              accepted](ControlTarget& actual) {
                if (&actual != self.get())
                    throw std::invalid_argument("T1 request reached a foreign actual owner target");
                // GPU recording/fence/mailbox map happen only in actual FIFO.
                std::lock_guard<std::recursive_mutex> protocolLock(
                    self->service_.hostProtocolMutex());
                *accepted = self->gateway_.recordActualParentOnOwner(a, patches);
                if (*accepted) {
                    self->owned_.store(true, std::memory_order_release);
                    *ticket = self->gateway_.waitActualParentOnOwner(a.key);
                }
            });
            // Coverage must include every native/context-copy access before
            // this branch can run. Held actual context and source ranges stay
            // protected while the genuine scheduler releases guest execution.
            {
                PS2Runtime::GuestExecutionReleaseScope release(&rt);
                request->wait();
            }
            if (rt.isStopRequested() || ps2_sched::currentThread() != a.task)
                throw std::runtime_error(
                    "Parent T1 caller did not reacquire its actual guest task");
            if (!*accepted) {
                heldT1_.store(false);
                return false;
            }
            // Under reacquired EE ownership, HOST scalar publication only.
            {
                std::lock_guard<std::recursive_mutex> lock(sourceMutex_);
                std::lock_guard<std::recursive_mutex> protocolLock(service_.hostProtocolMutex());
                gateway_.commitActualParentOnEe(a, *ticket, ram, ctx);
                heldT1_.store(false, std::memory_order_release);
            }
            return true;
        } catch (...) {
            failed_.store(true, std::memory_order_release);
            throw;
        }
    }
    void read(SourceSpace space, uint32_t at, uint32_t n, R5900Context* ctx, uint32_t pc) override {
        try {
            requireHealthy();
            std::lock_guard<std::recursive_mutex> sourceLock(sourceMutex_);
            heldReadGuard(space, at, n, ctx);
            pendingAccessGuard(space, at, n, ctx);
            std::lock_guard<std::recursive_mutex> lock(service_.hostProtocolMutex());
            if (space == SourceSpace::Context && ctx)
                service_.guardKnownContextRead(*ctx, at, n);
            else
                service_.beforeUpstreamSourceAccess(static_cast<protocol::Space>(space), at, n);
            if (space == SourceSpace::Ram)
                gateway_.beforeRamRead(at, n, pc);
            else if (space == SourceSpace::Context && ctx)
                gateway_.beforeContextReadOrUnknownWrite(*ctx, at, n, pc);

        } catch (...) {
            failed_.store(true, std::memory_order_release);
            throwOwnedSourceFailure(runtimeIdentity());
        }
    }
    void beforeUnknownWrite(SourceSpace space, uint32_t at, uint32_t n, R5900Context* ctx,
                            uint32_t pc) override {
        try {
            requireHealthy();
            std::lock_guard<std::recursive_mutex> sourceLock(sourceMutex_);
            if (space == SourceSpace::Context && ctx && service_.isFrozenCallbackCaller(*ctx))
                throw std::runtime_error("Caller Context write overtook its active callback loan");
            heldWriteGuard(space, at, n, ctx);
            protectedWriteGuard(space, at, n);
            pendingAccessGuard(space, at, n, ctx);
            if (space == SourceSpace::Ram)
                invalidateControlHistory(at, n);
            std::lock_guard<std::recursive_mutex> protocolLock(service_.hostProtocolMutex());
            if (space == SourceSpace::Context && ctx)
                service_.guardKnownContextRead(*ctx, at, n);
            else
                service_.beforeUpstreamSourceAccess(static_cast<protocol::Space>(space), at, n);
            // Generic native writes never consume a reviewed-site or pending
            // transaction shortcut. Only the explicit immutable permit can.
            if (space == SourceSpace::Context && ctx)
                gateway_.beforeContextReadOrUnknownWrite(*ctx, at, n, pc);
            else
                gateway_.beforeSourceWrite(static_cast<protocol::Space>(space), at, n, pc);

        } catch (...) {
            failed_.store(true, std::memory_order_release);
            throwOwnedSourceFailure(runtimeIdentity());
        }
    }
    void prepareRawWrite(SourceSpace, uint32_t, const void*, uint32_t, R5900Context*,
                         uint32_t) override {
        throw std::logic_error("Legacy raw prepare lacks explicit matched source write permit");
    }
    void completedRawWrite(SourceSpace, uint32_t, uint32_t, R5900Context*, uint32_t) override {
        throw std::logic_error("Legacy raw completion cannot consume explicit source permit");
    }

  private:
    std::weak_ptr<PreparedSourceWrite> pendingSourceWrite_;
    uint64_t nextSourceWrite_ = 1, nextScalarCapture_ = 1;
    uint64_t deferredContextControls_ = 0;
    // Populated only by completion of this target's exact typed metadata
    // permits; current Context bits alone never provide branch provenance.
    reo_source_closure::CompletedDelayFacts completedDelay_{};
    FirstEntryInvocationHandle completedDelayScope_, completedSourceEntryScope_;
    uint32_t completedSourceEntryPc_ = 0;
    PS2Runtime::RecompiledFunction completedSourceEntryBody_ = nullptr;
    uint64_t completedSourceEntryWriter_ = 0, pendingDelayMetadataSequence_ = 0;
    reo_source_closure::CompletedDelayFacts
    delayLiveFacts(R5900Context& ctx, const FirstEntryInvocationHandle& scope) const {
        reo_source_closure::CompletedDelayFacts x;
        x.scope = scope.get();
        x.context = &ctx;
        x.task = ps2_sched::currentThread();
        x.thread = std::this_thread::get_id();
        x.epoch = epoch_;
        x.gpuCalls = service_.upstreamOrdinal_;
        if (completedSourceEntryScope_ == scope && completedSourceEntryBody_ &&
            runtimeIdentity()->lookupFunction(completedSourceEntryPc_) ==
                completedSourceEntryBody_) {
            x.entryPc = completedSourceEntryPc_;
            x.body = completedSourceEntryBody_;
            x.entryWriter = completedSourceEntryWriter_;
        }
        return x;
    }
    void clearCompletedDelay() noexcept {
        completedDelay_ = {};
        completedDelayScope_.reset();
    }

    std::vector<protocol::Range> pendingContextControlOpaque_;
    struct ControlHistoryWord {
        uint32_t address, bits, sourcePc, sourceWord;
        uint64_t completedWriter;
        bool valid;
        uint8_t coverageMask = 15u;
    };
    std::vector<ControlHistoryWord> controlHistory_;
    bool pendingScalarHistory_ = false;
    uint32_t pendingScalarSourceWord_ = 0;
    void invalidateControlHistory(uint32_t at, uint32_t bytes) noexcept {
        for (auto& word : controlHistory_)
            if (protocol::overlap(at, bytes, word.address, 4)) {
                word.valid = false;
                word.coverageMask = 0u;
            }
    }
    const ControlHistoryWord* controlHistory(uint32_t address) const noexcept {
        for (const auto& word : controlHistory_)
            if (word.address == address)
                return &word;
        return nullptr;
    }
    void reserveControlHistory(SourceSpace space, uint32_t at, uint32_t bytes, uint32_t pc,
                               bool authenticatedPool = false, bool authenticatedHeader = false) {
        pendingScalarHistory_ =
            space == SourceSpace::Ram &&
            (authenticatedPool || authenticatedHeader ||
             (!(at & 3u) && !(bytes & 3u) && journal_.reviewedScalar(space, at, bytes, pc)));
        if (space == SourceSpace::Ram && poolControlWriters_.protects(at, bytes) &&
            !authenticatedPool)
            pendingScalarHistory_ = false;
        if (!pendingScalarHistory_)
            return;
        std::memcpy(&pendingScalarSourceWord_, static_cast<const uint8_t*>(ramIdentity()) + pc,
                    4); // Same pre-store guarded opcode; immutable through mirror.
        const uint32_t extra = (bytes + 3u) / 4u;
        if (extra > 65536u || controlHistory_.size() > 65536u - extra)
            throw std::runtime_error("Actual scalar writer history exhausted before store");
        controlHistory_.reserve(controlHistory_.size() +
                                extra); // Completion cannot allocate after CPU store.
    }
    void completeControlHistory(const PreparedSourceWrite& pending) noexcept {
        if (pending.space_ != SourceSpace::Ram)
            return;
        if (pendingPoolControlHistory_) {
            // Every byte must have an authenticated completed writer. A zero
            // value or old CPU word never supplies missing byte provenance.
            for (uint32_t k = 0; k < pending.bytes_; ++k) {
                const uint32_t address = pending.at_ + k, aligned = address & ~3u;
                ControlHistoryWord* found = nullptr;
                for (auto& word : controlHistory_)
                    if (word.address == aligned)
                        found = &word;
                if (!found) {
                    controlHistory_.push_back({aligned, 0u, pending.pc_, pendingScalarSourceWord_,
                                               pending.sequence_, false, 0u});
                    found = &controlHistory_.back();
                }
                const uint32_t shift = (address & 3u) * 8u;
                found->bits = (found->bits & ~(255u << shift)) |
                              (uint32_t(static_cast<const uint8_t*>(pending.data())[k]) << shift);
                found->coverageMask |= uint8_t(1u << (address & 3u));
                found->sourcePc = pending.pc_;
                found->sourceWord = pendingScalarSourceWord_;
                found->completedWriter = pending.sequence_;
                found->valid = found->coverageMask == 15u;
            }
            return;
        }
        invalidateControlHistory(pending.at_, pending.bytes_);
        if (!pendingScalarHistory_)
            return;
        for (uint32_t k = 0; k < pending.bytes_; k += 4) {
            uint32_t bits;
            std::memcpy(&bits, static_cast<const uint8_t*>(pending.data()) + k, 4);
            ControlHistoryWord* found = nullptr;
            for (auto& word : controlHistory_)
                if (word.address == pending.at_ + k)
                    found = &word;
            const ControlHistoryWord event{pending.at_ + k,   bits,
                                           pending.pc_,       pendingScalarSourceWord_,
                                           pending.sequence_, true};
            if (found)
                *found = event;
            else
                controlHistory_.push_back(event);
        }
    }
    struct ProtectedRevision {
        uint32_t address;
        uint64_t completedWriter;
    };
    std::array<ProtectedRevision, 19> protectedRevisions_{{{0x29fdb8u, 0},
                                                           {0x29fdbcu, 0},
                                                           {0x29fdc0u, 0},
                                                           {0x29fdb4u, 0},
                                                           {0x29f6f0u, 0},
                                                           {0x29f6f4u, 0},
                                                           {0x29f6f8u, 0},
                                                           {0x29f6fcu, 0},
                                                           {0x29f700u, 0},
                                                           {0x29f704u, 0},
                                                           {0x29f708u, 0},
                                                           {0x29f70cu, 0},
                                                           {0x29f710u, 0},
                                                           {0x29f714u, 0},
                                                           {0x29f718u, 0},
                                                           {0x29f71cu, 0},
                                                           {0x29f720u, 0},
                                                           {0x29f724u, 0},
                                                           {0x29f728u, 0}}};
    std::vector<std::weak_ptr<const ProtectedScalarCapture>> protectedCaptures_;
    void actualSourceScope(R5900Context* ctx, uint32_t pc, bool requireSamePc = true) const {
        if (!ctx || currentRuntime() != runtimeIdentity() || currentContext() != ctx ||
            !ps2ActualGuestExecutionDepth(runtimeIdentity()) || (requireSamePc && ctx->pc != pc))
            throw std::invalid_argument(
                "Source transaction lost real guest execution/context/site");
    }
    void protectedWriteGuard(SourceSpace space, uint32_t at, uint32_t n) const {
        if (space != SourceSpace::Ram)
            return;
        for (const auto& weak : protectedCaptures_)
            if (auto capture = weak.lock())
                for (const auto& word : capture->words_)
                    if (protocol::overlap(at, n, word.address, 4))
                        throw std::runtime_error(
                            "Source writer overtook protected scalar capture lease");
    }
    void pendingAccessGuard(SourceSpace space, uint32_t at, uint32_t n, R5900Context* ctx) const {
        if (auto pending = pendingSourceWrite_.lock())
            if (pending->space_ == space &&
                (space != SourceSpace::Context || pending->context_ == ctx) &&
                protocol::overlap(at, n, pending->at_, pending->bytes_))
                throw std::runtime_error(
                    "Source access overtook uncompleted exact write transaction");
    }
    PreparedSourceWrite& exactSourceWrite(const SourceWritePermit& permit, SourceSpace space,
                                          uint32_t at, uint32_t n, R5900Context* ctx, uint32_t pc,
                                          bool beforeStore) {
        actualSourceScope(ctx, pc, beforeStore);
        auto pending = pendingSourceWrite_.lock();
        if (!permit || !pending || permit.get() != pending.get() || pending->issuer_ != this ||
            pending->space_ != space || pending->at_ != at || pending->bytes_ != n ||
            pending->pc_ != pc || pending->epoch_ != epoch_ ||
            pending->sequence_ != nextSourceWrite_ || pending->context_ != ctx ||
            pending->task_ != ps2_sched::currentThread() ||
            pending->hostThread_ != std::this_thread::get_id() ||
            !pending->sourceLease_.owns_lock() || pending->completed_)
            throw std::invalid_argument("Foreign/reused/stale source write permit");
        if (!beforeStore && ctx->pc != pending->afterPc_)
            throw std::invalid_argument("Source completion changed unrelated original control PC");
        if (pending->validateActualIssuer_)
            pending->validateActualIssuer_();
        return *pending;
    }

  public:
#include "native_irq_cpu_controls1.inc"
#include "native_irq_packet_headers1.inc"
#include "native_heap_controls1.inc"
    SourceWritePermit beginAuthenticatedNativeControlWrite(R5900Context& ctx,
                                                           const NativeControlReturnHandle& event,
                                                           uint32_t at, const void* data,
                                                           uint32_t n) override {
        try {
            requireHealthy();
            actualSourceScope(&ctx, ctx.pc);
            std::unique_lock<std::recursive_mutex> sourceLock(sourceMutex_);
            std::lock_guard<std::recursive_mutex> protocolLock(service_.hostProtocolMutex());
            if (!event || event->issuerTarget() != this || &event->runtime() != runtimeIdentity() ||
                &event->context() != &ctx || &ctx != contextIdentity() ||
                !hasGenuineContextStorage() || !data || at != 32u || n != 16u ||
                !pendingSourceWrite_.expired() || nextSourceWrite_ == UINT64_MAX ||
                deferredContextControls_ == UINT64_MAX)
                throw std::invalid_argument(
                    "Native return lacks actual owner/exact v0 transaction");
            if (service_.isFrozenCallbackCaller(ctx))
                throw std::runtime_error("Native return overtook an active caller Context loan");
            heldWriteGuard(SourceSpace::Context, at, n, &ctx);
            pendingAccessGuard(SourceSpace::Context, at, n, &ctx);
            event->validateBeforeActualNativeStore(*this, ctx, at, data, n);
            const bool input =
                event->routine() == NativeRoutine::Abs || event->routine() == NativeRoutine::Srand;
            const auto expectedRole =
                event->routine() == NativeRoutine::EndOfHeap
                    ? NativeReturnRole::GuestPointer
                    : (event->routine() == NativeRoutine::GetThreadId ||
                               event->routine() == NativeRoutine::GetMemorySize
                           ? NativeReturnRole::KernelControl
                           : NativeReturnRole::Integer);
            if (event->role() != expectedRole || event->readCount() != (input ? 1u : 0u))
                throw std::invalid_argument(
                    "Native return differs from its complete reviewed body contract");
            if (input) {
                const auto& r = event->read(0);
                if (r.space != SourceSpace::Context || r.offset != 64u || r.bytes != 4u ||
                    !reo_source_closure::scalarControlLane(service_.compositionScalarRoles_, 64u,
                                                           4u))
                    throw std::invalid_argument(
                        "Integer native input has no retained scalar-control lineage");
                read(r.space, r.offset, r.bytes, &ctx, ctx.pc);
            }
            // This is a blind complete authored v0 overwrite; no old upper or
            // opaque destination lane is read. Allocation precedes CPU mutation.
            auto nextOpaque = service_.prepareTypedContextControlTransition(ctx, at, n);
            gateway_.prepareActualRawWriterCompletion();
            event->claimBeforeActualNativeStore(*this, ctx, at, data, n);
            auto permit = std::shared_ptr<PreparedSourceWrite>(new PreparedSourceWrite(
                this, SourceSpace::Context, at, data, n, ctx.pc, epoch_, nextSourceWrite_, &ctx,
                ps2_sched::currentThread(), true, std::move(sourceLock)));
            permit->validateActualIssuer_ = [this, event, context = &ctx, at, n] {
                event->validateBeforeActualNativeStore(*this, *context, at, event->data(), n);
            };
            journal_.prepareAuthenticatedContextWrite(at, permit->data(), n, ctx.pc,
                                                      protocol::SourcePatchKind::NativeScalar);
            permit->deferredControl_ = true;
            permit->deferredControlRole_ =
                event->role() == NativeReturnRole::GuestPointer ? 5u : 7u;
            pendingContextControlOpaque_ = std::move(nextOpaque);
            pendingScalarHistory_ = false;
            permit->mirrored_ = true;
            pendingSourceWrite_ = permit;
            return permit;
        } catch (...) {
            failed_.store(true, std::memory_order_release);
            throwOwnedSourceFailure(runtimeIdentity());
        }
    }
    SourceWritePermit beginGuardedCpuContextWrite(
        R5900Context& ctx, const reo_source_instrumentation::InstructionInputEvidenceHandle& inputs,
        uint32_t at, const void* data, uint32_t n,
        const reo_source_instrumentation::InstructionOrigin& origin) override {
        try {
            requireHealthy();
            actualSourceScope(&ctx, ctx.pc);
            std::unique_lock<std::recursive_mutex> sourceLock(sourceMutex_);
            std::lock_guard<std::recursive_mutex> protocolLock(service_.hostProtocolMutex());
            if (!inputs || inputs->issuerTarget() != this ||
                &inputs->runtime() != runtimeIdentity() || &inputs->context() != &ctx ||
                &ctx != contextIdentity() || !hasGenuineContextStorage() || !data ||
                !protocol::range(at, n, 1648u) || n > 16u || !pendingSourceWrite_.expired() ||
                nextSourceWrite_ == UINT64_MAX || deferredContextControls_ == UINT64_MAX)
                throw std::invalid_argument(
                    "CPU ingress lacks actual owner/exact bounded transaction");
            if (service_.isFrozenCallbackCaller(ctx))
                throw std::runtime_error("CPU ingress overtook an active caller Context loan");
            heldWriteGuard(SourceSpace::Context, at, n, &ctx);
            pendingAccessGuard(SourceSpace::Context, at, n, &ctx);
            inputs->validateBeforeActualCpuStore(*this, ctx, origin);
            if (origin.pc != ctx.pc || !protocol::range(origin.pc, 4u, protocol::RamBytes))
                throw std::invalid_argument("CPU ingress lost its actual bounded instruction PC");
            read(SourceSpace::Ram, origin.pc, 4u, &ctx, ctx.pc);
            uint32_t word;
            std::memcpy(&word, static_cast<const uint8_t*>(ramIdentity()) + origin.pc, 4u);
            if (word != origin.word)
                throw std::invalid_argument(
                    "CPU ingress original opcode changed before exact store");
            struct View {
                SourceSpace space;
                uint32_t at, limit;
                bool source;
            };
            reo_source_closure::validateGuardedCpuIngress(
                *inputs, at, data, n, origin, [&](uint32_t ea, bool fast) {
                    if (fast || !PS2Runtime::isSpecialAddress(ea))
                        return View{SourceSpace::Ram, ea & PS2_RAM_MASK, PS2_RAM_SIZE, true};
                    const bool scratch = runtimeIdentity()->memory().isScratchpad(ea);
                    const uint32_t physical = runtimeIdentity()->memory().translateAddress(ea);
                    if (scratch)
                        return View{SourceSpace::Spr, physical, PS2_SCRATCHPAD_SIZE, true};
                    if (physical < PS2_RAM_SIZE)
                        return View{SourceSpace::Ram, physical, PS2_RAM_SIZE, true};
                    return View{SourceSpace::Ram, 0, 0, false};
                });
            // Revalidate both effects and Bridge masks for every captured source
            // span; the receiver never re-reads any numerical input bytes.
            for (uint32_t i = 0; i < inputs->readCount(); ++i) {
                const auto& r = inputs->read(i);
                read(r.space, r.offset, r.bytes, &ctx, ctx.pc);
            }
            auto nextOpaque = service_.prepareTypedContextControlTransition(ctx, at, n);
            gateway_.prepareActualRawWriterCompletion();
            auto permit = std::shared_ptr<PreparedSourceWrite>(new PreparedSourceWrite(
                this, SourceSpace::Context, at, data, n, ctx.pc, epoch_, nextSourceWrite_, &ctx,
                ps2_sched::currentThread(), true, std::move(sourceLock)));
            permit->validateActualIssuer_ = [this, inputs, context = &ctx, origin] {
                inputs->validateBeforeActualCpuStore(*this, *context, origin);
            };
            journal_.prepareAuthenticatedContextWrite(at, permit->data(), n, ctx.pc,
                                                      protocol::SourcePatchKind::CpuNumeric);
            permit->deferredControl_ = true;
            permit->deferredControlRole_ = 0u;
            pendingContextControlOpaque_ = std::move(nextOpaque);
            pendingScalarHistory_ = false;
            permit->mirrored_ = true;
            pendingSourceWrite_ = permit;
            return permit;
        } catch (...) {
            failed_.store(true, std::memory_order_release);
            throwOwnedSourceFailure(runtimeIdentity());
        }
    }
    SourceWritePermit
    beginTypedSourceWrite(SourceSpace space, uint32_t at, const void* data, uint32_t n,
                          R5900Context* ctx, uint32_t pc,
                          const reo_source_instrumentation::InstructionOrigin& origin) override {
        using I = reo_source_instrumentation::ContextWriteIntent;
        if (space == SourceSpace::Context && ctx == contextIdentity() &&
            origin.intent == I::ReviewedRawIngress &&
            reo_source_instrumentation::actualInstructionInputs) {
            try {
                auto inputs = reo_source_instrumentation::actualInstructionInputs->capture(
                    *ctx, origin, shared_from_this());
                return beginGuardedCpuContextWrite(*ctx, inputs, at, data, n, origin);
            } catch (...) {
                failed_.store(true, std::memory_order_release);
                throwOwnedSourceFailure(runtimeIdentity());
            }
        }
        // RAW candidates remain subject to the actual registered writer site;
        // numerical outputs never gain mirror authority from the source claim.
        if (space != SourceSpace::Context || ctx != contextIdentity() ||
            origin.intent == I::ReviewedRawIngress)
            return beginSourceWrite(space, at, data, n, ctx, pc);
        if (origin.intent == I::NumericOrOpaque) {
            if (!ownsAnySource())
                return beginSourceWrite(space, at, data, n, ctx, pc);
            try {
                throw std::runtime_error(
                    "Owned Context numeric producer needs its actual GPU/source-input route");
            } catch (...) {
                failed_.store(true, std::memory_order_release);
                throwOwnedSourceFailure(runtimeIdentity());
            }
        }
        try {
            requireHealthy();
            actualSourceScope(ctx, pc);
            std::unique_lock<std::recursive_mutex> sourceLock(sourceMutex_);
            if (ctx != contextIdentity() || !data || !protocol::range(at, n, 1648u) ||
                !pendingSourceWrite_.expired() || nextSourceWrite_ == UINT64_MAX)
                throw std::invalid_argument("Typed Context writer lacks exact actual source scope");
            if (space == SourceSpace::Context && ctx && service_.isFrozenCallbackCaller(*ctx))
                throw std::runtime_error("Caller Context write overtook its active callback loan");
            heldWriteGuard(space, at, n, ctx);
            pendingAccessGuard(space, at, n, ctx);
            const bool metadata = origin.intent == I::GeneratedPcProgress &&
                                  ((at == offsetof(R5900Context, pc) && n == 4) ||
                                   (at == offsetof(R5900Context, branch_pc) && n == 4) ||
                                   (at == offsetof(R5900Context, in_delay_slot) && n == 1));
            const uint32_t instructionPc = metadata ? origin.pc : pc;
            read(SourceSpace::Ram, instructionPc, 4, ctx, pc);
            uint32_t word;
            std::memcpy(&word, static_cast<const uint8_t*>(ramIdentity()) + instructionPc, 4);
            if ((!metadata && origin.pc != pc) || origin.word != word)
                throw std::invalid_argument(
                    "Typed instruction differs from genuine original RAW opcode");

            std::unique_ptr<reo_source_closure::CompletedDelayControl> delayCertificate;
            FirstEntryInvocationHandle metadataScope;
            const bool delayField = at == offsetof(R5900Context, in_delay_slot) && n == 1u;
            const bool branchField = at == offsetof(R5900Context, branch_pc) && n == 4u;
            if (metadata) {
                metadataScope = reo_source_instrumentation::EntryScope::retainFirstEntryInvocation(
                    *runtimeIdentity(), *ctx);
                if (delayField && *static_cast<const uint8_t*>(data) == 0u &&
                    !reo_source_closure::sourceControlFlow(origin.word)) {
                    const auto live = delayLiveFacts(*ctx, metadataScope);
                    uint32_t branchWord = 0;
                    if (completedDelay_.enteredWriter) {
                        read(SourceSpace::Ram, completedDelay_.branchPc, 4u, ctx, pc);
                        std::memcpy(&branchWord,
                                    static_cast<const uint8_t*>(ramIdentity()) +
                                        completedDelay_.branchPc,
                                    4u);
                    }
                    service_.guardKnownContextRead(*ctx, offsetof(R5900Context, in_delay_slot), 1u);
                    service_.guardKnownContextRead(*ctx, offsetof(R5900Context, branch_pc), 4u);
                    const bool retained =
                        reo_source_closure::scalarControlLane(service_.compositionScalarRoles_,
                                                              offsetof(R5900Context, in_delay_slot),
                                                              1u) &&
                        reo_source_closure::scalarControlLane(service_.compositionScalarRoles_,
                                                              offsetof(R5900Context, branch_pc),
                                                              4u);
                    if (!reo_source_closure::completedDelayMatches(
                            completedDelay_, live, nextSourceWrite_, pc, origin, ctx->in_delay_slot,
                            ctx->branch_pc, branchWord, retained))
                        throw std::invalid_argument(
                            "Delay retirement lacks completed same-scope original branch metadata");
                    delayCertificate.reset(
                        new reo_source_closure::CompletedDelayControl(origin.pc, origin.word));
                }
            }
            try {
                service_.guardKnownContextWrite(*ctx, at, n, data, pc, origin,
                                                delayCertificate.get());
            } catch (const std::exception& e) {
                throw std::invalid_argument(
                    std::string(e.what()) + " [Context offset=" + std::to_string(at) +
                    " bytes=" + std::to_string(n) + " sourcePC=" + std::to_string(pc) +
                    " originPC=" + std::to_string(origin.pc) +
                    " opcode=" + std::to_string(origin.word) +
                    " intent=" + std::to_string(uint32_t(origin.intent)) + "]");
            }

            auto nextOpaque = service_.prepareTypedContextControlTransition(*ctx, at, n);
            gateway_.prepareActualRawWriterCompletion();
            auto permit = std::shared_ptr<PreparedSourceWrite>(
                new PreparedSourceWrite(this, space, at, data, n, pc, epoch_, nextSourceWrite_, ctx,
                                        ps2_sched::currentThread(), true, std::move(sourceLock)));
            journal_.prepareValidatedContextControl(at, permit->data(), n, pc);
            permit->deferredControl_ = true;
            permit->deferredControlRole_ =
                (at == offsetof(R5900Context, pc) || at == offsetof(R5900Context, branch_pc) ||
                 at / 16u == 31u)
                    ? 3u
                    : (at / 16u == 29u ? 6u : 7u);

            pendingDelayMetadataSequence_ = metadata ? nextSourceWrite_ : 0;
            if (metadata) {
                const auto facts = delayLiveFacts(*ctx, metadataScope);
                uint32_t value = 0;
                std::memcpy(&value, data, n);
                const auto registeredBody =
                    at == offsetof(R5900Context, pc) && n == 4u && origin.pc == pc && value == pc
                        ? runtimeIdentity()->lookupFunction(pc)
                        : nullptr;
                permit->completeActualIssuer_ = [this, facts, metadataScope, registeredBody, origin,
                                                 at, n, value, sequence = nextSourceWrite_] {
                    if (completedSourceEntryScope_ != metadataScope) {
                        clearCompletedDelay();
                        completedSourceEntryScope_.reset();
                        completedSourceEntryPc_ = 0;
                        completedSourceEntryBody_ = nullptr;
                        completedSourceEntryWriter_ = 0;
                    }
                    if (registeredBody) {
                        completedSourceEntryScope_ = metadataScope;
                        completedSourceEntryPc_ = origin.pc;
                        completedSourceEntryBody_ = registeredBody;
                        completedSourceEntryWriter_ = sequence;
                    }
                    if (at == offsetof(R5900Context, in_delay_slot) && n == 1u) {
                        clearCompletedDelay();
                        if (value == 1u && facts.entryWriter && facts.body &&
                            reo_source_closure::sourceControlFlow(origin.word)) {
                            completedDelay_ = facts;
                            completedDelay_.branchPc = origin.pc;
                            completedDelay_.branchWord = origin.word;
                            completedDelay_.enteredWriter = sequence;
                            completedDelayScope_ = metadataScope;
                        }
                    } else if (at == offsetof(R5900Context, branch_pc) && n == 4u) {
                        if (completedDelay_.scope == facts.scope &&
                            completedDelay_.context == facts.context &&
                            completedDelay_.task == facts.task &&
                            completedDelay_.thread == facts.thread &&
                            completedDelay_.epoch == facts.epoch &&
                            completedDelay_.enteredWriter + 1u == sequence &&
                            origin.pc == completedDelay_.branchPc &&
                            origin.word == completedDelay_.branchWord && value == origin.pc)
                            completedDelay_.branchWriter = sequence;
                        else
                            clearCompletedDelay();
                    }
                };
            }
            pendingContextControlOpaque_ = std::move(nextOpaque);
            permit->mirrored_ = true;
            pendingSourceWrite_ = permit;
            // No owner FIFO or device wait per instruction. The immutable
            // completed event is recorded before the next actual GPU frontier.
            return permit;
        } catch (...) {
            failed_.store(true, std::memory_order_release);
            throwOwnedSourceFailure(runtimeIdentity());
        }
    }
    bool hasDeferredContextControls() const {
        std::lock_guard<std::recursive_mutex> lock(sourceMutex_);
        return deferredContextControls_ != 0 || !pendingSourceWrite_.expired();
    }
    SourceWritePermit beginSourceWrite(SourceSpace space, uint32_t at, const void* data, uint32_t n,
                                       R5900Context* ctx, uint32_t pc) override {
        try {
            requireHealthy();
            actualSourceScope(ctx, pc);
            std::unique_lock<std::recursive_mutex> sourceLock(sourceMutex_);
            const uint32_t limit = space == SourceSpace::Ram   ? protocol::RamBytes
                                   : space == SourceSpace::Spr ? 0x4000u
                                                               : 1648u;
            if (!data || !protocol::range(at, n, limit) || n > 1024u * 1024u ||
                !pendingSourceWrite_.expired() || nextSourceWrite_ == UINT64_MAX)
                throw std::invalid_argument("Source transaction invalid/exhausted/overlapping");
            if (space == SourceSpace::Context && ctx && service_.isFrozenCallbackCaller(*ctx))
                throw std::runtime_error("Caller Context write overtook its active callback loan");
            heldWriteGuard(space, at, n, ctx);
            protectedWriteGuard(space, at, n);
            if (!protocol::range(pc, 4u, protocol::RamBytes))
                throw std::invalid_argument("Source writer opcode is outside actual RAM");
            read(SourceSpace::Ram, pc, 4, ctx,
                 pc); // Actual instruction identity is a guarded RAW source.
            if (space == SourceSpace::Ram && poolControlWriters_.protects(at, n) &&
                PoolControlWriterCatalogue::requiresDescriptorHistory(pc))
                for (uint32_t address : {0x2afef0u, 0x2afef8u}) {
                    const auto* history = controlHistory(address);
                    if (!history || !history->valid || !history->completedWriter)
                        throw std::invalid_argument(
                            "Pool pointer store lost actual completed descriptor control lineage");
                }
            pendingPoolControlHistory_ =
                space == SourceSpace::Ram &&
                poolControlWriters_.authenticate(
                    const_cast<uint8_t*>(static_cast<const uint8_t*>(ramIdentity())), *ctx,
                    *runtimeIdentity(), at, data, n, pc);
            auto packetHeaderSource =
                authenticateOriginalIrqPacketHeaderWrite(space, at, data, n, *ctx, pc);
            auto heapControlSource =
                authenticateOriginalHeapControlWrite(space, at, data, n, *ctx, pc);
            if (ownsAnySource() && (space == SourceSpace::Ram || space == SourceSpace::Spr)) {
                std::lock_guard<std::recursive_mutex> protocolLock(service_.hostProtocolMutex());
                uint32_t word;
                std::memcpy(&word, static_cast<const uint8_t*>(ramIdentity()) + pc, 4u);
                const uint32_t op = word >> 26, rt = (word >> 16) & 31u;
                if (op == 0x39u || op == 0x3eu || op == 0x1fu)
                    throw std::invalid_argument("CPU numerical RAM/SPR transfer requires its exact "
                                                "typed store certificate");
                if (op == 0x28u || op == 0x29u || op == 0x2bu || op == 0x3fu) {
                    const uint32_t width = op == 0x3fu ? 8u : 4u;
                    if (!pendingPoolControlHistory_ && rt &&
                        !reo_source_closure::scalarControlLane(service_.compositionScalarRoles_,
                                                               rt * 16u, width))
                        throw std::invalid_argument(
                            "Integer RAM store cannot relabel an unproved/numeric GPR as RAW");
                }
            }
            const bool reviewed = pendingPoolControlHistory_ || bool(packetHeaderSource) ||
                                  bool(heapControlSource) || journal_.reviewed(space, at, n, pc);
            reserveControlHistory(space, at, n, pc, pendingPoolControlHistory_,
                                  bool(packetHeaderSource) || bool(heapControlSource));
            if (reviewed && space == SourceSpace::Context && ctx != contextIdentity())
                throw std::invalid_argument("Reviewed source write belongs to foreign context");
            if (!reviewed)
                beforeUnknownWrite(space, at, n, ctx, pc);
            else
                gateway_.prepareActualRawWriterCompletion();
            // Immutable event allocation completes before pending journal/owner
            // mutation. This source mutex lease spans prepare/store/completion.
            auto permit = std::shared_ptr<PreparedSourceWrite>(new PreparedSourceWrite(
                this, space, at, data, n, pc, epoch_, nextSourceWrite_, ctx,
                ps2_sched::currentThread(), reviewed, std::move(sourceLock)));
            if (packetHeaderSource)
                permit->validateActualIssuer_ = [this, packetHeaderSource, at, n, ctx, pc,
                                                 permitRaw = permit.get()] {
                    validateOriginalIrqPacketHeaderWrite(packetHeaderSource, at, permitRaw->data(),
                                                         n, *ctx, pc);
                };
            if (heapControlSource)
                permit->validateActualIssuer_ = [this, heapControlSource, at, n, ctx, pc,
                                                 permitRaw = permit.get()] {
                    validateOriginalHeapControlWrite(heapControlSource, at, permitRaw->data(), n,
                                                     *ctx, pc);
                };
            pendingSourceWrite_ = permit;
            try {
                if (reviewed) {
                    if (pendingPoolControlHistory_)
                        journal_.prepareValidatedPoolControl(at, permit->data(), n, pc);
                    else if (packetHeaderSource)
                        journal_.prepareAuthenticatedPacketHeader(at, permit->data(), n, pc);
                    else if (heapControlSource)
                        journal_.prepareAuthenticatedHeapControl(at, permit->data(), n, pc);
                    else
                        journal_.prepare(space, at, permit->data(), n, pc);
                    const auto patch = journal_.prepared();
                    if (ownsAnySource()) {
                        if (ps2IoRegLockDepth() != 0)
                            throw std::logic_error(
                                "Reviewed source mirror cannot wait under IO/parser ownership");
                        // An earlier actual T2 callback can take sourceMutex_.
                        // Pending exact-range guards hold authority while this
                        // mutex is released for FIFO recording, avoiding deadlock.
                        permit->sourceLease_.unlock();
                        auto self = shared_from_this();
                        runActualOwnerControl(epoch_, [self, patch, ctx,
                                                       space](ControlTarget& actual) {
                            if (&actual != self.get())
                                throw std::invalid_argument(
                                    "Source mirror reached foreign owner FIFO");
                            std::lock_guard<std::recursive_mutex> lock(
                                self->service_.hostProtocolMutex());
                            if (space == SourceSpace::Ram)
                                self->gateway_.beforeReviewedRawRamOverwrite(patch, true);
                            else if (space == SourceSpace::Context &&
                                     self->service_.hookProtocol().hasContextLeaseFor(*ctx))
                                self->gateway_.beforeReviewedRawContextOverwrite(*ctx, patch, true);
                            else
                                self->service_.recordReviewedSourceOverwrite(patch);
                        });
                        permit->sourceLease_.lock();
                        actualSourceScope(ctx, pc);
                    }
                }
                permit->mirrored_ = true;
                return permit;
            } catch (...) {
                failed_.store(true, std::memory_order_release);
                throw;
            }

        } catch (...) {
            failed_.store(true, std::memory_order_release);
            throwOwnedSourceFailure(runtimeIdentity());
        }
    }
    void authorizeSourceWrite(const SourceWritePermit& permit, SourceSpace space, uint32_t at,
                              const void* data, uint32_t n, R5900Context* ctx,
                              uint32_t pc) override {
        try {
            requireHealthy();
            auto& pending = exactSourceWrite(permit, space, at, n, ctx, pc, true);
            if (!pending.mirrored_ || pending.authorized_ || !data ||
                std::memcmp(data, pending.data(), n))
                throw std::invalid_argument("Source write differs from immutable mirrored event");
            pending.authorized_ = true;

        } catch (...) {
            failed_.store(true, std::memory_order_release);
            throwOwnedSourceFailure(runtimeIdentity());
        }
    }
    void finishSourceWrite(const SourceWritePermit& permit, SourceSpace space, uint32_t at,
                           R5900Context* ctx, uint32_t pc) override {
        try {
            requireHealthy();
            auto& pending =
                exactSourceWrite(permit, space, at, permit ? permit->bytes() : 0, ctx, pc, false);
            if (!pending.authorized_ || !pending.mirrored_)
                throw std::invalid_argument("Source completion lacks authorized exact event");
            // Inspect only the exact just-stored RAW bytes. No stale graphic
            // word or preserved upper GPR lane is read by completion.
            const auto* bank = space == SourceSpace::Context
                                   ? reinterpret_cast<const uint8_t*>(ctx)
                                   : static_cast<const uint8_t*>(
                                         space == SourceSpace::Ram ? ramIdentity() : sprIdentity());
            if (std::memcmp(bank + at, pending.data(), pending.bytes_))
                throw std::runtime_error("Actual source store failed to write permit bytes");
            if (pending.reviewed_) {
                journal_.completed(space, at, pending.bytes_, pc);
                gateway_.actualRawWriterCompleted();
            }
            if (pending.deferredControl_) {
                service_.completeTypedContextControlTransition(*ctx, at, pending.bytes_,
                                                               pending.deferredControlRole_,
                                                               pendingContextControlOpaque_);
                ++deferredContextControls_;
            }
            completeControlHistory(pending);
            if (pendingPoolControlHistory_)
                poolControlWriters_.completed(*ctx, *runtimeIdentity(), at, pc);
            pendingPoolControlHistory_ = false;
            pendingScalarHistory_ = false;
            if (space == SourceSpace::Ram)
                for (auto& word : protectedRevisions_)
                    if (protocol::overlap(at, pending.bytes_, word.address, 4))
                        word.completedWriter = pending.sequence_;

            if ((space == SourceSpace::Context &&
                 pending.sequence_ != pendingDelayMetadataSequence_ &&
                 (protocol::overlap(at, pending.bytes_, offsetof(R5900Context, pc), 4u) ||
                  protocol::overlap(at, pending.bytes_, offsetof(R5900Context, in_delay_slot),
                                    1u) ||
                  protocol::overlap(at, pending.bytes_, offsetof(R5900Context, branch_pc), 4u))) ||
                (space == SourceSpace::Ram && completedDelay_.enteredWriter &&
                 protocol::overlap(at, pending.bytes_, completedDelay_.branchPc, 8u)))
                clearCompletedDelay();
            pendingDelayMetadataSequence_ = 0;
            if (pending.completeActualIssuer_)
                pending.completeActualIssuer_();
            pending.completed_ = true;
            pendingSourceWrite_.reset();
            ++nextSourceWrite_;
        } catch (...) {
            failed_.store(true, std::memory_order_release);
            throwOwnedSourceFailure(runtimeIdentity());
        }
    }
    void abandonSourceWrite(const SourceWritePermit& permit) noexcept override {
        auto pending = pendingSourceWrite_.lock();
        if (pending && permit.get() == pending.get() && !pending->completed_)
            failed_.store(true, std::memory_order_release);
    }
    ProtectedScalarCaptureHandle
    captureProtectedScalars(R5900Context* ctx, const std::vector<uint32_t>& addresses) override {
        requireHealthy();
        actualSourceScope(ctx, ctx ? ctx->pc : 0);
        std::lock_guard<std::recursive_mutex> lock(sourceMutex_);
        if (ctx != contextIdentity() || addresses.empty() || addresses.size() > 32 ||
            nextScalarCapture_ == UINT64_MAX || !pendingSourceWrite_.expired())
            throw std::invalid_argument("Protected scalar frontier invalid/exhausted");
        std::vector<ProtectedScalarCapture::Word> words;
        words.reserve(addresses.size());
        for (uint32_t at : addresses) {
            if (poolControlWriters_.protects(at, 4u) && !poolControlWriters_.initialized_)
                throw std::invalid_argument("Pool scalar capture precedes its completed "
                                            "authenticated pointer initialization");
            const ProtectedRevision* revision = nullptr;
            for (const auto& word : protectedRevisions_)
                if (word.address == at)
                    revision = &word;
            const auto* history = controlHistory(at);
            if (!revision && (!history || !history->valid || !history->completedWriter))
                throw std::invalid_argument(
                    "Dynamic protected field lacks actual completed ScalarControl writer");
            for (const auto& word : words)
                if (word.address == at)
                    throw std::invalid_argument("Repeated protected scalar view");
            read(SourceSpace::Ram, at, 4, ctx, ctx->pc);
            uint32_t bits;
            std::memcpy(&bits, static_cast<const uint8_t*>(ramIdentity()) + at, 4);
            if (!revision && history->bits != bits)
                throw std::runtime_error(
                    "Dynamic scalar field changed outside completed writer history");
            words.push_back(
                {at, bits, revision ? revision->completedWriter : history->completedWriter});
        }
        auto capture = std::shared_ptr<const ProtectedScalarCapture>(new ProtectedScalarCapture(
            this, runtimeIdentity(), ctx, ps2_sched::currentThread(), epoch_, nextScalarCapture_,
            nextSourceWrite_ - 1, std::move(words)));
        protectedCaptures_.erase(std::remove_if(protectedCaptures_.begin(),
                                                protectedCaptures_.end(),
                                                [](const auto& weak) { return weak.expired(); }),
                                 protectedCaptures_.end());
        if (protectedCaptures_.size() >= 4096)
            throw std::overflow_error("Protected scalar capture lease registry exhausted");
        protectedCaptures_.push_back(capture);
        ++nextScalarCapture_;
        return capture;
    }
    void validateProtectedScalars(const ProtectedScalarCaptureHandle& capture,
                                  R5900Context* ctx) const override {
        requireHealthy();
        actualSourceScope(ctx, ctx ? ctx->pc : 0);
        std::lock_guard<std::recursive_mutex> lock(sourceMutex_);
        if (!capture || capture->issuer_ != this || capture->runtime_ != runtimeIdentity() ||
            capture->context_ != ctx || capture->epoch_ != epoch_ ||
            capture->task_ != ps2_sched::currentThread() ||
            capture->hostThread_ != std::this_thread::get_id())
            throw std::invalid_argument("Protected scalar capture is foreign/stale/not reacquired");
        bool active = false;
        for (const auto& weak : protectedCaptures_)
            if (weak.lock() == capture)
                active = true;
        if (!active)
            throw std::invalid_argument("Protected scalar range lease was released");
        for (const auto& word : capture->words_) {
            const ProtectedRevision* revision = nullptr;
            for (const auto& item : protectedRevisions_)
                if (item.address == word.address)
                    revision = &item;
            const auto* history = controlHistory(word.address);
            if (revision ? revision->completedWriter != word.completedWriter
                         : (!history || !history->valid ||
                            history->completedWriter != word.completedWriter ||
                            history->bits != word.value))
                throw std::runtime_error("Protected scalar actual writer frontier changed");
            uint32_t bits;
            std::memcpy(&bits, static_cast<const uint8_t*>(ramIdentity()) + word.address, 4);
            if (bits != word.value)
                throw std::runtime_error(
                    "Protected scalar changed outside source transaction closure");
        }
    }
    void releaseProtectedScalars(const ProtectedScalarCaptureHandle& capture,
                                 R5900Context* ctx) override {
        validateProtectedScalars(capture, ctx);
        std::lock_guard<std::recursive_mutex> lock(sourceMutex_);
        protectedCaptures_.erase(std::remove_if(protectedCaptures_.begin(),
                                                protectedCaptures_.end(),
                                                [&](const auto& weak) {
                                                    return weak.expired() || weak.lock() == capture;
                                                }),
                                 protectedCaptures_.end());
    }

  private:
  private:
    reo_gpu_upstream::QueueResolverBindingHandle
    captureQueueResolverOnEe(const reo_gpu_upstream::CallHandle& call, R5900Context& ctx) {
        requireHealthy();
        actualSourceScope(&ctx, ctx.pc);
        if (!call || call->task() != ps2_sched::currentThread() || call->stamp().epoch != epoch_ ||
            &ctx != contextIdentity() || ctx.pc != call->entry())
            throw std::invalid_argument("Queue resolver capture lacks original actual EE owner");
        std::lock_guard<std::recursive_mutex> sourceLock(sourceMutex_);
        std::lock_guard<std::recursive_mutex> protocolLock(service_.hostProtocolMutex());
        auto viewport = service_.exactOriginalViewport(call);
        if (viewport->output)
            throw std::invalid_argument("Queue resolver must bind before first viewport dispatch");
        PS2Runtime* runtime = runtimeIdentity();
        const std::array<PS2Runtime::RecompiledFunction, 3> functions{
            runtime->lookupFunction(0x18dca0u), runtime->lookupFunction(0x1a0d70u),
            runtime->lookupFunction(0x1a1330u)};
        reo_gpu_upstream::QueueResolverKind kind;
        auto native = reoActualPoolResolverPassthroughIdentity();
        if (native && functions[0] == native)
            kind = reo_gpu_upstream::QueueResolverKind::NativeRawPointerPassthrough;
        else if ((!functions[0] || functions[0] == sub_0018DCA0_0x18dca0) &&
                 (!functions[1] || functions[1] == sub_001A0D70_0x1a0d70) &&
                 (!functions[2] || functions[2] == sub_001A1330_0x1a1330))
            kind = reo_gpu_upstream::QueueResolverKind::OriginalLookup;
        else
            throw std::invalid_argument("Queue resolver registered implementation is outside "
                                        "reviewed original/native profiles");
        return std::shared_ptr<const reo_gpu_upstream::QueueResolverBinding>(
            new reo_gpu_upstream::QueueResolverBinding(&service_, call, runtime, &ctx, kind,
                                                       call->task(), functions));
    }
    void validateQueueResolverOnEe(const reo_gpu_upstream::QueueResolverBindingHandle& binding,
                                   R5900Context& ctx) const {
        requireHealthy();
        actualSourceScope(&ctx, ctx.pc);
        if (!binding || binding->issuer_ != &service_ || binding->runtime_ != runtimeIdentity() ||
            binding->actualEeContext_ != &ctx ||
            binding->actualTask_ != ps2_sched::currentThread() ||
            binding->call_->stamp().epoch != epoch_ || ctx.pc != binding->call_->entry())
            throw std::invalid_argument("Queue resolver binding is stale/foreign/unprotected");
        const std::array<uint32_t, 3> entries{0x18dca0u, 0x1a0d70u, 0x1a1330u};
        for (unsigned k = 0; k < 3; ++k)
            if (binding->runtime_->lookupFunction(entries[k]) != binding->actualFunctions_[k])
                throw std::runtime_error(
                    "Registered queue resolver changed during actual held call");
        if (binding->kind_ == reo_gpu_upstream::QueueResolverKind::NativeRawPointerPassthrough &&
            binding->actualFunctions_[0] != reoActualPoolResolverPassthroughIdentity())
            throw std::runtime_error("Native queue resolver exact code identity differs");
    }

  private:
  private:
    reo_gpu_upstream::ProtectedQueueCaptureHandle
    captureViewportQueueBeforeGpuOnEe(const reo_gpu_upstream::CallHandle& call,
                                      const reo_gpu_upstream::QueueResolverBindingHandle& resolver,
                                      R5900Context& ctx) {
        requireHealthy();
        actualSourceScope(&ctx, ctx.pc);
        validateQueueResolverOnEe(resolver, ctx);
        if (!call || resolver->call_ != call)
            throw std::invalid_argument(
                "Queue capture lacks its exact registered resolver profile");
        // Source tracker covers these approved scalar addresses from actual
        // NativeTarget creation. Capture remains an ordinary strict RAW read;
        // it cannot borrow old opaque words after a GPU source started.
        std::vector<uint32_t> addresses{0x29fdb4u};
        addresses.reserve(12);
        auto indexFrontier = captureProtectedScalars(&ctx, addresses);
        const uint32_t selected = indexFrontier->word(0x29fdb4u);
        if (selected > 1u) {
            releaseProtectedScalars(indexFrontier, &ctx);
            throw std::invalid_argument(
                "Queue source buffer index outside exact two-buffer domain");
        }
        const uint32_t selectedBase = 0x29f6f0u + selected * 4u;
        for (uint32_t at : {0x29f6f4u, selectedBase + 12u, selectedBase + 20u, selectedBase + 28u,
                            0x29f724u, 0x29f728u})
            addresses.push_back(at);
        auto frontier = captureProtectedScalars(&ctx, addresses);
        releaseProtectedScalars(indexFrontier, &ctx);
        std::vector<reo_gpu_upstream::ProtectedQueueCapture::CodeWord> lookup;
        uint32_t resolved = 0u;
        try {
            const uint32_t db = frontier->word(0x29fdb4u);
            if (db > 1u)
                throw std::invalid_argument(
                    "Original queue index exceeds actual two-buffer source domain");
            const uint32_t handle = frontier->word(0x29f6fcu + db * 4u);
            if (resolver->kind_ == reo_gpu_upstream::QueueResolverKind::OriginalLookup) {
                // Extend one retained frontier while source/guest ownership
                // stays held. No GPU/ordinary writer may overtake these leases.
                addresses.push_back(0x2afef0u);
                addresses.push_back(0x2afef8u);
                auto descriptor = captureProtectedScalars(&ctx, addresses);
                const uint32_t count = descriptor->word(0x2afef0u),
                               base = descriptor->word(0x2afef8u);
                if (!count || count > 4096u || !handle || handle > count || (base & 15u) ||
                    !protocol::range(base, count * 16u, protocol::RamBytes))
                    throw std::invalid_argument("Actual original pool control domain exceeds "
                                                "source-backed4096-entry bound");
                const uint32_t entry = base + (handle - 1u) * 16u;
                addresses.push_back(entry);
                auto complete = captureProtectedScalars(&ctx, addresses);
                resolved = complete->word(entry);
                if ((resolved & 3u) || !protocol::range(resolved, 4, protocol::RamBytes))
                    throw std::invalid_argument(
                        "Original pool returned invalid managed pointer ring");
                lookup = {{0x1a1330u, 0x2afef0u, count},
                          {0x1a1354u, 0x2afef8u, base},
                          {0x1a1360u, entry, resolved}};
                releaseProtectedScalars(descriptor, &ctx);
                releaseProtectedScalars(frontier, &ctx);
                frontier = std::move(complete);
            } else
                resolved = handle;
            for (uint32_t at : addresses)
                if (!frontier->completedWriter(at))
                    throw std::invalid_argument(
                        "Queue scalar was not initialized by an actual completed writer");
            std::vector<reo_gpu_upstream::ProtectedQueueCapture::CodeWord> table;
            table.reserve(6);
            for (uint32_t at = 0x241bf0u; at < 0x241c08u; at += 4) {
                read(SourceSpace::Ram, at, 4, &ctx, ctx.pc);
                uint32_t bits;
                std::memcpy(&bits, static_cast<const uint8_t*>(ramIdentity()) + at, 4);
                // Original JR dispatch is source-controlled. Unsupported
                // targets are not guessed or promoted from pointer values.
                // State::run refuses an actually selected unsupported target before journal recording.
                table.push_back({0x18d09cu, at, bits});
            }
            std::vector<reo_gpu_upstream::ProtectedQueueCapture::CodeWord> writeCode;
            const std::array<std::pair<uint32_t, uint32_t>, 12> sites{{{0x18d01cu, 0xae230000u},
                                                                       {0x18d02cu, 0xaca4001cu},
                                                                       {0x18d034u, 0xac540000u},
                                                                       {0x18d048u, 0xacc00000u},
                                                                       {0x18d04cu, 0xae540034u},
                                                                       {0x18d058u, 0xae530038u},
                                                                       {0x18d118u, 0xae400034u},
                                                                       {0x18d120u, 0xae400038u},
                                                                       {0x18d124u, 0xae540034u},
                                                                       {0x18d128u, 0xae530038u},
                                                                       {0x18d134u, 0xae400034u},
                                                                       {0x18d13cu, 0xae400038u}}};
            for (const auto& site : sites) {
                read(SourceSpace::Ram, site.first, 4, &ctx, ctx.pc);
                uint32_t word;
                std::memcpy(&word, static_cast<const uint8_t*>(ramIdentity()) + site.first, 4);
                if (word != site.second)
                    throw std::invalid_argument(
                        "Queue retained write opcode differs from original source");
                writeCode.push_back({site.first, site.first, word});
            }
            return std::shared_ptr<const reo_gpu_upstream::ProtectedQueueCapture>(
                new reo_gpu_upstream::ProtectedQueueCapture(&service_, call, resolver, frontier,
                                                            std::move(table), std::move(writeCode),
                                                            std::move(lookup), resolved));
        } catch (...) {
            releaseProtectedScalars(frontier, &ctx);
            throw;
        }
    }
    void
    validateViewportQueueCaptureOnEe(const reo_gpu_upstream::ProtectedQueueCaptureHandle& capture,
                                     R5900Context& ctx) const {
        if (!capture || capture->issuer_ != &service_ || !capture->call_ ||
            capture->resolver_->call_ != capture->call_)
            throw std::invalid_argument("Queue capture is foreign/unissued");
        validateQueueResolverOnEe(capture->resolver_, ctx);
        validateProtectedScalars(capture->frontier_, &ctx);
    }

  private:
    struct CertifiedAllocatorEvent {
        CertifiedControlCommitHandle commit;
        uint64_t actualCompletedWriter;
        ProtectedScalarCaptureHandle successor;
    };
    std::vector<CertifiedAllocatorEvent> certifiedAllocatorEvents_;

  public:
    void commitCertifiedControlOnEe(const CertifiedControlCommitHandle& commit,
                                    R5900Context* ctx) override {
        try {
            if (!ctx || ctx != contextIdentity() || currentRuntime() != runtimeIdentity() ||
                currentContext() != ctx || ps2ActualGuestExecutionDepth(runtimeIdentity()) == 0u)
                throw std::invalid_argument(
                    "Certified allocator store lacks actual protected EE execution");
            std::lock_guard<std::recursive_mutex> sourceLock(sourceMutex_);
            std::lock_guard<std::recursive_mutex> protocolLock(service_.hostProtocolMutex());
            requireHealthy();
            auto entry = service_.validateAllocatorCommitOnEe(commit, *ctx);
            auto viewport = service_.exactOriginalViewport(entry->capture->call_);
            if (!heldT1_.load(std::memory_order_acquire) || !ownsAnySource() ||
                !pendingSourceWrite_.expired() || nextSourceWrite_ == UINT64_MAX ||
                nextScalarCapture_ == UINT64_MAX || certifiedAllocatorEvents_.size() >= 4096 ||
                viewport->heapFrontier != commit->capture_ ||
                (entry->capture->stateStage_ ? viewport->stateOutput != entry->capture->stateStage_
                                             : viewport->output != entry->capture->originalStage_))
                throw std::invalid_argument(
                    "Certified allocator event lacks genuine held source frontier");
            // This retained, exact-module GPU event can use the outer EE PC.
            // An ordinary prepared writer never inherits this exception.
            validateProtectedScalars(commit->capture_, ctx);
            ProtectedRevision* revision = nullptr;
            for (auto& word : protectedRevisions_)
                if (word.address == commit->address_)
                    revision = &word;
            if (!revision ||
                revision->completedWriter != commit->capture_->completedWriter(commit->address_))
                throw std::invalid_argument("Certified allocator protected writer changed");
            for (const auto& weak : protectedCaptures_)
                if (auto other = weak.lock())
                    if (other != commit->capture_)
                        for (const auto& word : other->words_)
                            if (protocol::overlap(commit->address_, 4, word.address, 4))
                                throw std::runtime_error("Certified allocator cannot invalidate "
                                                         "another active scalar lease");
            uint32_t before;
            std::memcpy(&before, static_cast<const uint8_t*>(ramIdentity()) + commit->address_, 4);
            if (before != commit->before_ || commit->capture_->word(0x29fdc0u) != before)
                throw std::runtime_error(
                    "Certified allocator heap value changed before scalar commit");
            auto writerCompletion = gateway_.prepareCertifiedControlWriterCompletion();
            // Reserve every allocation before the real store. The successor
            // originates in this genuine performed GPU-control/CPU-store
            // event, not a caller revision or an opaque host memory read.
            auto words = commit->capture_->words_;
            bool replaced = false;
            for (auto& word : words)
                if (word.address == commit->address_) {
                    word.value = commit->after_;
                    word.completedWriter = nextSourceWrite_;
                    replaced = true;
                }
            if (!replaced)
                throw std::logic_error("Certified allocator frontier omitted its heap word");
            auto successor =
                std::shared_ptr<const ProtectedScalarCapture>(new ProtectedScalarCapture(
                    this, runtimeIdentity(), ctx, ps2_sched::currentThread(), epoch_,
                    nextScalarCapture_, nextSourceWrite_, std::move(words)));
            protectedCaptures_.reserve(protectedCaptures_.size() + 1);
            certifiedAllocatorEvents_.reserve(certifiedAllocatorEvents_.size() + 1);
            if (controlHistory_.size() >= 65536u)
                throw std::overflow_error(
                    "Certified allocator integer writer history exhausted before CPU commit");
            controlHistory_.reserve(controlHistory_.size() + 1u);
            // Source mutex, real guest execution and Service protocol lock
            // remain held across this one trusted scalar store and completion.
            // Success publication below is non-allocating. A broken private
            // reservation is terminal owned failure, never a resumed guest.
            std::memcpy(const_cast<uint8_t*>(static_cast<const uint8_t*>(ramIdentity())) +
                            commit->address_,
                        &commit->after_, 4);
            if (!gateway_.consumeCertifiedControlWriterCompletion(writerCompletion)) {
                failed_.store(true, std::memory_order_release);
                service_.observeOwnerSticky(176u);
                throw std::runtime_error(
                    "Certified control writer lost its private reserved revision after store");
            }
            revision->completedWriter = nextSourceWrite_;
            const ControlHistoryWord completed{commit->address_,
                                               commit->after_,
                                               commit->sourcePc_,
                                               commit->sourceWord_,
                                               nextSourceWrite_,
                                               true,
                                               15u};
            ControlHistoryWord* previous = nullptr;
            for (auto& word : controlHistory_)
                if (word.address == commit->address_)
                    previous = &word;
            if (previous)
                *previous = completed;
            else
                controlHistory_.push_back(completed);
            const uint64_t sequence = nextSourceWrite_++;
            ++nextScalarCapture_;
            protectedCaptures_.erase(
                std::remove_if(protectedCaptures_.begin(), protectedCaptures_.end(),
                               [&](const auto& weak) {
                                   return weak.expired() || weak.lock() == commit->capture_;
                               }),
                protectedCaptures_.end());
            protectedCaptures_.push_back(successor);
            certifiedAllocatorEvents_.push_back({commit, sequence, successor});
            entry->successorFrontier = successor;
            viewport->heapFrontier = successor;
            entry->cpuCommitted = true;
        } catch (...) {
            failed_.store(true, std::memory_order_release);
            throw;
        }
    }

  private:
    struct CertifiedQueueEvent {
        CertifiedQueueCommitHandle commit;
        ProtectedScalarCaptureHandle successor;
    };
    std::vector<CertifiedQueueEvent> certifiedQueueEvents_;
    void commitCertifiedQueueOnEe(const CertifiedQueueCommitHandle& commit, R5900Context& ctx) {
        try {
            actualSourceScope(&ctx, ctx.pc);
            std::lock_guard<std::recursive_mutex> sourceLock(sourceMutex_);
            std::lock_guard<std::recursive_mutex> protocolLock(service_.hostProtocolMutex());
            requireHealthy();
            auto entry = service_.validateViewportQueueCommitOnEe(commit, ctx);
            validateQueueResolverOnEe(entry->capture->resolver_, ctx);
            validateProtectedScalars(commit->frontier_, &ctx);
            if (!heldT1_.load(std::memory_order_acquire) || !ownsAnySource() ||
                !pendingSourceWrite_.expired() || commit->stores_.empty() ||
                commit->stores_.size() > 16 ||
                nextSourceWrite_ > UINT64_MAX - commit->stores_.size() ||
                nextScalarCapture_ == UINT64_MAX || certifiedQueueEvents_.size() >= 4096)
                throw std::invalid_argument(
                    "Queue scalar batch lacks genuine held source sequence capacity");
            auto words = commit->frontier_->words_;
            std::map<uint32_t, uint32_t> staged;
            uint64_t sequence = nextSourceWrite_;
            // All preflight/allocation happens before the first real CPU store.
            // The ring operation is a source-proven blind overwrite; its old
            // numerical/opaque byte value is never read as CPU authority.
            for (const auto& store : commit->stores_) {
                if (!protocol::range(store.address, 4, protocol::RamBytes) || (store.address & 3u))
                    throw std::invalid_argument(
                        "Queue scalar destination outside exact admitted RAM");
                bool source = false;
                for (const auto& code : entry->capture->writeCode_)
                    if (code.sourcePc == store.sourcePc && code.bits == store.sourceWord)
                        source = true;
                if (!source)
                    throw std::invalid_argument(
                        "Queue batch lost its retained original instruction");
                for (const auto& weak : protectedCaptures_)
                    if (auto other = weak.lock())
                        if (other != commit->frontier_)
                            for (const auto& word : other->words_)
                                if (protocol::overlap(store.address, 4, word.address, 4))
                                    throw std::runtime_error("Queue batch would invalidate another "
                                                             "active protected lease");
                if (store.blind) {
                    const auto& ring = entry->snapshot->ring_;
                    if (store.sourcePc != 0x18d034u || store.sourceWord != 0xac540000u || !ring ||
                        ring->address != store.address ||
                        entry->capture->resolvedRing_ != ring->base)
                        throw std::invalid_argument(
                            "Queue blind overwrite lacks managed native destination lease");
                } else {
                    bool found = false;
                    for (auto& word : words)
                        if (word.address == store.address) {
                            found = true;
                            ProtectedRevision* revision = nullptr;
                            for (auto& item : protectedRevisions_)
                                if (item.address == store.address)
                                    revision = &item;
                            if (!revision || revision->completedWriter !=
                                                 commit->frontier_->completedWriter(store.address))
                                throw std::invalid_argument(
                                    "Queue real protected writer frontier changed");
                            uint32_t before;
                            if (auto it = staged.find(store.address); it != staged.end())
                                before = it->second;
                            else
                                std::memcpy(
                                    &before,
                                    static_cast<const uint8_t*>(ramIdentity()) + store.address, 4);
                            if (before != store.before || word.value != store.before)
                                throw std::runtime_error("Queue protected counter changed before "
                                                         "its exact ordered store");
                            word.value = store.after;
                            word.completedWriter = sequence;
                        }
                    if (!found)
                        throw std::invalid_argument(
                            "Queue fixed control store is not in retained scalar frontier");
                }
                staged[store.address] = store.after;
                ++sequence;
            }
            auto writerCompletion = gateway_.prepareCertifiedControlWriterCompletion();
            auto successor =
                std::shared_ptr<const ProtectedScalarCapture>(new ProtectedScalarCapture(
                    this, runtimeIdentity(), &ctx, ps2_sched::currentThread(), epoch_,
                    nextScalarCapture_, sequence - 1, std::move(words)));
            protectedCaptures_.reserve(protectedCaptures_.size() + 1);
            certifiedQueueEvents_.reserve(certifiedQueueEvents_.size() + 1);
            if (commit->stores_.size() > 65536u ||
                controlHistory_.size() > 65536u - commit->stores_.size())
                throw std::overflow_error(
                    "Certified queue integer writer history exhausted before CPU commit");
            controlHistory_.reserve(controlHistory_.size() + commit->stores_.size());
            sequence = nextSourceWrite_;
            // This is the original ordered integer store sequence under true
            // guest/source/protocol ownership. The worker did no live EE write.
            for (const auto& store : commit->stores_) {
                std::memcpy(const_cast<uint8_t*>(static_cast<const uint8_t*>(ramIdentity())) +
                                store.address,
                            &store.after, 4);
                const ControlHistoryWord event{
                    store.address, store.after, store.sourcePc, store.sourceWord, sequence,
                    true,          15u};
                ControlHistoryWord* prior = nullptr;
                for (auto& history : controlHistory_)
                    if (history.address == store.address)
                        prior = &history;
                if (prior)
                    *prior = event;
                else
                    controlHistory_.push_back(event);
                for (auto& word : protectedRevisions_)
                    if (word.address == store.address)
                        word.completedWriter = sequence;
                ++sequence;
            }
            if (!gateway_.consumeCertifiedControlWriterCompletion(writerCompletion)) {
                failed_.store(true, std::memory_order_release);
                service_.observeOwnerSticky(185u);
                throw std::runtime_error(
                    "Queue control batch lost its private reserved Gateway revision");
            }
            nextSourceWrite_ = sequence;
            ++nextScalarCapture_;
            protectedCaptures_.erase(
                std::remove_if(protectedCaptures_.begin(), protectedCaptures_.end(),
                               [&](const auto& weak) {
                                   return weak.expired() || weak.lock() == commit->frontier_;
                               }),
                protectedCaptures_.end());
            protectedCaptures_.push_back(successor);
            certifiedQueueEvents_.push_back({commit, successor});
            entry->successorFrontier = successor;
            entry->cpuCommitted = true;
        } catch (...) {
            failed_.store(true, std::memory_order_release);
            throw;
        }
    }

  public:
    Origins emptyOrigins() const override {
        std::lock_guard<std::recursive_mutex> lock(sourceMutex_);
        return wrap(const_cast<NativeTarget*>(this)->gateway_.origins().emptyTape());
    }
    Origins sliceOrigins(const Origins& x, uint32_t at, uint32_t n) const override {
        std::lock_guard<std::recursive_mutex> lock(sourceMutex_);
        return wrap(
            const_cast<NativeTarget*>(this)->gateway_.origins().slice(exact(x).value, at, n));
    }
    Origins concatOrigins(const Origins& a, const Origins& b) const override {
        std::lock_guard<std::recursive_mutex> lock(sourceMutex_);
        return wrap(const_cast<NativeTarget*>(this)->gateway_.origins().concatenate(
            exact(a).value, exact(b).value));
    }
    void appendParser(std::vector<uint8_t>& b, Origins& x, uint32_t address, uint32_t n,
                      bool spr) override {
        std::lock_guard<std::recursive_mutex> lock(sourceMutex_);
        auto tape = exact(x).value;
        gateway_.origins().appendParserBytes(
            b, tape, address, n, spr, [&](bool scratch, uint32_t at, uint8_t* out, uint32_t bytes) {
                read(scratch ? SourceSpace::Spr : SourceSpace::Ram, at, bytes, currentContext(),
                     currentContext() ? currentContext()->pc : 0);
                const auto* bank =
                    static_cast<const uint8_t*>(scratch ? sprIdentity() : ramIdentity());
                std::memcpy(out, bank + at, bytes);
            });
        x = wrap(std::move(tape));
    }
    void bindParser(const uint8_t* p, uint32_t n, const Origins& x) override {
        std::lock_guard<std::recursive_mutex> lock(sourceMutex_);
        gateway_.origins().bindActualCopiedStream(ramIdentity(), p, n, exact(x).value);
    }
    Origins beginParser(const uint8_t* p, uint32_t n) override {
        std::lock_guard<std::recursive_mutex> lock(sourceMutex_);
        return wrap(gateway_.origins().consumeActualCopiedStream(ramIdentity(), p, n));
    }
    void requireRaw(const Origins& x, uint32_t at, uint32_t n) const override {
        std::lock_guard<std::recursive_mutex> lock(sourceMutex_);
        const_cast<NativeTarget*>(this)->gateway_.origins().requireRaw(exact(x).value, at, n);
    }
    bool hasOpaque(const Origins& x, uint32_t at, uint32_t n) const override {
        std::lock_guard<std::recursive_mutex> lock(sourceMutex_);
        return const_cast<NativeTarget*>(this)->gateway_.origins().hasOpaque(exact(x).value, at, n);
    }
    reo_resident_live::Operation opaqueUnpack(const Origins& x, uint32_t at, uint32_t n,
                                              uint32_t command, uint32_t tops, uint32_t cycle,
                                              uint32_t mode) override {
        // This operation mints host metadata only. It records no GPU command
        // and performs no fence wait while the original parser owns IO.
        // Actual upload recording remains in ParallelArrayOwner.appendUploads.
        std::lock_guard<std::recursive_mutex> sourceLock(sourceMutex_);
        std::lock_guard<std::recursive_mutex> lock(service_.hostProtocolMutex());
        return gateway_.joinOriginalOpaqueUnpack(exact(x).value, at, n, command, tops, cycle, mode);
    }
};
} // namespace reo_parent_natural
