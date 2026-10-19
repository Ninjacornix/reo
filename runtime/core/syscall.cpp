#include "syscall.h"
#include <cstdio>
#include <cstring>

namespace reo {

// Syscall numbers
enum class Syscall : uint32_t {
    ResetEE = 0x01,
    SetGsCrt = 0x02,
    Exit = 0x04,
    LoadExecPS2 = 0x06,
    ExecPS2 = 0x07,
    DIntr = 0x0B,
    EIntr = 0x0C,
    CreateThread = 0x20,
    DeleteThread = 0x21,
    StartThread = 0x22,
    ExitThread = 0x23,
    ExitDeleteThread = 0x24,
    RotateThreadReadyQueue = 0x2F,
    SleepThread = 0x32,
    WakeupThread = 0x33,
    CreateSema = 0x40,
    DeleteSema = 0x41,
    SignalSema = 0x42,
    WaitSema = 0x44,
    PollSema = 0x45,
    FlushCache = 0x64,
    GsPutIMR = 0x71,
    SetVSyncFlag = 0x73,
    SetSyscall = 0x74,
    SifDmaStat = 0x76,
    SifSetDma = 0x77,
    SifSetDChain = 0x78,
    SifSetReg = 0x79,
    SifGetReg = 0x7A,
};

// Global kernel state
static KernelState s_kernel;

KernelState& get_kernel() {
    return s_kernel;
}

// Scheduler helper
// Find the highest-priority ready thread (lowest priority number)
static int find_next_ready_thread() {
    int best = -1;
    int best_prio = 0x7FFFFFFF;
    for (int i = 0; i < MAX_EE_THREADS; i++) {
        if (s_kernel.threads[i].status == ThreadStatus::Ready &&
            s_kernel.threads[i].priority < best_prio) {
            best = i;
            best_prio = s_kernel.threads[i].priority;
        }
    }
    return best;
}

// Syscall dispatch
void handle_syscall(EEContext* ctx, uint32_t code) {
    Syscall sc = (Syscall)(ctx->gpr[3].lo32()); // $v1 holds syscall number

    switch (sc) {
        case Syscall::SetGsCrt:
            hle_SetGsCrt(ctx);
            break;
        case Syscall::GsPutIMR:
            hle_GsPutIMR(ctx);
            break;
        case Syscall::SetVSyncFlag:
            hle_SetVSyncFlag(ctx);
            break;
        case Syscall::ExecPS2:
            hle_ExecPS2(ctx);
            break;

        // Thread management
        case Syscall::CreateThread:
            hle_CreateThread(ctx);
            break;
        case Syscall::DeleteThread:
            hle_DeleteThread(ctx);
            break;
        case Syscall::StartThread:
            hle_StartThread(ctx);
            break;
        case Syscall::ExitThread:
            hle_ExitThread(ctx);
            break;
        case Syscall::ExitDeleteThread:
            hle_ExitDeleteThread(ctx);
            break;
        case Syscall::SleepThread:
            hle_SleepThread(ctx);
            break;
        case Syscall::WakeupThread:
            hle_WakeupThread(ctx);
            break;
        case Syscall::RotateThreadReadyQueue:
            hle_RotateThreadReadyQueue(ctx);
            break;

        // Semaphores
        case Syscall::CreateSema:
            hle_CreateSema(ctx);
            break;
        case Syscall::DeleteSema:
            hle_DeleteSema(ctx);
            break;
        case Syscall::SignalSema:
            hle_SignalSema(ctx);
            break;
        case Syscall::WaitSema:
            hle_WaitSema(ctx);
            break;
        case Syscall::PollSema:
            hle_PollSema(ctx);
            break;

        // SIF
        case Syscall::SifSetDma:
            hle_SifSetDma(ctx);
            break;
        case Syscall::SifDmaStat:
            hle_SifDmaStat(ctx);
            break;
        case Syscall::SifSetReg:
            hle_SifSetReg(ctx);
            break;
        case Syscall::SifGetReg:
            hle_SifGetReg(ctx);
            break;
        case Syscall::SifSetDChain:
            // DMA chain mode — accept silently
            break;

        // Misc
        case Syscall::FlushCache:
            hle_FlushCache(ctx);
            break;
        case Syscall::DIntr:
            ctx->gpr[2].set32(1); // Return old interrupt state (enabled)
            break;
        case Syscall::EIntr:
            break;
        case Syscall::Exit:
            printf("[KERN] Exit syscall — stopping\n");
            break;
        case Syscall::SetSyscall:
            printf("[KERN] SetSyscall: num=0x%02X handler=0x%08X\n", ctx->gpr[4].lo32(),
                   ctx->gpr[5].lo32());
            break;

        default:
            printf("[SYSCALL] Unhandled syscall 0x%02X at PC=0x%08X\n", (uint32_t)sc, ctx->pc);
            break;
    }
}

//
// GS / VIDEO
//
void hle_SetGsCrt(EEContext* ctx) {
    uint32_t interlace = ctx->gpr[4].lo32();
    uint32_t mode = ctx->gpr[5].lo32();
    uint32_t field = ctx->gpr[6].lo32();

    const char* mode_str = "unknown";
    switch (mode) {
        case 0x02:
            mode_str = "NTSC (480i)";
            break;
        case 0x03:
            mode_str = "PAL (576i)";
            break;
        case 0x1A:
            mode_str = "480p (VESA)";
            break;
        case 0x50:
            mode_str = "1080i";
            break;
    }

    printf("[GS] SetGsCrt: interlace=%d, mode=0x%02X (%s), field=%d\n", interlace, mode, mode_str,
           field);
}

void hle_GsPutIMR(EEContext* ctx) {
    uint32_t imr = ctx->gpr[4].lo32();
    printf("[GS] GsPutIMR: 0x%08X\n", imr);
}

void hle_SetVSyncFlag(EEContext* ctx) {
    s_kernel.vsync_flag_addr1 = ctx->gpr[4].lo32();
    s_kernel.vsync_flag_addr2 = ctx->gpr[5].lo32();
    printf("[GS] SetVSyncFlag: flag1=0x%08X flag2=0x%08X\n", s_kernel.vsync_flag_addr1,
           s_kernel.vsync_flag_addr2);
}

void hle_ExecPS2(EEContext* ctx) {
    uint32_t entry = ctx->gpr[4].lo32();
    printf("[KERN] ExecPS2: entry=0x%08X\n", entry);
    // The main loop will look up this address in the recompiled function table
    ctx->pc = entry;
}

//
// THREAD MANAGEMENT
//
void hle_CreateThread(EEContext* ctx) {
    // $a0 = pointer to ThreadParam struct in EE memory
    // struct ThreadParam { int status; void* func; void* stack; int stack_size;
    //                      void* gp; int priority; ... };
    uint32_t param_addr = ctx->gpr[4].lo32();

    // Read thread parameters from guest memory
    uint32_t func = ctx->memory.read32(param_addr + 4);
    uint32_t stack = ctx->memory.read32(param_addr + 8);
    int stack_size = (int)ctx->memory.read32(param_addr + 12);
    uint32_t gp_val = ctx->memory.read32(param_addr + 16);
    int priority = (int)ctx->memory.read32(param_addr + 20);

    // Find a free thread slot
    int slot = -1;
    for (int i = 1; i < MAX_EE_THREADS; i++) {
        if (s_kernel.threads[i].status == ThreadStatus::Free) {
            slot = i;
            break;
        }
    }

    if (slot < 0) {
        printf("[KERN] CreateThread: no free slots!\n");
        ctx->gpr[2].set32((uint32_t)-1);
        return;
    }

    EEThread& t = s_kernel.threads[slot];
    t.status = ThreadStatus::Dormant;
    t.entry_pc = func;
    t.stack_ptr = stack + stack_size - 16; // Stack grows down, align to 16
    t.gp = gp_val;
    t.priority = priority;
    t.wakeup_count = 0;
    t.wait_sema_id = -1;

    printf("[KERN] CreateThread: id=%d entry=0x%08X prio=%d stack=0x%08X\n", slot, func, priority,
           t.stack_ptr);

    ctx->gpr[2].set32(slot); // Return thread ID in $v0
}

void hle_DeleteThread(EEContext* ctx) {
    int tid = (int)ctx->gpr[4].lo32();
    if (tid <= 0 || tid >= MAX_EE_THREADS) {
        ctx->gpr[2].set32((uint32_t)-1);
        return;
    }

    EEThread& t = s_kernel.threads[tid];
    if (t.status != ThreadStatus::Dormant) {
        printf("[KERN] DeleteThread: thread %d not dormant (status=%d)\n", tid, (int)t.status);
        ctx->gpr[2].set32((uint32_t)-1);
        return;
    }

    t.status = ThreadStatus::Free;
    printf("[KERN] DeleteThread: id=%d\n", tid);
    ctx->gpr[2].set32(0);
}

void hle_StartThread(EEContext* ctx) {
    int tid = (int)ctx->gpr[4].lo32();
    uint32_t arg = ctx->gpr[5].lo32();

    if (tid <= 0 || tid >= MAX_EE_THREADS) {
        ctx->gpr[2].set32((uint32_t)-1);
        return;
    }

    EEThread& t = s_kernel.threads[tid];
    if (t.status != ThreadStatus::Dormant) {
        printf("[KERN] StartThread: thread %d not dormant\n", tid);
        ctx->gpr[2].set32((uint32_t)-1);
        return;
    }

    t.status = ThreadStatus::Ready;
    t.arg = arg;

    printf("[KERN] StartThread: id=%d entry=0x%08X arg=0x%08X\n", tid, t.entry_pc, arg);
    ctx->gpr[2].set32(0);
}

void hle_ExitThread(EEContext* ctx) {
    int tid = s_kernel.current_thread;
    printf("[KERN] ExitThread: id=%d\n", tid);

    s_kernel.threads[tid].status = ThreadStatus::Dormant;

    // Schedule next thread
    int next = find_next_ready_thread();
    if (next >= 0) {
        s_kernel.threads[next].status = ThreadStatus::Running;
        s_kernel.current_thread = next;
    }
}

void hle_ExitDeleteThread(EEContext* ctx) {
    int tid = s_kernel.current_thread;
    printf("[KERN] ExitDeleteThread: id=%d\n", tid);

    s_kernel.threads[tid].status = ThreadStatus::Free;

    int next = find_next_ready_thread();
    if (next >= 0) {
        s_kernel.threads[next].status = ThreadStatus::Running;
        s_kernel.current_thread = next;
    }
}

void hle_SleepThread(EEContext* ctx) {
    int tid = s_kernel.current_thread;

    EEThread& t = s_kernel.threads[tid];

    // If there are pending wakeups, consume one and don't sleep
    if (t.wakeup_count > 0) {
        t.wakeup_count--;
        return;
    }

    t.status = ThreadStatus::Waiting;
    printf("[KERN] SleepThread: id=%d sleeping\n", tid);

    // Schedule next thread
    int next = find_next_ready_thread();
    if (next >= 0) {
        s_kernel.threads[next].status = ThreadStatus::Running;
        s_kernel.current_thread = next;
    } else {
        // No ready threads — in a real system this would idle.
        // For our runtime, we just return and let the main loop handle it.
        printf("[KERN] SleepThread: no ready threads (idle)\n");
    }
}

void hle_WakeupThread(EEContext* ctx) {
    int tid = (int)ctx->gpr[4].lo32();

    if (tid < 0 || tid >= MAX_EE_THREADS) {
        ctx->gpr[2].set32((uint32_t)-1);
        return;
    }

    EEThread& t = s_kernel.threads[tid];

    if (t.status == ThreadStatus::Waiting) {
        t.status = ThreadStatus::Ready;
        printf("[KERN] WakeupThread: id=%d → Ready\n", tid);
    } else {
        // Thread not sleeping yet — bank the wakeup
        t.wakeup_count++;
    }

    ctx->gpr[2].set32(0);
}

void hle_RotateThreadReadyQueue(EEContext* ctx) {
    int priority = (int)ctx->gpr[4].lo32();
    // Round-robin among threads of same priority — for now, just yield
    int next = find_next_ready_thread();
    if (next >= 0 &&
        s_kernel.threads[next].priority <= s_kernel.threads[s_kernel.current_thread].priority) {
        s_kernel.threads[s_kernel.current_thread].status = ThreadStatus::Ready;
        s_kernel.threads[next].status = ThreadStatus::Running;
        s_kernel.current_thread = next;
    }
    ctx->gpr[2].set32(0);
}

//
// SEMAPHORE MANAGEMENT
//
void hle_CreateSema(EEContext* ctx) {
    // $a0 = pointer to SemaParam struct
    // struct SemaParam { int count; int max_count; int init_count; ... }
    uint32_t param_addr = ctx->gpr[4].lo32();

    uint32_t init_count = ctx->memory.read32(param_addr + 0);
    uint32_t max_count = ctx->memory.read32(param_addr + 4);

    // Find free semaphore slot
    int slot = -1;
    for (int i = 0; i < MAX_EE_SEMAS; i++) {
        if (!s_kernel.semaphores[i].active) {
            slot = i;
            break;
        }
    }

    if (slot < 0) {
        printf("[KERN] CreateSema: no free slots!\n");
        ctx->gpr[2].set32((uint32_t)-1);
        return;
    }

    EESemaphore& s = s_kernel.semaphores[slot];
    s.active = true;
    s.count = (int)init_count;
    s.max_count = (int)max_count;
    s.init_count = (int)init_count;
    s.wait_threads = 0;

    printf("[KERN] CreateSema: id=%d init=%d max=%d\n", slot, s.count, s.max_count);
    ctx->gpr[2].set32(slot);
}

void hle_DeleteSema(EEContext* ctx) {
    int sid = (int)ctx->gpr[4].lo32();
    if (sid < 0 || sid >= MAX_EE_SEMAS || !s_kernel.semaphores[sid].active) {
        ctx->gpr[2].set32((uint32_t)-1);
        return;
    }

    // Wake any threads waiting on this semaphore
    for (int i = 0; i < MAX_EE_THREADS; i++) {
        if (s_kernel.threads[i].wait_sema_id == sid) {
            s_kernel.threads[i].status = ThreadStatus::Ready;
            s_kernel.threads[i].wait_sema_id = -1;
        }
    }

    s_kernel.semaphores[sid].active = false;
    printf("[KERN] DeleteSema: id=%d\n", sid);
    ctx->gpr[2].set32(0);
}

void hle_SignalSema(EEContext* ctx) {
    int sid = (int)ctx->gpr[4].lo32();
    if (sid < 0 || sid >= MAX_EE_SEMAS || !s_kernel.semaphores[sid].active) {
        ctx->gpr[2].set32((uint32_t)-1);
        return;
    }

    EESemaphore& s = s_kernel.semaphores[sid];

    // Check if any thread is waiting on this semaphore
    bool woke_thread = false;
    for (int i = 0; i < MAX_EE_THREADS; i++) {
        if (s_kernel.threads[i].status == ThreadStatus::Waiting &&
            s_kernel.threads[i].wait_sema_id == sid) {
            // Wake the first waiting thread
            s_kernel.threads[i].status = ThreadStatus::Ready;
            s_kernel.threads[i].wait_sema_id = -1;
            s.wait_threads--;
            woke_thread = true;
            break;
        }
    }

    if (!woke_thread) {
        // No waiters — increment count (up to max)
        if (s.count < s.max_count) {
            s.count++;
        }
    }

    ctx->gpr[2].set32(0);
}

void hle_WaitSema(EEContext* ctx) {
    int sid = (int)ctx->gpr[4].lo32();
    if (sid < 0 || sid >= MAX_EE_SEMAS || !s_kernel.semaphores[sid].active) {
        ctx->gpr[2].set32((uint32_t)-1);
        return;
    }

    EESemaphore& s = s_kernel.semaphores[sid];

    if (s.count > 0) {
        // Semaphore available — decrement and return
        s.count--;
        ctx->gpr[2].set32(0);
    } else {
        // Block current thread
        int tid = s_kernel.current_thread;
        s_kernel.threads[tid].status = ThreadStatus::Waiting;
        s_kernel.threads[tid].wait_sema_id = sid;
        s.wait_threads++;

        // Schedule next thread
        int next = find_next_ready_thread();
        if (next >= 0) {
            s_kernel.threads[next].status = ThreadStatus::Running;
            s_kernel.current_thread = next;
        }

        ctx->gpr[2].set32(0);
    }
}

void hle_PollSema(EEContext* ctx) {
    int sid = (int)ctx->gpr[4].lo32();
    if (sid < 0 || sid >= MAX_EE_SEMAS || !s_kernel.semaphores[sid].active) {
        ctx->gpr[2].set32((uint32_t)-1);
        return;
    }

    EESemaphore& s = s_kernel.semaphores[sid];

    if (s.count > 0) {
        s.count--;
        ctx->gpr[2].set32(0);
    } else {
        // Would block — return error instead
        ctx->gpr[2].set32((uint32_t)-1);
    }
}

//
// SIF (Sub-system Interface) — EE ↔ IOP communication
//
static uint32_t sif_regs[8] = {};

void hle_SifSetDma(EEContext* ctx) {
    // $a0 = pointer to SifDmaTransfer struct, $a1 = count
    uint32_t dma_addr = ctx->gpr[4].lo32();
    uint32_t count = ctx->gpr[5].lo32();

    printf("[SIF] SifSetDma: addr=0x%08X count=%d\n", dma_addr, count);

    // Return a DMA transfer ID (non-zero = success)
    static uint32_t dma_id = 1;
    ctx->gpr[2].set32(dma_id++);
}

void hle_SifDmaStat(EEContext* ctx) {
    // Check if a DMA transfer is complete
    // Always return -1 (completed) since we process DMA instantly
    ctx->gpr[2].set32((uint32_t)-1);
}

void hle_SifSetReg(EEContext* ctx) {
    uint32_t reg = ctx->gpr[4].lo32();
    uint32_t value = ctx->gpr[5].lo32();

    uint32_t idx = reg & 0x7;
    sif_regs[idx] = value;
    printf("[SIF] SetReg: reg=%d value=0x%08X\n", idx, value);
    ctx->gpr[2].set32(0);
}

void hle_SifGetReg(EEContext* ctx) {
    uint32_t reg = ctx->gpr[4].lo32();
    uint32_t idx = reg & 0x7;
    ctx->gpr[2].set32(sif_regs[idx]);
}

//
// MISC
//
void hle_FlushCache(EEContext* ctx) {
    // No-op — our runtime has no cache
}

} // namespace reo
