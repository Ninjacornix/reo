private:
PreEntryIntegerSourceHandle authenticateOriginalHeapControlWrite(SourceSpace space, uint32_t at,
                                                                 const void* data, uint32_t bytes,
                                                                 R5900Context& ctx, uint32_t pc) {
    if (space != SourceSpace::Ram || !originalHeapControlSite(pc))
        return {};
    auto source = actualPreEntryIntegerSource;
    if (!source || source->kind() != PreEntryIntegerSource::Kind::Queue ||
        source->originalBodyIdentity() != originalHeapControlBody(source->entry()))
        throw std::invalid_argument("Heap control lacks its sealed actual integer producer");
    validateOriginalHeapControlWrite(source, at, data, bytes, ctx, pc);
    return source;
}
void validateOriginalHeapControlWrite(const PreEntryIntegerSourceHandle& source, uint32_t at,
                                      const void* data, uint32_t bytes, R5900Context& ctx,
                                      uint32_t pc) {
    source->requireCurrent();
    actualSourceScope(&ctx, pc);
    const auto* site = originalHeapControlSite(pc);
    if (!site || source->entry() != site->entry || source->pc() != pc ||
        source->word() != site->word || &source->runtime() != runtimeIdentity() ||
        &source->context() != &ctx || source->ramIdentity() != ramIdentity() ||
        source->task() < 1 || bytes != 4u || !data || !originalHeapControlDestination(*site, at))
        throw std::invalid_argument(
            "Heap writer lost its exact original instruction/task/Context/destination");
    std::lock_guard<std::recursive_mutex> lock(service_.hostProtocolMutex());
    const uint32_t base = (site->word >> 21u) & 31u, reg = (site->word >> 16u) & 31u;
    service_.guardKnownContextRead(ctx, base * 16u, 4u);
    service_.guardKnownContextRead(ctx, reg * 16u, 4u);
    if (!reo_source_closure::scalarControlLane(service_.compositionScalarRoles_, base * 16u, 4u) ||
        !reo_source_closure::scalarControlLane(service_.compositionScalarRoles_, reg * 16u, 4u))
        throw std::runtime_error(
            "Heap writer cannot relabel numerical/unknown address or integer operand as RAW");
    uint32_t rawBase = 0, value = 0;
    std::memcpy(&rawBase, &ctx.r[base], 4u);
    std::memcpy(&value, &ctx.r[reg], 4u);
    if (((rawBase + uint32_t(int32_t(int16_t(site->word)))) & PS2_RAM_MASK) != at ||
        std::memcmp(&value, data, 4u))
        throw std::invalid_argument("Heap store differs from its genuine original address/operand");
}

public:
