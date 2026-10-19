std::unique_ptr<reo_gpu_static_group::GroupAdapter> staticGroup_;
std::unique_ptr<reo_gpu_static_group::TypedBuilder> staticBuilder_;
std::vector<Operation> staticHeld_;
uint32_t staticHeldBytes_ = 0;
bool staticSelected_ = false;
struct StaticCounters {
    uint64_t eligible = 0, groups = 0, rawRows = 0, maxGroup = 0, boundaries = 0;
    uint64_t retired = 0, fastGroups = 0, completeGpuGroups = 0, inputVertices = 0;
} staticCounters_;
bool staticLaunch(const Operation& op) const {
    return staticBuilder_ && staticBuilder_->covers(op, false);
}
void flushAllHeld() {
    flushStaticGroup();
    flushStream();
}
void flushStaticGroup() {
    if (staticHeld_.empty())
        return;
    ++staticCounters_.boundaries;
    if (!staticBuilder_ || !staticBuilder_->jobs()) {
        auto operations = std::move(staticHeld_);
        const auto bytes = staticHeldBytes_;
        staticHeldBytes_ = 0;
        try {
            if (staticBuilder_)
                staticBuilder_->clear();
            Batch pending{};
            pending.epoch = epoch_;
            pending.bankGeneration = generation_;
            pending.operations = std::move(operations);
            pending.payloadBytes = bytes;
            enqueueDirect(pending);
            return;
        } catch (...) {
            failed_ = true;
            throw;
        }
    }
    const uint32_t transaction = gs_.resident_material_group_next_generation();
    if (!transaction)
        throw std::overflow_error("Static preview GS transaction generation exhausted");
    const auto sourceClass = shaders_.staticGroup.scope == reo_gpu_static_group::Scope::ScopedLive
                                 ? reo_gpu_static_stream::SourceClass::LiteralTypedVIF
                                 : reo_gpu_static_stream::SourceClass::DerivedControl;
    auto words = staticBuilder_->literalTape(transaction, sourceClass);
    auto ordinals = staticBuilder_->ordinals();
    auto operations = std::move(staticHeld_);
    staticHeldBytes_ = 0;
    staticBuilder_->clear();
    try {
        std::vector<const Operation*> launches;
        for (const auto& op : operations)
            if (op.kind == Kind::Launch)
                launches.push_back(&op);
        if (launches.size() != ordinals.size() || launches.empty())
            throw std::logic_error("Static held operation/tape launch accounting differs");
        // Earlier legacy/static prefixes must already own their genuine tail.
        // Our own held lists were moved out first, so this cannot recurse.
        guardPublishedEffects();
        std::vector<ParallelGS::ResidentMaterialGroupCommand> commands(launches.size());
        uint32_t lastGeometry = ~0u;
        for (uint32_t j = 0; j < launches.size(); ++j) {
            const auto& op = *launches[j];
            auto& c = commands[j];
            auto& p = c.sourceParameters;
            const uint32_t at = 16 + j * 16, kind = words[at + 11], e = words[at + 6],
                           n = kind == 1 ? (words[e + 4] & 32767u) : 0u;
            c.kind = ParallelGS::ResidentMaterialGroupCommand::Kind(kind);
            c.sourceVertices = n;
            p[0] = n;
            p[1] = 11 * n;
            p[2] = 495;
            p[3] = 3213;
            p[4] = 0x5273fa3e;
            p[6] = transaction;
            p[7] = j;
            if (kind == 1) {
                for (unsigned q = 0; q < 4; ++q)
                    p[8 + q] = words[e + 4 + q];
                c.mainPRIM = (p[9] >> 15) & 2047;
                lastGeometry = j;
            } else if (kind == 2)
                for (unsigned q = 0; q < 28; ++q)
                    c.rawAD[q] = words[e + 4 + q];
            p[12] = op.top;
            p[13] = op.itop;
            p[14] = op.resume ? 4u : 0u;
            p[15] = 65536;
            p[32] = kind;
            p[33] = op.startPC;
            p[34] = uint32_t(launches.size());
            p[36] = 0x42534331;
            p[37] = 1;
            p[38] = 64;
            for (unsigned q = 0; q < 64; ++q)
                p[40 + q] = words[e + q];
        }
#ifdef REO_STATIC_OWNER_PREVIEW_DIAGNOSTICS
        const auto previewEntryLog = [&](const char* point) {
            const auto v = gs_.resident_material_group_entry_diagnostic();
            std::fprintf(
                stderr,
                "STATIC_PREVIEW_DIAG point%s firstOrdinal%llu jobs%u transaction%u primitive%llu "
                "pendingPalette%llu rendererPending%llu cursor%llu selected%llu base%llu "
                "lastRead%llu activeTransfer%llu sx%llu sy%llu AC%llu lastGeneration%llu\n",
                point, static_cast<unsigned long long>(launches.front()->ordinal),
                uint32_t(launches.size()), transaction, static_cast<unsigned long long>(v[0]),
                static_cast<unsigned long long>(v[1]), static_cast<unsigned long long>(v[2]),
                static_cast<unsigned long long>(v[3]), static_cast<unsigned long long>(v[4]),
                static_cast<unsigned long long>(v[5]), static_cast<unsigned long long>(v[6]),
                static_cast<unsigned long long>(v[7]), static_cast<unsigned long long>(v[8]),
                static_cast<unsigned long long>(v[9]), static_cast<unsigned long long>(v[10]),
                static_cast<unsigned long long>(v[11]));
        };
        previewEntryLog("beforeRecording");
#endif
        if (!gs_.prepare_resident_recording_projected())
            throw std::runtime_error("Static group preview overlaps incomplete ordinary GS input");
#ifdef REO_STATIC_OWNER_PREVIEW_DIAGNOSTICS
        previewEntryLog("afterRecording");
#endif
        ParallelGS::ResidentMaterialGroupPreviewHandle preview;
        if (!gs_.preview_resident_material_group(commands, epoch_, transaction, preview))
            throw std::runtime_error("Static ordered material preview domain declined");
        std::vector<reo_gpu_batched_stream_consumer::JobParameters> materials(launches.size());
        for (uint32_t j = 0; j < launches.size(); ++j)
            std::memcpy(&materials[j], preview->parameters(j).data(), 448);
        Vulkan::BufferCreateInfo uploadInfo{};
        uploadInfo.domain = Vulkan::BufferDomain::Host;
        uploadInfo.size = words.size() * 4;
        uploadInfo.usage = VK_BUFFER_USAGE_TRANSFER_SRC_BIT;
        auto upload = device_.create_buffer(uploadInfo, words.data());
        if (!upload)
            throw std::runtime_error("Immutable static typed upload allocation failed");
        const reo_gpu_static_group::Authority authority{&device_, &whole_->state(), &whole_->data(),
                                                        &whole_->completion()};
        const reo_gpu_static_group::TypedTape input{
            &device_, upload.get(), uint32_t(words.size()), uint32_t(launches.size()),
            words[3], transaction,  uint32_t(sourceClass)};
        auto run = std::make_shared<reo_gpu_static_group::Run>();
        run->preview = preview;
        run->lastGeometry = lastGeometry;
        reo_gpu_mixed_material::SourceCertificate sourceCertificate(gs_, preview);
        gs_.record_resident_command([&](Vulkan::CommandBuffer& cmd) {
            run->output = staticGroup_->record(cmd, authority, input, std::move(materials),
                                               ordinals, epoch_, generation_, &sourceCertificate);
        });
        if (!gs_.submit_resident_material_group_receipt(preview, whole_->completion(),
                                                        run->output.triangles->bank(3)))
            throw std::runtime_error("Static group has no actual source/authority receipt");
        const auto producerFence = gs_.resident_material_group_producer_fence(preview);
        if (!producerFence)
            throw std::runtime_error("Static group producer fence absent");
        if (parent_)
            parent_->sealActualUploads(producerFence);
        const bool committed =
            gs_.commit_resident_material_group(preview); // waits THIS genuine early producer fence
        retireParentUploads(producerFence);
        if (!committed)
            throw std::runtime_error("Static group complete material/source transaction refused");
        for (uint32_t j = 0; j < launches.size(); ++j)
            for (uint32_t chunk = 0; chunk < run->output.triangles->chunks(j); ++chunk) {
                if (!gs_.submit_resident_group_material(
                        preview, j, run->output.triangles->inputs(j, chunk, epoch_)))
                    throw std::runtime_error("Static certified material/output view refused");
            }
        auto* cert = const_cast<Vulkan::Buffer*>(&run->output.triangles->bank(3));
        cert->add_reference();
        const uint64_t tailOffset =
            lastGeometry == ~0u ? 0u : uint64_t(lastGeometry) * 4192u + 4032u;
        if (!gs_.adopt_resident_group_tail(preview, Vulkan::BufferHandle(cert), tailOffset))
            throw std::runtime_error("Static ordered actual graphics tail refused");
        for (uint32_t j = 0; j < launches.size(); ++j) {
            Job entry{};
            entry.ordinal = launches[j]->ordinal;
            entry.staticGroup = run;
            entry.staticLocal = j;
            entry.tailPublished = true;
            jobs_.push_back(std::move(entry));
            lastEnqueued_ = launches[j]->ordinal;
        }
        ++staticCounters_.groups;
        staticCounters_.maxGroup = std::max<uint64_t>(staticCounters_.maxGroup, launches.size());
        // That full prefix has a real receipt and its frontend tail. Subsequent
        // pixel completion is owned independently by GSRenderer's lifetimes.
        needsPublicationCheck_ = false;
        logStream("static_group_source_authority_retired_graphics_queued");
    } catch (...) {
        failed_ = true;
        throw;
    }
}
void acceptStaticBatch(const Batch& batch) {
    validate(batch);
    uint64_t ordinal = lastAccepted_;
    size_t count = jobs_.size() + streamBuilder_.jobs() + staticBuilder_->jobs();
    for (const auto& op : batch.operations)
        if (op.kind == Kind::Launch) {
            if (op.program->bindingId == shaders_.staticGroup.program->bindingId &&
                op.program->exactImage != shaders_.staticGroup.program->exactImage)
                throw std::invalid_argument(
                    "Configured static group binding has a different exact image");
            bool registered = staticLaunch(op) || findMulti(op), resume = false, literal = false;
            for (const auto& module : shaders_.programs)
                if (module.bindingId == op.program->bindingId) {
                    registered = true;
                    resume = module.canResume;
                    literal = op.resume ? module.resumeLiteralSourcePreserved
                                        : module.freshLiteralSourcePreserved;
                }
            if (!registered || (op.resume && !staticLaunch(op) && !findMulti(op) && !resume) ||
                (op.program->literalSourcePreserved && !staticLaunch(op) && !findMulti(op) &&
                 !literal) ||
                op.ordinal != ordinal + 1 || ++count > MaxLaunches)
                throw std::runtime_error(
                    "Static owner rejected unregistered/incomplete/unordered launch");
            validateLiteralEnvelope(op.effect);
            ordinal = op.ordinal;
        }
    cold(batch);
    requireOwner(batch.epoch, batch.bankGeneration);
    preflightParent(batch);
    try {
        for (const auto& op : batch.operations) {
            if (op.kind == Kind::Launch) {
                if (staticLaunch(op)) {
                    flushStream();
                    if (!staticBuilder_->covers(op) ||
                        staticBuilder_->jobs() >= shaders_.staticGroup.capacity ||
                        !staticBuilder_->room(0, 1) || staticHeld_.size() == MaxOperations)
                        flushStaticGroup();
                    if (!staticBuilder_->launch(op, uint32_t(staticCounters_.groups)))
                        throw std::logic_error("Static source admission changed after preflight");
                    staticHeld_.push_back(op);
                    staticSelected_ = true;
                    ++staticCounters_.eligible;
                    lastAccepted_ = op.ordinal;
                } else {
                    flushStaticGroup();
                    staticSelected_ = false;
                    if (stream_ || boundary_)
                        acceptStream(single(op));
                    else {
                        enqueueDirect(single(op));
                        lastAccepted_ = op.ordinal;
                    }
                }
            } else {
                if (op.kind == Kind::Control && op.controlByte == 32 && op.payload.size() == 4) {
                    uint32_t bits;
                    std::memcpy(&bits, op.payload.data(), 4);
                    if (bits == cycleMirror_) {
                        enqueueDirect(single(op));
                        ++streamCounters_.idempotentCycleWrites;
                        continue;
                    }
                }
                const uint32_t rows =
                    reo_gpu_static_group::TypedBuilder::rawRows(op, cycleMirror_, modeMirror_);
                if (staticSelected_ && rows) {
                    if (!staticBuilder_->room(rows) || staticHeld_.size() == MaxOperations ||
                        staticHeldBytes_ + op.payload.size() > MaxBatchBytes)
                        flushStaticGroup();
                    if (!staticBuilder_->raw(op, cycleMirror_, modeMirror_))
                        throw std::logic_error("Static typed raw admission changed");
                    staticHeld_.push_back(op);
                    staticHeldBytes_ += uint32_t(op.payload.size());
                    staticCounters_.rawRows += rows;
                } else {
                    flushStaticGroup();
                    if (stream_ || boundary_)
                        acceptStream(single(op));
                    else
                        enqueueDirect(single(op));
                    if (op.kind == Kind::Control && op.payload.size() == 4) {
                        uint32_t bits;
                        std::memcpy(&bits, op.payload.data(), 4);
                        if (op.controlByte == 32)
                            cycleMirror_ = bits;
                        if (op.controlByte == 36)
                            modeMirror_ = bits;
                    }
                }
            }
        }
    } catch (...) {
        failed_ = true;
        throw;
    }
}
