#if defined(REO_GAME_FILE1)
#include "overrides/reo_cheats.h"
#include "overrides/reo_mods.h"
#include "overrides/reo_rumble.h"
#include "overrides/reo_audio.h"
#endif
#if defined(REO_HAVE_GPU_PARENT_NATURAL_HOOKS) && defined(REO_GAME_FILE1)
#include "natural_dispatch.h"
#endif
#include "gs_priv_atomic.h"

#include "gs_backend_route.h"
#if __has_include("ps2_codegen_features.h")
#include "ps2_codegen_features.h"
#else
#define REO_GENERATED_SOURCE_AUDIT 0
#endif

#include "vu_specialized_route.h"

#include "vu_native_geometry_route.h"

#include "vu_program_collection.h"

#include "vif_launch_overhead.h"

#include "overrides/reo_game_clock_observer.h"
#include "overrides/reo_performance.h"

#include "overrides/actor_first_nonfinite.h"
#include "overrides/ground_query_origin.h"
#include "overrides/reo_gpu_movie_boundary.h"
#if defined(REO_GAME_FILE1)
#include "overrides/movie_join_observer.h"
#include "overrides/reo_memory_card.h"
#endif

#include "reo_vu_specialized.h"

#ifdef REO_HAVE_PARALLEL_GS

#include "parallel_backend.h"
#include "enrollment/installer.hpp"
namespace gs_backend_bridge {
void publishPrivilegedReset(const Privileged&);
}
#if defined(_WIN32) && defined(REO_GAME_FILE1)
#include "movie_runtime/native_movie_game.h"
#endif

#endif

/*

 * REO Bootstrap — Main entry point for running recompiled RE Outbreak

 *

 * Supports both games:

 *   - RE Outbreak File #1 (SLUS-20765): 3,209 recompiled functions

 *   - RE Outbreak File #2 (SLUS-20984): 3,525 recompiled functions

 *

 * Build: compile all generated .cpp files + this bootstrap against

 *        PS2Recomp's runtime library.

 *

 * Usage:

 *   reo_recomp --game file1   (or --game file2)

 *   reo_recomp --elf <path> --data <path>   (manual override)

 */

#include "ps2_runtime.h"

#include "ps2_debug_panel.h"

#include "ps2_recompiled_functions.h"

#include "game_overrides.h"

#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <string>

#include <vector>

#include <filesystem>
#include <fstream>
#include "gpu_display_transport.h"
#include "raylib.h"

#include <chrono>

namespace fs = std::filesystem;

// Function registration — defined in each game's generated register_functions.cpp

// The active build target (file1 or file2) provides the implementation.

extern void registerAllFunctions(PS2Runtime& runtime);
#if defined(REO_GAME_FILE1)
namespace reo_irq_integer {
void installActualOriginalCpuIrqGameReceiver(PS2Runtime&);
}
#endif
namespace reo_missing_entries {
void install(PS2Runtime& runtime);
}
extern bool ReoInstallPaletteOriginObserver(PS2Runtime& runtime);
#if defined(REO_GAME_FILE1)
extern bool ReoInstallPaletteParentFrontierObserver(PS2Runtime& runtime);
#endif

// Overlay function registration — runtime-loaded code dumped from PCSX2

extern void registerOverlayFunctions(PS2Runtime& runtime);

#ifdef REO_HAVE_OVL

extern void reoRegisterOverlays(PS2Runtime& runtime); // recomp/config/output_ovl (BIN/*.DAT)

#endif

#ifdef REO_HAVE_EXTRA

extern void reoRegisterExtraFunctions(PS2Runtime& runtime); // recomp/config/output_extra

#endif

extern void reoPad2Stop(); // overrides/reo_hw_bridge.cpp

extern void
reoDebugPanelText(std::string& out); // overrides/reo_hw_bridge.cpp, see ps2_debug_panel.h

struct GameDef {

    const char* name;

    const char* elf_name;

    const char* serial;

    const char* default_data;

    uint32_t entry_point;
};

static const GameDef s_games[] = {

    {"Resident Evil Outbreak", "SLUS_207.65", "SLUS-20765", "game_data", 0x00100008},

    {"Resident Evil Outbreak: File #2", "SLUS_209.84", "SLUS-20984", "game_data_file2", 0x00100008},

};

static void print_banner(const GameDef& g) {

    printf("\n");

    printf("  ██████╗ ███████╗ ██████╗ \n");

    printf("  ██╔══██╗██╔════╝██╔═══██╗\n");

    printf("  ██████╔╝█████╗  ██║   ██║\n");

    printf("  ██╔══██╗██╔══╝  ██║   ██║\n");

    printf("  ██║  ██║███████╗╚██████╔╝\n");

    printf("  ╚═╝  ╚═╝╚══════╝ ╚═════╝ \n");

    printf("\n");

    printf("  %s: Recompiled\n", g.name);

    printf("  [%s]  Static recompilation — no emulator\n", g.serial);

    printf("  Don't let the memory of Raccoon City die.\n");

    printf("\n");
}

#ifdef _WIN32

#ifndef NOMINMAX

#define NOMINMAX

#endif

// Raylib and Win32 export these names with incompatible signatures.
#define CloseWindow ReoWin32CloseWindow
#define ShowCursor ReoWin32ShowCursor
#define Rectangle ReoWin32Rectangle
#include <windows.h>
#undef CloseWindow
#undef ShowCursor
#undef Rectangle
#include "runtime/timer/windows_resolution.h"

// Crash diagnostics: on an unhandled exception print the code, fault address and the

// unwound host call stack as module+RVA (exe frames resolve with a /MAP link, see

// docs/DIVERGENCES.md D15). Read-only; does not change execution.

//

// RECONSTRUCTED 2026-10-18: the module+rva version (reoCrashDiag, used by the

// gpuinc4x builds, e.g. "addr=KERNELBASE.dll+0xC41CA" / "[CRASH] stack (module+rva):")

// was lost from this file by an accidental `git checkout`; no copy survived. Rebuilt

// from the format strings and symbol names in the Oct 18 private-build object

// (snapshotModules/findModule/modules/moduleCount, "%ls+0x%llX", "raw 0x%llX").

#include <tlhelp32.h>

namespace reoCrashDiag {

struct Module {
    DWORD64 base, end;
    wchar_t name[44];
};

Module modules[128];

int moduleCount = 0;

// Taken at install time (and again in the filter): the filter must not depend on

// loader state that a crashing thread may hold.

void snapshotModules() {

    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, GetCurrentProcessId());

    if (snap == INVALID_HANDLE_VALUE)
        return;

    MODULEENTRY32W me{};
    me.dwSize = sizeof(me);

    int n = 0;

    for (BOOL ok = Module32FirstW(snap, &me); ok && n < 128; ok = Module32NextW(snap, &me)) {

        Module& m = modules[n++];

        m.base = reinterpret_cast<DWORD64>(me.modBaseAddr);

        m.end = m.base + me.modBaseSize;

        wcsncpy_s(m.name, me.szModule, _TRUNCATE);
    }

    moduleCount = n;

    CloseHandle(snap);
}

const Module* findModule(DWORD64 address) {

    for (int i = 0; i < moduleCount; ++i)

        if (address >= modules[i].base && address < modules[i].end)
            return &modules[i];

    return nullptr;
}

} // namespace reoCrashDiag

static LONG WINAPI reoCrashFilter(EXCEPTION_POINTERS* ep) {

    CONTEXT c = *ep->ContextRecord;

    reoCrashDiag::snapshotModules(); // include DLLs loaded after install (Vulkan driver etc.)

    char where[128];

    const auto* faultAddress = ep->ExceptionRecord->ExceptionAddress;

    if (const auto* m = reoCrashDiag::findModule(reinterpret_cast<DWORD64>(faultAddress)))

        _snprintf_s(
            where, sizeof(where), _TRUNCATE, "%ls+0x%llX", m->name,

            static_cast<unsigned long long>(reinterpret_cast<DWORD64>(faultAddress) - m->base));

    else

        _snprintf_s(where, sizeof(where), _TRUNCATE, "raw %p", faultAddress);

    fprintf(stderr, "\n[CRASH] code=0x%08lX addr=%s tid=%lu",

            ep->ExceptionRecord->ExceptionCode, where, GetCurrentThreadId());

    if (ep->ExceptionRecord->ExceptionCode == EXCEPTION_ACCESS_VIOLATION &&

        ep->ExceptionRecord->NumberParameters >= 2) {

        const ULONG_PTR kind =
            ep->ExceptionRecord->ExceptionInformation[0]; // 0 read, 1 write, 8 DEP execute

        fprintf(stderr, " %s 0x%llX",
                kind == 1   ? "write"
                : kind == 8 ? "execute"
                            : "read",

                static_cast<unsigned long long>(ep->ExceptionRecord->ExceptionInformation[1]));
    }

    // Uncaught MSVC C++ exception: walk the x64 ThrowInfo catchable types (image-relative)
    // and print what() when the thrown object derives from std::exception.
    if (ep->ExceptionRecord->ExceptionCode == 0xE06D7363 &&
        ep->ExceptionRecord->NumberParameters >= 4 &&
        ep->ExceptionRecord->ExceptionInformation[0] == 0x19930520) {
        const auto object = ep->ExceptionRecord->ExceptionInformation[1];
        const auto throwInfo = ep->ExceptionRecord->ExceptionInformation[2];
        const auto image = ep->ExceptionRecord->ExceptionInformation[3];
        const char* typeName = nullptr;
        bool isStdException = false;
        if (object && throwInfo && image) {
            const auto rva = [image](uint32_t offset) { return image + offset; };
            const auto array = rva(*reinterpret_cast<const uint32_t*>(throwInfo + 12));
            const int count = *reinterpret_cast<const int*>(array);
            for (int i = 0; i < count && i < 32; ++i) {
                const auto type = rva(reinterpret_cast<const uint32_t*>(array + 4)[i]);
                const char* name = reinterpret_cast<const char*>(
                    rva(*reinterpret_cast<const uint32_t*>(type + 4)) + 16);
                if (i == 0)
                    typeName = name;
                if (std::strcmp(name, ".?AVexception@std@@") == 0)
                    isStdException = true;
            }
        }
        fprintf(stderr, " c++ type=%s", typeName ? typeName : "?");
        if (isStdException)
            fprintf(stderr, " what=\"%s\"", reinterpret_cast<const std::exception*>(object)->what());
    }

    fprintf(stderr, "\n[CRASH] stack (module+rva):");

    for (int i = 0; i < 48 && c.Rip; ++i) {

        DWORD64 imageBase = 0;

        if (const auto* m = reoCrashDiag::findModule(c.Rip))

            fprintf(stderr, " %ls+0x%llX", m->name,
                    static_cast<unsigned long long>(c.Rip - m->base));

        else

            fprintf(stderr, " raw 0x%llX", static_cast<unsigned long long>(c.Rip));

        PRUNTIME_FUNCTION fn = RtlLookupFunctionEntry(c.Rip, &imageBase, nullptr);

        if (fn) {

            PVOID handlerData = nullptr;
            DWORD64 establisher = 0;

            RtlVirtualUnwind(UNW_FLAG_NHANDLER, imageBase, c.Rip, fn, &c, &handlerData,
                             &establisher, nullptr);

        } else {

            c.Rip = *reinterpret_cast<DWORD64*>(c.Rsp);

            c.Rsp += 8;
        }
    }

    fprintf(stderr, "\n");

    fflush(stderr);

    return EXCEPTION_CONTINUE_SEARCH;
}

// REO_HW_WATCH=<guest addr>: x64 debug-register write watchpoint on the host bytes that

// back a guest RAM word, armed on every thread of the process. Each write prints the

// new value and the writer's host stack (exe RVAs; resolve with a /MAP link). Diagnostic

// only: finds host code (HLE/runtime) that corrupts guest memory.

#include <tlhelp32.h>

#include <atomic>

#include <thread>

#include <mutex>

#include <condition_variable>

static uintptr_t g_watchHost = 0;

static uint32_t g_watchGuest = 0;

static std::atomic<int> g_watchHits{0};

static PVOID g_watchHandler = nullptr;

static std::mutex g_diagnosticMutex;

static std::condition_variable g_diagnosticCv;

static bool g_diagnosticStop = false;

static std::vector<std::thread> g_diagnosticWorkers;

static bool reoDiagnosticWait(unsigned milliseconds) {

    std::unique_lock<std::mutex> lock(g_diagnosticMutex);

    return g_diagnosticCv.wait_for(lock, std::chrono::milliseconds(milliseconds),
                                   [] { return g_diagnosticStop; });
}

// Construct after the runtime so every diagnostic releases its borrowed RAM/GS

// pointers before the runtime is destroyed, including on exception unwinding.

struct ReoDiagnosticLifetime {

    ~ReoDiagnosticLifetime() {

        {
            std::lock_guard<std::mutex> lock(g_diagnosticMutex);
            g_diagnosticStop = true;
        }

        g_diagnosticCv.notify_all();

        for (auto& worker : g_diagnosticWorkers)
            if (worker.joinable())
                worker.join();

        g_diagnosticWorkers.clear();

        if (g_watchHandler) {
            RemoveVectoredExceptionHandler(g_watchHandler);
            g_watchHandler = nullptr;
        }
    }
};

static void reoPrintStack(CONTEXT c) {

    const DWORD64 base = reinterpret_cast<DWORD64>(GetModuleHandleW(nullptr));

    for (int i = 0; i < 24 && c.Rip; ++i) {

        fprintf(stderr, " 0x%llX",
                static_cast<unsigned long long>(c.Rip >= base ? c.Rip - base : c.Rip));

        DWORD64 imageBase = 0;

        PRUNTIME_FUNCTION fn = RtlLookupFunctionEntry(c.Rip, &imageBase, nullptr);

        if (fn) {

            PVOID handlerData = nullptr;
            DWORD64 establisher = 0;

            RtlVirtualUnwind(UNW_FLAG_NHANDLER, imageBase, c.Rip, fn, &c, &handlerData,
                             &establisher, nullptr);

        } else {

            c.Rip = *reinterpret_cast<DWORD64*>(c.Rsp);

            c.Rsp += 8;
        }
    }
}

static LONG CALLBACK reoWatchHandler(EXCEPTION_POINTERS* ep) {

    if (ep->ExceptionRecord->ExceptionCode != EXCEPTION_SINGLE_STEP ||
        !(ep->ContextRecord->Dr6 & 1u))

        return EXCEPTION_CONTINUE_SEARCH;

    ep->ContextRecord->Dr6 = 0;

    if (g_watchHits.fetch_add(1) < 400) {

        // In read/write mode, touching the watched word here would re-trigger the watch.

        static const bool rw = std::getenv("REO_HW_WATCH_RW") != nullptr;

        uint32_t v = 0;

        if (!rw)
            std::memcpy(&v, reinterpret_cast<const void*>(g_watchHost), 4);

        fprintf(stderr, "[HW-WATCH] guest 0x%x = 0x%x tid=%lu stack:", g_watchGuest, v,
                GetCurrentThreadId());

        reoPrintStack(*ep->ContextRecord);

        fprintf(stderr, "\n");
    }

    return EXCEPTION_CONTINUE_EXECUTION;
}

static void reoArmWatchOnAllThreads(bool enabled = true) {

    const DWORD self = GetCurrentThreadId();

    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);

    if (snap == INVALID_HANDLE_VALUE)
        return;

    THREADENTRY32 te{};
    te.dwSize = sizeof(te);

    for (BOOL ok = Thread32First(snap, &te); ok; ok = Thread32Next(snap, &te)) {

        if (te.th32OwnerProcessID != GetCurrentProcessId() || te.th32ThreadID == self)
            continue;

        HANDLE th = OpenThread(THREAD_GET_CONTEXT | THREAD_SET_CONTEXT | THREAD_SUSPEND_RESUME,
                               FALSE, te.th32ThreadID);

        if (!th)
            continue;

        if (SuspendThread(th) != (DWORD)-1) {

            CONTEXT c{};
            c.ContextFlags = CONTEXT_DEBUG_REGISTERS;

            if (GetThreadContext(th, &c) &&
                ((enabled && c.Dr0 != g_watchHost) || (!enabled && c.Dr0 == g_watchHost))) {

                c.Dr0 = enabled ? g_watchHost : 0;

                // L0, 4 bytes; RW = write (01) or read/write (11) with REO_HW_WATCH_RW=1.

                static const bool rw = std::getenv("REO_HW_WATCH_RW") != nullptr;

                c.Dr7 = (c.Dr7 & ~0xF0003ull) |
                        (enabled ? (1ull | ((rw ? 3ull : 1ull) << 16) | (3ull << 18)) : 0);

                SetThreadContext(th, &c);
            }

            ResumeThread(th);
        }

        CloseHandle(th);
    }

    CloseHandle(snap);
}

// REO_STACKDUMP_AT=<seconds>: after that long, print every thread's host stack (exe

// RVAs) once -- for diagnosing hangs/deadlocks without a debugger.

static void reoStartStackDump() {

    const char* e = std::getenv("REO_STACKDUMP_AT");

    if (!e)
        return;

    const unsigned secs = static_cast<unsigned>(std::strtoul(e, nullptr, 0));

    // REO_STACKDUMP_N=<n>: take n samples 20 ms apart (a poor man's profiler).

    const char* ne = std::getenv("REO_STACKDUMP_N");

    const unsigned samples = ne ? static_cast<unsigned>(std::strtoul(ne, nullptr, 0)) : 1u;

    const char* ie = std::getenv("REO_STACKDUMP_INTERVAL_MS");

    const unsigned intervalMs =
        ie ? std::min(5000u, std::max(20u, static_cast<unsigned>(std::strtoul(ie, nullptr, 0))))
           : 20u;

    g_diagnosticWorkers.emplace_back([secs, samples, intervalMs] {
        if (reoDiagnosticWait(secs * 1000u))
            return;

        for (unsigned sample = 0; sample < samples; ++sample) {

            if (reoDiagnosticWait(sample ? intervalMs : 0))
                return;

            const DWORD self = GetCurrentThreadId();

            HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);

            if (snap == INVALID_HANDLE_VALUE)
                return;

            THREADENTRY32 te{};
            te.dwSize = sizeof(te);

            for (BOOL ok = Thread32First(snap, &te); ok; ok = Thread32Next(snap, &te)) {

                if (te.th32OwnerProcessID != GetCurrentProcessId() || te.th32ThreadID == self)
                    continue;

                HANDLE th =
                    OpenThread(THREAD_GET_CONTEXT | THREAD_SUSPEND_RESUME, FALSE, te.th32ThreadID);

                if (!th)
                    continue;

                if (SuspendThread(th) != (DWORD)-1) {

                    // Walk while suspended, print after resuming: printing while the target is

                    // suspended stalls whenever it holds the stderr lock.

                    DWORD64 frames[24];
                    int nframes = 0;

                    CONTEXT c{};
                    c.ContextFlags = CONTEXT_FULL;

                    if (GetThreadContext(th, &c)) {

                        const DWORD64 base = reinterpret_cast<DWORD64>(GetModuleHandleW(nullptr));

                        for (; nframes < 24 && c.Rip; ++nframes) {

                            frames[nframes] = c.Rip >= base ? c.Rip - base : c.Rip;

                            DWORD64 imageBase = 0;

                            PRUNTIME_FUNCTION fn =
                                RtlLookupFunctionEntry(c.Rip, &imageBase, nullptr);

                            if (!fn) {
                                ++nframes;
                                break;
                            }

                            PVOID handlerData = nullptr;
                            DWORD64 establisher = 0;

                            RtlVirtualUnwind(UNW_FLAG_NHANDLER, imageBase, c.Rip, fn, &c,
                                             &handlerData, &establisher, nullptr);
                        }
                    }

                    ResumeThread(th);

                    if (nframes) {

                        char line[1024];

                        int len = snprintf(line, sizeof(line),
                                           "[STACKDUMP] tid=%lu stack:", te.th32ThreadID);

                        for (int i = 0; i < nframes && len < 1000; ++i)

                            len += snprintf(line + len, sizeof(line) - len, " 0x%llX",
                                            static_cast<unsigned long long>(frames[i]));

                        fprintf(stderr, "%s\n", line);
                    }
                }

                CloseHandle(th);
            }

            CloseHandle(snap);

            fflush(stderr);
        }
    });
}

// REO_SHOT_AT=<s>[,<s>...]: write shot_<s>.bmp (the frame the runtime presents) at those

// times -- visual checks without access to the window.

static void reoWriteBmp(const char* path, const std::vector<uint8_t>& rgba, uint32_t w,
                        uint32_t h) {

    FILE* f = fopen(path, "wb");

    if (!f)
        return;

    const uint32_t rowBytes = w * 4u, dataBytes = rowBytes * h, fileBytes = 54u + dataBytes;

    uint8_t hdr[54] = {'B', 'M'};

    auto put32 = [&](int o, uint32_t v) { memcpy(hdr + o, &v, 4); };

    put32(2, fileBytes);
    put32(10, 54);
    put32(14, 40);
    put32(18, w);
    put32(22, h);

    hdr[26] = 1;
    hdr[28] = 32;
    put32(34, dataBytes);

    fwrite(hdr, 1, 54, f);

    std::vector<uint8_t> row(rowBytes);

    for (uint32_t y = 0; y < h; ++y) {

        const uint8_t* src = rgba.data() + static_cast<size_t>(h - 1 - y) * rowBytes;

        for (uint32_t x = 0; x < w; ++x) {

            row[x * 4 + 0] = src[x * 4 + 2];
            row[x * 4 + 1] = src[x * 4 + 1];

            row[x * 4 + 2] = src[x * 4 + 0];
            row[x * 4 + 3] = 255;
        }

        fwrite(row.data(), 1, rowBytes, f);
    }

    fclose(f);
}

static void reoStartShots(PS2Runtime* runtime) {

    const char* e = std::getenv("REO_SHOT_AT");

    if (!e || !runtime)
        return;

    std::vector<unsigned> times;

    for (const char* q = e; *q;) {

        char* end = nullptr;

        times.push_back(static_cast<unsigned>(std::strtoul(q, &end, 0)));

        if (!end || end == q)
            break;

        q = (*end == ',') ? end + 1 : end;
    }

    g_diagnosticWorkers.emplace_back([runtime, times] {
        unsigned elapsed = 0;

        for (unsigned t : times) {

            if (reoDiagnosticWait(t > elapsed ? (t - elapsed) * 1000u : 0))
                return;

            if (t > elapsed)
                elapsed = t;

            std::vector<uint8_t> px;
            uint32_t w = 0, h = 0;

            const auto shotNs = std::chrono::duration_cast<std::chrono::nanoseconds>(
                                    std::chrono::steady_clock::now().time_since_epoch())
                                    .count();

            if (runtime->gs().copyLatchedHostPresentationFrame(px, w, h) && w && h &&
                px.size() >= size_t(w) * h * 4) {

                char name[64];
                snprintf(name, sizeof(name), "shot_%u.bmp", t);

                reoWriteBmp(name, px, w, h);

                // Alongside: raw GS VRAM + display registers, for offline analysis.

                const auto g = gsPrivSnapshot(runtime->memory().gs());

                std::vector<uint8_t> gpuVram;

                const uint8_t* vram = runtime->memory().getGSVRAM();

                if (gs_backend_bridge::active()) {

                    gpuVram.resize(PS2_GS_VRAM_SIZE);

                    gs_backend_bridge::exportCpuVram(gpuVram.data(), gpuVram.size());

                    vram = gpuVram.data();
                }

                if (vram) {

                    char vn[64];
                    snprintf(vn, sizeof(vn), "vram_%u.bin", t);

                    if (FILE* vf = fopen(vn, "wb")) {
                        fwrite(vram, 1, PS2_GS_VRAM_SIZE, vf);
                        fclose(vf);
                    }
                }

                // REO_SHOT_RAM=1: also dump EE RAM (32 MB per shot).

                static const bool dumpRam = std::getenv("REO_SHOT_RAM") != nullptr;

                if (const uint8_t* ram = dumpRam ? runtime->memory().getRDRAM() : nullptr) {

                    char rn[64];
                    snprintf(rn, sizeof(rn), "eeram_%u.bin", t);

                    if (FILE* rf = fopen(rn, "wb")) {
                        fwrite(ram, 1, PS2_RAM_SIZE, rf);
                        fclose(rf);
                    }
                }

                fprintf(
                    stderr,
                    "[SHOT] gs pmode=%llx smode2=%llx dispfb1=%llx display1=%llx dispfb2=%llx "
                    "display2=%llx bgcolor=%llx\n",

                    (unsigned long long)g[0], (unsigned long long)g[2], (unsigned long long)g[7],

                    (unsigned long long)g[8], (unsigned long long)g[9], (unsigned long long)g[10],

                    (unsigned long long)g[14]);

                fprintf(stderr, "[SHOT] %s %ux%u ns=%llu\n", name, w, h,
                        static_cast<unsigned long long>(shotNs));

            } else {

                fprintf(stderr,
                        "[SHOT] t=%u: no presented frame"
                        "\n",
                        t);
            }
        }
    });
}

static void reoStartHwWatch(uint8_t* rdram) {

    const char* e = std::getenv("REO_HW_WATCH");

    if (!e || !rdram)
        return;

    g_watchGuest = static_cast<uint32_t>(std::strtoul(e, nullptr, 0)) & 0x01FFFFFCu;

    g_watchHost = reinterpret_cast<uintptr_t>(rdram + g_watchGuest);

    g_watchHandler = AddVectoredExceptionHandler(1, reoWatchHandler);

    if (!g_watchHandler)
        return;

    fprintf(stderr, "[HW-WATCH] armed on guest 0x%x\n", g_watchGuest);

    // REO_HW_WATCH_AFTER=<seconds>: arm late, so boot-time accesses don't use up the hit budget.

    const char* after = std::getenv("REO_HW_WATCH_AFTER");

    const DWORD delayMs = after ? static_cast<DWORD>(std::strtoul(after, nullptr, 0) * 1000u) : 0;

    g_diagnosticWorkers.emplace_back([delayMs] {
        if (!reoDiagnosticWait(delayMs)) {

            do {
                reoArmWatchOnAllThreads();
            } while (!reoDiagnosticWait(50));
        }

        // Run from the helper so the main thread's watchpoint is cleared too.

        reoArmWatchOnAllThreads(false);
    });
}

#endif

int main(int argc, char* argv[]) {

#ifdef _WIN32

    reoCrashDiag::snapshotModules();

    SetUnhandledExceptionFilter(reoCrashFilter);

#endif

    setvbuf(stdout, nullptr, _IONBF, 0); // unbuffered: pinpoint crash location

    // Defaults — selected game determines paths

    int game_idx = -1; // -1 = auto-detect from build target

    std::string elf_path;

    std::string game_data;

    for (int i = 1; i < argc; i++) {

        if (strcmp(argv[i], "--game") == 0 && i + 1 < argc) {

            const char* g = argv[++i];

            if (strcmp(g, "file1") == 0 || strcmp(g, "outbreak") == 0 || strcmp(g, "1") == 0)

                game_idx = 0;

            else if (strcmp(g, "file2") == 0 || strcmp(g, "2") == 0)

                game_idx = 1;

            else {

                fprintf(stderr, "[REO] Unknown game: %s (use 'file1' or 'file2')\n", g);

                return 1;
            }

        } else if (strcmp(argv[i], "--elf") == 0 && i + 1 < argc) {

            elf_path = argv[++i];

        } else if (strcmp(argv[i], "--data") == 0 && i + 1 < argc) {

            game_data = argv[++i];

        } else if (strcmp(argv[i], "--help") == 0) {

            printf("Usage: reo_recomp [--game file1|file2] [--elf <path>] [--data <path>]\n");

            printf("  --game   Which game to run: file1 or file2 (auto-detected if not set)\n");

            printf("  --elf    Path to game ELF (default: auto from game selection)\n");

            printf("  --data   Path to extracted game data (default: auto from game selection)\n");

            return 0;
        }
    }

    // Auto-detect game from build target (compile-time define)

#if defined(REO_GAME_FILE2)

    if (game_idx < 0)
        game_idx = 1;

#else

    if (game_idx < 0)
        game_idx = 0;

#endif

    const GameDef& g = s_games[game_idx];

    print_banner(g);

    // Resolve paths

    if (game_data.empty())
        game_data = g.default_data;

    if (elf_path.empty())
        elf_path = std::string(game_data) + "/" + g.elf_name;

    if (!fs::exists(elf_path)) {

        fprintf(stderr, "[REO] ELF not found: %s\n", elf_path.c_str());

        fprintf(stderr, "[REO] Run: reo-extract <ISO> %s\n", g.default_data);

        return 1;
    }

    printf("[BOOT] ELF: %s\n", elf_path.c_str());

    printf("[BOOT] Game data: %s\n", game_data.c_str());

    // Initialize the PS2Recomp runtime

    printf("[BOOT] Initializing PS2 runtime...\n");

    PS2Runtime runtime;

    const char* vuSpecialized = std::getenv("REO_VU_SPECIALIZED");

    if (!vuSpecialized || std::strcmp(vuSpecialized, "0") != 0) {

        reoRegisterVuSpecializedPrograms();

    } else {

        vu_specialized::registerProgramTable(nullptr);

        vu_native_geometry::registerProgramTable(nullptr);
    }

    printf("[VU-AOT] registered programs=%u native programs=%u\n",

           vu_specialized::registeredProgramCount(), vu_native_geometry::registeredProgramCount());

    vif_launch_overhead::setIdentityProvider(vu_program_collection::currentIdentity);

#ifdef REO_HAVE_PARALLEL_GS

    reo_parallel_backend::Config gpuConfig;

    gpuConfig.residentPresentation = reo_gpu_present::requested();
    if (gpuConfig.residentPresentation) {
        const fs::path shaders = fs::u8path(GetApplicationDirectory()) / "reo-gpu-present";
        auto readShader = [](const fs::path& path) {
            std::ifstream f(path, std::ios::binary | std::ios::ate);
            if (!f)
                throw std::runtime_error("Missing precompiled GPU presentation shader");
            const auto size = f.tellg();
            if (size < 20 || size > 1024 * 1024 || size % 4)
                throw std::runtime_error("Invalid GPU presentation shader size");
            std::vector<uint32_t> words(size_t(size) / 4);
            f.seekg(0);
            f.read(reinterpret_cast<char*>(words.data()), size);
            if (!f || words[0] != 0x07230203)
                throw std::runtime_error("Invalid GPU presentation SPIR-V");
            return words;
        };
        gpuConfig.presentationVertex = readShader(shaders / "present_opaque.vert.spv");
        gpuConfig.presentationFragment = readShader(shaders / "present_native.frag.spv");
        gpuConfig.presentationTarget = reo_gpu_present::target;
        gpuConfig.presentationEpochCurrent = reo_gpu_present::currentEpoch;
        fprintf(stderr, "[GPU-PRESENT] resident path selected; developer pane disabled; filtering "
                        "and opacity on GPU\n");
    }
    gpuConfig.validatedDrawing = true;

    gpuConfig.descriptorBuffer = false;

    // Match the stock PCSX2 automatic FFMD0/anti-blur presentation policy.

    // These host scanout options preserve the game's original CRT registers.

    gpuConfig.forceProgressive = true;

    gpuConfig.antiBlur = true;

    gpuConfig.persistentPipelineCache = true;
    if (const char* cache = std::getenv("REO_PIPELINE_CACHE_FILE"); cache && *cache)
        gpuConfig.pipelineCacheFile = cache;

    gpuConfig.publishPrivilegedReset = gs_backend_bridge::publishPrivilegedReset;

    gpuConfig.publishStatusAck = [](uint64_t) {};

    gpuConfig.peekEventFrontState = gs_backend_bridge::peekEventFrontState;

#if defined(REO_GAME_FILE1)
    // Resolve the fourteen finite compiled body identities before backend creation.
    // Normal generated registration after ELF load installs these SAME guarded
    // symbols again. No Runtime RAM/opcode image is read or seeded here.
    if (const char* first = std::getenv("REO_GPU_FIRST_ENTRY_AUDIT"); first && first[0]) {
#if !REO_GENERATED_SOURCE_AUDIT
        std::fprintf(stderr, "GPU source audits require game code generated with --source-audit.\n");
        return 1;
#endif
        runtime.registerFunction(0x196010u, &sub_00196010_0x196010);
        runtime.registerFunction(0x197900u, &sub_00197900_0x197900);
        runtime.registerFunction(0x191280u, &sub_00191280_0x191280);
        runtime.registerFunction(0x18f710u, &sub_0018F710_0x18f710);
        runtime.registerFunction(0x1921b0u, &sub_001921B0_0x1921b0);
        runtime.registerFunction(0x18f570u, &sub_0018F570_0x18f570);
        runtime.registerFunction(0x18fdf0u, &sub_0018FDF0_0x18fdf0);
        runtime.registerFunction(0x18f970u, &sub_0018F970_0x18f970);
        runtime.registerFunction(0x18fce0u, &sub_0018FCE0_0x18fce0);
        runtime.registerFunction(0x18f880u, &sub_0018F880_0x18f880);
        runtime.registerFunction(0x18f7e0u, &sub_0018F7E0_0x18f7e0);
        runtime.registerFunction(0x197490u, &sub_00197490_0x197490);
        runtime.registerFunction(0x18f6a0u, &sub_0018F6A0_0x18f6a0);
#if defined(REO_HAVE_GPU_PARENT_NATURAL_HOOKS)
        runtime.registerFunction(0x19bbd0u, &ReoNaturalParentBody);
#endif
    }
#endif
#if defined(REO_GAME_FILE1)
    reo_gpu_enrollment::configureBeforeBoot(gpuConfig, fs::u8path(GetApplicationDirectory()),
                                            g.serial, &runtime);
#else
    // The resident geometry registry is pinned to File #1 code images; a File #1
    // setting left in the user environment must not prevent File #2 from starting.
    // Clear it for this process so the runtime's own check does not refuse either.
    if (const char* resident = std::getenv("REO_VIF1_GPU_RESIDENT"); resident && resident[0] == '1') {
        fprintf(stderr, "[GPU-GEOMETRY] REO_VIF1_GPU_RESIDENT cleared: resident geometry is "
                        "File #1 only; geometry stays on the CPU VU path\n");
#ifdef _WIN32
        _putenv_s("REO_VIF1_GPU_RESIDENT", "");
#else
        unsetenv("REO_VIF1_GPU_RESIDENT");
#endif
    }
#endif

    gs_backend_bridge::registerFactory(reo_parallel_backend::makeFactory(std::move(gpuConfig)));

#endif

    size_t ramBackingBytes = PS2_RAM_SIZE;
#if defined(REO_GAME_FILE1)
    if (std::getenv("REO_MOD_ENEMY_SPAWN_SEED")) ramBackingBytes = 2u * PS2_RAM_SIZE;
#endif
    if (!runtime.initialize(g.name, ramBackingBytes)) {

        fprintf(stderr, "[BOOT] Failed to initialize runtime\n");

        return 1;
    }

    // Configure I/O paths

    PS2Runtime::IoPaths paths;

    paths.elfPath = elf_path;

    paths.elfDirectory = fs::path(elf_path).parent_path();

    paths.hostRoot = game_data;

    paths.cdRoot = game_data;

    paths.mcRoot = "saves";
#ifdef _WIN32
    if (const wchar_t* card = _wgetenv(L"REO_MC0_ROOT"); card && *card)
        paths.mcRoot = fs::path(card);
#else
    if (const char* card = std::getenv("REO_MC0_ROOT"); card && *card)
        paths.mcRoot = card;
#endif

    PS2Runtime::setIoPaths(paths);

    fs::create_directories(paths.mcRoot);

    // Load the ELF into guest memory

    printf("[BOOT] Loading ELF into guest memory...\n");

    if (!runtime.loadELF(elf_path)) {

        fprintf(stderr, "[BOOT] Failed to load ELF: %s\n", elf_path.c_str());

        return 1;
    }

    // loadELF() -> configureIoPathsFromElf() resets host/cd/mc roots to the ELF's

    // directory; restore --data and ./saves. (The HW bridge's CDVD already captured

    // its root during loadELF, so it still uses the ELF directory.)

    PS2Runtime::setIoPaths(paths);

    printf("[BOOT] I/O roots: cd=%s host=%s mc=%s\n",

           PS2Runtime::getIoPaths().cdRoot.string().c_str(),

           PS2Runtime::getIoPaths().hostRoot.string().c_str(),

           reinterpret_cast<const char*>(PS2Runtime::getIoPaths().mcRoot.u8string().c_str()));

    // Register all recompiled functions

    printf("[BOOT] Registering recompiled functions...\n");

    registerAllFunctions(runtime);

    printf("[BOOT] Registering overlay functions (runtime-loaded code)...\n");

    registerOverlayFunctions(runtime);

#ifdef REO_HAVE_OVL

    reoRegisterOverlays(runtime);

#endif

#ifdef REO_HAVE_EXTRA

    reoRegisterExtraFunctions(runtime);

#endif

    printf("[BOOT] All functions registered.\n");

    // Only normal bootstrap-owned32MiB File1 RAM can enable the private observer.

    reo_game_clock::configure(g.serial, runtime.memory().getRDRAM(), PS2_RAM_SIZE);
    reo_performance::configure(g.serial, runtime.memory().getRDRAM(), PS2_RAM_SIZE);

    reo_actor_origin::configure(g.serial, runtime.memory().getRDRAM(), PS2_RAM_SIZE);
    reo_ground_origin::configure(g.serial, runtime.memory().getRDRAM(), PS2_RAM_SIZE);

    // Re-apply game overrides AFTER function registration.

    // loadELF() applies them first, but registerAllFunctions() overwrites

    // our custom handlers with the generated stubs. This second pass ensures

    // our overrides take precedence over generated code.

    printf("[BOOT] Applying game overrides (post-registration)...\n");

    ps2_game_overrides::applyMatching(runtime, elf_path, g.entry_point);
#if defined(REO_GAME_FILE1)
    if (std::strcmp(g.serial, "SLUS-20765") == 0)
        reo::mc2::install(runtime);
#endif
    if (std::strcmp(g.serial, "SLUS-20765") == 0)
        reo_movie_entry::install(runtime);
#if defined(REO_GAME_FILE1)
    if (std::strcmp(g.serial, "SLUS-20765") == 0)
        reo_missing_entries::install(runtime); // unregistered entries (stutter + skipped logic)
#endif
#if defined(REO_GAME_FILE1)
    if (std::strcmp(g.serial, "SLUS-20765") == 0)
        reo_movie_join::install(runtime);
#endif
#if defined(_WIN32) && defined(REO_HAVE_PARALLEL_GS) && defined(REO_GAME_FILE1)
    if (std::strcmp(g.serial, "SLUS-20765") == 0) {
        const char* gpuMovie = std::getenv("REO_GPU_MOVIE");
        if (gpuMovie && std::atoi(gpuMovie) != 0 && !reo_gpu_movie::installNativeMovieGame(runtime))
            throw std::runtime_error(
                "Native GPU movie installation refused its original GAME identities");
        // REO_TRACE_171920=1 (CPU movie path only; the GPU route requires the original pointer at 0x171920):
        // log every entry into the movie demuxer's end-of-program callback, for comparing the paths.
        const char* trace = std::getenv("REO_TRACE_171920");
        if (trace && trace[0] == '1' && !(gpuMovie && std::atoi(gpuMovie) != 0) &&
            runtime.lookupFunction(0x171920u) == &sub_00171920_0x171920)
            runtime.registerFunction(
                0x171920u, +[](uint8_t* rdram, R5900Context* ctx, PS2Runtime* rt) {
                    static uint32_t calls = 0;
                    auto rd = [rdram](uint32_t a) {
                        uint32_t v = 0;
                        std::memcpy(&v, rdram + (a & 0x1ffffffcu), 4);
                        return v;
                    };
                    uint32_t a2 = 0;
                    std::memcpy(&a2, &ctx->r[6], 4);
                    const uint32_t sofdec = a2 & 0x1fffffffu,
                                   work = rd(sofdec + 0x1b30) & 0x1fffffffu;
                    if (++calls <= 64)
                        std::fprintf(stderr,
                                     "[TRACE-171920] call=%u sofdec=%08x work=%08x ring10=%08x "
                                     "ring48=%08x flag9ec=%08x\n",
                                     calls, sofdec, work, rd(work + 0xa48 + 0x10),
                                     rd(work + 0xa48 + 0x48), rd(work + 0x9ec));
                    sub_00171920_0x171920(rdram, ctx, rt);
                });
    }
#endif
#if defined(REO_HAVE_GPU_PARENT_NATURAL_HOOKS) && defined(REO_GAME_FILE1)
    // Install both exact registry bodies before any producer can select them.
    // The allocation-only diagnostic observer cannot authorize opaque bytes.
    if (std::strcmp(g.serial, "SLUS-20765") == 0 && !ReoInstallConnectedParentBodies(runtime))
        throw std::runtime_error("Guarded parent registry differs from pinned original bodies");
#else
    if (std::strcmp(g.serial, "SLUS-20765") == 0)
        ReoInstallPaletteOriginObserver(runtime);
#if defined(REO_GAME_FILE1)
    if (std::strcmp(g.serial, "SLUS-20765") == 0)
        ReoInstallPaletteParentFrontierObserver(runtime);
#endif
#endif

    // Seal the exact File1 integer IRQ implementation after genuine original
    // registration and native SDK overrides. Runtime alone requires no GAME symbol.
    // Natural mode retains original helpers. Registration recognizes those
    // identities separately from reviewed SDK overrides; unsupported execution
    // paths remain refused by the owned integer dispatcher.
#if defined(REO_GAME_FILE1)
    if (std::strcmp(g.serial, "SLUS-20765") == 0) {
        try {
            reo_irq_integer::installActualOriginalCpuIrqGameReceiver(runtime);
            printf("[REO] original CPU IRQ receiver registered\n");
        } catch (const std::exception& e) {
            printf("[REO] original CPU IRQ receiver not registered: %s\n", e.what());
        }
    }
#endif

    // Begin execution

    printf("[BOOT] Starting execution at entry point 0x%08X...\n", g.entry_point);

    printf("[BOOT] ========================================\n\n");

#ifdef _WIN32

    ReoDiagnosticLifetime diagnosticLifetime;

    reoStartHwWatch(runtime.memory().getRDRAM());

    reoStartStackDump();

    reoStartShots(&runtime);

#endif

    ps2SetDebugPanelProvider(reoDebugPanelText);

#if defined(REO_GAME_FILE1)
    if (std::strcmp(g.serial, "SLUS-20765") == 0) {
        reo::cheats::install(runtime);
        reo::mods::install(runtime);
        reo::rumble::install(runtime);
        reo::audio::install(runtime);
    }
#endif
#ifdef _WIN32
    reo::ScopedTimerResolution timerPrecision;
#endif
    runtime.run();

    if (const char* stats = std::getenv("REO_GS_TRI_BATCH_STATS"); stats && std::atoi(stats) != 0) {

        extern uint64_t ps2GsTriangleBatchStat(unsigned);

        fprintf(
            stderr,
            "[GS-TRI-BATCH] parallel_batches=%llu parallel_triangles=%llu serial_triangles=%llu\n",

            static_cast<unsigned long long>(ps2GsTriangleBatchStat(0)),

            static_cast<unsigned long long>(ps2GsTriangleBatchStat(1)),

            static_cast<unsigned long long>(ps2GsTriangleBatchStat(2)));
    }

    // run() has joined all guest/IRQ/GS workers; format/export only now.

    reo_game_clock::export_after_join();

    reo_actor_origin::export_after_join();
    reo_ground_origin::export_after_join();

    reoPad2Stop(); // feeder writes guest RAM; stop it before the runtime is destroyed

    printf("\n[BOOT] ========================================\n");

    printf("[BOOT] Execution ended.\n");

    return 0;
}
