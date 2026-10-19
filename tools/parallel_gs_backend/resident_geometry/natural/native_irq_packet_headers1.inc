private:
struct OriginalIrqPacketPointerWitness {
    IrqCpuLeaseHandle lease;
    uint32_t address, taggedPointer, sourcePc, sourceWord;
    uint64_t completedWriter;
};
std::optional<OriginalIrqPacketPointerWitness> originalIrqPacketPointer_;
PreEntryIntegerSourceHandle
authenticateOriginalIrqPacketHeaderWrite(SourceSpace space, uint32_t at, const void* data,
                                         uint32_t bytes, R5900Context& ctx, uint32_t pc) {
    if (space != SourceSpace::Ram || (pc != 0x124e50u && pc != 0x124e58u))
        return {};
    auto source = actualPreEntryIntegerSource;
    if (!source || source->kind() != PreEntryIntegerSource::Kind::Queue ||
        source->entry() != 0x124e50u || source->originalBodyIdentity() != &::sub_00124E50_0x124e50)
        throw std::invalid_argument("IRQ packet header lacks its sealed actual integer producer");
    validateOriginalIrqPacketHeaderWrite(source, at, data, bytes, ctx, pc);
    return source;
}
void validateOriginalIrqPacketHeaderWrite(const PreEntryIntegerSourceHandle& source, uint32_t at,
                                          const void* data, uint32_t bytes, R5900Context& ctx,
                                          uint32_t pc) {
    source->requireCurrent();
    actualSourceScope(&ctx, pc);
    const uint32_t word = pc == 0x124e50u ? 0xac860084u : 0xac850080u,
                   reg = pc == 0x124e50u ? 6u : 5u, offset = pc == 0x124e50u ? 0x84u : 0x80u;
    if (&source->runtime() != runtimeIdentity() || &source->context() != &ctx ||
        source->ramIdentity() != ramIdentity() || source->pc() != pc || source->word() != word ||
        bytes != 4u || !data || source->task() < 1)
        throw std::invalid_argument(
            "IRQ header writer lost exact original instruction/task/Context");
    std::lock_guard<std::recursive_mutex> lock(service_.hostProtocolMutex());
    service_.guardKnownContextRead(ctx, 4u * 16u, 4u);
    service_.guardKnownContextRead(ctx, reg * 16u, 4u);
    if (!reo_source_closure::scalarControlLane(service_.compositionScalarRoles_, 4u * 16u, 4u) ||
        !reo_source_closure::scalarControlLane(service_.compositionScalarRoles_, reg * 16u, 4u))
        throw std::runtime_error(
            "IRQ header producer cannot relabel numerical/unknown pointer or A1/A2 input as RAW");
    uint32_t pointer, value;
    std::memcpy(&pointer, &ctx.r[4], 4u);
    std::memcpy(&value, &ctx.r[reg], 4u);
    if ((pointer & 3u) || !protocol::range(pointer, 0x88u, protocol::RamBytes) ||
        at != pointer + offset || std::memcmp(&value, data, 4u))
        throw std::invalid_argument(
            "IRQ header store differs from genuine original pointer/operand");
}
void retainOriginalCpuIrqPacketPointer(
    const IrqCpuLeaseHandle& lease, uint32_t at, const void* value, uint32_t bytes,
    const reo_source_instrumentation::InstructionOrigin& origin) {
    const bool first = origin.pc == 0x18d240u && origin.word == 0x8c710000u,
               second = origin.pc == 0x18d2c4u && origin.word == 0x8c510000u;
    if (!first && !second)
        return;
    exactCpuIrqLease(lease);
    auto identity = reo_irq_integer::currentWriteIdentity();
    identity.validateOnEe();
    if (identity.lease != lease || identity.origin.pc != origin.pc ||
        identity.origin.word != origin.word || !value || bytes != 4u)
        throw std::invalid_argument("IRQ packet pointer lost exact original ring load");
    auto& ctx = lease->initializer()->context();
    uint32_t base;
    std::memcpy(&base, &ctx.r[first ? 3u : 2u], 4u);
    const auto* history = controlHistory(at);
    uint32_t bits;
    std::memcpy(&bits, value, 4u);
    if ((bits >> 28u) != 4u) {
        originalIrqPacketPointer_.reset();
        return;
    }
    if ((base & PS2_RAM_MASK) != at || !history || !history->valid || !history->completedWriter ||
        history->bits != bits || history->sourcePc != 0x18d034u ||
        history->sourceWord != 0xac540000u)
        throw std::runtime_error(
            "IRQ pointer is not its authentic completed original queue ring word");
    if (!cpuIrqFrontier_ || cpuIrqFrontier_->completedWriter(at) != history->completedWriter)
        throw std::runtime_error("IRQ packet pointer lacks retained protected ring frontier");
    validateProtectedScalars(cpuIrqFrontier_, &ctx);
    originalIrqPacketPointer_ = OriginalIrqPacketPointerWitness{
        lease, at, bits, origin.pc, origin.word, history->completedWriter};
}
bool tryReadCertifiedOriginalCpuIrqHeader(
    const IrqCpuLeaseHandle& lease, uint32_t at, void* dst, uint32_t bytes,
    const reo_source_instrumentation::InstructionOrigin& origin) {
    const bool first = origin.pc == 0x18d37cu && origin.word == 0x8e250080u,
               second = origin.pc == 0x18d398u && origin.word == 0x8e250084u;
    if (!first && !second)
        return false;
    exactCpuIrqLease(lease);
    auto identity = reo_irq_integer::currentWriteIdentity();
    identity.validateOnEe();
    if (identity.lease != lease || identity.origin.pc != origin.pc ||
        identity.origin.word != origin.word || !dst || bytes != 4u || !originalIrqPacketPointer_ ||
        originalIrqPacketPointer_->lease != lease)
        throw std::invalid_argument(
            "IRQ header read lacks exact fresh callback/ring/source lifetime");
    auto& ctx = lease->initializer()->context();
    const auto& witness = *originalIrqPacketPointer_;
    const auto* ring = controlHistory(witness.address);
    if (!ring || !ring->valid || ring->completedWriter != witness.completedWriter ||
        ring->bits != witness.taggedPointer || ring->sourcePc != 0x18d034u ||
        ring->sourceWord != 0xac540000u)
        throw std::runtime_error("IRQ header pointer's genuine ring writer changed");
    uint32_t packet;
    std::memcpy(&packet, &ctx.r[17], 4u);
    if ((witness.taggedPointer >> 28u) != 4u || packet != (witness.taggedPointer & 0x0fffffffu) ||
        (packet & 3u) || !protocol::range(packet, 0x88u, protocol::RamBytes) ||
        at != packet + (first ? 0x80u : 0x84u))
        throw std::invalid_argument("IRQ header is not the exact original subtype4 packet field");
    const auto* header = controlHistory(at);
    const uint32_t producerPc = first ? 0x124e58u : 0x124e50u,
                   producerWord = first ? 0xac850080u : 0xac860084u;
    if (!header || !header->valid || !header->completedWriter || header->sourcePc != producerPc ||
        header->sourceWord != producerWord)
        throw std::runtime_error("IRQ packet field has no completed exact integer header producer");
    // The fresh callback lease has already waited its real same-bank fence.
    // The current logical RAW guard is mandatory; no GPU packet payload is
    // copied and no equality test grants numerical bytes a scalar role.
    requireCpuIrqControlHistory(at, bytes, ctx);
    validateProtectedScalars(cpuIrqFrontier_, &ctx);
    read(SourceSpace::Ram, at, bytes, &ctx, ctx.pc);
    std::memcpy(dst, static_cast<const uint8_t*>(ramIdentity()) + at, bytes);
    return true;
}

public:
