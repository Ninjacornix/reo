#pragma once

#include "context.h"
#include <cstdint>
#include <vector>

namespace reo {

/*
 * PS2 BIOS Syscall Handling
 *
 * PS2 games make BIOS calls via the `syscall` instruction. The recompiled
 * code will call into these handlers instead. We provide high-level
 * implementations of the most commonly used BIOS services.
 *
 * The EE kernel provides ~120 syscalls. Games typically use a subset
 * focused on threading, memory allocation, TLB, DMA, and semaphores.
 */

// Thread management
enum class ThreadStatus {
    Free,
    Dormant, // Created but not started
    Running, // Currently executing
    Ready,   // Runnable, waiting for CPU
    Waiting, // Blocked (sleep, semaphore, etc.)
};

struct EEThread {
    int id = -1;
    ThreadStatus status = ThreadStatus::Free;
    uint32_t entry_pc = 0;  // Thread function address
    uint32_t stack_ptr = 0; // Stack pointer ($sp)
    uint32_t gp = 0;        // Global pointer ($gp)
    uint32_t arg = 0;       // Argument passed to thread start
    int priority = 0;       // Lower = higher priority
    int wakeup_count = 0;   // Pending wakeups (WakeupThread increments)
    int wait_sema_id = -1;  // Semaphore this thread is waiting on (-1 = none)
};

constexpr int MAX_EE_THREADS = 64;

// Semaphore management
struct EESemaphore {
    int id = -1;
    bool active = false;
    int count = 0;        // Current count
    int max_count = 1;    // Maximum count
    int init_count = 0;   // Initial count
    int wait_threads = 0; // Number of threads waiting
};

constexpr int MAX_EE_SEMAS = 128;

// Kernel state
struct KernelState {
    EEThread threads[MAX_EE_THREADS] = {};
    EESemaphore semaphores[MAX_EE_SEMAS] = {};
    int current_thread = 0; // Currently running thread ID
    int next_thread_id = 1;
    int next_sema_id = 1;

    // Vsync flag addresses (set by SetVSyncFlag syscall)
    uint32_t vsync_flag_addr1 = 0;
    uint32_t vsync_flag_addr2 = 0;

    void init() {
        for (int i = 0; i < MAX_EE_THREADS; i++) {
            threads[i].id = i;
            threads[i].status = ThreadStatus::Free;
        }
        for (int i = 0; i < MAX_EE_SEMAS; i++) {
            semaphores[i].id = i;
            semaphores[i].active = false;
        }
        // Thread 0 is the main thread
        threads[0].status = ThreadStatus::Running;
        threads[0].priority = 0;
        current_thread = 0;
        next_thread_id = 1;
        next_sema_id = 1;
    }
};

// Global kernel state
KernelState& get_kernel();

// Syscall dispatch
void handle_syscall(EEContext* ctx, uint32_t code);

// Individual handlers
void hle_SetGsCrt(EEContext* ctx);
void hle_GsPutIMR(EEContext* ctx);
void hle_SetVSyncFlag(EEContext* ctx);
void hle_ExecPS2(EEContext* ctx);

// Thread operations
void hle_CreateThread(EEContext* ctx);
void hle_DeleteThread(EEContext* ctx);
void hle_StartThread(EEContext* ctx);
void hle_ExitThread(EEContext* ctx);
void hle_ExitDeleteThread(EEContext* ctx);
void hle_SleepThread(EEContext* ctx);
void hle_WakeupThread(EEContext* ctx);
void hle_RotateThreadReadyQueue(EEContext* ctx);

// Semaphore operations
void hle_CreateSema(EEContext* ctx);
void hle_DeleteSema(EEContext* ctx);
void hle_SignalSema(EEContext* ctx);
void hle_WaitSema(EEContext* ctx);
void hle_PollSema(EEContext* ctx);

// Misc
void hle_FlushCache(EEContext* ctx);

// SIF (Sub-system Interface)
void hle_SifSetDma(EEContext* ctx);
void hle_SifDmaStat(EEContext* ctx);
void hle_SifSetReg(EEContext* ctx);
void hle_SifGetReg(EEContext* ctx);

} // namespace reo
