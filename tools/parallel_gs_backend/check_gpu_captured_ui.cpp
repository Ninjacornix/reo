// Offline qualification of the selected literal-source-guarded UI kernels.
// Candidate capability bits below apply to this isolated fixture only. This
// executable neither modifies the live catalogue nor certifies fresh entries
// which were not actually present in the captured corpus.
#define main previous_backend_check_main
#include "check.cpp"
#undef main
#include <sstream>

static std::vector<uint8_t> uiBytes(const fs::path& p, size_t size = 0) {
    std::ifstream f(p, std::ios::binary);
    CHECK(bool(f));
    std::vector<uint8_t> b{std::istreambuf_iterator<char>(f), {}};
    CHECK(size ? b.size() == size : !b.empty());
    return b;
}
int main(int argc, char** argv) try {
    CHECK(argc == 5);
    const fs::path assets = argv[1], cases = argv[2], out = argv[3];
    CHECK(!fs::exists(out));
    fs::create_directories(out);
    Util::register_thread_index(0);
    auto bootstrap = reo_gpu_catalog::build(assets, reo_gpu_enrollment_selected::assets(),
                                            reo_gpu_enrollment_selected::proofs());
    std::ifstream list(cases);
    CHECK(bool(list));
    std::ofstream report(out / "cases.tsv");
    report << "case\timage\tPC\tresume\tstatus\tevents\tchangedBytes\tresult\n";
    std::string line;
    unsigned passed = 0;
    while (std::getline(list, line)) {
        if (!line.empty() && line.back() == '\r')
            line.pop_back();
        if (line.empty())
            continue;
        std::istringstream fields(line);
        std::array<std::string, 8> v;
        for (auto& value : v)
            CHECK(bool(std::getline(fields, value, '\t')));
        unsigned index = 8;
        for (unsigned i : {1u, 6u, 7u})
            if (v[2] == reo_gpu_catalog::imageSpecs()[i].digest)
                index = i;
        if (index == 8)
            continue;
        const auto folder = fs::path(v[0]);
        const uint32_t pc = uint32_t(std::stoul(v[3])), top = uint32_t(std::stoul(v[4])),
                       itop = uint32_t(std::stoul(v[5]));
        const bool resume = std::stoul(v[6]) != 0;
        const unsigned packetCount = unsigned(std::stoul(v[7]));
        const auto state = uiBytes(folder / "input.state.bin", 632),
                   data = uiBytes(folder / "input.data.bin", 16384);
        CHECK(reo_gpu_catalog::sha256(uiBytes(folder / "input.code.bin", 16384)) == v[2]);
        auto program =
            std::make_shared<reo_resident_live::Program>(*bootstrap.registry->programs.at(index));
        program->completeSetup = program->completeGeometry = program->completeClipping =
            program->completeCarry = program->orderedEffects = program->exactTermination = true;
        program->canResume = true;
        program->literalSourcePreserved = true;
        reo_resident_live::ArrayShaderBundle shaders{};
        shaders.whole2ea = bootstrap.shaders.whole2ea;
        shaders.whole2eaBinding = bootstrap.shaders.whole2eaBinding;
        shaders.programs = bootstrap.shaders.programs;
        for (auto& module : shaders.programs)
            if (module.bindingId == program->bindingId) {
                module.canResume = true;
                module.freshLiteralSourcePreserved = true;
                module.resumeLiteralSourcePreserved = true;
            }
        shaders.strip = bootstrap.shaders.strip;
        shaders.unpack = bootstrap.shaders.unpack;
        shaders.effectValidate = bootstrap.shaders.effectValidate;
        shaders.bytePatch = bootstrap.shaders.bytePatch;
        shaders.pooledTail = reo_gpu_catalog::readSpirv(
            assets, {"multi-effect/pooled_tail.spv",
                     "d6573a4179e53b87959ddaf0aa280b7da0d5302e68051e40758725536135e344"});
        Config config;
        config.validatedDrawing = true;
        config.residentGeometry =
            reo_resident_live::makeArrayResidentOwnerConfig(std::move(shaders));
        config.residentGeometry.enabled = true;
        config.residentGeometry.fullProtocolCoverage = bootstrap.owner.fullProtocolCoverage;
        config.persistentPipelineCache = true;
        config.pipelineCacheFile = argv[4];
        config.publishPrivilegedReset = [](const Privileged&) {};
        config.publishStatusAck = [](uint64_t) {};
        std::vector<uint8_t> initial(VramSize, 0x80u);
        std::fill(initial.begin(), initial.begin() + 512u * 448u * 4u, 0u);
        Init init;
        init.vram = initial.data();
        init.vramSize = initial.size();
        init.registers = display();
        std::string reason;
        auto backend = makeFactory(config)();
        if (!backend->init(init, reason)) {
            std::cerr << "UI fixture backend init: " << reason << "\n";
            CHECK(false);
        }
        setup(*backend);
        const uint64_t texture =
            0x3c00ull | (1ull << 14) | (6ull << 26) | (6ull << 30) | (1ull << 34);
        backend->directRegister(6, texture);
        backend->directRegister(7, texture);
        const uint64_t viewport = 0x7000ull | (0x7200ull << 32);
        backend->directRegister(0x18, viewport);
        backend->directRegister(0x19, viewport);
        reo_resident_live::Handoff bank{};
        bank.epoch = 1;
        bank.bankGeneration = 1;
        bank.cycle = 0x0404;
        std::memcpy(bank.state.data(), state.data(), 632);
        std::memcpy(bank.data.data(), data.data(), 16384);
        backend->residentImportHandoff(bank);
        reo_resident_live::Operation op;
        op.kind = reo_resident_live::Kind::Launch;
        op.program = program;
        op.ordinal = 1;
        op.codeGeneration = 1;
        op.startPC = pc;
        op.resume = resume;
        op.top = top;
        op.itop = itop;
        if (resume || pc != 0u) {
            uint32_t tag[4]{};
            std::memcpy(tag, data.data() + ((top + 1u) & 1023u) * 16u, 16);
            CHECK((tag[0] & 0xffff8000u) == 32768u && ((tag[1] >> 26u) & 3u) == 0u);
            const uint32_t nreg = (tag[1] >> 28u) & 15u;
            if (nreg == 3u && tag[2] == 0x412u) {
                op.effect.type = reo_resident_live::LiteralEffect::Type::Strip;
                op.effect.vertexCapacity = 256;
                op.effect.echo[0] = 1;
                op.effect.echo[1] = 256;
                op.effect.echo[2] = (tag[1] >> 15u) & 2047u;
                std::memcpy(op.effect.echo.data() + 4, tag, 16);
            } else {
                CHECK(nreg == 1u && tag[2] == 14u && (tag[0] & 32767u) == 6u);
                op.effect.type = reo_resident_live::LiteralEffect::Type::MaterialAD;
                op.effect.echo[0] = 2;
                op.effect.echo[1] = 6;
                for (unsigned q = 0; q < 7; ++q)
                    std::memcpy(op.effect.echo.data() + 4 + q * 4,
                                data.data() + ((top + 1u + q) & 1023u) * 16u, 16);
            }
        }
        reo_resident_live::Batch batch;
        batch.epoch = 1;
        batch.bankGeneration = 1;
        batch.operations.push_back(op);
        backend->residentEnqueue(batch);
        const auto receipts =
            backend->residentRetire(reo_resident_live::Barrier::DmaComplete, 1, 1);
        CHECK(receipts.size() == 1);
        const auto& receipt = receipts[0];
        CHECK(receipt.status == 0 && receipt.ended && receipt.eventCount == packetCount);
        reo_resident_live::Handoff final{};
        final.epoch = 1;
        final.bankGeneration = 1;
        backend->residentExportHandoff(final);
        const auto expectedState = uiBytes(folder / "original/vu_final_state.bin", 632),
                   expectedData = uiBytes(folder / "original/vu_final_data.bin", 16384);
        CHECK(std::equal(final.state.begin(), final.state.end(), expectedState.begin()));
        CHECK(std::equal(final.data.begin(), final.data.end(), expectedData.begin()));
        Config plain = config;
        plain.residentGeometry = {};
        plain.pipelineCacheFile = (out / "reference.cache").string();
        auto ordinary = makeFactory(plain)();
        CHECK(ordinary->init(init, reason));
        setup(*ordinary);
        ordinary->directRegister(6, texture);
        ordinary->directRegister(7, texture);
        ordinary->directRegister(0x18, viewport);
        ordinary->directRegister(0x19, viewport);
        for (unsigned i = 0; i < packetCount; ++i) {
            char name[40];
            std::snprintf(name, sizeof(name), "vu_gif_%04u.bin", i);
            const auto packet = uiBytes(folder / "original" / name);
            ordinary->rawGif(1, packet.data(), packet.size());
        }
        std::vector<uint8_t> actual(VramSize), expected(VramSize);
        backend->exportVram(0, actual.data(), actual.size());
        ordinary->exportVram(0, expected.data(), expected.size());
        CHECK(actual == expected);
        size_t changed = 0;
        for (size_t i = 0; i < initial.size(); ++i)
            changed += expected[i] != initial[i];
        report << folder.filename().string() << '\t' << v[2] << '\t' << pc << '\t' << resume << '\t'
               << receipt.status << '\t' << receipt.eventCount << '\t' << changed
               << "\tPASS_COMPONENT_NOT_ADMISSION\n";
        report.flush();
        ordinary->close();
        backend->close();
        ++passed;
    }
    CHECK(passed > 0);
    std::cout << "PASS captured UI cases=" << passed << " checks=" << checks << "\n";
    return 0;
} catch (const std::exception& e) {
    std::cerr << "FAIL captured UI: " << e.what() << "\n";
    return 1;
}
