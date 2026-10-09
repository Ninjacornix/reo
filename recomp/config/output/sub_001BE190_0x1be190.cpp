#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BE190
// Address: 0x1be190 - 0x1be1ac
void sub_001BE190_0x1be190(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BE190_0x1be190");
#endif

    ctx->pc = 0x1be190u;

    // 0x1be190: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1be190u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1be194: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1be194u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1be198: 0xac2344e0  sw          $v1, 0x44E0($at)
    ctx->pc = 0x1be198u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17632), GPR_U32(ctx, 3));
    // 0x1be19c: 0x3c0342c8  lui         $v1, 0x42C8
    ctx->pc = 0x1be19cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)17096 << 16));
    // 0x1be1a0: 0xac800008  sw          $zero, 0x8($a0)
    ctx->pc = 0x1be1a0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 0));
    // 0x1be1a4: 0x3e00008  jr          $ra
    ctx->pc = 0x1BE1A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BE1A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE1A4u;
            // 0x1be1a8: 0xac830038  sw          $v1, 0x38($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 56), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1BE1ACu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
