#include "runtime/ps2_vu1.h"
#if defined(REO_VU_ISOLATED_RUNTIME_STUBS)
#include "vu_isolated_runtime_hooks.h"
#endif
#include "runtime/ps2_gs_gpu.h"
#include "runtime/ps2_memory.h"
#include <array>
#include <algorithm>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace fs = std::filesystem;
static unsigned checks = 0, failures = 0;
static void check(bool value, const char* name) {
    ++checks;
    failures += !value;
    std::printf("%s %s\n", value ? "PASS" : "FAIL", name);
}
static std::vector<uint8_t> read(const fs::path& file) {
    std::ifstream input(file, std::ios::binary);
    if (!input)
        throw std::runtime_error("Cannot read " + file.string());
    return {std::istreambuf_iterator<char>(input), std::istreambuf_iterator<char>()};
}
struct Fixture {
    VU1Interpreter vu;
    GS gs;
    PS2Memory memory;
    std::array<uint8_t, 16384> code{}, data{};
    void pair(unsigned pc, uint32_t lower, uint32_t upper = 0x000002FFu) {
        std::memcpy(code.data() + pc, &lower, 4);
        std::memcpy(code.data() + pc + 4, &upper, 4);
    }
    void run(unsigned cycles = 1, unsigned pc = 0) {
        vu.execute(code.data(), code.size(), data.data(), data.size(), gs, &memory, pc, 0, cycles);
    }
};
static void writeBytes(std::ofstream& out, const void* ptr, size_t size) {
    out.write(static_cast<const char*>(ptr), size);
}
static void save(const fs::path& file, const Fixture& f) {
    std::ofstream out(file, std::ios::binary | std::ios::trunc);
    const uint32_t header[] = {0x504F4E56u,
                               1,
                               uint32_t(sizeof(VU1State)),
                               uint32_t(f.data.size()),
                               uint32_t(f.memory.packets.size()),
                               uint32_t(f.gs.packets.size())};
    writeBytes(out, header, sizeof(header));
    writeBytes(out, &f.vu.state(), sizeof(VU1State));
    writeBytes(out, f.data.data(), f.data.size());
    for (const auto* list : {&f.memory.packets, &f.gs.packets})
        for (const auto& packet : *list) {
            const uint32_t size = uint32_t(packet.size());
            writeBytes(out, &size, sizeof(size));
            writeBytes(out, packet.data(), packet.size());
        }
    if (!out)
        throw std::runtime_error("Cannot write " + file.string());
}
static void fixtures(const fs::path& out) {
    {
        Fixture f;
        f.pair(0, 0x8000033C);
        f.vu.state().vi[0] = 123;
        f.vu.state().vf[0][0] = 19;
        f.vu.state().vf[7][2] = 42;
        f.vu.state().clip = 0xABCD;
        f.run();
        check(f.vu.state().vf[7][2] == 42 && f.vu.state().clip == 0xABCD && f.vu.state().pc == 8,
              "canonical lower/upper NOP preserve operands and advance PC");
        check(f.vu.state().vi[0] == 0 && f.vu.state().vf[0][0] == 0 && f.vu.state().vf[0][3] == 1,
              "NOP pair still enforces zero-register invariants");
        save(out / "fixture-canonical.bin", f);
    }
    {
        Fixture f;
        f.vu.state().vf[2][0] = 4;
        f.vu.state().i = 2;
        const uint32_t addi = (8u << 21) | (2u << 11) | (3u << 6) | 0x22u;
        f.pair(0, 0x40400000u, 0x80000000u | addi); // Literal 3; upper reads old I=2.
        f.pair(8, 0x8000033Cu, (8u << 21) | (2u << 11) | (4u << 6) | 0x22u);
        f.run(2);
        check(f.vu.state().vf[3][0] == 6 && f.vu.state().vf[4][0] == 7 && f.vu.state().i == 3,
              "I flag retains old-I arithmetic then lower literal assignment");
        save(out / "fixture-literal-arithmetic.bin", f);
    }
    {
        Fixture f;
        f.pair(0, 0x8000033Cu, 0x800002FFu);
        f.run();
        uint32_t bits;
        std::memcpy(&bits, &f.vu.state().i, 4);
        check(bits == 0x8000033Cu, "NOP upper with I flag treats canonical lower word as literal");
        save(out / "fixture-literal-nop.bin", f);
    }
    {
        Fixture f;
        f.pair(0, 0x8000033Cu, 0x400002FFu);
        f.pair(8, 0x10010001u);
        f.pair(16, 0x10020001u, 0x400002FFu);
        f.pair(24, 0x8000033Cu);
        f.run(10);
        check(f.vu.state().pc == 16 && f.vu.state().vi[1] == 1 && f.vu.state().vi[2] == 0,
              "NOP E flag retains its one-pair delay and resume PC");
        save(out / "fixture-e-before-resume.bin", f);
        f.vu.resume(f.code.data(), f.code.size(), f.data.data(), f.data.size(), f.gs, &f.memory, 3,
                    10);
        check(f.vu.state().pc == 32 && f.vu.state().vi[2] == 1 && f.vu.state().itop == 3,
              "resume continues preserved PC through next E delay");
        save(out / "fixture-e-after-resume.bin", f);
    }
    {
        Fixture f;
        f.pair(0, 0x40000002u);
        f.pair(8, 0x10010001u);
        f.pair(16, 0x10020001u);
        f.pair(24, 0x10030001u);
        f.run(3);
        check(f.vu.state().vi[1] == 1 && f.vu.state().vi[2] == 0 && f.vu.state().vi[3] == 1,
              "NOP upper retains lower branch and delay pair");
        save(out / "fixture-branch.bin", f);
    }
    {
        Fixture f;
        f.pair(0, 0x8000033Cu, 0x7FFFFAFFu); // Same NOP row with unused fields/flags.
        f.run();
        check(f.vu.state().ebit && f.vu.state().pc == 8,
              "upper NOP decode ignores unused fields while preserving E flag");
        save(out / "fixture-nop-unused-fields.bin", f);
    }
    {
        Fixture f;
        f.pair(0, 0x8000033Cu);
        f.run();
        f.pair(0, 0x10010001u);
        f.run();
        check(f.vu.state().vi[1] == 1, "same-pointer code mutation replaces NOP with IADDIU");
        f.vu.state().vf[2][0] = 4;
        f.vu.state().vf[3][0] = 5;
        f.pair(0, 0x8000033Cu, (8u << 21) | (3u << 16) | (2u << 11) | (4u << 6) | 0x28u);
        f.run();
        check(f.vu.state().vf[4][0] == 9, "same-pointer upper code mutation executes arithmetic");
        f.pair(0, 0x8000033Cu);
        f.run();
        check(f.vu.state().vf[4][0] == 9, "same-pointer mutation back to NOP retains prior result");
        save(out / "fixture-code-mutation.bin", f);
    }
}
struct Snapshot {
    std::string name;
    std::array<uint8_t, 16384> code{}, data{};
    std::array<uint8_t, sizeof(VU1State)> state{};
    std::array<uint32_t, 10> meta{};
};
static Snapshot load(const fs::path& prefix, const std::string& name) {
    Snapshot s;
    s.name = name;
    auto code = read(prefix.string() + ".code.bin"), data = read(prefix.string() + ".data.bin"),
         state = read(prefix.string() + ".state.bin"), meta = read(prefix.string() + ".meta.bin");
    if (code.size() != s.code.size() || data.size() != s.data.size() ||
        state.size() != s.state.size() || meta.size() != 40)
        throw std::runtime_error("Snapshot size mismatch: " + prefix.string());
    std::memcpy(s.code.data(), code.data(), code.size());
    std::memcpy(s.data.data(), data.data(), data.size());
    std::memcpy(s.state.data(), state.data(), state.size());
    std::memcpy(s.meta.data(), meta.data(), meta.size());
    if (s.meta[0] != 0x31555652u || s.meta[1] != 1 || s.meta[2] != 16384 || s.meta[3] != 16384 ||
        s.meta[8] != sizeof(VU1State))
        throw std::runtime_error("Snapshot format mismatch: " + prefix.string());
    return s;
}
static void replay(Fixture& f, const Snapshot& s) {
    std::memcpy(f.code.data(), s.code.data(), s.code.size());
    std::memcpy(f.data.data(), s.data.data(), s.data.size());
    std::memcpy(&f.vu.state(), s.state.data(), s.state.size());
    f.memory.packets.clear();
    f.gs.packets.clear();
    f.memory.vif1_regs.top = s.meta[5];
    f.memory.vif1_regs.tops = s.meta[6];
    f.memory.vif1_regs.itop = s.meta[7];
    const uint32_t pc = f.vu.state().pc;
    f.vu.execute(f.code.data(), f.code.size(), f.data.data(), f.data.size(), f.gs, &f.memory, pc,
                 s.meta[7], s.meta[4]);
}
int main(int argc, char** argv) try {
    if (argc < 5) {
        std::fprintf(stderr, "Usage: EXE EMPTY_OUTPUT ROUNDS WEIGHTED_DIR STATIC_DIR\n");
        return 2;
    }
    for (const char* env : {"REO_VU1_DUMP", "REO_VU1_TIMING_AT"})
        _putenv_s(env, "");
    const fs::path out = argv[1];
    if (fs::exists(out) && !fs::is_empty(out))
        throw std::runtime_error("Output must be empty: " + out.string());
    fs::create_directories(out);
    const unsigned rounds = std::min(100ul, std::strtoul(argv[2], nullptr, 10));
    if (!rounds)
        throw std::runtime_error("Rounds must be positive");
    fixtures(out);
    std::vector<Snapshot> set;
    for (int dir = 3; dir < argc; ++dir) {
        std::vector<fs::path> files;
        for (const auto& entry : fs::directory_iterator(argv[dir]))
            if (entry.is_regular_file() && entry.path().filename().string().ends_with(".code.bin"))
                files.push_back(entry.path());
        std::sort(files.begin(), files.end());
        check(files.size() == (dir == 3 ? 256u : 64u),
              dir == 3 ? "256 weighted snapshot inputs" : "64 static snapshot inputs");
        for (const auto& file : files) {
            auto prefix = file;
            auto text = prefix.string();
            text.resize(text.size() - 9);
            const auto name =
                std::string(dir == 3 ? "weighted-" : "static-") + file.stem().stem().string();
            set.push_back(load(text, name));
        }
    }
    Fixture f;
    uint64_t packets = 0, bytes = 0;
    unsigned ended = 0;
    for (const auto& s : set) {
        replay(f, s);
        save(out / (s.name + ".bin"), f);
        ended += f.vu.state().ebit;
        packets += f.memory.packets.size();
        for (const auto& p : f.memory.packets)
            bytes += p.size();
    }
    // Warm both instruction and packet-sink allocation paths outside measurement.
    for (const auto& s : set)
        replay(f, s);
    std::vector<double> samples;
    uint64_t checksum = 0;
    for (unsigned round = 0; round < rounds; ++round) {
        auto start = std::chrono::steady_clock::now();
        for (const auto& s : set) {
            replay(f, s);
            checksum += f.vu.state().pc + f.memory.packets.size();
        }
        samples.push_back(
            std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - start)
                .count());
    }
    std::ofstream result(out / "benchmark.json");
    result << "{\"snapshots\":" << set.size() << ",\"rounds\":" << rounds
           << ",\"packets\":" << packets << ",\"packet_bytes\":" << bytes << ",\"ended\":" << ended
           << ",\"checksum\":" << checksum << ",\"wall_ms\":[";
    for (size_t i = 0; i < samples.size(); ++i) {
        if (i)
            result << ',';
        result << samples[i];
    }
    result << "]}\n";
    if (!result)
        throw std::runtime_error("Cannot write benchmark result");
    std::printf("FULL_REPLAYS %zu packets=%llu bytes=%llu ended=%u benchmark_rounds=%u\n",
                set.size(), static_cast<unsigned long long>(packets),
                static_cast<unsigned long long>(bytes), ended, rounds);
    std::printf("CHECKS %u passed %u failed\n", checks - failures, failures);
    return failures ? 1 : 0;
} catch (const std::exception& e) {
    std::fprintf(stderr, "ERROR %s\n", e.what());
    return 2;
}
