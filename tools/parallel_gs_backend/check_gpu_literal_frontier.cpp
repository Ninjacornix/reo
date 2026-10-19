// Regression for real retained ordinal15894: MSCNT at528 emits a literal strip
// and ends at128. Packet type alone must not select the main-body consumer.
#define main previous_backend_check_main
#include "check.cpp"
#undef main

static std::vector<uint8_t> frontierBytes(const fs::path& path, size_t size = 0) {
    std::ifstream file(path, std::ios::binary);
    CHECK(bool(file));
    std::vector<uint8_t> bytes{std::istreambuf_iterator<char>(file), {}};
    CHECK(size ? bytes.size() == size : !bytes.empty());
    return bytes;
}
int main(int argc, char** argv) try {
    const bool visible = std::getenv("REO_CHECK_VISIBLE_GEOMETRY") &&
                         std::atoi(std::getenv("REO_CHECK_VISIBLE_GEOMETRY")) != 0;
    CHECK(argc == 5 || argc == 6);
    const bool sequence = argc == 6;
    const fs::path assets = argv[1], reference = argv[2], out = argv[3];
    CHECK(!fs::exists(out));
    fs::create_directories(out);
    Util::register_thread_index(0);
    auto bootstrap = reo_gpu_catalog::build(assets, reo_gpu_enrollment_selected::assets(),
                                            reo_gpu_enrollment_selected::proofs());
    reo_gpu_catalog::configureStaticIncremental(bootstrap, assets);
    Config config;
    config.validatedDrawing = true;
    config.residentGeometry = bootstrap.owner;
    config.persistentPipelineCache = true;
    config.pipelineCacheFile = argv[4];
    config.publishPrivilegedReset = [](const Privileged&) {};
    config.publishStatusAck = [](uint64_t) {};
    auto backend = makeFactory(config)();
    std::vector<uint8_t> initial(VramSize);
    if (visible)
        std::fill(initial.begin() + 0x3c0000u, initial.begin() + 0x3c4000u, 0x80u);
    Init init;
    init.vram = initial.data();
    init.vramSize = initial.size();
    init.registers = display();
    std::string reason;
    CHECK(backend->init(init, reason));
    setup(*backend);
    const uint64_t texture = 0x3c00ull | (1ull << 14) | (6ull << 26) | (6ull << 30) | (1ull << 34);
    backend->directRegister(6, texture);
    backend->directRegister(7, texture);
    const uint64_t viewport = 0x7000ull | (0x7200ull << 32);
    if (visible) {
        backend->directRegister(0x18, viewport);
        backend->directRegister(0x19, viewport);
    }
    const auto state = frontierBytes(reference / "input.state.bin", 632),
               data = frontierBytes(reference / "input.data.bin", 16384),
               meta = frontierBytes(reference / "input.meta.bin", 40);
    unsigned packetCount = 0;
    {
        std::ifstream list(reference / "original/vu_gif_packets.jsonl");
        CHECK(bool(list));
        std::string line;
        while (std::getline(list, line))
            if (!line.empty())
                ++packetCount;
    }
    CHECK(packetCount > 0);
    uint32_t pc = 0, top = 0, itop = 0;
    std::memcpy(&pc, state.data() + 604, 4);
    std::memcpy(&top, meta.data() + 20, 4);
    std::memcpy(&itop, meta.data() + 28, 4);
    CHECK(pc == 0x528u);
    reo_resident_live::Handoff handoff{};
    handoff.epoch = 1;
    handoff.bankGeneration = 1;
    handoff.cycle = 0x0404;
    std::memcpy(handoff.state.data(), state.data(), 632);
    std::memcpy(handoff.data.data(), data.data(), 16384);
    if (sequence) {
        const fs::path first = argv[5];
        const auto firstState = frontierBytes(first / "input.state.bin", 632),
                   firstData = frontierBytes(first / "input.data.bin", 16384),
                   firstFinal = frontierBytes(first / "original/vu_final_state.bin", 632);
        CHECK(state == firstFinal);
        std::memcpy(handoff.state.data(), firstState.data(), 632);
        std::memcpy(handoff.data.data(), firstData.data(), 16384);
        backend->residentImportHandoff(handoff);
        reo_resident_live::Operation body;
        body.kind = reo_resident_live::Kind::Launch;
        body.program = bootstrap.registry->programs.at(2);
        body.ordinal = 1;
        body.codeGeneration = 1;
        body.resume = true;
        body.top = 469;
        body.effect.type = reo_resident_live::LiteralEffect::Type::Strip;
        body.effect.vertexCapacity = 256;
        body.effect.echo[0] = 1;
        body.effect.echo[1] = 256;
        std::memcpy(body.effect.echo.data() + 4, firstData.data() + 470u * 16u, 16);
        body.effect.echo[2] = (body.effect.echo[5] >> 15u) & 2047u;
        reo_resident_live::Batch firstBatch;
        firstBatch.epoch = 1;
        firstBatch.bankGeneration = 1;
        firstBatch.operations.push_back(body);
        backend->residentEnqueue(firstBatch);
        // Keep the first GPU state bank. Only raw data upload commands follow;
        // no state re-import, no PC write and no CPU numerical execution.
    } else
        backend->residentImportHandoff(handoff);
    reo_resident_live::Operation op;
    op.kind = reo_resident_live::Kind::Launch;
    op.program = bootstrap.registry->programs.at(2);
    op.ordinal = 1;
    op.codeGeneration = 1;
    op.resume = true;
    op.startPC = 0;
    op.top = top;
    op.itop = itop;
    op.effect.type = reo_resident_live::LiteralEffect::Type::Strip;
    op.effect.vertexCapacity = 256;
    op.effect.echo[0] = 1;
    op.effect.echo[1] = 256;
    std::memcpy(op.effect.echo.data() + 4, data.data() + ((top + 1u) & 1023u) * 16u, 16);
    op.effect.echo[2] = (op.effect.echo[5] >> 15u) & 2047u;
    reo_resident_live::Batch batch;
    batch.epoch = 1;
    batch.bankGeneration = 1;
    if (sequence) {
        op.ordinal = 2;
        for (uint32_t offset = 0; offset < 16384; offset += 4096) {
            reo_resident_live::Operation upload;
            upload.kind = reo_resident_live::Kind::DataWrite;
            upload.controlByte = offset;
            upload.payload.assign(data.begin() + offset, data.begin() + offset + 4096);
            batch.payloadBytes += 4096;
            batch.operations.push_back(std::move(upload));
        }
    }
    batch.operations.push_back(op);
    backend->residentEnqueue(batch);
    auto receipts = backend->residentRetire(reo_resident_live::Barrier::DmaComplete, 1, 1);
    CHECK(receipts.size() == (sequence ? 2u : 1u));
    if (sequence)
        CHECK(receipts[0].status == 0 && receipts[0].ended && receipts[0].eventCount == 9);
    CHECK(receipts.back().status == 0 && receipts.back().ended &&
          receipts.back().eventCount == packetCount);
    // Polling an already retired VU prefix must produce no new completions.
    CHECK(backend->residentRetire(reo_resident_live::Barrier::GuestRead, 1, 1).empty());
    CHECK(backend->residentRetire(reo_resident_live::Barrier::GuestRead, 1, 1).empty());
    reo_resident_live::Handoff result{};
    result.epoch = 1;
    result.bankGeneration = 1;
    backend->residentExportHandoff(result);
    // Preserve failing numerical output as well as passing receipts.
    const auto save = [&](const char* name, const void* bytes, size_t size) {
        const auto path = out / name;
        CHECK(!fs::exists(path));
        std::ofstream file(path, std::ios::binary);
        file.write(static_cast<const char*>(bytes), size);
        CHECK(bool(file));
    };
    save("gpu-final-state.bin", result.state.data(), result.state.size());
    save("gpu-final-data.bin", result.data.data(), result.data.size());
    const auto finalState = frontierBytes(reference / "original/vu_final_state.bin", 632),
               finalData = frontierBytes(reference / "original/vu_final_data.bin", 16384);
    CHECK(std::equal(result.state.begin(), result.state.end(), finalState.begin()));
    CHECK(std::equal(result.data.begin(), result.data.end(), finalData.begin()));
    uint32_t finalPC = 0, expectedPC = 0;
    std::memcpy(&finalPC, result.state.data() + 604, 4);
    std::memcpy(&expectedPC, finalState.data() + 604, 4);
    CHECK(finalPC == expectedPC);
    // A prefix containing only a raw VIF bank write is DIRTY despite having
    // zero launches. Its real retirement must remain observable in the bank.
    reo_resident_live::Batch upload;
    upload.epoch = 1;
    upload.bankGeneration = 1;
    reo_resident_live::Operation write;
    write.kind = reo_resident_live::Kind::DataWrite;
    write.controlByte = 0;
    write.payload.assign(finalData.begin(), finalData.begin() + 4);
    write.payload[0] ^= 1u;
    upload.payloadBytes = 4;
    upload.operations.push_back(write);
    backend->residentEnqueue(upload);
    CHECK(backend->residentRetire(reo_resident_live::Barrier::DmaComplete, 1, 1).empty());
    reo_resident_live::Handoff written{};
    written.epoch = 1;
    written.bankGeneration = 1;
    backend->residentExportHandoff(written);
    CHECK(written.state == result.state);
    auto changedData = result.data;
    changedData[0] ^= 1u;
    CHECK(written.data == changedData);
    Config plain = config;
    plain.residentGeometry = {};
    plain.pipelineCacheFile = (out / "reference.cache").string();
    auto ordinary = makeFactory(plain)();
    CHECK(ordinary->init(init, reason));
    setup(*ordinary);
    ordinary->directRegister(6, texture);
    ordinary->directRegister(7, texture);
    if (visible) {
        ordinary->directRegister(0x18, viewport);
        ordinary->directRegister(0x19, viewport);
    }
    if (sequence) {
        for (unsigned index = 0; index < 9; ++index) {
            char name[40];
            std::snprintf(name, sizeof(name), "vu_gif_%04u.bin", index);
            const auto packet = frontierBytes(fs::path(argv[5]) / "original" / name);
            ordinary->rawGif(1, packet.data(), packet.size());
        }
    }
    for (unsigned index = 0; index < packetCount; ++index) {
        char name[40];
        std::snprintf(name, sizeof(name), "vu_gif_%04u.bin", index);
        const auto packet = frontierBytes(reference / "original" / name);
        ordinary->rawGif(1, packet.data(), packet.size());
    }
    std::vector<uint8_t> rendered(VramSize), expected(VramSize);
    backend->exportVram(0, rendered.data(), rendered.size());
    ordinary->exportVram(0, expected.data(), expected.size());
    CHECK(rendered == expected);
    size_t changedBytes = 0;
    for (size_t i = 0; i < initial.size(); ++i)
        changedBytes += expected[i] != initial[i];
    if (visible && sequence)
        CHECK(changedBytes > 0);
    std::cout << "visible=" << visible << " changed_vram_bytes=" << changedBytes << "\n";
    ordinary->close();
    backend->close();
    std::ofstream report(out / "result.json");
    report << "{\"status\":\"PASS\",\"scope\":\"actual GPU control-dependent "
              "continuation\",\"preceding_body_no_state_reimport\":"
           << (sequence ? "true" : "false") << ",\"inputPC\":1320,\"outputPC\":" << finalPC
           << ",\"events\":" << packetCount
           << ",\"visible_fixture\":" << (visible ? "true" : "false")
           << ",\"changed_vram_bytes\":" << changedBytes
           << ",\"full_state_bytes\":632,\"full_data_bytes\":16384,\"full_vram_bytes\":4194304,"
              "\"checks\":"
           << checks << "}\n";
    CHECK(bool(report));
    std::cout << "PASS literal frontier checks=" << checks << "\n";
    return 0;
} catch (const std::exception& error) {
    std::cerr << "FAIL literal frontier: " << error.what() << "\n";
    return 1;
}
