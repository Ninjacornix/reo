#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00170560
// Address: 0x170560 - 0x170570
void sub_00170560_0x170560(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00170560_0x170560");
#endif

    ctx->pc = 0x170560u;

    // 0x170560: 0x8c831b30  lw          $v1, 0x1B30($a0)
    ctx->pc = 0x170560u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 6960)));
    // 0x170564: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x170564u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x170568: 0x3e00008  jr          $ra
    ctx->pc = 0x170568u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17056Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x170568u;
            // 0x17056c: 0xac62007c  sw          $v0, 0x7C($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 124), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x170570u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
