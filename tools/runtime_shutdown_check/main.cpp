#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include "ps2_syscalls.h"
#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstring>
#include <thread>

// This fixture returns normally: destruction and static worker teardown are
// part of the test, unlike the existing runtime runner's std::_Exit path.
namespace {
std::atomic<unsigned> guestCalls{0}, alarmCalls{0}, irqCalls{0};
std::atomic<bool> ready{false};
bool draw = false;
bool useAlarm = false;
bool useIrq = false;
constexpr uint32_t mainPc = 0x10000, childPc = 0x10100, alarmPc = 0x10200, irqPc = 0x10300;

void child(uint8_t* ram, R5900Context* ctx, PS2Runtime* rt) {
    ++guestCalls;
    ps2_syscalls::SleepThread(ram, ctx, rt);
    ctx->pc = 0;
}
void alarm(uint8_t*, R5900Context* ctx, PS2Runtime* rt) {
    ++alarmCalls;
    // Cancellation must join an already-dispatched callback as well as an
    // alarm worker asleep on an empty queue.
    while (!rt->isStopRequested())
        std::this_thread::yield();
    ctx->pc = 0;
}
void irq(uint8_t*, R5900Context* ctx, PS2Runtime* rt) {
    ++irqCalls;
    auto& gs = rt->gs();
    gs.writeRegister(0x4c, 10ull << 16);
    gs.writeRegister(0x40, (639ull << 16) | (447ull << 48));
    gs.writeRegister(0x47, 0);
    gs.writeRegister(0x4e, 1ull << 32);
    gs.writeRegister(0x00, 6);
    gs.writeRegister(0x01, 0x80405060);
    while (!rt->isStopRequested()) {
        gs.writeRegister(0x05, 0);
        gs.writeRegister(0x05, (640ull * 16) | ((448ull * 16) << 16));
    }
    ctx->pc = 0;
}
void entry(uint8_t* ram, R5900Context* ctx, PS2Runtime* rt) {
    const uint32_t param[] = {0, childPc, 0x40000, 0x4000, 0, 1, 0};
    std::memcpy(ram + 0x30000, param, sizeof(param));
    SET_GPR_U32(ctx, 4, 0x30000);
    ps2_syscalls::CreateThread(ram, ctx, rt);
    const uint32_t tid = GPR_U32(ctx, 2);
    SET_GPR_U32(ctx, 4, tid);
    SET_GPR_U32(ctx, 5, 0);
    ps2_syscalls::StartThread(ram, ctx, rt);
    // Also leave a worker suspended before it can acquire the guest CPU.
    std::memcpy(ram + 0x30000, param, sizeof(param));
    SET_GPR_U32(ctx, 4, 0x30000);
    ps2_syscalls::CreateThread(ram, ctx, rt);
    const uint32_t suspended = GPR_U32(ctx, 2);
    SET_GPR_U32(ctx, 4, suspended);
    ps2_syscalls::StartThread(ram, ctx, rt);
    SET_GPR_U32(ctx, 4, suspended);
    ps2_syscalls::SuspendThread(ram, ctx, rt);
    ready.store(true, std::memory_order_release);
    if (draw) {
        auto& gs = rt->gs();
        gs.writeRegister(0x4c, 10ull << 16); // FRAME_1 CT32, width 640.
        gs.writeRegister(0x40, (639ull << 16) | (447ull << 48));
        gs.writeRegister(0x47, 0);
        gs.writeRegister(0x4e, 1ull << 32);
        gs.writeRegister(0x00, 6); // Sprite.
        gs.writeRegister(0x01, 0x80302010);
        for (unsigned i = 0; i < 1000 && !rt->isStopRequested(); ++i) {
            gs.writeRegister(0x05, 0);
            gs.writeRegister(0x05, (640ull * 16) | ((448ull * 16) << 16));
        }
    }
    if (useAlarm) {
        // The alarm callback will own the CPU until the stop signal. The
        // host coordinator must still cancel it without joining under CPU.
        SET_GPR_U32(ctx, 4, 1);
        SET_GPR_U32(ctx, 5, alarmPc);
        SET_GPR_U32(ctx, 6, 0);
        ps2_syscalls::SetAlarm(ram, ctx, rt);
    }
    if (useIrq) {
        SET_GPR_U32(ctx, 4, 2);
        SET_GPR_U32(ctx, 5, irqPc);
        SET_GPR_U32(ctx, 6, 0);
        SET_GPR_U32(ctx, 7, 0);
        ps2_syscalls::AddIntcHandler(ram, ctx, rt);
    }
    ps2_syscalls::SleepThread(ram, ctx, rt);
    ctx->pc = 0;
}
} // namespace

int main() {
    _putenv_s("REO_HEADLESS", "1");
    _putenv_s("REO_GS_THREAD", "1");
    _putenv_s("REO_GS_NO_PARALLEL", "");
    _putenv_s("REO_GS_NO_FASTPATH", "");
    unsigned failures = 0;
    for (unsigned pass = 0; pass < 5; ++pass) {
        ready.store(false);
        draw = pass == 1;
        useAlarm = pass == 2 || pass == 3;
        useIrq = pass == 4;
        const auto started = std::chrono::steady_clock::now();
        {
            PS2Runtime runtime;
            if (!runtime.initialize("shutdown fixture"))
                return 2;
            runtime.registerFunction(mainPc, entry);
            runtime.registerFunction(childPc, child);
            runtime.registerFunction(alarmPc, alarm);
            runtime.registerFunction(irqPc, irq);
            runtime.cpu().pc = mainPc;
            std::thread closer([&] {
                const auto deadline = std::chrono::steady_clock::now() + std::chrono::seconds(5);
                while (!ready.load(std::memory_order_acquire) &&
                       std::chrono::steady_clock::now() < deadline)
                    std::this_thread::sleep_for(std::chrono::milliseconds(1));
                while (useIrq && irqCalls.load() == 0 &&
                       std::chrono::steady_clock::now() < deadline)
                    std::this_thread::sleep_for(std::chrono::milliseconds(1));
                std::this_thread::sleep_for(std::chrono::milliseconds(30));
                runtime.requestStop();
            });
            runtime.run();
            closer.join();
            if (!ready.load() || g_activeThreads.load() != 0)
                ++failures;
            // Explicit stop must discard further GS writes without the old
            // enqueue=false synchronous fallback changing VRAM.
            const uint32_t before =
                *reinterpret_cast<const uint32_t*>(runtime.memory().getGSVRAM());
            if ((draw || useIrq) && before == 0)
                ++failures;
            runtime.gs().writeRegister(0x01, 0x80706050);
            runtime.gs().writeRegister(0x00, 0);
            runtime.gs().writeRegister(0x05, 0);
            const uint32_t after = *reinterpret_cast<const uint32_t*>(runtime.memory().getGSVRAM());
            if (before != after)
                ++failures;
        } // Actual runtime/RAM destruction must happen here.
        const unsigned calls = guestCalls.load(), alarms = alarmCalls.load(),
                       irqs = irqCalls.load();
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
        if (calls != guestCalls.load() || alarms != alarmCalls.load() || irqs != irqCalls.load())
            ++failures;
        const auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                            std::chrono::steady_clock::now() - started)
                            .count();
        if (ms > 2000)
            ++failures;
        std::printf(
            "shutdown pass=%u draw=%u duration_ms=%lld guest_calls=%u alarm_calls=%u failures=%u\n",
            pass, unsigned(draw), static_cast<long long>(ms), calls, alarms, failures);
    }
    if (alarmCalls.load() < 2)
        ++failures;
    if (irqCalls.load() == 0)
        ++failures;
    std::printf("runtime shutdown: %s (%u failures)\n", failures ? "FAIL" : "PASS", failures);
    return failures ? 1 : 0;
}
