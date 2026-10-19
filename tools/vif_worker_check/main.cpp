// Coordinator-built isolated fixture: real VIF/VU/GIF/GS and guest CPU scopes,
// modeled DMA publication. No game input, audio substitution or live hooks.
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include "runtime/ps2_gs_gpu.h"
#include "../../third_party/PS2Recomp/ps2xRuntime/src/lib/ps2_guest_sched.h"
#include "../../build-ninja/m2-vif-worker-prototype/ordered_worker.h"
#include <algorithm>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <mutex>
#include <stdexcept>
#include <string>
#include <thread>

uint32_t ps2IoRegLockDepth() noexcept;
namespace fs = std::filesystem;
using namespace vif_worker_prototype;
namespace {
std::atomic<unsigned> checks{0}, failures{0};
void check(bool ok, const char* name) {
    ++checks;
    if (!ok)
        ++failures;
    std::printf("%s %s\n", ok ? "PASS" : "FAIL", name);
}
template <class Pred> bool await(Pred predicate) {
    const auto deadline = std::chrono::steady_clock::now() + std::chrono::seconds(3);
    while (!predicate() && std::chrono::steady_clock::now() < deadline)
        std::this_thread::yield();
    return predicate();
}
struct Gate {
    std::mutex mutex;
    std::condition_variable cv;
    std::atomic<bool> entered{false};
    bool opened = false;
    void enter(const std::atomic<bool>& stop) {
        std::unique_lock<std::mutex> lock(mutex);
        entered = true;
        cv.notify_all();
        const auto deadline = std::chrono::steady_clock::now() + std::chrono::seconds(3);
        while (!opened && !stop.load()) {
            if (cv.wait_until(lock, std::min(deadline, std::chrono::steady_clock::now() +
                                                           std::chrono::milliseconds(10))) ==
                    std::cv_status::timeout &&
                std::chrono::steady_clock::now() >= deadline)
                throw std::runtime_error("fixture gate timeout");
        }
    }
    void open() {
        {
            std::lock_guard<std::mutex> lock(mutex);
            opened = true;
        }
        cv.notify_all();
    }
};
template <class T> void append(std::vector<uint8_t>& out, const T& value) {
    const auto* bytes = reinterpret_cast<const uint8_t*>(&value);
    out.insert(out.end(), bytes, bytes + sizeof(value));
}
void appendBytes(std::vector<uint8_t>& out, const void* data, size_t size) {
    const auto* bytes = static_cast<const uint8_t*>(data);
    out.insert(out.end(), bytes, bytes + size);
}
void word(std::vector<uint8_t>& bytes, uint32_t value) {
    append(bytes, value);
}
uint32_t command(unsigned op, unsigned count = 0, unsigned imm = 0) {
    return (op << 24) | (count << 16) | imm;
}
std::vector<uint8_t> gif(std::initializer_list<std::pair<uint64_t, uint64_t>> writes) {
    std::vector<uint8_t> result;
    append(result, uint64_t(writes.size()) | 0x8000ull | (1ull << 60));
    append(result, 0xEull);
    for (const auto& [value, reg] : writes) {
        append(result, value);
        append(result, reg);
    }
    return result;
}
std::vector<uint8_t> point(unsigned x, uint32_t color) {
    return gif({{color, 1}, {x * 16u, 5}});
}
Job vif(std::vector<uint8_t> bytes, bool dma = true) {
    Job job;
    job.kind = Kind::Vif;
    job.bytes = std::move(bytes);
    job.channel = dma ? 1 : 10;
    job.qwc = uint32_t((job.bytes.size() + 15) / 16);
    job.madr = 0x20000;
    job.tadr = 0x34560;
    return job;
}
Job path3(std::vector<uint8_t> bytes) {
    Job job;
    job.kind = Kind::Path3;
    job.bytes = std::move(bytes);
    job.channel = 2;
    job.qwc = uint32_t(job.bytes.size() / 16);
    return job;
}
Job capture(unsigned number = 0) {
    Job job;
    job.kind = Kind::Capture;
    GSRegisters regs{};
    regs.pmode = 1;
    regs.smode2 = 2;
    regs.dispfb1 = 1ull << 9;
    regs.display1 = (63ull << 32) | (63ull << 44);
    append(job.metadata, regs);
    append(job.metadata, number);
    return job;
}
struct Backend {
    PS2Runtime runtime;
    GifArbiter arbiter;
    std::vector<uint8_t> events, captures;
    std::vector<uint32_t> capturePixels;
    Gate* gate = nullptr;
    std::atomic<bool> gateFirst{false};
    Backend() {
        if (!runtime.initialize("isolated VIF worker fixture"))
            throw std::runtime_error("runtime init");
        auto& memory = runtime.memory();
        std::memset(memory.getVU1Code(), 0, PS2_VU1_CODE_SIZE);
        std::memset(memory.getVU1Data(), 0, PS2_VU1_DATA_SIZE);
        std::memset(memory.getGSVRAM(), 0, PS2_GS_VRAM_SIZE);
        memory.vif1_regs = {};
        arbiter.setProcessPacketFn([this](const uint8_t* bytes, uint32_t size) {
            word(events, 3);
            word(events, size);
            appendBytes(events, bytes, size);
            runtime.gs().processGIFPacket(bytes, size);
        });
        memory.setGifArbiter(&arbiter);
        memory.setVu1MscalCallback([this](uint32_t pc, uint32_t itop) {
            word(events, 1);
            word(events, pc);
            word(events, itop);
            stateEvent();
            auto& mem = runtime.memory();
            runtime.vu1().execute(mem.getVU1Code(), PS2_VU1_CODE_SIZE, mem.getVU1Data(),
                                  PS2_VU1_DATA_SIZE, runtime.gs(), &mem, pc, itop, 65536);
            stateEvent();
        });
        memory.setVu1MscntCallback([this](uint32_t itop) {
            word(events, 2);
            word(events, itop);
            stateEvent();
            auto& mem = runtime.memory();
            runtime.vu1().resume(mem.getVU1Code(), PS2_VU1_CODE_SIZE, mem.getVU1Data(),
                                 PS2_VU1_DATA_SIZE, runtime.gs(), &mem, itop, 65536);
            stateEvent();
            if (itop == 78)
                check(runtime.vu1().state().pc == 64 && runtime.vu1().state().vi[1] == 5 &&
                          runtime.vu1().state().vi[2] == 9 && runtime.vu1().state().vi[7] == 321 &&
                          runtime.vu1().state().vi[8] == 77,
                      "real MPG/MSCAL/XTOP/XITOP/E-delay/MSCNT state oracle");
        });
    }
    ~Backend() {
        runtime.memory().setGifArbiter(nullptr);
    }
    void stateEvent() {
        const auto& mem = runtime.memory();
        append(events, mem.vif1_regs);
        append(events, runtime.vu1().state());
        appendBytes(events, runtime.memory().getVU1Code(), PS2_VU1_CODE_SIZE);
        appendBytes(events, runtime.memory().getVU1Data(), PS2_VU1_DATA_SIZE);
    }
    void execute(const Job& job, const std::atomic<bool>& stop) {
        if (ps2IoRegLockDepth() != 0)
            throw std::logic_error("worker entered backend holding IO");
        if (job.kind == Kind::Vif && gateFirst.exchange(false) && gate)
            gate->enter(stop);
        if (stop.load())
            return;
        auto& mem = runtime.memory();
        switch (job.kind) {
            case Kind::Vif:
                mem.processVIF1Data(job.bytes.data(), uint32_t(job.bytes.size()));
                arbiter.drain();
                break;
            case Kind::Path3:
                mem.submitGifPacket(GifPathId::Path3, job.bytes.data(), uint32_t(job.bytes.size()));
                break;
            case Kind::Capture: {
                if (job.metadata.size() != sizeof(GSRegisters) + 4)
                    throw std::runtime_error("capture metadata");
                std::memcpy(&mem.gs(), job.metadata.data(), sizeof(GSRegisters));
                arbiter.drain();
                runtime.gs().latchHostPresentationFrame();
                std::vector<uint8_t> pixels;
                uint32_t width = 0, height = 0;
                if (!runtime.gs().copyLatchedHostPresentationFrame(pixels, width, height) ||
                    width != 64 || height != 64)
                    throw std::runtime_error("actual display capture");
                append(captures, width);
                append(captures, height);
                appendBytes(captures, pixels.data(), pixels.size());
                uint32_t pixel = 0;
                std::memcpy(&pixel, pixels.data() + 4, 4);
                capturePixels.push_back(pixel & 0xFFFFFFu);
                break;
            }
            case Kind::RegisterWrite: {
                if (job.bytes.size() != 8)
                    throw std::runtime_error("register record");
                uint32_t address = 0, value = 0;
                std::memcpy(&address, job.bytes.data(), 4);
                std::memcpy(&value, job.bytes.data() + 4, 4);
                mem.writeIORegister(address, value);
                break;
            }
            case Kind::Reset:
                mem.writeIORegister(0x10003C10, 1);
                runtime.vu1().reset();
                break;
            case Kind::Fence:
                arbiter.drain();
                break;
        }
    }
    std::vector<uint8_t> snapshot() {
        auto& mem = runtime.memory();
        std::vector<uint8_t> bytes;
        const uint32_t header[] = {0x57464956,
                                   1,
                                   sizeof(VIFRegisters),
                                   sizeof(VU1State),
                                   PS2_VU1_CODE_SIZE,
                                   PS2_VU1_DATA_SIZE,
                                   uint32_t(PS2_GS_VRAM_SIZE),
                                   uint32_t(events.size()),
                                   uint32_t(captures.size())};
        appendBytes(bytes, header, sizeof(header));
        append(bytes, mem.vif1_regs);
        append(bytes, runtime.vu1().state());
        appendBytes(bytes, mem.getVU1Code(), PS2_VU1_CODE_SIZE);
        appendBytes(bytes, mem.getVU1Data(), PS2_VU1_DATA_SIZE);
        appendBytes(bytes, mem.getGSVRAM(), PS2_GS_VRAM_SIZE);
        appendBytes(bytes, events.data(), events.size());
        appendBytes(bytes, captures.data(), captures.size());
        return bytes;
    }
};

std::vector<Job> fixtureJobs() {
    std::vector<Job> jobs;
    jobs.push_back(path3(gif({{1ull << 16, 0x4C},
                              {(63ull << 16) | (63ull << 48), 0x40},
                              {0, 0x18},
                              {1ull << 32, 0x4E},
                              {0, 0x47},
                              {0, 0},
                              {0x8000FF00, 1}})));
    std::vector<uint8_t> program;
    const uint32_t pairs[][2] = {{0x1003000Au, 0x2FF},      {0x800706BCu, 0x2FF},
                                 {0x800806BDu, 0x2FF},      {0x80001EFCu, 0x2FF},
                                 {0x8000033Cu, 0x400002FF}, {0x10010005u, 0x2FF},
                                 {0x10020009u, 0x400002FF}, {0x8000033Cu, 0x2FF}};
    word(program, command(0x4A, 8));
    appendBytes(program, pairs, sizeof(pairs));
    // Two descriptor boundaries inside MPG: carry lives exclusively on the worker.
    jobs.push_back(vif({program.begin(), program.begin() + 28}));
    jobs.push_back(vif({program.begin() + 28, program.end()}));
    const auto packet = point(0, 0x8000FF00);
    std::vector<uint8_t> data;
    word(data, command(1, 0, 0x0101));
    word(data, command(0x6C, 3, 10));
    appendBytes(data, packet.data(), packet.size());
    word(data, command(3, 0, 321));
    word(data, command(2, 0, 4));
    word(data, command(4, 0, 77));
    word(data, command(0x14));
    jobs.push_back(vif(std::move(data)));
    jobs.push_back(capture(0));
    std::vector<uint8_t> resume;
    word(resume, command(4, 0, 78));
    word(resume, command(0x10));
    word(resume, command(0x11));
    word(resume, command(0x13));
    word(resume, command(0x17));
    jobs.push_back(vif(std::move(resume)));
    // Mask ownership and FIFO must remain with the same worker as VIF parsing.
    std::vector<uint8_t> mask;
    word(mask, command(6, 0, 0x8000));
    jobs.push_back(vif(std::move(mask)));
    jobs.push_back(path3(point(1, 0x800000FF)));
    jobs.push_back(capture(1));
    std::vector<uint8_t> direct;
    const auto blue = point(2, 0x80FF0000);
    word(direct, command(0x51, 0, 3));
    appendBytes(direct, blue.data(), blue.size());
    jobs.push_back(vif(std::move(direct)));
    std::vector<uint8_t> unmask;
    word(unmask, command(6));
    jobs.push_back(vif(std::move(unmask)));
    jobs.push_back(capture(2));
    std::vector<uint8_t> wrap;
    word(wrap, command(0x6C, 2, 1023));
    for (unsigned i = 0; i < 8; ++i)
        word(wrap, 0xABCD0000 + i);
    word(wrap, command(0x4A, 2, 2047));
    for (unsigned i = 0; i < 4; ++i)
        word(wrap, 0x12340000 + i);
    jobs.push_back(vif(std::move(wrap)));
    // Reset invalidates an incomplete old payload; a fresh MARK cannot finish it.
    std::vector<uint8_t> partial;
    word(partial, command(0x6C, 2, 42));
    word(partial, 0xDEADBEEF);
    jobs.push_back(vif(std::move(partial)));
    Job reset;
    reset.kind = Kind::Reset;
    jobs.push_back(std::move(reset));
    std::vector<uint8_t> mark;
    word(mark, command(7, 0, 0x1234));
    jobs.push_back(vif(std::move(mark)));
    return jobs;
}
void save(const fs::path& path, const std::vector<uint8_t>& bytes) {
    std::ofstream file(path, std::ios::binary);
    file.write(reinterpret_cast<const char*>(bytes.data()), bytes.size());
    if (!file)
        throw std::runtime_error("cannot write fixture output");
}
void parity(const fs::path& output) {
    std::vector<uint8_t> serial, threaded;
    for (bool worker : {false, true}) {
        Backend backend;
        const std::atomic<bool> stop{false};
        std::unique_ptr<OrderedWorker> queue;
        if (worker)
            queue = std::make_unique<OrderedWorker>(
                1, 1024 * 1024, 8,
                [&](const Job& j, const std::atomic<bool>& s) { backend.execute(j, s); });
        for (auto job : fixtureJobs()) {
            if (worker) {
                auto accepted = queue->submit(std::move(job));
                check(accepted.accepted && queue->wait(accepted.ticket) == Result::Executed,
                      "worker transaction completed");
            } else
                backend.execute(job, stop);
        }
        check(backend.capturePixels.size() == 3 && backend.capturePixels[0] == 0 &&
                  backend.capturePixels[1] == 0 && backend.capturePixels[2] == 0xFF,
              "actual display capture retains masked PATH3 until unmask");
        check(backend.runtime.memory().vif1_regs.mark == 0x1234 &&
                  backend.runtime.memory().vif1_regs.code == command(7, 0, 0x1234),
              "reset retires partial payload before new MARK");
        uint32_t wrapped = 0;
        std::memcpy(&wrapped, backend.runtime.memory().getVU1Data(), 4);
        check(wrapped == 0xABCD0004, "real VIF data wrap oracle");
        uint32_t wrappedCode = 0;
        std::memcpy(&wrappedCode, backend.runtime.memory().getVU1Code(), 4);
        check(wrappedCode == 0x12340002, "real MPG code wrap oracle");
        if (queue) {
            queue->stop();
            check(queue->idle(), "worker joined before final state observation");
        }
        auto bytes = backend.snapshot();
        save(output / (worker ? "worker.bin" : "serial.bin"), bytes);
        (worker ? threaded : serial) = std::move(bytes);
    }
    check(serial == threaded, "all VIF/VU code/data/state, ordered GIF callbacks, capture pixels "
                              "and final 4 MiB VRAM match serial");
}

void capacityStopReinit() {
    Gate gate;
    std::atomic<unsigned> executed{0};
    OrderedWorker queue(71, 4096, 1, [&](const Job&, const std::atomic<bool>& stop) {
        gate.enter(stop);
        if (!stop.load())
            ++executed;
    });
    auto job = vif(std::vector<uint8_t>(16));
    auto active = queue.submit(job);
    check(await([&] { return gate.entered.load(); }),
          "active transaction entered deterministic gate");
    const auto first = queue.publication();
    check((first.dma[1].chcr & 0x100) && first.dma[1].qwc == 1 && first.dstat == 0,
          "accepted input retains STR/QWC with no premature completion");
    check((queue.publication().dma[1].chcr & 0x100) != 0,
          "busy read is observational and cannot clear STR");
    Job fence;
    fence.kind = Kind::Fence;
    check(!queue.submit(fence, false).accepted,
          "bounded try-submit refuses saturated active capacity");
    std::atomic<bool> rejected{false};
    std::thread blocked([&] { rejected = !queue.submit(fence).accepted; });
    check(await([&] { return queue.capacityWaitersForFixture() == 1; }),
          "capacity waiter actually parked");
    queue.stop();
    blocked.join();
    check(rejected && executed == 0 && OrderedWorker::result(active.ticket) == Result::Cancelled,
          "stop wakes active completion and capacity waiters without execution");
    check(queue.publication().dstat == 0 && !(queue.publication().dma[1].chcr & 0x100) &&
              queue.idle(),
          "cancel retires busy state without fake D_STAT completion");
    OrderedWorker next(72, 4096, 3, [&](const Job&, const std::atomic<bool>&) { ++executed; });
    auto fresh = next.submit(job);
    check(next.wait(fresh.ticket) == Result::Executed && fresh.ticket->generation == 72,
          "new generation executes after old owner is joined");
    check(next.publication().dstat == 2 && next.publication().completed == fresh.ticket->sequence,
          "new generation publishes exactly its own VIF completion");
    next.stop();
    Gate failedGate;
    OrderedWorker failed(73, 4096, 3, [&](const Job&, const std::atomic<bool>& stop) {
        failedGate.enter(stop);
        throw std::runtime_error("injected execution failure");
    });
    auto bad = failed.submit(fence);
    check(await([&] { return failedGate.entered.load(); }), "failure injection gate entered");
    auto behind = failed.submit(fence);
    failedGate.open();
    check(failed.wait(bad.ticket) == Result::Failed &&
              failed.wait(behind.ticket) == Result::Cancelled,
          "executor failure poisons pending generation and wakes every waiter");
    failed.stop();
}

void sourceOwnership() {
    Backend backend;
    Gate gate;
    backend.gate = &gate;
    backend.gateFirst = true;
    OrderedWorker queue(80, 4096, 4, [&](const Job& job, const std::atomic<bool>& stop) {
        backend.execute(job, stop);
    });
    std::vector<uint8_t> original;
    word(original, command(7, 0, 0x4321));
    auto job = vif(original);
    job.asr0 = 0x556600;
    job.asr1 = 0x778800;
    auto accepted = queue.submit(job);
    check(await([&] { return gate.entered.load(); }),
          "source-copy fixture gates before parser execution");
    word(original, command(7, 0, 0xFFFF));
    std::fill(job.bytes.begin(), job.bytes.end(), 0);
    const auto busy = queue.publication().dma[1];
    check(busy.madr == 0x20000 && busy.tadr == 0x34560 && busy.asr0 == 0x556600 &&
              busy.asr1 == 0x778800,
          "accepted descriptor owns final tag/address/stack publication");
    bool overwriteRejected = false;
    try {
        queue.submit(vif(std::vector<uint8_t>(16)), false);
    } catch (const std::logic_error&) {
        overwriteRejected = true;
    }
    check(overwriteRejected, "concurrent DMA cannot overwrite the active channel");
    gate.open();
    check(queue.wait(accepted.ticket) == Result::Executed,
          "owned source executes after caller mutation");
    queue.stop();
    check(backend.runtime.memory().vif1_regs.mark == 0x4321,
          "worker observes owned original bytes after caller source is changed");
}

void guestCpuAndIrqDependency() {
    Backend backend;
    Gate gate;
    backend.gate = &gate;
    backend.gateFirst = true;
    auto& runtime = backend.runtime;
    R5900Context context{};
    context.pc = 0x1033E8;
    SET_GPR_U32((&context), 31, 0x18D57C);
    runtime.Store32(runtime.memory().getRDRAM(), &context, 0x1000E000, 1);
    OrderedWorker queue(81, 65536, 8, [&](const Job& job, const std::atomic<bool>& stop) {
        backend.execute(job, stop);
    });
    std::atomic<bool> irqSubmitted{false}, irqIo{false}, readyGuest{false}, audioWake{false},
        audioRan{false}, mainReturned{false};
    std::atomic<bool> start{false};
    Ticket irqTicket, captureTicket;
    constexpr int Main = 101, Ready = 102, Audio = 103;
    for (auto [tid, priority] : {std::pair{Main, 24}, std::pair{Ready, 18}, std::pair{Audio, 16}}) {
        ps2_sched::setPriority(tid, priority);
        ps2_sched::setSuspended(tid, false);
    }
    std::thread irq([&] {
        ps2_sched::setCurrentThread(-1);
        if (!await([&] { return start.load(); }))
            return;
        PS2Runtime::GuestExecutionScope cpu(&runtime);
        R5900Context ctx{};
        irqIo = runtime.Load32(runtime.memory().getRDRAM(), &ctx, 0x1000E000) == 1;
        // Conservative PATH3 completion follows execution. Original wake happens
        // after this wait, so it cannot wake sleeping music while prior VIF runs.
        {
            PS2Runtime::GuestExecutionReleaseScope release(&runtime);
            auto packet = queue.submit(path3(point(1, 0x800000FF)));
            irqTicket = packet.ticket;
            auto captureJob = queue.submit(capture(1));
            captureTicket = captureJob.ticket;
            irqSubmitted = true;
            queue.wait(irqTicket);
        }
        audioWake = true;
    });
    std::thread ready([&] {
        ps2_sched::setCurrentThread(Ready);
        if (!await([&] { return irqSubmitted.load(); }))
            return;
        PS2Runtime::GuestExecutionScope cpu(&runtime);
        R5900Context ctx{};
        readyGuest = runtime.Load32(runtime.memory().getRDRAM(), &ctx, 0x1000E000) == 1;
    });
    std::thread audio([&] {
        ps2_sched::setCurrentThread(Audio);
        if (!await([&] { return audioWake.load(); }))
            return;
        PS2Runtime::GuestExecutionScope cpu(&runtime);
        audioRan = true;
    });
    std::thread controller([&] {
        const bool passed = await([&] { return irqSubmitted.load() && readyGuest.load(); });
        check(passed && irqIo && gate.entered,
              "IRQ and ready producer acquire actual CPU and real IO while VIF waits");
        if (passed) {
            check(!audioRan && !audioWake,
                  "negative control: sleeping music remains unwoken behind blocking IRQ PATH3");
            check(OrderedWorker::result(irqTicket) == Result::Pending &&
                      OrderedWorker::result(captureTicket) == Result::Pending && !mainReturned,
                  "later PATH3/capture cannot overtake incomplete VIF output prefix");
            check((queue.publication().dma[1].chcr & 0x100) != 0 && queue.publication().dstat == 0,
                  "in-flight VIF never publishes STR/D_STAT completion while gated");
        }
        gate.open();
    });
    ps2_sched::setCurrentThread(Main);
    {
        PS2Runtime::GuestExecutionScope cpu1(&runtime), cpu2(&runtime);
        volatile uint32_t local = 0x7654ABCD;
        const uint32_t pc = context.pc, ra = GPR_U32((&context), 31);
        {
            PS2Runtime::GuestExecutionReleaseScope release(&runtime);
            auto packet = queue.submit(vif(std::vector<uint8_t>(16)));
            check(await([&] { return gate.entered.load(); }),
                  "VIF worker begins without guest CPU ownership");
            start = true;
            check(queue.wait(packet.ticket) == Result::Executed,
                  "main waits for actual synchronous transaction completion");
        }
        check(context.pc == pc && GPR_U32((&context), 31) == ra && local == 0x7654ABCD,
              "nested CPU release restores PC/RA/native stack state");
        mainReturned = true;
    }
    controller.join();
    irq.join();
    ready.join();
    audio.join();
    check(audioRan, "music-priority guest eventually runs after original IRQ dependency clears");
    queue.wait(captureTicket);
    queue.stop();
    check(queue.publication().dstat == 6 && queue.idle(),
          "both DMA channels complete only after real worker execution");
    for (int tid : {Main, Ready, Audio})
        ps2_sched::forget(tid);
    ps2_sched::setCurrentThread(-1);
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
    parity(output);
    capacityStopReinit();
    sourceOwnership();
    guestCpuAndIrqDependency();
    std::printf("VIF_WORKER_FIXTURE checks=%u failures=%u native_integration=0\n", checks.load(),
                failures.load());
    return failures ? 1 : 0;
} catch (const std::exception& error) {
    std::fprintf(stderr, "ERROR %s\n", error.what());
    return 2;
}
