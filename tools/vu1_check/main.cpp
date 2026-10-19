#include "runtime/ps2_vu1.h"
#if defined(REO_VU_ISOLATED_RUNTIME_STUBS)
#include "vu_isolated_runtime_hooks.h"
#endif
#include "runtime/ps2_gs_gpu.h"
#include "runtime/ps2_memory.h"
#include <array>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <vector>

static unsigned failures = 0, checks = 0;
static void check(bool result, const char* name) {
    ++checks;
    std::printf("%s %s\n", result ? "PASS" : "FAIL", name);
    failures += !result;
}
struct Fixture {
    VU1Interpreter vu;
    GS gs;
    PS2Memory memory;
    std::array<uint8_t, 16384> code{}, data{};
    void pair(unsigned pc, uint32_t lower, uint32_t upper = 0x000002FF) {
        std::memcpy(code.data() + pc, &lower, 4);
        std::memcpy(code.data() + pc + 4, &upper, 4);
    }
    void run(unsigned cycles = 1) {
        vu.execute(code.data(), code.size(), data.data(), data.size(), gs, &memory, 0, 0, cycles);
    }
};
static bool close(float a, float b) {
    return std::fabs(a - b) < 0.00001f;
}
static std::vector<uint8_t> read(const std::filesystem::path& path) {
    std::ifstream f(path, std::ios::binary);
    return {std::istreambuf_iterator<char>(f), std::istreambuf_iterator<char>()};
}
static uint64_t byteHash(const uint8_t* data, size_t size) {
    uint64_t result = 14695981039346656037ull;
    for (size_t i = 0; i < size; ++i)
        result = (result ^ data[i]) * 1099511628211ull;
    return result;
}
static std::string jsonString(const std::string& value) {
    std::string result = "\"";
    for (unsigned char c : value) {
        if (c == '\\' || c == '\"') {
            result += '\\';
            result += char(c);
        } else if (c < 32) {
            char escaped[8];
            std::snprintf(escaped, sizeof(escaped), "\\u%04x", unsigned(c));
            result += escaped;
        } else
            result += char(c);
    }
    return result + '\"';
}
static bool gifEndsAtEop(const std::vector<uint8_t>& packet) {
    uint64_t position = 0;
    while (position + 16 <= packet.size()) {
        uint64_t tag = 0;
        std::memcpy(&tag, packet.data() + position, 8);
        position += 16;
        const uint64_t loops = tag & 32767, regs = (tag >> 60 & 15) ? (tag >> 60 & 15) : 16;
        const unsigned format = unsigned(tag >> 58 & 3);
        const uint64_t payload = format == 0   ? loops * regs * 16
                                 : format == 1 ? ((loops * regs + 1) / 2) * 16
                                               : loops * 16;
        if (payload > packet.size() - position)
            return false;
        position += payload;
        if (tag & (1ull << 15))
            return position == packet.size();
    }
    return false;
}
int main(int argc, char** argv) {
    // Separate process: constructor configuration/latch is deliberately static.
    // Default instruction tests below continue to disable all capture output.
    if (argc == 3 &&
        (!std::strcmp(argv[1], "--gate-check") || !std::strcmp(argv[1], "--gate-at-check") ||
         !std::strcmp(argv[1], "--gate-program-check"))) {
        const bool timeOnly = !std::strcmp(argv[1], "--gate-at-check");
        const bool weightedOnly = !std::strcmp(argv[1], "--gate-program-check");
        const std::filesystem::path directory(argv[2]);
        std::error_code error;
        if (std::filesystem::exists(directory, error) &&
            !std::filesystem::is_empty(directory, error)) {
            std::fprintf(stderr, "Gate test requires an empty owned output directory\n");
            return 2;
        }
        std::filesystem::create_directories(directory, error);
        if (error) {
            std::fprintf(stderr, "Cannot create gate test directory\n");
            return 2;
        }
        _putenv_s("REO_VU1_DUMP", directory.string().c_str());
        _putenv_s("REO_VU1_DUMP_LIMIT", "2");
        _putenv_s("REO_VU1_DUMP_GATE", "0x10");
        _putenv_s("REO_VU1_DUMP_MASK", "0xFF");
        _putenv_s("REO_VU1_DUMP_VALUE", "2");
        _putenv_s("REO_VU1_DUMP_AT", timeOnly ? "3600" : "");
        _putenv_s("REO_VU1_DUMP_PROGRAM", weightedOnly ? "weighted" : "");
        Fixture f;
        f.pair(0, 0x8000033C);
        std::vector<uint8_t> ram(PS2_RAM_SIZE, 0);
        auto exists = [&](unsigned index) {
            char name[64];
            std::snprintf(name, sizeof(name), "vu1-run-%04u.code.bin", index);
            return std::filesystem::exists(directory / name);
        };
        auto sizeIs = [&](const char* name, uintmax_t expected) {
            std::error_code sizeError;
            const auto size = std::filesystem::file_size(directory / name, sizeError);
            return !sizeError && size == expected;
        };
        auto gate = [&](uint32_t value) { std::memcpy(ram.data() + 16, &value, 4); };
        if (weightedOnly) {
            f.pair(0, 0x01E10003);
            f.run();
            check(!exists(0), "weighted program still requires readable RAM gate");
            f.memory.setDiagnosticRAM(ram.data());
            f.run();
            check(!exists(0), "weighted pre-gate call does not consume budget");
            gate(0x102);
            f.pair(0, 0x01ED0016);
            f.run();
            check(!exists(0), "static-room program cannot consume weighted capture budget");
            f.pair(0, 0x01E10003, 0x400002FF);
            f.run();
            check(!exists(0), "weighted filter checks both words of the first instruction pair");
            f.pair(0, 0x01E10003);
            f.vu.execute(f.code.data(), 4, f.data.data(), f.data.size(), f.gs, &f.memory, 0, 0, 1);
            check(!exists(0), "weighted filter rejects an incomplete instruction pair");
            f.run();
            check(exists(0) && sizeIs("vu1-run-0000.code.bin", 16384) &&
                      sizeIs("vu1-run-0000.data.bin", 16384) &&
                      sizeIs("vu1-run-0000.state.bin", sizeof(VU1State)) &&
                      sizeIs("vu1-run-0000.meta.bin", 40),
                  "weighted match captures complete original-format snapshots at index0");
            f.pair(0, 0x01ED0016);
            f.run();
            check(!exists(1), "armed weighted capture continues to reject static-room programs");
            gate(0);
            f.pair(0, 0x01E10003);
            f.run();
            check(exists(1), "weighted capture remains latched after RAM phase changes");
            f.run();
            check(!exists(2), "weighted capture stops at the matching-call budget");
            std::printf("PROGRAM_GATE_CHECKS %u passed %u failed\n", checks - failures, failures);
            return failures ? 1 : 0;
        }
        f.run();
        check(!exists(0), "RAM gate with null backing memory does not capture");
        f.memory.setDiagnosticRAM(ram.data());
        f.run();
        check(!exists(0), "pre-gate call does not consume snapshot budget");
        gate(0x102);
        f.run();
        if (timeOnly)
            check(!exists(0), "time gate blocks capture even when RAM mask matches");
        else {
            check(exists(0) && sizeIs("vu1-run-0000.code.bin", 16384) &&
                      sizeIs("vu1-run-0000.data.bin", 16384) &&
                      sizeIs("vu1-run-0000.state.bin", sizeof(VU1State)) &&
                      sizeIs("vu1-run-0000.meta.bin", 40),
                  "masked gate starts complete snapshots at index0");
            gate(0);
            f.run();
            check(exists(1), "armed capture remains latched after RAM phase changes");
            f.run();
            check(!exists(2), "capture stops at two-snapshot limit");
        }
        std::printf("GATE_CHECKS %u passed %u failed\n", checks - failures, failures);
        return failures ? 1 : 0;
    }
    // Ignore diagnostic env vars in this standalone process to avoid recursively
    // producing replay inputs or changing completed game-capture evidence.
    _putenv_s("REO_VU1_DUMP", "");
    {
        Fixture f;
        f.vu.state().vf[25][0] = 49;
        f.vu.state().vf[25][1] = 9;
        f.vu.state().vf[25][2] = 16;
        f.vu.state().vf[25][3] = 81;
        f.vu.state().p = 7;
        f.vu.state().q = 11;
        // Exact ERSQRT VF25.y and MFP VF25.y words reached by Kevin's shader.
        f.pair(0, 0x8020CFBD);
        f.pair(8, 0x8099067C);
        f.run(2);
        check(close(f.vu.state().p, 1.0f / 3) && close(f.vu.state().vf[25][1], 1.0f / 3),
              "captured ERSQRT computes selected Y reciprocal square root and MFP reads P");
        check(f.vu.state().vf[25][0] == 49 && f.vu.state().vf[25][2] == 16 &&
                  f.vu.state().vf[25][3] == 81 && f.vu.state().q == 11,
              "ERSQRT and selected MFP preserve other lanes and Q");
    }
    {
        Fixture f;
        f.vu.state().vf[25][1] = -4;
        f.vu.state().p = 7;
        f.pair(0, 0x8020CFBD);
        f.pair(8, 0x8099067C);
        f.run(2);
        check(f.vu.state().p == -4 && f.vu.state().vf[25][1] == -4,
              "ERSQRT preserves negative input rather than taking its absolute value");
    }
    {
        Fixture f;
        f.vu.state().vf[25][1] = 0;
        f.vu.state().p = 7;
        f.pair(0, 0x8020CFBD);
        f.run();
        check(f.vu.state().p == 0 && !std::signbit(f.vu.state().p),
              "ERSQRT zero produces zero rather than maximum float");
        f.vu.state().vf[25][1] = -0.0f;
        f.vu.state().p = 7;
        f.run();
        check(f.vu.state().p == 0 && std::signbit(f.vu.state().p),
              "ERSQRT preserves negative zero");
    }
    {
        Fixture f;
        f.vu.state().vf[2][0] = 3;
        f.vu.state().vf[3][0] = 4;
        f.pair(0, 0x8000033C, (8u << 21) | (3u << 16) | (2u << 11) | (1u << 6) | 0x28);
        f.run();
        check(close(f.vu.state().vf[1][0], 7), "lower NOP still executes upper ADD");
    }
    {
        Fixture f;
        f.vu.state().i = 2;
        f.vu.state().vf[2][0] = 3;
        f.pair(0, 0x3F800000, 0x80000000 | (8u << 21) | (2u << 11) | (1u << 6) | 0x22);
        f.run();
        check(close(f.vu.state().i, 1) && close(f.vu.state().vf[1][0], 5),
              "I flag executes upper with old I then loads lower immediate");
    }
    {
        Fixture f;
        f.vu.state().vi[4] = 200;
        f.vu.state().vf[31][0] = 1;
        f.vu.state().vf[31][1] = 2;
        f.vu.state().vf[31][2] = 3;
        f.vu.state().vf[31][3] = 4;
        uint64_t eop = 0x8000;
        std::memcpy(f.data.data(), &eop, 8);
        f.pair(0, 0x81E4FB7D);
        f.run();
        check(!std::memcmp(f.data.data() + 3200, f.vu.state().vf[31], 16) &&
                  f.vu.state().vi[4] == 201 && f.gs.packets.empty() && f.memory.packets.empty(),
              "captured PC C0 SQI VF31 VI4 writes and increments without false XGKICK");
    }
    {
        Fixture f;
        f.vu.state().vi[3] = 10;
        uint64_t tag = 0x1000000000008001ull;
        std::memcpy(f.data.data() + 160, &tag, 8);
        f.pair(0, 0x80001EFC);
        f.run();
        check(f.memory.packets.size() == 1 && f.memory.packets[0].size() == 32,
              "actual XGKICK uses VI3 and ends at packed EOP");
    }
    {
        Fixture f;
        f.memory.vif1_regs.top = 321;
        f.memory.vif1_regs.itop = 77;
        f.pair(0, 0x800006BC | (7u << 16));
        f.run();
        check(f.vu.state().vi[7] == 321, "actual XTOP reads VIF TOP");
        f.pair(0, 0x800006BD | (8u << 16));
        f.vu.state().vi[8] = 0;
        f.vu.execute(f.code.data(), f.code.size(), f.data.data(), f.data.size(), f.gs, &f.memory, 0,
                     77, 1);
        check(f.vu.state().vi[8] == 77, "actual XITOP reads latched ITOP");
    }
    {
        Fixture f;
        f.vu.state().vi[4] = -7;
        f.pair(0, 0x800003FD | (15u << 21) | (20u << 16) | (4u << 11));
        f.run();
        int32_t value = 0;
        std::memcpy(&value, &f.vu.state().vf[20][0], 4);
        check(value == -7, "actual MFIR preserves 5-bit vector destination");
    }
    {
        Fixture f;
        int32_t values[4] = {16, 32, -48, 64};
        std::memcpy(f.vu.state().vf[2], values, 16);
        f.pair(0, 0x8000033C, (15u << 21) | (3u << 16) | (2u << 11) | (4u << 6) | 0x3D);
        f.run();
        check(close(f.vu.state().vf[3][0], 1) && close(f.vu.state().vf[3][2], -3),
              "upper ITOF4 uses actual secondary table and FT destination");
    }
    {
        Fixture f;
        f.vu.state().acc[0] = 5;
        f.vu.state().vf[2][0] = 2;
        f.vu.state().vf[3][2] = 4;
        f.pair(0, 0x8000033C, (8u << 21) | (3u << 16) | (2u << 11) | (2u << 6) | 0x3E);
        f.run();
        check(close(f.vu.state().acc[0], 13), "upper MADDAz uses actual secondary table");
    }
    {
        Fixture f;
        f.vu.state().vi[5] = 17;
        const uint32_t value = 123;
        std::memcpy(f.data.data() + 17 * 16, &value, 4);
        f.pair(0, 0x81062BFE);
        f.run();
        check(f.vu.state().vi[6] == 123, "captured PC78 ILWR loads selected component into VI6");
        f.vu.state().clip = 0xABC123;
        f.pair(0, 0x38090000);
        f.run();
        check(f.vu.state().vi[9] == 0x123,
              "FCGET uses its original primary opcode and destination");
    }
    {
        Fixture f;
        f.pair(0, 0x8000033C, 0x400002FF);
        f.pair(8, 0x10010001);
        f.pair(16, 0x10020001);
        f.run(10);
        check(f.vu.state().vi[1] == 1 && f.vu.state().vi[2] == 0 && f.vu.state().pc == 16,
              "E flag executes its delay pair and leaves correct resume PC");
    }
    {
        Fixture f;
        f.pair(0, 0x40000002); // B target24; pair8 is the delay slot.
        f.pair(8, 0x10010001);
        f.pair(16, 0x10020001);
        f.pair(24, 0x10030001);
        f.run(3);
        check(f.vu.state().vi[1] == 1 && f.vu.state().vi[2] == 0 && f.vu.state().vi[3] == 1,
              "taken branch executes one delay pair then target");
    }
    if (argc > 1) {
        const std::filesystem::path prefix(argv[1]);
        std::filesystem::path output;
        unsigned dumpLimit = 256;
        uint64_t byteBudget = 16u * 1024u * 1024u;
        for (int i = 2; i < argc; ++i) {
            if (i + 1 >= argc) {
                std::fprintf(stderr, "Missing snapshot replay option value\n");
                return 2;
            }
            const char* option = argv[i++];
            const char* value = argv[i];
            if (!std::strcmp(option, "--dump-gif"))
                output = value;
            else if (!std::strcmp(option, "--dump-gif-count"))
                dumpLimit = unsigned(std::min(512ul, std::strtoul(value, nullptr, 0)));
            else if (!std::strcmp(option, "--dump-gif-bytes"))
                byteBudget =
                    std::min<uint64_t>(64u * 1024u * 1024u, std::strtoull(value, nullptr, 0));
            else {
                std::fprintf(stderr, "Unknown snapshot replay option: %s\n", option);
                return 2;
            }
        }
        std::ofstream manifest;
        if (!output.empty()) {
            std::error_code error;
            if (std::filesystem::exists(output, error) &&
                !std::filesystem::is_empty(output, error)) {
                std::fprintf(stderr, "GIF export requires an empty owned directory\n");
                return 2;
            }
            std::filesystem::create_directories(output, error);
            if (error) {
                std::fprintf(stderr, "Cannot create GIF export directory\n");
                return 2;
            }
            manifest.open(output / "vu_gif_packets.jsonl", std::ios::out | std::ios::trunc);
            if (!manifest) {
                std::fprintf(stderr, "Cannot open GIF export manifest\n");
                return 2;
            }
        }
        Fixture f;
        auto code = read(prefix.string() + ".code.bin"), data = read(prefix.string() + ".data.bin"),
             state = read(prefix.string() + ".state.bin"),
             meta = read(prefix.string() + ".meta.bin");
        check(code.size() == 16384 && data.size() == 16384 && state.size() == sizeof(VU1State) &&
                  meta.size() == 40,
              "captured replay input sizes and native state layout");
        if (code.size() == 16384 && data.size() == 16384 && state.size() == sizeof(VU1State) &&
            meta.size() == 40) {
            std::memcpy(f.code.data(), code.data(), code.size());
            std::memcpy(f.data.data(), data.data(), data.size());
            std::memcpy(&f.vu.state(), state.data(), state.size());
            uint32_t fields[10];
            std::memcpy(fields, meta.data(), 40);
            f.memory.vif1_regs.top = fields[5];
            f.memory.vif1_regs.tops = fields[6];
            f.memory.vif1_regs.itop = fields[7];
            const uint32_t pc = f.vu.state().pc;
            f.vu.execute(f.code.data(), f.code.size(), f.data.data(), f.data.size(), f.gs,
                         &f.memory, pc, fields[7], fields[4]);
            std::printf("REPLAY pc=%04x end=%04x packets=%zu\n", pc, f.vu.state().pc,
                        f.memory.packets.size());
            unsigned saved = 0;
            uint64_t savedBytes = 0;
            bool saveFailed = false;
            for (unsigned i = 0; i < f.memory.packets.size(); ++i) {
                std::printf("PACKET %u bytes=%zu\n", i, f.memory.packets[i].size());
                const auto& packet = f.memory.packets[i];
                if (!manifest.is_open() || saveFailed || saved >= dumpLimit ||
                    packet.size() > byteBudget - savedBytes)
                    continue;
                char filename[48];
                std::snprintf(filename, sizeof(filename), "vu_gif_%04u.bin", saved);
                std::ofstream file(output / filename, std::ios::binary | std::ios::trunc);
                file.write(reinterpret_cast<const char*>(packet.data()), packet.size());
                file.close();
                if (!file) {
                    saveFailed = true;
                    continue;
                }
                char record[640];
                std::snprintf(
                    record, sizeof(record),
                    ",\"packet\":%u,\"bytes\":%zu,\"fnv\":\"%016llx\",\"complete_eop\":%s,\"top\":%"
                    "u,\"tops\":%u,\"itop\":%u,\"pc_before\":%u,\"pc_after\":%u,\"ebit_after\":%s,"
                    "\"code_fnv\":\"%016llx\",\"data_fnv\":\"%016llx\",\"state_fnv\":\"%016llx\"}",
                    i, packet.size(),
                    static_cast<unsigned long long>(byteHash(packet.data(), packet.size())),
                    gifEndsAtEop(packet) ? "true" : "false", fields[5], fields[6], fields[7], pc,
                    f.vu.state().pc, f.vu.state().ebit ? "true" : "false",
                    static_cast<unsigned long long>(byteHash(code.data(), code.size())),
                    static_cast<unsigned long long>(byteHash(data.data(), data.size())),
                    static_cast<unsigned long long>(byteHash(state.data(), state.size())));
                manifest << "{\"file\":" << jsonString(filename)
                         << ",\"source_prefix\":" << jsonString(prefix.string()) << record << '\n';
                saveFailed |= !manifest;
                ++saved;
                savedBytes += packet.size();
            }
            if (manifest.is_open()) {
                // Retain the complete numerical result alongside the ordered
                // packets so GPU continuation integration can compare against
                // this independent production-interpreter execution.
                auto saveFinal = [&](const char* name, const void* bytes, size_t size) {
                    std::ofstream file(output / name, std::ios::binary);
                    file.write(static_cast<const char*>(bytes), size);
                    file.close();
                    saveFailed |= !file;
                };
                saveFinal("vu_final_state.bin", &f.vu.state(), sizeof(VU1State));
                saveFinal("vu_final_data.bin", f.data.data(), f.data.size());
                manifest.flush();
                saveFailed |= !manifest;
                std::printf("SAVED_VU_PACKETS %u bytes=%llu failed=%u\n", saved,
                            static_cast<unsigned long long>(savedBytes), unsigned(saveFailed));
                if (saveFailed)
                    return 2;
            }
        }
    }
    std::printf("CHECKS %u passed %u failed\n", checks - failures, failures);
    return failures ? 1 : 0;
}
