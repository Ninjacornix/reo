#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include "ps2_syscalls.h"
#include "runtime/ps2_gs_gpu.h"
#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <thread>

void ps2GsMarkVsync();
void ps2GsSetDispatchTestGate(bool);
bool ps2GsDispatchTestGateWaiting() noexcept;
bool ps2GsProducerPacePending() noexcept;
uint32_t ps2IoRegLockDepth() noexcept;
namespace {
constexpr uint32_t Entry = 0x10000, MainResume = 0x10004, Producer = 0x10100,
                   ProducerResume = 0x10104, Observer = 0x10200, Irq = 0x10300,
                   NestedEntry = 0x10400, NestedReturn = 0x10404;
std::atomic<bool> mainSubmitted{false}, producerSubmitted{false}, mainResumed{false},
    producerResumed{false}, callbackInside{false};
std::atomic<bool> callbackQueryDone{false}, nestedEntered{false}, nestedBodyRan{false};
std::atomic<unsigned> observerCalls{0}, irqCalls{0}, failures{0};
bool stopWhileBlocked = false;
bool backedgeMode = false;
void fail(const char* what) {
    ++failures;
    std::printf("FAIL %s\n", what);
}
void dma(uint32_t channel, uint32_t, uint32_t, uint32_t, const uint8_t*, void* user) {
    if (channel != 0x1000A000)
        return;
    auto* rt = static_cast<PS2Runtime*>(user);
    callbackInside = true;
    rt->gs().writeRegister(0x01, 0x8000ff00); // Green, third pixel.
    rt->gs().writeRegister(0x05, 2u * 16u);
    if (backedgeMode) {
        // write8 owns an outer scope and writeIORegister a recursive scope.
        // This query has real debt and a gated worker: an unguarded wait would
        // release CPU inside DMA and deadlock an IRQ's subsequent IO read.
        if (ps2IoRegLockDepth() < 2u)
            fail("recursive byte-DMA IO scope not tracked");
        const unsigned beforeIrq = irqCalls.load(), beforeOther = observerCalls.load();
        (void)rt->shouldPreemptGuestExecution();
        if (irqCalls.load() != beforeIrq || observerCalls.load() != beforeOther)
            fail("backedge released CPU inside DMA IO scope");
        if (!ps2GsProducerPacePending())
            fail("IO-guarded backedge consumed producer debt");
        callbackQueryDone = true;
    }
    callbackInside = false;
}
void nestedEntry(uint8_t*, R5900Context* ctx, PS2Runtime* rt) {
    // Exactly the entry-PC hazard of generated nested call wrappers. Waiting
    // must preserve this native stack, PC, RA and local state, not return early.
    ctx->pc = NestedEntry;
    const uint32_t savedRa = GPR_U32(ctx, 31);
    volatile uint32_t local = 0x1234abcd;
    nestedEntered = true;
    if (rt->shouldPreemptGuestExecution())
        return;
    if (ctx->pc != NestedEntry || GPR_U32(ctx, 31) != savedRa || local != 0x1234abcd)
        fail("in-place wait changed nested PC/RA/local state");
    nestedBodyRan = true;
    ctx->pc = savedRa;
}
void irq(uint8_t* ram, R5900Context* ctx, PS2Runtime* rt) {
    // Increment only after an actual IO read: releasing CPU while keeping IO
    // locked in DMA would deadlock this handler instead of passing the test.
    (void)rt->Load32(ram, ctx, 0x1000E000);
    ++irqCalls;
    ctx->pc = 0;
}
void observer(uint8_t* ram, R5900Context* ctx, PS2Runtime* rt) {
    (void)rt->Load32(ram, ctx, 0x1000E000);
    if (ps2GsProducerPacePending())
        fail("non-GS guest inherited another producer debt");
    ++observerCalls;
    ctx->pc = 0;
}
void producer(uint8_t*, R5900Context* ctx, PS2Runtime* rt) {
    rt->gs().writeRegister(0x01, 0x8000ffff); // Yellow, fourth pixel.
    rt->gs().writeRegister(0x05, 3u * 16u);
    if (!ps2GsProducerPacePending())
        fail("guest producer missing debt");
    producerSubmitted = true;
    if (backedgeMode) {
        (void)rt->shouldPreemptGuestExecution();
        if (rt->isStopRequested())
            return;
        if (ps2GsProducerPacePending())
            fail("guest backedge failed to consume debt");
    }
    ctx->pc = ProducerResume;
}
void producerResume(uint8_t*, R5900Context* ctx, PS2Runtime*) {
    if (ps2GsDispatchTestGateWaiting())
        fail("guest resumed before its frozen target completed");
    producerResumed = true;
    ctx->pc = 0;
}
void makeThread(uint8_t* ram, R5900Context* ctx, PS2Runtime* rt, uint32_t pc, uint32_t stack) {
    // Lower priority than main: StartThread itself must not release main early.
    const uint32_t param[] = {0, pc, stack, 0x4000, 0, 127, 0};
    std::memcpy(ram + 0x30000, param, sizeof(param));
    SET_GPR_U32(ctx, 4, 0x30000);
    ps2_syscalls::CreateThread(ram, ctx, rt);
    const uint32_t tid = GPR_U32(ctx, 2);
    SET_GPR_U32(ctx, 4, tid);
    SET_GPR_U32(ctx, 5, 0);
    ps2_syscalls::StartThread(ram, ctx, rt);
}
void entry(uint8_t* ram, R5900Context* ctx, PS2Runtime* rt) {
    if (ps2GsProducerPacePending())
        fail("new GS session inherited stale debt");
    SET_GPR_U32(ctx, 4, 0);
    SET_GPR_U32(ctx, 5, 1);
    ps2_syscalls::ChangeThreadPriority(ram, ctx, rt);
    SET_GPR_U32(ctx, 4, 2);
    SET_GPR_U32(ctx, 5, Irq);
    SET_GPR_U32(ctx, 6, 0);
    SET_GPR_U32(ctx, 7, 0);
    ps2_syscalls::AddIntcHandler(ram, ctx, rt);
    makeThread(ram, ctx, rt, Producer, 0x40000);
    makeThread(ram, ctx, rt, Observer, 0x45000);
    auto& gs = rt->gs();
    gs.writeRegister(0x4c, 1ull << 16);
    gs.writeRegister(0x40, (63ull << 16) | (63ull << 48));
    gs.writeRegister(0x47, 0);
    gs.writeRegister(0x4e, 1ull << 32);
    gs.writeRegister(0x18, 0);
    gs.writeRegister(0, 0);
    gs.writeRegister(1, 0x800000ff);
    gs.writeRegister(5, 0);
    gs.writeRegister(1, 0x80ff0000);
    gs.writeRegister(5, 16);
    // Make a real outstanding two-frame target while the GS worker is gated.
    ps2GsMarkVsync();
    ps2GsMarkVsync();
    ps2GsMarkVsync();
    rt->Store32(ram, ctx, 0x1000A020, 1);
    rt->Store32(ram, ctx, 0x1000A010, 0x20000);
    if (backedgeMode)
        rt->Store8(ram, ctx, 0x1000A001, 1); // Nested IO lock / DMA callback.
    else
        rt->Store32(ram, ctx, 0x1000A000, 0x100);
    if (callbackInside.load())
        fail("DMA callback did not return");
    if (!ps2GsProducerPacePending())
        fail("main producer missing debt after DMA returned");
    mainSubmitted = true;
    if (backedgeMode) {
        if (ps2IoRegLockDepth() != 0u || !callbackQueryDone.load())
            fail("DMA did not leave all IO scopes");
        const uint32_t outerRa = GPR_U32(ctx, 31);
        SET_GPR_U32(ctx, 31, NestedReturn);
        ctx->pc = NestedEntry;
        const uint32_t entryPc = ctx->pc;
        auto fn = rt->lookupFunction(NestedEntry);
        fn(ram, ctx, rt);
        // Same completion check as generated wrappers; a forced entry-PC
        // unwind would skip the callee body but falsely report completion.
        if (ctx->pc == entryPc)
            ctx->pc = NestedReturn;
        if (rt->isStopRequested())
            return;
        if (ctx->pc != NestedReturn || !nestedBodyRan.load())
            fail("entry-PC callee falsely completed or failed to resume");
        SET_GPR_U32(ctx, 31, outerRa);
        if (ps2GsProducerPacePending())
            fail("main backedge failed to consume debt");
    }
    ctx->pc = MainResume;
}
void mainResume(uint8_t* ram, R5900Context* ctx, PS2Runtime* rt) {
    if (ps2GsDispatchTestGateWaiting())
        fail("main resumed before its frozen target completed");
    rt->gs().refreshDisplaySnapshot();
    const auto* pixels = rt->memory().getGSVRAM();
    const uint32_t expected[] = {0x000000ff, 0x00ff0000, 0x0000ff00, 0x0000ffff};
    const unsigned offsets[] = {0, 4, 16, 20}; // Independent first-row PSMCT32 word positions.
    for (unsigned x = 0; x < 4; ++x) {
        uint32_t actual;
        std::memcpy(&actual, pixels + offsets[x], 4);
        if ((actual & 0xffffffu) != expected[x])
            fail("FIFO pixel color/order changed");
    }
    mainResumed = true;
    ps2_syscalls::SleepThread(ram, ctx, rt);
    ctx->pc = 0;
}
} // namespace
int main(int argc, char** argv) {
    backedgeMode = argc > 1 && std::strcmp(argv[1], "--backedge") == 0;
    _putenv_s("REO_HEADLESS", "1");
    _putenv_s("REO_GS_THREAD", "1");
    _putenv_s("REO_GS_DISPATCH_PACE", backedgeMode ? "2" : "1");
    _putenv_s("REO_GS_STATE_PACKET_NO_PACE", "0");
    _putenv_s("REO_GS_DISPATCH_PACE_TEST_GATE", "1");
    for (unsigned pass = 0; pass < 3; ++pass) {
        mainSubmitted = false;
        producerSubmitted = false;
        mainResumed = false;
        producerResumed = false;
        callbackInside = false;
        callbackQueryDone = false;
        nestedEntered = false;
        nestedBodyRan = false;
        observerCalls = 0;
        irqCalls = 0;
        stopWhileBlocked = pass == 1;
        PS2Runtime rt;
        if (!rt.initialize("dispatcher pacing fixture"))
            return 2;
        PS2Memory::HwBridgeCallbacks bridge{};
        bridge.onDmaStart = dma;
        bridge.user = &rt;
        rt.memory().setHwBridge(bridge);
        rt.registerFunction(Entry, entry);
        rt.registerFunction(MainResume, mainResume);
        rt.registerFunction(Producer, producer);
        rt.registerFunction(ProducerResume, producerResume);
        rt.registerFunction(Observer, observer);
        rt.registerFunction(Irq, irq);
        rt.cpu().pc = Entry;
        rt.registerFunction(NestedEntry, nestedEntry);
        ps2GsSetDispatchTestGate(true);
        std::thread coordinator([&] {
            const auto deadline = std::chrono::steady_clock::now() + std::chrono::seconds(4);
            while (std::chrono::steady_clock::now() < deadline &&
                   !(mainSubmitted.load() && producerSubmitted.load() && observerCalls.load() &&
                     irqCalls.load() && ps2GsDispatchTestGateWaiting() &&
                     (!backedgeMode || nestedEntered.load())))
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            if (!(mainSubmitted.load() && producerSubmitted.load() && observerCalls.load() &&
                  irqCalls.load() && ps2GsDispatchTestGateWaiting()))
                fail("real IRQ/non-GS guest failed to progress while both producers were paced");
            if (mainResumed.load() || producerResumed.load() || callbackInside.load())
                fail("producer resumed early or still holds DMA callback");
            if (backedgeMode &&
                (!callbackQueryDone.load() || !nestedEntered.load() || nestedBodyRan.load()))
                fail("nested callee failed to block in place after guarded DMA");
            if (stopWhileBlocked) {
                rt.requestStop();
                return;
            }
            ps2GsSetDispatchTestGate(false);
            while (std::chrono::steady_clock::now() < deadline &&
                   !(mainResumed.load() && producerResumed.load()))
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            if (!(mainResumed.load() && producerResumed.load()))
                fail("main/guest boundary failed to resume");
            rt.requestStop();
        });
        rt.run();
        coordinator.join();
        if (stopWhileBlocked && (mainResumed.load() || producerResumed.load()))
            fail("stop resumed cancelled guest work");
        std::printf("dispatcher pacing mode=%u pass=%u stop=%u irq=%u other_guest=%u "
                    "main_resumed=%u producer_resumed=%u nested_body=%u failures=%u\n",
                    backedgeMode ? 2u : 1u, pass, unsigned(stopWhileBlocked), irqCalls.load(),
                    observerCalls.load(), unsigned(mainResumed.load()),
                    unsigned(producerResumed.load()), unsigned(nestedBodyRan.load()),
                    failures.load());
    }
    std::printf("dispatcher pacing: %s (%u failures)\n", failures.load() ? "FAIL" : "PASS",
                failures.load());
    return failures.load() ? 1 : 0;
}
