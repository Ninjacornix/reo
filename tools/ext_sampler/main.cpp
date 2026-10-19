// External stack sampler for a running reo_recomp process (no rebuild of the game).
// Suspends each thread briefly, walks its stack with dbghelp from THIS process
// (reads the target's memory and image .pdata; takes none of the target's locks),
// resumes it, and prints the same "[STACKDUMP] tid=N stack: 0xRVA ..." lines as the
// in-process sampler, so the existing prof_agg.py/link map tooling applies.
// Addresses inside the main exe are printed as exe RVAs; others as absolute.
//   ext_sampler.exe <pid> <delay_s> <samples> <interval_ms>  > samples.log
#include <windows.h>
#include <dbghelp.h>
#include <tlhelp32.h>
#include <cstdio>
#include <cstdlib>
#include <vector>
#pragma comment(lib, "dbghelp.lib")

int main(int argc, char** argv) {
    if (argc < 5) {
        std::fprintf(stderr, "usage: ext_sampler <pid> <delay_s> <samples> <interval_ms>\n");
        return 2;
    }
    const DWORD pid = std::strtoul(argv[1], nullptr, 0);
    const unsigned delay = std::strtoul(argv[2], nullptr, 0),
                   samples = std::strtoul(argv[3], nullptr, 0),
                   interval = std::strtoul(argv[4], nullptr, 0);
    HANDLE proc = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pid);
    if (!proc) {
        std::fprintf(stderr, "OpenProcess failed %lu\n", GetLastError());
        return 1;
    }
    SymSetOptions(SYMOPT_DEFERRED_LOADS | SYMOPT_NO_PROMPTS | SYMOPT_FAIL_CRITICAL_ERRORS);
    if (!SymInitialize(proc, nullptr, TRUE)) {
        std::fprintf(stderr, "SymInitialize failed %lu\n", GetLastError());
        return 1;
    }
    DWORD64 exeBase = 0, exeEnd = 0;
    if (HANDLE ms = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pid); ms != INVALID_HANDLE_VALUE) {
        MODULEENTRY32W me{};
        me.dwSize = sizeof(me);
        if (Module32FirstW(ms, &me)) {
            exeBase = reinterpret_cast<DWORD64>(me.modBaseAddr);
            exeEnd = exeBase + me.modBaseSize;
        }
        CloseHandle(ms);
    }
    std::fprintf(stderr, "ext_sampler pid=%lu exeBase=0x%llx size=0x%llx\n", pid, exeBase,
                 exeEnd - exeBase);
    Sleep(delay * 1000u);
    unsigned taken = 0;
    for (unsigned s = 0; s < samples; ++s) {
        if (s)
            Sleep(interval);
        DWORD code = 0;
        if (!GetExitCodeProcess(proc, &code) || code != STILL_ACTIVE)
            break;
        HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
        if (snap == INVALID_HANDLE_VALUE)
            break;
        THREADENTRY32 te{};
        te.dwSize = sizeof(te);
        for (BOOL ok = Thread32First(snap, &te); ok; ok = Thread32Next(snap, &te)) {
            if (te.th32OwnerProcessID != pid)
                continue;
            HANDLE th =
                OpenThread(THREAD_GET_CONTEXT | THREAD_SUSPEND_RESUME | THREAD_QUERY_INFORMATION,
                           FALSE, te.th32ThreadID);
            if (!th)
                continue;
            DWORD64 frames[32];
            int n = 0;
            if (SuspendThread(th) != static_cast<DWORD>(-1)) {
                CONTEXT c{};
                c.ContextFlags = CONTEXT_FULL;
                if (GetThreadContext(th, &c)) {
                    STACKFRAME64 f{};
                    f.AddrPC.Offset = c.Rip;
                    f.AddrPC.Mode = AddrModeFlat;
                    f.AddrFrame.Offset = c.Rbp;
                    f.AddrFrame.Mode = AddrModeFlat;
                    f.AddrStack.Offset = c.Rsp;
                    f.AddrStack.Mode = AddrModeFlat;
                    while (n < 32 &&
                           StackWalk64(IMAGE_FILE_MACHINE_AMD64, proc, th, &f, &c, nullptr,
                                       SymFunctionTableAccess64, SymGetModuleBase64, nullptr) &&
                           f.AddrPC.Offset)
                        frames[n++] = f.AddrPC.Offset;
                }
                ResumeThread(th);
            }
            CloseHandle(th);
            if (!n)
                continue;
            std::printf("[STACKDUMP] tid=%lu stack:", te.th32ThreadID);
            for (int i = 0; i < n; ++i) {
                const DWORD64 a = frames[i];
                if (a >= exeBase && a < exeEnd) {
                    std::printf(" 0x%llX", a - exeBase);
                    continue;
                }
                // Other modules: name+rva so waits/driver/CRT frames are attributable.
                IMAGEHLP_MODULE64 mi{};
                mi.SizeOfStruct = sizeof(mi);
                if (SymGetModuleInfo64(proc, a, &mi))
                    std::printf(" %s+0x%llX", mi.ModuleName, a - mi.BaseOfImage);
                else
                    std::printf(" ?0x%llX", a);
            }
            std::printf("\n");
        }
        CloseHandle(snap);
        ++taken;
    }
    std::fflush(stdout);
    std::fprintf(stderr, "ext_sampler done samples=%u\n", taken);
    SymCleanup(proc);
    CloseHandle(proc);
    return 0;
}
