#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012AB60
// Address: 0x12ab60 - 0x12ab88
void sub_0012AB60_0x12ab60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012AB60_0x12ab60");
#endif

    ctx->pc = 0x12ab60u;

    // 0x12ab60: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12ab60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12ab64: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12ab64u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12ab68: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12ab68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12ab6c: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12ab6cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12ab70: 0x244204f0  addiu       $v0, $v0, 0x4F0
    ctx->pc = 0x12ab70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1264));
    // 0x12ab74: 0x8c65047c  lw          $a1, 0x47C($v1)
    ctx->pc = 0x12ab74u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 1148)));
    // 0x12ab78: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x12ab78u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x12ab7c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12ab7cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12ab80: 0x804aa98  j           func_12AA60
    ctx->pc = 0x12AB80u;
    ctx->pc = 0x12AB84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12AB80u;
            // 0x12ab84: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12AA60u;
    if (runtime->hasFunction(0x12AA60u)) {
        auto targetFn = runtime->lookupFunction(0x12AA60u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0012AA60_0x12aa60(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12AB88u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
