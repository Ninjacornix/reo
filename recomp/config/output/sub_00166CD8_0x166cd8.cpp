#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00166CD8
// Address: 0x166cd8 - 0x166d04
void sub_00166CD8_0x166cd8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00166CD8_0x166cd8");
#endif

    switch (ctx->pc) {
        case 0x166ce0u: goto label_166ce0;
        default: break;
    }

    ctx->pc = 0x166cd8u;

    // 0x166cd8: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x166cd8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x166cdc: 0x0  nop
    ctx->pc = 0x166cdcu;
    // NOP
label_166ce0:
    // 0x166ce0: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x166ce0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x166ce4: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x166ce4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x166ce8: 0xac800004  sw          $zero, 0x4($a0)
    ctx->pc = 0x166ce8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
    // 0x166cec: 0xac800008  sw          $zero, 0x8($a0)
    ctx->pc = 0x166cecu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 0));
    // 0x166cf0: 0xac80000c  sw          $zero, 0xC($a0)
    ctx->pc = 0x166cf0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 0));
    // 0x166cf4: 0x441fffa  bgez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x166CF4u;
    {
        const bool branch_taken_0x166cf4 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x166CF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166CF4u;
            // 0x166cf8: 0x24840010  addiu       $a0, $a0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x166cf4) {
            ctx->pc = 0x166CE0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_166ce0;
        }
    }
    ctx->pc = 0x166CFCu;
    // 0x166cfc: 0x3e00008  jr          $ra
    ctx->pc = 0x166CFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166CE0u: goto label_166ce0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x166D04u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
