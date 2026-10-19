#include "Syscalls/Common.h"
#include "Syscalls/Sync.h"
#include "Syscalls/Thread.h"

#include <future>

namespace {
int checks = 0, failures = 0;
constexpr int caller = 5, target = 10, resource = 41;

void check(bool ok, const char* description) {
    ++checks;
    failures += !ok;
    std::printf("%s %s\n", ok ? "PASS" : "FAIL", description);
    std::fflush(stdout);
}

std::shared_ptr<ThreadInfo> threadInfo(int id, int status) {
    auto info = std::make_shared<ThreadInfo>();
    info->status = status;
    info->started = status != THS_DORMANT;
    info->priority = info->currentPriority = 24;
    std::lock_guard<std::mutex> lock(g_thread_map_mutex);
    g_threads[id] = info;
    return info;
}

int terminate(uint8_t* rdram, int id) {
    R5900Context context{};
    SET_GPR_S32(&context, 4, id);
    ps2_syscalls::TerminateThread(rdram, &context, nullptr);
    return GPR_S32((&context), 2);
}

void resourceCase(uint8_t* rdram, bool event) {
    auto info = threadInfo(target, THS_RUN);
    auto sema = std::make_shared<SemaInfo>();
    sema->maxCount = 1;
    auto flag = std::make_shared<EventFlagInfo>();
    {
        std::lock_guard<std::mutex> lock(g_sema_map_mutex);
        g_semas[resource] = sema;
    }
    {
        std::lock_guard<std::mutex> lock(g_event_flag_map_mutex);
        g_eventFlags[resource] = flag;
    }
    std::atomic<bool> unwound{false}, returnedNormally{false};
    std::thread waiter([&] {
        g_currentThreadId = target;
        R5900Context context{};
        SET_GPR_S32(&context, 4, resource);
        SET_GPR_U32(&context, 5, 1);
        try {
            if (event)
                ps2_syscalls::WaitEventFlag(rdram, &context, nullptr);
            else
                ps2_syscalls::WaitSema(rdram, &context, nullptr);
            returnedNormally = true;
        } catch (const std::exception& error) {
            unwound = std::strcmp(error.what(), "PS2 Thread Exit") == 0;
        }
        // Isolated host lifecycle boundary, equivalent to StartThread's catch.
        // The real wait and termination syscalls run unchanged above.
        {
            std::lock_guard<std::mutex> lock(info->m);
            info->started = false;
            info->status = THS_DORMANT;
        }
        info->cv.notify_all();
    });

    bool blocked = false;
    auto deadline = std::chrono::steady_clock::now() + std::chrono::seconds(2);
    while (std::chrono::steady_clock::now() < deadline) {
        {
            std::lock_guard<std::mutex> lock(info->m);
            blocked = info->status == THS_WAIT &&
                      info->waitType == (event ? TSW_EVENT : TSW_SEMA) && info->waitId == resource;
        }
        if (blocked)
            break;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    check(blocked, event ? "production WaitEventFlag blocks on its resource"
                         : "production WaitSema blocks on its resource");
    // Acquire the resource mutex to ensure the waiter has entered its CV wait.
    if (event) {
        std::lock_guard<std::mutex> lock(flag->m);
    } else {
        std::lock_guard<std::mutex> lock(sema->m);
    }

    std::promise<int> completed;
    auto result = completed.get_future();
    std::thread terminator([&] {
        g_currentThreadId = caller;
        completed.set_value(terminate(rdram, target));
    });
    const bool timely = result.wait_for(std::chrono::seconds(2)) == std::future_status::ready;
    check(timely, "TerminateThread reaches dormant without a resource signal");
    if (!timely) {
        // Failure-only cleanup wakes the real CV without altering resource data.
        info->terminated = true;
        info->forceRelease = true;
        if (event) {
            std::lock_guard<std::mutex> lock(flag->m);
            flag->cv.notify_all();
        } else {
            std::lock_guard<std::mutex> lock(sema->m);
            sema->cv.notify_all();
        }
    }
    if (result.wait_for(std::chrono::seconds(2)) != std::future_status::ready) {
        std::fprintf(stderr, "FAIL bounded cleanup could not release termination\n");
        std::_Exit(3);
    }
    check(result.get() == KE_OK, "successful termination preserves KE_OK");
    terminator.join();
    waiter.join();
    check(unwound && !returnedNormally, "wait exits through cooperative ThreadExitException");
    {
        std::lock_guard<std::mutex> lock(info->m);
        check(!info->started && info->status == THS_DORMANT, "target is dormant after unwind");
        check(info->waitType == TSW_NONE && info->waitId == 0, "wait registration is removed");
    }
    {
        std::lock_guard<std::mutex> lock(sema->m);
        check(sema->count == 0 && sema->waiters == 0 && !sema->deleted,
              "semaphore count and lifetime are unchanged");
    }
    {
        std::lock_guard<std::mutex> lock(flag->m);
        check(flag->bits == 0 && flag->waiters == 0 && !flag->deleted,
              "event bits and lifetime are unchanged");
    }
    check(terminate(rdram, target) == KE_DORMANT, "second termination retains dormant error");
}
} // namespace

int main() {
    // Hard process deadline also bounds unexpected failures outside the CV test.
    std::thread([] {
        std::this_thread::sleep_for(std::chrono::seconds(20));
        std::fprintf(stderr, "FAIL test process watchdog expired\n");
        std::_Exit(4);
    }).detach();
    _putenv_s("REO_IMMEDIATE_SWITCH", "");
    std::vector<uint8_t> ram(32 * 1024 * 1024);
    g_currentThreadId = caller;
    threadInfo(caller, THS_RUN);
    check(terminate(ram.data(), 999999) == KE_UNKNOWN_THID, "unknown target retains its error");
    threadInfo(target, THS_DORMANT);
    check(terminate(ram.data(), target) == KE_DORMANT, "dormant target retains its error");
    resourceCase(ram.data(), false);
    resourceCase(ram.data(), true);
    std::printf("%d/%d checks passed\n", checks - failures, checks);
    std::fflush(stdout);
    std::_Exit(failures ? 1 : 0);
}
