// File #2 native network host integration. Address/call-site evidence is recorded
// in docs/FILE2_PORT.md; original account authentication remains server-controlled.
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include "reo_hw_bridge.h"
#include "../../network/native/ee_count_clock.h"
#include "../../network/native/automatic_account.h"
#include "../../network/native/game_netcode.h"
#include <cstdlib>
#include <cstring>
#include <atomic>
void o3_00598B20_0x598b20(uint8_t*, R5900Context*, PS2Runtime*);
void o3_005A53A0_0x5a53a0(uint8_t*, R5900Context*, PS2Runtime*);
void o3_0060D3E0_0x60d3e0(uint8_t*, R5900Context*, PS2Runtime*);
void o3_0060D3F0_0x60d3f0(uint8_t*, R5900Context*, PS2Runtime*);
void o3_0060E0E0_0x60e0e0(uint8_t*, R5900Context*, PS2Runtime*);
void o3_00613B60_0x613b60(uint8_t*, R5900Context*, PS2Runtime*);
void o3_00619390_0x619390(uint8_t*, R5900Context*, PS2Runtime*);
void sub_0016F598_0x16f598(uint8_t*, R5900Context*, PS2Runtime*);
void sub_001F4110_0x1f4110(uint8_t*, R5900Context*, PS2Runtime*);
void sub_001B3C30_0x1b3c30(uint8_t*, R5900Context*, PS2Runtime*);
void sub_001B63C0_0x1b63c0(uint8_t*, R5900Context*, PS2Runtime*);
void sub_001F2BB0_0x1f2bb0(uint8_t*, R5900Context*, PS2Runtime*);
void o2_00689F70_0x689f70(uint8_t*, R5900Context*, PS2Runtime*);
void o2_006AF6A0_0x6af6a0(uint8_t*, R5900Context*, PS2Runtime*);
void sub_0013B440_0x13b440(uint8_t*, R5900Context*, PS2Runtime*);
namespace reo_file2_network {
namespace {
void nativeReliableSend(uint8_t* rdram,R5900Context* ctx,PS2Runtime* runtime) {
    reo_network::native::capture(rdram,reo_network::native::File2);
    reo_network::native::cadence(rdram,reo_network::native::File2,
                               reo_network::native::runtime().enhanced(reo_network::native::nowUs()));
    reo_network::native::worldPump(rdram,ctx,runtime,true);
    sub_001F2BB0_0x1f2bb0(rdram,ctx,runtime);
}
void nativeMotionCorrection(uint8_t* rdram,R5900Context* ctx,PS2Runtime* runtime) {
    reo_network::native::correction(rdram,reo_network::native::File2,GPR_U32(ctx,4));
    o2_00689F70_0x689f70(rdram,ctx,runtime);
}
void nativeMotionReceive(uint8_t* rdram,R5900Context* ctx,PS2Runtime* runtime) {
    reo_network::native::MotionRecord record(rdram,reo_network::native::File2,GPR_U32(ctx,4),GPR_U32(ctx,5));
    o2_006AF6A0_0x6af6a0(rdram,ctx,runtime);
}
void nativeEventSend(uint8_t* rdram,R5900Context* ctx,PS2Runtime* runtime) {
    reo_network::native::worldObserve(rdram,true,GPR_U32(ctx,4),GPR_U32(ctx,5));
    const auto mode=reo_network::native::reliableRefresh && GPR_U32(ctx,4)==8 ? 4u :
        reo_network::native::eventReliability(rdram,reo_network::native::File2,GPR_U32(ctx,4),GPR_U32(ctx,5),GPR_U32(ctx,7));
    if(mode!=GPR_U32(ctx,7)) SET_GPR_U32(ctx,7,mode);
    sub_0013B440_0x13b440(rdram,ctx,runtime);
}
void originalEntry1B6418(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    // SLUS_209.84 has a separate entry at 1B6418, absorbed into the mapped
    // 1B63C0 range. Execute its original prologue and call, then enter the
    // generated body's existing 1B642C continuation (including both tail calls).
    // Original words: 27BDFFF0 FFB00000 FFBF0008 0C06CF0C 0080802D.
    ctx->pc = 0x1B6418;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 0xFFFFFFF0u));
    ctx->pc = 0x1B641C;
    WRITE64(GPR_U32(ctx, 29), GPR_U64(ctx, 16));
    ctx->pc = 0x1B6420;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    SET_GPR_U32(ctx, 31, 0x1B642C);
    ctx->pc = 0x1B6428;
    ctx->in_delay_slot = true;
    ctx->branch_pc = 0x1B6424;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 4) + GPR_U64(ctx, 0));
    ctx->in_delay_slot = false;
    ctx->pc = 0x1B3C30;
    auto callee = runtime->lookupFunction(0x1B3C30);
    (callee ? callee : sub_001B3C30_0x1b3c30)(rdram, ctx, runtime);
    if (ctx->pc == 0x1B3C30) ctx->pc = 0x1B642C;
    if (ctx->pc != 0x1B642C) return;
    sub_001B63C0_0x1b63c0(rdram, ctx, runtime);
}

void nativeNetworkDisplay(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    namespace account = reo_network::automatic_account;
    const unsigned step = READ8(0x6E9490);
    static unsigned previousStep = ~0u;
    // This callback belongs only to the verified netwk overlay. It runs after
    // Network is selected, including the fresh-card NET-file creation prompt.
    if (account::enabled() && (!account::armed.load() ||
        (step == 2 && previousStep != 2 && account::completed.load())))
        account::arm();
    previousStep = step;
    o3_0060E0E0_0x60e0e0(rdram, ctx, runtime);
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
    sub_0016F598_0x16f598(rdram, ctx, runtime);
}

void nativeNetworkSeconds(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    const char* host = std::getenv("REO_COOP_HOST");
    const char* mode = std::getenv("REO_COOP_PLATFORM_AUTH");
    if (!host || !*host || !mode || std::strcmp(mode, "native") != 0) {
        sub_001F4110_0x1f4110(rdram, ctx, runtime);
        return;
    }
    // Original 1F4110 accumulates GetSystemTime ticks through 11E7F0/11F080.
    // Its MMIO-backed tick stayed 0x01000000 on both native clients, keeping
    // elapsed seconds at zero and preventing the scenario packet queue draining.
    static reo_network::ElapsedSecondsClock clock;
    const bool reset = READ8(0x36DD70) == 0;
    const uint32_t previousBits = READ32(0x36DD78);
    float previous;
    std::memcpy(&previous, &previousBits, sizeof(previous));
    if (reset) {
        // Preserve the original initialized flag and previous-tick snapshot.
        sub_001F4110_0x1f4110(rdram, ctx, runtime);
        std::fprintf(stderr, "[COOP-CLOCK] File #2 SDK elapsed seconds use monotonic host time\n");
    }
    ctx->f[0] = clock.read(reset, previous);
    uint32_t secondsBits;
    std::memcpy(&secondsBits, &ctx->f[0], sizeof(secondsBits));
    WRITE32(0x36DD78, secondsBits);
    ctx->pc = GPR_U32(ctx, 31);
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
    const uint32_t work = READ32(0x64C160);
    if (account::enabled() && GPR_U32(ctx, 31) == 0x618A38 && GPR_U32(ctx, 4) == 0x6E9460 &&
        READ8(0x6E9490) == 49 && READ8(0x6E9491) == 11 && work >= 0x100000 &&
        work <= 0x2000000 - 0x700 && READ8(work + 0x28) == 1 && READ8(work + 0x21) == 5 &&
        READ16(work + 0x3E) == 15 && READ8(0x64C148) == 0) {
        account::editorReadyGeneration.store(account::generation.load());
        std::array<char, 16> password{};
        if (account::credential(password)) {
            const R5900Context caller = *ctx;
            // Supply the native credential as the original editor's initial text,
            // then invoke its ordinary Enter handler. Account authentication is untouched.
            for (unsigned i = 0; i < password.size(); ++i) WRITE8(0x6E9460 + i, uint8_t(password[i]));
            SET_GPR_U32(ctx, 5, 5); SET_GPR_U32(ctx, 6, 15); SET_GPR_U32(ctx, 7, 0x6E9460);
            bool applied = runAccountHelper(rdram, ctx, runtime, 0x5986E0, 0);
            if (applied) applied = runAccountHelper(rdram, ctx, runtime, 0x5998E0, 0);
            *ctx = caller;
            volatile char* clear = password.data();
            for (unsigned i = 0; i < password.size(); ++i) clear[i] = 0;
            if (!applied) return;
            account::inputApplied();
            std::fprintf(stderr, "\n[COOP-AUTO] native-password-applied %u\n", account::generation.load());
        }
    }
    o3_00598B20_0x598b20(rdram, ctx, runtime);
}

void nativeAccountPoll(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    const char* mode = std::getenv("REO_COOP_PLATFORM_AUTH");
    const char* username = std::getenv("REO_COOP_USERNAME");
    const char* host = std::getenv("REO_COOP_HOST");
    const uint32_t browser = READ32(0x682FD0);
    const uint32_t nested = READ32(0x682FD8);
    const uint32_t display = READ32(0x682FE0);
    const auto inRam = [](uint32_t address, uint32_t bytes) {
        return address >= 0x100000 && address <= 0x2000000 - bytes;
    };
    if (host && *host && mode && std::strcmp(mode, "native") == 0 &&
        validAccountUsername(username) &&
        (!reo_network::automatic_account::enabled() || reo_network::automatic_account::accountReady()) &&
        GPR_U32(ctx, 31) == 0x61831C && READ8(0x6E9490) == 48 &&
        READ8(0x6E9491) == 3 && inRam(browser, 0x50000) && inRam(nested, 0x60000) &&
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
        if (!runAccountHelper(rdram, ctx, runtime, 0x5B9F70, temporary))
            return;
        SET_GPR_U32(ctx, 29, stack);
        // Exact AMUSA_GAME_BACK UI result, followed by ordinary fade/cleanup.
        // The original caller saves the ID and still asks the server to authenticate it.
        WRITE8(0x683D88, 2);
        if (!runAccountHelper(rdram, ctx, runtime, 0x5B2750, 0))
            return;
        std::fprintf(
            stderr,
            "[COOP-ACCOUNT] Launcher account selected; server authentication still required\n");
    }
    o3_005A53A0_0x5a53a0(rdram, ctx, runtime);
}

void nativePlatformInformation(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    const char* mode = std::getenv("REO_COOP_PLATFORM_AUTH");
    constexpr uint32_t consoleNotice[] = {0x268B60, 0x268D90, 0x268FC0, 0x2691E0};
    bool originalNotice = READ16(0x37C720) == 4;
    for (unsigned i = 0; i < 4 && originalNotice; ++i)
        originalNotice = READ32(0x37C764 + i * 4) == consoleNotice[i];
    auto* bridge = ReoHwBridge::instance();
    if (!mode || std::strcmp(mode, "native") != 0 || !originalNotice || !bridge ||
        !bridge->nativeNetworkLinkReady()) {
        o3_00619390_0x619390(rdram, ctx, runtime);
        return;
    }
    // Omit only the verified built-in notice for the unused console service.
    // Server-provided pages retain their original display and consent workflow.
    std::fprintf(
        stderr,
        "[COOP-NATIVE-PLATFORM] Original console DNAS notice omitted; no agreement recorded\n");
    o3_0060D3F0_0x60d3f0(rdram, ctx, runtime);
    SET_GPR_S32(ctx, 2, 1);
    ctx->pc = GPR_U32(ctx, 31);
}

void nativePlatformStep(uint8_t* rdram, R5900Context* ctx, PS2Runtime* runtime) {
    const char* mode = std::getenv("REO_COOP_PLATFORM_AUTH");
    if (!mode || std::strcmp(mode, "native") != 0) {
        o3_00613B60_0x613b60(rdram, ctx, runtime);
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
    o3_0060D3E0_0x60d3e0(rdram, ctx, runtime);
    SET_GPR_S32(ctx, 2, 1);
    ctx->pc = GPR_U32(ctx, 31);
}
} // namespace
void install(PS2Runtime& runtime) {
    runtime.registerFunction(0x1F2BB0,nativeReliableSend);
    runtime.registerFunction(0x13B440,nativeEventSend);
    runtime.registerOverlayFunction(0x58D000u,0x336F574Du,4u,3u,0x689F70u,nativeMotionCorrection);
    runtime.registerOverlayFunction(0x58D000u,0x336F574Du,4u,3u,0x6AF6A0u,nativeMotionReceive);
    runtime.registerFunction(0x1B6418, originalEntry1B6418);
    runtime.registerFunction(0x16F598, nativeNetworkCount);
    runtime.registerFunction(0x1F4110, nativeNetworkSeconds);
    const auto overlay = [&](uint32_t entry, PS2Runtime::RecompiledFunction function) {
        runtime.registerOverlayFunction(0x58D000u, 0x336F574Du, 4u, 4u, entry, function);
    };
    overlay(0x60E0E0, nativeNetworkDisplay);
    overlay(0x598B20, nativePasswordPoll);
    overlay(0x5A53A0, nativeAccountPoll);
    overlay(0x613B60, nativePlatformStep);
    overlay(0x619390, nativePlatformInformation);
}
} // namespace reo_file2_network
