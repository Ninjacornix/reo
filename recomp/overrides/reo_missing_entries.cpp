// Function entries the recompiler never registered. Each one was reached at runtime through
// PS2Runtime::lookupFunction's "Function at address ... not found" fallback, which returns to $ra
// and so SKIPS the original code. Measured 2026-10-19 (build-ninja/play/stderr.log, ~13 min of play):
// 0x6A1390 x6898 and 0x1B7890 x1214, in bursts of up to 240 calls/s (the user-visible stutter, plus
// the skipped logic itself).
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include "reo_hw_bridge.h"
#include "../../network/native/ee_count_clock.h"
#include "../../network/native/automatic_account.h"
#include "../../network/native/game_netcode.h"
#include <cstdlib>
#include <cstring>
#include <atomic>

#if __has_include("../config/output_extra/dnas_tail_aot/reo_dnas_tail_aot.inc")
#include "../config/output_extra/dnas_tail_aot/reo_dnas_tail_aot.inc"
#define REO_HAS_DNAS_TAIL_AOT 1
#endif
#if __has_include("../config/output_extra/native_network/reo_slot_query.inc")
#include "../config/output_extra/native_network/reo_slot_query.inc"
#define REO_HAS_SLOT_QUERY_AOT 1
#endif
#if __has_include("../config/output_extra/native_network/reo_free_mode_callback.inc")
#include "../config/output_extra/native_network/reo_free_mode_callback.inc"
#define REO_HAS_FREE_MODE_CALLBACK_AOT 1
#endif
#if __has_include("../config/output_extra/native_network/reo_verified_callbacks.inc")
#include "../config/output_extra/native_network/reo_verified_callbacks.inc"
#define REO_HAS_VERIFIED_CALLBACKS_AOT 1
#endif
#if __has_include("../config/output_extra/native_network/reo_lobby_profile_callback.inc")
#include "../config/output_extra/native_network/reo_lobby_profile_callback.inc"
#include "../config/output_extra/native_network/reo_lobby_state_callback.inc"
#include "../config/output_extra/native_network/reo_lobby_choice_callback.inc"
#define REO_HAS_LOBBY_CALLBACKS_AOT 1
#endif

void o2_006A12B0_0x6a12b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime);
// Separate original O2 entries merged into 6A12B0 by the function map.
// The generated entry switch contains resume PCs, not 6A1390/6A13D0.
static void zombieFadeDelay(uint8_t* rdram,R5900Context* ctx,PS2Runtime* runtime) {
    const auto a=GPR_U32(ctx,4);
    const auto ticks=int16_t(int16_t(READ16(a+0xe))-1);
    WRITE16(a+0xe,uint16_t(ticks));
    if(ticks<=0) WRITE8(a+0xa,uint8_t(READ8(a+0xa)+1));
    ctx->f[12]=0;ctx->pc=0x58c300;
    runtime->lookupFunction(ctx->pc)(rdram,ctx,runtime);
}
static void zombieFadeOut(uint8_t* rdram,R5900Context* ctx,PS2Runtime* runtime) {
    const auto a=GPR_U32(ctx,4),sp=GPR_U32(ctx,29)-32;
    WRITE64(sp+16,GPR_U64(ctx,31));WRITE128(sp,GPR_VEC(ctx,16));
    SET_GPR_U32(ctx,29,sp);SET_GPR_U32(ctx,16,a);
    const auto alpha=READ8(a+0xccc);
    if(alpha<8) {
        WRITE8(a+0xccc,0);WRITE8(a+0xa,uint8_t(READ8(a+0xa)+1));WRITE8(a+1,0);
        SET_GPR_U32(ctx,31,0x6a1404);ctx->pc=0x6acb50;
        runtime->lookupFunction(ctx->pc)(rdram,ctx,runtime);
        if(ctx->pc!=0x6a1404) return;
    } else { WRITE8(a+0xccc,alpha-8);ctx->pc=0x6a1404; }
    // This genuine generated resume copies alpha and restores this exact frame.
    o2_006A12B0_0x6a12b0(rdram,ctx,runtime);
}
void o3_00603320_0x603320(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime);
void o3_005F74E0_0x5f74e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime);
void o3_005F74F0_0x5f74f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime);
void o3_00609750_0x609750(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime);
void o3_005F8280_0x5f8280(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime);
void o3_005809B0_0x5809b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime);
void o3_0058BF10_0x58bf10(uint8_t*, R5900Context*, PS2Runtime*);
void o3_0059FB00_0x59fb00(uint8_t*, R5900Context*, PS2Runtime*);
void o3_00599110_0x599110(uint8_t*, R5900Context*, PS2Runtime*);
void o3_005A54C0_0x5a54c0(uint8_t*, R5900Context*, PS2Runtime*);
void sub_001F3BCC_0x1f3bcc(uint8_t*, R5900Context*, PS2Runtime*);
void sub_001DC7B8_0x1dc7b8(uint8_t*, R5900Context*, PS2Runtime*);
void sub_001DFDA8_0x1dfda8(uint8_t*, R5900Context*, PS2Runtime*);
void sub_001DF99C_0x1df99c(uint8_t*, R5900Context*, PS2Runtime*);
void sub_001EA000_0x1ea000(uint8_t*, R5900Context*, PS2Runtime*);
void sub_001C8850_0x1c8850(uint8_t*, R5900Context*, PS2Runtime*);
void sub_001C72F0_0x1c72f0(uint8_t*, R5900Context*, PS2Runtime*);
void o2_006647F0_0x6647f0(uint8_t*, R5900Context*, PS2Runtime*);
void o2_0067ED50_0x67ed50(uint8_t*, R5900Context*, PS2Runtime*);
void sub_001AFDD0_0x1afdd0(uint8_t*, R5900Context*, PS2Runtime*);

namespace reo_missing_entries {
namespace {
void nativeReliableSend(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    const char* host = std::getenv("REO_COOP_HOST");
    const char* mode = std::getenv("REO_COOP_PLATFORM_AUTH");
    if (host && *host && mode && std::strcmp(mode, "native") == 0 &&
        READ32(0x235F60) == 0x3F800000u) {
        // SLUS-20765's reliable queue defaults to 1 second. Match File #2's
        // original 0.5-second batch interval; retain non-default server tuning.
        // The original pump still owns queueing, ACKs, retries and send completion.
        WRITE32(0x235F60, 0x3F000000u);
        std::fprintf(stderr, "[COOP-RATE] File #1 reliable batching: 1000 -> 500 ms\n");
    }
    reo_network::native::capture(rdram,reo_network::native::File1);
    reo_network::native::cadence(rdram,reo_network::native::File1,
                               reo_network::native::runtime().enhanced(reo_network::native::nowUs()));
    reo_network::native::worldPump(rdram,ctx,runtime,false);
    sub_001C72F0_0x1c72f0(rdram, ctx, runtime);
}
void nativeMotionCorrection(uint8_t* rdram,R5900Context* ctx,PS2Runtime* runtime) {
    reo_network::native::correction(rdram,reo_network::native::File1,GPR_U32(ctx,4));
    o2_006647F0_0x6647f0(rdram,ctx,runtime);
}
void nativeMotionReceive(uint8_t* rdram,R5900Context* ctx,PS2Runtime* runtime) {
    reo_network::native::MotionRecord record(rdram,reo_network::native::File1,GPR_U32(ctx,4),GPR_U32(ctx,5));
    o2_0067ED50_0x67ed50(rdram,ctx,runtime);
}
void nativeEventSend(uint8_t* rdram,R5900Context* ctx,PS2Runtime* runtime) {
    reo_network::native::worldObserve(rdram,false,GPR_U32(ctx,4),GPR_U32(ctx,5));
    const auto mode=reo_network::native::reliableRefresh && GPR_U32(ctx,4)==8 ? 4u :
        reo_network::native::eventReliability(rdram,reo_network::native::File1,GPR_U32(ctx,4),GPR_U32(ctx,5),GPR_U32(ctx,7));
    if(mode!=GPR_U32(ctx,7)) SET_GPR_U32(ctx,7,mode);
    sub_001AFDD0_0x1afdd0(rdram,ctx,runtime);
}

void nativeNetworkDisplay(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    namespace account = reo_network::automatic_account;
    const unsigned step = READ8(0x6DF150);
    static unsigned previousStep = ~0u;
    // This callback belongs only to the verified netwk overlay. It runs after
    // Network is selected, including the fresh-card NET-file creation prompt.
    if (account::enabled() && (!account::armed.load() ||
        (step == 2 && previousStep != 2 && account::completed.load())))
        account::arm();
    previousStep = step;
    o3_005F8280_0x5f8280(rdram, ctx, runtime);
}
void nativeNetworkSeconds(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    const char* host = std::getenv("REO_COOP_HOST");
    const char* mode = std::getenv("REO_COOP_PLATFORM_AUTH");
    if (!host || !*host || !mode || std::strcmp(mode, "native") != 0) {
        sub_001C8850_0x1c8850(rdram, ctx, runtime);
        return;
    }
    // The original SDK returns accumulated seconds from an HBlank timer.
    // That MMIO counter is stored-only in this runtime, so use host time.
    static reo_network::ElapsedSecondsClock clock;
    const bool reset = READ8(0x33B200) == 0;
    uint32_t previousBits = READ32(0x33B210);
    float previous;
    std::memcpy(&previous, &previousBits, sizeof(previous));
    if (reset) {
        // Preserve the original timer initialization for other register readers.
        runtime->Store32(rdram, ctx, 0x10000810, 0);
        runtime->Store32(rdram, ctx, 0x10000800, 0);
        runtime->Store32(rdram, ctx, 0x10000810, 0x83);
        WRITE8(0x33B200, 1);
        std::fprintf(stderr, "[COOP-CLOCK] SDK elapsed seconds use monotonic host time\n");
    }
    ctx->f[0] = clock.read(reset, previous);
    uint32_t secondsBits;
    std::memcpy(&secondsBits, &ctx->f[0], sizeof(secondsBits));
    WRITE32(0x33B210, secondsBits);
    ctx->pc = GPR_U32(ctx, 31);
}

void nativeNetworkCount(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    const char* host = std::getenv("REO_COOP_HOST");
    const char* mode = std::getenv("REO_COOP_PLATFORM_AUTH");
    if (host && *host && mode && std::strcmp(mode, "native") == 0) {
        // This SDK hardware getter otherwise reads a never-advanced context field.
        // Keep original gettimeofday conversion, send delays and timeout logic.
        static const reo_network::EeCountClock clock;
        ctx->cop0_count = clock.read();
    }
    sub_001EA000_0x1ea000(rdram, ctx, runtime);
}

template <uint32_t Entry, PS2Runtime::RecompiledFunction Function>
void traceSnapPacket(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    static const bool enabled = [] {
        const char* value = std::getenv("REO_SNAP_TRACE");
        return value && std::strcmp(value, "1") == 0;
    }();
    static std::atomic<unsigned> count{0};
    const bool trace = enabled && count.fetch_add(1) < 64;
    const uint32_t a0 = GPR_U32(ctx, 4), a1 = GPR_U32(ctx, 5);
    const uint32_t packet = Entry == 0x1DFDA8 || Entry == 0x1DF99C ? a1 : a0;
    const auto word = [&](uint32_t address) -> uint32_t {
        return address <= 0x2000000 - 4 ? READ32(address) : 0xffffffff;
    };
    if (trace)
        std::fprintf(stderr,
                     "[SNAP-PACKET] entry=%08x a0=%08x a1=%08x a2=%08x a3=%08x "
                     "header=%08x/%08x/%08x/%08x error=%08x\n",
                     Entry, a0, a1, GPR_U32(ctx, 6), GPR_U32(ctx, 7), word(packet + 0x2C),
                     word(packet + 0x30), word(packet + 0x34), word(packet + 0x38), word(0x259D10));
    Function(rdram, ctx, runtime);
    if (trace)
        std::fprintf(
            stderr,
            "[SNAP-PACKET] leave=%08x pc=%08x v0=%08x header=%08x/%08x/%08x/%08x error=%08x\n",
            Entry, ctx->pc, GPR_U32(ctx, 2), word(packet + 0x2C), word(packet + 0x30),
            word(packet + 0x34), word(packet + 0x38), word(0x259D10));
}

void browserDeactivate(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    // Original overlay 3 tail entry: j 5A54C0; addiu a0,zero,3.
    SET_GPR_U32(ctx, 4, 3);
    ctx->pc = 0x5A54C0;
    o3_005A54C0_0x5a54c0(rdram, ctx, runtime);
}

bool validAccountUsername(const char* value) {
    if (!value)
        return false;
    size_t length = 0;
    bool underscore = true;
    for (; value[length] && length <= 10; ++length) {
        const unsigned char c = value[length];
        if (c == '_') {
            if (underscore)
                return false;
            underscore = true;
        } else {
            if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')))
                return false;
            underscore = false;
        }
    }
    return length >= 4 && length <= 10 && !underscore;
}

// Run these short original UI helpers through any genuine recompiler resumptions.
bool runAccountHelper(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime, uint32_t entry,
                      uint32_t argument) {
    const uint32_t returnPc = GPR_U32(ctx, 31);
    SET_GPR_U32(ctx, 4, argument);
    ctx->pc = entry;
    for (unsigned steps = 0; steps < 4096 && !runtime->isStopRequested(); ++steps) {
        auto function = runtime->lookupFunction(ctx->pc);
        if (!function)
            break;
        function(rdram, ctx, runtime);
        if (ctx->pc == returnPc)
            return true;
    }
    std::fprintf(stderr, "[COOP-ACCOUNT] Original account helper did not return, pc=%08x\n",
                 ctx->pc);
    runtime->requestStop();
    return false;
}

void nativePasswordPoll(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    namespace account = reo_network::automatic_account;
    const uint32_t work = READ32(0x6436D0);
    if (account::enabled() && GPR_U32(ctx, 31) == 0x608B60 && GPR_U32(ctx, 4) == 0x6DF110 &&
        READ8(0x6DF150) == 46 && READ8(0x6DF151) == 11 && work >= 0x100000 &&
        work <= 0x2000000 - 0x700 && READ8(work + 0x28) == 1 && READ8(work + 0x21) == 5 &&
        READ16(work + 0x3E) == 15 && READ8(0x6436C8) == 0) {
        std::array<char, 16> password{};
        if (account::credential(password)) {
            const R5900Context caller = *ctx;
            // Supply the native credential as the original editor's initial text,
            // then invoke its ordinary Enter handler. Account authentication is untouched.
            for (unsigned i = 0; i < password.size(); ++i) WRITE8(0x6DF110 + i, uint8_t(password[i]));
            SET_GPR_U32(ctx, 5, 5); SET_GPR_U32(ctx, 6, 15); SET_GPR_U32(ctx, 7, 0x6DF110);
            bool applied = runAccountHelper(rdram, ctx, runtime, 0x5805A0, 0);
            if (applied) applied = runAccountHelper(rdram, ctx, runtime, 0x5816A0, 0);
            *ctx = caller;
            volatile char* clear = password.data();
            for (unsigned i = 0; i < password.size(); ++i) clear[i] = 0;
            if (!applied) return;
            account::inputApplied();
            std::fprintf(stderr, "\n[COOP-AUTO] native-password-applied %u\n", account::generation.load());
        }
    }
    o3_005809B0_0x5809b0(rdram, ctx, runtime);
}

void nativeAccountPoll(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    const char* mode = std::getenv("REO_COOP_PLATFORM_AUTH");
    const char* username = std::getenv("REO_COOP_USERNAME");
    const char* host = std::getenv("REO_COOP_HOST");
    const uint32_t browser = READ32(0x67C2B0);
    const uint32_t nested = READ32(0x67C2B8);
    const uint32_t display = READ32(0x67C2C0);
    const auto inRam = [](uint32_t address, uint32_t bytes) {
        return address >= 0x100000 && address <= 0x2000000 - bytes;
    };
    if (host && *host && mode && std::strcmp(mode, "native") == 0 &&
        validAccountUsername(username) &&
        (!reo_network::automatic_account::enabled() || reo_network::automatic_account::accountReady()) &&
        GPR_U32(ctx, 31) == 0x60841C && READ8(0x6DF150) == 45 &&
        READ8(0x6DF151) == 3 && inRam(browser, 0x50000) && inRam(nested, 0x60000) &&
        inRam(display, 4) && READ8(nested + 1) == 1) {
        const uint32_t stack = GPR_U32(ctx, 29);
        const uint32_t temporary = stack - 16;
        if (stack < 64 || !inRam(stack - 64, 64)) {
            std::fprintf(stderr, "[COOP-ACCOUNT] Invalid account selection stack\n");
            runtime->requestStop();
            return;
        }
        SET_GPR_U32(ctx, 29, temporary);
        for (size_t i = 0; i < 16; ++i)
            WRITE8(temporary + static_cast<uint32_t>(i),
                   i < std::strlen(username) ? username[i] : 0);
        if (!runAccountHelper(rdram, ctx, runtime, 0x59FB00, temporary))
            return;
        SET_GPR_U32(ctx, 29, stack);
        // Exact AMUSA_GAME_BACK UI result, followed by ordinary fade/cleanup.
        // The original caller saves the ID and still asks the server to authenticate it.
        WRITE8(0x67DA98, 2);
        if (!runAccountHelper(rdram, ctx, runtime, 0x599110, 0))
            return;
        std::fprintf(
            stderr,
            "[COOP-ACCOUNT] Launcher account selected; server authentication still required\n");
    }
    o3_0058BF10_0x58bf10(rdram, ctx, runtime);
}

void httpCompletionByte(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    // Original 732AA0 and 732AB0: jr ra; sb a1,0(a2) in the delay slot.
    WRITE8(GPR_U32(ctx, 6), static_cast<uint8_t>(GPR_U32(ctx, 5)));
    ctx->pc = GPR_U32(ctx, 31);
}

void nativePlatformInformation(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    const char* mode = std::getenv("REO_COOP_PLATFORM_AUTH");
    constexpr uint32_t consoleNotice[] = {0x2591C0, 0x2593D0, 0x2595E0, 0x2597C0, 0x2599E0};
    bool originalNotice = READ32(0x35EBB0) == 5;
    for (unsigned i = 0; i < 5 && originalNotice; ++i)
        originalNotice = READ32(0x35EC50 + i * 4) == consoleNotice[i];
    auto* bridge = ReoHwBridge::instance();
    if (!mode || std::strcmp(mode, "native") != 0 || !originalNotice || !bridge ||
        !bridge->nativeNetworkLinkReady()) {
        o3_00609750_0x609750(rdram, ctx, runtime);
        return;
    }
    // Omit only the verified built-in notice for the unused console service.
    // Server-provided pages retain their original display and consent workflow.
    std::fprintf(
        stderr,
        "[COOP-NATIVE-PLATFORM] Original console DNAS notice omitted; no agreement recorded\n");
    o3_005F74F0_0x5f74f0(rdram, ctx, runtime);
    SET_GPR_S32(ctx, 2, 1);
    ctx->pc = GPR_U32(ctx, 31);
}

void nativePlatformStep(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    const char* mode = std::getenv("REO_COOP_PLATFORM_AUTH");
    if (!mode || std::strcmp(mode, "native") != 0) {
        o3_00603320_0x603320(rdram, ctx, runtime);
        return;
    }
    auto* bridge = ReoHwBridge::instance();
    if (!bridge || !bridge->nativeNetworkLinkReady()) {
        SET_GPR_S32(ctx, 2, 0);
        ctx->pc = GPR_U32(ctx, 31);
        return;
    }
    reo_network::automatic_account::arm();
    static bool reported = false;
    if (!reported) {
        std::fprintf(stderr, "[COOP-NATIVE-PLATFORM] Console DNAS is not used in native mode; "
                             "continuing to openSNAP account authentication\n");
        reported = true;
    }
    // Complete the platform-only workflow step. The original account challenge,
    // credentials, lobby admission and gameplay protocol remain server-controlled.
    o3_005F74E0_0x5f74e0(rdram, ctx, runtime);
    SET_GPR_S32(ctx, 2, 1);
    ctx->pc = GPR_U32(ctx, 31);
}
// 0x1B7890..0x1B78A0 (SLUS_207.65), the third of three adjacent setters (0x1B7870/0x1B7880 were
// found by Ghidra; this one was not, and sub_001B74D0 has no entry case for it):
//   lui $at,0x23 ; lw $v1,0x4768($at) ; jr $ra ; sw $a0,0x80($v1)   (store in the delay slot)
void sub_001B7890(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    (void)runtime;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0x23u << 16));
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 0x4768u)));
    WRITE32(ADD32(GPR_U32(ctx, 3), 0x80u), GPR_U32(ctx, 4));
    ctx->pc = GPR_U32(ctx, 31);
}
// Original BIN/8.DAT (MWo3 id 10), 814720: 3c01008b / 03e00008 /
// ac24a318. The network death flow calls this state setter; it lies just beyond
// the last mapped function. Preserve the store in the JR delay slot.
void networkScenarioState(uint8_t* rdram,R5900Context* ctx,PS2Runtime* runtime) {
    SET_GPR_S32(ctx,1,0x008b0000);
    const auto target=GPR_U32(ctx,31);
    WRITE32(ADD32(GPR_U32(ctx,1),uint32_t(int32_t(int16_t(0xa318)))),GPR_U32(ctx,4));
    ctx->pc=target;
}
} // namespace

// Call after all generated (and overlay) registration.
void install(PS2Runtime& runtime) {
    runtime.registerFunction(0x1C72F0, nativeReliableSend);
    runtime.registerFunction(0x1AFDD0,nativeEventSend);
    runtime.registerOverlayFunction(0x570000u,0x336F574Du,4u,3u,0x6647F0u,nativeMotionCorrection);
    runtime.registerOverlayFunction(0x570000u,0x336F574Du,4u,3u,0x67ED50u,nativeMotionReceive);
    runtime.registerOverlayFunction(0x810000u,0x336F574Du,4u,10u,0x814720u,networkScenarioState);
    runtime.registerOverlayFunction(0x570000u, 0x336F574Du, 4u, 4u, 0x5F8280u, nativeNetworkDisplay);
    runtime.registerOverlayFunction(0x570000u, 0x336F574Du, 4u, 4u, 0x5809B0u, nativePasswordPoll);
    runtime.registerFunction(0x1C8850, nativeNetworkSeconds);
    runtime.registerFunction(0x1EA000, nativeNetworkCount);
    runtime.registerFunction(0x1F3BCC, traceSnapPacket<0x1F3BCC, sub_001F3BCC_0x1f3bcc>);
    runtime.registerFunction(0x1DC7B8, traceSnapPacket<0x1DC7B8, sub_001DC7B8_0x1dc7b8>);
    runtime.registerFunction(0x1DFDA8, traceSnapPacket<0x1DFDA8, sub_001DFDA8_0x1dfda8>);
    runtime.registerFunction(0x1DF99C, traceSnapPacket<0x1DF99C, sub_001DF99C_0x1df99c>);
#ifdef REO_HAS_DNAS_TAIL_AOT
    // Missing original DNAS exports and their resumptions remain scoped to netdnas id5.
    reo_dnas_tail_aot::install(runtime);
#endif
#ifdef REO_HAS_SLOT_QUERY_AOT
    for (uint32_t entry : {0x814370u, 0x8143E8u, 0x8143F8u})
        runtime.registerOverlayFunction(0x810000u, 0x336F574Du, 4u, 10u, entry,
                                        coop_slot_query_0x814370);
#endif
#ifdef REO_HAS_FREE_MODE_CALLBACK_AOT
    runtime.registerOverlayFunction(0x570000u, 0x336F574Du, 4u, 4u, 0x57B690u,
                                    coop_free_mode_callback_0x57b690);
#endif
#ifdef REO_HAS_VERIFIED_CALLBACKS_AOT
    reo_verified_callback_cluster::install(runtime);
#endif
#ifdef REO_HAS_LOBBY_CALLBACKS_AOT
    runtime.registerOverlayFunction(0x570000u, 0x336F574Du, 4u, 4u, 0x57A6A0u,
                                    coop_lobby_profile_callback_0x57a6a0);
    runtime.registerOverlayFunction(0x570000u, 0x336F574Du, 4u, 4u, 0x57A730u,
                                    coop_lobby_state_callback_0x57a730);
    runtime.registerOverlayFunction(0x570000u, 0x336F574Du, 4u, 4u, 0x585930u,
                                    coop_lobby_choice_callback_0x585930);
#endif
    if (!runtime.hasFunction(0x1B7890u))
        runtime.registerFunction(0x1B7890u, sub_001B7890);
    runtime.registerOverlayFunction(0x570000u, 0x336F574Du, 4u, 3u, 0x6a1390u,zombieFadeDelay);
    runtime.registerOverlayFunction(0x570000u, 0x336F574Du, 4u, 3u, 0x6a13d0u,zombieFadeOut);
    runtime.registerOverlayFunction(0x570000u, 0x336F574Du, 4u, 4u, 0x603320u, nativePlatformStep);
    runtime.registerOverlayFunction(0x570000u, 0x336F574Du, 4u, 4u, 0x609750u,
                                    nativePlatformInformation);
    runtime.registerOverlayFunction(0x570000u, 0x336F574Du, 4u, 4u, 0x58BF10u, nativeAccountPoll);
    runtime.registerOverlayFunction(0x570000u, 0x336F574Du, 4u, 4u, 0x5A15C0u, browserDeactivate);
    runtime.registerOverlayFunction(0x6E0000u, 0x336F574Du, 4u, 6u, 0x732AA0u, httpCompletionByte);
    runtime.registerOverlayFunction(0x6E0000u, 0x336F574Du, 4u, 6u, 0x732AB0u, httpCompletionByte);
}
} // namespace reo_missing_entries
