// No game assets or guest state forcing: real scheduler, IRQ registry and GS.
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include "ps2_syscalls.h"
#include "runtime/ps2_gs_gpu.h"
#include "Syscalls/Interrupt.h"
#include "../../third_party/PS2Recomp/ps2xRuntime/src/lib/ps2_guest_sched.h"
#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <thread>
#include <vector>

namespace ps2_syscalls {
bool RunVblankCaptureFixtureBoundary(uint8_t*, PS2Runtime*, bool, void (*)(void*), void*);
void joinInterruptWorker();
} // namespace ps2_syscalls
namespace ps2_sched {
std::string debugState(int);
}
namespace {
constexpr uint32_t Handler1 = 0x10000u, Handler2 = 0x10004u;
constexpr int ProducerTid = 100;
std::atomic<unsigned> failures{0}, handlerCalls{0};
std::atomic<bool> armed{false};
unsigned handlerOrder[2]{};
void fail(const char* reason) {
    ++failures;
    std::printf("FAIL %s\n", reason);
}
bool await(const std::atomic<bool>& flag) {
    const auto deadline = std::chrono::steady_clock::now() + std::chrono::seconds(3);
    while (!flag.load(std::memory_order_acquire) && std::chrono::steady_clock::now() < deadline)
        std::this_thread::yield();
    return flag.load(std::memory_order_acquire);
}
void handler(uint8_t*, R5900Context* ctx, PS2Runtime* rt) {
    if (armed.load(std::memory_order_acquire)) {
        const unsigned n = handlerCalls.fetch_add(1);
        if (n < 2)
            handlerOrder[n] = GPR_U32(ctx, 5);
        // A privileged post-flip surface selection, as in an original handler.
        rt->memory().gs().dispfb1 = (1ull << 9) | 32u;
    }
    ctx->pc = 0;
}
int addHandler(PS2Runtime& rt, uint32_t pc, uint32_t order, uint32_t arg) {
    R5900Context ctx{};
    SET_GPR_U32(&ctx, 4, 2);
    SET_GPR_U32(&ctx, 5, pc);
    SET_GPR_U32(&ctx, 6, order);
    SET_GPR_U32(&ctx, 7, arg);
    ps2_syscalls::AddIntcHandler(rt.memory().getRDRAM(), &ctx, &rt);
    // Registration starts the actual clock worker. Stop/join it so this
    // fixture drives one precise boundary rather than racing a second clock.
    ps2_syscalls::joinInterruptWorker();
    return static_cast<int>(GPR_U32((&ctx), 2));
}
struct Case {
    PS2Runtime* rt = nullptr;
    bool legacy = false, cancel = false;
    std::atomic<bool> start{false}, attempted{false}, drawn{false}, finished{false};
};
void between(void* user) {
    auto& c = *static_cast<Case*>(user);
    c.start.store(true, std::memory_order_release);
    if (!await(c.attempted))
        fail("producer failed to attempt real guest admission");
    if (c.legacy) {
        if (!await(c.finished) || !c.drawn.load())
            fail("legacy gap failed to admit drawing guest");
    } else {
        ps2_sched::awaitQueued(ProducerTid, 200000);
        // Await actual scheduler queue admission, not an arbitrary sleep.
        if (!ps2_sched::debugState(ProducerTid).ends_with("/1"))
            fail("producer not queued in actual scheduler");
        if (c.finished.load() || c.drawn.load())
            fail("producer crossed atomic postflip boundary");
        if (c.cancel)
            c.rt->requestStop();
    }
}
bool captured(PS2Runtime& rt, uint32_t expectedFbp, uint8_t first) {
    std::vector<uint8_t> pixels;
    uint32_t width = 0, height = 0, fbp = ~0u, source = ~0u;
    bool preferred = true;
    rt.gs().getLastDisplayBaseBytes(); // Outside guest ownership; drain marker and later draw.
    const bool ok =
        rt.gs().copyLatchedHostPresentationFrame(pixels, width, height, &fbp, &source, &preferred);
    if (!ok || width != 64 || height != 64 || fbp != expectedFbp || source != expectedFbp ||
        preferred || pixels.size() != 64u * 64u * 4u)
        return false;
    for (size_t i = 0; i < pixels.size(); i += 4u) {
        const uint8_t expected = i == 0 ? first : 255u;
        if (pixels[i] != expected || pixels[i + 1u] != expected || pixels[i + 2u] != expected)
            return false;
    }
    return true;
}
enum Registry { None, One, Masked, Disabled, Multiple };
void runCase(const char* name, bool legacy, Registry registry, bool cancel = false) {
    armed = false;
    handlerCalls = 0;
    handlerOrder[0] = handlerOrder[1] = 0;
    Case c;
    c.legacy = legacy;
    c.cancel = cancel;
    {
        PS2Runtime rt;
        c.rt = &rt;
        if (!rt.initialize("vblank boundary fixture")) {
            fail("runtime initialization");
            return;
        }
        rt.registerFunction(Handler1, handler);
        rt.registerFunction(Handler2, handler);
        int id = 0;
        if (registry != None) {
            id = addHandler(rt, Handler1, 0, 1);
            if (id != 1)
                fail("fresh runtime retained INTC handler IDs");
        }
        if (registry == Multiple && addHandler(rt, Handler2, 1, 2) != 2)
            fail("second ordered INTC handler ID changed");
        R5900Context ctx{};
        // Lifecycle must reset the actual DMAC registry/IDs as well. Merely
        // resetting an unrelated TU's copies cannot pass this fresh-session check.
        SET_GPR_U32(&ctx, 4, 0);
        SET_GPR_U32(&ctx, 5, Handler1);
        ps2_syscalls::AddDmacHandler(rt.memory().getRDRAM(), &ctx, &rt);
        ps2_syscalls::joinInterruptWorker();
        if (GPR_U32((&ctx), 2) != 1u)
            fail("fresh runtime retained DMAC handler IDs");
        if (registry == Masked) {
            SET_GPR_U32(&ctx, 4, 2);
            ps2_syscalls::DisableIntc(rt.memory().getRDRAM(), &ctx, &rt);
        }
        if (registry == Disabled) {
            SET_GPR_U32(&ctx, 5, uint32_t(id));
            ps2_syscalls::DisableIntcHandler(rt.memory().getRDRAM(), &ctx, &rt);
        }
        const uint32_t selected = (registry == One || registry == Multiple) ? 32u : 0u;
        std::memset(rt.memory().getGSVRAM(), 255, PS2_GS_VRAM_SIZE);
        auto& regs = rt.memory().gs();
        regs.pmode = 1;
        regs.smode2 = 2;
        regs.dispfb1 = 1ull << 9;
        regs.display1 = (63ull << 32) | (63ull << 44);
        auto& gs = rt.gs();
        gs.writeRegister(GS_REG_FRAME_1, (1ull << 16) | selected);
        gs.writeRegister(GS_REG_SCISSOR_1, (63ull << 16) | (63ull << 48));
        gs.writeRegister(GS_REG_XYOFFSET_1, 0);
        gs.writeRegister(GS_REG_ZBUF_1, 1ull << 32);
        gs.writeRegister(GS_REG_TEST_1, 0);
        gs.writeRegister(GS_REG_PRIM, 0);
        gs.writeRegister(GS_REG_RGBAQ, 0x3f80000080000000ull);
        gs.getLastDisplayBaseBytes();
        ps2_sched::setPriority(ProducerTid, 32);
        ps2_sched::setSuspended(ProducerTid, false);
        std::thread producer([&] {
            ps2_sched::setCurrentThread(ProducerTid);
            if (!await(c.start)) {
                fail("producer start timeout");
                c.finished = true;
                return;
            }
            c.attempted.store(true, std::memory_order_release);
            {
                PS2Runtime::GuestExecutionScope execution(&rt);
                if (!rt.isStopRequested()) {
                    gs.writeRegister(GS_REG_XYZ2, 0);
                    c.drawn = true;
                }
            }
            c.finished = true;
            ps2_sched::forget(ProducerTid);
            ps2_sched::setCurrentThread(-1);
        });
        ps2_sched::setCurrentThread(-1);
        armed = true;
        if (!ps2_syscalls::RunVblankCaptureFixtureBoundary(rt.memory().getRDRAM(), &rt, legacy,
                                                           between, &c))
            fail("private fixture entry disabled");
        producer.join();
        armed = false;
        const unsigned expectedCalls = registry == Multiple ? 2u : (registry == One ? 1u : 0u);
        if (handlerCalls.load() != expectedCalls || (expectedCalls && handlerOrder[0] != 1u) ||
            (expectedCalls == 2u && handlerOrder[1] != 2u))
            fail("enabled mask/handler order changed");
        if (cancel) {
            if (c.drawn.load())
                fail("stop admitted cancelled producer drawing");
        } else {
            if (!c.drawn.load())
                fail("producer did not resume after boundary");
            if (!captured(rt, selected, legacy ? 0u : 255u))
                fail("immutable first pixel/surface/queue-order mismatch");
            uint32_t current = ~0u;
            std::memcpy(&current, rt.memory().getGSVRAM() + selected * 8192u, 4u);
            if ((current & 0xffffffu) != 0u)
                fail("postmarker producer did not modify selected VRAM");
        }
        rt.requestStop();
    } // Real stop/join/destruction; next case initializes a fresh session.
    std::printf("vblank boundary case=%s legacy=%u handlers=%u drawn=%u stop=%u failures=%u\n",
                name, unsigned(legacy), handlerCalls.load(), unsigned(c.drawn.load()),
                unsigned(cancel), failures.load());
}
} // namespace
int main() {
    _putenv_s("REO_HEADLESS", "1");
    _putenv_s("REO_GS_THREAD", "1");
    _putenv_s("REO_VBLANK_CAPTURE_TEST", "1");
    _putenv_s("REO_GS_DISPATCH_PACE", "0");
    _putenv_s("REO_GS_DISPATCH_PACE_TEST_GATE", "");
    _putenv_s("REO_FIELD_BOB", "");
    runCase("legacy-gap", true, One);
    runCase("atomic-single", false, One);
    runCase("atomic-none", false, None);
    runCase("atomic-masked", false, Masked);
    runCase("atomic-disabled", false, Disabled);
    runCase("atomic-multiple", false, Multiple);
    runCase("atomic-stop", false, One, true);
    runCase("atomic-reinitialized", false, One);
    std::printf("vblank capture boundary: %s (%u failures)\n", failures.load() ? "FAIL" : "PASS",
                failures.load());
    return failures.load() ? 1 : 0;
}
