// Production VIF parser regression and bounded capture replay; no game assets
// are needed for synthetic cases. Coordinator owns build/run serialization.
#include "runtime/ps2_memory.h"
#include "runtime/ps2_gs_gpu.h"
#include "runtime/ps2_vu1.h"

#include <algorithm>
#include <array>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <vector>

namespace {
uint32_t command(uint8_t opcode, uint8_t count = 0, uint16_t immediate = 0) {
    return (uint32_t(opcode) << 24) | (uint32_t(count) << 16) | immediate;
}
void append(std::vector<uint8_t>& bytes, uint32_t word) {
    const size_t offset = bytes.size();
    bytes.resize(offset + 4);
    std::memcpy(bytes.data() + offset, &word, 4);
}
void run(PS2Memory& memory, const std::vector<uint32_t>& words) {
    memory.processVIF1Data(reinterpret_cast<const uint8_t*>(words.data()),
                           uint32_t(words.size() * 4));
}
void reset(PS2Memory& memory) {
    memory.vif1_regs = {};
    std::memset(memory.getVU1Code(), 0, PS2_VU1_CODE_SIZE);
    std::memset(memory.getVU1Data(), 0, PS2_VU1_DATA_SIZE);
}
std::vector<uint8_t> read(const std::filesystem::path& path) {
    std::ifstream file(path, std::ios::binary);
    return {std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};
}
uint64_t hash(const uint8_t* data, size_t bytes) {
    uint64_t value = 14695981039346656037ull;
    for (size_t i = 0; i < bytes; ++i)
        value = (value ^ data[i]) * 1099511628211ull;
    return value;
}
bool vectorIs(PS2Memory& memory, uint32_t address, const std::array<uint32_t, 4>& value) {
    return std::memcmp(memory.getVU1Data() + address * 16, value.data(), 16) == 0;
}
bool gifEndsAtEop(const uint8_t* data, uint32_t bytes) {
    uint64_t position = 0;
    while (position + 16 <= bytes) {
        uint64_t tag = 0;
        std::memcpy(&tag, data + position, 8);
        position += 16;
        const uint64_t loops = tag & 32767, regs = ((tag >> 60) & 15) ? ((tag >> 60) & 15) : 16;
        const unsigned format = unsigned((tag >> 58) & 3);
        const uint64_t payload = format == 0   ? loops * regs * 16
                                 : format == 1 ? ((loops * regs + 1) / 2) * 16
                                               : loops * 16;
        if (payload > bytes - position)
            return false;
        position += payload;
        if (tag & (1ull << 15))
            return position == bytes;
    }
    return false;
}
struct ReplayLimit {};
} // namespace

int main(int argc, char** argv) {
    PS2Memory memory;
    if (!memory.initialize())
        return 2;
    const bool replayVu = argc >= 3 && std::strcmp(argv[1], "--replay-vu") == 0;
    unsigned kickLimit = 8;
    std::filesystem::path gifDumpDirectory;
    unsigned gifDumpLimit = 256;
    uint64_t gifDumpBudget = 16u * 1024u * 1024u;
    if (replayVu)
        for (int i = 3; i < argc; ++i) {
            if (i + 1 >= argc) {
                std::fprintf(stderr, "Missing replay option value: %s\n", argv[i]);
                return 2;
            }
            const char* option = argv[i++];
            const char* value = argv[i];
            if (!std::strcmp(option, "--max-kicks"))
                kickLimit =
                    unsigned(std::min(256ul, std::max(1ul, std::strtoul(value, nullptr, 0))));
            else if (!std::strcmp(option, "--dump-gif"))
                gifDumpDirectory = value;
            else if (!std::strcmp(option, "--dump-gif-count"))
                gifDumpLimit = unsigned(std::min(512ul, std::strtoul(value, nullptr, 0)));
            else if (!std::strcmp(option, "--dump-gif-bytes"))
                gifDumpBudget =
                    std::min<uint64_t>(64u * 1024u * 1024u, std::strtoull(value, nullptr, 0));
            else {
                std::fprintf(stderr, "Unknown replay option: %s\n", option);
                return 2;
            }
        }
    std::ofstream gifManifest;
    if (!gifDumpDirectory.empty()) {
        std::error_code error;
        if (std::filesystem::exists(gifDumpDirectory, error) &&
            !std::filesystem::is_empty(gifDumpDirectory, error)) {
            std::fprintf(stderr, "GIF export requires an empty owned directory\n");
            return 2;
        }
        std::filesystem::create_directories(gifDumpDirectory, error);
        if (error) {
            std::fprintf(stderr, "Cannot create GIF dump directory: %s\n", error.message().c_str());
            return 2;
        }
        gifManifest.open(gifDumpDirectory / "vu_gif_packets.jsonl",
                         std::ios::out | std::ios::trunc);
        if (!gifManifest) {
            std::fprintf(stderr, "Cannot open GIF manifest\n");
            return 2;
        }
    }
    VU1Interpreter vu;
    GS gs;
    unsigned packets = 0, vuPackets = 0;
    unsigned vuEopPackets = 0, vuNonEExits = 0;
    uint32_t maxVuPacketBytes = 0;
    uint64_t packetBytes = 0, vuPacketBytes = 0;
    unsigned kicks = 0, gifSaved = 0;
    uint64_t gifSavedBytes = 0;
    bool gifSaveFailed = false;
    bool executingVu = false;
    memory.setGifPacketCallback([&](const uint8_t* data, uint32_t bytes) {
        ++packets;
        packetBytes += bytes;
        if (executingVu) {
            ++vuPackets;
            vuPacketBytes += bytes;
            maxVuPacketBytes = std::max(maxVuPacketBytes, bytes);
            vuEopPackets += gifEndsAtEop(data, bytes);
            // Only actual PATH1 emissions from VU execution: PATH2 callbacks
            // can contain untagged IMAGE continuation bytes, not whole packets.
            if (gifManifest.is_open() && !gifSaveFailed && gifSaved < gifDumpLimit &&
                bytes <= gifDumpBudget - gifSavedBytes) {
                char filename[48];
                std::snprintf(filename, sizeof(filename), "vu_gif_%04u.bin", gifSaved);
                std::ofstream file(gifDumpDirectory / filename, std::ios::binary | std::ios::trunc);
                file.write(reinterpret_cast<const char*>(data), bytes);
                file.close();
                if (!file)
                    gifSaveFailed = true;
                else {
                    char record[512];
                    std::snprintf(record, sizeof(record),
                                  "{\"index\":%u,\"file\":\"%s\",\"packet\":%u,\"vu_packet\":%u,"
                                  "\"kick\":%u,\"bytes\":%u,\"fnv\":\"%016llx\",\"complete_eop\":%"
                                  "s,\"top\":%u,\"tops\":%u,\"itop\":%u,\"pc\":%u}",
                                  gifSaved, filename, packets, vuPackets, kicks, bytes,
                                  static_cast<unsigned long long>(hash(data, bytes)),
                                  gifEndsAtEop(data, bytes) ? "true" : "false",
                                  memory.vif1_regs.top, memory.vif1_regs.tops, vu.state().itop,
                                  vu.state().pc);
                    gifManifest << record << '\n';
                    gifSaveFailed |= !gifManifest;
                    ++gifSaved;
                    gifSavedBytes += bytes;
                }
            }
        }
        if (replayVu && packets <= 256) {
            uint64_t tag = 0;
            if (bytes >= 8)
                std::memcpy(&tag, data, 8);
            std::printf("gif_packet=%u during_vu=%u bytes=%u fnv=%016llx tag=%016llx nloop=%u "
                        "eop=%u flg=%u nreg=%u\n",
                        packets, unsigned(executingVu), bytes,
                        static_cast<unsigned long long>(hash(data, bytes)),
                        static_cast<unsigned long long>(tag), unsigned(tag & 32767),
                        unsigned((tag >> 15) & 1), unsigned((tag >> 58) & 3),
                        unsigned((tag >> 60) & 15));
        }
    });
    memory.setVu1MscalCallback([&](uint32_t pc, uint32_t itop) {
        if (replayVu && kicks >= kickLimit)
            throw ReplayLimit{};
        ++kicks;
        std::printf("kick=%u pc=%x top=%u tops=%u itop=%u itops=%u dbf=%u\n", kicks, pc,
                    memory.vif1_regs.top, memory.vif1_regs.tops, itop, memory.vif1_regs.itops,
                    (memory.vif1_regs.stat >> 7) & 1);
        if (replayVu) {
            std::printf(
                "vu_input code_fnv=%016llx data_fnv=%016llx\n",
                static_cast<unsigned long long>(hash(memory.getVU1Code(), PS2_VU1_CODE_SIZE)),
                static_cast<unsigned long long>(hash(memory.getVU1Data(), PS2_VU1_DATA_SIZE)));
            executingVu = true;
            vu.execute(memory.getVU1Code(), PS2_VU1_CODE_SIZE, memory.getVU1Data(),
                       PS2_VU1_DATA_SIZE, gs, &memory, pc, itop, 65536);
            executingVu = false;
            vuNonEExits += !vu.state().ebit;
            std::printf(
                "vu_result pc=%x ebit=%u data_fnv=%016llx vi0=%d vi1=%d vi2=%d vi3=%d\n",
                vu.state().pc, unsigned(vu.state().ebit),
                static_cast<unsigned long long>(hash(memory.getVU1Data(), PS2_VU1_DATA_SIZE)),
                vu.state().vi[0], vu.state().vi[1], vu.state().vi[2], vu.state().vi[3]);
        }
    });
    memory.setVu1MscntCallback([&](uint32_t itop) {
        if (replayVu && kicks >= kickLimit)
            throw ReplayLimit{};
        ++kicks;
        std::printf("resume=%u top=%u tops=%u itop=%u itops=%u dbf=%u\n", kicks,
                    memory.vif1_regs.top, memory.vif1_regs.tops, itop, memory.vif1_regs.itops,
                    (memory.vif1_regs.stat >> 7) & 1);
        if (replayVu) {
            std::printf(
                "vu_input code_fnv=%016llx data_fnv=%016llx\n",
                static_cast<unsigned long long>(hash(memory.getVU1Code(), PS2_VU1_CODE_SIZE)),
                static_cast<unsigned long long>(hash(memory.getVU1Data(), PS2_VU1_DATA_SIZE)));
            executingVu = true;
            vu.resume(memory.getVU1Code(), PS2_VU1_CODE_SIZE, memory.getVU1Data(),
                      PS2_VU1_DATA_SIZE, gs, &memory, itop, 65536);
            executingVu = false;
            vuNonEExits += !vu.state().ebit;
            std::printf(
                "vu_result pc=%x ebit=%u data_fnv=%016llx vi0=%d vi1=%d vi2=%d vi3=%d\n",
                vu.state().pc, unsigned(vu.state().ebit),
                static_cast<unsigned long long>(hash(memory.getVU1Data(), PS2_VU1_DATA_SIZE)),
                vu.state().vi[0], vu.state().vi[1], vu.state().vi[2], vu.state().vi[3]);
        }
    });
    if (argc >= 3 && (std::strcmp(argv[1], "--replay") == 0 || replayVu)) {
        const std::filesystem::path directory(argv[2]);
        auto code = read(directory / "vif1_initial_code.bin");
        auto data = read(directory / "vif1_initial_data.bin");
        auto regs = read(directory / "vif1_initial_regs.bin");
        if (code.size() != PS2_VU1_CODE_SIZE || data.size() != PS2_VU1_DATA_SIZE ||
            regs.size() != sizeof(VIFRegisters)) {
            std::fprintf(stderr, "Missing or incomplete initial VIF/VU snapshots\n");
            return 2;
        }
        std::memcpy(memory.getVU1Code(), code.data(), code.size());
        std::memcpy(memory.getVU1Data(), data.data(), data.size());
        std::memcpy(&memory.vif1_regs, regs.data(), regs.size());
        unsigned buffers = 0;
        for (; buffers < 512; ++buffers) {
            char filename[64];
            std::snprintf(filename, sizeof(filename), "vif1_%04u.bin", buffers);
            const auto input = read(directory / filename);
            if (input.empty())
                break;
            try {
                memory.processVIF1Data(input.data(), uint32_t(input.size()));
            } catch (const ReplayLimit&) {
                std::printf("bounded_replay_limit=%u buffer=%u\n", kickLimit, buffers);
                ++buffers;
                break;
            }
            std::printf(
                "buffer=%u bytes=%zu code_fnv=%016llx data_fnv=%016llx\n", buffers, input.size(),
                static_cast<unsigned long long>(hash(memory.getVU1Code(), PS2_VU1_CODE_SIZE)),
                static_cast<unsigned long long>(hash(memory.getVU1Data(), PS2_VU1_DATA_SIZE)));
        }
        std::printf("replayed_buffers=%u kicks=%u vu_executed=%u gif_packets=%u gif_bytes=%llu "
                    "vu_packets=%u vu_packet_bytes=%llu vu_max_packet=%u vu_eop_packets=%u "
                    "vu_non_e_exits=%u\n",
                    buffers, kicks, unsigned(replayVu), packets,
                    static_cast<unsigned long long>(packetBytes), vuPackets,
                    static_cast<unsigned long long>(vuPacketBytes), maxVuPacketBytes, vuEopPackets,
                    vuNonEExits);
        if (gifManifest.is_open()) {
            gifManifest.flush();
            gifSaveFailed |= !gifManifest;
            std::printf("saved_vu_packets=%u saved_vu_bytes=%llu save_failed=%u\n", gifSaved,
                        static_cast<unsigned long long>(gifSavedBytes), unsigned(gifSaveFailed));
        }
        return buffers && !gifSaveFailed ? 0 : 2;
    }

    unsigned failures = 0;
    auto check = [&](bool condition, const char* name) {
        std::printf("%s %s\n", condition ? "PASS" : "FAIL", name);
        failures += !condition;
    };
    run(memory, {command(0x01, 0, 0x0101), command(0x03, 0, 32), command(0x02, 0, 16),
                 command(0x04, 0, 7)});
    check(memory.vif1_regs.itops == 7 && memory.vif1_regs.itop == 0,
          "ITOP command stages ITOPS until execution");
    run(memory, {command(0x6c, 1, 0x8000), 11, 22, 33, 44, command(0x14)});
    check(vectorIs(memory, 32, {11, 22, 33, 44}), "first FLG-relative UNPACK uses BASE");
    check(memory.vif1_regs.top == 32 && memory.vif1_regs.tops == 48 && memory.vif1_regs.itop == 7 &&
              (memory.vif1_regs.stat & 0x80),
          "MSCAL latches old TOPS and advances double buffer");
    run(memory, {command(0x04, 0, 9)});
    check(memory.vif1_regs.itops == 9 && memory.vif1_regs.itop == 7, "next ITOP remains staged");
    run(memory, {command(0x6c, 1, 0x8000), 55, 66, 77, 88, command(0x17)});
    check(vectorIs(memory, 48, {55, 66, 77, 88}) && memory.vif1_regs.top == 48 &&
              memory.vif1_regs.tops == 32 && memory.vif1_regs.itop == 9 &&
              !(memory.vif1_regs.stat & 0x80),
          "MSCNT latches second TOPS and returns to BASE");
    run(memory, {command(0x14), command(0x02, 0, 8)});
    check(memory.vif1_regs.base == 32 && memory.vif1_regs.tops == 32 &&
              memory.vif1_regs.ofst == 8 && !(memory.vif1_regs.stat & 0x80),
          "OFFSET preserves BASE after a double-buffer toggle");

    reset(memory);
    run(memory, {command(0x4a, 2, 2047), 0x12345678, 0x87654321, 0x11223344, 0x55667788});
    const std::array<uint32_t, 2> first{0x12345678, 0x87654321}, second{0x11223344, 0x55667788};
    check(std::memcmp(memory.getVU1Code() + PS2_VU1_CODE_SIZE - 8, first.data(), 8) == 0 &&
              std::memcmp(memory.getVU1Code(), second.data(), 8) == 0,
          "MPG wraps at 16 KiB micro memory");

    // A real transfer may end between a VIF command and its payload or midway
    // through that payload. Its next buffer resumes data, not opcode decoding.
    std::vector<uint8_t> stream;
    for (uint32_t word :
         {command(0x01, 0, 0x0101), command(0x6c, 2, 8), 11u, 22u, 33u, 44u, 55u, 66u, 77u, 88u,
          command(0x4a, 2, 4), 0x12345678u, 0x87654321u, 0x11223344u, 0x55667788u})
        append(stream, word);
    reset(memory);
    memory.processVIF1Data(stream.data(), uint32_t(stream.size()));
    std::array<uint8_t, PS2_VU1_DATA_SIZE> expectedData{};
    std::array<uint8_t, PS2_VU1_CODE_SIZE> expectedCode{};
    std::memcpy(expectedData.data(), memory.getVU1Data(), expectedData.size());
    std::memcpy(expectedCode.data(), memory.getVU1Code(), expectedCode.size());
    unsigned splitFailures = 0;
    for (uint32_t split = 4; split < stream.size(); split += 4) {
        reset(memory);
        memory.processVIF1Data(stream.data(), split);
        memory.processVIF1Data(stream.data() + split, uint32_t(stream.size()) - split);
        splitFailures +=
            std::memcmp(expectedData.data(), memory.getVU1Data(), expectedData.size()) != 0 ||
            std::memcmp(expectedCode.data(), memory.getVU1Code(), expectedCode.size()) != 0;
    }
    check(splitFailures == 0,
          "UNPACK and MPG are invariant across every word-boundary fragment split");

    reset(memory);
    run(memory, {command(0x01, 0, 0x0101), command(0x6c, 1, 16)});
    const unsigned initialKicks = kicks;
    const std::array<uint32_t, 4> opcodeLike{command(0x14), command(0x4a, 1), command(0x50, 0, 1),
                                             command(0x02, 0, 80)};
    run(memory, {opcodeLike[0], opcodeLike[1], opcodeLike[2], opcodeLike[3]});
    check(vectorIs(memory, 16, opcodeLike) && kicks == initialKicks,
          "command-only split resumes UNPACK data even when data resembles opcodes");

    reset(memory);
    run(memory, {command(0x01, 0, 0x0101), command(0x6c, 2, 8), 11});
    reset(memory); // Models initialization/FBRST clearing the pending CODE.
    run(memory, {command(0x01, 0, 0x0101), command(0x6c, 1, 24), 101, 102, 103, 104});
    check(vectorIs(memory, 24, {101, 102, 103, 104}) && vectorIs(memory, 8, {0, 0, 0, 0}),
          "CODE reset discards a stale incomplete payload");

    reset(memory);
    run(memory, {command(0x4a, 2, 2047)});
    run(memory, {first[0], first[1]});
    run(memory, {second[0], second[1]});
    check(std::memcmp(memory.getVU1Code() + PS2_VU1_CODE_SIZE - 8, first.data(), 8) == 0 &&
              std::memcmp(memory.getVU1Code(), second.data(), 8) == 0,
          "MPG at 3FF8 wraps after two payload fragments");

    reset(memory);
    run(memory, {command(0x20)});
    run(memory, {0x14000000, command(0x30), 1, 2});
    run(memory, {3, 4, command(0x31), 5});
    run(memory, {6, 7, 8});
    check(memory.vif1_regs.mask == 0x14000000 && memory.vif1_regs.row[0] == 1 &&
              memory.vif1_regs.row[3] == 4 && memory.vif1_regs.col[0] == 5 &&
              memory.vif1_regs.col[3] == 8,
          "STMASK STROW and STCOL survive fragmented payloads");

    reset(memory);
    const unsigned beforeDirectKicks = kicks;
    run(memory, {command(0x13), command(0x50, 0, 1)});
    run(memory, {0, 0});
    run(memory, {command(0x14), 0, command(0x01, 0, 0x0101), command(0x6c, 1, 32), 91, 92, 93, 94});
    check(kicks == beforeDirectKicks && vectorIs(memory, 32, {91, 92, 93, 94}),
          "fragmented DIRECT consumes its payload then resumes VIFcodes");
    std::printf("vif1_cases=13 failures=%u fragment_failures=%u\n", failures, splitFailures);
    return failures ? 1 : 0;
}
