#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00164840
// Address: 0x164840 - 0x16485c
void sub_00164840_0x164840(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00164840_0x164840");
#endif

    ctx->pc = 0x164840u;

    // 0x164840: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x164840u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x164844: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x164844u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x164848: 0x8c821b74  lw          $v0, 0x1B74($a0)
    ctx->pc = 0x164848u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 7028)));
    // 0x16484c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16484cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x164850: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x164850u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x164854: 0x804ca08  j           func_132820
    ctx->pc = 0x164854u;
    ctx->pc = 0x164858u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164854u;
            // 0x164858: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x132820u;
    if (runtime->hasFunction(0x132820u)) {
        auto targetFn = runtime->lookupFunction(0x132820u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00132820_0x132820(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16485Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
