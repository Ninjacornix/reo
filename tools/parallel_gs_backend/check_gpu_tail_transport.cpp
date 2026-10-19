// Real GPU-produced queue followed by ordinary, non-vertex GIF traffic.
#define main previous_backend_check_main
#include "check.cpp"
#undef main

static std::vector<uint8_t> retainedBytes(const fs::path& path, size_t size) {
    std::ifstream file(path, std::ios::binary);
    std::vector<uint8_t> bytes{std::istreambuf_iterator<char>(file), {}};
    CHECK(bytes.size() == size);
    return bytes;
}

int main(int argc, char** argv) try {
    CHECK(argc == 5); // ASSETS RETAINED672_REFERENCE NEW_OUT PRIVATE_CACHE
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
    Init init;
    init.vram = initial.data();
    init.vramSize = initial.size();
    init.registers = display();
    std::string reason;
    CHECK(backend->init(init, reason));
    setup(*backend);
    // A real disjoint texture domain, matching the producer's textured PRIM.
    // Default TEX0 would alias the framebuffer and is correctly refused.
    const uint64_t texture = 0x3c00ull | (1ull << 14) | (6ull << 26) | (6ull << 30) | (1ull << 34);
    backend->directRegister(6, texture);
    backend->directRegister(7, texture);
    const auto state = retainedBytes(reference / "input.state.bin", 632);
    const auto data = retainedBytes(reference / "input.data.bin", 16384);
    const auto echo = retainedBytes(reference / "input.echo.bin", 128);
    reo_resident_live::Handoff handoff{};
    handoff.epoch = 1;
    handoff.bankGeneration = 1;
    std::memcpy(handoff.state.data(), state.data(), 632);
    std::memcpy(handoff.data.data(), data.data(), 16384);
    handoff.cycle = 0x0404;
    backend->residentImportHandoff(handoff);
    reo_resident_live::Batch batch;
    batch.epoch = 1;
    batch.bankGeneration = 1;
    reo_resident_live::Operation op;
    op.kind = reo_resident_live::Kind::Launch;
    op.program = bootstrap.registry->programs.at(2);
    op.ordinal = 1;
    op.codeGeneration = 1;
    op.startPC = 0;
    op.resume = true;
    op.top = 469;
    op.itop = 0;
    op.effect.type = reo_resident_live::LiteralEffect::Type::Strip;
    std::memcpy(op.effect.echo.data(), echo.data(), 128);
    op.effect.vertexCapacity = op.effect.echo[4] & 32767u;
    batch.operations.push_back(op);
    backend->residentEnqueue(batch);
    auto receipts = backend->residentRetire(reo_resident_live::Barrier::DmaComplete, 1, 1);
    CHECK(receipts.size() == 1 && receipts[0].status == 0 && receipts[0].ended &&
          receipts[0].eventCount == 9);
    reo_resident_live::Handoff result;
    result.epoch = 1;
    result.bankGeneration = 1;
    backend->residentExportHandoff(result);
    CHECK(std::equal(result.state.begin(), result.state.end(),
                     retainedBytes(reference / "original/vu_final_state.bin", 632).begin()));
    CHECK(std::equal(result.data.begin(), result.data.end(),
                     retainedBytes(reference / "original/vu_final_data.bin", 16384).begin()));

    // Independent ordinary-GIF reference, using all nine original packets.
    Config referenceConfig = config;
    referenceConfig.residentGeometry = {};
    referenceConfig.pipelineCacheFile = (out / "reference.cache").string();
    auto ordinary = makeFactory(referenceConfig)();
    CHECK(ordinary->init(init, reason));
    setup(*ordinary);
    ordinary->directRegister(6, texture);
    ordinary->directRegister(7, texture);
    for (unsigned index = 0; index < 9; ++index) {
        char name[64];
        std::snprintf(name, sizeof(name), "vu_gif_%04u.bin", index);
        std::ifstream file(reference / "original" / name, std::ios::binary);
        const std::vector<uint8_t> raw{std::istreambuf_iterator<char>(file), {}};
        CHECK(!raw.empty() && raw.size() % 16 == 0);
        ordinary->rawGif(1, raw.data(), raw.size());
    }
    // A complete 64-bit host-to-local transfer. IMAGE padding is transport,
    // not vertex input; use two pixels so the upstream transfer is nonempty.
    constexpr uint32_t destination = 240u * 256u, colour = 0xff336699u;
    backend->directRegister(0x50, (240ull << 32) | (1ull << 48));
    backend->directRegister(0x51, 0);
    backend->directRegister(0x52, 2ull | (1ull << 32));
    backend->directRegister(0x53, 0);
    ordinary->directRegister(0x50, (240ull << 32) | (1ull << 48));
    ordinary->directRegister(0x51, 0);
    ordinary->directRegister(0x52, 2ull | (1ull << 32));
    ordinary->directRegister(0x53, 0);
    std::vector<uint8_t> before(VramSize), after(VramSize), referenceBefore(VramSize),
        referenceAfter(VramSize);
    backend->exportVram(0, before.data(), before.size());
    ordinary->exportVram(0, referenceBefore.data(), referenceBefore.size());
    const std::vector<uint64_t> image{1ull | (1ull << 15) | (2ull << 58), 0, colour, 0};
    gif(*backend, 3, image);
    backend->exportVram(0, after.data(), after.size());
    gif(*ordinary, 3, image);
    ordinary->exportVram(0, referenceAfter.data(), referenceAfter.size());
    const auto save = [&](const char* name, const std::vector<uint8_t>& bytes) {
        std::ofstream file(out / name, std::ios::binary);
        file.write(reinterpret_cast<const char*>(bytes.data()), bytes.size());
        CHECK(bool(file));
    };
    save("GPU.before.bin", before);
    save("GPU.after.bin", after);
    save("reference.before.bin", referenceBefore);
    save("reference.after.bin", referenceAfter);
    CHECK(before == referenceBefore);
    CHECK(after == referenceAfter);
    uint32_t actualPixel = 0;
    std::memcpy(&actualPixel, after.data() + destination, 4);
    CHECK(actualPixel == colour);
    // Non-PRE attribute-only packed traffic must also preserve the queue.
    const std::vector<uint64_t> rgba{1ull | (1ull << 15) | (1ull << 60), 1, 0x8000000080ull,
                                     0x8000000080ull};
    gif(*backend, 1, rgba);
    bool guarded = false;
    try {
        backend->directRegister(5, 0);
    } catch (const std::exception& error) {
        guarded = std::string(error.what()).find("empty CPU shadow of the GPU queue") !=
                  std::string::npos;
    }
    CHECK(guarded); // No silent queue reset or CPU shadow consumption.
    const auto nextTail = [&] {
        backend->residentImportHandoff(handoff);
        ++batch.operations.front().ordinal;
        backend->residentEnqueue(batch);
        const auto retired = backend->residentRetire(reo_resident_live::Barrier::DmaComplete, 1, 1);
        CHECK(retired.size() == 1 && retired[0].status == 0 && retired[0].ended &&
              retired[0].eventCount == 9);
        for (unsigned index = 0; index < 9; ++index) {
            char name[64];
            std::snprintf(name, sizeof(name), "vu_gif_%04u.bin", index);
            std::ifstream file(reference / "original" / name, std::ios::binary);
            const std::vector<uint8_t> raw{std::istreambuf_iterator<char>(file), {}};
            ordinary->rawGif(1, raw.data(), raw.size());
        }
    };
    const auto reglist = [&](Backend& target, uint64_t address, uint64_t value) {
        gif(target, 1, {1ull | (1ull << 15) | (1ull << 58) | (1ull << 60), address, value, 0});
    };
    nextTail();
    // REGLIST calls the register handler directly, bypassing write_register().
    // Its real 64-bit colour/Q overwrite must release the GPU register lease.
    const uint64_t literalColour = 0x80808080ull | (0x3f800000ull << 32);
    reglist(*backend, 1, literalColour);
    reglist(*ordinary, 1, literalColour);
    backend->directRegister(0, 0);
    ordinary->directRegister(0, 0); // Actual PRIM reset.
    backend->directRegister(5, 0);
    ordinary->directRegister(5, 0);
    nextTail();
    // The same rule applies to a real 64-bit S/T overwrite; Q remains governed
    // by the original nonempty-header and RGBAQ semantics.
    reglist(*backend, 2, 0x3f8000003f800000ull);
    reglist(*ordinary, 2, 0x3f8000003f800000ull);
    reglist(*backend, 1, literalColour);
    reglist(*ordinary, 1, literalColour);
    backend->directRegister(0, 16);
    ordinary->directRegister(0, 16); // Textured point, ST mode.
    backend->directRegister(5, 16);
    ordinary->directRegister(5, 16);
    backend->exportVram(0, after.data(), after.size());
    ordinary->exportVram(0, referenceAfter.data(), referenceAfter.size());
    save("GPU.after-reglist.bin", after);
    save("reference.after-reglist.bin", referenceAfter);
    CHECK(after == referenceAfter);
    ordinary->close();
    backend->close();
    std::ofstream report(out / "result.json");
    report << "{\"status\":\"PASS\",\"checks\":" << checks
           << ",\"real_gpu\":true,\"original_packets\":9,"
              "\"full_state_bytes\":632,\"full_data_bytes\":16384,\"full_vram_bytes\":4194304,"
              "\"image_and_attribute_traffic_preserve_gpu_queue\":true,\"ordinary_vertex_still_"
              "refused\":true,"
              "\"reglist_rgbaq_and_st_overwrites_release_register_ownership\":true}\n";
    CHECK(bool(report));
    std::cout << "PASS GPU tail transport checks=" << checks << "\n";
    return 0;
} catch (const std::exception& error) {
    std::cerr << "FAIL GPU tail transport: " << error.what() << "\n";
    return 1;
}
