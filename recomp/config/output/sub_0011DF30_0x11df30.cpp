#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011DF30
// Address: 0x11df30 - 0x11df40
void sub_0011DF30_0x11df30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011DF30_0x11df30");
#endif

    ctx->pc = 0x11df30u;

    // 0x11df30: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x11df30u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11df34: 0x3c04b000  lui         $a0, 0xB000
    ctx->pc = 0x11df34u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)45056 << 16));
    // 0x11df38: 0x80477b0  j           func_11DEC0
    ctx->pc = 0x11DF38u;
    ctx->pc = 0x11DF3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DF38u;
            // 0x11df3c: 0x34841000  ori         $a0, $a0, 0x1000 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)4096);
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DEC0u;
    if (runtime->hasFunction(0x11DEC0u)) {
        auto targetFn = runtime->lookupFunction(0x11DEC0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011DEC0_0x11dec0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x11DF40u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
