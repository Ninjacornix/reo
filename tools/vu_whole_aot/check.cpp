// Reuse the capture reader, real interpreter fixture and complete packet serializer.
#define main existingReplayMain
#include "../vu_nop_check/main.cpp"
#undef main
#include "vu_whole_program.h"
#include "reo_vu_whole_registered_generated.h"

int main(int argc, char** argv) try {
    if (argc != 3)
        throw std::runtime_error("Usage: check CAPTURES FRESH_OUTPUT");
    const fs::path out = argv[2];
    if (!out.parent_path().empty())
        fs::create_directories(out.parent_path());
    if (!fs::create_directory(out))
        throw std::runtime_error("Fresh output required");
    for (const char* key : {"REO_VU1_DUMP", "REO_VU1_TIMING_AT"})
        _putenv_s(key, "");
    const auto* table = reo_vu_whole_registered_generated::programTable();
    if (!vu_whole_program::registerProgramTable(table))
        throw std::runtime_error("Table registration refused");
    std::vector<fs::path> files;
    for (const auto& item : fs::directory_iterator(argv[1]))
        if (item.is_regular_file() && item.path().string().ends_with(".code.bin"))
            files.push_back(item.path());
    std::sort(files.begin(), files.end());
    if (files.empty())
        throw std::runtime_error("No snapshots");
    std::vector<Snapshot> snapshots;
    for (const auto& path : files) {
        auto prefix = path.string();
        prefix.resize(prefix.size() - 9);
        snapshots.push_back(load(prefix, path.stem().stem().string()));
    }
    Fixture baseline, candidate;
    uint64_t packets = 0, packetBytes = 0, selected = 0;
    for (const auto& s : snapshots) {
        vu_whole_program::registerProgramTable(nullptr);
        replay(baseline, s);
        vu_whole_program::registerProgramTable(table);
        VU1State initial;
        std::memcpy(&initial, s.state.data(), sizeof(initial));
        selected +=
            vu_whole_program::selectProgram(s.code.data(), 16384, s.data.data(), 16384, initial.pc,
                                            false, &candidate.vu.state()) != nullptr;
        replay(candidate, s);
        const bool equal =
            std::memcmp(&baseline.vu.state(), &candidate.vu.state(), sizeof(VU1State)) == 0 &&
            baseline.data == candidate.data &&
            baseline.memory.packets == candidate.memory.packets &&
            baseline.gs.packets == candidate.gs.packets;
        if (!equal) {
            save(out / (s.name + "-baseline.bin"), baseline);
            save(out / (s.name + "-candidate.bin"), candidate);
            throw std::runtime_error("State/data/GIF mismatch: " + s.name);
        }
        packets += candidate.memory.packets.size() + candidate.gs.packets.size();
        for (const auto* list : {&candidate.memory.packets, &candidate.gs.packets})
            for (const auto& packet : *list)
                packetBytes += packet.size();
    }
    if (selected != snapshots.size())
        throw std::runtime_error("One or more captures did not select the supplied table");
    std::vector<double> times[2];
    uint64_t checksum = 0;
    for (unsigned mode = 0; mode < 2; ++mode) {
        vu_whole_program::registerProgramTable(mode ? table : nullptr);
        for (unsigned round = 0; round < 5; ++round) {
            const auto start = std::chrono::steady_clock::now();
            for (const auto& s : snapshots) {
                replay(candidate, s);
                checksum += candidate.vu.state().pc + candidate.memory.packets.size();
            }
            times[mode].push_back(
                std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - start)
                    .count());
        }
    }
    std::ofstream receipt(out / "result.json");
    receipt << "{\"snapshots\":" << snapshots.size() << ",\"selected\":" << selected
            << ",\"stateBytes\":" << sizeof(VU1State)
            << ",\"dataBytes\":16384,\"packets\":" << packets << ",\"packetBytes\":" << packetBytes
            << ",\"checksum\":" << checksum;
    for (unsigned mode = 0; mode < 2; ++mode) {
        receipt << (mode ? ",\"candidateMs\":[" : ",\"baselineMs\":[");
        for (unsigned i = 0; i < times[mode].size(); ++i) {
            if (i)
                receipt << ',';
            receipt << times[mode][i];
        }
        receipt << ']';
    }
    receipt << "}\n";
    if (!receipt)
        throw std::runtime_error("Cannot write result");
    std::printf("PASS snapshots=%zu selected=%llu stateBytes=%zu dataBytes=16384 packets=%llu "
                "packetBytes=%llu\n",
                snapshots.size(), selected, sizeof(VU1State), packets, packetBytes);
    return 0;
} catch (const std::exception& e) {
    std::fprintf(stderr, "FAIL %s\n", e.what());
    return 1;
}
