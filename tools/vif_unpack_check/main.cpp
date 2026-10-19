#include "runtime/ps2_memory.h"
#include <algorithm>
#include <array>
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
    std::ifstream in(file, std::ios::binary);
    if (!in)
        throw std::runtime_error("Cannot read " + file.string());
    return {std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>()};
}
static void append(std::vector<uint8_t>& bytes, uint32_t word) {
    size_t at = bytes.size();
    bytes.resize(at + 4);
    std::memcpy(bytes.data() + at, &word, 4);
}
static uint32_t cmd(unsigned op, unsigned num = 0, unsigned imm = 0) {
    return (op << 24) | (num << 16) | imm;
}
struct Harness {
    PS2Memory memory;
    std::vector<uint8_t> events;
    uint64_t callbackCount = 0;
    bool record = true;
    Harness() {
        if (!memory.initialize())
            throw std::runtime_error("Memory initialization failed");
        memory.setVu1MscalCallback([this](uint32_t pc, uint32_t itop) { event(1, pc, itop); });
        memory.setVu1MscntCallback([this](uint32_t itop) { event(2, 0, itop); });
        memory.setGifPacketCallback([this](const uint8_t* data, uint32_t bytes) {
            ++callbackCount;
            if (record) {
                append(events, 3);
                append(events, bytes);
                events.insert(events.end(), data, data + bytes);
            }
        });
    }
    void event(uint32_t kind, uint32_t pc, uint32_t itop) {
        ++callbackCount;
        if (!record)
            return;
        append(events, kind);
        append(events, pc);
        append(events, itop);
        const auto* regs = reinterpret_cast<const uint8_t*>(&memory.vif1_regs);
        events.insert(events.end(), regs, regs + sizeof(memory.vif1_regs));
        events.insert(events.end(), memory.getVU1Code(), memory.getVU1Code() + PS2_VU1_CODE_SIZE);
        events.insert(events.end(), memory.getVU1Data(), memory.getVU1Data() + PS2_VU1_DATA_SIZE);
    }
    void reset() {
        memory.vif1_regs = {};
        events.clear();
        callbackCount = 0;
        record = true;
        for (unsigned i = 0; i < PS2_VU1_CODE_SIZE; ++i)
            memory.getVU1Code()[i] = uint8_t(i * 29 + 11);
        for (unsigned i = 0; i < PS2_VU1_DATA_SIZE; ++i)
            memory.getVU1Data()[i] = uint8_t(i * 17 + 53);
    }
    void run(const std::vector<uint8_t>& bytes) {
        memory.processVIF1Data(bytes.data(), uint32_t(bytes.size()));
    }
    void save(const fs::path& file) {
        std::ofstream out(file, std::ios::binary | std::ios::trunc);
        const uint32_t header[] = {0x46505556u,
                                   1,
                                   uint32_t(sizeof(VIFRegisters)),
                                   PS2_VU1_CODE_SIZE,
                                   PS2_VU1_DATA_SIZE,
                                   uint32_t(events.size())};
        out.write(reinterpret_cast<const char*>(header), sizeof(header));
        out.write(reinterpret_cast<const char*>(&memory.vif1_regs), sizeof(memory.vif1_regs));
        out.write(reinterpret_cast<const char*>(memory.getVU1Code()), PS2_VU1_CODE_SIZE);
        out.write(reinterpret_cast<const char*>(memory.getVU1Data()), PS2_VU1_DATA_SIZE);
        out.write(reinterpret_cast<const char*>(events.data()), events.size());
        if (!out)
            throw std::runtime_error("Cannot write " + file.string());
    }
};
static std::vector<uint8_t> unpack(unsigned vectors, unsigned destination, unsigned op = 0x6C,
                                   unsigned flags = 0) {
    std::vector<uint8_t> result;
    append(result, cmd(op, vectors == 256 ? 0 : vectors, destination | flags));
    for (unsigned i = 0; i < vectors * 4; ++i)
        append(result, 0x12830000u + i * 0x101u);
    return result;
}
static bool vectorIs(Harness& h, unsigned address, const std::array<uint32_t, 4>& expected) {
    return std::memcmp(h.memory.getVU1Data() + address * 16, expected.data(), 16) == 0;
}
static void fixtures(Harness& h, const fs::path& out) {
    unsigned index = 0;
    auto save = [&](const char* name) {
        char file[100];
        std::snprintf(file, sizeof(file), "fixture-%03u-%s.bin", index++, name);
        h.save(out / file);
    };
    for (unsigned cycle : {0u, 0x0101u, 0x0404u, 0xFFFFu})
        for (unsigned count : {1u, 2u, 255u, 256u}) {
            h.reset();
            h.memory.vif1_regs.cycle = cycle;
            auto input = unpack(count, 17);
            h.run(input);
            check(std::memcmp(h.memory.getVU1Data() + 17 * 16, input.data() + 4, count * 16) == 0,
                  "contiguous raw V4-32 matches all independent source bytes");
            check(h.memory.vif1_regs.num == (count == 256 ? 0 : count) &&
                      h.memory.vif1_regs.code == cmd(0x6C, count == 256 ? 0 : count, 17),
                  "NUM and CODE preserved, including NUM zero for 256 vectors");
            save("contiguous");
        }
    for (unsigned count : {1u, 2u, 256u}) {
        h.reset();
        h.memory.vif1_regs.cycle = 0x0404;
        const unsigned dest = 1024 - count;
        auto input = unpack(count, dest);
        h.run(input);
        check(std::memcmp(h.memory.getVU1Data() + dest * 16, input.data() + 4, count * 16) == 0,
              "copy ending exactly at 1024-vector boundary");
        save("exact-end");
    }
    {
        h.reset();
        auto input = unpack(1, 12, 0xEC);
        h.run(input);
        check((h.memory.vif1_regs.stat & (1u << 11)) &&
                  h.memory.vif1_regs.code == cmd(0xEC, 1, 12) &&
                  std::memcmp(h.memory.getVU1Data() + 12 * 16, input.data() + 4, 16) == 0,
              "IRQ bit remains set before optimized payload write");
        save("irq");
    }
    {
        h.reset();
        auto input = unpack(2, 1023);
        h.run(input);
        check(std::memcmp(h.memory.getVU1Data() + 1023 * 16, input.data() + 4, 16) == 0 &&
                  std::memcmp(h.memory.getVU1Data(), input.data() + 20, 16) == 0,
              "1024 wrap retains generic vector order");
        save("wrap");
    }
    {
        h.reset();
        h.memory.vif1_regs.tops = 1010;
        auto input = unpack(3, 20, 0x6C, 0xC000);
        h.run(input);
        check(std::memcmp(h.memory.getVU1Data() + 6 * 16, input.data() + 4, 48) == 0,
              "FLG/TOPS destination wraps before contiguous copy; USN leaves 32-bit words raw");
        save("tops");
    }
    for (unsigned mode : {1u, 2u, 3u}) {
        h.reset();
        h.memory.vif1_regs.mode = mode;
        const std::array<uint32_t, 4> row = {11, 22, 33, 44};
        std::memcpy(h.memory.vif1_regs.row, row.data(), 16);
        auto input = unpack(2, 20);
        h.run(input);
        uint32_t raw[8];
        std::memcpy(raw, input.data() + 4, 32);
        std::array<uint32_t, 4> first{}, second{};
        for (unsigned c = 0; c < 4; ++c) {
            first[c] = raw[c] + (mode == 3 ? 0 : row[c]);
            second[c] = raw[4 + c] + (mode == 3 ? 0 : mode == 2 ? first[c] : row[c]);
        }
        check(vectorIs(h, 20, first) && vectorIs(h, 21, second),
              "mode 1/2/3 fallback preserves arithmetic");
        check(std::memcmp(h.memory.vif1_regs.row, mode == 2 ? second.data() : row.data(), 16) == 0,
              "mode fallback preserves row state");
        save("mode");
    }
    {
        h.reset();
        h.memory.vif1_regs.cycle = 0x0204;
        auto input = unpack(3, 10);
        h.run(input);
        check(std::memcmp(h.memory.getVU1Data() + 10 * 16, input.data() + 4, 32) == 0 &&
                  std::memcmp(h.memory.getVU1Data() + 14 * 16, input.data() + 36, 16) == 0,
              "CL greater than WL retains skip spacing");
        save("skip-cycle");
    }
    {
        h.reset();
        h.memory.vif1_regs.cycle = 0x0402;
        h.memory.vif1_regs.row[0] = 17;
        auto input = unpack(2, 10);
        uint32_t word = cmd(0x6C, 4, 10);
        std::memcpy(input.data(), &word, 4);
        h.run(input);
        check(std::memcmp(h.memory.getVU1Data() + 10 * 16, input.data() + 4, 32) == 0 &&
                  vectorIs(h, 12, {17, 0, 0, 0}) && vectorIs(h, 13, {17, 0, 0, 0}),
              "CL less than WL retains row-fill cycles");
        save("fill-cycle");
    }
    {
        h.reset();
        h.memory.vif1_regs.mask = 0xE4;
        h.memory.vif1_regs.row[1] = 77;
        h.memory.vif1_regs.col[0] = 88;
        uint32_t protectedWord;
        std::memcpy(&protectedWord, h.memory.getVU1Data() + 10 * 16 + 12, 4);
        auto input = unpack(1, 10, 0x7C);
        h.run(input);
        check(vectorIs(h, 10, {0x12830000u, 77, 88, protectedWord}),
              "masked V4-32 retains raw/row/column/protected lane selection");
        save("mask");
    }
    for (unsigned split : {2u, 4u, 8u, 35u}) {
        h.reset();
        auto input = unpack(2, 30);
        const auto before =
            std::vector<uint8_t>(h.memory.getVU1Data(), h.memory.getVU1Data() + PS2_VU1_DATA_SIZE);
        h.memory.processVIF1Data(input.data(), split);
        check(std::memcmp(before.data(), h.memory.getVU1Data(), before.size()) == 0,
              "truncated UNPACK defers all payload writes");
        save("partial");
        h.memory.processVIF1Data(input.data() + split, uint32_t(input.size() - split));
        check(std::memcmp(h.memory.getVU1Data() + 30 * 16, input.data() + 4, 32) == 0,
              "fragment continuation completes deferred raw copy");
        save("continued");
    }
    for (unsigned dest : {4u, 5u}) {
        h.reset();
        auto input = unpack(3, dest);
        std::memcpy(h.memory.getVU1Data() + 64, input.data(), input.size());
        std::vector<uint8_t> expected(h.memory.getVU1Data(),
                                      h.memory.getVU1Data() + PS2_VU1_DATA_SIZE);
        for (unsigned vector = 0; vector < 3; ++vector) {
            uint8_t temp[16];
            std::memcpy(temp, expected.data() + 68 + vector * 16, 16);
            std::memcpy(expected.data() + dest * 16 + vector * 16, temp, 16);
        }
        h.memory.processVIF1Data(h.memory.getVU1Data() + 64, uint32_t(input.size()));
        check(std::memcmp(expected.data(), h.memory.getVU1Data(), expected.size()) == 0,
              "overlapping payload falls back to original sequential source/write behavior");
        save("overlap");
    }
    {
        h.reset();
        auto input = unpack(2, 60);
        append(input, cmd(3, 0, 32));
        append(input, cmd(2, 0, 48));
        append(input, cmd(4, 0, 7));
        append(input, cmd(0x4A, 1, 2));
        append(input, 0x8000033Cu);
        append(input, 0x400002FFu);
        append(input, cmd(0x50, 0, 1));
        append(input, 0x00008000u);
        append(input, 0x10000000u);
        append(input, 0);
        append(input, 0);
        append(input, cmd(0x15, 0, 0x11));
        append(input, cmd(0x17));
        h.run(input);
        check(h.callbackCount == 3 && h.memory.vif1_regs.top == 80 &&
                  h.memory.vif1_regs.tops == 32 && h.memory.vif1_regs.itop == 7,
              "DIRECT/MSCALF/MSCNT ordered callbacks see unpacked bytes and double-buffer latches");
        const uint32_t expectedCode[] = {0x8000033Cu, 0x400002FFu};
        check(std::memcmp(h.memory.getVU1Code() + 16, expectedCode, 8) == 0,
              "MPG code upload persists beside optimized UNPACK");
        save("callbacks");
    }
    std::printf("SYNTHETIC_ARTIFACTS %u\n", index);
}
int main(int argc, char** argv) try {
    if (argc != 5) {
        std::fprintf(stderr, "Usage EXE EMPTY_OUTPUT ROUNDS CAPTURE_DIR COMPLETE_BUFFER_COUNT\n");
        return 2;
    }
    _putenv_s("REO_VIF1_DUMP", "");
    _putenv_s("REO_VIF1_DUMP_COUNT", "");
    const fs::path out = argv[1], capture = argv[3];
    if (fs::exists(out) && !fs::is_empty(out))
        throw std::runtime_error("Output must be empty");
    fs::create_directories(out);
    const unsigned rounds = std::min(100ul, std::strtoul(argv[2], nullptr, 10));
    const unsigned complete = unsigned(std::strtoul(argv[4], nullptr, 10));
    if (!rounds || complete != 4)
        throw std::runtime_error(
            "Positive rounds and exactly four metadata-complete buffers required");
    Harness h;
    fixtures(h, out);
    h.reset();
    auto regs = read(capture / "vif1_initial_regs.bin"),
         code = read(capture / "vif1_initial_code.bin"),
         data = read(capture / "vif1_initial_data.bin");
    if (regs.size() != sizeof(VIFRegisters) || code.size() != PS2_VU1_CODE_SIZE ||
        data.size() != PS2_VU1_DATA_SIZE)
        throw std::runtime_error("Wrong initial capture layout");
    std::memcpy(&h.memory.vif1_regs, regs.data(), regs.size());
    std::memcpy(h.memory.getVU1Code(), code.data(), code.size());
    std::memcpy(h.memory.getVU1Data(), data.data(), data.size());
    for (unsigned i = 0; i < complete; ++i) {
        char name[64];
        std::snprintf(name, sizeof(name), "vif1_%04u.bin", i);
        h.run(read(capture / name));
        h.save(out / (std::string("capture-") + name));
    }
    // Representative reached format, not an entire original DMA/VU replay.
    std::vector<uint8_t> workload;
    append(workload, cmd(1, 0, 0x0404));
    for (unsigned i = 0; i < 512; ++i) {
        auto input = unpack(256, (i % 4) * 256);
        workload.insert(workload.end(), input.begin(), input.end());
    }
    h.reset();
    h.record = false;
    h.run(workload);
    h.save(out / "benchmark-final.bin");
    std::vector<double> samples;
    for (unsigned round = 0; round < rounds; ++round) {
        h.reset();
        h.record = false;
        auto start = std::chrono::steady_clock::now();
        h.run(workload);
        samples.push_back(
            std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - start)
                .count());
    }
    std::ofstream result(out / "benchmark.json");
    result << "{\"input_bytes\":" << workload.size() << ",\"vectors\":131072,\"rounds\":" << rounds
           << ",\"wall_ms\":[";
    for (size_t i = 0; i < samples.size(); ++i) {
        if (i)
            result << ',';
        result << samples[i];
    }
    result << "]}\n";
    if (!result)
        throw std::runtime_error("Cannot write timing");
    std::printf("CHECKS %u passed %u failed\n", checks - failures, failures);
    return failures ? 1 : 0;
} catch (const std::exception& e) {
    std::fprintf(stderr, "ERROR %s\n", e.what());
    return 2;
}
