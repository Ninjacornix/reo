#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00164820
// Address: 0x164820 - 0x16483c
void sub_00164820_0x164820(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00164820_0x164820");
#endif

    ctx->pc = 0x164820u;

    // 0x164820: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x164820u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x164824: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x164824u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x164828: 0x8c821b74  lw          $v0, 0x1B74($a0)
    ctx->pc = 0x164828u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 7028)));
    // 0x16482c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16482cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x164830: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x164830u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x164834: 0x804c9ee  j           func_1327B8
    ctx->pc = 0x164834u;
    ctx->pc = 0x164838u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164834u;
            // 0x164838: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1327B8u;
    if (runtime->hasFunction(0x1327B8u)) {
        auto targetFn = runtime->lookupFunction(0x1327B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001327B8_0x1327b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16483Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
