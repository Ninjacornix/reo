#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00132148
// Address: 0x132148 - 0x132160
void sub_00132148_0x132148(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00132148_0x132148");
#endif

    ctx->pc = 0x132148u;

    // 0x132148: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x132148u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13214c: 0x2463b75c  addiu       $v1, $v1, -0x48A4
    ctx->pc = 0x13214cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294948700));
    // 0x132150: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x132150u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x132154: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x132154u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x132158: 0x3e00008  jr          $ra
    ctx->pc = 0x132158u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13215Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132158u;
            // 0x13215c: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x132160u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
