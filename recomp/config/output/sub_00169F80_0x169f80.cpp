#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00169F80
// Address: 0x169f80 - 0x169fa4
void sub_00169F80_0x169f80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00169F80_0x169f80");
#endif

    ctx->pc = 0x169f80u;

    // 0x169f80: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x169f80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x169f84: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x169f84u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169f88: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x169f88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x169f8c: 0xc0382d  daddu       $a3, $a2, $zero
    ctx->pc = 0x169f8cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169f90: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x169f90u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169f94: 0x8c851ab4  lw          $a1, 0x1AB4($a0)
    ctx->pc = 0x169f94u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 6836)));
    // 0x169f98: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x169f98u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x169f9c: 0x8059c32  j           func_1670C8
    ctx->pc = 0x169F9Cu;
    ctx->pc = 0x169FA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169F9Cu;
            // 0x169fa0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1670C8u;
    if (runtime->hasFunction(0x1670C8u)) {
        auto targetFn = runtime->lookupFunction(0x1670C8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001670C8_0x1670c8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x169FA4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
