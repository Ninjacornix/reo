#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AC630
// Address: 0x1ac630 - 0x1ac650
void sub_001AC630_0x1ac630(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AC630_0x1ac630");
#endif

    ctx->pc = 0x1ac630u;

    // 0x1ac630: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x1ac630u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x1ac634: 0x3e00008  jr          $ra
    ctx->pc = 0x1AC634u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AC638u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC634u;
            // 0x1ac638: 0x8c224170  lw          $v0, 0x4170($at) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16752)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1AC63Cu;
    // 0x1ac63c: 0x0  nop
    ctx->pc = 0x1ac63cu;
    // NOP
    // 0x1ac640: 0x3e00008  jr          $ra
    ctx->pc = 0x1AC640u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1AC648u;
    // 0x1ac648: 0x0  nop
    ctx->pc = 0x1ac648u;
    // NOP
    // 0x1ac64c: 0x0  nop
    ctx->pc = 0x1ac64cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
