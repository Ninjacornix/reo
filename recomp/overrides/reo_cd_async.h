#pragma once
// File #1: complete sceCdRead (0x101788) asynchronously, as the IOP's CD DMA does on
// hardware. sceCdRead sets its busy word 0x207934 and status 0x207958, then issues the
// no-wait cdvdfsv N-command read (client 0x208AD0, rpc 1, send 0x207A00 {lsn, count,
// dst, mode}) with end callback 0x1004D8(endParam = 0x208A00). The callback releases
// the CD lock semaphore and clears the busy word via 0x100298; sceCdSync(1) polls it.
//
// The HLE SifCallRpc reads sectors and runs that callback synchronously while holding
// g_sif_call_rpc_mutex and guest execution, so a slow host read (measured 187/502 ms on
// 2026-11-03) froze every guest thread. Releasing guest execution inside the handler
// deadlocked against other RPC callers. This path instead returns from the call
// immediately; a host worker reads without guest execution or the RPC mutex, then runs
// the original callback as interrupt context (GuestExecutionScope, async stack), like
// alarm callbacks. Only that exact call is matched; every other RPC uses the HLE.
// REO_CD_ASYNC=0 restores the synchronous HLE read.
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include "ps2_syscalls.h"
#include "reo_hw_bridge.h"
#include "reo_game_clock_observer.h"
#include <atomic>
#include <condition_variable>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <exception>
#include <mutex>
#include <thread>

namespace reo_cd_async {
inline bool enabled = false;
inline uint8_t* ram = nullptr;

constexpr uint32_t client = 0x208ad0u, send = 0x207a00u, callback = 0x1004d8u,
                   return_address = 0x101908u;

struct Request {
    uint32_t lsn, count, dst, end_param, gp;
    PS2Runtime* runtime;
};
inline std::mutex mutex;
inline std::condition_variable wake;
inline std::deque<Request> queue;
inline std::once_flag started;
inline std::atomic<unsigned> logged{0};

inline void configure(const char* serial, uint8_t* memory, size_t bytes) {
    if (const char* value = std::getenv("REO_CD_ASYNC"); value && !std::strcmp(value, "0"))
        return;
    using reo_game_clock::word;
    if (!serial || std::strcmp(serial, "SLUS-20765") || !memory || bytes != PS2_RAM_SIZE ||
        word(memory, 0x1018e4) != 0xafb30000u ||  // sw s3, 0(sp)      endParam
        word(memory, 0x1018ec) != 0x256b04d8u ||  // addiu t3, t3, 0x4D8 callback
        word(memory, 0x1018f8) != 0x24080018u ||  // addiu t0, zero, 0x18 send size
        word(memory, 0x101900) != 0x0c045e7au ||  // jal SifCallRpc
        word(memory, 0x1004d8) == 0u)
        return;
    ram = memory;
    enabled = true;
    std::fprintf(stderr, "[CD-ASYNC] enabled: sceCdRead completes on a host worker\n");
}

inline void complete(const Request& request) {
    auto* bridge = ReoHwBridge::instance();
    const bool ok = bridge && bridge->readCdSectors(request.lsn, request.count, request.dst, ram);
    if (logged.fetch_add(1, std::memory_order_relaxed) < 40)
        std::fprintf(stderr, "[CD-ASYNC] read lsn=%u n=%u dst=0x%08X -> %s\n", request.lsn,
                     request.count, request.dst, ok ? "ok" : "FAIL");
    PS2Runtime* runtime = request.runtime;
    if (!runtime || runtime->isStopRequested() || !runtime->hasFunction(callback))
        return;
    thread_local uint32_t stack_top = 0;
    if (!stack_top)
        stack_top = runtime->reserveAsyncCallbackStack(0x4000u, 16u);
    R5900Context context{};
    SET_GPR_U32(&context, 28, request.gp);
    SET_GPR_U32(&context, 29, stack_top ? stack_top : PS2_RAM_SIZE - 0x10u);
    SET_GPR_U32(&context, 31, 0u);
    SET_GPR_U32(&context, 4, request.end_param);
    context.pc = callback;
    const auto function = runtime->lookupFunction(callback);
    // Interrupt context: atomic with respect to guest threads (as SIF DMA completion).
    PS2Runtime::GuestExecutionScope execution(runtime);
    if (!runtime->isStopRequested())
        function(ram, &context, runtime);
}

inline void worker() {
    for (;;) {
        Request request{};
        {
            std::unique_lock<std::mutex> lock(mutex);
            wake.wait(lock, [] { return !queue.empty(); });
            request = queue.front();
            queue.pop_front();
        }
        try {
            complete(request);
        } catch (const std::exception& error) {
            std::fprintf(stderr, "[CD-ASYNC] completion stopped: %s\n", error.what());
        } catch (...) {
        }
    }
}

// Bound at 0x1179E8 (SifCallRpc). Delegates everything except File #1's sceCdRead.
inline void sifCallRpc(uint8_t* rdram, R5900Context* context, PS2Runtime* runtime) {
    if (!enabled || rdram != ram || GPR_U32(context, 31) != return_address ||
        GPR_U32(context, 4) != client || GPR_U32(context, 5) != 1u ||
        GPR_U32(context, 6) != 1u || GPR_U32(context, 7) != send ||
        GPR_U32(context, 8) != 0x18u || GPR_U32(context, 11) != callback) {
        ps2_syscalls::sceSifCallRpc(rdram, context, runtime);
        return;
    }
    using reo_game_clock::word;
    const Request request{word(ram, send), word(ram, send + 4), word(ram, send + 8),
                          word(ram, GPR_U32(context, 29)), GPR_U32(context, 28), runtime};
    // Same guest-visible client fields as the HLE call (hdr.mode, command, end_function,
    // end_param); t_SifRpcClientData layout.
    auto put = [](uint32_t address, uint32_t value) { std::memcpy(ram + address, &value, 4); };
    put(client + 12, 1u);
    put(client + 16, 1u);
    put(client + 28, callback);
    put(client + 32, request.end_param);
    std::call_once(started, [] { std::thread(worker).detach(); });
    {
        std::lock_guard<std::mutex> lock(mutex);
        queue.push_back(request);
    }
    wake.notify_one();
    SET_GPR_S32(context, 2, 0);
}
} // namespace reo_cd_async
