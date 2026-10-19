#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include "ps2_syscalls.h"
#include "runtime/ps2_gs_gpu.h"
#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <thread>

void ps2GsSetDispatchTestGate(bool);
void ps2GsMarkVsync();
bool ps2GsDispatchTestGateWaiting() noexcept;
bool ps2GsProducerPacePending() noexcept;
uint32_t ps2IoRegLockDepth() noexcept;
namespace ps2_sched {
int debugWaitingWorkers();
std::string debugState(int);
} // namespace ps2_sched
namespace {
constexpr uint32_t Entry = 0x10000, Resume = 0x10004, Observer = 0x10100, Irq = 0x10200,
                   Nested = 0x10300, NestedReturn = 0x10304, Packet = 0x20000;
std::atomic<unsigned> failures{0}, irqCalls{0}, observerCalls{0}, callbacks{0}, nestedCallbacks{0};
std::atomic<bool> callbackDone{false}, postIrqEntered{false}, releasePostIrq{false},
    kickReturned{false}, bodyRan{false}, parityDone{false};
bool enabled = false, stopPass = false;
R5900Context* mainContext = nullptr;
void fail(const char* s) {
    ++failures;
    std::printf("FAIL %s\n", s);
}
template <class Pred> bool await(Pred pred, unsigned ms = 2000) {
    const auto end = std::chrono::steady_clock::now() + std::chrono::milliseconds(ms);
    while (!pred() && std::chrono::steady_clock::now() < end)
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    return pred();
}
void irq(uint8_t* ram, R5900Context* ctx, PS2Runtime* rt) {
    if ((rt->Load32(ram, ctx, 0x1000E000) & 1u) == 0u)
        fail("IRQ observed disabled fixture DMAC"); // Real IO mutex.
    ++irqCalls;
    if (callbackDone.load() && !releasePostIrq.load()) {
        postIrqEntered = true;
        while (!releasePostIrq.load() && !rt->isStopRequested())
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    ctx->pc = 0;
}
void observer(uint8_t* ram, R5900Context* ctx, PS2Runtime* rt) {
    if ((rt->Load32(ram, ctx, 0x1000E000) & 1u) == 0u)
        fail("guest observed disabled fixture DMAC");
    ++observerCalls;
    ctx->pc = 0;
}
void dma(uint32_t channel, uint32_t, uint32_t, uint32_t, const uint8_t* ram, void* user) {
    if (channel != 0x10009000u)
        return;
    auto* rt = static_cast<PS2Runtime*>(user);
    if (callbacks.fetch_add(1) != 0u) {
        ++nestedCallbacks;
        return;
    }
    if (enabled ? (!irqCalls.load() || !observerCalls.load())
                : (irqCalls.load() || observerCalls.load()))
        fail("pre-kick priority admission differs from the selected control");
    if (ps2IoRegLockDepth() == 0u)
        fail("DMA callback is not inside actual IO scope");
    if ((rt->Load32(const_cast<uint8_t*>(ram), mainContext, 0x1000E000) & 1u) == 0u)
        fail("DMA callback observed disabled fixture DMAC");
    // Queue a real worker while main still owns CPU and IO; a nested checkpoint
    // must not release either pre- or post-write while that worker needs MMIO.
    if (!await([] { return ps2_sched::debugWaitingWorkers() > 0; }))
        fail("post-kick IRQ did not queue");
    const unsigned beforeIrq = irqCalls.load(), beforeOther = observerCalls.load();
    rt->gs().writeRegister(0x46, 1); // A real pace debt that checkpoints must leave intact.
    rt->Store32(const_cast<uint8_t*>(ram), mainContext, 0x10009020, 0);
    rt->Store32(const_cast<uint8_t*>(ram), mainContext, 0x10009000, 0x100);
    rt->Store32(const_cast<uint8_t*>(ram), mainContext, 0x10009020, 4);
    if (irqCalls.load() != beforeIrq || observerCalls.load() != beforeOther)
        fail("recursive IO callback released guest execution");
    if (!ps2GsProducerPacePending())
        fail("recursive checkpoint settled GS debt");
    callbackDone = true;
}
void nested(uint8_t* ram, R5900Context* ctx, PS2Runtime* rt) {
    ctx->pc = Nested;
    const uint32_t ra = GPR_U32(ctx, 31);
    volatile uint32_t local = 0x1973abcd;
    mainContext = ctx;
    rt->Store32(ram, ctx, 0xB0009000, 0x100); // Physical VIF1 CHCR, real DIRECT DMA.
    kickReturned = true;
    if (ctx->pc != Nested || GPR_U32(ctx, 31) != ra || local != 0x1973abcd)
        fail("boundary changed nested entry PC/RA/native local");
    if (rt->isStopRequested())
        return;
    if (!ps2GsProducerPacePending())
        fail("boundary consumed GS debt before the existing backedge/dispatcher");
    bodyRan = true;
    ctx->pc = ra;
}
void entry(uint8_t* ram, R5900Context* ctx, PS2Runtime* rt) {
    // Explicit hardware setup before either test control admits a D_CTRL read.
    // An absent D_CTRL is tolerated by DMA kick, whereas reading that register
    // first creates a zero slot in the current memory implementation.
    rt->Store32(ram, ctx, 0x1000E000, 1);
    SET_GPR_U32(ctx, 4, 0);
    SET_GPR_U32(ctx, 5, 1);
    ps2_syscalls::ChangeThreadPriority(ram, ctx, rt);
    SET_GPR_U32(ctx, 4, 2);
    SET_GPR_U32(ctx, 5, Irq);
    SET_GPR_U32(ctx, 6, 0);
    SET_GPR_U32(ctx, 7, 0);
    ps2_syscalls::AddIntcHandler(ram, ctx, rt);
    const uint32_t param[] = {0, Observer, 0x40000, 0x4000, 0, 2, 0};
    std::memcpy(ram + 0x30000, param, sizeof(param));
    SET_GPR_U32(ctx, 4, 0x30000);
    ps2_syscalls::CreateThread(ram, ctx, rt);
    const int observerTid = GPR_U32(ctx, 2);
    SET_GPR_U32(ctx, 4, observerTid);
    SET_GPR_U32(ctx, 5, 0);
    ps2_syscalls::StartThread(ram, ctx, rt);
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
    ps2GsMarkVsync();
    ps2GsMarkVsync();
    ps2GsMarkVsync();
    // VIF NOP,NOP,NOP,DIRECT(3 QW), then a packed A+D GIF tag and two writes.
    const uint32_t vif[] = {0, 0, 0, 0x50000003};
    const uint64_t gif[] = {0x1000000000008002ull, 0xE, 0x8000ff00ull, 0x01, 2u * 16u, 0x05};
    std::memcpy(ram + Packet, vif, sizeof(vif));
    std::memcpy(ram + Packet + 16, gif, sizeof(gif));
    rt->Store32(ram, ctx, 0x10009010, Packet);
    rt->Store32(ram, ctx, 0x10009020, 4);
    SET_GPR_U32(ctx, 4, 0);
    SET_GPR_U32(ctx, 5, 24);
    ps2_syscalls::ChangeThreadPriority(ram, ctx, rt);
    if (!await([observerTid] {
            return ps2_sched::debugState(observerTid).ends_with("/1") &&
                   ps2_sched::debugWaitingWorkers() > 0;
        }))
        fail("actual higher-priority guest and IRQ failed to queue");
    rt->Store32(ram, ctx, 0x10009000, 0x80); // STR is 0x100; this must not yield.
    rt->Store32(ram, ctx, 0x1000A000, 0);    // Other channel must not yield either.
    if (irqCalls.load() || observerCalls.load())
        fail("non-start/other-channel control admitted waiting work");
    const uint32_t outerRa = GPR_U32(ctx, 31);
    SET_GPR_U32(ctx, 31, NestedReturn);
    ctx->pc = Nested;
    rt->lookupFunction(Nested)(ram, ctx, rt);
    if (rt->isStopRequested())
        return;
    if (ctx->pc != NestedReturn || !bodyRan.load())
        fail("nested entry wrapper falsely completed or lost its body");
    SET_GPR_U32(ctx, 31, outerRa);
    gs.writeRegister(1, 0x8000ffff);
    gs.writeRegister(5, 3u * 16u);
    ctx->pc = Resume;
}
void resume(uint8_t*, R5900Context* ctx, PS2Runtime* rt) {
    {
        PS2Runtime::GuestExecutionReleaseScope release(rt);
        rt->gs().refreshDisplaySnapshot();
    }
    const auto* v = rt->memory().getGSVRAM();
    const unsigned offsets[] = {0, 4, 16, 20};
    const uint32_t expected[] = {0xff, 0xff0000, 0xff00, 0xffff};
    for (unsigned i = 0; i < 4; ++i) {
        uint32_t x;
        std::memcpy(&x, v + offsets[i], 4);
        if ((x & 0xffffff) != expected[i])
            fail("real VIF DIRECT / queued GIF FIFO pixel oracle failed");
    }
    uint64_t hash = 1469598103934665603ull;
    for (unsigned i = 0; i < 4u * 1024u * 1024u; ++i) {
        hash ^= v[i];
        hash *= 1099511628211ull;
    }
    std::printf("vif parity hash=%016llx\n", static_cast<unsigned long long>(hash));
    parityDone = true;
    ctx->pc = 0;
}
} // namespace
int main(int argc, char** argv) {
    enabled = argc > 1 && std::strcmp(argv[1], "--on") == 0;
    _putenv_s("REO_HEADLESS", "1");
    _putenv_s("REO_GS_THREAD", "1");
    _putenv_s("REO_GS_DISPATCH_PACE", "2");
    _putenv_s("REO_GS_DISPATCH_PACE_TEST_GATE", "1");
    _putenv_s("REO_VIF_BOUNDARY_YIELD", enabled ? "1" : "");
    _putenv_s("REO_SPIN_ROTATE", "");
    _putenv_s("REO_IMMEDIATE_SWITCH", "");
    for (unsigned pass = 0; pass < 3; ++pass) {
        irqCalls = 0;
        observerCalls = 0;
        callbacks = 0;
        nestedCallbacks = 0;
        callbackDone = false;
        postIrqEntered = false;
        releasePostIrq = false;
        kickReturned = false;
        bodyRan = false;
        parityDone = false;
        stopPass = pass == 1;
        PS2Runtime rt;
        if (!rt.initialize("VIF boundary fixture"))
            return 2;
        PS2Memory::HwBridgeCallbacks br{};
        br.onDmaStart = dma;
        br.user = &rt;
        rt.memory().setHwBridge(br);
        rt.registerFunction(Entry, entry);
        rt.registerFunction(Resume, resume);
        rt.registerFunction(Observer, observer);
        rt.registerFunction(Irq, irq);
        rt.registerFunction(Nested, nested);
        rt.cpu().pc = Entry;
        ps2GsSetDispatchTestGate(true);
        std::thread coordinator([&] {
            if (!await([] { return postIrqEntered.load(); }))
                fail("post-kick IRQ failed actual MMIO progress");
            if (enabled ? kickReturned.load() : !kickReturned.load())
                fail("post-kick control did not distinguish in-place admission from dispatcher "
                     "admission");
            if (!callbackDone.load() || nestedCallbacks.load() != 1u)
                fail("recursive VIF callback coverage incomplete");
            if (stopPass) {
                rt.requestStop();
                return;
            }
            releasePostIrq = true;
            if (!await([] { return bodyRan.load() && ps2GsDispatchTestGateWaiting(); }))
                fail("nested body did not resume / GS gate not exercised");
            ps2GsSetDispatchTestGate(false);
            if (!await([] { return parityDone.load(); }))
                fail("FIFO oracle failed to finish");
            rt.requestStop();
        });
        rt.run();
        coordinator.join();
        if (stopPass && parityDone.load())
            fail("stop resumed cancelled frame work");
        std::printf(
            "vif boundary on=%u pass=%u stop=%u irq=%u guest=%u nested=%u body=%u failures=%u\n",
            unsigned(enabled), pass, unsigned(stopPass), irqCalls.load(), observerCalls.load(),
            nestedCallbacks.load(), unsigned(bodyRan.load()), failures.load());
    }
    std::printf("VIF boundary: %s (%u failures)\n", failures.load() ? "FAIL" : "PASS",
                failures.load());
    return failures.load() ? 1 : 0;
}
