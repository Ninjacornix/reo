#include "MiniTest.h"
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include "Syscalls/Common.h"
#include "../../third_party/PS2Recomp/ps2xRuntime/src/lib/ps2_guest_sched.h"

void sub_00189B08_0x189b08(uint8_t*, R5900Context*, PS2Runtime*);

void register_backedge_tests() {
    MiniTest::Case("GeneratedBackedge", [](TestCase& suite) {
        suite.Run("entry-target copy survives a higher-priority waiter", [](TestCase& t) {
            PS2Runtime runtime;
            t.IsTrue(runtime.memory().initialize(), "RAM initializes");
            auto* ram = runtime.memory().getRDRAM();
            auto* rdram = ram;
            auto& ctx = runtime.cpu();
            constexpr unsigned count = 128, src = 0x70000, dst = 0x72000;
            for (unsigned i = 0; i < count * 16; ++i)
                ram[src + i] = uint8_t(i * 13 + 7);
            const uint32_t terminal = 0xf0000001;
            std::memcpy(ram + src + (count - 1) * 16, &terminal, 4);
            std::memset(ram + dst, 0, count * 16);
            ps2_sched::setCurrentThread(200);
            ps2_sched::setPriority(200, 32);
            ps2_sched::setPriority(201, 1);
            std::atomic<bool> serviced{false};
            bool ranBeforeReturn = false;
            {
                PS2Runtime::GuestExecutionScope guest(&runtime);
                std::thread waiter([&] {
                    ps2_sched::setCurrentThread(201);
                    PS2Runtime::GuestExecutionScope irq(&runtime);
                    serviced = true;
                });
                ps2_sched::awaitQueued(201, 1000000);
                ctx.pc = 0x189b08;
                SET_GPR_U32(&ctx, 4, src);
                SET_GPR_U32(&ctx, 5, dst);
                SET_GPR_U32(&ctx, 6, count);
                SET_GPR_U32(&ctx, 31, 0x18c2f4);
                sub_00189B08_0x189b08(ram, &ctx, &runtime);
                // Exactly the generated caller's entry-PC completion convention.
                if (ctx.pc == 0x189b08)
                    ctx.pc = 0x18c2f4;
                ranBeforeReturn = serviced.load();
                {
                    PS2Runtime::GuestExecutionReleaseScope release(&runtime);
                    waiter.join();
                }
            }
            t.IsTrue(ranBeforeReturn, "higher-priority worker runs before copy returns");
            t.IsTrue(GPR_U32(&ctx, 6) == 0, "every loop iteration executed");
            t.IsTrue(std::memcmp(ram + src, ram + dst, count * 16) == 0,
                     "full copy includes final END+IRQ tag");
            ps2_sched::forget(200);
            ps2_sched::forget(201);
            ps2_sched::setCurrentThread(-1);
        });
        suite.Run("terminated suspended thread can leave an in-place yield", [](TestCase& t) {
            PS2Runtime runtime;
            runtime.memory().initialize();
            auto info = std::make_shared<ThreadInfo>();
            {
                std::lock_guard<std::mutex> lock(g_thread_map_mutex);
                g_threads[202] = info;
            }
            const int oldId = g_currentThreadId;
            g_currentThreadId = 202;
            ps2_sched::setCurrentThread(202);
            ps2_sched::setPriority(202, 32);
            ps2_sched::setPriority(203, 1);
            std::atomic<bool> done{false}, rescued{false};
            bool unwound = false;
            {
                PS2Runtime::GuestExecutionScope guest(&runtime);
                std::thread waiter([&] {
                    ps2_sched::setCurrentThread(203);
                    PS2Runtime::GuestExecutionScope irq(&runtime);
                    ps2_sched::setSuspended(202, true);
                    info->terminated = true;
                });
                ps2_sched::awaitQueued(203, 1000000);
                // Bound a regression that otherwise waits forever on suspension.
                std::thread rescue([&] {
                    for (unsigned i = 0; i < 200 && !done; ++i)
                        std::this_thread::sleep_for(std::chrono::milliseconds(5));
                    if (!done) {
                        rescued = true;
                        ps2_sched::setSuspended(202, false);
                    }
                });
                for (unsigned i = 0; i < 64 && !unwound; ++i)
                    unwound = runtime.shouldPreemptGuestExecution();
                done = true;
                {
                    PS2Runtime::GuestExecutionReleaseScope release(&runtime);
                    waiter.join();
                    rescue.join();
                    ps2_sched::setSuspended(202, false);
                }
            }
            t.IsTrue(unwound, "terminated thread unwinds to its dispatcher");
            t.IsTrue(info->terminated.load(), "higher-priority termination was delivered");
            t.IsTrue(!rescued, "terminated thread need not be resumed to unwind");
            {
                std::lock_guard<std::mutex> lock(g_thread_map_mutex);
                g_threads.erase(202);
            }
            g_currentThreadId = oldId;
            ps2_sched::forget(202);
            ps2_sched::forget(203);
            ps2_sched::setCurrentThread(-1);
        });
        suite.Run("stop still unwinds a generated backedge", [](TestCase& t) {
            PS2Runtime runtime;
            runtime.requestStop();
            t.IsTrue(runtime.shouldPreemptGuestExecution(), "stop breaks a busy loop");
        });
    });
}
