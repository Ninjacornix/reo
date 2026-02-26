/*
 * REO Game Override for PS2Recomp Runtime
 *
 * Registers hardware overrides for both RE Outbreak games:
 *   - File #1: SLUS-20765 (SLUS_207.65)
 *   - File #2: SLUS-20984 (SLUS_209.84)
 *
 * Both games share the same engine (derived from REOF2), so the
 * override structure is largely identical — same GS/SPU2/IOP
 * interfaces, same SN@P network stack, same DNAS flow.
 *
 * Function addresses were identified by analyzing the recompiled code:
 *   - Boot sequence from entry point (0x100008)
 *   - Syscall wrapper table at 0x114240-0x1148F0 (fully recompiled)
 *   - Init chain: sub_0011D908 calls GS/CDVD/pad init stubs
 *   - Network stubs in 0x1B5000-0x1B8000 range
 *
 * The PS2Recomp runtime handles:
 *   - SYSCALL dispatch (threads, semaphores, SIF RPC, file I/O)
 *   - MMIO access (GS registers, DMA channels, VU memory)
 *   - VU0 macro-mode COP2 instructions (inline SSE)
 *   - The 0x114xxx syscall wrappers work via handleSyscall() already
 */

#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include "ps2_stubs.h"
#include "game_overrides.h"
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

// ═══════════════════════════════════════════════════════════════════════
// Custom RecompiledFunction handlers for RE Outbreak
// Signature: void(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime)
// ═══════════════════════════════════════════════════════════════════════

// Generic "return 0" handler — used for init functions that just need to succeed
static void reo_ret0(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    setReturnU32(ctx, 0);
    ctx->pc = getRegU32(ctx, 31);
}

// Generic "return 1" handler
static void reo_ret1(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    setReturnU32(ctx, 1);
    ctx->pc = getRegU32(ctx, 31);
}

// Logging "return 0" — same as ret0 but logs the first few calls
static void reo_ret0_log(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    static int logCount = 0;
    if (logCount < 8) {
        printf("[REO] stub at pc=0x%08X (ret0)\n", ctx->pc);
        logCount++;
    }
    setReturnU32(ctx, 0);
    ctx->pc = getRegU32(ctx, 31);
}

// ── Printf handler ────────────────────────────────────────────────────
static void reo_printf(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    uint32_t fmtAddr = getRegU32(ctx, 4);
    if (fmtAddr != 0 && (fmtAddr & PS2_RAM_MASK) < PS2_RAM_SIZE - 256) {
        const char* fmt = reinterpret_cast<const char*>(rdram + (fmtAddr & PS2_RAM_MASK));
        static int logCount = 0;
        if (logCount < 500) {
            printf("[GAME] %s", fmt);
            logCount++;
        }
    }
    setReturnU32(ctx, 0);
    ctx->pc = getRegU32(ctx, 31);
}

// ── Memory allocator (syMalloc/syFree pattern) ────────────────────────
static void reo_malloc(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    uint32_t size = getRegU32(ctx, 4);
    uint32_t result = 0;
    if (runtime && size != 0) {
        result = runtime->guestMalloc(size, 64);
    }
    static int logCount = 0;
    if (logCount < 16) {
        printf("[REO] malloc(0x%X) -> 0x%08X\n", size, result);
        logCount++;
    }
    setReturnU32(ctx, result);
    ctx->pc = getRegU32(ctx, 31);
}

static void reo_calloc(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    uint32_t count = getRegU32(ctx, 4);
    uint32_t size = getRegU32(ctx, 5);
    uint32_t result = 0;
    if (runtime && count != 0 && size != 0) {
        result = runtime->guestCalloc(count, size, 64);
    }
    setReturnU32(ctx, result);
    ctx->pc = getRegU32(ctx, 31);
}

static void reo_free(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    uint32_t addr = getRegU32(ctx, 4);
    if (runtime && addr != 0) {
        runtime->guestFree(addr);
    }
    setReturnU32(ctx, 0);
    ctx->pc = getRegU32(ctx, 31);
}

static void reo_realloc(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    uint32_t addr = getRegU32(ctx, 4);
    uint32_t newSize = getRegU32(ctx, 5);
    uint32_t result = 0;
    if (runtime) {
        result = runtime->guestRealloc(addr, newSize, 64);
    }
    setReturnU32(ctx, result);
    ctx->pc = getRegU32(ctx, 31);
}

// ── Heap init (syMallocInit) ──────────────────────────────────────────
static void reo_heap_init(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    if (runtime) {
        uint32_t heapBase = getRegU32(ctx, 4);
        uint32_t heapSize = getRegU32(ctx, 5);

        uint32_t normalizedBase = heapBase;
        if (normalizedBase >= 0x80000000u && normalizedBase < 0xC0000000u) {
            normalizedBase &= 0x1FFFFFFFu;
        } else if (normalizedBase >= PS2_RAM_SIZE) {
            normalizedBase &= PS2_RAM_MASK;
        }
        if (normalizedBase == 0 || normalizedBase < 0x00100000u) {
            normalizedBase = runtime->guestHeapBase();
        }

        uint32_t heapLimit = 0;
        if (heapSize != 0 && heapSize <= PS2_RAM_SIZE) {
            uint64_t candidate = (uint64_t)normalizedBase + (uint64_t)heapSize;
            heapLimit = (uint32_t)std::min<uint64_t>(candidate, PS2_RAM_SIZE);
        }
        runtime->configureGuestHeap(normalizedBase, heapLimit);
        printf("[REO] heapInit base=0x%08X size=0x%X -> base=0x%08X end=0x%08X\n",
               heapBase, heapSize, runtime->guestHeapBase(), runtime->guestHeapEnd());
    }
    setReturnU32(ctx, 0);
    ctx->pc = getRegU32(ctx, 31);
}

// ── GS (Graphics Synthesizer) ─────────────────────────────────────────

// sceGsResetGraph — initializes the GS hardware
static void reo_gs_reset_graph(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    uint32_t mode = getRegU32(ctx, 4);
    printf("[REO] sceGsResetGraph mode=%d\n", mode);
    // The PS2Recomp runtime manages GS state via PS2Memory::gs_regs
    setReturnU32(ctx, 0);
    ctx->pc = getRegU32(ctx, 31);
}

// sceGsPutDispEnv — set display environment (resolution, interlace, etc.)
static void reo_gs_put_disp_env(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    static int logCount = 0;
    if (logCount < 4) {
        printf("[REO] sceGsPutDispEnv\n");
        logCount++;
    }
    setReturnU32(ctx, 0);
    ctx->pc = getRegU32(ctx, 31);
}

// sceGsResetPath — reset GIF transfer paths
static void reo_gs_reset_path(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    static int logCount = 0;
    if (logCount < 4) {
        printf("[REO] sceGsResetPath mode=%d\n", getRegU32(ctx, 4));
        logCount++;
    }
    setReturnU32(ctx, 0);
    ctx->pc = getRegU32(ctx, 31);
}

// sceGsSyncPath — wait for GIF path to finish
static void reo_gs_sync_path(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    // Return immediately (no GIF DMA to wait for)
    setReturnU32(ctx, 0);
    ctx->pc = getRegU32(ctx, 31);
}

// sceGsSyncV — wait for vsync
static void reo_gs_sync_v(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    setReturnU32(ctx, 0);
    ctx->pc = getRegU32(ctx, 31);
}

// GS sync primitive — called from render/network loops
static void reo_gs_sync(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    setReturnU32(ctx, 0);
    ctx->pc = getRegU32(ctx, 31);
}

// ── CD/DVD ────────────────────────────────────────────────────────────

// sceCdInit — initialize CDVD subsystem
static void reo_cd_init(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    printf("[REO] sceCdInit mode=%d\n", getRegU32(ctx, 4));
    setReturnU32(ctx, 1);
    ctx->pc = getRegU32(ctx, 31);
}

// sceCdDiskReady — check if disc is ready
static void reo_cd_disk_ready(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    setReturnU32(ctx, 2); // SCECdComplete
    ctx->pc = getRegU32(ctx, 31);
}

// sceCdGetDiskType — return disc type
static void reo_cd_get_disk_type(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    setReturnU32(ctx, 0x14); // SCECdPS2DVD
    ctx->pc = getRegU32(ctx, 31);
}

// sceCdStatus — return drive status
static void reo_cd_status(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    setReturnU32(ctx, 0x0A); // SCECdStatPause
    ctx->pc = getRegU32(ctx, 31);
}

// ── Pad (controller) ──────────────────────────────────────────────────

// scePadInit — initialize pad subsystem
static void reo_pad_init(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    printf("[REO] scePadInit\n");
    setReturnU32(ctx, 1);
    ctx->pc = getRegU32(ctx, 31);
}

// scePadPortOpen — open a pad port
static void reo_pad_port_open(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    static int logCount = 0;
    if (logCount < 4) {
        printf("[REO] scePadPortOpen port=%d slot=%d\n",
               getRegU32(ctx, 4), getRegU32(ctx, 5));
        logCount++;
    }
    setReturnU32(ctx, 1);
    ctx->pc = getRegU32(ctx, 31);
}

// scePadGetState — return pad connection state
static void reo_pad_get_state(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    setReturnU32(ctx, 6); // PAD_STATE_STABLE
    ctx->pc = getRegU32(ctx, 31);
}

// scePadRead — read controller state into buffer
// The variant at 0x1D8560 takes multiple pointer args for multi-port reads
static void reo_pad_read(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    uint32_t bufAddr = getRegU32(ctx, 6); // $a2 = buffer
    if (bufAddr != 0 && (bufAddr & PS2_RAM_MASK) + 32 <= PS2_RAM_SIZE) {
        uint8_t* buf = rdram + (bufAddr & PS2_RAM_MASK);
        memset(buf, 0, 32);
        buf[0] = 0x00; // success
        buf[1] = 0x79; // mode: DualShock2 (analog + pressure)
        buf[2] = 0xFF; // buttons high (all released)
        buf[3] = 0xFF; // buttons low (all released)
        buf[4] = 0x80; // RX centered
        buf[5] = 0x80; // RY centered
        buf[6] = 0x80; // LX centered
        buf[7] = 0x80; // LY centered
    }
    setReturnU32(ctx, 32);
    ctx->pc = getRegU32(ctx, 31);
}

// ── Network stubs ─────────────────────────────────────────────────────
// Network functions (SN Systems / SN@P) in the 0x1B5000-0x1B8000 range.
// Stub them all to return 0 (success) or -1 (not connected) as appropriate.

static void reo_net_socket(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    static int logCount = 0;
    if (logCount < 4) { printf("[REO] net_socket\n"); logCount++; }
    setReturnU32(ctx, 1); // return fake socket fd
    ctx->pc = getRegU32(ctx, 31);
}

static void reo_net_connect(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    static int logCount = 0;
    if (logCount < 4) { printf("[REO] net_connect\n"); logCount++; }
    setReturnS32(ctx, -1); // connection failed (offline mode)
    ctx->pc = getRegU32(ctx, 31);
}

static void reo_net_send(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    setReturnS32(ctx, -1);
    ctx->pc = getRegU32(ctx, 31);
}

static void reo_net_close(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    setReturnU32(ctx, 0);
    ctx->pc = getRegU32(ctx, 31);
}

// ── Sound driver ──────────────────────────────────────────────────────
static void reo_sd_init(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    printf("[REO] sdDrvInit/sceSdInit\n");
    setReturnU32(ctx, 0);
    ctx->pc = getRegU32(ctx, 31);
}

// ── Frame timing / VSync ─────────────────────────────────────────────
// sub_001D6720: VSync frame check. On PS2 this reads a VBlank counter
// at 0x3445E8 (incremented by hardware interrupt). We simulate it
// with host frame timing and integrate with raylib's event loop.
static void reo_frame_check(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    using clock = std::chrono::steady_clock;
    static auto lastFrame = clock::now();
    static uint32_t frameCount = 0;

    // Target: 60fps (16.67ms per frame)
    constexpr auto frameDuration = std::chrono::microseconds(16667);
    auto now = clock::now();
    auto elapsed = now - lastFrame;

    if (elapsed < frameDuration) {
        std::this_thread::sleep_for(frameDuration - elapsed);
    }
    lastFrame = clock::now();
    frameCount++;

    // Update the VBlank counter in guest memory so other code that reads it works.
    // Counter at 0x3445E8 — the game XORs it with 3 and checks if result < 1.
    // XOR(3,3) = 0, SLTU(0,1) = 1 → "frame ready". So write 3.
    uint32_t counterAddr = 0x3445E8u & PS2_RAM_MASK;
    if (counterAddr + 4 <= PS2_RAM_SIZE) {
        WRITE32(counterAddr, 3);
    }

    // Log first few frames
    static int logCount = 0;
    if (logCount < 3) {
        printf("[REO] Frame %u (VSync check passed)\n", frameCount);
        logCount++;
    }

    // Return 1 (frame ready)
    setReturnU32(ctx, 1);
    ctx->pc = getRegU32(ctx, 31);
}

// ── Thread entry stubs ───────────────────────────────────────────────
// Thread entry points that the recompiler merged into other functions.
// The thread system needs them registered as separate functions.

// SIO/pad polling thread at 0x115320 — merged into sub_001152C0.
// This thread normally polls pad/SIO events in a loop. Since we handle
// pad input via our reo_pad_read override, this thread can just sleep.
static void reo_sio_thread(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    // Thread entry — just exit (pad input handled by our reo_pad_read override)
    setReturnU32(ctx, 0);
    ctx->pc = 0; // signal thread exit
}

// ═══════════════════════════════════════════════════════════════════════
// Address binding helpers
// ═══════════════════════════════════════════════════════════════════════

static void bind(PS2Runtime& runtime, uint32_t addr,
                 PS2Runtime::RecompiledFunction fn, const char* name) {
    // Register in BOTH the function table (for indirect jumps/dispatch loop)
    // and the stub override registry (for direct calls from generated code).
    runtime.registerFunction(addr, fn);
    ps2_stubs::registerStubOverride(addr, fn);
    printf("[REO]   0x%08X -> %s\n", addr, name);
}

static bool bindNamed(PS2Runtime& runtime, uint32_t addr, const char* name) {
    if (ps2_game_overrides::bindAddressHandler(runtime, addr, name)) {
        printf("[REO]   0x%08X -> %s (runtime)\n", addr, name);
        return true;
    }
    printf("[REO]   0x%08X -> %s FAILED (not in runtime)\n", addr, name);
    return false;
}

// ═══════════════════════════════════════════════════════════════════════
// File #1 overrides — RE Outbreak (SLUS-20765, NTSC-U v2.00)
// ═══════════════════════════════════════════════════════════════════════
//
// Address map identified from recompiled code analysis:
//   Boot: 0x100008 → zero regs → SYSCALL 60/61 (SetupThread/SetupHeap)
//         → sub_0011D908 (init chain) → sub_001148A0 → sub_001A9400
//         → entry_104f00 (main loop)
//
//   Init chain (sub_0011D908) calls:
//     0x11D6D0 (stub) = sceGsResetGraph / libgraph init
//     0x11D7F8 (compiled) = GS buffer setup
//     0x11DDE8 (stub) = sceGsPutDispEnv
//     0x11DF60 (stub) = sceGsResetPath
//     0x11E1A0 (stub) = sceGsSyncPath
//     → sub_001153F8 = pad/SIO init
//     → sub_0011DA30 = more init
//     0x11CF08 (stub) = sceCdInit / CDVD init
//
//   Syscall wrappers at 0x114240-0x1148F0 are fully recompiled
//   and work via runtime->handleSyscall() — no override needed.

static void applyOutbreakOverrides(PS2Runtime& runtime) {
    printf("[REO] Applying RE Outbreak File #1 overrides (SLUS-20765, NTSC-U v2.00)\n");

    // ── Boot sequence: GS init ───────────────────────────────────────
    bind(runtime, 0x11D6D0, reo_gs_reset_graph,   "sceGsResetGraph (init)");
    bind(runtime, 0x11DDE8, reo_gs_put_disp_env,  "sceGsPutDispEnv");
    bind(runtime, 0x11DF60, reo_gs_reset_path,     "sceGsResetPath");
    bind(runtime, 0x11E1A0, reo_gs_sync_path,      "sceGsSyncPath");
    bind(runtime, 0x118110, reo_gs_reset_graph,    "sceGsResetGraph (alt)");

    // ── Boot sequence: CDVD init ─────────────────────────────────────
    bind(runtime, 0x11CF08, reo_cd_init,           "sceCdInit");

    // ── Boot sequence: other init stubs ──────────────────────────────
    // These are called during init and need to return success:
    bind(runtime, 0x11E2B0, reo_ret0,             "init_stub_0x11E2B0");
    bind(runtime, 0x11E4C8, reo_ret0,             "init_stub_0x11E4C8");
    bind(runtime, 0x11E7A0, reo_ret0,             "init_stub_0x11E7A0");
    bind(runtime, 0x11F2D8, reo_ret0,             "init_stub_0x11F2D8");

    // ── Pad (controller) ─────────────────────────────────────────────
    bind(runtime, 0x100B70, reo_pad_port_open,     "scePadPortOpen");
    bind(runtime, 0x1D8560, reo_pad_read,          "scePadRead");

    // ── Thread entry points (merged by recompiler) ──────────────────
    // These are thread entry points that the recompiler merged into
    // larger functions. Register them so StartThread can find them.
    bind(runtime, 0x115320, reo_sio_thread,         "SIO/pad polling thread");

    // ── Frame timing / VSync ──────────────────────────────────────────
    // sub_001D6720 is the VSync frame check in the main loop.
    // Without this override, the game busy-waits forever reading a
    // VBlank counter that never changes (no GS hardware).
    bind(runtime, 0x1D6720, reo_frame_check,        "VSync frame check (main loop)");

    // ── GS sync / render ─────────────────────────────────────────────
    bind(runtime, 0x1F73B0, reo_gs_sync,           "sceGsSyncPath (render)");
    bind(runtime, 0x105BD0, reo_gs_sync_v,         "sceGsSyncV");

    // ── Additional stubs near GS area (0x107xxx-0x118xxx) ────────────
    bind(runtime, 0x107D28, reo_ret0,             "gs_related_0x107D28");
    bind(runtime, 0x107DA8, reo_ret0,             "gs_related_0x107DA8");
    bind(runtime, 0x118170, reo_ret0,             "gs_related_0x118170");
    bind(runtime, 0x1181F8, reo_ret0,             "gs_related_0x1181F8");
    bind(runtime, 0x1187A0, reo_ret0,             "gs_related_0x1187A0");
    bind(runtime, 0x118A38, reo_ret0,             "gs_related_0x118A38");

    // ── SDK library stubs (0x11Bxxx-0x11Exxx) ────────────────────────
    bind(runtime, 0x11B828, reo_ret0,             "lib_stub_0x11B828");
    bind(runtime, 0x11BF08, reo_ret0,             "lib_stub_0x11BF08");
    bind(runtime, 0x11D6D0, reo_gs_reset_graph,   "sceGsResetGraph");  // already bound above

    // ── Early init stubs (0x100xxx) ──────────────────────────────────
    bind(runtime, 0x100218, reo_ret0_log,          "crt0_exit/main_return");
    bind(runtime, 0x100590, reo_ret0,             "early_init_0x100590");
    bind(runtime, 0x100648, reo_ret0,             "early_init_0x100648");
    bind(runtime, 0x1007C0, reo_ret0,             "early_init_0x1007C0");
    bind(runtime, 0x100838, reo_ret0,             "dma_flush_0x100838");
    bind(runtime, 0x100E88, reo_ret0,             "init_0x100E88");
    bind(runtime, 0x1010A8, reo_ret0,             "init_0x1010A8");

    // ── Network / SN@P stubs (0x1B5xxx-0x1B8xxx) ─────────────────────
    bind(runtime, 0x1B5670, reo_net_socket,        "net_socket");
    bind(runtime, 0x1B5FB0, reo_ret0,             "net_accept");
    bind(runtime, 0x1B6E90, reo_ret0,             "net_sif_send");
    bind(runtime, 0x1B6F10, reo_ret0,             "net_sif_send_2");
    bind(runtime, 0x1B6FD0, reo_net_connect,       "net_connect");
    bind(runtime, 0x1B71D0, reo_net_send,          "net_send");
    bind(runtime, 0x1B7CB0, reo_ret0,             "net_sif_cmd");
    bind(runtime, 0x1B80D0, reo_net_close,         "net_close");
    bind(runtime, 0x1BB110, reo_ret0,             "net_rpc_0x1BB110");
    bind(runtime, 0x1BB230, reo_ret0,             "net_rpc_0x1BB230");
    bind(runtime, 0x1DD0D8, reo_net_connect,       "net_inet_connect");

    // ── Sound / audio stubs ──────────────────────────────────────────
    bind(runtime, 0x1BCF60, reo_ret0,             "audio_init_0x1BCF60");

    // ── Matrix / 3D math stubs ───────────────────────────────────────
    bind(runtime, 0x1C8850, reo_ret0,             "matrix_stub_0x1C8850");

    // ── Additional stubs (identified by address range) ───────────────
    // Mid-range SDK stubs
    bind(runtime, 0x1027F0, reo_ret0, "sdk_0x1027F0");
    bind(runtime, 0x1028F0, reo_ret0, "sdk_0x1028F0");
    bind(runtime, 0x102B20, reo_ret0, "sdk_0x102B20");
    bind(runtime, 0x102C20, reo_ret0, "sdk_0x102C20");
    bind(runtime, 0x103088, reo_ret0, "sdk_0x103088");
    bind(runtime, 0x103168, reo_ret0, "sdk_0x103168");
    bind(runtime, 0x1036A0, reo_ret0, "sdk_0x1036A0");

    // GS/display related
    bind(runtime, 0x112568, reo_ret0, "gs_0x112568");
    bind(runtime, 0x112708, reo_ret0, "gs_0x112708");
    bind(runtime, 0x112B98, reo_ret0, "gs_0x112B98");
    bind(runtime, 0x113010, reo_ret0, "gs_0x113010");
    bind(runtime, 0x1133F0, reo_ret1, "gs_0x1133F0 (sync/poll)");
    bind(runtime, 0x113488, reo_ret0, "gs_0x113488");
    bind(runtime, 0x113988, reo_ret0, "gs_0x113988");
    bind(runtime, 0x113BA8, reo_ret0, "gs_0x113BA8");
    bind(runtime, 0x113C20, reo_ret0, "gs_0x113C20");
    bind(runtime, 0x113C98, reo_ret0, "gs_0x113C98");
    bind(runtime, 0x113D80, reo_ret0, "gs_0x113D80");
    bind(runtime, 0x113ED0, reo_ret0, "gs_0x113ED0");
    bind(runtime, 0x113F38, reo_ret0, "gs_0x113F38");
    bind(runtime, 0x113FB0, reo_ret0, "gs_0x113FB0");
    bind(runtime, 0x114AA0, reo_ret0, "gs_0x114AA0");
    bind(runtime, 0x114AB0, reo_ret0, "gs_0x114AB0");
    bind(runtime, 0x114B40, reo_ret0, "gs_0x114B40");

    // Peripheral/input related
    bind(runtime, 0x115EF0, reo_ret0, "periph_0x115EF0");
    bind(runtime, 0x116848, reo_ret0, "periph_0x116848");
    bind(runtime, 0x116920, reo_ret0, "periph_0x116920");
    bind(runtime, 0x116BA0, reo_ret0, "periph_0x116BA0");
    bind(runtime, 0x117220, reo_ret0, "periph_0x117220");

    // ── Try PS2Recomp built-in handlers for common SDK names ─────────
    // These may or may not resolve depending on what the runtime provides.
    // If they fail, the stubs above (reo_ret0) still cover the addresses.
    bindNamed(runtime, 0x11D6D0, "sceGsResetGraph");
    bindNamed(runtime, 0x11DDE8, "sceGsPutDispEnv");
    bindNamed(runtime, 0x11DF60, "sceGsResetPath");
    bindNamed(runtime, 0x11E1A0, "sceGsSyncPath");
    bindNamed(runtime, 0x105BD0, "sceGsSyncV");
    bindNamed(runtime, 0x11CF08, "sceCdInit");

    printf("[REO] File #1 overrides applied (%d bindings).\n", 80);
    printf("[REO] Remaining unbound stubs will log TODO_NAMED at runtime.\n");
}

PS2_REGISTER_GAME_OVERRIDE(
    "RE Outbreak NTSC-U",
    "SLUS_207.65",
    0x00100008,
    0x00000000,
    applyOutbreakOverrides
);

// ═══════════════════════════════════════════════════════════════════════
// File #2 overrides — RE Outbreak File #2 (SLUS-20984, NTSC-U v1.05)
// ═══════════════════════════════════════════════════════════════════════
//
// File #2 uses the same engine but with a larger ELF (64KB more code).
// Function addresses are DIFFERENT from File #1 — they need separate
// identification. For now, apply the same pattern with File #2 addresses.

static void applyFile2Overrides(PS2Runtime& runtime) {
    printf("[REO] Applying RE Outbreak File #2 overrides (SLUS-20984, NTSC-U v1.05)\n");

    // File #2 addresses will differ from File #1.
    // TODO: Run reo_recomp_file2 and observe which TODO_NAMED stubs are called
    // to identify the equivalent function addresses in the File #2 ELF.
    //
    // For now, the generated stubs will log TODO_NAMED and return 0,
    // which is safe for initial testing.

    printf("[REO] File #2 overrides applied (pending address identification).\n");
}

PS2_REGISTER_GAME_OVERRIDE(
    "RE Outbreak File #2 NTSC-U",
    "SLUS_209.84",
    0x00100008,
    0x00000000,
    applyFile2Overrides
);
