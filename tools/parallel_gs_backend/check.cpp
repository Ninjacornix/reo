#include "parallel_backend.h"
#include "stream_helpers.h"
#include "gs_registers.hpp"
#include "thread_id.hpp"
#ifdef REO_CHECK_WITH_CATALOGUE
#include "resident_geometry/enrollment/enrollment_selected.hpp"
#include "resident_geometry/enrollment/static_incremental.hpp"
#endif
#include <exception>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <thread>
using namespace gs_backend_bridge;
using namespace reo_parallel_backend;
using namespace ParallelGS;
namespace fs = std::filesystem;
static unsigned checks = 0;
#define CHECK(c)                                                                                   \
    do {                                                                                           \
        ++checks;                                                                                  \
        if (!(c))                                                                                  \
            throw std::runtime_error(std::string("CHECK failed: ") + #c + " at " +                 \
                                     std::to_string(__LINE__));                                    \
    } while (0)
template <class F> void rejects(F&& f) {
    bool caught = false;
    try {
        f();
    } catch (const std::exception&) {
        caught = true;
    }
    CHECK(caught);
}
constexpr size_t VramSize = 4u * 1024u * 1024u;
struct AD {
    uint8_t addr;
    uint64_t value;
};
static std::vector<uint64_t> packet(std::initializer_list<AD> commands) {
    std::vector<uint64_t> p;
    p.push_back(uint64_t(commands.size()) | (1ull << 15) | (1ull << 60));
    p.push_back(14);
    for (auto c : commands) {
        p.push_back(c.value);
        p.push_back(c.addr);
    }
    return p;
}
static void gif(Backend& b, uint8_t path, const std::vector<uint64_t>& p, size_t first = 0,
                size_t length = ~size_t(0)) {
    if (length == ~size_t(0))
        length = p.size() * 8 - first;
    b.rawGif(path, reinterpret_cast<const uint8_t*>(p.data()) + first, length);
}
static uint32_t pixel(Backend& b, size_t offset = 12) {
    uint32_t value = 0;
    b.exportVram(offset, reinterpret_cast<uint8_t*>(&value), 4);
    return value;
}
static void setup(Backend& b) {
    const AD commands[] = {{0x1A, 1},
                           {0x4C, 8ull << 16},
                           {0x4D, 8ull << 16},
                           {0x4E, 224ull | (1ull << 32)},
                           {0x4F, 224ull | (1ull << 32)},
                           {0x40, (511ull << 16) | (447ull << 48)},
                           {0x41, (511ull << 16) | (447ull << 48)},
                           {0x47, 0x30000},
                           {0x48, 0x30000},
                           {0x18, 0},
                           {0x19, 0},
                           {0x46, 1}};
    for (auto c : commands)
        b.directRegister(c.addr, c.value);
}
static void triangle(Backend& b, uint32_t rgba) {
    b.directRegister(0, 3);
    b.directRegister(1, rgba | (0x3F800000ull << 32));
    b.directRegister(5, 0);
    b.directRegister(5, 64ull * 16);
    b.directRegister(5, (64ull * 16) << 16);
}
static Privileged display() {
    // NTSC analog: upstream mode width640, clock divider4, magnification5
    // produces640*4/5=512. INT+FFMD yields224-line fields ->448 output lines.
    Reg64<SMODE1Bits> clock{};
    clock.desc.LC = SMODE1Bits::LC_ANALOG;
    clock.desc.CMOD = SMODE1Bits::CMOD_NTSC;
    clock.desc.SPML = 4;
    Privileged p{};
    p[0] = 1;
    p[1] = clock.bits;
    p[2] = 3;
    p[7] = 8ull << 9;
    p[8] = 636ull | (50ull << 12) | (4ull << 23) | (2559ull << 32) | (447ull << 44);
    p[15] = 0x551B4000;
    p[16] = 0x7F00;
    return p;
}
static void beginRead(Backend& b, uint32_t psm, uint32_t width, uint32_t height = 1) {
    b.directRegister(0x50, (8ull << 16) | (uint64_t(psm) << 24));
    b.directRegister(0x51, 1ull | (1ull << 16));
    b.directRegister(0x52, width | (uint64_t(height) << 32));
    b.directRegister(0x53, 1);
}
static void pureHelpers() {
    CHECK(mergeLane(0x1122334455667788, 1, 1, 0xAB) == 0x112233445566AB88);
    CHECK(mergeLane(0, 4, 4, 0x12345678) == 0x1234567800000000ull);
    CHECK(mergeLane(1, 0, 8, ~0ull) == ~0ull);
    rejects([] { mergeLane(0, 1, 2, 0); });
    ByteFifo fifo;
    std::vector<uint8_t> input(35);
    for (unsigned i = 0; i < 35; ++i)
        input[i] = uint8_t(i);
    fifo.replace(input);
    uint8_t out[40]{};
    CHECK(fifo.read(out, 17) == 17);
    CHECK(fifo.read(out + 17, 40 - 17) == 18);
    CHECK(fifo.remaining() == 0);
    CHECK(fifo.read(out, 1) == 0);
    CHECK(std::memcmp(out, input.data(), 35) == 0);
    fifo.replace(input);
    fifo.clear();
    CHECK(fifo.remaining() == 0);
    auto p = packet({{0x53, 1}, {0x61, 0}, {0x62, 0xFFFFFFFF000000ABull}});
    // Every legal quadword split must retain command count and exact offsets.
    for (size_t split = 16; split < p.size() * 8; split += 16) {
        GifBoundaryObserver observer;
        auto a = observer.observe(1, reinterpret_cast<const uint8_t*>(p.data()), split);
        auto c = observer.observe(1, reinterpret_cast<const uint8_t*>(p.data()) + split,
                                  p.size() * 8 - split);
        for (auto& v : c)
            v.end += split;
        a.insert(a.end(), c.begin(), c.end());
        CHECK(a.size() == 3);
        CHECK(a[0].end == 32 && a[1].end == 48 && a[2].end == 64);
        CHECK(a[0].addr == 0x53 && a[1].addr == 0x61 && a[2].addr == 0x62);
    }
    GifBoundaryObserver observer;
    CHECK(observer.observe(2, reinterpret_cast<const uint8_t*>(p.data()), 16).empty());
    CHECK(observer.observe(1, reinterpret_cast<const uint8_t*>(p.data()), p.size() * 8).size() ==
          3);
    CHECK(observer.observe(2, reinterpret_cast<const uint8_t*>(p.data()) + 16, p.size() * 8 - 16)
              .size() == 3);
    // Odd REGLIST padding and opaque IMAGE payload must not be read as A+D.
    std::vector<uint64_t> opaque = {1ull | (1ull << 58) | (3ull << 60),
                                    0xFFF,
                                    0,
                                    0x61,
                                    0,
                                    0x60,
                                    1ull | (2ull << 58),
                                    0,
                                    0,
                                    0x61};
    CHECK(observer.observe(3, reinterpret_cast<const uint8_t*>(opaque.data()), opaque.size() * 8)
              .empty());
    CHECK(observer.observe(3, reinterpret_cast<const uint8_t*>(p.data()), p.size() * 8).size() ==
          3);
    observer.reset();
    CHECK(observer.observe(2, reinterpret_cast<const uint8_t*>(p.data()), p.size() * 8).size() ==
          3);
    rejects([&] { observer.observe(0, reinterpret_cast<const uint8_t*>(p.data()), 16); });
}
static void save(const fs::path& path, const std::vector<uint8_t>& bytes) {
    std::ofstream f(path, std::ios::binary);
    f.write(reinterpret_cast<const char*>(bytes.data()), std::streamsize(bytes.size()));
    if (!f)
        throw std::runtime_error("Cannot write proof artifact");
}
int main(int argc, char** argv) try {
    if (argc != 2)
        throw std::runtime_error("Usage: parallel_backend_check NEW_OUTPUT_DIRECTORY");
    const fs::path output = fs::absolute(argv[1]);
    if (fs::exists(output))
        throw std::runtime_error("Output already exists");
    fs::create_directories(output);
    Util::register_thread_index(4);
    pureHelpers();
    CHECK(currentPath() == 3);
    {
        PathScope one(1);
        CHECK(currentPath() == 1);
        {
            PathScope two(2);
            CHECK(currentPath() == 2);
        }
        CHECK(currentPath() == 1);
    }
    CHECK(currentPath() == 3);
    registerFactory(makeFactory());
    CHECK(bool(registeredFactory()));
    registerFactory({});
    CHECK(!registeredFactory());
    std::vector<uint8_t> initial(VramSize, 0);
    Init init;
    init.vram = initial.data();
    init.vramSize = initial.size();
    init.registers = display();
    std::string reason;
    Route fallback;
    CHECK(!fallback.start(Choice::Parallel, init, makeFactory(), reason));
    CHECK(fallback.state() == State::Software);
    CHECK(!reason.empty());
    fallback.stop();
    Config config;
    config.validatedDrawing = true;
    Privileged published{};
    unsigned resets = 0;
    config.persistentPipelineCache = true;
    config.pipelineCacheFile = (output / L"pipelines.cache").string();
    uint64_t publishedCsr = init.registers[15];
    std::vector<uint64_t> ackMasks;
    config.publishPrivilegedReset = [&](const Privileged& p) {
        published = p;
        publishedCsr = p[15];
        ++resets;
    };
    config.publishStatusAck = [&](uint64_t mask) {
        ackMasks.push_back(mask);
        publishedCsr &= ~mask;
    };
    Config incomplete = config;
    incomplete.publishStatusAck = {};
    CHECK(!fallback.start(Choice::Parallel, init, makeFactory(incomplete), reason));
    CHECK(fallback.state() == State::Software);
    CHECK(reason.find("acknowledgment") != std::string::npos);
    fallback.stop();
    auto backend = makeFactory(config)();
    Backend* active = backend.get();
    unsigned finished = 0, signaled = 0, labeled = 0;
    bool inspectPrefix = false;
    uint32_t prefixPixel = 0;
#define MARK(x)                                                                                    \
    do {                                                                                           \
        std::fprintf(stderr, "[MARK] " x "\n");                                                    \
        std::fflush(stderr);                                                                       \
    } while (0)
    MARK("factory");
    init.completedEvent = [&](uint8_t addr, uint64_t) {
        if (addr == 0x61) {
            ++finished;
            if (inspectPrefix)
                prefixPixel = pixel(*active);
        }
        if (addr == 0x60)
            ++signaled;
        if (addr == 0x62)
            ++labeled;
        if (addr == 0x60)
            publishedCsr |= 1;
        if (addr == 0x61)
            publishedCsr |= 2;
    };
    MARK("callbacks");
    CHECK(backend->init(init, reason));
    CHECK(Util::get_current_thread_index() == 4);
    CHECK(reason.empty());
    MARK("init");
    CHECK(snapshotPrivileged(*backend) == init.registers);
    MARK("snapshot");
    backend->privilegedWrite(0x70, 1, 0xAB);
    CHECK((snapshotPrivileged(*backend)[7] & 255) == 0xAB);
    backend->privilegedWrite(0x72, 2, 0xCDEF);
    CHECK((snapshotPrivileged(*backend)[7] & 0xFFFF0000u) == 0xCDEF0000u);
    backend->privilegedWrite(0x74, 4, 0x12345678);
    CHECK(snapshotPrivileged(*backend)[7] >> 32 == 0x12345678u);
    backend->privilegedWrite(0x78, 8, ~0ull);
    CHECK(snapshotPrivileged(*backend)[7] >> 32 == 0x12345678u);
    backend->privilegedWrite(0x70, 8, init.registers[7]);
    MARK("priv-write-context");
    CHECK(pixel(*backend) == 0);
    setup(*backend);
    MARK("setup");
    std::exception_ptr workerError;
    std::thread worker([&] {
        try {
            Util::register_thread_index(7);
            triangle(*backend, 0x80604020);
            backend->flush();
            CHECK(pixel(*backend) == 0x80604020);
            CHECK(Util::get_current_thread_index() == 7);
        } catch (...) {
            workerError = std::current_exception();
        }
    });
    worker.join();
    MARK("worker-join");
    if (workerError)
        std::rethrow_exception(workerError);
    CHECK(Util::get_current_thread_index() == 4);
    CHECK(pixel(*backend, 8192 - 4) == 0);
    MARK("pixel-8k");
    Frame image = backend->capture({display(), 123});
    MARK("capture");
    std::cout << "SCANOUT width=" << image.width << " height=" << image.height
              << " bytes=" << image.rgba.size() << " SMODE1=0x" << std::hex << display()[1]
              << " SMODE2=0x" << display()[2] << " DISPLAY1=0x" << display()[8] << std::dec << '\n';
    save(output / "triangle-rgba.bin", image.rgba);
    {
        std::ofstream metadata(output / "triangle-scanout.json");
        metadata << "{\"width\":" << image.width << ",\"height\":" << image.height
                 << ",\"bytes\":" << image.rgba.size()
                 << ",\"expected_width\":512,\"expected_height\":448}\n";
        CHECK(bool(metadata));
    }
    CHECK(image.width == 512 && image.height == 448);
    CHECK(image.tick == 123 && image.displayFbp == 0 && image.rgba.size() == 512u * 448u * 4u);
    CHECK(std::any_of(image.rgba.begin(), image.rgba.end(), [](uint8_t b) { return b != 0; }));
    // Complete the FINISH prefix before parsing the subsequent sprite in the SAME packet.
    inspectPrefix = true;
    auto mixed = packet({{0x61, 0},
                         {0, 6},
                         {1, 0x3F80000090705030ull},
                         {5, 0},
                         {5, (64ull * 16) | ((64ull * 16) << 16)}});
    gif(*backend, 1, mixed);
    inspectPrefix = false;
    CHECK(finished == 1);
    CHECK(prefixPixel == 0x80604020);
    CHECK(pixel(*backend) == 0x90705030);
    const auto firstFrame = image.rgba;
    Frame later = backend->capture({display(), 124});
    CHECK(later.width == 512 && later.height == 448 && later.tick == 124);
    CHECK(later.rgba != firstFrame);
    CHECK(image.rgba == firstFrame);
    save(output / "sprite-reused-staging-rgba.bin", later.rgba);
    // Independent path parser state survives serialized path interleaving.
    auto split = packet(
        {{0, 6}, {1, 0x3F800000A0806040ull}, {5, 0}, {5, (64ull * 16) | ((64ull * 16) << 16)}});
    gif(*backend, 2, split, 0, 16);
    auto label = packet({{0x62, 0xFFFFFFFF000000CDull}});
    gif(*backend, 3, label);
    for (size_t offset = 16; offset < split.size() * 8; offset += 16)
        gif(*backend, 2, split, offset, 16);
    CHECK(labeled == 1);
    CHECK(pixel(*backend) == 0xA0806040);
    // Ordinary packed NREG=2 loop split at EVERY quadword.
    backend->directRegister(0, 6);
    std::vector<uint64_t> packedSprite = {2ull | (1ull << 15) | (2ull << 60),
                                          0x51,
                                          0x40ull | (0x60ull << 32),
                                          0x80ull | (0xA0ull << 32),
                                          0,
                                          0,
                                          0x40ull | (0x60ull << 32),
                                          0x80ull | (0xA0ull << 32),
                                          1024ull | (1024ull << 32),
                                          0};
    for (size_t offset = 0; offset < packedSprite.size() * 8; offset += 16)
        gif(*backend, 1, packedSprite, offset, 16);
    CHECK(pixel(*backend) == 0xA0806040);
    // Guaranteed ADONLYHandlers[2] fast path. Without remaining-input fallback
    // the one-qword body chunks get a zero quota and do not advance the parser.
    auto optimizedAd = packet(
        {{0, 6}, {1, 0x3F800000A0806040ull}, {5, 0}, {5, (64ull * 16) | ((64ull * 16) << 16)}});
    optimizedAd[0] = 2ull | (1ull << 15) | (2ull << 60);
    optimizedAd[1] = 0xEE;
    for (size_t offset = 0; offset < optimizedAd.size() * 8; offset += 16)
        gif(*backend, 2, optimizedAd, offset, 16);
    CHECK(pixel(*backend) == 0xA0806040);
    // Exact tails, independent cursor and capture at TRXDIR before later overwrite.
    beginRead(*backend, 0, 5);
    backend->directRegister(1, 0x3F80000080604020ull);
    triangle(*backend, 0x80604020);
    uint8_t transfer[32]{};
    CHECK(backend->readTransfer(transfer, 17) == 17);
    CHECK(backend->readTransfer(transfer + 17, 15) == 3);
    CHECK(backend->readTransfer(transfer, 1) == 0);
    for (unsigned i = 0; i < 5; ++i) {
        uint32_t got;
        std::memcpy(&got, transfer + 4 * i, 4);
        CHECK(got == 0xA0806040);
    }
    beginRead(*backend, 1, 3);
    CHECK(backend->readTransfer(transfer, 2) == 2);
    CHECK(backend->readTransfer(transfer + 2, 30) == 7);
    for (unsigned i = 0; i < 3; ++i) {
        CHECK(transfer[3 * i] == 0x20);
        CHECK(transfer[3 * i + 1] == 0x40);
        CHECK(transfer[3 * i + 2] == 0x60);
    }
    beginRead(*backend, 0, 5);
    CHECK(backend->readTransfer(transfer, 17) == 17);
    beginRead(*backend, 0, 5);
    CHECK(backend->readTransfer(transfer, 32) == 20);
    CHECK(backend->readTransfer(transfer, 32) == 0);
    // Raw-GIF TRXDIR must capture before a subsequent overwrite in its packet.
    auto readThenDraw = packet({{0x53, 1},
                                {0, 6},
                                {1, 0x3F800000B0907050ull},
                                {5, 0},
                                {5, (64ull * 16) | ((64ull * 16) << 16)}});
    gif(*backend, 3, readThenDraw);
    CHECK(backend->readTransfer(transfer, 32) == 20);
    uint32_t before = 0;
    std::memcpy(&before, transfer, 4);
    CHECK(before == 0x80604020);
    CHECK(pixel(*backend) == 0xB0907050);
    // W1C on the exact written byte lane, not a merged historical CSR.
    backend->directRegister(0x60, 0xFFFFFFFF00000011ull);
    CHECK(signaled == 1);
    CHECK((snapshotPrivileged(*backend)[15] & 1u) != 0);
    CHECK(uint32_t(snapshotPrivileged(*backend)[18]) == 0x11);
    backend->privilegedWrite(0x1000, 1, 1);
    backend->directRegister(0x60, 0xFFFFFFFF00000022ull);
    CHECK(signaled == 2);
    CHECK(uint32_t(snapshotPrivileged(*backend)[18]) == 0x22);
    CHECK(uint32_t(snapshotPrivileged(*backend)[18] >> 32) == 0xCD);
    backend->privilegedWrite(0x1000, 1, 3);
    backend->directRegister(0x61, 0);
    CHECK(finished == 2);
    CHECK((snapshotPrivileged(*backend)[15] & 3u) == 2u);
    CHECK(ackMasks.size() == 2 && ackMasks[0] == 1 && ackMasks[1] == 3);
    CHECK((publishedCsr & 3u) == (snapshotPrivileged(*backend)[15] & 3u));
    // Direct context fills preserve registers, cursor, masks and 16-bit packing.
    backend->directRegister(0x40, (1ull << 16) | (1ull << 48));
    backend->directRegister(0x4C, (8ull << 16) | (0xFF000000ull << 32));
    CHECK(backend->clearContext(0, 0x11223344, false));
    CHECK(pixel(*backend) == 0xB0223344);
    backend->directRegister(0x4C, (8ull << 16) | (2ull << 24));
    CHECK(backend->clearContext(0, 0x80604020, true));
    uint16_t packed = 0;
    backend->exportVram(12, reinterpret_cast<uint8_t*>(&packed), 2);
    CHECK(packed == 0xB104);
    backend->directRegister(0x4C, 0);
    CHECK(!backend->clearContext(0, 0, false));
    rejects([&] { backend->exportVram(VramSize, transfer, 1); });
    // CSR RESET publication exactly matches real privileged reset, retaining VRAM.
    backend->privilegedWrite(0x1010, 2, 0);
    CHECK(snapshotPrivileged(*backend)[16] == 0x6000);
    backend->privilegedWrite(0x1011, 1, 0x15);
    CHECK(snapshotPrivileged(*backend)[16] == 0x7500);
    backend->privilegedWrite(0x1001, 1, 2);
    CHECK(resets == 1);
    CHECK(published[15] == 0x551B4000 && published[16] == 0x7F00);
    for (size_t i = 0; i < 19; ++i)
        if (i != 15 && i != 16)
            CHECK(published[i] == 0);
    backend->exportVram(12, reinterpret_cast<uint8_t*>(&packed), 2);
    CHECK(packed == 0xB104);
    CHECK(backend->readTransfer(transfer, 32) == 0);
    setup(*backend);
    backend->reset();
    setup(*backend);
    triangle(*backend, 0x80604020);
    backend->flush();
    CHECK(pixel(*backend) == 0x80604020);
    // Second uncleared SIGNAL: the backend owns a resumable GS FIFO stall the
    // way PCSX2 queues a SIGNAL behind an unacknowledged one. The pending
    // SIGNAL and the unconsumed packet suffix are preserved (no loss, no
    // double observer advance); the guest CSR acknowledgment releases both.
    backend->directRegister(0x60, 0xFFFFFFFF00000033ull);
    CHECK(signaled == 3);
    CHECK(uint32_t(snapshotPrivileged(*backend)[18]) == 0x33);
    auto haltBuffer = packet({{0x61, 0},
                              {0, 6},
                              {1, 0x3F80000020101010ull},
                              {5, 0},
                              {5, (64ull * 16) | ((64ull * 16) << 16)}});
    backend->directRegister(0x60, 0xFFFFFFFF00000044ull);
    CHECK(signaled == 3); // held, never rejected
    CHECK((snapshotPrivileged(*backend)[15] & 1u) != 0);
    gif(*backend, 1, haltBuffer);
    CHECK(finished == 2);
    CHECK(pixel(*backend) == 0x80604020); // held sprite (0x20101010) must not draw while parked
    CHECK(ackMasks.size() == 2);          // the held lane produced no ack of its own
    // Held-work ownership report: the predictive hold parked the whole
    // packet (the halt engaged before any feeding) plus the held lane.
    CHECK(backend->heldGifCount() == 2);
    CHECK(backend->heldGifBytes() == haltBuffer.size() * 8);
    backend->privilegedWrite(0x1000, 1, 1); // guest acknowledges; the stall releases
    CHECK(signaled == 4 &&
          uint32_t(snapshotPrivileged(*backend)[18]) == 0x44); // exactly-once delivery
    CHECK(finished == 3 && pixel(*backend) == 0x20101010);     // held suffix resumed in order
    CHECK((snapshotPrivileged(*backend)[15] & 3u) == 3u); // SIGNAL and held FINISH both latched
    CHECK(ackMasks.size() == 3 && ackMasks[2] == 1); // CPU ACK published on the exact written lane
    CHECK(backend->heldGifBytes() == 0 && backend->heldGifCount() == 0); // released exactly once
    // Rounds B and C: repeated SIGNAL stalls separated by guest acknowledgments,
    // each with drawing that must complete only after its own release.
    const auto stalledRound = [&](uint8_t firstId, uint8_t heldId, uint32_t color,
                                  unsigned signalFirst, unsigned finishedAfter, size_t acksBefore) {
        backend->privilegedWrite(0x1000, 1, 1); // clear the bit latched by the previous release
        CHECK(ackMasks.size() == acksBefore + 1);
        backend->directRegister(0x60, 0xFFFFFFFF00000000ull | firstId);
        CHECK(signaled == signalFirst && uint32_t(snapshotPrivileged(*backend)[18]) == firstId);
        backend->directRegister(0x60, 0xFFFFFFFF00000000ull | heldId);
        CHECK(signaled == signalFirst); // held, never rejected
        CHECK(backend->heldGifCount() == 1);
        CHECK(backend->heldGifBytes() == 0); // a lane, no packet bytes yet
        auto buffer = packet({{0x61, 0},
                              {0, 6},
                              {1, 0x3F80000000000000ull | color},
                              {5, 0},
                              {5, (64ull * 16) | ((64ull * 16) << 16)}});
        gif(*backend, 1, buffer);
        CHECK(backend->heldGifCount() == 2);
        CHECK(backend->heldGifBytes() == buffer.size() * 8);
        CHECK(uint32_t(snapshotPrivileged(*backend)[18]) != heldId); // nothing delivered while held
        CHECK(signaled == signalFirst &&
              finished == finishedAfter - 1); // no completion for parked work
        backend->privilegedWrite(0x1000, 1, 1);
        CHECK(signaled == signalFirst + 1 &&
              uint32_t(snapshotPrivileged(*backend)[18]) == heldId); // exactly-once delivery
        CHECK(finished == finishedAfter &&
              pixel(*backend) == color); // drawing ran after the release, in order
        CHECK(backend->heldGifBytes() == 0 &&
              backend->heldGifCount() == 0); // released exactly once
    };
    stalledRound(0x77, 0x88, 0x50607080, 5, 4, 3);
    stalledRound(0x99, 0xAA, 0x60708090, 7, 5, 5);
    // RESET while the second stall is pending: the held SIGNAL, the held
    // packet and a held LABEL lane are all canceled - no stale SIGNAL, no ID
    // update, no IRQ, and no acknowledgment publication afterwards.
    backend->directRegister(0x60, 0xFFFFFFFF000000BBull);
    CHECK(signaled == 8); // held
    gif(*backend, 1,
        packet({{0x61, 0},
                {0, 6},
                {1, 0x3F800000708090A0ull},
                {5, 0},
                {5, (64ull * 16) | ((64ull * 16) << 16)}}));
    backend->directRegister(0x62,
                            0xFFFFFFFF000000EEull); // held LABEL lane must never update the ID
    CHECK(backend->heldGifCount() == 3);
    CHECK(backend->heldGifBytes() == 96); // register lanes carry no bytes
    const size_t acksAtReset = ackMasks.size();
    backend->privilegedWrite(0x1001, 1, 2);
    CHECK(resets == 2);
    CHECK(signaled == 8 && finished == 5 &&
          snapshotPrivileged(*backend)[18] == 0); // nothing stale delivered
    CHECK(ackMasks.size() == acksAtReset); // canceled work publishes no ACK and raises no IRQ
    CHECK(backend->heldGifBytes() == 0 &&
          backend->heldGifCount() == 0); // cancellation releases exactly once
    // A bounded backlog (the runtime budget is what actually parks bytes in
    // memory; here the backend must absorb its held lanes in strict order)
    // still resumes from a single acknowledgment.
    setup(*backend); // the CSR RESET above cleared all GS context state
    backend->directRegister(0x60, 0xFFFFFFFF000000CCull);
    CHECK(signaled == 9 && uint32_t(snapshotPrivileged(*backend)[18]) == 0xCC);
    backend->directRegister(0x60, 0xFFFFFFFF000000DDull);
    CHECK(signaled == 9); // stall engaged again
    constexpr unsigned kBacklog = 48;
    size_t backlogBytes = 0;
    for (unsigned i = 0; i < kBacklog; ++i) {
        auto entry = packet({{0x61, 0},
                             {0, 6},
                             {1, 0x3F80000000000000ull | (0x010101ull * (i + 1ull))},
                             {5, 0},
                             {5, (64ull * 16) | ((64ull * 16) << 16)}});
        backlogBytes += entry.size() * 8;
        gif(*backend, 1, entry);
    }
    CHECK(backend->heldGifCount() == 1 + kBacklog);
    CHECK(backend->heldGifBytes() == backlogBytes);
    CHECK(signaled == 9); // held work stays parked, never delivered early
    backend->privilegedWrite(0x1000, 1, 1);
    CHECK(signaled == 10 && uint32_t(snapshotPrivileged(*backend)[18]) == 0xDD);
    if (finished != 5 + kBacklog || pixel(*backend) != 0x303030)
        std::fprintf(stderr, "[DBG] finished=%u expected=%u pixel=0x%X\n", finished, 5 + kBacklog,
                     pixel(*backend));
    CHECK(finished == 5 + kBacklog &&
          pixel(*backend) == 0x303030); // every entry resumed, strict order
    CHECK(backend->heldGifBytes() == 0 && backend->heldGifCount() == 0);
    // Shutdown while stalled must still make progress, and no stale held work
    // may leak into a fresh session.
    backend->directRegister(0x60, 0xFFFFFFFF000000FFull); // held
    gif(*backend, 1,
        packet({{0x61, 0},
                {0, 6},
                {1, 0x3F80000090A0B0C0ull},
                {5, 0},
                {5, (64ull * 16) | ((64ull * 16) << 16)}}));
    CHECK(backend->heldGifCount() == 2 && backend->heldGifBytes() == 96);
    backend->close();
    backend->close();
    CHECK(Util::get_current_thread_index() == 4);
    CHECK(fs::is_regular_file(output / L"pipelines.cache"));
    CHECK(fs::file_size(output / L"pipelines.cache") > 80 &&
          fs::file_size(output / L"pipelines.cache") <= 64u * 1024u * 1024u + 80);
    CHECK(backend->init(init, reason));
    CHECK(pixel(*backend) == 0);
    setup(*backend);
    triangle(*backend, 0x80604020);
    CHECK(pixel(*backend) == 0x80604020);
    backend->close();
    // Runtime-accounting coverage. The runtime clears `completed` only when the
    // held report is empty in BOTH bytes and lanes, so the backend report must
    // stay nonzero in each of these three shapes: (a) a held zero-byte register
    // lane, (b) a SIGNAL at a packet's final boundary (empty suffix, pending
    // event), and (c) reinitialization after prior submissions.
    {
        Init accInit;
        accInit.vram = initial.data();
        accInit.vramSize = initial.size();
        accInit.registers = display();
        unsigned accFinished = 0, accSignaled = 0;
        accInit.completedEvent = [&](uint8_t addr, uint64_t) {
            if (addr == 0x61)
                ++accFinished;
            if (addr == 0x60)
                ++accSignaled;
        };
        Config acc;
        acc.validatedDrawing = true;
        unsigned accResets = 0;
        acc.publishPrivilegedReset = [&](const Privileged&) { ++accResets; };
        acc.publishStatusAck = [&](uint64_t) {};
        auto fresh = makeFactory(acc)();
        Backend* f = fresh.get();
        std::string r2;
        CHECK(f->init(accInit, r2));
        setup(*f);
        // (a) Held zero-byte register: a SIGNAL parked behind a pending flag
        //     consumes no bytes but must still report one outstanding lane.
        f->directRegister(0x60, 0xFFFFFFFF00000011ull);
        CHECK(accSignaled == 1);                        // delivered, bit0 set
        f->directRegister(0x60, 0xFFFFFFFF00000022ull); // held: zero bytes, one lane
        CHECK(f->heldGifCount() == 1);
        CHECK(f->heldGifBytes() == 0);
        f->privilegedWrite(0x1000, 1, 1); // ack releases the lone lane
        CHECK(f->heldGifCount() == 0 && f->heldGifBytes() == 0);
        CHECK(accSignaled == 2);
        f->privilegedWrite(0x1000, 1, 1); // ack 0x22: clear bit0 so the next SIGNAL can deliver
        // (b) SIGNAL at the final packet boundary: no suffix bytes are parked,
        //     but the pending SIGNAL event must remain reported until acked.
        f->directRegister(0x60, 0xFFFFFFFF00000033ull);
        CHECK(accSignaled == 3); // delivered, bit0 set
        auto endSignal =
            packet({{0x61, 0}, {0x60, 0xFFFFFFFF00000044ull}}); // FINISH + trailing SIGNAL
        gif(*f, 1, endSignal);
        CHECK(accFinished == 1); // FINISH delivered before the halt
        CHECK(f->heldGifBytes() == 0);
        CHECK(f->heldGifCount() >= 1);    // pending SIGNAL still outstanding
        CHECK(accSignaled == 3);          // the trailing SIGNAL is NOT delivered yet
        f->privilegedWrite(0x1000, 1, 1); // ack delivers the pending SIGNAL
        CHECK(accSignaled == 4);
        CHECK(f->heldGifCount() == 0 && f->heldGifBytes() == 0);
        // (c) Reinitialization after prior submissions clears held accounting:
        //     a fresh session inherits no parked work from the previous one.
        f->directRegister(0x60, 0xFFFFFFFF00000055ull); // held
        gif(*f, 1,
            packet({{0x61, 0},
                    {0, 6},
                    {1, 0x3F80000080808080ull},
                    {5, 0},
                    {5, (64ull * 16) | ((64ull * 16) << 16)}}));
        CHECK(f->heldGifCount() >= 1); // outstanding work before reinit
        f->close();
        f->close();
        CHECK(f->init(accInit, r2));
        CHECK(pixel(*f) == 0);
        CHECK(f->heldGifCount() == 0 && f->heldGifBytes() == 0); // no stale hold after reinit
        setup(*f);
        triangle(*f, 0x80604020);
        f->flush();
        CHECK(pixel(*f) == 0x80604020);
        f->close();
    }
    // Mixed-execution CPU<->GPU handoff plumbing. The route-refusal checks run
    // unconditionally; the owner-level checks need the real catalogue bundle
    // (REO_CHECK_WITH_CATALOGUE + REO_CHECK_CATALOGUE_DIR) because a genuine
    // whole2ea owner is pipeline-backed and device-backed, never a stub.
    {
        reo_resident_live::Handoff blank{};
        Route refusalRoute; // never started: State::Empty refuses without device work
        CHECK(!refusalRoute.residentImportHandoff(blank));
        CHECK(!refusalRoute.residentExportHandoff(blank));
    }
#ifdef REO_CHECK_WITH_CATALOGUE
    {
        const char* catalogueEnv = std::getenv("REO_CHECK_CATALOGUE_DIR");
        if (!catalogueEnv || !fs::is_regular_file(fs::path(catalogueEnv) / "package.json"))
            std::fprintf(stderr, "[SKIP] handoff owner checks need REO_CHECK_CATALOGUE_DIR\n");
        else {
            const fs::path catalogueDir = fs::path(catalogueEnv);
            auto bootstrap =
                reo_gpu_catalog::build(catalogueDir, reo_gpu_enrollment_selected::assets(),
                                       reo_gpu_enrollment_selected::proofs());
            if (const char* multi = std::getenv("REO_CHECK_STATIC_MULTI");
                multi && std::strcmp(multi, "1") == 0)
                reo_gpu_catalog::configureStaticIncremental(bootstrap, catalogueDir);
            CHECK(bootstrap.readyToInstall);
            CHECK(bootstrap.owner.enabled && bootstrap.owner.fullProtocolCoverage &&
                  bool(bootstrap.owner.factory));
            // Exactly one admitted program, boundaries from the device oracle,
            // registry-level completeness stays false (coverage is not
            // ownership).
            unsigned admittedCount = 0;
            for (const auto& program : bootstrap.registry->programs)
                if (program->gpuAdmitted) {
                    ++admittedCount;
                    CHECK(bool(program->canResume));
                    CHECK(program->admittedFreshPCs.size() == 2);
                    CHECK(std::any_of(program->admittedFreshPCs.begin(),
                                      program->admittedFreshPCs.end(),
                                      [](uint32_t pc) { return pc == 296; }));
                    CHECK(std::any_of(program->admittedFreshPCs.begin(),
                                      program->admittedFreshPCs.end(),
                                      [](uint32_t pc) { return pc == 1320; }));
                }
            CHECK(admittedCount == 1);
            CHECK(!bootstrap.registry->complete());
            CHECK(bootstrap.registry->perProgramAdmission);
            CHECK(bootstrap.registry->allowIncrementalFallback);

            // A dedicated backend: a declined handoff must stay local to this
            // session and must never poison the shared session above.
            Config hConfig;
            hConfig.validatedDrawing = true;
            hConfig.publishPrivilegedReset = [&](const Privileged&) {};
            hConfig.publishStatusAck = [&](uint64_t) {};
            // The whole2ea owner prewarm compiles the whole catalogue; without
            // a persistent cache every harness run recompiles synchronously.
            // The cache path is FIXED (outside the per-run output directory,
            // which must be fresh) via REO_CHECK_CACHE_FILE.
            hConfig.persistentPipelineCache = true;
            hConfig.pipelineCacheFile =
                std::getenv("REO_CHECK_CACHE_FILE")
                    ? std::string(std::getenv("REO_CHECK_CACHE_FILE"))
                    : (output.parent_path() / "pipelines-handoff.cache").string();
            hConfig.residentGeometry = bootstrap.owner;
            auto hBackend = makeFactory(hConfig)();
            Backend* h = hBackend.get();
            Init hInit;
            hInit.vram = initial.data();
            hInit.vramSize = initial.size();
            hInit.registers = display();
            std::string hReason;
            CHECK(h->init(hInit, hReason));
            setup(*h);
            CHECK(pixel(*h) == 0);
            // (1) Zero epoch/bank generation is a foreign identity: refused
            //     before any device-level work, deterministically, for BOTH
            //     directions.
            reo_resident_live::Handoff malformed{};
            uint8_t marker = 0xAB;
            std::memset(malformed.state.data(), int(marker), malformed.state.size());
            rejects([&] { h->residentImportHandoff(malformed); });
            rejects([&] { h->residentExportHandoff(malformed); });
            // (2) A genuine identity on a healthy owner imports: the bank is
            //     created from the CURRENT handoff (never the boot snapshot,
            //     never cold()) and (3) exports back byte-for-byte, including
            //     the architectural carry and the VIF controls.
            const uint64_t epoch = 0xA011, generation = 0x33;
            auto traced = [&](const char* what, const std::function<void()>& step) {
                try {
                    step();
                } catch (...) {
                    std::fprintf(stderr, "[HANDOFF-FAIL] step=%s\n", what);
                    std::fflush(stderr);
                    throw;
                }
            };
            reo_resident_live::Handoff first{};
            first.epoch = epoch;
            first.bankGeneration = generation;
            for (size_t i = 0; i < first.state.size(); ++i)
                first.state[i] = uint8_t(i * 7u + 3u);
            for (size_t i = 0; i < first.data.size(); ++i)
                first.data[i] = uint8_t(i * 13u + 5u);
            first.row = {0x11111111u, 0x22222222u, 0x33333333u, 0x44444444u};
            first.column = {0x55555555u, 0x66666666u, 0x77777777u, 0x88888888u};
            first.cycle = 0x0404;
            first.mode = 0x123;
            first.mask = 0x456789;
            traced("import-create", [&] { h->residentImportHandoff(first); });
            reo_resident_live::Handoff roundTrip{};
            roundTrip.epoch = epoch;
            roundTrip.bankGeneration = generation;
            traced("export-roundtrip", [&] { h->residentExportHandoff(roundTrip); });
            CHECK(roundTrip.state == first.state);
            CHECK(roundTrip.data == first.data);
            CHECK(roundTrip.row == first.row && roundTrip.column == first.column);
            CHECK(roundTrip.cycle == first.cycle && roundTrip.mode == first.mode &&
                  roundTrip.mask == first.mask);
            // (4) Import OVERWRITES an existing bank in place: a second import
            //     with different contents changes what exports back.
            reo_resident_live::Handoff second{first};
            std::memset(second.state.data(), int(0x5A), second.state.size());
            for (size_t i = 0; i < second.data.size(); ++i)
                second.data[i] = uint8_t(255u - second.data[i]);
            second.cycle = 0x8282;
            second.mode = 0x321;
            second.mask = 0x987654;
            traced("import-overwrite", [&] { h->residentImportHandoff(second); });
            reo_resident_live::Handoff afterOverwrite{};
            afterOverwrite.epoch = epoch;
            afterOverwrite.bankGeneration = generation;
            traced("export-after-overwrite", [&] { h->residentExportHandoff(afterOverwrite); });
            CHECK(afterOverwrite.state == second.state);
            CHECK(afterOverwrite.data == second.data);
            CHECK(afterOverwrite.cycle == second.cycle && afterOverwrite.mode == second.mode &&
                  afterOverwrite.mask == second.mask);
            // (5) A stale epoch/generation is refused even though the bank
            //     exists: GPU ownership identity is checked, never guessed.
            reo_resident_live::Handoff stale{second};
            stale.epoch = epoch + 1;
            rejects([&] { h->residentImportHandoff(stale); });
            reo_resident_live::Handoff staleGeneration{second};
            staleGeneration.bankGeneration = generation + 1;
            rejects([&] { h->residentExportHandoff(staleGeneration); });
            // (6) GS reset keeps the bank and advances the epoch; a post-reset
            //     import at the NEW epoch is honored (ownership survived a
            //     reset without reinitializing through cold()).
            h->residentPrepareGsReset(epoch + 1);
            reo_resident_live::Handoff freshEpoch{second};
            freshEpoch.epoch = epoch + 1;
            traced("import-post-reset", [&] { h->residentImportHandoff(freshEpoch); });
            reo_resident_live::Handoff postReset{};
            postReset.epoch = epoch + 1;
            postReset.bankGeneration = generation;
            traced("export-post-reset", [&] { h->residentExportHandoff(postReset); });
            CHECK(postReset.state == second.state && postReset.data == second.data);
            // (7) The plain graphics path is unaffected by all of the above.
            triangle(*h, 0x11223344);
            h->flush();
            CHECK(pixel(*h) == 0x11223344);
            // Two separately queued initializers must both have real device
            // receipts. This catches an owner recording commands but omitting
            // its Job and lastEnqueued_ update (the next enqueue then rejects
            // ordinal 2, and retirement incorrectly returns no launches).
            reo_resident_live::Handoff numerical{};
            numerical.epoch = epoch + 1;
            numerical.bankGeneration = generation;
            const uint32_t one = 0x3f800000u;
            std::memcpy(numerical.state.data() + 12, &one, sizeof(one));
            h->residentImportHandoff(numerical);
            auto admitted = std::find_if(bootstrap.registry->programs.begin(),
                                         bootstrap.registry->programs.end(),
                                         [](const auto& program) { return program->gpuAdmitted; });
            CHECK(admitted != bootstrap.registry->programs.end());
            for (uint64_t ordinal = 1; ordinal <= 2; ++ordinal) {
                reo_resident_live::Operation initOperation{};
                initOperation.kind = reo_resident_live::Kind::Launch;
                initOperation.program = *admitted;
                initOperation.ordinal = ordinal;
                initOperation.startPC = 0;
                initOperation.maxPairs = 65536;
                reo_resident_live::Batch batch{};
                batch.epoch = numerical.epoch;
                batch.bankGeneration = generation;
                batch.operations.push_back(initOperation);
                h->residentEnqueue(batch);
            }
            const auto initialized = h->residentRetire(reo_resident_live::Barrier::GuestRead,
                                                       numerical.epoch, generation);
            CHECK(initialized.size() == 2);
            for (size_t i = 0; i < initialized.size(); ++i) {
                CHECK(initialized[i].ordinal == i + 1);
                CHECK(initialized[i].epoch == numerical.epoch &&
                      initialized[i].bankGeneration == generation);
                CHECK(initialized[i].status == 0 && initialized[i].ended);
            }
            h->close();
            h->close();
        }
    }
#endif
    // Native single-bank model: frontend ACK is immediate; its delayed worker
    // copy must NOT erase a newer event that completed in the meantime.
    Privileged front = init.registers;
    bool currentEpoch = true;
    unsigned nativeEvents = 0, nativeResetCalls = 0;
    Config nativeConfig;
    nativeConfig.validatedDrawing = true;
    nativeConfig.publishPrivilegedReset = [&](const Privileged&) { ++nativeResetCalls; };
    nativeConfig.peekEventFrontState = [&]() -> std::optional<Privileged> {
        if (!currentEpoch)
            return std::nullopt;
        return front;
    };
    Init nativeInit = init;
    nativeInit.completedEvent = [&](uint8_t addr, uint64_t payload) {
        ++nativeEvents;
        const uint32_t mask = uint32_t(payload >> 32), id = uint32_t(payload);
        if (addr == 0x60) {
            front[18] =
                (front[18] & 0xFFFFFFFF00000000ull) | ((uint32_t(front[18]) & ~mask) | (id & mask));
            front[15] |= 1;
        }
        if (addr == 0x61)
            front[15] |= 2;
        if (addr == 0x62)
            front[18] = uint32_t(front[18]) |
                        (uint64_t((uint32_t(front[18] >> 32) & ~mask) | (id & mask)) << 32);
    };
    backend = makeFactory(nativeConfig)();
    CHECK(backend->init(nativeInit, reason));
    backend->directRegister(0x60, 0xFFFFFFFF00000011ull);
    CHECK(nativeEvents == 1);
    front[15] &= ~3ull; // Actual CPU ACK happened; worker copy is still queued.
    backend->directRegister(0x61, 0);
    CHECK((front[15] & 3u) == 2u);
    backend->privilegedWrite(0x1000, 1, 3);
    CHECK((front[15] & 3u) == 2u);
    CHECK((snapshotPrivileged(*backend)[15] & 3u) == 2u);
    backend->directRegister(0x60, 0xFFFFFFFF00000022ull);
    CHECK(nativeEvents == 3);
    front[15] &= ~1ull;
    backend->directRegister(0x60, 0xFFFFFFFF00000033ull);
    CHECK(nativeEvents == 4);
    backend->privilegedWrite(0x1000, 1, 1);
    CHECK((front[15] & 1u) == 1u);
    CHECK(uint32_t(snapshotPrivileged(*backend)[18]) == 0x33);
    front[16] = 0x7500;
    backend->directRegister(0x62, 0xFFFFFFFF000000ABull);
    CHECK(snapshotPrivileged(*backend)[16] == 0x7500);
    CHECK(snapshotPrivileged(*backend)[18] >> 32 == 0xAB);
    const unsigned eventsBeforeReset = nativeEvents;
    currentEpoch = false;
    backend->directRegister(0x61, 0);
    CHECK(nativeEvents == eventsBeforeReset);
    // CPU applied RESET at store time and a newer display write already followed.
    front = {};
    front[15] = 0x551B4000;
    front[16] = 0x7F00;
    front[7] = 0x1234;
    backend->privilegedWrite(0x1001, 1, 2);
    CHECK(nativeResetCalls == 1);
    CHECK(front[7] == 0x1234 && front[15] == 0x551B4000 && front[16] == 0x7F00);
    currentEpoch = true;
    backend->directRegister(0x61, 0);
    CHECK(nativeEvents == eventsBeforeReset + 1);
    CHECK((snapshotPrivileged(*backend)[15] & 3u) == 2u);
    backend->close();
    std::ofstream report(output / "result.json");
    report << "{\"checks\":" << checks
           << ",\"failures\":0,\"hardware\":true,\"native_integration\":false}\n";
    CHECK(bool(report));
    std::cout << "PASS checks=" << checks << " real_gpu=1 native_integration=0\n";
    return 0;
} catch (const std::exception& e) {
    std::cerr << "FAIL " << e.what() << " checks=" << checks << '\n';
    return 1;
}
