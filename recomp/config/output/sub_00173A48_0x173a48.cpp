#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00173A48
// Address: 0x173a48 - 0x173a70
void sub_00173A48_0x173a48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00173A48_0x173a48");
#endif

    ctx->pc = 0x173a48u;

    // 0x173a48: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x173a48u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x173a4c: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x173a4cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173a50: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x173a50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x173a54: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x173a54u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x173a58: 0xac40004c  sw          $zero, 0x4C($v0)
    ctx->pc = 0x173a58u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 76), GPR_U32(ctx, 0));
    // 0x173a5c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x173a5cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x173a60: 0xac400048  sw          $zero, 0x48($v0)
    ctx->pc = 0x173a60u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 72), GPR_U32(ctx, 0));
    // 0x173a64: 0x805ded2  j           func_177B48
    ctx->pc = 0x173A64u;
    ctx->pc = 0x173A68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173A64u;
            // 0x173a68: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177B48u;
    if (runtime->hasFunction(0x177B48u)) {
        auto targetFn = runtime->lookupFunction(0x177B48u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00177B48_0x177b48(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x173A6Cu;
    // 0x173a6c: 0x0  nop
    ctx->pc = 0x173a6cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
