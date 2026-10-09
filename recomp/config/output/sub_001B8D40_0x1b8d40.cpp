#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B8D40
// Address: 0x1b8d40 - 0x1b8d64
void sub_001B8D40_0x1b8d40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B8D40_0x1b8d40");
#endif

    ctx->pc = 0x1b8d40u;

    // 0x1b8d40: 0xa0382d  daddu       $a3, $a1, $zero
    ctx->pc = 0x1b8d40u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8d44: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1b8d44u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8d48: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x1b8d48u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8d4c: 0x24440008  addiu       $a0, $v0, 0x8
    ctx->pc = 0x1b8d4cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1b8d50: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x1b8d50u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b8d54: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1b8d54u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8d58: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1b8d58u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8d5c: 0x806e4f4  j           func_1B93D0
    ctx->pc = 0x1B8D5Cu;
    ctx->pc = 0x1B8D60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8D5Cu;
            // 0x1b8d60: 0x502d  daddu       $t2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93D0u;
    if (runtime->hasFunction(0x1B93D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001B93D0_0x1b93d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1B8D64u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
