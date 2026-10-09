#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B8FA0
// Address: 0x1b8fa0 - 0x1b8fbc
void sub_001B8FA0_0x1b8fa0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B8FA0_0x1b8fa0");
#endif

    ctx->pc = 0x1b8fa0u;

    // 0x1b8fa0: 0x90860003  lbu         $a2, 0x3($a0)
    ctx->pc = 0x1b8fa0u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3)));
    // 0x1b8fa4: 0x24870038  addiu       $a3, $a0, 0x38
    ctx->pc = 0x1b8fa4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 4), 56));
    // 0x1b8fa8: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x1b8fa8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b8fac: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1b8facu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8fb0: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x1b8fb0u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8fb4: 0x806e4f4  j           func_1B93D0
    ctx->pc = 0x1B8FB4u;
    ctx->pc = 0x1B8FB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8FB4u;
            // 0x1b8fb8: 0x2404000c  addiu       $a0, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93D0u;
    if (runtime->hasFunction(0x1B93D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001B93D0_0x1b93d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1B8FBCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
