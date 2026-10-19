// Isolated parser-boundary fixture; coordinator builds/runs after native closes.
// Reuse the frozen fixture's actual VIF/VU/GIF/GS backend without modifying it.
#define main frozen_worker_fixture_main
#include "../vif_worker_check/main.cpp"
#undef main
#include "../../build-ninja/m2-vif-async-integration/vif_cursor.h"
using namespace vif_async_candidate;
namespace {
uint64_t pauseCount = 0, quotaCount = 0, boundaryCount = 0;
std::vector<Job> cursorJobs() {
    auto jobs = fixtureJobs();
    std::vector<uint8_t> formats;
    word(formats, command(1, 0, 0x0203)); // skipped destination cycles
    word(formats, command(0x30));
    for (unsigned i = 0; i < 4; ++i)
        word(formats, 0x1020 + i);
    word(formats, command(0x31));
    for (unsigned i = 0; i < 4; ++i)
        word(formats, 0x2030 + i);
    word(formats, command(0x20));
    word(formats, 0xE4E4E4E4);
    for (unsigned vn = 0; vn < 4; ++vn)
        for (unsigned vl = 0; vl < 4; ++vl) {
            const unsigned op = 0x60 + (vn << 2) + vl;
            const auto code = command(op, 3, 100 + vn * 16 + vl * 4);
            word(formats, code);
            const unsigned bytes = payloadBytes(code, 0x0203);
            for (unsigned i = 0; i < bytes; ++i)
                formats.push_back(uint8_t(0x81 + i));
        }
    word(formats, command(1, 0, 0x0301)); // fill writes, fewer source vectors
    word(formats, command(5, 0, 2));      // row feedback
    const auto masked = command(0x7D, 7, 0x4000 | 200);
    word(formats, masked);
    for (unsigned i = 0; i < payloadBytes(masked, 0x0301); ++i)
        formats.push_back(uint8_t(3 + i));
    word(formats, command(5));
    word(formats, command(1, 0, 0x0101));
    const auto red = point(3, 0x800000FF);
    word(formats, command(0x50, 0, unsigned(red.size() / 16)));
    appendBytes(formats, red.data(), red.size());
    word(formats, command(0x15)); // true MSCALF synchronous parity, repeated launch is real
    jobs.insert(jobs.end() - 4, vif(std::move(formats)));
    return jobs;
}
void feed(Cursor& cursor, Backend& backend, const uint8_t* bytes, uint32_t size,
          uint32_t quotaBytes, uint32_t quotaCommands, bool pauses) {
    uint32_t pos = 0;
    unsigned iterations = 0;
    uint64_t deniedAt = ~uint64_t(0);
    bool denied = false;
    VIFRegisters atDenial{};
    size_t eventsAtDenial = 0;
    auto ready = [&](const Command& c) {
        if (pauses && c.inputStart != deniedAt) {
            deniedAt = c.inputStart;
            denied = true;
            atDenial = backend.runtime.memory().vif1_regs;
            eventsAtDenial = backend.events.size();
            ++pauseCount;
            return false;
        }
        return true;
    };
    for (;;) {
        if (++iterations > size * 4u + 1024u)
            throw std::runtime_error("cursor progress loop");
        const auto p = cursor.resume(bytes ? bytes + pos : nullptr, size - pos,
                                     {quotaBytes, quotaCommands}, ready);
        if (p.consumed > size - pos || p.consumed > quotaBytes || p.commands > quotaCommands)
            throw std::runtime_error("cursor exceeded bounded step");
        pos += p.consumed;
        if (p.reason == Reason::WaitVu || p.reason == Reason::WaitGif ||
            p.reason == Reason::WaitVuGif) {
            if (!denied ||
                std::memcmp(&atDenial, &backend.runtime.memory().vif1_regs, sizeof(atDenial)) ||
                backend.events.size() != eventsAtDenial)
                throw std::runtime_error("dependency yield changed command side effects");
            if (p.pending.headerBytes != 4 ||
                p.pending.receivedPayloadBytes != p.pending.payloadBytes)
                throw std::runtime_error("dependency cursor lost payload position");
            denied = false;
            continue;
        }
        if (p.reason == Reason::Quota) {
            ++quotaCount;
            continue;
        }
        if (p.reason == Reason::Stopped)
            throw std::runtime_error("unexpected stopped cursor");
        if (pos != size)
            throw std::runtime_error("cursor omitted source bytes");
        break;
    }
}
std::vector<uint8_t> scenario(bool useCursor, uint64_t split, uint32_t quotaBytes,
                              uint32_t quotaCommands, bool pauses,
                              std::vector<uint8_t>* atSplit = nullptr) {
    Backend backend;
    Cursor cursor(backend.runtime.memory());
    uint64_t stream = 0;
    const std::atomic<bool> stop{false};
    for (auto job : cursorJobs()) {
        if (job.kind == Kind::Reset)
            cursor.reinitialize();
        if (job.kind != Kind::Vif) {
            backend.execute(job, stop);
            continue;
        }
        const auto n = uint32_t(job.bytes.size());
        const uint32_t first =
            split >= stream && split <= stream + n ? uint32_t(split - stream) : n;
        auto segment = [&](uint32_t start, uint32_t length) {
            if (useCursor)
                feed(cursor, backend, job.bytes.data() + start, length, quotaBytes, quotaCommands,
                     pauses);
            else
                backend.execute(
                    vif({job.bytes.begin() + start, job.bytes.begin() + start + length}), stop);
            backend.arbiter.drain();
        };
        segment(0, first);
        if (atSplit && atSplit->empty() && split >= stream && split <= stream + n)
            *atSplit = backend.snapshot();
        if (first < n)
            segment(first, n - first);
        backend.arbiter.drain();
        stream += n;
    }
    return backend.snapshot();
}
void allBoundaries(const fs::path& output) {
    uint64_t total = 0;
    for (const auto& job : cursorJobs())
        if (job.kind == Kind::Vif)
            total += job.bytes.size();
    const auto baseline = scenario(false, 0, 65536, 64, false);
    save(output / "serial.bin", baseline);
    auto full = scenario(true, 0, 65536, 64, false);
    save(output / "cursor.bin", full);
    check(baseline == full,
          "cursor complete-command wrapper matches full real state/GIF/capture/VRAM");
    for (uint64_t boundary = 0; boundary <= total; ++boundary) {
        std::vector<uint8_t> serialPrefix, cursorPrefix;
        auto expected = scenario(false, boundary, 65536, 64, false, &serialPrefix);
        auto actual = scenario(true, boundary, 65536, 64, false, &cursorPrefix);
        ++boundaryCount;
        if (expected != baseline || actual != baseline || serialPrefix.empty() ||
            serialPrefix != cursorPrefix) {
            const auto different =
                std::mismatch(actual.begin(), actual.end(), baseline.begin(), baseline.end());
            std::fprintf(stderr, "BOUNDARY FAIL split=%llu offset=%zu\n",
                         (unsigned long long)boundary, size_t(different.first - actual.begin()));
            save(output / "failure.bin", actual);
            save(output / "serial-prefix.bin", serialPrefix);
            save(output / "cursor-prefix.bin", cursorPrefix);
            check(false, "every byte-boundary real full-state parity");
            return;
        }
    }
    check(true, "every byte-boundary paused-prefix and final real "
                "VIF/VU/data/code/GIF/display/VRAM parity");
    for (uint32_t q : {1u, 2u, 3u, 4u, 7u, 16u, 63u, 65536u}) {
        auto actual = scenario(true, 0, q, 1, true);
        check(actual == baseline,
              "bounded byte/one-command quota plus dependency pauses preserve full real state");
    }
    check(pauseCount > 0 && quotaCount > 0, "dependency and quota branches actually exercised");
}
void partialStopReset() {
    Backend backend;
    Cursor cursor(backend.runtime.memory());
    auto& memory = backend.runtime.memory();
    std::vector<uint8_t> partial;
    word(partial, command(0x6C, 2, 42));
    word(partial, 0xDEADBEEF);
    const auto p = cursor.resume(partial.data(), uint32_t(partial.size()));
    const auto position = cursor.position();
    uint32_t unchanged = 0;
    std::memcpy(&unchanged, memory.getVU1Data() + 42 * 16, 4);
    check(p.reason == Reason::NeedInput && p.consumed == 8 && p.commands == 0 &&
              position.headerBytes == 4 && position.receivedPayloadBytes == 4 &&
              position.payloadBytes == 32 && position.code == command(0x6C, 2, 42) &&
              memory.vif1_regs.code == position.code && unchanged == 0,
          "partial UNPACK has exact cursor/CODE position and no premature data write");
    cursor.stop();
    std::vector<uint8_t> remainder(28, 0xAA);
    const auto stopped = cursor.resume(remainder.data(), 28);
    check(stopped.reason == Reason::Stopped && stopped.consumed == 0 && backend.events.empty() &&
              cursor.ownedBytes() == 0,
          "stop rejects input and retires unexecuted payload without callback");
    const auto generation = cursor.generation();
    memory.writeIORegister(0x10003C10, 1);
    cursor.reinitialize();
    std::vector<uint8_t> mark;
    word(mark, command(7, 0, 0x4321));
    cursor.synchronous(mark.data(), 4);
    check(cursor.generation() == generation + 1 && memory.vif1_regs.mark == 0x4321 &&
              memory.vif1_regs.code == command(7, 0, 0x4321) && cursor.empty(),
          "real FBRST plus new cursor generation cannot finish stale payload");
    for (unsigned split = 1; split < 4; ++split) {
        Cursor small(memory);
        auto code = command(0x14);
        const auto before = memory.vif1_regs;
        const auto events = backend.events.size();
        const auto a = small.resume(reinterpret_cast<const uint8_t*>(&code), split);
        check(a.reason == Reason::NeedInput && a.commands == 0 &&
                  std::memcmp(&before, &memory.vif1_regs, sizeof(before)) == 0 &&
                  backend.events.size() == events,
              "partial command header changes no register or VU/GIF side effect");
        small.stop();
    }
    Cursor narrow(memory, 8);
    std::vector<uint8_t> large;
    word(large, command(0x50, 0, 1));
    bool rejected = false;
    try {
        narrow.resume(large.data(), 4);
    } catch (const std::length_error&) {
        rejected = true;
    }
    check(rejected && narrow.ownedBytes() == 0 && narrow.stopped(),
          "owned input bound rejects and retires oversized payload before allocation/execution");
    Cursor zero(memory);
    const auto z = zero.resume(mark.data(), 4, {4, 0});
    check(z.reason == Reason::Quota && z.consumed == 0 && z.commands == 0 && zero.empty(),
          "zero command quota cannot consume or duplicate a command");
    // Declared maximum DIRECT payload is framed but not interpreted or allocated.
    std::vector<uint8_t> maximum;
    word(maximum, command(0x50));
    Cursor bounded(memory);
    auto m = bounded.resume(maximum.data(), 4);
    check(m.reason == Reason::NeedInput && m.pending.payloadBytes == 1048576 &&
              bounded.ownedBytes() == 4,
          "DIRECT zero IMM retains bounded declared 1 MiB payload position");
    bounded.stop();
}
void originalVifCountBeforeMusic() {
    // This is a control-flow model of 18D650/18D160, NOT live DMAC/IRQ plumbing.
    Gate firstGate, secondGate;
    std::atomic<unsigned> executions{0};
    OrderedWorker queue(91, 4096, 3, [&](const Job&, const std::atomic<bool>& stop) {
        const auto ordinal = ++executions;
        (ordinal == 1 ? firstGate : secondGate).enter(stop);
    });
    auto first = queue.submit(vif(std::vector<uint8_t>(16)));
    check(await([&] { return firstGate.entered.load(); }),
          "original dependency model enters first VIF");
    std::atomic<unsigned> count{2};
    std::atomic<bool> irqAdmitted{false}, path3Accepted{false}, musicWake{false};
    std::thread irq([&] {
        irqAdmitted = true;
        if (queue.wait(first.ticket) != Result::Executed)
            return;
        --count; // models original DMAC retirement AFTER real ticket completion
        auto second = queue.submit(vif(std::vector<uint8_t>(16)));
        if (!second.accepted || queue.wait(second.ticket) != Result::Executed)
            return;
        --count;
        if (count != 0 || (queue.publication().dma[1].chcr & 0x100))
            return;
        path3Accepted = true; // ideal zero-latency PATH3 AFTER the original VIF wait
        musicWake = true;
    });
    check(await([&] { return irqAdmitted.load(); }) && count == 2 && !path3Accepted && !musicWake &&
              (queue.publication().dma[1].chcr & 0x100),
          "fast PATH3 cannot wake music before original pre-PATH3 VIF/count dependency");
    firstGate.open();
    check(await([&] { return secondGate.entered.load(); }) && count == 1 && !path3Accepted &&
              !musicWake && (queue.publication().dma[1].chcr & 0x100),
          "one true completion decrements one entry and next VIF still blocks original music wake");
    secondGate.open();
    irq.join();
    queue.stop();
    check(count == 0 && path3Accepted && musicWake && queue.publication().dstat == 2 &&
              queue.idle(),
          "music wake follows complete ordered VIF retirement even with ideal PATH3");
}
} // namespace
int main(int argc, char** argv) try {
    if (argc != 2) {
        std::fprintf(stderr, "Usage: EXE FRESH_OUTPUT_DIRECTORY\n");
        return 2;
    }
    const fs::path output = argv[1];
    if (fs::exists(output) && !fs::is_empty(output))
        throw std::runtime_error("output must be empty");
    fs::create_directories(output);
    _putenv_s("REO_HEADLESS", "1");
    _putenv_s("REO_GS_THREAD", "0");
    _putenv_s("REO_GS_DISPATCH_PACE", "0");
    _putenv_s("REO_VU1_DUMP", "");
    _putenv_s("REO_VU1_TIMING_AT", "");
    _putenv_s("REO_VIF1_DUMP", "");
    allBoundaries(output);
    partialStopReset();
    originalVifCountBeforeMusic();
    std::printf("VIF_CURSOR_FIXTURE checks=%u failures=%u boundaries=%llu pauses=%llu quotas=%llu "
                "native_integration=0\n",
                checks.load(), failures.load(), (unsigned long long)boundaryCount,
                (unsigned long long)pauseCount, (unsigned long long)quotaCount);
    return failures ? 1 : 0;
} catch (const std::exception& error) {
    std::fprintf(stderr, "ERROR %s\n", error.what());
    return 2;
}
