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
#include "ps2_recompiled_functions.h"
#include "game_overrides.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

// Function registration — defined in each game's generated register_functions.cpp
// The active build target (file1 or file2) provides the implementation.
extern void registerAllFunctions(PS2Runtime& runtime);

// Overlay function registration — runtime-loaded code dumped from PCSX2
extern void registerOverlayFunctions(PS2Runtime& runtime);

struct GameDef {
    const char* name;
    const char* elf_name;
    const char* serial;
    const char* default_data;
    uint32_t entry_point;
};

static const GameDef s_games[] = {
    { "Resident Evil Outbreak",          "SLUS_207.65", "SLUS-20765", "game_data",       0x00100008 },
    { "Resident Evil Outbreak: File #2", "SLUS_209.84", "SLUS-20984", "game_data_file2", 0x00100008 },
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
#include <windows.h>
// Crash diagnostics: on an unhandled exception print the code, fault address and the
// unwound host call stack as RVAs of reo_recomp.exe (resolve with a /MAP link, see
// docs/DIVERGENCES.md D15). Read-only; does not change execution.
static LONG WINAPI reoCrashFilter(EXCEPTION_POINTERS* ep) {
    const DWORD64 base = reinterpret_cast<DWORD64>(GetModuleHandleW(nullptr));
    CONTEXT c = *ep->ContextRecord;
    fprintf(stderr, "\n[CRASH] code=0x%08lX addr=%p rva=0x%llX tid=%lu",
            ep->ExceptionRecord->ExceptionCode, ep->ExceptionRecord->ExceptionAddress,
            static_cast<unsigned long long>(c.Rip - base), GetCurrentThreadId());
    if (ep->ExceptionRecord->ExceptionCode == EXCEPTION_ACCESS_VIOLATION &&
        ep->ExceptionRecord->NumberParameters >= 2)
        fprintf(stderr, " %s 0x%llX", ep->ExceptionRecord->ExceptionInformation[0] ? "write" : "read",
                static_cast<unsigned long long>(ep->ExceptionRecord->ExceptionInformation[1]));
    fprintf(stderr, "\n[CRASH] stack (exe RVAs):");
    for (int i = 0; i < 48 && c.Rip; ++i) {
        DWORD64 imageBase = 0;
        fprintf(stderr, " 0x%llX", static_cast<unsigned long long>(c.Rip >= base ? c.Rip - base : c.Rip));
        PRUNTIME_FUNCTION fn = RtlLookupFunctionEntry(c.Rip, &imageBase, nullptr);
        if (fn) {
            PVOID handlerData = nullptr; DWORD64 establisher = 0;
            RtlVirtualUnwind(UNW_FLAG_NHANDLER, imageBase, c.Rip, fn, &c, &handlerData, &establisher, nullptr);
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
static uintptr_t g_watchHost = 0;
static uint32_t g_watchGuest = 0;
static std::atomic<int> g_watchHits{0};

static void reoPrintStack(CONTEXT c) {
    const DWORD64 base = reinterpret_cast<DWORD64>(GetModuleHandleW(nullptr));
    for (int i = 0; i < 24 && c.Rip; ++i) {
        fprintf(stderr, " 0x%llX", static_cast<unsigned long long>(c.Rip >= base ? c.Rip - base : c.Rip));
        DWORD64 imageBase = 0;
        PRUNTIME_FUNCTION fn = RtlLookupFunctionEntry(c.Rip, &imageBase, nullptr);
        if (fn) {
            PVOID handlerData = nullptr; DWORD64 establisher = 0;
            RtlVirtualUnwind(UNW_FLAG_NHANDLER, imageBase, c.Rip, fn, &c, &handlerData, &establisher, nullptr);
        } else {
            c.Rip = *reinterpret_cast<DWORD64*>(c.Rsp);
            c.Rsp += 8;
        }
    }
}

static LONG CALLBACK reoWatchHandler(EXCEPTION_POINTERS* ep) {
    if (ep->ExceptionRecord->ExceptionCode != EXCEPTION_SINGLE_STEP || !(ep->ContextRecord->Dr6 & 1u))
        return EXCEPTION_CONTINUE_SEARCH;
    ep->ContextRecord->Dr6 = 0;
    if (g_watchHits.fetch_add(1) < 400) {
        uint32_t v = 0;
        std::memcpy(&v, reinterpret_cast<const void*>(g_watchHost), 4);
        fprintf(stderr, "[HW-WATCH] guest 0x%x = 0x%x tid=%lu stack:", g_watchGuest, v, GetCurrentThreadId());
        reoPrintStack(*ep->ContextRecord);
        fprintf(stderr, "\n");
    }
    return EXCEPTION_CONTINUE_EXECUTION;
}

static void reoArmWatchOnAllThreads() {
    const DWORD self = GetCurrentThreadId();
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
    if (snap == INVALID_HANDLE_VALUE) return;
    THREADENTRY32 te{}; te.dwSize = sizeof(te);
    for (BOOL ok = Thread32First(snap, &te); ok; ok = Thread32Next(snap, &te)) {
        if (te.th32OwnerProcessID != GetCurrentProcessId() || te.th32ThreadID == self) continue;
        HANDLE th = OpenThread(THREAD_GET_CONTEXT | THREAD_SET_CONTEXT | THREAD_SUSPEND_RESUME, FALSE, te.th32ThreadID);
        if (!th) continue;
        if (SuspendThread(th) != (DWORD)-1) {
            CONTEXT c{}; c.ContextFlags = CONTEXT_DEBUG_REGISTERS;
            if (GetThreadContext(th, &c) && c.Dr0 != g_watchHost) {
                c.Dr0 = g_watchHost;
                c.Dr7 = (c.Dr7 & ~0xF0003ull) | 1ull | (1ull << 16) | (3ull << 18); // L0, write, 4 bytes
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
    if (!e) return;
    const unsigned secs = static_cast<unsigned>(std::strtoul(e, nullptr, 0));
    std::thread([secs] {
        Sleep(secs * 1000u);
        const DWORD self = GetCurrentThreadId();
        HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
        if (snap == INVALID_HANDLE_VALUE) return;
        THREADENTRY32 te{}; te.dwSize = sizeof(te);
        for (BOOL ok = Thread32First(snap, &te); ok; ok = Thread32Next(snap, &te)) {
            if (te.th32OwnerProcessID != GetCurrentProcessId() || te.th32ThreadID == self) continue;
            HANDLE th = OpenThread(THREAD_GET_CONTEXT | THREAD_SUSPEND_RESUME, FALSE, te.th32ThreadID);
            if (!th) continue;
            if (SuspendThread(th) != (DWORD)-1) {
                CONTEXT c{}; c.ContextFlags = CONTEXT_FULL;
                if (GetThreadContext(th, &c)) {
                    fprintf(stderr, "[STACKDUMP] tid=%lu stack:", te.th32ThreadID);
                    reoPrintStack(c);
                    fprintf(stderr, "\n");
                }
                ResumeThread(th);
            }
            CloseHandle(th);
        }
        CloseHandle(snap);
        fflush(stderr);
    }).detach();
}

// REO_SHOT_AT=<s>[,<s>...]: write shot_<s>.bmp (the frame the runtime presents) at those
// times -- visual checks without access to the window.
static void reoWriteBmp(const char* path, const std::vector<uint8_t>& rgba, uint32_t w, uint32_t h) {
    FILE* f = fopen(path, "wb");
    if (!f) return;
    const uint32_t rowBytes = w * 4u, dataBytes = rowBytes * h, fileBytes = 54u + dataBytes;
    uint8_t hdr[54] = {'B', 'M'};
    auto put32 = [&](int o, uint32_t v) { memcpy(hdr + o, &v, 4); };
    put32(2, fileBytes); put32(10, 54); put32(14, 40); put32(18, w); put32(22, h);
    hdr[26] = 1; hdr[28] = 32; put32(34, dataBytes);
    fwrite(hdr, 1, 54, f);
    std::vector<uint8_t> row(rowBytes);
    for (uint32_t y = 0; y < h; ++y) {
        const uint8_t* src = rgba.data() + static_cast<size_t>(h - 1 - y) * rowBytes;
        for (uint32_t x = 0; x < w; ++x) {
            row[x * 4 + 0] = src[x * 4 + 2]; row[x * 4 + 1] = src[x * 4 + 1];
            row[x * 4 + 2] = src[x * 4 + 0]; row[x * 4 + 3] = 255;
        }
        fwrite(row.data(), 1, rowBytes, f);
    }
    fclose(f);
}

static void reoStartShots(PS2Runtime* runtime) {
    const char* e = std::getenv("REO_SHOT_AT");
    if (!e || !runtime) return;
    std::vector<unsigned> times;
    for (const char* q = e; *q;) {
        char* end = nullptr;
        times.push_back(static_cast<unsigned>(std::strtoul(q, &end, 0)));
        if (!end || end == q) break;
        q = (*end == ',') ? end + 1 : end;
    }
    std::thread([runtime, times] {
        unsigned elapsed = 0;
        for (unsigned t : times) {
            if (t > elapsed) { Sleep((t - elapsed) * 1000u); elapsed = t; }
            std::vector<uint8_t> px; uint32_t w = 0, h = 0;
            if (runtime->gs().copyLatchedHostPresentationFrame(px, w, h) && w && h && px.size() >= size_t(w) * h * 4) {
                char name[64]; snprintf(name, sizeof(name), "shot_%u.bmp", t);
                reoWriteBmp(name, px, w, h);
                // Alongside: raw GS VRAM + display registers, for offline analysis.
                const auto& g = runtime->memory().gs();
                if (const uint8_t* vram = runtime->memory().getGSVRAM()) {
                    char vn[64]; snprintf(vn, sizeof(vn), "vram_%u.bin", t);
                    if (FILE* vf = fopen(vn, "wb")) { fwrite(vram, 1, PS2_GS_VRAM_SIZE, vf); fclose(vf); }
                }
                fprintf(stderr, "[SHOT] gs pmode=%llx smode2=%llx dispfb1=%llx display1=%llx dispfb2=%llx display2=%llx bgcolor=%llx\n",
                        (unsigned long long)g.pmode, (unsigned long long)g.smode2, (unsigned long long)g.dispfb1,
                        (unsigned long long)g.display1, (unsigned long long)g.dispfb2, (unsigned long long)g.display2,
                        (unsigned long long)g.bgcolor);
                fprintf(stderr, "[SHOT] %s %ux%u" "\n", name, w, h);
            } else {
                fprintf(stderr, "[SHOT] t=%u: no presented frame" "\n", t);
            }
        }
    }).detach();
}

static void reoStartHwWatch(uint8_t* rdram) {
    const char* e = std::getenv("REO_HW_WATCH");
    if (!e || !rdram) return;
    g_watchGuest = static_cast<uint32_t>(std::strtoul(e, nullptr, 0)) & 0x01FFFFFCu;
    g_watchHost = reinterpret_cast<uintptr_t>(rdram + g_watchGuest);
    AddVectoredExceptionHandler(1, reoWatchHandler);
    fprintf(stderr, "[HW-WATCH] armed on guest 0x%x\n", g_watchGuest);
    std::thread([] { for (;;) { reoArmWatchOnAllThreads(); Sleep(50); } }).detach();
}
#endif

int main(int argc, char* argv[]) {
#ifdef _WIN32
    SetUnhandledExceptionFilter(reoCrashFilter);
#endif
    setvbuf(stdout, nullptr, _IONBF, 0);  // unbuffered: pinpoint crash location
    // Defaults — selected game determines paths
    int game_idx = -1;  // -1 = auto-detect from build target
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
    if (game_idx < 0) game_idx = 1;
#else
    if (game_idx < 0) game_idx = 0;
#endif

    const GameDef& g = s_games[game_idx];
    print_banner(g);

    // Resolve paths
    if (game_data.empty()) game_data = g.default_data;
    if (elf_path.empty())  elf_path = std::string(game_data) + "/" + g.elf_name;

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

    if (!runtime.initialize(g.name)) {
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
    PS2Runtime::setIoPaths(paths);

    fs::create_directories("saves");

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
           PS2Runtime::getIoPaths().mcRoot.string().c_str());

    // Register all recompiled functions
    printf("[BOOT] Registering recompiled functions...\n");
    registerAllFunctions(runtime);
    printf("[BOOT] Registering overlay functions (runtime-loaded code)...\n");
    registerOverlayFunctions(runtime);
    printf("[BOOT] All functions registered.\n");

    // Re-apply game overrides AFTER function registration.
    // loadELF() applies them first, but registerAllFunctions() overwrites
    // our custom handlers with the generated stubs. This second pass ensures
    // our overrides take precedence over generated code.
    printf("[BOOT] Applying game overrides (post-registration)...\n");
    ps2_game_overrides::applyMatching(runtime, elf_path, g.entry_point);

    // Begin execution
    printf("[BOOT] Starting execution at entry point 0x%08X...\n", g.entry_point);
    printf("[BOOT] ========================================\n\n");

#ifdef _WIN32
    reoStartHwWatch(runtime.memory().getRDRAM());
    reoStartStackDump();
    reoStartShots(&runtime);
#endif
    runtime.run();

    printf("\n[BOOT] ========================================\n");
    printf("[BOOT] Execution ended.\n");

    return 0;
}
