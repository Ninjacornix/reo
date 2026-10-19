// Included privately inside the actual parent Service. No numerical inputs or
// Context images enter this API; calls retain the existing, fenced GPU banks.
class RetainedInvocation final {
    friend class Service;
    friend class RetainedInvocationScope;
    const Service* issuer_;
    PS2Runtime* runtime_;
    R5900Context* context_;
    std::shared_ptr<const void> storage_;
    reo_parent_natural::FirstEntryInvocationHandle invocation_;
    reo_gpu_upstream::BanksHandle banks_;
    Vulkan::Fence initialFence_;
    PS2Runtime::RecompiledFunction body_;
    uint64_t epoch_, generation_, contextRevision_;
    uint32_t entry_;
    int32_t task_;
    std::thread::id thread_;
    std::atomic<bool> active_{true};
    reo_gpu_upstream::CallHandle call_;
    uint64_t finalTimeline_ = 0;
    uint32_t finalPc_ = 0; // Set only by the actual Service after its certified final fence.
    bool committed_ = false;
    RetainedInvocation(const Service* service, PS2Runtime& runtime, R5900Context& context,
                       std::shared_ptr<const void> storage,
                       reo_parent_natural::FirstEntryInvocationHandle invocation,
                       reo_gpu_upstream::BanksHandle banks, Vulkan::Fence fence,
                       PS2Runtime::RecompiledFunction body, uint64_t epoch, uint64_t generation,
                       uint64_t revision, uint32_t entry)
        : issuer_(service), runtime_(&runtime), context_(&context), storage_(std::move(storage)),
          invocation_(std::move(invocation)), banks_(std::move(banks)),
          initialFence_(std::move(fence)), body_(body), epoch_(epoch), generation_(generation),
          contextRevision_(revision), entry_(entry), task_(ps2_sched::currentThread()),
          thread_(std::this_thread::get_id()) {}

  public:
    RetainedInvocation(const RetainedInvocation&) = delete;
};
using RetainedInvocationHandle = std::shared_ptr<RetainedInvocation>;
class RetainedInvocationScope final {
    friend class Service;
    RetainedInvocationHandle ticket_;
    explicit RetainedInvocationScope(RetainedInvocationHandle ticket)
        : ticket_(std::move(ticket)) {}

  public:
    RetainedInvocationScope(const RetainedInvocationScope&) = delete;
    ~RetainedInvocationScope() {
        // The EE stack owns liveness. Queued GS closures can retain a ticket,
        // but cannot keep an unwound invocation active or manufacture success.
        if (ticket_ && ticket_->active_.exchange(false, std::memory_order_acq_rel))
            try {
                ticket_->runtime_->requestStop();
            } catch (...) {
            }
    }
    RetainedInvocationHandle ticket() const noexcept {
        return ticket_;
    }
};
std::weak_ptr<RetainedInvocation> activeRetainedInvocation_;
// Set only after the initial real upload fence, then advanced only by the
// existing authenticated GS-only carry after its actual source/FIFO fence.
reo_gpu_upstream::BanksHandle retainedSourceBanks_;
Vulkan::Fence retainedSourceFence_;
uint64_t retainedSourceEpoch_ = 0, retainedSourceGeneration_ = 0;

bool hasRetainedInvocationAdmission() const noexcept {
    return configuration_.boundedRetainedInvocations && !configuration_.retainedEntryBodies.empty();
}
static bool retainedSourceEntry(uint32_t entry) noexcept {
    switch (entry) {
        case 0x196010u:
        case 0x197900u:
        case 0x191280u:
        case 0x18f710u:
        case 0x1921b0u:
        case 0x18f570u:
        case 0x18fdf0u:
        case 0x18f970u:
        case 0x18fce0u:
        case 0x18f880u:
        case 0x18f7e0u:
        case 0x197490u:
        case 0x18f6a0u:
            return true;
        default:
            return false;
    }
}
void requireRetainedSourceBankIdentity() const {
    requireHealthy();
    const auto& cold = configuration_.cold;
    if (!hasRetainedInvocationAdmission() ||
        configuration_.tier != protocol::AdmissionTier::OfflineComponent ||
        configuration_.gates.ready() || configuration_.producerProofs.complete() || !cold ||
        !cold->capturedEntry || !firstEntryUploadFence_ ||
        firstEntryUploaded_ != cold->capturedEntry || !retainedSourceFence_ ||
        retainedSourceEpoch_ != epoch_ || retainedSourceGeneration_ != generation_ || !producer_ ||
        !producer_->upstreamBanks_ || producer_->upstreamBanks_->device() != &device_ ||
        retainedSourceBanks_ != producer_->upstreamBanks_ ||
        producer_->upstreamBanks_->issuer() != producer_.get() ||
        producer_->upstreamBanks_->stamp().session != configuration_.session ||
        producer_->upstreamBanks_->stamp().epoch != epoch_ ||
        producer_->upstreamBanks_->stamp().bankGeneration != generation_ ||
        producer_->guestContextIdentity_ != activeSourceContextIdentity() || !callbacks_.empty() ||
        !irqPauses_.empty())
        throw std::invalid_argument("Retained entry requires its original fenced GPU banks and "
                                    "unchanged source context/epoch");
    // The initial invocation may have ended. Its immutable image is NEVER
    // uploaded again. Only the live allocation identity remains relevant.
    auto& runtime = firstEntryUploaded_->runtime();
    if (runtime.isStopRequested() || runtime.memory().getRDRAM() != cold->ram ||
        runtime.memory().getScratchpad() != cold->spr ||
        !reo_parent_natural::matchesActualGuestContextStorage(
            runtime, *activeSourceContextIdentity(), activeSourceContextLifetime()))
        throw std::invalid_argument("Retained entry source allocation ended or changed");
}
std::unique_ptr<RetainedInvocationScope>
beginRetainedInvocationOnEe(PS2Runtime& runtime, uint8_t* ram, R5900Context& context,
                            uint32_t entry, PS2Runtime::RecompiledFunction body) {
    std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
    requireRetainedSourceBankIdentity();
    if (!activeRetainedInvocation_.expired() || &runtime != &firstEntryUploaded_->runtime() ||
        ram != configuration_.cold->ram || &context != activeSourceContextIdentity() ||
        context.pc != entry || reo_parent_natural::currentRuntime() != &runtime ||
        reo_parent_natural::currentContext() != &context ||
        !ps2ActualGuestExecutionDepth(&runtime) || ps2_sched::currentThread() < 1 ||
        ps2IoRegLockDepth() != 0u || reo_source_instrumentation::actualInstructionOrigin.pc ||
        reo_source_instrumentation::actualInstructionOrigin.word || !body ||
        !runtime.hasFunction(entry) || runtime.lookupFunction(entry) != body)
        throw std::invalid_argument(
            "Retained entry lacks its genuine pre-instruction Runtime/task/body scope");
    unsigned matches = 0;
    for (const auto& original : configuration_.retainedEntryBodies)
        if (original.entry == entry && original.body == body)
            ++matches;
    if (matches != 1u || !retainedSourceEntry(entry))
        throw std::invalid_argument(
            "Retained entry is outside the finite registered body catalogue");
    const uint32_t raBytes = entry == 0x18f6a0u ? 8u : 4u;
    guardKnownContextRead(context, 31u * 16u, raBytes);
    bridge_.beforeContextAccess(context, 31u * 16u, raBytes, entry);
    if (entry == 0x196010u) {
        guardKnownContextRead(context, 4u * 16u, 1u);
        bridge_.beforeContextAccess(context, 4u * 16u, 1u, entry);
    }
    if (entry == 0x196010u) {
        if (!admitsOriginalSetterOnEe(context))
            throw std::invalid_argument(
                "Retained setter command has no exact admitted GPU source module");
    } else if (entry == 0x197900u) {
        if (!hasOriginalStatePacket197900())
            throw std::invalid_argument("Retained state source module is absent");
    } else {
        uint32_t mask = reo_gpu_upstream::ReturnPC;
        if (entry == 0x18f6a0u) {
            if (!hasOriginalComposition())
                throw std::invalid_argument("Retained composition module is absent");
            guardKnownContextRead(context, 29u * 16u, 8u);
            bridge_.beforeContextAccess(context, 29u * 16u, 8u, entry);
            mask = 3u;
        } else if (entry == 0x191280u) {
            if (!producer_->matrix191280_)
                throw std::invalid_argument("Retained matrix module is absent");
            mask = 15u;
        } else if (reo_gpu_upstream::Viewport::supports(entry)) {
            if (!hasOriginalViewport())
                throw std::invalid_argument("Retained viewport module is absent");
            mask = reo_gpu_upstream::Viewport::argumentMask(entry);
        } else {
            if (!hasOriginalPerspective())
                throw std::invalid_argument("Retained perspective module is absent");
            mask = reo_gpu_upstream::perspectiveIntegerControls(entry);
        }
        for (uint32_t slot = 4u; slot <= 6u; ++slot)
            if (mask & (1u << (slot - 3u))) {
                guardKnownContextRead(context, slot * 16u, 4u);
                bridge_.beforeContextAccess(context, slot * 16u, 4u, entry);
            }
    }
    auto invocation =
        reo_source_instrumentation::EntryScope::retainFirstEntryInvocation(runtime, context);
    auto ticket = RetainedInvocationHandle(new RetainedInvocation(
        this, runtime, context, activeSourceContextLifetime(), std::move(invocation),
        producer_->upstreamBanks_, retainedSourceFence_, body, epoch_, generation_,
        activeContextRevision_, entry));
    auto scope = std::unique_ptr<RetainedInvocationScope>(new RetainedInvocationScope(ticket));
    activeRetainedInvocation_ = ticket;
    return scope;
}
void requireRetainedInvocationIdentity(const RetainedInvocationHandle& ticket) const {
    requireRetainedSourceBankIdentity();
    if (!ticket || ticket->issuer_ != this || activeRetainedInvocation_.lock() != ticket ||
        !ticket->active_.load(std::memory_order_acquire) || ticket->runtime_->isStopRequested() ||
        ticket->epoch_ != epoch_ || ticket->generation_ != generation_ ||
        ticket->contextRevision_ != activeContextRevision_ ||
        ticket->context_ != activeSourceContextIdentity() ||
        ticket->storage_ != activeSourceContextLifetime() ||
        ticket->banks_ != producer_->upstreamBanks_ ||
        ticket->initialFence_ != retainedSourceFence_ ||
        !ticket->runtime_->hasFunction(ticket->entry_) ||
        ticket->runtime_->lookupFunction(ticket->entry_) != ticket->body_ ||
        !reo_parent_natural::matchesActualGuestContextStorage(*ticket->runtime_, *ticket->context_,
                                                              ticket->storage_))
        throw std::invalid_argument("Retained entry ticket is foreign, stale, unwound or belongs "
                                    "to different GPU/source banks");
}
void requireRetainedInvocationOnEe(const RetainedInvocationHandle& ticket) const {
    requireRetainedInvocationIdentity(ticket);
    if (reo_parent_natural::currentRuntime() != ticket->runtime_ ||
        reo_parent_natural::currentContext() != ticket->context_ ||
        !ps2ActualGuestExecutionDepth(ticket->runtime_) ||
        ps2_sched::currentThread() != ticket->task_ ||
        std::this_thread::get_id() != ticket->thread_ || ps2IoRegLockDepth() != 0u ||
        reo_source_instrumentation::EntryScope::retainFirstEntryInvocation(
            *ticket->runtime_, *ticket->context_) != ticket->invocation_)
        throw std::invalid_argument(
            "Retained entry did not reacquire the exact original EE EntryScope/task");
}
void bindRetainedInvocationOnEe(const RetainedInvocationHandle& ticket,
                                const reo_gpu_upstream::CallHandle& call) {
    std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
    requireRetainedInvocationOnEe(ticket);
    if (!call || ticket->call_ || call->issuer() != this || call->entry() != ticket->entry_ ||
        call->task() != ticket->task_ || call->stamp().session != configuration_.session ||
        call->stamp().epoch != epoch_ || call->stamp().bankGeneration != generation_ ||
        call->stamp().ordinal != upstreamOrdinal_)
        throw std::invalid_argument("Retained entry cannot bind a foreign/repeated original Call");
    const auto bind = [&](const auto& entry) {
        if (entry->retainedInvocationBound)
            throw std::logic_error("Source Call already has an invocation");
        entry->retainedInvocation = ticket;
        entry->retainedInvocationBound = true;
    };
    if (call->entry() == 0x196010u)
        bind(exactOriginalSetter(call));
    else if (call->entry() == 0x197900u || reo_gpu_upstream::Viewport::supports(call->entry()))
        bind(exactOriginalViewport(call));
    else if (call->entry() == 0x18f6a0u)
        bind(exactOriginalComposition(call));
    else if (call->entry() == 0x191280u)
        bind(exactOriginal191280(call));
    else
        bind(exactOriginalPerspective(call));
    ticket->call_ = call;
    // This byte is the original dispatcher's consumed integer command, read
    // only after both opaque-bank guards. Upper argument lanes gain no role.
    if (call->entry() == 0x196010u)
        compositionScalarRoles_[4u * 16u] = 7u;
}
void requireRetainedInvocationOnOwner(const RetainedInvocationHandle& ticket,
                                      const reo_gpu_upstream::CallHandle& call) const {
    std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
    requireRetainedInvocationIdentity(ticket);
    if (!call || ticket->call_ != call || call->issuer() != this ||
        call->entry() != ticket->entry_ || call->task() != ticket->task_ ||
        call->stamp().session != configuration_.session || call->stamp().epoch != epoch_ ||
        call->stamp().bankGeneration != generation_)
        throw std::invalid_argument(
            "Retained invocation does not authorize this exact ordered Call");
}
template <class Entry>
RetainedInvocationHandle requireBoundRetainedInvocation(const std::shared_ptr<Entry>& entry) const {
    auto ticket = entry->retainedInvocation.lock();
    if (entry->retainedInvocationBound) {
        if (!ticket)
            throw std::invalid_argument("Retained call outlived its authentic invocation ticket");
        requireRetainedInvocationOnOwner(ticket, entry->call);
    } else if (ticket)
        throw std::logic_error("Retained call has an unbound invocation");
    return ticket;
}
void validateRetainedCommitOnEe(const RetainedInvocationHandle& ticket,
                                const reo_gpu_upstream::CallHandle& call, uint64_t timeline) const {
    if (!ticket)
        return; // Only genuinely unbound legacy component Calls use this branch.
    requireRetainedInvocationOnEe(ticket);
    requireRetainedInvocationOnOwner(ticket, call);
    if (ticket->committed_ || !timeline || timeline > completed_)
        throw std::invalid_argument(
            "Retained scalar commit precedes a true completed final source fence");
}
void publishRetainedCommit(const RetainedInvocationHandle& ticket, uint64_t timeline) noexcept {
    if (ticket) {
        ticket->finalTimeline_ = timeline;
        ticket->finalPc_ = ticket->call_->returnPc();
        ticket->committed_ = true;
    }
}
void finishRetainedInvocationOnEe(const RetainedInvocationHandle& ticket,
                                  const reo_gpu_upstream::CallHandle& call) {
    std::lock_guard<std::recursive_mutex> lock(hostProtocolMutex_);
    requireRetainedInvocationOnEe(ticket);
    if (ticket->call_ != call || !ticket->committed_ || !ticket->finalTimeline_ ||
        ticket->finalTimeline_ > completed_ || ticket->context_->pc != ticket->finalPc_)
        throw std::invalid_argument(
            "Retained invocation did not complete its actual fenced EE scalar return");
    ticket->active_.store(false, std::memory_order_release);
    activeRetainedInvocation_.reset();
}
