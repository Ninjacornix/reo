private:
std::weak_ptr<const IrqCpuLease> actualCpuIrqLease_;
ProtectedScalarCaptureHandle cpuIrqFrontier_;
std::bitset<1024> cpuIrqStackAuthored_;
void exactCpuIrqLease(const IrqCpuLeaseHandle& lease) {
    requireHealthy();
    if (!lease || lease->issuer() != this || actualCpuIrqLease_.lock() != lease ||
        lease->epoch() != epoch_)
        throw std::invalid_argument("Foreign original CPU IRQ lease");
    lease->validateOnEe();
    auto& ctx = lease->initializer()->context();
    actualSourceScope(&ctx, ctx.pc);
    std::lock_guard<std::recursive_mutex> lock(service_.hostProtocolMutex());
    if (service_.callbacks_.empty() ||
        service_.callbacks_.back()->freshInitializer != lease->initializer() ||
        !service_.callbacks_.back()->waited || service_.callbacks_.back()->closed ||
        &ctx != contextIdentity())
        throw std::invalid_argument("Original CPU IRQ no longer owns genuine fresh Context/loan");
    service_.exactFreshIrqFrame(service_.callbacks_.back());
}
bool cpuIrqStack(const IrqCpuLeaseHandle& lease, uint32_t at, uint32_t bytes) const noexcept {
    const uint32_t top = lease->initializer()->stackTop();
    return top >= 1024u && at >= top - 1024u && uint64_t(at) + bytes <= top;
}
void requireCpuIrqControlHistory(uint32_t at, uint32_t bytes, R5900Context& ctx) {
    if (!bytes || bytes > 16u)
        throw std::invalid_argument("IRQ control input exceeds exact scalar extent");
    for (uint32_t word = at & ~3u; word < uint64_t(at) + bytes; word += 4u) {
        const auto* history = controlHistory(word);
        if (!history || !history->valid || !history->completedWriter)
            throw std::runtime_error(
                "IRQ control lacks an actual ScalarControl writer; CPU values cannot seed history");
        uint32_t bits;
        std::memcpy(&bits, static_cast<const uint8_t*>(ramIdentity()) + word, 4);
        if (bits != history->bits)
            throw std::runtime_error("IRQ control changed outside completed source history");
        for (const auto& revision : protectedRevisions_)
            if (revision.address == word && revision.completedWriter != history->completedWriter)
                throw std::runtime_error(
                    "IRQ fixed control revision differs from actual ScalarControl history");
    }
    std::vector<uint32_t> addresses;
    if (cpuIrqFrontier_)
        for (const auto& w : cpuIrqFrontier_->words_)
            addresses.push_back(w.address);
    for (uint32_t word = at & ~3u; word < uint64_t(at) + bytes; word += 4u)
        if (std::find(addresses.begin(), addresses.end(), word) == addresses.end())
            addresses.push_back(word);
    if (addresses.size() > 32u)
        throw std::runtime_error("IRQ CPU control input exceeds bounded protected frontier");
    auto next = captureProtectedScalars(&ctx, addresses);
    if (cpuIrqFrontier_)
        releaseProtectedScalars(cpuIrqFrontier_, &ctx);
    cpuIrqFrontier_ = std::move(next);
}

public:
CallbackFrameHandle enterOriginalCpuIrqContext(const IrqInitializerHandle& init) override {
    if (!OriginalCpuIrqControlCoverageImplemented || !init || init->handler() != 0x18d160u ||
        init->sourceStep() != sub_0018D160_0x18d160)
        throw std::runtime_error("Original integer IRQ route remains default off/unreviewed");
    struct Admission {
        const IrqInitializer* prior;
        Admission(const IrqInitializer* x) : prior(reo_irq_integer::actualCpuContextAdmission) {
            reo_irq_integer::actualCpuContextAdmission = x;
        }
        ~Admission() {
            reo_irq_integer::actualCpuContextAdmission = prior;
        }
    } admission(init.get());
    return enterActualIrqContext(init); // Actual GPU main save/fresh image/fences.
}
IrqCpuLeaseHandle beginOriginalCpuIrqControl(const IrqInitializerHandle& init) override {
    requireHealthy();
    if (!OriginalCpuIrqControlCoverageImplemented || !init || init->handler() != 0x18d160u ||
        !actualCpuIrqLease_.expired() || !pendingSourceWrite_.expired() || journal_.hasPrepared() ||
        journal_.hasCompleted())
        throw std::invalid_argument("Original CPU IRQ entry has pending/foreign source authority");
    init->validateBeforeAnyIrqInstructionOnEe();
    std::lock_guard<std::recursive_mutex> source(sourceMutex_);
    std::lock_guard<std::recursive_mutex> lock(service_.hostProtocolMutex());
    if (service_.callbacks_.empty() || service_.callbacks_.back()->freshInitializer != init ||
        &init->context() != contextIdentity())
        throw std::invalid_argument("CPU IRQ initializer has no actual fresh GPU main loan");
    service_.exactFreshIrqFrame(service_.callbacks_.back());
    auto lease = std::shared_ptr<const IrqCpuLease>(
        new IrqCpuLease(this, init, epoch_, actualOwnerBindingGeneration()));
    actualCpuIrqLease_ = lease;
    cpuIrqStackAuthored_.reset();
    cpuIrqFrontier_.reset();
    originalIrqPacketPointer_.reset();
    return lease;
}
void readOriginalCpuIrq(const IrqCpuLeaseHandle& lease, SourceSpace space, uint32_t at, void* dst,
                        uint32_t bytes,
                        const reo_source_instrumentation::InstructionOrigin& origin) override {
    std::lock_guard<std::recursive_mutex> source(sourceMutex_);
    exactCpuIrqLease(lease);
    auto& ctx = lease->initializer()->context();
    const auto identity = reo_irq_integer::currentWriteIdentity();
    identity.validateOnEe();
    if (identity.lease != lease || origin.pc != identity.origin.pc ||
        origin.word != identity.origin.word || !dst || !bytes || bytes > 16u ||
        (!reo_irq_integer::site(origin.pc, origin.word) && !reo_irq_integer::nativeScopeActive()))
        throw std::invalid_argument("IRQ read lacks exact original integer source");
    if (space == SourceSpace::Context) {
        if (!reo_irq_integer::integerField(at, bytes))
            throw std::runtime_error(
                "Original integer IRQ cannot read numerical FPU/VF/ACC/Q Context fields");
        read(space, at, bytes, &ctx, ctx.pc);
        std::memcpy(dst, reinterpret_cast<const uint8_t*>(&ctx) + at, bytes);
        return;
    }
    if (space != SourceSpace::Ram || !protocol::range(at, bytes, protocol::RamBytes))
        throw std::runtime_error("Original CPU IRQ has no SPR/numerical memory authority");
    if (tryReadCertifiedOriginalCpuIrqHeader(lease, at, dst, bytes, origin))
        return;
    const bool code = reo_irq_integer::site(at, origin.word) != nullptr;
    const bool literal = code || (at >= 0x23fdf0u && uint64_t(at) + bytes <= 0x23fdf8u) ||
                         (at >= 0x241c10u && uint64_t(at) + bytes <= 0x241c28u) ||
                         (origin.pc == 0x18d298u && at == 0x23fde0u && bytes == 16u);
    if (cpuIrqStack(lease, at, bytes)) {
        const uint32_t base = lease->initializer()->stackTop() - 1024u;
        for (uint32_t b = 0; b < bytes; ++b)
            if (!cpuIrqStackAuthored_.test(at - base + b))
                throw std::runtime_error("IRQ stack input has no actual authored integer store");
    } else if (!literal) {
        const bool fixedNonpointer =
            bytes == 4u && !(at & 3u) &&
            (at == 0x29fdb4u || at == 0x29f6f0u || at == 0x29f6f4u || at == 0x29f6f8u ||
             (at >= 0x29f704u && at <= 0x29f728u) || at == 0x294148u || at == 0x294150u);
        if (!fixedNonpointer || controlHistory(at))
            requireCpuIrqControlHistory(at, bytes, ctx);
        else {
            if (!cold_->capturedEntry)
                throw std::runtime_error("IRQ fixed control lacks genuine cold RAW input issuer");
            const auto& snapshot = cold_->capturedEntry->preEntryControls();
            if (!snapshot)
                throw std::runtime_error("Cold RAW control lost its actual snapshot issuer");
            snapshot->requireAuthenticColdOwner(*runtimeIdentity(), *cold_->actualContext,
                                                ramIdentity(),
                                                cold_->capturedEntry->contextLifetime());
            const ProtectedRevision* revision = nullptr;
            for (const auto& r : protectedRevisions_)
                if (r.address == at)
                    revision = &r;
            uint32_t original, current;
            std::memcpy(&original,
                        static_cast<const uint8_t*>(cold_->capturedEntry->initialRam()) + at, 4u);
            std::memcpy(&current, static_cast<const uint8_t*>(ramIdentity()) + at, 4u);
            if (!revision || revision->completedWriter != 0u || original != current)
                throw std::runtime_error(
                    "IRQ cold RAW control changed without an authenticated integer source writer");
            read(SourceSpace::Ram, at, bytes, &ctx, ctx.pc);
            std::vector<uint32_t> addresses;
            if (cpuIrqFrontier_)
                for (const auto& w : cpuIrqFrontier_->words_)
                    addresses.push_back(w.address);
            if (std::find(addresses.begin(), addresses.end(), at) == addresses.end())
                addresses.push_back(at);
            auto next = captureProtectedScalars(&ctx, addresses);
            if (cpuIrqFrontier_)
                releaseProtectedScalars(cpuIrqFrontier_, &ctx);
            cpuIrqFrontier_ = std::move(next);
        }
    }
    // RAW guards remain mandatory: no opaque packet/matrix bytes are read.
    read(SourceSpace::Ram, at, bytes, &ctx, ctx.pc);
    std::memcpy(dst, static_cast<const uint8_t*>(ramIdentity()) + at, bytes);
    retainOriginalCpuIrqPacketPointer(lease, at, dst, bytes, origin);
}
SourceWritePermit
beginOriginalCpuIrqWrite(const IrqCpuLeaseHandle& lease, SourceSpace space, uint32_t at,
                         const void* value, uint32_t bytes,
                         const reo_source_instrumentation::InstructionOrigin& origin,
                         bool native) override {
    try {
        std::unique_lock<std::recursive_mutex> source(sourceMutex_);
        exactCpuIrqLease(lease);
        auto& ctx = lease->initializer()->context();
        const auto identity = reo_irq_integer::currentWriteIdentity();
        identity.validateOnEe();
        if (identity.lease != lease || origin.pc != identity.origin.pc ||
            origin.word != identity.origin.word || !value || !bytes || bytes > 16u ||
            !pendingSourceWrite_.expired() || nextSourceWrite_ == UINT64_MAX)
            throw std::invalid_argument("CPU IRQ store lost genuine source/permit capacity");
        if (native) {
            if (!reo_irq_integer::exactNativeReturn(at, value, bytes) ||
                space != SourceSpace::Context)
                throw std::invalid_argument(
                    "CPU IRQ native return differs from exact helper/constant/shape");
        } else if (!reo_irq_integer::site(origin.pc, origin.word))
            throw std::invalid_argument("CPU IRQ store is not an original integer instruction");
        if (space == SourceSpace::Context && !native &&
            !reo_irq_integer::integerWriteShape(at, bytes, origin))
            throw std::runtime_error("CPU IRQ destination is outside exact integer opcode fields");
        if (space != SourceSpace::Context && space != SourceSpace::Ram)
            throw std::runtime_error("CPU IRQ store cannot touch SPR or numerical banks");
        const uint32_t limit = space == SourceSpace::Context ? 1648u : protocol::RamBytes;
        if (!protocol::range(at, bytes, limit))
            throw std::invalid_argument("CPU IRQ store outside actual bank");
        heldWriteGuard(space, at, bytes, &ctx);
        pendingAccessGuard(space, at, bytes, &ctx);
        ProtectedScalarCaptureHandle successor;
        const bool stack = space == SourceSpace::Ram && cpuIrqStack(lease, at, bytes);
        if (space == SourceSpace::Ram) {
            // Every RAM store is the exact original SB/SW/SD/SQ operand.
            const uint32_t op = origin.word >> 26u;
            const uint32_t expected = op == 0x28u   ? 1u
                                      : op == 0x2bu ? 4u
                                      : op == 0x3fu ? 8u
                                      : op == 0x1fu ? 16u
                                                    : 0u;
            if (expected != bytes)
                throw std::invalid_argument(
                    "CPU IRQ RAM write is not its original integer store opcode");
            const uint32_t rs = (origin.word >> 21u) & 31u, rt = (origin.word >> 16u) & 31u;
            uint32_t base = 0;
            if (rs)
                std::memcpy(&base, &ctx.r[rs], 4);
            const uint32_t address = base + uint32_t(int32_t(int16_t(origin.word)));
            if ((address & PS2_RAM_MASK) != at)
                throw std::invalid_argument(
                    "CPU IRQ RAM store differs from actual integer address operands");
            std::array<uint8_t, 16> operand{};
            if (rt)
                std::memcpy(operand.data(), &ctx.r[rt], bytes);
            if (std::memcmp(operand.data(), value, bytes))
                throw std::invalid_argument(
                    "CPU IRQ RAM store differs from exact original GPR operand");
            if (!stack) {
                const bool destination =
                    (origin.pc == 0x18d224u && (at == 0x29f704u || at == 0x29f708u)) ||
                    ((origin.pc == 0x18d234u || origin.pc == 0x18d250u) &&
                     (at == 0x29f714u || at == 0x29f718u)) ||
                    (origin.pc == 0x18d2ccu && at == 0x29f71cu) ||
                    ((origin.pc == 0x18d270u || origin.pc == 0x18d3ecu) && at == 0x29f720u) ||
                    (origin.pc == 0x18d394u && at == 0x294148u) ||
                    (origin.pc == 0x18d3a0u && at == 0x294150u) ||
                    (origin.pc == 0x18d3b8u && at == 0x294158u);
                if ((bytes != (origin.pc == 0x18d3b8u ? 8u : 4u)) || !destination)
                    throw std::invalid_argument(
                        "Original CPU IRQ RAM bookkeeping has no exact fixed counter destination");
                requireCpuIrqControlHistory(at, bytes, ctx);
                validateProtectedScalars(cpuIrqFrontier_, &ctx);
                if ((at & 3u) || (bytes & 3u))
                    throw std::runtime_error("CPU IRQ partial RAM bookkeeping requires a separate "
                                             "exact byte-history issuer");
                for (const auto& weak : protectedCaptures_)
                    if (auto other = weak.lock())
                        if (other != cpuIrqFrontier_)
                            for (const auto& word : other->words_)
                                if (protocol::overlap(at, bytes, word.address, 4))
                                    throw std::runtime_error("CPU IRQ store conflicts with "
                                                             "independent protected scalar lease");
                auto words = cpuIrqFrontier_->words_;
                for (uint32_t k = 0; k < bytes; k += 4) {
                    uint32_t bits;
                    std::memcpy(&bits, static_cast<const uint8_t*>(value) + k, 4);
                    bool found = false;
                    for (auto& word : words)
                        if (word.address == at + k) {
                            word.value = bits;
                            word.completedWriter = nextSourceWrite_;
                            found = true;
                        }
                    if (!found)
                        throw std::runtime_error(
                            "CPU IRQ counter store has no exact protected source word");
                }
                if (nextScalarCapture_ == UINT64_MAX)
                    throw std::overflow_error("CPU IRQ protected successor exhausted");
                successor =
                    std::shared_ptr<const ProtectedScalarCapture>(new ProtectedScalarCapture(
                        this, runtimeIdentity(), &ctx, ps2_sched::currentThread(), epoch_,
                        nextScalarCapture_, nextSourceWrite_, std::move(words)));
                ++nextScalarCapture_;
                protectedCaptures_.reserve(protectedCaptures_.size() + 1);
                controlHistory_.reserve(controlHistory_.size() + bytes / 4u);
                pendingScalarHistory_ = true;
                pendingScalarSourceWord_ = origin.word;
            } else {
                protectedWriteGuard(space, at, bytes);
                pendingScalarHistory_ = false;
            }
        }
        auto nextOpaque = space == SourceSpace::Context
                              ? service_.prepareTypedContextControlTransition(ctx, at, bytes)
                              : std::vector<protocol::Range>{};
        gateway_.prepareActualRawWriterCompletion();
        auto permit = std::shared_ptr<PreparedSourceWrite>(
            new PreparedSourceWrite(this, space, at, value, bytes, ctx.pc, epoch_, nextSourceWrite_,
                                    &ctx, ps2_sched::currentThread(), true, std::move(source)));
        permit->validateActualIssuer_ = [this, lease, identity] {
            identity.validateOnEe();
            exactCpuIrqLease(lease);
        };
        journal_.prepareAuthenticatedIrqControl(space, at, permit->data(), bytes, ctx.pc);
        pendingSourceWrite_ = permit;
        if (space == SourceSpace::Context) {
            permit->deferredControl_ = true;
            permit->deferredControlRole_ =
                (at == offsetof(R5900Context, pc) || at == offsetof(R5900Context, branch_pc) ||
                 at / 16u == 31u)
                    ? 3u
                : at / 16u == 29u ? 6u
                                  : 7u;
            pendingContextControlOpaque_ = std::move(nextOpaque);
            pendingScalarHistory_ = false;
        } else {
            const auto patch = journal_.prepared();
            permit->sourceLease_.unlock();
            auto self = shared_from_this();
            // Keep genuine EE ownership during the true scalar mirror fence.
            runActualOwnerControl(epoch_, [self, lease, patch](ControlTarget& owner) {
                if (&owner != self.get())
                    throw std::invalid_argument(
                        "CPU IRQ scalar mirror reached foreign factory owner");
                self->service_.mirrorOriginalCpuIrqControlOnOwner(lease, patch);
            });
            permit->sourceLease_.lock();
            identity.validateOnEe();
            exactCpuIrqLease(lease);
        }
        permit->completeActualIssuer_ = [this, lease, space, at, bytes, stack, successor] {
            if (space != SourceSpace::Ram)
                return;
            if (stack) {
                const uint32_t base = lease->initializer()->stackTop() - 1024u;
                for (uint32_t b = 0; b < bytes; ++b)
                    cpuIrqStackAuthored_.set(at - base + b);
            }
            if (successor) {
                auto old = cpuIrqFrontier_;
                protectedCaptures_.erase(
                    std::remove_if(protectedCaptures_.begin(), protectedCaptures_.end(),
                                   [&](const auto& w) { return w.expired() || w.lock() == old; }),
                    protectedCaptures_.end());
                protectedCaptures_.push_back(successor);
                cpuIrqFrontier_ = successor;
            }
        };
        permit->mirrored_ = true;
        return permit;
    } catch (...) {
        failed_.store(true, std::memory_order_release);
        throwOwnedSourceFailure(runtimeIdentity());
    }
}
void endOriginalCpuIrqControl(const IrqCpuLeaseHandle& lease) override {
    std::lock_guard<std::recursive_mutex> source(sourceMutex_);
    exactCpuIrqLease(lease);
    if (lease->initializer()->context().pc != 0u || !pendingSourceWrite_.expired() ||
        journal_.hasPrepared())
        throw std::runtime_error("CPU IRQ return preceded exact source permit completion");
    if (cpuIrqFrontier_)
        releaseProtectedScalars(cpuIrqFrontier_, &lease->initializer()->context());
    cpuIrqFrontier_.reset();
    const_cast<IrqCpuLease*>(lease.get())->active_.store(false, std::memory_order_release);
    actualCpuIrqLease_.reset();
    originalIrqPacketPointer_.reset();
}

public:
