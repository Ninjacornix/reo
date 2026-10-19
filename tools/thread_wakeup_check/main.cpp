#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include "Syscalls/Common.h"
#include "Syscalls/Thread.h"

#include <future>

void sub_0012BF98_0x12bf98(uint8_t*, R5900Context*, PS2Runtime*);

namespace {
int checks = 0, failures = 0;
constexpr int caller = 5, target = 1;
constexpr uint32_t pendingAddress = 0x21049c, targetAddress = 0x2104e8;

void check(bool result, const char* message) {
    ++checks;
    if (!result)
        ++failures;
    std::printf("%s %s\n", result ? "PASS" : "FAIL", message);
}

std::shared_ptr<ThreadInfo> fixture(int id, int status, int wait = TSW_NONE, int suspends = 0) {
    auto info = std::make_shared<ThreadInfo>();
    info->started = status != THS_DORMANT;
    info->status = status;
    info->waitType = wait;
    info->suspendCount = suspends;
    info->priority = info->currentPriority = 24;
    std::lock_guard<std::mutex> guard(g_thread_map_mutex);
    g_threads[id] = info;
    return info;
}

int wake(uint8_t* ram, int id, bool interrupt = false) {
    R5900Context ctx{};
    SET_GPR_S32(&ctx, 4, id);
    if (interrupt)
        ps2_syscalls::iWakeupThread(ram, &ctx, nullptr);
    else
        ps2_syscalls::WakeupThread(ram, &ctx, nullptr);
    return GPR_S32((&ctx), 2);
}

int queued(const std::shared_ptr<ThreadInfo>& info) {
    std::lock_guard<std::mutex> guard(info->m);
    return info->wakeupCount;
}

void handshake(PS2Runtime& runtime, uint32_t request) {
    auto* ram = runtime.memory().getRDRAM();
    std::memcpy(ram + pendingAddress, &request, 4);
    const uint32_t id = target;
    std::memcpy(ram + targetAddress, &id, 4);
    R5900Context ctx{};
    ctx.pc = 0x12bf98;
    SET_GPR_U32(&ctx, 29, 0x100000);
    SET_GPR_U32(&ctx, 31, 0);
    // Compile and call the actual existing generated guest function, together
    // with its original ReferThreadStatus/WakeupThread syscall wrappers.
    sub_0012BF98_0x12bf98(ram, &ctx, &runtime);
    check(ctx.pc == 0 && GPR_U32((&ctx), 29) == 0x100000,
          "original handshake returns with its stack restored");
}

uint32_t pending(PS2Runtime& runtime) {
    uint32_t value;
    std::memcpy(&value, runtime.memory().getRDRAM() + pendingAddress, 4);
    return value;
}

template <class Action> void blockedCase(uint8_t* ram, Action action) {
    auto info = fixture(target, THS_RUN);
    std::promise<void> completion;
    auto done = completion.get_future();
    std::thread sleeper([&] {
        g_currentThreadId = target;
        R5900Context ctx{};
        ps2_syscalls::SleepThread(ram, &ctx, nullptr);
        completion.set_value();
    });
    bool sleeping = false;
    const auto deadline = std::chrono::steady_clock::now() + std::chrono::seconds(2);
    while (std::chrono::steady_clock::now() < deadline) {
        {
            std::lock_guard<std::mutex> guard(info->m);
            sleeping = info->status == THS_WAIT && info->waitType == TSW_SLEEP;
        }
        if (sleeping)
            break;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    check(sleeping, "fixture reaches the real production SleepThread wait");
    if (sleeping)
        action(info);
    const bool released = done.wait_for(std::chrono::seconds(2)) == std::future_status::ready;
    check(released, "wake releases the blocked target within the bounded deadline");
    if (!released) {
        info->forceRelease.store(true);
        info->cv.notify_all();
    }
    sleeper.join();
    check(queued(info) == 0, "released sleep consumes its wake request once");
}
} // namespace

int main() {
    // Only an isolated kernel fixture, with no guest dispatch threads, renderer
    // or audio device. No production priority-switch behavior is under test.
    _putenv_s("REO_IMMEDIATE_SWITCH", "");
    auto* runtime = new PS2Runtime();
    if (!runtime->memory().initialize())
        return 2;
    auto* ram = runtime->memory().getRDRAM();
    g_currentThreadId = caller;
    fixture(caller, THS_RUN);

    for (bool interrupt : {false, true}) {
        std::printf("-- %s --\n", interrupt ? "iWakeupThread" : "WakeupThread");
        check(wake(ram, 0, interrupt) == KE_ILLEGAL_THID, "zero target retains its error");
        check(wake(ram, caller, interrupt) == KE_ILLEGAL_THID, "self target retains its error");
        check(wake(ram, 999999, interrupt) == KE_UNKNOWN_THID, "unknown target retains its error");
        auto dormant = fixture(target, THS_DORMANT);
        check(wake(ram, target, interrupt) == KE_DORMANT && queued(dormant) == 0,
              "dormant target retains its error and gains no wake request");
        auto ready = fixture(target, THS_READY);
        check(wake(ram, target, interrupt) == target,
              "successful queued wake returns the target id");
        check(queued(ready) == 1, "ready target receives one queued wake request");
        g_currentThreadId = target;
        R5900Context ctx{};
        ps2_syscalls::SleepThread(ram, &ctx, nullptr);
        g_currentThreadId = caller;
        check(queued(ready) == 0 && ready->status == THS_RUN,
              "next sleep consumes the queued wake without blocking");
        blockedCase(ram, [&](const auto&) {
            check(wake(ram, target, interrupt) == target,
                  "successful blocked wake returns the target id");
        });
    }

    std::puts("-- original CRI guest handshake 0x12BF98 --");
    blockedCase(ram, [&](const auto&) {
        handshake(*runtime, 1);
        check(pending(*runtime) == 0, "actual original blocked-main handshake clears 0x21049C");
    });

    auto suspended = fixture(target, THS_WAITSUSPEND, TSW_SLEEP, 1);
    handshake(*runtime, 1);
    check(pending(*runtime) == 0, "actual original suspended-main handshake clears 0x21049C");
    check(suspended->status == THS_SUSPEND && suspended->suspendCount == 1 &&
              queued(suspended) == 1,
          "suspended wake preserves existing suspension semantics");

    auto ready = fixture(target, THS_READY);
    handshake(*runtime, 1);
    check(pending(*runtime) == 1 && queued(ready) == 0,
          "original handshake leaves a nonwaiting target pending without waking it");
    auto waiting = fixture(target, THS_WAIT, TSW_SLEEP);
    handshake(*runtime, 0);
    check(pending(*runtime) == 0 && queued(waiting) == 0 && waiting->status == THS_WAIT,
          "original handshake with no service request leaves the sleeping target untouched");

    std::printf("%d/%d checks passed\n", checks - failures, checks);
    std::fflush(stdout);
    std::fflush(stderr);
    std::_Exit(failures ? 1 : 0);
}
