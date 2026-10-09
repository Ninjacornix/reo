#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015FF70
// Address: 0x15ff70 - 0x15ff88
void sub_0015FF70_0x15ff70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015FF70_0x15ff70");
#endif

    ctx->pc = 0x15ff70u;

    // 0x15ff70: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15ff70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15ff74: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15ff74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15ff78: 0x8c840044  lw          $a0, 0x44($a0)
    ctx->pc = 0x15ff78u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 68)));
    // 0x15ff7c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15ff7cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15ff80: 0x8059108  j           func_164420
    ctx->pc = 0x15FF80u;
    ctx->pc = 0x15FF84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FF80u;
            // 0x15ff84: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x164420u;
    if (runtime->hasFunction(0x164420u)) {
        auto targetFn = runtime->lookupFunction(0x164420u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00164420_0x164420(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15FF88u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
