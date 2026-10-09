#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00189A50
// Address: 0x189a50 - 0x189a6c
void sub_00189A50_0x189a50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00189A50_0x189a50");
#endif

    ctx->pc = 0x189a50u;

    // 0x189a50: 0x51080  sll         $v0, $a1, 2
    ctx->pc = 0x189a50u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x189a54: 0x441821  addu        $v1, $v0, $a0
    ctx->pc = 0x189a54u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x189a58: 0x8c63000c  lw          $v1, 0xC($v1)
    ctx->pc = 0x189a58u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x189a5c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x189a5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x189a60: 0xacc30000  sw          $v1, 0x0($a2)
    ctx->pc = 0x189a60u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 3));
    // 0x189a64: 0x3e00008  jr          $ra
    ctx->pc = 0x189A64u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x189A68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189A64u;
            // 0x189a68: 0xacc50004  sw          $a1, 0x4($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x189A6Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
