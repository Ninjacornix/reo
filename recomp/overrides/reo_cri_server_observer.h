#pragma once
// Read-only timing of File #1's CRI-style server dispatcher (0x141E20). The original
// runs up to six registered callbacks {fn, arg} from 0x264820 + id * 0x30; guest
// thread 6 (entry 0x12AD70) dispatches id 4. A 2026-11-03 session measured
// 161/230 ms CPU ownership by thread 6 during two visible freezes. This observer
// names the slow dispatch: it delegates the original exactly once and only reports
// dispatches at or above REO_CRI_SERVER_SLOW_MS (unset or 0 disables; the launcher's
// Developer > "Audio and disc service stalls" sets 20).
// ms is wall time; own_ms subtracts this guest thread's scheduler waits (time spent
// letting other guest threads run), matching the heartbeat's own/wait accounting.
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include "reo_game_clock_observer.h"
#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#ifdef _WIN32
// Declared here rather than including <windows.h> (min/max macros in including TUs).
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(union _LARGE_INTEGER*);
#endif

extern void sub_00141E20_0x141e20(uint8_t*, R5900Context*, PS2Runtime*);
extern void sub_00130D48_0x130d48(uint8_t*, R5900Context*, PS2Runtime*);
extern void sub_00135EF0_0x135ef0(uint8_t*, R5900Context*, PS2Runtime*);
extern void sub_00137D80_0x137d80(uint8_t*, R5900Context*, PS2Runtime*);
extern void sub_00129A60_0x129a60(uint8_t*, R5900Context*, PS2Runtime*);
extern void sub_00138208_0x138208(uint8_t*, R5900Context*, PS2Runtime*);
extern void sub_0012D678_0x12d678(uint8_t*, R5900Context*, PS2Runtime*);
extern void sub_00134C58_0x134c58(uint8_t*, R5900Context*, PS2Runtime*);
extern void sub_0012C798_0x12c798(uint8_t*, R5900Context*, PS2Runtime*);
namespace ps2_sched {
extern std::atomic<int64_t> g_waitNs[256];
int currentThread();
}

namespace reo_cri_server {
inline uint8_t* ram = nullptr;
inline int64_t threshold_ns = 0;
inline unsigned reports = 0;
constexpr unsigned report_limit = 200;
constexpr uint32_t table = 0x264820u;
// Id 4's only callback 0x12A1C8 -> 0x12A020 stores its step (1..6) at 0x20F390
// before calling 0x130D48, 0x135EF0, 0x137D80, 0x135EF0, 0x130D48, 0x129A60.
// Id 2's callback 0x12A1A8 -> 0x132C08 (ADX-style server) stores its step (1..3)
// at 0x21B754 around 0x12D678, the 16-handle 0x134C58 loop, and 0x12C798.
inline thread_local uint32_t step_word = 0;
inline thread_local int64_t step_ns[8] = {};
inline thread_local bool in_dispatch = false;

// QueryPerformanceCounter ticks: the time domain of the launcher's slowdown trace.
inline uint64_t qpc_now() {
#ifdef _WIN32
    long long value = 0; // LARGE_INTEGER is a union over one 64-bit QuadPart
    QueryPerformanceCounter(reinterpret_cast<union _LARGE_INTEGER*>(&value));
    return uint64_t(value);
#else
    return 0;
#endif
}
inline int64_t now_ns() {
    return std::chrono::duration_cast<std::chrono::nanoseconds>(
               std::chrono::steady_clock::now().time_since_epoch())
        .count();
}
// Step 3 (0x137D80) brackets its device calls with original marker writes
// 0x138208(code): 0x1600/1601, 0x1700/1701, 0x1800/1801, 0x1900/1901 (CD path),
// 0x2000/2001, 0x2100/2101, 0x2200/2201|2202 (file path).
struct Mark { uint32_t code; int64_t ns; };
inline thread_local Mark marks[24] = {};
inline thread_local unsigned mark_count = 0;
inline int64_t waited_ns() {
    const int tid = ps2_sched::currentThread();
    return tid >= 0 && tid < 256 ? ps2_sched::g_waitNs[tid].load(std::memory_order_relaxed) : 0;
}
inline thread_local int64_t step3_begin = 0;
inline thread_local bool in_step3 = false;
inline void marker(uint8_t* memory, R5900Context* context, PS2Runtime* runtime) {
    if (in_step3 && mark_count < 24)
        marks[mark_count++] = {GPR_U32(context, 4), now_ns() - waited_ns()};
    sub_00138208_0x138208(memory, context, runtime);
}
// HLE calls inside step 3: [0] SifInitRpc (0x117080), [1] SifCallRpc (0x1179E8).
inline thread_local int64_t hle_ns[2] = {};
inline thread_local unsigned hle_calls[2] = {};
template <void (*original)(uint8_t*, R5900Context*, PS2Runtime*), unsigned slot>
inline void hle(uint8_t* memory, R5900Context* context, PS2Runtime* runtime) {
    if (!in_step3) {
        original(memory, context, runtime);
        return;
    }
    const int64_t begin = now_ns() - waited_ns();
    original(memory, context, runtime);
    hle_ns[slot] += now_ns() - waited_ns() - begin;
    ++hle_calls[slot];
}
template <void (*original)(uint8_t*, R5900Context*, PS2Runtime*)>
inline void step(uint8_t* memory, R5900Context* context, PS2Runtime* runtime) {
    if (!in_dispatch || memory != ram) {
        original(memory, context, runtime);
        return;
    }
    const uint32_t index = reo_game_clock::word(ram, step_word);
    const bool file_step = step_word == 0x20f390u && index == 3;
    const int64_t begin = now_ns() - waited_ns();
    if (file_step) {
        step3_begin = begin;
        mark_count = 0;
        in_step3 = true;
    }
    original(memory, context, runtime);
    if (file_step)
        in_step3 = false;
    const int64_t end = now_ns() - waited_ns();
    if (index < 8)
        step_ns[index] += end - begin;
    if (file_step && mark_count < 24)
        marks[mark_count++] = {0xffffffffu, end};
}

inline void configure(const char* serial, uint8_t* memory, size_t bytes) {
    if (const char* value = std::getenv("REO_CRI_SERVER_SLOW_MS"))
        threshold_ns = std::strtoll(value, nullptr, 10) * 1'000'000;
    if (threshold_ns <= 0 || !serial || std::strcmp(serial, "SLUS-20765") || !memory ||
        bytes != PS2_RAM_SIZE ||
        reo_game_clock::word(memory, 0x141e20) != 0x00041040u ||
        reo_game_clock::word(memory, 0x141e24) != 0x27bdffc0u ||
        reo_game_clock::word(memory, 0x141e28) != 0x00441021u ||
        reo_game_clock::word(memory, 0x141e2c) != 0xffb40020u)
        return;
    ram = memory;
    std::fprintf(stderr, "[CRI-SERVER] timing enabled; reporting dispatches >= %lld ms\n",
                 static_cast<long long>(threshold_ns / 1'000'000));
}

inline void dispatch(uint8_t* memory, R5900Context* context, PS2Runtime* runtime) {
    const uint32_t id = GPR_U32(context, 4);
    const bool observe = ram && memory == ram && id < 8;
    uint32_t slots[12] = {};
    if (observe)
        for (unsigned i = 0; i < 12; ++i)
            slots[i] = reo_game_clock::word(ram, table + id * 0x30u + i * 4u);
    const bool steps = observe && (id == 4 || id == 2) && !in_dispatch;
    if (steps) {
        step_word = id == 4 ? 0x20f390u : 0x21b754u;
        std::memset(step_ns, 0, sizeof(step_ns));
        step3_begin = 0;
        mark_count = 0;
        std::memset(hle_ns, 0, sizeof(hle_ns));
        std::memset(hle_calls, 0, sizeof(hle_calls));
        in_dispatch = true;
    }
    const int64_t begin = now_ns(), waited = waited_ns();
    const uint64_t qpc = qpc_now();
    sub_00141E20_0x141e20(memory, context, runtime);
    const int64_t elapsed = now_ns() - begin;
    const int64_t owned = elapsed - (waited_ns() - waited);
    if (steps)
        in_dispatch = false;
    if (!observe || owned < threshold_ns || reports >= report_limit)
        return;
    ++reports;
    // qpc_begin shares the slowdown recorder's QPC domain (continuous.csv time column).
    std::fprintf(stderr, "[CRI-SERVER] slow id=%u own_ms=%.3f ms=%.3f qpc_begin=%llu callbacks:",
                 id, owned / 1e6, elapsed / 1e6, static_cast<unsigned long long>(qpc));
    for (unsigned i = 0; i < 6; ++i)
        if (slots[i * 2])
            std::fprintf(stderr, " [%u]0x%06x(0x%08x)", i, slots[i * 2], slots[i * 2 + 1]);
    if (steps) {
        std::fprintf(stderr, " steps_own_ms:");
        for (unsigned i = 1; i <= (id == 4 ? 6u : 3u); ++i)
            std::fprintf(stderr, " %u=%.3f", i, step_ns[i] / 1e6);
        // Step-3 timeline: each marker with owned ms since the previous point (end = return).
        if (step3_begin) {
            std::fprintf(stderr, " step3:");
            int64_t previous = step3_begin;
            for (unsigned i = 0; i < mark_count; ++i) {
                if (marks[i].code == 0xffffffffu)
                    std::fprintf(stderr, " end+%.3f", (marks[i].ns - previous) / 1e6);
                else
                    std::fprintf(stderr, " %x+%.3f", marks[i].code, (marks[i].ns - previous) / 1e6);
                previous = marks[i].ns;
            }
            std::fprintf(stderr, " hle: SifInitRpc=%ux%.3f SifCallRpc=%ux%.3f", hle_calls[0],
                         hle_ns[0] / 1e6, hle_calls[1], hle_ns[1] / 1e6);
        }
    }
    std::fprintf(stderr, "\n");
}
} // namespace reo_cri_server
